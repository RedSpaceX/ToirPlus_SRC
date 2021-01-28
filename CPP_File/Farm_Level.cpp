#include "Farm_Level.h"

KPos Home1_Pos(400.0, 172.0, 460.0);		// can check ky 2 toa do nay
KPos Home2_Pos(14340.0, 180.0, 14390.0);	// can check ky 2 toa do nay
KPos GiuaManHinh_Pos(7460.0,54.0,7376.0);	// can check ky 2 toa do nay
float nTime_Buy_Item = 0;
//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IS_TEAM_1()
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD offsetNexus = NEXUS - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return false;
	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return false;
	BYTE isDied = IS_DEAD(pPlayer) ? 1 : 0;
	if (isDied != 0) return false;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pNpc = (KNpc*)dw3;
		int isDie = IS_DEAD(pNpc) == true ? 1 : 0;
		//if (!pNpc->IsAlly(pPlayer->nTeam_ID) || pNpc->nIs_Nexus != (int)offsetNexus || isDie == 1 || pNpc->nHP <= 0.)
		if (!pNpc->IsAlly(pPlayer->nTeam_ID) || IS_NEXUS(pNpc) == false || isDie == 1 || pNpc->nHP <= 0)
			continue;
		float nDistance = Distance_3D(Home1_Pos, pNpc->CurrentPos);
		if(nDistance < 2500.0)
		{
			return true;
		}
	}
	return false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IS_TEAM_2()
{
	return false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KNpc* GET_ENEMY_TURRET(char* sz_HeroName, float nRange)
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return NULL;
	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	BYTE isDied = IS_DEAD(pPlayer) ? 1 : 0;
	if (isDied != 0) return NULL;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyTurret = (KNpc*)dw3;
		int isDie = IS_DEAD(pEnemyTurret) ? 1 : 0;
		if (!pEnemyTurret->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pEnemyTurret->nHP <= 0. || !IS_TURRET(pEnemyTurret))
			continue;
		if (CheckName( (sz__Turret), pEnemyTurret->GetNameNpc()) == false) continue;
		if (CheckName(sz_HeroName, pEnemyTurret->GetNameHero()) == false) continue;
		float fdistance = Distance_3D(GiuaManHinh_Pos, pEnemyTurret->CurrentPos);
		if (fdistance > nRange) continue;
		//__oMsg("%s   : fdistance: %f", pEnemyTurret->GetNameHero(), fdistance);
		return pEnemyTurret;
	}
	return NULL;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KNpc* GET_ALLY_TURRET(char* sz_HeroName, float nRange)
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return NULL;
	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return NULL;
	BYTE isDied = IS_DEAD(pPlayer) ? 1 : 0;
	if (isDied != 0) return NULL;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyTurret = (KNpc*)dw3;
		int isDie = IS_DEAD(pEnemyTurret) ? 1 : 0;
		if (pEnemyTurret->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pEnemyTurret->nHP <= 0. || !IS_TURRET(pEnemyTurret))
			continue;
		if (CheckName( (sz__Turret), pEnemyTurret->GetNameNpc()) == false) continue;
		if (CheckName(sz_HeroName, pEnemyTurret->GetNameHero()) == false) continue;
		float fdistance = Distance_3D(GiuaManHinh_Pos, pEnemyTurret->CurrentPos);
		if (fdistance > nRange) continue;
		//__oMsg("%s   : fdistance: %f", pEnemyTurret->GetNameHero(), fdistance);
		return pEnemyTurret;
	}
	return NULL;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KNpc* GET_ENEMY_INHIBITOR(float nRange)  // so voi diem Giua_ManHinh
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	//DWORD offsetInhibitor = INHIBITOR - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return NULL;
	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return NULL;
	BYTE isDied = IS_DEAD(pPlayer) ? 1 : 0;
	if (isDied != 0) return NULL;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pNpc = (KNpc*)dw3;
		int isDie = IS_DEAD(pNpc) == true ? 1 : 0;
		if (!pNpc->IsEnemy(pPlayer->nTeam_ID) || !IS_INHIBITOR(pNpc) || isDie == 1 || pNpc->nHP <= 0)
			continue;
		if(pNpc->nIsTargetableToTeam != 4) continue;
		float fdistance = Distance_3D(GiuaManHinh_Pos, pNpc->CurrentPos);
		if (fdistance > nRange) continue;
		//__oMsg("%s   : fdistance: %f", pNpc->GetNameHero(), fdistance);
		return pNpc;
	}
	return NULL;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KNpc* GET_ENEMY_NEXUS(float nRange)
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD offsetNexus = NEXUS - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return NULL;
	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return NULL;
	BYTE isDied = IS_DEAD(pPlayer) ? 1 : 0;
	if (isDied != 0) return NULL;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pNpc = (KNpc*)dw3;
		int isDie = IS_DEAD(pNpc) == true ? 1 : 0;
		//if (!pNpc->IsEnemy(pPlayer->nTeam_ID) || pNpc->nIs_Nexus != (int)offsetNexus || isDie == 1 || pNpc->nHP <= 0.)
		if (!pNpc->IsEnemy(pPlayer->nTeam_ID) || IS_NEXUS(pNpc) == false || isDie == 1 || pNpc->nHP <= 0)
			continue;
		if(pNpc->nIsTargetableToTeam != 4) continue;
		float fdistance = Distance_3D(GiuaManHinh_Pos, pNpc->CurrentPos);
		if (fdistance > nRange) continue;
		//__oMsg("%s   : fdistance: %f", pNpc->GetNameHero(), fdistance);
		return pNpc;
	}
	return NULL;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
float nTime2EndGame = 0;
void DoEndGame()
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_ENDGAME = BASE_ENDGAME - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_ENDGAME;
	if(!dw1) return;
	EndGame* tmp = (EndGame*)dw1;
	//if(!dw1) return;
	//__oMsg("end end: %d", (BYTE)tmp->nGiaTri);
	if((BYTE)tmp->nGiaTri == 3 /*|| dw1 == 4*/)
	{
		//__oMsg("truoc:%d; tmp=%d", dw1, tmp->nGiaTri);
		nTime2EndGame += SYS_TIMER;
		if(nTime2EndGame > 3180.0)
		{
			nTime2EndGame = 0;
			//dw1 = 4;
			tmp->nGiaTri = 4;
			//exit(-1);
			//ExitProcess(0);
		}
		//__oMsg("sau:%d; tmp=%d", dw1, tmp->nGiaTri);
	}
}
//==================================================================================//
//==================================================================================//
//==================================================================================//
float nTime_UpLevel = 0;
bool  ADC_AUTO_UP_LEVEL()
{
	KNpc* pPlayer = GetPlayer();
	if(!pPlayer) return false;
	nTime_UpLevel += SYS_TIMER;
	if(nTime_UpLevel < 3000.0) return false;
	bool nResult = false;
	if(CheckName(pPlayer->GetNameHero(),  (sz__Ashe)) || 
	   CheckName(pPlayer->GetNameHero(),  (sz__Ezreal)))
	{
		if((BYTE)pPlayer->nLevel == 1 || (BYTE)pPlayer->nLevel == 3 || (BYTE)pPlayer->nLevel == 5 || (BYTE)pPlayer->nLevel == 8 || (BYTE)pPlayer->nLevel == 10)
		{
			nResult = UP_LEVEL(SKILL_Q);
			nTime_UpLevel = 0;
		}
		if((BYTE)pPlayer->nLevel == 2 || (BYTE)pPlayer->nLevel == 4 || (BYTE)pPlayer->nLevel == 7 || (BYTE)pPlayer->nLevel == 9 || (BYTE)pPlayer->nLevel == 12)
		{
			nResult = UP_LEVEL(SKILL_W);
			nTime_UpLevel = 0;
		}
		if((BYTE)pPlayer->nLevel == 13 || (BYTE)pPlayer->nLevel == 14 || (BYTE)pPlayer->nLevel == 15 || (BYTE)pPlayer->nLevel == 17 || (BYTE)pPlayer->nLevel == 18)
		{
			nResult = UP_LEVEL(SKILL_E);
			nTime_UpLevel = 0;
		}
		if((BYTE)pPlayer->nLevel == 6 || (BYTE)pPlayer->nLevel == 11 || (BYTE)pPlayer->nLevel == 16)
		{
			nResult = UP_LEVEL(SKILL_R);
			nTime_UpLevel = 0;
		}
	}
	else if(CheckName(pPlayer->GetNameHero(),  (sz__Corki)))	//-- CORKI -----
	{
		if((BYTE)pPlayer->nLevel == 1 || (BYTE)pPlayer->nLevel == 3 || (BYTE)pPlayer->nLevel == 5 || (BYTE)pPlayer->nLevel == 8 || (BYTE)pPlayer->nLevel == 10)
		{
			nResult = UP_LEVEL(SKILL_Q);
			nTime_UpLevel = 0;
		}
		if((BYTE)pPlayer->nLevel == 2 || (BYTE)pPlayer->nLevel == 4 || (BYTE)pPlayer->nLevel == 7 || (BYTE)pPlayer->nLevel == 9 || (BYTE)pPlayer->nLevel == 12)
		{
			nResult = UP_LEVEL(SKILL_E);
			nTime_UpLevel = 0;
		}
		if((BYTE)pPlayer->nLevel == 13 || (BYTE)pPlayer->nLevel == 14 || (BYTE)pPlayer->nLevel == 15 || (BYTE)pPlayer->nLevel == 17 || (BYTE)pPlayer->nLevel == 18)
		{
			nResult = UP_LEVEL(SKILL_W);
			nTime_UpLevel = 0;
		}
		if((BYTE)pPlayer->nLevel == 6 || (BYTE)pPlayer->nLevel == 11 || (BYTE)pPlayer->nLevel == 16)
		{
			nResult = UP_LEVEL(SKILL_R);
			nTime_UpLevel = 0;
		}
	}
	else if(CheckName(pPlayer->GetNameHero(),  (sz__Annie)))	//-- ANNIE -----
	{
		if((BYTE)pPlayer->nLevel == 1 || (BYTE)pPlayer->nLevel == 4 || (BYTE)pPlayer->nLevel == 7 || (BYTE)pPlayer->nLevel == 9 || (BYTE)pPlayer->nLevel == 12)
		{
			nResult = UP_LEVEL(SKILL_Q);
			nTime_UpLevel = 0;
		}
		if((BYTE)pPlayer->nLevel == 2 || (BYTE)pPlayer->nLevel == 5 || (BYTE)pPlayer->nLevel == 8 || (BYTE)pPlayer->nLevel == 10 || (BYTE)pPlayer->nLevel == 13)
		{
			nResult = UP_LEVEL(SKILL_W);
			nTime_UpLevel = 0;
		}
		if((BYTE)pPlayer->nLevel == 3 || (BYTE)pPlayer->nLevel == 14 || (BYTE)pPlayer->nLevel == 15 || (BYTE)pPlayer->nLevel == 17 || (BYTE)pPlayer->nLevel == 18)
		{
			nResult = UP_LEVEL(SKILL_E);
			nTime_UpLevel = 0;
		}
		if((BYTE)pPlayer->nLevel == 6 || (BYTE)pPlayer->nLevel == 11 || (BYTE)pPlayer->nLevel == 16)
		{
			nResult = UP_LEVEL(SKILL_R);
			nTime_UpLevel = 0;
		}
	}
	else
	{
		if((BYTE)pPlayer->nLevel == 1 || (BYTE)pPlayer->nLevel == 4 || (BYTE)pPlayer->nLevel == 8 || (BYTE)pPlayer->nLevel == 12 || (BYTE)pPlayer->nLevel == 15)
		{
			nResult = UP_LEVEL(SKILL_Q);
			nTime_UpLevel = 0;
		}
		if((BYTE)pPlayer->nLevel == 2 || (BYTE)pPlayer->nLevel == 5 || (BYTE)pPlayer->nLevel == 9 || (BYTE)pPlayer->nLevel == 13 || (BYTE)pPlayer->nLevel == 17)
		{
			nResult = UP_LEVEL(SKILL_W);
			nTime_UpLevel = 0;
		}
		if((BYTE)pPlayer->nLevel == 3 || (BYTE)pPlayer->nLevel == 7 || (BYTE)pPlayer->nLevel == 10 || (BYTE)pPlayer->nLevel == 14 || (BYTE)pPlayer->nLevel == 18)
		{
			nResult = UP_LEVEL(SKILL_E);
			nTime_UpLevel = 0;
		}
		if((BYTE)pPlayer->nLevel == 6 || (BYTE)pPlayer->nLevel == 11 || (BYTE)pPlayer->nLevel == 16)
		{
			nResult = UP_LEVEL(SKILL_R);
			nTime_UpLevel = 0;
		}
	}
	return nResult;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool CHECK_AND_BUY_ITEM()
{
	KNpc* pPlayer = GetPlayer();
	if(!pPlayer) return false;
	bool nIs_BienVe = true;

	float nGold = pPlayer->nGold;
	nTime_Buy_Item += SYS_TIMER;
	if(nTime_Buy_Item < 1500.0) return false;
	if(CheckName(pPlayer->GetNameHero(),  (sz__Ezreal)))
	{
		if(!GET_ITEM(ITEM_LamNgoc_ID) && !GET_ITEM(ITEM_NuocMat_ID) && !GET_ITEM(ITEM_KiemMuRa_ID) && !GET_ITEM(ITEM_ThanKiemMuRa_ID))// mua LamNgoc
		{
			BUY_ITEM(ITEM_LamNgoc_ID);
			nTime_Buy_Item = 0;
			//return false;
		}
		if(GET_ITEM(ITEM_LamNgoc_ID) && !GET_ITEM(ITEM_NuocMat_ID) && !GET_ITEM(ITEM_KiemMuRa_ID) && !GET_ITEM(ITEM_ThanKiemMuRa_ID))// mua NuocMat
		{
			if(nGold > 400.0)
			{
				BUY_ITEM(ITEM_NuocMat_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if((GET_ITEM(ITEM_NuocMat_ID) || GET_ITEM(ITEM_KiemMuRa_ID) || GET_ITEM(ITEM_ThanKiemMuRa_ID)) && !GET_ITEM(ITEM_ThuyKiem_ID) && !GET_ITEM(ITEM_GangTayBangGia_ID))// mua ThuyKiem
		{
			if(nGold > 1050.0)
			{
				BUY_ITEM(ITEM_ThuyKiem_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if((GET_ITEM(ITEM_NuocMat_ID) || GET_ITEM(ITEM_KiemMuRa_ID) || GET_ITEM(ITEM_ThanKiemMuRa_ID)) && GET_ITEM(ITEM_ThuyKiem_ID) && !GET_ITEM(ITEM_GangTayBangGia_ID))// mua GangTayBangGia
		{
			if(nGold > 1650.0)
			{
				BUY_ITEM(ITEM_GangTayBangGia_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if(GET_ITEM(ITEM_NuocMat_ID) && GET_ITEM(ITEM_GangTayBangGia_ID) &&!GET_ITEM(ITEM_KiemMuRa_ID)  && !GET_ITEM(ITEM_ThanKiemMuRa_ID))// mua ThanKiemMuRa
		{
			if((nGold > 1650.0 && !GET_ITEM(ITEM_CuocChim_ID)) || (nGold > 775.0 && GET_ITEM(ITEM_CuocChim_ID)))
			{
				BUY_ITEM(ITEM_KiemMuRa_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
			if(nGold > 875.0 && !GET_ITEM(ITEM_CuocChim_ID))
			{
				BUY_ITEM(ITEM_CuocChim_ID);
				nTime_Buy_Item = 0;
				return false;
			}
		}
		if((GET_ITEM(ITEM_KiemMuRa_ID) || GET_ITEM(ITEM_ThanKiemMuRa_ID)) && GET_ITEM(ITEM_GangTayBangGia_ID) && !GET_ITEM(ITEM_GIAY_Lonia_ID))	// mua Giay
		{
			if(nGold > 900.0)
			{
				BUY_ITEM(ITEM_GIAY_Lonia_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if((GET_ITEM(ITEM_KiemMuRa_ID) || GET_ITEM(ITEM_ThanKiemMuRa_ID)) && GET_ITEM(ITEM_GangTayBangGia_ID) && GET_ITEM(ITEM_GIAY_Lonia_ID) && !GET_ITEM(ITEM_KiemHaiTac_ID) && !GET_ITEM(ITEM_GUOM_VO_DANH_ID))	// mua KiemHaiTac
		{
			if(nGold > 1500.0)
			{
				BUY_ITEM(ITEM_KiemHaiTac_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if((GET_ITEM(ITEM_KiemMuRa_ID) || GET_ITEM(ITEM_ThanKiemMuRa_ID)) && GET_ITEM(ITEM_GangTayBangGia_ID) && GET_ITEM(ITEM_GIAY_Lonia_ID) && GET_ITEM(ITEM_KiemHaiTac_ID)
			&& !GET_ITEM(ITEM_GUOM_VO_DANH_ID))	// mua Guom VoDanh
		{
			if(nGold > 1900.0)
			{
				BUY_ITEM(ITEM_GUOM_VO_DANH_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if((GET_ITEM(ITEM_KiemMuRa_ID) || GET_ITEM(ITEM_ThanKiemMuRa_ID)) && GET_ITEM(ITEM_GangTayBangGia_ID) && GET_ITEM(ITEM_GIAY_Lonia_ID)
			&& GET_ITEM(ITEM_GUOM_VO_DANH_ID) && !GET_ITEM(ITEM_NO_THAN_ID))	// mua NoThan
		{
			if(nGold > 2700.0)
			{
				BUY_ITEM(ITEM_NO_THAN_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if((GET_ITEM(ITEM_KiemMuRa_ID) || GET_ITEM(ITEM_ThanKiemMuRa_ID)) && GET_ITEM(ITEM_GangTayBangGia_ID) && GET_ITEM(ITEM_GIAY_Lonia_ID)
			&& GET_ITEM(ITEM_GUOM_VO_DANH_ID) && GET_ITEM(ITEM_NO_THAN_ID) && !GET_ITEM(ITEM_CUONG_CUNG_ID))	// mua CuongCung
		{
			if(nGold > 2600.0)
			{
				if(GET_ITEM(ITEM_KIEM_DORAN_ID))
				{
					SELL_ITEM(ITEM_KIEM_DORAN_ID);
					nTime_Buy_Item = 0;
					return nIs_BienVe;
				}
				BUY_ITEM(ITEM_CUONG_CUNG_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
	}
	else if(CheckName(pPlayer->GetNameHero(),  (sz__Corki)))// DUNG CHO CORKI
	{
		if((BYTE)pPlayer->nLevel < 6)	//mua Kiem-Doran
		{
			if(!GET_ITEM(ITEM_KIEM_DORAN_ID))
			{
				BUY_ITEM(ITEM_KIEM_DORAN_ID);
				nTime_Buy_Item = 0;
				return false;
			}
		}
		if(!GET_ITEM(ITEM_KiemRangCua_ID) && !GET_ITEM(ITEM_ChuyGai_ID))	// KiemRangCua
		{
			if((nGold > 1300.0 && !GET_ITEM(ITEM_AoVai_ID)) || (nGold > 850.0 && GET_ITEM(ITEM_AoVai_ID)))
			{
				BUY_ITEM(ITEM_KiemRangCua_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
			if(nGold > 450.0 && !GET_ITEM(ITEM_AoVai_ID))
			{
				BUY_ITEM(ITEM_AoVai_ID);
				nTime_Buy_Item = 0;
				return false;
			}
		}
		if(GET_ITEM(ITEM_KiemRangCua_ID) && !GET_ITEM(ITEM_ChuyGai_ID) && !GET_ITEM(ITEM_ThuyKiem_ID) && !GET_ITEM(ITEM_TamHopKiem_ID))// mua ThuyKiem
		{
			if(nGold > 1050.0)
			{
				BUY_ITEM(ITEM_ThuyKiem_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if(GET_ITEM(ITEM_KiemRangCua_ID) && !GET_ITEM(ITEM_ChuyGai_ID) && GET_ITEM(ITEM_ThuyKiem_ID) 
			&& !GET_ITEM(ITEM_TamHopKiem_ID))// mua TamHopKiem
		{
			if((nGold > 2683.0 && !GET_ITEM(ITEM_KiemChich_ID)) || (nGold > 1583.0 && GET_ITEM(ITEM_KiemChich_ID)))
			{
				BUY_ITEM(ITEM_TamHopKiem_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
			if(nGold > 1100.0 && !GET_ITEM(ITEM_KiemChich_ID))
			{
				BUY_ITEM(ITEM_KiemChich_ID);
				nTime_Buy_Item = 0;
				return false;
			}
		}
		if(GET_ITEM(ITEM_TamHopKiem_ID) && GET_ITEM(ITEM_KiemRangCua_ID) 
			&& !GET_ITEM(ITEM_ChuyGai_ID))	// mua ChuyGai
		{
			if(nGold > 1950.0)
			{
				BUY_ITEM(ITEM_ChuyGai_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if(GET_ITEM(ITEM_TamHopKiem_ID) && GET_ITEM(ITEM_ChuyGai_ID) 
			&& !GET_ITEM(ITEM_GIAY_PhapSu_ID))	// mua Giay phap su
		{
			if(nGold > 1100.0)
			{
				BUY_ITEM(ITEM_GIAY_PhapSu_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if(GET_ITEM(ITEM_TamHopKiem_ID) && GET_ITEM(ITEM_ChuyGai_ID) && GET_ITEM(ITEM_GIAY_PhapSu_ID) 
			&& !GET_ITEM(ITEM_KIEM_BF_ID) && !GET_ITEM(ITEM_VOCUCKIEM_ID))	// mua KiemBF
		{
			if(nGold > 1300.0)
			{
				BUY_ITEM(ITEM_KIEM_BF_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if(GET_ITEM(ITEM_TamHopKiem_ID) && GET_ITEM(ITEM_ChuyGai_ID) && GET_ITEM(ITEM_GIAY_PhapSu_ID)&& GET_ITEM(ITEM_KIEM_BF_ID) 
			&& !GET_ITEM(ITEM_VOCUCKIEM_ID))	// mua voCuc
		{
			if((nGold > 2300.0 && !GET_ITEM(ITEM_AoChoangTim_ID)) || (nGold > 1500.0 && GET_ITEM(ITEM_AoChoangTim_ID)))
			{
				BUY_ITEM(ITEM_VOCUCKIEM_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
			if(nGold > 800.0 && !GET_ITEM(ITEM_AoChoangTim_ID))
			{
				BUY_ITEM(ITEM_AoChoangTim_ID);
				nTime_Buy_Item = 0;
				return false;
			}
		}
		if(GET_ITEM(ITEM_TamHopKiem_ID) && GET_ITEM(ITEM_ChuyGai_ID) && GET_ITEM(ITEM_GIAY_PhapSu_ID) && GET_ITEM(ITEM_VOCUCKIEM_ID) 
			&& !GET_ITEM(ITEM_LuoiHaiTuThan_ID))	// mua LuoiHaiTuThan
		{
			if(nGold > 3600.0)
			{
				BUY_ITEM(ITEM_LuoiHaiTuThan_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}

		if(GET_ITEM(ITEM_TamHopKiem_ID) && GET_ITEM(ITEM_ChuyGai_ID) && GET_ITEM(ITEM_GIAY_PhapSu_ID) && GET_ITEM(ITEM_VOCUCKIEM_ID) 
			&& GET_ITEM(ITEM_LuoiHaiTuThan_ID) && !GET_ITEM(ITEM_NO_THAN_ID))	// mua NoThan
		{
			if(nGold > 2700.0)
			{
				if(GET_ITEM(ITEM_KIEM_DORAN_ID))
				{
					SELL_ITEM(ITEM_KIEM_DORAN_ID);
					nTime_Buy_Item = 0;
					return nIs_BienVe;
				}
				BUY_ITEM(ITEM_NO_THAN_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
	}
	else if(IS_ADC(pPlayer))		//=== Dung cho da so AD Carry ============ ADC-ADC =============
	{
		if((BYTE)pPlayer->nLevel < 6)	//mua Kiem-Doran
		{
			if(!GET_ITEM(ITEM_KIEM_DORAN_ID))
			{
				BUY_ITEM(ITEM_KIEM_DORAN_ID);
				nTime_Buy_Item = 0;
				return false;
			}
		}
		if(!GET_ITEM(ITEM_KiemRangCua_ID) && !GET_ITEM(ITEM_ChuyGai_ID))	// KiemRangCua
		{
			if((nGold > 1300.0 && !GET_ITEM(ITEM_AoVai_ID)) || (nGold > 850.0 && GET_ITEM(ITEM_AoVai_ID)))
			{
				BUY_ITEM(ITEM_KiemRangCua_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
			if(nGold > 450.0 && !GET_ITEM(ITEM_AoVai_ID))
			{
				BUY_ITEM(ITEM_AoVai_ID);
				nTime_Buy_Item = 0;
				return false;
			}
		}
		if(GET_ITEM(ITEM_KiemRangCua_ID) && !GET_ITEM(ITEM_ChuyGai_ID) && !GET_ITEM(ITEM_KIEM_BF_ID) && !GET_ITEM(ITEM_VOCUCKIEM_ID))	// mua KiemBF
		{
			if(nGold > 1300.0)
			{
				BUY_ITEM(ITEM_KIEM_BF_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if(GET_ITEM(ITEM_KiemRangCua_ID) && !GET_ITEM(ITEM_ChuyGai_ID) && GET_ITEM(ITEM_KIEM_BF_ID) 
			&& !GET_ITEM(ITEM_VOCUCKIEM_ID))	// mua voCuc
		{
			if((nGold > 2300.0 && !GET_ITEM(ITEM_AoChoangTim_ID)) || (nGold > 1500.0 && GET_ITEM(ITEM_AoChoangTim_ID)))
			{
				BUY_ITEM(ITEM_VOCUCKIEM_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
			if(nGold > 800.0 && !GET_ITEM(ITEM_AoChoangTim_ID))
			{
				BUY_ITEM(ITEM_AoChoangTim_ID);
				nTime_Buy_Item = 0;
				return false;
			}
		}
		if(GET_ITEM(ITEM_KiemRangCua_ID) && !GET_ITEM(ITEM_ChuyGai_ID) && GET_ITEM(ITEM_VOCUCKIEM_ID) 
			&& !GET_ITEM(ITEM_GIAY_CUONGNO_ID))	// mua Giay Cuong No
		{
			if(nGold > 1100.0)
			{
				BUY_ITEM(ITEM_GIAY_CUONGNO_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		//if(GET_ITEM(ITEM_KiemRangCua_ID) && !GET_ITEM(ITEM_ChuyGai_ID) && GET_ITEM(ITEM_VOCUCKIEM_ID) && GET_ITEM(ITEM_GIAY_CUONGNO_ID)
		//	&& !GET_ITEM(ITEM_CUNG_GO_ID) && !GET_ITEM(ITEM_CUONG_CUNG_ID))	// mua cung go khi chua co CungGo va CuongCung
		//{
		//	if(nGold > 1000.0)
		//	{
		//		BUY_ITEM(ITEM_CUNG_GO_ID);
		//		nTime_Buy_Item = 0;
		//		return nIs_BienVe;
		//	}
		//}
		if(GET_ITEM(ITEM_KiemRangCua_ID) && !GET_ITEM(ITEM_ChuyGai_ID) && GET_ITEM(ITEM_VOCUCKIEM_ID) && GET_ITEM(ITEM_GIAY_CUONGNO_ID)
			/*&& GET_ITEM(ITEM_CUNG_GO_ID)*/ && !GET_ITEM(ITEM_CUONG_CUNG_ID))	// mua CuongCung
		{
			if((nGold > 2600.0 && !GET_ITEM(ITEM_SongKiem_ID)) || (nGold > 1400.0 && GET_ITEM(ITEM_SongKiem_ID)))
			{
				BUY_ITEM(ITEM_CUONG_CUNG_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
			if(nGold > 1200.0 && !GET_ITEM(ITEM_SongKiem_ID))
			{
				BUY_ITEM(ITEM_SongKiem_ID);
				nTime_Buy_Item = 0;
				return false;
			}
		}
		if(GET_ITEM(ITEM_KiemRangCua_ID) && GET_ITEM(ITEM_VOCUCKIEM_ID) && GET_ITEM(ITEM_GIAY_CUONGNO_ID) && GET_ITEM(ITEM_CUONG_CUNG_ID)  
		    && !GET_ITEM(ITEM_ChuyGai_ID))	// mua ChuyGai
		{
			if(nGold > 1950.0)
			{
				BUY_ITEM(ITEM_ChuyGai_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if(GET_ITEM(ITEM_CUONG_CUNG_ID) && GET_ITEM(ITEM_ChuyGai_ID) && GET_ITEM(ITEM_GIAY_CUONGNO_ID) && GET_ITEM(ITEM_VOCUCKIEM_ID)
			&& !GET_ITEM(ITEM_NO_THAN_ID))	// mua NoThan
		{
			if(nGold > 2700.0)
			{
				BUY_ITEM(ITEM_NO_THAN_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if(GET_ITEM(ITEM_CUONG_CUNG_ID) && GET_ITEM(ITEM_ChuyGai_ID) && GET_ITEM(ITEM_VOCUCKIEM_ID) && GET_ITEM(ITEM_GIAY_CUONGNO_ID) && GET_ITEM(ITEM_NO_THAN_ID)
			&& !GET_ITEM(ITEM_GUOM_VO_DANH_ID))	// mua Guom VoDanh
		{
			if(nGold > 3400.0)
			{
				if(GET_ITEM(ITEM_KIEM_DORAN_ID))
				{
					SELL_ITEM(ITEM_KIEM_DORAN_ID);
					nTime_Buy_Item = 250;
					return nIs_BienVe;
				}
				BUY_ITEM(ITEM_GUOM_VO_DANH_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		
	}
	else	// DUNG CHO TAT CA AP ============ AP-AP =============
	{
		if((BYTE)pPlayer->nLevel < 6)	//mua Nhan-Doran
		{
			if(!GET_ITEM(ITEM_Nhan_DORAN_ID))
			{
				BUY_ITEM(ITEM_Nhan_DORAN_ID);
				nTime_Buy_Item = 0;
				return false;
			}
		}
		if(!GET_ITEM(ITEM_CocHaiHoa_ID) && !GET_ITEM(ITEM_CocQuyAthe_ID))	// Coc HaiHoa
		{
			if(nGold > 800.0)
			{
				BUY_ITEM(ITEM_CocHaiHoa_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if(GET_ITEM(ITEM_CocHaiHoa_ID) && !GET_ITEM(ITEM_CocQuyAthe_ID))	// Coc Quy Athe
		{
			if(nGold > 1300.0)
			{
				BUY_ITEM(ITEM_CocQuyAthe_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if(GET_ITEM(ITEM_CocQuyAthe_ID) && !GET_ITEM(ITEM_DaVinhHang_ID) && !GET_ITEM(ITEM_TruongTruongSinh_ID))	// mua Da Vinh Hang
		{
			if(nGold > 1100.0)
			{
				BUY_ITEM(ITEM_DaVinhHang_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
			
		}
		if(GET_ITEM(ITEM_CocQuyAthe_ID) && GET_ITEM(ITEM_DaVinhHang_ID) && !GET_ITEM(ITEM_TruongTruongSinh_ID))	// mua TruongTruongSinh
		{
			if(nGold > 1600.0)
			{
				BUY_ITEM(ITEM_TruongTruongSinh_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if(GET_ITEM(ITEM_CocQuyAthe_ID) && GET_ITEM(ITEM_TruongTruongSinh_ID) && !GET_ITEM(ITEM_GIAY_PhapSu_ID))	// mua Giay Phap Su
		{
			if(nGold > 1100.0)
			{
				BUY_ITEM(ITEM_GIAY_PhapSu_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
		if(GET_ITEM(ITEM_CocQuyAthe_ID) && GET_ITEM(ITEM_TruongTruongSinh_ID) && GET_ITEM(ITEM_GIAY_PhapSu_ID) 
			&& !GET_ITEM(ITEM_QuyThuMore_ID))	// mua QuyThu Morelo
		{
			if((nGold > 2900.0 && !GET_ITEM(ITEM_SachQuy_ID)) || (nGold > 2000.0 && GET_ITEM(ITEM_SachQuy_ID)))
			{
				BUY_ITEM(ITEM_QuyThuMore_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
			if(nGold > 900.0 && !GET_ITEM(ITEM_SachQuy_ID))
			{
				BUY_ITEM(ITEM_SachQuy_ID);
				nTime_Buy_Item = 0;
				return false;
			}
		}
		if(GET_ITEM(ITEM_CocQuyAthe_ID) && GET_ITEM(ITEM_TruongTruongSinh_ID) && GET_ITEM(ITEM_GIAY_PhapSu_ID) && GET_ITEM(ITEM_QuyThuMore_ID)
			&& !GET_ITEM(ITEM_MuPhuThuy_ID))	// mua MuPhuThuy
		{
			if((nGold > 3800.0 && !GET_ITEM(ITEM_GayQuaKho_ID)) || (nGold > 2550.0 && GET_ITEM(ITEM_GayQuaKho_ID)))
			{
				BUY_ITEM(ITEM_MuPhuThuy_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
			if(nGold > 1250.0 && !GET_ITEM(ITEM_GayQuaKho_ID))
			{
				BUY_ITEM(ITEM_GayQuaKho_ID);
				nTime_Buy_Item = 0;
				return false;
			}
		}
		if(GET_ITEM(ITEM_CocQuyAthe_ID) && GET_ITEM(ITEM_TruongTruongSinh_ID) && GET_ITEM(ITEM_GIAY_PhapSu_ID) && GET_ITEM(ITEM_QuyThuMore_ID)
			&& GET_ITEM(ITEM_MuPhuThuy_ID) && !GET_ITEM(ITEM_TRUONG_HU_VO_ID))	// ban Nhan doran - Mua Truong HuVo
		{
			if(nGold > 2650.0)
			{
				if(GET_ITEM(ITEM_Nhan_DORAN_ID))
				{
					SELL_ITEM(ITEM_Nhan_DORAN_ID);
					nTime_Buy_Item = 0;
					return nIs_BienVe;
				}
				BUY_ITEM(ITEM_TRUONG_HU_VO_ID);
				nTime_Buy_Item = 0;
				return nIs_BienVe;
			}
		}
	}

	return false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
extern bool g_bNormalAttackHero;
extern bool g_bClearLane;
extern float g_DelayNormalAttack;
extern float g_tDelay;
extern bool g_IsDodging;
int m_nKillTurret_01_Step = 0;
int m_nKillTurret_02_Step = 0;
int m_nKillTurret_03_Step = 0;
int m_nKillTurret_04_Step = 0;
float nTime_NextStep = 0;
float nTime_Wait_LinhDanh = 0;
float TIME_NEXTSTEP = 500.0;
float nFarm_TickStart, nFarm_TickEnd = 0;
void Farm_Level()
{
//////	//return;
//////	DoEndGame();
//////	KNpc* pPlayer = GetPlayer();
//////	if(!pPlayer) return;
//////	if(IS_DEAD(pPlayer)) return;
//////	ADC_AUTO_UP_LEVEL();
//////	if(g_IsDodging) return;
//////
//////	if(1 == 1)
//////	{
//////		float nPercent_HP = 100*pPlayer->nHP/pPlayer->nMaxHP;
//////		float nPercent_MP = 100*pPlayer->nMP/pPlayer->nMaxMP;
////////----- Mua Item neu chet || gan nha -------------------------------------
//////		float nKC_BuyItem = Distance_3D(Home1_Pos, pPlayer->CurrentPos);
//////		if(!IS_TEAM_1()) nKC_BuyItem = Distance_3D(Home2_Pos, pPlayer->CurrentPos);
//////		if(IS_DEAD(pPlayer) || nKC_BuyItem < 1000.0)
//////		{
//////			CHECK_AND_BUY_ITEM();
//////			m_nKillTurret_01_Step = 0;
//////			m_nKillTurret_02_Step = 0;
//////			m_nKillTurret_03_Step = 0;
//////			m_nKillTurret_04_Step = 0;
//////		}
//////		if(nKC_BuyItem < 1000.0 && (nPercent_HP < 85.0 || nPercent_MP < 85.0)) return;	// doi hoi mau-mana day moi len
//////
//////		KNpc*			     pAllyTurret_xxx = GET_ALLY_TURRET( (sz__SRUAP_Turret_Order1), 2200.0);
//////		if(!pAllyTurret_xxx) pAllyTurret_xxx = GET_ALLY_TURRET( (sz__SRUAP_Turret_Order2), 4000.0);
//////		if(!pAllyTurret_xxx) pAllyTurret_xxx = GET_ALLY_TURRET( (sz__SRUAP_Turret_Order3), 5500.0);
//////		if(!pAllyTurret_xxx) pAllyTurret_xxx = GET_ALLY_TURRET( (sz__SRUAP_Turret_Order4), 8000.0);
//////		if(!IS_TEAM_1())
//////		{
//////								 pAllyTurret_xxx = GET_ALLY_TURRET( (sz__SRUAP_Turret_Chaos1), 2200.0);
//////			if(!pAllyTurret_xxx) pAllyTurret_xxx = GET_ALLY_TURRET( (sz__SRUAP_Turret_Chaos2), 4000.0);
//////			if(!pAllyTurret_xxx) pAllyTurret_xxx = GET_ALLY_TURRET( (sz__SRUAP_Turret_Chaos3), 5500.0);
//////			if(!pAllyTurret_xxx) pAllyTurret_xxx = GET_ALLY_TURRET( (sz__SRUAP_Turret_Chaos4), 8000.0);
//////		}
////////===== Tru 1 chua chet =====================================================
//////		KNpc* pEnemyTurret_1 = GET_ENEMY_TURRET( (sz__SRUAP_Turret_Chaos1), 2200.0);
//////		if(!IS_TEAM_1())
//////		{
//////			pEnemyTurret_1 = GET_ENEMY_TURRET( (sz__SRUAP_Turret_Order1), 2200.0);
//////		}
//////		
//////		KPos GiuaManHinh_Pos_NEW(7346,54,7056);
//////		if(!IS_TEAM_1())
//////		{
//////			//KPos GiuaManHinh_Pos_NEW(7616.0,53.3,7764.0);
//////			GiuaManHinh_Pos_NEW.x = 7594;
//////			GiuaManHinh_Pos_NEW.y = 53;
//////			GiuaManHinh_Pos_NEW.z = 7768;
//////		}
//////		KPos POS_ATK_1;
//////		if(pEnemyTurret_1)
//////		{
//////			KPos pos1, pos2;
//////			//TIM_DIEM_CACH_1DIEM(pos1, pos2, GiuaManHinh_Pos, pEnemyTurret_1->CurrentPos, 785.0);// cu~
//////			TIM_DIEM_CACH_1DIEM(pos1, pos2, GiuaManHinh_Pos_NEW, pEnemyTurret_1->CurrentPos, 950);
//////			float nKC1 = Distance_2D(pos1, pEnemyTurret_1->CurrentPos);
//////			float nKC2 = Distance_2D(pos2, pEnemyTurret_1->CurrentPos);
//////			if(nKC1 > nKC2)	 POS_ATK_1 = pos2;
//////			else			 POS_ATK_1 = pos1;
//////			
//////			float nKC_Player2_GiuaManHinh = Distance_3D(pPlayer->CurrentPos, GiuaManHinh_Pos_NEW);
//////			float nKC_Player2_POSATK1     = Distance_3D(pPlayer->CurrentPos, POS_ATK_1);
//////			
//////			if(m_nKillTurret_01_Step == 0) //--- danh o diem GiuaManHinh --------------
//////			{
//////				if(nPercent_HP < 20.0 || CHECK_AND_BUY_ITEM())	////-- ve khi het mau || co tien mua do ----
//////				{
//////					m_nKillTurret_01_Step = 3;
//////					return;
//////				}
//////				nTime_Wait_LinhDanh += SYS_TIMER;
//////				int counMinionATK = CountMinionAttack(pPlayer);
//////				int counHeroATK   = CountNPCAttack(pPlayer);
//////				if(counMinionATK >= 3 || (counMinionATK + counHeroATK >= 2)
//////				   ||(CountEnemyPlayerInRange(1000.0) > Count_AllyPlayer_Around_NPC(pPlayer, 1000.0) + 1)) //-- chay khi nhieu linh danh ---
//////				{
//////					nFarm_TickStart = (float)GetTickCount();
//////					if(pAllyTurret_xxx)
//////					{
//////						//__oMsg("-- bi 2 thang linh danh --- Step: %d [ng %d - linh %d]", m_nKillTurret_01_Step , g_bNormalAttackHero, g_bClearLane);
//////						MOVE_TO(pAllyTurret_xxx->CurrentPos.x, pAllyTurret_xxx->CurrentPos.z);
//////						nTime_Wait_LinhDanh = 0;
//////						g_bClearLane = false;
//////						g_bNormalAttackHero = false;
//////						return;
//////					}
//////				}
//////				if(nKC_Player2_GiuaManHinh > 450.0 && !CountEnemyMinionInRange(500.0)) //-- quay lai GiuaManHinh_Pos_NEW ---
//////				{
//////					nFarm_TickEnd = (float)GetTickCount();
//////					if(g_tDelay >= 400.0 && g_DelayNormalAttack > 400.0 && nFarm_TickEnd - nFarm_TickStart >= 1000.0)
//////					{
//////						//__oMsg("TRO LAI GiuaManHinh - Step: %d [ng %d - linh %d]", m_nKillTurret_01_Step , g_bNormalAttackHero, g_bClearLane);
//////						MOVE_TO(GiuaManHinh_Pos_NEW.x, GiuaManHinh_Pos_NEW.z);
//////						nTime_NextStep = 0;
//////						return;
//////					}
//////				}
//////				if(CountEnemyPlayerInRange(pPlayer->nAttackRange + 100) /*&& CountEnemyMinionInRange(700.0) < 3*/ && nTime_Wait_LinhDanh >= 750) //-- co TuongDich ----
//////				{
//////					g_bClearLane = false;
//////					g_bNormalAttackHero = true;
//////					nTime_NextStep = 0;
//////					return;
//////				}
//////				if(CountEnemyMinionInRange(pPlayer->nAttackRange + 100) && nTime_Wait_LinhDanh >= 750) //-- co LinhDich ----
//////				{
//////					g_bNormalAttackHero = false;
//////					g_bClearLane = true;
//////					nTime_NextStep = 0;
//////					return;
//////				}
//////
//////				KNpc *virtualNPC = new KNpc;
//////				virtualNPC->CurrentPos = POS_ATK_1;
//////				if(Count_AllyMinion_Around_NPC(virtualNPC, 650.0) >= 2 && !Count_EnemyPlayer_Around_NPC(virtualNPC, 650.0))
//////				{
//////					nTime_NextStep += SYS_TIMER;
//////					if(nTime_NextStep >= TIME_NEXTSTEP)
//////					{
//////						//__oMsg("Next-Step - Step: %d", m_nKillTurret_01_Step);
//////						m_nKillTurret_01_Step = 1;
//////					}
//////				}
//////				//delete virtualNPC;
//////			}
//////			else if(m_nKillTurret_01_Step == 1) //--- danh o diem POS_ATK_1 --------------
//////			{
//////				if(nPercent_HP < 20.0 || CHECK_AND_BUY_ITEM())	////-- ve khi het mau || co tien mua do ----
//////				{
//////					m_nKillTurret_01_Step = 3;
//////					return;
//////				}
//////				nTime_Wait_LinhDanh += SYS_TIMER;
//////				int counMinionATK = CountMinionAttack(pPlayer);
//////				int counHeroATK   = CountNPCAttack(pPlayer);
//////				if(counMinionATK >= 3 || (counMinionATK + counHeroATK >= 2)
//////					||(CountEnemyPlayerInRange(1000.0) > Count_AllyPlayer_Around_NPC(pPlayer, 1000.0) + 1)) //-- chay khi nhieu linh danh ---
//////				{
//////					if(pAllyTurret_xxx)
//////					{
//////						//__oMsg("-- bi 2 thang linh danh --- Step: %d [ng %d - linh %d]", m_nKillTurret_01_Step , g_bNormalAttackHero, g_bClearLane);
//////						MOVE_TO(pAllyTurret_xxx->CurrentPos.x, pAllyTurret_xxx->CurrentPos.z);
//////						m_nKillTurret_01_Step = 0;
//////						nTime_Wait_LinhDanh = 0;
//////						g_bClearLane = false;
//////						g_bNormalAttackHero = false;
//////						return;
//////					}
//////				}
//////
//////				KNpc *virtualNPC = new KNpc;
//////				virtualNPC->CurrentPos = POS_ATK_1;
//////				if(Count_EnemyPlayer_Around_NPC(virtualNPC, 450.0) || Count_EnemyMinion_Around_NPC(virtualNPC, 500.0) >= 3)
//////				{
//////					nTime_NextStep += SYS_TIMER;
//////					if(nTime_NextStep >= TIME_NEXTSTEP)
//////					{
//////						//__oMsg("Down-Step DOWN DOWN DOWN DOWN - Step: %d", m_nKillTurret_01_Step);
//////						m_nKillTurret_01_Step = 0;
//////					}
//////				}
//////				//delete virtualNPC;
//////
//////				//if(nKC_Player2_POSATK1 > 185.0 ||IsEnemyTurretInRange(1075.0)) //-- quay lai POS_ATK_1 ---
//////				if(nKC_Player2_POSATK1 > 375.0 ||IsEnemyTurretInRange(1130.0)) //-- quay lai POS_ATK_1 ---
//////				{
//////					if(g_tDelay >= 400 && g_DelayNormalAttack > 400)
//////					{
//////						//__oMsg("TRO LAI POS_ATK_1 - Step: %d [ng %d - linh %d]", m_nKillTurret_01_Step , g_bNormalAttackHero, g_bClearLane);
//////						MOVE_TO(POS_ATK_1.x, POS_ATK_1.z);
//////						nTime_NextStep = 0;
//////						return;
//////					}
//////				}
//////				if(CountEnemyPlayerInRange(pPlayer->nAttackRange + 100) /*&& CountEnemyMinionInRange(700.0) < 3*/ && !IsEnemyTurretInRange(1075.0) && nTime_Wait_LinhDanh >= 750) //-- co TuongDich va ko Gan tru dich ----
//////				{
//////					g_bClearLane = false;
//////					g_bNormalAttackHero = true;
//////					nTime_NextStep = 0;
//////					return;
//////				}
//////				if(CountEnemyMinionInRange(pPlayer->nAttackRange + 100) && nTime_Wait_LinhDanh >= 750)
//////				{
//////					//-- co LinhDich ----
//////					g_bNormalAttackHero = false;
//////					g_bClearLane = true;
//////				}
//////				if(Count_AllyMinion_Around_NPC(pEnemyTurret_1, 875.0) >= 3 && !Count_EnemyPlayer_Around_NPC(pEnemyTurret_1, 1100.0))
//////				{
//////				//-- danh tru -----
//////					m_nKillTurret_01_Step = 2;
//////					g_bClearLane = false;
//////					g_bNormalAttackHero = false;
//////					return;
//////				}
//////			}
//////			else if(m_nKillTurret_01_Step == 2) //--- Danh Tru --------------
//////			{
//////				if(g_tDelay >= 400.0)
//////				{
//////					if(CheckName(pPlayer->GetNameHero(),  (sz__Ashe)))
//////					{
//////						if(CanCastSpell2(SKILL_Q) == 0)
//////						{
//////							ASHE_DO_SKILL_Q(pPlayer);
//////						}
//////					}
//////					NormalAttack(pEnemyTurret_1);
//////					g_tDelay = 0;
//////				}
//////				if(Count_AllyMinion_Around_NPC(pEnemyTurret_1, 875.0) < 3 || Count_EnemyPlayer_Around_NPC(pEnemyTurret_1, 1100.0))
//////				{
//////					m_nKillTurret_01_Step = 1;
//////					g_bClearLane = false;
//////					return;
//////				}
//////			}
//////			else if(m_nKillTurret_01_Step == 3) //--- ve nha khi het mau --------------
//////			{
//////				if(pAllyTurret_xxx)
//////				{
//////					float nKC = Distance_3D(pAllyTurret_xxx->CurrentPos, pPlayer->CurrentPos);
//////					if(nKC > 300.0)
//////					{
//////						MOVE_TO(pAllyTurret_xxx->CurrentPos.x, pAllyTurret_xxx->CurrentPos.z);
//////						return;
//////					}
//////					DO_RECALL_SKILL();
//////				}
//////			}
//////				
//////		}
//////
////////===== Tru 2 chua chet =====================================================
//////		KNpc* pEnemyTurret_2 = GET_ENEMY_TURRET( (sz__SRUAP_Turret_Chaos2), 4000.0);
//////		if(!IS_TEAM_1())
//////		{
//////			pEnemyTurret_2 = GET_ENEMY_TURRET( (sz__SRUAP_Turret_Order2), 4000.0);
//////		}
//////		KPos POS_ATK_2;
//////		if(!pEnemyTurret_1 && pEnemyTurret_2)
//////		{
//////			KPos pos1, pos2;
//////			//TIM_DIEM_CACH_1DIEM(pos1, pos2, GiuaManHinh_Pos, pEnemyTurret_2->CurrentPos, 2425.0); //cu~
//////			TIM_DIEM_CACH_1DIEM(pos1, pos2, GiuaManHinh_Pos_NEW, pEnemyTurret_2->CurrentPos, 2615.0);
//////			float nKC1 = Distance_2D(pos1, pEnemyTurret_2->CurrentPos);
//////			float nKC2 = Distance_2D(pos2, pEnemyTurret_2->CurrentPos);
//////			if(nKC1 > nKC2)	 POS_ATK_2 = pos2;
//////			else			 POS_ATK_2 = pos1;
//////			
//////			float nKC_Player2_GiuaManHinh = Distance_3D(pPlayer->CurrentPos, GiuaManHinh_Pos_NEW);
//////			float nKC_Player2_POSATK2     = Distance_3D(pPlayer->CurrentPos, POS_ATK_2);
//////		
//////			if(m_nKillTurret_02_Step == 0) //--- danh o diem POS_ATK_2 --------------
//////			{
//////				if(nPercent_HP < 15.0 || CHECK_AND_BUY_ITEM())	////-- ve khi het mau || co tien mua do ----
//////				{
//////					m_nKillTurret_02_Step = 2;
//////					return;
//////				}
//////				nTime_Wait_LinhDanh += SYS_TIMER;
//////				int counMinionATK = CountMinionAttack(pPlayer);
//////				//int counHeroATK   = CountNPCAttack(pPlayer);
//////				if(counMinionATK >= 3 /*|| (counMinionATK + counHeroATK >= 2)*/
//////					||(CountEnemyPlayerInRange(1000.0) > Count_AllyPlayer_Around_NPC(pPlayer, 1000.0) + 1)) //-- chay khi nhieu linh danh ---
//////				{
//////					nFarm_TickStart = (float)GetTickCount();
//////					if(pAllyTurret_xxx)
//////					{
//////						//__oMsg("-- bi 3 thang linh danh --- tru2-step : %d", m_nKillTurret_02_Step);
//////						MOVE_TO(pAllyTurret_xxx->CurrentPos.x, pAllyTurret_xxx->CurrentPos.z);
//////						nTime_Wait_LinhDanh = 0;
//////						g_bClearLane = false;
//////						g_bNormalAttackHero = false;
//////						return;
//////					}
//////				}
//////				//if((nKC_Player2_POSATK2 > 200.0 && !CountEnemyMinionInRange(500.0) && !CountEnemyPlayerInRange(500.0)) || IsEnemyTurretInRange(1085.0)) //-- quay lai POS_ATK_2 ---
//////				if((nKC_Player2_POSATK2 > 350.0 && !CountEnemyMinionInRange(575.0) && !CountEnemyPlayerInRange(575.0)) || IsEnemyTurretInRange(1100.0)) //-- quay lai POS_ATK_2 ---
//////				{
//////					nFarm_TickEnd = (float)GetTickCount();
//////					if(g_tDelay >= 400.0 && g_DelayNormalAttack > 400.0 && nFarm_TickEnd - nFarm_TickStart >= 1000.0)
//////					{
//////						//__oMsg("TRO LAI POS_ATK_2 - tru2-Step: %d", m_nKillTurret_02_Step);
//////						MOVE_TO(POS_ATK_2.x, POS_ATK_2.z);
//////						nTime_NextStep = 0;
//////						return;
//////					}
//////				}
//////				if(CountEnemyPlayerInRange(pPlayer->nAttackRange + 100) && !IsEnemyTurretInRange(1100.0) && nTime_Wait_LinhDanh >= 1000.0) //-- co TuongDich va ko Gan tru dich ----
//////				{
//////					g_bClearLane = false;
//////					g_bNormalAttackHero = true;
//////					nTime_NextStep = 0;
//////					nTime_Wait_LinhDanh = 0;
//////					return;
//////				}
//////				if(CountEnemyMinionInRange(pPlayer->nAttackRange + 100) && nTime_Wait_LinhDanh >= 1000.0) //-- co LinhDich ----
//////				{
//////					g_bClearLane = true;
//////					nTime_Wait_LinhDanh = 0;
//////				}
//////				if(Count_AllyMinion_Around_NPC(pEnemyTurret_2, 875.0) >= 3 
//////				   && (!Count_EnemyPlayer_Around_NPC(pEnemyTurret_2, 1100.0) || (Count_EnemyPlayer_Around_NPC(pEnemyTurret_2, 1100.0) && !Count_EnemyPlayer_Around_NPC(pPlayer, 1400.0)))
//////				  )
//////				{
//////					//-- danh tru -----
//////					m_nKillTurret_02_Step = 1;
//////					g_bClearLane = false;
//////					g_bNormalAttackHero = false;
//////					return;
//////				}
//////			}
//////			else if(m_nKillTurret_02_Step == 1) //--- Danh Tru --------------
//////			{
//////				if(g_tDelay >= 400.0)
//////				{
//////					if(CheckName(pPlayer->GetNameHero(),  (sz__Ashe)))
//////					{
//////						if(CanCastSpell2(SKILL_Q) == 0)
//////						{
//////							ASHE_DO_SKILL_Q(pPlayer);
//////						}
//////					}
//////					NormalAttack(pEnemyTurret_2);
//////					g_tDelay = 0;
//////				}
//////				if(Count_AllyMinion_Around_NPC(pEnemyTurret_2, 875.0) < 3 || (Count_EnemyPlayer_Around_NPC(pEnemyTurret_2, 1100.0) && Count_EnemyPlayer_Around_NPC(pPlayer, 1100.0)))
//////				{
//////					m_nKillTurret_02_Step = 0;
//////					g_bClearLane = false;
//////					return;
//////				}
//////			}
//////			else if(m_nKillTurret_02_Step == 2) //--- ve nha khi het mau --------------
//////			{
//////				if(pAllyTurret_xxx)
//////				{
//////					float nKC = Distance_3D(pAllyTurret_xxx->CurrentPos, pPlayer->CurrentPos);
//////					if(nKC > 300.0)
//////					{
//////						MOVE_TO(pAllyTurret_xxx->CurrentPos.x, pAllyTurret_xxx->CurrentPos.z);
//////						return;
//////					}
//////					DO_RECALL_SKILL();
//////				}
//////			}
//////		}
////////===== Tru 3 chua chet =====================================================
//////		KNpc* pEnemyTurret_3 = GET_ENEMY_TURRET( (sz__SRUAP_Turret_Chaos3), 5500.0);
//////		if(!IS_TEAM_1())
//////		{
//////			pEnemyTurret_3 = GET_ENEMY_TURRET( (sz__SRUAP_Turret_Order3), 5500.0);
//////		}
//////		KPos POS_ATK_3;
//////		if(!pEnemyTurret_1 && !pEnemyTurret_2 && pEnemyTurret_3)
//////		{
//////			KPos pos1, pos2;
//////			//TIM_DIEM_CACH_1DIEM(pos1, pos2, GiuaManHinh_Pos, pEnemyTurret_3->CurrentPos, 4175.0);
//////			TIM_DIEM_CACH_1DIEM(pos1, pos2, GiuaManHinh_Pos_NEW, pEnemyTurret_3->CurrentPos, 4390.0);
//////			float nKC1 = Distance_2D(pos1, pEnemyTurret_3->CurrentPos);
//////			float nKC2 = Distance_2D(pos2, pEnemyTurret_3->CurrentPos);
//////			if(nKC1 > nKC2)	 POS_ATK_3 = pos2;
//////			else			 POS_ATK_3 = pos1;
//////			
//////			float nKC_Player2_GiuaManHinh = Distance_3D(pPlayer->CurrentPos, GiuaManHinh_Pos_NEW);
//////			float nKC_Player2_POSATK3     = Distance_3D(pPlayer->CurrentPos, POS_ATK_3);
//////
//////			if(m_nKillTurret_03_Step == 0) //--- danh o diem POS_ATK_2 --------------
//////			{
//////				if(nPercent_HP < 15.0 || CHECK_AND_BUY_ITEM())	////-- ve khi het mau || co tien mua do ----
//////				{
//////					m_nKillTurret_03_Step = 2;
//////					return;
//////				}
//////				nTime_Wait_LinhDanh += SYS_TIMER;
//////				if((CountMinionAttack(pPlayer) + CountNPCAttack(pPlayer)) >= 4) //-- chay khi nhieu linh danh ---
//////				{
//////					if(pAllyTurret_xxx)
//////					{
//////						//__oMsg("-- bi 3 thang linh danh --- tru3-step : %d", m_nKillTurret_03_Step);
//////						MOVE_TO(pAllyTurret_xxx->CurrentPos.x, pAllyTurret_xxx->CurrentPos.z);
//////						nTime_Wait_LinhDanh = 0;
//////						g_bClearLane = false;
//////						g_bNormalAttackHero = false;
//////						return;
//////					}
//////				}
//////				//if((nKC_Player2_POSATK3 > 200.0 && !CountEnemyMinionInRange(500.0) && !CountEnemyPlayerInRange(500.0)) || IsEnemyTurretInRange(1085.0)) //-- quay lai POS_ATK_2 ---
//////				if((nKC_Player2_POSATK3 > 350.0 && !CountEnemyMinionInRange(575.0) && !CountEnemyPlayerInRange(575.0)) || IsEnemyTurretInRange(1100.0)) //-- quay lai POS_ATK_2 ---
//////				{
//////					if(g_tDelay >= 400.0 && g_DelayNormalAttack > 400.0)
//////					{
//////						//__oMsg("TRO LAI POS_ATK_3 - tru3-Step: %d", m_nKillTurret_03_Step);
//////						MOVE_TO(POS_ATK_3.x, POS_ATK_3.z);
//////						nTime_NextStep = 0;
//////						return;
//////					}
//////				}
//////				if(CountEnemyPlayerInRange(pPlayer->nAttackRange + 100) && !IsEnemyTurretInRange(1100.0) && nTime_Wait_LinhDanh >= 1000.0) //-- co TuongDich va ko Gan tru dich ----
//////				{
//////					g_bClearLane = false;
//////					g_bNormalAttackHero = true;
//////					nTime_NextStep = 0;
//////					nTime_Wait_LinhDanh = 0;
//////					return;
//////				}
//////				if(CountEnemyMinionInRange(pPlayer->nAttackRange + 100) && nTime_Wait_LinhDanh >= 1000.0) //-- co LinhDich ----
//////				{
//////					g_bClearLane = true;
//////					g_bNormalAttackHero = false;
//////					nTime_Wait_LinhDanh = 0;
//////				}
//////				if(Count_AllyMinion_Around_NPC(pEnemyTurret_3, 875.0) >= 3 
//////				   && (!Count_EnemyPlayer_Around_NPC(pEnemyTurret_3, 1100.0) || (Count_EnemyPlayer_Around_NPC(pEnemyTurret_3, 1100.0) && !Count_EnemyPlayer_Around_NPC(pPlayer, 1400.0)))
//////				  )
//////				{
//////					//-- danh tru -----
//////					m_nKillTurret_03_Step = 1;
//////					g_bClearLane = false;
//////					g_bNormalAttackHero = false;
//////					return;
//////				}
//////			}
//////			else if(m_nKillTurret_03_Step == 1) //--- Danh Tru --------------
//////			{
//////				if(g_tDelay >= 400.0)
//////				{
//////					if(CheckName(pPlayer->GetNameHero(),  (sz__Ashe)))
//////					{
//////						if(CanCastSpell2(SKILL_Q) == 0)
//////						{
//////							ASHE_DO_SKILL_Q(pPlayer);
//////						}
//////					}
//////					NormalAttack(pEnemyTurret_3);
//////					g_tDelay = 0;
//////				}
//////				if(Count_AllyMinion_Around_NPC(pEnemyTurret_3, 875.0) < 3 || (Count_EnemyPlayer_Around_NPC(pEnemyTurret_3, 1100.0) && Count_EnemyPlayer_Around_NPC(pPlayer, 1100.0)))
//////				{
//////					m_nKillTurret_03_Step = 0;
//////					g_bClearLane = false;
//////					return;
//////				}
//////			}
//////			else if(m_nKillTurret_03_Step == 2) //--- ve nha khi het mau --------------
//////			{
//////				KPos* pSafe_Pos = new KPos;
//////				//if(IS_TEAM_1()) {pSafe_Pos->x = 9138.0; pSafe_Pos->y = 53.9; pSafe_Pos->z = 11368.0;}
//////				//if(!IS_TEAM_1()){pSafe_Pos->x = 5712.0; pSafe_Pos->y = 51.4; pSafe_Pos->z =  3550.0;}
//////				if(IS_TEAM_1()) {pSafe_Pos->x = 10080; pSafe_Pos->y = 52; pSafe_Pos->z = 7814;}
//////				if(!IS_TEAM_1()){pSafe_Pos->x =  4818; pSafe_Pos->y = 51; pSafe_Pos->z = 7148;}
//////
//////				float nKC_1 = Distance_3D(pAllyTurret_xxx->CurrentPos, pPlayer->CurrentPos);
//////				float nKC   = Distance_3D(*pSafe_Pos, pPlayer->CurrentPos);
//////				if(nKC_1 < nKC) *pSafe_Pos = pAllyTurret_xxx->CurrentPos;
//////				nKC = Distance_3D(*pSafe_Pos, pPlayer->CurrentPos);
//////
//////				if(nKC > 300.0)
//////				{
//////					MOVE_TO(pSafe_Pos->x, pSafe_Pos->z);
//////					//delete pSafe_Pos;
//////					return;
//////				}
//////				DO_RECALL_SKILL();
//////
//////				//if(pSafe_Pos) delete pSafe_Pos;
//////
//////			}
//////		}
////////===== NhaLinh chua chet =====================================================
//////		KNpc* pEnemyInhibitor_1 = GET_ENEMY_INHIBITOR(6250.0);
//////		if(!pEnemyTurret_1 && !pEnemyTurret_2 && !pEnemyTurret_3 && pEnemyInhibitor_1)
//////		{
//////			if(CountEnemyPlayerInRange(575.0) && !IsEnemyTurretInRange(1150.0)) //-- co TuongDich va ko Gan tru dich ----
//////			{
//////				g_bClearLane = false;
//////				g_bNormalAttackHero = true;
//////				return;
//////			}
//////			if(CountEnemyMinionInRange(575.0)) //-- co LinhDich ----
//////			{
//////				g_bClearLane = true;
//////				return;
//////			}
//////			g_bClearLane = false;
//////			g_bNormalAttackHero = false;
//////			if(g_tDelay >= 400.0)
//////			{
//////				if(CheckName(pPlayer->GetNameHero(),  (sz__Ashe)))
//////				{
//////					if(CanCastSpell2(SKILL_Q) == 0)
//////					{
//////						ASHE_DO_SKILL_Q(pPlayer);
//////					}
//////				}
//////				NormalAttack(pEnemyInhibitor_1);
//////				g_tDelay = 0;
//////			}
//////		}
////////===== Tru 4-5 chua chet =====================================================
//////		KNpc* pEnemyTurret_4 = GET_ENEMY_TURRET( (sz__SRUAP_Turret_Chaos4), 8000.0);
//////		if(!IS_TEAM_1())
//////		{
//////			pEnemyTurret_4 = GET_ENEMY_TURRET( (sz__SRUAP_Turret_Order4), 8000.0);
//////		}
//////		KPos POS_ATK_4;
//////		if(!pEnemyTurret_1 && !pEnemyTurret_2 && !pEnemyTurret_3 && !pEnemyInhibitor_1 && pEnemyTurret_4)
//////		{
//////			KPos pos1, pos2;
//////			//TIM_DIEM_CACH_1DIEM(pos1, pos2, GiuaManHinh_Pos, pEnemyTurret_4->CurrentPos, 6450.0);
//////			TIM_DIEM_CACH_1DIEM(pos1, pos2, GiuaManHinh_Pos_NEW, pEnemyTurret_4->CurrentPos, 6700.0);
//////			float nKC1 = Distance_2D(pos1, pEnemyTurret_4->CurrentPos);
//////			float nKC2 = Distance_2D(pos2, pEnemyTurret_4->CurrentPos);
//////			if(nKC1 > nKC2)	 POS_ATK_4 = pos2;
//////			else			 POS_ATK_4 = pos1;
//////			
//////			float nKC_Player2_GiuaManHinh = Distance_3D(pPlayer->CurrentPos, GiuaManHinh_Pos_NEW);
//////			float nKC_Player2_POSATK4     = Distance_3D(pPlayer->CurrentPos, POS_ATK_4);
//////
//////			if(m_nKillTurret_04_Step == 0) //--- danh o diem POS_ATK_2 --------------
//////			{
//////				if(nPercent_HP < 15.0 || CHECK_AND_BUY_ITEM())	////-- ve khi het mau || co tien mua do ----
//////				{
//////					m_nKillTurret_04_Step = 2;
//////					return;
//////				}
//////				nTime_Wait_LinhDanh += SYS_TIMER;
//////				if((CountMinionAttack(pPlayer) + CountNPCAttack(pPlayer)) >= 3) //-- chay khi nhieu linh danh ---
//////				{
//////					if(pAllyTurret_xxx)
//////					{
//////						//__oMsg("-- bi 3 thang linh danh --- tru4.5-step : %d", m_nKillTurret_04_Step);
//////						MOVE_TO(pAllyTurret_xxx->CurrentPos.x, pAllyTurret_xxx->CurrentPos.z);
//////						nTime_Wait_LinhDanh = 0;
//////						g_bClearLane = false;
//////						g_bNormalAttackHero = false;
//////						return;
//////					}
//////				}
//////				//if((nKC_Player2_POSATK4 > 220.0 && !CountEnemyMinionInRange(500.0) && !CountEnemyPlayerInRange(500.0)) || IsEnemyTurretInRange(1100.0)) //-- quay lai POS_ATK_2 ---
//////				if((nKC_Player2_POSATK4 > 330.0 && !CountEnemyMinionInRange(575.0) && !CountEnemyPlayerInRange(575.0)) || IsEnemyTurretInRange(1150.0)) //-- quay lai POS_ATK_2 ---
//////				{
//////					if(g_tDelay >= 400.0 && g_DelayNormalAttack > 400.0)
//////					{
//////						//__oMsg("TRO LAI POS_ATK_4 - tru4.5-Step: %d", m_nKillTurret_04_Step);
//////						MOVE_TO(POS_ATK_4.x, POS_ATK_4.z);
//////						return;
//////					}
//////				}
//////				if(CountEnemyPlayerInRange(pPlayer->nAttackRange + 100) && !IsEnemyTurretInRange(1100.0) && nTime_Wait_LinhDanh >= 1000.0) //-- co TuongDich va ko Gan tru dich ----
//////				{
//////					g_bClearLane = false;
//////					g_bNormalAttackHero = true;
//////					nTime_Wait_LinhDanh = 0;
//////					return;
//////				}
//////				if(CountEnemyMinionInRange(pPlayer->nAttackRange + 100) && nTime_Wait_LinhDanh >= 1000.0) //-- co LinhDich ----
//////				{
//////					g_bClearLane = true;
//////					g_bNormalAttackHero = false;
//////					nTime_Wait_LinhDanh = 0;
//////				}
//////				if(Count_AllyMinion_Around_NPC(pEnemyTurret_4, 850.0) >= 4 
//////				   && (!Count_EnemyPlayer_Around_NPC(pEnemyTurret_4, 1200.0) || (Count_EnemyPlayer_Around_NPC(pEnemyTurret_4, 1200.0) && !Count_EnemyPlayer_Around_NPC(pPlayer, 1400.0)))
//////				  )
//////				{
//////					//-- danh tru -----
//////					m_nKillTurret_04_Step = 1;
//////					g_bClearLane = false;
//////					g_bNormalAttackHero = false;
//////					return;
//////				}
//////			}
//////			else if(m_nKillTurret_04_Step == 1) //--- Danh Tru --------------
//////			{
//////				if(g_tDelay >= 400.0)
//////				{
//////					if(CheckName(pPlayer->GetNameHero(),  (sz__Ashe)))
//////					{
//////						if(CanCastSpell2(SKILL_Q) == 0)
//////						{
//////							ASHE_DO_SKILL_Q(pPlayer);
//////						}
//////					}
//////					NormalAttack(pEnemyTurret_4);
//////					g_tDelay = 0;
//////				}
//////				if(Count_AllyMinion_Around_NPC(pEnemyTurret_4, 850.0) < 4 || (Count_EnemyPlayer_Around_NPC(pEnemyTurret_4, 1200.0) && Count_EnemyPlayer_Around_NPC(pPlayer, 1100.0)))
//////				{
//////					m_nKillTurret_04_Step = 0;
//////					g_bClearLane = false;
//////					return;
//////				}
//////			}
//////			else if(m_nKillTurret_04_Step == 2) //--- ve nha khi het mau --------------
//////			{
//////				KPos* pSafe_Pos = new KPos;
//////				//if(IS_TEAM_1()) {pSafe_Pos->x = 9138.0; pSafe_Pos->y = 53.9; pSafe_Pos->z = 11368.0;}
//////				//if(!IS_TEAM_1()){pSafe_Pos->x = 5712.0; pSafe_Pos->y = 51.4; pSafe_Pos->z =  3550.0;}
//////				if(IS_TEAM_1()) {pSafe_Pos->x = 10080; pSafe_Pos->y = 52; pSafe_Pos->z = 7814;}
//////				if(!IS_TEAM_1()){pSafe_Pos->x =  4818; pSafe_Pos->y = 51; pSafe_Pos->z = 7148;}
//////
//////				float nKC_1 = Distance_3D(pAllyTurret_xxx->CurrentPos, pPlayer->CurrentPos);
//////				float nKC   = Distance_3D(*pSafe_Pos, pPlayer->CurrentPos);
//////				if(nKC_1 < nKC) *pSafe_Pos = pAllyTurret_xxx->CurrentPos;
//////				nKC = Distance_3D(*pSafe_Pos, pPlayer->CurrentPos);
//////
//////				if(nKC > 300.0)
//////				{
//////					MOVE_TO(pSafe_Pos->x, pSafe_Pos->z);
//////					//delete pSafe_Pos;
//////					return;
//////				}
//////				DO_RECALL_SKILL();
//////
//////				//if(pSafe_Pos) delete pSafe_Pos;
//////			}
//////		}
////////===== Nexus chua chet =====================================================
//////		KNpc* pNexus = GET_ENEMY_NEXUS(20000.0);
//////		if(!pEnemyTurret_1 && !pEnemyTurret_2 && !pEnemyTurret_3 && !pEnemyTurret_4 && !pEnemyInhibitor_1 && pNexus)
//////		{
//////			if(CountEnemyPlayerInRange(575.0) && !IsEnemyTurretInRange(1150.0)) //-- co TuongDich va ko Gan tru dich ----
//////			{
//////				g_bClearLane = false;
//////				g_bNormalAttackHero = true;
//////				return;
//////			}
//////			if(CountEnemyMinionInRange(575.0)) //-- co LinhDich ----
//////			{
//////				g_bClearLane = true;
//////				return;
//////			}
//////			g_bClearLane = false;
//////			g_bNormalAttackHero = false;
//////
//////			if(g_tDelay >= 400.0)
//////			{
//////				if(CheckName(pPlayer->GetNameHero(),  (sz__Ashe)))
//////				{
//////					if(CanCastSpell2(SKILL_Q) == 0)
//////					{
//////						ASHE_DO_SKILL_Q(pPlayer);
//////					}
//////				}
//////				NormalAttack(pNexus);
//////				g_tDelay = 0;
//////			}
//////		}
//////	}
}