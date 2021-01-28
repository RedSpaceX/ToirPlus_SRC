#include "Evade.h"
#include "Position.h"
#include "PositionInfo.h"
#include "EvadeUtils.h"
#include "EvadeCommand.h"
#include "EvadeHelper.h"
#include "Situation.h"
#include "SpellDetector.h"
#include "EvadeSpells.h"

extern SpellDetector*	_SpellDetector;
extern Evade*			_Evade;
extern EvadeHelper*		_EvadeHelper;
extern EvadeUtils*		_EvadeUtils;

extern float TickLimiter_menu, ExtraPingBuffer_menu;
extern bool ClickOnlyOnce_menu, EnableEvadeDistance_menu, ContinueMovement_menu, RecalculatePosition_menu, DodgeSkillShots_menu, FastMovementBlock_menu;
extern bool DodgeDangerous_menu, DodgeDangerousKeyEnabled_menu;
extern int  DodgeDangerousKey_menu, DodgeDangerousKey2_menu;

extern GameObjectIssueOrderEventArgs* ArgsMove;

void fuck()
{
	//int posChecked = 0;
	//int maxPosToCheck = 50;
	//int posRadius = 30;
	//int radiusIndex = 0;

	//Vec3D heroPoint   = GetPlayer()->currentPos();
	//Vec3D lastMovePos = mousePosVec3D();

	//std::vector<PositionInfo*> posTable;
	//extern float ExtraPingBuffer_menu, ExtraEvadeDistance_menu;
	//float extraDelayBuffer   = ExtraPingBuffer_menu;
	//float extraEvadeDistance = ExtraEvadeDistance_menu;
	//Spell lowestEvadeTimeSpell;

	//while (posChecked < maxPosToCheck)
	//{
	//	radiusIndex++;

	//	int curRadius = radiusIndex * (2 * posRadius);
	//	int curCircleChecks = (int)ceil((2 *  3.1415927f * (float)curRadius) / (2 * (float)posRadius));

	//	for (int i = 1; i < curCircleChecks; i++)
	//	{
	//		posChecked++;
	//		float cRadians = (2 * 3.1415927f / (curCircleChecks - 1)) * i; //check decimals
	//		Vec3D pos((float)floor(heroPoint.x + curRadius * cos(cRadians)), heroPoint.y, (float)floor(heroPoint.z + curRadius * sin(cRadians)));
	//		posTable.push_back(InitPositionInfo(pos, extraDelayBuffer, extraEvadeDistance, lastMovePos, lowestEvadeTimeSpell));
	//		Draw2DCircle(pos, 3, WHITE);
	//	}
	//}
}

//---------------------------------------------------------------------//--------------------//
void OnGameUpdate_Evade()	//*********
{
	fuck();

	__try
	{
		////ObjectCache.myHeroCache.UpdateInfo();
		CheckHeroInDanger();

		/*if (isChanneling && channelPosition.Distance(ObjectCache.myHeroCache.serverPos2D) > 50
			&& !myHero.IsChannelingImportantSpell())
		{
			isChanneling = false;
		}*/

		/*if (ObjectCache.menuCache.cache["ResetConfig"].GetValue<bool>())
		{
			ResetConfig();
			menu.Item("ResetConfig").SetValue(false);
		}*/

		float limitDelay = TickLimiter_menu; //Tick limiter : default=100ms

		if (_EvadeHelper->fastEvadeMode || _EvadeUtils->TickCount() - _Evade->lastTickCount > limitDelay)
		{
			if (_EvadeUtils->TickCount() > _Evade->lastStopEvadeTime)
			{
				DodgeSkillShots_func();				//walking           
				ContinueLastBlockedCommand();
			}

			_Evade->lastTickCount = _EvadeUtils->TickCount();
		}

		UseEvadeSpell();				//using spells
		CheckDodgeOnlyDangerous();		// chi ne skill nguy hiem
		RecalculatePath();
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		//__oMsg("ERROR : OnGameUpdate.Evade");
		SEND_TEXT_SYSTEM("ERROR : OnGameUpdate.Evade");
	}
}

//---------------------------------------------------------------------//--------------------//
void RecalculatePath()
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return;
	
	if (RecalculatePosition_menu && _Evade->isDodging)//recheck path
	{
		if (_Evade->lastPosInfo != 0 && !_Evade->lastPosInfo->recalculatedPath)
		{
			std::vector<Vec3D> path = Unit_Path(myHero);

			if ((int)path.size() > 0)
			{
				Vec3D movePos = path.back();
				if (movePos.Distance2D(_Evade->lastPosInfo->position) < 5) //more strict checking
				{
					PositionInfo* posInfo = CanHeroWalkToPos(movePos, myHero->nMoveSpeed, 0, 0, false);		// doan nay co the tao con tro nhieu
					if (posInfo->posDangerCount > _Evade->lastPosInfo->posDangerCount)
					{
						_Evade->lastPosInfo->recalculatedPath = true;

						if (PreferEvadeSpell())					//dung spell de ne'
						{
							_Evade->lastPosInfo = SetAllUndodgeable();
							//__oMsg("[-][-]--- EVADE+SPELL --- RecalculatePath->PreferEvadeSpell");
						}
						else
						{
							PositionInfo* newPosInfo = GetBestPosition();
							if (newPosInfo->posDangerCount < posInfo->posDangerCount)
							{
								//__oMsg("[IN.RecalculatePath()-2]");
								_Evade->lastPosInfo = newPosInfo;
								CheckHeroInDanger();
								DodgeSkillShots_func();
							}
						}
					}
				}
			}
		}
	}
}

//---------------------------------------------------------------------//--------------------//
void ContinueLastBlockedCommand()
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return;

	if (ContinueMovement_menu && ShouldDodge())		//"Continue Last Movement" - default = true
	{
		Vec3D movePos    = _Evade->lastBlockedUserMoveTo->targetPosition;
		float extraDelay = ExtraPingBuffer_menu;

		if (_Evade->isDodging == false && _Evade->lastBlockedUserMoveTo->isProcessed == false
			&& _EvadeUtils->TickCount() - _Evade->lastEvadeCommand->timestamp > (float)GetPingGame() + extraDelay
			&& _EvadeUtils->TickCount() - _Evade->lastBlockedUserMoveTo->timestamp < 1500)
		{
			int iSecret = 35;
			srand ((unsigned)time(NULL));
			iSecret = rand() % 65 + 1;

			movePos = movePos + (movePos - myHero->currentPos()).Normalized() * (float)iSecret;

			if (!CheckMovePath(movePos, (float)GetPingGame() + extraDelay))
			{
				//////Console.WriteLine("Continue Movement");
				//////myHero.IssueOrder(GameObjectOrder.MoveTo, movePos.To3D());
				EC_MoveTo(movePos);
				_Evade->lastBlockedUserMoveTo->isProcessed = true;
				//__oMsg("      -[***]- ContinueLastBlockedCommand ====> NE' =====> NE'");
			}
		}
	}
}

//---------------------------------------------------------------------//--------------------//
void CheckHeroInDanger()
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return;

	bool playerInDanger = false;
	
	for (std::map<int, Spell>::iterator it_spells = _SpellDetector->spells->begin(); it_spells!= _SpellDetector->spells->end(); ++it_spells)
	{
		Spell spell = it_spells->second;
		
		if (_Evade->lastPosInfo != 0)
		{
			//__oMsg("SIZE(%d), spell.spellID: %d", _Evade->lastPosInfo->dodgeableSpells->size(), spell.spellID);
			std::vector<int>::iterator it_x = find (_Evade->lastPosInfo->dodgeableSpells->begin(), _Evade->lastPosInfo->dodgeableSpells->end(), spell.spellID);
			if (it_x != _Evade->lastPosInfo->dodgeableSpells->end())
			{
				//__oMsg("InSkillShot() : %d", InSkillShot(myHero->currentPos(), spell, BoundRadius(myHero)));
				if (InSkillShot(myHero->currentPos(), spell, BoundRadius(myHero)))
				{
					playerInDanger = true;
					break;
				}

				if (EnableEvadeDistance_menu && _EvadeUtils->TickCount() < _Evade->lastPosInfo->endTime)	// "Extended Evade" - default = false
				{
					playerInDanger = true;
					break;
				}
			}
		}
	}

	if (_Evade->isDodging && !playerInDanger)
	{
		_Evade->lastDodgingEndTime = _EvadeUtils->TickCount();
	}

	if (_Evade->isDodging == false && !ShouldDodge())
		return;

	_Evade->isDodging = playerInDanger;
}

//---------------------------------------------------------------------//--------------------//
void DodgeSkillShots_func()
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return;

    if (!ShouldDodge())
    {
        _Evade->isDodging = false;
        return;
    }

    ///////*
    //////if (isDodging && playerInDanger == false) //serverpos test
    //////{
    //////    myHero.IssueOrder(GameObjectOrder.HoldPosition, myHero, false);
    //////}*/

    if (_Evade->isDodging)
    {
        if (_Evade->lastPosInfo != 0)
        {
            ///////*foreach (KeyValuePair<int, Spell> entry in SpellDetector.spells)
            //////{
            //////    Spell spell = entry.Value;

            //////    Console.WriteLine("" + (int)(TickCount-spell.startTime));
            //////}*/

            Vec3D lastBestPosition = _Evade->lastPosInfo->position;
			std::vector<Vec3D> path = Unit_Path(myHero);

			if (ClickOnlyOnce_menu == false || !((int)path.size() > 0 && _Evade->lastPosInfo->position.Distance2D(path.back()) < 5))
			//--///|| lastPosInfo.timestamp > lastEvadeOrderTime)
			{
				EC_MoveTo(lastBestPosition);
				//Draw2DCircle(lastBestPosition, 1, RED);
				_Evade->lastEvadeOrderTime = _EvadeUtils->TickCount();
				//__oMsg("      -[***]- DodgeSkillShots_func.222 ====> NE' =====> NE'");
			}
        }
    }
    else //if not dodging
    {
		//Check if hero will walk into a skillshot
		std::vector<Vec3D> path = Unit_Path(myHero);	

		if((int)path.size() > 0)
		{
			Vec3D movePos = path.back();
			if (movePos.IsValid() && CheckMovePath(movePos))
			{
				PositionInfo* posInfo = GetBestPositionMovementBlock(movePos);
				if (posInfo != 0)
				{
					EC_MoveTo(posInfo->position);
					//__oMsg("      -[***]- DodgeSkillShots_func.333 ====> NE' =====> NE'");
				}
				return;
			}
		}
    }
}

//---------------------------------------------------------------------//--------------------//
void CheckLastMoveTo()
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return;

	if (_EvadeHelper->fastEvadeMode || FastMovementBlock_menu)
	{
		if (_Evade->isDodging == false)
		{
			if (_Evade->lastIssueOrderArgs != 0 && _Evade->lastIssueOrderArgs->Order == Order_MoveTo)
			{
				if (GetTimeGame() * 1000 - _Evade->lastIssueOrderGameTime < 500)
				{
					OnIssueOrder_Evade(myHero, _Evade->lastIssueOrderArgs);
					_Evade->lastIssueOrderArgs = 0;
				}
			}
		}
	}
}

//---------------------------------------------------------------------//--------------------//
bool isDodgeDangerousEnabled()
{
	if (DodgeDangerous_menu == true)	return true;		//"Dodge Only Dangerous", default = false

	if (DodgeDangerousKeyEnabled_menu == true)
	{
		if(isRiotOnTop())
		{
			if((GetAsyncKeyState(DodgeDangerousKey_menu) & 0x8000) || (GetAsyncKeyState(DodgeDangerousKey2_menu) & 0x8000))
				return true;
		}
	}

	return false;
}

//---------------------------------------------------------------------//--------------------//
void CheckDodgeOnlyDangerous() //Dodge only dangerous event
{
	bool bDodgeOnlyDangerous = isDodgeDangerousEnabled();

	if (_Evade->dodgeOnlyDangerous == false && bDodgeOnlyDangerous)
	{
		RemoveNonDangerousSpells();
		_Evade->dodgeOnlyDangerous = true;
	}
	else
	{
		_Evade->dodgeOnlyDangerous = bDodgeOnlyDangerous;
	}
}

//---------------------------------------------------------------------//--------------------//
void SpellDetector_OnProcessDetectedSpells()
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return;

    if (DodgeSkillShots_menu == false)
    {
        _Evade->lastPosInfo = SetAllUndodgeable();
        UseEvadeSpell();
        return;
    }
	
	float extraDelayBuffer = ExtraPingBuffer_menu;
    if (CheckDangerousPos(myHero->currentPos(), 0) /* || CheckDangerousPos(GetGamePosition(myHero, (float)GetPingGame() + extraDelayBuffer), 0)*/)	//serverPos2DExtra = GetGamePosition(myHero, (float)GetPingGame() + extraDelayBuffer)
    {
        if (PreferEvadeSpell())
        {
            _Evade->lastPosInfo = SetAllUndodgeable();
			//__oMsg(" [-][-]--- EVADE+SPELL --- SpellDetector_OnProcessDetectedSpells->PreferEvadeSpell");
        }
        else
        {
            PositionInfo *posInfo = GetBestPosition();

            float calculationTimer = _EvadeUtils->TickCount();
            float caculationTime   = _EvadeUtils->TickCount() - calculationTimer;

            ////////////computing time
            ///////////*if (numCalculationTime > 0)
            //////////{
            //////////    sumCalculationTime += caculationTime;
            //////////    avgCalculationTime = sumCalculationTime / numCalculationTime;
            //////////}
            //////////numCalculationTime += 1;*/

            ////////////Console.WriteLine("CalculationTime: " + caculationTime);

            ///////////*if (EvadeHelper.GetHighestDetectedSpellID() > EvadeHelper.GetHighestSpellID(posInfo))
            //////////{
            //////////    return;
            //////////}*/

            if (posInfo != 0)
            {
                _Evade->lastPosInfo = CompareLastMovePos(posInfo);

				//Vec3D serverPos2DPing = GetGamePosition(myHero, (float)GetPingGame());
				Vec3D serverPos2DPing = myHero->currentPos();
                float travelTime = serverPos2DPing.Distance2D(_Evade->lastPosInfo->position) / myHero->nMoveSpeed;

                _Evade->lastPosInfo->endTime = _EvadeUtils->TickCount() + travelTime * 1000 - 100;
            }
			
            CheckHeroInDanger();

            if (_EvadeUtils->TickCount() > _Evade->lastStopEvadeTime)
            {
                DodgeSkillShots_func(); //walking   
				//__oMsg("      -[***]- SpellDetector_OnProcessDetectedSpells ====> NE' =====> NE'");
            }
			
            CheckLastMoveTo();
            UseEvadeSpell();	//using spells

        }
    }
    else
    {
         _Evade->lastPosInfo = SetAllDodgeable();
        CheckLastMoveTo();
    }


    //Console.WriteLine("SkillsDodged: " + lastPosInfo.dodgeableSpells.Count + " DangerLevel: " + lastPosInfo.undodgeableSpells.Count);            
}

//---------------------------------------------------------------------//--------------------//
void OnIssueOrder_Evade(KNpc* hero, GameObjectIssueOrderEventArgs* args)
{
	if(args == 0) return;
	if(hero == 0) hero = GetPlayer();
	if(hero == 0) return;
		
	if (!ShouldDodge())
		return;

	if (args->Order == 2)	//Move
    {
        if (_Evade->isDodging && (int)_SpellDetector->spells->size() > 0)
        {
            CheckHeroInDanger();

            _Evade->lastBlockedUserMoveTo->order = Order_MoveTo;
			_Evade->lastBlockedUserMoveTo->targetPosition = args->TargetPosition;
			_Evade->lastBlockedUserMoveTo->timestamp	  = (float)GetTickCount();
			_Evade->lastBlockedUserMoveTo->isProcessed	  = false;
			
            args->Process = false;	//Block the command
        }
        else
        {
            Vec3D movePos = args->TargetPosition;
            float extraDelay = ExtraPingBuffer_menu;
        
            if (CheckMovePath(movePos, (float)GetPingGame() + extraDelay))
            {
                ///////*if (ObjectCache.menuCache.cache["AllowCrossing"].GetValue<bool>())
                //////{
                //////    var extraDelayBuffer = ObjectCache.menuCache.cache["ExtraPingBuffer"]
                //////        .GetValue<Slider>().Value + 30;
                //////    var extraDist = ObjectCache.menuCache.cache["ExtraCPADistance"]
                //////        .GetValue<Slider>().Value + 10;

                //////    var tPosInfo = EvadeHelper.CanHeroWalkToPos(movePos, ObjectCache.myHeroCache.moveSpeed, extraDelayBuffer + ObjectCache.gamePing, extraDist);

                //////    if (tPosInfo.posDangerLevel == 0)
                //////    {
                //////        lastPosInfo = tPosInfo;
                //////        return;
                //////    }
                //////}*/
				
				_Evade->lastBlockedUserMoveTo->order = Order_MoveTo;
				_Evade->lastBlockedUserMoveTo->targetPosition = args->TargetPosition;
				_Evade->lastBlockedUserMoveTo->timestamp	  = (float)GetTickCount();
				_Evade->lastBlockedUserMoveTo->isProcessed	  = false;

                args->Process = false; //Block the command

                if ((float)GetTickCount() - _Evade->lastMovementBlockTime < 500 && _Evade->lastMovementBlockPos.Distance2D(args->TargetPosition) < 100)
                {
                    return;
                }

                _Evade->lastMovementBlockPos  = args->TargetPosition;
                _Evade->lastMovementBlockTime = (float)GetTickCount();

                PositionInfo* posInfo = GetBestPositionMovementBlock(movePos);
                if (posInfo != 0)
                {
                    EC_MoveTo(posInfo->position);
                }
                return;
            }
            else
            {
                _Evade->lastBlockedUserMoveTo->isProcessed = true;
            }
        }
    }
	else //need more logic
	{
		if (_Evade->isDodging)
		{
			args->Process = false; //Block the command
		}
		else
		{
			if (args->Order == 3)	//Order_Auto.Attack
			{
				KNpc* target = args->Target;
				if (target != 0 && IsValidObj(target))
				{
					if (Distance(hero, target) > hero->nAttackRange + 110)
					{
						Vec3D movePos = args->TargetPosition;
						float extraDelay = ExtraPingBuffer_menu;
						if (CheckMovePath(movePos, (float)GetPingGame() + extraDelay))
						{
							args->Process = false; //Block the command
							return;
						}
					}
				}
			}
		}
	}

	if (args->Process == true)
	{
		_Evade->lastIssueOrderGameTime = GetTimeGame() * 1000;
		_Evade->lastIssueOrderTime	   = (float)GetTickCount();
		_Evade->lastIssueOrderArgs     = args;

		if (args->Order == 2)
		{
			_Evade->lastMoveToPosition  = args->TargetPosition;
			_Evade->lastMoveToServerPos = hero->currentPos();
		}

		//if (args->Order == Stop)	
		//{
		//	lastStopPosition = myHero.ServerPosition.To2D();		// ko thay no dung` lam gi
		//}
	}
}