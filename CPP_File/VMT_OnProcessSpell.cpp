#include "VMT_OnProcessSpell.h"
#include "VMTHooked.h"
#include "SpellDetector.h"


extern OnProcessSpellAction* OPS_HookedList;
extern OnProcessSpellAction_222* OPS_HookedList_222;

DWORD OFFSET_pCast = 0;

//==================================================================================//
//---------------VMT-HOOKING NEW-ON-PROCESS-SPELL ----------------------------------//
//---------------Dung cho Hero thoi, bao gom ca AA va` All.skill QWERDF-123456.......


typedef int (__thiscall *OnProcessSpell_New ) (void*, DWORD, DWORD); 
OnProcessSpell_New Org_OnProcessSpell = 0; //(OnProcessSpell_New)0x5A9A80;//0x5D2D30;//0x97C1D0;//

//==================================================================================//
//------------//-------------------//---------:
//DWORD  ON_PROCESS_SPELL		     = 0x5A9A80;	//Ref : 005D8C37 (9.1 --> ko can dung` nua)
//DWORD  OFFSET_VMT_OnProcessSpell = 0x1018;		//VMT_ONPROCESSSPELL_OFFSET
//UINT   Index_OnProcessSpell      = 26;			//0x68
PDWORD pdwOldVMT_OnProcessSpell	 = 0;
PDWORD pdwNewVMT_OnProcessSpell  = 0;
//------------//-------------------//---------:
KCastSpell* _spellCast = 0;
DWORD		_unitTemp  = 0;
DWORD		_arg1, _arg2, _arg3 = 0;
//---------------//-------------//-------:
void __declspec(naked) VMTHook_OnprocessSpell()
{
	__asm mov _unitTemp, ecx
	__asm
	{
		push eax
		mov eax, dword ptr [esp + 8]
		mov _arg1, eax
		mov eax, dword ptr [esp + 12]			//arg2 : spell
		mov _arg2, eax	
		mov eax, dword ptr [esp + 16]
		mov _arg3, eax
		pop eax 
	} 

	__asm pushad 
	//__asm pushfd

		if(_arg2 && _unitTemp && _arg1 == 0xB && _arg3 == 0)
		{
			_spellCast = (KCastSpell*)(_arg2 - 8);


			////------------ PRINT-TEST ------------:
			//		KSkill_2 *pSkill_2 = (KSkill_2 *)_spellCast->__pK_str2;
			//		if (pSkill_2 != 0)
			//		{
			//			__oMsg("[CurTime: %f][%s][%x]: [%.3f, %.3f, %.3f][%.3f, %.3f, %.3f]", GetTimeGame(), pSkill_2->GetSkillName(), _spellCast->nMy_ID_1, _spellCast->SourcePos.x, _spellCast->SourcePos.y, _spellCast->SourcePos.z, _spellCast->MaxDestPos.x, _spellCast->MaxDestPos.y, _spellCast->MaxDestPos.z);
			//		}
			////------------ PRINT-TEST ------------:




			//------ cho nay phai dung <vector> moi dung kieu ------:
			//OnProcessSpell_2_SpellDetector((KNpc*)(_unitTemp - VMT_ONPROCESSSPELL_OFFSET), (KCastSpell*)_spellCast);

			if (OPS_HookedList) 
			{
				OPS_HookedList->OPS_Called((KNpc*)(_unitTemp - VMT_ONPROCESSSPELL_OFFSET), (KCastSpell*)_spellCast);
			}

		}

	//__asm popfd
	__asm popad


	__asm
	{
		push _arg3
		push _arg2
		push _arg1
		mov ecx, _unitTemp
		call Org_OnProcessSpell
		retn 0xC
	} 
}

//==================================================================================//
void Test_OPS(KNpc* hero, KCastSpell* spellCast)
{
	int a = 0;
	if (a == 0) a += 1;
	//__oMsg_2("Test_OnProcessSpell: %s - %f", hero->GetNameNpc(), GetTimeGame());
}

//==================================================================================//
bool add1Lan_OPS = true;
void Detour_VMT_OnProcessSpell()
{
	if (OPS_HookedList && add1Lan_OPS == true)
	{
		add1Lan_OPS = false;
		OPS_HookedList->Add(Test_OPS);
		OPS_HookedList->Add(OnProcessSpell_2_SpellDetector);
	}
	
	//------//-------//---------:
	KNpc* myHero = GetPlayer();
	if (!myHero) return;
	if (G_Module == 0) return;

	if (OFFSET_pCast == 0)
	{
		OFFSET_pCast = (DWORD)&myHero->_pCastSpellBook - (DWORD)myHero;
	}

	//if (Org_OnProcessSpell == 0) Org_OnProcessSpell = (OnProcessSpell_New)(ON_PROCESS_SPELL - TEMP_ENTRY_POINT + G_Module);

	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dwHero1 = *(DWORD*)tempHero;
	DWORD dwHero2 = *(DWORD*)tempHeroMax;
	if (!dwHero1 || !dwHero2 ) return;

	int countHero = (dwHero2 - dwHero1)/4;
	for (int i = 0; i < countHero; ++i)
	{
		DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
		if (dwHero3 == 0) continue;
		KNpc *enemyHero = (KNpc*)dwHero3;
		//if (IS_DEAD(enemyHero)) continue;

		//if (enemyHero->nTeam_ID != myHero->nTeam_ID || myHero == enemyHero)	// choi all Hero cho mau'
		{
			if ((DWORD)pdwNewVMT_OnProcessSpell != *(DWORD*)(dwHero3 + VMT_ONPROCESSSPELL_OFFSET))
			{
				if (Org_OnProcessSpell == 0)
				{
					DWORD temp_x = *(DWORD*)(dwHero3 + VMT_ONPROCESSSPELL_OFFSET);
					if (temp_x)
						Org_OnProcessSpell = (OnProcessSpell_New)GetOrg_Func((PDWORD)temp_x, VMT_ONPROCESSSPELL_INDEX/4);

					//__oMsg_2("[Hero] - NewVMT = %x, OnProcessSpell = %x - %x", temp_x, GetOrg_Func((PDWORD)temp_x, VMT_ONPROCESSSPELL_INDEX/4), dwHero3 + VMT_ONPROCESSSPELL_OFFSET);
				}
				else
				{
					if (SwapVMT ((PDWORD*)(dwHero3 + VMT_ONPROCESSSPELL_OFFSET), pdwOldVMT_OnProcessSpell, pdwNewVMT_OnProcessSpell))
					{
						HookVMTFuncion ((PDWORD*)(dwHero3 + VMT_ONPROCESSSPELL_OFFSET), (DWORD) VMTHook_OnprocessSpell, VMT_ONPROCESSSPELL_INDEX/4); 
					}
				}
			}
		}
	}
}

//==================================================================================//
void Retour_VMT_OnProcessSpell()
{
	KNpc* myHero = GetPlayer();
	if (!myHero) return;
	if (G_Module == 0) return;

	DWORD tempHero    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	DWORD tempHeroMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dwHero1 = *(DWORD*)tempHero;
	DWORD dwHero2 = *(DWORD*)tempHeroMax;
	if (!dwHero1 || !dwHero2 ) return;

	int countHero = (dwHero2 - dwHero1)/4;
	for (int i = 0; i < countHero; ++i)
	{
		DWORD dwHero3 = *(DWORD*)(dwHero1 + 4*i);
		if (dwHero3 == 0) continue;
		KNpc *enemyHero = (KNpc*)dwHero3;
		//if (IS_DEAD(enemyHero)) continue;

		//if (enemyHero->nTeam_ID != myHero->nTeam_ID || myHero == enemyHero)
		{
			if (pdwOldVMT_OnProcessSpell) 
			{
				SwapVMT_Back((PDWORD*)(dwHero3 + VMT_ONPROCESSSPELL_OFFSET), pdwOldVMT_OnProcessSpell);
			}
		}
	}
}



//==================================================================================//
//==================================================================================//
//---------------VMT-HOOKING NEW-ON-PROCESS-SPELL-2 --------------------------------//
//---------------Dung cho Minion+Turret va` chi voi AA -----------------------------//

typedef int (__thiscall *OnProcessSpell_New_222 ) (void*, DWORD, DWORD); 
OnProcessSpell_New_222 Org_OnProcessSpell_222 = 0; 


PDWORD pdwOldVMT_OnProcessSpell_222	 = 0;
PDWORD pdwNewVMT_OnProcessSpell_222  = 0;
//------------//-------------------//---------:
KCastSpell* _spellCast_222 = 0;
DWORD		_unitTemp_222  = 0;
DWORD		_arg1_222, _arg2_222 = 0;
//---------------//-------------//-------:
void __declspec(naked) VMTHook_OnprocessSpell_222()
{
	__asm mov _unitTemp_222, ecx
	__asm
	{
		push eax
		mov eax, dword ptr [esp + 8]
		mov _arg1_222, eax
		mov eax, dword ptr [esp + 12]			//_arg2_222 : spell
		mov _arg2_222, eax	 
		pop eax 
	} 

	__asm pushad 
		//__asm pushfd
		
		if(_arg2_222 && _unitTemp_222 && OFFSET_pCast)
		{
			_spellCast_222 = (KCastSpell*)(_arg2_222 - 8);

			if (OPS_HookedList_222) 
			{
				OPS_HookedList_222->OPS_Called((KNpc*)(_unitTemp_222 - OFFSET_pCast), (KCastSpell*)_spellCast_222);
			}

		}

		//__asm popfd
		__asm popad


		__asm
		{
			push _arg2_222
			push _arg1_222
			mov ecx, _unitTemp_222
			call Org_OnProcessSpell_222
			retn 0x8
		} 
}

//==================================================================================//
void Test_OPS_222(KNpc* minion, KCastSpell* spellCast)
{
	int a = 0;
	if (a == 0) a += 1;
	//__oMsg_2("Test_OnProcessSpell_222: %s - %f", minion->GetNameNpc(), GetTimeGame());
}

//==================================================================================//
bool add1Lan_OPS_222 = true;
void Detour_VMT_OnProcessSpell_222()
{
	int VMT_ONPROCESSSPELL_222_INDEX = 0x38;

	if (OPS_HookedList_222 && add1Lan_OPS_222 == true)
	{
		add1Lan_OPS_222 = false;
		OPS_HookedList_222->Add(Test_OPS_222);
		//OPS_HookedList_222->Add(xxxx_func);
	}

	//------//-------//---------:
	KNpc* myHero = GetPlayer();
	if (!myHero) return;
	if (G_Module == 0) return;

	if (OFFSET_pCast == 0)
	{
		OFFSET_pCast = (DWORD)&myHero->_pCastSpellBook - (DWORD)myHero;
	}
	
	if (OFFSET_pCast == 0) return;

	//DWORD tempUnit    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
	//DWORD tempUnitMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;

	DWORD tempUnit    = BASE_AttackableUnit     - TEMP_ENTRY_POINT + G_Module;
	DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dwUnit1 = *(DWORD*)tempUnit;
	DWORD dwUnit2 = *(DWORD*)tempUnitMax;
	if (!dwUnit1 || !dwUnit2 ) return;

	int countUnit = (dwUnit2 - dwUnit1)/4;
	for (int i = 0; i < countUnit; ++i)
	{
		DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*i);
		if (dwUnit3 == 0) continue;
		KNpc *UnitAlly = (KNpc*)dwUnit3;

		if (IS_DEAD(UnitAlly))						  continue;
		if ((BYTE)UnitAlly->nIsTargetableToTeam != 4) continue;
		if (UnitAlly->nTeam_ID == 0x12C)			  continue;		//Jungle
		if (UnitAlly->nTeam_ID != myHero->nTeam_ID)	  continue;
		if (Distance(myHero, UnitAlly) > 2200.0f)	  continue;

		if ((IS_MINION(UnitAlly) && CheckName(sz__Minion, UnitAlly->GetNameNpc())) || IS_TURRET(UnitAlly))
		{
			if ((DWORD)pdwNewVMT_OnProcessSpell_222 != *(DWORD*)(dwUnit3 + OFFSET_pCast))
			{
				if (Org_OnProcessSpell_222 == 0)
				{
					DWORD temp_x = *(DWORD*)(dwUnit3 + OFFSET_pCast);
					if (temp_x)
						Org_OnProcessSpell_222 = (OnProcessSpell_New_222)GetOrg_Func((PDWORD)temp_x, VMT_ONPROCESSSPELL_222_INDEX/4);

					//__oMsg_2("[Hero] - NewVMT = %x, OnProcessSpell = %x - %x", temp_x, GetOrg_Func((PDWORD)temp_x, VMT_ONPROCESSSPELL_INDEX/4), dwHero3 + VMT_ONPROCESSSPELL_OFFSET);
				}
				else
				{
					if (SwapVMT ((PDWORD*)(dwUnit3 + OFFSET_pCast), pdwOldVMT_OnProcessSpell_222, pdwNewVMT_OnProcessSpell_222))
					{
						HookVMTFuncion ((PDWORD*)(dwUnit3 + OFFSET_pCast), (DWORD) VMTHook_OnprocessSpell_222, VMT_ONPROCESSSPELL_222_INDEX/4); 
					}
				}
			}
		}

		//DWORD temp_x = *(DWORD*)(dwUnit3 + OFFSET_pCast);
		//if (IS_MINION(UnitAlly))
		//{
		//	__oMsg_2("[MINI] - NewVMT = %x, OnProcessSpell = %x - %x", temp_x, GetOrg_Func((PDWORD)temp_x, VMT_ONPROCESSSPELL_222_INDEX/4), dwUnit3 + VMT_ONPROCESSSPELL_222_INDEX);
		//}
		//
		//if (IS_TURRET(UnitAlly))
		//{
		//	__oMsg_2("[%d] %s - %.3f, %.3f, %.3f", (BYTE)UnitAlly->nIsTargetableToTeam, UnitAlly->GetNameNpc(), UnitAlly->CurrentPos.x, UnitAlly->CurrentPos.y, UnitAlly->CurrentPos.z);

		//	//__oMsg_2("[Turr] - NewVMT = %x, OnProcessSpell = %x - %x", temp_x, GetOrg_Func((PDWORD)temp_x, VMT_ONPROCESSSPELL_222_INDEX/4), dwUnit3 + VMT_ONPROCESSSPELL_222_INDEX);
		//}
		//
		//continue;
	}
	//__oMsg_2("----------\n");
}


//==================================================================================//
void Retour_VMT_OnProcessSpell_222()	// chua chac chan cho lam, sau khi retour co the crash !!!
{
	if (OFFSET_pCast == 0) return;

	KNpc* myHero = GetPlayer();
	if (!myHero) return;
	if (G_Module == 0) return;

	DWORD tempUnit    = BASE_AttackableUnit     - TEMP_ENTRY_POINT + G_Module;
	DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dwUnit1 = *(DWORD*)tempUnit;
	DWORD dwUnit2 = *(DWORD*)tempUnitMax;
	if (!dwUnit1 || !dwUnit2 ) return;

	int countUnit = (dwUnit2 - dwUnit1)/4;
	for (int i = 0; i < countUnit; ++i)
	{
		DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*i);
		if (dwUnit3 == 0) continue;
		KNpc *UnitAlly = (KNpc*)dwUnit3;

		if (IS_DEAD(UnitAlly))						  continue;
		if ((BYTE)UnitAlly->nIsTargetableToTeam != 4) continue;
		if (UnitAlly->nTeam_ID == 0x12C)			  continue;		//Jungle
		if (UnitAlly->nTeam_ID != myHero->nTeam_ID)	  continue;
		//if (Distance(myHero, UnitAlly) > 2200.0f)	  continue;

		if ((IS_MINION(UnitAlly) && CheckName(sz__Minion, UnitAlly->GetNameNpc())) || IS_TURRET(UnitAlly))
		{
			if (pdwOldVMT_OnProcessSpell_222 && (DWORD)pdwOldVMT_OnProcessSpell_222 != *(DWORD*)(dwUnit3 + OFFSET_pCast))
			{
				SwapVMT_Back((PDWORD*)(dwUnit3 + OFFSET_pCast), pdwOldVMT_OnProcessSpell_222);
			}
		}
	}
}


////==================================================================================//
////---------------VMT-HOOKING NEW-ON-PROCESS-SPELL ----------------------------------//
//
//typedef int (__thiscall *OnProcessSpell_TEST_New ) (void*, DWORD, DWORD); 
//OnProcessSpell_TEST_New Org_OnProcessSpell_TEST = (OnProcessSpell_TEST_New)0x5F0810; //(OnProcessSpell_TEST_New)0x5A9A80;//0x5D2D30;//0x97C1D0;//
//
////==================================================================================//
////------------//-------------------//---------:
//DWORD  ON_PROCESS_SPELL_TEST		  = 0x5F0810;	
//DWORD  OFFSET_VMT_OnProcessSpell_TEST = 0x1018;
//UINT   Index_OnProcessSpell_TEST      = 3;			//0xC
//PDWORD pdwOldVMT_OnProcessSpell_Hero  = 0;
//PDWORD pdwNewVMT_OnProcessSpell_Hero  = 0;
//
//PDWORD pdwOldVMT_OnProcessSpell_Minion  = 0;
//PDWORD pdwNewVMT_OnProcessSpell_Minion  = 0;
////------------//-------------------//---------:
//KCastSpell* _spellCast_TEST = 0;
//DWORD		_unitTemp_TEST  = 0;
//DWORD		_arg1_TEST, _arg2_TEST = 0;
////---------------//-------------//-------:
//void __declspec(naked) VMTHook_OnProcessSpell_TEST()
//{
//	__asm mov _unitTemp_TEST, ecx
//	__asm
//	{
//		push eax
//		mov eax, dword ptr [esp + 8]
//		mov _arg1_TEST, eax
//		mov eax, dword ptr [esp + 12]			//arg2 : spell
//		mov _arg2_TEST, eax	
//		//mov eax, dword ptr [esp + 16]
//		//mov _arg3_TEST, eax
//		pop eax 
//	} 
//
//	__asm pushad 
//	//__asm pushfd
//
//		//__oMsg("%x, %x, %x [%x]", _arg1_TEST, _arg2_TEST, _arg3_TEST, *(DWORD*)_arg2_TEST);
//		if(_arg1_TEST == 0 && _arg2_TEST != 0 && _unitTemp_TEST != 0)
//		{
//			__oMsg("[_arg2_TEST: %x - %x", _arg2_TEST, _unitTemp_TEST - OFFSET_VMT_OnProcessSpell_TEST);
//			_spellCast_TEST = (KCastSpell*)(_arg2_TEST - 8);
//
//			//if (!IsBadReadPtr(_spellCast_TEST, 128))
//			{
//				if (_spellCast_TEST->nMy_ID_1 != 0 && _spellCast_TEST->nMy_ID_1 == _spellCast_TEST->nMy_ID_2)
//				{
//					//------------ PRINT-TEST ------------:
//					KSkill_2 *pSkill_2 = (KSkill_2 *)_spellCast_TEST->__pK_str2;
//					if (pSkill_2 != 0)
//					{
//						__oMsg("[OPS_MAIN: %f][%s][%x]: [%.3f, %.3f, %.3f][%.3f, %.3f, %.3f]", GetTimeGame(), pSkill_2->GetSkillName(), _spellCast_TEST->nMy_ID_1, _spellCast_TEST->SourcePos.x, _spellCast_TEST->SourcePos.y, _spellCast_TEST->SourcePos.z, _spellCast_TEST->MaxDestPos.x, _spellCast_TEST->MaxDestPos.y, _spellCast_TEST->MaxDestPos.z);
//					}
//					//------------ PRINT-TEST ------------:
//
//					////------ cho nay phai dung <vector> moi dung kieu ------:
//					//OnProcessSpell_2_SpellDetector((KNpc*)(_unitTemp_TEST - OFFSET_VMT_OnProcessSpell_TEST), (KCastSpell*)_spellCast_TEST);
//					if (OPS_HookedList) 
//					{
//						OPS_HookedList->OPS_Called((KNpc*)(_unitTemp_TEST - OFFSET_VMT_OnProcessSpell_TEST), (KCastSpell*)_spellCast_TEST);
//					}
//				}
//			}
//		}
//
//	//__asm popfd
//	__asm popad
//
//
//	__asm
//	{
//		push _arg1_TEST
//		mov ecx, _unitTemp_TEST
//		call Org_OnProcessSpell_TEST
//		retn 0x4
//	} 
//}
//
////==================================================================================//
//bool add1Lan = true;
//void Detour_VMT_OnProcessSpell_TEST()
//{
//	if (OPS_HookedList && add1Lan == true)
//	{
//		add1Lan = false;
//		OPS_HookedList->Add(OnProcessSpell_2_SpellDetector);
//		//__oMsg(" ---------------- ADDED 1 LAN THOI ANH OI --------- ADDEDEDEDED -------");
//	}
//
//	KNpc* myHero = GetPlayer();
//	if (!myHero) return;
//	if (G_Module == 0) return;
//
//	if (Org_OnProcessSpell_TEST == 0) Org_OnProcessSpell_TEST = (OnProcessSpell_TEST_New)(ON_PROCESS_SPELL_TEST - TEMP_ENTRY_POINT + G_Module);
//
//	DWORD tempUnit    = BASE_HERO     - TEMP_ENTRY_POINT + G_Module;
//	DWORD tempUnitMax = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;
//	DWORD dwUnit1 = *(DWORD*)tempUnit;
//	DWORD dwUnit2 = *(DWORD*)tempUnitMax;
//	if (!dwUnit1 || !dwUnit2 ) return;
//
//	int countUnit = (dwUnit2 - dwUnit1)/4;
//	for (int i = 0; i < countUnit; ++i)
//	{
//		DWORD dwUnit3 = *(DWORD*)(dwUnit1 + 4*i);
//		if (dwUnit3 == 0) continue;
//		KNpc *unitt = (KNpc*)dwUnit3;
//		if (IS_DEAD(unitt)) continue;
//		if (IS_HERO(unitt))
//		{
//			if ((DWORD)pdwNewVMT_OnProcessSpell_Hero != *(DWORD*)(dwUnit3 + OFFSET_VMT_OnProcessSpell_TEST))
//			{
//				if (SwapVMT ((PDWORD*)(dwUnit3 + OFFSET_VMT_OnProcessSpell_TEST), pdwOldVMT_OnProcessSpell_Hero, pdwNewVMT_OnProcessSpell_Hero))
//				{
//					HookVMTFuncion ((PDWORD*)(dwUnit3 + OFFSET_VMT_OnProcessSpell_TEST), (DWORD) VMTHook_OnProcessSpell_TEST, Index_OnProcessSpell_TEST); 
//				}
//				__oMsg("[%x]Hero : %x - %s", dwUnit3, *(DWORD*)(dwUnit3 + OFFSET_VMT_OnProcessSpell_TEST), unitt->GetNameNpc());
//				//__oMsg("[%x][%x]OnProcessSpell_TEST.SWAP-VTABLE: %s - %x - %x", dwHero3, dwHero3 + OFFSET_VMT_OnProcessSpell_TEST, enemyHero->GetNameHero(), pdwOldVMT_OnProcessSpell_TEST, pdwNewVMT_OnProcessSpell_TEST);
//			}
//		}
//
//		//if (IS_MINION(unitt) && CheckName("Minion_", unitt->GetNameNpc()))
//		//{
//		//	if ((DWORD)pdwNewVMT_OnProcessSpell_Minion != *(DWORD*)(dwUnit3 + OFFSET_VMT_OnProcessSpell_TEST))
//		//	{
//		//		if (SwapVMT ((PDWORD*)(dwUnit3 + OFFSET_VMT_OnProcessSpell_TEST), pdwOldVMT_OnProcessSpell_Minion, pdwNewVMT_OnProcessSpell_Minion))
//		//		{
//		//			HookVMTFuncion ((PDWORD*)(dwUnit3 + OFFSET_VMT_OnProcessSpell_TEST), (DWORD) VMTHook_OnProcessSpell_TEST, Index_OnProcessSpell_TEST); 
//		//		}
//		//		__oMsg("Minion : %x - %s", *(DWORD*)(dwUnit3 + OFFSET_VMT_OnProcessSpell_TEST), unitt->GetNameNpc());
//		//		//__oMsg("[%x][%x]OnProcessSpell_TEST.SWAP-VTABLE: %s - %x - %x", dwHero3, dwHero3 + OFFSET_VMT_OnProcessSpell_TEST, enemyHero->GetNameHero(), pdwOldVMT_OnProcessSpell_TEST, pdwNewVMT_OnProcessSpell_TEST);
//		//	}
//		//}
//	}
//}
//
////==================================================================================//
//void Retour_VMT_OnProcessSpell_TEST()
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
//		KNpc *unitt = (KNpc*)dwHero3;
//		if (IS_DEAD(unitt)) continue;
//
//		if (IS_HERO(unitt)   && pdwOldVMT_OnProcessSpell_Hero)   SwapVMT_Back((PDWORD*)(dwHero3 + OFFSET_VMT_OnProcessSpell_TEST), pdwOldVMT_OnProcessSpell_Hero);
//		//if (IS_MINION(unitt) && CheckName("Minion_", unitt->GetNameNpc()) && pdwOldVMT_OnProcessSpell_Minion) SwapVMT_Back((PDWORD*)(dwHero3 + OFFSET_VMT_OnProcessSpell_TEST), pdwOldVMT_OnProcessSpell_Minion);
//	}
//}









