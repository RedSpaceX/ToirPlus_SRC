#include "OnEvent.h"



//==================================================================================//
typedef int (__thiscall* oCreateObject)(void*, DWORD);
oCreateObject oOnCreateObject;
int __stdcall Hook_CreateObject(DWORD nNetworkID)
{
	void * pThis = NULL;
	__asm
	{
		mov pThis, ecx
	}
	KNpc* pObj = (KNpc*)pThis;
	int nRs = oOnCreateObject(pThis, nNetworkID);

	if(pObj->nIndex > 0x3FFFFCC8 && CheckName("reticle_self", pObj->GetNameNpc()))
	{
		//__oMsg("%x, :%x [time:%f][%f,%f,%f][%f,%f,%f] name: %s :\n", pObj->nIndex, pObj->nType_1, GetTimeGame(), pObj->currentPos().x, pObj->currentPos().y, pObj->currentPos().z, pObj->ServerPosition.x, pObj->ServerPosition.y, pObj->ServerPosition.z, pObj->GetNameNpc());
	}
	//__oMsg("Hook_CreateObject: ----> pThis: %x - nNetworkID: %x, name : %s - %x", pThis, nNetworkID, pObj->GetNameNpc(), pObj->nIndex);
	

	if(pObj->nType_1 == 0x8001) // Obj Missile
	{
		KMissileData* pMissData = (KMissileData*)pObj->nMissileData;
		if(pMissData)
		{
			__oMsg("-------Dang Check ben Trong OnCreateObject --------------");
			__oMsg("[nMissileData]      : [%x - %x] = %x", &pObj->nMissileData, (DWORD)&pObj->nMissileData - (DWORD)pObj, pObj->nMissileData);
			__oMsg("[nMissileOwner_ID1] : [%x - %x] = %x", &pObj->nMissileOwnerID_1, (DWORD)&pObj->nMissileOwnerID_1 - (DWORD)pObj, pObj->nMissileOwnerID_1);
			__oMsg("[nMissileOwner_ID2] : [%x - %x] = %x", &pObj->nMissileOwnerID_2, (DWORD)&pObj->nMissileOwnerID_2 - (DWORD)pObj, pObj->nMissileOwnerID_2);
			__oMsg("[nMissileTargetID]  : [%x - %x] = %x", &pObj->nMissileTargetID, (DWORD)&pObj->nMissileTargetID - (DWORD)pObj, pObj->nMissileTargetID);
			__oMsg("[MissileSrcPos]     : [%x - %x] = %f - %f - %f", &pObj->MissileSrcPos.x, (DWORD)&pObj->MissileSrcPos.x - (DWORD)pObj, pObj->MissileSrcPos.x, pObj->MissileSrcPos.y, pObj->MissileSrcPos.z);
			__oMsg("[MissileDestPos]    : [%x - %x] = %f - %f - %f", &pObj->MissileDestPos.x, (DWORD)&pObj->MissileDestPos.x - (DWORD)pObj, pObj->MissileDestPos.x, pObj->MissileDestPos.y, pObj->MissileDestPos.z);
			__oMsg("[MissileCursorPos]  : [%x - %x] = %f - %f - %f", &pObj->MissileCursorPos.x, (DWORD)&pObj->MissileCursorPos.x - (DWORD)pObj, pObj->MissileCursorPos.x, pObj->MissileCursorPos.y, pObj->MissileCursorPos.z);
			__oMsg("[GetMissileOwner_Name] : [%x - %x] = %s", (DWORD)&pMissData->szMissileName, (DWORD)&pMissData->szMissileName - (DWORD)pMissData, pMissData->GetMissileOwner_Name());
			__oMsg("[nOwnerData]           : [%x - %x] = %x", (DWORD)&pMissData->nOwnerData, (DWORD)&pMissData->nOwnerData - (DWORD)pMissData, pMissData->nOwnerData);
			__oMsg("[nMissile_Struct_3]    : [%x - %x] = %x", (DWORD)&pMissData->nMissile_Struct_3, (DWORD)&pMissData->nMissile_Struct_3 - (DWORD)pMissData, pMissData->nMissile_Struct_3);
			KMissile_OwnerData* pMiss_OwnerData = (KMissile_OwnerData*)pMissData->nOwnerData;
			if(pMiss_OwnerData)
			{
				__oMsg("\n[nOwnerData]-> GetMissileOwner_CharName: [%x - %x] = %s", (DWORD)&pMiss_OwnerData->szMissileOwnerCharName, (DWORD)&pMiss_OwnerData->szMissileOwnerCharName - (DWORD)pMiss_OwnerData, pMiss_OwnerData->GetMissileOwner_CharName());
			}
			KMissile_Struct_3* pMiss_Struct_3 = (KMissile_Struct_3*)pMissData->nMissile_Struct_3;
			if(pMiss_Struct_3)
			{
				__oMsg("[Struct_3: %x]-> Range   : %f", &pMiss_Struct_3->nRange, pMiss_Struct_3->nRange);
				__oMsg("[Struct_3]-> Range_2     : %f", pMiss_Struct_3->nRange_2);
				__oMsg("[Struct_3]-> Radius      : %f", pMiss_Struct_3->nRadius);
				__oMsg("[Struct_3]-> MissileSpeed: %f", pMiss_Struct_3->nMissileSpeed);
				__oMsg("[Struct_3]-> MissileWidth: %f", pMiss_Struct_3->nMissileWidth);
			}
		}
	}
	return nRs;
}

//==================================================================================//
DWORD nOnCreateObjFunc  = 0;
DWORD nOnCROBackUp_Code1 = 0;
DWORD nOnCROBackUp_Code2 = 0;
void Detour_OnCreateObj()
{
	if (!IsGameReady())
		return;
	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempFunc = ON_CREATE_OBJ_FUNC - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempFunc = 0x6FB7A0 - TEMP_ENTRY_POINT + hModule;// 0x6FB7A0: 7.24(theo EB)
	DWORD nFunc 	= nTempFunc;

	nOnCreateObjFunc = nFunc;
	if (nOnCreateObjFunc)
	{
		if(!nOnCROBackUp_Code1 || !nOnCROBackUp_Code2)
		{
			nOnCROBackUp_Code1 = *(DWORD*) nOnCreateObjFunc;
			nOnCROBackUp_Code2 = *(DWORD*)(nOnCreateObjFunc + 4);
			oOnCreateObject = (oCreateObject)(DetourFunction((PBYTE)nOnCreateObjFunc,(PBYTE)&Hook_CreateObject));
		}
	}
}

//==================================================================================//
void Retour_OnCreateObj()
{
	if(nOnCROBackUp_Code1 && nOnCROBackUp_Code2)
	{
		DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
		DWORD nTempFunc = ON_CREATE_OBJ_FUNC - TEMP_ENTRY_POINT + hModule;
		//DWORD nTempFunc = 0x6FB7A0 - TEMP_ENTRY_POINT + hModule;
		DWORD nFunc 	= nTempFunc;

		nOnCreateObjFunc = nFunc;

		HWND  hWnd = FindWindow( (sz__RiotWindowClass), NULL);	
		if(hWnd) 
		{
			DWORD proccess_ID;
			GetWindowThreadProcessId(hWnd, &proccess_ID);
			HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, FALSE, proccess_ID);
			if(hProcess)
			{
				DWORD n_Size = 4;					
				WriteProcessMemory(hProcess, (LPVOID)nOnCreateObjFunc, &nOnCROBackUp_Code1, n_Size, &n_Size);
				WriteProcessMemory(hProcess, (LPVOID)(nOnCreateObjFunc + 4), &nOnCROBackUp_Code2, n_Size, &n_Size);
			}
		}
		nOnCROBackUp_Code1 = 0;
		nOnCROBackUp_Code2 = 0;
	}
}

