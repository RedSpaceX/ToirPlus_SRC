//#include "DodgeMalphiteS.h"
//#include "SpellSpecial.h"
//#include "SpellDetector.h"
//
//
//extern SpellDetector* _SpellDetector;
////---------------------------------------------------------------------//--------------------//
//void Evade_Malphite_R()
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
//		if (!CheckName(enemyHero->GetNameHero(), "Malphite")) continue;
//		if (Distance(enemyHero, myHero) > 2500)				  continue;
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
//			if (CheckName("R_cas_",missileObj->GetNameNpc()) && CheckName("Malphite",missileObj->GetNameNpc()))	//"Malphite_Base_R_cas_trail"
//			{
//				if (IsDashing(enemyHero))
//				{
//					//__oMsg("--Malphite-TimeGame: %f", GetTimeGame());
//					std::string mis_Name("MalphiteR_Special");
//
//					std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//					if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//					{
//						SpellData spellData = it_onMissileSpells->second;
//
//						Vec3D StartPos = GET_START_POS(enemyHero);
//						Vec3D EndPos   = GET_END_POS(enemyHero);
//
//						if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							if(it_onMissileSpells->second.projectileSpeed == 0) continue;
//							float missileLifeTime = 888 + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed;
//
//							if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//							{
//								//__oMsg("---((***))----- Malphite_R_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//								CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//								it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//							}
//						}
//					}
//				}
//			}
//		}
//	}	
//}
//
////---------------------------------------------------------------------//--------------------//
//void Evade_Tryndamere_E()
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
//		if (!CheckName(enemyHero->GetNameHero(), "Tryndamere")) continue;
//		if (Distance(enemyHero, myHero) > 2500)				  continue;
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
//			if (CheckName("E_Slash_",missileObj->GetNameNpc()) && CheckName("Tryndamere",missileObj->GetNameNpc()))	
//			{
//				if (IsDashing(enemyHero))
//				{
//					//__oMsg("--Tryndamere-TimeGame: %f", GetTimeGame());
//					std::string mis_Name("TryndamereE_Special");
//
//					std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//					if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//					{
//						SpellData spellData = it_onMissileSpells->second;
//
//						Vec3D StartPos = GET_START_POS(enemyHero);
//						Vec3D EndPos   = GET_END_POS(enemyHero);
//
//						if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							if(it_onMissileSpells->second.projectileSpeed == 0) continue;
//							float missileLifeTime = 888 + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed;
//
//							if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//							{
//								//__oMsg("---((***))----- Tryndamere_E_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//								CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//								it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
////---------------------------------------------------------------------//--------------------//
//void Evade_Sejuani_Q()
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
//		if (!CheckName(enemyHero->GetNameHero(), "Sejuani")) continue;
//		if (Distance(enemyHero, myHero) > 2500)				  continue;
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
//			if (CheckName("_Q_cas",missileObj->GetNameNpc()) && CheckName("Sejuani",missileObj->GetNameNpc()))	
//			{
//				if (IsDashing(enemyHero))
//				{
//					//__oMsg("--Sejuani-TimeGame: %f", GetTimeGame());
//					std::string mis_Name("SejuaniQ_Special");
//
//					std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//					if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//					{
//						SpellData spellData = it_onMissileSpells->second;
//
//						Vec3D StartPos = GET_START_POS(enemyHero);
//						Vec3D EndPos   = GET_END_POS(enemyHero);
//
//						if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							if(it_onMissileSpells->second.projectileSpeed == 0) continue;
//							float missileLifeTime = 888 + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed;
//
//							if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//							{
//								//__oMsg("---((***))----- Sejuani_Q_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//								CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//								it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
////---------------------------------------------------------------------//--------------------//
//void Evade_Leblanc_W_WR()
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
//		if (!CheckName(enemyHero->GetNameHero(), "Leblanc")) continue;
//		if (Distance(enemyHero, myHero) > 2500)				  continue;
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
//			if (CheckName("_W_cas",missileObj->GetNameNpc()) && CheckName("LeBlanc",missileObj->GetNameNpc()))	//"LeBlanc_Skin04_W_cas"
//			{
//				if (IsDashing(enemyHero))
//				{
//					//__oMsg("--LeBlanc-TimeGame: %f", GetTimeGame());
//					std::string mis_Name("LeblancW_Special");
//
//					std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//					if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//					{
//						SpellData spellData = it_onMissileSpells->second;
//
//						Vec3D StartPos = GET_START_POS(enemyHero);
//						Vec3D EndPos   = GET_END_POS(enemyHero);
//
//						if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							if(it_onMissileSpells->second.projectileSpeed == 0) continue;
//							float missileLifeTime = 50 + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed;
//
//							if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//							{
//								//__oMsg("---((***))----- LeBlanc_W_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//								CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//								it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
////---------------------------------------------------------------------//--------------------//
//void Evade_Gragas_E()
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
//		if (!CheckName(enemyHero->GetNameHero(), "Gragas"))	continue;
//		if (Distance(enemyHero, myHero) > 2000)				continue;
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
//			if (CheckName("_E_Cas",missileObj->GetNameNpc()) && CheckName("Gragas",missileObj->GetNameNpc()))	//"LeBlanc_Skin04_W_cas"
//			{
//				if (IsDashing(enemyHero))
//				{
//					//__oMsg("--Gragas-TimeGame: %f", GetTimeGame());
//					std::string mis_Name("GragasE_Special");
//
//					std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//					if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//					{
//						SpellData spellData = it_onMissileSpells->second;
//
//						Vec3D StartPos = GET_START_POS(enemyHero);
//						Vec3D EndPos   = GET_END_POS(enemyHero);
//
//						if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							if(it_onMissileSpells->second.projectileSpeed == 0) continue;
//							float missileLifeTime = 555 + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed;
//
//							if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//							{
//								//__oMsg("---((***))----- Gragas_E_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//								CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//								it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}

////---------------------------------------------------------------------//--------------------//
//void Evade_Gnar_E()
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
//		if (!CheckName(enemyHero->GetNameHero(), "Gnar"))	continue;
//		if (Distance(enemyHero, myHero) > 2000)				continue;
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
//			if (CheckName("_E_Trail",missileObj->GetNameNpc()) && CheckName("Gnar",missileObj->GetNameNpc()))	//"LeBlanc_Skin04_W_cas"
//			{
//				if (IsDashing(enemyHero))
//				{
//					//__oMsg("--GnarE1-TimeGame: %f", GetTimeGame());
//					std::string mis_Name("GnarE1_Special");
//
//					std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//					if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//					{
//						SpellData spellData = it_onMissileSpells->second;
//
//						Vec3D StartPos = GET_START_POS(enemyHero);
//						Vec3D EndPos   = GET_END_POS(enemyHero);
//
//						if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//						{
//							float missileLifeTime = it_onMissileSpells->second.projectileSpeed > 0 ? 555 + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed : 1000;
//
//							if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//							{
//								//__oMsg("---((***))----- Gnar_E1_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//								CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//								it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//								return;
//							}
//						}
//					}
//				}
//			}
//		}
//
//		if (enemyHero->nOverrideCollisionRadius > 150 && IsDashing(enemyHero))	//E-2-BIG
//		{
//			//__oMsg("--GnarE22-TimeGame: %f", GetTimeGame());
//			std::string mis_Name("GnarE2_Special");
//
//			std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//			if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//			{
//				SpellData spellData = it_onMissileSpells->second;
//
//				Vec3D StartPos = GET_START_POS(enemyHero);
//				Vec3D EndPos   = GET_END_POS(enemyHero);
//
//				if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//				{
//					float missileLifeTime = it_onMissileSpells->second.projectileSpeed > 0 ? 555 + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed : 1000;
//
//					if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//					{
//						//__oMsg("---((***))----- Gnar_E2_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//						it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//						return;
//					}
//				}
//			}
//		}
//	}
//}
//
////---------------------------------------------------------------------//--------------------//
//void Evade_Shen_E()
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
//		if (!CheckName(enemyHero->GetNameHero(), "Shen"))	continue;
//		if (Distance(enemyHero, myHero) > 2000)				continue;
//
//		//------//------//------:
//		if (IsDashing(enemyHero))	
//		{
//			//__oMsg("--Shen-TimeGame: %f", GetTimeGame());
//			std::string mis_Name("ShenE_Special");
//
//			std::map<std::string, SpellData>::iterator it_onMissileSpells = _SpellDetector->onMissileSpells->find(str_tolower(mis_Name)); 
//			if (it_onMissileSpells != _SpellDetector->onMissileSpells->end())
//			{
//				SpellData spellData = it_onMissileSpells->second;
//
//				Vec3D StartPos = GET_START_POS(enemyHero);
//				Vec3D EndPos   = GET_END_POS(enemyHero);
//
//				if (StartPos.IsValid() && EndPos.IsValid() && StartPos.Distance2D(myHero->currentPos()) < spellData.range + 1000)
//				{
//					float missileLifeTime = it_onMissileSpells->second.projectileSpeed > 0 ? 555 + 1000*it_onMissileSpells->second.range/it_onMissileSpells->second.projectileSpeed : 1000;
//
//					if ((float)GetTickCount() - it_onMissileSpells->second.lastCreateMissileTime > missileLifeTime)
//					{
//						//__oMsg("---((***))----- Shen_E_CREATE-MISSLE-11111: MissileNam: %s, KC_Missile = %.3f",mis_Name.c_str(), StartPos.Distance2D(EndPos));
//						CreateSpellData(enemyHero, StartPos, EndPos, spellData, 0, 0);
//						it_onMissileSpells->second.lastCreateMissileTime = (float)GetTickCount();
//						return;
//					}
//				}
//			}
//		}
//	}
//}