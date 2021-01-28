#include "VMTHooked.h"
#include "VMT_OnProcessSpell.h"
#include "VMT_OnCreateObject.h"
#include "VMT_OnSendRecvPacket.h"


extern bool canUse_VMT;
OnProcessSpellAction*		OPS_HookedList = 0;
OnProcessSpellAction_222*	OPS_HookedList_222 = 0;
OnCreateMissileAction*		OCM_HookedList = 0;
OnPlayAnimationAction*		OPA_HookedList = 0;
OnSendRecvPacketAction* 	OSRP_HookedList = 0;
//==================================================================================//
DWORD GetOrg_Func(PDWORD vtable, int index)
{
	return vtable[index];
}

//==================================================================================//
void Detour_VMT_ALL()
{
	if (OPS_HookedList	   == 0) OPS_HookedList		= new OnProcessSpellAction;
	if (OPS_HookedList_222 == 0) OPS_HookedList_222 = new OnProcessSpellAction_222;

	if (OCM_HookedList	   == 0) OCM_HookedList		= new OnCreateMissileAction;
	if (OPA_HookedList	   == 0) OPA_HookedList		= new OnPlayAnimationAction;
	
	if (canUse_VMT)
	{
		//__oMsg("DANG DUNG` BAN HOOK-VTABLE ????????????");
		Detour_VMT_OnProcessSpell();
		////Detour_VMT_OnProcessSpell_222();
		
		Detour_VMT_OnCreateMissile();
	}

}

//==================================================================================//
void Retour_VMT_ALL()
{
	if (canUse_VMT)
	{
		Retour_VMT_OnProcessSpell();
		////Retour_VMT_OnProcessSpell_222();
		
		Retour_VMT_OnCreateMissile();
	}
	
	Retour_VMT_OnSendRecvPacket();
}

//==================================================================================//
//#ifdef _WIN64
//#define _PTR_MAX_VALUE ((void*)0x000F000000000000)
//#else
//#define _PTR_MAX_VALUE ((void*)0xFFF00000)
//#endif

inline bool IsValidPtr(void* p) { return (p >= (void*)0x10000) && (p < (void*)0xFFF00000) && p != 0; }

UINT CountVMTFunctions(PDWORD pdwVMT)
{
	return 1000;


	int dwIndex = 0; 
	for (dwIndex = 0; pdwVMT [ dwIndex ]; dwIndex++)
	{
		if ( !IsValidPtr  ((void*)pdwVMT [dwIndex]))
			break;
		else
		{
			//__oMsg("-- [%d][%x]: %x", dwIndex, (DWORD)&pdwVMT [ dwIndex ], pdwVMT [ dwIndex ]);
		}
	} 
	//__oMsg("------ TOTAL = %d", dwIndex);
	return dwIndex;
}

//==================================================================================//
bool SwapVMT(PDWORD *ppdwClassBase, PDWORD &pdwOldVMT, PDWORD &pdwNewVMT)
{
	pdwOldVMT = *ppdwClassBase;
	//__oMsg("SwapVMT---> pdwOldVMT : %x", pdwOldVMT);

	UINT dwVMTSize = CountVMTFunctions ( pdwOldVMT );
	if ( ! dwVMTSize ) { return false; }

	if (!pdwNewVMT) pdwNewVMT = new DWORD [ dwVMTSize ];
	//PDWORD pdwNewVMT = new DWORD [ dwVMTSize ];
	if ( ! pdwNewVMT ) { return false; }

	memcpy ( pdwNewVMT, pdwOldVMT, sizeof ( DWORD ) * dwVMTSize );
	//__oMsg("pdwNewVMT: %x, OldVMT: %x", pdwNewVMT, pdwOldVMT);
	//return true;

	*ppdwClassBase = pdwNewVMT;

	//__oMsg("SwapVMT : OldVMT: %x, NewVMT : %x - size: %d", pdwOldVMT, pdwNewVMT, dwVMTSize);

	//DWORD OriginalProtection = 0;
	//VirtualProtect((LPVOID)pdwOldVMT, 4, PAGE_EXECUTE_READWRITE, &OriginalProtection);
	//__oMsg("OriginalProtection: %x", OriginalProtection);
	//VirtualProtect((LPVOID)pdwNewVMT, 4, PAGE_EXECUTE_READWRITE, &OriginalProtection);
	//__oMsg("OriginalProtection: %x", OriginalProtection);
	return true;
}

//==================================================================================//
bool SwapVMT_Back(PDWORD *ppdwClassBase, PDWORD pdwOldVMT)
{
	*ppdwClassBase   = pdwOldVMT;

	return true;
}

//==================================================================================//
bool HookVMTFuncion ( PDWORD *ppdwClassBase, DWORD dwNewFunction, UINT uiFunctionIndex )
{
	PDWORD pdwVMT = *ppdwClassBase;
	if ( pdwVMT &&  uiFunctionIndex <= CountVMTFunctions(pdwVMT) &&  uiFunctionIndex >= 0 )
	{
		pdwVMT [ uiFunctionIndex ] = dwNewFunction;
		return true;
	}
	return false;
}

//==================================================================================//