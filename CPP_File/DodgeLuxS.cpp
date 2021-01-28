#include "DodgeLuxS.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"


extern SpellDetector* _SpellDetector;
extern bool DodgeFOWSpells_menu;
//---------------------------------------------------------------------//--------------------//
void Evade_Lux_R()
{
	////////if (DodgeFOWSpells_menu == false) return;

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
	////////	if (enemyHero->nTeam_ID == myHero->nTeam_ID)	 continue;
	////////	if (IsCanSee(enemyHero)) continue;
	////////	if (!CheckName(enemyHero->GetNameHero(), "Lux")) continue;
	////////	
	////////	//if (Distance(enemyHero, myHero) > 5000) continue;

	////////	//------//------//------:
	////////	DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
	////////	DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
	////////	if (!dw0) return;

	////////	DWORD dw1 = *(DWORD*)(dw0 + 8);
	////////	if (!dw1) return;

	////////	int nCount = *(DWORD*)(dw0 + 0xC);
	////////	if (!nCount) return;

	////////	for (int kk = 0; kk < nCount; ++kk)
	////////	{
	////////		DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
	////////		if (dw3 == 0) continue;
	////////		KNpc *missileObj = (KNpc*)dw3;

	////////		if (IS_OBJ_DELETED(missileObj) == true)	 continue;
	////////		if (missileObj->nIndex < 0x3FFFFCC8)     continue;
	////////		if (OBJECT_TYPE(missileObj) != 1)		 continue;

	////////		if (CheckName("R_mis_beam_middle",missileObj->GetNameNpc()) && CheckName("Lux",missileObj->GetNameNpc()))
	////////		{
	////////			//KNpc* objHiu_XaNhat = 0;
	////////			//float max_KC        = 0;

	////////			//KNpc* objHiu_GanNhat = 0;
	////////			//float min_KC         = 999999;

	////////			KEnemyDistance phacHIU[2] = {0};
	////////			int tempCount_Hiu = 0;

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
	////////				KNpc *enemyHiu = (KNpc*)dwUnit3;
	////////				if (IS_DEAD(enemyHiu))    continue;
	////////				if (!IS_MINION(enemyHiu)) continue;
	////////				if (enemyHiu->nTeam_ID == myHero->nTeam_ID || enemyHiu->nTeam_ID == 0x12C)    continue;
	////////				if (!CheckName(enemyHiu->GetNameNpc(), "hiu")) continue;
	////////				if (!CheckNameEx(enemyHiu->GetNameHero(), "TestCubeRender")) continue;
	////////				
	////////				if (tempCount_Hiu < 2)
	////////				{
	////////					phacHIU[tempCount_Hiu].pEnemy = enemyHiu;
	////////					tempCount_Hiu += 1;
	////////				}
	////////				
	////////				//float distant = Distance(enemyHiu, enemyHero);
	////////				//if (distant > max_KC)
	////////				//{
	////////				//	max_KC = distant;
	////////				//	objHiu_XaNhat = enemyHiu;
	////////				//}
	////////				//if (distant < min_KC)
	////////				//{
	////////				//	min_KC = distant;
	////////				//	objHiu_GanNhat = enemyHiu;
	////////				//}
	////////			}

	////////			//if (objHiu_XaNhat != 0 && IsUnitInList(objHiu_XaNhat) && !IS_DEAD(objHiu_XaNhat) && objHiu_GanNhat != 0 && IsUnitInList(objHiu_GanNhat) && !IS_DEAD(objHiu_GanNhat))
	////////			if (phacHIU[0].pEnemy != 0 && IsUnitInList(phacHIU[0].pEnemy) && !IS_DEAD(phacHIU[0].pEnemy) && phacHIU[1].pEnemy != 0 && IsUnitInList(phacHIU[1].pEnemy) && !IS_DEAD(phacHIU[1].pEnemy))
	////////			{
	////////				//__oMsg("--LUX-YES-222:  %f", GetTimeGame());
	////////				std::string mis_Name("LuxR_Special");

	////////				std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
	////////				if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
	////////				{
	////////					Vec3D dir = (phacHIU[0].pEnemy->currentPos() - phacHIU[1].pEnemy->currentPos()).Normalized();
	////////					Vec3D pos1 = missileObj->currentPos() - dir * 1750;
	////////					Vec3D pos2 = missileObj->currentPos() + dir * 1750;

	////////					//it_onMissileSpells->second.range = Distance(pos1, pos2);
	////////					it_onMissileSpells->second.waitExtra = 150;

	////////					SpellData spellData = it_onMissileSpells->second;

	////////					Vec3D StartPos = pos1;
	////////					Vec3D EndPos   = pos2;

	////////					if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	////////					{
	////////						if (!IsCanSee(enemyHero))	
	////////						{
	////////							float missileLifeTime = spellData.projectileSpeed > 0 ? 555 +  spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;

	////////							if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////							{
	////////								__oMsg("---((***))----- LUX-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
	////////								CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
	////////								it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
	////////							}
	////////						}
	////////					}
	////////				}
	////////			}
	////////		}
	////////	}
	////////}	
}

//---------------------------------------------------------------------//--------------------//
void Evade_Jinx_W()
{
	//////if (DodgeFOWSpells_menu == false) return;

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
	//////	if (enemyHero->nTeam_ID == myHero->nTeam_ID)	 continue;
	//////	if (!CheckName(enemyHero->GetNameHero(), "Jinx")) continue;
	//////	if (IsCanSee(enemyHero)) continue;
	//////	//if (Distance(enemyHero, myHero) > 5000) continue;

	//////	//------//------//------:
	//////	DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
	//////	DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
	//////	if (!dw0) return;

	//////	DWORD dw1 = *(DWORD*)(dw0 + 8);
	//////	if (!dw1) return;

	//////	int nCount = *(DWORD*)(dw0 + 0xC);
	//////	if (!nCount) return;

	//////	for (int kk = 0; kk < nCount; ++kk)
	//////	{
	//////		DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
	//////		if (dw3 == 0) continue;
	//////		KNpc *missileObj = (KNpc*)dw3;

	//////		if (IS_OBJ_DELETED(missileObj) == true)	 continue;
	//////		if (missileObj->nIndex < 0x3FFFFCC8)     continue;
	//////		if (OBJECT_TYPE(missileObj) != 1)		 continue;

	//////		if (CheckName("_W_Beam", missileObj->GetNameNpc()) && CheckName("Jinx",missileObj->GetNameNpc()))	//Jinx_Base_W_Beam
	//////		{
	//////			//__oMsg("--Jinx-TimeGame:  %f", GetTimeGame());
	//////			std::string mis_Name("JinxW_Special");

	//////			std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
	//////			if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
	//////			{
	//////				SpellData spellData = it_onMissileSpells->second;

	//////				Vec3D StartPos = enemyHero->currentPos();
	//////				Vec3D EndPos   = GET_REAL_FACING_POS(enemyHero);

	//////				if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	//////				{
	//////					if (!IsCanSee(enemyHero))	
	//////					{
	//////						float missileLifeTime = spellData.projectileSpeed > 0 ? 555 +  spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;

	//////						if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	//////						{
	//////							//__oMsg("---((***))----- Jinx_W_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
	//////							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
	//////							it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
	//////						}
	//////					}
	//////				}
	//////			}
	//////		}
	//////	}
	//////}	
}

//---------------------------------------------------------------------//--------------------//
void Evade_Jhin_W()
{
	//////if (DodgeFOWSpells_menu == false) return;

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
	//////	if (enemyHero->nTeam_ID == myHero->nTeam_ID)	 continue;
	//////	if (!CheckName(enemyHero->GetNameHero(), "Jhin")) continue;
	//////	if (IsCanSee(enemyHero)) continue;
	//////	//if (Distance(enemyHero, myHero) > 5000) continue;

	//////	//------//------//------:
	//////	DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + G_Module;
	//////	DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
	//////	if (!dw0) return;

	//////	DWORD dw1 = *(DWORD*)(dw0 + 8);
	//////	if (!dw1) return;

	//////	int nCount = *(DWORD*)(dw0 + 0xC);
	//////	if (!nCount) return;

	//////	for (int kk = 0; kk < nCount; ++kk)
	//////	{
	//////		DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
	//////		if (dw3 == 0) continue;
	//////		KNpc *missileObj = (KNpc*)dw3;

	//////		if (IS_OBJ_DELETED(missileObj) == true)	 continue;
	//////		if (missileObj->nIndex < 0x3FFFFCC8)     continue;
	//////		if (OBJECT_TYPE(missileObj) != 1)		 continue;

	//////		if (CheckName("_W_indicator", missileObj->GetNameNpc()) && CheckName("Jhin",missileObj->GetNameNpc()))	//Jhin_Base_W_indicator
	//////		{
	//////			//__oMsg("--Jhin-TimeGame:  %f", GetTimeGame());
	//////			std::string mis_Name("JhinW_Special");

	//////			std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
	//////			if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
	//////			{
	//////				SpellData spellData = it_onMissileSpells->second;

	//////				Vec3D StartPos = enemyHero->currentPos();
	//////				Vec3D EndPos   = GET_REAL_FACING_POS(enemyHero);

	//////				if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
	//////				{
	//////					if (!IsCanSee(enemyHero))	
	//////					{
	//////						float missileLifeTime = spellData.projectileSpeed > 0 ? 555 +  spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;

	//////						if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	//////						{
	//////							//__oMsg("---((***))----- Jhin_W_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
	//////							CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
	//////							it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
	//////						}
	//////					}
	//////				}
	//////			}
	//////		}
	//////	}
	//////}	
}