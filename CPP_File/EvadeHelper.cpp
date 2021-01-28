#include "EvadeHelper.h"
#include "MathUtilsCPA.h"
#include "MathUtils.h"
#include "Position.h"
#include "PositionInfo.h"
#include "EvadeUtils.h"
#include "Situation.h"
#include "SpellDetector.h"

extern  SpellDetector*		_SpellDetector;
extern  Evade*				_Evade;
extern	EvadeHelper*		_EvadeHelper;


extern float ExtraCPADistance_menu, ExtraPingBuffer_menu, ExtraEvadeDistance_menu, MinComfortZone_menu, ExtraAvoidDistance_menu, RejectMinDistance_menu;
extern float FastEvadeActivationTime_menu;
extern bool  CalculateWindupDelay_menu, HigherPrecision_menu;
extern int   EvadeMode_menu;
extern int   myTeamId;
extern DWORD G_Module;

//-------------------------------------------------//-----------------------//----------
bool sort_000(PositionInfo* p1, PositionInfo* p2)	// GetBestPositionMovementBlock()
{
	//posTable.OrderBy(p => p.isDangerousPos) .OrderBy(p => p.posDangerLevel) .ThenBy(p => p.hasExtraDistance) .ThenBy(p => p.distanceToMouse);
	if      (p1->isDangerousPos < p2->isDangerousPos) return true;			//so sanh lay so be hon
	else if (p1->isDangerousPos > p2->isDangerousPos) return false;

	if      (p1->posDangerLevel < p2->posDangerLevel) return true;				//so sanh lay so be hon
	else if (p1->posDangerLevel > p2->posDangerLevel) return false;

	if      (p1->hasExtraDistance < p2->hasExtraDistance) return true;			//so sanh lay so be hon
	else if (p1->hasExtraDistance > p2->hasExtraDistance) return false;

	if      (p1->distanceToMouse < p2->distanceToMouse) return true;			//so sanh lay so be hon
	else if (p1->distanceToMouse > p2->distanceToMouse) return false;

	return false;
}

//-------------------------------------------------//-----------------------//----------
bool sort_111(PositionInfo* p1, PositionInfo* p2)	// GetBestPosition --> EvadeMode_menu = Fastest(index=2)
{
	//posTable.OrderBy(p => p.isDangerousPos) .ThenByDescending(p => p.intersectionTime) .ThenBy(p => p.posDangerLevel) .ThenBy(p => p.posDangerCount);
	if      (p1->isDangerousPos < p2->isDangerousPos) return true;			//so sanh lay so be hon
	else if (p1->isDangerousPos > p2->isDangerousPos) return false;
	
	if      (p1->intersectionTime > p2->intersectionTime) return true;		//so sanh lay so lon hon
	else if (p1->intersectionTime < p2->intersectionTime) return false;

	if      (p1->posDangerLevel < p2->posDangerLevel) return true;			//so sanh lay so be hon
	else if (p1->posDangerLevel > p2->posDangerLevel) return false;

	if      (p1->posDangerCount < p2->posDangerCount) return true;			//so sanh lay so be hon
	else if (p1->posDangerCount > p2->posDangerCount) return false;

	return false;
}

//-------------------------------------------------//-----------------------//----------
bool sort_222(PositionInfo* p1, PositionInfo* p2)	// GetBestPosition --> else-if-dong` 4
{
	//posTable.OrderBy(p => p.rejectPosition).ThenBy(p => p.posDangerLevel).ThenBy(p => p.posDangerCount).ThenBy(p => p.distanceToMouse);

	if      (p1->rejectPosition < p2->rejectPosition) return true;			//so sanh lay so be hon
	else if (p1->rejectPosition > p2->rejectPosition) return false;

	if      (p1->posDangerLevel < p2->posDangerLevel) return true;			//so sanh lay so nho hon
	else if (p1->posDangerLevel > p2->posDangerLevel) return false;

	if      (p1->posDangerCount < p2->posDangerCount) return true;			//so sanh lay so be hon
	else if (p1->posDangerCount > p2->posDangerCount) return false;

	if      (p1->distanceToMouse < p2->distanceToMouse) return true;		//so sanh lay so be hon
	else if (p1->distanceToMouse > p2->distanceToMouse) return false;

	return false;
}

//-------------------------------------------------//-----------------------//----------
bool PlayerInSkillShot(Spell spell)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return false;
	
	return InSkillShot(myHero->currentPos(), spell, BoundRadius(myHero));
}

//-------------------------------------------------//-----------------------//----------
PositionInfo* InitPositionInfo(Vec3D pos, float extraDelayBuffer, float extraEvadeDistance, Vec3D lastMovePos, Spell lowestEvadeTimeSpell)
{
	//__oMsg("create->InitPositionInfo");
	PositionInfo* posInfo = 0;
	KNpc* myHero = GetPlayer();
	if(!myHero)
	{
		posInfo = new PositionInfo;
		return posInfo;
	}

	if (!IsMoving(myHero) && myHero->currentPos().Distance2D(pos) <= 75)
	{	
		//__oMsg("sao vao day??");
		pos = myHero->currentPos();
	}

	float extraDist = ExtraCPADistance_menu;		//default menu = 50.0f
	
	posInfo = CanHeroWalkToPos(pos, myHero->nMoveSpeed, extraDelayBuffer + (float)GetPingGame(), extraDist);
	posInfo->isDangerousPos   = CheckDangerousPos(pos, 6);
	posInfo->hasExtraDistance = (extraEvadeDistance > 0 && CheckDangerousPos(pos, extraEvadeDistance)) ? true : false;
	posInfo->closestDistance  = posInfo->distanceToMouse;
	//posInfo->intersectionTime = GetMinCPADistance(pos);		//CODE-OLD
	posInfo->distanceToMouse  = GetPositionValue(pos);
	posInfo->posDistToChamps  = GetDistanceToChampions(pos);
	posInfo->speed			  = myHero->nMoveSpeed;

	if (RejectMinDistance_menu > 0 && RejectMinDistance_menu > posInfo->closestDistance) //reject closestdistance
		posInfo->rejectPosition = true;

	if (MinComfortZone_menu > posInfo->posDistToChamps)
		posInfo->hasComfortZone = false;

	return posInfo;
}

//-------------------------------------------------//-----------------------//----------
PositionInfo* GetBestPosition()
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return SetAllUndodgeable();

	int posChecked = 0;
	int maxPosToCheck = 60;
	int posRadius = 50;
	int radiusIndex = 0;
	
	float extraDelayBuffer   = ExtraPingBuffer_menu;
	float extraEvadeDistance = ExtraEvadeDistance_menu;

	UpdateSpells();
	CalculateEvadeTime();

	if (CalculateWindupDelay_menu)
	{
		float extraWindupDelay = _Evade->lastWindupTime - (float)GetTickCount();
		if (extraWindupDelay > 0)
		{
			extraDelayBuffer += (float) extraWindupDelay;
		}
	}

	extraDelayBuffer += (float)(_Evade->avgCalculationTime);

	if (HigherPrecision_menu)
	{
		maxPosToCheck = 150;
		posRadius = 30;
	}
	

	Vec3D heroPoint   = myHero->currentPos();
	Vec3D lastMovePos = mousePosVec3D();

	std::vector<PositionInfo*> posTable;

	Spell lowestEvadeTimeSpell;
	float lowestEvadeTime = GetLowestEvadeTime(lowestEvadeTimeSpell);

	std::vector<Vec3D> fastestPositions = GetFastestPositions();
	
	for(int kk=0; kk < (int)fastestPositions.size(); kk++)		//add the fastest positions into list of candidates
	{
		//__oMsg("extraDelayBuffer: %f - %d", extraDelayBuffer, kk);
		//__oMsg("fastPos : [%d] - %f - %f - %f", kk, fastestPositions[kk].x, fastestPositions[kk].y, fastestPositions[kk].z);
		posTable.push_back(InitPositionInfo(fastestPositions[kk], extraDelayBuffer, extraEvadeDistance, lastMovePos, lowestEvadeTimeSpell));
		
		//Draw2DCircle(fastestPositions[kk], 5, BLUE);
	}
	
	//__oMsg("[%d]closestDistance: %f - intersectionTime:%f - lowestEvadeTime: %f", posTable[0]->isDangerousPos,posTable[0]->closestDistance, posTable[0]->intersectionTime, lowestEvadeTime);
	//_EvadeHelper->fastEvadeMode = true;
	//return posTable[0];

	while (posChecked < maxPosToCheck)
	{
		radiusIndex++;

		int curRadius = radiusIndex * (2 * posRadius);
		int curCircleChecks = (int)ceil((2 *  3.1415927f * (float)curRadius) / (2 * (float)posRadius));

		for (int i = 1; i < curCircleChecks; i++)
		{
			posChecked++;
			float cRadians = (2 * 3.1415927f / (curCircleChecks - 1)) * i; //check decimals
			Vec3D pos((float)floor(heroPoint.x + curRadius * cos(cRadians)), heroPoint.y, (float)floor(heroPoint.z + curRadius * sin(cRadians)));
			posTable.push_back(InitPositionInfo(pos, extraDelayBuffer, extraEvadeDistance, lastMovePos, lowestEvadeTimeSpell));
			//Draw2DCircle(pos, 3, YELLOW);

			//__oMsg("[count: %d]%d - %f - %d - %d", (int)sortedPosTable.size(), sortedPosTable[i]->isDangerousPos, sortedPosTable[i]->intersectionTime, sortedPosTable[i]->posDangerLevel, sortedPosTable[i]->posDangerCount);
		}
	}
	

	//__oMsg("_EvadeHelper->fastEvadeMode: %d, %f - %f", _EvadeHelper->fastEvadeMode, lowestEvadeTime, FastEvadeActivationTime_menu + (float)GetPingGame() + extraDelayBuffer);

	//IOrderedEnumerable<PositionInfo> sortedPosTable;
	std::vector<PositionInfo*> sortedPosTable;

	if (EvadeMode_menu == 2)	//"Fastest"
	{
		//__oMsg(" *********** GetBestPosition -> Fast.test");
		//posTable.OrderBy(p => p.isDangerousPos) .ThenByDescending(p => p.intersectionTime) .ThenBy(p => p.posDangerLevel) .ThenBy(p => p.posDangerCount);
		std::sort(posTable.begin(), posTable.end(), sort_111);			
		sortedPosTable = posTable;
		_EvadeHelper->fastEvadeMode = true;

		///*for (int ttt = 0; ttt < (int)sortedPosTable.size(); ttt++)
		//{
		//	Draw2DCircle(sortedPosTable[ttt]->position, 3, YELLOW);
		//	__oMsg("[count: %d]%d - (%.3f - %.3f) - %d - %d", (int)sortedPosTable.size(), sortedPosTable[ttt]->isDangerousPos, sortedPosTable[ttt]->intersectionTime, sortedPosTable[ttt]->closestDistance, sortedPosTable[ttt]->posDangerLevel, sortedPosTable[ttt]->posDangerCount);
		//}*/
		////Sleep(2000);
	}
	else if (_EvadeHelper->fastEvadeMode == true)
	{
		//__oMsg(" *********** GetBestPosition -> _EvadeHelper->fastEvadeMode=true");
		//posTable.OrderBy(p => p.isDangerousPos) .ThenByDescending(p => p.intersectionTime) .ThenBy(p => p.posDangerLevel) .ThenBy(p => p.posDangerCount);
		std::sort(posTable.begin(), posTable.end(), sort_111);			
		sortedPosTable = posTable;
	}
	else if (FastEvadeActivationTime_menu > 0 && FastEvadeActivationTime_menu + (float)GetPingGame() + extraDelayBuffer > lowestEvadeTime)	//default = 65.0f = FastEvadeActivationTime_menu
	{
		//__oMsg(" *********** GetBestPosition -> 333-3");
		//posTable.OrderBy(p => p.isDangerousPos) .ThenByDescending(p => p.intersectionTime) .ThenBy(p => p.posDangerLevel) .ThenBy(p => p.posDangerCount);
		std::sort(posTable.begin(), posTable.end(), sort_111);			
		sortedPosTable = posTable;
		_EvadeHelper->fastEvadeMode = true;
	}
	else
	{
		//__oMsg(" *********** GetBestPosition -> 444.0");
		//posTable.OrderBy(p => p.rejectPosition).ThenBy(p => p.posDangerLevel).ThenBy(p => p.posDangerCount).ThenBy(p => p.distanceToMouse);
		std::sort(posTable.begin(), posTable.end(), sort_222);	
		sortedPosTable = posTable;

		if (sortedPosTable[0]->posDangerCount != 0) //if can't dodge smoothly, dodge fast
		{
			//__oMsg(" *********** GetBestPosition -> 444.1");
			//posTable.OrderBy(p => p.isDangerousPos) .ThenByDescending(p => p.intersectionTime) .ThenBy(p => p.posDangerLevel) .ThenBy(p => p.posDangerCount);
			std::sort(posTable.begin(), posTable.end(), sort_111);	
			std::vector<PositionInfo*> sortedPosTableFastest = posTable;

			if (sortedPosTableFastest[0]->posDangerCount == 0)
			{
				//__oMsg(" *********** GetBestPosition -> 444.2");
				sortedPosTable = sortedPosTableFastest;
				_EvadeHelper->fastEvadeMode = true;
			}
		}
	}
	

	for(int kk=0; kk < (int)sortedPosTable.size(); ++kk)		//add the fastest positions into list of candidates
	{
		//doan nay can xem lai
		if (CheckPathCollision(myHero, sortedPosTable[kk]->position) == false)
		{
			if (_EvadeHelper->fastEvadeMode)
			{
				sortedPosTable[kk]->position = GetExtendedSafePosition(myHero->currentPos(), sortedPosTable[kk]->position, extraEvadeDistance);
				
				//__oMsg(" *********** GetBestPosition -> LAST.1");
				//Draw2DCircle(sortedPosTable[kk]->position, 10, GREEN);
				return CanHeroWalkToPos(sortedPosTable[kk]->position, myHero->nMoveSpeed, (float)GetPingGame(), 0);
			}

			//if (PositionInfoStillValid(sortedPosTable[kk]))		//-- ko dung`
			{
				if (CheckDangerousPos(sortedPosTable[kk]->position, extraEvadeDistance)) //extra evade distance, no multiple skillshots
				{
					//__oMsg(" *********** GetBestPosition -> LAST.2");
					sortedPosTable[kk]->position = GetExtendedSafePosition(myHero->currentPos(), sortedPosTable[kk]->position, extraEvadeDistance);
				}
				//__oMsg(" *********** GetBestPosition -> LAST.3");
				return sortedPosTable[kk];
			}
		}
	}
	
	return SetAllUndodgeable();
}

//-------------------------------------------------//-----------------------//----------
PositionInfo* GetBestPositionMovementBlock(Vec3D movePos)
{
	PositionInfo* result_0 = 0;

	KNpc* myHero = GetPlayer();
	if(!myHero) return result_0;

	int posChecked    = 0;
	int maxPosToCheck = 60;
	int posRadius     = 50;
	int radiusIndex   = 0;

	float extraEvadeDistance = ExtraAvoidDistance_menu;

	Vec3D heroPoint   = myHero->currentPos();
	Vec3D lastMovePos = movePos; //////Game.CursorPos.To2D(); //movePos

	std::vector<PositionInfo*> posTable;

	float extraDist        = ExtraCPADistance_menu;
	float extraDelayBuffer = ExtraPingBuffer_menu;

	while (posChecked < maxPosToCheck)
	{
		radiusIndex++;

		int curRadius       = radiusIndex * (2 * posRadius);
		int curCircleChecks = (int)ceil((2 * 3.1415927f * (float)curRadius) / (2 * (float)posRadius));		

		for (int i = 1; i < curCircleChecks; i++)
		{
			posChecked++;
			float cRadians = (2 * 3.1415927f / (curCircleChecks - 1)) * i; //check decimals

			Vec3D pos((float)floor(heroPoint.x + curRadius * cos(cRadians)), heroPoint.y, (float)floor(heroPoint.z + curRadius * sin(cRadians)));

			PositionInfo* posInfo     = CanHeroWalkToPos(pos, myHero->nMoveSpeed, extraDelayBuffer + (float)GetPingGame(), extraDist);
			posInfo->isDangerousPos   = CheckDangerousPos(pos, 6) || CheckMovePath(pos);
			posInfo->distanceToMouse  = GetPositionValue(pos);
			posInfo->hasExtraDistance = (extraEvadeDistance > 0 && HasExtraAvoidDistance(pos, extraEvadeDistance)) ? true : false;

			posTable.push_back(posInfo);
		}
	}
	
	//__oMsg(" *********** GetBestPositionMovementBlock(Vec3D movePos) : chac chua vao");

	//posTable.OrderBy(p => p.isDangerousPos) .OrderBy(p => p.posDangerLevel) .ThenBy(p => p.hasExtraDistance) .ThenBy(p => p.distanceToMouse);
	std::sort(posTable.begin(), posTable.end(), sort_000);			

	for(int i=0; i<(int)posTable.size(); ++i)
	{
		if (CheckPathCollision(myHero, posTable[i]->position) == false)
		{
			return posTable[i];
		}
	}

	return result_0;
}

//-------------------------------------------------//-----------------------//----------
bool sort_Blink(PositionInfo* p1, PositionInfo* p2)	
{
	//posTable.OrderBy(p => p.isDangerousPos) .ThenBy(p => p.hasExtraDistance) .ThenBy(p => p.distanceToMouse);
	if      (p1->isDangerousPos < p2->isDangerousPos) return true;			//so sanh lay so be hon
	else if (p1->isDangerousPos > p2->isDangerousPos) return false;

	if      (p1->hasExtraDistance < p2->hasExtraDistance) return true;		//so sanh lay so be hon
	else if (p1->hasExtraDistance > p2->hasExtraDistance) return false;

	if      (p1->distanceToMouse < p2->distanceToMouse) return true;		//so sanh lay so be hon
	else if (p1->distanceToMouse > p2->distanceToMouse) return false;

	return false;
}

//-------------------------------------------------//-----------------------//----------
PositionInfo* GetBestPositionBlink()
{
	PositionInfo* result_0 = 0;

	KNpc* myHero = GetPlayer();
	if(!myHero) return result_0;

	int posChecked    = 0;
	int maxPosToCheck = 100;
	int posRadius     = 50;
	int radiusIndex   = 0;

	float extraEvadeDistance = max(100, ExtraEvadeDistance_menu);

	Vec3D heroPoint   = myHero->currentPos();  //--deo-can--//-- ObjectCache.myHeroCache.serverPos2DPing;
	Vec3D lastMovePos = mousePosVec3D(); 

	float minComfortZone = MinComfortZone_menu;

	std::vector<PositionInfo*> posTable;
					
	while (posChecked < maxPosToCheck)
	{
		radiusIndex++;

		int curRadius = radiusIndex * (2 * posRadius);
		int curCircleChecks = (int)ceil((2 * 3.1415927f * (float)curRadius) / (2 * (float)posRadius));

		for (int i = 1; i < curCircleChecks; i++)
		{
			posChecked++;
			float cRadians = (2 * 3.1415927f / (curCircleChecks - 1)) * i; //check decimals

			Vec3D pos((float)floor(heroPoint.x + curRadius * cos(cRadians)), heroPoint.y, (float)floor(heroPoint.z + curRadius * sin(cRadians)));

			bool  isDangerousPos = CheckDangerousPos(pos, 6);
			float dist = GetPositionValue(pos);
			
			PositionInfo* posInfo = new PositionInfo(pos, isDangerousPos, dist);
			posInfo->hasExtraDistance = extraEvadeDistance > 0 ? CheckDangerousPos(pos, extraEvadeDistance) : false;

			posInfo->posDistToChamps = GetDistanceToChampions(pos);

			if (minComfortZone < posInfo->posDistToChamps)
			{
				posTable.push_back(posInfo);
			}
		}
	}

	std::sort(posTable.begin(), posTable.end(), sort_Blink);	//posTable.OrderBy(p => p.isDangerousPos) .ThenBy(p => p.hasExtraDistance) .ThenBy(p => p.distanceToMouse);	
	for(int i = 0; i < (int)posTable.size(); ++i)
	{
		if (CheckPointCollision(myHero, posTable[i]->position) == false)
		{
			return posTable[i];
		}
	}

	return result_0;
}

//-------------------------------------------------//-----------------------//----------
bool sort_Dash(PositionInfo* p1, PositionInfo* p2)	
{
	//posTable.OrderBy(p => p.isDangerousPos) .ThenBy(p => p.posDangerLevel) .ThenBy(p => p.posDangerCount) .ThenBy(p => p.hasExtraDistance) .ThenBy(p => p.distanceToMouse);
	if      (p1->isDangerousPos < p2->isDangerousPos) return true;			//so sanh lay so be hon
	else if (p1->isDangerousPos > p2->isDangerousPos) return false;

	if      (p1->posDangerLevel < p2->posDangerLevel) return true;			//so sanh lay so be hon
	else if (p1->posDangerLevel > p2->posDangerLevel) return false;

	if      (p1->posDangerCount < p2->posDangerCount) return true;			//so sanh lay so be hon
	else if (p1->posDangerCount > p2->posDangerCount) return false;

	if      (p1->hasExtraDistance < p2->hasExtraDistance) return true;		//so sanh lay so be hon
	else if (p1->hasExtraDistance > p2->hasExtraDistance) return false;

	if      (p1->distanceToMouse < p2->distanceToMouse) return true;		//so sanh lay so be hon
	else if (p1->distanceToMouse > p2->distanceToMouse) return false;

	return false;
}

//-------------------------------------------------//-----------------------//----------
PositionInfo* GetBestPositionDash(EvadeSpellData spell)
{
	PositionInfo* result_0 = 0;

	KNpc* myHero = GetPlayer();
	if(!myHero) return 0;

	int posChecked    = 0;
	int maxPosToCheck = 100;
	int posRadius     = 50;
	int radiusIndex   = 0;

	float extraDelayBuffer   = ExtraPingBuffer_menu;
	float extraEvadeDistance = max(100, ExtraEvadeDistance_menu);
	float extraDist          = ExtraCPADistance_menu;

	Vec3D heroPoint   = myHero->currentPos();  //--deo-can--//-- ObjectCache.myHeroCache.serverPos2DPing;
	Vec3D lastMovePos = mousePosVec3D();

	std::vector<PositionInfo*> posTable;
	//std::vector<int> *spellList = GetSpellList();

	int minDistance = 50; //Math.Min(spell.range, minDistance)
	int maxDistance = INT_MAX;

	if (spell.fixedRange)
	{
		minDistance = (int)spell.range;
		maxDistance = (int)spell.range;
	}

	while (posChecked < maxPosToCheck)
	{
		radiusIndex++;

		int curRadius = radiusIndex * (2 * posRadius) + (minDistance - 2 * posRadius);
		int curCircleChecks = (int)ceil((2 * 3.1415927f * (float)curRadius) / (2 * (float)posRadius));

		for (int i = 1; i < curCircleChecks; i++)
		{
			posChecked++;
			float cRadians = (2 * 3.1415927f / (curCircleChecks - 1)) * i; //check decimals
			Vec3D pos((float)floor(heroPoint.x + curRadius * cos(cRadians)), heroPoint.y, (float)floor(heroPoint.z + curRadius * sin(cRadians)));

			PositionInfo* posInfo     = CanHeroWalkToPos(pos, spell.speed, extraDelayBuffer + (float)GetPingGame(), extraDist);
			posInfo->isDangerousPos   = CheckDangerousPos(pos, 6);
			posInfo->hasExtraDistance = extraEvadeDistance > 0 ? CheckDangerousPos(pos, extraEvadeDistance) : false;// ? 1 : 0;                    
			posInfo->distanceToMouse  = GetPositionValue(pos);
			//posInfo->spellList        = spellList;
			posInfo->posDistToChamps  = GetDistanceToChampions(pos);

			posTable.push_back(posInfo);
		}

		if (curRadius >= maxDistance)
			break;
	}

	//posTable.OrderBy(p => p.isDangerousPos) .ThenBy(p => p.posDangerLevel) .ThenBy(p => p.posDangerCount) .ThenBy(p => p.hasExtraDistance) .ThenBy(p => p.distanceToMouse);
	std::sort(posTable.begin(), posTable.end(), sort_Dash);
	for(int i = 0; i < (int)posTable.size(); ++i)
	{
		if (CheckPathCollision(myHero, posTable[i]->position) == false)
		{
			//if (PositionInfoStillValid(posTable[i], spell.speed))
			{
				return posTable[i];
			}
		}
	}
	return 0;
}

//-------------------------------------------------//-----------------------//----------
bool sort_TargetedDash(PositionInfo* p1, PositionInfo* p2)	
{
	//posTable.OrderBy(p => p.isDangerousPos) .ThenBy(p => p.posDangerLevel) .ThenBy(p => p.posDangerCount) .ThenBy(p => p.distanceToMouse);
	if      (p1->isDangerousPos < p2->isDangerousPos) return true;			//so sanh lay so be hon
	else if (p1->isDangerousPos > p2->isDangerousPos) return false;

	if      (p1->posDangerLevel < p2->posDangerLevel) return true;			//so sanh lay so be hon
	else if (p1->posDangerLevel > p2->posDangerLevel) return false;

	if      (p1->posDangerCount < p2->posDangerCount) return true;			//so sanh lay so be hon
	else if (p1->posDangerCount > p2->posDangerCount) return false;

	if      (p1->distanceToMouse < p2->distanceToMouse) return true;		//so sanh lay so be hon
	else if (p1->distanceToMouse > p2->distanceToMouse) return false;

	return false;
}

//-------------------------------------------------//-----------------------//----------
bool sort_TargetedDash2(PositionInfo* p1, PositionInfo* p2)	
{
	//posTable.OrderBy(p => p.isDangerousPos) .ThenBy(p => p.distanceToMouse);
	if      (p1->isDangerousPos < p2->isDangerousPos) return true;			//so sanh lay so be hon
	else if (p1->isDangerousPos > p2->isDangerousPos) return false;

	if      (p1->distanceToMouse < p2->distanceToMouse) return true;		//so sanh lay so be hon
	else if (p1->distanceToMouse > p2->distanceToMouse) return false;

	return false;
}

//-------------------------------------------------//-----------------------//----------
PositionInfo* GetBestPositionTargetedDash(EvadeSpellData spell)
{
	PositionInfo* result_0 = 0;

	KNpc* myHero = GetPlayer();
	if(!myHero) return 0;

	float extraDelayBuffer   = ExtraPingBuffer_menu;
	float extraEvadeDistance = max(100, ExtraEvadeDistance_menu);
	float extraDist			 = ExtraCPADistance_menu;

	Vec3D heroPoint   = myHero->currentPos();  //--deo-can--//-- ObjectCache.myHeroCache.serverPos2DPing;
	Vec3D lastMovePos = mousePosVec3D();

	std::vector<PositionInfo*> posTable;
	//std::vector<int> *spellList = GetSpellList();

	int minDistance = 50;		//Math.Min(spell.range, minDistance)
	int maxDistance = INT_MAX;

	if (spell.fixedRange)
	{
		minDistance = (int)spell.range;
		maxDistance = (int)spell.range;
	}

	std::vector<KNpc*> collisionCandidates;

	
	SpellTargets* phack_1;
	phack_1 = std::find (spell.spellTargets, spell.spellTargets + 6, _Targetables);

	if (phack_1 != spell.spellTargets + 6)
	{
		DWORD tempUnit    = BASE_AttackableUnit     - TEMP_ENTRY_POINT + G_Module;
		DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
		DWORD dw1 = *(DWORD*)tempUnit;
		DWORD dw2 = *(DWORD*)tempUnitMax;
		if (dw1 && dw2 )
		{	
			int nCount = (dw2 - dw1)/4;
			for (int i = 0; i < nCount; ++i)
			{
				DWORD dw3 = *(DWORD*)(dw1 + 4*i);
				KNpc *obj = (KNpc*)dw3;

				if (obj == 0)      continue;
				if (obj == myHero) continue;
				//if (!IsValidTarget(obj, spell.range, false)) continue;
				if (IS_DEAD(obj) == true) continue;
				if (IS_TURRET(obj)) continue;
				if (IsCanSee(obj) == false)  continue;
				if (Distance(myHero, obj) > spell.range) continue;

				if (obj->nTeam_ID == myHero->nTeam_ID)
				{
					if (IS_MINION(obj) && CheckName(sz__Minion, obj->GetNameNpc()) == true) 
					{
						collisionCandidates.push_back(obj);
					}
					else if (IS_HERO(obj))
					{
						collisionCandidates.push_back(obj);
					}
					else if (IS_MINION(obj) && (BYTE)obj->nIsTargetableToTeam == 3)	//dao-kataria
					{
						if (CheckName(sz__HiddenMinion, obj->GetNameNpc()) == true)
							collisionCandidates.push_back(obj);
					}
				}
				else
				{
					if (IS_HERO(obj))
					{
						collisionCandidates.push_back(obj);
					}
				}
			}
		}
	}
	else
	{
		DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
		DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
		DWORD dw1 = *(DWORD*)tempHero;
		DWORD dw2 = *(DWORD*)tempHeroMax;
		if (dw1 && dw2 )
		{	
			int nCount = (dw2 - dw1)/4;
			for (int i = 0; i < nCount; ++i)
			{
				DWORD dw3 = *(DWORD*)(dw1 + 4*i);
				KNpc *hero = (KNpc*)dw3;

				if (hero == 0)      continue;
				if (hero == myHero) continue;
				if (IS_DEAD(hero) == true || (BYTE)hero->nIsTargetableToTeam != 4) continue;
				if (IsCanSee(hero) == false) continue;
				if (Distance(myHero, hero) > spell.range) continue;

				SpellTargets* phack_2;
				phack_2 = std::find (spell.spellTargets, spell.spellTargets + 6, _EnemyChampions);
				SpellTargets* phack_3;
				phack_3 = std::find (spell.spellTargets, spell.spellTargets + 6, _AllyChampions);
				
				if (phack_2 != spell.spellTargets + 6 && phack_3 != spell.spellTargets + 6)
				{
					collisionCandidates.push_back(hero);
				}
				else if (phack_2 != spell.spellTargets + 6 )	//_EnemyChampions
				{
					if (hero->nTeam_ID == myTeamId) continue;
					collisionCandidates.push_back(hero);
				}
				else if (phack_3 != spell.spellTargets + 6 )	//_AllyChampions
				{
					if (hero->nTeam_ID != myTeamId) continue;
					collisionCandidates.push_back(hero);
				}
			}
		}

		DWORD tempUnit    = BASE_AttackableUnit     - TEMP_ENTRY_POINT + G_Module;
		DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
		DWORD dw_1 = *(DWORD*)tempUnit;
		DWORD dw_2 = *(DWORD*)tempUnitMax;
		if (dw_1 && dw_2 )
		{	
			int nCount = (dw_2 - dw_1)/4;
			for (int i = 0; i < nCount; ++i)
			{
				DWORD dw3 = *(DWORD*)(dw_1 + 4*i);
				KNpc *minion = (KNpc*)dw3;

				if (minion == 0)      continue;
				if (minion == myHero) continue;
				if (IS_DEAD(minion) == true || (BYTE)minion->nIsTargetableToTeam != 4) continue;
				if (IS_MINION(minion) == false) continue;
				if (IsCanSee(minion) == false)  continue;
				if (CheckName(sz__Minion, minion->GetNameNpc()) == false) continue;
				if (Distance(myHero, minion) > spell.range) continue;

				SpellTargets* phack_2;
				phack_2 = std::find (spell.spellTargets, spell.spellTargets + 6, _EnemyMinions);
				SpellTargets* phack_3;
				phack_3 = std::find (spell.spellTargets, spell.spellTargets + 6, _AllyMinions);

				if (phack_2 != spell.spellTargets + 6 && phack_3 != spell.spellTargets + 6)
				{
					collisionCandidates.push_back(minion);
				}
				else if (phack_2 != spell.spellTargets + 6 )	//_EnemyMinions
				{
					if (minion->nTeam_ID == myTeamId) continue;
					collisionCandidates.push_back(minion);
				}
				else if (phack_3 != spell.spellTargets + 6 )	//_AllyMinions
				{
					if (minion->nTeam_ID != myTeamId) continue;
					collisionCandidates.push_back(minion);
				}
			}
		}
	}

	for (int i = 0; i < (int)collisionCandidates.size(); ++i)
	{
		KNpc* candidate = collisionCandidates[i];
		if (IsUnitInList(candidate) == false) continue;

		Vec3D pos = candidate->currentPos();
		PositionInfo* posInfo = 0;

		if (spell.spellName.compare(sz__YasuoDashWrapper) == 0)
		{
			bool hasDashBuff = false;
			if (GET_BUFF(candidate, sz__YasuoDashWrapper) != 0)
			{
				hasDashBuff = true;
			}
			if (hasDashBuff)
				continue;
		}

		if (spell.behindTarget)
		{
			Vec3D dir = (pos - heroPoint).Normalized();
			pos = pos + dir * (BoundRadius_Minion(candidate) + BoundRadius(myHero));
		}

		if (spell.infrontTarget)
		{
			Vec3D dir = (pos - heroPoint).Normalized();
			pos = pos - dir * (BoundRadius_Minion(candidate) + BoundRadius(myHero));
		}

		if (spell.fixedRange)
		{
			Vec3D dir = (pos - heroPoint).Normalized();
			pos = heroPoint + dir * spell.range;
		}

		if (spell.evadeType == _Dash)
		{
			posInfo = CanHeroWalkToPos(pos, spell.speed, extraDelayBuffer + (float)GetPingGame(), extraDist);
			posInfo->isDangerousPos  = CheckDangerousPos(pos, 6);
			posInfo->distanceToMouse = GetPositionValue(pos);
			//posInfo->spellList = spellList;
		}
		else
		{
			bool  isDangerousPos = CheckDangerousPos(pos, 6);
			float dist           = GetPositionValue(pos);

			posInfo = new PositionInfo(pos, isDangerousPos, dist);
		}

		posInfo->target = candidate;
		posTable.push_back(posInfo);
	}

	if (spell.evadeType == _Dash)
	{
		if ((int)posTable.size() > 0)
		{
			//posTable.OrderBy(p => p.isDangerousPos) .ThenBy(p => p.posDangerLevel) .ThenBy(p => p.posDangerCount) .ThenBy(p => p.distanceToMouse);
			std::sort(posTable.begin(), posTable.end(), sort_TargetedDash);
			for(int i = 0; i < (int)posTable.size(); ++i)
			{
				//__oMsg("for-iii");
				if (posTable[i] != 0 && _Evade->lastPosInfo != 0 && posTable[i]->isDangerousPos == false && _Evade->lastPosInfo->posDangerLevel >= posTable[i]->posDangerLevel)
				{
					//__oMsg("for-xxx : %d -------------", i);
					//Cast2Target(posTable[i]->target, _W);
					return posTable[i];
				}
			}
		}
		
	}
	else
	{
		if ((int)posTable.size() > 0)
		{
			//posTable.OrderBy(p => p.isDangerousPos) .ThenBy(p => p.distanceToMouse);
			std::sort(posTable.begin(), posTable.end(), sort_TargetedDash2);
			//for(int i = 0; i < (int)posTable.size(); ++i)
			//{
			//	__oMsg("i=%d, is_danger = %d, danger = %d", i, posTable[i]->isDangerousPos, posTable[i]->posDangerLevel);
			//}
			return posTable[0];
		}
	}

	return 0;
}

//-------------------------------------------------//-----------------------//----------
bool PositionInfoStillValid(PositionInfo* posInfo, float moveSpeed)
{
	return true; //too buggy
}

//-------------------------------------------------//-----------------------//----------
Vec3D GetExtendedSafePosition(Vec3D from, Vec3D to, float extendDistance)
{
	if (to.y == 0 && from.y != 0) to.y   = from.y;
	if (to.y != 0 && from.y == 0) from.y = to.y;

	Vec3D direction = (to - from).Normalized();
	Vec3D lastPosition = to;
	float sectorDistance = 50;
	
	KNpc* myHero = GetPlayer();
	if(!myHero) return lastPosition;

	for (float i = sectorDistance; i <= extendDistance; i += sectorDistance)
	{
		Vec3D pos = to + direction * i;

		if (CheckDangerousPos(pos, 6) || CheckPathCollision(myHero, pos))
		{
			return lastPosition;
		}

		lastPosition = pos;
	}

	return lastPosition;
}

//-------------------------------------------------//-----------------------//----------
void CalculateEvadeTime()
{
	KNpc* myHero = GetPlayer();
	if (!myHero) return;

	for (std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->begin(); it_spells!= _SpellDetector->spells->end(); ++it_spells)
	{
		Spell spell = it_spells->second;
		float evadeTime, spellHitTime;
		CanHeroEvade(spell, myHero, evadeTime, spellHitTime);

		spell.spellHitTime = spellHitTime;
		spell.evadeTime = evadeTime;
	}
}

//-------------------------------------------------//-----------------------//----------
Vec3D GetFastestPosition(Spell spell)
{
	Vec3D vZezo(0,0,0);
	KNpc* myHero = GetPlayer();
	if (!myHero) return vZezo;

	Vec3D heroPos = myHero->currentPos();

	if (spell.spellType == Line)
	{
		Vec3D projection = ProjectOn(heroPos, spell.startPos, spell.endPos).SegmentPoint;
		//projection.y = heroPos.y;

		//__oMsg("GetFastestPosition: radius = %f", spell.radius);
		Vec3D vExtend = Extend(projection, heroPos, spell.radius + BoundRadius(myHero) + 15);
		//Vec3D xxx =		(heroPos - projection).Normalized();

		//float KC = spell.radius + BoundRadius(myHero) + 20 - projection.Distance2D(heroPos);
		//__oMsg("[%f]KC den diem ne' = %f, tgian(ms) = %f", spell.radius + BoundRadius(myHero) + 20, KC, 1000*KC/myHero->nMoveSpeed);

		//__oMsg("GetFastestPosition ----VKL : %f, %f, %f (dis: %f)(leng: %f)", xxx.x, xxx.y, xxx.z, projection.Distance2D(heroPos), xxx.Leng());
		////v + (to - v).Normalized() * distance

		//__oMsg("GetFastestPosition->projection(%f, %f, %f) : %f (%f) - radius: %f",projection.x, projection.y, projection.z, projection.Distance2D(vExtend), spell.radius + BoundRadius(myHero) + 520, spell.radius);
		return vExtend;
	}
	else if (spell.spellType == Circular)
	{
		return Extend(spell.endPos, heroPos, spell.radius + 15);
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
		}
		Vec3D vExtend = Extend(heroPos, p, nDistant + BoundRadius(myHero) + 15);
		return vExtend;
	}

	return vZezo;
}

//-------------------------------------------------//-----------------------//----------
std::vector<Vec3D> GetFastestPositions()
{
	std::vector<Vec3D> positions;
	
	for (std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->begin(); it_spells!= _SpellDetector->spells->end(); ++it_spells)
	{
		Spell spell = it_spells->second;
		Vec3D pos = GetFastestPosition(spell);
		if (pos.IsValid())
		{
			//__oMsg("pos.IsValid()");
			positions.push_back(pos);
		}
	}

	return positions;
}

//-------------------------------------------------//-----------------------//----------
float GetMinCPADistance(Vec3D movePos)
{
	float minDist = FLT_MAX;
	KNpc* myHero = GetPlayer();
	if(!myHero) return minDist;

	Vec3D heroPoint = myHero->currentPos();
	//Vec3D serverPos2DPing = GetGamePosition(myHero, (float)GetPingGame());

	for (std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->begin(); it_spells!= _SpellDetector->spells->end(); ++it_spells)
	{
		Spell spell = it_spells->second;
		//minDist = min(minDist, GetClosestDistanceApproach(spell, movePos, myHero->nMoveSpeed, (float)GetPingGame(), serverPos2DPing, 0));
		minDist = min(minDist, GetClosestDistanceApproach(spell, movePos, myHero->nMoveSpeed, (float)GetPingGame(), heroPoint, 0));
	}

	return minDist;
}

//-------------------------------------------------//-----------------------//----------
Vec3D GetNearWallPoint(Vec3D start, Vec3D end)
{
	Vec3D direction = (end - start).Normalized();
	float distance  = Distance(start, end) + 125;
	for (float i = 5; i < distance; i += 5)
	{
		/*Vec3D v = end - direction * i;
		if (IsWall(&v))
		{
			return v;
		}*/
		Vec3D v = start + direction * i;
		if (IsWall(&v))
		{
			//if (i >= 180) v = start + direction * (i - 180);
			return v;
		}
	}

	Vec3D zezo(0,0,0);
	return zezo;
}

//-------------------------------------------------//-----------------------//----------
PositionInfo* CanHeroWalkToPos(Vec3D pos, float speed, float delay, float extraDist, bool useServerPosition)
{
	KNpc* myHero = GetPlayer();
	if(!myHero)
	{
		PositionInfo* chackovao = new PositionInfo;
		return chackovao;
	}

	int posDangerLevel = 0;
	int posDangerCount = 0;
	float closestDistance = FLT_MAX;
	std::vector<int> *dodgeableSpells   = new std::vector<int>;
	std::vector<int> *undodgeableSpells = new std::vector<int>;

	Vec3D heroPos = myHero->currentPos();

	float minComfortDistance = MinComfortZone_menu;	// default = 550

	if (useServerPosition == false)
	{
		heroPos = myHero->currentPos();
	}
	
	for (std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->begin(); it_spells!= _SpellDetector->spells->end(); ++it_spells)
	{
		Spell spell = it_spells->second;
		
		//__oMsg("xxx: %f, closestDistance: %f", GetClosestDistanceApproach(spell, pos, speed, delay, heroPos, extraDist), closestDistance);

		closestDistance = min(closestDistance, GetClosestDistanceApproach(spell, pos, speed, delay, heroPos, extraDist));
		
		//__oMsg("hero: %d, pos: %d", InSkillShot(heroPos, spell, BoundRadius(myHero)), InSkillShot(pos, spell, BoundRadius(myHero) + 6));
		//__oMsg("DK1: %d, DK2: %d, DK3: %d", InSkillShot(pos, spell, BoundRadius(myHero) + 6), PredictSpellCollision(spell, pos, speed, delay, heroPos, extraDist, useServerPosition),
		//	(spell.info.spellType != Line && isNearEnemy(pos, minComfortDistance)));

		if (InSkillShot(pos, spell, BoundRadius(myHero) + 6)
			|| PredictSpellCollision(spell, pos, speed, delay, heroPos, extraDist, useServerPosition)
			|| (spell.info.spellType != Line && isNearEnemy(pos, minComfortDistance)))
		{
			posDangerLevel  = max(posDangerLevel, spell.dangerlevel);
			posDangerCount += spell.dangerlevel;
			//__oMsg("posDangerLevel: %d, posDangerCount: %d, spell.dangerlevel : %d, closestDistance: %f", posDangerLevel, posDangerCount,spell.dangerlevel, closestDistance);
			//__oMsg("undodgeableSpells, pos: %.3f, %.3f, %.3f", pos.x, pos.y, pos.z);
			undodgeableSpells->push_back(spell.spellID);
		}
		else
		{
			//__oMsg("dodgeableSpells, pos: %.3f, %.3f, %.3f", pos.x, pos.y, pos.z);
			dodgeableSpells->push_back(spell.spellID);
		}
	}
	bool isPosDangerCount = (posDangerCount > 0) ? true : false;
	PositionInfo* result = new PositionInfo(pos, posDangerLevel, posDangerCount, isPosDangerCount, closestDistance, dodgeableSpells, undodgeableSpells);
	return result;

}

//-------------------------------------------------//-----------------------//----------
float GetClosestDistanceApproach(Spell spell, Vec3D pos, float speed, float delay, Vec3D heroPos, float extraDist)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return 1.1f;
	
	if(pos.y == 0)	   pos.y	 = myHero->CurrentPos.y;
	if(heroPos.y == 0) heroPos.y = myHero->CurrentPos.y;

	Vec3D walkDir = (pos - heroPos).Normalized();

	if (spell.spellType == Line && spell.info.projectileSpeed != FLT_MAX)
	{
		Vec3D spellPos    = GetCurrentSpellPosition(spell, true, delay);
		Vec3D spellEndPos = GetSpellEndPosition(spell);
		Vec3D extendedPos = ExtendDir(pos, walkDir, BoundRadius(myHero) + speed * delay / 1000);

		Vec3D cHeroPos;
		Vec3D cSpellPos;

		float cpa2 = GetCollisionDistanceEx(heroPos, walkDir * speed, BoundRadius(myHero),
			spellPos, spell.direction * spell.info.projectileSpeed, spell.radius + extraDist, cHeroPos, cSpellPos);

		ProjectionInfo cHeroPosProjection  = ProjectOn(cHeroPos, heroPos, extendedPos);
		ProjectionInfo cSpellPosProjection = ProjectOn(cSpellPos, spellPos, spellEndPos);

		if (cSpellPosProjection.IsOnSegment && cHeroPosProjection.IsOnSegment && cpa2 != FLT_MAX)
		{
			return 0;
		}

		float cpa = CPAPointsEx(heroPos, walkDir * speed, spellPos, spell.direction * spell.info.projectileSpeed, pos, spellEndPos, cHeroPos, cSpellPos);

		cHeroPosProjection  = ProjectOn(cHeroPos, heroPos, extendedPos);
		cSpellPosProjection = ProjectOn(cSpellPos, spellPos, spellEndPos);

		float checkDist = BoundRadius(myHero) + spell.radius + extraDist;
		
		//__oMsg("checkDist: %f, cpa: %f  ==> %f", checkDist, cpa, cpa - checkDist);
		if (cSpellPosProjection.IsOnSegment && cHeroPosProjection.IsOnSegment)
		{
			//__oMsg("1-checkDist: %f", (float)max(0, cpa - checkDist));
			return (float)max(0, cpa - checkDist);
		}
		//__oMsg("2-checkDist: %f", checkDist);
		return checkDist;

		//return MathUtils.ClosestTimeOfApproach(heroPos, walkDir * speed, spellPos, spell.direction * spell.info.projectileSpeed);
	}
	else if (spell.spellType == Line && spell.info.projectileSpeed == FLT_MAX)
	{
		float spellHitTime   = max(0, spell.endTime - (float)GetTickCount() - delay);  //extraDelay
		float walkRange      = heroPos.Distance2D(pos);
		float predictedRange = speed * (spellHitTime / 1000);
		Vec3D tHeroPos       = heroPos + walkDir * min(predictedRange, walkRange); //Hero predicted pos

		ProjectionInfo projection = ProjectOn(tHeroPos, spell.startPos, spell.endPos);

		return max(0, tHeroPos.Distance2D(projection.SegmentPoint) - (spell.radius + BoundRadius(myHero) + extraDist)); //+ dodgeBuffer
	}
	else if (spell.spellType == Circular)
	{
		float spellHitTime = max(0, spell.endTime - (float)GetTickCount() - delay);  //extraDelay
		float walkRange = heroPos.Distance2D(pos);
		float predictedRange = speed * (spellHitTime / 1000);
		Vec3D tHeroPos = heroPos + walkDir * min(predictedRange, walkRange); //Hero predicted pos

		if (spell.info.spellName == "VeigarEventHorizon")
		{
			float wallRadius = 65;
			float midRadius = spell.radius - wallRadius;

			if (spellHitTime == 0)
			{
				return 0;
			}

			return tHeroPos.Distance2D(spell.endPos) >= spell.radius
				? max(0, tHeroPos.Distance2D(spell.endPos) - midRadius - wallRadius)
				: max(0, midRadius - tHeroPos.Distance2D(spell.endPos) - wallRadius);
		}

		if (spell.info.spellName == "DariusCleave")
		{
			float wallRadius = 115;
			float midRadius = spell.radius - wallRadius;

			if (spellHitTime == 0)
			{
				return 0;
			}

			return tHeroPos.Distance2D(spell.endPos) >= spell.radius
				? max(0, tHeroPos.Distance2D(spell.endPos) - midRadius - wallRadius)
				: max(0, midRadius - tHeroPos.Distance2D(spell.endPos) - wallRadius);
		}
		
		//__oMsg("[Circle]: KC1: %.3f, KC2: %.3f", tHeroPos.Distance2D(spell.endPos), spell.radius + extraDist);
		float closestDist = max(0, tHeroPos.Distance2D(spell.endPos) - (spell.radius + extraDist));
		if (spell.info.extraEndTime > 0 && closestDist != 0)
		{
			float remainingTime = max(0, spell.endTime + spell.info.extraEndTime - (float)GetTickCount() - delay);
			float predictedRange2 = speed * (remainingTime / 1000);
			Vec3D tHeroPos2 = heroPos + walkDir * min(predictedRange2, walkRange);

			if (CheckMoveToDirection(tHeroPos, tHeroPos2))
			{
				//__oMsg("[Circle]: extraEndTime > 0 ===> lux-eee-1");
				return 0;
			}
		}
		else
		{
			//__oMsg("lux-eee-2");
			return closestDist;
		}
	}
	else if (spell.spellType == Arc_x)
	{
		Vec3D spellPos    = GetCurrentSpellPosition(spell, true, delay);
		Vec3D spellEndPos = GetSpellEndPosition(spell);

		Vec3D pDir  = Perpendicular(spell.direction);
		spellPos    = spellPos - pDir * spell.radius / 2;
		spellEndPos = spellEndPos - pDir * spell.radius / 2;

		Vec3D extendedPos = ExtendDir(pos, walkDir, BoundRadius(myHero));

		Vec3D cHeroPos;
		Vec3D cSpellPos;

		float cpa = CPAPointsEx(heroPos, walkDir * speed, spellPos, spell.direction * spell.info.projectileSpeed, pos, spellEndPos, cHeroPos, cSpellPos);

		ProjectionInfo cHeroPosProjection  = ProjectOn(cHeroPos, heroPos, extendedPos);
		ProjectionInfo cSpellPosProjection = ProjectOn(cSpellPos, spellPos, spellEndPos);

		float checkDist = spell.radius + extraDist;

		if (InSkillShot(cHeroPos, spell, BoundRadius(myHero)))
		{
			if (cSpellPosProjection.IsOnSegment && cHeroPosProjection.IsOnSegment)
			{
				return max(0, cpa - checkDist);
			}
			else
			{
				return checkDist;
			}
		}
	}
	else if (spell.spellType == Cone)
	{
		float spellHitTime = max(0, spell.endTime - (float)GetTickCount() - delay);  //extraDelay
		float walkRange = heroPos.Distance2D(pos);
		float predictedRange = speed * (spellHitTime / 1000);
		Vec3D tHeroPos = heroPos + walkDir * min(predictedRange, walkRange); //Hero predicted pos

		std::vector<Vec3D> sides;
		sides.push_back(ProjectOn(heroPos, spell.cnStart, spell.cnLeft).SegmentPoint);
		sides.push_back(ProjectOn(heroPos, spell.cnLeft, spell.cnRight).SegmentPoint);
		sides.push_back(ProjectOn(heroPos, spell.cnRight, spell.cnStart).SegmentPoint);

		Vec3D p;
		float nDistant = FLT_MAX;
		for(int i=0; i < (int)sides.size(); i++)
		{
			if(heroPos.Distance2D(sides[i]) < nDistant)
			{
				nDistant = heroPos.Distance2D(sides[i]);
				p = sides[i];
			}
		}

		//return max(0, tHeroPos.Distance2D(p) - (spell.radius + BoundRadius(myHero) + extraDist));	//DOAN NAY CHAC CHAN SAI
		//__oMsg("[Cone]: KC1: %f, KC2: %f", tHeroPos.Distance2D(heroPos), (p.Distance2D(heroPos) + BoundRadius(myHero) + extraDist));
		return max(0, tHeroPos.Distance2D(heroPos) - (p.Distance2D(heroPos) + BoundRadius(myHero) + extraDist));	
	}

	return 1;
}

//-------------------------------------------------//-----------------------//----------
bool PredictSpellCollision(Spell spell, Vec3D pos, float speed, float delay, Vec3D heroPos, float extraDist, bool useServerPosition)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return false;

	//extraDist = extraDist + 10;
	
	//return GetClosestDistanceApproach(spell, pos, speed, 0, myHero->currentPos(), 0) == 0;

	//--- deo can tinh ping peo gi ca
	if (useServerPosition == false)
	{
		return GetClosestDistanceApproach(spell, pos, speed, 0, myHero->currentPos(), 0) == 0;
	}

	return
		GetClosestDistanceApproach(spell, pos, speed, delay, //Game.Ping + Extra Buffer
		myHero->currentPos(), extraDist) == 0
		|| GetClosestDistanceApproach(spell, pos, speed, (float)GetPingGame(), //Game.Ping
		myHero->currentPos(), extraDist) == 0;


	//Vec3D serverPos2DPing = GetGamePosition(myHero, (float)GetPingGame());

	//return
	//	GetClosestDistanceApproach(spell, pos, speed, delay, //Game.Ping + Extra Buffer
	//	serverPos2DPing, extraDist) == 0
	//	|| GetClosestDistanceApproach(spell, pos, speed, (float)GetPingGame(), //Game.Ping
	//	serverPos2DPing, extraDist) == 0;
}

//-------------------------------------------------//-----------------------//----------
bool CheckPathCollision(KNpc* unit, Vec3D movePos)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return false;

	std::vector<Vec3D> path = Unit_GetPath(unit, myHero->currentPos(), movePos);

	if ((int)path.size() > 0)
	{
		if (movePos.Distance2D(path.back()) > 5 || path.size() > 2)
		{
			return true;
		}
	}
	return false;
}

//-------------------------------------------------//-----------------------//----------
bool CheckPointCollision(KNpc* unit, Vec3D movePos)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return false;

	std::vector<Vec3D> path = Unit_GetPath(unit, myHero->currentPos(), movePos);
	if ((int)path.size() > 0)
	{
		if (movePos.Distance2D(path.back()) > 5)
		{
			return true;
		}
	}
	return false;
}

//-------------------------------------------------//-----------------------//----------
bool CheckMovePath(Vec3D movePos, float extraDelay)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return false;

    ///////////*if (EvadeSpell.lastSpellEvadeCommand.evadeSpellData != null)
    //////////{
    //////////    var evadeSpell = EvadeSpell.lastSpellEvadeCommand.evadeSpellData;
    //////////    float evadeTime = ObjectCache.gamePing;

    //////////    if (EvadeSpell.lastSpellEvadeCommand.evadeSpellData.evadeType == EvadeType.Dash)
    //////////        evadeTime += evadeSpell.spellDelay + ObjectCache.myHeroCache.serverPos2D.Distance(movePos) / (evadeSpell.speed / 1000);
    //////////    else if (EvadeSpell.lastSpellEvadeCommand.evadeSpellData.evadeType == EvadeType.Blink)
    //////////        evadeTime += evadeSpell.spellDelay;

    //////////    if (Evade.GetTickCount - EvadeSpell.lastSpellEvadeCommand.timestamp < evadeTime)
    //////////    {

    //////////        Console.WriteLine("in" + CheckMoveToDirection(EvadeSpell.lastSpellEvadeCommand.targetPosition, movePos));
    //////////        return CheckMoveToDirection(EvadeSpell.lastSpellEvadeCommand.targetPosition, movePos);
    //////////    }
    //////////}*/

    Vec3D startPoint = myHero->currentPos();
    
    //if (IsDashing(myHero))
    //{
	//	Vec3D EndPos = GET_END_POS(myHero);
	//	if(EndPos.IsValid())
	//		startPoint = EndPos;                
    //}
    
	std::vector<Vec3D> path = Unit_GetPath(myHero, startPoint, movePos); //from serverpos
    Vec3D lastPoint(0,0,0);
	
	for(int kk=0; kk<(int)path.size(); kk++)
	{
		if(lastPoint.IsValid() && CheckMoveToDirection(lastPoint, path[kk], extraDelay))
		{
			return true;
		}

		if (lastPoint.IsValid())
		{
			lastPoint = path[kk];
		}
		else
		{
			lastPoint = myHero->currentPos();
		}
	}

    return false;
}

//-------------------------------------------------//-----------------------//----------
bool LineIntersectLinearSegment(Vec3D a1, Vec3D b1, Vec3D a2, Vec3D b2)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return false;

	int segmentRadius = 55;

	float myBoundingRadius = BoundRadius(myHero);
	Vec3D segmentDir	   = Perpendicular((b1 - a1).Normalized());
	Vec3D segmentStart	   = a1;
	Vec3D segmentEnd	   = b1;

	Vec3D startRightPos = segmentStart + segmentDir * (segmentRadius + myBoundingRadius);
	Vec3D startLeftPos  = segmentStart - segmentDir * (segmentRadius + myBoundingRadius);
	Vec3D endRightPos   = segmentEnd   + segmentDir * (segmentRadius + myBoundingRadius);
	Vec3D endLeftPos    = segmentEnd   - segmentDir * (segmentRadius + myBoundingRadius);

	bool int1 = CheckLineIntersection(a2, b2, startRightPos, startLeftPos);
	bool int2 = CheckLineIntersection(a2, b2, endRightPos, endLeftPos);
	bool int3 = CheckLineIntersection(a2, b2, startRightPos, endRightPos);
	bool int4 = CheckLineIntersection(a2, b2, startLeftPos, endLeftPos);

	if (int1 || int2 || int3 || int4)
	{
		return true;
	}

	return false;
}

//-------------------------------------------------//-----------------------//----------
bool CheckMoveToDirection(Vec3D from, Vec3D movePos, float extraDelay)
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return false;

	Vec3D dir = (movePos - from).Normalized();
	/////movePos = movePos.ExtendDir(dir, ObjectCache.myHeroCache.boundingRadius);
	
	for (std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->begin(); it_spells!= _SpellDetector->spells->end(); ++it_spells)
	{
		Spell spell = it_spells->second;	
		
		if (!InSkillShot(from, spell, BoundRadius(myHero)))
		{
			Vec3D spellPos = spell.currentSpellPosition;

			if (spell.spellType == Line)
			{
				if (LineIntersectLinearSpell(spell, from, movePos))	
					return true;
			}
			else if (spell.spellType == Circular)
			{
				if (spell.info.spellName == "VeigarEventHorizon")
				{
					Vec3D vZezo(0,0,0);
					float cpa2 = CPAPointsEx(from, dir * myHero->nMoveSpeed, spell.endPos, vZezo, movePos, spell.endPos);

					if (from.Distance2D(spell.endPos) < spell.radius && !(from.Distance2D(spell.endPos) < spell.radius - 135 && movePos.Distance2D(spell.endPos) < spell.radius - 135))
					{
						return true;
					}
					else if (from.Distance2D(spell.endPos) > spell.radius && cpa2 < spell.radius + 10)
					{
						return true;
					}
				}
				else if (spell.info.spellName == "DariusCleave")
				{
					Vec3D vZezo(0,0,0);
					float cpa3 = CPAPointsEx(from, dir * myHero->nMoveSpeed, spell.endPos, vZezo, movePos, spell.endPos);

					if (from.Distance2D(spell.endPos) < spell.radius && !(from.Distance2D(spell.endPos) < spell.radius - 230 && movePos.Distance2D(spell.endPos) < spell.radius - 230))
					{
						return true;
					}
					else if (from.Distance2D(spell.endPos) > spell.radius && cpa3 < spell.radius + 10)
					{
						return true;
					}
				}
				else
				{
					Vec3D cHeroPos;
					Vec3D cSpellPos;
					Vec3D vZezo(0,0,0);
					float cpa2 = GetCollisionDistanceEx(from, dir * myHero->nMoveSpeed, 1, spell.endPos, vZezo, spell.radius, cHeroPos, cSpellPos);
					
					if(CheckName("_trap", (char*)spell.info.spellName.c_str()) && !(cpa2 < spell.radius + 10))
					{
						continue;
					}

					ProjectionInfo cHeroPosProjection = ProjectOn(cHeroPos, from, movePos);
					if (cHeroPosProjection.IsOnSegment && cpa2 != FLT_MAX)
					{
						return true;
					}
				}
			}
			else if (spell.spellType == Arc_x)
			{
				if (isLeftOfLineSegment(from, spell.startPos, spell.endPos))
				{
					return CheckLineIntersection(from, movePos, spell.startPos, spell.endPos);
				}

				float spellRange = spell.startPos.Distance2D(spell.endPos);
				Vec3D midPoint = spell.startPos + spell.direction * (spellRange / 2);
				Vec3D vZezo(0,0,0);

				float cpa = CPAPointsEx(from, dir * myHero->nMoveSpeed, midPoint, vZezo, movePos, midPoint);

				if (cpa < spell.radius + 10)
				{
					return true;
				}
			}
			else if (spell.spellType == Cone)
			{
				if (LineIntersectLinearSegment(spell.cnStart, spell.cnLeft, from, movePos) ||
					LineIntersectLinearSegment(spell.cnLeft, spell.cnRight, from, movePos) ||
					LineIntersectLinearSegment(spell.cnRight, spell.cnStart, from, movePos))
					return true;
			}
		}
	}

	return false;
}