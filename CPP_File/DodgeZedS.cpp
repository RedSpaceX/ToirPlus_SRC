#include "DodgeZedS.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"


extern SpellDetector* _SpellDetector;
extern bool DodgeFOWSpells_menu;
//---------------------------------------------------------------------//--------------------//
//DWORD _zedPhacShadow[2] = {0};
DWORD _zedMissile[2]    = {0};
//void Evade_Zed_Q()
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
//		if (!CheckName(enemyHero->GetNameHero(), "Zed")) continue;
//
//		//------//------//------:
//		if (IsCanSee(enemyHero))
//		{
//			_zedPhacShadow[0] = 0;
//			_zedPhacShadow[1] = 0;
//
//			if (Distance(enemyHero, myHero) > 2500) continue;
//			KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
//			if (!args) continue;
//
//			KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
//			if(!pK_str2) continue;
//
//			std::string spell_name(pK_str2->GetSkillName());
//			if (spell_name.compare("ZedQ") != 0) continue;
//			
//			if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//
//			//------//------//------:
//			DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
//			DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
//			DWORD dwUnit1 = *(DWORD*)tempUnit;
//			DWORD dwUnit2 = *(DWORD*)tempUnitMax;
//			if (!dwUnit1 || !dwUnit2 ) return;
//			int countUnit = (dwUnit2 - dwUnit1)/4;
//			for (int iii = 0; iii < countUnit; ++iii)
//			{
//				DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
//				if (dwUnit3 == 0) continue;
//				KNpc *minion = (KNpc*)dwUnit3;
//				if (IS_DEAD(minion))    continue;
//				if (!IS_MINION(minion)) continue;
//				if ((BYTE)minion->nIsTargetableToTeam == 4 || minion->nTeam_ID == myHero->nTeam_ID) continue;
//				if (CheckName( sz__Shadow, minion->GetNameNpc()) == false) continue;
//				if (CheckName( sz__ZedShadow, minion->GetNameHero()) == false) continue;
//				if (_zedPhacShadow[0] == 0) 
//				{
//					_zedPhacShadow[0] = (DWORD)minion;
//					continue;
//				}
//				else if (_zedPhacShadow[1] == 0 && _zedPhacShadow[0] != (DWORD)minion)
//				{
//					_zedPhacShadow[1] = (DWORD)minion;
//					break;
//				}
//			}
//
//			//------//------//------:
//			std::string spellSpecial("ZedQ_Special");
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData = it_onProcessSpells->second;
//				float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//				{
//					Vec3D Start1(args->SourcePos.x , args->SourcePos.y , args->SourcePos.z);
//					Vec3D End1  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
//					if (Start1.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//					{
//						//__oMsg("---((*00*))----- Zed_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), Start1.Distance2D(End1), spellData.spellDelay);
//						CreateSpellData(enemyHero, Start1, End1, spellData, 0, 0);
//					}
//					
//					//----:
//					KNpc* shadow1 = (KNpc*)_zedPhacShadow[0];
//					if (shadow1 != 0 && !IS_DEAD(shadow1) && IsUnitInList(shadow1))
//					{
//						Vec3D Start2 = shadow1->currentPos();
//						Vec3D End2  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
//						if (Start2.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							//__oMsg("---((*11*))----- Zed_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), Start2.Distance2D(End2), spellData.spellDelay);
//							CreateSpellData(enemyHero, Start2, End2, spellData, 0, 0);
//						}
//					}
//					
//					//----:
//					KNpc* shadow2 = (KNpc*)_zedPhacShadow[1];
//					if (shadow2 != 0 && !IS_DEAD(shadow2) && IsUnitInList(shadow2))
//					{
//						Vec3D Start3 = shadow2->currentPos();
//						Vec3D End3  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
//						if (Start3.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							//__oMsg("---((*22*))----- Zed_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), Start3.Distance2D(End3), spellData.spellDelay);
//							CreateSpellData(enemyHero, Start3, End3, spellData, 0, 0);
//						}
//					}
//
//					it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//				}
//			}
//		}
//		else
//		{
//			if (DodgeFOWSpells_menu == false) return;
//
//			_zedMissile[0] = 0;
//			_zedMissile[1] = 0;
//			//------//------//------:
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
//				if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
//				if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;
//				if (!CheckNameEx("ZedQMissile", missileObj->GetNameNpc())) continue;
//
//				if (_zedMissile[0] == 0) 
//				{
//					_zedMissile[0] = (DWORD)missileObj;
//					continue;
//				}
//				else if (_zedMissile[1] == 0 && _zedMissile[0] != (DWORD)missileObj)
//				{
//					_zedMissile[1] = (DWORD)missileObj;
//					break;
//				}
//			}
//			
//			//------//------//------:
//			if (_zedMissile[0] == 0 && _zedMissile[1] == 0) return;
//
//			std::string spellSpecial("ZedQ_Special");
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData = it_onProcessSpells->second;
//				float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//				{
//					//----:
//					KNpc* missile1 = (KNpc*)_zedMissile[0];
//					if (missile1 != 0)
//					{
//						Vec3D Start(missile1->MissileSrcPos.x, missile1->MissileSrcPos.y, missile1->MissileSrcPos.z);
//						Vec3D End  (missile1->MissileDestPos.x, missile1->MissileDestPos.y, missile1->MissileDestPos.z);
//						if (Start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							//__oMsg("---((*11.2*))----- Zed_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), Start.Distance2D(End), spellData.spellDelay);
//							CreateSpellData(enemyHero, Start, End, spellData, missile1, 0);
//						}
//					}
//
//					//----:
//					KNpc* missile2 = (KNpc*)_zedMissile[1];
//					if (missile2 != 0)
//					{
//						Vec3D Start(missile2->MissileSrcPos.x, missile2->MissileSrcPos.y, missile2->MissileSrcPos.z);
//						Vec3D End  (missile2->MissileDestPos.x, missile2->MissileDestPos.y, missile2->MissileDestPos.z);
//						if (Start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							//__oMsg("---((*22.2*))----- Zed_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), Start.Distance2D(End), spellData.spellDelay);
//							CreateSpellData(enemyHero, Start, End, spellData, missile2, 0);
//						}
//					}
//
//					it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//				}
//			}
//		}
//	}
//}

////---------------------------------------------------------------------//--------------------//
//KNpc* _luluPhacker	  = 0;
//DWORD _luluMissile[2] = {0};
//void Evade_Lulu_Q()
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
//		if (!CheckName(enemyHero->GetNameHero(), "Lulu")) continue;
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
//			if (spell_name.compare("LuluQ") != 0) continue;
//
//			if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//
//			//------//------//------:
//			DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
//			DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
//			DWORD dwUnit1 = *(DWORD*)tempUnit;
//			DWORD dwUnit2 = *(DWORD*)tempUnitMax;
//			if (!dwUnit1 || !dwUnit2 ) return;
//			int countUnit = (dwUnit2 - dwUnit1)/4;
//			for (int iii = 0; iii < countUnit; ++iii)
//			{
//				DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
//				if (dwUnit3 == 0) continue;
//				KNpc *minion = (KNpc*)dwUnit3;
//				if (IS_DEAD(minion))    continue;
//				if (!IS_MINION(minion)) continue;
//				if ((BYTE)minion->nIsTargetableToTeam == 4 || minion->nTeam_ID == myHero->nTeam_ID) continue;
//				if (CheckName("RobotBuddy", minion->GetNameNpc()) == false) continue;
//				if (CheckName("LuluFaerie", minion->GetNameHero()) == false) continue;
//
//				_luluPhacker = minion;
//				break;
//			}
//
//			//------//------//------:
//			std::string spellSpecial("LuluQ_Special");
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData = it_onProcessSpells->second;
//				float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//				{
//					Vec3D Start1(args->SourcePos.x , args->SourcePos.y , args->SourcePos.z);
//					Vec3D End1  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
//					if (Start1.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//					{
//						//__oMsg("---((*00*))----- ZLuLu_Q1_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), Start1.Distance2D(End1), spellData.spellDelay);
//						CreateSpellData(enemyHero, Start1, End1, spellData, 0, 0);
//					}
//
//					//----:
//					if (_luluPhacker != 0 && !IS_DEAD(_luluPhacker) && IsUnitInList(_luluPhacker))
//					{
//						Vec3D Start2 = _luluPhacker->currentPos();
//						Vec3D End2  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
//						if (Start2.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							//__oMsg("---((*11*))----- ZLuLu_Q2_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), Start2.Distance2D(End2), spellData.spellDelay);
//							CreateSpellData(enemyHero, Start2, End2, spellData, 0, 0);
//						}
//					}
//					it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//				}
//			}
//		}
//		else
//		{
//			if (DodgeFOWSpells_menu == false) return;
//
//			_luluMissile[0] = 0;
//			_luluMissile[1] = 0;
//			//------//------//------:
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
//				if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
//				if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;
//				if (!CheckName("LuluQMissile", missileObj->GetNameNpc())) continue;		//"LuluQMissile" hoac "LuluQMissileTwo"
//
//				if (_luluMissile[0] == 0) 
//				{
//					_luluMissile[0] = (DWORD)missileObj;
//					continue;
//				}
//				else if (_luluMissile[1] == 0 && _luluMissile[0] != (DWORD)missileObj)
//				{
//					_luluMissile[1] = (DWORD)missileObj;
//					break;
//				}
//			}
//
//			//------//------//------:
//			if (_luluMissile[0] == 0 && _luluMissile[1] == 0) return;
//
//			std::string spellSpecial("LuluQ_Special");
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData = it_onProcessSpells->second;
//				float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//				{
//					//----:
//					KNpc* missile1 = (KNpc*)_luluMissile[0];
//					if (missile1 != 0)
//					{
//						Vec3D Start(missile1->MissileSrcPos.x, missile1->MissileSrcPos.y, missile1->MissileSrcPos.z);
//						Vec3D End  (missile1->MissileDestPos.x, missile1->MissileDestPos.y, missile1->MissileDestPos.z);
//						if (Start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							//__oMsg("---((*11.2*))----- LULU_Q1_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), Start.Distance2D(End), spellData.spellDelay);
//							CreateSpellData(enemyHero, Start, End, spellData, missile1, 0);
//						}
//					}
//
//					//----:
//					KNpc* missile2 = (KNpc*)_luluMissile[1];
//					if (missile2 != 0)
//					{
//						Vec3D Start(missile2->MissileSrcPos.x, missile2->MissileSrcPos.y, missile2->MissileSrcPos.z);
//						Vec3D End  (missile2->MissileDestPos.x, missile2->MissileDestPos.y, missile2->MissileDestPos.z);
//						if (Start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							//__oMsg("---((*22.2*))----- LULU_Q2_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), Start.Distance2D(End), spellData.spellDelay);
//							CreateSpellData(enemyHero, Start, End, spellData, missile2, 0);
//						}
//					}
//
//					it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//				}
//			}
//		}
//	}
//}

//---------------------------------------------------------------------//--------------------//
void Evade_Ziggs_Q()
{
	//////KNpc* myHero = GetPlayer();
	//////if (!myHero) return;
	//////if (G_Module == 0) return;

	//////DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	//////DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	//////DWORD dwHero1 = *(DWORD*)tempHero;
	//////DWORD dwHero2 = *(DWORD*)tempHeroMax;
	//////if (!dwHero1 || !dwHero2 ) return;

	//////int countHero = (dwHero2 - dwHero1)/4;
	//////for (int i = 0; i < countHero; ++i)
	//////{
	//////	DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
	//////	if (dwHero3 == 0) continue;
	//////	KNpc *enemyHero = (KNpc*)dwHero3;
	//////	if (enemyHero->nTeam_ID == myHero->nTeam_ID)		   continue;
	//////	if (!CheckName(enemyHero->GetNameHero(), "Ziggs")) continue;

	//////	//------//------//------:
	//////	if (IsCanSee(enemyHero))
	//////	{
	//////		if (Distance(enemyHero, myHero) > 2500) continue;
	//////		KCastSpell* args = (KCastSpell*)enemyHero->_pCastSpell;
	//////		if (!args) continue;

	//////		KSkill_2*  pK_str2 = (KSkill_2*) args->__pK_str2;
	//////		if(!pK_str2) continue;

	//////		std::string spell_name(pK_str2->GetSkillName());
	//////		if (spell_name.compare("ZiggsQ") != 0) continue;

	//////		if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;

	//////		//------//------//------:
	//////		std::string spellSpecial("ZiggsQ_Special");
	//////		std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
	//////		if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
	//////		{
	//////			SpellData spellData = it_onProcessSpells->second;
	//////			float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;

	//////			if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	//////			{
	//////				Vec3D startPos(args->SourcePos.x , args->SourcePos.y , args->SourcePos.z);
	//////				Vec3D endPos  (args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
	//////				Vec3D dir	= (endPos - startPos).Normalized();

	//////				if (startPos.Distance2D(myHero->currentPos()) < spellData.range + 1600)
	//////				{
	//////					if (endPos.Distance2D(startPos) > 850)
	//////					{
	//////						endPos = startPos + dir * 850;
	//////					}

	//////					//__oMsg("---((*00*))----- Ziggs_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), startPos.Distance2D(endPos), spellData.spellDelay);
	//////					CreateSpellData(enemyHero, startPos, endPos, spellData, 0, 0, false);

	//////					Vec3D endPos2 = endPos + dir * 0.4f * startPos.Distance2D(endPos);
	//////					spellData.range = startPos.Distance2D(endPos2);
	//////					spellData.waitExtra = 475;
	//////					float exEntick = 250; //1000 * endPos.Distance2D(endPos2)/1600 + 150;
	//////					//__oMsg("---((*00*))----- Ziggs_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), startPos.Distance2D(endPos2), exEntick);
	//////					CreateSpellData(enemyHero, startPos, endPos2, spellData, 0, exEntick, false);

	//////					Vec3D endPos3 = endPos2 + dir * 0.6f * endPos.Distance2D(endPos2);
	//////					spellData.range = startPos.Distance2D(endPos3);
	//////					spellData.waitExtra = 1025;
	//////					//exEntick = exEntick + 1000 * endPos2.Distance2D(endPos3)/1600 + 250;
	//////					exEntick = 800;
	//////					//__oMsg("---((*00*))----- Ziggs_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), startPos.Distance2D(endPos3), exEntick);
	//////					CreateSpellData(enemyHero, startPos, endPos3, spellData, 0, exEntick);
	//////				}
	//////				it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
	//////			}
	//////		}
	//////	}
	//////	else
	//////	{
	//////		if (DodgeFOWSpells_menu == false) return;	
	//////		//------//------//------:
	//////		DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
	//////		DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
	//////		if (!dw0) return;

	//////		DWORD dw1 = *(DWORD*)(dw0 + 8);
	//////		if (!dw1) return;

	//////		int nCount_xxx = *(DWORD*)(dw0 + 0xC);
	//////		if (!nCount_xxx) return;

	//////		for (int kk = 0; kk < nCount_xxx; ++kk)
	//////		{
	//////			DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
	//////			if (dw3 == 0) continue;
	//////			KNpc *missileObj = (KNpc*)dw3;

	//////			if (IS_OBJ_DELETED(missileObj) == true)	 continue;
	//////			if (missileObj->nIndex < 0x3FFFFCC8)     continue;			
	//////			if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
	//////			if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;
	//////			if (!CheckNameEx("ZiggsQSpell", missileObj->GetNameNpc())) continue;

	//////			//------//------//------:
	//////			std::string spellSpecial("ZiggsQ_Special");
	//////			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
	//////			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
	//////			{
	//////				SpellData spellData = it_onProcessSpells->second;
	//////				float missileLifeTime = spellData.projectileSpeed > 0 ? 1222 + 0 + 1000*spellData.range/spellData.projectileSpeed : 1000;

	//////				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	//////				{
	//////					//Vec3D startPos = missileObj->currentPos();
	//////					Vec3D startPos(missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
	//////					Vec3D endPos  (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z);
	//////					Vec3D dir	= (endPos - startPos).Normalized();

	//////					if (startPos.Distance2D(myHero->currentPos()) < spellData.range + 1600)
	//////					{
	//////						if (endPos.Distance2D(startPos) > 850)
	//////						{
	//////							endPos = startPos + dir * 850;
	//////						}

	//////						//__oMsg("---((*01*))----- Ziggs_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), startPos.Distance2D(endPos), spellData.spellDelay);
	//////						CreateSpellData(enemyHero, startPos, endPos, spellData, missileObj, 0, false);

	//////						Vec3D endPos2 = endPos + dir * 0.4f * startPos.Distance2D(endPos);
	//////						spellData.range = startPos.Distance2D(endPos2);
	//////						spellData.waitExtra = 475;
	//////						float exEntick = 250; //1000 * endPos.Distance2D(endPos2)/1600 + 150;
	//////						//__oMsg("---((*01*))----- Ziggs_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), startPos.Distance2D(endPos2), exEntick);
	//////						CreateSpellData(enemyHero, startPos, endPos2, spellData, missileObj, exEntick, false);

	//////						Vec3D endPos3 = endPos2 + dir * 0.6f * endPos.Distance2D(endPos2);
	//////						spellData.range = startPos.Distance2D(endPos3);
	//////						spellData.waitExtra = 1025;
	//////						exEntick = 800; //exEntick + 1000 * endPos2.Distance2D(endPos3)/1600 + 250;
	//////						//__oMsg("---((*01*))----- Ziggs_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), startPos.Distance2D(endPos3), exEntick);
	//////						CreateSpellData(enemyHero, startPos, endPos3, spellData, missileObj, exEntick);
	//////					}
	//////					it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
	//////				}
	//////			}
	//////		}	
	//////	}
	//////}
}

////---------------------------------------------------------------------//--------------------//
//void Evade_Zoe_Q2()
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
//		if (enemyHero->nTeam_ID == myHero->nTeam_ID)	 continue;
//		if (!CheckName(enemyHero->GetNameHero(), "Zoe")) continue;
//
//		//------//------//------:
//		if (!IsCanSee(enemyHero) && DodgeFOWSpells_menu == false) continue;
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
//			if (!IS_OBJECT_TYPE(missileObj, 0x8001)) continue;
//			if (missileObj->nTeam_ID == myHero->nTeam_ID) continue;
//
//			std::string mis_name("ZoeQMis2");	//co ca "ZoeQMis2Warning" phacker
//
//			if (mis_name.compare(missileObj->GetNameNpc()) != 0) continue;		
//
//			std::string spellSpecial("ZoeQ2_Special");
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				Vec3D Start(missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
//				Vec3D End  (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z);
//
//				SpellData spellData  = it_onProcessSpells->second;
//				spellData.spellDelay = 0;
//				spellData.range      = Distance(Start, End) + 50;
//
//				float missileLifeTime = spellData.projectileSpeed > 0 ? 999 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//				if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//				{		
//					if (Start.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//					{
//						//__oMsg("---((*11.2*))----- Zoe_Q2_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellSpecial.c_str(), spellData.range, spellData.spellDelay);
//						CreateSpellData(enemyHero, Start, End, spellData, missileObj, 0);
//					}
//		
//					it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//				}
//			}
//
//		}
//	}
//}

//---------------------------------------------------------------------//--------------------//
void Evade_Lulu_Q_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)
{
	////////if (spellData.spellName.compare("LuluQ") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	////////if (!IsCanSee(hero)) return;
	////////if (Distance(hero, myHero) > 2500) return;

	////////Vec3D Start(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
	////////Vec3D End  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);

	//////////------//------//------:
	////////bool hasLuluFaerie = false;

	////////DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
	////////DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	////////DWORD dwUnit1 = *(DWORD*)tempUnit;
	////////DWORD dwUnit2 = *(DWORD*)tempUnitMax;
	////////if (!dwUnit1 || !dwUnit2 ) return;
	////////int countUnit = (dwUnit2 - dwUnit1)/4;
	////////for (int iii = 0; iii < countUnit; ++iii)
	////////{
	////////	DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
	////////	if (dwUnit3 == 0) continue;
	////////	KNpc *minion = (KNpc*)dwUnit3;
	////////	if (IS_DEAD(minion))    continue;
	////////	if (!IS_MINION(minion)) continue;
	////////	if ((BYTE)minion->nIsTargetableToTeam == 4 || minion->nTeam_ID == myHero->nTeam_ID) continue;
	////////	if (Distance(minion, hero) > 800) continue;
	////////	if (CheckName("RobotBuddy", minion->GetNameNpc()) == false) continue;
	////////	if (CheckName("LuluFaerie", minion->GetNameHero()) == false) continue;
	////////	
	////////	hasLuluFaerie = true;

	////////	//__oMsg("---((*00*))----- LuluQ_CREATE_OPS-0000: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), Start.Distance2D(End), spellData.spellDelay);
	////////	CreateSpellData(hero, Start, End, spellData, 0, 0);

	////////	//__oMsg("---((*11*))----- LULU_ROBOT_Q_CREATE_OPS-1111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), Start.Distance2D(End), spellData.spellDelay);
	////////	CreateSpellData(hero, minion->currentPos(), End, spellData, 0, 0);
	////////	return;
	////////}

	////////if (hasLuluFaerie == false)
	////////{
	////////	//__oMsg("---((*222*))----- LuluQ_CREATE_OPS-0000: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), Start.Distance2D(End), spellData.spellDelay);
	////////	CreateSpellData(hero, Start, End, spellData, 0, 0);
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Lulu_Q_OCM(KNpc* missileObj, SpellData &spellData)
{
	////////if (DodgeFOWSpells_menu == false) return;

	////////if (spellData.missileName.compare("LuluQMissile") != 0) return;

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
	////////					//__oMsg("	  ---------(LULU-Q.mis)SpellMissile.OnCreate -- MISSILE-DA~GA'N-ROI: KC_Missile = %.3f", start.Distance2D(end));
	////////					break;
	////////				}
	////////			}
	////////		}

	////////		if(spellData.projectileSpeed == 0) return;
	////////		float missileLifeTime = 690 + 69 + 1000*spellData.range/spellData.projectileSpeed;

	////////		if (objectAssigned == false && (float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////		{
	////////			bool hasLuluFaerie = false;
	////////			////------//------//------:
	////////			//DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
	////////			//DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	////////			//DWORD dwUnit1 = *(DWORD*)tempUnit;
	////////			//DWORD dwUnit2 = *(DWORD*)tempUnitMax;
	////////			//if (!dwUnit1 || !dwUnit2 ) return;
	////////			//int countUnit = (dwUnit2 - dwUnit1)/4;
	////////			//for (int iii = 0; iii < countUnit; ++iii)
	////////			//{
	////////			//	DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
	////////			//	if (dwUnit3 == 0) continue;
	////////			//	KNpc *minion = (KNpc*)dwUnit3;
	////////			//	if (IS_DEAD(minion))    continue;
	////////			//	if (!IS_MINION(minion)) continue;
	////////			//	if ((BYTE)minion->nIsTargetableToTeam == 4 || minion->nTeam_ID == myHero->nTeam_ID) continue;
	////////			//	if (Distance(minion, hero) > 800) continue;
	////////			//	if (CheckName("RobotBuddy", minion->GetNameNpc()) == false) continue;
	////////			//	if (CheckName("LuluFaerie", minion->GetNameHero()) == false) continue;

	////////			//	hasLuluFaerie = true;

	////////			//	spellData.spellDelay = 0;

	////////			//	__oMsg("---((*11.11: %.3f))----- LULU_Q_MISILE_CREATE-MISSLE-2222: %s KC_Missile = %.3f (%.3f) - delay: %f", GetTimeGame(), mis_Name.c_str(), start.Distance2D(end), Distance(myHero, hero),spellData.spellDelay);
	////////			//	CreateSpellData(hero, start, end, spellData, 0);

	////////			//	__oMsg("---((*22.22: %.3f))----- LULU.ROBOT.Q_MISILE_CREATE-MISSLE-2222: %s KC_Missile = %.3f (%.3f) - delay: %f", GetTimeGame(), mis_Name.c_str(), start.Distance2D(end), Distance(myHero, hero),spellData.spellDelay);
	////////			//	CreateSpellData(hero, minion->currentPos(), end, spellData, 0);

	////////			//	spellData.lastCreateMissileTime = (float)GetTickCount();
	////////			//	return;
	////////			//}
	////////			if (hasLuluFaerie == false)
	////////			{
	////////				spellData.spellDelay = 0;

	////////				//__oMsg("---((*33.33: %.3f))----- LULU_Q_MISILE_CREATE-MISSLE-2222: %s KC_Missile = %.3f (%.3f) - delay: %f", GetTimeGame(), mis_Name.c_str(), start.Distance2D(end), Distance(myHero, hero),spellData.spellDelay);
	////////				CreateSpellData(hero, start, end, spellData, 0);

	////////				spellData.lastCreateMissileTime = (float)GetTickCount();
	////////			}
	////////		}
	////////	}
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Zed_Q_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)
{
	////////if (spellData.spellName.compare("ZedQ") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	////////if (!IsCanSee(hero)) return;
	////////if (Distance(hero, myHero) > 2500) return;

	//////////------//------//------:
	////////_zedPhacShadow[0] = 0;
	////////_zedPhacShadow[1] = 0;

	//////////------//------//------:
	////////DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
	////////DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	////////DWORD dwUnit1 = *(DWORD*)tempUnit;
	////////DWORD dwUnit2 = *(DWORD*)tempUnitMax;
	////////if (!dwUnit1 || !dwUnit2 ) return;
	////////int countUnit = (dwUnit2 - dwUnit1)/4;
	////////for (int iii = 0; iii < countUnit; ++iii)
	////////{
	////////	DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
	////////	if (dwUnit3 == 0) continue;
	////////	KNpc *minion = (KNpc*)dwUnit3;
	////////	if (IS_DEAD(minion))    continue;
	////////	if (!IS_MINION(minion)) continue;
	////////	if ((BYTE)minion->nIsTargetableToTeam == 4 || minion->nTeam_ID == myHero->nTeam_ID) continue;
	////////	if (Distance(minion, myHero) > 2500) continue;
	////////	if (CheckName( sz__Shadow, minion->GetNameNpc()) == false) continue;
	////////	if (CheckName( sz__ZedShadow, minion->GetNameHero()) == false) continue;
	////////	if (_zedPhacShadow[0] == 0) 
	////////	{
	////////		_zedPhacShadow[0] = (DWORD)minion;
	////////		continue;
	////////	}
	////////	else if (_zedPhacShadow[1] == 0 && _zedPhacShadow[0] != (DWORD)minion)
	////////	{
	////////		_zedPhacShadow[1] = (DWORD)minion;
	////////		break;
	////////	}
	////////}

	//////////------//------//------:
	////////
	////////Vec3D Start1(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
	////////Vec3D End1  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
	////////if (Start1.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	////////{
	////////	//__oMsg("---((*00*))----- Zed_Q_CREATE_OPS-00000: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), Start1.Distance2D(End1), spellData.spellDelay);
	////////	CreateSpellData(hero, Start1, End1, spellData, 0, 0);
	////////}

	//////////----:
	////////KNpc* shadow1 = (KNpc*)_zedPhacShadow[0];
	////////if (shadow1 != 0 && !IS_DEAD(shadow1) && IsUnitInList(shadow1))
	////////{
	////////	Vec3D Start2 = shadow1->currentPos();
	////////	Vec3D End2  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
	////////	if (Start2.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	////////	{
	////////		//__oMsg("---((*11*))----- Zed_Q_CREATE_OPS-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), Start1.Distance2D(End1), spellData.spellDelay);
	////////		CreateSpellData(hero, Start2, End2, spellData, 0, 0);
	////////	}
	////////}

	//////////----:
	////////KNpc* shadow2 = (KNpc*)_zedPhacShadow[1];
	////////if (shadow2 != 0 && !IS_DEAD(shadow2) && IsUnitInList(shadow2))
	////////{
	////////	Vec3D Start3 = shadow2->currentPos();
	////////	Vec3D End3  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
	////////	if (Start3.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	////////	{
	////////		//__oMsg("---((*22*))----- Zed_Q_CREATE_OPS-22222: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), Start1.Distance2D(End1), spellData.spellDelay);
	////////		CreateSpellData(hero, Start3, End3, spellData, 0, 0);
	////////	}
	////////}	
}

//---------------------------------------------------------------------//--------------------//
void Evade_Zed_Q_OCM(KNpc* missileObj, SpellData &spellData)
{
	////////if (DodgeFOWSpells_menu == false) return;

	////////if (spellData.missileName.compare("ZedQMissile") != 0) return;

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
	////////					//__oMsg("	  ---------(Zed-Q.mis)SpellMissile.OnCreate -- MISSILE-DA~GA'N-ROI: KC_Missile = %.3f", start.Distance2D(end));
	////////					break;
	////////				}
	////////			}
	////////		}

	////////		if(spellData.projectileSpeed == 0) return;
	////////		float missileLifeTime = 690 + 69 + 1000*spellData.range/spellData.projectileSpeed;

	////////		if (objectAssigned == false && (float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////		{
	////////			bool hasZedShuriken = false;
	////////			//------//------//------:
	////////			DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
	////////			DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	////////			DWORD dwUnit1 = *(DWORD*)tempUnit;
	////////			DWORD dwUnit2 = *(DWORD*)tempUnitMax;
	////////			if (!dwUnit1 || !dwUnit2 ) return;
	////////			int countUnit = (dwUnit2 - dwUnit1)/4;
	////////			for (int iii = 0; iii < countUnit; ++iii)
	////////			{
	////////				DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
	////////				if (dwUnit3 == 0) continue;
	////////				KNpc *minion = (KNpc*)dwUnit3;
	////////				if (IS_DEAD(minion))    continue;
	////////				if (!IS_MINION(minion)) continue;
	////////				if ((BYTE)minion->nIsTargetableToTeam == 4 || minion->nTeam_ID == myHero->nTeam_ID) continue;
	////////				if (Distance(minion, myHero) > 2500) continue;
	////////				if (CheckName( sz__Shadow, minion->GetNameNpc()) == false) continue;
	////////				if (CheckName( sz__ZedShadow, minion->GetNameHero()) == false) continue;
	////////				if (Distance(minion->currentPos(), start) < 50) continue;
	////////				
	////////				hasZedShuriken = true;

	////////				spellData.spellDelay = 0;

	////////				//__oMsg("---((*11.11: %.3f))----- Zed_Q_MISILE_CREATE-MISSLE-2222: %s KC_Missile = %.3f (%.3f) - delay: %f", GetTimeGame(), mis_Name.c_str(), start.Distance2D(end), Distance(myHero, hero),spellData.spellDelay);
	////////				CreateSpellData(hero, start, end, spellData, 0);

	////////				//__oMsg("---((*22.22: %.3f))----- Zed_Q_MISILE_CREATE-MISSLE-2222: %s KC_Missile = %.3f (%.3f) - delay: %f", GetTimeGame(), mis_Name.c_str(), start.Distance2D(end), Distance(myHero, hero),spellData.spellDelay);
	////////				CreateSpellData(hero, minion->currentPos(), end, spellData, 0);

	////////				spellData.lastCreateMissileTime = (float)GetTickCount();
	////////			}
	////////			if (hasZedShuriken == false)
	////////			{
	////////				spellData.spellDelay = 0;

	////////				//__oMsg("---((*33.33: %.3f))----- Zed_Q_MISILE_CREATE-MISSLE-2222: %s KC_Missile = %.3f (%.3f) - delay: %f", GetTimeGame(), mis_Name.c_str(), start.Distance2D(end), Distance(myHero, hero),spellData.spellDelay);
	////////				CreateSpellData(hero, start, end, spellData, 0);

	////////				spellData.lastCreateMissileTime = (float)GetTickCount();
	////////			}
	////////		}
	////////	}
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Ziggs_Q_OPS(KNpc* hero, KCastSpell* spellCast, SpellData spellData)
{
	////////if (spellData.spellName.compare("ZiggsQ") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	////////if (Distance(hero, myHero) > 2500) return;

	//////////------//------//------:

	////////Vec3D startPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
	////////Vec3D endPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
	////////Vec3D dir	= (endPos - startPos).Normalized();

	////////if (startPos.Distance2D(myHero->currentPos()) < spellData.range + 1600)
	////////{
	////////	if (endPos.Distance2D(startPos) > 850)
	////////	{
	////////		endPos = startPos + dir * 850;
	////////	}

	////////	//__oMsg("---((*00*))----- Ziggs_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), startPos.Distance2D(endPos), spellData.spellDelay);
	////////	CreateSpellData(hero, startPos, endPos, spellData, 0, 0, false);

	////////	Vec3D endPos2 = endPos + dir * 0.4f * startPos.Distance2D(endPos);
	////////	spellData.range = startPos.Distance2D(endPos2);
	////////	spellData.waitExtra = 475;
	////////	float exEntick = 250; //1000 * endPos.Distance2D(endPos2)/1600 + 150;
	////////	//__oMsg("---((*11*))----- Ziggs_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), startPos.Distance2D(endPos2), exEntick);
	////////	CreateSpellData(hero, startPos, endPos2, spellData, 0, exEntick, false);

	////////	Vec3D endPos3 = endPos2 + dir * 0.6f * endPos.Distance2D(endPos2);
	////////	spellData.range = startPos.Distance2D(endPos3);
	////////	spellData.waitExtra = 1025;
	////////	//exEntick = exEntick + 1000 * endPos2.Distance2D(endPos3)/1600 + 250;
	////////	exEntick = 800;
	////////	//__oMsg("---((*22*))----- Ziggs_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", spellData.spellName.c_str(), startPos.Distance2D(endPos3), exEntick);
	////////	CreateSpellData(hero, startPos, endPos3, spellData, 0, exEntick);
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Ziggs_Q_OCM(KNpc* missileObj, SpellData &spellData)
{
	////////if (DodgeFOWSpells_menu == false) return;

	////////if (spellData.missileName.compare("ZiggsQSpell") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	//////////------//------//------:
	////////KNpc* hero = (KNpc*)GetObjectByID(missileObj->nMissileOwnerID_1);
	////////if (hero)
	////////{
	////////	Vec3D start (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
	////////	Vec3D end   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 

	////////	if (start.Distance2D(myHero->currentPos()) < spellData.range + 1600)
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
	////////					//__oMsg("	  ---------(Z-I-G-Gs-Q.mis)SpellMissile.OnCreate -- MISSILE-DA~GA'N-ROI: KC_Missile = %.3f", start.Distance2D(end));
	////////					break;
	////////				}
	////////			}
	////////		}

	////////		float missileLifeTime = spellData.projectileSpeed > 0 ? 1222 + 0 + 1000*spellData.range/spellData.projectileSpeed : 1000;

	////////		if (objectAssigned == false && (float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////		{
	////////			Vec3D startPos(missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
	////////			Vec3D endPos  (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z);
	////////			Vec3D dir	= (endPos - startPos).Normalized();

	////////			if (endPos.Distance2D(startPos) > 850)
	////////			{
	////////				endPos = startPos + dir * 850;
	////////			}

	////////			//__oMsg("---((*01.00*))----- Ziggs_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellData.missileName.c_str(), startPos.Distance2D(endPos), spellData.spellDelay);
	////////			CreateSpellData(hero, startPos, endPos, spellData, missileObj, 0, false);

	////////			Vec3D endPos2 = endPos + dir * 0.4f * startPos.Distance2D(endPos);
	////////			spellData.range = startPos.Distance2D(endPos2);
	////////			spellData.waitExtra = 475;
	////////			float exEntick = 250; //1000 * endPos.Distance2D(endPos2)/1600 + 150;
	////////			//__oMsg("---((*01.11*))----- Ziggs_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellData.missileName.c_str(), startPos.Distance2D(endPos2), exEntick);
	////////			CreateSpellData(hero, startPos, endPos2, spellData, missileObj, exEntick, false);

	////////			Vec3D endPos3 = endPos2 + dir * 0.6f * endPos.Distance2D(endPos2);
	////////			spellData.range = startPos.Distance2D(endPos3);
	////////			spellData.waitExtra = 1025;
	////////			exEntick = 800; //exEntick + 1000 * endPos2.Distance2D(endPos3)/1600 + 250;
	////////			//__oMsg("---((*01.22*))----- Ziggs_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spellData.missileName.c_str(), startPos.Distance2D(endPos3), exEntick);
	////////			CreateSpellData(hero, startPos, endPos3, spellData, missileObj, exEntick);
	////////			spellData.lastCreateMissileTime = (float)GetTickCount();
	////////		}
	////////	}
	////////}
}

//---------------------------------------------------------------------//--------------------//
void Evade_Zoe_Q2_OCM(KNpc* missileObj, SpellData &spellData)
{
	////////if (spellData.missileName.compare("ZoeQMis2") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;

	//////////------//------//------:
	////////KNpc* hero = (KNpc*)GetObjectByID(missileObj->nMissileOwnerID_1);
	////////if (hero)
	////////{
	////////	Vec3D curPos   = missileObj->currentPos();
	////////	Vec3D StartPos (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
	////////	Vec3D EndPos   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 

	////////	spellData.range = StartPos.Distance2D(EndPos);

	////////	if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
	////////	{
	////////		float missileLifeTime = spellData.projectileSpeed > 0 ? 666 + 1000*spellData.range/spellData.projectileSpeed : 1000.0f;

	////////		if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////		{
	////////			//__oMsg("---((*11*))----- ZOE_Q22_-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f", missileObj->GetNameNpc(), StartPos.Distance2D(EndPos), spellData.spellDelay);

	////////			CreateSpellData(hero, curPos, EndPos, spellData, missileObj, 0);

	////////			spellData.lastCreateMissileTime = (float)GetTickCount();
	////////		}
	////////	}
	////////}
}