#include "VMT_OnCreateObject.h"
#include "VMTHooked.h"
#include "SpellDetector.h"





extern OnCreateMissileAction* OCM_HookedList;
extern OnPlayAnimationAction* OPA_HookedList;
//==================================================================================//
//---------------VMT-HOOKING NEW-ON-PLAY-ANIMATION ----------------------------------//

typedef int (__thiscall *OnPlayAnimation_New) (void*, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
OnPlayAnimation_New Org_OnPlayAnimation = 0;	//0x5D6C60 (9.1)	//Ref: 5e2d22 "Idle1"

//==================================================================================//
//------------//-------------------//---------:
DWORD	_unitTemp_OPA  = 0;
DWORD	_arg1_OPA, _arg2_OPA, _arg3_OPA, _arg4_OPA, _arg5_OPA, _arg6_OPA = 0;

struct playAnimation
{
	char  szAnimation[128];
};

//---------------//-------------//-------:
void __declspec(naked) VMTHook_OnPlayAnimation()
{
	__asm mov _unitTemp_OPA, ecx
	__asm
	{
		push eax
		mov eax, dword ptr [esp + 8]
		mov _arg1_OPA, eax	
		mov eax, dword ptr [esp + 12]		//DWORD nAnimation
		mov _arg2_OPA, eax	
		mov eax, dword ptr [esp + 16]
		mov _arg3_OPA, eax	
		mov eax, dword ptr [esp + 20]
		mov _arg4_OPA, eax	
		mov eax, dword ptr [esp + 24]
		mov _arg5_OPA, eax	
		mov eax, dword ptr [esp + 28]
		mov _arg6_OPA, eax	
		pop eax 
	} 

	__asm pushad 
		//__asm pushfd

		if(_arg2_OPA && _unitTemp_OPA)
		{
			if (OPA_HookedList) 
			{
				char * szAnimation = (char *)_arg2_OPA;
				OPA_HookedList->OPA_Called((KNpc*)(_unitTemp_OPA - VMT_ONPLAYANIMATION_OFFSET), szAnimation);
			}

		}

		//__asm popfd
	__asm popad

	__asm
	{
		push _arg6_OPA
		push _arg5_OPA
		push _arg4_OPA
		push _arg3_OPA
		push _arg2_OPA
		push _arg1_OPA
		mov ecx, _unitTemp_OPA
		call Org_OnPlayAnimation
		retn 0x18
	} 
}

//==================================================================================//
void Test_OPA(KNpc* hero, char* szAnimation)
{
	int a = 0;
	if (a == 0) a += 1;
	//__oMsg("Test_OPA:  - %s", hero->GetNameNpc(), szAnimation);
}


//==================================================================================//
//---------------VMT-HOOKING NEW-ON-CREATE-MISSILE ----------------------------------//

typedef int (__thiscall *OnCreateMissile_New ) (void*, DWORD); 
OnCreateMissile_New Org_OnCreateMissile = 0;	//0x5D2D30 (9.1)	//"SData not found for caster unknown\n"

//==================================================================================//
//------------//-------------------//---------:
//DWORD  ON_CREATE_MISSILE		  = 0x5D2D30;		//Ref : 009834EF (9.1 --> ko can dung` nua)
//DWORD  OFFSET_VMT_OnCreateMissile = 0;
//UINT   Index_OnCreateMissile      = 260;			//0x410
PDWORD pdwOldVMT_OnCreateMissile  = 0;
PDWORD pdwNewVMT_OnCreateMissile  = 0;
//------------//-------------------//---------:
KCastSpell* _spellCast_OCM = 0;
DWORD		_unitTemp_OCM  = 0;
DWORD		_arg1_OCM      = 0;
//---------------//-------------//-------:
void __declspec(naked) VMTHook_OnCreateMissile()
{
	__asm mov _unitTemp_OCM, ecx
	__asm
	{
		push eax
		mov eax, dword ptr [esp + 8]
		mov _arg1_OCM, eax							//arg2 : spell
		pop eax 
	} 

	__asm pushad 
		//__asm pushfd

		if(_arg1_OCM && _unitTemp_OCM)
		{
			_spellCast_OCM = (KCastSpell*)(_arg1_OCM - 8);


			//------------ PRINT-TEST ------------:
					/*KSkill_2 *pSkill_2 = (KSkill_2 *)_spellCast_OCM->__pK_str2;
					if (pSkill_2 != 0)
					{
						__oMsg("[OCM][time: %f][%s][%x]: [%.3f, %.3f, %.3f][%.3f, %.3f, %.3f]", GetTimeGame(), pSkill_2->GetSkillName(), _spellCast_OCM->nMy_ID_1, _spellCast_OCM->SourcePos.x, _spellCast_OCM->SourcePos.y, _spellCast_OCM->SourcePos.z, _spellCast_OCM->MaxDestPos.x, _spellCast_OCM->MaxDestPos.y, _spellCast_OCM->MaxDestPos.z);
					}*/
			//------------ PRINT-TEST ------------||--

			if (OCM_HookedList) 
			{
				OCM_HookedList->OCM_Called((KNpc*)(_unitTemp_OCM - VMT_ONCREAREMISSILE_OFFSET), (KCastSpell*)_spellCast_OCM);
			}

		}

		//__asm popfd
	__asm popad

	__asm
	{
		push _arg1_OCM
		mov ecx, _unitTemp_OCM
		call Org_OnCreateMissile
		retn 0x4
	} 
}

//==================================================================================//
void Test_OCM(KNpc* hero, KCastSpell* spellCast)
{
	int a = 0;
	if (a == 0) a += 1;
	//__oMsg("Test_OCM: %s - [%.5f]", hero->GetNameNpc(), GetTimeGame());
}

//==================================================================================//
bool add1Lan_OCM = true;
bool add1Lan_OPA = true;
void Detour_VMT_OnCreateMissile()
{
	if (OCM_HookedList && add1Lan_OCM == true)
	{
		add1Lan_OCM = false;
		OCM_HookedList->Add(Test_OCM);
	}
	
	//------//-------:
	if (OPA_HookedList && add1Lan_OPA == true)
	{
		add1Lan_OPA = false;
		OPA_HookedList->Add(Test_OPA);
	}
	
	//------//-------//---------:
	//------//-------//---------:
	KNpc* myHero = GetPlayer();
	if (!myHero) return;
	
	//------//-------//---------:
	//------//-------//---------:
	if (Org_OnCreateMissile == 0)
	{
		DWORD temp_x = *(DWORD*)((DWORD)myHero + VMT_ONCREAREMISSILE_OFFSET);
		if (temp_x)
			Org_OnCreateMissile = (OnCreateMissile_New)GetOrg_Func((PDWORD)temp_x, VMT_ONCREAREMISSILE_INDEX/4);

		return;
	}

	//------//-------:
	if (Org_OnPlayAnimation == 0)
	{
		DWORD temp_x = *(DWORD*)((DWORD)myHero + VMT_ONPLAYANIMATION_OFFSET);
		if (temp_x)
			Org_OnPlayAnimation = (OnPlayAnimation_New)GetOrg_Func((PDWORD)temp_x, VMT_ONPLAYANIMATION_INDEX/4);
		//__oMsg("Org_OnPlayAnimation: %x", Org_OnPlayAnimation);
		return;
	}
	
	//------//-------//---------:
	//------//-------//---------:
	if (G_Module == 0) return;
	
	//if (Org_OnCreateMissile == 0) Org_OnCreateMissile = (OnCreateMissile_New)(ON_CREATE_MISSILE - TEMP_ENTRY_POINT + G_Module);

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
			if ((DWORD)pdwNewVMT_OnCreateMissile != *(DWORD*)(dwHero3 + VMT_ONCREAREMISSILE_OFFSET))
			{
				if (SwapVMT ((PDWORD*)(dwHero3 + VMT_ONCREAREMISSILE_OFFSET), pdwOldVMT_OnCreateMissile, pdwNewVMT_OnCreateMissile))
				{
					HookVMTFuncion ((PDWORD*)(dwHero3 + VMT_ONCREAREMISSILE_OFFSET), (DWORD) VMTHook_OnCreateMissile, VMT_ONCREAREMISSILE_INDEX/4); 
					HookVMTFuncion ((PDWORD*)(dwHero3 + VMT_ONPLAYANIMATION_OFFSET), (DWORD) VMTHook_OnPlayAnimation, VMT_ONPLAYANIMATION_INDEX/4); 
				}
			}
		}
	}
}

//==================================================================================//
void Retour_VMT_OnCreateMissile()
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

		//if (enemyHero->nTeam_ID != myHero->nTeam_ID || myHero == enemyHero)	// choi all Hero cho mau'
		{
			if (pdwOldVMT_OnCreateMissile)
			{
				SwapVMT_Back((PDWORD*)(dwHero3 + VMT_ONCREAREMISSILE_OFFSET), pdwOldVMT_OnCreateMissile);
				SwapVMT_Back((PDWORD*)(dwHero3 + VMT_ONPLAYANIMATION_OFFSET), pdwOldVMT_OnCreateMissile);
			}
		}
	}
}






////==================================================================================//
//struct fuckSubObject
//{
//	int			temp_1[7];
//	char		szSubObjName[16];		
//	int			nLen;
//	int			nMaxlen;
//	int			temp_2[13];
//	DWORD		funcCreateObject;		//0x68 (9.1)
//
//	char*		GetSubObjName()
//	{
//		char * szName = szSubObjName;
//		if((BYTE)nLen > 15)
//		{
//			DWORD dw = *(DWORD*)&szSubObjName;
//			szName = (char *)dw;
//		}
//		return szName;
//	}
//};
//
////==================================================================================//
//void checkObjectCreated()
//{
//	if (G_Module == 0) return;
//
//	DWORD dw1    = 0x3276BA4 - TEMP_ENTRY_POINT + G_Module;
//	DWORD dw2 = *(DWORD*)dw1;
//	if (!dw2) return;
//
//	for (int i = 0; i < 30; ++i)
//	{
//		int   temp1 = *(DWORD*)(dw2 + 8*i + 0);
//		DWORD temp2 = *(DWORD*)(dw2 + 8*i + 4);
//		
//		fuckSubObject* subObj = (fuckSubObject*)temp2;
//		if (subObj != 0)
//		{
//			__oMsg("--check-- [i=%d, dw2=%x] temp1: %x (%d) - temp2: %x [%s]", i, dw2, temp1, temp1, temp2, subObj->GetSubObjName());
//		}
//	}
//}
//
////---------------//-------------//-------:
//DWORD _ObjCreatedTemp = 0;
//DWORD _Org_OnCreateObject = 0x472FB0;
//DWORD _arg1xx = 0;
//KNpc* fioraPS = 0;
//Vec3D possss(0,0,0);
//void __declspec(naked) VMTHook_OnCreateObject()
//{
//	__asm mov _ObjCreatedTemp, ecx
//	/*__asm
//	{
//		push eax
//		mov eax, dword ptr [esp + 8]
//		mov _arg1xx, eax
//		pop eax 
//	} */
//
//	__asm pushad 
//	
//		__oMsg("_arg1xx: %x, Obj: %x", _arg1xx, _ObjCreatedTemp);
//		fioraPS = (KNpc*)_ObjCreatedTemp;
//		possss = fioraPS->currentPos();
//		__oMsg("   2---> [%s]curPos: %f, %f, %f, src[%f, %f, %f]", fioraPS->GetNameNpc(), fioraPS->currentPos().x,fioraPS->currentPos().y, fioraPS->currentPos().z, fioraPS->ServerPosition.x, fioraPS->ServerPosition.y, fioraPS->ServerPosition.z);
//	__asm popad
//
//
//	__asm
//	{
//		//push _arg1xx
//		mov ecx, _ObjCreatedTemp
//		call _Org_OnCreateObject
//		retn 
//	} 
//}
//
////---------------//-------------//-------:
//DWORD orgCreateObjFunc = 0;
//DWORD objCreated = 0;
//PDWORD pdwNewVMT_OnCreateObj_1 = 0;
//PDWORD pdwOldVMT_OnCreateObj_1 = 0;
//KNpc* fioraPS1 = 0;
//void __declspec(naked) VMTHook_CreateObject()
//{
//	__asm
//	{
//		call orgCreateObjFunc
//		mov objCreated, eax
//		
//	} 
//	
//	__asm pushad 
//
//		__oMsg("1-[objCreated = %x, func = %x", objCreated - 4, orgCreateObjFunc);
//		
//		if (objCreated)
//		{	
//			fioraPS1 = (KNpc*)(objCreated - 4);
//			//__oMsg("   1--->curPos: %f, %f, %f, ", fioraPS1->currentPos().x,fioraPS1->currentPos().y, fioraPS1->currentPos().z);
//			if ((DWORD)pdwNewVMT_OnCreateObj_1 != *(DWORD*)(objCreated - 4 + 0))
//			{
//				if (SwapVMT ((PDWORD*)(objCreated - 4 + 0), pdwOldVMT_OnCreateObj_1, pdwNewVMT_OnCreateObj_1))
//				{
//					HookVMTFuncion ((PDWORD*)(objCreated - 4 + 0), (DWORD) VMTHook_OnCreateObject, 46); 
//				}
//			}
//		}
//
//	__asm popad
//
//	__asm
//	{
//		retn
//
//	} 
//}
//
////==================================================================================//
//void Detour_subObj_0x68()
//{
//	if (G_Module == 0) return;
//
//	DWORD dw1    = 0x3276BA4 - TEMP_ENTRY_POINT + G_Module;
//	DWORD dw2 = *(DWORD*)dw1;
//	if (!dw2) return;
//
//	
//
//	for (int i = 0; i < 30; ++i)
//	{
//		int   temp1 = *(DWORD*)(dw2 + 8*i + 0);
//		DWORD temp2 = *(DWORD*)(dw2 + 8*i + 4);
//
//		fuckSubObject* subObj = (fuckSubObject*)temp2;
//
//		if (temp1 == 9 && subObj != 0)	//obj_GeneralParticleEmitter
//		{
//			orgCreateObjFunc = subObj->funcCreateObject;
//			__oMsg("[i=%d, dw2=%x] temp1: %x(%d) - temp2: %x [%s] - [%x]orgFunc = %x", i, dw2, temp1, temp1, temp2, subObj->GetSubObjName(), (DWORD)&subObj->funcCreateObject, orgCreateObjFunc);
//
//			if (orgCreateObjFunc != 0) 
//				subObj->funcCreateObject = (DWORD)&VMTHook_CreateObject;
//			__oMsg("AFTER, funcNew = %x, old = %x", subObj->funcCreateObject, orgCreateObjFunc);
//			break;
//		}
//	}
//
//	if (orgCreateObjFunc)
//	{
//		
//	}
//}