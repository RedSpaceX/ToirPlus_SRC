#include "DodgePykeS.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"


extern SpellDetector* _SpellDetector;
extern bool DodgeFOWSpells_menu;
//---------------------------------------------------------------------//--------------------//
void Evade_Pyke_Q()
{
	//KNpc* myHero = GetPlayer();
	//if (!myHero) return;
	//if (G_Module == 0) return;

	//DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	//DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	//DWORD dwHero1 = *(DWORD*)tempHero;
	//DWORD dwHero2 = *(DWORD*)tempHeroMax;
	//if (!dwHero1 || !dwHero2 ) return;

	//int countHero = (dwHero2 - dwHero1)/4;
	//for (int i = 0; i < countHero; ++i)
	//{
	//	DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
	//	if (dwHero3 == 0) continue;
	//	KNpc *enemyHero = (KNpc*)dwHero3;
	//	if (IS_DEAD(enemyHero)) continue;
	//	if (enemyHero->nTeam_ID == myHero->nTeam_ID) continue;
	//	//if (!CheckName(enemyHero->GetNameHero(), "Pyke")) continue;

	//	//----//----//----:
	//	if (IsCanSee(enemyHero))
	//	{
	//		if (Distance(enemyHero, myHero) > 2200)	continue;

	//		DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
	//		DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
	//		DWORD dw1 = *(DWORD*)dw0;
	//		if (!dw1) return;

	//		int countAllObj = *(DWORD*)(dw0 + 4);
	//		if (!countAllObj) return;

	//		for (int kk = 0; kk < countAllObj; ++kk)
	//		{
	//			DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
	//			if (dw3 == 0) continue;
	//			KNpc *missileObj = (KNpc*)dw3;

	//			if (IS_OBJ_DELETED(missileObj) == true)	continue;
	//			//if (missileObj->nIndex < 0x3FFFFCC8)    continue;
	//			if (OBJECT_TYPE(missileObj) != 1)       continue;

	//			//if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
	//			//if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;

	//			if (CheckName("Q_Channel_Cas", missileObj->GetNameNpc()) && CheckName("Pyke", missileObj->GetNameNpc()))	//Pyke_Base_Q_Channel_Cas
	//			{
	//				//------//------//------:
	//				std::string Special_name("PykeQ_Special");
	//				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
	//				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
	//				{
	//					SpellData spellData = it_onProcessSpells->second;

	//					Vec3D StartPos = enemyHero->currentPos(); 
	//					Vec3D EndPos   = Extend(StartPos, GET_REAL_FACING_POS(enemyHero), 500); 

	//					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
	//					{
	//						float missileLifeTime = spellData.projectileSpeed > 0 ? 999 + 1000*spellData.range/spellData.projectileSpeed : 1000.0f;

	//						if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	//						{
	//							//__oMsg("---((*11*))----- PYKE_Q_-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",Special_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
	//							it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();

	//							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
	//						}
	//					}
	//				}
	//			}
	//		}
	//	}
	//	else
	//	{
	//		DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
	//		DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
	//		DWORD dw1 = *(DWORD*)dw0;
	//		if (!dw1) return;

	//		int countAllObj = *(DWORD*)(dw0 + 4);
	//		if (!countAllObj) return;

	//		for (int kk = 0; kk < countAllObj; ++kk)
	//		{
	//			DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
	//			if (dw3 == 0) continue;
	//			KNpc *missileObj = (KNpc*)dw3;

	//			if (IS_OBJ_DELETED(missileObj) == true)	continue;
	//			if (missileObj->nIndex < 0x3FFFFCC8)    continue;
	//			//if (OBJECT_TYPE(missileObj) != 1)       continue;

	//			if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
	//			if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;

	//			if (CheckName("PykeQRange", missileObj->GetNameNpc()))	//PykeQRange
	//			{
	//				//------//------//------:
	//				std::string Special_name("PykeQ_Special");
	//				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
	//				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
	//				{
	//					SpellData spellData = it_onProcessSpells->second;

	//					Vec3D StartPos (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
	//					Vec3D EndPos   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z);  

	//					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
	//					{
	//						float missileLifeTime = spellData.projectileSpeed > 0 ? 999 + 1000*spellData.range/spellData.projectileSpeed : 1000.0f;

	//						if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	//						{
	//							//__oMsg("---((*22*))----- PYKE_Q_FOW-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",Special_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
	//							it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();

	//							CreateSpellData(enemyHero, StartPos, EndPos, spellData, missileObj, 0);
	//						}
	//					}
	//				}
	//			}
	//		}
	//	}
	//}
}

//---------------------------------------------------------------------//--------------------//
//////float timeStartEPyke = 0;
//////Vec3D startPosEPyke(0,0,0);
void Evade_Pyke_E()
{
	//////////----//----:
	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;
	////////if (G_Module == 0) return;

	////////DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	////////DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	////////DWORD dwHero1 = *(DWORD*)tempHero;
	////////DWORD dwHero2 = *(DWORD*)tempHeroMax;
	////////if (!dwHero1 || !dwHero2 ) return;

	////////int countHero = (dwHero2 - dwHero1)/4;
	////////for (int i = 0; i < countHero; ++i)
	////////{
	////////	DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
	////////	if (dwHero3 == 0) continue;
	////////	KNpc *enemyHero = (KNpc*)dwHero3;
	////////	if (IS_DEAD(enemyHero)) continue;
	////////	if (enemyHero->nTeam_ID == myHero->nTeam_ID)	  continue;
	////////	if (!IsCanSee(enemyHero))						  continue;
	////////	if (Distance(enemyHero, myHero) > 2000)			  continue;
	////////	if (!CheckName(enemyHero->GetNameHero(), "Pyke")) continue;
	////////	
	////////	if ((float)GetTickCount() - timeStartEPyke > 1666) 
	////////	{
	////////		timeStartEPyke = 0;
	////////		Vec3D zero(0,0,0);
	////////		startPosEPyke = zero;
	////////	}

	////////	//----//----//----:
	////////	KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
	////////	if (args)
	////////	{
	////////		KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
	////////		if(pK_str2)
	////////		{
	////////			std::string spell_name(pK_str2->GetSkillName());
	////////			if (timeStartEPyke == 0 && spell_name.compare("PykeE") == 0)
	////////			{
	////////				//timeDelayCastE   = 1000*(args->nTime_DanBatDauBay - args->nTime_BatDauBAN);		// nhin thay thi = 275, FOW thi nho hon
	////////				//if (timeDelayCastE <= 0) timeDelayCastE = 100;
	////////				//__oMsg("fffaafa: %f", timeDelayCastE);

	////////				timeStartEPyke  = (float)GetTickCount();
	////////				
	////////				Vec3D TempSrcPos(args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
	////////				Vec3D TempEndPos(args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);

	////////				startPosEPyke = Extend(TempSrcPos, TempEndPos, -100);
	////////			}
	////////		}
	////////	}

	////////	//------//------//------:
	////////	if (timeStartEPyke > 0 && startPosEPyke.IsValid() && (float)GetTickCount() - timeStartEPyke > 250)
	////////	{
	////////		std::string Special_name("PykeE");
	////////		std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
	////////		if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
	////////		{
	////////			SpellData spellData = it_onProcessSpells->second;

	////////			Vec3D StartPos = startPosEPyke;
	////////			Vec3D EndPos   = enemyHero->currentPos();
	////////			
	////////			spellData.range = StartPos.Distance2D(enemyHero->currentPos()) + 250;

	////////			if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1500 )
	////////			{
	////////				float missileLifeTime = spellData.projectileSpeed > 0 ? 1999 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;

	////////				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////				{
	////////					//__oMsg("---((*11*))----- Pyke-EE-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",Special_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
	////////					it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();

	////////					CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
	////////				}
	////////			}
	////////		}
	////////	}
	////////}
}

////---------------------------------------------------------------------//--------------------//
//void Evade_Ornn_E()
//{
//	//----//----:
//	KNpc* myHero = GetPlayer();
//	if (!myHero) return;
//	if (G_Module == 0) return;
//
//	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
//	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
//	DWORD dwHero1 = *(DWORD*)tempHero;
//	DWORD dwHero2 = *(DWORD*)tempHeroMax;
//	if (!dwHero1 || !dwHero2 ) return;
//
//	int countHero = (dwHero2 - dwHero1)/4;
//	for (int i = 0; i < countHero; ++i)
//	{
//		DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
//		if (dwHero3 == 0) continue;
//		KNpc *enemyHero = (KNpc*)dwHero3;
//		if (IS_DEAD(enemyHero)) continue;
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID) continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Ornn")) continue;
//
//		//----//----//----:
//		if (IsCanSee(enemyHero))
//		{
//			if (Distance(enemyHero, myHero) > 2500)	continue;
//
//			KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//			if (args)
//			{
//				KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//				if(pK_str2)
//				{
//					std::string spell_name(pK_str2->GetSkillName());
//					if (spell_name.compare("OrnnE") == 0)
//					{
//						//------//------//------:
//						DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//						DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//						DWORD dw1 = *(DWORD*)dw0;
//						if (!dw1) return;
//
//						int countAllObj = *(DWORD*)(dw0 + 4);
//						if (!countAllObj) return;
//
//						for (int kk = 0; kk < countAllObj; ++kk)
//						{
//							DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//							if (dw3 == 0) continue;
//							KNpc *missileObj = (KNpc*)dw3;
//
//							if (IS_OBJ_DELETED(missileObj) == true)	continue;
//							if (missileObj->nIndex < 0x3FFFFCC8)    continue;
//							if (OBJECT_TYPE(missileObj) != 1)       continue;
//
//							if (CheckName("E_destination_mark", missileObj->GetNameNpc()) && CheckName("Ornn", missileObj->GetNameNpc()))	//Ornn_Base_E_destination_mark, Ornn_Base_E_Indicator_Red
//							{
//								std::string Special_name("OrnnE_Special");
//								std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
//								if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//								{
//									SpellData spellData   = it_onProcessSpells->second;
//									SpellData spellData_1 = it_onProcessSpells->second;
//
//									float missileLifeTime = spellData.projectileSpeed > 0 ? 999 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000.0f;
//
//									if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//									{
//										Vec3D StartPos(args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
//										Vec3D EndPos(args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);  
//
//										if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
//										{
//											__oMsg("---((*11*))----- ORNN_E11-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",Special_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//											it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//											CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//
//											spellData_1.spellType = Circular;
//											spellData_1.range     = Distance(StartPos, missileObj->currentPos());
//											Vec3D EndPos_1 = missileObj->currentPos();
//
//											CreateSpellData(enemyHero, StartPos, EndPos_1, spellData_1, 0, 0, true, Circular, true, 400);
//										}
//									}
//								}
//							}
//						}
//
//						//------//------//------:
//						std::string Special_name("OrnnE_Special");
//						std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
//						if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//						{
//							SpellData spellData = it_onProcessSpells->second;
//							
//							float missileLifeTime = spellData.projectileSpeed > 0 ? 999 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000.0f;
//
//							if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//							{
//								Vec3D StartPos(args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
//								Vec3D EndPos(args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);  
//
//								if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
//								{
//									__oMsg("---((*22*))----- ORNN_E22-CREATE-MISSLE-22222: MissileNam: %s, KC_Missile = %.3f - delay: %f",Special_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//									it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//									CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//		else
//		{
//			//...
//		}
//
//	}
//}