#include "CommonsFunc.h"


extern DWORD      G_Module;
extern int        myTeamId;
//==================================================================================//
//==================================================================================//
//==================================================================================//
float nDoSkill_TickStart = 0;
float nDoSkill_TickEnd   = 0;
float nDoSkill_DeltaTick = 0;
float nDoSkill_DelayMax  = 88;

//==================================================================================//
void DO_SKILL_LINE(KNpc* pEnemy, int sttSkill, float nKhoangCach)
{
	//nDoSkill_DeltaTick = nDoSkill_TickEnd - nDoSkill_TickStart;
	//if(nDoSkill_DeltaTick < SLMHTClientData::GetInstance()->GetCBDelaySkillAfter()) return;

	if (sttSkill == -1) return;
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return;
	KSkill*   pSkill_X = (KSkill*) pPlayer->_pSkill[sttSkill];
	if(!pSkill_X) return;
	//KSkill_2*  pKSkill__X = (KSkill_2*) pSkill_X->__pK_str2;
	//if(!pKSkill__X) return;
	//__oMsg("===== CanCastSpell2(0) : %d", CanCastSpell2(0));
	if(CanCastSpell2(sttSkill) !=  0) return;
	//if(CanCastSpell2(0) ==  64) return;
	//if(CanCastSpell2(0) ==  32) return;
	//if ((BYTE)CanCastSpell(pKSkill__X) == 0) return;

	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= CAST_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX		= (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;

	DWORD nDest		= (DWORD)&pEnemy->CurrentPos.x;
	KPos PosDuDoan = GetPos_DuDoan(pEnemy, nKhoangCach);
	float fDistance = Distance_2D(pPlayer->CurrentPos, pEnemy->CurrentPos);
	if (PosDuDoan != 0 && nKhoangCach >= 0 && fDistance > 220.0)
	{
		nDest		= (DWORD)&PosDuDoan.x;
	}
	float buffMouse[3]		 = {0,0,0};
	DWORD nBuffer = (DWORD)&buffMouse[0];
	__asm{
		push 0
		push nBuffer
		push nDest
		push sttSkill
		push pSkill_X
		mov ecx,_ECX
		mov eax,nFunc
		call eax
	}
	//nDoSkill_TickStart = (float)GetTickCount();
	//__oMsg("[LINE-]nDoSkill_DeltaTick %f - %f - %d", nDoSkill_DeltaTick, nDoSkill_DelayMax, SLMHTClientData::GetInstance()->GetCBDelaySkillAfter());
}

//==================================================================================//
void DO_SKILL_LINE_4LUA(KNpc* pEnemy, int sttSkill, float nKhoangCach)
{
	if (sttSkill == -1) return;
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return;
	KSkill*   pSkill_X = (KSkill*) pPlayer->_pSkill[sttSkill];
	if(!pSkill_X) return;
	//if(CanCastSpell2(sttSkill) !=  0) return;

	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= CAST_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX		= (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;

	DWORD nDest		= (DWORD)&pEnemy->CurrentPos.x;
	KPos PosDuDoan = GetPos_DuDoan(pEnemy, nKhoangCach);
	float fDistance = Distance_2D(pPlayer->CurrentPos, pEnemy->CurrentPos);
	if (PosDuDoan != 0 && nKhoangCach >= 0 && fDistance > 220.0)
	{
		nDest		= (DWORD)&PosDuDoan.x;
	}
	float buffMouse[3]		 = {0,0,0};
	DWORD nBuffer = (DWORD)&buffMouse[0];
	__asm{
			push 0
			push nBuffer
			push nDest
			push sttSkill
			push pSkill_X
			mov ecx,_ECX
			mov eax,nFunc
			call eax
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void DO_SKILL_LINE_POS(KPos *StartPos, KPos* EndPos, int sttSkill)
{
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return;
	KSkill*   pSkill_X = (KSkill*) pPlayer->_pSkill[sttSkill];
	if(!pSkill_X) return;
	if(CanCastSpell2(sttSkill) !=  0) return;

	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= CAST_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX		= (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;

	DWORD nStartPos		= (DWORD)&StartPos->x;
	DWORD nEndPos		= (DWORD)&EndPos->x;

	__asm{
			push 0
			push nEndPos
			push nStartPos
			push sttSkill
			push pSkill_X
			mov ecx,_ECX
			mov eax,nFunc
			call eax
	}
}

//==================================================================================//
void DO_SKILL_LINE_POS_4LUA(KPos *StartPos, KPos* EndPos, int sttSkill)
{
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return;
	KSkill*   pSkill_X = (KSkill*) pPlayer->_pSkill[sttSkill];
	if(!pSkill_X) return;
	//if(CanCastSpell2(sttSkill) !=  0) return;

	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= CAST_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX		= (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;

	DWORD nStartPos		= (DWORD)&StartPos->x;
	DWORD nEndPos		= (DWORD)&EndPos->x;

	__asm{
			push 0
			push nEndPos
			push nStartPos
			push sttSkill
			push pSkill_X
			mov ecx,_ECX
			mov eax,nFunc
			call eax
	}
}

//==================================================================================//
//==================================================================================//
void DO_SKILL_TO_POS(KPos *pPos, int sttSkill)//cai nay chi danh cho Lua
{
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return;
	KSkill*   pSkill_X = (KSkill*) pPlayer->_pSkill[sttSkill];
	if(!pSkill_X) return;
	//if(CanCastSpell2(sttSkill) !=  0) return;

	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= CAST_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX		= (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;

	DWORD nPos		= (DWORD)&pPos->x;
	float buffMouse[3]		 = {0,0,0};
	DWORD nBuffer = (DWORD)&buffMouse[0];
	__asm{
			push 0
			push nBuffer
			push nPos
			push sttSkill
			push pSkill_X
			mov ecx,_ECX
			mov eax,nFunc
			call eax
	}
}

//==================================================================================//
//==================================================================================//
void RELEASE_SKILL_TO_POS(KPos *pPos, int sttSkill)// cai nay chi danh cho Lua
{
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return;
	KSkill*   pSkill_X = (KSkill*) pPlayer->_pSkill[sttSkill];
	if(!pSkill_X) return;
	//if(CanCastSpell2(sttSkill) !=  0) return;

	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc  = RELEASE_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX  = (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;
	DWORD nDest		= (DWORD)&pPos->x;
	
	__asm{
			push 1
			push nDest
			push sttSkill
			push pSkill_X
			mov ecx,_ECX
			mov eax,nFunc
			call eax
	}
}

//==================================================================================//
//==================================================================================//
void RELEASE_SKILL_LINE(KNpc* pEnemy, int sttSkill, float nKhoangCach)
{
	//nDoSkill_DeltaTick = nDoSkill_TickEnd - nDoSkill_TickStart;
	//if(nDoSkill_DeltaTick < SLMHTClientData::GetInstance()->GetCBDelaySkillAfter()) return;

	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return;
	KSkill*   pSkill_X = (KSkill*) pPlayer->_pSkill[sttSkill];
	if(!pSkill_X) return;
	if(CanCastSpell2(sttSkill) !=  0) return;

	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc  = RELEASE_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX  = (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;
	DWORD nDest		= (DWORD)&pEnemy->CurrentPos.x;
	KPos PosDuDoan = GetPos_DuDoan(pEnemy, nKhoangCach);
	if (PosDuDoan != 0)
	{
		nDest		= (DWORD)&PosDuDoan.x;
	}
	__asm{
		push 1
		push nDest
		push sttSkill
		push pSkill_X
		mov ecx,_ECX
		mov eax,nFunc
		call eax
	}
	//nDoSkill_TickStart = (float)GetTickCount();
	//__oMsg("[RELEASE-]nDoSkill_DeltaTick %f", nDoSkill_DeltaTick);
}

//==================================================================================//
void RELEASE_SKILL_LINE_4LUA(KNpc* pEnemy, int sttSkill, float nKhoangCach)
{
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return;
	KSkill*   pSkill_X = (KSkill*) pPlayer->_pSkill[sttSkill];
	if(!pSkill_X) return;
	//if(CanCastSpell2(sttSkill) !=  0) return;

	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc  = RELEASE_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX  = (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;
	DWORD nDest		= (DWORD)&pEnemy->CurrentPos.x;
	KPos PosDuDoan = GetPos_DuDoan(pEnemy, nKhoangCach);
	if (PosDuDoan != 0)
	{
		nDest		= (DWORD)&PosDuDoan.x;
	}
	__asm{
		push 1
			push nDest
			push sttSkill
			push pSkill_X
			mov ecx,_ECX
			mov eax,nFunc
			call eax
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void RELEASE_SKILL_LINE_2(KNpc* pEnemy, int sttSkill, float nKhoangCach)
{
	//nDoSkill_DeltaTick = nDoSkill_TickEnd - nDoSkill_TickStart;
	//if(nDoSkill_DeltaTick < SLMHTClientData::GetInstance()->GetCBDelaySkillAfter()) return;

	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return;
	KSkill*   pSkill_X = (KSkill*) pPlayer->_pSkill[sttSkill];
	if(!pSkill_X) return;
	if(CanCastSpell2(sttSkill) !=  0) return;

	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc  = RELEASE_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX  = (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;
	DWORD nDest		= (DWORD)&pEnemy->CurrentPos.x;
	KPos PosDuDoan = GetPos_DuDoan(pEnemy, nKhoangCach);
	if (PosDuDoan != 0)
	{
		nDest		= (DWORD)&PosDuDoan.x;
	}
	__asm{
		push 0
		push nDest
		push sttSkill
		push pSkill_X
		mov ecx,_ECX
		mov eax,nFunc
		call eax
	}
	//nDoSkill_TickStart = (float)GetTickCount();
	//__oMsg("skill %d", sttSkill);
}

//==================================================================================//
void RELEASE_SKILL_LINE_2_4LUA(KNpc* pEnemy, int sttSkill, float nKhoangCach)
{
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return;
	KSkill*   pSkill_X = (KSkill*) pPlayer->_pSkill[sttSkill];
	if(!pSkill_X) return;
	//if(CanCastSpell2(sttSkill) !=  0) return;

	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc  = RELEASE_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX  = (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;
	DWORD nDest		= (DWORD)&pEnemy->CurrentPos.x;
	KPos PosDuDoan = GetPos_DuDoan(pEnemy, nKhoangCach);
	if (PosDuDoan != 0)
	{
		nDest		= (DWORD)&PosDuDoan.x;
	}
	__asm{
		push 0
			push nDest
			push sttSkill
			push pSkill_X
			mov ecx,_ECX
			mov eax,nFunc
			call eax
	}
}

////==================================================================================//
//void CANCEL_SKILL(int sttSkill)
//{
//	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
//	if (hModule == NULL) return;
//	DWORD nFunc  = RELEASE_SPELL - TEMP_ENTRY_POINT + hModule;
//	DWORD nTempBASE_SKILL = BASE_SKILL - TEMP_ENTRY_POINT + hModule;
//	DWORD dw1 = *(DWORD*)nTempBASE_SKILL;
//	if (dw1 == NULL) return;
//	DWORD _ECX = *(DWORD*)(dw1 + 0x2C);
//	if (_ECX == NULL) return;
//	__asm{
//		push sttSkill
//		push 2
//		mov ecx,_ECX
//		mov eax,nFunc
//		call eax
//	}
//	//__oMsg("cancel skill %d", sttSkill);
//}

//==================================================================================//
void DO_SKILL_TARGET(KNpc* pEnemy, int sttSkill)
{
	//nDoSkill_DeltaTick = nDoSkill_TickEnd - nDoSkill_TickStart;
	//if(nDoSkill_DeltaTick < SLMHTClientData::GetInstance()->GetCBDelaySkillAfter()) return;

	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return;
	KSkill*   pSkill_X = (KSkill*) pPlayer->_pSkill[sttSkill];
	if(!pSkill_X) return;
	if(CanCastSpell2(sttSkill) !=  0) return;

	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= CAST_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX		= (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;

	DWORD nDest		= (DWORD)&pEnemy->CurrentPos.x;
	DWORD nIndex	= pEnemy->nIndex;
	float buffMouse[3]		 = {0,0,0};
	DWORD nBuffer = (DWORD)&buffMouse[0];
	__asm{
		push nIndex
		push nBuffer
		push nDest
		push sttSkill
		push pSkill_X
		mov ecx,_ECX
		mov eax,nFunc
		call eax
	}
	//nDoSkill_TickStart = (float)GetTickCount();
	//__oMsg("[TARGET-]nDoSkill_DeltaTick %f - %f - %d", nDoSkill_DeltaTick, nDoSkill_DelayMax, SLMHTClientData::GetInstance()->GetCBDelaySkillAfter());
}

//==================================================================================//
void DO_SKILL_TARGET_4LUA(KNpc* pEnemy, int sttSkill)
{
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return;
	KSkill*   pSkill_X = (KSkill*) pPlayer->_pSkill[sttSkill];
	if(!pSkill_X) return;
	//if(CanCastSpell2(sttSkill) !=  0) return;		//lua ko can cai nay

	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= CAST_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX		= (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;

	DWORD nDest		= (DWORD)&pEnemy->CurrentPos.x;
	DWORD nIndex	= pEnemy->nIndex;

	float buffMouse[3]		 = {0,0,0};
	DWORD nBuffer = (DWORD)&buffMouse[0];
	__asm{
		push nIndex
			push nBuffer
			push nDest
			push sttSkill
			push pSkill_X
			mov ecx,_ECX
			mov eax,nFunc
			call eax
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool DO_SKILL_SMITE(KNpc* pEnemy)
{
	
	if (DO_SKILL_ITEM(pEnemy,  (sz__SummonerSmite))) return true;						//==> trung phat vang
	else if (DO_SKILL_ITEM(pEnemy,  (sz__S5_SummonerSmitePlayerGanker))) return true;	//==> trung phat xanh
	else if (DO_SKILL_ITEM(pEnemy,  (sz__S5_SummonerSmiteDuel))) return true;			//==> trung phat do

	//KNpc*   pPlayer = GetPlayer();
	//if(!pPlayer) return false;
	//if ((BYTE)pPlayer->nIsDie == 1) return false;

	//for (int i = 0; i < 20; ++i)
	//{
	//	KSkill *pSkill = (KSkill *)pPlayer->_pSkill[i];
	//	if(!pSkill) continue;
	//	KSkill_2*  pKSkill_2GetName = (KSkill_2*) pSkill->__pK_str2;
	//	if(!pKSkill_2GetName) continue;
	//	__oMsg("ten skill:%s", pKSkill_2GetName->GetSkillName());
	//	if (CheckName(pKSkill_2GetName->GetSkillName(),  (sz__SummonerSmite)) && CheckName( (sz__SummonerSmite), pKSkill_2GetName->GetSkillName()))
	//	if (CheckName("SummonerSmite", pKSkill_2GetName->GetSkillName()))
	//	{
	//		if (CanCastSpell2(i) != 0) return false;
	//		DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	//		DWORD nFunc		= CAST_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
	//		DWORD _ECX		= (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;

	//		DWORD nDest		= (DWORD)&pEnemy->CurrentPos.x;
	//		DWORD nIndex	= pEnemy->nIndex;
	//		__asm{
	//			push nIndex
	//				push nDest
	//				push nDest
	//				push i
	//				push pSkill
	//				mov ecx,_ECX
	//				mov eax,nFunc
	//				call eax
	//		}
	//		return true;
	//	}
	//}
	return false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KNpc* GetJungle(float nRange)
{
	KEnemyDistance monster[50];
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return NULL;
	int nCount = (dw2 - dw1)/4;

	KNpc *pPlayer = GetPlayer();
	BYTE isDied = (BYTE)pPlayer->nIsDie;
	if (isDied != 0) return NULL;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pJungle = (KNpc*)dw3;
		int isDie = (BYTE)pJungle->nIsDie;
		if (pJungle->nTeam_ID == 0x64 || pJungle->nTeam_ID == 0xC8 || isDie == 1 || pJungle->nHP <= 0)
			continue;
		if ((BYTE)pJungle->nIsTargetableToTeam != 4) continue;
		if (!IsCanSee(pJungle)) continue;
		
		if (!CheckName( (sz__SRU_), pJungle->GetNameNpc()))
		{
			if(!CheckName( (sz__Sru_), pJungle->GetNameNpc()))
			{
				if(!CheckName( (sz__MiniKrug), pJungle->GetNameNpc()))
				{
					if(!CheckName("TT_N", pJungle->GetNameNpc()))//TT_NWolf23.1.2 - TT_NWraith21.1.2 - TT_NGolem22.1.2
					{
						if(!CheckName("TT_S", pJungle->GetNameNpc())) continue;//TT_Spiderboss8.1.1
					}
				}
			}
		}
		float nDistance = Distance_3D(pPlayer->CurrentPos, pJungle->CurrentPos);
		if(nRange == 0)
		{
			if (pPlayer->nAttackRange < 300)
			{
				nRange = pPlayer->nAttackRange + pJungle->nOverrideCollisionRadius + 10;
			} 
			else
			{
				nRange = pPlayer->nAttackRange + 110;
			}
		}
		if (nDistance > nRange) continue;
		monster[jCount].pEnemy = pJungle;
		monster[jCount].nThuTuUuTien = 1;
		if (CheckName(pJungle->GetNameHero(), sz__SRU_Gromp)	 || 
			CheckName(pJungle->GetNameHero(), sz__SRU_Krug)		 ||
			CheckName(pJungle->GetNameHero(), sz__SRU_Razorbeak) ||
			CheckName(pJungle->GetNameHero(), sz__SRU_Murkwolf)  ||
			CheckName(pJungle->GetNameHero(), sz__Sru_Crab)		 ||
			CheckName(pJungle->GetNameHero(), "TT_NGolem" )		 ||
			CheckName(pJungle->GetNameHero(), "TT_NWraith" )     ||
			CheckName(pJungle->GetNameHero(), "TT_NWolf" )     
			)
		{
			monster[jCount].nThuTuUuTien = 2;
		}
		if (CheckName(pJungle->GetNameHero(),  (sz__SRU_Red)) || 
			CheckName(pJungle->GetNameHero(),  (sz__SRU_Blue)) )
		{
			monster[jCount].nThuTuUuTien = 3;
		}
		if (CheckName(pJungle->GetNameHero(), sz__SRU_RiftHerald) || 
			CheckName(pJungle->GetNameHero(), sz__SRU_Baron)      || 
			CheckName(sz__SRU_Dragon, pJungle->GetNameNpc())      ||
			CheckName("TT_Spiderboss", pJungle->GetNameNpc())
			)
		{
			if(nDistance <= 550.0) monster[jCount].nThuTuUuTien = 4;
		}
		jCount += 1;
	}

	// tim quai rung co thu tu uu tien cao hon
	int nUuTienMax = 0;
	int nIndex = -1;
	for (int i = 0; i < jCount; ++i)
	{
		if (nUuTienMax < monster[i].nThuTuUuTien)
		{
			nUuTienMax = monster[i].nThuTuUuTien;
			nIndex = i;
		}
	}
	if (nIndex == -1)
	{
		return NULL;
	} 
	else
	{
		return monster[nIndex].pEnemy;
	}
}

//==================================================================================//
KNpc* GetJungle_Small(float nRange)
{
	KEnemyDistance monster[50];
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return NULL;
	int nCount = (dw2 - dw1)/4;

	KNpc *pPlayer = GetPlayer();
	BYTE isDied = (BYTE)pPlayer->nIsDie;
	if (isDied != 0) return NULL;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pJungle = (KNpc*)dw3;
		int isDie = (BYTE)pJungle->nIsDie;
		if (pJungle->nTeam_ID == 0x64 || pJungle->nTeam_ID == 0xC8 || isDie == 1 || pJungle->nHP <= 0)
			continue;
		if ((BYTE)pJungle->nIsTargetableToTeam != 4) continue;
		if (!IsCanSee(pJungle)) continue;

		if (!CheckName( (sz__SRU_), pJungle->GetNameNpc()))
		{
			if(!CheckName( (sz__Sru_), pJungle->GetNameNpc()))
			{
				if(!CheckName( (sz__MiniKrug), pJungle->GetNameNpc()))
				{
					if(!CheckName("TT_N", pJungle->GetNameNpc()))//TT_NWolf23.1.2 - TT_NWraith21.1.2 - TT_NGolem22.1.2
					{
						if(!CheckName("TT_S", pJungle->GetNameNpc())) continue;//TT_Spiderboss8.1.1
					}
				}
			}
		}
		float nDistance = Distance_3D(pPlayer->CurrentPos, pJungle->CurrentPos);
		if(nRange == 0)
		{
			if (pPlayer->nAttackRange < 300)
			{
				nRange = pPlayer->nAttackRange + pJungle->nOverrideCollisionRadius + 10;
			} 
			else
			{
				nRange = pPlayer->nAttackRange + 110;
			}
		}
		if (nDistance > nRange) continue;
		monster[jCount].pEnemy = pJungle;
		monster[jCount].nThuTuUuTien = 1;
		if (CheckName(pJungle->GetNameHero(), sz__SRU_Gromp)	 || 
			CheckName(pJungle->GetNameHero(), sz__SRU_Krug)		 ||
			CheckName(pJungle->GetNameHero(), sz__SRU_Razorbeak) ||
			CheckName(pJungle->GetNameHero(), sz__SRU_Murkwolf)  ||
			CheckName(pJungle->GetNameHero(), sz__Sru_Crab)		 ||
			CheckName(pJungle->GetNameHero(), "TT_NGolem" )		 ||
			CheckName(pJungle->GetNameHero(), "TT_NWraith" )     ||
			CheckName(pJungle->GetNameHero(), "TT_NWolf" )  
			)
		{
			monster[jCount].nThuTuUuTien = 2;
		}
		if (CheckName(pJungle->GetNameHero(),  (sz__SRU_Red)) || 
			CheckName(pJungle->GetNameHero(),  (sz__SRU_Blue)) )
		{
			monster[jCount].nThuTuUuTien = 3;
		}
		if (CheckName(pJungle->GetNameHero(), sz__SRU_RiftHerald) || 
			CheckName(pJungle->GetNameHero(), sz__SRU_Baron)      || 
			CheckName(sz__SRU_Dragon, pJungle->GetNameNpc())      ||
			CheckName("TT_Spiderboss", pJungle->GetNameNpc())
			)
		{
			if(nDistance <= 550.0) monster[jCount].nThuTuUuTien = 4;
		}
		jCount += 1;
	}

	// tim quai rung co thu tu uu tien cao hon
	int nUuTienMin = 100;
	int nIndex = -1;
	for (int i = 0; i < jCount; ++i)
	{
		if (nUuTienMin > monster[i].nThuTuUuTien)
		{
			nUuTienMin = monster[i].nThuTuUuTien;
			nIndex = i;
		}
	}
	if (nIndex == -1)
	{
		return NULL;
	} 
	else
	{
		return monster[nIndex].pEnemy;
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KNpc* GetJungleNearest(float nRange)
{
	KEnemyDistance monster[50];
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return NULL;
	int nCount = (dw2 - dw1)/4;

	KNpc *pPlayer = GetPlayer();
	BYTE isDied = (BYTE)pPlayer->nIsDie;
	if (isDied != 0) return NULL;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pJungle = (KNpc*)dw3;
		int isDie = (BYTE)pJungle->nIsDie;
		if (pJungle->nTeam_ID == 0x64 || pJungle->nTeam_ID == 0xC8 || isDie == 1 || pJungle->nHP <= 0.)
			continue;
		float nDistance = Distance_3D(pPlayer->CurrentPos, pJungle->CurrentPos);
		if (nRange == 0)
		{
			if (pPlayer->nAttackRange < 300)
			{
				nRange = 550;
			} 
			else
			{
				nRange = pPlayer->nAttackRange + 75;
			}
		}
		if (nDistance > nRange) continue;
		if (!CheckName( (sz__SRU_), pJungle->GetNameNpc()))
		{
			if(!CheckName( (sz__Sru_), pJungle->GetNameNpc())) continue;
		}
		if ((BYTE)pJungle->nIsTargetableToTeam != 4) continue;

		monster[jCount].pEnemy = pJungle;
		monster[jCount].fDistance = nDistance;
		jCount += 1;
	}

	// tim quai rung gan nhat
	float fMin = nRange;
	int nIndex = -1;
	for (int i = 0; i < jCount; ++i)
	{
		if (fMin > monster[i].fDistance)
		{
			fMin = monster[i].fDistance;
			nIndex = i;
		}
	}
	if (nIndex == -1)
	{
		return NULL;
	} 
	else
	{
		return monster[nIndex].pEnemy;
	}
}

//==================================================================================//
KPos GetPos_DuDoan(KNpc *pEnemy, float nKhoangCach)
{
	KPos ret;// khoi tao vi tri (0, 0, 0)
	if(!pEnemy) return ret;

	DWORD movNote = (DWORD)pEnemy->_pMOVE;
	if(!movNote) return ret;

	DWORD tempMov  = *(DWORD*)(movNote + 4);
	stMOVE *enemyPos = (stMOVE *)tempMov;
	//stMOVE *enemyPos = (stMOVE*) pEnemy->_pMOVE;	//old-fuck
	if(!enemyPos) return ret;

	//if ((BYTE)enemyPos->nIsMoving == 0) return ret;
	if ((BYTE)pEnemy->nIsMove == 0) return ret;
	if (GET_BUFF_DUNGIM(pEnemy)) return ret;
	if (!pEnemy->IsChampion()) return ret;

	KPos posNghiem1, posNghiem2;// khoi tao vi tri (0, 0, 0)
	float nKC = Distance_2D(pEnemy->CurrentPos, enemyPos->__strPosDest);
	if (nKC < nKhoangCach)
	{
		//return &enemyPos->__strPosDest;
		KPos virtualPOS;
		virtualPOS.x = (pEnemy->CurrentPos.x + enemyPos->__strPosDest.x)/2;
		virtualPOS.y = (pEnemy->CurrentPos.y + enemyPos->__strPosDest.y)/2;
		virtualPOS.z = (pEnemy->CurrentPos.z + enemyPos->__strPosDest.z)/2;
		return virtualPOS;
	}
	TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pEnemy->CurrentPos, enemyPos->__strPosDest, nKhoangCach);
	float nTempKC1 = Distance_2D(posNghiem1, enemyPos->__strPosDest);
	float nTempKC2 = Distance_2D(posNghiem2, enemyPos->__strPosDest);
	if (nTempKC1 < nTempKC2)
	{
		return posNghiem1;
	}
	else
	{
		return posNghiem2;
	}
}

//==================================================================================//
int CountSkillAttacking(KNpc *pNpcIsAttacked)
{
	int result = 0;
	if (!G_Module)       return result;
	if (!pNpcIsAttacked) return result;
	DWORD nTemp1 = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	DWORD nTemp2 = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;

	DWORD dw1 = *(DWORD*)nTemp1;
	DWORD dw2 = *(DWORD*)nTemp2;
	if (!dw1 || !dw2 ) return result;

	int nCount = (dw2 - dw1)/4;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemy = (KNpc*)dw3;
		if (!pEnemy->IsChampion() || !pEnemy->IsEnemy(pNpcIsAttacked->nTeam_ID) || pEnemy->isDead() || !pEnemy->isTargetable())
			continue;

		KCastSpell *pEnemyCastSpell = (KCastSpell *)pEnemy->_pCastSpell;
		if (!pEnemyCastSpell) continue;
		KSkill_2 *pSkill_2 = (KSkill_2 *)pEnemyCastSpell->__pK_str2;
		if (pSkill_2 == 0)   continue;
	
		//float nKC = Distance_2D(pNpcIsAttacked->CurrentPos, pEnemy->CurrentPos);
		//if (CheckName(sz__BasicAttack, pSkill_2->GetSkillName()))	// danh thuong va 1 so dieu kien cua danh thuong
		//{
		//	float range = pEnemy->nAttackRange;
		//	if(pEnemy->nBaseAttackDamage + pEnemy->nFlat_PhysicalDamageMod < 110) continue;
		//	if(pEnemy->IsChampion() && (nKC > range + pNpcIsAttacked->nOverrideCollisionRadius + 20.0)) continue;
		//} 
		
		
	}
	return result;
}

//==================================================================================//
int CountNPCAttack(KNpc *pNpcIsAttacked)
{
	int result = 0;
	if (!G_Module)		 return result;
	if (!pNpcIsAttacked) return result;
	DWORD nTemp1 = BASE_AttackableUnit     - TEMP_ENTRY_POINT + G_Module;
	DWORD nTemp2 = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;

	DWORD dw1 = *(DWORD*)nTemp1;
	DWORD dw2 = *(DWORD*)nTemp2;
	if (!dw1 || !dw2 ) return result;

	int nCount = (dw2 - dw1)/4;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemy = (KNpc*)dw3;
		if ((!pEnemy->IsChampion() && !pEnemy->IsTurret()) || !pEnemy->IsEnemy(pNpcIsAttacked->nTeam_ID) || pEnemy->isDead() || !pEnemy->isTargetable())
			continue;

		KCastSpell *pEnemyCastSpell = (KCastSpell *)pEnemy->_pCastSpell;
		if (!pEnemyCastSpell) continue;
		KSkill_2 *pSkill_2 = (KSkill_2 *)pEnemyCastSpell->__pK_str2;
		if (pSkill_2 == 0)   continue;

		float nKC = Distance_2D(pNpcIsAttacked->CurrentPos, pEnemy->CurrentPos);
		if (CheckName(sz__BasicAttack, pSkill_2->GetSkillName()))	// danh thuong va 1 so dieu kien cua danh thuong
		{
			float range = pEnemy->nAttackRange;
			float dmgEnemy = pEnemy->nBaseAttackDamage + pEnemy->nFlat_PhysicalDamageMod;
			if(dmgEnemy < 110)
			{
				if(3*dmgEnemy < pNpcIsAttacked->nHP) continue;
			}
			if(pEnemy->IsChampion() && (nKC > range + pNpcIsAttacked->nOverrideCollisionRadius + 35.0)) continue;
		} 
		if (CheckName(sz__recall, pSkill_2->GetSkillName())) continue;

		if (pEnemyCastSpell->nEnemy_ID == pNpcIsAttacked->nID)
		{
			result = result + 1;
		}
	}
	return result;
}

//==================================================================================//
int	CountMinionAttack(KNpc *pNpcIsAttacked)
{
	int jCountNPC = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return jCountNPC;
	DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;

	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return jCountNPC;

	int nCount = (dw2 - dw1)/4;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pNPC = (KNpc*)dw3;
		int isDie = (BYTE)pNPC->nIsDie;
		if (!pNPC->IsEnemy(pNpcIsAttacked->nTeam_ID) || isDie == 1 || pNPC->nHP <= 0. || !pNPC->IsMinion())
			continue;
		if (CheckName( (sz__Minion), pNPC->GetNameNpc()) == false) continue;
		KCastSpell *pNPC_CastSpell = (KCastSpell *)pNPC->_pCastSpell;
		if (!pNPC_CastSpell) continue;
		KSkill_2 *pSkill_2 = (KSkill_2 *)pNPC_CastSpell->__pK_str2;
		if (pSkill_2 == NULL) continue;
		
		float nKC = Distance_2D(pNpcIsAttacked->CurrentPos, pNPC->CurrentPos);
		if(nKC > 2500.0) continue;

		if (CheckName( (sz__SiegeBasicAttack), pSkill_2->GetSkillName()))	// danh thuong danh xa-linh to
		{
			if(nKC > (450.0 + pNpcIsAttacked->nOverrideCollisionRadius)) continue;
		}
		if (CheckName( (sz__RangedBasicAttack), pSkill_2->GetSkillName()))	// danh thuong danh xa
		{
			if(nKC > (700.0 + pNpcIsAttacked->nOverrideCollisionRadius)) continue;
		}
		if (CheckName( (sz__MeleeBasicAttack), pSkill_2->GetSkillName()))	// danh thuong danh xa
		{
			if(nKC > (275.0 + pNpcIsAttacked->nOverrideCollisionRadius)) continue;
		}
	
		if (pNPC_CastSpell->nEnemy_ID == pNpcIsAttacked->nID)
		{
			jCountNPC = jCountNPC + 1;
		}
	}
	return jCountNPC;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IS_INLINE_SKILL(KNpc *pNpc, KPos *startPoint,KPos *endPoint, float nRadius, float nRange, bool isHasMinion)  //dZ.x - dX.z  = C1 = dZ*pos1.x - dX*pos1.z  (1)(d)
{																												 //dX.x + dZ.z  = C2 = dX*player_x + dZ*player_z (2)(vuong goc voi d)
	float Range = nRange + 100;     //thu 120.0 xem sao
	float R     = nRadius  + 95;
	if (isHasMinion) R  = nRadius  + 85;
	//if(CO_HIT_RUN || CO_HARASS || CO_TUNG SKILL) R = (pBufferSpell->nRadius  + 60.0);

	float dX = endPoint->x - startPoint->x;
	float dZ = endPoint->z - startPoint->z;
	float Npc_x = pNpc->CurrentPos.x;
	float Npc_z = pNpc->CurrentPos.z;
	float C1    = dZ*startPoint->x - dX*startPoint->z;
	float C2    = dX*Npc_x + dZ*Npc_z;

	float calc1 = sqrt(dZ*dZ + dX*dX);
	float kc1 = abs(dZ*Npc_x - dX*Npc_z  - C1)/calc1; //k/c tu NPC den (1)(d)
	if(kc1 >= R)  return FALSE;
	//---------------------------
	KPos tmpPos;
	int  rc = NghiemHePTBacNhat(tmpPos,dZ, -dX, C1, dX, dZ, C2); //giao diem cua (1) va (2)
	if (!rc) return FALSE;
	float vuonggoc_x = tmpPos.x;
	float vuonggoc_z = tmpPos.z;
	float kc2 = sqrt((vuonggoc_x - startPoint->x)*(vuonggoc_x - startPoint->x) + (vuonggoc_z - startPoint->z)*(vuonggoc_z - startPoint->z)); //k/c tu giao diem o tren den pos1
	if(kc2 >= Range) return FALSE;
	//-----------------------------
	//dX.x + dZ.z  = C3 = dX*pos1->x + dZ*pos1->z (3)(vuong goc voi d)- va di qua pos1
	float C3 = dX*startPoint->x + dZ*startPoint->z;
	float tichvohuong = (dX*vuonggoc_x + dZ*vuonggoc_z  - C3)*(dX*endPoint->x + dZ*endPoint->z  - C3);// xet diem vuong goc va pos2 cung phia hay khac phia so voi (3)
	if(tichvohuong < 0) return FALSE;

	return TRUE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int NPC_INLINE_SKILL(KNpc* pEnemy, KPos *startPoint,KPos *endPoint, float  nRadius, float nRange, float nKhoangCach)// gom minion-only
{
	if(pEnemy == NULL) return 0;
	int nCountNPC = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return 0;
	int nCount = (dw2 - dw1)/4;

	BYTE isDied = (BYTE)pEnemy->nIsDie;
	if (isDied != 0) return 0;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pNpc = (KNpc*)dw3;
		int isDie = (BYTE)pNpc->nIsDie;
		if (!pNpc->IsAlly(pEnemy->nTeam_ID) || isDie == 1 || pNpc->nHP <= 0 || !pNpc->IsMinion())
			continue;
		if ((BYTE)pNpc->nIsTargetableToTeam != 4) continue;
		if (CheckName( (sz__Minion), pNpc->GetNameNpc()) == false) continue;
		if (IS_INLINE_SKILL(pNpc, startPoint,endPoint, nRadius, nRange, true))
		{
			KPos diemVuongGoc1;   // diem vuong goc cua Player chieu xuong duong thang skill
			GIAO_DIEM_VUONG_GOC(diemVuongGoc1, *startPoint, *endPoint, pEnemy->CurrentPos);
			float nDistance1 = Distance_2D(diemVuongGoc1, *startPoint);

			KPos diemVuongGoc2;   // diem vuong goc cua NPC chieu xuong duong thang skill
			GIAO_DIEM_VUONG_GOC(diemVuongGoc2, *startPoint, *endPoint, pNpc->CurrentPos);
			float nDistance2 = Distance_2D(diemVuongGoc2, *startPoint);
			if (nDistance1 - nDistance2 > nKhoangCach) nCountNPC += 1;
		}
	}
	return nCountNPC;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int NPC_INLINE_SKILL2(KNpc* pEnemy, KPos *startPoint,KPos *endPoint, float  nRadius, float nRange, float nKhoangCach)// gom minion + hero
{
	if(pEnemy == NULL) return 0;
	int nCountNPC = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return 0;
	int nCount = (dw2 - dw1)/4;

	BYTE isDied = (BYTE)pEnemy->nIsDie;
	if (isDied != 0) return 0;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pNpc = (KNpc*)dw3;
		int isDie = (BYTE)pNpc->nIsDie;
		if (!pNpc->IsAlly(pEnemy->nTeam_ID) || isDie == 1 || pNpc->nHP <= 0 || (!pNpc->IsMinion() && !pNpc->IsChampion()))
			continue;
		if ((BYTE)pNpc->nIsTargetableToTeam != 4) continue;
		if(pNpc->IsMinion())
		{
			if (CheckName( (sz__Minion), pNpc->GetNameNpc()) == false) continue;
		}
		else
		{
			if (!IsCanSee(pNpc)) continue;
		}
		if (IS_INLINE_SKILL(pNpc, startPoint,endPoint, nRadius, nRange, false))
		{
			KPos diemVuongGoc1;   // diem vuong goc cua Player chieu xuong duong thang skill
			GIAO_DIEM_VUONG_GOC(diemVuongGoc1, *startPoint, *endPoint, pEnemy->CurrentPos);
			float nDistance1 = Distance_2D(diemVuongGoc1, *startPoint);

			KPos diemVuongGoc2;   // diem vuong goc cua NPC chieu xuong duong thang skill
			GIAO_DIEM_VUONG_GOC(diemVuongGoc2, *startPoint, *endPoint, pNpc->CurrentPos);
			float nDistance2 = Distance_2D(diemVuongGoc2, *startPoint);
			if (nDistance1 - nDistance2 > nKhoangCach) nCountNPC += 1;
		}
	}
	return nCountNPC;
}

//==================================================================================//
//==================================================================================//
int CHAMP_INLINE_SKILL(KNpc* pEnemy, KPos *startPoint,KPos *endPoint, float  nRadius, float nRange, float nKhoangCach)
{
	if(pEnemy == NULL) return 0;
	int nCountNPC = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return 0;
	int nCount = (dw2 - dw1)/4;

	BYTE isDied = (BYTE)pEnemy->nIsDie;
	if (isDied != 0) return 0;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pNpc = (KNpc*)dw3;
		int isDie = (BYTE)pNpc->nIsDie;
		if (!pNpc->IsAlly(pEnemy->nTeam_ID) || isDie == 1 || pNpc->nHP <= 0 || !pNpc->IsChampion())
			continue;
		if ((BYTE)pNpc->nIsTargetableToTeam != 4) continue;
		if (!IsCanSee(pNpc)) continue;
		if (IS_INLINE_SKILL(pNpc, startPoint,endPoint, nRadius, nRange, false))
		{
			KPos diemVuongGoc1;   // diem vuong goc cua Player chieu xuong duong thang skill
			GIAO_DIEM_VUONG_GOC(diemVuongGoc1, *startPoint, *endPoint, pEnemy->CurrentPos);
			float nDistance1 = Distance_2D(diemVuongGoc1, *startPoint);

			KPos diemVuongGoc2;   // diem vuong goc cua NPC chieu xuong duong thang skill
			GIAO_DIEM_VUONG_GOC(diemVuongGoc2, *startPoint, *endPoint, pNpc->CurrentPos);
			float nDistance2 = Distance_2D(diemVuongGoc2, *startPoint);
			if (nDistance1 - nDistance2 > nKhoangCach) nCountNPC += 1;
		}
	}
	return nCountNPC;
}

//==================================================================================//
//==================================================================================//
int HERO_R_INLINE_SKILL(KNpc* pEnemy1, KNpc* pEnemy, KPos *startPoint,KPos *endPoint, float  nRadius, float nRange, float nKhoangCach)// gom hero-only
{
	int nCountNPC = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	int nCount = (dw2 - dw1)/4;

	BYTE isDied = (BYTE)pEnemy->nIsDie;
	if (isDied != 0) return 0;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pNpc = (KNpc*)dw3;
		int isDie = (BYTE)pNpc->nIsDie;
		if (!pNpc->IsAlly(pEnemy->nTeam_ID) || isDie == 1 || pNpc->nHP <= 0 || !pNpc->IsChampion())
			continue;
		if ((BYTE)pNpc->nIsTargetableToTeam != 4) continue;
		if(pEnemy1 == pNpc) continue;
		if (!IsCanSee(pEnemy)) continue;
		if (IS_INLINE_SKILL(pNpc, startPoint,endPoint, nRadius, nRange, false))
		{
			KPos diemVuongGoc1;   // diem vuong goc cua Player chieu xuong duong thang skill
			GIAO_DIEM_VUONG_GOC(diemVuongGoc1, *startPoint, *endPoint, pEnemy->CurrentPos);
			float nDistance1 = Distance_2D(diemVuongGoc1, *startPoint);

			KPos diemVuongGoc2;   // diem vuong goc cua NPC chieu xuong duong thang skill
			GIAO_DIEM_VUONG_GOC(diemVuongGoc2, *startPoint, *endPoint, pNpc->CurrentPos);
			float nDistance2 = Distance_2D(diemVuongGoc2, *startPoint);
			if (nDistance1 - nDistance2 > nKhoangCach) nCountNPC += 1;
		}
	}
	return nCountNPC;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int CountEnemyInQuadOf(KNpc* pEnemy, KPos *startPoint,KPos *endPoint, float  nWidth, float nLength)
{
	int nCountNPC = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return 0;
	int nCount = (dw2 - dw1)/4;

	BYTE isDied = (BYTE)pEnemy->nIsDie;
	if (isDied != 0) return 0;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pNpc = (KNpc*)dw3;
		if(!pNpc->IsMinion() && !pNpc->IsChampion()) continue;
		if(!IsValidTarget(pNpc)) continue;
	
		//if (CheckName( (sz__Minion), pNpc->GetNameNpc()) == false) continue;
		if (IS_INLINE_SKILL(pNpc, startPoint,endPoint, nWidth, nLength, false))
		{
			nCountNPC += 1;
		}
	}
	return nCountNPC;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void ThongBaoDutDiem(KNpc *pEnemy, int SttSkill)
{
	//char txt[50];
	//char fmt[50] = "co the dut diem %s tu xa bang skill %s";
	//char skill[2] = "R";
	//if (2 == SttSkill) strcpy(skill, "E");
	//else if (1 == SttSkill) strcpy(skill, "W");
	//else if (0 == SttSkill) strcpy(skill, "Q");
	//sprintf(txt, fmt, pEnemy->GetNameHero(), skill);
	//SEND_TEXT_SYSTEM(txt);
}


//==================================================================================//
bool hasSpell(int stt, char* szName)
{
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return false;

	KSkill *pSkill = (KSkill *)pPlayer->_pSkill[stt];
	if(!pSkill) return false;
	KSkill_2*  pKSkill_2GetName = (KSkill_2*) pSkill->__pK_str2;
	if(!pKSkill_2GetName) return false;
	
	if (CheckName(pKSkill_2GetName->GetSkillName(), szName) && CheckName(szName, pKSkill_2GetName->GetSkillName())) return true;
	return false;
}

//==================================================================================//
bool DO_SKILL_ITEM(KNpc* pNPC, char* ITEM_NAME)
{
	//nDoSkill_DeltaTick = nDoSkill_TickEnd - nDoSkill_TickStart;
	//if(nDoSkill_DeltaTick < SLMHTClientData::GetInstance()->GetCBDelaySkillAfter()) return false;

	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return false;
	if ((BYTE)pPlayer->nIsDie == 1) return false;

	for (int i = 0; i < 20; ++i)
	{
		KSkill *pSkill = (KSkill *)pPlayer->_pSkill[i];
		if(!pSkill) continue;
		KSkill_2*  pKSkill_2GetName = (KSkill_2*) pSkill->__pK_str2;
		if(!pKSkill_2GetName) continue;
		
		//__oMsg("[%d]pKSkill_2GetName: %s ", i, pKSkill_2GetName->GetSkillName());
		if (CheckName(pKSkill_2GetName->GetSkillName(), ITEM_NAME) && CheckName(ITEM_NAME, pKSkill_2GetName->GetSkillName()))
		{
			if (CanCastSpell2(i) != 0) return false;
			DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
			DWORD nFunc		= CAST_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
			DWORD _ECX		= (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;

			DWORD nDest		= (DWORD)&pNPC->CurrentPos.x;
			DWORD nIndex	= pNPC->nIndex;
			float buffMouse[3]		 = {0,0,0};
			DWORD nBuffer = (DWORD)&buffMouse[0];
			__asm{
				push nIndex
				push nBuffer
				push nDest
				push i
				push pSkill
				mov ecx,_ECX
				mov eax,nFunc
				call eax
			}
			//nDoSkill_TickStart = (float)GetTickCount();
			//__oMsg("[SMITE-]nDoSkill_DeltaTick %f", nDoSkill_DeltaTick);
			return true;
		}
	}
	return false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int GET_STT_SKILL(char* SKILL_NAME)
{
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return -1;
	if ((BYTE)pPlayer->nIsDie == 1) return -1;

	for (int i = 0; i < 20; ++i)
	{
		KSkill *pSkill = (KSkill *)pPlayer->_pSkill[i];
		if(!pSkill) continue;
		KSkill_2*  pKSkill_2GetName = (KSkill_2*) pSkill->__pK_str2;
		if(!pKSkill_2GetName) continue;
		if (CheckName(pKSkill_2GetName->GetSkillName(), SKILL_NAME) && CheckName(SKILL_NAME, pKSkill_2GetName->GetSkillName()))
		{
			return i;
		}
	}
	return -1;
}

//==================================================================================//
bool hasItem(int nID)
{
	if(GET_ITEM(nID)) return true;
	return false;
}

//==================================================================================//
KItem* GET_ITEM(int nID)
{
	//return 0;
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return 0;

	for (int i = 0; i < 11; ++i)
	{
		KItem *pItem = (KItem*)pPlayer->_pItem[i];
		if(!pItem) continue;
		//__oMsg("[%d] %x", i, pItem);
		KItem_1 *pItem_1 = (KItem_1*)pItem->_KItem_1;
		if(!pItem_1) continue;
		//__oMsg("[pItem_1] %x", pItem_1);
		//break;
		KItem_2 *pItem_2 = (KItem_2*)pItem_1->_KItem_2;
		if(!pItem_2) continue;
		//__oMsg("[%d] NAME: %s - ITEM_ID = %x", i, pItem_1->pName, pItem_2->nID);
		if (pItem_2->nID == nID)
		{
			return pItem;
		}
	}
	return 0;
}

//==================================================================================//
KItem* GET_ITEM_2(KNpc* pNPC, int nID)
{
	//return 0;
	if(!pNPC) return 0;

	for (int i = 0; i < 11; ++i)
	{
		KItem *pItem = (KItem*)pNPC->_pItem[i];
		if(!pItem) continue;
		//__oMsg("[%d] %x", i, pItem);
		KItem_1 *pItem_1 = (KItem_1*)pItem->_KItem_1;
		if(!pItem_1) continue;
		//__oMsg("[pItem_1] %x", pItem_1);
		//break;
		KItem_2 *pItem_2 = (KItem_2*)pItem_1->_KItem_2;
		if(!pItem_2) continue;
		//__oMsg("[%d] NAME: %s - ITEM_ID = %x", i, pItem_1->pName, pItem_2->nID);
		if (pItem_2->nID == nID)
		{
			return pItem;
		}
	}
	return 0;
}

//==================================================================================//
int GET_ITEM_ID(int nSlotItem)
{
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return 0;

	for (int i = 0; i < 11; ++i)
	{
		KItem *pItem = (KItem*)pPlayer->_pItem[i];
		if(!pItem) continue;
		KItem_1 *pItem_1 = (KItem_1*)pItem->_KItem_1;
		if(!pItem_1) continue;
		KItem_2 *pItem_2 = (KItem_2*)pItem_1->_KItem_2;
		if(!pItem_2) continue;
		if (i == nSlotItem)
		{
			return pItem_2->nID;
		}
	}
	return 0;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool BUY_ITEM(int nID)
{
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return false;
	DWORD nResult = 0;
	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= BUY_ITEM_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX		= (DWORD)(pPlayer) + OFF_THIS_BUY_ITEM;
	int nItem_ID = nID;
	__asm{
		push -1
		push nItem_ID
		mov ecx,_ECX
		mov eax,nFunc
		call eax
		mov nResult,eax
	}
	return (BYTE)nResult > 0 ? true : false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool SELL_ITEM(int nID)
{
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return false;
	DWORD nResult = 0;

	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= SELL_ITEM_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX		= (DWORD)(pPlayer) + OFF_THIS_SELL_ITEM;

	for (int i = 0; i < 11; ++i)
	{
		KItem *pItem = (KItem*)pPlayer->_pItem[i];
		if(!pItem) continue;
		KItem_1 *pItem_1 = (KItem_1*)pItem->_KItem_1;
		if(!pItem_1) continue;
		KItem_2 *pItem_2 = (KItem_2*)pItem_1->_KItem_2;
		if(!pItem_2) continue;
		if (pItem_2->nID == nID)
		{
			int nIndex = i;
			__asm{
				push nIndex
				mov ecx,_ECX
				mov eax,nFunc
				call eax
				mov nResult,eax
			}
		}
	}
	return (BYTE)nResult > 0 ? true : false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool UP_LEVEL(int nSTT_Skill)
{
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return false;
	DWORD nResult = 0;
	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= LEVELUP_SPELL_2_FUNC - TEMP_ENTRY_POINT + hModule; // lay LEVELUP_SPELL_1_FUNC cung dc, nhug phai tinh ECX lang ngoang ..
	int nIndex = nSTT_Skill;
	__asm{
		push nIndex
		mov eax,nFunc
		call eax
		mov nResult,eax
	}
	return (BYTE)nResult > 0 ? true : false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KPos GET_ENEMY_POS_B()
{
	KPos Home1(396, 182, 462);		// can check ky 2 toa do nay
	KPos Home2(14340, 172, 14390);	// can check ky 2 toa do nay

	KPos pPos_B;	

	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD offsetNexus = NEXUS - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return pPos_B;
	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	BYTE isDied = (BYTE)pPlayer->nIsDie;
	if (isDied != 0) return pPos_B;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyNexus = (KNpc*)dw3;
		int isDie = (BYTE)pEnemyNexus->nIsDie;
		if (!pEnemyNexus->IsEnemy(pPlayer->nTeam_ID) || pEnemyNexus->nIs_Nexus != (int)offsetNexus || isDie == 1 || pEnemyNexus->nHP <= 0.)
			continue;

		float fdistance_1 = Distance_3D(Home1, pEnemyNexus->CurrentPos);
		float fdistance_2 = Distance_3D(Home2, pEnemyNexus->CurrentPos);
		if (fdistance_1 > fdistance_2)
		{
			pPos_B.x = Home2.x;
			pPos_B.y = Home2.y;
			pPos_B.z = Home2.z;
		}
		else
		{
			pPos_B.x = Home1.x;
			pPos_B.y = Home1.y;
			pPos_B.z = Home1.z;
		}
		return pPos_B;
	}
	return pPos_B;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KBuffs*  GET_BUFF(KNpc* pNpc ,char* szBuffName)
{
	if(!pNpc) return 0;
	if ((BYTE)pNpc->nIsDie == 1) return 0;

	int nBuff_Count = (pNpc->pMax_Buffs - pNpc->pBuffs)/8;
	for(int i=0; i< nBuff_Count; i++){
		DWORD dw = *(DWORD*)(pNpc->pBuffs + 8*i);
		KBuffs* pBuffs = (KBuffs*)dw;
		if(!pBuffs) continue;
		if(pBuffs->nIndex == -1) continue;
		KBuffs_1* pBuffs_1 = (KBuffs_1*)pBuffs->__pBuffs_1;
		if(!pBuffs_1) continue;
		if(pBuffs->nStart_Count == pBuffs->nEnd_Count) continue;						// dang ko bi gam giao: nhan dang bang cai nay cung dc
		//__oMsg("[test] Buff Name: [%d] %x : %s", i, pBuffs, pBuffs_1->szName);
		if(!(CheckName(szBuffName, pBuffs_1->szName) && CheckName(pBuffs_1->szName, szBuffName))) continue;
		//__oMsg("Buff Name: [%d] %x : %s ========= %x - %x..%x", i, pBuffs, pBuffs_1->szName, &pBuffs->nStart_NhanDang, pBuffs->nEnd_NhanDang, &pBuffs->nStart_Count);
		//if(pBuffs->nStart_NhanDang == pBuffs->nEnd_NhanDang) continue;				// dang ko bi gam giao
		

		//=============doan nay tinh thu sluong giao============================================================================
		//int nCount_Giao = (pBuffs->nEnd_Count - pBuffs->nStart_Count)/8;
		//__oMsg("[DA TIM THAY] Buff Name: [%d] %x : %s", i, pBuffs, pBuffs_1->szName);
		//=======================================================================================================================
		return pBuffs;
	}
	return 0;
}

//==================================================================================//
char*  GET_BUFF_NAME(KBuffs* pBuff)
{
	if (pBuff == 0) return "NULL";

	KBuffs_1* pBuffs_1 = (KBuffs_1*)pBuff->__pBuffs_1;
	if(pBuffs_1)
	{
		return pBuffs_1->szName;
	}
	return "NULL";
}

//==================================================================================//
KNpc* GetObjectByBuff(KBuffs *pCurBuff)
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	DWORD nTempAttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempAttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	
	DWORD dw1 = *(DWORD*)nTempAttackableUnit;
	DWORD dw2 = *(DWORD*)nTempAttackableUnit_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pObject = (KNpc*)dw3;
		if((BYTE)pObject->nIsDie == 1 || pObject->nIndex < 0x3FFFFCC8) continue;
		int nBuff_Count = (pObject->pMax_Buffs - pObject->pBuffs)/8;
		for(int j=0; j< nBuff_Count; j++){
			DWORD dwbuff = *(DWORD*)(pObject->pBuffs + 8*j);
			KBuffs* pBuffs = (KBuffs*)dwbuff;
			if(pBuffs == pCurBuff) return pObject;
		}	
	}
	return 0;
}

//==================================================================================//
void Get_All_BuffNameActive(KNpc* pNpc, char* (&nResult)[60])
{
	int nBuff_Count = (pNpc->pMax_Buffs - pNpc->pBuffs)/8;
	for(int i=0; i< nBuff_Count; i++){
		DWORD dw = *(DWORD*)(pNpc->pBuffs + 8*i);
		KBuffs* pBuffs = (KBuffs*)dw;
		if(!pBuffs) continue;
		if(pBuffs->nIndex == -1) continue;
		if(pBuffs->nStart_Count == pBuffs->nEnd_Count) continue;
		KBuffs_1* pBuffs_1 = (KBuffs_1*)pBuffs->__pBuffs_1;
		if(!pBuffs_1) continue;
		//strcpy(nResult[i], pBuffs_1->szName);
		nResult[i] = pBuffs_1->szName;
	}
}

//==================================================================================//
//==================================================================================//
int	COUNT_BUFF_BY_TYPE(KNpc* pNpc, int nType)
{
	int nRs = 0;
	int nBuff_Count = (pNpc->pMax_Buffs - pNpc->pBuffs)/8;
	for(int i=0; i< nBuff_Count; i++){
		DWORD dw = *(DWORD*)(pNpc->pBuffs + 8*i);
		KBuffs* pBuffs = (KBuffs*)dw;
		if(!pBuffs) continue;
		if(pBuffs->nIndex == -1) continue;
		if(pBuffs->nStart_Count == pBuffs->nEnd_Count) continue;

		//KBuffs_1* pBuffs_1 = (KBuffs_1*)pBuffs->__pBuffs_1;
		//if(!pBuffs_1) continue;						
		//__oMsg("%d [%s]", (BYTE)pBuffs->nIndex, pBuffs_1->szName);
		if(/*nType != Knockup_Buff && */(BYTE)pBuffs->nIndex == nType)
		{
			nRs +=1;
			//KBuffs_1* pBuffs_1 = (KBuffs_1*)pBuffs->__pBuffs_1;
			//if(!pBuffs_1) continue;						
			//__oMsg("%d [%s]", (BYTE)pBuffs->nIndex, pBuffs_1->szName);
		}
		//if(nType == Knockup_Buff && (BYTE)pBuffs->nIndex == nType)
		//{
			//if(GET_BUFF(pNpc, "barontailpopup") == 0) nRs +=1;
		//}
	}
	return nRs;
}

//==================================================================================//
//==================================================================================//
int	GET_BUFF_DUNGIM(KNpc* pEnemy)
{
	int nBuff_Count = (pEnemy->pMax_Buffs - pEnemy->pBuffs)/8;
	for(int i=0; i< nBuff_Count; i++){
		DWORD dw = *(DWORD*)(pEnemy->pBuffs + 8*i);
		KBuffs* pBuffs = (KBuffs*)dw;
		if(!pBuffs) continue;
		if((BYTE)pBuffs->nIndex == -1 || pBuffs->__pBuffs_1 == 0) continue;
		if(pBuffs->nStart_Count == pBuffs->nEnd_Count)            continue;						
		if((BYTE)pBuffs->nIndex == Stun_Buff )					  return (BYTE)pBuffs->nIndex;				// Stun
		if((BYTE)pBuffs->nIndex == Snare_Buff)				   	  return (BYTE)pBuffs->nIndex;				// Snare(troi Bay Jinx, W-Ryze ...)	
		if((BYTE)pBuffs->nIndex == Sleep_Buff)				   	  return (BYTE)pBuffs->nIndex;				// Slee[(Sleep-Zoe ...)	
		//if((BYTE)pBuffs->nIndex == Knockup_Buff)		          return (BYTE)pBuffs->nIndex;				// Knockup 
		//if((BYTE)pBuffs->nIndex == Knockback_Buff)		return (BYTE)pBuffs->nIndex;				// Knockback
	}
	return 0;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int	GET_BUFF_SLOW(KNpc* pEnemy)
{
	if(pEnemy->nMoveSpeed < 280.0)									return 1;
	return 0;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int	GET_BUFF_BATLOI(KNpc* pEnemy)
{
	int nBuff_Count = (pEnemy->pMax_Buffs - pEnemy->pBuffs)/8;
	for(int i=0; i< nBuff_Count; i++){
		DWORD dw = *(DWORD*)(pEnemy->pBuffs + 8*i);
		KBuffs* pBuffs = (KBuffs*)dw;
		if(!pBuffs) continue;
		if((BYTE)pBuffs->nIndex == -1 || pBuffs->__pBuffs_1 == 0) continue;
		if(pBuffs->nStart_Count == pBuffs->nEnd_Count)            continue;		
		if((BYTE)pBuffs->nIndex == Charm_Buff)					return (BYTE)pBuffs->nIndex;			
		if((BYTE)pBuffs->nIndex == Fear_Buff)					return (BYTE)pBuffs->nIndex;
		if((BYTE)pBuffs->nIndex == Flee_Buff)					return (BYTE)pBuffs->nIndex;
		if((BYTE)pBuffs->nIndex == Taunt_Buff)					return (BYTE)pBuffs->nIndex;			
		if((BYTE)pBuffs->nIndex == Polymorph_Buff)				return (BYTE)pBuffs->nIndex;			
		if((BYTE)pBuffs->nIndex == Silence_Buff)				return (BYTE)pBuffs->nIndex;			
		if((BYTE)pBuffs->nIndex == Blind_Buff)					return (BYTE)pBuffs->nIndex;			
		//if((BYTE)pBuffs->nIndex == Knockup_Buff && !GET_BUFF(pEnemy,"barontailpopup")) return (BYTE)pBuffs->nIndex;		
		if((BYTE)pBuffs->nIndex == Suppression_Buff)			return (BYTE)pBuffs->nIndex;	// Suppression : dan ap, ap che	(R-Malzahar) => nguy hiem

	}
	return 0;
}

//==================================================================================//
int	GET_BUFF_MIKAEL(KNpc* unit)
{
	int nBuff_Count = (unit->pMax_Buffs - unit->pBuffs)/8;
	for(int i=0; i< nBuff_Count; i++){
		DWORD dw = *(DWORD*)(unit->pBuffs + 8*i);
		KBuffs* pBuffs = (KBuffs*)dw;
		if(!pBuffs) continue;
		if((BYTE)pBuffs->nIndex == -1 || pBuffs->__pBuffs_1 == 0) continue;
		if(pBuffs->nStart_Count == pBuffs->nEnd_Count)            continue;		
		if((BYTE)pBuffs->nIndex == Stun_Buff)					return (BYTE)pBuffs->nIndex;
		if((BYTE)pBuffs->nIndex == Snare_Buff)					return (BYTE)pBuffs->nIndex;
		if((BYTE)pBuffs->nIndex == Sleep_Buff)					return (BYTE)pBuffs->nIndex;
		if((BYTE)pBuffs->nIndex == Taunt_Buff)					return (BYTE)pBuffs->nIndex;
		if((BYTE)pBuffs->nIndex == Fear_Buff)					return (BYTE)pBuffs->nIndex;	
		if((BYTE)pBuffs->nIndex == Silence_Buff)				return (BYTE)pBuffs->nIndex;			
	}
	return 0;
}

//==================================================================================//
int	GET_BUFF_THANHTAY(KNpc* unit)
{
	int nBuff_Count = (unit->pMax_Buffs - unit->pBuffs)/8;
	for(int i=0; i< nBuff_Count; i++){
		DWORD dw = *(DWORD*)(unit->pBuffs + 8*i);
		KBuffs* pBuffs = (KBuffs*)dw;
		if(!pBuffs) continue;
		if((BYTE)pBuffs->nIndex == -1 || pBuffs->__pBuffs_1 == 0) continue;
		if(pBuffs->nStart_Count == pBuffs->nEnd_Count)            continue;		
		if((BYTE)pBuffs->nIndex == Stun_Buff)					return (BYTE)pBuffs->nIndex;
		if((BYTE)pBuffs->nIndex == Snare_Buff)					return (BYTE)pBuffs->nIndex;
		if((BYTE)pBuffs->nIndex == Sleep_Buff)					return (BYTE)pBuffs->nIndex;
		if((BYTE)pBuffs->nIndex == Taunt_Buff)					return (BYTE)pBuffs->nIndex;
		if((BYTE)pBuffs->nIndex == Charm_Buff)					return (BYTE)pBuffs->nIndex;
		if((BYTE)pBuffs->nIndex == Fear_Buff)					return (BYTE)pBuffs->nIndex;	
		if((BYTE)pBuffs->nIndex == Blind_Buff)					return (BYTE)pBuffs->nIndex;
		if((BYTE)pBuffs->nIndex == Flee_Buff)					return (BYTE)pBuffs->nIndex;
		if((BYTE)pBuffs->nIndex == Polymorph_Buff)				return (BYTE)pBuffs->nIndex;
		if((BYTE)pBuffs->nIndex == Silence_Buff)				return (BYTE)pBuffs->nIndex;			
	}
	return 0;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int	GET_BUFF_DACBIET(KNpc* pEnemy)
{
	//if(GET_BUFF(pEnemy ,  (sz__Meditate)))					return 1;	// THIEN cua M.Yi
	if(GET_BUFF(pEnemy ,  (sz__AlphaStrike)))				return 1;	// tuyet ky ALPHA cua M.Yi

	if(GET_BUFF(pEnemy ,  (sz__zhonyasringshield)))		return 2;   // dong ho cat
	if((pEnemy->nHP + pEnemy->nGiap_Mau) < 75 && GET_BUFF(pEnemy ,  (sz__UndyingRage)))		return 2;	// Tu Choi Tu Than cua Tryndamere(1 cai nua la :bloodlustparticle)
	if(GET_BUFF(pEnemy ,  (sz__JudicatorIntervention)))	return 2;   // Bat Tu Ho Than cua Kayle -> ko bi sat thuong trong 2s
	if(GET_BUFF(pEnemy ,  (sz__bardrstasis)))				return 2;   // R cua Bard				-> ko bi sat thuong trong 2.5s
	if (GET_BUFF(pEnemy,  (sz__VladimirSanguinePool)))		return 2;	// chieu W cua Vladimir
	if (GET_BUFF(pEnemy,  (sz__AatroxPassiveDeath)))		return 2;	// Hieu ung Aatrox hoi sinh
	if (GET_BUFF(pEnemy,  (sz__KarthusDeathDefiedBuff)))	return 2;	// Hieu ung xay ra khi Karthus chet
	if (GET_BUFF(pEnemy,  (sz__KogMawIcathianSurprise)))	return 2;	// Hieu ung xay ra khi KogMaw chet
	return 0;
}
// "RyzeW" -> hieu ung troi W cua Ryze
// "RyzeE" -> hieu ung dong chay ma phap E cua Ryze






