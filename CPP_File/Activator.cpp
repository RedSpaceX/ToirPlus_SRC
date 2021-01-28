#include "Activator.h"


extern KLanguage* pLang;
extern DWORD      G_Module;
extern int		  myTeamId;
extern KNpc*	  MY_HERO;

extern int		  countBiDanhBoiSkillDinhHuong;
extern bool       nCombo_Mode, nLaneClear_Mode, nMixed_Mode;
extern CIniFile*  menu_IniFile;

extern bool isRengar, isShaco, isKhazix;

bool hasHealItems, hasSolari, hasRedemption, hasSeraph, hasZhonya, hasMikael, hasGiaiThuat, hasKhienBang, hasRiuMangXa, hasVodanh, hasHextech = false;
bool hasSummonHeal, hasSummonDot, hasSummonBarrier, hasSummonCleanse = false;
bool hasTPlom, hasTPxanh, hasTPdo = false;
int  indexTP = -1;
//======================================================================================================
void CheckListItem()
{
	//__try
	{
		if(hasItem(0x7da) || hasItem(0x7d3) || hasItem(0x7ef) || hasItem(0x7f0) || hasItem(0x7f1))  // con 1 binh mau nua (Item2010|RegenerationPotion|ItemCrystalFlask|ItemCrystalFlaskJungle|ItemDarkCrystalFlask)
			 hasHealItems = true;
		else hasHealItems = false;

		if(hasItem(0xc05) || hasItem(0xc02) || hasItem(0xea4))  //tiamat | mangxa | dai mang xa
			 hasRiuMangXa = true; 
		else hasRiuMangXa = false;

		if(hasItem(0xc76)) hasSolari	 = true;					//solari
		else			   hasSolari	 = false;

		if(hasItem(0xc23)) hasRedemption = true;					//day truyen chuoc toi
		else			   hasRedemption = false;

		if(hasItem(0xbe0)) hasSeraph	 = true;					//Dai thien su
		else			   hasSeraph	 = false;

		if(hasItem(0xc47)) hasKhienBang  = true;					//khien bang
		else			   hasKhienBang  = false;

		if(hasItem(0xc96)) hasMikael	 = true;					//mikael
		else			   hasMikael	 = false;

		if(hasItem(0x974) || hasItem(0xc55)) hasZhonya    = true;	//DHC
		else								 hasZhonya    = false;

		if(hasItem(0xc44) || hasItem(0xc43)) hasGiaiThuat = true;  //khan gia thuat-dao thuy ngan
		else								 hasGiaiThuat = false;

		if(hasItem(0xc51) || hasItem(0xc48)) hasVodanh	  = true;     //vodanh | hai tac
		else						         hasVodanh    = false;

		if(hasItem(0xc4a) || hasItem(0xc50) || hasItem(0xbd6)) hasHextech = true;     //HextechGunblade|ItemSoFBoltSpellBase|ItemWillBoltSpellBase
		else												   hasHextech = false;
	}	
	//__except(EXCEPTION_EXECUTE_HANDLER) 
	//{ 
	//	//__oMsg("CheckListItem, dissssssssgameeeeeeeeeeee");
	//	SEND_TEXT_SYSTEM("CheckListItem"); 
	//}
	
}

//======================================================================================================
void Check_D_F_Spells(KNpc *pPlayer)
{
	if(!pPlayer) return;

	//__try
	{
		if (hasSpell(4, "SummonerHeal") || hasSpell(5, "SummonerHeal")) 
			 hasSummonHeal = true;
		else hasSummonHeal = false;

		if (hasSpell(4, "SummonerDot") || hasSpell(5, "SummonerDot"))
			 hasSummonDot = true;
		else hasSummonDot = false;

		if(hasSpell(4, "SummonerBarrier") || hasSpell(5, "SummonerBarrier")) 
			 hasSummonBarrier = true;
		else hasSummonBarrier = false;

		if (hasSpell(4, "SummonerBoost") || hasSpell(5, "SummonerBoost")) 
			 hasSummonCleanse = true;
		else hasSummonCleanse = false;

		//------- Smite -------:
		if (hasSpell(4, "SummonerSmite") || hasSpell(5, "SummonerSmite")) 
			 hasTPlom = true;//TP ghe
		else hasTPlom = false;

		if (hasSpell(4, "S5_SummonerSmitePlayerGanker") || hasSpell(5, "S5_SummonerSmitePlayerGanker")) hasTPxanh = true;
		else hasTPxanh = false;

		if (hasSpell(4, "S5_SummonerSmiteDuel") || hasSpell(5, "S5_SummonerSmiteDuel")) hasTPdo = true;
		else hasTPdo = false;

		if (hasTPlom || hasTPxanh || hasTPdo)
		{
			for (int i = 4; i < 6; ++i)
			{
				KSkill *pSkill = (KSkill *)pPlayer->_pSkill[i];
				if (!pSkill) continue;

				KSkill_2*  pKSkill_2GetName = (KSkill_2*) pSkill->__pK_str2;
				if (!pKSkill_2GetName) continue;

				//if (CheckName("S5_SummonerSmiteDuel",         pKSkill_2GetName->GetSkillName())  || 
				//	CheckName("S5_SummonerSmitePlayerGanker", pKSkill_2GetName->GetSkillName())  ||
				//	CheckName(pKSkill_2GetName->GetSkillName(), "SummonerSmite")   
			     //  )

				if (CheckName("SummonerSmite", pKSkill_2GetName->GetSkillName()))
				{
					indexTP = i; 
					return;
				}
			}
		}
	}	

	//__except(EXCEPTION_EXECUTE_HANDLER) 
	//{ 
	//	//__oMsg("CheckListSpells, dissssssssgameeeeeeeeeeee");
	//	SEND_TEXT_SYSTEM("CheckListSpells"); 
	//}
}

//======================================================================================================
float timeRecheckItemSpells = 0;
bool  isCheck_D_F_Spells	= false;
void ActivatorAllItem()
{
	if ( !MY_HERO) return;

	//...... CHECK.D.F.SPELLS ......
	if (isCheck_D_F_Spells == false)
	{
		//__oMsg("isCheck_D_F_Spells = %d", isCheck_D_F_Spells);

		Check_D_F_Spells(MY_HERO);		//Check D.F Spell (check duy nhat 1lan, con Zoe co the lam check rieng)
		isCheck_D_F_Spells = true;
	}

	if (pLang->isStopAllActivator) return;

	

	//...... CHECK.ITEM ......(22s/lan)
	if ((float)GetTickCount() - timeRecheckItemSpells > 22000)
	{
		CheckListItem();
		timeRecheckItemSpells = (float)GetTickCount();
	}

	//--------------------------------------------------:
	if (pLang->isAutoWard)
	{
		AutoWard_With_LanternThresh(MY_HERO);
		AutoWard_With_InvisibleHero(MY_HERO);
	}

	if (pLang->isAutoPosionBiscuitOnOff && hasHealItems)
		AutoHealItems(MY_HERO);

	if (pLang->isAutoSummonerHealOnOff && hasSummonHeal)
		AutoSummonerHeal(MY_HERO);

	if (pLang->isAutoBarrierOnOff && hasSummonBarrier)
		AutoBarrier(MY_HERO);

	if (pLang->isAutoSolariOnOff && hasSolari)
		AutoIronSolari(MY_HERO);

	if (pLang->isAutoRedemptionOnOff && hasRedemption)
		AutoDayChuyenChuocToi(MY_HERO);

	if (pLang->isAutoSeraphOnOff && hasSeraph)
		AutoSeraphs(MY_HERO);

	if (pLang->isAutoZhonyaOnOff && hasZhonya)
		AutoZhonyas(MY_HERO);

	if (pLang->isAutoCleanseQuickSilverMercurialMikaelOnOff)//check item ben trong
		AutoCleaseMercurial(MY_HERO);

	if (pLang->isAutoIgniteOnOff && hasSummonDot)
		AutoIgnite();

	if (pLang->isAutoRanduninOnOff && hasKhienBang)
		AutoKhienBang(MY_HERO);
	
	//RiuMangXa o OnDoCast_Delayed

	if(pLang->isAutoBilgewaterRuinedKingOnOff && hasVodanh && nCombo_Mode)
		AutoVoDanh(MY_HERO);

	if(pLang->isAutoHextechItemOnOff && hasHextech && nCombo_Mode)
		AutoHextech(MY_HERO);
}

//==================================================================================//
void AutoHealItems(KNpc *pPlayer)
{
	if (!pPlayer)		  return;
	if (IS_DEAD(pPlayer)) return;
	__try
	{
		if (100 * pPlayer->nHP / pPlayer->nMaxHP > pLang->autoPosionBiscuitLimit) return;

		KPos Home1(400.0f  , 172.0f, 460.0f);		// can check ky 2 toa do nay
		KPos Home2(14340.0f, 180.0f, 14390.0f);		// can check ky 2 toa do nay

		float nKC1 = Distance_2D(pPlayer->CurrentPos, Home1);
		float nKC2 = Distance_2D(pPlayer->CurrentPos, Home2);

		if (nKC1 < 650 || nKC2 < 650) return;

		if (!GET_BUFF(pPlayer, sz__RegenerationPotion))		 DO_SKILL_ITEM(pPlayer, sz__RegenerationPotion);	//==> Binh Mau
		//if(!GET_BUFF(pPlayer, sz__ItemMiniRegenPotion))		 DO_SKILL_ITEM(pPlayer, sz__ItemMiniRegenPotion);	//==> Banh Quy Hoi Suc
		if (!GET_BUFF(pPlayer, "Item2010"))					 DO_SKILL_ITEM(pPlayer, "Item2010");	//==> Banh Quy 
		if (!GET_BUFF(pPlayer, sz__ItemCrystalFlask))		 DO_SKILL_ITEM(pPlayer, sz__ItemCrystalFlask);		//==> Thuoc Tai Su Dung
		if (!GET_BUFF(pPlayer, sz__ItemCrystalFlaskJungle))	 DO_SKILL_ITEM(pPlayer, sz__ItemCrystalFlaskJungle);//==> Thuoc Cua Tho San
		if (!GET_BUFF(pPlayer, sz__ItemDarkCrystalFlask))	 DO_SKILL_ITEM(pPlayer, sz__ItemDarkCrystalFlask);	//==> Thuoc Bien Di
	}	
	__except(EXCEPTION_EXECUTE_HANDLER) 
	{ 
		//__oMsg("AutoHealItems, dissssssssgameeeeeeeeeeee");
		SEND_TEXT_SYSTEM("AutoHealItems"); 
	}
}
//==================================================================================//
void AutoSummonerHeal(KNpc *pPlayer)
{
	if (!pPlayer)		  return;
	if (IS_DEAD(pPlayer)) return;

	__try
	{
		if(!G_Module) return;
		DWORD nTemp1 = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
		DWORD nTemp2 = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
		DWORD dw1 = *(DWORD*)nTemp1;
		DWORD dw2 = *(DWORD*)nTemp2;
		if(!dw1 || !dw2 ) return;

		int nCount = (dw2 - dw1)/4;
		for(int i = 0; i < nCount; ++i)
		{
			DWORD dw3 = *(DWORD*)(dw1 + 4*i);
			if(dw3 == 0) continue;
			KNpc *ally = (KNpc*)dw3;
			if(ally->IsEnemy(pPlayer->nTeam_ID) || IS_DEAD(ally) || !ally->isTargetable() || !IS_HERO( ally)) continue;
			if (100*ally->nHP/ally->nMaxHP > pLang->autoSummonerHealLimit) continue;
			if(Distance_2D(pPlayer->CurrentPos, ally->CurrentPos) > 815)   continue;
			KPos Home1(400.0, 172.0, 460.0);		// can check ky 2 toa do nay
			KPos Home2(14340.0, 180.0, 14390.0);	// can check ky 2 toa do nay
			float nKC1 = Distance_2D(pPlayer->CurrentPos, Home1);
			float nKC2 = Distance_2D(pPlayer->CurrentPos, Home2);
			if (nKC1 < 640 || nKC2 < 640) continue;	
			if(ally != pPlayer)
			{
				if(CountNPCAttack(ally)) DO_HOI_MAU_SKILL();		//ironstylusbuff, ironstyluscheck : dung day chuyen Iron Solari co 2 cai buff nay
				return;
			}
			else
			{
				if (isRengar && GET_BUFF(pPlayer, sz__RengarR)) continue;		 // -- rengar dang tang hinh || cbi tang hinh ( vua bam R)
				if (countBiDanhBoiSkillDinhHuong || CountNPCAttack(pPlayer)) DO_HOI_MAU_SKILL();
			}
		}
	}	
	__except(EXCEPTION_EXECUTE_HANDLER) 
	{ 
		//__oMsg("AutoSummonerHeal, dissssssssgameeeeeeeeeeee");
		SEND_TEXT_SYSTEM("AutoSummonerHeal"); 
	}
}

//==================================================================================//
void AutoBarrier(KNpc *pPlayer)
{
	if (!pPlayer)		  return;
	if (IS_DEAD(pPlayer)) return;

	float percentHP = 100*pPlayer->nHP/pPlayer->nMaxHP;
	__try
	{
		if(percentHP <= pLang->autoBarrierLimit && (countBiDanhBoiSkillDinhHuong || CountNPCAttack(pPlayer)))
			DO_SKILL_ITEM(pPlayer, sz__SummonerBarrier);	//==> bat La Chan
	}	
	__except(EXCEPTION_EXECUTE_HANDLER) 
	{ 
		//__oMsg("AutoBarrier, dissssssssgameeeeeeeeeeee");
		SEND_TEXT_SYSTEM("AutoBarrier"); 
	}
}

//======================================================================================================
void AutoIronSolari(KNpc *pPlayer)
{
	if (!pPlayer)		  return;
	if (IS_DEAD(pPlayer)) return;
	__try
	{
		if(!G_Module) return;
		DWORD nTemp1 = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
		DWORD nTemp2 = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;

		DWORD dw1 = *(DWORD*)nTemp1;
		DWORD dw2 = *(DWORD*)nTemp2;
		if(!dw1 || !dw2 ) return;
		int nCount = (dw2 - dw1)/4;
		for(int i = 0; i < nCount; ++i)
		{
			DWORD dw3 = *(DWORD*)(dw1 + 4*i);
			if(dw3 == 0) continue;
			KNpc *ally = (KNpc*)dw3;
			if(ally->IsEnemy(pPlayer->nTeam_ID) || IS_DEAD(ally) || !ally->isTargetable() || !IS_HERO( ally)) continue;
			if(100*(ally->nHP + ally->nGiap_Mau)/ally->nMaxHP > pLang->autoSolariLimit) continue;
			if(Distance_2D(pPlayer->CurrentPos, ally->CurrentPos) > 790) continue;

			if(ally != pPlayer)
			{
				if(CountNPCAttack(ally)) DO_SKILL_ITEM(ally, sz__IronStylus);		//ironstylusbuff, ironstyluscheck : dung day chuyen Iron Solari co 2 cai buff nay
				return;
			}
			else
			{
				if (isRengar && GET_BUFF(pPlayer, sz__RengarR)) continue;		 // -- rengar dang tang hinh || cbi tang hinh ( vua bam R)
				if (countBiDanhBoiSkillDinhHuong || CountNPCAttack(pPlayer)) DO_SKILL_ITEM(pPlayer, sz__IronStylus);
			}
		}
	}	
	__except(EXCEPTION_EXECUTE_HANDLER) 
	{ 
		//__oMsg("AutoIronSolari, dissssssssgameeeeeeeeeeee");
		SEND_TEXT_SYSTEM("AutoIronSolari"); 
	}
}

//==================================================================================//
void AutoDayChuyenChuocToi(KNpc *pPlayer)
{
	if (!pPlayer)		  return;
	if (IS_DEAD(pPlayer)) return;

	__try
	{
		if(!G_Module) return;
		DWORD nTemp1 = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
		DWORD nTemp2 = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;

		DWORD dw1 = *(DWORD*)nTemp1;
		DWORD dw2 = *(DWORD*)nTemp2;
		if(!dw1 || !dw2 ) return;
		int nCount = (dw2 - dw1)/4;
		for(int i = 0; i < nCount; ++i)
		{
			DWORD dw3 = *(DWORD*)(dw1 + 4*i);
			if (dw3 == 0) continue;
			KNpc *ally = (KNpc*)dw3;
			if(ally->IsEnemy(pPlayer->nTeam_ID) || IS_DEAD(ally) || !ally->isTargetable() || !IS_HERO(ally)) continue;
			if(100*ally->nHP/ally->nMaxHP > pLang->autoRedemptionLimit) continue;
			if(Distance_2D(pPlayer->CurrentPos, ally->CurrentPos) > 5500) continue;

			if(ally != pPlayer)
			{
				if(CountNPCAttack(ally)) DO_SKILL_LINE(ally, GET_STT_SKILL(sz__ItemRedemption), 400);
				return;
			}
			else
			{
				if (isRengar && GET_BUFF(pPlayer, sz__RengarR)) continue;		 // -- rengar dang tang hinh || cbi tang hinh ( vua bam R)
				if (countBiDanhBoiSkillDinhHuong || CountNPCAttack(pPlayer)) DO_SKILL_LINE(pPlayer, GET_STT_SKILL(sz__ItemRedemption), 400);
			}
		}
	}	
	__except(EXCEPTION_EXECUTE_HANDLER) 
	{ 
		//__oMsg("AutoDayChuyenChuocToi, dissssssssgameeeeeeeeeeee");
		SEND_TEXT_SYSTEM("AutoDayChuyenChuocToi"); 
	}
}

//======================================================================================================
void AutoSeraphs(KNpc *pPlayer)
{
	if (!pPlayer)		  return;
	if (IS_DEAD(pPlayer)) return;
	__try
	{
		float percentHP   = 100*(pPlayer->nHP + pPlayer->nGiap_Mau)/pPlayer->nMaxHP;

		if(percentHP <= pLang->autoSeraphLimit && (countBiDanhBoiSkillDinhHuong || CountNPCAttack(pPlayer)) && !GET_BUFF(pPlayer , sz__zhonyasringshield))
		{
			DO_SKILL_ITEM(pPlayer, sz__ItemSeraphsEmbrace);			//==> Gay Dai Thien Su
		}
	}	
	__except(EXCEPTION_EXECUTE_HANDLER) 
	{ 
		//__oMsg("AutoSeraphs, dissssssssgameeeeeeeeeeee");
		SEND_TEXT_SYSTEM("AutoSeraphs"); 
	}
}

//======================================================================================================
void AutoZhonyas(KNpc *pPlayer)
{
	if (!pPlayer)		  return;
	if (IS_DEAD(pPlayer)) return;
	__try
	{
		float percentHP   = 100*(pPlayer->nHP + pPlayer->nGiap_Mau)/pPlayer->nMaxHP;
		//int countEnemyAround = Count_EnemyPlayer_Around_NPC(pPlayer, 300);

		if(percentHP <= pLang->autoZhonyaLimit && (countBiDanhBoiSkillDinhHuong || CountNPCAttack(pPlayer)))
		{
			DO_SKILL_ITEM(pPlayer,  "Item2420");						//==> stopwatch
			DO_SKILL_ITEM(pPlayer, sz__ZhonyasHourglass);			//==> Dong Ho Cat
		}
	}	
	__except(EXCEPTION_EXECUTE_HANDLER) 
	{ 
		//__oMsg("AutoZhonyas, dissssssssgameeeeeeeeeeee");
		SEND_TEXT_SYSTEM("AutoZhonyas"); 
	}
}

//======================================================================================================
float timeDoMikael, timeDoMecur, timeDoClease, timeDelayDoCleaseEx = 0;
void AutoCleaseMercurial(KNpc *pPlayer)
{
	if (pPlayer == 0)      return;
	if (IS_DEAD(pPlayer)) return;
	timeDelayDoCleaseEx += SYS_TIMER;
	
	if (timeDelayDoCleaseEx > 200 && (hasMikael || hasSummonCleanse || hasGiaiThuat))
	{
		int buffDungIm = GET_BUFF_DUNGIM(pPlayer);
		int buffBatLoi = GET_BUFF_BATLOI(pPlayer);
		int cur_Buff   = buffDungIm != 0 ? buffDungIm : buffBatLoi;

		if (cur_Buff != 0)
		{
			//-- do Mikael -----------
			if (hasMikael)
			{
				int curBuff1 = GET_BUFF_MIKAEL(pPlayer);
				if (curBuff1)
				{
					timeDoMikael += SYS_TIMER;
					if (timeDoMikael >= pLang->autoCleanseQuickSilverMercurialMikael_Limit)
					{
						if ((pLang->isQss_Stun  && curBuff1 == Stun_Buff )	|| 
							(pLang->isQss_Sleep && curBuff1 == Sleep_Buff)	|| 
							(pLang->isQss_Taunt && curBuff1 == Taunt_Buff)	|| 
							(pLang->isQss_Snare && curBuff1 == Snare_Buff)	|| 
							(pLang->isQss_Fear  && (curBuff1 == Fear_Buff || GET_BUFF(pPlayer, "fleeslow")))	||
							(pLang->isQss_Silence  && curBuff1 == Silence_Buff))
						{
							if (DO_SKILL_ITEM(pPlayer, sz__ItemMorellosBane))   //==> Mikael
							{
								timeDoMikael         = 0;
								timeDelayDoCleaseEx  = 0;
								return;
							}
						}
					}
				}
			}
			
			//-- do ThanhTay -----------
			if (hasSummonCleanse)
			{
				int curBuff2 = GET_BUFF_THANHTAY(pPlayer);
				if (curBuff2)
				{
					timeDoClease += SYS_TIMER;
					if (timeDoClease >= pLang->autoCleanseQuickSilverMercurialMikael_Limit)
					{
						if ((pLang->isQss_Stun  && curBuff2 == Stun_Buff )	||
							(pLang->isQss_Sleep && curBuff2 == Sleep_Buff)	|| 
							(pLang->isQss_Taunt && curBuff2 == Taunt_Buff)	||
							(pLang->isQss_Charm && curBuff2 == Charm_Buff)	||
							(pLang->isQss_Snare && curBuff2 == Snare_Buff)	|| 
							(pLang->isQss_Fear  && (curBuff2 == Fear_Buff || GET_BUFF(pPlayer, "fleeslow")))	||
							(pLang->isQss_Flee  && curBuff2 == Flee_Buff )	||
							(pLang->isQss_Blind && curBuff2 == Blind_Buff)	||
							(pLang->isQss_Polymorph && curBuff2 == Polymorph_Buff)||
							(pLang->isQss_Silence  && curBuff2 == Silence_Buff))
						{
							if (DO_SKILL_ITEM(pPlayer, sz__SummonerBoost))   //==> Thanh Tay
							{
								//__oMsg("Thanh Tay: %f", timeDelayDoCleaseEx);
								timeDoClease         = 0;
								timeDelayDoCleaseEx  = 0;
								return;
							}
						}
					}
				}
			}
			
			//-- do KhanGiaiThuat+DaoThuyNgan -----------
			timeDoMecur += SYS_TIMER;
			if (hasGiaiThuat)
			{
				if (timeDoMecur >= pLang->autoCleanseQuickSilverMercurialMikael_Limit)
				{
					if ((pLang->isQss_Suppression && cur_Buff == Suppression_Buff )||
						(pLang->isQss_Stun  && cur_Buff == Stun_Buff )	||
						(pLang->isQss_Sleep && cur_Buff == Sleep_Buff)	|| 
						(pLang->isQss_Taunt && cur_Buff == Taunt_Buff)	||
						(pLang->isQss_Charm && cur_Buff == Charm_Buff)	||
						(pLang->isQss_Snare && cur_Buff == Snare_Buff)	|| 
						(pLang->isQss_Fear  && (cur_Buff == Fear_Buff || GET_BUFF(pPlayer, "fleeslow")))	||
						(pLang->isQss_Flee  && cur_Buff == Flee_Buff )	||
						(pLang->isQss_Blind && cur_Buff == Blind_Buff)	||
						(pLang->isQss_Polymorph && cur_Buff == Polymorph_Buff)||
						(pLang->isQss_Silence && cur_Buff == Silence_Buff))
					{
						if (DO_SKILL_ITEM(pPlayer, sz__QuicksilverSash))   //==> KhanGiaiThuat
						{
							//__oMsg("DoKhanGiaiThuat: %f", timeDelayDoCleaseEx);
							timeDoMecur          = 0;
							timeDelayDoCleaseEx  = 0;
							return;
						}
						if (DO_SKILL_ITEM(pPlayer, sz__ItemMercurial))    //==> DaoThuyNgan
						{
							//__oMsg("DaoThuyNgan: %f", timeDelayDoCleaseEx);
							timeDoMecur          = 0;
							timeDelayDoCleaseEx  = 0;
							return;
						}
					}
				}
			}
		}
		else if (pLang->isQss_Slow &&  pPlayer->nMoveSpeed < pLang->Qss_SlowMoveSpeed)	//---- Qss-Slow :
		{
			KBuffs* plantSlow  = GET_BUFF(pPlayer, "planthealthslow");
			KBuffs* dragonSlow = GET_BUFF(pPlayer, "waterdragonslow");
			bool hasSlow_1 = false;
			if ((plantSlow || dragonSlow) && (COUNT_BUFF_BY_TYPE(pPlayer, Slow_Buff) >= 2))
				hasSlow_1 = true;
			//__oMsg("plantSlow: %d, dragonSlow: %d, hasSlow_1: %d, countSlow: %d", plantSlow, dragonSlow, hasSlow_1, COUNT_BUFF_BY_TYPE(pPlayer, Slow_Buff));
			if ((!plantSlow && !dragonSlow) || hasSlow_1 == true)
			{
				if (hasMikael)
				{
					timeDoMikael += SYS_TIMER;
					if (timeDoMikael >= pLang->autoCleanseQuickSilverMercurialMikael_Limit)
					{
						if (DO_SKILL_ITEM(pPlayer, sz__ItemMorellosBane))   //==> Mikael
						{
							//__oMsg("Mikael: %f", timeDelayDoCleaseEx);
							timeDoMikael         = 0;
							timeDelayDoCleaseEx  = 0;
							return;
						}
					}
				}
				if (hasSummonCleanse)
				{
					timeDoClease += SYS_TIMER;
					if (timeDoClease >= pLang->autoCleanseQuickSilverMercurialMikael_Limit)
					{
						if (DO_SKILL_ITEM(pPlayer, sz__SummonerBoost))   //==> Thanh Tay
						{
							//__oMsg("Thanh Tay: %f", timeDelayDoCleaseEx);
							timeDoClease         = 0;
							timeDelayDoCleaseEx  = 0;
							return;
						}
					}
				}
				if (hasGiaiThuat)
				{
					timeDoMecur += SYS_TIMER;
					if (timeDoMecur >= pLang->autoCleanseQuickSilverMercurialMikael_Limit)
					{
						if (DO_SKILL_ITEM(pPlayer, sz__QuicksilverSash))   //==> KhanGiaiThuat
						{
							//__oMsg("KhanGiaiThuat: %f", timeDelayDoCleaseEx);
							timeDoMecur          = 0;
							timeDelayDoCleaseEx  = 0;
							return;
						}
						if (DO_SKILL_ITEM(pPlayer, sz__ItemMercurial))    //==> DaoThuyNgan
						{
							//__oMsg("DaoThuyNgan: %f", timeDelayDoCleaseEx);
							timeDoMecur          = 0;
							timeDelayDoCleaseEx  = 0;
							return;
						}
					}
				}
			}
		}
		else
		{ 
			timeDoMikael = 0;
			timeDoClease = 0;
			timeDoMecur  = 0; 
		}
	}
}

//======================================================================================================
void AutoIgnite()
{
	__try
	{
		KNpc* target = GetTargetSelector(0, 625, DmgPhysical);
		if(target && GetPlayer())
		{
			float damage = (float)(55 + (BYTE)GetPlayer()->nLevel * 25);
			if(pLang->isAutoIgniteOnOff && target->nHP/damage <= pLang->sliderIgnite)
			{
				DO_IGNITE(target);
			}
		}
	}	
	__except(EXCEPTION_EXECUTE_HANDLER) 
	{ 
		//__oMsg("AutoIgnite, dissssssssgameeeeeeeeeeee");
		SEND_TEXT_SYSTEM("AutoIgnite"); 
	}
}

//======================================================================================================
void AutoKhienBang(KNpc *pPlayer)
{
	if(pPlayer == 0)      return;
	if(IS_DEAD(pPlayer)) return;
	__try
	{
		if(!G_Module) return;
		DWORD nTemp1 = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
		DWORD nTemp2 = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;

		DWORD dw1 = *(DWORD*)nTemp1;
		DWORD dw2 = *(DWORD*)nTemp2;
		if (!dw1 || !dw2 ) return;

		int nCount = (dw2 - dw1)/4;
		int nCountEnemyInKhienBang = 0;
		for(int i = 0; i < nCount; ++i)
		{
			DWORD dw3 = *(DWORD*)(dw1 + 4*i);
			if(dw3 == 0) continue;
			KNpc *pEnemy = (KNpc*)dw3;
			if(!pEnemy->IsEnemy(pPlayer->nTeam_ID) || IS_DEAD(pEnemy) || !pEnemy->isTargetable() || !IS_HERO(pEnemy)) continue;
			if(Distance_2D(pPlayer->CurrentPos, pEnemy->CurrentPos) <= 475) // 475 la Radius cua Khien Bang
			{
				nCountEnemyInKhienBang += 1;
			}
		}
		if(nCountEnemyInKhienBang > pLang->autoRandunin_Limit)
		{
			if (isRengar)
			{
				if(GET_BUFF(pPlayer,  (sz__RengarR))) return;				// -- rengar dang tang hinh || cbi tang hinh ( vua bam R)
			}
			if (isKhazix)
			{
				if(GET_BUFF(pPlayer, sz__khazixrstealth)) return;			// -- Khazix dang tang hinh
			}
			if (isShaco)
			{
				if(GET_BUFF(pPlayer,  (sz__Deceive))) return;				// -- Shaco dang tang hinh				
			}

			DO_SKILL_ITEM(pPlayer, sz__RanduinsOmen);						//==> Khien Bang
		}
	}	
	__except(EXCEPTION_EXECUTE_HANDLER) 
	{ 
		//__oMsg("AutoKhienBang, dissssssssgameeeeeeeeeeee");
		SEND_TEXT_SYSTEM("AutoKhienBang"); 
	}
}

//======================================================================================================
void AutoRiuMangXa(KNpc *pPlayer)
{
	if(pPlayer == 0)      return;
	if(IS_DEAD(pPlayer)) return;
	
	if(!G_Module) return;
	DWORD nTemp1 = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	DWORD nTemp2 = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;

	DWORD dw1 = *(DWORD*)nTemp1;
	DWORD dw2 = *(DWORD*)nTemp2;
	if (!dw1 || !dw2 ) return;

	int nCount = (dw2 - dw1)/4;
	int nCountEnemyInTiamat    = 0;
	for(int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if(dw3 == 0) continue;
		KNpc *pEnemy = (KNpc*)dw3;
		if(!pEnemy->IsEnemy(pPlayer->nTeam_ID) || IS_DEAD(pEnemy) || !pEnemy->isTargetable() || !IS_HERO(pEnemy)) continue;
		if(Distance_2D(pPlayer->CurrentPos, pEnemy->CurrentPos) < 300) // 300 la Radius cua Tiamat
		{
			nCountEnemyInTiamat += 1;
		}
	}
	if (nCountEnemyInTiamat > pLang->autoTiamatHydra_Limit)
	{
		if (isRengar)
		{
			if (GET_BUFF(pPlayer,  (sz__RengarR))) return; // -- rengar dang tang hinh || cbi tang hinh ( vua bam R)
		}
		if (isKhazix)
		{
			if (GET_BUFF(pPlayer, sz__khazixrstealth)) return;			 // -- Khazix dang tang hinh
		}
		if (isShaco)
		{
			if (GET_BUFF(pPlayer, sz__Deceive)) return;								// -- Shaco dang tang hinh				
		}

		DO_SKILL_ITEM(pPlayer, sz__ItemTiamatCleave);			//==> Riu Tiamat + Riu Mang Xa 
		DO_SKILL_ITEM(pPlayer, sz__ItemTitanicHydraCleave);		//==> Riu Dai Mang Xa			
	}
}

//======================================================================================================
void AutoVoDanh(KNpc *pPlayer)
{
	if(pPlayer == 0)      return;
	if(IS_DEAD(pPlayer)) return;

	__try
	{
		KNpc* target = GetTargetSelector(0, 600, DmgPhysical);
		if (target && target->percentHP() < pLang->fAutoBilgewaterRuinedKing_LimitHP)
		{
			if (isRengar)
			{
				if(GET_BUFF(pPlayer,  (sz__RengarR))) return;					// -- Rengar dang tang hinh || cbi tang hinh ( vua bam R)
			}
			if (isKhazix)
			{
				if(GET_BUFF(pPlayer, sz__khazixrstealth)) return;			// -- Khazix dang tang hinh
			}
			if (isShaco)
			{
				if(GET_BUFF(pPlayer, sz__Deceive)) return;					// -- Shaco dang tang hinh
			}

			DO_SKILL_ITEM(target,  sz__BilgewaterCutlass);				//==> Kiem Hai Tac
			DO_SKILL_ITEM(target,  sz__ItemSwordOfFeastAndFamine);		//==> Guom Vo Danh
		}
	}	
	__except(EXCEPTION_EXECUTE_HANDLER) 
	{ 
		//__oMsg("AutoVoDanh, dissssssssgameeeeeeeeeeee");
		SEND_TEXT_SYSTEM("AutoVoDanh"); 
	}
}

//======================================================================================================
void AutoHextech(KNpc *pPlayer)
{
	if(pPlayer == 0)      return;
	if (IS_DEAD(pPlayer)) return;

	KNpc* target = GetTargetSelector(0, 750, DmgMagical);
	if(target)
	{
		if (isRengar)
		{
			if(GET_BUFF(pPlayer,  (sz__RengarR))) return;					// -- Rengar dang tang hinh || cbi tang hinh ( vua bam R)
		}
		if (isKhazix)
		{
			if(GET_BUFF(pPlayer, sz__khazixrstealth)) return;			// -- Khazix dang tang hinh
		}
		if (isShaco)
		{
			if(GET_BUFF(pPlayer, sz__Deceive)) return;					// -- Shaco dang tang hinh
		}

		DO_SKILL_ITEM(target, sz__HextechGunblade);							 //==> Kiem Sung HextechGunblade
		DO_SKILL_LINE(target, GET_STT_SKILL(sz__ItemSoFBoltSpellBase), 200); //==> Dai Lung Hextech
		DO_SKILL_LINE(target, GET_STT_SKILL(sz__ItemWillBoltSpellBase), 200);//==> Sung Ngan Hextech
	}
}



//======================================================================================================
bool  Use_Smite_Kill_Steal, Use_Smite_in_Combo, Use_Smite_Small_Jungle, Use_Smite_Blue, Use_Smite_Red, Use_Smite_Dragon, Use_Smite_Baron, Use_Smite_RiftHerald, Use_Smite_Rift_Scuttler;
bool  Use_Smite_Spider, Use_Smite_Wolf, Use_Smite_Wraith, Use_Smite_Golem;
float smiteRange = 600.0f;
int   _enableSmite_Key;
bool  _enable_Smite;
void  Smite_MenuValueDefault()
{
	_enable_Smite		   = menu_IniFile->ReadBoolean("AutoSmiteCore", "Enabled Auto Smite", true);		// co bien pLang->isAutoSmiteOnOff roi, nhung ko dung`
	_enableSmite_Key       = menu_IniFile->ReadInteger("AutoSmiteCore", "Enabled Smite Key", 73);			// Phim I

	Use_Smite_Kill_Steal   = menu_IniFile->ReadBoolean("AutoSmiteCore", "Auto Smite KS", true);
	Use_Smite_in_Combo     = menu_IniFile->ReadBoolean("AutoSmiteCore", "Auto Smite in Combo", true);
	smiteRange             = menu_IniFile->ReadFloat("AutoSmiteCore", "Smite Range", 650.0f);
	Use_Smite_Baron        = menu_IniFile->ReadBoolean("AutoSmiteCore", "Auto Smite Baron", true);
	Use_Smite_Dragon	   = menu_IniFile->ReadBoolean("AutoSmiteCore", "Auto Smite Dragon", true);
	Use_Smite_RiftHerald   = menu_IniFile->ReadBoolean("AutoSmiteCore", "Auto Smite RiftHerald", true);
	Use_Smite_Rift_Scuttler= menu_IniFile->ReadBoolean("AutoSmiteCore", "Auto Smite RiftScuttler", true);
	Use_Smite_Red	       = menu_IniFile->ReadBoolean("AutoSmiteCore", "Auto Smite Red", true);
	Use_Smite_Blue		   = menu_IniFile->ReadBoolean("AutoSmiteCore", "Auto Smite Blue", true);
	Use_Smite_Small_Jungle = menu_IniFile->ReadBoolean("AutoSmiteCore", "Auto Smite Small Jungle", false);
	//-------3v3 map:
	Use_Smite_Spider       = menu_IniFile->ReadBoolean("AutoSmiteCore", "Auto Smite SpiderBoss", true);
	Use_Smite_Wolf         = menu_IniFile->ReadBoolean("AutoSmiteCore", "Auto Smite Wolf", false);
	Use_Smite_Wraith       = menu_IniFile->ReadBoolean("AutoSmiteCore", "Auto Smite Wraith", false);
	Use_Smite_Golem        = menu_IniFile->ReadBoolean("AutoSmiteCore", "Auto Smite Golem", false);
}

//======================================================================================================
void  Smite_OnDrawMenu()
{
	if (Menu_Begin("Auto Smite"))
	{
		if (Menu_Begin("Auto Smite"))
		{
			Menu_Bool("Enabled Auto Smite", "Enabled Auto Smite", &_enable_Smite, "AutoSmiteCore");
			Menu_KeyBinding("Smite-Key", "Enabled Smite Key", &_enableSmite_Key, "AutoSmiteCore");
			Menu_End();
		}

		Use_Smite_Kill_Steal   = Menu_Bool("Auto Smite KS", "Auto Smite KS", &Use_Smite_Kill_Steal, "AutoSmiteCore");
		Use_Smite_in_Combo     = Menu_Bool("Auto Smite in Combo", "Auto Smite in Combo", &Use_Smite_in_Combo, "AutoSmiteCore");
		smiteRange			   = Menu_SliderFloat("Smite Range (combo+KS)", "Smite Range", &smiteRange, 0, 650.0f, "AutoSmiteCore");
		Menu_Separator();
		Use_Smite_Baron		   = Menu_Bool("Baron", "Auto Smite Baron", &Use_Smite_Baron, "AutoSmiteCore");
		Use_Smite_Dragon	   = Menu_Bool("Dragon", "Auto Smite Dragon", &Use_Smite_Dragon, "AutoSmiteCore");
		Use_Smite_RiftHerald   = Menu_Bool("RiftHerald", "Auto Smite RiftHerald", &Use_Smite_RiftHerald, "AutoSmiteCore");
		Use_Smite_Rift_Scuttler= Menu_Bool("RiftScuttler", "Auto Smite RiftScuttler", &Use_Smite_Rift_Scuttler, "AutoSmiteCore");
		Use_Smite_Red          = Menu_Bool("Red", "Auto Smite Red", &Use_Smite_Red, "AutoSmiteCore");
		Use_Smite_Blue         = Menu_Bool("Blue", "Auto Smite Blue", &Use_Smite_Blue, "AutoSmiteCore");
		Use_Smite_Small_Jungle = Menu_Bool("Gromp / Krug / Razorbeak / Murkwolf", "Auto Smite Small Jungle", &Use_Smite_Small_Jungle, "AutoSmiteCore");
		
		Menu_Separator();
		Menu_Bool("Spider Boss", "Auto Smite SpiderBoss", &Use_Smite_Spider, "AutoSmiteCore");
		Menu_Bool("Wolf", "Auto Smite Wolf", &Use_Smite_Wolf, "AutoSmiteCore");
		Menu_Bool("Wraith", "Auto Smite Wraith", &Use_Smite_Wraith, "AutoSmiteCore");
		Menu_Bool("Golem", "Auto Smite Golem", &Use_Smite_Golem, "AutoSmiteCore");

		Menu_End();
	}
}

//======================================================================================================
void  Draw_Smite_Status()
{
	if (!pLang->isDrawingOnOff) return;
	
	KNpc* myHero = GetPlayer();
	if (!myHero) return;
	
	KPos heroPosOut, worldPos;				//for leftEndPos
	worldPos = myHero->CurrentPos;
	WorldPos_to_ScreenPos(&worldPos, &heroPosOut);

	Vec3D heroPos(heroPosOut.x, heroPosOut.y, heroPosOut.z);
	float dimension = 26.0f;

	if(_enable_Smite) PrintTextBold("Smite : ON", 16 , sz__Arial, heroPos.x - dimension, heroPos.y + 1.69f*dimension, heroPos.x, heroPos.y, YELLOW,  Get_Device());
	else			  PrintTextBold("Smite : OFF", 16, sz__Arial, heroPos.x - dimension, heroPos.y + 1.69f*dimension, heroPos.x, heroPos.y, WHITE ,  Get_Device());
}

//======================================================================================================
float GetSmiteDamage(KNpc *pPlayer, KNpc *target)
{
	if (!pPlayer || !target) return 0;
	if (indexTP > -1)
	{
		if (IS_HERO(target))
		{
			if (hasTPxanh) return (20.0f + 8*(BYTE)pPlayer->nLevel); // S5_SummonerSmitePlayerGanker
			if (hasTPdo)   return (54.0f + 6*(BYTE)pPlayer->nLevel);	// S5_SummonerSmiteDuel
		}
		else
		{
			float  dmg[19] = {0, 390, 410, 430, 450, 480, 510, 540, 570, 600, 640, 680, 720, 760, 800, 850, 900, 950, 1000};
			return dmg[(BYTE)pPlayer->nLevel];
		}
	}
	return 0;
}

//======================================================================================================
void LogicSmiteJungle(KNpc *pPlayer)	//KS + smite quai rung, smiteCombo o onB4Attack
{
	if (_enable_Smite == false) return;
	if (indexTP == -1)			return;
	if (!pPlayer)				return;
	if (!G_Module)				return;

	//__try
	{
		if (IS_DEAD(pPlayer))  return;
		if (!CanCast(indexTP)) return;
	
		
		if (Use_Smite_Kill_Steal)
		{
			KNpc* targetKS = GetTargetSelector(pPlayer, 1500, DmgPhysical);
			if (targetKS && Distance(targetKS, pPlayer) < smiteRange && GetSmiteDamage(pPlayer, targetKS) > targetKS->nHP) 
			{ 
				Cast2Target(targetKS, indexTP); 
				return; 
			}
		}
		
		if (nCombo_Mode && Use_Smite_in_Combo)
		{
			KNpc* target = GetTargetSelector(pPlayer, 1500, DmgPhysical);
			if (target && Distance(target, pPlayer) < smiteRange)
			{ 
				Cast2Target(target, indexTP); 
				return; 
			}
		}

		DWORD tempUnit    = BASE_AttackableUnit - TEMP_ENTRY_POINT	   + G_Module;
		DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;

		DWORD dw1 = *(DWORD*)tempUnit;
		DWORD dw2 = *(DWORD*)tempUnitMax;
		if (!dw1 || !dw2 ) return;

		int nCount = (dw2 - dw1)/4;

		for (int i = 0; i < nCount; ++i)
		{
			DWORD dw3 = *(DWORD*)(dw1 + 4*i);
			if (dw3 == 0) continue;
			KNpc *jungle = (KNpc*)dw3;

			if (jungle->nTeam_ID != 0x12C)   continue;
			if (!IS_MINION(jungle))			 continue;

			if (!IsValidTarget(jungle, 650)) continue;
			if (jungle->nMaxHP < 10)		 continue;


			float dmgSmite  = GetSmiteDamage(pPlayer, jungle);
			float colisionR = jungle->nOverrideCollisionRadius;

			if(Use_Smite_Baron  && dmgSmite > jungle->nHP && colisionR == 180.0f)		//SRU_Baron12.1.1      , COL = 180.000000 - 105.000000 (BoundRadius)
			{ 
				Cast2Target(jungle, indexTP); 
				return; 
			}	 

			if(Use_Smite_Dragon && dmgSmite > jungle->nHP && colisionR == 200.0f)		//SRU_Dragon_Elder6.5.1, COL = 200.000000 - 125.000000 (BoundRadius)
			{ 
				Cast2Target(jungle, indexTP); 
				return; 
			}

			if(Use_Smite_RiftHerald && dmgSmite > jungle->nHP && colisionR == 120.0f	//SRU_RiftHerald17.1.1 , COL = 120.000000 - 110.000000 (BoundRadius)
				&& jungle->nMaxHP > 3000.0f)	
			{
				Cast2Target(jungle, indexTP); 
				return; 
			}	
			
			if(Use_Smite_Blue   && dmgSmite > jungle->nHP && colisionR == 120.0f		//SRU_Blue1.1.1, COL = 120.000000 - 131.000000 (BoundRadius)
				&& jungle->nMaxHP < 3000.0f)
			{ 
				Cast2Target(jungle, indexTP); 
				return; 
			}

			if(Use_Smite_Red	&& dmgSmite > jungle->nHP && colisionR == 145.0f)		//SRU_Red4.1.1 , COL = 145.000000 - 120.000000 (BoundRadius)
			{
				Cast2Target(jungle, indexTP); 
				return; 
			}

			if(Use_Smite_Rift_Scuttler && dmgSmite > jungle->nHP && colisionR == 110.0f) //Sru_Crab16.1.1 ,    COL = 110.000000 - 50.000000	(BoundRadius)
			{
				Cast2Target(jungle, indexTP); 
				return; 
			}	

																						//SRU_Razorbeak3.1.1, COL = 70.000000  - 75.000000	(BoundRadius)
																						//SRU_Krug5.1.1,      COL = 100.000000 - 100.000000 (BoundRadius)
																						//SRU_Murkwolf2.1.1,  COL = 100.000000 - 80.000000	(BoundRadius)
			if(Use_Smite_Small_Jungle && dmgSmite > jungle->nHP && (colisionR == 70.0f || colisionR == 100.0f))
			{
				Cast2Target(jungle, indexTP); 
				return; 
			}


			//////if (!CheckName(sz__SRU_, jungle->GetNameNpc()) && !CheckName(sz__Sru_, jungle->GetNameNpc()) 
			//////	&& !CheckName("TT_N", jungle->GetNameNpc()) && !CheckName("TT_S", jungle->GetNameNpc())
			//////	&& !CheckName("Sru_Crab", jungle->GetNameNpc())
			//////	) continue;
			//////
			//////float dmgSmite = GetSmiteDamage(pPlayer, jungle);
			//////
			//////if(Use_Smite_Baron  && CheckName(jungle->GetNameHero(), sz__SRU_Baron)  && dmgSmite > jungle->nHP) { Cast2Target(jungle, indexTP); return; }	 
			//////if(Use_Smite_Dragon && CheckName(sz__SRU_Dragon, jungle->GetNameHero()) && dmgSmite > jungle->nHP) { Cast2Target(jungle, indexTP); return; }// rong check ten nguoc lai 
			//////if(Use_Smite_Red    && CheckName(jungle->GetNameHero(), sz__SRU_Red)    && dmgSmite > jungle->nHP) { Cast2Target(jungle, indexTP); return; }
			//////if(Use_Smite_Blue   && CheckName(jungle->GetNameHero(), sz__SRU_Blue)   && dmgSmite > jungle->nHP) { Cast2Target(jungle, indexTP); return; }	
			//////if(Use_Smite_RiftHerald && CheckName(jungle->GetNameHero(), sz__SRU_RiftHerald) && dmgSmite > jungle->nHP) {Cast2Target(jungle, indexTP); return; }	 
			//////if(Use_Smite_Rift_Scuttler && CheckName(jungle->GetNameHero(), "Sru_Crab") && dmgSmite > jungle->nHP) {Cast2Target(jungle, indexTP); return; }	
			//////
			//////if(CheckName(jungle->GetNameHero(), sz__SRU_Gromp) || CheckName(jungle->GetNameHero(), sz__SRU_Razorbeak) ||
			//////	CheckName(jungle->GetNameHero(), sz__SRU_Krug)  || CheckName(jungle->GetNameHero(), sz__SRU_Murkwolf))/* || CheckName(jungle->GetNameHero(), sz__Sru_Crab)*/
			//////{
			//////	if(Use_Smite_Small_Jungle && dmgSmite > jungle->nHP) { Cast2Target(jungle, indexTP); return; }
			//////}
			//////
			//////if(Use_Smite_Spider  && CheckName(jungle->GetNameHero(), "TT_Spiderboss")  && dmgSmite > jungle->nHP) { Cast2Target(jungle, indexTP); return; }	 
			//////if(Use_Smite_Wolf    && CheckName(jungle->GetNameHero(), "TT_NWolf")       && dmgSmite > jungle->nHP) { Cast2Target(jungle, indexTP); return; }	 
			//////if(Use_Smite_Wraith  && CheckName(jungle->GetNameHero(), "TT_NWraith")     && dmgSmite > jungle->nHP) { Cast2Target(jungle, indexTP); return; }	 
			//////if(Use_Smite_Golem   && CheckName(jungle->GetNameHero(), "TT_NGolem")      && dmgSmite > jungle->nHP) { Cast2Target(jungle, indexTP); return; }	 
		}

	}
	//__except(EXCEPTION_EXECUTE_HANDLER)
	//{
	//	SEND_TEXT_SYSTEM("Logic Smite Jungle ..");
	//}
}

//==================================================================================//
extern KTS_Prio _allyList[10];
void Mikael_MenuValueDefault()
{
	prio_allyList();

	//for(int i = 0; i < 10; ++i) 
	//{
	//	_allyList[i].nPrio = GetDBPriority(_allyList[i].charName);
	//}
}

//==================================================================================//
void cbMikaelDrawMenu()
{
	if(Menu_Begin("Setting Mikael Allies Saver"))
	{
		for (int i = 0; i < 10; ++i)
		{
			if(_allyList[i].networkID == 0) continue;
			_allyList[i].nPrio = Menu_SliderInt_KoSave(_allyList[i].charName, &_allyList[i].nPrio, 0, 5);
		}		
		Menu_End();
	}
}

//==================================================================================//
void Mikael_update(KNpc *pPlayer)
{
	//--- Do Mikael cho tuong dong minh ----------------
	if (!hasMikael)							 return;
	if (!pLang->doMikael4allies)			 return;
	if (!pPlayer || !G_Module || !myTeamId)  return;
	
	int	  mucuutien_hardCC	   = 0;
	KNpc* Lulu_BestAlly_hardCC = 0;
	
	int	  mucuutien_slow       = 0;
	KNpc* Lulu_BestAlly_slow   = 0;

	DWORD nTemp1 = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	DWORD nTemp2 = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dw1 = *(DWORD*)nTemp1;
	DWORD dw2 = *(DWORD*)nTemp2;
	if (!dw1 || !dw2 ) return;

	int nCount = (dw2 - dw1)/4;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *ally = (KNpc*)dw3;

		//if (pPlayer == ally)			continue;		// sao lai k dung` cho ban than ???

		if (ally->nTeam_ID != myTeamId) continue;
		if (IS_DEAD(ally))				continue;		
		if (!ally->isTargetable())		continue;

		if (Distance_2D(pPlayer->CurrentPos, ally->CurrentPos) > 750) continue;

		int curBuff_mk = GET_BUFF_MIKAEL(ally);
		if (curBuff_mk)
		{
			if ((pLang->isQss_Stun  && curBuff_mk == Stun_Buff )	|| 
				(pLang->isQss_Sleep && curBuff_mk == Sleep_Buff)	|| 
				(pLang->isQss_Taunt && curBuff_mk == Taunt_Buff)	|| 
				(pLang->isQss_Snare && curBuff_mk == Snare_Buff)	|| 
				(pLang->isQss_Fear  && (curBuff_mk == Fear_Buff		|| GET_BUFF(ally, "fleeslow")))	||
				(pLang->isQss_Silence && curBuff_mk == Silence_Buff))
			{
				//DO_SKILL_ITEM(ally, sz__ItemMorellosBane); 
				//return;
				for (int j = 0; j < 10; ++j)
				{
					if (_allyList[j].networkID && _allyList[j].nPrio > 0 && ally->nIndex == _allyList[j].networkID)
					{
						if (_allyList[j].nPrio > mucuutien_hardCC)
						{
							mucuutien_hardCC     = _allyList[j].nPrio;
							Lulu_BestAlly_hardCC = ally;
						}
					}
				}
			}
		}

		if (pLang->isQss_Slow  && ally->nMoveSpeed < pLang->Qss_SlowMoveSpeed)
		{
			//KBuffs* plantSlow  = GET_BUFF(ally, "planthealthslow");
			//KBuffs* dragonSlow = GET_BUFF(ally, "waterdragonslow");

			bool has_2Slow = false;
			if ((COUNT_BUFF_BY_TYPE(ally, Slow_Buff) >= 2) && (GET_BUFF(ally, "planthealthslow") || GET_BUFF(ally, "waterdragonslow")))
				has_2Slow = true;

			//__oMsg("plantSlow: %d, dragonSlow: %d, hasSlow_1: %d, countSlow: %d", plantSlow, dragonSlow, hasSlow_1, COUNT_BUFF_BY_TYPE(ally, Slow_Buff));

			if (has_2Slow == true || (!GET_BUFF(ally, "planthealthslow") && !GET_BUFF(ally, "waterdragonslow")))
			{
				for(int j = 0; j < 10; ++j)
				{
					if(_allyList[j].networkID && _allyList[j].nPrio > 0 && ally->nIndex == _allyList[j].networkID)
					{
						if (_allyList[j].nPrio > mucuutien_slow)
						{
							mucuutien_slow	   = _allyList[j].nPrio;
							Lulu_BestAlly_slow = ally;
						}
					}
				}
			}
		}
	}

	//------ Uu tien cuu thang hard.CC truoc --------------------:
	if (Lulu_BestAlly_hardCC)
	{
		DO_SKILL_ITEM(Lulu_BestAlly_hardCC, sz__ItemMorellosBane); 
		return;
	}
	else if (Lulu_BestAlly_slow)
	{
		DO_SKILL_ITEM(Lulu_BestAlly_slow, sz__ItemMorellosBane); 
		return;
	}
}

//==================================================================================//
//============= AUTO-FUCK-WARD =====================================================//
KNpc* Get_EnemyLongDen_Around(KNpc* hero, float nRange)
{
	if (!hero || !G_Module || !myTeamId)  return 0;
	if (IS_DEAD(hero)) return 0;

	DWORD nTempUnit    = BASE_AttackableUnit     - TEMP_ENTRY_POINT + G_Module;
	DWORD nTempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dw1 = *(DWORD*)nTempUnit;
	DWORD dw2 = *(DWORD*)nTempUnitMax;
	if (!dw1 || !dw2 ) return 0;

	int nCount = (dw2 - dw1)/4;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc* pObject = (KNpc*)dw3;

		if (pObject->nTeam_ID == 0x12C)    continue;
		if (pObject->nTeam_ID == myTeamId) continue;
		if (!IS_MINION(pObject))		   continue;
		if (IS_DEAD(pObject))			   continue;
		
		//if ((BYTE)pLong_Den->nIsTargetableToTeam == 4) continue;
	
		if (Distance(hero, pObject) > nRange) continue;

		if (CheckName("ThreshLantern", pObject->GetNameNpc()))
		{
			return pObject;
		}
	}
	return 0;
}

//==================================================================================//
int GetMySkillWardIndex()
{
	int index = GET_STT_SKILL(sz__ItemGhostWard);
	if (index > 0)
	{
		if (CanCast(index)) return index;
	}
	
	index = GET_STT_SKILL(sz__TrinketTotemLvl1);
	if (index > 0)
	{
		if (CanCast(index)) return index;
	}

	index = GET_STT_SKILL("TrinketOrbLvl3");
	if (index > 0)
	{
		if (CanCast(index)) return index;
	}
	
	index = GET_STT_SKILL(sz__JammerDevice);
	if (index > 0)
	{
		if (CanCast(index)) return index;
	}

	return -1;
}

//==================================================================================//
float AutoWard_Delay = 0;

void AutoWard_With_LanternThresh(KNpc* myHero)
{
	if (!myHero || !G_Module || !myTeamId)  return;
	if (IS_DEAD(myHero)) return;

	static bool hasEnemyThesh   = false;
	static bool checkThreshOnce = false;

	if (checkThreshOnce == false)	//check Thresh Once..
	{
		DWORD nTempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
		DWORD nTempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
		DWORD dw1 = *(DWORD*)nTempHero;
		DWORD dw2 = *(DWORD*)nTempHeroMax;
		if (!dw1 || !dw2 ) return;

		int nCount = (dw2 - dw1)/4;

		for (int i = 0; i < nCount; ++i)
		{
			DWORD dw3 = *(DWORD*)(dw1 + 4*i);
			if (dw3 == 0) continue;
			KNpc *enemyHero = (KNpc*)dw3;

			if (enemyHero->nTeam_ID == myTeamId) continue;
			if (CheckName(enemyHero->GetNameHero(), "Thresh"))
			{
				hasEnemyThesh = true;
				return;
			}
		}

		checkThreshOnce = true;
	}
	
	if (hasEnemyThesh == false) return;

	if ((float)GetTickCount() - AutoWard_Delay < 2500) return;

	KNpc* LongDenThresh = Get_EnemyLongDen_Around(myHero, 575);
	if (!LongDenThresh) return;

	DWORD nTempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	DWORD nTempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dw1 = *(DWORD*)nTempHero;
	DWORD dw2 = *(DWORD*)nTempHeroMax;
	if (!dw1 || !dw2 ) return;

	int nCount = (dw2 - dw1)/4;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *enemyHero = (KNpc*)dw3;

		if (!IsValidTarget(enemyHero, 900)) continue;

		if (Distance(enemyHero, LongDenThresh) < 305 || Distance(LongDenThresh, GET_END_POS(enemyHero)) <= 305)
		{
			if (CheckName(enemyHero->GetNameHero(), "Thresh"))  continue;

			int indexSkill = GetMySkillWardIndex();
			if (indexSkill > 0)
			{
				Cast2Pos(&LongDenThresh->currentPos(), indexSkill);	
				AutoWard_Delay = (float)GetTickCount();
				return;
			}
			else
			{
				extern bool isCaitlyn, isJhin, isJinx, isTeemo;

				if (isCaitlyn && CanCast(_W))
				{
					Cast2Pos(&LongDenThresh->currentPos(), _W);
					AutoWard_Delay = (float)GetTickCount();
					return;
				}
				else if (isJhin && CanCast(_E))
				{
					Cast2Pos(&LongDenThresh->currentPos(), _E);
					AutoWard_Delay = (float)GetTickCount();
					return;
				}
				else if (isJinx && CanCast(_E))
				{
					Cast2Pos(&LongDenThresh->currentPos(), _E);
					AutoWard_Delay = (float)GetTickCount();
					return;
				}
				else if (isTeemo && CanCast(_R))
				{
					KSkill* pSkill = (KSkill*) myHero->_pSkill[_R];
					if (pSkill)
					{
						int levelSpell  = (BYTE)pSkill->nLevel > 3 ? 3 : (BYTE)pSkill->nLevel;
						if (levelSpell == 1)
						{
							if (Distance(myHero, LongDenThresh) < 399)
							{
								Cast2Pos(&LongDenThresh->currentPos(), _R);
								AutoWard_Delay = (float)GetTickCount();
								return;
							}
						}
						else if (levelSpell > 1)
						{
							Cast2Pos(&LongDenThresh->currentPos(), _R);
							AutoWard_Delay = (float)GetTickCount();
							return;
						}
					}
				}
			}
		}
	}
}

//==================================================================================//
KEnemyInfo MapHack22[10] = {0};
void AutoWard_With_InvisibleHero(KNpc* myHero)
{
	if (!myHero || !G_Module || !myTeamId) return;
	if (IS_DEAD(myHero)) return;

	DWORD nTempHero	   = BASE_HERO	   - TEMP_ENTRY_POINT + G_Module;
	DWORD nTempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dw1		   = *(DWORD*)nTempHero;
	DWORD dw2		   = *(DWORD*)nTempHeroMax;
	if (!dw1 || !dw2 ) return;

	int nCount = (dw2 - dw1)/4;

	int index = 0;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *enemyHero = (KNpc*)dw3;

		if (enemyHero->nTeam_ID == myTeamId) continue;

		if (MapHack22[index].nIndex == 0)	// THEM du lieu enemy
		{
			MapHack22[index].nIndex = enemyHero->nIndex; 
		}
		else								// CAP NHAT du lieu cua enemy da ton tai
		{
			for (int k = 0; k < 10; ++k)
			{
				if (MapHack22[k].nIndex == 0) continue;
				if (MapHack22[k].nIndex == enemyHero->nIndex)
				{
					MapHack22[k].pEnemy = enemyHero;

					if (GetTimeGame() < 15)
						MapHack22[k].LastSeen = 15;

					/*if (GetTimeGame() < 30)
					{
						MapHack22[k].LastSeenPosition = enemySpow;
						MapHack22[k].MoveSpeed = 650;
					}*/

					if (IsCanSee(enemyHero))
					{
						MapHack22[k].MoveSpeed		  = enemyHero->nMoveSpeed;
						MapHack22[k].LastSeenPosition = enemyHero->CurrentPos;
						MapHack22[k].LastSeen		  = GetTimeGame();
						MapHack22[k].LastEndPos		  = GET_END_POS(enemyHero);
					}	

					if ((BYTE)enemyHero->nIsBasing == 6 || (BYTE)enemyHero->nIsBasing == 8)
					{
						MapHack22[k].nTick_End     = GetTimeGame() + 1.0f;
						MapHack22[k].LastSeenRange = 0;
					}
					else if ((BYTE)enemyHero->nIsBasing == 0)
					{
						MapHack22[k].nTick_Start = GetTimeGame();
					}

					if (IS_DEAD(enemyHero))		MapHack22[k].TimeDead = GetTimeGame();
					else						MapHack22[k].TimeLife = GetTimeGame();
				}
			}
		}
		index += 1;
	}

	if ((float)GetTickCount() - AutoWard_Delay < 2500) return;

	if (nCombo_Mode || nLaneClear_Mode || nMixed_Mode)
	{
		for (int k = 0; k < 10; ++k)
		{
			if (MapHack22[k].nIndex == 0) continue;

			if (GetTimeGame() - MapHack22[k].LastSeen > 0.05f &&  GetTimeGame() - MapHack22[k].LastSeen < 1 )
			{
				if (MapHack22[k].pEnemy->nIsBasing == 0 && MapHack22[k].TimeLife - MapHack22[k].TimeDead > 30)	//chua hieu no cho cai lolz nay vao lam gi`
				{
					Vec3D lastPos(MapHack22[k].LastSeenPosition.x, MapHack22[k].LastSeenPosition.y, MapHack22[k].LastSeenPosition.z);
					Vec3D posWard = ( MapHack22[k].LastEndPos.IsValid() && (fabs(lastPos.x - MapHack22[k].LastEndPos.x) > FLT_EPSILON || fabs(lastPos.z - MapHack22[k].LastEndPos.z) > FLT_EPSILON) )
								  ? Extend(lastPos, MapHack22[k].LastEndPos, 50) 
								  : lastPos;

					if (Distance(myHero, posWard) < 575  /*&& Distance(lastPos, MapHack22[k].LastEndPos) > 50*/ )
					{	
						extern bool isAshe, isCaitlyn, isJhin, isJinx, isTeemo;

						if (isAshe && CanCast(_E))
						{
							Vec3D posee = Extend(myHero->currentPos(), lastPos, 5000);
							Cast2Pos(&posee, _E);
							AutoWard_Delay = (float)GetTickCount();
							return;
						}
						else if (isCaitlyn && CanCast(_W))
						{
							Cast2Pos(&posWard, _W);
							AutoWard_Delay = (float)GetTickCount();
							return;
						}
						else if (isJhin && CanCast(_E))
						{
							Cast2Pos(&posWard, _E);
							AutoWard_Delay = (float)GetTickCount();
							return;
						}
						else if (isJinx && CanCast(_E))
						{
							Cast2Pos(&posWard, _E);
							AutoWard_Delay = (float)GetTickCount();
							return;
						}
						else if (isTeemo && CanCast(_R))
						{
							KSkill* pSkill = (KSkill*) myHero->_pSkill[_R];
							if (pSkill)
							{
								int levelSpell  = (BYTE)pSkill->nLevel > 3 ? 3 : (BYTE)pSkill->nLevel;
								if (levelSpell == 1)
								{
									if (Distance(myHero, lastPos) < 399)
									{
										Cast2Pos(&posWard, _R);
										AutoWard_Delay = (float)GetTickCount();
										return;
									}
								}
								else if (levelSpell > 1)
								{
									Cast2Pos(&posWard, _R);
									AutoWard_Delay = (float)GetTickCount();
									return;
								}
							}
						}

						int indexSkill = GetMySkillWardIndex();
						if (indexSkill > 0)
						{
							Cast2Pos(&posWard, indexSkill);	
							AutoWard_Delay = (float)GetTickCount();
							return;
						}
					}
				}				
			}
		}
	}
}

