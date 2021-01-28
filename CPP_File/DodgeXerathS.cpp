#include "DodgeXerathS.h"
#include "SpellSpecial.h"
#include "SpellDetector.h"


extern SpellDetector* _SpellDetector;
extern bool DodgeFOWSpells_menu;
//---------------------------------------------------------------------//--------------------//
//////float lastXerathQ = 0;
void Evade_Xerath_Q_1(KNpc* hero, KCastSpell* spellCast, SpellData spellData)
{
	////////if (spellData.spellName.compare("XerathArcanopulse2") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;
	////////if (G_Module == 0) return;

	////////if (!IsCanSee(hero)) return;
	////////if (Distance(hero, myHero) > 2500) return;

	//////////------//------//------:
	////////Vec3D StartPos(spellCast->SourcePos.x , spellCast->SourcePos.y , spellCast->SourcePos.z);
	////////Vec3D EndPos  (spellCast->MaxDestPos.x, spellCast->MaxDestPos.y, spellCast->MaxDestPos.z);
	////////
	////////spellData.range = StartPos.Distance2D(EndPos) + 25;

	//////////__oMsg("---((***))----- XERATH-Q1Special-OnProcesSpell-11111: KC_Missile = %.3f, range: %f", StartPos.Distance2D(EndPos), spellData.range);
	////////CreateSpellData(hero, StartPos, EndPos, spellData);
	////////lastXerathQ = (float)GetTickCount();
}

//---------------------------------------------------------------------//--------------------//
void Evade_Xerath_Q_2()
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
	////////	if (enemyHero->nTeam_ID == myHero->nTeam_ID)		continue;
	////////	if (!IsCanSee(enemyHero))							continue;		//FOW nhung ban' 1 cai no hien xerath roi
	////////	if (Distance(enemyHero, myHero) > 2500)				continue;
	////////	if (!CheckName(enemyHero->GetNameHero(), "Xerath")) continue;
	////////	
	////////	//------//------//------:
	////////	KNpc* objHiu_XaNhat = 0;
	////////	float max_KC        = 0;

	////////	DWORD tempUnit    = BASE_AttackableUnit		- TEMP_ENTRY_POINT + G_Module;
	////////	DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	////////	DWORD dwUnit1 = *(DWORD*)tempUnit;
	////////	DWORD dwUnit2 = *(DWORD*)tempUnitMax;
	////////	if (!dwUnit1 || !dwUnit2 ) return;
	////////	int countUnit = (dwUnit2 - dwUnit1)/4;
	////////	for (int iii = 0; iii < countUnit; ++iii)
	////////	{
	////////		DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*iii);
	////////		if (dwUnit3 == 0) continue;
	////////		KNpc *enemyHiu = (KNpc*)dwUnit3;
	////////		if (enemyHiu->nIsTargetableToTeam == 4)	 continue;
	////////		if (IS_DEAD(enemyHiu))    continue;
	////////		if (!IS_MINION(enemyHiu)) continue;
	////////		if (enemyHiu->nTeam_ID == myHero->nTeam_ID || enemyHiu->nTeam_ID == 0x12C)    continue;
	////////		if (Distance(myHero, enemyHiu) > 2500)				continue;
	////////		if (!CheckName(enemyHiu->GetNameNpc(), "hiu")) continue;
	////////		if (!CheckNameEx(enemyHiu->GetNameHero(), "TestCubeRender10Vision")) continue;

	////////		float distant = Distance(enemyHiu, enemyHero);
	////////		if (distant > max_KC)
	////////		{
	////////			max_KC = distant;
	////////			objHiu_XaNhat = enemyHiu;
	////////		}
	////////	}
	////////	
	////////	if (objHiu_XaNhat != 0 && IsUnitInList(objHiu_XaNhat) && !IS_DEAD(objHiu_XaNhat) /*&& objHiu_GanNhat != 0 && IsUnitInList(objHiu_GanNhat) && !IS_DEAD(objHiu_GanNhat)*/)
	////////	{
	////////		std::string mis_Name("XerathQ_Special");

	////////		std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
	////////		if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
	////////		{
	////////			it_onMissileSpells->second.range = max_KC + 25;
	////////			SpellData spellData = it_onMissileSpells->second;

	////////			Vec3D StartPos = enemyHero->currentPos();
	////////			Vec3D EndPos   = objHiu_XaNhat->currentPos();
	////////			

	////////			if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 888)
	////////			{
	////////				float missileLifeTime = 999;

	////////				if ((float)GetTickCount() - lastXerathQ > missileLifeTime)
	////////				{
	////////					//__oMsg("---((***))----- XERATH-Q2-OnTick-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
	////////					CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
	////////					lastXerathQ = (float)GetTickCount();
	////////				}
	////////			}
	////////		}
	////////	}
	////////}	
}

//---------------------------------------------------------------------//--------------------//
void Evade_Xerath_R(KNpc* missileObj, SpellData &spellData)
{
	////////if (spellData.missileName.compare("XerathLocusPulse") != 0) return;

	////////KNpc* myHero = GetPlayer();
	////////if (!myHero) return;
	////////if (G_Module == 0) return;

	////////
	//////////------//------//------:
	////////KNpc* hero = (KNpc*)GetObjectByID(missileObj->nMissileOwnerID_1);
	////////if (hero)
	////////{
	////////	Vec3D start (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
	////////	Vec3D end   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 

	////////	spellData.range = start.Distance2D(end) + 5;

	////////	float missileLifeTime = spellData.projectileSpeed > 0 ? spellData.spellDelay + 185 : 1000;

	////////	if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
	////////	{
	////////		if (start.Distance2D(myHero->currentPos()) < spellData.range + 1500)
	////////		{
	////////			//__oMsg("---((*11.1: %.3f))----- XeRac_R_CREATE-MISSLE-11111: KC_Missile = %.3f (%.3f) - delay: %f", GetTimeGame(), start.Distance2D(end), Distance(myHero, hero),spellData.spellDelay);
	////////			CreateSpellData(hero, start, end, spellData);

	////////			spellData.lastCreateMissileTime = (float)GetTickCount();
	////////		}
	////////	}
	////////}
}

////---------------------------------------------------------------------//--------------------//
//void Evade_Xerath_Q()
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
//		if (!CheckName(enemyHero->GetNameHero(), "Xerath")) continue;
//		if (Distance(enemyHero, myHero) > 2500) continue;
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
//			if (CheckName("Q_cas_charge",missileObj->GetNameNpc()) && CheckName("Xerath",missileObj->GetNameNpc()))
//			{
//				KNpc* objHiu_XaNhat = 0;
//				float max_KC        = 0;
//
//				//KNpc* objHiu_GanNhat = 0;
//				//float min_KC         = 999999;
//
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
//					KNpc *enemyHiu = (KNpc*)dwUnit3;
//					if (IS_DEAD(enemyHiu))    continue;
//					if (!IS_MINION(enemyHiu)) continue;
//					if (enemyHiu->nTeam_ID == myHero->nTeam_ID || enemyHiu->nTeam_ID == 0x12C)    continue;
//					if (!CheckName(enemyHiu->GetNameNpc(), "hiu")) continue;
//					if (!CheckNameEx(enemyHiu->GetNameHero(), "TestCubeRender10Vision")) continue;
//
//					float distant = Distance(enemyHiu, enemyHero);
//					if (distant > max_KC)
//					{
//						max_KC = distant;
//						objHiu_XaNhat = enemyHiu;
//					}
//					/*if (distant < min_KC)
//					{
//						min_KC = distant;
//						objHiu_GanNhat = enemyHiu;
//					}*/
//				}
//
//				if (objHiu_XaNhat != 0 && IsUnitInList(objHiu_XaNhat) && !IS_DEAD(objHiu_XaNhat) /*&& objHiu_GanNhat != 0 && IsUnitInList(objHiu_GanNhat) && !IS_DEAD(objHiu_GanNhat)*/)
//				{
//					//__oMsg("--Xerath-YES-222: %f - %f", max_KC, GetTimeGame());
//					std::string mis_Name("XerathQ_Special");
//
//					std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//					if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//					{
//						it_onMissileSpells->second.range = max_KC + 25;
//						SpellData spellData = it_onMissileSpells->second;
//
//						//Vec3D StartPos = objHiu_GanNhat->currentPos();
//						Vec3D StartPos = enemyHero->currentPos();
//						Vec3D EndPos   = objHiu_XaNhat->currentPos();
//
//						if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 888)
//						{
//							//if (IsCanSee(enemyHero))	//xerath ko can cai nay
//							{
//								//--------------------------------:
//								if(it_onMissileSpells->second.projectileSpeed == 0) continue;
//								float missileLifeTime = 888 + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed;
//
//								if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//								{
//									//__oMsg("---((***))----- XERATH-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//									CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//									it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}	
//}

////---------------------------------------------------------------------//--------------------//
//void Evade_Xerath_W()
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
//		if (!CheckName(enemyHero->GetNameHero(), "Xerath")) continue;
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
//			if (spell_name.compare("XerathArcaneBarrage2") != 0) continue;		
//
//			if (GetTimeGame() - args->nTime_DanBatDauBay <= 2.0f && GetTimeGame() - args->nTime_DanBatDauBay > 0.08f) continue;
//
//			//------//------//------:
//			std::string Special_name("XerathW_Special");
//			std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
//			if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//			{
//				SpellData spellData = it_onProcessSpells->second;
//
//				Vec3D StartPos(args->SourcePos.x, args->SourcePos.y, args->SourcePos.z);
//				Vec3D EndPos(args->MaxDestPos.x, args->MaxDestPos.y, args->MaxDestPos.z);
//			
//				if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
//				{
//					float missileLifeTime = spellData.projectileSpeed > 0 ? 888 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//					if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//					{
//						//__oMsg("---((*11*))----- Xeratth-W-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",spell_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//						it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
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
//				if (OBJECT_TYPE(missileObj) != 1)		 continue;
//
//				if (CheckName("_W_aoe", missileObj->GetNameNpc()) && CheckName("Xerath", missileObj->GetNameNpc()) && !CheckName("W_aoe_explosion", missileObj->GetNameNpc()))	//Xerath_Base_W_aoe_green , Xerath_Base_W_aoe_explosion
//				{
//					//------//------//------:
//					std::string Special_name("XerathW_Special");
//					std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(Special_name)); 
//					if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//					{
//						SpellData spellData = it_onProcessSpells->second;
//						
//						spellData.waitExtra = 0;
//						Vec3D EndPos   = missileObj->currentPos();
//						Vec3D StartPos = Extend(EndPos, myHero->currentPos(), -spellData.range);
//
//						if (StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000 )
//						{
//							float missileLifeTime = spellData.projectileSpeed > 0 ? 1555 + spellData.spellDelay + 1000*spellData.range/spellData.projectileSpeed : 1000;
//
//							if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//							{
//								//__oMsg("---((*22*))----- Xeratth_W_FOW-CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f - delay: %f",Special_name.c_str(), StartPos.Distance2D(EndPos), spellData.spellDelay);
//								it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//
//								CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}

////---------------------------------------------------------------------//--------------------//
//void Evade_Xerath_R()
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
//		if (!CheckName(enemyHero->GetNameHero(), "Xerath")) continue;
//		//if (Distance(enemyHero, myHero) > 8000) continue;
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
//			if (CheckName("XerathLocusPulse",missileObj->GetNameNpc()))
//			{
//				//------//------//------:
//				std::string spellSpecial("XerathR_Special");
//				std::map<std::string, SpellData>::iterator it_onProcessSpells = _SpellDetector->onProcessSpells->find(str_tolower(spellSpecial)); 
//				if (it_onProcessSpells != _SpellDetector->onProcessSpells->end())
//				{
//					Vec3D start (missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z);
//					Vec3D end   (missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z); 
//
//					SpellData spellData  = it_onProcessSpells->second;
//					spellData.range = start.Distance2D(end) + 25;
//
//					//spellData.spellDelay = 50 + 1000 * start.Distance2D(end)/spellData.projectileSpeed;
//					float missileLifeTime = spellData.projectileSpeed > 0 ? spellData.spellDelay /*+ 1000*spellData.range/spellData.projectileSpeed*/ : 1000;
//
//					if ((float)GetTickCount() - spellData.lastCreateMissileTime > missileLifeTime)
//					{
//						if (end.Distance2D(myHero->currentPos()) < spellData.range + 1500)
//						{
//							//__oMsg("---((*11.1: %.3f))----- XeRac_R_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f (%.3f) - delay: %f", GetTimeGame(), spellSpecial.c_str(), start.Distance2D(end), Distance(myHero, enemyHero),spellData.spellDelay);
//							CreateSpellData(enemyHero, start, end, spellData);
//
//							it_onProcessSpells->second.lastCreateMissileTime = (float)GetTickCount();
//						}
//					}
//				}
//			}
//		}
//	}	
//}