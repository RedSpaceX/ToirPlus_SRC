#include "EvadeSpells.h"
#include "Situation.h"
#include "Evade.h"
#include "EvadeHelper.h"
#include "PositionInfo.h"
#include "Position.h"
#include "EvadeCommand.h"


extern  SpellDetector*		_SpellDetector;
extern	EvadeSpell*			_EvadeSpell;
extern	Evade*				_Evade;

//extern  SpellDatabase*		_SpellDatabase;
//extern	EvadeHelper*		_EvadeHelper;


extern bool  DodgeSkillShots_menu, CalculateWindupDelay_menu;
extern float ExtraPingBuffer_menu, SpellActivationTime_menu;
extern cb_UseSpellFunc useSpellFunc_CB;
//-----------------------------------------//-------------------------//
SpellSlot GetSummonerSlot(std::string spellName)
{
	KNpc* myHero = GetPlayer();
	if (!myHero) return Unknown_slot;

	KSkill *pSkill_D = (KSkill *)myHero->_pSkill[4];
	if(!pSkill_D) return Unknown_slot;
	KSkill_2*  pKSkill_D2 = (KSkill_2*) pSkill_D->__pK_str2;
	if(!pKSkill_D2) return Unknown_slot;

	KSkill *pSkill_F = (KSkill *)myHero->_pSkill[5];
	if(!pSkill_F) return Unknown_slot;
	KSkill_2*  pKSkill_F2 = (KSkill_2*) pSkill_F->__pK_str2;
	if(!pKSkill_F2) return Unknown_slot;
	
	if (spellName.compare(pKSkill_D2->GetSkillName()) == 0)
	{
		return Summoner1_slot;
	}
	else if (spellName.compare(pKSkill_F2->GetSkillName()) == 0)
	{
		return Summoner2_slot;
	}

	return Unknown_slot;
}

//-----------------------------------------//-------------------------//
int GetDefaultSpellMode(EvadeSpellData spell)
{
	if (spell.dangerlevel > 3)
	{
		return 0;
	}

	return 1;
}

//-----------------------------------------//-------------------------//
bool PreferEvadeSpell()
{
	KNpc* myHero = GetPlayer();
	if (!myHero) return false;

	if (!ShouldUseEvadeSpell())
		return false;

	for (std::map<int, Spell>::iterator it = _SpellDetector->spells->begin(); it!= _SpellDetector->spells->end(); ++it)	
	{
		Spell spell = it->second;
		if (!InSkillShot(myHero->currentPos(), spell, BoundRadius(myHero)))
		{
			continue;
		}

		if (ActivateEvadeSpell(spell, true))
		{
			//__oMsg("PreferEvadeSpell-IN-IN-FUNC");
			return true;
		}
	}

	return false;
}

//-----------------------------------------//-------------------------//
void UseEvadeSpell()
{
	if (!ShouldUseEvadeSpell())
	{
		return;
	}

	//-//int posDangerlevel = EvadeHelper.CheckPosDangerLevel(ObjectCache.myHeroCache.serverPos2D, 0);

	if ((float)GetTickCount() - _EvadeSpell->lastSpellEvadeCommand->timestamp < 1000)
	{
		return;
	}
	
	for (std::map<int, Spell>::iterator it = _SpellDetector->spells->begin(); it!= _SpellDetector->spells->end(); ++it)	//BAT BUOC PHAI UPDATE CAI NAY`
	{
		Spell spell = it->second;

		if (ShouldActivateEvadeSpell(spell))
		{
			if (ActivateEvadeSpell(spell))
			{
				//__oMsg("UseEvadeSpell-EEEEEE1");
				SetAllUndodgeable();
				return;
			}
		}
	}
}

//-----------------------------------------//-------------------------//
bool CompareEvadeOption(PositionInfo* posInfo, bool checkSpell)
{
    if (checkSpell)
    {
        if (posInfo->posDangerLevel == 0)
        {
            return true;
        }
    }

    return isBetterMovePos(posInfo);
}

//-----------------------------------------//-------------------------//
bool ShouldActivateEvadeSpell(Spell spell)
{
	KNpc* myHero = GetPlayer();
	if (!myHero) return false;

    if (_Evade->lastPosInfo == 0)
        return false;

    if (DodgeSkillShots_menu)
    {
		std::vector<int>::iterator it_x = find (_Evade->lastPosInfo->undodgeableSpells->begin(), _Evade->lastPosInfo->undodgeableSpells->end(), spell.spellID);
		if(it_x != _Evade->lastPosInfo->undodgeableSpells->end())
		{
			if (InSkillShot(myHero->currentPos(), spell, BoundRadius(myHero)))
			{
				return true;
			}
		}
    }
    else
    {
        if (InSkillShot(myHero->currentPos(), spell, BoundRadius(myHero)))
        {
            return true;
        }
    }
    ///////*float activationTime = Evade.menu.SubMenu("MiscSettings").SubMenu("EvadeSpellMisc").Item("EvadeSpellActivationTime")
    //////    .GetValue<Slider>().Value + ObjectCache.gamePing;

    //////if (spell.spellHitTime != float.MinValue && activationTime > spell.spellHitTime - spell.evadeTime)
    //////{
    //////    return true;
    //////}*/

    return false;
}

//-----------------------------------------//-------------------------//
bool ShouldUseMovementBuff(Spell spell)
{	
	for (int i = 0; i < (int)_EvadeSpell->evadeSpells->size(); ++i)	//da sap xep roi
	{
		EvadeSpellData evadespell = _EvadeSpell->evadeSpells->at(i);
		if (evadespell.evadeType == _MovementSpeedBuff)
		{
			if (evadespell.esSetting.UseSpell == true 
				&& GetSpellDangerLevel_ES(evadespell) <= GetSpellDangerLevel(spell)
				//&& (evadespell.isItem && Items.CanUseItem((int)evadeSpell.itemID)
				&& (evadespell.isItem == false && CanCast(evadespell.spellKey) == true))
			{
				if (evadespell.checkSpellName == false)
				{
					return true;
				}
				else
				{
					KNpc* myHero = GetPlayer();
					if (!myHero) continue;

					KSkill *pSkill = (KSkill *)myHero->_pSkill[evadespell.spellKey];
					if (!pSkill) continue;

					KSkill_2*  pKSkill2 = (KSkill_2*) pSkill->__pK_str2;
					if (!pKSkill2) continue;

					if (evadespell.spellName.compare(pKSkill2->GetSkillName()) == 0)	//chac phai convert to lower
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

//-----------------------------------------//-------------------------//
int GetSpellDangerLevel_ES(EvadeSpellData evadeSpell)
{
	return evadeSpell.esSetting.EvadeSpellDangerLevel + 1;
}

//-----------------------------------------//-------------------------//
bool ActivateEvadeSpell(Spell spell, bool checkSpell)
{
	KNpc* myHero = GetPlayer();
	if (!myHero) return false;

	if (CheckName("_trap", (char*)spell.info.spellName.c_str()))
		return false;

	//--//var sortedEvadeSpells = evadeSpells.OrderBy(s => s.dangerlevel);	//sort roi hay sao ay

	float extraDelayBuffer    = ExtraPingBuffer_menu;	//default = 65
	float spellActivationTime = SpellActivationTime_menu + (float)GetPingGame() + extraDelayBuffer;	//default = 400 + xx + xxx

	if (CalculateWindupDelay_menu == true)
	{
		float extraWindupDelay = _Evade->lastWindupTime - (float)GetTickCount();
		if (extraWindupDelay > 0)
		{
			return false;
		}
	}
	
	for (int i = 0; i < (int)_EvadeSpell->evadeSpells->size(); ++i)
	{
		bool processSpell = true;
		EvadeSpellData evadeSpell = _EvadeSpell->evadeSpells->at(i);

		if (evadeSpell.checkSpellName == true && evadeSpell.spellKey == 100)
		{
			evadeSpell.spellKey = E_slot; //for Gnar-Big-E
		}

		if (evadeSpell.esSetting.UseSpell == false || GetSpellDangerLevel_ES(evadeSpell) > GetSpellDangerLevel(spell)
			|| (evadeSpell.isItem == false &&  CanCast(evadeSpell.spellKey) == false))
			//|| (evadeSpell.isItem && !Items.CanUseItem((int)evadeSpell.itemID))	
		{
			continue; //can't use spell right now               
		}

		if (evadeSpell.checkSpellName == true)
		{
			KSkill *pSkill = (KSkill *)myHero->_pSkill[evadeSpell.spellKey];
			if (!pSkill) continue;

			KSkill_2*  pKSkill2 = (KSkill_2*) pSkill->__pK_str2;
			if (!pKSkill2) continue;
			
			//__oMsg("SpellName: %s", pKSkill2->GetSkillName());
			if(evadeSpell.spellName.compare(pKSkill2->GetSkillName()) != 0) continue;	//chac phai convert to lower
		}

		//-------------//-------:
		float evadeTime, spellHitTime;
		CanHeroEvade(spell, myHero, evadeTime, spellHitTime);

		float finalEvadeTime = (spellHitTime - evadeTime);

		if (checkSpell)
		{
			int mode = evadeSpell.esSetting.EvadeSpellMode;
			if (mode == 0)		//---- "Undodgeable"
			{
				continue;
			}
			else if (mode == 1)	//---- "Activation Time"
			{
				if (spellActivationTime < finalEvadeTime)
				{
					continue;
				}
			}
		}
		else
		{
			//--//if (ObjectCache.menuCache.cache[evadeSpell.name + "LastResort"].GetValue<bool>())
			if (evadeSpell.spellDelay <= 50 && evadeSpell.evadeType != _Dash)
			{
				std::vector<Vec3D> path = Unit_Path(myHero);	
				if ((int)path.size() > 0)
				{
					Vec3D movePos = path.back();
					PositionInfo* posInfo = CanHeroWalkToPos(movePos, myHero->nMoveSpeed, 0, 0);

					if (GetSpellDangerLevel_ES(evadeSpell) > posInfo->posDangerLevel)
					{
						continue;
					}
				}
			}
		}

		//-------------//-------:
		if (evadeSpell.evadeType != _Dash && spellHitTime > evadeSpell.spellDelay + 75 + (float)GetPingGame() + ExtraPingBuffer_menu)
		{
			processSpell = false;

			if (checkSpell == false)
			{
				continue;
			}
		}
		
		//-------------//-------:
		if (evadeSpell.isSpecial)
		{
			if (useSpellFunc_CB != 0)
			{
				if (useSpellFunc_CB(evadeSpell, processSpell))
				{
					return true;
				}
			}

			continue;
		}
		else if (evadeSpell.evadeType == _Blink)
		{
			if (evadeSpell.castType == _Position)
			{
				PositionInfo* posInfo = GetBestPositionBlink();
				if (posInfo != 0)
				{
					if (processSpell == true)
					{
						EC_CastSpell(&evadeSpell, posInfo->position);
						//--//-- DelayAction.Add(50, () => myHero.IssueOrder(GameObjectOrder.MoveTo, posInfo.position.To3D()));
						return true;
					}
				}
			}
			else if (evadeSpell.castType == _Target)
			{
				PositionInfo* posInfo = GetBestPositionTargetedDash(evadeSpell);
				if (posInfo != 0 && posInfo->target != 0 && posInfo->posDangerLevel == 0)
				{
					if (processSpell == true)
					{
						
						if (evadeSpell.charName.compare("Katarina") == 0 || evadeSpell.charName.compare("Xayah") == 0 || evadeSpell.charName.compare("Evelynn") == 0)
						{
							//__oMsg("vao-mammama");
							EC_CastSpell(&evadeSpell, posInfo->target->currentPos());
							//--//-- DelayAction.Add(50, () => myHero.IssueOrder(GameObjectOrder.MoveTo, posInfo.position.To3D()));
							return true;
						}
						else
						{
							//__oMsg("xxx--vao-mammama");
							EC_CastSpell(&evadeSpell, posInfo->target);
							//--//-- DelayAction.Add(50, () => myHero.IssueOrder(GameObjectOrder.MoveTo, posInfo.position.To3D()));
							return true;
						}
					}
				}
			}
		}
		else if (evadeSpell.evadeType == _Dash)
		{
			if (evadeSpell.castType == _Position)
			{
				PositionInfo* posInfo = GetBestPositionDash(evadeSpell);
				if (posInfo != 0 && CompareEvadeOption(posInfo, checkSpell))
				{
					if (evadeSpell.isReversed)
					{
						Vec3D dir   = (posInfo->position - myHero->currentPos()).Normalized();
						float range = myHero->currentPos().Distance2D(posInfo->position);
						Vec3D pos   = myHero->currentPos() - dir * range;

						posInfo->position = pos;
					}
					
					if (processSpell) 
					{
						EC_CastSpell(&evadeSpell, posInfo->position);
						//--//-- DelayAction.Add(50, () => myHero.IssueOrder(GameObjectOrder.MoveTo, posInfo.position.To3D()));
						return true;
					}
				}
			}
			else if (evadeSpell.castType == _Target)
			{
				PositionInfo* posInfo = GetBestPositionTargetedDash(evadeSpell);
				if (posInfo != 0 && posInfo->target != 0 && posInfo->posDangerLevel == 0)
				{
					if (processSpell) 
					{
						EC_CastSpell(&evadeSpell, posInfo->target);
						EC_MoveTo(posInfo->target->currentPos());
						EC_CastSpell(&evadeSpell, posInfo->target);
						EC_MoveTo(posInfo->target->currentPos());
						EC_CastSpell(&evadeSpell, posInfo->target);
						//__oMsg("vkl-1: %x - %d - %d - %s", posInfo->target, IS_DEAD(posInfo->target), IS_OBJ_DELETED(posInfo->target), posInfo->target->GetNameNpc());
						//--//-- DelayAction.Add(50, () => myHero.IssueOrder(GameObjectOrder.MoveTo, posInfo.position.To3D()));
						return true;
					}					
				}
			}
		}
		else if (evadeSpell.evadeType == _WindWall)
		{
			if (hasProjectile(spell) || evadeSpell.spellName.compare("FioraW") == 0) //temp fix, don't have fiora :'(
			{
				Vec3D dir = (spell.startPos - myHero->currentPos()).Normalized();
				Vec3D pos = myHero->currentPos() + dir * 100;
				
				if (processSpell) 
				{
					EC_CastSpell(&evadeSpell, pos);
					return true;
				}
			}
		}
		else if (evadeSpell.evadeType == _SpellShield)
		{
			//if (evadeSpell.isItem)
			//{
			//	CastEvadeSpell(() => Items.UseItem((int)evadeSpell.itemID), processSpell);
			//	return true;
			//}

			if (evadeSpell.castType == _Target)
			{
				if (processSpell) 
				{
					EC_CastSpell(&evadeSpell, myHero);
					return true;
				}
			}

			if (evadeSpell.castType == _Self)
			{
				if (processSpell) 
				{
					EC_CastSpell(&evadeSpell, myHero);
					return true;
				}
			}
		}
		else if (evadeSpell.evadeType == _MovementSpeedBuff)
		{
			if (evadeSpell.isItem)
			{
				//PositionInfo* posInfo = GetBestPosition();
				//if (posInfo != 0)
				//{
				//	CastEvadeSpell(() => Items.UseItem((int)evadeSpell.itemID), processSpell);
				//	DelayAction.Add(5, () => EvadeCommand.MoveTo(posInfo.position));
				//	return true;
				//}
			}
			else
			{
				if (evadeSpell.castType == _Self)
				{
					PositionInfo* posInfo = GetBestPosition();
					if (posInfo != 0)
					{
						if (processSpell) 
						{
							EC_CastSpell(&evadeSpell, myHero);
							EC_MoveTo(posInfo->position);	// phai delay 5ms
							return true;
						}
					}
				}
				else if (evadeSpell.castType == _Position)
				{
					PositionInfo* posInfo = GetBestPosition();
					if (posInfo != 0)
					{
						if (processSpell) 
						{
							EC_CastSpell(&evadeSpell, posInfo->position);
							EC_MoveTo(posInfo->position);  // phai delay 5ms
							return true;
						}
					}
				}
			}
		}
	}

	return false;
}