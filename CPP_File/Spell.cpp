#include "Spell.h"
#include "Position.h"
#include "EvadeUtils.h"
#include "MathUtils.h"
#include "EvadeSpells.h"

extern  DWORD			G_Module;
extern  int				myTeamId;
extern  KNpc*			MY_HERO;

extern EvadeUtils*		_EvadeUtils;
extern SpellDetector*	_SpellDetector;
extern EvadeSpell*		_EvadeSpell;
extern float ExtraSpellRadius_menu;
//-------------------------------------------------//-----------------------//----------
float GetSpellRadius(Spell spell)
{	
	float radius	  = 66.666f;
	float extraRadius = ExtraSpellRadius_menu;


	for (std::map<std::string, SpellData>::iterator it_xxx=_SpellDetector->onProcessSpells->begin(); it_xxx!=_SpellDetector->onProcessSpells->end(); ++it_xxx)
	{
		if(spell.info.spellName.compare(it_xxx->second.sSetting.key_spell) == 0)
		{
			radius = it_xxx->second.sSetting.SpellRadius;

			if (spell.info.hasEndExplosion && spell.spellType == Circular)
			{
				return spell.info.secondaryRadius + extraRadius;
			}

			if (spell.spellType == Arc_x)
			{
				float spellRange = spell.startPos.Distance2D(spell.endPos);
				float arcRadius = spell.info.radius * (1 + spellRange/100) + extraRadius;

				return arcRadius;
			}

			return (float)(radius + extraRadius);
		}
	}


	//var radius = ObjectCache.menuCache.cache[spell.info.spellName + "SpellRadius"].GetValue<Slider>().Value;
	return (float)(spell.info.radius + extraRadius);
}

//-------------------------------------------------//-----------------------//----------
int GetSpellDangerLevel(Spell &spell)
{
	int dangerlevel = 2;
	for (std::map<std::string, SpellData>::iterator it_xxx=_SpellDetector->onProcessSpells->begin(); it_xxx!=_SpellDetector->onProcessSpells->end(); ++it_xxx)
	{
		if(spell.info.spellName.compare(it_xxx->second.sSetting.key_spell) == 0)
		{
			int danger_xx = it_xxx->second.sSetting.DangerLevel;
			dangerlevel = danger_xx + 1;
			return dangerlevel;
		}
	}
	return spell.info.dangerlevel;
}

//-------------------------------------------------//-----------------------//----------
bool hasProjectile(Spell &spell)
{
	return spell.info.projectileSpeed > 0 && spell.info.projectileSpeed != FLT_MAX;
}

//-------------------------------------------------//-----------------------//----------
Vec3D GetSpellProjection(Spell &spell, Vec3D pos, bool predictPos)
{
	Vec3D vZezo(0,0,0);
	if (spell.spellType == Line)
	{
		if (predictPos)
		{
			Vec3D spellPos    = spell.currentSpellPosition;
			Vec3D spellEndPos = GetSpellEndPosition(spell);

			return ProjectOn(pos, spellPos, spellEndPos).SegmentPoint;
		}

		return ProjectOn(pos, spell.startPos, spell.endPos).SegmentPoint;
	}

	if (spell.spellType == Arc_x)
	{
		if (predictPos)
		{
			Vec3D spellPos    = spell.currentSpellPosition;
			Vec3D spellEndPos = GetSpellEndPosition(spell);

			return ProjectOn(pos, spellPos, spellEndPos).SegmentPoint;
		}

		return ProjectOn(pos, spell.startPos, spell.endPos).SegmentPoint;
	}

	if (spell.spellType == Circular)
	{
		return spell.endPos;
	}

	if (spell.spellType == Cone)
	{

	}

	return vZezo;
}

//-------------------------------------------------//-----------------------//----------
Vec3D GetCollisionAllyPos(Vec3D startPos, Vec3D endPos, float range, float Radius, float extraRadius, float extraResult)
{
	Vec3D allyPosSeg(0,0,0);
	float nMinRange  = 19999;

	DWORD tempUnit    = BASE_AttackableUnit     - TEMP_ENTRY_POINT + G_Module;
	DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dw1x = *(DWORD*)tempUnit;
	DWORD dw2x = *(DWORD*)tempUnitMax;
	if (dw1x && dw2x )
	{
		int nCount = (dw2x - dw1x)/4;
		for (int kkk = 0; kkk < nCount; ++kkk)
		{
			DWORD dw3 = *(DWORD*)(dw1x + 4*kkk);
			if (dw3 == 0) continue;
			KNpc *Minion = (KNpc*)dw3;

			if (!IS_MINION(Minion))				continue;
			if (Minion->nTeam_ID == 0x12C)		continue;
			if (Minion->nTeam_ID == myTeamId)	continue;

			if (!IsValidTarget(Minion, range + 75, false, &startPos)) continue;

			char sz_Temp[] = {77, 105, 110, 105, 111, 110, 0};			// "Minion"
			if (!CheckName(sz_Temp, Minion->GetNameNpc()))	continue;

			ProjectionInfo projection = ProjectOn(Minion->currentPos(), startPos, Extend(startPos, endPos, range + 75));
			if (projection.IsOnSegment && projection.SegmentPoint.Distance2D(Minion->currentPos()) <= Radius + GetBoundingRadius(Minion) + extraRadius)
			{
				if (nMinRange > startPos.Distance2D(Minion->currentPos()))
				{
					nMinRange  = startPos.Distance2D(Minion->currentPos());
					allyPosSeg = Extend(projection.SegmentPoint, startPos, GetBoundingRadius(Minion) + extraResult);
				}
			}
		}
	}
	return allyPosSeg;
}

//-------------------------------------------------//-----------------------//----------
KNpc* CheckSpellCollision_Sp(Spell &spell, bool ignoreSelf)
{
	if ( !G_Module ) return 0;
	if ( !myTeamId ) return 0;
	if ( !MY_HERO  ) return 0;

	if ((int)spell.info.collisionObjects.size() < 1)
	{
		return 0;
	}

	std::vector<KNpc*> collisionCandidates;
	Vec3D spellPos = spell.currentSpellPosition;
	float distanceToHero = spellPos.Distance2D(MY_HERO->currentPos());
	
	for (int jj=0; jj < (int)spell.info.collisionObjects.size(); jj++)
	{
		if (spell.info.collisionObjects[jj] == EnemyChampions)
		{
			DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
			DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
			DWORD dw1 = *(DWORD*)tempHero;
			DWORD dw2 = *(DWORD*)tempHeroMax;
			if (!dw1 || !dw2 ) return 0;

			int nCount = (dw2 - dw1)/4;
			for (int i = 0; i < nCount; ++i)
			{
				DWORD dw3 = *(DWORD*)(dw1 + 4*i);
				if (dw3 == 0) continue;
				KNpc *allyHero = (KNpc*)dw3;
				if (allyHero->nTeam_ID != myTeamId) continue;
				if(IsValidTarget(allyHero, distanceToHero, false, &spellPos))
				{
					if (ignoreSelf && allyHero == MY_HERO)
					{
						continue;
					}
					collisionCandidates.push_back(allyHero);
				}
			}
		}
		if(spell.info.collisionObjects[jj] == EnemyMinions)
		{
			DWORD tempUnit    = BASE_AttackableUnit     - TEMP_ENTRY_POINT + G_Module;
			DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
			DWORD dw1 = *(DWORD*)tempUnit;
			DWORD dw2 = *(DWORD*)tempUnitMax;
			if (!dw1 || !dw2 ) return 0;

			int nCount = (dw2 - dw1)/4;
			for (int i = 0; i < nCount; ++i)
			{
				DWORD dw3 = *(DWORD*)(dw1 + 4*i);
				if (dw3 == 0) continue;
				KNpc *allyMinion = (KNpc*)dw3;
				if (allyMinion->nTeam_ID != myTeamId) continue;
				if (!IS_MINION(allyMinion))			  continue;
				if (IsValidTarget(allyMinion, distanceToHero, false, &spellPos))
				{
					if (!CheckName(sz__Minion, allyMinion->GetNameNpc())) continue;
					collisionCandidates.push_back(allyMinion);
				}
			}
		}
	}

	//var sortedCandidates = collisionCandidates.OrderBy(h => h.Distance(spellPos));
	
	KNpc* unitResult = 0;
	float nMinRange  = 20000;
	for (int jj=0; jj < (int)collisionCandidates.size(); jj++)
	{
		if(InSkillShot(collisionCandidates[jj]->currentPos(), spell, BoundRadius_Minion(collisionCandidates[jj]), false))
		{
			if (nMinRange > spellPos.Distance2D(collisionCandidates[jj]->currentPos()))
			{
				nMinRange  = spellPos.Distance2D(collisionCandidates[jj]->currentPos());
				unitResult = collisionCandidates[jj];
				//__oMsg("SIZE = %d", (int)collisionCandidates.size());
			}
		}
	}

	return unitResult;
}

//-------------------------------------------------//-----------------------//----------
float GetSpellHitTime(Spell spell, Vec3D pos)
{
	Vec3D spellPos;

	switch (spell.spellType)
	{
		case Line:
			if (spell.info.projectileSpeed == FLT_MAX)
				return max(0, spell.endTime - _EvadeUtils->TickCount() - (float)GetPingGame());
			
			spellPos = GetCurrentSpellPosition(spell, true, (float)GetPingGame());
			return 1000 * spellPos.Distance2D(pos) / spell.info.projectileSpeed;

		case Cone:
		case Circular:
			return max(0, spell.endTime - _EvadeUtils->TickCount() - (float)GetPingGame());
	}

	return FLT_MAX;
}

//-------------------------------------------------//-----------------------//----------
bool CanHeroEvade(Spell spell, KNpc* hero, float &rEvadeTime, float &rSpellHitTime)
{
	Vec3D heroPos = hero->currentPos();
	float evadeTime = 0;
	float spellHitTime = 0;
	float speed = hero->nMoveSpeed;
	float delay = 0;

	//---- dung item de move ne : tam thoi chua lam ---:
	EvadeSpellData moveBuff;
	bool hasEvadeSpellData = false;
	for (int i = 0; i < (int)_EvadeSpell->evadeSpells->size(); ++i)	//da sap xep roi
	{
		EvadeSpellData evadespell = _EvadeSpell->evadeSpells->at(i);
		if (evadespell.evadeType == _MovementSpeedBuff && CanCast(evadespell.spellKey) == true)
		{
			hasEvadeSpellData = true;
			moveBuff = evadespell;
			break;
		}
	}

	if (hasEvadeSpellData == true && ShouldUseMovementBuff(spell))
	{
		KNpc* myHero = GetPlayer();
		if (myHero)
		{
			KSkill *pSkill_X = (KSkill *)myHero->_pSkill[moveBuff.spellKey];
			if (pSkill_X)
			{
				speed += speed * moveBuff.speedArray[(BYTE)pSkill_X->nLevel - 1] / 100;
				delay += (moveBuff.spellDelay > 50 ? moveBuff.spellDelay : 0) + (float)GetPingGame();
			}
		}
	}

	if (spell.spellType == Line)
	{
		Vec3D projection = ProjectOn(heroPos, spell.startPos, spell.endPos).SegmentPoint;
		evadeTime = 1000 * (spell.radius - heroPos.Distance2D(projection) + BoundRadius(hero) + 10.0f) / speed;		// chac phai cong them 1 chut
		spellHitTime = GetSpellHitTime(spell, projection);
	}
	else if (spell.spellType == Circular)
	{
		evadeTime = 1000 * (spell.radius - heroPos.Distance2D(spell.endPos)) / speed;
		spellHitTime = GetSpellHitTime(spell, heroPos);
	}
	else if (spell.spellType == Cone)
	{
		std::vector<Vec3D> vSegmentPoint;
		vSegmentPoint.push_back(ProjectOn(heroPos, spell.cnStart, spell.cnLeft).SegmentPoint);
		vSegmentPoint.push_back(ProjectOn(heroPos, spell.cnLeft, spell.cnRight).SegmentPoint);
		vSegmentPoint.push_back(ProjectOn(heroPos, spell.cnRight, spell.cnStart).SegmentPoint);
		
		Vec3D p;
		float nDistant = FLT_MAX;
		for(int i=0; i < (int)vSegmentPoint.size(); i++)
		{
			float dist2SegmentPoint = heroPos.Distance2D(vSegmentPoint[i]);
			if( dist2SegmentPoint < nDistant)
			{
				nDistant = dist2SegmentPoint;
				p = vSegmentPoint[i];
			}
			//__oMsg("i=%d, KC = %f, time = %f", i, dist2SegmentPoint + BoundRadius(hero), 1000 * (dist2SegmentPoint + BoundRadius(hero))/speed);
		}

		//evadeTime = 1000 * (spell.info.range / 2 - heroPos.Distance2D(p) + BoundRadius(hero)) / speed;
		evadeTime = 1000 * (heroPos.Distance2D(p) + BoundRadius(hero)) / speed;
		spellHitTime = GetSpellHitTime(spell, heroPos);
	}

	rEvadeTime = evadeTime;
	rSpellHitTime = spellHitTime;

	return spellHitTime - delay > evadeTime;
}

//-------------------------------------------------//-----------------------//----------
Vec3D GetSpellEndPosition(Spell spell)
{
	Vec3D vZezo(0,0,0);
	return spell.predictedEndPos == vZezo ? spell.endPos : spell.predictedEndPos;
}

//-------------------------------------------------//-----------------------//----------
Vec3D GetSpellEndPosition_forDraw(Spell spell, float fakeRange)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return GetSpellEndPosition(spell);

	if(spell.info.spellType == Line && spell.info.range > 3500)	//LuxR = 3300, JhinR = 3500
	{
		ProjectionInfo proJ = ProjectOn(myHero->currentPos(), spell.startPos, spell.endPos);
		if(proJ.IsOnSegment) //doan nay hinh nhu hoi nham ti', nhung k anh huong nhieu lam
		{
			Vec3D endPosFake_1 = Extend(spell.startPos, spell.endPos, Distance(spell.startPos, proJ.SegmentPoint) + fakeRange);
			
			if(Distance(spell.currentSpellPosition, spell.endPos) < Distance(proJ.SegmentPoint, spell.endPos))
			{
				Vec3D endPosFake_2 = spell.currentSpellPosition + spell.direction * 1300;
				return endPosFake_2;

			}
			return  endPosFake_1;
		}
		else 
		{
			Vec3D endPosFake_1 = Extend(spell.startPos, spell.endPos, Distance(spell.startPos, myHero->currentPos()) + fakeRange);

			if(Distance(spell.currentSpellPosition, spell.endPos) < Distance(myHero->currentPos(), spell.endPos))
			{
				Vec3D endPosFake_2 = spell.currentSpellPosition + spell.direction * 1300;
				return endPosFake_2;
			}
			return  endPosFake_1;
		}
	}
	
	//spellPos = spell.startPos + spell.direction * spell.info.projectileSpeed * (spellTime / 1000);

	return GetSpellEndPosition(spell);
}

//-------------------------------------------------//-----------------------//----------
void UpdateSpellInfo(Spell &spell)
{
	//spell.nTest_1 = 999.9f;
	//__oMsg("2-test: %f", spell.nTest_1);
	//return;

	spell.currentSpellPosition    = GetCurrentSpellPosition(spell, false, 0, 0);
	//__oMsg("-----[3] spellPos: %f, %f, %f", spell.currentSpellPosition.x, spell.currentSpellPosition.y, spell.currentSpellPosition.z);
	spell.currentNegativePosition = GetCurrentSpellPosition(spell, true, 0, 0);
	spell.dangerlevel             = GetSpellDangerLevel(spell);
	//__oMsg("-----UpdateSpellInfo: dangerlevel=%d", spell.dangerlevel);
}

//-------------------------------------------------//-----------------------//----------
Vec3D GetCurrentSpellPosition(Spell &spell, bool allowNegative, float delay, float extraDistance)
{
	Vec3D spellPos = spell.startPos;

	KNpc* myHero = GetPlayer();
	if(!myHero) return spellPos;

	if (spell.info.updatePosition == false)
	{
		return spellPos;
	}

	if (spell.spellType == Line || spell.spellType == Arc_x)
	{
		float spellTime = (float)GetTickCount() - spell.startTime -  spell.info.spellDelay - max(0, spell.info.extraEndTime);

		if (spell.info.projectileSpeed == FLT_MAX)
		{
			return spell.startPos;
		}

		if (spellTime >= 0 || allowNegative)
		{
			spellPos = spell.startPos + spell.direction * spell.info.projectileSpeed * (spellTime / 1000);
			//__oMsg("-----[1] [%.3f]spellPos: [%.3f, %.3f, %.3f]", spellTime, spellPos.x, spellPos.y, spellPos.z);
		}
	}
	else if (spell.spellType == Circular || spell.spellType == Cone)
	{
		spellPos = spell.endPos;
	}

			////////if (spell.spellObject != 0 && spell.KoUpCurrentPos != true &&				//createSpell o onProces thi spell.KoUpCurrentPos=true roi, lay startPos se~ ve chuan hon, con neu createMissile thi phai lay lai startPos, ko thi no se ve hoi lech. ti
			////////	IsValidObj(spell.spellObject) /*&& spell.spellObject.IsVisible*/ && 
			////////	Distance_2D(spell.spellObject->CurrentPos, myHero->CurrentPos) < spell.info.range + 1000)
			////////{
			////////	if(spell.info.missileDelay > 0)	//them doan nay de ne' in FOW nhieu hon(mac du co the van~ trung, dung cho 1 so skill dac biet nguy hiem)
			////////	{
			////////		float spellTime = (float)GetTickCount() - spell.startTime -  spell.info.missileDelay /* - max(0, spell.info.extraEndTime)*/;
			////////		spellPos = spell.startPos_2 + spell.direction * spell.info.projectileSpeed * (spellTime / 1000);
			////////	}
			////////	else
			////////	{
			////////		ProjectionInfo projOn = ProjectOn(spell.spellObject->currentPos(), spell.startPos, spell.endPos);
			////////		if(projOn.IsOnSegment)
			////////		{
			////////			 spellPos = projOn.SegmentPoint;
			////////			// __oMsg("-------xxxxx---xxxx----");
			////////		}
			////////		else
			////////		{
			////////			spellPos = spell.spellObject->currentPos();
			////////			//__oMsg("-------yyyyy---yyyy----");
			////////		}
			////////	}
			////////	////spellPos = spell.spellObject->currentPos();
			////////}

	if ( spell.spellObject != 0 && IsValidObj(spell.spellObject) /*&& spell.spellObject.IsVisible*/ &&	//ko check ddc IsVisible cua Missile
		 Distance_2D(spell.spellObject->CurrentPos, myHero->CurrentPos) < spell.info.range + 1000 )
	{
		spellPos = spell.spellObject->currentPos();
	}

	if (delay > 0 && spell.info.projectileSpeed != FLT_MAX && spell.spellType == Line)
	{
		spellPos = spellPos + spell.direction * spell.info.projectileSpeed * (delay / 1000);
		//__oMsg("-----[2] spellPos: %f, %f, %f", spellPos.x, spellPos.y, spellPos.z);
	}

	if (extraDistance > 0 && spell.info.projectileSpeed != FLT_MAX
		&& spell.spellType == Line)
	{
		spellPos = spellPos + spell.direction * extraDistance;
	}

	return spellPos;
}

//-------------------------------------------------//-----------------------//----------
//-------------------------------------------------//-----------------------//----------
bool LineIntersectLinearSpell(Spell spell, Vec3D a, Vec3D b)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return false;

	float myBoundingRadius = BoundRadius(myHero);
	Vec3D spellDir    = spell.direction;
	Vec3D pSpellDir   = Perpendicular(spell.direction);
	float spellRadius = spell.radius;
	Vec3D spellPos    = spell.currentSpellPosition;		// -spellDir * myBoundingRadius; //leave some space at back of spell
	Vec3D endPos      = GetSpellEndPosition(spell);		// +spellDir * myBoundingRadius; //leave some space at the front of spell

	Vec3D startRightPos = spellPos + pSpellDir * (spellRadius + myBoundingRadius);
	Vec3D startLeftPos  = spellPos - pSpellDir * (spellRadius + myBoundingRadius);
	Vec3D endRightPos   = endPos + pSpellDir * (spellRadius + myBoundingRadius);
	Vec3D endLeftPos	= endPos - pSpellDir * (spellRadius + myBoundingRadius);

	bool int1 = CheckLineIntersection(a, b, startRightPos, startLeftPos);	
	bool int2 = CheckLineIntersection(a, b, endRightPos, endLeftPos);
	bool int3 = CheckLineIntersection(a, b, startRightPos, endRightPos);
	bool int4 = CheckLineIntersection(a, b, startLeftPos, endLeftPos);

	if (int1 || int2 || int3 || int4)
	{
		return true;
	}

	return false;
}