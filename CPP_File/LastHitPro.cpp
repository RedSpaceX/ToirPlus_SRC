#include "LastHitPro.h"


extern bool nReset_DanhThuong;
extern bool b_Vladimir_DoingE;
extern bool Lucian_R_doing;
//extern float Jax_Time_DoSkill;
extern float g_tDelay;
extern bool nIs_DanhVoiMay;

float  nMissileSpeed				= 2000.0;
float  nMissileSpeed_Max			= 2500.0;
float  nDelayXuatChieu_vs_Melee		= 175.0;
float  nDelayXuatChieu_vs_Ranged	= 75.0;
float  nDelayXuatChieu_vs_Siege		= 125.0;
int    nAlready_SetTime             = 0;
float  nTime_SetLai					= 0.0;
bool   nDa_Test						= false;
extern KLanguage* pLang;
//==================================================================================//
//==================================================================================//
//==================================================================================//
float nStart_Ticked, nEnd_Ticked = 0;
float nStart_Ticked_1, nEnd_Ticked_1 = 0;
float nTime_Dem = 0;
void Check123()
{
	//KNpc *pPlayer = GetPlayer();
	//if(!pPlayer) return;
	//if (IS_DEAD(pPlayer)) return;
	//if(nAlready_SetTime == 0)
	//{
	//	Set_TimesLastHitPro();
	//}

	//float nTimeGame = GetTimeGame();
	//stNORMAL_ATTACK* Basic_Attack = (stNORMAL_ATTACK*)pPlayer->_pNormalAttack;
	//float nTimeCoolDown = Basic_Attack->nCooldownExpires;
	//
	//if(nTimeCoolDown - nTimeGame >= 1.6 - 0.03)
	//{
	//	nStart_Ticked = GetTickCount();
	//	nStart_Ticked_1 = GetTickCount();
	//	__oMsg("============== :  %f - %f - %f", nTimeCoolDown - nTimeGame, nStart_Ticked, nMissileSpeed);
	//}

	//DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	//DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	//DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	//DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	//if (!dw1 || !dw2 ) return;
	//int nCount = (dw2 - dw1)/4;

	////---- xxx -----------------------------------------------------------
	//for (int i = 0; i < nCount; ++i)
	//{
	//	DWORD dw3 = *(DWORD*)(dw1 + 4*i);
	//	if (dw3 == 0) continue;
	//	KNpc *pNpc = (KNpc*)dw3;
	//	if (!pNpc->IsEnemy(pPlayer->nTeam_ID) || IS_DEAD(pNpc) == true || pNpc->nHP <= 0. || (!IS_MINION(pNpc) && !IS_HERO(pNpc)))
	//		continue;
	//	if ((BYTE)pNpc->nIsTargetableToTeam != 4) continue;
	//	float nDist_Player2Minion = Distance_2D(pPlayer->CurrentPos, pNpc->CurrentPos);
	//	if (nDist_Player2Minion > 700) continue;
	//	if (CheckName( (sz__Minion), pNpc->GetNameNpc()) == true) continue;
	//	if (pNpc == pPlayer) continue;

	//	if (nTimeGame < 0) continue;
	//	stNORMAL_ATTACK* pEnemy_Basic_Attack = (stNORMAL_ATTACK*)pNpc->_pNormalAttack;
	//	if (pEnemy_Basic_Attack == NULL) continue;

	//	float nEnemy_TimeCoolDown = pEnemy_Basic_Attack->nCooldownExpires;
	//	
	//	if(nEnemy_TimeCoolDown - nTimeGame >= 1.6 - 0.05)
	//	{
	//		//nStart_Ticked_1 = GetTickCount();
	//		//__oMsg("xx : %f", nStart_Ticked_1);
	//		//nTime_Dem = 0;
	//	}
	//	
	//	if(!GET_BUFF(pNpc, "garenpassiveheal") || !GET_BUFF(pNpc, "garenpassive"))
	//	
	//	{
	//		nEnd_Ticked  = GetTickCount();
	//		float nDelta = (nEnd_Ticked - nStart_Ticked)/1000.0;
	//		__oMsg("[1].Delta : %.4f - KC: %.4f - TimeBay: %.4f - delay: %.4f", nDelta, nDist_Player2Minion, nDist_Player2Minion/nMissileSpeed, nDelta - nDist_Player2Minion/nMissileSpeed);
	//	}
	//	if(pPlayer->nHP < 600.0)
	//	{
	//		
	//		//nEnd_Ticked_1  = GetTickCount();
	//		//__oMsg("xx2 : %f", nEnd_Ticked_1);
	//		//float nDelta = (nEnd_Ticked_1 - nStart_Ticked_1)/1000.0;
	//		//__oMsg("[2].Delta : %.4f - KC: %.4f - TimeBay: %.4f - delay: %.4f", nDelta, nDist_Player2Minion, nDist_Player2Minion/(float)650, nDelta - nDist_Player2Minion/(float)650);
	//	}
	//	if(pNpc->nHP < 595.0)
	//	{
	//		nEnd_Ticked_1  = GetTickCount();
	//		float nDelta = (nEnd_Ticked_1 - nStart_Ticked_1)/1000.0;
	//		__oMsg("[2].Delta : %.4f - KC: %.4f - TimeBay: %.4f - delay: %.4f", nDelta, nDist_Player2Minion, nDist_Player2Minion/nMissileSpeed, nDelta - nDist_Player2Minion/nMissileSpeed);
	//	}
	//}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void AutoLastHitPro(bool nAttackChampions)
{
	//KNpc *pPlayer = GetPlayer();
	//if(!pPlayer) return;
	//if (IS_DEAD(pPlayer)) return;
	//nTime_SetLai += SYS_TIMER;

	//if(nAlready_SetTime == 0 || nTime_SetLai > 40000)// 40s up 1 lan
	//{
	//	Set_TimesLastHitPro();
	//	nTime_SetLai = 0;
	//	//__oMsg("nMissileSpeed : %f", nMissileSpeed);
	//}
	//if(pPlayer->nAttackSpeedMod >= (float)1.82)
	//{
	//	nDelayXuatChieu_vs_Melee		= (float)0.8*nDelayXuatChieu_vs_Melee;
	//	nDelayXuatChieu_vs_Ranged	    = (float)0.75*nDelayXuatChieu_vs_Ranged;
	//	nDelayXuatChieu_vs_Siege		= (float)0.75*nDelayXuatChieu_vs_Siege;
	//}

	//DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	//DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	//DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	//DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	//if (!dw1 || !dw2 ) return;
	//int nCount = (dw2 - dw1)/4;

	////--- Dang Recall --------------------------------------------------
	//if ((BYTE)pPlayer->nIsCastingSpell == 1)
	//{
	//	KCastSpell *pCastSpell = (KCastSpell *)pPlayer->_pCastSpell;
	//	if (pCastSpell == NULL) return;
	//	KSkill_2 *pSkill_2 = (KSkill_2 *)pCastSpell->__pK_str2;
	//	if (pSkill_2 == NULL) return;
	//	if (CheckName( (sz__recall), pSkill_2->GetSkillName())) return;
	//}
	////--- Caitlyn dang co Buff ban xa -----------------------------------
	//if (CheckName(  (sz__Caitlyn), pPlayer->GetNameHero()))
	//{
	//	KNpc* pEnemy_DB = SearchNPC2KillFastest(1350);
	//	if(pEnemy_DB)
	//	{
	//		if(GET_BUFF(pEnemy_DB,  (sz__caitlynyordletrapinternal)))  // pEnemy_DB bi Troi Bay cua Caitlyn
	//		{
	//			NormalAttack(pEnemy_DB);
	//			g_tDelay = 0;
	//			return;
	//		}
	//	}
	//}
	////---- xxx -----------------------------------------------------------
	//for (int i = 0; i < nCount; ++i)
	//{
	//	DWORD dw3 = *(DWORD*)(dw1 + 4*i);
	//	if (dw3 == 0) continue;
	//	KNpc *pNpc = (KNpc*)dw3;
	//	if (!pNpc->IsEnemy(pPlayer->nTeam_ID) || IS_DEAD(pNpc) == true || pNpc->nHP <= 0 || (!IS_MINION(pNpc) && !IS_HERO(pNpc)))
	//		continue;
	//	if ((BYTE)pNpc->nIsTargetableToTeam != 4) continue;

	//	float nDist_Player2Minion = Distance_2D(pPlayer->CurrentPos, pNpc->CurrentPos);
	//	float nRange = 0;
	//	if (pPlayer->nAttackRange < 300)
	//	{
	//		nRange = pPlayer->nAttackRange + pNpc->nOverrideCollisionRadius;
	//		if(nAttackChampions == true) nRange = pPlayer->nAttackRange + pNpc->nOverrideCollisionRadius + 10;
	//	} 
	//	else
	//	{
	//		nRange = pPlayer->nAttackRange + 75;
	//	}
	//	if (nDist_Player2Minion > nRange) continue;
	//
	//	float nDamageReceive = GetDamageReceive(pPlayer, pNpc);
	//	if(IS_MINION(pNpc))
	//	{
	//		if (CheckName( (sz__Minion), pNpc->GetNameNpc()) == false) continue; 
	//		int   nCount_DangBiDanh		  = 0;
	//		float nTongDmg_DangPhaiChiu   = 0;
	//		int   nAlly_CountAttack       = 0;
	//		float nAlly_TotalDamage       = 0;

	//		for (int j = 0; j < nCount; ++j)
	//		{
	//			DWORD dw4 = *(DWORD*)(dw1 + 4*j);
	//			if (dw4 == 0) continue;
	//			KNpc *pNpc_Ally = (KNpc*)dw4;
	//			if (!pNpc_Ally->IsAlly(pPlayer->nTeam_ID) || IS_DEAD(pNpc_Ally) == true || pNpc_Ally->nHP <= 0 || !IS_MINION( pNpc_Ally))
	//				continue;
	//			if ((BYTE)pNpc_Ally->nIsTargetableToTeam != 4) continue;
	//			if (CheckName( (sz__Minion), pNpc_Ally->GetNameNpc()) == false) continue;
	//			float nDist_AllyMinion2Minion = Distance_2D(pNpc_Ally->CurrentPos, pNpc->CurrentPos);

	//			KCastSpell *pCastSpell = (KCastSpell *)pNpc_Ally->_pCastSpell;
	//			if (pCastSpell == NULL) continue;
	//			if(pNpc->nID == pCastSpell->nEnemy_ID)
	//			{
	//				float nDmgNPC_Ally = pNpc_Ally->nFlat_PhysicalDamageMod + pNpc_Ally->nBaseAttackDamage;
	//				if(CheckName( (sz__MinionMelee), pNpc_Ally->GetNameHero()))
	//				{
	//					if(nDist_AllyMinion2Minion <= MinionMelee_Range + pNpc->nOverrideCollisionRadius)
	//					{
	//						nTongDmg_DangPhaiChiu += nDmgNPC_Ally;
	//						nCount_DangBiDanh	  += 1;
	//						float nTimeGame = GetTimeGame();
	//						if (nTimeGame < 0) continue;
	//						//stNORMAL_ATTACK* pAlly_Basic_Attack = (stNORMAL_ATTACK*)pNpc_Ally->_pNormalAttack;
	//						//if (pAlly_Basic_Attack == NULL) continue;
	//						float nAlly_TimeCoolDown = GET_CDBA_NEW(pNpc_Ally);

	//						float nThoiDiemXuatChieu_Ally = nAlly_TimeCoolDown - 1*1000/(float)MinionMelee_AttackSpeed;//tam 0.8 giay
	//						float nTgian_DanDaBay	      = nTimeGame - nThoiDiemXuatChieu_Ally;
	//						float nTongTgian_DanBay		  = (float)0.36 + nDist_AllyMinion2Minion/(float)MinionMelee_MissileSpeed;
	//						if(nDa_Test == false) // nhung con chua test ky ==> dung thuat toan cu~
	//						{
	//							//__oMsg("vao-FLASE");
	//							nTongTgian_DanBay		  = (float)0.25 + nDist_AllyMinion2Minion/(float)MinionMelee_MissileSpeed;
	//						}
	//						float nTgian_ConLai			  = nTongTgian_DanBay - nTgian_DanDaBay;
	//					
	//						float nPlayerTongTgian_DanBay = Get_AA_Animate_Delay() + nDist_Player2Minion/nMissileSpeed;
	//						if(nDa_Test == false)
	//						{
	//							nPlayerTongTgian_DanBay = nDelayXuatChieu_vs_Melee + nDist_Player2Minion/nMissileSpeed;
	//						}
	//						if(nPlayerTongTgian_DanBay >= nTgian_ConLai && nTgian_ConLai > 0)
	//						{
	//							nAlly_TotalDamage       += nDmgNPC_Ally;
	//							nAlly_CountAttack		+= 1;
	//						}
	//					}
	//				}
	//				if(CheckName( (sz__MinionRanged), pNpc_Ally->GetNameHero()))
	//				{
	//					if(nDist_AllyMinion2Minion <= MinionRanged_Range + pNpc->nOverrideCollisionRadius)
	//					{
	//						nTongDmg_DangPhaiChiu += nDmgNPC_Ally;
	//						nCount_DangBiDanh	  += 1;
	//						float nTimeGame = GetTimeGame();
	//						if (nTimeGame < 0) continue;
	//						//stNORMAL_ATTACK* pAlly_Basic_Attack = (stNORMAL_ATTACK*)pNpc_Ally->_pNormalAttack;
	//						//if (pAlly_Basic_Attack == NULL) continue;
	//						float nAlly_TimeCoolDown = GET_CDBA_NEW(pNpc_Ally);
	//						
	//						float nThoiDiemXuatChieu_Ally = nAlly_TimeCoolDown - 1*1000/(float)MinionRanged_AttackSpeed;//tam 1.5 giay
	//						float nTgian_DanDaBay	      = nTimeGame - nThoiDiemXuatChieu_Ally;
	//						float nTongTgian_DanBay	      = (float)0.45 + nDist_AllyMinion2Minion/(float)MinionRanged_MissileSpeed;
	//						if(nDa_Test == false) // nhung con chua test ky ==> dung thuat toan cu~
	//						{
	//							nTongTgian_DanBay		  = (float)0.5 + nDist_AllyMinion2Minion/(float)MinionRanged_MissileSpeed;
	//						}
	//						float nTgian_ConLai			  = nTongTgian_DanBay - nTgian_DanDaBay;
	//						
	//						float nPlayerTongTgian_DanBay = Get_AA_Animate_Delay() + nDist_Player2Minion/nMissileSpeed;
	//						if(nDa_Test == false)
	//						{
	//							nPlayerTongTgian_DanBay = nDelayXuatChieu_vs_Ranged + nDist_Player2Minion/nMissileSpeed;
	//						}
	//						if(nPlayerTongTgian_DanBay >= nTgian_ConLai && nTgian_ConLai > 0)
	//						{
	//							nAlly_TotalDamage       += nDmgNPC_Ally;
	//							nAlly_CountAttack		+= 1;
	//						}
	//					}
	//				}
	//				if(CheckName( (sz__MinionSiege), pNpc_Ally->GetNameHero()))
	//				{
	//					if(nDist_AllyMinion2Minion <= MinionSiege_Range + pNpc->nOverrideCollisionRadius)
	//					{
	//						nTongDmg_DangPhaiChiu += nDmgNPC_Ally;
	//						nCount_DangBiDanh	  += 1;
	//						float nTimeGame = GetTimeGame();
	//						if (nTimeGame < 0) continue;
	//						//stNORMAL_ATTACK* pAlly_Basic_Attack = (stNORMAL_ATTACK*)pNpc_Ally->_pNormalAttack;
	//						//if (pAlly_Basic_Attack == NULL) continue;
	//						float nAlly_TimeCoolDown = GET_CDBA_NEW(pNpc_Ally);
	//						
	//						float nThoiDiemXuatChieu_Ally = nAlly_TimeCoolDown - 1*1000/(float)MinionSiege_AttackSpeed;//tam 1.0 giay
	//						float nTgian_DanDaBay	      = nTimeGame - nThoiDiemXuatChieu_Ally;
	//						float nTongTgian_DanBay		  = (float)0.275 + nDist_AllyMinion2Minion/(float)MinionSiege_MissileSpeed;
	//						if(nDa_Test == false) // nhung con chua test ky ==> dung thuat toan cu~
	//						{
	//							nTongTgian_DanBay		  = (float)0.35 + nDist_AllyMinion2Minion/(float)MinionSiege_MissileSpeed;
	//						}
	//						float nTgian_ConLai			  = nTongTgian_DanBay - nTgian_DanDaBay;
 //
	//						float nPlayerTongTgian_DanBay = Get_AA_Animate_Delay() + nDist_Player2Minion/nMissileSpeed;
	//						if(nDa_Test == false)
	//						{
	//							nPlayerTongTgian_DanBay = nDelayXuatChieu_vs_Siege + nDist_Player2Minion/nMissileSpeed;
	//						}
	//						if(nPlayerTongTgian_DanBay >= nTgian_ConLai && nTgian_ConLai > 0)
	//						{
	//							nAlly_TotalDamage       += nDmgNPC_Ally;
	//							nAlly_CountAttack		+= 1;
	//						}
	//					}
	//				}
	//				
	//			}
	//		}
	//		if (pPlayer->nAttackRange > 300.0 && (nCount_DangBiDanh >= 3 || (nCount_DangBiDanh == 2 && nTongDmg_DangPhaiChiu >= nDamageReceive)))
	//		{
	//			nDamageReceive += nAlly_TotalDamage;
	//		}
	//		if (nDamageReceive >= pNpc->nHP)
	//		{
	//			float TIMEGAME = GetTimeGame();
	//			if (TIMEGAME < 0) return;
	//			//stNORMAL_ATTACK* _stNORMAL_ATTACK = (stNORMAL_ATTACK*)pPlayer->_pNormalAttack;
	//			//if (_stNORMAL_ATTACK == NULL) return;
	//			float nTimeCoolDown = GET_CDBA_NEW(pPlayer);
	//			if((nTimeCoolDown - 0.1)> TIMEGAME) return;
	//			if (CheckName(pPlayer->GetNameHero(),  (sz__Vladimir)))
	//			{
	//				if(b_Vladimir_DoingE == true) return;
	//			}
	//			NormalAttack(pNpc);
	//			//__oMsg("[%d] %d -- %f - %f  => [%f - %f - %f - %f - %f]",nCount_DangBiDanh, nAlly_CountAttack, pNpc->nHP, nXXX, nDelayXuatChieu_vs_Melee, nDelayXuatChieu_vs_Ranged, nDelayXuatChieu_vs_Siege, nMissileSpeed, nMissileSpeed_Max);
	//			g_tDelay = 0.;
	//		}
	//	}
	//	else
	//	{
	//		if(nAttackChampions == false) continue;
	//		float TIMEGAME = GetTimeGame();
	//		if (TIMEGAME < 0) return;
	//		//stNORMAL_ATTACK* _stNORMAL_ATTACK = (stNORMAL_ATTACK*)pPlayer->_pNormalAttack;
	//		//if (_stNORMAL_ATTACK == NULL) return;
	//		float nTimeCoolDown = GET_CDBA_NEW(pPlayer);
	//		if((nTimeCoolDown - 0.1)> TIMEGAME  && nReset_DanhThuong == false) return;
	//		if(GET_BUFF_DACBIET(pNpc) >= 2) return; // ko danh tuong khi co dong ho cat..
	//		if (pLang->isTargetSelector_old /*SLMHTClientData::GetInstance()->GetCBAtkCurrentSelected()*/)
	//		{
	//			DWORD nID_EnemySelected = GET_ENEMY_ID_SELECTED();
	//			//__oMsg("C.1--nID_EnemySelected: %x", nID_EnemySelected);
	//			if(nID_EnemySelected == pNpc->nID)
	//			{
	//				//__oMsg("C.2--nID_EnemySelected: %x", nID_EnemySelected);
	//				NormalAttack(pNpc);
	//				g_tDelay = 0;
	//				nReset_DanhThuong = false;
	//				//Jax_Time_DoSkill = 0.0;
	//				return;
	//			}
	//		}
	//		if (CheckName(pPlayer->GetNameHero(),  (sz__Vladimir)))
	//		{
	//			if(b_Vladimir_DoingE == true) return;
	//		}
	//		if (CheckName(pPlayer->GetNameHero(),  (sz__Varus)))
	//		{
	//			if(GET_BUFF(pPlayer,  (sz__VarusQ)) && CanCastSpell2(SKILL_Q) == 0) return;		
	//		}
	//		if (CheckName(pPlayer->GetNameHero(),  (sz__Xerath)))
	//		{
	//			if(GET_BUFF(pPlayer,  (sz__XerathArcanopulseChargeUp)) && CanCastSpell2(SKILL_Q) == 0) return;
	//		}
	//		if (pPlayer->nAttackRange < 300.0)
	//		{
	//			if(nDist_Player2Minion > 290.0)	return;
	//		}
	//		NormalAttack(pNpc);
	//		g_tDelay = 0.;
	//		nReset_DanhThuong = false;
	//		//Jax_Time_DoSkill = 0.0;
	//	}
	//}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void AutoRiaMauMinion()
{
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return;
	if (IS_DEAD(pPlayer)) return;
	nTime_SetLai += SYS_TIMER;

	if(nAlready_SetTime == 0 || nTime_SetLai > 40000.0)// 40s up 1 lan
	{
		Set_TimesLastHitPro();
		nTime_SetLai = 0;
		//__oMsg("nMissileSpeed : %f", nMissileSpeed);
	}
	if(pPlayer->nAttackSpeedMod >= 1.82)
	{
		nDelayXuatChieu_vs_Melee		= (float)0.8*nDelayXuatChieu_vs_Melee;
		nDelayXuatChieu_vs_Ranged	    = (float)0.75*nDelayXuatChieu_vs_Ranged;
		nDelayXuatChieu_vs_Siege		= (float)0.75*nDelayXuatChieu_vs_Siege;
	}

	KEnemyDistance nEnemyMinion[100];
	int jCount = 0;

	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return;
	int nCount = (dw2 - dw1)/4;

	//--- Dang Recall --------------------------------------------------
	if ((BYTE)pPlayer->nIsCastingSpell == 1)
	{
		KCastSpell *pCastSpell = (KCastSpell *)pPlayer->_pCastSpell;
		if (pCastSpell == NULL) return;
		KSkill_2 *pSkill_2 = (KSkill_2 *)pCastSpell->__pK_str2;
		if (pSkill_2 == NULL) return;
		if (CheckName( (sz__recall), pSkill_2->GetSkillName())) return;
	}
	
	//---- xxx -----------------------------------------------------------
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pNpc = (KNpc*)dw3;
		if (!pNpc->IsEnemy(pPlayer->nTeam_ID) || IS_DEAD(pNpc) == true || pNpc->nHP <= 0 || !IS_MINION(pNpc))
			continue;
		if ((BYTE)pNpc->nIsTargetableToTeam != 4) continue;

		float nDist_Player2Minion = Distance_2D(pPlayer->CurrentPos, pNpc->CurrentPos);
		float nRange = 0;
		if (pPlayer->nAttackRange < 300)
		{
			nRange = pPlayer->nAttackRange + pNpc->nOverrideCollisionRadius;
		} 
		else
		{
			nRange = pPlayer->nAttackRange + 100;
			if (nIs_DanhVoiMay)
				nRange = pPlayer->nAttackRange + 225;
		}
		if (nDist_Player2Minion > nRange) continue;
		if (CheckName( (sz__Minion), pNpc->GetNameNpc()) == false) continue;
		
//--- cho EnemyMinion vao 1 mang khac --------------------------------------------------------
		nEnemyMinion[jCount].pEnemy		= pNpc;
		nEnemyMinion[jCount].fDistance  = nDist_Player2Minion;
		nEnemyMinion[jCount].nHP		= pNpc->nHP;
		nEnemyMinion[jCount].nMaxHP		= pNpc->nMaxHP;
		nEnemyMinion[jCount].nDamage	= pNpc->nBaseAttackDamage + pNpc->nFlat_PhysicalDamageMod;

		KBuffs*  pBuff_Giao = GET_BUFF(pNpc ,  (sz__kalistaexpungemarker));
		if(pBuff_Giao)
		{
			float nTimeGame = GetTimeGame();
			nEnemyMinion[jCount].nTimeGiaoKalista		= pBuff_Giao->nEnd_Time - nTimeGame;
		}
		else
		{
			nEnemyMinion[jCount].nTimeGiaoKalista		= (float)2.35;
		}
		jCount += 1;
//---------------------------------------------------------------------------------------------
		float nDame_WaitLastHit		  = 0.0;
		float nDamageReceive		  = GetDamageReceive(pPlayer, pNpc);
		int   nCount_DangBiDanh		  = 0;
		float nTongDmg_DangPhaiChiu   = 0.0;
		int   nAlly_CountAttack       = 0;
		float nAlly_TotalDamage       = 0.0;

		for (int j = 0; j < nCount; ++j)
		{
			DWORD dw4 = *(DWORD*)(dw1 + 4*j);
			if (dw4 == 0) continue;
			KNpc *pNpc_Ally = (KNpc*)dw4;
			if (!pNpc_Ally->IsAlly(pPlayer->nTeam_ID) || IS_DEAD(pNpc_Ally) == true || pNpc_Ally->nHP <= 0 || !IS_MINION( pNpc_Ally))
				continue;
			if ((BYTE)pNpc_Ally->nIsTargetableToTeam != 4) continue;
			if (CheckName( (sz__Minion), pNpc_Ally->GetNameNpc()) == false) continue;
			float nDist_AllyMinion2Minion = Distance_2D(pNpc_Ally->CurrentPos, pNpc->CurrentPos);

			KCastSpell *pCastSpell = (KCastSpell *)pNpc_Ally->_pCastSpell;
			if (pCastSpell == NULL) continue;
			if(pNpc->nID == pCastSpell->nEnemy_ID)
			{
				float nDmgNPC_Ally = pNpc_Ally->nFlat_PhysicalDamageMod + pNpc_Ally->nBaseAttackDamage;
				if(CheckName( (sz__MinionMelee), pNpc_Ally->GetNameHero()))
				{
					if(nDist_AllyMinion2Minion <= MinionMelee_Range + pNpc->nOverrideCollisionRadius + 200)
					{
						nTongDmg_DangPhaiChiu += nDmgNPC_Ally;
						nCount_DangBiDanh	  += 1;
					}
				}
				if(CheckName( (sz__MinionRanged), pNpc_Ally->GetNameHero()))
				{
					if(nDist_AllyMinion2Minion <= MinionRanged_Range + pNpc->nOverrideCollisionRadius + 150)
					{
						nTongDmg_DangPhaiChiu += nDmgNPC_Ally;
						nCount_DangBiDanh	  += 1;
					}
				}
				if(CheckName( (sz__MinionSiege), pNpc_Ally->GetNameHero()))
				{
					if(nDist_AllyMinion2Minion <= MinionSiege_Range + pNpc->nOverrideCollisionRadius + 175)
					{
						nTongDmg_DangPhaiChiu += nDmgNPC_Ally;
						nCount_DangBiDanh	  += 1;
					}
				}
			}
		}
		extern bool nIs_PushLane;
		float nSoLan = (float)1.85;
		if(nDamageReceive > 120 && pPlayer->nAttackSpeedMod >= (float)1.58)
		{
			nSoLan = (float)1.45;
		}
		if(nIs_PushLane) nSoLan = (float)1.3;
		nDame_WaitLastHit = 2*nTongDmg_DangPhaiChiu + nSoLan*nDamageReceive;
		if(CheckName( (sz__Kalista), pPlayer->GetNameHero()))
		{	
			if(nCount_DangBiDanh >= 2 && 1.5*nTongDmg_DangPhaiChiu >= pNpc->nHP)
			{
				//float nDamage_E = Kalista_GetDamage_E(pNpc);
				//if(nDamage_E >= pNpc->nHP)
				//{
				//	//Kalista_DO_SKILL_E(pNpc);
				//}
			}
			if(CanCastSpell2(SKILL_E) == 0) nDame_WaitLastHit = 0;
			else							nDame_WaitLastHit = (float)1.5*nTongDmg_DangPhaiChiu + (float)1.1*nDamageReceive;
			
		}
	
		//--- cho nay Return de doi LastHit Minion -----------------
		float nX = (float)1.7;
		if(nIs_PushLane) nX = (float)1.3;
		if (nDame_WaitLastHit >= pNpc->nHP && nCount_DangBiDanh && (BYTE)pPlayer->nLevel < 10 && pPlayer->nAttackSpeedMod < nX)
		{
			return;
		}
	}

//-- Danh EnemyMinion nhieu mau nhat hoac it mau nhat --------------------------------------------------------------
	if((BYTE)pPlayer->nLevel < 10 && pPlayer->nAttackSpeedMod < 1.70 && Count_AllyMinion_Around_NPC(pPlayer, 900.0))
	{
		if(CheckName( (sz__Kalista), pPlayer->GetNameHero()) || //--- Ap dung cho V-Kalista ---------- Danh it mau truoc
		   CheckName( (sz__Vayne), pPlayer->GetNameHero())	  ||
		   CheckName( (sz__Ashe), pPlayer->GetNameHero())	  ||
		   CheckName( (sz__Orianna), pPlayer->GetNameHero()))
		{	
			float fMin_HP = 20000;
			int nIndex = -1;
			for (int j = 0; j < jCount; ++j)
			{
				if (fMin_HP > nEnemyMinion[j].nHP)
				{
					fMin_HP = nEnemyMinion[j].nHP;
					nIndex = j;
				}
			}
			if (nIndex == -1)
			{
				if(AutoClearLanePro() == false)
				{
					return;
				}
			} 
			else
			{
				float TIMEGAME = GetTimeGame();
				if (TIMEGAME < 0) return;
				//stNORMAL_ATTACK* _stNORMAL_ATTACK = (stNORMAL_ATTACK*)pPlayer->_pNormalAttack;
				//if (_stNORMAL_ATTACK == NULL) return;
				float nTimeCoolDown = GET_CDBA_NEW(pPlayer);
				if((nTimeCoolDown - 0.1)> TIMEGAME) return;
				if(AutoClearLanePro() == false)// ko co Chams - Turret - Inhibitor - Nexus thi danh Linh nhieu mau nhat
				{
					NormalAttack(nEnemyMinion[nIndex].pEnemy);
					g_tDelay = 0;
				}
			}
		}
		else		//---------- Danh Dam-to nhat truoc(XETO->BanXa->CanChien)
		{
			float fMax_Damage = 0;
			int nIndex = -1;
			for (int j = 0; j < jCount; ++j)
			{
				if (fMax_Damage < nEnemyMinion[j].nDamage)
				{
					fMax_Damage = nEnemyMinion[j].nDamage;
					nIndex = j;
				}
			}
			if (nIndex == -1)
			{
				if (CheckName(pPlayer->GetNameHero(),  (sz__Vladimir)))
				{
					if(b_Vladimir_DoingE == true) return;
				}
				if(AutoClearLanePro() == false)
				{
					return;
				}
			} 
			else
			{
				float TIMEGAME = GetTimeGame();
				if (TIMEGAME < 0) return;
				//stNORMAL_ATTACK* _stNORMAL_ATTACK = (stNORMAL_ATTACK*)pPlayer->_pNormalAttack;
				//if (_stNORMAL_ATTACK == NULL) return;
				float nTimeCoolDown = GET_CDBA_NEW(pPlayer);
				if((nTimeCoolDown - 0.1)> TIMEGAME) return;
				if (CheckName(pPlayer->GetNameHero(),  (sz__Vladimir)))
				{
					if(b_Vladimir_DoingE == true) return;
				}
				if(AutoClearLanePro() == false)// ko co Chams - Turret - Inhibitor - Nexus thi danh Linh nhieu mau nhat
				{
					NormalAttack(nEnemyMinion[nIndex].pEnemy);
					g_tDelay = 0;
				}
			}
		}
	}
	else // -- danh Minion it mau -------------------
	{
		float fMin_HP = 20000;
		int nIndex = -1;
		for (int j = 0; j < jCount; ++j)
		{
			if (fMin_HP > nEnemyMinion[j].nHP)
			{
				fMin_HP = nEnemyMinion[j].nHP;
				nIndex = j;
			}
		}
		if (nIndex == -1)
		{
			if (CheckName(pPlayer->GetNameHero(),  (sz__Vladimir)))
			{
				if(b_Vladimir_DoingE == true) return;
			}
			if(AutoClearLanePro() == false)
			{
				return;
			}
		} 
		else
		{
			float TIMEGAME = GetTimeGame();
			if (TIMEGAME < 0) return;
			//stNORMAL_ATTACK* _stNORMAL_ATTACK = (stNORMAL_ATTACK*)pPlayer->_pNormalAttack;
			//if (_stNORMAL_ATTACK == NULL) return;
			float nTimeCoolDown = GET_CDBA_NEW(pPlayer);
			if((nTimeCoolDown - 0.1)> TIMEGAME) return;
			if (CheckName(pPlayer->GetNameHero(),  (sz__Vladimir)))
			{
				if(b_Vladimir_DoingE == true) return;
			}
			if(AutoClearLanePro() == false)// ko co Chams - Turret - Inhibitor - Nexus thi danh Linh nhieu mau nhat
			{
				NormalAttack(nEnemyMinion[nIndex].pEnemy);
				g_tDelay = 0;
			}
		}
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool AutoClearLanePro()
{
	//DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	//DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	//DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	//DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	//if (!dw1 || !dw2 ) return false;
	//int nCount = (dw2 - dw1)/4;
	//KNpc *pPlayer = GetPlayer();
	//if(!pPlayer) return false;
	//if (IS_DEAD(pPlayer)) return false;

	//if (CheckName(  (sz__Caitlyn), pPlayer->GetNameHero()))// dung cho Caitlyn
	//{
	//	KNpc* pEnemy_DB = SearchNPC2KillFastest(1350);
	//	if(pEnemy_DB)
	//	{
	//		if(GET_BUFF(pEnemy_DB,  (sz__caitlynyordletrapinternal)))   // pEnemy_DB bi Troi Bay cua Caitlyn
	//		{
	//			NormalAttack(pEnemy_DB);
	//			g_tDelay = 0;
	//			return true;
	//		}
	//	}
	//}
	//KNpc **pEnemyXXX = new KNpc*[nCount];
	//int nXXX = 0;
	//int  nIndexNexus = -1, nIndexInhibitor = -1, nIndexTurret = -1, nIndexHero = -1;

	//for (int i = 0; i < nCount; ++i)
	//{
	//	DWORD dw3 = *(DWORD*)(dw1 + 4*i);
	//	if (dw3 == 0) continue;
	//	KNpc *pNpc = (KNpc*)dw3;
	//	if (!pNpc->IsEnemy(pPlayer->nTeam_ID) || IS_DEAD(pNpc) == true || pNpc->nHP <= 0. || IS_MINION(pNpc))
	//		continue;
	//	float nDistance = Distance_3D(pPlayer->CurrentPos, pNpc->CurrentPos);
	//	float nRange = 0;
	//	if (pPlayer->nAttackRange < 300)
	//	{
	//		nRange = pPlayer->nAttackRange + 115;
	//		if(IS_HERO(pNpc)) nRange = pPlayer->nAttackRange + pNpc->nOverrideCollisionRadius + 10;
	//	} 
	//	else
	//	{
	//		nRange = pPlayer->nAttackRange + 75;
	//		if (nIs_DanhVoiMay)
	//			nRange = pPlayer->nAttackRange + 225;
	//	}
	//	if (nDistance > nRange) continue;
	//	if ((BYTE)pNpc->nIsTargetableToTeam != 4) continue;

	//	if (IS_HERO(pNpc) && !IsEnemyTurretInRange(1050))
	//	{
	//		nIndexHero = nXXX;
	//		pEnemyXXX[nXXX] = pNpc;
	//		nXXX += 1;
	//	}
	//	if (IS_TURRET(pNpc))
	//	{
	//		nIndexTurret = nXXX;
	//		pEnemyXXX[nXXX] = pNpc;
	//		nXXX += 1;
	//	}
	//	DWORD offsetNexus = NEXUS - TEMP_ENTRY_POINT + hModule;
	//	if (IS_NEXUS(pNpc))
	//	{
	//		nIndexNexus = nXXX;
	//		pEnemyXXX[nXXX] = pNpc;
	//		nXXX += 1;
	//	}
	//	DWORD offsetInhibitor = INHIBITOR - TEMP_ENTRY_POINT + hModule;
	//	if (IS_INHIBITOR(pNpc))
	//	{
	//		nIndexInhibitor = nXXX;
	//		pEnemyXXX[nXXX] = pNpc;
	//		nXXX += 1;
	//	}
	//}
	//float TIMEGAME = GetTimeGame();
	//if (TIMEGAME < 0)
	//{
	//	delete [] pEnemyXXX;
	//	return false;
	//}
	////stNORMAL_ATTACK* _stNORMAL_ATTACK = (stNORMAL_ATTACK*)pPlayer->_pNormalAttack;
	////if (_stNORMAL_ATTACK == NULL)
	////{
	////	delete [] pEnemyXXX;
	////	return false;
	////}
	//float nTimeCoolDown = GET_CDBA_NEW(pPlayer);
	//if((nTimeCoolDown - 0.1)> TIMEGAME)
	//{
	//	delete [] pEnemyXXX;
	//	return false;
	//}
	//if (nIndexTurret != -1)
	//{
	//	NormalAttack(pEnemyXXX[nIndexTurret]);
	//	g_tDelay = 0;
	//	delete []pEnemyXXX;
	//	return true;
	//}
	//if (nIndexHero != -1)
	//{
	//	NormalAttack(pEnemyXXX[nIndexHero]);
	//	g_tDelay = 0;
	//	delete []pEnemyXXX;
	//	return true;
	//}
	//if (nIndexNexus != -1)
	//{
	//	NormalAttack(pEnemyXXX[nIndexNexus]);
	//	g_tDelay = 0;
	//	delete []pEnemyXXX;
	//	return true;
	//}
	//if (nIndexInhibitor != -1)
	//{
	//	NormalAttack(pEnemyXXX[nIndexInhibitor]);
	//	g_tDelay = 0;
	//	delete []pEnemyXXX;
	//	return true;
	//}
	//delete []pEnemyXXX;

	return false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void Set_TimesLastHitPro()
{
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return;
	if (IS_DEAD(pPlayer)) return;
	nAlready_SetTime = 1;
	//__oMsg("SET_LAN_DAU_____ : %f", nMissileSpeed);
//------ ASHE ---------------------------------------------------------------------------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Ashe)))
	{
		nMissileSpeed					= (float)Ashe_MissileSpeed;
		nMissileSpeed_Max				= (float)Ashe_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Ashe_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Ashe_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Ashe_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ VAYNE ---------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Vayne)))
	{
		nMissileSpeed					= (float)Vayne_MissileSpeed;
		nMissileSpeed_Max				= (float)Vayne_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Vayne_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Vayne_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Vayne_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ KALISTA --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Kalista)))
	{
		nMissileSpeed					= (float)Kalista_MissileSpeed;
		nMissileSpeed_Max				= (float)Kalista_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Kalista_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Kalista_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Kalista_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ JINX --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Jinx)))
	{
		nMissileSpeed					= (float)Jinx_MissileSpeed;
		nMissileSpeed_Max				= (float)Jinx_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Jinx_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Jinx_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Jinx_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ CAITLYN --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Caitlyn)))
	{
		nMissileSpeed					= (float)Caitlyn_MissileSpeed;
		nMissileSpeed_Max				= (float)Caitlyn_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Caitlyn_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Caitlyn_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Caitlyn_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ JHIN --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Jhin)))
	{
		nMissileSpeed					= (float)Jhin_MissileSpeed;
		nMissileSpeed_Max				= (float)Jhin_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ TWITCH --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Twitch)))
	{
		nMissileSpeed					= (float)Twitch_MissileSpeed;
		nMissileSpeed_Max				= (float)Twitch_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Twitch_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Twitch_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Twitch_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ EZREAL --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Ezreal)))
	{
		nMissileSpeed					= (float)Ezreal_MissileSpeed;
		nMissileSpeed_Max				= (float)Ezreal_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Ezreal_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Ezreal_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Ezreal_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ TRISTANA --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Tristana)))
	{
		nMissileSpeed					= (float)Tristana_MissileSpeed;
		nMissileSpeed_Max				= (float)Tristana_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Tristana_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Tristana_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Tristana_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ SIVIR --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Sivir)))
	{
		nMissileSpeed					= (float)Sivir_MissileSpeed;
		nMissileSpeed_Max				= (float)Sivir_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Sivir_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Sivir_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Sivir_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ KOGMAW --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__KogMaw)))
	{
		nMissileSpeed					= (float)KogMaw_MissileSpeed;
		nMissileSpeed_Max				= (float)KogMaw_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)KogMaw_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)KogMaw_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)KogMaw_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ VARUS --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Varus)))
	{
		nMissileSpeed					= (float)Varus_MissileSpeed;
		nMissileSpeed_Max				= (float)Varus_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Varus_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Varus_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Varus_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ DRAVEN --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Draven)))
	{
		nMissileSpeed					= (float)Draven_MissileSpeed;
		nMissileSpeed_Max				= (float)Draven_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Draven_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Draven_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Draven_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ QUINN --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Quinn)))
	{
		nMissileSpeed					= (float)Quinn_MissileSpeed;
		nMissileSpeed_Max				= (float)Quinn_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Quinn_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Quinn_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Quinn_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ MISS FORTUNE --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__MissFortune)))
	{
		nMissileSpeed					= (float)MissFor_MissileSpeed;
		nMissileSpeed_Max				= (float)MissFor_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)MissFor_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)MissFor_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)MissFor_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ LUCIAN --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Lucian)))
	{
		nMissileSpeed					= (float)Lucian_MissileSpeed;
		nMissileSpeed_Max				= (float)Lucian_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Lucian_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Lucian_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Lucian_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ GRAVES --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Graves)))
	{
		nMissileSpeed					= (float)Graves_MissileSpeed;
		nMissileSpeed_Max				= (float)Graves_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Graves_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Graves_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Graves_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ KINDRED --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Kindred)))
	{
		nMissileSpeed					= (float)Kindred_MissileSpeed;
		nMissileSpeed_Max				= (float)Kindred_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Kindred_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Kindred_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Kindred_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ CORKI --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Corki)))
	{
		nMissileSpeed					= (float)Corki_MissileSpeed;
		nMissileSpeed_Max				= (float)Corki_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Corki_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Corki_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Corki_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ JAYCE --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Jayce)) && pPlayer->nAttackRange > 400)
	{
		nMissileSpeed					= (float)Jayce_MissileSpeed;
		nMissileSpeed_Max				= (float)Jayce_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Jayce_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Jayce_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Jayce_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Jayce)) && pPlayer->nAttackRange < 400)
	{
		nMissileSpeed					= (float)Jayce2_MissileSpeed;
		nMissileSpeed_Max				= (float)Jayce2_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ ELISE --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Elise)) && pPlayer->nAttackRange > 400)
	{
		nMissileSpeed					= (float)Elise_MissileSpeed;
		nMissileSpeed_Max				= (float)Elise_MissileSpeed_Max;
		nDa_Test						= true;
	}
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Elise)) && pPlayer->nAttackRange < 400)
	{
		nMissileSpeed					= (float)Elise2_MissileSpeed;
		nMissileSpeed_Max				= (float)Elise2_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ KAYLE --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Kayle)))
	{
		nMissileSpeed					= (float)Kayle_MissileSpeed;
		nMissileSpeed_Max				= (float)Kayle_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ NUNU --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Nunu)))
	{
		nMissileSpeed					= (float)Nunu_MissileSpeed;
		nMissileSpeed_Max				= (float)Nunu_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ Fiora --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Fiora)))
	{
		nMissileSpeed					= (float)Fiora_MissileSpeed;
		nMissileSpeed_Max				= (float)Fiora_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ Fiddlesticks --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Fiddlesticks)))
	{
		nMissileSpeed					= (float)Fiddlesticks_MissileSpeed;
		nMissileSpeed_Max				= (float)Fiddlesticks_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ KENNEN --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Kennen)))
	{
		nMissileSpeed					= (float)Kennen_MissileSpeed;
		nMissileSpeed_Max				= (float)Kennen_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Kennen_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Kennen_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Kennen_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ TEEMO --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Teemo)))
	{
		nMissileSpeed					= (float)Teemo_MissileSpeed;
		nMissileSpeed_Max				= (float)Teemo_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Teemo_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Teemo_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Teemo_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ TWISTED_FATE --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__TwistedFate)))
	{
		nMissileSpeed					= (float)TwistedFate_MissileSpeed;
		nMissileSpeed_Max				= (float)TwistedFate_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)TwistedFate_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)TwistedFate_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)TwistedFate_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ XERATH --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Xerath)))
	{
		nMissileSpeed					= (float)XeRath_MissileSpeed;
		nMissileSpeed_Max				= (float)XeRath_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)XeRath_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)XeRath_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)XeRath_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ ANNIE --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Annie)))
	{
		nMissileSpeed					= (float)Annie_MissileSpeed;
		nMissileSpeed_Max				= (float)Annie_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Annie_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Annie_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Annie_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ AHRI --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Ahri)))
	{
		nMissileSpeed					= (float)Ahri_MissileSpeed;
		nMissileSpeed_Max				= (float)Ahri_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Ahri_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Ahri_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Ahri_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ ANIVIA --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Anivia)))
	{
		nMissileSpeed					= (float)Anivia_MissileSpeed;
		nMissileSpeed_Max				= (float)Anivia_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Anivia_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Anivia_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Anivia_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ AURELION SOL --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__AurelionSol)))
	{
		nMissileSpeed					= (float)AureSol_MissileSpeed;
		nMissileSpeed_Max				= (float)AureSol_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)AureSol_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)AureSol_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)AureSol_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ AZIR --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Azir)))
	{
		nMissileSpeed					= (float)Azir_MissileSpeed;
		nMissileSpeed_Max				= (float)Azir_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Azir_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Azir_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Azir_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ LEBLANC --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Leblanc)))
	{
		nMissileSpeed					= (float)Leblanc_MissileSpeed;
		nMissileSpeed_Max				= (float)Leblanc_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Leblanc_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Leblanc_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Leblanc_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ BRAND --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Brand)))
	{
		nMissileSpeed					= (float)Brand_MissileSpeed;
		nMissileSpeed_Max				= (float)Brand_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Brand_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Brand_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Brand_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ BARD --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Bard)))
	{
		nMissileSpeed					= (float)Bard_MissileSpeed;
		nMissileSpeed_Max				= (float)Bard_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Bard_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Bard_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Bard_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ CASSIOPEIA --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Cassiopeia)))
	{
		nMissileSpeed					= (float)Cassiopeia_MissileSpeed;
		nMissileSpeed_Max				= (float)Cassiopeia_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Cassiopeia_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Cassiopeia_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Cassiopeia_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ LUX --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Lux)))
	{
		nMissileSpeed					= (float)Lux_MissileSpeed;
		nMissileSpeed_Max				= (float)Lux_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Lux_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Lux_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Lux_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ RYZE --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Ryze)))
	{
		nMissileSpeed					= (float)Ryze_MissileSpeed;
		nMissileSpeed_Max				= (float)Ryze_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Ryze_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Ryze_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Ryze_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ SYNDRA --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Syndra)))
	{
		nMissileSpeed					= (float)Syndra_MissileSpeed;
		nMissileSpeed_Max				= (float)Syndra_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Syndra_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Syndra_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Syndra_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ ORIANNA --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Orianna)))
	{
		nMissileSpeed					= (float)Orianna_MissileSpeed;
		nMissileSpeed_Max				= (float)Orianna_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Orianna_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Orianna_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Orianna_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ VIKTOR --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Viktor)))
	{
		nMissileSpeed					= (float)Viktor_MissileSpeed;
		nMissileSpeed_Max				= (float)Viktor_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Viktor_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Viktor_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Viktor_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ VEIGAR --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Veigar)))
	{
		nMissileSpeed					= (float)Veigar_MissileSpeed;
		nMissileSpeed_Max				= (float)Veigar_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Veigar_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Veigar_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Veigar_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ VELKOZ --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Velkoz)))
	{
		nMissileSpeed					= (float)Velkoz_MissileSpeed;
		nMissileSpeed_Max				= (float)Velkoz_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Velkoz_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Velkoz_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Velkoz_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ ZIGGS --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Ziggs)))
	{
		nMissileSpeed					= (float)Ziggs_MissileSpeed;
		nMissileSpeed_Max				= (float)Ziggs_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Ziggs_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Ziggs_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Ziggs_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ ZILEAN --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Zilean)))
	{
		nMissileSpeed					= (float)Zilean_MissileSpeed;
		nMissileSpeed_Max				= (float)Zilean_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Zilean_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Zilean_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Zilean_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ ZYRA --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Zyra)))
	{
		nMissileSpeed					= (float)Zyra_MissileSpeed;
		nMissileSpeed_Max				= (float)Zyra_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Zyra_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Zyra_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Zyra_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ VLADIMIR --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Vladimir)))
	{
		nMissileSpeed					= (float)Vladimir_MissileSpeed;
		nMissileSpeed_Max				= (float)Vladimir_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Vladimir_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Vladimir_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Vladimir_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ THRESH --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Thresh)))
	{
		nMissileSpeed					= (float)Thresh_MissileSpeed;
		nMissileSpeed_Max				= (float)Thresh_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Thresh_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Thresh_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Thresh_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ SWAIN --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Swain)))
	{
		nMissileSpeed					= (float)Swain_MissileSpeed;
		nMissileSpeed_Max				= (float)Swain_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Swain_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Swain_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Swain_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ TALIYAH --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Taliyah)))
	{
		float nX = 1;
		if((BYTE)pPlayer->nLevel >= 10) nX = (float)0.95;
		nMissileSpeed					=    (float)Taliyah_MissileSpeed;
		nMissileSpeed_Max				=    (float)Taliyah_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= nX*(float)Taliyah_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= nX*(float)Taliyah_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= nX*(float)Taliyah_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ MALZAHAR --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Malzahar)))
	{
		float nX = 1;
		if((BYTE)pPlayer->nLevel >= 10) nX = (float)0.95;
		nMissileSpeed					= (float)Malzahar_MissileSpeed;
		nMissileSpeed_Max				= (float)Malzahar_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= nX*(float)Malzahar_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= nX*(float)Malzahar_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= nX*(float)Malzahar_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ KARTHUS --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Karthus)))
	{
		nMissileSpeed					= (float)Karthus_MissileSpeed;
		nMissileSpeed_Max				= (float)Karthus_MissileSpeed_Max;
		nDelayXuatChieu_vs_Melee		= (float)Karthus_DelayXuatChieu_vs_Melee/1000;
		nDelayXuatChieu_vs_Ranged		= (float)Karthus_DelayXuatChieu_vs_Ranged/1000;
		nDelayXuatChieu_vs_Siege		= (float)Karthus_DelayXuatChieu_vs_Siege/1000;
		nDa_Test						= true;
	}
//------ SORAKA --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Soraka)))
	{
		nMissileSpeed					= (float)Soraka_MissileSpeed;
		nMissileSpeed_Max				= (float)Soraka_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ KARMA --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Karma)))
	{
		nMissileSpeed					= (float)Karma_MissileSpeed;
		nMissileSpeed_Max				= (float)Karma_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ HEIMERDINGER --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Heimerdinger)))
	{
		nMissileSpeed					= (float)Heimerdinger_MissileSpeed;
		nMissileSpeed_Max				= (float)Heimerdinger_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ JANNA --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Janna)))
	{
		nMissileSpeed					= (float)Janna_MissileSpeed;
		nMissileSpeed_Max				= (float)Janna_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ MORGANA --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Morgana)))
	{
		nMissileSpeed					= (float)Morgana_MissileSpeed;
		nMissileSpeed_Max				= (float)Morgana_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ NIDALEE --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Nidalee)) && pPlayer->nAttackRange > 400)
	{
		nMissileSpeed					= (float)Nidalee_MissileSpeed;
		nMissileSpeed_Max				= (float)Nidalee_MissileSpeed_Max;
		nDa_Test						= true;
	}
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Nidalee)) && pPlayer->nAttackRange < 400)
	{
		nMissileSpeed					= (float)Nidalee2_MissileSpeed;
		nMissileSpeed_Max				= (float)Nidalee2_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ SHYVANA --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Shyvana)))
	{
		nMissileSpeed					= (float)Shyvana_MissileSpeed;
		nMissileSpeed_Max				= (float)Shyvana_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ ZED --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Zed)))
	{
		nMissileSpeed					= (float)Zed_MissileSpeed;
		nMissileSpeed_Max				= (float)Zed_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ YASUO --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Yasuo)))
	{
		nMissileSpeed					= (float)Yasuo_MissileSpeed;
		nMissileSpeed_Max				= (float)Yasuo_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ LISSANDRA --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Lissandra)))
	{
		nMissileSpeed					= (float)Lissandra_MissileSpeed;
		nMissileSpeed_Max				= (float)Lissandra_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ SONA --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Sona)))
	{
		nMissileSpeed					= (float)Sona_MissileSpeed;
		nMissileSpeed_Max				= (float)Sona_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ NAMI --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Nami)))
	{
		nMissileSpeed					= (float)Nami_MissileSpeed;
		nMissileSpeed_Max				= (float)Nami_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ URGOT --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Urgot)))
	{
		nMissileSpeed					= (float)Urgot_MissileSpeed;
		nMissileSpeed_Max				= (float)Urgot_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ LULU --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Lulu)))
	{
		nMissileSpeed					= (float)Lulu_MissileSpeed;
		nMissileSpeed_Max				= (float)Lulu_MissileSpeed_Max;
		nDa_Test						= true;	
	}
//------ GNAR --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Gnar)))
	{
		nMissileSpeed					= (float)Gnar_MissileSpeed;
		nMissileSpeed_Max				= (float)Gnar_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ XAYAH --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Xayah)))
	{
		nMissileSpeed					= (float)Xayah_MissileSpeed;
		nMissileSpeed_Max				= (float)Xayah_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ DARIUS --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Darius)))
	{
		nMissileSpeed					= (float)Darius_MissileSpeed;
		nMissileSpeed_Max				= (float)Darius_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ GAREN --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Garen)))
	{
		nMissileSpeed					= (float)Garen_MissileSpeed;
		nMissileSpeed_Max				= (float)Garen_MissileSpeed_Max;
		nDa_Test						= true;
	}
//------ NASUS --------------------------------------------------------------------------
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Nasus)))
	{
		nMissileSpeed					= (float)Nasus_MissileSpeed;
		nMissileSpeed_Max				= (float)Nasus_MissileSpeed_Max;
		nDa_Test						= true;
	}

	else if(pPlayer->nAttackRange < 350)// cho ca lu~ danh gan vao day
	{
		nMissileSpeed					= 420;
		nMissileSpeed_Max				= 420;
		nDa_Test						= true;
	}
	else// lu danh xa con` lai. neu chua test
	{
		nMissileSpeed					= 1750;
		nMissileSpeed_Max				= 1750;
		nDa_Test						= true;
	}
}