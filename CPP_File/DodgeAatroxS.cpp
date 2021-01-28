//#include "DodgeAatroxS.h"
//#include "SpellSpecial.h"
//#include "SpellDetector.h"
//
//
//extern SpellDetector* _SpellDetector;
////---------------------------------------------------------------------//--------------------//
////---------------------------------------------------------------------//--------------------//
//void Evade_Aatrox_Q()
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
//		if (!CheckName(enemyHero->GetNameHero(), "Aatrox")) continue;
//		if (Distance(enemyHero, myHero) > 2000)				continue;
//
//		KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//		if (!args) continue;
//		KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//		if(!pK_str2) continue;
//
//		std::string spell_name(pK_str2->GetSkillName());
//		if (spell_name.compare("AatroxQWrapperCast") != 0) continue;
//		
//		//------//------//------:
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
//			if (OBJECT_TYPE(missileObj) != 1)		 continue;
//
//			if (CheckName("_Q_Indicator_01",missileObj->GetNameNpc()) && CheckName("Aatrox",missileObj->GetNameNpc()))	//Q-1
//			{
//				
//				std::string mis_Name("AatroxQ1_Special");
//
//				std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//				if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//				{
//					//__oMsg("--Aatrox_Q1-222: %f ", GetTimeGame());
//					SpellData spellData = it_onMissileSpells->second;
//
//					Vec3D StartPos = enemyHero->currentPos();
//					//Vec3D EndPos   = Extend(StartPos, enemyHero->currentPos(), 700);
//					Vec3D EndPos   = Extend(enemyHero->currentPos(), GET_REAL_FACING_POS(enemyHero), spellData.range);
//
//					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//					{
//						if(it_onMissileSpells->second.projectileSpeed == 0) continue;
//						float missileLifeTime = 555 + it_onMissileSpells->second.spellDelay + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed;
//
//						if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//						{
//							//__oMsg("---((***))----- Aatrox_Q1-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//							it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//						}
//					}
//				}
//			}
//			else if (CheckName("_Q_Indicator_02",missileObj->GetNameNpc()) && CheckName("Aatrox",missileObj->GetNameNpc()))	//Q-2
//			{
//				std::string mis_Name("AatroxQ2_Special");
//
//				std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//				if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//				{
//					//__oMsg("--Aatrox_Q2-222: %f ", GetTimeGame());
//					SpellData spellData = it_onMissileSpells->second;
//
//					Vec3D StartPos = enemyHero->currentPos();
//					//Vec3D EndPos   = Extend(StartPos, enemyHero->currentPos(), 700);
//					Vec3D EndPos   = Extend(enemyHero->currentPos(), GET_REAL_FACING_POS(enemyHero), spellData.range);
//
//					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//					{
//						if(it_onMissileSpells->second.projectileSpeed == 0) continue;
//						float missileLifeTime = 555 + it_onMissileSpells->second.spellDelay + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed;
//
//						if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//						{
//							//__oMsg("---((***))----- Aatrox_Q2-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//							it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//						}
//					}
//				}
//			}
//			else if (CheckName("_Q_Indicator_03",missileObj->GetNameNpc()) && CheckName("Aatrox",missileObj->GetNameNpc()))	//Q-3
//			{
//				std::string mis_Name("AatroxQ3_Special");
//
//				std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//				if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//				{
//					//__oMsg("--Aatrox_Q3-222: %f ", GetTimeGame());
//					SpellData spellData = it_onMissileSpells->second;
//
//					Vec3D StartPos = enemyHero->currentPos();
//					//Vec3D EndPos   = Extend(StartPos, enemyHero->currentPos(), 700);
//					Vec3D EndPos   = Extend(enemyHero->currentPos(), GET_REAL_FACING_POS(enemyHero), spellData.range);
//
//					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//					{
//						if(it_onMissileSpells->second.projectileSpeed == 0) continue;
//						float missileLifeTime = 555 + it_onMissileSpells->second.spellDelay + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed;
//
//						if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//						{
//							//__oMsg("---((***))----- Aatrox_Q3-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//							it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//						}
//					}
//				}
//			}
//		}
//	}	
//}