#include "Position.h"


extern  int					myTeamId;
extern  SpellDetector*		_SpellDetector;

extern bool PreventDodgingUnderTower_menu;
//-------------------------------------------------//-----------------------//----------
bool InSkillShot(Vec3D position, Spell spell, float radius, bool predictCollision)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return false;

	if (spell.spellType == Line)
	{
		Vec3D spellPos = spell.currentSpellPosition;
		Vec3D spellEndPos = predictCollision ? GetSpellEndPosition(spell) : spell.endPos;

		ProjectionInfo projection = ProjectOn(position, spellPos, spellEndPos);
		//__oMsg(" [InSkillShot]isOnSegment : %d, spellPos(%f, %f, %f), SegmentPoint:(%f, %f, %f)", projection.IsOnSegment, spellPos.x, spellPos.y, spellPos.z, projection.SegmentPoint.x, projection.SegmentPoint.y, projection.SegmentPoint.z);
		//__oMsg(" [InSkillShot] : %d, %f < %f (%f, %f, %f) >hero(%f, %f, %f)", projection.IsOnSegment, projection.SegmentPoint.Distance2D(position), spell.radius + radius, position.x, position.y, position.z, myHero->currentPos().x, myHero->currentPos().y, myHero->currentPos().z);
		return projection.IsOnSegment && projection.SegmentPoint.Distance2D(position) <= spell.radius + radius;
	}

	if (spell.spellType == Circular)
	{
		if (spell.info.spellName == "VeigarEventHorizon")
		{
			return position.Distance2D(spell.endPos) <= spell.radius + radius - BoundRadius(myHero)
				&& position.Distance2D(spell.endPos) >= spell.radius + radius - BoundRadius(myHero) - 125;
		}
		if (spell.info.spellName == "DariusCleave")
		{
			return position.Distance2D(spell.endPos) <= spell.radius + radius - BoundRadius(myHero)
				&& position.Distance2D(spell.endPos) >= spell.radius + radius - BoundRadius(myHero) - 220;
		}

		return position.Distance2D(spell.endPos) <= spell.radius + radius - BoundRadius(myHero);
	}

	if (spell.spellType == Arc_x)
	{
		if (isLeftOfLineSegment(position, spell.startPos, spell.endPos))
		{
			return false;
		}

		float spellRange = spell.startPos.Distance2D(spell.endPos);
		Vec3D midPoint = spell.startPos + spell.direction * (spellRange/2);

		return position.Distance2D(midPoint) <= spell.radius + radius - BoundRadius(myHero);
	}

	if (spell.spellType == Cone)
	{
		return	!isLeftOfLineSegment(position, spell.cnStart , spell.cnLeft) && 
				!isLeftOfLineSegment(position, spell.cnLeft, spell.cnRight) && 
				!isLeftOfLineSegment(position, spell.cnRight, spell.cnStart);
	}

	return false;
}

//-------------------------------------------------//-----------------------//----------
bool isLeftOfLineSegment(Vec3D pos, Vec3D start, Vec3D end)
{
	//return ((end.x - start.x) * (pos.y - start.y) - (end.y - start.y) * (pos.x - start.x)) > 0;
	return ((end.x - start.x) * (pos.z - start.z) - (end.z - start.z) * (pos.x - start.x)) > 0;
}

//-------------------------------------------------//-----------------------//----------
float GetDistanceToTurrets(Vec3D pos)
{
	float minDist = FLT_MAX;

	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == 0) return 0;
	DWORD tempUnit    = BASE_AttackableUnit     - TEMP_ENTRY_POINT + hModule;
	DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)tempUnit;
	DWORD dw2 = *(DWORD*)tempUnitMax;
	if (!dw1 || !dw2 ) return 0;

	int nCount = (dw2 - dw1)/4;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *enemyTurret = (KNpc*)dw3;
		
		if (enemyTurret->nIndex < 0x3FFFFCC8)	continue;
		if (enemyTurret->nTeam_ID == myTeamId)	continue;
		if (!IS_TURRET(enemyTurret)) continue;
		
		if (!IS_DEAD(enemyTurret) && IsCanSee(enemyTurret))
		{
			float distToTurret    = pos.Distance2D(enemyTurret->currentPos());
			minDist		          = min(minDist, distToTurret);
		}
	}

	return minDist;
}

//-------------------------------------------------//-----------------------//----------
float GetDistanceToChampions(Vec3D pos)
{
	float minDist = FLT_MAX;

	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == 0) return 0;
	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + hModule;
	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)tempHero;
	DWORD dw2 = *(DWORD*)tempHeroMax;
	if (!dw1 || !dw2 ) return 0;

	int nCount = (dw2 - dw1)/4;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *enemyHero = (KNpc*)dw3;
		if (enemyHero->nTeam_ID == myTeamId) continue;

		if(!IS_DEAD(enemyHero) && IsCanSee(enemyHero))
		{
			Vec3D heroPos = enemyHero->currentPos();
			float dist    = heroPos.Distance2D(pos);
			minDist		  = min(minDist, dist);
		}
	}

	return minDist;
}

//-------------------------------------------------//-----------------------//----------
bool HasExtraAvoidDistance(Vec3D pos, float extraBuffer)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return false;

	for (std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->begin(); it_spells!= _SpellDetector->spells->end(); ++it_spells)
	{
		Spell spell = it_spells->second;

		if (spell.spellType == Line)
		{
			if (InSkillShot(pos, spell, BoundRadius(myHero) + extraBuffer))
			{
				return true;
			}
		}
	}

	return false;
}

//-------------------------------------------------//-----------------------//----------
float GetPositionValue(Vec3D pos)
{
	float posValue = pos.Distance2D(mousePosVec3D());

	KNpc* myHero = GetPlayer();
	if(!myHero) return posValue;

	if (PreventDodgingUnderTower_menu)
	{
		float turretRange = 875 + BoundRadius(myHero);
		float distanceToTurrets = GetDistanceToTurrets(pos);

		if (turretRange > distanceToTurrets)
		{
			posValue += 5 * (turretRange - distanceToTurrets);
		}
	}

	return posValue;
}

//-------------------------------------------------//-----------------------//----------
bool CheckDangerousPos(Vec3D pos, float extraBuffer, bool checkOnlyDangerous)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return false;

	for (std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->begin(); it_spells!= _SpellDetector->spells->end(); ++it_spells)
	{
		Spell spell = it_spells->second;
		
		if (checkOnlyDangerous && spell.dangerlevel < 3)
		{
			continue;
		}

		if (InSkillShot(pos, spell, BoundRadius(myHero) + extraBuffer))
		{
			return true;
		}
	}

	return false;
}