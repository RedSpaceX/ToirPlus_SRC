#include "SpellDetector.h"
#include "EvadeUtils.h"
#include "Situation.h"
#include "Evade.h"
#include "SpellSpecial.h"
#include "DodSpecial_1.h"
#include "DodSpecial_2.h"

extern  DWORD				G_Module;
extern  int					myTeamId;
extern  KNpc*				MY_HERO;
extern  bool				canUse_VMT;

extern  EvadeUtils*			_EvadeUtils;
extern  SpellDetector*		_SpellDetector;
extern  SpellDatabase*		_SpellDatabase;
extern	EvadeHelper*		_EvadeHelper;
extern	Evade*				_Evade;

//int		spellIDCount = 0;

extern bool CheckSpellCollision_menu, AdvancedSpellDetection_menu, DodgeCircularSpells_menu, DodgeFOWSpells_menu;
extern float ExtraPingBuffer_menu, SpellDetectionTime_menu, ReactionTime_menu, DodgeInterval_menu;
//-------------------------------------------------//-----------------------//----------
int CreateSpell(Spell &newSpell, bool processSpell)
{
	
	int spellID = _SpellDetector->spellIDCount++;
	newSpell.spellID = spellID;

	UpdateSpellInfo(newSpell);
	_SpellDetector->detectedSpells->insert(std::pair<int, Spell> (spellID, newSpell));
	//__oMsg("[*INSERTED*]->_SpellDetector->DETECTED_SPELLS.ID = %d", spellID);

	if (processSpell)
	{
		CheckSpellCollision_SpD();
		AddDetectedSpells();
	}
	
	//__oMsg("in-CreateSpell: %d", spellID);
	return spellID;
}


//public static SpellSlot GetSpellSlot(this AIHeroClient unit, string name)
//{
//	foreach (var spell in
//		unit.Spellbook.Spells.Where(
//		spell => String.Equals(spell.Name, name, StringComparison.CurrentCultureIgnoreCase)))
//	{
//		return spell.Slot;
//	}
//
//	return SpellSlot.Unknown;
//}


//-------------------------------------------------//-----------------------//----------
void DeleteSpell_11(int spellID)
{
	std::map<int, Spell>::iterator it_1111 = _SpellDetector->spells->find(spellID); 
	if (it_1111 != _SpellDetector->spells->end())
	{
		_SpellDetector->spells->erase(it_1111);
		return;
	}
}

//-------------------------------------------------//-----------------------//----------
void DeleteSpell_22(int spellID)
{
	std::map<int, Spell>::iterator it_2222 = _SpellDetector->drawSpells->find(spellID); 
	if (it_2222 != _SpellDetector->drawSpells->end())
	{
		_SpellDetector->drawSpells->erase(it_2222);
		return;
	}
}

//-------------------------------------------------//-----------------------//----------
void DeleteSpell_33(int spellID)
{
	std::map<int, Spell>::iterator it_3333 = _SpellDetector->detectedSpells->find(spellID); 
	if (it_3333 != _SpellDetector->detectedSpells->end())
	{
		_SpellDetector->detectedSpells->erase(it_3333);
		return;
	}
}

//-------------------------------------------------//-----------------------//----------
void DeleteSpell(int spellID)
{
	DeleteSpell_11(spellID);
	DeleteSpell_22(spellID);
	DeleteSpell_33(spellID);

	//////return;
	////std::map<int, Spell>::iterator it_1111 = _SpellDetector->spells->find(spellID); 
	////if (it_1111 != _SpellDetector->spells->end())
	////{
	////	_SpellDetector->spells->erase(it_1111);
	////	//break;
	////}
	////
	////std::map<int, Spell>::iterator it_2222 = _SpellDetector->drawSpells->find(spellID); 
	////if (it_2222 != _SpellDetector->drawSpells->end())
	////{
	////	_SpellDetector->drawSpells->erase(it_2222);
	////	//break;
	////}

	////std::map<int, Spell>::iterator it_3333 = _SpellDetector->detectedSpells->find(spellID); 
	////if (it_3333 != _SpellDetector->detectedSpells->end())
	////{
	////	_SpellDetector->detectedSpells->erase(it_3333);
	////	//break;
	////}
}

//-------------------------------------------------//-----------------------//----------
int GetCurrentSpellID()
{
	return _SpellDetector->spellIDCount;
}

//-------------------------------------------------//-----------------------//----------
std::vector<int>* GetSpellList()
{
	std::vector<int>* spellList = 0;
	
	for (std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->begin(); it_spells!= _SpellDetector->spells->end(); ++it_spells)
	{
		Spell spell = it_spells->second;
		spellList->push_back(spell.spellID);
	}

	return spellList;
}

//-------------------------------------------------//-----------------------//----------
int GetHighestDetectedSpellID()
{
	int highest = 0;
	
	for (std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->begin(); it_spells!= _SpellDetector->spells->end(); ++it_spells)
	{
		highest = max(highest, it_spells->first);	//key
	}

	return highest;
}

//-------------------------------------------------//-----------------------//----------
float GetLowestEvadeTime(Spell &lowestSpell)
{
	float lowest = FLT_MAX;
	//lowestSpell = null;
	
	for (std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->begin(); it_spells!= _SpellDetector->spells->end(); ++it_spells)
	{
		Spell spell = it_spells->second;
		
		if (spell.spellHitTime != FLT_MIN)
		{
			//Console.WriteLine("spellhittime: " + spell.spellHitTime);
			lowest = min(lowest, (spell.spellHitTime - spell.evadeTime));
			lowestSpell = spell;
		}
	}

	return lowest;
}

//-------------------------------------------------//-----------------------//----------
Spell GetMostDangerousSpell(bool hasProjectile)
{
	int maxDanger = 0;
	Spell maxDangerSpell;
	
	for (std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->begin(); it_spells!= _SpellDetector->spells->end(); ++it_spells)
	{
		Spell spell = it_spells->second;
		
		if (!hasProjectile || (spell.info.projectileSpeed > 0 && spell.info.projectileSpeed != FLT_MAX))
		{
			int dangerlevel = spell.dangerlevel;

			if (dangerlevel > maxDanger)
			{
				maxDanger = dangerlevel;
				maxDangerSpell = spell;
			}
		}
	}

	return maxDangerSpell;
}

//-------------------------------------------------//-----------------------//----------
void CreateSpellData(KNpc* hero, Vec3D spellStartPos, Vec3D spellEndPos, SpellData spellData, KNpc* obj, float extraEndTick, bool processSpell, SpellType spellType, bool checkEndExplosion, float spellRadius)
{
	if ( !MY_HERO ) return;

	if (checkEndExplosion && spellData.hasEndExplosion)
	{
		CreateSpellData(hero, spellStartPos, spellEndPos, spellData, obj, extraEndTick, false, spellData.spellType, false);

		CreateSpellData(hero, spellStartPos, spellEndPos, spellData, obj, extraEndTick, true, Circular, false);

		return;
	}

	if (spellStartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
	{
		Vec3D startPosition = spellStartPos;
		Vec3D endPosition   = spellEndPos;
		Vec3D direction     = (endPosition - startPosition).Normalized();
		float endTick = 0;

		if (spellType == None)
		{
			spellType = spellData.spellType;
		}

		if (spellData.fixedRange) //for diana q
		{
			if (endPosition.Distance2D(startPosition) > spellData.range)
				endPosition = startPosition + direction * spellData.range;
		}

		if (spellType == Line)
		{
			endTick = spellData.spellDelay + (spellData.range / spellData.projectileSpeed) * 1000;
			endPosition = startPosition + direction * spellData.range;

			if (spellData.fixedRange) // for all lines
			{
				if (endPosition.Distance2D(startPosition) < spellData.range)
				{
					endPosition = startPosition + direction * spellData.range;
				}
			}
			
			//... ADD MORE ...
			if (spellData.EndPosMouse_add > 0)			//moi them cai nay, cho shyvana-R(va E2)
				endPosition = Extend(spellEndPos, spellStartPos, - (BoundRadius(MY_HERO) + spellData.EndPosMouse_add));

			if (endPosition.Distance2D(startPosition) > spellData.range)
				endPosition = startPosition + direction * spellData.range;
			
			if (spellData.useEndPosition)
			{
				float range = endPosition.Distance2D(startPosition);
				endTick = spellData.spellDelay + (range / spellData.projectileSpeed) * 1000;
			}

			if (obj != 0)
				endTick = endTick - spellData.spellDelay - (Distance(obj->currentPos(), spellStartPos) / spellData.projectileSpeed) * 1000;	 //chi vao 1 lan nen obj->currentPos() la thoi diem dan. xuat hien.
		}
		else if (spellType == Circular)
		{
			endTick = spellData.spellDelay;

			if (endPosition.Distance2D(startPosition) > spellData.range)
				endPosition = startPosition + direction * spellData.range;

			if (spellData.projectileSpeed == 0 && hero != 0)
			{
				endPosition = hero->currentPos();
			}
			else if (spellData.projectileSpeed > 0)
			{
				endTick = endTick + 1000 * startPosition.Distance2D(endPosition) / spellData.projectileSpeed;

				if (spellData.spellType == Line && spellData.hasEndExplosion)
				{
					if (!spellData.useEndPosition)
					{
						endPosition = startPosition + direction * spellData.range;
					}
				}

				if (obj != 0)	//tu them, chac phai cho vao`
					endTick = endTick - spellData.spellDelay - (Distance(obj->currentPos(), spellStartPos) / spellData.projectileSpeed) * 1000;	 
			} 
		}
		else if (spellType == Arc_x)
		{
			endTick = endTick + 1000 * startPosition.Distance2D(endPosition) / spellData.projectileSpeed;

			if (obj != 0)
				endTick -= spellData.spellDelay;
		}
		else if (spellType == Cone)
		{
			endPosition = startPosition + direction * spellData.range;
			endTick = spellData.spellDelay;

			if (endPosition.Distance2D(startPosition) > spellData.range)
				endPosition = startPosition + direction * spellData.range;

			if (spellData.projectileSpeed == 0 && hero != 0)
			{
				endPosition = hero->currentPos();
			}
			else if (spellData.projectileSpeed > 0)
			{
				endTick = endTick + 1000 * startPosition.Distance2D(endPosition) / spellData.projectileSpeed;
			}
			//__oMsg("endTick: %f, spellData.projectileSpeed : %f", endTick, spellData.projectileSpeed);
		}
		else
		{
			return;
		}

		if (spellData.invert)
		{
			Vec3D dir = (startPosition - endPosition).Normalized();
			endPosition = startPosition + dir * startPosition.Distance2D(endPosition);
		}

		if (spellData.isPerpendicular)
		{
			startPosition = spellEndPos - Perpendicular(direction) * spellData.secondaryRadius;
			endPosition   = spellEndPos + Perpendicular(direction) * spellData.secondaryRadius;
		}

		endTick += extraEndTick;

		Spell newSpell;
		newSpell.startTime	= _EvadeUtils->TickCount();
		newSpell.endTime	= _EvadeUtils->TickCount() + endTick;
		newSpell.startPos	= startPosition;
		newSpell.startPos_2	= startPosition;
		newSpell.endPos		= endPosition;
		newSpell.height		= spellEndPos.y + spellData.extraDrawHeight;
		newSpell.direction	= direction;
		newSpell.info		= spellData;
		newSpell.spellType	= spellType;
		newSpell.radius     = spellRadius > 0 ? spellRadius : GetSpellRadius(newSpell);
		
		//__oMsg("newSpell.radius: %.3f - endTime: %.3f",  newSpell.radius, newSpell.endTime);
		if (spellType == Cone)
		{
			//newSpell.radius = 100 + (newSpell.radius * 3); // for now.. eh
			float gocRadian  = spellData.angle * D3DX_PI/180;
			newSpell.radius  = 2 * tan(gocRadian/2) * spellData.range;
			newSpell.cnStart = startPosition + direction;
			newSpell.cnLeft  = endPosition + Perpendicular(direction) * newSpell.radius;
			newSpell.cnRight = endPosition - Perpendicular(direction) * newSpell.radius;
			//__oMsg("newSpell.radius.cone-2: %f",  newSpell.radius);
		}

		if (hero != 0)
			newSpell.heroID = hero->nIndex;

		if (obj != 0)
		{
			newSpell.spellObject  = obj;
			newSpell.projectileID = obj->nIndex;
			newSpell.startPos_2   = obj->currentPos();
			////newSpell.startPos	  = obj->currentPos();
		}

		int spellID = CreateSpell(newSpell, processSpell);
		//__oMsg("-------> ***** End.Create-Spell --------------");

		//if (extraEndTick != 1337f) // traps
		//{
		//	DelayAction.Add((int)(endTick + spellData.extraEndTime), () => DeleteSpell(spellID));
		//}
	}
}

//-------------------------------------------------//-----------------------//----------
//void AddDetectedSpells__tetete()
//{
//	
//	__try
//	{
//		AddDetectedSpells();
//	}
//	__except(EXCEPTION_EXECUTE_HANDLER)
//	{
//		__oMsg("ERROR: AddDetectedSpells();");
//	}
//}
//void CheckSpellEndTime__tetete()
//{
//
//	__try
//	{
//		CheckSpellEndTime();
//	}
//	__except(EXCEPTION_EXECUTE_HANDLER)
//	{
//		__oMsg("ERROR: CheckSpellEndTime();");
//	}
//}
//void UpdateSpells__tetete()
//{
//
//	__try
//	{
//		UpdateSpells();
//	}
//	__except(EXCEPTION_EXECUTE_HANDLER)
//	{
//		__oMsg("ERROR: UpdateSpells();");
//	}
//}
//void CheckSpellCollision_SpD__tetete()
//{
//
//	__try
//	{
//		CheckSpellCollision_SpD();
//	}
//	__except(EXCEPTION_EXECUTE_HANDLER)
//	{
//		__oMsg("ERROR: CheckSpellCollision_SpD();");
//	}
//}

void OnGameUpdate_SpellDetector()	//*********
{
	UpdateSpells();
	//UpdateSpells__tetete();

	//return;

	if ((float)GetTickCount() - _SpellDetector->lastCheckSpellCollisionTime > 100)	// check colision L# = 100
	{
		CheckSpellCollision_SpD();
		//CheckSpellCollision_SpD__tetete();

		_SpellDetector->lastCheckSpellCollisionTime = (float)GetTickCount();
	}

	if ((float)GetTickCount() - _SpellDetector->lastCheckTime > 1)
	{
		//////CheckCasterDead(); 

		CheckSpellEndTime();
		//CheckSpellEndTime__tetete();

		AddDetectedSpells();
		//AddDetectedSpells__tetete();
		_SpellDetector->lastCheckTime = (float)GetTickCount();
	}
}

//-------------------------------------------------//-----------------------//----------
void UpdateSpells()
{
	int sizeBefore = (int)_SpellDetector->detectedSpells->size();
	for (std::map<int, Spell>::iterator it = _SpellDetector->detectedSpells->begin(); it!= _SpellDetector->detectedSpells->end(); ++it)
	{
		if ((int)_SpellDetector->detectedSpells->size() != sizeBefore) 
			break;
		UpdateSpellInfo(it->second);	//update-spell : spell.UpdateSpellInfo();
	}

	////------ chac phai them 2 thang lolz nay nua ----:
	//int sizeBefore_1 = (int)_SpellDetector->drawSpells->size();
	//for (std::map<int, Spell>::iterator it = _SpellDetector->drawSpells->begin(); it!= _SpellDetector->drawSpells->end(); ++it)
	//{
	//	if ((int)_SpellDetector->drawSpells->size() != sizeBefore_1) 
	//		break;
	//	UpdateSpellInfo(it->second);	
	//}
	
	//int sizeBefore_2 = (int)_SpellDetector->spells->size();
	//for (std::map<int, Spell>::iterator it = _SpellDetector->spells->begin(); it!= _SpellDetector->spells->end(); ++it)	//BAT BUOC PHAI UPDATE CAI NAY`
	//{
	//	if ((int)_SpellDetector->spells->size() != sizeBefore_2)
	//		break;
	//	UpdateSpellInfo(it->second);	
	//}
}

//-------------------------------------------------//-----------------------//----------
void CheckSpellEndTime()
{
	if ( !G_Module ) return;
	if ( !myTeamId ) return;
	if ( !MY_HERO  ) return;
	
	//__oMsg("test1");
	//__oMsg("[--CheckSpellEndTime-] SIZE: %d", (int)_SpellDetector->detectedSpells->size());

	int sizeBefore = (int)_SpellDetector->detectedSpells->size();
	for (std::map<int, Spell>::iterator it = _SpellDetector->detectedSpells->begin(); it!= _SpellDetector->detectedSpells->end(); it++)
	{
		//__oMsg("test222.00-sao1 : %d", (int)_SpellDetector->detectedSpells->size());

		if ((int)_SpellDetector->detectedSpells->size() != sizeBefore) break;

		//__oMsg("test222.11-sao1 : %d", (int)_SpellDetector->detectedSpells->size());
		//__oMsg("test222.22 : %d", (int)_SpellDetector->detectedSpells->size());
		Spell spell = it->second;
		//__oMsg("test222.33");

		if(CheckName("_trap", (char*)spell.info.spellName.c_str()))		continue;

		bool deleteSpell_WhenEnemyHeroDead = false;

		DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
		DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
		DWORD dw1 = *(DWORD*)tempHero;
		DWORD dw2 = *(DWORD*)tempHeroMax;
		if (!dw1 || !dw2 ) return;
		
		int nCount = (dw2 - dw1)/4;
		for (int i = 0; i < nCount; ++i)
		{
			DWORD dw3 = *(DWORD*)(dw1 + 4*i);
			if (dw3 == 0) continue;
			KNpc *enemyHero = (KNpc*)dw3;
			if (enemyHero->nTeam_ID == myTeamId) continue;
			if (IS_DEAD(enemyHero) && spell.heroID == enemyHero->nIndex)
			{
				if (spell.spellObject == 0)
				{
					deleteSpell_WhenEnemyHeroDead = true;
					DeleteSpell(it->first);
					break;

					//_DelayAction->Add(1,  (_DelayAction->Callback)DeleteSpell(it->first));
					//__oMsg("[*DELETED* -11-]Delete Spell.in.CheckSpellEndTime.1");
				}
			}
		}
		
		if (deleteSpell_WhenEnemyHeroDead == true) 
			break;

		//__oMsg("    [---]Delete Spell.in.CheckSpellEndTime.2.0 : %d, %f < %f (tick)", CanHeroWalkIntoSpell(spell), spell.endTime, (float)GetTickCount() );
		//if (spell.spellObject != 0) tTime = tTime - spell.info.missileDelay;	//tu. che'
		
					
		
		float tTime = spell.endTime + spell.info.extraEndTime - 25;
		if ((tTime < (float)GetTickCount()) || CanHeroWalkIntoSpell(spell) == false)
		{
			DeleteSpell(it->first);
			//__oMsg("[*DELETED* -22-] Delete Spell.in.CheckSpellEndTime.2.11 - it->first: %d, size: %d", it->first, (int)_SpellDetector->detectedSpells->size());
			//__oMsg("test3");
			//DelayAction.Add(1, () => DeleteSpell(entry.Key));

			break;
		}
	}
}

//-------------------------------------------------//-----------------------//----------
void CheckSpellCollision_SpD()
{
	if (CheckSpellCollision_menu == false)
	{
		return;
	}
	
	int sizeBefore = (int)_SpellDetector->detectedSpells->size();
	
	for (std::map<int, Spell>::iterator it = _SpellDetector->detectedSpells->begin(); it!= _SpellDetector->detectedSpells->end(); ++it)
	{
		if ((int)_SpellDetector->detectedSpells->size() != sizeBefore) break;

		Spell spell = it->second;

		KNpc* collisionObject = CheckSpellCollision_Sp(spell, true);
		if (collisionObject != 0 && !IS_DEAD(collisionObject))
		{
			it->second.predictedEndPos = GetSpellProjection(spell, collisionObject->currentPos());

			if (spell.currentSpellPosition.Distance2D(collisionObject->currentPos()) < BoundRadius_Minion(collisionObject) + spell.radius)	// bound cua linh', lay 65 cung dc
			{
				DeleteSpell(it->first);
				//DelayAction.Add(1, () => DeleteSpell(entry.Key));
				//__oMsg("[*DELETED* -33-] Delete Spell.in.CheckSpellCollision_SpD");
				break;
			}
		}
	}
}

//-------------------------------------------------//-----------------------//----------
//bool CanHeroWalkIntoSpell_TETET()
//{ 
//	bool result = true;
//	__try
//	{
//		result = false;//CanHeroWalkIntoSpell(spell);
//	}
//	__except(EXCEPTION_EXECUTE_HANDLER)
//	{
//		__oMsg("ERROR : CanHeroWalkIntoSpell_TETET");
//	}
//	return result;
//}


//-------------------------------------------------//-----------------------//----------
bool CanHeroWalkIntoSpell(Spell spell)
{ 
	KNpc* myHero = GetPlayer();
	if(!myHero) return true;

	if (AdvancedSpellDetection_menu)
	{
		Vec3D heroPos = myHero->currentPos();
		//var extraDist = myHero.Distance(ObjectCache.myHeroCache.serverPos2D);
		float extraDist = 5;

		if (spell.spellType == Line)
		{
			float walkRadius  = myHero->nMoveSpeed * (spell.endTime - (float)GetTickCount()) / 1000 + BoundRadius(myHero) + spell.info.radius + extraDist + 10;
			Vec3D spellPos    = spell.currentSpellPosition;
			Vec3D spellEndPos = GetSpellEndPosition(spell);

			ProjectionInfo projection = ProjectOn(heroPos, spellPos, spellEndPos);
			//Draw2DCircle(projection.SegmentPoint, 10, WHITE);
			//__oMsg(" kchero: %.3f, walkRadius: %.3f, time: %.3f", projection.SegmentPoint.Distance2D(heroPos), walkRadius, spell.endTime - (float)GetTickCount());
			return projection.SegmentPoint.Distance2D(heroPos) <= walkRadius;
		}
		else if (spell.spellType == Circular)
		{
			float walkRadius = myHero->nMoveSpeed * (spell.endTime - (float)GetTickCount()) / 1000 + BoundRadius(myHero) + spell.info.radius + extraDist + 10;

			if (heroPos.Distance2D(spell.endPos) < walkRadius)
			{
				return true;
			}

		}
		else if (spell.spellType == Arc_x)
		{
			float spellRange = spell.startPos.Distance2D(spell.endPos);
			Vec3D midPoint   = spell.startPos + spell.direction * (spellRange / 2);
			float arcRadius  = spell.info.radius * (1 + spellRange / 100);

			float walkRadius = myHero->nMoveSpeed * (spell.endTime - (float)GetTickCount()) / 1000 + BoundRadius(myHero) + arcRadius + /*extraDist +*/ 10;

			if (heroPos.Distance2D(midPoint) < walkRadius)
			{
				return true;
			}
		}

		return false;
	}

	return true;
}

//-------------------------------------------------//-----------------------//----------
void AddDetectedSpells()
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return;

	bool spellAdded = false;
	
	int sizeBefore = (int)_SpellDetector->detectedSpells->size();
	
	for (std::map<int, Spell>::iterator it = _SpellDetector->detectedSpells->begin(); it!= _SpellDetector->detectedSpells->end(); ++it)
	{
		if ((int)_SpellDetector->detectedSpells->size() != sizeBefore) break;

		Spell spell = it->second;
		
		if (CheckName("_trap", (char*)spell.info.spellName.c_str()))
		{
			// todo:
		}
		else
		{
			for (std::map<std::string, SpellData>::iterator it_xxx=_SpellDetector->onProcessSpells->begin(); it_xxx!=_SpellDetector->onProcessSpells->end(); ++it_xxx)
			{
				if(spell.info.spellName.compare(it_xxx->second.sSetting.key_spell) == 0)
				{
					//EvadeHelper.fastEvadeMode = ObjectCache.menuCache.cache[spell.info.spellName + "FastEvade"].GetValue<bool>();
					_EvadeHelper->fastEvadeMode = it_xxx->second.sSetting.FastEvade;
					break;
				}
			}
		}

		float evadeTime, spellHitTime;
		CanHeroEvade(spell, myHero, evadeTime, spellHitTime);

		spell.spellHitTime = spellHitTime;
		spell.evadeTime    = evadeTime;
		
		//__oMsg("						                           -----spellHitTime: %f, evadeTime: %f", spell.spellHitTime, spell.evadeTime);

		float extraDelay = ExtraPingBuffer_menu;
		
		if (spell.spellHitTime - extraDelay < 2500 && CanHeroWalkIntoSpell(spell))
			//if(true)
		{
			Spell newSpell = spell;
			int spellID = spell.spellID;
			
			std::map<int, Spell>::iterator it_drawSpells = _SpellDetector->drawSpells->find(spell.spellID); 
			if (it_drawSpells != _SpellDetector->drawSpells->end())
			{ /*....to do....*/}
			else
			{
				_SpellDetector->drawSpells->insert(std::pair<int, Spell> (spellID, newSpell));
				//__oMsg("[*INSERTED*]->_SpellDetector->DRAW_SPEELS.ID = %d", spellID);
			}

			//var spellFlyTime = Evade.GetTickCount - spell.startTime;
			bool  isFastEvade_inMenuSpell   = false;
			bool  isDodgeSpell_inMenuSpell  = false;
			float DodgeIgnoreHP_inMenuSpell = 100.0f;
			float reactionTime_inMenuSpell  = 0;
			for (std::map<std::string, SpellData>::iterator it_xxx=_SpellDetector->onProcessSpells->begin(); it_xxx!=_SpellDetector->onProcessSpells->end(); ++it_xxx)
			{
				if(spell.info.spellName.compare(it_xxx->second.sSetting.key_spell) == 0)
				{
					isFastEvade_inMenuSpell   = it_xxx->second.sSetting.FastEvade;
					isDodgeSpell_inMenuSpell  = it_xxx->second.sSetting.DodgeSpell;
					DodgeIgnoreHP_inMenuSpell = it_xxx->second.sSetting.DodgeIgnoreHP;
					reactionTime_inMenuSpell  = it_xxx->second.sSetting.ReactionTime;
					break;
				}
			}

			if (spellHitTime < SpellDetectionTime_menu && !isFastEvade_inMenuSpell)								//"Spell Detection Time" - default = 0;	(tgian phat hien)
			{	
				//__oMsg(" ---------- HitTime: %.3f < %.2f(SpellDetectionTime_menu)", spellHitTime, SpellDetectionTime_menu);
				continue;
			}
			
			//------ cho nay can them 1 it Logic :
			////__oMsg(" [ss=> %d]---------- FlyTime: %.3f < Reaction(%.2f)", _EvadeUtils->TickCount() - spell.startTime < ReactionTime_menu, _EvadeUtils->TickCount() - spell.startTime, ReactionTime_menu);
			if (!isFastEvade_inMenuSpell && _EvadeUtils->TickCount() - spell.startTime < reactionTime_inMenuSpell)		//"Reaction Time" - default = 0;	(tgian phan ung)
			{
				continue;	// ko dung` reactionTime_inMenuSpell o menu, reactionTime_inMenuSpell luon = 0
			}
				
			//-- CODE THEM ---:
			if (!isFastEvade_inMenuSpell && reactionTime_inMenuSpell == 0 && spell.info.waitExtra > 0 /*&& spell.info.range < 2000*/)
			{
				//__oMsg("spell.spellHitTime: %.3f - spell.evadeTime = %.3f", spell.spellHitTime, spell.evadeTime);
				if (spell.spellHitTime - spell.evadeTime > 500 + spell.info.waitExtra)
				{
					//__oMsg("      ****** [*CONTINUE*] ------: CHUA CAN INSERT ---: %.3f - %.3f = %.3f", spell.spellHitTime, spell.evadeTime, spell.spellHitTime - spell.evadeTime);
					continue;
				}
			}

			//------ cho nay cam giac ko can thiet :
			float dodgeInterval = DodgeInterval_menu;															//"Dodge Interval" - default = 0;
			if (_Evade->lastPosInfo != 0 && dodgeInterval > 0)
			{
				float timeElapsed = _EvadeUtils->TickCount() - _Evade->lastPosInfo->timestamp;
				
				//__oMsg(" [ss=> %d]---------- Interval: %.3f > timeElapsed(%.2f)", dodgeInterval > timeElapsed, dodgeInterval, timeElapsed);
				if (dodgeInterval > timeElapsed && !isFastEvade_inMenuSpell)
				{
					//--//var delay = dodgeInterval - timeElapsed;
					//-//DelayAction.Add((int)delay, () => SpellDetector_OnProcessDetectedSpells());
					continue;
				}
			}

			std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->find(spell.spellID); 
			if (it_spells != _SpellDetector->spells->end())
			{ /*....to do....*/}
			else
			{
				if (!(isDodgeDangerousEnabled() && GetSpellDangerLevel(newSpell) < 3) && isDodgeSpell_inMenuSpell)
				{
					if (newSpell.spellType == Circular && DodgeCircularSpells_menu == false)
					{
						//return spellID;
						continue;
					}

					float healthThreshold = DodgeIgnoreHP_inMenuSpell;

					if (myHero->percentHP() <= healthThreshold)
					{
						_SpellDetector->spells->insert(std::pair<int, Spell> (spellID, newSpell));
						spellAdded = true;
						//__oMsg("[*** INSERTED*]->_SpellDetector->SPEELSSS.ID = %d", spellID);
					}
				}
			}

			if (CheckSpellCollision_menu && spell.predictedEndPos.IsValid())
			{
				spellAdded = false;
				//__oMsg("spellAdded = false");
			}
		}
	}


	if (spellAdded)
	{
		//__oMsg("VAO -> SpellDetector_OnProcessDetectedSpells()");
		////OnProcessDetectedSpells?.Invoke();//sk nay lap ham ben evade
		SpellDetector_OnProcessDetectedSpells();
	}
}

//-------------------------------------------------//-----------------------//----------
void RemoveNonDangerousSpells()
{
	int sizeB4 = (int)_SpellDetector->spells->size();

	for (std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->begin(); it_spells!= _SpellDetector->spells->end(); ++it_spells)
	{
		if (sizeB4 != (int)_SpellDetector->spells->size()) break;

		Spell spell = it_spells->second;
		if(GetSpellDangerLevel(spell) < 3)
		{
			//__oMsg("[*DELETED* -44-] in.RemoveNonDangerousSpells");
			DeleteSpell(spell.spellID);
			break;
		}
	}
}


//-------------------------------------------------//-----------------------//----------

struct checkEnemyCastSpell
{
	int		nSlot;
	DWORD	pLastPcast;		//slot
	float   fTimeStart;		//time bat dau cast
	//float   fTimeBay;		//time dan. bat dau bay
};

//---------------//----------//----------//----------:
//std::map<DWORD, std::vector<checkEnemyCastSpell>* > *enemyCasting = 0;

std::map< DWORD, float > *enemyCasting = 0;
//======================================================================================================||
bool canUpdateEnemyCastingSpell(DWORD HeroNetID, int slot, float timeStart, float timeBay, DWORD curCastSpell, char* heroName, char* spellName)
{
	if ( enemyCasting == 0 ) enemyCasting = new std::map< DWORD, float >;

	std::map< DWORD, float >::iterator it_xxx = enemyCasting->find(HeroNetID);
	if (it_xxx != enemyCasting->end())
	{
		float deltaTime = fabs(it_xxx->second - timeStart);
		if (  deltaTime > 0.01f )
		{
			//__oMsg("XXXX_XXX: [%x][%s][%s][%d] : timeStart: %.4f, it_xxx->second: %.4f, %d", HeroNetID, heroName, spellName, slot, timeStart, it_xxx->second, soluongHero);
			it_xxx->second = timeStart;
			return true;
		}

		//if (slot == it_xxx->second.nSlot)
		//{
		//	float deltaTime = fabs(it_xxx->second.fTimeStart - timeStart);
		//	if (  deltaTime > 0.015f )
		//	{
		//		__oMsg("[111].[%x][%s][%s][%d]timeStart: %.4f, it_xxx->second.fTimeStart: %.4f, %x", HeroNetID, heroName, spellName, slot, timeStart, it_xxx->second.fTimeStart, curCastSpell);
		//		it_xxx->second.fTimeStart = timeStart;
		//		it_xxx->second.pLastPcast = curCastSpell;
		//		return true;
		//	}

		//	if ( timeStart > 0 && deltaTime < FLT_EPSILON )		// cho vao` cho chac, chac k bao gio vao
		//	{
		//		if (it_xxx->second.pLastPcast != curCastSpell)
		//		{
		//			__oMsg("[222].[%x][%s][%s][%d]timeStart: %.4f, it_xxx->second.fTimeStart: %.4f, %x", HeroNetID, heroName, spellName, slot, timeStart, it_xxx->second.fTimeStart, curCastSpell);
		//			it_xxx->second.fTimeStart = timeStart;
		//			it_xxx->second.pLastPcast = curCastSpell;
		//			return true;
		//		}
		//	}
		//}
	}
	else
	{
		//soluongHero += 1;
		//__oMsg("KHOI TAO: [%x][%s][%s][%d] : %.4f, %d", HeroNetID, heroName, spellName, slot, timeStart, soluongHero);
		enemyCasting->insert(std::pair<DWORD, float> (HeroNetID, timeStart));
		return true;
	}
	return false;
}

//---------------//----------//----------//----------:
float print_1Lan = 0;
void OnProcessSpell_SpellDetector(/*Obj_AI_Base hero, GameObjectProcessSpellCastEventArgs args*/)	//*********  //Obj_AI_Hero.OnProcessSpellCast += Game_ProcessSpell; --> tam thoi cho vao onGameUpdate
{
	if ( !G_Module ) return;
	if ( !myTeamId ) return;
	if ( !MY_HERO  ) return;
	
	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dw1 = *(DWORD*)tempHero;
	DWORD dw2 = *(DWORD*)tempHeroMax;
	if ( !dw1 || !dw2 ) return;

	int nCount = (dw2 - dw1)/4;
	for ( int i = 0; i < nCount; ++i )
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if ( dw3 == 0 ) continue;
		KNpc *hero = (KNpc*)dw3;
		
		if ( hero->isRecall() )	continue;
		if ( !CheckTeam(hero) )	continue;
		
		KCastSpell* args = (KCastSpell*)hero->_pCastSpell;
		if ( !args ) continue;

		////KSkill_2*  pK_str2xxx = (KSkill_2*) args->__pK_str2;
		////if(!pK_str2xxx) continue;

		if ( !canUpdateEnemyCastingSpell(hero->nIndex, (BYTE)args->nSlot, args->nTime_BatDauBAN, args->nTime_DanBatDauBay, (DWORD)args, "", "" /*hero->GetNameHero(), pK_str2xxx->GetSkillName()*/) )
		{
			//__oMsg("	  ---------KO CHECK PCAST.SPELL NUA: %0.3f", GetTimeGame());
			continue;
		}

		////if ( GetTimeGame() < args->nTime_DanBatDauBay + 1.5f && GetTimeGame() > args->nTime_BatDauBAN + 0.06f) continue;		//0.06f la vao khoang 2 lan

		KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
		if(!pK_str2) continue;
		
		std::string SPELL_NAME(pK_str2->GetSkillName());
		
		//__oMsg("********* TimeGame: %.3f", GetTimeGame());

		//////-------Test-Print-SpellInfo --:
		//if((float)GetTickCount() - print_1Lan > 500)
		//{
		//	__oMsg("\n====== GAME-SPELL-INFO ===============:");
		//	__oMsg("Name           : %s [dist2enemy: %.2f] - [%.2f][hero: %x - %x]", SPELL_NAME.c_str(), Distance(MY_HERO, hero), Distance_2D(args->SourcePos, args->MaxDestPos), hero, &hero->_pCastSpell);
		//	__oMsg("SrcPos         : %.3f, %.3f, %.3f", args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
		//	__oMsg("DesPos         : %.3f, %.3f, %.3f", args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
		//	__oMsg("MouPos         : %.3f, %.3f, %.3f", args->MousePos.x, args->MousePos.y, args->MousePos.z);
		//	__oMsg("Delay(slot: %d) : %.3f", (BYTE)args->nSlot, 1000*args->nDelay_AAAnimate);
		//	__oMsg("Ban[%.3f] - Bay[%.3f] - CD[%.3f - (%.2f, %.2f)] ", args->nTime_BatDauBAN, args->nTime_DanBatDauBay, args->nTime_CDExpiresAA, args->nCoolDownAA, *(float*)((DWORD)args + 0x4C8));
		//	__oMsg("  -------------------- ");
		//	KMissile_Struct_3* pStruct_3 = (KMissile_Struct_3*)pK_str2->__pK_str3;
		//	__oMsg("Radius         : %.3f [%x]", pStruct_3->nRadius, (DWORD)&pStruct_3->nRadius);
		//	__oMsg("Range1         : %.3f", pStruct_3->nRange);
		//	__oMsg("Range2         : %.3f", pStruct_3->nRange_2);
		//	__oMsg("Width          : %.3f", pStruct_3->nMissileWidth);
		//	__oMsg("Speed          : %.3f", pStruct_3->nMissileSpeed);

		//	__oMsg("======== END ===================================\n");
		//	print_1Lan = (float)GetTickCount();
		//}
		
		////------------------------------------------||

		std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(SPELL_NAME));		//L#: .TryGetValue
		if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
		{
			SpellData spellData = it_onProcessSpells->second;
			
			
			if ( spellData.isSpecial_11x )
			{
				//__oMsg("\nCALLING : Dodge_Special_1111 (%s) (%s) : ", hero->GetNameHero(), SPELL_NAME.c_str());
				Dodge_Special_1111(hero, args, it_onProcessSpells->second, (char*)SPELL_NAME.c_str());
			}
			else
			{
				if (/*specialSpellArgs.noProcess == false && */spellData.noProcess == false)
				{
					//--------------------------------:
					bool foundMissile = false;
					if (spellData.isThreeWay == false && spellData.isSpecial == false)
					{
						//int sizeBefore = (int)_SpellDetector->detectedSpells->size();

						for (std::map<int, Spell>::iterator it_1 = _SpellDetector->detectedSpells->begin(); it_1!= _SpellDetector->detectedSpells->end(); ++it_1)
						{
							//if ((int)_SpellDetector->detectedSpells->size() != sizeBefore) break;

							Spell spell = it_1->second;

							Vec3D Start(args->SourcePos.x , args->SourcePos.y , args->SourcePos.z);
							Vec3D End  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);

							//if (End.x == Start.x && End.y == Start.y && End.z == Start.z)		// for Yasuo3
							if ( fabs(End.x - Start.x) < FLT_EPSILON && fabs(End.y - Start.y) < FLT_EPSILON && fabs(End.z - Start.z) < FLT_EPSILON)
							{
								End.x = args->MousePos.x;
								End.y = args->MousePos.y;
								End.z = args->MousePos.z;
							}

							Vec3D dir = (End - Start).Normalized();
							if (spell.spellObject != 0)
							{
								if(CheckNameEx((char*)str_tolower(spell.info.spellName).c_str(), (char*)str_tolower(SPELL_NAME).c_str())) // todo: fix urf spells
								{
									if (spell.heroID == hero->nIndex && AngleBetween(dir, spell.direction) < 10)
									{
										//__oMsg("	  ---------[OnProcessSpell] [foundMissile] - 11.DA~GAN'");
										foundMissile = true;
										break;
									}
								}
								else
								{
									if((int)spell.info.extraSpellNames.size() > 0)
									{
										for (int kk = 0; kk < (int)spell.info.extraSpellNames.size(); ++kk)
										{
											if(CheckNameEx((char*)str_tolower(spell.info.extraSpellNames[kk]).c_str(), (char*)str_tolower(SPELL_NAME).c_str())) // todo: fix urf spells
											{
												if (spell.heroID == hero->nIndex && AngleBetween(dir, spell.direction) < 10)
												{
													//__oMsg("	  ---------[OnProcessSpell] [foundMissile] - 22.DA~GAN'");
													foundMissile = true;
													break;
												}
											}
										}
										if (foundMissile == true)
										{
											break;
										}
									}
								}
							}
						}
					}

					//--------------------------------:
					bool isCreateOnce = false;

					//--------------------------------:
					if (foundMissile == false && isCreateOnce == false)
					{
						Vec3D Start(args->SourcePos.x , args->SourcePos.y , args->SourcePos.z);
						Vec3D End  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);

						//if(End.x == Start.x && End.y == Start.y && End.z == Start.z)		// for Yasuo3

						if ( fabs(End.x - Start.x) < FLT_EPSILON && fabs(End.y - Start.y) < FLT_EPSILON && fabs(End.z - Start.z) < FLT_EPSILON)
						{
							End.x = args->MousePos.x;
							End.y = args->MousePos.y;
							End.z = args->MousePos.z;
						}

						//__oMsg("---((***))----- CREATE-SPELL-1-PhatThoi (PCAST)----------: args(%s) - it(%s) rad = %f", SPELL_NAME.c_str(), spellData.spellName.c_str(), spellData.radius);
						//__oMsg("\n     ====== FUCKER-SPELL-INFO ===============:");
						//__oMsg("     Name           : %s - missile(%s)", spellData.spellName.c_str(), spellData.missileName.c_str());
						//__oMsg("     Delay          : %.3f", spellData.spellDelay);
						//__oMsg("     ExDelay        : %.3f", spellData.extraDelay);
						//__oMsg("       ------- ");
						//__oMsg("     Radius         : %.3f", spellData.radius);
						//__oMsg("     Range          : %.3f", spellData.range);
						////__oMsg("     Range2         : %.3f", spellData.nRange_2);
						////__oMsg("     Width          : %.3f", spellData.nMissileWidth);
						//__oMsg("     Speed          : %.3f", spellData.projectileSpeed);

						//__oMsg("     ======== END ===================================\n");
						CreateSpellData(hero, Start, End, spellData);		//detectedSpells->insert
					}
				}
			}
		}
	}
}

//-------------------------------------------------//-----------------------//----------
//-------------------------------------------------//-----------------------//----------

struct checkEnemyMissile
{
	float	fTimeSpawn;		
	Vec3D   startPos;	
	Vec3D   endPos;
};

//---------------//----------//----------//----------:
std::map<DWORD, checkEnemyMissile> *enemyMissile = 0;

//======================================================================================================||
bool canUpdateEnemyMissile(DWORD netID, Vec3D vecStart, Vec3D vecEnd, float timeSpawn)
{
	if ( enemyMissile == 0 )  enemyMissile = new std::map<DWORD, checkEnemyMissile>;

	std::map<DWORD, checkEnemyMissile>::iterator it_xxx = enemyMissile->find(netID);
	if (it_xxx != enemyMissile->end())
	{
		if ( fabs(it_xxx->second.startPos.x - vecStart.x) > FLT_EPSILON || fabs(it_xxx->second.startPos.z - vecStart.z) > FLT_EPSILON )
		{
			//__oMsg("[aa]vecStart: [%.4f, %.4f,%.4f ], it_xxx->startPos: [%.4f, %.4f,%.4f ] - %x, %.3f", vecStart.x, vecStart.y, vecStart.z, it_xxx->second.startPos.x, it_xxx->second.startPos.y, it_xxx->second.startPos.z, netID, timeSpawn);
			it_xxx->second.startPos   = vecStart;	
			it_xxx->second.endPos	  = vecEnd;
			it_xxx->second.fTimeSpawn = timeSpawn;
			return true;  
		}
	}
	else
	{
		checkEnemyMissile temp;
		temp.startPos   = vecStart;		
		temp.endPos	    = vecEnd;
		temp.fTimeSpawn = timeSpawn;
		enemyMissile->insert(std::pair<DWORD, checkEnemyMissile> (netID, temp));
		return true;
	}
	return false;
}

//-------------------------------------------------//-----------------------//----------
void OnCreate_SpellMissile()	//********* FAKE TRONG OnCreate.Missile
{
	if (DodgeFOWSpells_menu == false) return;
	
	//...... ERASE ......:
	if (enemyMissile && enemyMissile->size() > 10)	
	{
		std::map<DWORD, checkEnemyMissile>::iterator it;
		for (it = enemyMissile->begin(); it != enemyMissile->end(); ++it)
		{
			if (it->second.fTimeSpawn < GetTimeGame() - 30)
			{
				//__oMsg("ERASE : %d", enemyMissile->size());
				enemyMissile->erase(it);
				break;						// BREAK HOAC RETURN THI KO BI CRASH
			}
		}
	}

	//----------------------------------
	if ( !G_Module ) return;
	if ( !myTeamId ) return;
	if ( !MY_HERO  ) return;
	
	DWORD mangHeroID[5] = {0};
	int   xxx           = 0;

	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dw_a = *(DWORD*)tempHero;
	DWORD dw_b = *(DWORD*)tempHeroMax;
	if ( !dw_a || !dw_b ) return;

	int countHero = (dw_b - dw_a)/4;
	for ( int i = 0; i < countHero; ++i )
	{
		DWORD dw3 = *(DWORD*)(dw_a + 4*i);
		if ( dw3 == 0 ) continue;
		KNpc *hero = (KNpc*)dw3;

		if ( !CheckTeam(hero) )	continue;
		
		if (xxx < 5)
		{
			mangHeroID[xxx] = hero->nID;
			xxx = xxx + 1;
		}
	}

	//------//------//------:
	DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
	DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
	if ( !dw0 ) return;

	DWORD dw1 = *(DWORD*)(dw0 + 8);
	if ( !dw1 ) return;

	int nCount_xxx = *(DWORD*)(dw0 + 0xC);
	if ( !nCount_xxx ) return;

	for ( int kk = 0; kk < nCount_xxx; ++kk )
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
		if ( dw3 == 0 ) continue;
		KNpc *objectMis = (KNpc*)dw3;

		if ( !IS_OBJECT_TYPE(objectMis, 0x8000) )	 continue;

		if ( !CheckTeam(objectMis) )				 continue;			//comment de test

		if ( (objectMis->nIndex & 0x3fff) <= 0 || 
			 (objectMis->nIndex & 0x3fff) > 0xFF00 ) continue;
		if ( IS_OBJ_DELETED(objectMis) == true )	 continue;
		if ( !objectMis->nMissileOwnerID_1 )		 continue;

		if ( fabs(objectMis->MissileSrcPos.x ) < FLT_EPSILON && fabs(objectMis->MissileSrcPos.z ) < FLT_EPSILON /*&& fabs(objectMis->MissileSrcPos.y ) < FLT_EPSILON*/ ) continue;
		if ( fabs(objectMis->MissileDestPos.x) < FLT_EPSILON && fabs(objectMis->MissileDestPos.z) < FLT_EPSILON /*&& fabs(objectMis->MissileDestPos.y) < FLT_EPSILON*/ ) continue;	

		DWORD * p = std::find (mangHeroID, mangHeroID + 5, objectMis->nMissileOwnerID_1);
		if (p != mangHeroID + 5) 
		{
		}
		else continue;
		
		Vec3D startX(objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z);
		Vec3D endX  (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z);

		if ( !canUpdateEnemyMissile(objectMis->nIndex ,startX, endX, GetTimeGame()) ) continue;
		

						/*KMissileData* misData = (KMissileData*)objectMis->nMissileData;
						if (misData)
						{
							KMissile_Struct_3* pMiss_Struct_3 = (KMissile_Struct_3*)misData->nMissile_Struct_3;
							if (pMiss_Struct_3)
							{					
								__oMsg("          ---- 1.Missile.PRrint: [%s]Speed: %.2f(%.2f,%.2f) [%x - %x - %x]DIST:  %f {%.4f}", objectMis->GetNameNpc(), pMiss_Struct_3->nMissileSpeed, pMiss_Struct_3->nMissileMinSpeed, pMiss_Struct_3->nMissileMaxSpeed, objectMis->nIndex, objectMis->nTeam_ID, objectMis->nMissileOwnerID_1, Distance_2D(objectMis->MissileSrcPos, objectMis->MissileDestPos), GetTimeGame() );
								__oMsg("          ---- 2.Missile.PRrint: src:[%.3f, %.3f], des:[%.3f, %.3f]", objectMis->MissileSrcPos.x, objectMis->MissileSrcPos.z, objectMis->MissileDestPos.x, objectMis->MissileDestPos.z);
							}
						}*/


		std::string MISS_NAME(objectMis->GetNameNpc());
		
		std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(MISS_NAME)); 
		if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
		{
			SpellData spellData = it_onMissileSpells->second;
			
			if (spellData.isSpecial_22x)
			{
				//__oMsg("CALLING : Dodge_Special_2222 (%s) : ", MISS_NAME.c_str());
				//__oMsg("      [....]\n  ", MISS_NAME.c_str());
				Dodge_Special_2222(objectMis, it_onMissileSpells->second, (char*)MISS_NAME.c_str());
			}
			else
			{
				//////if ( spellData.isSpecial == true)	
				//////{
				//////	Special_OnCreateMissile(objectMis, it_onMissileSpells->second);
				//////	return;
				//////}

				//////if (spellData.isSpecial_22x) continue;

				Vec3D CurrePos(objectMis->CurrentPos.x , objectMis->CurrentPos.y , objectMis->CurrentPos.z);
				Vec3D StartPos(objectMis->MissileSrcPos.x , objectMis->MissileSrcPos.y , objectMis->MissileSrcPos.z);
				Vec3D EndPos  (objectMis->MissileDestPos.x, objectMis->MissileDestPos.y, objectMis->MissileDestPos.z);
	
				if (StartPos.Distance2D(MY_HERO->currentPos()) < spellData.range + 1000)
				{
					KNpc* hero = (KNpc*)GetObjectByID(objectMis->nMissileOwnerID_1);
					if (hero)
					{
						if (IsCanSee(hero))	//Nhin-Thay
						{
							//-- KO VAO VI KO DUNG` PACKET
							if ( spellData.usePackets )	
							{
								CreateSpellData(hero, StartPos, EndPos, spellData, objectMis);
								return;
							}

							//---------------------------------------------------------:
							bool objectAssigned = false;
							for (std::map<int, Spell>::iterator it_1 = _SpellDetector->detectedSpells->begin(); it_1!= _SpellDetector->detectedSpells->end(); ++it_1)
							{
								Spell spell = it_1->second;
								Vec3D dir   = (EndPos - StartPos).Normalized();
								if (str_tolower(spell.info.missileName).compare(str_tolower(MISS_NAME)) == 0)			// todo: fix urf spells
								{
									if (spell.heroID == hero->nIndex && AngleBetween(dir, spell.direction) < 10)
									{
										if (spell.info.isThreeWay == false && spell.info.isSpecial == false)
										{
											it_1->second.spellObject = objectMis;
										
											objectAssigned = true;
											//__oMsg("	  ---------SpellMissile.OnCreate -- MISSILE.DA.GAN.ROI-111: KC_Missile = %.3f", StartPos.Distance2D(EndPos));
											////it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
											break;
										}
									}
								}
								else
								{
									if((int)spell.info.extraMissileNames.size() > 0)
									{
										for (int kk = 0; kk < (int)spell.info.extraMissileNames.size(); ++kk)
										{
											if(str_tolower(spell.info.extraMissileNames[kk]).compare(str_tolower(MISS_NAME)) == 0)				 // todo: fix urf spells
											{
												if (spell.heroID == hero->nIndex && AngleBetween(dir, spell.direction) < 10)
												{
													if (spell.info.isThreeWay == false && spell.info.isSpecial == false)
													{
														it_1->second.spellObject = objectMis;

														objectAssigned = true;
														//__oMsg("	  ---------SpellMissile.OnCreate**(ExtraName: kk=%d) -- MISSILE.DA.GAN.ROI-222: KC_Missile = %.3f", kk, StartPos.Distance2D(EndPos));
														////it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
														break;
													}
												}
											}
										}
										if(objectAssigned == true) break;
									}
								}
							}
						
							//---------------------------------------------------------:
							if (objectAssigned == false /*&& it_onMissileSpells->second.projectileSpeed > FLT_EPSILON*/)
							{
								////__oMsg("---((***))----- CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",MISS_NAME.c_str(), StartPos.Distance2D(EndPos));
								CreateSpellData(hero, StartPos, EndPos, spellData, objectMis);
							}
						}
						else	//...... Enemy.In.FOW ......
						{
							//---------------------------------------------------------:
							bool objectAssigned = false;
							for (std::map<int, Spell>::iterator it_1 = _SpellDetector->detectedSpells->begin(); it_1!= _SpellDetector->detectedSpells->end(); ++it_1)
							{
								Spell spell = it_1->second;
								Vec3D dir   = (EndPos - StartPos).Normalized();
								if(str_tolower(spell.info.missileName).compare(str_tolower(MISS_NAME)) == 0)			// todo: fix urf spells
								{
									if (spell.heroID == hero->nIndex && AngleBetween(dir, spell.direction) < 10)
									{
										if (spell.info.isThreeWay == false && spell.info.isSpecial == false)
										{
											it_1->second.spellObject = objectMis;
											objectAssigned = true;
											//__oMsg("	  ---------Missile.OnCreate -- [*** FOW-FOW] MISSILE-DA~GAN-ROI-111: KC_Missile = %.3f", StartPos.Distance2D(EndPos));
											break;
										}
									}
								}
								else
								{
									if((int)spell.info.extraMissileNames.size() > 0)
									{
										for (int kk = 0; kk < (int)spell.info.extraMissileNames.size(); ++kk)
										{
											if(str_tolower(spell.info.extraMissileNames[kk]).compare(str_tolower(MISS_NAME)) == 0)				 // todo: fix urf spells
											{
												if (spell.heroID == hero->nIndex && AngleBetween(dir, spell.direction) < 10)
												{
													if (spell.info.isThreeWay == false && spell.info.isSpecial == false)
													{
														it_1->second.spellObject = objectMis;
														objectAssigned = true;
														//__oMsg("	  ---------Missile.OnCreate -- [*** FOW-FOW]**(ExtraMisName:kk=%d) MISSILE-DA~GAN-ROI-222: KC_Missile = %.3f", kk, StartPos.Distance2D(EndPos));
														break;
													}
												}
											}
										}

										if(objectAssigned == true) break;
									}
								}
							}
						
							//---------------------------------------------------------:
							if (objectAssigned == false /*&& it_onMissileSpells->second.projectileSpeed > FLT_EPSILON*/)
							{
								//__oMsg("---((***))----- CREATE-MISSLE-2222 -- [*** FOW-FOW]: MissileNam: %s, %.3f, KC_Missile = %.3f",MISS_NAME.c_str(), StartPos.Distance2D(MY_HERO->currentPos()), StartPos.Distance2D(EndPos));
								CreateSpellData(hero, StartPos, EndPos, spellData, objectMis);
							}
						}
					}
				}
			}
		}
	}
}

//-------------------------------------------------//-----------------------//----------
void OnProcessSpell_2_SpellDetector(KNpc* hero, KCastSpell* spellCast)
{
	__try
	{
		OnProcessSpell_2_SpellDetector_Main(hero, spellCast);
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		SEND_TEXT_SYSTEM("ERROR : OnProcessSpell.SpellDetector.2 - error");
	}
}

//-----------------------//----------------:
void OnProcessSpell_2_SpellDetector_Main(KNpc* hero, KCastSpell* spellCast)
{
	if (AllClassReady() == false) return;

	KSkill_2*  pK_str2 = (KSkill_2*) spellCast->__pK_str2;

	if (CheckTeam(hero) && IS_HERO(hero) && pK_str2)	//------- TEST nen COMMENT ------ CHU Y
	{
		std::string spell_name = pK_str2->GetSkillName();
		Vec3D Start(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
		Vec3D End  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

		//__oMsg("\n====== GAME-SPELL-INFO (ON-PROCESS-SPELL) ===============:");
		//__oMsg("Name           : [hero = %x]%s [dist2enemy: %.2f] - [%.2f]", hero, spell_name.c_str(), Distance(GetPlayer(), hero), Distance_2D(spellCast->SourcePos, spellCast->MaxDestPos));
		//__oMsg("SrcPos         : %.3f, %.3f, %.3f [hero: %.3f, %.3f, %.3f]", spellCast->SourcePos.x, spellCast->SourcePos.y, spellCast->SourcePos.z, hero->currentPos().x, hero->currentPos().y, hero->currentPos().z);
		//__oMsg("DesPos         : %.3f, %.3f, %.3f", spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
		//__oMsg("MouPos         : %.3f, %.3f, %.3f", spellCast->MousePos.x, spellCast->MousePos.y, spellCast->MousePos.z);
		//__oMsg("Delay(slot: %d): %.3f {TG: %f}", (BYTE)spellCast->nSlot, 1000*spellCast->nDelay_AAAnimate, GetTimeGame());
		////__oMsg("Bay: %.3f, Ban : %.3f", spellCast->nTime_DanBatDauBay, spellCast->nTime_BatDauBAN);
		//__oMsg("  ------- ");
		//KMissile_Struct_3* pStruct_3 = (KMissile_Struct_3*)pK_str2->__pK_str3;
		//__oMsg("Radius         : %.3f [%x]", pStruct_3->nRadius, (DWORD)&pStruct_3->nRadius);
		//__oMsg("Range1         : %.3f", pStruct_3->nRange);
		//__oMsg("Range2         : %.3f", pStruct_3->nRange_2);
		//__oMsg("Width          : %.3f", pStruct_3->nMissileWidth);
		//__oMsg("Speed          : %.3f", pStruct_3->nMissileSpeed);

		//__oMsg("======== END ===================================\n");
		//__oMsg("TimeGame: %f", GetTimeGame());
		//////------------------------------------------||

		std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spell_name));		//L#: .TryGetValue
		if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
		{
			SpellData spellData = it_onProcessSpells->second;

			
			if (canUse_VMT && spellData.isSpecial == true)		// CHINA-ONLY
			{
				Special_OnProcessSpell(hero, spellCast, spellData);		
				return;
			}

			//-----------//--------------//--------------:
			if (spellData.isSpecial_00x == false) return;

			//-----------//--------------//--------------:
			if (spellData.usePackets == false)
			{
				//var specialSpellArgs = new SpecialSpellEventArgs { spellData = spellData };
				//OnProcessSpecialSpell?.Invoke(hero, args, spellData, specialSpellArgs);
				////--- optional update from specialSpellArgs
				//spellData = specialSpellArgs.spellData;

				if (/*specialSpellArgs.noProcess == false && */spellData.noProcess == false)
				{
					//--------------------------------:
					bool foundMissile = false;
					if (spellData.isThreeWay == false && spellData.isSpecial == false)
					{
						//int sizeBefore = (int)_SpellDetector->detectedSpells->size();
						for (std::map<int, Spell>::iterator it_1 = _SpellDetector->detectedSpells->begin(); it_1!= _SpellDetector->detectedSpells->end(); ++it_1)
						{
							//if ((int)_SpellDetector->detectedSpells->size() != sizeBefore) break;

							Spell spell = it_1->second;
							
							Vec3D dir = (End - Start).Normalized();
							if (spell.spellObject != 0)
							{
								//__oMsg("xxx1: %s", spell.info.spellName.c_str());
								if(CheckNameEx((char*)str_tolower(spell.info.spellName).c_str(), (char*)str_tolower(spell_name).c_str())) // todo: fix urf spells
								{
									//__oMsg("xxx2: %s - %f - %d", spell.info.spellName.c_str(), AngleBetween(dir, spell.direction), spell.heroID == hero->nIndex);
									if (spell.heroID == hero->nIndex && AngleBetween(dir, spell.direction) < 10)
									{
										//__oMsg("	  ---------[OnProcessSpell_SpellDetector.2] [foundMissile] - 11.DA~GAN'");
										foundMissile = true;
										break;
									}
								}
								else
								{
									if((int)spell.info.extraSpellNames.size() > 0)
									{
										//__oMsg("0000: %s", spell.info.spellName.c_str());
										for (int kk = 0; kk < (int)spell.info.extraSpellNames.size(); ++kk)
										{
											//__oMsg("1111: %s", spell.info.spellName.c_str());
											if(CheckNameEx((char*)str_tolower(spell.info.extraSpellNames[kk]).c_str(), (char*)str_tolower(spell_name).c_str())) // todo: fix urf spells
											{
												//__oMsg("2222: %s - %f - %d", spell.info.spellName.c_str(), AngleBetween(dir, spell.direction), spell.heroID == hero->nIndex);
												if (spell.heroID == hero->nIndex && AngleBetween(dir, spell.direction) < 10)
												{
													//__oMsg("	  ---------[OnProcessSpell_SpellDetector.2] [foundMissile] - 22.DA~GAN'");
													foundMissile = true;
													break;
												}
											}
										}
										if (foundMissile == true)
										{
											break;
										}
									}
								}
							}
						}

						//--------------------------------:
						if (foundMissile == false)
						{
							//__oMsg("---((***))----- CREATE-SPELL-1-PhatThoi (ON-PROCESS-SPELL) ----------: args(%s) - it(%s) rad = %f", spell_name.c_str(), spellData.spellName.c_str(), spellData.radius);
							//__oMsg("\n====== FUCKER-SPELL-INFO ===============:");
							//__oMsg("Name           : %s - missile(%s)", spellData.spellName.c_str(), spellData.missileName.c_str());
							//__oMsg("Delay          : %.3f", spellData.spellDelay);
							//__oMsg("ExDelay        : %.3f", spellData.extraDelay);
							//__oMsg("  ------- ");
							//__oMsg("Radius         : %.3f", spellData.radius);
							//__oMsg("Range          : %.3f", spellData.range);
							////__oMsg("Range2         : %.3f", spellData.nRange_2);
							////__oMsg("Width          : %.3f", spellData.nMissileWidth);
							//__oMsg("Speed          : %.3f", spellData.projectileSpeed);

							//__oMsg("======== END ===================================\n");

							CreateSpellData(hero, Start, End, spellData);		//detectedSpells->insert

							/////*for (std::map<int, Spell>::iterator it_2 = _SpellDetector->detectedSpells->begin(); it_2!= _SpellDetector->detectedSpells->end(); ++it_2)
							////{
							////	it_2->second.KoUpCurrentPos = true;
							////}*/
						}
					}
				}
			}
		}
	}
}

