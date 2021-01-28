#include "DodgeXinZhaoS.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"


//extern SpellDetector* _SpellDetector;
//extern bool DodgeFOWSpells_menu;
////---------------------------------------------------------------------//--------------------//
//void Evade_XinZhao_W()
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)		   continue;
//		if (!CheckName(enemyHero->GetNameHero(), "XinZhao")) continue;
//
//		//------//------//------:
//		if (IsCanSee(enemyHero))
//		{
//			if (Distance(enemyHero, myHero) > 2500) continue;
//			KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//			if (!args) continue;
//
//			KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//			if(!pK_str2) continue;
//
//			std::string spell_name(pK_str2->GetSkillName());
//			if (spell_name.compare("XinZhaoW") != 0) continue;
//
//			if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//
//			//------//------//------:
//			std::string spellSpecial("XinZhaoW_Special");
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData = it_onProcessSpells->second;
//				float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//				{
//					Vec3D start(args->SourcePos.x , args->SourcePos.y , args->SourcePos.z);
//					Vec3D end  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z); 
//
//					if (start.Distance2D(myHero->currentPos()) < spellData.range + 1000 /*&& start.Distance2D(myHero->currentPos()) > 345*/)
//					{
//						//__oMsg("---((*11.1*))----- XinZhaoW_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), start.Distance2D(end), spellData.spellDelay);
//						CreateSpellData(enemyHero, start, end, spellData);
//
//						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//					}
//				}
//			}
//		}
//	}
//}
//
////---------------------------------------------------------------------//--------------------//
//void Evade_XinZhao_R()
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)		   continue;
//		if (!CheckName(enemyHero->GetNameHero(), "XinZhao")) continue;
//
//		//------//------//------:
//		if (IsCanSee(enemyHero))
//		{
//			if (Distance(enemyHero, myHero) > 2500) continue;
//			KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//			if (!args) continue;
//
//			KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//			if(!pK_str2) continue;
//
//			std::string spell_name(pK_str2->GetSkillName());
//			if (spell_name.compare("XinZhaoR") != 0) continue;
//
//			if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//
//			//------//------//------:
//			std::string spellSpecial("XinZhaoR_Special");
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData = it_onProcessSpells->second;
//				float missileLifeTime = spellData.projectileSpeed > 0 ? 1555 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//				{
//					Vec3D end   = enemyHero->currentPos(); 
//					Vec3D start = Extend(end, myHero->currentPos(), -500);
//
//					if (end.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//					{
//						//__oMsg("---((*11.1*))----- XinZhaoR_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), start.Distance2D(end), spellData.spellDelay);
//						CreateSpellData(enemyHero, start, end, spellData);
//
//						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//					}
//				}
//			}
//		}
//	}
//}

////---------------------------------------------------------------------//--------------------//
//void Evade_Neeko_R()
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)		   continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Neeko")) continue;
//
//		//------//------//------:
//		DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
//		DWORD dw0 = nTempBASE_OBJECT_ALL + 4;
//		DWORD dw1 = *(DWORD*)dw0;
//		if (!dw1) return;
//
//		int countAllObj = *(DWORD*)(dw0 + 4);
//		if (!countAllObj) return;
//		for (int kk = 0; kk < countAllObj; ++kk)
//		{
//			DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
//			if (dw3 == 0) continue;
//			KNpc *missileObj = (KNpc*)dw3;
//
//			if (IS_OBJ_DELETED(missileObj) == true)	 continue;
//			if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
//			if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
//			if (missileObj->nTeam_ID != enemyHero->nTeam_ID) continue;
//
//			if (CheckName("NeekoRIndicatorMis", missileObj->GetNameNpc()))
//			{
//				//------//------//------:
//				std::string spellSpecial("NeekoR_Special");
//				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
//				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//				{
//					SpellData spellData = it_onProcessSpells->second;
//					float missileLifeTime = spellData.projectileSpeed > 0 ? 3000 + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//					if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//					{
//						Vec3D end   = enemyHero->currentPos(); 
//						Vec3D start = enemyHero->currentPos(); //Extend(end, myHero->currentPos(), -600);
//
//						//__oMsg("---((*111*))----- NeekoooR_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), start.Distance2D(end), spellData.spellDelay);
//						CreateSpellData(enemyHero, start, end, spellData);
//
//						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//					}
//				}
//			}
//		}
//	}
//}