#include "DodgeMalzaharS.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"
#include "EvadeHelper.h"





extern SpellDetector* _SpellDetector;
extern bool DodgeFOWSpells_menu;
////---------------------------------------------------------------------//--------------------//
//DWORD _twoPortal[2] = {0};
//void Evade_Malzahar_Q()
//{
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)		  continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Malzahar")) continue;
//		
//		//------//------//------:
//		if (IsCanSee(enemyHero))
//		{
//			if (Distance(enemyHero, myHero) > 2500)	continue;
//
//			KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//			if (!args) continue;
//
//			KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//			if(!pK_str2) continue;
//
//			std::string spell_name(pK_str2->GetSkillName());
//			if (spell_name.compare("MalzaharQ") != 0) continue;		//pCastSpell xuat hien 1.991s
//
//			if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//
//			//------//------//------:
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spell_name)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData = it_onProcessSpells->second;
//
//				Vec3D StartPos(args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
//				Vec3D EndPos(args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
//
//				Vec3D direction  = (EndPos - StartPos).Normalized();
//				Vec3D pDirection = Perpendicular(direction);
//				Vec3D targetPoint = EndPos;
//				
//				Vec3D pos1 = targetPoint - pDirection * spellData.sideRadius;
//				Vec3D pos2 = targetPoint + pDirection * spellData.sideRadius;
//
//				if (pos1.Distance2D(myHero->currentPos()) < spellData.sideRadius + 1000 || pos2.Distance2D(myHero->currentPos()) < spellData.sideRadius + 1000)
//				{
//					float missileLifeTime = spellData.projectileSpeed > 0 ? 1350 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//					
//					if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//					{
//						//__oMsg("---((*11*))----- MalzaharQ-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//						CreateSpellData(enemyHero, pos1, pos2, spellData, 0, 0, false);
//						CreateSpellData(enemyHero, pos2, pos1, spellData, 0, 0);
//					}
//				}
//			}
//		}
//		else
//		{
//			if (DodgeFOWSpells_menu == false) return;
//
//			_twoPortal[0] = 0;
//			_twoPortal[1] = 0;
//
//			DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//			DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//			DWORD dw1 = *(DWORD*)dw0;
//			if (!dw1) return;
//
//			int countAllObj = *(DWORD*)(dw0 + 4);
//			if (!countAllObj) return;
//
//			for (int kk = 0; kk < countAllObj; ++kk)
//			{
//				DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//				if (dw3 == 0) continue;
//				KNpc *missileObj = (KNpc*)dw3;
//
//				if (IS_OBJ_DELETED(missileObj) == true)	 continue;
//				if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
//				if (OBJECT_TYPE(missileObj) != 1)		 continue;
//				
//				//Malzahar_Base_Q_Voidflash_01: 3s, Malzahar_Base_Q_portal_: 2s
//				if (CheckName("Q_portal", missileObj->GetNameNpc()) && CheckName("Malzahar", missileObj->GetNameNpc()))
//				{
//					if (_twoPortal[0] == 0)
//					{
//						_twoPortal[0] = (DWORD)missileObj;
//						continue;
//					}
//					else if (_twoPortal[1] == 0 && _twoPortal[0] != (DWORD)missileObj)
//					{
//						_twoPortal[1] = (DWORD)missileObj;
//						break;
//					}
//				}
//			}
//			
//			if (_twoPortal[0] == 0 || _twoPortal[1] == 0) return;
//
//			KNpc* portal0 = (KNpc*)_twoPortal[0];
//			KNpc* portal1 = (KNpc*)_twoPortal[1];
//
//			std::string mis_Name("MalzaharQ");	// lay ten nay` thi se ko create missile neu da create o pCastSpell roi
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(mis_Name)); // lay luon onProcessSpells cho missile
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData = it_onProcessSpells->second;
//				
//				float missileLifeTime = spellData.projectileSpeed > 0 ? 1350 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;	// cho delay vao cung dc k sao
//				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//				{
//					Vec3D pos0 = portal0->currentPos();
//					Vec3D pos1 = portal1->currentPos();
//
//					if (pos0.Distance2D(myHero->currentPos()) < spellData.range + 1000 || pos1.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//					{
//						
//							it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//							//__oMsg("---((*22*))----- MalzaharQ-CREATE-MISSLE-22222: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), pos0.Distance2D(pos1));
//							CreateSpellData(enemyHero, pos0, pos1, spellData, 0, 0, false);
//							CreateSpellData(enemyHero, pos1, pos0, spellData, 0, 0);
//					}
//				}	
//			}
//		}
//	}
//}

////---------------------------------------------------------------------//--------------------//
//float timeMisQVelkoz   = 0;
//Vec3D srcPosMisQVelkoz(0,0,0);
//void Evade_Velkoz_Q2()
//{
//	if (timeMisQVelkoz > 0 && (float)GetTickCount() - timeMisQVelkoz > 1555)
//	{
//		timeMisQVelkoz = 0;
//		Vec3D zero(0,0,0);
//		srcPosMisQVelkoz = zero;
//	}
//
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)		  continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Velkoz")) continue;
//						  
//		//if (DodgeFOWSpells_menu == false) return;	//bat buoc phai check missile, ko dung setting nay dc
//
//		DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//		DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//		DWORD dw1 = *(DWORD*)dw0;
//		if (!dw1) return;
//
//		int countAllObj = *(DWORD*)(dw0 + 4);
//		if (!countAllObj) return;
//
//		for (int kk = 0; kk < countAllObj; ++kk)
//		{
//			DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//			if (dw3 == 0) continue;
//			KNpc *missileObj = (KNpc*)dw3;
//
//			if (IS_OBJ_DELETED(missileObj) == true)	 continue;
//			if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
//			if (OBJECT_TYPE(missileObj) != 1 && OBJECT_TYPE(missileObj) != 0x8001) continue;
//
//			//------//------:
//			if (timeMisQVelkoz == 0 && !srcPosMisQVelkoz.IsValid() && missileObj->nTeam_ID != myHero->nTeam_ID && CheckName("VelkozQMissile", missileObj->GetNameNpc()))
//			{
//				timeMisQVelkoz = (float)GetTickCount();
//				Vec3D src(missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
//				srcPosMisQVelkoz = src;
//				continue;
//			}
//			
//			//------//------:
//			if (CheckName("Q_SplitImplosion", missileObj->GetNameNpc()) && CheckName("Velkoz", missileObj->GetNameNpc()))	//"Velkoz_Base_Q_SplitImplosion"
//			{
//				if (timeMisQVelkoz > 0 && srcPosMisQVelkoz.IsValid())
//				{
//					std::string mis_Name("VelkozQ2_Special");	// lay ten nay` thi se ko create missile neu da create o pCastSpell roi
//					std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(mis_Name)); // lay luon onProcessSpells cho missile
//					if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//					{
//						SpellData spellData  = it_onProcessSpells->second;
//						spellData.spellDelay = 285;
//						float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + 285 + 1000*spellData.range/spellData.projectileSpeed : 1000;	// cho delay vao cung dc k sao
//						if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//						{
//							
//							Vec3D tmpStart = srcPosMisQVelkoz;
//							Vec3D tmpEnd   = missileObj->currentPos();			//"Velkoz_Base_Q_SplitImplosion"
//							Vec3D dir   = (tmpEnd - tmpStart).Normalized();
//
//							Vec3D endPosition1   = tmpEnd - Perpendicular(dir) * spellData.range;
//							Vec3D endPosition2   = tmpEnd + Perpendicular(dir) * spellData.range;
//
//							if (tmpEnd.Distance2D(myHero->currentPos()) < spellData.range + 1500)
//							{
//
//								it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//								//__oMsg("---((*22*))----- VelkozQ2_Special-CREATE-MISSLE-22222: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), endPosition1.Distance2D(endPosition2));
//								CreateSpellData(enemyHero, tmpEnd, endPosition1, spellData);
//								CreateSpellData(enemyHero, tmpEnd, endPosition2, spellData);
//							}
//						}	
//					}
//				}
//			}
//		}	
//	}
//}

////---------------------------------------------------------------------//--------------------//
//void Evade_Velkoz_W()
//{
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)		  continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Velkoz")) continue;
//
//		DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//		DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//		DWORD dw1 = *(DWORD*)dw0;
//		if (!dw1) return;
//
//		int countAllObj = *(DWORD*)(dw0 + 4);
//		if (!countAllObj) return;
//
//		for (int kk = 0; kk < countAllObj; ++kk)
//		{
//			DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//			if (dw3 == 0) continue;
//			KNpc *missileObj = (KNpc*)dw3;
//
//			if (IS_OBJ_DELETED(missileObj) == true)	 continue;
//			if (missileObj->nIndex < 0x3FFFFCC8)     continue;	
//			if (OBJECT_TYPE(missileObj) != 1) continue;
//
//			//if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
//			//if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;	
//
//			//------//------:
//			if (CheckName("_W_Telegraph", missileObj->GetNameNpc()) && CheckName("Velkoz", missileObj->GetNameNpc()))	
//			{
//				DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
//				DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
//				DWORD dwUnit1 = *(DWORD*)tempUnit;
//				DWORD dwUnit2 = *(DWORD*)tempUnitMax;
//				if (!dwUnit1 || !dwUnit2 ) return;
//				int countUnit = (dwUnit2 - dwUnit1)/4;
//				for (int iii = 0; iii < countUnit; ++iii)
//				{
//					DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
//					if (dwUnit3 == 0) continue;
//					KNpc *enemyEyebeamVision = (KNpc*)dwUnit3;
//					if (IS_OBJ_DELETED(enemyEyebeamVision)) continue;
//					if (IS_DEAD(enemyEyebeamVision))    continue;
//					if (!IS_MINION(enemyEyebeamVision)) continue;
//					if (enemyEyebeamVision->nTeam_ID == myHero->nTeam_ID || enemyEyebeamVision->nTeam_ID == 0x12C)    continue;
//					if (!CheckName(enemyEyebeamVision->GetNameNpc(), "EyebeamVision")) continue;
//					if (!CheckName("TestCube", enemyEyebeamVision->GetNameHero())) continue;
//					
//					std::string mis_Name("VelkozW_Special");	
//					std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(mis_Name)); 
//					if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//					{
//						SpellData spellData  = it_onProcessSpells->second;
//						float missileLifeTime = spellData.projectileSpeed > 0 ?  2222.0f /*888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed*/ : 1000;	
//						if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//						{
//							Vec3D Start = missileObj->currentPos();
//							Vec3D End   = enemyEyebeamVision->currentPos(); 			
//
//							if (Start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//							{
//								it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//								//__oMsg("---((*22*))----- VelkozW-11_Special-CREATE-MISSLE-22222: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), End.Distance2D(Start));
//								CreateSpellData(enemyHero, Start, End, spellData);
//							}
//						}	
//					}
//					
//				}
//			}
//
//
//
//			//if (CheckName("VelkozWMissile", missileObj->GetNameNpc()))	//Velkoz_Base_W_Telegraph_Green
//			//{
//			//	std::string mis_Name("VelkozW_Special");	
//			//	std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(mis_Name)); 
//			//	if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			//	{
//			//		SpellData spellData  = it_onProcessSpells->second;
//			//		float missileLifeTime = spellData.projectileSpeed > 0 ? 555 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;	
//			//		if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//			//		{
//			//			Vec3D Start (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
//			//			Vec3D End   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 			
//			//
//			//			if (Start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//			//			{
//			//				it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//			//				//__oMsg("---((*22*))----- VelkozW-11_Special-CREATE-MISSLE-22222: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), End.Distance2D(Start));
//			//				CreateSpellData(enemyHero, Start, End, spellData);
//			//			}
//			//		}	
//			//	}
//			//}
//
//
//		}	
//
//
//		//std::string mis_Name("VelkozW_Special");	
//		//std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(mis_Name)); 
//		//if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//		//{
//		//	SpellData spellData  = it_onProcessSpells->second;
//		//	float missileLifeTime = spellData.projectileSpeed > 0 ?  2222 /*888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed*/ : 1000;	
//		//	if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//		//	{
//		//		Vec3D Start = missileObj->currentPos();
//		//		Vec3D End   = enemyEyebeamVision->currentPos(); 			
//
//		//		if (Start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//		//		{
//		//			it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//		//			__oMsg("---((*22*))----- VelkozW-11_Special-CREATE-MISSLE-22222: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), End.Distance2D(Start));
//		//			CreateSpellData(enemyHero, Start, End, spellData);
//		//		}
//		//	}	
//		//}
//
//
//	}
//}
//
////---------------------------------------------------------------------//--------------------//
//void Evade_Velkoz_E()
//{
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)		continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Velkoz")) continue;
//
//		if (IsCanSee(enemyHero))
//		{
//			if (Distance(enemyHero, myHero) > 2200)	  continue;
//
//			KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//			if (!args) continue;
//
//			KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//			if(!pK_str2) continue;
//
//			std::string spell_name(pK_str2->GetSkillName());
//			if (spell_name.compare("VelkozE") != 0) continue;		//pCastSpell xuat hien xxx s
//
//			if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//	
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spell_name)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData  = it_onProcessSpells->second;
//				float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;	
//				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//				{			
//					Vec3D Start(args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
//					Vec3D End(args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
//
//					if (Start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//					{
//						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//						//__oMsg("---((*22*))----- VelkozE-11_Special-CREATE-MISSLE-22222: MissileNam: %s, KC_Missile = %.3f",spell_name.c_str(), End.Distance2D(Start));
//						CreateSpellData(enemyHero, Start, End, spellData);
//					}
//				}	
//			}
//		}
//		else
//		{
//			if (DodgeFOWSpells_menu == false) return;
//
//			DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//			DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//			DWORD dw1 = *(DWORD*)dw0;
//			if (!dw1) return;
//
//			int countAllObj = *(DWORD*)(dw0 + 4);
//			if (!countAllObj) return;
//
//			for (int kk = 0; kk < countAllObj; ++kk)
//			{
//				DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//				if (dw3 == 0) continue;
//				KNpc *missileObj = (KNpc*)dw3;
//
//				if (IS_OBJ_DELETED(missileObj) == true)	 continue;
//				if (missileObj->nIndex < 0x3FFFFCC8)     continue;	
//				if (OBJECT_TYPE(missileObj) != 1) continue;
//
//				//if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
//				//if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;	
//
//				//------//------:
//				if (CheckName("_E_AOE_", missileObj->GetNameNpc()) && CheckName("Velkoz", missileObj->GetNameNpc()))	
//				{
//					std::string mis_Name("VelkozE");	
//					std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(mis_Name)); 
//					if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//					{
//						SpellData spellData  = it_onProcessSpells->second;
//						spellData.waitExtra  = 0;
//						float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;	
//						if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//						{
//							Vec3D End   = missileObj->currentPos(); 
//							Vec3D Start = Extend(End, myHero->currentPos(), - spellData.range);
//
//							if (Start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//							{
//								it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//								//__oMsg("---((*22*))----- VelkozEE-2222_Special-CREATE-MISSLE-22222: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), End.Distance2D(Start));
//								CreateSpellData(enemyHero, Start, End, spellData);
//							}
//						}	
//					}
//				}
//			}	
//		}
//	}
//}

////---------------------------------------------------------------------//--------------------//
//float timeQLineMis = 0;
//Vec3D posQLineMis(0,0,0);
//void Evade_Graves_Q2()
//{
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)	  continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Graves")) continue;
//
//		//------//------//------:
//		if (IsCanSee(enemyHero))
//		{
//			if (Distance(enemyHero, myHero) > 2200)			  continue;
//
//			KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//			if (!args) continue;
//			
//			KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//			if(!pK_str2) continue;
//
//			std::string spell_name(pK_str2->GetSkillName());
//			if (spell_name.compare("GravesQLineSpell") != 0) continue;		//pCastSpell xuat hien xxx s
//			
//			//__oMsg("--TIME-GAME: %f", GetTimeGame());
//
//			if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//
//			//------//------Q2------:
//			std::string Q1Name("GravesQ2_Special");
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Q1Name)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				Vec3D StartPos(args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
//				Vec3D EndPos(args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
//				
//				float missileLifeTime = it_onProcessSpells->second.projectileSpeed > 0 ? /*1270*/ 1500 + 250 + 1000*it_onProcessSpells->second.range/it_onProcessSpells->second.projectileSpeed : 1000;
//
//				if ((float)GetTickCount() - it_onProcessSpells->second.lastCreateMissileTime > missileLifeTime)
//				{
//					it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//					
//					SpellData spellData_1 = it_onProcessSpells->second;
//					SpellData spellData_2 = it_onProcessSpells->second;
//
//					Vec3D start = StartPos;
//					Vec3D end   = EndPos;
//
//					if (StartPos.Distance2D(myHero->currentPos()) < 1000 + 1500)
//					{
//						end = StartPos + (EndPos - StartPos).Normalized() * it_onProcessSpells->second.range;
//						
//						float xFuck = 250;
//						if (args->nTime_DanBatDauBay < args->nTime_BatDauBAN)
//						{
//							xFuck = 0;		//deo hieu sao ban trong FOW van co pCast, va timeBay < timeBan
//							//__oMsg("--xFuck BANG BANG 0000-000"); 
//						}
//
//						spellData_1.spellDelay      = 1000 + xFuck  - 50 + 1000*Distance(end, start)/3000;
//						spellData_2.spellDelay      = spellData_1.spellDelay;
//
//						Vec3D w = GetNearWallPoint(start, end);
//						if (w.IsValid())
//						{
//							end = w;
//							spellData_1.spellDelay = 200 + xFuck + 1000*Distance(end, start)/3000;	//3000 la speed cua Q1, 625 la time no? khi va vao` wall, xFuck la delay cua Q1(deo hieu sao 625-650 lai chuan the)
//							spellData_2.spellDelay = spellData_1.spellDelay + 250;
//							//__oMsg("--DIS_VV_VVVV: %f", Distance(end, start));
//						}
//
//						//---- Line-1:(vuongGoc)
//						spellData_1.isPerpendicular = true;
//						spellData_1.secondaryRadius = 265;
//						spellData_1.updatePosition  = false;
//						spellData_1.projectileSpeed = 20000;
//						spellData_1.waitExtra       = 0;
//						
//						
//						//__oMsg("---((*111_11*))----- Graves_Q2_LineSpell_CREATE-MISSLE-1.1: KC_x = %.3f - delay: %f, MissileNam: %s", start.Distance2D(end), spellData_1.spellDelay, spell_name.c_str());
//						CreateSpellData(enemyHero, enemyHero->currentPos(), end, spellData_1, 0, 0, true, None, true, 170);
//
//						//---- Line-2:(Bay Nguoc Ve)
//						//__oMsg("---((*111_22*))----- Graves_Q2_LineSpell_CREATE-MISSLE-1.2: KC_x = %.3f - delay: %f, MissileNam: %s", start.Distance2D(end), spellData_2.spellDelay, spell_name.c_str());
//						//spellData_2.waitExtra = 200;
//						spellData_2.range     = Distance(end, start) - 20;
//						CreateSpellData(enemyHero, end, start, spellData_2);
//					}
//				}
//			}
//		}
//		else
//		{
//			//	//if (DodgeFOWSpells_menu == false) return;
//			//	if (timeQLineMis > 0 && (float)GetTickCount() - timeQLineMis > 500)
//			//	{
//			//		Vec3D zero(0,0,0);
//			//		timeQLineMis = 0;
//			//		posQLineMis = zero;
//			//	}
//			//	
//			//	//------//------:
//			//	DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//			//	DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//			//	DWORD dw1 = *(DWORD*)dw0;
//			//	if (!dw1) return;
//
//			//	int countAllObj = *(DWORD*)(dw0 + 4);
//			//	if (!countAllObj) return;
//
//			//	for (int kk = 0; kk < countAllObj; ++kk)
//			//	{
//			//		DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//			//		if (dw3 == 0) continue;
//			//		KNpc *missileObj = (KNpc*)dw3;
//
//			//		if (IS_OBJ_DELETED(missileObj) == true)	 continue;
//			//		if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
//			//		if (OBJECT_TYPE(missileObj) != 1 && OBJECT_TYPE(missileObj) != 0x8001)		 continue;
//
//			//		if (timeQLineMis == 0 && !posQLineMis.IsValid() && CheckName("GravesQLineMis", missileObj->GetNameNpc()))
//			//		{
//			//			timeQLineMis = (float)GetTickCount();
//			//			posQLineMis  = missileObj->currentPos();
//			//			continue;
//			//		}
//			//		
//			//		//------ no-Wall --:
//			//		if (CheckName("Q_Bomb", missileObj->GetNameNpc()) && CheckName("Graves", missileObj->GetNameNpc()) && false == CheckName("Q_Bomb_Wall", missileObj->GetNameNpc()))
//			//		{
//			//			if (posQLineMis.IsValid())
//			//			{
//			//				std::string Q1Name("GravesQ2_Special");
//			//				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Q1Name)); 
//			//				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			//				{
//			//					Vec3D StartPos = enemyHero->currentPos();
//			//					Vec3D EndPos   = missileObj->currentPos();	//Graves_Base_Q_Bomb pos
//
//			//					float missileLifeTime = it_onProcessSpells->second.projectileSpeed > 0 ?  1666 + 1000*it_onProcessSpells->second.range/it_onProcessSpells->second.projectileSpeed : 1000;
//
//			//					if ((float)GetTickCount() - it_onProcessSpells->second.lastCreateMissileTime > missileLifeTime)
//			//					{
//			//						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//			//						SpellData spellData_1 = it_onProcessSpells->second;
//			//						SpellData spellData_2 = it_onProcessSpells->second;
//
//			//						spellData_1.spellDelay      = 900;
//			//						spellData_2.spellDelay      = spellData_1.spellDelay;
//
//			//						//---- Line-1:(vuongGoc)
//			//						spellData_1.isPerpendicular = true;
//			//						spellData_1.secondaryRadius = 255;
//			//						spellData_1.updatePosition  = false;
//			//						spellData_1.projectileSpeed = 20000;
//			//						spellData_1.waitExtra		= 0;
//
//
//			//						__oMsg("---((*111_11*))----- Graves_Q2_LineSpell_CREATE-MISSLE-1.1: KC_x = %.3f - delay: %f, MissileNam: %s", StartPos.Distance2D(EndPos), spellData_1.spellDelay, Q1Name.c_str());
//			//						CreateSpellData(enemyHero, enemyHero->currentPos(), EndPos, spellData_1, 0, 0, true, None, true, 170);
//
//			//						//---- Line-2:(Bay Nguoc Ve)
//			//						__oMsg("---((*111_22*))----- Graves_Q2_LineSpell_CREATE-MISSLE-1.2: KC_x = %.3f - delay: %f, MissileNam: %s", StartPos.Distance2D(EndPos), spellData_2.spellDelay, Q1Name.c_str());
//			//						CreateSpellData(enemyHero, EndPos, StartPos, spellData_2);
//			//					}	
//			//				}
//			//			}
//			//		}
//
//			//		//------ Wall --:
//			//		if (CheckName("Q_Bomb_Wall", missileObj->GetNameNpc()) && CheckName("Graves", missileObj->GetNameNpc()))
//			//		{
//			//			if (posQLineMis.IsValid())
//			//			{
//			//				std::string Q1Name("GravesQ2_Special");
//			//				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Q1Name)); 
//			//				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			//				{
//			//					Vec3D StartPos = enemyHero->currentPos();
//			//					Vec3D EndPos   = missileObj->currentPos();	//Graves_Base_Q_Bomb_Wall pos
//
//			//					float missileLifeTime = it_onProcessSpells->second.projectileSpeed > 0 ?  1666 + 1000*it_onProcessSpells->second.range/it_onProcessSpells->second.projectileSpeed : 1000;
//
//			//					if ((float)GetTickCount() - it_onProcessSpells->second.lastCreateMissileTime > missileLifeTime)
//			//					{
//			//						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//			//						SpellData spellData_1 = it_onProcessSpells->second;
//			//						SpellData spellData_2 = it_onProcessSpells->second;
//
//			//						spellData_1.spellDelay      = 200;
//			//						spellData_2.spellDelay      = spellData_1.spellDelay;
//
//			//						//---- Line-1:(vuongGoc)
//			//						spellData_1.isPerpendicular = true;
//			//						spellData_1.secondaryRadius = 255;
//			//						spellData_1.updatePosition  = false;
//			//						spellData_1.projectileSpeed = 20000;
//			//						spellData_1.waitExtra		= 0;
//
//
//			//						__oMsg("---((*111_11*))----- Graves_Q2_LineSpell_CREATE-MISSLE-1.1: KC_x = %.3f - delay: %f, MissileNam: %s", StartPos.Distance2D(EndPos), spellData_1.spellDelay, Q1Name.c_str());
//			//						CreateSpellData(enemyHero, enemyHero->currentPos(), EndPos, spellData_1, 0, 0, true, None, true, 170);
//
//			//						//---- Line-2:(Bay Nguoc Ve)
//			//						__oMsg("---((*111_22*))----- Graves_Q2_LineSpell_CREATE-MISSLE-1.2: KC_x = %.3f - delay: %f, MissileNam: %s", StartPos.Distance2D(EndPos), spellData_2.spellDelay, Q1Name.c_str());
//			//						CreateSpellData(enemyHero, EndPos, StartPos, spellData_2);
//			//					}	
//			//				}
//			//			}
//			//		}
//			//	}	
//		}
//	}
//}

//---------------------------------------------------------------------//--------------------//
void Evade_Graves_R2()	//Hinh non co gi do sai sai
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
	//	if (enemyHero->nTeam_ID == myHero->nTeam_ID)	  continue;
	//	if (!CheckName(enemyHero->GetNameHero(), "Graves")) continue;

	//	//------//------//------:
	//	if (IsCanSee(enemyHero))
	//	{
	//		if (Distance(enemyHero, myHero) > 3500)	continue;

	//		KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
	//		if (!args) continue;

	//		KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
	//		if(!pK_str2) continue;

	//		std::string spell_name(pK_str2->GetSkillName());
	//		if (spell_name.compare("GravesChargeShot") != 0) continue;		//pCastSpell xuat hien xxx s

	//		if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;

	//		//------//------Q2------:
	//		std::string Q1Name("GravesR2_Special");
	//		std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Q1Name)); 
	//		if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
	//		{
	//			Vec3D StartPos(args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
	//			Vec3D EndPos(args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);

	//			float missileLifeTime = it_onProcessSpells->second.projectileSpeed > 0 ? 888 + 1000*it_onProcessSpells->second.range/it_onProcessSpells->second.projectileSpeed : 1000;

	//			if ((float)GetTickCount() - it_onProcessSpells->second.lastCreateMissileTime > missileLifeTime)
	//			{
	//				it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();

	//				SpellData spellData = it_onProcessSpells->second;

	//				Vec3D start = StartPos;
	//				Vec3D end   = EndPos;
	//				end = StartPos + (EndPos - StartPos).Normalized() * 1000;

	//				Vec3D end2 = StartPos + (EndPos - StartPos).Normalized() * 1750;

	//				spellData.spellDelay = spellData.spellDelay + + 500 + 1000*Distance(end, start)/1800;
	//				if (1)
	//				{
	//					//----------
	//				}
	//				
	//				__oMsg("---((*111_11*))----- Graves_Q2_LineSpell_CREATE-MISSLE-1.1: KC_x = %.3f - delay: %f, MissileNam: %s", start.Distance2D(end), spellData.spellDelay, spell_name.c_str());
	//				CreateSpellData(enemyHero, end, end2, spellData);
	//			}	
	//		}
	//	}
	//	else
	//	{
	//		//	//if (DodgeFOWSpells_menu == false) return;
	//		//	if (timeQLineMis > 0 && (float)GetTickCount() - timeQLineMis > 500)
	//		//	{
	//		//		Vec3D zero(0,0,0);
	//		//		timeQLineMis = 0;
	//		//		posQLineMis = zero;
	//		//	}
	//		//	
	//		//	//------//------:
	//		//	DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
	//		//	DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
	//		//	DWORD dw1 = *(DWORD*)dw0;
	//		//	if (!dw1) return;

	//		//	int countAllObj = *(DWORD*)(dw0 + 4);
	//		//	if (!countAllObj) return;

	//		//	for (int kk = 0; kk < countAllObj; ++kk)
	//		//	{
	//		//		DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
	//		//		if (dw3 == 0) continue;
	//		//		KNpc *missileObj = (KNpc*)dw3;

	//		//		if (IS_OBJ_DELETED(missileObj) == true)	 continue;
	//		//		if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
	//		//		if (OBJECT_TYPE(missileObj) != 1 && OBJECT_TYPE(missileObj) != 0x8001)		 continue;

	//		//		if (timeQLineMis == 0 && !posQLineMis.IsValid() && CheckName("GravesQLineMis", missileObj->GetNameNpc()))
	//		//		{
	//		//			timeQLineMis = (float)GetTickCount();
	//		//			posQLineMis  = missileObj->currentPos();
	//		//			continue;
	//		//		}
	//		//		
	//		//		//------ no-Wall --:
	//		//		if (CheckName("Q_Bomb", missileObj->GetNameNpc()) && CheckName("Graves", missileObj->GetNameNpc()) && false == CheckName("Q_Bomb_Wall", missileObj->GetNameNpc()))
	//		//		{
	//		//			if (posQLineMis.IsValid())
	//		//			{
	//		//				std::string Q1Name("GravesQ2_Special");
	//		//				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Q1Name)); 
	//		//				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
	//		//				{
	//		//					Vec3D StartPos = enemyHero->currentPos();
	//		//					Vec3D EndPos   = missileObj->currentPos();	//Graves_Base_Q_Bomb pos

	//		//					float missileLifeTime = it_onProcessSpells->second.projectileSpeed > 0 ?  1666 + 1000*it_onProcessSpells->second.range/it_onProcessSpells->second.projectileSpeed : 1000;

	//		//					if ((float)GetTickCount() - it_onProcessSpells->second.lastCreateMissileTime > missileLifeTime)
	//		//					{
	//		//						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();

	//		//						SpellData spellData_1 = it_onProcessSpells->second;
	//		//						SpellData spellData_2 = it_onProcessSpells->second;

	//		//						spellData_1.spellDelay      = 900;
	//		//						spellData_2.spellDelay      = spellData_1.spellDelay;

	//		//						//---- Line-1:(vuongGoc)
	//		//						spellData_1.isPerpendicular = true;
	//		//						spellData_1.secondaryRadius = 255;
	//		//						spellData_1.updatePosition  = false;
	//		//						spellData_1.projectileSpeed = 20000;
	//		//						spellData_1.waitExtra		= 0;


	//		//						__oMsg("---((*111_11*))----- Graves_Q2_LineSpell_CREATE-MISSLE-1.1: KC_x = %.3f - delay: %f, MissileNam: %s", StartPos.Distance2D(EndPos), spellData_1.spellDelay, Q1Name.c_str());
	//		//						CreateSpellData(enemyHero, enemyHero->currentPos(), EndPos, spellData_1, 0, 0, true, None, true, 170);

	//		//						//---- Line-2:(Bay Nguoc Ve)
	//		//						__oMsg("---((*111_22*))----- Graves_Q2_LineSpell_CREATE-MISSLE-1.2: KC_x = %.3f - delay: %f, MissileNam: %s", StartPos.Distance2D(EndPos), spellData_2.spellDelay, Q1Name.c_str());
	//		//						CreateSpellData(enemyHero, EndPos, StartPos, spellData_2);
	//		//					}	
	//		//				}
	//		//			}
	//		//		}

	//		//		//------ Wall --:
	//		//		if (CheckName("Q_Bomb_Wall", missileObj->GetNameNpc()) && CheckName("Graves", missileObj->GetNameNpc()))
	//		//		{
	//		//			if (posQLineMis.IsValid())
	//		//			{
	//		//				std::string Q1Name("GravesQ2_Special");
	//		//				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Q1Name)); 
	//		//				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
	//		//				{
	//		//					Vec3D StartPos = enemyHero->currentPos();
	//		//					Vec3D EndPos   = missileObj->currentPos();	//Graves_Base_Q_Bomb_Wall pos

	//		//					float missileLifeTime = it_onProcessSpells->second.projectileSpeed > 0 ?  1666 + 1000*it_onProcessSpells->second.range/it_onProcessSpells->second.projectileSpeed : 1000;

	//		//					if ((float)GetTickCount() - it_onProcessSpells->second.lastCreateMissileTime > missileLifeTime)
	//		//					{
	//		//						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();

	//		//						SpellData spellData_1 = it_onProcessSpells->second;
	//		//						SpellData spellData_2 = it_onProcessSpells->second;

	//		//						spellData_1.spellDelay      = 200;
	//		//						spellData_2.spellDelay      = spellData_1.spellDelay;

	//		//						//---- Line-1:(vuongGoc)
	//		//						spellData_1.isPerpendicular = true;
	//		//						spellData_1.secondaryRadius = 255;
	//		//						spellData_1.updatePosition  = false;
	//		//						spellData_1.projectileSpeed = 20000;
	//		//						spellData_1.waitExtra		= 0;


	//		//						__oMsg("---((*111_11*))----- Graves_Q2_LineSpell_CREATE-MISSLE-1.1: KC_x = %.3f - delay: %f, MissileNam: %s", StartPos.Distance2D(EndPos), spellData_1.spellDelay, Q1Name.c_str());
	//		//						CreateSpellData(enemyHero, enemyHero->currentPos(), EndPos, spellData_1, 0, 0, true, None, true, 170);

	//		//						//---- Line-2:(Bay Nguoc Ve)
	//		//						__oMsg("---((*111_22*))----- Graves_Q2_LineSpell_CREATE-MISSLE-1.2: KC_x = %.3f - delay: %f, MissileNam: %s", StartPos.Distance2D(EndPos), spellData_2.spellDelay, Q1Name.c_str());
	//		//						CreateSpellData(enemyHero, EndPos, StartPos, spellData_2);
	//		//					}	
	//		//				}
	//		//			}
	//		//		}
	//		//	}	
	//	}
	//}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Graves_Q2_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)
{	
	////////if (spellData.spellName.compare("GravesQLineSpell") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	////////Vec3D StartPos(spellCast->SourcePos.x, spellCast->SourcePos.y, spellCast->SourcePos.z);
	////////Vec3D EndPos(spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
	////////
	////////SpellData spellData_1 = spellData;
	////////SpellData spellData_2 = spellData;

	////////Vec3D start = StartPos;
	////////Vec3D end   = EndPos;

	////////if (StartPos.Distance2D(myHero->currentPos()) < 1000 + 1500)
	////////{
	////////	CreateSpellData(hero, StartPos, EndPos, spellData, 0, 0);	//Q1-Ghe

	////////	for (std::map<int, Spell>::iterator it_2 = _SpellDetector->detectedSpells->begin(); it_2!= _SpellDetector->detectedSpells->end(); ++it_2)
	////////	{
	////////		it_2->second.KoUpCurrentPos = true;
	////////	}
	////////	
	////////	//------------//-------------

	////////	end = StartPos + (EndPos - StartPos).Normalized() * spellData.range;

	////////	float xFuck = 250;
	////////	//if (args->nTime_DanBatDauBay < args->nTime_BatDauBAN)
	////////	//{
	////////	//	xFuck = 0;		//deo hieu sao ban trong FOW van co pCast, va timeBay < timeBan
	////////	//	//__oMsg("--xFuck BANG BANG 0000-000"); 
	////////	//}

	////////	spellData_1.spellDelay      = 1000 + xFuck  - 50 + 1000*Distance(end, start)/3000;
	////////	spellData_2.spellDelay      = spellData_1.spellDelay;

	////////	Vec3D w = GetNearWallPoint(start, end);
	////////	if (w.IsValid())
	////////	{
	////////		end = w;
	////////		spellData_1.spellDelay = 200 + xFuck + 1000*Distance(end, start)/3000;	//3000 la speed cua Q1, 625 la time no? khi va vao` wall, xFuck la delay cua Q1(deo hieu sao 625-650 lai chuan the)
	////////		spellData_2.spellDelay = spellData_1.spellDelay + 250;
	////////		//__oMsg("--DIS_VV_VVVV: %f", Distance(end, start));
	////////	}

	////////	//---- Line-1:(vuongGoc)
	////////	spellData_1.isPerpendicular = true;
	////////	spellData_1.secondaryRadius = 265;
	////////	spellData_1.updatePosition  = false;
	////////	spellData_1.projectileSpeed = 20000;
	////////	spellData_1.waitExtra       = 0;


	////////			//__oMsg("---((*111_11*))----- Graves_Q2_LineSpell_CREATE-MISSLE-1.1: KC_x = %.3f - delay: %f, MissileNam: %s", start.Distance2D(end), spellData_1.spellDelay, spellData.spellName.c_str());
	////////	CreateSpellData(hero, hero->currentPos(), end, spellData_1, 0, 0, true, None, true, 170);

	////////	//---- Line-2:(Bay Nguoc Ve)
	////////			//__oMsg("---((*111_22*))----- Graves_Q2_LineSpell_CREATE-MISSLE-1.2: KC_x = %.3f - delay: %f, MissileNam: %s", start.Distance2D(end), spellData_2.spellDelay, spellData.spellName.c_str());
	////////	//spellData_2.waitExtra = 200;
	////////	spellData_2.range     = Distance(end, start) - 20;
	////////	spellData_2.projectileSpeed = 1600;
	////////	CreateSpellData(hero, end, start, spellData_2, 0, 0, true, None, true, 85);
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Malzahar_Q_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)
{
	////////if (spellData.spellName.compare("MalzaharQ") != 0) return;
	////////
	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	////////Vec3D StartPos(spellCast->SourcePos.x, spellCast->SourcePos.y, spellCast->SourcePos.z);
	////////Vec3D EndPos(spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

	////////Vec3D direction  = (EndPos - StartPos).Normalized();
	////////Vec3D pDirection = Perpendicular(direction);
	////////Vec3D targetPoint = EndPos;
	////////
	////////Vec3D pos1 = targetPoint - pDirection * spellData.sideRadius;
	////////Vec3D pos2 = targetPoint + pDirection * spellData.sideRadius;

	////////if (pos1.Distance2D(myHero->currentPos()) < spellData.sideRadius + 1000 || pos2.Distance2D(myHero->currentPos()) < spellData.sideRadius + 1000)
	////////{
	////////	//__oMsg("---((*11*))----- MalzaharQ-CREATE-OPS-11111: O-P-S: %s, KC_Missile = %.3f - delay: %f",spellData.spellName.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);

	////////	CreateSpellData(hero, pos1, pos2, spellData, 0, 0, false);
	////////	CreateSpellData(hero, pos2, pos1, spellData, 0, 0);

	////////	for (std::map<int, Spell>::iterator it_2 = _SpellDetector->detectedSpells->begin(); it_2!= _SpellDetector->detectedSpells->end(); ++it_2)
	////////	{
	////////		it_2->second.KoUpCurrentPos = true;
	////////	}
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Velkoz_Q_1_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)
{
	////////if (spellData.spellName.compare("VelkozQ") != 0) return;
	////////
	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	////////if (!IsCanSee(hero)) return;
	////////if (Distance(hero, myHero) > 2500) return;

	//////////------//------//------:
	////////Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
	////////Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

	//////////__oMsg("---((***))----- Velkoz-Q1_OPC-OnProcesSpell-11111: KC_Missile = %.3f, range: %f", StartPos.Distance2D(EndPos), spellData.range);
	////////CreateSpellData(hero, StartPos, EndPos, spellData);
	////////for (std::map<int, Spell>::iterator it_2 = _SpellDetector->detectedSpells->begin(); it_2!= _SpellDetector->detectedSpells->end(); ++it_2)
	////////{
	////////	it_2->second.KoUpCurrentPos = true;
	////////}
}

//////////---------------------------------------------------------------------//--------------------//
////////float timeMissileQ1Velkoz = 0;
////////Vec3D srcPosQ1Velkoz(0,0,0);
////////Vec3D desPosQ1Velkoz(0,0,0);
void Evade_Velkoz_Q_1_OCM(KNpc* missileObj, SpellData &spellData)
{
	////////if (DodgeFOWSpells_menu == false) return;

	////////if (spellData.missileName.compare("VelkozQMissile") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;
	////////if (G_Module == 0) return;

	//////////------//------//------:
	////////KNpc* hero = (KNpc*)GetObjectByID(missileObj->nMissileOwnerID_1);
	////////if (hero)
	////////{
	////////	Vec3D start (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
	////////	Vec3D end   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 
	////////	
	////////	if (!srcPosQ1Velkoz.IsValid() && !desPosQ1Velkoz.IsValid())
	////////	{
	////////		timeMissileQ1Velkoz = (float)GetTickCount();
	////////		srcPosQ1Velkoz      = start;
	////////		desPosQ1Velkoz      = end;
	////////	}
	////////	else
	////////	{
	////////		if ((float)GetTickCount() - timeMissileQ1Velkoz > 1250)		//tam thoi reset o day dc, vi hien tai goi lien tuc neu co missileQ1
	////////		{
	////////			timeMissileQ1Velkoz = (float)GetTickCount();
	////////			Vec3D zezo(0,0,0);
	////////			srcPosQ1Velkoz      = zezo;
	////////			desPosQ1Velkoz      = zezo;
	////////		}
	////////	}

	////////	if (start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	////////	{
	////////		//--------------------------------:
	////////		std::string mis_Name(missileObj->GetNameNpc());
	////////		bool objectAssigned = false;

	////////		for (std::map<int, Spell>::iterator it_1 = _SpellDetector->detectedSpells->begin(); it_1!= _SpellDetector->detectedSpells->end(); ++it_1)
	////////		{
	////////			Spell spell = it_1->second;
	////////			Vec3D dir   = (end - start).Normalized();
	////////			
	////////			if(str_tolower(spell.info.missileName).compare(str_tolower(mis_Name)) == 0)			// todo: fix urf spells
	////////			{
	////////				if (spell.heroID == hero->nIndex && AngleBetween(dir, spell.direction) < 10)
	////////				{
	////////					it_1->second.spellObject = missileObj;
	////////					
	////////					spellData.lastCreateMissileTime = (float)GetTickCount();
	////////					objectAssigned = true;
	////////					//__oMsg("	  ---------(velkoz-Q1)SpellMissile.OnCreate -- MISSILE-DA~GA'N-ROI: KC_Missile = %.3f", start.Distance2D(end));
	////////					break;
	////////				}
	////////			}
	////////		}
	////////		
	////////		if(spellData.projectileSpeed == 0) return;
	////////		float missileLifeTime = 690 + 69 + 1000*spellData.range/spellData.projectileSpeed;

	////////		if (objectAssigned == false && (float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////		{
	////////			//__oMsg("---((*11.1: %.3f))----- Velkoz_Q1_CREATE-MISSLE-11111: %s KC_Missile = %.3f (%.3f) - delay: %f", GetTimeGame(), mis_Name.c_str(), start.Distance2D(end), Distance(myHero, hero),spellData.spellDelay);
	////////			CreateSpellData(hero, start, end, spellData, missileObj);

	////////			spellData.lastCreateMissileTime = (float)GetTickCount();
	////////		}
	////////	}
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Velkoz_Q_2_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)
{
	////////if (spellData.spellName.compare("VelkozQSplitActivate") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;
	////////if (G_Module == 0) return;

	////////if (!IsCanSee(hero)) return;
	////////if (Distance(hero, myHero) > 2500) return;

	//////////------//------//------:
	////////if (srcPosQ1Velkoz.IsValid() && desPosQ1Velkoz.IsValid())
	////////{
	////////	Vec3D tmpStart = srcPosQ1Velkoz;
	////////	float dist     = 1300.0f * ((float)GetTickCount() - timeMissileQ1Velkoz)/1000;
	////////	Vec3D tmpEnd   = Extend(tmpStart, desPosQ1Velkoz, 85 + dist );	

	////////	Vec3D dir   = (tmpEnd - tmpStart).Normalized();
	////////	Vec3D endPosition1   = tmpEnd - Perpendicular(dir) * spellData.range;
	////////	Vec3D endPosition2   = tmpEnd + Perpendicular(dir) * spellData.range;

	////////	Vec3D StartPos = tmpEnd;

	////////	//__oMsg("---((***))----- Velkoz-Q22_OPC-OnProcesSpell-11111: KC_Missile = %.3f, range: %f", StartPos.Distance2D(tmpEnd), spellData.range);
	////////	CreateSpellData(hero, StartPos, endPosition1, spellData);
	////////	CreateSpellData(hero, StartPos, endPosition2, spellData);
	////////	for (std::map<int, Spell>::iterator it_2 = _SpellDetector->detectedSpells->begin(); it_2!= _SpellDetector->detectedSpells->end(); ++it_2)
	////////	{
	////////		it_2->second.KoUpCurrentPos = true;
	////////	}
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Velkoz_Q_2_OCM(KNpc* missileObj, SpellData &spellData)
{
	////////if (DodgeFOWSpells_menu == false) return;

	////////if (spellData.missileName.compare("VelkozQMissileSplit") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	//////////------//------//------:
	////////KNpc* hero = (KNpc*)GetObjectByID(missileObj->nMissileOwnerID_1);
	////////if (hero)
	////////{
	////////	Vec3D start (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
	////////	Vec3D end   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 

	////////	if (start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	////////	{
	////////		//--------------------------------:
	////////		std::string mis_Name(missileObj->GetNameNpc());
	////////		bool objectAssigned = false;

	////////		for (std::map<int, Spell>::iterator it_1 = _SpellDetector->detectedSpells->begin(); it_1!= _SpellDetector->detectedSpells->end(); ++it_1)
	////////		{
	////////			Spell spell = it_1->second;
	////////			Vec3D dir   = (end - start).Normalized();

	////////			if(str_tolower(spell.info.missileName).compare(str_tolower(mis_Name)) == 0)			// todo: fix urf spells
	////////			{
	////////				if (spell.heroID == hero->nIndex && AngleBetween(dir, spell.direction) < 10)
	////////				{
	////////					it_1->second.spellObject = missileObj;

	////////					spellData.lastCreateMissileTime = (float)GetTickCount();
	////////					objectAssigned = true;
	////////					//__oMsg("	  ---------(velkoz-Q2)SpellMissile.OnCreate -- MISSILE-DA~GA'N-ROI: KC_Missile = %.3f", start.Distance2D(end));
	////////					break;
	////////				}
	////////			}
	////////		}

	////////		if(spellData.projectileSpeed == 0) return;
	////////		float missileLifeTime = 690 + 69 + 1000*spellData.range/spellData.projectileSpeed;

	////////		if (objectAssigned == false && (float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////		{
	////////			//__oMsg("---((*11.1: %.3f))----- Velkoz_Q2_CREATE-MISSLE-11111: %s KC_Missile = %.3f (%.3f) - delay: %f", GetTimeGame(), mis_Name.c_str(), start.Distance2D(end), Distance(myHero, hero),spellData.spellDelay);
	////////			
	////////			spellData.spellDelay = 0;

	////////			Vec3D end2 = Extend(start, end, -spellData.range);
	////////			
	////////			CreateSpellData(hero, start, end, spellData, 0);
	////////			CreateSpellData(hero, start, end2, spellData, 0);

	////////			spellData.lastCreateMissileTime = (float)GetTickCount();
	////////		}
	////////	}
	////////}
}