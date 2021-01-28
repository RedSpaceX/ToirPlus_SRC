#include "Utils.h"

float g_TimePrevious = 0;
float g_TimeNow = 0;
bool g_TimeSpecial = false;
extern bool g_bNormalAttackHero, g_bCheckKeyPress, g_bPressingKey_S, g_bClearLane, g_bHarass;
extern bool g_isUsedFlash;
KNpc g_EnemyPlayer_ODD[5];
KNpc g_EnemyPlayer_EVEN[5];
float nCoolDownAA_Chuan = 0;


bool nLUA_BasicAtackOnly = false;
bool nLUA_MoveOnly = false;
extern DWORD G_Module;

int countBiDanhBoiSkillDinhHuong = 0;

extern DWORD G_Module;
//==================================================================================//
bool IS_ALIVE(KNpc* pNpc)			//[NEW] ---> dung` khi Obj ton tai, con song ...
{
	if (!G_Module) return false;
	if (!pNpc)	   return false;

	BYTE result = 0; 
	DWORD nFunc	= IS_ALIVE_FUNC - TEMP_ENTRY_POINT + G_Module;
	DWORD _ECX  = (DWORD)pNpc;
	
	__asm
	{
		push _ECX
		mov ecx, _ECX
		mov eax, nFunc
		call eax
		mov result, al
	}

	return (result <= 0) ? false : true;
}

//==================================================================================//
bool IS_TARGET_ABLE(KNpc* pNpc)		//[NEW] ---> dung` khi quat' dc Obj
{
	return false;


	/*if (!G_Module) return false;
	if (!pNpc)	   return false;

	BYTE result = 0; 
	DWORD nFunc	= IS_TARGET_ABLE_FUNC - TEMP_ENTRY_POINT + G_Module;
	DWORD _ECX  = (DWORD)pNpc;

	__asm
	{
		push _ECX
		mov ecx, _ECX
		mov eax, nFunc
		call eax
		mov result, al
	}

	return (result <= 0) ? false : true;*/
}

//==================================================================================//
void CHECK_MISSILE()
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return;

	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == 0) return;

	DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + hModule;

	DWORD dw0 = *(DWORD*)nTempBASE_OBJECT_ALL;
	if (!dw0) return;

	DWORD dw1 = *(DWORD*)(dw0 + 8);
	if (!dw1) return;

	int nCount_n = *(DWORD*)(dw0 + 0xC);
	if (!nCount_n) return;

	for (int kk = 0; kk < nCount_n; ++kk)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*kk);
		if (dw3 == 0) continue;
		KNpc *missileObj = (KNpc*)dw3;
		if (IS_OBJ_DELETED(missileObj, "123") == true)	 continue;

		//if(missileObj->nIndex < 0x3FFFFCC8)      continue;
		//if(!IS_OBJECT_TYPE(missileObj, 0x8000))	 continue;

		if (CheckName("SRU", missileObj->GetNameNpc())) continue;
		if (CheckName("sru", missileObj->GetNameNpc())) continue;
		if (CheckName("Sru", missileObj->GetNameNpc())) continue;
		if (CheckName("LevelProp", missileObj->GetNameNpc())) continue;
		if (CheckName("Dragon", missileObj->GetNameNpc())) continue;
		if (CheckName("Dragon", missileObj->GetNameNpc())) continue;
		if (CheckName("Barracks", missileObj->GetNameNpc())) continue;
		if (CheckName("Turret", missileObj->GetNameNpc())) continue;
		if (CheckName("Swain_", missileObj->GetNameNpc())) continue;
		if (CheckName("candle_", missileObj->GetNameNpc())) continue;
		if (CheckName("Plinths_", missileObj->GetNameNpc())) continue;
		if (CheckName("Plant", missileObj->GetNameNpc())) continue;
		if (CheckName("_T1", missileObj->GetNameNpc())) continue;
		if (CheckName("_T2", missileObj->GetNameNpc())) continue;
		if (CheckName("monsterCamp", missileObj->GetNameNpc())) continue;

		if (CheckName("SRX_", missileObj->GetNameNpc())) continue;
		if (CheckName("Info_BrazierLocation", missileObj->GetNameNpc())) continue;
		if (CheckName("DrawFX", missileObj->GetNameNpc())) continue;
	


		////if (CheckName("Ashe", missileObj->GetNameNpc()))		//if (IS_OBJECT_TYPE(missileObj, 0x8001))
		////{
		////	KMissileData* misData = (KMissileData*)missileObj->nMissileData;
		////	//__oMsg("[%x]misData: %x - OwnerID_1: %x - OwnerID_2: %x", missileObj, missileObj->nMissileData, missileObj->nMissileOwnerID_1, missileObj->nMissileOwnerID_2);
		////	__oMsg("----------- misData: %x [%s] - type: %x", misData, missileObj->GetNameNpc(), OBJECT_TYPE(missileObj));
		////	//return;
		////}

		__oMsg("%s - %x", missileObj->GetNameNpc(), OBJECT_TYPE(missileObj));

		if (/*CheckName("Senna", missileObj->GetNameNpc()) &&*/ IS_OBJECT_TYPE(missileObj, 0x8000))
		{
			KMissileData* misData = (KMissileData*)missileObj->nMissileData;
			__oMsg("[%x]misData: %x - OwnerID_1: %x - OwnerID_2: %x", missileObj, missileObj->nMissileData, missileObj->nMissileOwnerID_1, missileObj->nMissileOwnerID_2);
			__oMsg("----------- misData: %x ", misData /*missileObj->nTemp_9_11, missileObj->nTemp_9_11*/);

			//return;

			//__oMsg("Temp[0]: %x", missileObj->nTemp_9_12[0]);
			//__oMsg("Temp[1]: %x", missileObj->nTemp_9_12[1]);
			//__oMsg("Temp[2]: %x", missileObj->nTemp_9_12[2]);
			//__oMsg("Temp[3]: %x", missileObj->nTemp_9_12[3]);
			//__oMsg("Temp[4]: %x", missileObj->nTemp_9_12[4]);
			//__oMsg("Temp[5]: %x", missileObj->nTemp_9_12[5]);
			//__oMsg("Temp[6]: %x", missileObj->nTemp_9_12[6]);

			if (misData)
			{
				KMissile_Struct_3* pMiss_Struct_3 = (KMissile_Struct_3*)misData->nMissile_Struct_3;
				if (pMiss_Struct_3)
				{
					__oMsg("MisSpeed: %f (%.2f - %.2f), %s, %s [src: %.3f, %.3f, %.3f][des: %.3f, %.3f, %.3f][cursor: %.3f, %.3f, %.3f]",pMiss_Struct_3->nMissileSpeed, pMiss_Struct_3->nMissileMinSpeed, pMiss_Struct_3->nMissileMaxSpeed, misData->GetMissileOwner_Name(), missileObj->GetNameNpc(), missileObj->MissileSrcPos.x, missileObj->MissileSrcPos.y, missileObj->MissileSrcPos.z, missileObj->MissileDestPos.x, missileObj->MissileDestPos.y, missileObj->MissileDestPos.z, missileObj->MissileCursorPos.x, missileObj->MissileCursorPos.y, missileObj->MissileCursorPos.z);
				}
			}
		}

	}	
}

//==================================================================================//
bool g_Exit = false;
bool Get_Exit(){
	return g_Exit;
}

//==================================================================================//
void Set_LUA_Combo(bool nIsCombo)
{
	
}

//==================================================================================//
void Set_LUA_Harass(bool nIsHarass)
{
	
}

//==================================================================================//
void Set_LUA_ClearLane(bool nIsClearLane)
{
	
}

void Set_LUA_BasicAttack(bool nIsLuaBAOnly)
{
	
}

//==================================================================================//
void Set_LUA_MoveOnly(bool nIsLuaMoveOnly)
{
	
}
//==================================================================================//
extern int LUA_KEY_CODE;
int Get_Key_Code()
{	
	//__oMsg("LUA_KEY_CODE %d", LUA_KEY_CODE);
	return LUA_KEY_CODE;
}

//==================================================================================//
//==================================================================================//
void RecheckLoginMsg(bool isSuccess)
{
	//char txt[50];
	//sprintf(txt, "Thread[%d]-", GetCurrentThreadId());
	//if (isSuccess)
	//{
	//	sprintf(txt, "%s%s",txt, "re-check login thanh cong");
	//	SEND_TEXT_SYSTEM(txt);
	//} 
	//else
	//{
	//	sprintf(txt, "%s%s",txt, "re-check login that bai");
	//	SEND_TEXT_SYSTEM(txt);
	//}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
float nMoveFunc4Evade_TickStart = 0;
float nMoveFunc4Evade_TickEnd   = 0;
float nMoveFunc4Evade_DeltaTick = 0;

#include <intrin.h>

#pragma intrinsic(_ReturnAddress)

void MOVE_TO(float &posX, float &posY) {
	//nMoveFunc4Evade_DeltaTick = nMoveFunc4Evade_TickEnd - nMoveFunc4Evade_TickStart;
	//if(nMoveFunc4Evade_DeltaTick < 100) return;
	////VMProtectBegin("DLL_VM__MOVE_TO_ORG");
	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempFunc = MOVE_TO_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD nFunc 	= nTempFunc;

	DWORD nTempECX  = BASE - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX 		= *(DWORD*)nTempECX;
	if(!_ECX) return;
	float posZ		 = GetPlayer() ? GetPlayer()->CurrentPos.y : 0.0f;
	float buff[5]		 = {posX,posZ,posY};
	DWORD* nBuffer = (DWORD*)&buff[0];

	
	///*if (_ReturnAddress())
	//{
	//	__oMsg_2("R11113331");
	//}
	//__oMsg_2("Return address from %s: %p\n", __FUNCTION__, _ReturnAddress());*/


	__asm{
		push 1
		push 0
		push 0
		push 0
		push nBuffer
		push 2
		mov ecx,_ECX
		mov eax,nFunc
		call eax
	}
	
	return;


	DWORD retnAddress = 0x1A1DD8; //0xF66198;//0x3F8B7C;
	DWORD retnInstruction = hModule + retnAddress; //retn instruction 
	__asm
	{
			push retnHere
			mov ecx, _ECX
			push 0
			push 0
			push 0
			push 0
			push nBuffer
			push 2
			push retnInstruction
			//mov ebp, x111
			//mov [esp], ebp
			//add   esp, 4 
			jmp nTempFunc
			retnHere:
	}

//	__oMsg("========== CALL_MOVE: %f", nDeltaTick_MoveFunc);
	//nMoveFunc4Evade_TickStart = (float)GetTickCount();
	////VMProtectEnd();
}

//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
float nMoveFunc_TickStart = 0;
float nMoveFunc_TickEnd   = 0;
float nMoveFunc_DeltaTick = 0;
float nMoveFunc_DelayMax      = 0;
//void MOVE_TO_RCLICK(float &posX, float &posY) 
//{
//	nMoveFunc_DeltaTick = nMoveFunc_TickEnd - nMoveFunc_TickStart;
//	if(nMoveFunc_DeltaTick < nMoveFunc_DelayMax) return;
//
//	////VMProtectBegin("DLL_VM__MOVE_TO_RCLICK");
//	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
//	DWORD nTempFunc = RCLICK_MOVE_TO_FUNC - TEMP_ENTRY_POINT + hModule;
//	DWORD nFunc 	= nTempFunc;
//
//	DWORD nTempBASE_SKILL  = BASE_SKILL - TEMP_ENTRY_POINT + hModule;
//	DWORD dw1 = *(DWORD*)nTempBASE_SKILL;
//	if (!dw1) return;
//	DWORD dw2 = *(DWORD*)(dw1 + 0x24);
//	if (!dw2) return;
//	DWORD _ECX 		= dw2;
//
//	KPos vScreen, pPosIn;
//	pPosIn.x = posX;
//	pPosIn.y = 0;
//	pPosIn.z = posY;
//	WorldPos_to_ScreenPos(&pPosIn, &vScreen);
//	int nPosXScreen = (int)vScreen.x;
//	int nPosYScreen = (int)vScreen.y;
//	__asm{
//			push 0
//			push 0
//			push nPosYScreen
//			push nPosXScreen
//			push 0
//			push 0
//			push 0
//			mov ecx,_ECX
//			mov ebx,nFunc
//			call ebx
//			//.....goi lan 2(nha chuot)
//			push 0
//			push 0
//			push nPosYScreen
//			push nPosXScreen
//			push 0
//			push 0
//			push 1
//			mov ecx,_ECX
//			mov ebx,nFunc
//			call ebx
//	}
//	//delete vScreen;
//	//delete pPosIn;
//	//__oMsg("nDelayMove_Max: %f, %f", nMoveFunc_DelayMax, nMoveFunc_DeltaTick);
//	nMoveFunc_TickStart = (float)GetTickCount();
//	////VMProtectEnd();
//}

////--------------------------------------------------------------------------------
////--------------------------------------------------------------------------------
//void MOVE_TO_EVENT(float &posX, float &posY) 
//{
//	nMoveFunc_DeltaTick = nMoveFunc_TickEnd - nMoveFunc_TickStart;
//	if(nMoveFunc_DeltaTick < nMoveFunc_DelayMax) return;
//
//	////VMProtectBegin("DLL_VM__MOVE_TO_EVENT");
//	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
//	DWORD nTempFunc = EVENT_MOVE_TO_FUNC - TEMP_ENTRY_POINT + hModule;
//	DWORD nFunc 	= nTempFunc;
//
//	DWORD nTempBASE_SKILL  = BASE_SKILL - TEMP_ENTRY_POINT + hModule;
//	DWORD dw1 = *(DWORD*)nTempBASE_SKILL;
//	if (!dw1) return;
//	DWORD dw2 = *(DWORD*)(dw1 + 0x24);
//	if (!dw2) return;
//	DWORD _ECX 		= dw2;
//
//	KPos vScreen, pPosIn;
//	pPosIn.x = posX;
//	pPosIn.y = 0;
//	pPosIn.z = posY;
//	WorldPos_to_ScreenPos(&pPosIn, &vScreen);
//	int nPosXScreen = (int)vScreen.x;
//	int nPosYScreen = (int)vScreen.y;
//
//	KGameEvent pGameEvent;
//	pGameEvent.pName_evtPlayerMoveClick_MouseTriggered = (DWORD)&sz__evtPlayerMoveClick_MouseTriggered;
//	pGameEvent.nLen_EventName						   = 0x21;
//	pGameEvent.nMaxLen_EventName					   = 0x2F;
//	pGameEvent.nThamSoBang1					           = 1;
//	pGameEvent.nPosXScreen					           = nPosXScreen;
//	pGameEvent.nPosYScreen					           = nPosYScreen;
//	pGameEvent.nThamSo_Click					       = 0;
//	pGameEvent.pName_evtPlayerReleaseMoveClick		   = (DWORD)&sz__evtPlayerReleaseMoveClick;
//	DWORD nThamSo = (DWORD)&pGameEvent.pName_evtPlayerMoveClick_MouseTriggered;
//	//__oMsg("pGameEvent: %x", pGameEvent);
//	__asm{
//			push nThamSo
//			mov ecx,_ECX
//			mov ebx,nFunc
//			call ebx
//	}
//	/*pGameEvent.nThamSo_Click					       = 2;
//	__asm{
//			push nThamSo
//			mov ecx,_ECX
//			mov ebx,nFunc
//			call ebx
//	}*/
//	pGameEvent.nThamSo_Click					       = 1;
//	__asm{
//			push nThamSo
//			mov ecx,_ECX
//			mov ebx,nFunc
//			call ebx
//	}
//	//delete vScreen;
//	//delete pPosIn;
//	//__oMsg("nDelayMove_Max: %f, %f", nMoveFunc_DelayMax, nMoveFunc_DeltaTick);
//	nMoveFunc_TickStart = (float)GetTickCount();
//	////VMProtectEnd();
//}

//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
//extern float nDoSkill_TickEnd;
//int  GET_DELAYMOVE_RANDOM()
//{
//	//nDoSkill_TickEnd  = (float)GetTickCount();
//	nMoveFunc_TickEnd       = (float)GetTickCount();
//	nMoveFunc4Evade_TickEnd = (float)GetTickCount();
//	int nDelay_Random = 100;
//	//srand(time(NULL)); //==> ko can cai nay`. cho no random loan len
//	//nDelay_Random = rand() % 51 + 140;   // khoang do dai 150-200
//	//if(CountEnemyPlayerInRange(2000) == 0) nDelay_Random = 250;
//	return nDelay_Random;
//}

//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
void  DISABLE_SETECTOR()
{
	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_SKILL = BASE_SKILL - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_SKILL;
	if(!dw1) return;
	DWORD dw2 = *(DWORD*)(dw1 + 0x30);
	if(!dw2) return;
	KSelectTarget* pSelectTarget = (KSelectTarget*)dw2;
	//__oMsg("nSelectOrNot: %x",(BYTE)pSelectTarget->nSelectOrNot);
	if((BYTE)pSelectTarget->nSelectOrNot == 1) (BYTE)pSelectTarget->nSelectOrNot = 0;
}

//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
DWORD GET_ENEMY_ID_SELECTED()
{
	DWORD nResult = 0;
	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_SKILL = BASE_SKILL - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_SKILL;
	if(!dw1) return 0;
	DWORD dw2 = *(DWORD*)(dw1 + 0x30);
	if(!dw2) return 0;
	KSelectTarget* pSelectTarget = (KSelectTarget*)dw2; 
	nResult = pSelectTarget->nIDTargetSelected;
	return nResult;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
extern bool g_IsDodging;
void BlockMove()
{
	KNpc *pPlayer = GetPlayer();
	if (pPlayer == NULL)
	{
		return;
	}
	if (pPlayer->nBLOCK_MOVE != 1)
		pPlayer->nBLOCK_MOVE = 1;
	g_IsDodging = true;
	//__oMsg("test block move, %x, %d", &pPlayer->nBLOCK_MOVE,pPlayer->nBLOCK_MOVE );
}


//==================================================================================//
//==================================================================================//
//==================================================================================//
void UnBlockMove()
{
	KNpc *pPlayer = GetPlayer();
	if (pPlayer == NULL)
	{
		return;
	}
	if (pPlayer->nBLOCK_MOVE != 0)
		pPlayer->nBLOCK_MOVE = 0;
	g_IsDodging = false;
	//__oMsg("test unblock move, %x, %d", &pPlayer->nBLOCK_MOVE,pPlayer->nBLOCK_MOVE );
}


//==================================================================================//
//==================================================================================//
//==================================================================================//
void SEND_TEXT_SYSTEM(char *szTextMsg)
{
	//__oMsg("SEND_TEXT_SYSTEM-1: %s", szTextMsg);
	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc = SEND_TEXT_SYSTEM_FUNC - TEMP_ENTRY_POINT + hModule;
	
	DWORD tmpECX  = BASE_CHAT_SYS - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX    = *(DWORD*)tmpECX ;
	if(!_ECX) return;
	DWORD* szText = (DWORD*)szTextMsg;
	__asm{
		push 1
		push szText
		mov ecx,_ECX
		mov eax,nFunc
		call eax
	}
	//__oMsg("SEND_TEXT_SYSTEM-2");
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void SEND_CHAT2PLAYER(char *szTextMsg)
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD dw1  = ECX_SEND_CHAT - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX  = *(DWORD*)dw1;
	if(!_ECX) return;
	DWORD dw2  = *(DWORD*)_ECX;
	if(!dw2) return;
	DWORD nFunc = *(DWORD*)(dw2 + 128);
	if(!nFunc) return;

	DWORD* szText = (DWORD*)szTextMsg;
	//__oMsg("nFunc: %x", nFunc);
	__asm{
			push 0
			push szText
			mov ecx,_ECX
			mov eax,nFunc
			call eax
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int isTypeEnter = 0;
bool IS_CHATTING()
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD dw1     = BASE_CHAT_SYS - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX    = *(DWORD*)dw1 ;
	if (!_ECX) return false;
	//__oMsg_2("chatting-1 : %x", _ECX);
	DWORD dw2  = *(DWORD*)(_ECX + 0x7C);
	if (dw2 == 0) return false;

	if ((BYTE)dw2 == 1)
	{
		return true;

		//DWORD temp  = BASE_DRAW_CIRCLEMINIMAP - TEMP_ENTRY_POINT + hModule;
		//DWORD dw_miniMap = *(DWORD*)temp;
		//if (!dw_miniMap) return false;
		////__oMsg_2("chatting-2 : %x", dw_miniMap);

		//BYTE rs = *(BYTE*)(dw_miniMap + 0x80);
		//if (rs != 0) return true;
	}
	return false;


	////------ cu~ -------------
	//bool nIs_Chatting = false;
	//DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	//DWORD dw1  = BASE_CHAT_SYS - TEMP_ENTRY_POINT + hModule;
	//DWORD _ECX    = *(DWORD*)dw1 ;
	//if(!_ECX) return false;
	//DWORD dw2  = *(DWORD*)(_ECX + 0x7C);
	//if(!dw2) return nIs_Chatting;
	//if((BYTE)dw2 == 1) nIs_Chatting = true;
	//return nIs_Chatting;
}

////////==================================================================================//
//////#include <Psapi.h>
//////#pragma comment(lib, "Psapi.lib")
//////HMODULE GetGameModule()
//////{
//////	HWND g_hWinAPP = FindWindow("RiotWindowClass", NULL); // Game
//////	if (!g_hWinAPP) return 0;
//////
//////	DWORD dwProcessID;
//////	GetWindowThreadProcessId(g_hWinAPP, &dwProcessID);
//////	if(!dwProcessID) return 0;
//////
//////	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION|PROCESS_CREATE_THREAD|PROCESS_VM_OPERATION|PROCESS_VM_WRITE|PROCESS_VM_READ, FALSE, dwProcessID);
//////	if(!hProcess) return 0;
//////
//////	SIZE_T Memory = 0;
//////	SYSTEM_INFO sys_info = {0};
//////	WCHAR NtMappedFileName[MAX_PATH + 1] = {0};
//////	MEMORY_BASIC_INFORMATION mem_basic_info	= {0};
//////
//////	GetSystemInfo(&sys_info);
//////
//////	for(Memory = 0; Memory < (SIZE_T)sys_info.lpMaximumApplicationAddress; Memory += mem_basic_info.RegionSize)
//////	{
//////		SIZE_T vqr = VirtualQueryEx(hProcess, (LPCVOID)Memory, &mem_basic_info, sizeof(MEMORY_BASIC_INFORMATION));
//////		if(vqr != 0)
//////		{
//////			//__oMsg(":[%x] base:%x, APro:%x, Pro:%x, Type:%x, state:%x, size:%x", mem_basic_info.AllocationBase, mem_basic_info.BaseAddress, mem_basic_info.AllocationProtect, mem_basic_info.Protect, mem_basic_info.Type, mem_basic_info.State, mem_basic_info.RegionSize);
//////			if((mem_basic_info.AllocationProtect & PAGE_EXECUTE_WRITECOPY) && (mem_basic_info.Protect & (PAGE_EXECUTE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY)))
//////			{
//////				if(GetMappedFileNameW(hProcess, (HMODULE)mem_basic_info.AllocationBase,
//////					NtMappedFileName, MAX_PATH) == 0)
//////				{
//////					return (HMODULE)mem_basic_info.AllocationBase;
//////				}
//////			}
//////		}
//////		else
//////		{
//////			return 0;
//////		}
//////	}
//////	return 0;
//////}

//==================================================================================//
void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition( hStdOut, homeCoords );
}


//==================================================================================//
#include <Psapi.h>
#pragma comment(lib, "Psapi.lib")
HMODULE GetGameModule()
{
	HWND g_hWinAPP = FindWindow("RiotWindowClass", NULL); // Game
	if (!g_hWinAPP) return 0;

	DWORD dwProcessID;
	GetWindowThreadProcessId(g_hWinAPP, &dwProcessID);
	if(!dwProcessID) return 0;

	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION|PROCESS_CREATE_THREAD|PROCESS_VM_OPERATION|PROCESS_VM_WRITE|PROCESS_VM_READ, FALSE, dwProcessID);
	if(!hProcess) return 0;

	SIZE_T Memory = 0;
	SYSTEM_INFO sys_info = {0};
	WCHAR NtMappedFileName[MAX_PATH + 1] = {0};
	MEMORY_BASIC_INFORMATION mem_basic_info	= {0};

	GetSystemInfo(&sys_info);

	for(Memory = 0; Memory < (SIZE_T)sys_info.lpMaximumApplicationAddress; Memory += mem_basic_info.RegionSize)
	{
		SIZE_T vqr = VirtualQueryEx(hProcess, (LPCVOID)Memory, &mem_basic_info, sizeof(MEMORY_BASIC_INFORMATION));
		if(vqr != 0)
		{
			//__oMsg(":[%x] base:%x, APro:%x, Pro:%x, Type:%x, state:%x, size:%x", mem_basic_info.AllocationBase, mem_basic_info.BaseAddress, mem_basic_info.AllocationProtect, mem_basic_info.Protect, mem_basic_info.Type, mem_basic_info.State, mem_basic_info.RegionSize);
			if((mem_basic_info.AllocationProtect & PAGE_EXECUTE_WRITECOPY) && (mem_basic_info.Protect & (PAGE_EXECUTE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY)))
			{
				if(GetMappedFileNameW(hProcess, (HMODULE)mem_basic_info.AllocationBase,
					NtMappedFileName, MAX_PATH) == 0)
				{
					if (hProcess)
					{
						CloseHandle(hProcess);
						return (HMODULE)mem_basic_info.AllocationBase;
					}
				}
			}
		}
		else
		{
			return 0;
		}
	}
	return 0;
}

//==================================================================================//
DWORD g_Address = 0;
HMODULE MyGetModuleHandle(const char* name)
{
	//return GetGameModule();
	//return (HMODULE)0x400000;


	if(G_Module) return (HMODULE)(G_Module + g_Address);
	
	//HMODULE hModule = GetModuleHandle(NULL) + g_Address;
	//if(hModule) return hModule;

	HMODULE hModule = GetModuleHandle(name) + g_Address;
	if(hModule) return hModule;

	//hModule = GetGameModule();
	//if(hModule) return hModule;

	return 0;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
float Get_Delay_BasicAttack()
{
	float nDelay_BA = 675;
	KNpc *pPlayer = GetPlayer();
	if (!pPlayer) return nDelay_BA;
	if(IS_ADC(pPlayer)) nDelay_BA = 450;
	/*if (CheckName(pPlayer->GetNameHero(),  (sz__Jinx)))				nDelay_BA = 400.0;
	else if (CheckName(pPlayer->GetNameHero(),  (sz__Thresh)))			nDelay_BA = 450.0;
	else																		nDelay_BA = 400.0;*/
	
	float nBonus_ASpeed = pPlayer->nAttackSpeedMod - 1;
	float nReduced_Time = (float)0.30*nDelay_BA*nBonus_ASpeed;
	nDelay_BA = nDelay_BA - nReduced_Time;
	
	if(nDelay_BA <= 250) nDelay_BA = 250;
	//__oMsg("nHit:(%d) nDelay: %f - nReduced: %f -(%f)",nFirst_Hit, nDelay_BA, nReduced_Time, nBonus_ASpeed*100);
	//__oMsg("nDelay: %f ",nDelay_BA);
	return nDelay_BA;
}
//==================================================================================//
//==================================================================================//
//==================================================================================//
extern float nCoolDownAA_Chuan;
extern bool bIsLuaLoaded;

void NormalAttack(KNpc *pNpc)
{
	////VMProtectBegin("DLL_VM__NormalAttack");
	KNpc* pPlayer = GetPlayer();
	if(pPlayer && CheckName((sz__Jhin), pPlayer->GetNameHero()))
	{
		if(pPlayer->nJhinMissile == 0) return;// Jhin DangThayDan
	}

	//--- FireBeforeAttack(target);
	

	

	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempFunc = MOVE_TO_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD nFunc 	= nTempFunc;

	DWORD nTempECX  = BASE - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX 		= *(DWORD*)nTempECX;

	if(!_ECX) return;
	DWORD Monster	= (DWORD)&pNpc->nTemp_1;

	DWORD* nBuffer	= (DWORD*)&pNpc->CurrentPos.x;
	__asm{
			push 1
			push 0
			push 0
			push Monster
			push nBuffer
			push 3
			mov ecx,_ECX
			mov eax,nFunc
			call eax
	}

	nCoolDownAA_Chuan = Get_AA_Delay() + GetTimeGame() + (float)0.1 ;
	////VMProtectEnd();
	//__oMsg("goi vao Normal Attack");
}



//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IsAllyMinionInRange(float nRange)
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return false;
	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return false;
	BYTE isDied = (BYTE)pPlayer->nIsDie;
	if (isDied != 0) return false;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pAllyMinion = (KNpc*)dw3;
		int isDie = (BYTE)pAllyMinion->nIsDie;
		if (!pAllyMinion->IsAlly(pPlayer->nTeam_ID) || isDie == 1 || pAllyMinion->nHP <= 0. || !pAllyMinion->IsMinion())
			continue;
		float fdistance = Distance_2D(pPlayer->CurrentPos, pAllyMinion->CurrentPos);
		if (fdistance > nRange) continue;
		if (CheckName( (sz__Minion), pAllyMinion->GetNameNpc()) == false) continue;
		return true;
	}
	return false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int CountEnemyMinionInRange(float nRange)
{
	int countEnemyMinion = 0;

	if(!G_Module) return 0;
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + G_Module;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return 0;
	int nCount = (dw2 - dw1)/4;
	
	

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *enemyMinion = (KNpc*)dw3;
		if(!enemyMinion->IsMinion()) continue;
		if(!IsValidTarget(enemyMinion, nRange)) continue;
		
		if (CheckName(sz__Minion, enemyMinion->GetNameNpc()) == false) continue;
		countEnemyMinion += 1;
	}
	return countEnemyMinion;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IsEnemyTurretInRange(float nRange)
{
	if(!G_Module) return false;
	DWORD tempUnit    = BASE_AttackableUnit     - TEMP_ENTRY_POINT + G_Module;
	DWORD tempUnitMax = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + G_Module;
	DWORD dw1 = *(DWORD*)tempUnit;
	DWORD dw2 = *(DWORD*)tempUnitMax;
	if (!dw1 || !dw2 ) return false;

	int nCount = (dw2 - dw1)/4;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *enemyTurret = (KNpc*)dw3;
		if(!enemyTurret->IsTurret()) continue;
		if(!IsValidTarget(enemyTurret, nRange)) continue;
		return true;
	}
	return false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int CountEnemyPlayerInRange(float nRange)
{
	int countEnemy = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == 0) return 0;
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;

	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return 0;

	int nCount = (dw2 - dw1)/4;	
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *enemy = (KNpc*)dw3;
		if(!IsValidTarget(enemy, nRange)) continue;
		
		countEnemy += 1;
	}
	return countEnemy;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int Count_EnemyPlayer_Around_NPC(KNpc* pNpc, float nRange)
{
	int countEnemy = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == 0) return 0;
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;

	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return 0;

	int nCount = (dw2 - dw1)/4;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *enemy = (KNpc*)dw3;
		if(pNpc == enemy) continue;
		if(!IsValidTarget(enemy)) continue;
		
		countEnemy += 1;
	}
	return countEnemy;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int Count_EnemyMinion_Around_NPC(KNpc* pNpc, float nRange)
{
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyMinion = (KNpc*)dw3;
		if(pNpc == pEnemyMinion) continue;
		if(!pEnemyMinion->IsMinion()) continue;
		if(!IsValidTarget(pEnemyMinion)) continue;	
		
		if (CheckName(sz__Minion, pEnemyMinion->GetNameNpc()) == false) continue;

		jCount += 1;
	}
	return jCount;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int Count_EnemyTurret_Around_NPC(KNpc* pNpc, float nRange)
{
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return 0;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyTurret = (KNpc*)dw3;
		int isDie = (BYTE)pEnemyTurret->nIsDie;
		if (!pEnemyTurret->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pEnemyTurret->nHP <= 0. || !pEnemyTurret->IsTurret())
			continue;
		if ((BYTE)pEnemyTurret->nIsTargetableToTeam != 4) continue;
		float fdistance = Distance_2D(pNpc->CurrentPos, pEnemyTurret->CurrentPos);
		if (fdistance > nRange) continue;
		if (CheckName( (sz__Turret), pEnemyTurret->GetNameNpc()) == false) continue;
		//if (!IsCanSee(pEnemyMinion)) continue;
		jCount += 1;
	}
	return jCount;	
}
//==================================================================================//
//==================================================================================//
//==================================================================================//
int Count_AllyPlayer_Around_NPC(KNpc* pNpc, float nRange)
{
	int jCount = 0;

	if(!G_Module) return 0;
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + G_Module;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + G_Module;

	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return 0;

	int nCount = (dw2 - dw1)/4;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *allyPlayer = (KNpc*)dw3;
		if(allyPlayer->IsEnemy(pPlayer->nTeam_ID))   continue;	
		if(allyPlayer == pNpc)    continue;
		if(allyPlayer == pPlayer) continue;
		if(!IsValidTarget(allyPlayer, 20000, false)) continue;
		
		jCount += 1;
	}
	return jCount;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int Count_AllyMinion_Around_NPC(KNpc* pNpc, float nRange)
{
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return 0;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pAllyMinion = (KNpc*)dw3;
		int isDie = (BYTE)pAllyMinion->nIsDie;
		if (pAllyMinion->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pAllyMinion->nHP <= 0. || !pAllyMinion->IsMinion())
			continue;
		if(pNpc == pAllyMinion) continue;
		if ((BYTE)pAllyMinion->nIsTargetableToTeam != 4) continue;
		if (CheckName( (sz__Minion), pAllyMinion->GetNameNpc()) == false) continue;
		float fdistance = Distance_2D(pNpc->CurrentPos, pAllyMinion->CurrentPos);
		if (fdistance > nRange) continue;
		//if (!IsCanSee(pEnemyMinion)) continue;
		jCount += 1;
	}
	return jCount;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//

KNpc* GET_VISION_WARD(float nRange, bool isMat_Tim)
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return 0;
	
	bool nCoMatTim = false;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pVisionWard = (KNpc*)dw3;
		int isDie = (BYTE)pVisionWard->nIsDie;
		if (pVisionWard->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pVisionWard->nHP == 0.0)
			continue;
		if ((BYTE)pVisionWard->nIsTargetableToTeam != 4) continue;
		float fdistance = Distance_2D(pPlayer->CurrentPos, pVisionWard->CurrentPos);
		if (fdistance > nRange) continue;
		
		if (pVisionWard->nMaxMP - pVisionWard->nMP >= 2.0) continue;
		if (CheckName( (sz__YellowTrinket), pVisionWard->GetNameHero()))		  // mat vang bthuong
		{
			float TIMEGAME = GetTimeGame();
			if (TIMEGAME < 0) continue;

			KSkill*   pSkill_0= (KSkill*) pVisionWard->_pSkill[0];
			if(!pSkill_0) continue;
			float nTimeCoolDown = pSkill_0->nCooldownExpires;
			if(TIMEGAME - nTimeCoolDown >= 1.5) continue;

			 return pVisionWard;
		}
		if (CheckName( (sz__SightWard), pVisionWard->GetNameHero()))			 // mat thuong
		{
			float TIMEGAME = GetTimeGame();
			if (TIMEGAME < 0.) continue;

			KSkill*   pSkill_0= (KSkill*) pVisionWard->_pSkill[0];
			if(!pSkill_0) continue;
			float nTimeCoolDown = pSkill_0->nCooldownExpires;
			if(TIMEGAME - nTimeCoolDown >= 1.5) continue;
			return pVisionWard;
		}

		if(isMat_Tim && CheckName( (sz__JammerDevice), pVisionWard->GetNameHero()))			  // mat tim
		{
			float TIMEGAME = GetTimeGame();
			if (TIMEGAME < 0.) continue;

			KSkill*   pSkill_0= (KSkill*) pVisionWard->_pSkill[0];
			if(!pSkill_0) continue;
			float nTimeCoolDown = pSkill_0->nCooldownExpires;
			if(TIMEGAME - nTimeCoolDown >= 1.5) continue;
			return pVisionWard;
		}
	}
	return NULL;
}

//==================================================================================//
KNpc* SearchNearestAllyTurret(float nRange)
{
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return 0;

	KEnemyDistance pTru[20];
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return 0;

	DWORD nTempBASE_AttackableUnit     = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_Max = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_Max;
	if(!dw1 || !dw2 ) return 0;

	int nCount = (dw2 - dw1)/4;
	for(int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if(dw3 == 0) continue;
		KNpc *pTurret = (KNpc*)dw3;
		
		if(!pTurret->IsTurret() || pTurret->IsEnemy(pPlayer->nTeam_ID)) continue;
		if(!IsValidTarget(pTurret, nRange, false)) continue;
		pTru[jCount].pEnemy = pTurret;
		pTru[jCount].fDistance = Distance_2D(pPlayer->CurrentPos, pTurret->CurrentPos);
		jCount += 1;
	}

	// tim tru gan nhat
	float fMin = 100000;
	int nIndex = -1;
	for (int i = 0; i < jCount; ++i)
	{
		if(pTru[i].pEnemy == 0) continue;
		if (fMin > pTru[i].fDistance)
		{
			fMin = pTru[i].fDistance;
			nIndex = i;
		}
	}
	if (nIndex == -1) return 0;
	else			  return pTru[nIndex].pEnemy;
}

//==================================================================================//
KNpc* SearchNearestAllyPlayer(float nRange)
{
	KEnemyDistance AllyPlayers[10];
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	DWORD nTempBASE_HERO     = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return 0;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pAllyPlayer = (KNpc*)dw3;
		int isDie = (BYTE)pAllyPlayer->nIsDie;
		if (pAllyPlayer->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pAllyPlayer->nHP <= 0 || !pAllyPlayer->IsChampion())
			continue;
		if(pPlayer == pAllyPlayer) continue;
		if ((BYTE)pAllyPlayer->nIsTargetableToTeam != 4) continue;
		float fdistance = Distance_2D(pPlayer->CurrentPos, pAllyPlayer->CurrentPos);
		if (fdistance > nRange) continue;
		if (GET_BUFF_DACBIET(pAllyPlayer)) continue;

		AllyPlayers[jCount].pEnemy = pAllyPlayer;
		AllyPlayers[jCount].fDistance = fdistance;
		jCount += 1;
	}

	// tim tuong gan nhat
	float fMin = 100000;
	int nIndex = -1;
	for (int i = 0; i < jCount; ++i)
	{
		if(AllyPlayers[i].pEnemy == 0) continue;
		if (fMin > AllyPlayers[i].fDistance)
		{
			fMin = AllyPlayers[i].fDistance;
			nIndex = i;
		}
	}
	if (nIndex == -1) return 0;
	else              return AllyPlayers[nIndex].pEnemy;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KNpc* SearchFarestAllyPlayer(float nRange)
{
	KEnemyDistance AllyPlayers[10];
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return 0;	

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pAllyPlayer = (KNpc*)dw3;
		int isDie = (BYTE)pAllyPlayer->nIsDie;
		if (pAllyPlayer->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pAllyPlayer->nHP <= 0. || !pAllyPlayer->IsChampion())
			continue;
		if(pPlayer == pAllyPlayer) continue;
		if ((BYTE)pAllyPlayer->nIsTargetableToTeam != 4) continue;
		float fdistance = Distance_2D(pPlayer->CurrentPos, pAllyPlayer->CurrentPos);
		if (fdistance > nRange) continue;
		if (GET_BUFF_DACBIET(pAllyPlayer)) continue;

		AllyPlayers[jCount].pEnemy = pAllyPlayer;
		AllyPlayers[jCount].fDistance = fdistance;
		jCount += 1;
	}

	// tim tuong xa nhat
	float fMax = 0;
	int nIndex = -1;
	for (int i = 0; i < jCount; ++i)
	{
		if (fMax < AllyPlayers[i].fDistance)
		{
			fMax = AllyPlayers[i].fDistance;
			nIndex = i;
		}
	}
	if (nIndex == -1)
	{
		return NULL;
	} 
	else
	{
		return AllyPlayers[nIndex].pEnemy;
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KNpc* SearchNearestNPC(float nRange)
{
	KEnemyDistance enemyPlayers[10];
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return 0;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyPlayer = (KNpc*)dw3;
		int isDie = (BYTE)pEnemyPlayer->nIsDie;
		if (!pEnemyPlayer->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pEnemyPlayer->nHP <= 0. || !pEnemyPlayer->IsChampion())
			continue;
		if ((BYTE)pEnemyPlayer->nIsTargetableToTeam != 4) continue;
		float fdistance = Distance_2D(pPlayer->CurrentPos, pEnemyPlayer->CurrentPos);
		if (fdistance > nRange) continue;
		if (GET_BUFF_DACBIET(pEnemyPlayer)) continue;
		if (!IsCanSee(pEnemyPlayer)) continue;
		
		enemyPlayers[jCount].pEnemy = pEnemyPlayer;
		enemyPlayers[jCount].fDistance = fdistance;
		jCount += 1;
	}

	// tim tuong gan nhat
	float fMin = nRange;
	int nIndex = -1;
	for (int i = 0; i < jCount; ++i)
	{
		if (fMin > enemyPlayers[i].fDistance)
		{
			fMin = enemyPlayers[i].fDistance;
			nIndex = i;
		}
	}
	if (nIndex == -1)
	{
		return NULL;
	} 
	else
	{
		return enemyPlayers[nIndex].pEnemy;
	}
}

//==================================================================================//
//==================================================================================//
KNpc* SearchEnemyMinHP(float nRange)
{
	KEnemyDistance enemyPlayers[10];
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return 0;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyPlayer = (KNpc*)dw3;
		int isDie = (BYTE)pEnemyPlayer->nIsDie;
		if (!pEnemyPlayer->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pEnemyPlayer->nHP <= 0. || !pEnemyPlayer->IsChampion())
			continue;
		if ((BYTE)pEnemyPlayer->nIsTargetableToTeam != 4) continue;
		float fdistance = Distance_2D(pPlayer->CurrentPos, pEnemyPlayer->CurrentPos);
		if (fdistance > nRange) continue;
		if (GET_BUFF_DACBIET(pEnemyPlayer)) continue;
		if (!IsCanSee(pEnemyPlayer)) continue;
		
		enemyPlayers[jCount].pEnemy = pEnemyPlayer;
		enemyPlayers[jCount].nHP = pEnemyPlayer->nHP;
		jCount += 1;
	}

	// tim tuong it mau nhat
	float nMinHP = 100000;
	int nIndex = -1;
	for (int i = 0; i < jCount; ++i)
	{
		if (nMinHP > enemyPlayers[i].nHP)
		{
			nMinHP = enemyPlayers[i].nHP;
			nIndex = i;
		}
	}
	if (nIndex == -1)
	{
		return NULL;
	} 
	else
	{
		return enemyPlayers[nIndex].pEnemy;
	}
}

//==================================================================================//
//==================================================================================//
KNpc* SearchNearestNPC_Minion(float nRange)
{
	KEnemyDistance enemyPlayers[100];
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	//DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return 0;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyMinion = (KNpc*)dw3;
		int isDie = (BYTE)pEnemyMinion->nIsDie;
		if (!pEnemyMinion->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pEnemyMinion->nHP <= 0. || !pEnemyMinion->IsMinion())
			continue;
		if ((BYTE)pEnemyMinion->nIsTargetableToTeam != 4) continue;
		if (CheckName( (sz__Minion), pEnemyMinion->GetNameNpc()) == false) continue;
		float fdistance = Distance_2D(pPlayer->CurrentPos, pEnemyMinion->CurrentPos);
		if (fdistance > nRange) continue;
		enemyPlayers[jCount].pEnemy = pEnemyMinion;
		enemyPlayers[jCount].fDistance = fdistance;
		jCount += 1;
	}

	// tim tuong gan nhat
	float fMin = nRange;
	int nIndex = -1;
	for (int i = 0; i < jCount; ++i)
	{
		if (fMin > enemyPlayers[i].fDistance)
		{
			fMin = enemyPlayers[i].fDistance;
			nIndex = i;
		}
	}
	if (nIndex == -1)
	{
		return NULL;
	} 
	else
	{
		return enemyPlayers[nIndex].pEnemy;
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KNpc* SearchFarestNPC_Minion(float nRange)
{
	KEnemyDistance enemyPlayers[100];
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	//DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return 0;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyMinion = (KNpc*)dw3;
		int isDie = (BYTE)pEnemyMinion->nIsDie;
		if (!pEnemyMinion->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pEnemyMinion->nHP <= 0. || !pEnemyMinion->IsMinion())
			continue;
		if ((BYTE)pEnemyMinion->nIsTargetableToTeam != 4) continue;
		if (CheckName( (sz__Minion), pEnemyMinion->GetNameNpc()) == false) continue;
		float fdistance = Distance_2D(pPlayer->CurrentPos, pEnemyMinion->CurrentPos);
		if (fdistance > nRange) continue;
		enemyPlayers[jCount].pEnemy = pEnemyMinion;
		enemyPlayers[jCount].fDistance = fdistance;
		jCount += 1;
	}

	// tim tuong gan nhat
	float fMax = 0.0;
	int nIndex = -1;
	for (int i = 0; i < jCount; ++i)
	{
		if (fMax < enemyPlayers[i].fDistance)
		{
			fMax = enemyPlayers[i].fDistance;
			nIndex = i;
		}
	}
	if (nIndex == -1)
	{
		return NULL;
	} 
	else
	{
		return enemyPlayers[nIndex].pEnemy;
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KNpc* SearchFarestNPC_AllyMinion(float nRange)
{
	KEnemyDistance Ally_Minion[100];
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	//DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return 0;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyMinion = (KNpc*)dw3;
		int isDie = (BYTE)pEnemyMinion->nIsDie;
		if (pEnemyMinion->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pEnemyMinion->nHP <= 0. || !pEnemyMinion->IsMinion())
			continue;
		if ((BYTE)pEnemyMinion->nIsTargetableToTeam != 4) continue;
		if (CheckName( (sz__Minion), pEnemyMinion->GetNameNpc()) == false) continue;
		float fdistance = Distance_2D(pPlayer->CurrentPos, pEnemyMinion->CurrentPos);
		if (fdistance > nRange) continue;
		Ally_Minion[jCount].pEnemy = pEnemyMinion;
		Ally_Minion[jCount].fDistance = fdistance;
		jCount += 1;
	}

	// tim tuong gan nhat
	float fMax = 0.0;
	int nIndex = -1;
	for (int i = 0; i < jCount; ++i)
	{
		if (fMax < Ally_Minion[i].fDistance)
		{
			fMax = Ally_Minion[i].fDistance;
			nIndex = i;
		}
	}
	if (nIndex == -1)
	{
		return NULL;
	} 
	else
	{
		return Ally_Minion[nIndex].pEnemy;
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KNpc* SearchNPC2KillFastest(float nRange, bool nAA)
{
	
//--------------------

	KEnemyDistance enemyPlayers[10];
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return NULL;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyPlayer = (KNpc*)dw3;
		int isDie = (BYTE)pEnemyPlayer->nIsDie;
		if (!pEnemyPlayer->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pEnemyPlayer->nHP <= 0. || !pEnemyPlayer->IsChampion())
			continue;
		if ((BYTE)pEnemyPlayer->nIsTargetableToTeam != 4) continue;
		float fdistance = Distance_2D(pPlayer->CurrentPos, pEnemyPlayer->CurrentPos);
		if (pPlayer->nAttackRange < 300)
		{
			if(nAA == true) nRange = pPlayer->nAttackRange + pEnemyPlayer->nOverrideCollisionRadius + 10;
		}
		if (fdistance > nRange) continue;
		if (!IsCanSee(pEnemyPlayer)) continue;
		if (GET_BUFF_DACBIET(pEnemyPlayer)) continue;
		
		if (CheckName(  (sz__Zed), pPlayer->GetNameHero()))
		{
			if(GET_BUFF(pEnemyPlayer, (sz__zedrdeathmark)))  return pEnemyPlayer; // pEnemyPlayer bi khac DAU AN TU THAN cua ZED
		}
		if (CheckName(  (sz__Tristana), pPlayer->GetNameHero()))
		{
			if(GET_BUFF(pEnemyPlayer,  (sz__tristanaechargesound)))  return pEnemyPlayer; // pEnemyPlayer bi nem BOC THUOC SUNG cua TRISTANA
		}
		if (CheckName(  (sz__Caitlyn), pPlayer->GetNameHero()))
		{
			if(GET_BUFF(pEnemyPlayer, sz__caitlynyordletrapinternal))  return pEnemyPlayer; // pEnemyPlayer bi Troi Bay cua Caitlyn
		}
		if (CheckName(  (sz__Illaoi), pPlayer->GetNameHero()))
		{
			if(GET_BUFF(pEnemyPlayer,  (sz__illaoiespirit)))  return pEnemyPlayer; // pEnemyPlayer bi Thu Thach Linh Hon E cua ILLAOI
		}
		enemyPlayers[jCount].pEnemy = pEnemyPlayer;
		enemyPlayers[jCount].fDistance = fdistance;
		float nDmgReceive = GetDamageReceive(pPlayer, pEnemyPlayer);
		if (nDmgReceive == 0)
		{
			nDmgReceive = (float)0.001;
		}
		//__oMsg("nDmgReceive----->%f",nDmgReceive);
		enemyPlayers[jCount].nCount2BeKill = pEnemyPlayer->nHP / nDmgReceive; // so lan nhan sat thuong se chet
		jCount += 1;
	}

	// tim tuong co "so lan nhan sat thuong se chet" nho nhat
	float fCount2BeKill = 500;
	int nIndex = -1;
	for (int i = 0; i < jCount; ++i)
	{
		if (enemyPlayers[i].fDistance > nRange)
		{
			continue;
		}
		if (fCount2BeKill > enemyPlayers[i].nCount2BeKill)
		{
			fCount2BeKill = enemyPlayers[i].nCount2BeKill;
			nIndex = i;
		}
	}
	if (nIndex == -1)
	{
		return NULL;
	} 
	else
	{
		return enemyPlayers[nIndex].pEnemy;
	}
}

//==================================================================================//
//==================================================================================//
KNpc* SearchEnemyNPC_CC_AroundNPC(KNpc* pNpc, float nRange)
{
	KEnemyDistance enemyPlayers[10];
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;
	
	int nCount = (dw2 - dw1)/4;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *enemy = (KNpc*)dw3;
		if(!enemy->IsChampion())		 continue;
		if(!IsValidTarget(pNpc, nRange)) continue;
		
		if(GET_BUFF_SLOW(enemy) || GET_BUFF_DUNGIM(enemy))
		{
			enemyPlayers[jCount].pEnemy = enemy;
			enemyPlayers[jCount].fDistance = Distance_2D(pNpc->CurrentPos, enemy->CurrentPos);
			float nDmgReceive = GetDamageReceive(pNpc, enemy);
			if (nDmgReceive == 0)
			{
				nDmgReceive = (float)0.001;
			}
			enemyPlayers[jCount].nCount2BeKill = enemy->nHP / nDmgReceive; // so lan nhan sat thuong se chet
			jCount += 1;
		}
	}

	// tim tuong co "so lan nhan sat thuong se chet" nho nhat, va dinh' CC
	float fCount2BeKill = 500;
	int nIndex = -1;
	for (int i = 0; i < jCount; ++i)
	{
		if (enemyPlayers[i].fDistance > nRange)
		{
			continue;
		}
		if (fCount2BeKill > enemyPlayers[i].nCount2BeKill)
		{
			fCount2BeKill = enemyPlayers[i].nCount2BeKill;
			nIndex = i;
		}
	}
	if (nIndex == -1)
	{
		return NULL;
	} 
	else
	{
		return enemyPlayers[nIndex].pEnemy;
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KNpc* Search_EnemyMinion_Around_NPC(KNpc* pNpc, float nRange)
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return NULL;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyMinion = (KNpc*)dw3;
		int isDie = (BYTE)pEnemyMinion->nIsDie;
		if (!pEnemyMinion->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pEnemyMinion->nHP <= 0. || !pEnemyMinion->IsMinion())
			continue;
		if(pNpc == pEnemyMinion) continue;
		if ((BYTE)pEnemyMinion->nIsTargetableToTeam != 4) continue;
		if (CheckName( (sz__Minion), pEnemyMinion->GetNameNpc()) == false) continue;
		float fdistance = Distance_2D(pNpc->CurrentPos, pEnemyMinion->CurrentPos);
		if (fdistance > nRange) continue;
		//if (!IsCanSee(pEnemyMinion)) continue;
		return pEnemyMinion;
	}
	return NULL;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
float GetDamageReceive(KNpc* pPlayer, KNpc* pEnemy)
{
	if(!pPlayer || !pEnemy) return -1;

	float nDamageReceive = 0.0; // sat thuong nhan vao cua Enemy
	float nDamageReceive_AD = 0.0; // sat thuong vat ly nhan vao cua Enemy
	float nDamageReceive_AP = 0.0; // sat thuong phep nhan vao cua Enemy
	float nDmgOfPlayer = pPlayer->nFlat_PhysicalDamageMod + pPlayer->nBaseAttackDamage;
	//__oMsg("-----DAMEGE:%x,%f;%f", &pPlayer->nFlat_PhysicalDamageMod, nDamageReceive, nDmgOfPlayer);
	if (CheckName(pPlayer->GetNameHero(),  (sz__Kalista)))
	{
		nDmgOfPlayer = (float)0.9 * nDmgOfPlayer;
	}
	if (GET_ITEM(ITEM_CUNG_GO_ID))
	{
		nDmgOfPlayer += 15;
	}
	if (GET_ITEM(ITEM_CUONG_CUNG_ID))
	{
		nDmgOfPlayer += 15;
	}
	if (GET_ITEM(ITEM_GUOM_VO_DANH_ID))
	{
		float nDamage = (float)0.06 * pEnemy->nHP;
		if (nDamage > 60 && !pEnemy->IsChampion())
		{
			nDamage = 60;
		}
		nDmgOfPlayer += nDamage;
	}
	if (GET_ITEM(ITEM_NANH_NASHOR_ID))
	{
		float nDamage = 15 + (float)0.15*(pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod);
		nDmgOfPlayer += nDamage;
	}
	if (GET_BUFF(pPlayer,  (sz__sheen)) || GET_BUFF(pPlayer,  (sz__itemfrozenfist)) || GET_BUFF(pPlayer,  (sz__lichbane)))
	{// sheen: thuy kiem-tam hop kiem ; 	itemfrozenfist: gang tay bang gia;	lichbane: song kiem tai uong
		nDmgOfPlayer += pPlayer->nBaseAttackDamage;
	}
	
//-- DRAVEN ------
	if (GET_BUFF(pPlayer, "DravenSpinningAttack"))// draven dang co riu xoay
	{
		KSkill* pQ = (KSkill*)pPlayer->_pSkill[_Q]; //BONUS PHYSICAL DAMAGE: 35/40/45/50/55 (+65/75/85/95/105% bonus AD)
		if(pQ && (BYTE)pQ->nLevel !=0)
		{
			float dmg        = 30.0f + (BYTE)pQ->nLevel*5.0f;
			float perBonusAD = (55.0f + (BYTE)pQ->nLevel*10.0f)/100;
			nDmgOfPlayer += dmg + perBonusAD*pPlayer->nFlat_PhysicalDamageMod; // stvl cong them
		}
	}

////-- MISS-FORTUNE ------
//	if (pEnemy->IsMinion() && CheckName(pPlayer->GetNameHero(), sz__MissFortune))// MissFortune-tinh voi linh thoi
//	{
//		extern int MissFLastAtkId;
//		if(pEnemy->nIndex != MissFLastAtkId)
//		{
//			float perAD[19] = {0, 0.5f, 0.5f, 0.5f, 0.6f, 0.6f, 0.6f, 0.7f, 0.7f, 0.8f, 0.8f, 0.9f, 0.9f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
//			int level  = (BYTE)pPlayer->nLevel > 18 ? 18 : (BYTE)pPlayer->nLevel;
//
//			float bonus = (pPlayer->nFlat_PhysicalDamageMod + pPlayer->nBaseAttackDamage)*perAD[level];
//			//if(pEnemy->IsMinion()) bonus = bonus/2;
//
//			nDmgOfPlayer += bonus/2;
//		}
//	}

//-- PANTHEON ------
	if (GET_BUFF(pPlayer,  (sz__PantheonEPassive)))
	{// PantheonEPassive: noi tai E cua Pantheon
		float nPercent = 100*pEnemy->nHP/pEnemy->nMaxHP;
		if (nPercent <= 15)
		{
			nDmgOfPlayer *= 2;
		}
	}
//-- ZED ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Zed)))
	{// noi tai cua Zed
		float nPercent = 100*pEnemy->nHP/pEnemy->nMaxHP;
		if (nPercent <= 50)
		{
			nDmgOfPlayer += (float)0.06*pEnemy->nMaxHP;
		}
	}
//-- RIVEN ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Riven)))
	{
		if(GET_BUFF(pPlayer,  (sz__rivenpassiveaaboost)))
		{
			nDmgOfPlayer += (float)0.25*nDmgOfPlayer;
		}
	}
//-- QUINN ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Quinn)))
	{
		if(GET_BUFF(pEnemy,  (sz__quinneroot)))
		{
			nDmgOfPlayer  += ((float)0.14 + (float)0.02*(BYTE)pPlayer->nLevel) *nDmgOfPlayer + (10 + 5*(BYTE)pPlayer->nLevel); 
		}
	}
//-- GRAVES ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Graves)))
	{
		if(pEnemy->IsMinion())
		{
			float nKC = Distance_2D(pPlayer->CurrentPos, pEnemy->CurrentPos);
			float nPercent_Dam = (float)0.69 + (float)0.01*(BYTE)pPlayer->nLevel;
			if(nKC > 450)		nDmgOfPlayer = nDmgOfPlayer*nPercent_Dam;
			else if(nKC > 300)	nDmgOfPlayer = nDmgOfPlayer*(nPercent_Dam + nPercent_Dam/3);
			else				nDmgOfPlayer = nDmgOfPlayer*(nPercent_Dam + 2*nPercent_Dam/3);
		}
	}
//-- ASHE ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Ashe)))
	{
		if(GET_BUFF(pEnemy,  (sz__ashepassiveslow)))
		{
			nDmgOfPlayer = nDmgOfPlayer*((float)1.1 + pPlayer->nCritChance);
		}
	}
//-- CAITLYN ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Caitlyn)))
	{
		if(GET_BUFF(pPlayer,  (sz__caitlynheadshot)))
		{
			nDmgOfPlayer += (float)1.5*nDmgOfPlayer;
		}
	}
//-- LUCIAN ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Lucian)))
	{
		if(GET_BUFF(pPlayer,  (sz__LucianPassiveBuff)))
		{
			if(pEnemy->IsMinion())	nDmgOfPlayer += nDmgOfPlayer; // ban 2 lan, chi tinh linh, tuong thi tinh theo cong thuc khac(ko can thiet phai tinh)
		}
	}
//-- SWAIN ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Swain)))
	{
		if(GET_BUFF(pEnemy,  (sz__SwainTorment)))
		{
			nDmgOfPlayer += (float)0.2*nDmgOfPlayer; 
		}
	}
//-- JARVAN4 ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__JarvanIV)))
	{
		if(!GET_BUFF(pEnemy,  (sz__jarvanivmartialcadencecheck)))
		{

			nDmgOfPlayer += (float)0.08*pEnemy->nHP; 
		}
	}
//-- JHIN ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Jhin)))
	{
		float nPercent_HP_Missed		= 0;
		if ((BYTE)pPlayer->nLevel < 6)
		{
			nPercent_HP_Missed			= (float)0.15;
		}
		else if ((BYTE)pPlayer->nLevel < 11)
		{
			nPercent_HP_Missed			= (float)0.2;
		}
		else if ((BYTE)pPlayer->nLevel <= 18)
		{
			nPercent_HP_Missed			= (float)0.25;
		}
		if(GET_BUFF(pPlayer,  (sz__jhinpassiveattackbuff)))
		{
			//__oMsg("co_buff_phat_ban_thu_4;%f", nPercent_HP_Missed);
			nDmgOfPlayer += (float)0.56*nDmgOfPlayer + nPercent_HP_Missed*(pEnemy->nMaxHP - pEnemy->nHP); 
		}
		float nPercentBonusAD			= 0;
		nPercentBonusAD = (BYTE)pPlayer->nLevel <= 11 ? (float)0.01*((BYTE)pPlayer->nLevel + 1) : ((float)0.12 + (float)0.04*((BYTE)pPlayer->nLevel - 11));
		nPercentBonusAD += (float)0.04*pPlayer->nCritChance/(float)0.1 + (float)0.025*(pPlayer->nAttackSpeedMod - 1)/(float)0.1;
		nDmgOfPlayer += (pPlayer->nFlat_PhysicalDamageMod + pPlayer->nBaseAttackDamage)*nPercentBonusAD;
	}
//-- NASUS ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Nasus)))
	{
		if(GET_BUFF(pPlayer,  (sz__NasusQ)) || CanCastSpell2(SKILL_Q) == 8 || CanCastSpell2(SKILL_Q) == 0)
		{
			KSkill*   pSkillQ = (KSkill*) pPlayer->_pSkill[SKILL_Q];
			if(pSkillQ)
			{
				if(pSkillQ->nLevel != 0)
				{
					nDmgOfPlayer  += 10 + 20*pSkillQ->nLevel + pSkillQ->nAdd_Dmg; //BONUS PHYSICAL DAMAGE: 30 / 50 / 70 / 90 / 110 (+ Siphoning Strike stacks)
				}
			}
		}
	}
//-- VAYNE ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Vayne)))
	{
		if(GET_BUFF(pPlayer,  (sz__vaynetumblebonus)))
		{
			KSkill*   pSkillQ = (KSkill*) pPlayer->_pSkill[SKILL_Q];
			if(pSkillQ)
			{
				if((BYTE)pSkillQ->nLevel != 0)
				{
					nDmgOfPlayer  += ((float)0.45 + (float)0.05*(BYTE)pSkillQ->nLevel)*nDmgOfPlayer; //50/55/60/65/70% AD
				}
			}
		}
	}
//-- CAMILLE ------ 
	if (CheckName(pPlayer->GetNameHero(),  (sz__Camille)))
	{
		KSkill*   pSkillQ= (KSkill*) pPlayer->_pSkill[SKILL_Q]; //BONUS PHYSICAL DAMAGE: 20 / 25 / 30 / 35 / 40% AD.
		if(pSkillQ)
		{
			KSkill_2*  pKSkill_Q = (KSkill_2*) pSkillQ->__pK_str2;
			if(pKSkill_Q)
			{
				if(CheckName( (sz__CamilleQ2), pKSkill_Q->GetSkillName()) == false) // Q-ghe
				{
					if(GET_BUFF(pPlayer,  (sz__CamilleQ)) || CanCastSpell2(SKILL_Q) == 8 || CanCastSpell2(SKILL_Q) == 0)
					{
						if(pSkillQ->nLevel != 0)
						{
							nDmgOfPlayer  += ((float)0.15 + (float)0.05*pSkillQ->nLevel)*nDmgOfPlayer;
						}
					}
				}
				else														   // Q2-xin
				{
					if(GET_BUFF(pPlayer,  (sz__camilleqprimingcomplete)))
					{
						if(pSkillQ->nLevel != 0)
						{
							nDmgOfPlayer  += 2*((float)0.15 + (float)0.05*pSkillQ->nLevel)*nDmgOfPlayer;
						}
					}
				}
			}
		}
	}
//-- MALPHITE ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Malphite)) && GET_BUFF(pPlayer,  (sz__MalphiteCleave)))
	{//BONUS PHYSICAL DAMAGE: 15 / 30 / 45 / 60 / 75 (+ 10% AP) (+ 15% armor)
		KSkill*   pSkillW = (KSkill*) pPlayer->_pSkill[SKILL_W];
		if(pSkillW && pSkillW->nLevel != 0)
		{
			nDmgOfPlayer  += 15*pSkillW->nLevel + (float)0.1*(pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod) + (float)0.15*pPlayer->nArmor;
		}
	}
//-- MASTER YI ------
	if ( CheckName(pPlayer->GetNameHero(),  (sz__MasterYi)) && GET_BUFF(pPlayer,  (sz__wujustylevisual)) )
	{// 10% AD as bonus attack damage
		nDmgOfPlayer += (float)0.1*nDmgOfPlayer;
	}

	float pEnemy_nArmor = pEnemy->nArmor;
	if (GET_ITEM(ITEM_NO_THAN_ID) || GET_ITEM(ITEM_LOINHACTUVONG_ID))
	{
		pEnemy_nArmor = pEnemy_nArmor - pEnemy->nArmor_CongThem*PERCENT_XUYENGIAP_NOTHAN/100;
	}
	float nXuyenGiap = SATLUC_XUYENTHANG*pPlayer->nXyenGiap_Diem/100 + (1 - SATLUC_XUYENTHANG/100)*pPlayer->nXyenGiap_Diem*(BYTE)pEnemy->nLevel/18;

	if(!pEnemy->IsChampion()) nXuyenGiap = 0;
	pEnemy_nArmor = pEnemy_nArmor - nXuyenGiap;
	if (pEnemy_nArmor >= 0)
	{
		nDamageReceive_AD = nDmgOfPlayer * (100/(100 + pEnemy_nArmor));
	}
	else
	{
		nDamageReceive_AD = nDmgOfPlayer * (2-100/(100 - pEnemy_nArmor));
	}

//========================= TINH DAMAGE AP =============================================
	if (CheckName(pPlayer->GetNameHero(),  (sz__TwistedFate)))
	{
		if(GET_BUFF(pPlayer,  (sz__cardmasterstackparticle)))
		{
			nDamageReceive_AP += 55 + (float)0.5*(pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod); // dame nay tinh theo dame phep, co tang theo cap...
			if (pEnemy->nSpellBlock >= 0)
			{
				nDamageReceive_AP = nDamageReceive_AP * (100/(100 + pEnemy->nSpellBlock));
			}
			else
			{
				nDamageReceive_AP = nDamageReceive_AP * (2-100/(100 - pEnemy->nSpellBlock));
			}
		}
	}
//-- VIKTOR ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Viktor)))
	{
		if(GET_BUFF(pPlayer,  (sz__ViktorPowerTransferReturn)))
		{
			KSkill*   pSkillQ = (KSkill*) pPlayer->_pSkill[SKILL_Q];
			if(pSkillQ)
			{
				if(pSkillQ->nLevel != 0)
				{
					nDamageReceive_AP += pSkillQ->nLevel*20 + (float)0.5*(pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod); // dame nay tinh theo dame phep, co tang theo cap...
					if (pEnemy->nSpellBlock >= 0)
					{
						nDamageReceive_AP = nDamageReceive_AP * (100/(100 + pEnemy->nSpellBlock));
					}
					else
					{
						nDamageReceive_AP = nDamageReceive_AP * (2-100/(100 - pEnemy->nSpellBlock));
					}
				}
			}
		}
	}
//-- VARUS ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Varus)))
	{
		KSkill*   pSkillW = (KSkill*) pPlayer->_pSkill[SKILL_W];
		if(pSkillW)
		{
			if(pSkillW->nLevel != 0)
			{
				nDamageReceive_AP +=  1 + pSkillW->nLevel*4 + (float)0.25*(pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod); // dame nay tinh theo dame phep, co tang theo cap...
				if (pEnemy->nSpellBlock >= 0)
				{
					nDamageReceive_AP = nDamageReceive_AP * (100/(100 + pEnemy->nSpellBlock));
				}
				else
				{
					nDamageReceive_AP = nDamageReceive_AP * (2-100/(100 - pEnemy->nSpellBlock));
				}
			}
		}
	}
//-- LUX ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Lux)) && GET_BUFF(pEnemy,  (sz__LuxIlluminatingFraulein))) // enemy bi hieu ung anh sang cua Lux
	{// noi tai cua Lux - phan cong them nay tinh theo sat thuong phep ??
		if (pEnemy->nSpellBlock >= 0)
		{
			nDamageReceive_AP = nDamageReceive_AP + (10 + 10*(BYTE)pPlayer->nLevel + (float)0.2*(pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod)) * (100/(100 + pEnemy->nSpellBlock));
		}
		else
		{
			nDamageReceive_AP = nDamageReceive_AP + (10 + 10*(BYTE)pPlayer->nLevel + (float)0.2*(pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod)) * (2-100/(100 - pEnemy->nSpellBlock));
		}
	}
//-- TEEMO ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Teemo)))
	{
		KSkill*   pSkillE = (KSkill*) pPlayer->_pSkill[SKILL_E];
		if(pSkillE)
		{
			if(pSkillE->nLevel != 0)
			{// dame nay tinh theo dame phep, co tang theo cap...
				nDamageReceive_AP = pSkillE->nLevel*10 + (float)0.3*(pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod);
				if (pEnemy->nSpellBlock >= 0)
				{
					nDamageReceive_AP = nDamageReceive_AP * (100/(100 + pEnemy->nSpellBlock));
				}
				else
				{
					nDamageReceive_AP = nDamageReceive_AP * (2-100/(100 - pEnemy->nSpellBlock));
				}
			}
		}
	}
//-- KAYLE ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Kayle)))
	{
		KSkill*   pSkillE = (KSkill*) pPlayer->_pSkill[SKILL_E];
		if(pSkillE && pSkillE->nLevel != 0)
		{// dame nay tinh theo dame phep, co tang theo cap...BONUS MAGIC DAMAGE: 10 / 15 / 20 / 25 / 30 (+ 15% AP)
			nDamageReceive_AP = 5 + 5*pSkillE->nLevel + (float)0.15*(pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod);
			if (GET_BUFF(pPlayer,  (sz__JudicatorRighteousFury)))
			{// ENHANCED BONUS MAGIC DAMAGE: 20 / 30 / 40 / 50 / 60 (+ 30% AP)
				nDamageReceive_AP = 10 + 10*pSkillE->nLevel + (float)0.3*(pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod);
			}
			if (pEnemy->nSpellBlock >= 0)
			{
				nDamageReceive_AP = nDamageReceive_AP * (100/(100 + pEnemy->nSpellBlock));
			}
			else
			{
				nDamageReceive_AP = nDamageReceive_AP * (2-100/(100 - pEnemy->nSpellBlock));
			}
		}
	}
//-- KENNEN ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Kennen)) && GET_BUFF(pPlayer,  (sz__kennendoublestrikelive)))
	{//MAGIC DAMAGE: 40 / 50 / 60 / 70 / 80% AD
		KSkill*   pSkillE = (KSkill*) pPlayer->_pSkill[SKILL_W];
		if (pSkillE && 0 != pSkillE->nLevel)
		{
			float nAD = pPlayer->nFlat_PhysicalDamageMod + pPlayer->nBaseAttackDamage;
			nDamageReceive_AP	= nAD * ((float)0.3 + pSkillE->nLevel * (float)0.1) * (100/(100 + pEnemy->nSpellBlock));
			if(pEnemy->nSpellBlock < 0)
			{
				nDamageReceive_AP	= nAD * ((float)0.3 + pSkillE->nLevel * (float)0.1) * (2 - 100/(100 - pEnemy->nSpellBlock));
			}
		}
	}
//-- KHAZIX ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Khazix)) && pEnemy->IsChampion())
	{
		if(GET_BUFF(pPlayer,  (sz__KhazixPDamage)))
		{
			float nBonus_AD = pPlayer->nFlat_PhysicalDamageMod; // bonus AD
			nDamageReceive_AP += 6 + 8*(BYTE)pPlayer->nLevel + (float)0.2*nBonus_AD; // 6 + 8*nLevel + 20% bonus AD => thanh dame phep
			if (pEnemy->nSpellBlock >= 0)
			{
				nDamageReceive_AP = nDamageReceive_AP * (100/(100 + pEnemy->nSpellBlock));
			}
			else
			{
				nDamageReceive_AP = nDamageReceive_AP * (2-100/(100 - pEnemy->nSpellBlock));
			}
		}
	}
//-- JAX ------ 
	if (CheckName(pPlayer->GetNameHero(),  (sz__Jax)))
	{
		if(GET_BUFF(pPlayer,  (sz__JaxEmpowerTwo)) || CanCastSpell2(SKILL_W) == 8 || CanCastSpell2(SKILL_W) == 0)
		{
			KSkill*   pSkillW = (KSkill*) pPlayer->_pSkill[SKILL_W];
			if(pSkillW)
			{
				if(pSkillW->nLevel != 0)
				{
					nDamageReceive_AP  += 5 + 35*pSkillW->nLevel + (float)0.6*(pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod); //MAGIC DAMAGE: 40 / 75 / 110 / 145 / 180 (+ 60% AP))
					if (pEnemy->nSpellBlock >= 0)
					{
						nDamageReceive_AP = nDamageReceive_AP * (100/(100 + pEnemy->nSpellBlock));
					}
					else
					{
						nDamageReceive_AP = nDamageReceive_AP * (2-100/(100 - pEnemy->nSpellBlock));
					}
				}
			}
		}
	}
//-- ORIANNA ------ 
	if (CheckName(pPlayer->GetNameHero(),  (sz__Orianna)))
	{
		float nDame_NoiTai = 0;
		if		((BYTE)pPlayer->nLevel < 4)  nDame_NoiTai = 10;
		else if ((BYTE)pPlayer->nLevel < 7)  nDame_NoiTai = 18;
		else if ((BYTE)pPlayer->nLevel < 10) nDame_NoiTai = 26;
		else if ((BYTE)pPlayer->nLevel < 13) nDame_NoiTai = 34;
		else if ((BYTE)pPlayer->nLevel < 16) nDame_NoiTai = 42;
		else if ((BYTE)pPlayer->nLevel <= 18) nDame_NoiTai = 50;
		if (pEnemy->nSpellBlock >= 0)
		{
			nDamageReceive_AP = (nDamageReceive_AP + nDame_NoiTai + (float)0.15*(pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod)) * (100/(100 + pEnemy->nSpellBlock));
		}
		else
		{
			nDamageReceive_AP = (nDamageReceive_AP + nDame_NoiTai + (float)0.15*(pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod)) * (2-100/(100 - pEnemy->nSpellBlock));
		}
	}
//-- SONA ------ 
	if (CheckName(pPlayer->GetNameHero(),  (sz__Sona)) && GET_BUFF(pPlayer,  (sz__sonapassiveattack)))
	{
		nDamageReceive_AP = (BYTE)pPlayer->nLevel < 8 ? (5 + 10*(BYTE)pPlayer->nLevel) : (5 + 10*8 + 15*((BYTE)pPlayer->nLevel - 8)) + (float)0.2*(pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod);
		if (pEnemy->nSpellBlock >= 0)
		{
			nDamageReceive_AP = nDamageReceive_AP * (100/(100 + pEnemy->nSpellBlock));
		}
		else
		{
			nDamageReceive_AP = nDamageReceive_AP * (2-100/(100 - pEnemy->nSpellBlock));
		}
	}
//-- LULU ------ 
	if (CheckName(pPlayer->GetNameHero(),  (sz__Lulu)))
	{
		
	}
//-- ZIGGS ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Ziggs)))
	{
		if(GET_BUFF(pPlayer,  (sz__ZiggsShortFuse)))
		{
			float nSMPT = pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod; //  AP
			nDamageReceive_AP += 16 + 4*(BYTE)pPlayer->nLevel + (float)0.3*nSMPT; // 16 + 4*nLevel + 30% AP => thanh dame phep(lay min-dame-->chuan chuan lam)
			if (pEnemy->nSpellBlock >= 0)
			{
				nDamageReceive_AP = nDamageReceive_AP * (100/(100 + pEnemy->nSpellBlock));
			}
			else
			{
				nDamageReceive_AP = nDamageReceive_AP * (2-100/(100 - pEnemy->nSpellBlock));
			}
		}
	}
//-- DIANA ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Diana)))
	{
		
	}
//-- CHO"GATH ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Chogath)))
	{
		
	}
//============================
	nDamageReceive = nDamageReceive_AD + nDamageReceive_AP;

//-- VAYNE ------
	if (CheckName(pPlayer->GetNameHero(),  (sz__Vayne)))
	{
		KSkill*   pSkillW = (KSkill*) pPlayer->_pSkill[SKILL_W];
		float nPercent_HP = 0;
		float nDam_Min	  = 0;	
		if(pSkillW)
		{
			if(pSkillW->nLevel != 0)
			{
				nPercent_HP  = (float)(0.02 + 0.02*pSkillW->nLevel); 	//ST CHUAN: 4/6/8/10/12% of target's maximum health 
				nDam_Min	  = (float)(35 + 15*pSkillW->nLevel);		//ST	  : 50/65/80/95/110
			}
		}
		KBuffs* pBuff = GET_BUFF(pEnemy,  (sz__VayneSilveredDebuff));
		if(pBuff)
		{
			int nCount = (pBuff->nEnd_Count - pBuff->nStart_Count)/8;
			if(nCount >= 2)
			{
				float nDam_Chuan = pEnemy->nMaxHP*nPercent_HP;
				if(nDam_Chuan < nDam_Min) nDam_Chuan = nDam_Min;
				if(pEnemy->IsMinion() && nDam_Chuan > 200) nDam_Chuan = 200;
				nDamageReceive += nDam_Chuan;
			}
		}
	}
//-- MASTER YI ------
	if ( CheckName(pPlayer->GetNameHero(),  (sz__MasterYi)) && GET_BUFF(pPlayer,  (sz__wujustylesuperchargedvisual)) )
	{//TRUE DAMAGE: 14 / 23 / 32 / 41 / 50 (+ 25% bonus AD)
		KSkill*   pSkillE = (KSkill*) pPlayer->_pSkill[SKILL_E];
		float nST_Chuan = 0;
		if(pSkillE && pSkillE->nLevel != 0)
		{
			nST_Chuan  = 5 + 9*(BYTE)pSkillE->nLevel + (float)0.25*(pPlayer->nFlat_MagicDamageMod + pPlayer->nFlat_MagicDamageMod*pPlayer->nPercent_MagicDamageMod);
		}
		nDamageReceive += nST_Chuan;
	}
	//__oMsg("=========================== nDamage_Tay : %f", nDamageReceive);
	return nDamageReceive;
}

//==================================================================================//
KNpc* SearchNPC2KillFastest_AP(float nRange)
{
	
//--------------------

	KEnemyDistance enemyPlayers[10]; // 5 nguoi choi
	int jCount = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return 0;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyPlayer = (KNpc*)dw3;
		int isDie = (BYTE)pEnemyPlayer->nIsDie;
		if (!pEnemyPlayer->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pEnemyPlayer->nHP <= 0. || !pEnemyPlayer->IsChampion())
			continue;
		if ((BYTE)pEnemyPlayer->nIsTargetableToTeam != 4) continue;
		float fdistance = Distance_2D(pPlayer->CurrentPos, pEnemyPlayer->CurrentPos);
		if (fdistance > nRange) continue;
		if (!IsCanSee(pEnemyPlayer)) continue;
		if (GET_BUFF_DACBIET(pEnemyPlayer)) continue;
		
		/*if (CheckName(  (sz__Veigar), pPlayer->GetNameHero()))
		{
			if(GET_BUFF_DUNGIM(pEnemyPlayer))  return pEnemyPlayer;
		}*/

		enemyPlayers[jCount].pEnemy = pEnemyPlayer;
		enemyPlayers[jCount].fDistance = fdistance;
		float nDmgReceive = GetDamageReceive_AP(pPlayer, pEnemyPlayer);
		//__oMsg("nDmgReceive----->%f",nDmgReceive);
		enemyPlayers[jCount].nCount2BeKill = pEnemyPlayer->nHP / nDmgReceive; // so lan nhan sat thuong se chet
		jCount += 1;
	}

	// tim tuong co "so lan nhan sat thuong se chet" nho nhat
	float fCount2BeKill = 300;
	int nIndex = -1;
	for (int i = 0; i < jCount; ++i)
	{
		if (enemyPlayers[i].fDistance > nRange)
		{
			continue;
		}
		if (fCount2BeKill > enemyPlayers[i].nCount2BeKill)
		{
			fCount2BeKill = enemyPlayers[i].nCount2BeKill;
			nIndex = i;
		}
	}
	if (nIndex == -1)
	{
		return NULL;
	} 
	else
	{
		return enemyPlayers[nIndex].pEnemy;
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
float GetDamageReceive_AP(KNpc* pPlayer, KNpc* pEnemy)
{
	float nAP_Receive = 0.0; // sat thuong phep nhan vao cua Enemy
	float nDmgAP_OfPlayer = 250; // qui uoc de lay so lan (lay ty le chung)
	//__oMsg("-----DAMEGE:%x,%f;%f", &pPlayer->nFlat_PhysicalDamageMod, nDamageReceive, nDmgOfPlayer);
	if (pEnemy->nSpellBlock >= 0)
	{
		nAP_Receive = nDmgAP_OfPlayer * (100/(100 + pEnemy->nSpellBlock));
	}
	else
	{
		nAP_Receive = nDmgAP_OfPlayer * (2-100/(100 - pEnemy->nSpellBlock));
	}
	return nAP_Receive;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IsCanSee(KNpc *pEnemy)
{
	if(pEnemy && pEnemy->nIsTargetableToTeam == 4 && (pEnemy->IsNexus() || pEnemy->IsInhibitor())) return true;
	DWORD bCanSee = 0;
	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc = CAN_SEE_FUNC - TEMP_ENTRY_POINT + hModule;

	DWORD _ECX = (DWORD)pEnemy;
	if(!_ECX) return false;
	__asm{
		mov ecx,_ECX
			mov eax,nFunc
			call eax
			mov bCanSee,eax
	}
	return ((BYTE)bCanSee > 0 ? true : false);
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IS_ADC(KNpc *pNpc)
{
	bool nIs_ADC = false; 
	if(!pNpc) return nIs_ADC;
	if((BYTE)pNpc->nIsDie == 1) return nIs_ADC;
	if(CheckName(  (sz__Caitlyn), pNpc->GetNameHero()))		return true;
	if(CheckName(  (sz__Jinx), pNpc->GetNameHero()))			return true;
	if(CheckName(  (sz__Twitch), pNpc->GetNameHero()))			return true;
	if(CheckName(  (sz__Tristana), pNpc->GetNameHero()))		return true;
	if(CheckName(  (sz__Teemo), pNpc->GetNameHero()))			return true;
	if(CheckName(  (sz__Lucian), pNpc->GetNameHero()))			return true;
	if(CheckName(  (sz__Sivir), pNpc->GetNameHero()))			return true;
	//if(CheckName(  (sz__Kennen), pNpc->GetNameHero()))			return true;
	if(CheckName(  (sz__MissFortune), pNpc->GetNameHero()))	return true;
	if(CheckName(  (sz__Graves), pNpc->GetNameHero()))			return true;
	if(CheckName(  (sz__Ezreal), pNpc->GetNameHero()))			return true;
	if(CheckName(  (sz__Azir), pNpc->GetNameHero()))			return true;
	if(CheckName(  (sz__Ashe), pNpc->GetNameHero()))			return true;
	if(CheckName(  (sz__Kalista), pNpc->GetNameHero()))		return true;
	if(CheckName(  (sz__Vayne), pNpc->GetNameHero()))			return true;
	if(CheckName(  (sz__Jhin), pNpc->GetNameHero()))			return true;
	if(CheckName(  (sz__Varus), pNpc->GetNameHero()))			return true;
	if(CheckName(  (sz__KogMaw), pNpc->GetNameHero()))			return true;
	if(CheckName(  (sz__Corki), pNpc->GetNameHero()))			return true;
	if(CheckName(  (sz__Draven), pNpc->GetNameHero()))			return true;
	if(CheckName(  (sz__Quinn), pNpc->GetNameHero()))			return true;

	return nIs_ADC;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
extern float g_DelayNormalAttack;

extern bool nReset_DanhThuong;

//extern bool g_bMove2MousePos;
extern float g_tDelay;
//==================================================================================//
//==================================================================================//
//==================================================================================//
bool Can_NormalAttack()
{
	bool nCan_Attk = true;
	KNpc *pPlayer = GetPlayer();

	float TIMEGAME = GetTimeGame();
	//stNORMAL_ATTACK* _stNORMAL_ATTACK = (stNORMAL_ATTACK*)pPlayer->_pNormalAttack;
	//if (_stNORMAL_ATTACK == NULL) return false;
	float nTimeCoolDown = pPlayer->nCooldownExpiresBA;
	float nDelta = nTimeCoolDown - TIMEGAME;
	//__oMsg("----- nDelta : %f", nDelta);
	if(nDelta > 0 && nReset_DanhThuong == false)
	{
		return false;
	}
	return nCan_Attk;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KPos* GetMousePos()
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	DWORD nTempBASE_SKILL = BASE_SKILL - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_SKILL;
	if (!dw1) return NULL;
	DWORD dw2 = *(DWORD*)(dw1 + 0x14);
	if (!dw2) return NULL;
	DWORD dw3 = dw2 + 28;
	KPos *mousePos = (KPos*)dw3;
	return mousePos;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void SetMousePos(KPos *pos)
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return;
	DWORD nTempBASE_SKILL = BASE_SKILL - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_SKILL;
	if (!dw1) return;
	DWORD dw2 = *(DWORD*)(dw1 + 0x14);
	if (!dw2) return;
	DWORD dw3 = dw2 + 28;
	*(float*)dw3		= pos->x;
	*(float*)(dw3 + 4)  = pos->y;
	*(float*)(dw3 + 8)  = pos->z;
	//__oMsg("dw3: %x - %f", *(DWORD*)dw3, pos->x);
}
//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IsPlayingWithBot()
{
	return false; // bo tinh nang quang cao
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return NULL;
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	//DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return NULL;

	int nCount = (dw2 - dw1)/4;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pHero = (KNpc*)dw3;
		//__oMsg("%x,hero=%d",(DWORD)&pHero->nIsBot - dw3, (BYTE)pHero->nIsBot);
		if ((BYTE)pHero->nIsBot == 1) // khi bat tinh nang quang cao len thi can check offset cua bien nay
		{
			return true;
		}
	}
	return false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
//bool g_Exit = false;
bool IsGameReady()
{
	//__oMsg("IsGameReady-1");
	//float nTimeGame = GetTimeGame_Dubi();
	float nTimeGame = GetTimeGame();
	//__oMsg("Game time:%f", nTimeGame);
	if (nTimeGame <= 6.0) return false;
	if (g_Exit == true)
	{
		
		Retour_EndScene();
		Retour_OnCreateObj();
		
		return false;
	}
	//__oMsg("tra ve true");
	return true;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KNpc* GetPlayer()
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBase  = BASE - TEMP_ENTRY_POINT + hModule;
	DWORD dw 		= *(DWORD*)nTempBase;
	KNpc *pPlayer = (KNpc*)dw;
	if (pPlayer == 0)
		return NULL;
	return pPlayer;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
float Distance_3D(float x1, float y1, float z1, float x2, float y2, float z2)
{
	float distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2));
	return distance;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
float Distance_3D(KPos start, KPos end)
{
	float distance = Distance_3D(start.x, start.y, start.z, end.x, end.y, end.z);
	return distance;
}
//==================================================================================//
//==================================================================================//
//==================================================================================//
float Distance_2D(float x1, float y1, float x2, float y2)
{
	float distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	return distance;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
float Distance_2D(KPos start, KPos end)
{
	float distance = Distance_2D(start.x, start.z, end.x, end.z);
	return distance;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int NghiemHePTBacNhat(KPos &pos, float &a1,float b1,float &c1,float a2,float b2,float &c2)
{
	// a1.x + b1.y = c1
	// a2.x + b2.y = c2
	float _D  = a1*b2 - a2*b1;
	float _Dx = c1*b2 - c2*b1;
	float _Dz = a1*c2 - a2*c1;
	if(_D == 0) return 0;
	float abc = _Dx/_D;
	pos.x = _Dx/_D;
	pos.z = _Dz/_D;
	return 1;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool DodgeMissileLine(KPos* startPoint,KPos* endPoint, float radius, float range, KBuffer_Spell* pBufferSpell, float timeFlying, bool flag, fPtrRESET_DATA_SPELL fPtrRESET)
{
	//dZ*x - dX*z  = C1 = dZ*startPoint->x - dX*startPoint->z		(1)(d: duong thang di qua 2 diem startPoint & endPoint)
	//dX*x + dZ*z  = C2 = dX*player_x + dZ*player_z	(2)(vuong goc voi d, di qua vi tri cua nguoi choi)
	//dZ.x - dX.z  = C4   = dZ.dodge_x  - dX.dodge_z 	(4)(song song voi d + di qua diem dodge)
	//==>C4 = C1 - R*calc1
	//==>C4 = C1 + R*calc1
	if (pBufferSpell == NULL) return FALSE;
	//__oMsg("TRUOC timeFlying=%f;TImer=%f", timeFlying, pBufferSpell->nTimer);
	if (timeFlying <= pBufferSpell->nTimer)
	{
		//__oMsg("SAU timeFlying=%f;TImer=%f", timeFlying, pBufferSpell->nTimer);
		fPtrRESET(pBufferSpell->index);
		UnBlockMove();
		return FALSE;
	}
	
	KNpc *g_pPlayer = GetPlayer();
	KPos diemVuongGoc;
	GIAO_DIEM_VUONG_GOC(diemVuongGoc, *startPoint, *endPoint, g_pPlayer->CurrentPos);
	float nKhoangCach = Distance_2D(diemVuongGoc, g_pPlayer->CurrentPos);
	//__oMsg("=========khoang cach cu = %f", nKhoangCach);
	if(nKhoangCach >= radius + 160.)
	{
		//__oMsg("===xxx======UnBlockMove()");
		UnBlockMove();
	}

	//--- cho them doan nay : dang combo se ko ne nhung skill ko nguy hiem --------------------------------------
	if(g_bNormalAttackHero/* && pBufferSpell->nIsDangerous == false*/)
	{
		UnBlockMove();
		return FALSE;
	}

	if (IsNPCMissileInLine(g_pPlayer, startPoint, endPoint, radius, range, flag) == false)
	{
		return FALSE;
	}
	//float R = (radius + g_pPlayer->nOverrideCollisionRadius + 30.);
	float R = (radius + 180);
	//__oMsg("1------------------R = %f, Collision_Radius = %f", R, g_pPlayer->nOverrideCollisionRadius);
	float dX = endPoint->x - startPoint->x;
	float dZ = endPoint->z - startPoint->z;
	float player_x = g_pPlayer->CurrentPos.x;
	float player_z = g_pPlayer->CurrentPos.z;
	float C1       = dZ*startPoint->x - dX*startPoint->z;
	float C2	   = dX*player_x + dZ*player_z;
	
	float calc1    = sqrt(dZ*dZ + dX*dX);
	//-----------------------------------
	KPos tmpPos0, tmpstartPoint, tmpendPoint;
	int Nghiem_0 	= NghiemHePTBacNhat(tmpPos0,dZ, -dX, C1, dX, dZ, C2); // giao diem cua (1) va (2)
	if (!Nghiem_0) 	return FALSE;
	float x_0 	= 	tmpPos0.x;
	float z_0 	= 	tmpPos0.z;
	//-----------------------------------
	float C4_1 = dZ*x_0 - dX*z_0 - R*calc1;
	float C4_2 = dZ*x_0 - dX*z_0 + R*calc1; 
	
	int  Nghiem1 	= NghiemHePTBacNhat(tmpstartPoint,dZ, -dX, C4_1, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem1) 	return FALSE;
	float dodge1_x 	= tmpstartPoint.x;
	float dodge1_z 	= tmpstartPoint.z;
	//-----------------------------------
	int  Nghiem2 	= NghiemHePTBacNhat(tmpendPoint,dZ, -dX, C4_2, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem2) 	return FALSE;
	float dodge2_x 	= tmpendPoint.x;
	float dodge2_z 	= tmpendPoint.z;
	//-----------------------------------
	float kc1 = sqrt((player_x - dodge1_x)*(player_x - dodge1_x) + (player_z - dodge1_z)*(player_z - dodge1_z));
	float kc2 = sqrt((player_x - dodge2_x)*(player_x - dodge2_x) + (player_z - dodge2_z)*(player_z - dodge2_z));
	
	
	float dodge_x,dodge_z;

	if (kc1 < kc2){
		dodge_x = dodge1_x;
		dodge_z = dodge1_z;
	}
	else {
		dodge_x = dodge2_x;
		dodge_z = dodge2_z;
	}
	//----------------------------
	BlockMove();
	MOVE_TO(dodge_x,dodge_z);
	return TRUE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool WINAPI DodgeMissileLine_45do(KPos* pos1,KPos* pos2, float radius, float maxDist, KBuffer_Spell* pBufferSpell, float timeFlying, bool flag, fPtrRESET_DATA_SPELL fPtrRESET)
{
 //dZ.x - dX.z  = C1 = dZ*pos1.x - dX*pos1.z		(1)(d)
 //dX.x + dZ.z  = C2 = dX*player_x + dZ*player_z	(2)(vuong goc voi d, di qua player)
 //dZ.x - dX.z  = C3 = dZ.player_x - dX.player_z	(3)(song song voi d + di qua player)
 //dZ.x - dX.z  = C5   = dZ.dodge_x  - dX.dodge_z 	(4)(song song voi d + di qua dodge)
 //==>C4 = dZ.x_0 - dX.y_0 - R*calc1
 //==>C4 = dZ.x_0 - dX.y_0 + R*calc1
 //PG cua (2) va (3) : ------------------------------------------------------------------------------
 //dX.x + dZ.z  - C2 = dZ.x - dX.z  - C3		=> (dX-dZ).x + (dZ+dX).z = C2-C3 	(PG1)
 //dX.x + dZ.z  - C2 = -(dZ.x - dX.z  - C3)		=> (dX+dZ).x + (dZ-dX).z = C2+C3	(PG2)
 //--------------------------------------------------------------------------------------------------
	if (pBufferSpell == NULL) return false;
	float fDistance = Distance_2D(pos1->x, pos1->z, pos2->x, pos2->z);
	//__oMsg("TRUOC khoang cach skill line= %f;timeFlying=%f;TImer=%f", fDistance, timeFlying, pBufferSpell->nTimer);
	if (timeFlying <= pBufferSpell->nTimer)
	{
		//__oMsg("SAU khoang cach skill line= %f;timeFlying=%f;TImer=%f", fDistance, timeFlying, pBufferSpell->nTimer);
		UnBlockMove();
		fPtrRESET(pBufferSpell->index);
		return false;
	}
	
	KNpc *g_pPlayer = GetPlayer();
	KPos diemVuongGoc;
	GIAO_DIEM_VUONG_GOC(diemVuongGoc, *pos1, *pos2, g_pPlayer->CurrentPos);
	float nKhoangCach = Distance_2D(diemVuongGoc, g_pPlayer->CurrentPos);
	//__oMsg("=========khoang cach cu = %f", nKhoangCach);
	if(nKhoangCach >= radius + g_pPlayer->nOverrideCollisionRadius)
	{
		//__oMsg("=========UnBlockMove()");
		UnBlockMove();
	}

	//--- cho them doan nay : dang combo se ko ne nhung skill ko nguy hiem --------------------------------------
	if(g_bNormalAttackHero/* && pBufferSpell->nIsDangerous == false*/)
	{
		UnBlockMove();
		return false;
	}

	if (IsNPCMissileInLine(g_pPlayer, pos1, pos2, radius, maxDist, flag) == false)
	{
		return false;
	}
//--- moi them ---------------------------------------
	countBiDanhBoiSkillDinhHuong = 1;
	KBuffs* pBuffBlackShield = GET_BUFF(g_pPlayer, "BlackShield");
	if(pBuffBlackShield && pBuffBlackShield->nEnd_Time - GetTimeGame() > 0.3) return false;
	
	KBuffs* pBuffSivirE = GET_BUFF(g_pPlayer, "SivirE");

	

	if(pBuffSivirE && pBuffBlackShield->nEnd_Time - GetTimeGame() > 0.3) return false;

	float R = (radius + g_pPlayer->nOverrideCollisionRadius + 30);
	////__oMsg("1------------------R = %f, Collision_Radius = %f", R, g_pPlayer->nOverrideCollisionRadius);

	float dX = pos2->x - pos1->x;
	float dZ = pos2->z - pos1->z;
	float player_x = g_pPlayer->CurrentPos.x;
	float player_z = g_pPlayer->CurrentPos.z;
	float C1       = dZ*pos1->x - dX*pos1->z;
	float C2     	= dX*player_x + dZ*player_z;
	float C3	   	= dZ*player_x - dX*player_z;
	float C5;
	float PG_1 = C2-C3;
	float PG_2 = C2+C3;

	float calc1    = sqrt(dZ*dZ + dX*dX);
	//-----------------------------------
	KPos tmpPos0, tmpPos1, tmpPos2;
	int Nghiem_0  = NghiemHePTBacNhat(tmpPos0,dZ, -dX, C1, dX, dZ, C2); // giao diem cua (1) va (2)
	if (!Nghiem_0)  return false;
	float x_0  =  tmpPos0.x;
	float z_0  =  tmpPos0.z;
	//-----------------------------------
	float C4_1 = dZ*x_0 - dX*z_0 - R*calc1;
	float C4_2 = dZ*x_0 - dX*z_0 + R*calc1; 

	int  Nghiem1  = NghiemHePTBacNhat(tmpPos1,dZ, -dX, C4_1, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem1)  return false;
	float dodge1_x  = tmpPos1.x;
	float dodge1_z  = tmpPos1.z;
	//-----------------------------------
	int  Nghiem2  = NghiemHePTBacNhat(tmpPos2,dZ, -dX, C4_2, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem2)  return false;
	float dodge2_x  = tmpPos2.x;
	float dodge2_z  = tmpPos2.z;
	//-----------------------------------
	float kc1 = sqrt((player_x - dodge1_x)*(player_x - dodge1_x) + (player_z - dodge1_z)*(player_z - dodge1_z));
	float kc2 = sqrt((player_x - dodge2_x)*(player_x - dodge2_x) + (player_z - dodge2_z)*(player_z - dodge2_z));

	float dodge_x,dodge_z;
	if (kc1 < kc2){
	dodge_x = dodge1_x;
	dodge_z = dodge1_z;
	}
	else {
	dodge_x = dodge2_x;
	dodge_z = dodge2_z;
	}
	//----------------------------
	C5       = dZ*dodge_x  - dX*dodge_z; 
	int  rc1 = NghiemHePTBacNhat(tmpPos1,dZ, -dX, C5, (dX-dZ), (dZ+dX), PG_1); // giao diem cua (4) va (PG1)
	if (!rc1)	return false;

	float evade1_x = tmpPos1.x;
	float evade1_z = tmpPos1.z;

	int rc2 = NghiemHePTBacNhat(tmpPos2,dZ, -dX, C5, (dX+dZ), (dZ-dX), PG_2);	// giao diem cua (4) va (PG2)
	if (!rc2) 	return false;

	float evade2_x = tmpPos2.x;
	float evade2_z = tmpPos2.z;
	//----------------------------
	float evade_x;
	float evade_z;
	float tichvohuong_1 = (dX*evade1_x + dZ*evade1_z - C2)*(dX*pos1->x + dZ*pos1->z - C2); // xet evade1 va pos1 so voi duong (2)
	if(tichvohuong_1>0){																 // -> evade1 va pos1 cung huong so voi duong (2)
		evade_x = tmpPos2.x;
		evade_z = tmpPos2.z;
	}
	else{																				 // -> evade1 va pos1 nguoc huong so voi duong (2)
		evade_x = tmpPos1.x;
		evade_z = tmpPos1.z;
	}
	BlockMove();
	MOVE_TO(evade_x,evade_z);
	return true;
}
//==================================================================================//
//==================================================================================//
//==================================================================================//
bool WINAPI DodgeMissileLine_45do_TIEN(KPos* pos1,KPos* pos2, float radius, float maxDist, KBuffer_Spell* pBufferSpell, float timeFlying, bool flag, fPtrRESET_DATA_SPELL fPtrRESET)
{
	//dZ.x - dX.z  = C1 = dZ*pos1.x - dX*pos1.z		(1)(d)
	//dX.x + dZ.z  = C2 = dX*player_x + dZ*player_z	(2)(vuong goc voi d, di qua player)
	//dZ.x - dX.z  = C3 = dZ.player_x - dX.player_z	(3)(song song voi d + di qua player)
	//dZ.x - dX.z  = C5   = dZ.dodge_x  - dX.dodge_z 	(4)(song song voi d + di qua dodge)
	//==>C4 = dZ.x_0 - dX.y_0 - R*calc1
	//==>C4 = dZ.x_0 - dX.y_0 + R*calc1
	//PG cua (2) va (3) : ------------------------------------------------------------------------------
	//dX.x + dZ.z  - C2 = dZ.x - dX.z  - C3		=> (dX-dZ).x + (dZ+dX).z = C2-C3 	(PG1)
	//dX.x + dZ.z  - C2 = -(dZ.x - dX.z  - C3)		=> (dX+dZ).x + (dZ-dX).z = C2+C3	(PG2)
	//--------------------------------------------------------------------------------------------------
	if (pBufferSpell == NULL) return FALSE;
	float fDistance = Distance_2D(pos1->x, pos1->z, pos2->x, pos2->z);
	//__oMsg("TRUOC khoang cach skill line= %f;timeFlying=%f;TImer=%f", fDistance, timeFlying, pBufferSpell->nTimer);
	if (timeFlying <= pBufferSpell->nTimer)
	{
		//__oMsg("SAU khoang cach skill line= %f;timeFlying=%f;TImer=%f", fDistance, timeFlying, pBufferSpell->nTimer);
		UnBlockMove();
		fPtrRESET(pBufferSpell->index);
		return FALSE;
	}
	
	KNpc *g_pPlayer = GetPlayer();
	KPos diemVuongGoc;
	GIAO_DIEM_VUONG_GOC(diemVuongGoc, *pos1, *pos2, g_pPlayer->CurrentPos);
	float nKhoangCach = Distance_2D(diemVuongGoc, g_pPlayer->CurrentPos);
	//__oMsg("=========khoang cach cu = %f", nKhoangCach);
	if(nKhoangCach >= radius + g_pPlayer->nOverrideCollisionRadius)
	{
		//__oMsg("=========UnBlockMove()");
		UnBlockMove();
	}

	//--- cho them doan nay : dang combo se ko ne nhung skill ko nguy hiem --------------------------------------
	if(g_bNormalAttackHero/* && pBufferSpell->nIsDangerous == false*/)
	{
		UnBlockMove();
		return FALSE;
	}

	if (IsNPCMissileInLine(g_pPlayer, pos1, pos2, radius, maxDist, flag) == false)
	{
		return FALSE;
	}
	
//--- moi them ---------------------------------------
	countBiDanhBoiSkillDinhHuong = 1;
	KBuffs* pBuffBlackShield = GET_BUFF(g_pPlayer, "BlackShield");
	if(pBuffBlackShield && pBuffBlackShield->nEnd_Time - GetTimeGame() > 0.3) return false;
	
	KBuffs* pBuffSivirE = GET_BUFF(g_pPlayer, "SivirE");

	

	if(pBuffSivirE && pBuffBlackShield->nEnd_Time - GetTimeGame() > 0.3) return false;

	float R = (radius + g_pPlayer->nOverrideCollisionRadius + 30);
	////__oMsg("1------------------R = %f, Collision_Radius = %f", R, g_pPlayer->nOverrideCollisionRadius);

	float dX = pos2->x - pos1->x;
	float dZ = pos2->z - pos1->z;
	float player_x = g_pPlayer->CurrentPos.x;
	float player_z = g_pPlayer->CurrentPos.z;
	float C1       = dZ*pos1->x - dX*pos1->z;
	float C2     	= dX*player_x + dZ*player_z;
	float C3	   	= dZ*player_x - dX*player_z;
	float C5;
	float PG_1 = C2-C3;
	float PG_2 = C2+C3;

	float calc1    = sqrt(dZ*dZ + dX*dX);
	//-----------------------------------
	KPos tmpPos0, tmpPos1, tmpPos2;
	int Nghiem_0  = NghiemHePTBacNhat(tmpPos0,dZ, -dX, C1, dX, dZ, C2); // giao diem cua (1) va (2)
	if (!Nghiem_0)  return FALSE;
	float x_0  =  tmpPos0.x;
	float z_0  =  tmpPos0.z;
	//-----------------------------------
	float C4_1 = dZ*x_0 - dX*z_0 - R*calc1;
	float C4_2 = dZ*x_0 - dX*z_0 + R*calc1; 

	int  Nghiem1  = NghiemHePTBacNhat(tmpPos1,dZ, -dX, C4_1, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem1)  return FALSE;
	float dodge1_x  = tmpPos1.x;
	float dodge1_z  = tmpPos1.z;
	//-----------------------------------
	int  Nghiem2  = NghiemHePTBacNhat(tmpPos2,dZ, -dX, C4_2, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem2)  return FALSE;
	float dodge2_x  = tmpPos2.x;
	float dodge2_z  = tmpPos2.z;
	//-----------------------------------
	float kc1 = sqrt((player_x - dodge1_x)*(player_x - dodge1_x) + (player_z - dodge1_z)*(player_z - dodge1_z));
	float kc2 = sqrt((player_x - dodge2_x)*(player_x - dodge2_x) + (player_z - dodge2_z)*(player_z - dodge2_z));

	float dodge_x,dodge_z;
	if (kc1 < kc2){
		dodge_x = dodge1_x;
		dodge_z = dodge1_z;
	}
	else {
		dodge_x = dodge2_x;
		dodge_z = dodge2_z;
	}
	//----------------------------
	C5       = dZ*dodge_x  - dX*dodge_z; 
	int  rc1 = NghiemHePTBacNhat(tmpPos1,dZ, -dX, C5, (dX-dZ), (dZ+dX), PG_1); // giao diem cua (4) va (PG1)
	if (!rc1)	return FALSE;

	float evade1_x = tmpPos1.x;
	float evade1_z = tmpPos1.z;

	int rc2 = NghiemHePTBacNhat(tmpPos2,dZ, -dX, C5, (dX+dZ), (dZ-dX), PG_2);	// giao diem cua (4) va (PG2)
	if (!rc2) 	return FALSE;

	float evade2_x = tmpPos2.x;
	float evade2_z = tmpPos2.z;
	//----------------------------
	float evade_x;
	float evade_z;
	float tichvohuong_1 = (dX*evade1_x + dZ*evade1_z - C2)*(dX*pos1->x + dZ*pos1->z - C2); // xet evade1 va pos1 so voi duong (2)
	if(tichvohuong_1>0){																 // -> evade1 va pos1 cung huong so voi duong (2)
		evade_x = tmpPos1.x;
		evade_z = tmpPos1.z;
	}
	else{																				 // -> evade1 va pos1 nguoc huong so voi duong (2)
		evade_x = tmpPos2.x;
		evade_z = tmpPos2.z;
	}
	BlockMove();
	MOVE_TO(evade_x,evade_z);
	return TRUE;
}
//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IsNPCMissileInLine(KNpc *pNpc, KPos *pos1,KPos *pos2, float radius, float maxDist, bool flag) //dZ.x - dX.z  = C1 = dZ*pos1.x - dX*pos1.z  (1)(d)
{                                                                                       //dX.x + dZ.z  = C2 = dX*player_x + dZ*player_z (2)(vuong goc voi d)
	float Range = (maxDist + pNpc->nOverrideCollisionRadius + 30);  
	//float R		= (radius  + pNpc->nOverrideCollisionRadius + 30.0);
	float R		= (radius  + 100);
	float dX	= pos2->x - pos1->x;
	float dZ	= pos2->z - pos1->z;
	float Npc_x = pNpc->CurrentPos.x;
	float Npc_z = pNpc->CurrentPos.z;
	float C1    = dZ*pos1->x - dX*pos1->z;
	float C2    = dX*Npc_x + dZ*Npc_z;

	float calc1 = sqrt(dZ*dZ + dX*dX);
	float kc1	= abs(dZ*Npc_x - dX*Npc_z  - C1)/calc1; //k/c tu NPC den (1)(d)
	if(kc1 >= R)  return FALSE;
	//---------------------------
	KPos tmpPos;
	int  rc = NghiemHePTBacNhat(tmpPos,dZ, -dX, C1, dX, dZ, C2); //giao diem cua (1) va (2)
	if (!rc) return FALSE;
	float vuonggoc_x = tmpPos.x;
	float vuonggoc_z = tmpPos.z;
	float kc2 = sqrt((vuonggoc_x - pos1->x)*(vuonggoc_x - pos1->x) + (vuonggoc_z - pos1->z)*(vuonggoc_z - pos1->z)); //k/c tu giao diem o tren den pos1
	if(kc2 >= Range) return FALSE;
	//-----------------------------
	//dX.x + dZ.z  = C3 = dX*pos1->x + dZ*pos1->z (3)(vuong goc voi d)- va di qua pos1
	float C3 = dX*pos1->x + dZ*pos1->z;
	float tichvohuong = (dX*vuonggoc_x + dZ*vuonggoc_z  - C3)*(dX*pos2->x + dZ*pos2->z  - C3);// xet diem vuong goc va pos2 cung phia hay khac phia so voi (3)
	if(flag && tichvohuong < 0) return FALSE;

	//KPos *posNghiem1 = new KPos, *posNghiem2 = new KPos;
	//TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, pos1, pos2, maxDist);
	////float dX = pBuff.MaxDestPos.x - pBuff.SourcePos.x;
	////float dZ = pBuff.MaxDestPos.z - pBuff.SourcePos.z;
	//float C2_1 = dX*pos1->x + dZ*pos1->z;
	//float tichVoHuong_1 = (dX*pos2->x + dZ*pos2->z  - C2_1) * (dX*posNghiem1->x + dZ*posNghiem1->z  - C2_1);
	//if (tichVoHuong_1 >= 0)
	//{
	//	//__oMsg("Nghiem 1 = (%f, %f)", posNghiem1->x, posNghiem1->z);
	//	pos2->x = posNghiem1->x;
	//	pos2->z = posNghiem1->z;
	//}
	//else
	//{
	//	//__oMsg("Nghiem 2 = %f, %f)", posNghiem2->x, posNghiem2->z);
	//	pos2->x = posNghiem2->x;
	//	pos2->z = posNghiem2->z;
	//}
	////------------------------------------------------
	//float tichvohuong = (dX*pos1->x + dZ*pos1->z - C2)*(dX*pos2->x + dZ*pos2->z - C2);// kiem tra pos1-pos2 nam cung hay khac phia so voi duong thang (2)
	////__oMsg("tichvohuong----------> %f", tichvohuong);
	//if(flag && tichvohuong > 0)
	//{
	//	//__oMsg("----------> %s,%d", __FILE__, __LINE__);
	//	float kc3 = sqrt((vuonggoc_x - pos2->x)*(vuonggoc_x - pos2->x) + (vuonggoc_z - pos2->z)*(vuonggoc_z - pos2->z)); //k/c tu giao diem o tren den pos2
	//	if(kc3 > pNpc->nOverrideCollisionRadius + 30.0) return FALSE;
	//}
	return TRUE;
}
bool IsNPCInCircle(KNpc *pNpc, KPos *pos1, float radius)
{
	float R		= (radius  + 100);
	float Npc_x = pNpc->CurrentPos.x;
	float Npc_z = pNpc->CurrentPos.z;
	
	float kc1	= Distance_2D(Npc_x, Npc_z, pos1->x, pos1->z);
	if(kc1 >= R)		return FALSE;
	//---------------------------
	return TRUE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IsINSIDE_TAMGIAC(KPos *pos_diem, KPos *pos_1, KPos *pos_2, KPos *pos_3) 
{ 
	float fAB = (pos_diem->z - pos_1->z)*(pos_2->x - pos_1->x) - (pos_diem->x - pos_1->x)*(pos_2->z - pos_1->z);
	float fBC = (pos_diem->z - pos_2->z)*(pos_3->x - pos_2->x) - (pos_diem->x - pos_2->x)*(pos_3->z - pos_2->z);
	float fCA = (pos_diem->z - pos_3->z)*(pos_1->x - pos_3->x) - (pos_diem->x - pos_3->x)*(pos_1->z - pos_3->z); 

	if ((fAB*fBC > 0.) && (fBC*fCA > 0.)) return true;
	return false;
}
//==================================================================================//
//==================================================================================//
//==================================================================================//
bool WINAPI DodgeCircle(KPos* pos1, float radius, KBuffer_Spell* pBufferSpell, float timeFlying, fPtrRESET_DATA_SPELL fPtrRESET, bool flagFlash)
{
	if (pBufferSpell == NULL) return FALSE;
	//__oMsg("TRUOC[%f]--------------->[%s][%d]", pBufferSpell->nTimer, __FILE__, __LINE__);
	//__oMsg("TRUOC hero[%s]--------------->[%s][%d]", pBufferSpell->szHeroName, __FILE__, __LINE__);
	if (timeFlying <= pBufferSpell->nTimer)
	{
		//__oMsg("SAU[%f]--------------->[%s][%d]", pBufferSpell->nTimer, __FILE__, __LINE__);
		UnBlockMove();
		fPtrRESET(pBufferSpell->index);
		return FALSE;
	}
	
	KNpc *g_pPlayer = GetPlayer();
	float nKhoangCach1 = Distance_2D(*pos1, g_pPlayer->CurrentPos);
	if(nKhoangCach1 >= radius + 160.0)
	{
		//__oMsg("goi unblock1:%d, %s", __LINE__, __FILE__);
		UnBlockMove();
	}
	if (IsNPCInCircle(g_pPlayer, pos1, radius) == false)
	{
		//__oMsg("Is in Circle return false");
		return FALSE;
	}
	float player_x = g_pPlayer->CurrentPos.x;
	float player_z = g_pPlayer->CurrentPos.z;
	float R = (radius + 180);
	float dX = g_pPlayer->CurrentPos.x - pos1->x;
	float dZ =  g_pPlayer->CurrentPos.z - pos1->z;

	float C1       = dZ*pos1->x - dX*pos1->z;
	float C2   	= dX*pos1->x + dZ*pos1->z;

	float calc1    = sqrt(dZ*dZ + dX*dX);
	//-----------------------------------
	KPos tmpPos0, tmpPos1, tmpPos2;
	//float KhoangCach = Distance_2D(player_x, player_z, pos1->x, pos1->z);
	////__oMsg("kc ------------ :%f", KhoangCach);
	//-----------------------------------
	float C4_1 = dX*pos1->x + dZ*pos1->z - R*calc1;
	float C4_2 = dX*pos1->x + dZ*pos1->z + R*calc1; 

	int  Nghiem1  = NghiemHePTBacNhat(tmpPos1,dX, dZ, C4_1, dZ, -dX, C1); //giao diem cua (1) va (4)
	if (!Nghiem1)  return FALSE;
	float dodge1_x  = tmpPos1.x;
	float dodge1_z  = tmpPos1.z;
	//-----------------------------------
	int  Nghiem2  = NghiemHePTBacNhat(tmpPos2,dX, dZ, C4_2, dZ, -dX, C1); //giao diem cua (1) va (4)
	if (!Nghiem2)  return FALSE;
	float dodge2_x  = tmpPos2.x;
	float dodge2_z  = tmpPos2.z;
	//-----------------------------------
	float kc1 = Distance_2D(player_x, player_z, dodge1_x, dodge1_z);
	float kc2 = Distance_2D(player_x, player_z, dodge2_x, dodge2_z);

	float dodge_x,dodge_z;

	if (kc1 < kc2){
		dodge_x = dodge1_x;
		dodge_z = dodge1_z;
	}
	else {
		dodge_x = dodge2_x;
		dodge_z = dodge2_z;
	}
	//----------------------------
	if (CheckName(pBufferSpell->szHeroName,  (sz__Darius)))
	{
		goto DODGE;
	}
	dX = pBufferSpell->SourcePos.x - pos1->x;
	dZ = pBufferSpell->SourcePos.z - pos1->z;
	float D1 = dZ*pos1->x - dX*pos1->z;   //(a)duong thang di qua pBuff->Source va pos1(tam duong tron) : dZ*x - dX*z = D1 = dZ*pos1->x - dX*pos1->z;
	float D2 = dX*player_x + dZ*player_z; //(b)duong thang di qua g_pPlayer va vuong goc voi (a)   : dX*x + dZ*z = D2 = dX*player_x + dZ*player_z;
	// check pos1 va buff->Source nam cung hay khac phia voi (b)
	float tichvohuong =  (dX*pos1->x + dZ*pos1->z - D2)*(dX*pBufferSpell->SourcePos.x + dZ*pBufferSpell->SourcePos.z - D2);
	if(tichvohuong < 0)
	{
		KPos *pos_diem1 = new KPos,*pos_diem2 = new KPos, *vuonggoc = new KPos;
		int  Nghiem0  = NghiemHePTBacNhat(tmpPos0,dX, dZ, D2, dZ, -dX, D1);  //giao diem cua (a) va (b)  : giao diem cua 2 duong thang vuong goc voi nhau 
		vuonggoc->x = tmpPos0.x;
		vuonggoc->z = tmpPos0.z;

		GiaoDiem_DuongTronVaDuongThang(pos_diem1, pos_diem2, vuonggoc, &g_pPlayer->CurrentPos, pos1, R);
		// check pos_diem1 va g_pPlayer nam cung hay khac phia voi (a)
		tichvohuong = (dZ*pos_diem1->x - dX*pos_diem1->z - D1)*(dZ*g_pPlayer->CurrentPos.x - dX*g_pPlayer->CurrentPos.z - D1);
		if(tichvohuong >= 0)
		{
			dodge_x = pos_diem1->x;
			dodge_z = pos_diem1->z;
		}
		else
		{
			dodge_x = pos_diem2->x;
			dodge_z = pos_diem2->z;
		}
	}
DODGE:
	//----------------------------
	
	return TRUE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool DodgeCone(KPos* startPoint,KPos* endPoint, float radius_cone, float radius_line1, float range, KBuffer_Spell* pBufferSpell, float timeFlying, bool flag, fPtrRESET_DATA_SPELL fPtrRESET)
{
	if (pBufferSpell == NULL) return FALSE;
	if (timeFlying <= pBufferSpell->nTimer)
	{
		fPtrRESET(pBufferSpell->index);
	}
	KPos posNghiem1, posNghiem2;
	TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, *startPoint, *endPoint, range);
	float dX = endPoint->x - startPoint->x;
	float dZ = endPoint->z - startPoint->z;
	float C2 = dX * startPoint->x + dZ * startPoint->z;
	float tichVoHuong = (dX*endPoint->x + dZ*endPoint->z  - C2) * (dX*posNghiem1.x + dZ*posNghiem1.z  - C2);
	if (tichVoHuong >= 0)
	{
		endPoint->x = posNghiem1.x; endPoint->z = posNghiem1.z;     // chuyen diem endPoint ve dung vi tri cua no
	}
	else
		endPoint->x = posNghiem2.x, endPoint->z = posNghiem2.z;

	KPos *pos_diem1 = new KPos,*pos_diem2 = new KPos;
	TIM_2DIEM_CACH_1DIEM(pos_diem1, pos_diem2, endPoint, startPoint, radius_cone);  // 2 diem day cua hinh non, radius la k/c tu endPoint den pos1 hoac pos2

	KNpc *g_pPlayer = GetPlayer();
	float player_x = g_pPlayer->CurrentPos.x;
	float player_z = g_pPlayer->CurrentPos.z;
	if(!IsINSIDE_TAMGIAC(&g_pPlayer->CurrentPos, startPoint, pos_diem1, pos_diem2))// nam ngoai hinh non
	{
		//float radius_line = (radius_line1 + g_pPlayer->nOverrideCollisionRadius + 30.);
			////__oMsg("collision radius------------------------------%f", g_pPlayer->nOverrideCollisionRadius);
		bool checkInLine = ((IsNPCMissileInLine(g_pPlayer, startPoint, pos_diem1, radius_line1, range, flag) == true) 
						||  (IsNPCMissileInLine(g_pPlayer, startPoint, pos_diem2, radius_line1, range, flag) == true)
						||  (IsNPCMissileInLine(g_pPlayer, pos_diem1, pos_diem2, radius_line1, radius_cone*2, flag) == true));
		if( checkInLine == false )
		{
			////__oMsg("222------------------------------------------");
			return FALSE;
		}
	}
	//dX*x + dZ*z  = C2 = dX*player_x + dZ*player_z       (2)(vuong goc voi d, di qua vi tri cua nguoi choi)
	//a_dZ*x - a_dX*z  = a_C1 = a_dZ*startPoint->x - a_dX*startPoint->z  (a)(di qua startPoint va pos1)
	//b_dZ*x - b_dX*z  = b_C1 = b_dZ*startPoint->x - b_dX*startPoint->z  (b)(di qua startPoint va pos2)
	KPos Nghiem1, Nghiem2, Nghiem0, tmpPos, dodgePos;

	C2 = dX * player_x + dZ * player_z;
	float C1   = dZ*startPoint->x - dX*startPoint->z;
	int   n0   = NghiemHePTBacNhat(tmpPos,dZ, -dX, C1, dX, dZ, C2); //giao diem cua (1) va (2)
	if (!n0)  return FALSE;
	Nghiem0.x  = tmpPos.x;
	Nghiem0.z  = tmpPos.z;

	float a_dX = pos_diem1->x - startPoint->x;
	float a_dZ = pos_diem1->z - startPoint->z;
	float a_C1 = a_dZ*startPoint->x - a_dX*startPoint->z;
	int   n1   = NghiemHePTBacNhat(tmpPos,a_dZ, -a_dX, a_C1, dX, dZ, C2); //giao diem cua (a) va (2)
	if (!n1)  return FALSE;
	Nghiem1.x  = tmpPos.x;
	Nghiem1.z  = tmpPos.z;

	float b_dX = pos_diem2->x - startPoint->x;
	float b_dZ = pos_diem2->z - startPoint->z;
	float b_C1 = b_dZ*startPoint->x - b_dX*startPoint->z;
	int   n2   = NghiemHePTBacNhat(tmpPos,b_dZ, -b_dX, b_C1, dX, dZ, C2); //giao diem cua (b) va (2)
	if (!n2)  return FALSE;
	Nghiem2.x  = tmpPos.x;
	Nghiem2.z  = tmpPos.z;
	//-------------------------------
	float kc1 = sqrt((player_x - Nghiem1.x)*(player_x - Nghiem1.x) + (player_z - Nghiem1.z)*(player_z - Nghiem1.z));
	float kc2 = sqrt((player_x - Nghiem2.x)*(player_x - Nghiem2.x) + (player_z - Nghiem2.z)*(player_z - Nghiem2.z));
	////__oMsg("kc 1 = %f ------ kc 2 = %f --------------", kc1, kc2);
	if (kc1 < kc2){
		dodgePos.x = Nghiem1.x;
		dodgePos.z = Nghiem1.z;
	}
	else {
		dodgePos.x = Nghiem2.x;
		dodgePos.z = Nghiem2.z;
	}
	//-------------------------------
	float R = (radius_line1 + g_pPlayer->nOverrideCollisionRadius + 30);
	TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, dodgePos, Nghiem0, R);
	kc1 = sqrt((Nghiem0.x - posNghiem1.x)*(Nghiem0.x - posNghiem1.x) + (Nghiem0.z - posNghiem1.z)*(Nghiem0.z - posNghiem1.z));
	kc2 = sqrt((Nghiem0.x - posNghiem2.x)*(Nghiem0.x - posNghiem2.x) + (Nghiem0.z - posNghiem2.z)*(Nghiem0.z - posNghiem2.z));
	if (kc1 < kc2){
		dodgePos.x = posNghiem2.x;
		dodgePos.z = posNghiem2.z;
	}
	else {
		dodgePos.x = posNghiem1.x;
		dodgePos.z = posNghiem1.z;
	}
	//-------------------------------
	float kc3 = Distance_2D(*endPoint, Nghiem0);//sqrt((Nghiem0->x - endPoint->x)*(Nghiem0->x - endPoint->x) + (Nghiem0->z - endPoint->z)*(Nghiem0->z - endPoint->z));
	kc3 = kc3 + R; 
	float kc4 =  Distance_2D(dodgePos, Nghiem0);//sqrt((Nghiem0->x - dodgePos->x)*(Nghiem0->x - dodgePos->x) + (Nghiem0->z - dodgePos->z)*(Nghiem0->z - dodgePos->z));
	////__oMsg("kc 3 = %f ------ kc 4 = %f --------------", kc3, kc4);
	if(kc3 < kc4){
		//c_dZ*x - c_dX*z = c_C1 = c_dZ*pos_diem1->x - c_dX*pos_diem1->z     (c)di qua pos_diem1 va pos_diem2
		//dZ*x - dX*z     = C1_1 = dZ*player_x - dX*player_z      (d)(di qua pPlayer va song song voi (1))
		float c_dX = pos_diem2->x - pos_diem1->x;
		float c_dZ = pos_diem2->z - pos_diem1->z;
		float c_C1 = c_dZ*pos_diem1->x - c_dX*pos_diem1->z;
		float C1_1 = dZ*player_x - dX*player_z;

		n0   = NghiemHePTBacNhat(tmpPos,c_dZ, -c_dX, c_C1, dZ, -dX, C1_1); //giao diem cua (c) va (d)
		if (!n0)  return FALSE;
		Nghiem0.x  = tmpPos.x;
		Nghiem0.z  = tmpPos.z;

		TIM_DIEM_CACH_1DIEM(posNghiem1, posNghiem2, Nghiem0, g_pPlayer->CurrentPos, R);
		kc1 = sqrt((startPoint->x - posNghiem1.x)*(startPoint->x - posNghiem1.x) + (startPoint->z - posNghiem1.z)*(startPoint->z - posNghiem1.z));
		kc2 = sqrt((startPoint->x - posNghiem2.x)*(startPoint->x - posNghiem2.x) + (startPoint->z - posNghiem2.z)*(startPoint->z - posNghiem2.z));
		if (kc1 < kc2){
			dodgePos.x = posNghiem2.x;
			dodgePos.z = posNghiem2.z;
		}
		else {
			dodgePos.x = posNghiem1.x;
			dodgePos.z = posNghiem1.z;
		}
	}

	MOVE_TO(dodgePos.x,dodgePos.z);
	return TRUE;
	/*KPos diemVuongGoc;
	GIAO_DIEM_VUONG_GOC(diemVuongGoc, pBuff.SourcePos, pBuff.MaxDestPos, pPlayer->CurrentPos);
	fDistance = Distance_2D(diemVuongGoc, pBuff.SourcePos);*/
	/*//__oMsg("--------------------- distance = %f", fDistance);
	DodgeMissileLine_45do(&pBuff.SourcePos, &pBuff.MaxDestPos, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff);
	DodgeMissileLine_45do(&pBuff.SourcePos, pos_diem1, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff);
	DodgeMissileLine_45do(&pBuff.SourcePos, pos_diem2, float(TWISTEDFATE_Q_Radius), float(TWISTEDFATE_Q_Range), &pBuff);*/
//================================================================================================================
	//dZ*x - dX*z  = C1 = dZ*startPoint->x - dX*startPoint->z  (1)(d: duong thang di qua 2 diem startPoint & endPoint)
	//dX*x + dZ*z  = C2 = dX*player_x + dZ*player_z     (2)(vuong goc voi d, di qua vi tri cua nguoi choi)
	//dZ.x - dX.z  = C4   = dZ.dodge_x  - dX.dodge_z     (4)(song song voi d + di qua diem dodge)
	//==>C4 = C1 - R*calc1
	//==>C4 = C1 + R*calc1
//===========================================================================================================================
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IS_INCIRCLE(KNpc *pNpc, KPos *posTam, KBuffer_Spell* pBufferSpell)
{
	//float R		= (pBufferSpell->nRadius  + pNpc->nOverrideCollisionRadius + 30.0);
	float R		= (pBufferSpell->nRadius  + 100);

	float kc1	= Distance_2D(pNpc->CurrentPos, *posTam);
	//__oMsg("is in circle: kc1=%f  R=%f ----:%d, %s", kc1, R, __LINE__, __FILE__);
	if(kc1 >= R)		return FALSE;
	//---------------------------
	return TRUE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int COUNT_NPC_INCIRCLE(KPos *posTam, KBuffer_Spell *pBufferSpell)
{
	int nCountNPC = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return 0;
	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	BYTE isDied = (BYTE)pPlayer->nIsDie;
	if (isDied != 0) return nCountNPC;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pNpc = (KNpc*)dw3;
		int isDie = (BYTE)pNpc->nIsDie;
		if (!pNpc->IsAlly(pPlayer->nTeam_ID) || isDie == 1 || pNpc->nHP <= 0. || !pNpc->IsMinion())
			continue;
		if ((BYTE)pNpc->nIsTargetableToTeam != 4) continue;
		if (CheckName( (sz__Minion), pNpc->GetNameNpc()) == false) continue;
		if (IS_INCIRCLE(pNpc, posTam, pBufferSpell))
		{
			nCountNPC += 1;
		}
	}
	//__oMsg("******* nCountNPC = %d *********", nCountNPC);
	return nCountNPC;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool EVADE_CIRCLE(KPos* posTam, KBuffer_Spell* pBufferSpell, fPtrRESET_DATA_SPELL fPtrRESET/*, bool flagFlash*/)
{
	if (pBufferSpell == NULL) return FALSE;
	
	KNpc *pPlayer = GetPlayer();
	float nDistance = Distance_2D(*posTam, pBufferSpell->SourcePos);
	float nTime = 0.0;
	nTime = nDistance/pBufferSpell->nMissileSpeed;
	float nDelta = 150.0;
	if(nTime*1000 + pBufferSpell->nDelay > 1400.0) nDelta = 300.0;
	if(CheckName(pBufferSpell->szSpellName, "XerathRMissileWrapper")) nDelta = -255;
	if(CheckName(pBufferSpell->szSpellName, "SyndraWCast")) nDelta = -285;
	if(CheckName(pBufferSpell->szSpellName, "SyndraQ")) nDelta = -325;
	if(CheckName(pBufferSpell->szSpellName, "GnarBigE")) nDelta = -175;
	if(CheckName(pBufferSpell->szSpellName, "GnarE")) nDelta = -250;
	if ((nTime*1000 + pBufferSpell->nDelay) <= pBufferSpell->nTimer - nDelta)      // Check TIME de RESET pBufferSpell: dan qua roi ko can ne' nua
	{
		fPtrRESET(pBufferSpell->index);
		//__oMsg("Meo-RS-TIME");
		UnBlockMove();
		return FALSE;
	}
	//__oMsg("colestion = %f;nDistance =%f; nTIme = %f",pPlayer->nOverrideCollisionRadius, nDistance, nTime);
	//----------------------------------------------------------------
	float nKhoangCach1 = Distance_2D(*posTam, pPlayer->CurrentPos);
	if(nKhoangCach1 >= pBufferSpell->nRadius + 160.0)
	{
		//__oMsg("goi unblock1:%d, %s", __LINE__, __FILE__);
		UnBlockMove();
	}

	//--- cho them doan nay : dang combo se ko ne nhung skill ko nguy hiem --------------------------------------
	if(g_bNormalAttackHero && pBufferSpell->nIsDangerous == false)
	{
		UnBlockMove();
		return FALSE;
	}

	if (IS_INCIRCLE(pPlayer, posTam, pBufferSpell) == false)	return FALSE;
	
//--- moi them ---------------------------------------
	countBiDanhBoiSkillDinhHuong = 1;
	KBuffs* pBuffBlackShield = GET_BUFF(pPlayer, "BlackShield");
	if(pBuffBlackShield && pBuffBlackShield->nEnd_Time - GetTimeGame() > 0.3) return false;
	
	KBuffs* pBuffSivirE = GET_BUFF(pPlayer, "SivirE");

	

	if(pBuffSivirE && pBuffBlackShield->nEnd_Time - GetTimeGame() > 0.3) return false;

	//----------------------------------------------------------------
	float player_x = pBufferSpell->PlayerPos.x;
	float player_z = pBufferSpell->PlayerPos.z;
	float R		   = (pBufferSpell->nRadius + 180);
	if(pBufferSpell->nDangerValue == 5) R = (pBufferSpell->nRadius  + 250);
	float dX	   = player_x - posTam->x;
	float dZ	   = player_z - posTam->z;

	float C1	   = dZ*posTam->x - dX*posTam->z;			//(1) la duong thang di qua posTam & pPlayer
	float C2	   = dX*posTam->x + dZ*posTam->z;			//(2) la duong thang di qua posTam & vuong goc voi (1)

	float calc1    = sqrt(dZ*dZ + dX*dX);
	//---------------------------
	KPos tmpPos0, tmpPos1, tmpPos2;
	//---------------------------
	float C4_1 = dX*posTam->x + dZ*posTam->z - R*calc1;
	float C4_2 = dX*posTam->x + dZ*posTam->z + R*calc1; 

	int  Nghiem1  = NghiemHePTBacNhat(tmpPos1,dX, dZ, C4_1, dZ, -dX, C1); //giao diem cua (1) va (4_1)
	if (!Nghiem1)  return FALSE;
	float dodge1_x  = tmpPos1.x;
	float dodge1_z  = tmpPos1.z;
	//---------------------------
	int  Nghiem2  = NghiemHePTBacNhat(tmpPos2,dX, dZ, C4_2, dZ, -dX, C1); //giao diem cua (1) va (4_2)
	if (!Nghiem2)  return FALSE;
	float dodge2_x  = tmpPos2.x;
	float dodge2_z  = tmpPos2.z;
	//---------------------------
	float kc1 = Distance_2D(player_x, player_z, dodge1_x, dodge1_z);
	float kc2 = Distance_2D(player_x, player_z, dodge2_x, dodge2_z);

	float dodge_theoTam_x,dodge_theoTam_z;		// diem ne tu posTam => pPlayer => dodge_theoTam(3 diem nay nam tren 1 duong thang, va cat duong tron)
	if (kc1 < kc2){
		dodge_theoTam_x = dodge1_x;
		dodge_theoTam_z = dodge1_z;
	}
	else {
		dodge_theoTam_x = dodge2_x;
		dodge_theoTam_z = dodge2_z;
	}
	//----------------------------------------------------------------
	dX = pBufferSpell->SourcePos.x - posTam->x;
	dZ = pBufferSpell->SourcePos.z - posTam->z;
	float D1 = dZ*posTam->x - dX*posTam->z;   //(a)duong thang di qua pBuff->Source va posTam		 : dZ*x - dX*z = D1 = dZ*posTam->x - dX*posTam->z;
	float D2 = dX*player_x  + dZ*player_z;	  //(b)duong thang di qua pPlayer va vuong goc voi (a)   : dX*x + dZ*z = D2 = dX*player_x  + dZ*player_z;
	float D3 = dZ*player_x  - dX*player_z;	  //(c)duong thang di qua pPlayer va song song voi (a)   : dZ*x - dX*z = D3 = dZ*player_x  - dX*player_z;
	float D4 = dX*posTam->x + dZ*posTam->z;	  //(e)duong thang di qua posTam va vuong goc voi (a)    : dX*x + dZ*z = D4 = dX*posTam->x  + dZ*posTam->z;
	//---------------------------------
	KPos *pos_diem1 = new KPos,*pos_diem2 = new KPos, *vuonggoc = new KPos;
	int  Nghiem0  = NghiemHePTBacNhat(tmpPos0,dX, dZ, D2, dZ, -dX, D1);  //giao diem cua (a) va (b)  : giao diem cua 2 duong thang vuong goc voi nhau 
	vuonggoc->x = tmpPos0.x;
	vuonggoc->z = tmpPos0.z;
	GiaoDiem_DuongTronVaDuongThang(pos_diem1, pos_diem2, vuonggoc, &pBufferSpell->PlayerPos, posTam, R);
	float dodge_theoVuongGoc_x,dodge_theoVuongGoc_z;					// diem ne theo duong thang vuong goc voi (a)
	
	// check pos_diem1 va g_pPlayer nam cung hay khac phia voi (a)
	float tichvohuong = (dZ*pos_diem1->x - dX*pos_diem1->z - D1)*(dZ*player_x - dX*player_z - D1);
	if(tichvohuong >= 0)		
	{
		dodge_theoVuongGoc_x = pos_diem1->x;
		dodge_theoVuongGoc_z = pos_diem1->z;
	}
	else
	{
		dodge_theoVuongGoc_x = pos_diem2->x;
		dodge_theoVuongGoc_z = pos_diem2->z;
	}
	//-----------------------------------------------------------------
	//tinh theo 1 diem nua: diem nay nam tren duong thang(e): vuong goc voi(a),di qua posTam va cat duong tron 
	KPos *pos_diemX = new KPos;
	int  NghiemX  = NghiemHePTBacNhat(tmpPos0,dX, dZ, D4, dZ, -dX, D3);  //giao diem cua (e) va (c)  : 2 duong thang nay cung vuong goc voi nhau
	pos_diemX->x = tmpPos0.x;
	pos_diemX->z = tmpPos0.z;
	float R2		   = (pBufferSpell->nRadius + 100);
	GiaoDiem_DuongTronVaDuongThang(pos_diem1, pos_diem2, pos_diemX, posTam, posTam, R2);
	float dodge_theoDiemMoi_x,dodge_theoDiemMoi_z;					// diem ne thuoc duong thang vuong (e) va cat duong tron
	// check pos_diem1 va g_pPlayer nam cung hay khac phia voi (a)
	tichvohuong = (dZ*pos_diem1->x - dX*pos_diem1->z - D1)*(dZ*player_x - dX*player_z - D1);
	if(tichvohuong >= 0)		
	{
		dodge_theoDiemMoi_x = pos_diem1->x;
		dodge_theoDiemMoi_z = pos_diem1->z;
	}
	else
	{
		dodge_theoDiemMoi_x = pos_diem2->x;
		dodge_theoDiemMoi_z = pos_diem2->z;
	}
	//----------------------------------------------------------------------------------------------------------------------------------
	float EVADE_x,EVADE_z;
	//----------------------------------------------------------------
	// check posTam va pBufferSpell->Source nam cung hay khac phia voi (b)
	float tichvohuong1 =  (dX*posTam->x + dZ*posTam->z - D2)*(dX*pBufferSpell->SourcePos.x + dZ*pBufferSpell->SourcePos.z - D2);
	if(tichvohuong1 < 0)		// pPlayer nam giua posTam va pBufferSpell->SourcePos ( pPlayer dang gan tuong dich hon so voi posTam)
	{
		// check MousePos_Player va pBufferSpell->Source nam cung hay khac phia voi (b)
		float tichvohuong2 =  (dX*pBufferSpell->MousePos_Player.x + dZ*pBufferSpell->MousePos_Player.z - D2)*(dX*pBufferSpell->SourcePos.x + dZ*pBufferSpell->SourcePos.z - D2);
		if(tichvohuong2 <= 0)	// LUI XA DICH
		{
			float nTimeDanBay1 = (nTime*1000 + pBufferSpell->nDelay);
			float nDist_dichuyen_DiemMoi = Distance_2D(dodge_theoDiemMoi_x,dodge_theoDiemMoi_z, player_x, player_z);
			float nTime_dichuyen_DiemMoi = nDist_dichuyen_DiemMoi/pPlayer->nMoveSpeed;
			
			if(nTimeDanBay1 - 0.0 > nTime_dichuyen_DiemMoi*1000 && (pBufferSpell->nIsDangerous == true || !Count_EnemyPlayer_Around_NPC(pPlayer, 650.0)))
			{
				GiaoDiem_DuongTronVaDuongThang(pos_diem1, pos_diem2, pos_diemX, posTam, posTam, R);
				// check pos_diem1 va g_pPlayer nam cung hay khac phia voi (a)
				tichvohuong = (dZ*pos_diem1->x - dX*pos_diem1->z - D1)*(dZ*player_x - dX*player_z - D1);
				if(tichvohuong >= 0)		
				{
					dodge_theoDiemMoi_x = pos_diem1->x;
					dodge_theoDiemMoi_z = pos_diem1->z;
				}
				else
				{
					dodge_theoDiemMoi_x = pos_diem2->x;
					dodge_theoDiemMoi_z = pos_diem2->z;
				}

				EVADE_x = dodge_theoDiemMoi_x;
				EVADE_z = dodge_theoDiemMoi_z;
				//__oMsg("=========== DI 1_XXX(THEO DIEM MOI) :%f, %f", EVADE_x, EVADE_z);
			}
			else
			{//--- tam thoi bo cho nay xem sao (coi nhu la ko ne dc, NV tu chay theo click chuot cua nguoi choi) -------
				//EVADE_x = dodge_theoVuongGoc_x;
				//EVADE_z = dodge_theoVuongGoc_z;

				//__oMsg("=========== DI 1111(VUONG GOC) :%f, %f", EVADE_x, EVADE_z);
			}
			//__oMsg("di den 1:%f, %f", EVADE_x, EVADE_z);
		}
		else					// TIEN LAI GAN DICH
		{
			EVADE_x = dodge_theoTam_x;
			EVADE_z = dodge_theoTam_z;
			//__oMsg("di den 2:%f, %f", EVADE_x, EVADE_z);
			//__oMsg("=========== DI 2222(THEO TAM) :%f, %f", EVADE_x, EVADE_z);
		}
	}
	else						// posTam nam giua pPlayer va pBufferSpell->SourcePos ( pPlayer dang xa tuong dich hon so voi posTam)
	{
		// check MousePos_Player va pBufferSpell->Source nam cung hay khac phia voi (b)
		float tichvohuong2 =  (dX*pBufferSpell->MousePos_Player.x + dZ*pBufferSpell->MousePos_Player.z - D2)*(dX*pBufferSpell->SourcePos.x + dZ*pBufferSpell->SourcePos.z - D2);
		if(tichvohuong2 <= 0)	// LUI XA DICH
		{
			EVADE_x = dodge_theoTam_x;
			EVADE_z = dodge_theoTam_z;
			//__oMsg("di den 3:%f, %f", EVADE_x, EVADE_z);
			//__oMsg("=========== DI 3333(THEO TAM) :%f, %f", EVADE_x, EVADE_z);
		}
		else					// TIEN LAI GAN DICH
		{
			float nTimeDanBay1 = (nTime*1000 + pBufferSpell->nDelay);
			float nDist_dichuyen_DiemMoi = Distance_2D(dodge_theoDiemMoi_x,dodge_theoDiemMoi_z, player_x, player_z);
			float nTime_dichuyen_DiemMoi = nDist_dichuyen_DiemMoi/pPlayer->nMoveSpeed;
			//__oMsg("=========== nTimeDanBay1 - nTime_dichuyen_DiemMoi (THEO DIEM MOI) :%f, %f", nTimeDanBay1, nTime_dichuyen_DiemMoi*1000);
			if(nTimeDanBay1 - 0.0 > nTime_dichuyen_DiemMoi*1000)
			{
				GiaoDiem_DuongTronVaDuongThang(pos_diem1, pos_diem2, pos_diemX, posTam, posTam, R);
				// check pos_diem1 va g_pPlayer nam cung hay khac phia voi (a)
				tichvohuong = (dZ*pos_diem1->x - dX*pos_diem1->z - D1)*(dZ*player_x - dX*player_z - D1);
				if(tichvohuong >= 0)		
				{
					dodge_theoDiemMoi_x = pos_diem1->x;
					dodge_theoDiemMoi_z = pos_diem1->z;
				}
				else
				{
					dodge_theoDiemMoi_x = pos_diem2->x;
					dodge_theoDiemMoi_z = pos_diem2->z;
				}

				EVADE_x = dodge_theoDiemMoi_x;
				EVADE_z = dodge_theoDiemMoi_z;
				//__oMsg("=========== DI 2_XXX(THEO DIEM MOI) :%f, %f", EVADE_x, EVADE_z);
			}
			else
			{
				EVADE_x = dodge_theoVuongGoc_x;
				EVADE_z = dodge_theoVuongGoc_z;
				//__oMsg("=========== DI 4444(VUONG GOC) :%f, %f", EVADE_x, EVADE_z);
			}

			//__oMsg("di den 4:%f, %f", EVADE_x, EVADE_z);
		}
	}
	//----------------------------------------------------------------
	KPos tempPos;
	if(dX == 0.0) 
	{
		tempPos.x = player_x;
		tempPos.z = 111.0;
	}
	else
	{
		tempPos.x = 1.0;				// cho nay co the lay tempPos la pos_diemX cung dc
		tempPos.z = (dZ - D3)/dX ;
	}
	float R1		   = (pBufferSpell->nRadius + 100);
	GiaoDiem_DuongTronVaDuongThang(pos_diem1, pos_diem2, &tempPos, &pBufferSpell->PlayerPos, posTam, R1);
	float dodge_theoSongSong_x,dodge_theoSongSong_z;					// diem ne theo duong thang song song voi (a)
	// check MousePos_Player va pos_diem1 nam cung hay khac phia voi (b)
	tichvohuong =  (dX*pBufferSpell->MousePos_Player.x + dZ*pBufferSpell->MousePos_Player.z - D2)*(dX*pos_diem1->x + dZ*pos_diem1->z - D2);
	if(tichvohuong >= 0)		
	{
		dodge_theoSongSong_x = pos_diem1->x;
		dodge_theoSongSong_z = pos_diem1->z;
	}
	else
	{
		dodge_theoSongSong_x = pos_diem2->x;
		dodge_theoSongSong_z = pos_diem2->z;
	}
	//----------------------------------------------------------------
	float nTimeDanBay = (nTime*1000 + pBufferSpell->nDelay);
	float nDist_dichuyen_songsong = Distance_2D(dodge_theoSongSong_x,dodge_theoSongSong_z, player_x, player_z);
	float nTime_dichuyen_songsong = nDist_dichuyen_songsong/pPlayer->nMoveSpeed;
	if(nTimeDanBay - 20.0 > nTime_dichuyen_songsong*1000)
	{
		GiaoDiem_DuongTronVaDuongThang(pos_diem1, pos_diem2, &tempPos, &pBufferSpell->PlayerPos, posTam, R);
		float dodge_theoSongSong_x,dodge_theoSongSong_z;					// diem ne theo duong thang song song voi (a)
		// check MousePos_Player va pos_diem1 nam cung hay khac phia voi (b)
		tichvohuong =  (dX*pBufferSpell->MousePos_Player.x + dZ*pBufferSpell->MousePos_Player.z - D2)*(dX*pos_diem1->x + dZ*pos_diem1->z - D2);
		if(tichvohuong >= 0)		
		{
			dodge_theoSongSong_x = pos_diem1->x;
			dodge_theoSongSong_z = pos_diem1->z;
		}
		else
		{
			dodge_theoSongSong_x = pos_diem2->x;
			dodge_theoSongSong_z = pos_diem2->z;
		}
		EVADE_x = dodge_theoSongSong_x;
		EVADE_z = dodge_theoSongSong_z;
		//__oMsg("=========== DI SONG SONG:%f, %f", EVADE_x, EVADE_z);
	}
	float nKhoangCach = Distance_2D(EVADE_x, EVADE_z, player_x, player_z);
	//__oMsg("toa do hien tai:%f, %f, %f", pPlayer->CurrentPos.x, pPlayer->CurrentPos.y, pPlayer->CurrentPos.z);
	//__oMsg("toa do chuot doi phuong:%f, %f, %f", pBufferSpell->MousePos.x, pBufferSpell->MousePos.y, pBufferSpell->MousePos.z);
	//__oMsg("toa do maxdest:%f, %f, %f", pBufferSpell->MaxDestPos.x, pBufferSpell->MaxDestPos.y, pBufferSpell->MaxDestPos.z);
	//__oMsg("nKhoangCach=%.2f;;;pBufferSpell->nDangerValu=%d", nKhoangCach, pBufferSpell->nDangerValue);
	//----------------------------------------------------------------
	
	//----------------------------------------------------------------
	return TRUE;
}
//==================================================================================//
//==================================================================================//
//==================================================================================//
bool EVADE_CIRCLE_SONGSONG(KPos* posTam, KBuffer_Spell* pBufferSpell, fPtrRESET_DATA_SPELL fPtrRESET/*, bool flagFlash*/)
{
	if (pBufferSpell == NULL) return FALSE;
	
	KNpc *pPlayer = GetPlayer();
	float nDistance = Distance_2D(*posTam, pBufferSpell->SourcePos);
	float nTime = 0.0;
	nTime = nDistance/pBufferSpell->nMissileSpeed;
	float nDelta = 150.0;
	if(nTime*1000 + pBufferSpell->nDelay > 1400.0) nDelta = 300.0;
	if ((nTime*1000 + pBufferSpell->nDelay) <= pBufferSpell->nTimer - nDelta)      // Check TIME de RESET pBufferSpell: dan qua roi ko can ne' nua
	{
		fPtrRESET(pBufferSpell->index);
		UnBlockMove();
		return FALSE;
	}
	//__oMsg("colestion = %f;nDistance =%f; nTIme = %f",pPlayer->nOverrideCollisionRadius, nDistance, nTime);
	//----------------------------------------------------------------
	float nKhoangCach1 = Distance_2D(*posTam, pPlayer->CurrentPos);
	if(nKhoangCach1 >= pBufferSpell->nRadius + 160.0)
	{
		//__oMsg("goi unblock1:%d, %s", __LINE__, __FILE__);
		UnBlockMove();
	}

	//--- cho them doan nay : dang combo se ko ne nhung skill ko nguy hiem --------------------------------------
	if(g_bNormalAttackHero && pBufferSpell->nIsDangerous == false)
	{
		UnBlockMove();
		return FALSE;
	}

	if (IS_INCIRCLE(pPlayer, posTam, pBufferSpell) == false)	return FALSE;
	//----------------------------------------------------------------
	/*float player_x = pPlayer->CurrentPos.x;
	float player_z = pPlayer->CurrentPos.z;*/
	float player_x = pBufferSpell->PlayerPos.x;
	float player_z = pBufferSpell->PlayerPos.z;
	float R		   = (pBufferSpell->nRadius + 180);
	if(pBufferSpell->nDangerValue == 5) R = (pBufferSpell->nRadius  + 250);
	//----------------------------------------------------------------
	float dX = pBufferSpell->SourcePos.x - posTam->x;
	float dZ = pBufferSpell->SourcePos.z - posTam->z;
	float D1 = dZ*posTam->x - dX*posTam->z;   //(a)duong thang di qua pBuff->Source va posTam		 : dZ*x - dX*z = D1 = dZ*posTam->x - dX*posTam->z;
	float D2 = dX*player_x  + dZ*player_z;	  //(b)duong thang di qua pPlayer va vuong goc voi (a)   : dX*x + dZ*z = D2 = dX*player_x  + dZ*player_z;
	float D3 = dZ*player_x  - dX*player_z;	  //(c)duong thang di qua pPlayer va song song voi (a)   : dZ*x - dX*z = D3 = dZ*player_x  - dX*player_z;
	//----------------------------------------------------------------------------------------------------------------------------------
	float EVADE_x,EVADE_z;
	//----------------------------------------------------------------
	KPos *tempPos = new KPos;
	if(dX == 0.0) 
	{
		tempPos->x = player_x;
		tempPos->z = 111.0;
	}
	else
	{
		tempPos->x = 1.0;				
		tempPos->z = (dZ - D3)/dX ;
	}
	float R1		   = (pBufferSpell->nRadius + 100);
	KPos *pos_diem1 = new KPos,*pos_diem2 = new KPos;
	GiaoDiem_DuongTronVaDuongThang(pos_diem1, pos_diem2, tempPos, &pBufferSpell->PlayerPos, posTam, R1);
	float dodge_theoSongSong_x,dodge_theoSongSong_z;					// diem ne theo duong thang song song voi (a)
	// check MousePos_Player va pos_diem1 nam cung hay khac phia voi (b)
	float tichvohuong =  (dX*pBufferSpell->MousePos_Player.x + dZ*pBufferSpell->MousePos_Player.z - D2)*(dX*pos_diem1->x + dZ*pos_diem1->z - D2);
	if(tichvohuong >= 0)		
	{
		dodge_theoSongSong_x = pos_diem1->x;
		dodge_theoSongSong_z = pos_diem1->z;
	}
	else
	{
		dodge_theoSongSong_x = pos_diem2->x;
		dodge_theoSongSong_z = pos_diem2->z;
	}
	//----------------------------------------------------------------
	float nTimeDanBay = (nTime*1000 + pBufferSpell->nDelay);
	float nDist_dichuyen_songsong = Distance_2D(dodge_theoSongSong_x,dodge_theoSongSong_z, player_x, player_z);
	float nTime_dichuyen_songsong = nDist_dichuyen_songsong/pPlayer->nMoveSpeed;
	//__oMsg("nDist_dichuyen_songsong =%.2f; nTimeDanBay = %.2f =|= nTime_dichuyen_songsong = %.2f", nDist_dichuyen_songsong, nTimeDanBay, nTime_dichuyen_songsong*1000);
	if(nTimeDanBay - 0.0 > nTime_dichuyen_songsong*1000)
	{
		GiaoDiem_DuongTronVaDuongThang(pos_diem1, pos_diem2, tempPos, &pBufferSpell->PlayerPos, posTam, R);
		float dodge_theoSongSong_x,dodge_theoSongSong_z;					// diem ne theo duong thang song song voi (a)
		// check MousePos_Player va pos_diem1 nam cung hay khac phia voi (b)
		tichvohuong =  (dX*pBufferSpell->MousePos_Player.x + dZ*pBufferSpell->MousePos_Player.z - D2)*(dX*pos_diem1->x + dZ*pos_diem1->z - D2);
		if(tichvohuong >= 0)		
		{
			dodge_theoSongSong_x = pos_diem1->x;
			dodge_theoSongSong_z = pos_diem1->z;
		}
		else
		{
			dodge_theoSongSong_x = pos_diem2->x;
			dodge_theoSongSong_z = pos_diem2->z;
		}
		EVADE_x = dodge_theoSongSong_x;
		EVADE_z = dodge_theoSongSong_z;
		//__oMsg("=====X====== DI SONG SONG:%f, %f", EVADE_x, EVADE_z);
	}
	else
	{
		return FALSE;
	}
	
	//----------------------------------------------------------------
	return TRUE;
}
//==================================================================================//
//==================================================================================//
//==================================================================================//
bool EVADE_LINE(KPos* startPoint, KPos* endPoint, KBuffer_Spell* pBufferSpell, fPtrRESET_DATA_SPELL fPtrRESET, bool nSpecial)
{
	//dZ*x - dX*z  = C1 = dZ*startPoint->x - dX*startPoint->z  (1)(d: duong thang di qua 2 diem startPoint & endPoint)
	//dX*x + dZ*z  = C2 = dX*player_x + dZ*player_z     (2)(vuong goc voi d, di qua vi tri cua nguoi choi)
	//dZ.x - dX.z  = C4   = dZ.dodge_x  - dX.dodge_z     (4)(song song voi d + di qua diem dodge)
	//==>C4 = C1 - R*calc1
	//==>C4 = C1 + R*calc1
	if (pBufferSpell == NULL) return FALSE;
	
	//if (nSPELLDATA->IsDangerous == true){if(nut DODGE DANGEROUS dc ko bat}...   // nut DODGE DANGEROUS: xu ly voi chieu nguy hiem
	KNpc *pPlayer = GetPlayer();
	KPos diemVuongGoc;
	GIAO_DIEM_VUONG_GOC(diemVuongGoc, *startPoint, *endPoint, pPlayer->CurrentPos);
	float nKhoangCach = Distance_2D(diemVuongGoc, pPlayer->CurrentPos);
	float nDistance = Distance_2D(diemVuongGoc, *startPoint);
	//__oMsg("====== 90* : XX_nSpecialTimer[%.2f] -- XX_nTimer[%.2f], ===[nDistance: %.2f]", pBufferSpell->nSpecialTimer, pBufferSpell->nTimer,nDistance);
	float nTime = 0.0;
	//================ DOAN NAY TINH TOAN TIME DAN BAY QUA VI TRI PLAYER DUNG ================ :
	// - con` truong hop dan ko bay ma den luon nhu LUX_R, truong hop dan bay xuyen ban do nhu EZREAL_R.. : ...
	//==================================================================================================
	if(nSpecial == true)
	{
		float nKC_StartPoint2Player   = Distance_2D(diemVuongGoc, *startPoint);    // KC tu StartPoint-> den pPlayer
		float nTime_StartPoint2Player = nKC_StartPoint2Player/pBufferSpell->nMissileSpeed; // tgian dan bay tu diem start' -> den pPlayer
		if(CheckName( (sz__Jinx), pBufferSpell->szHeroName) && nKC_StartPoint2Player > 14000)  nTime_StartPoint2Player = nKC_StartPoint2Player/2200;

		float nKC_EvadePoint2Player = 6500;//dung cho EZREAL & DRAVEN       // KC bat dau ne'(cai nay can check ki hon voi tung con)
		if(CheckName( (sz__Ashe), pBufferSpell->szHeroName)) nKC_EvadePoint2Player = 6000;
		if(CheckName( (sz__Jinx), pBufferSpell->szHeroName)) nKC_EvadePoint2Player = 7000;
		float nTime_EvadePoint2Player = nKC_EvadePoint2Player/pBufferSpell->nMissileSpeed;  // tgian dan bay tu diem can ne'-> den pPlayer(thuong dao dong tu 0.7->0.8 giay)
		if(CheckName( (sz__Jinx), pBufferSpell->szHeroName) && nKC_StartPoint2Player > 14000)  nTime_EvadePoint2Player = nKC_EvadePoint2Player/2200;

		float nTime_StartPoint2Evade  = nTime_StartPoint2Player*1000 + pBufferSpell->nDelay - nTime_EvadePoint2Player*1000; // tgian dan bay tu StartPoint -> den diem can ne'
		if(nKC_StartPoint2Player < nKC_EvadePoint2Player) // KC GAN
		{
			float nTime_3 = nTime_StartPoint2Player + pBufferSpell->nDelay/1000; // Tong time tu start -> den pPlayer:bao gom time_delay cast + time dan bay 
			nTime_StartPoint2Evade = nTime_StartPoint2Player + pBufferSpell->nDelay/1000;
			if(nTime_StartPoint2Evade > (float)1.60)
			{
				nTime_StartPoint2Evade = (float)1.6;  // toi da chi cho ne trong 1.6 giay
				if (CheckName( (sz__Jinx), pBufferSpell->szHeroName)) nTime_StartPoint2Evade = (float)2.1;
			}
			if((nTime_3 - nTime_StartPoint2Evade)*1000 > pBufferSpell->nSpecialTimer) // Doan dan bay luc nay chua can ne'
			{
				//__oMsg("=1= GAN-90* : KO_NE(ko-ne):[%.2f] >= nSpecialTimer[%.2f]", (nTime_3 - nTime_StartPoint2Evade)*1000, pBufferSpell->nSpecialTimer);
				RESET_BUFFER_SPELL_SPECIAL(pBufferSpell->index);
				return FALSE;
			}
			//__oMsg("TRUOC: =2= GAN-90* : nTime_StartPoint2Evade(time-ne):[%.2f] <= nTimer[%.2f]", nTime_StartPoint2Evade*1000, pBufferSpell->nTimer);
			if (nTime_StartPoint2Evade*1000 <= pBufferSpell->nTimer ||(nTime_StartPoint2Player*1000 + pBufferSpell->nDelay - 500) < pBufferSpell->nSpecialTimer)      // Check TIME de RESET pBufferSpell: dan qua roi ko can ne' nua
			{
				//__oMsg("SAU: =2= GAN-90* : nTime_StartPoint2Evade(time-ne):[%.2f] <= nTimer[%.2f]", nTime_StartPoint2Evade*1000, pBufferSpell->nTimer);
				fPtrRESET(pBufferSpell->index);
				UnBlockMove();
				return FALSE;
			}
			goto START_EVADE;
		}
		if(nTime_StartPoint2Evade >= pBufferSpell->nSpecialTimer)// Doan dan bay luc nay chua can ne'
		{
			//__oMsg("=1= XA-90* : nTime_StartPoint2Evade(ko-ne):[%.2f] >= nSpecialTimer[%.2f]", nTime_StartPoint2Evade*1000, pBufferSpell->nSpecialTimer);
			RESET_BUFFER_SPELL_SPECIAL(pBufferSpell->index);
			return FALSE;
		}
		float deltaTSub = 1000.0;
		if(CheckName( (sz__Jinx), pBufferSpell->szHeroName) && nKC_StartPoint2Player > 9000) deltaTSub = 1600;
		if (nTime_EvadePoint2Player*1000 <= pBufferSpell->nTimer || (nTime_StartPoint2Player*1000 + pBufferSpell->nDelay - deltaTSub) < pBufferSpell->nSpecialTimer)// Check TIME de RESET pBufferSpell: dan qua roi ko can ne' nua
		{
			//__oMsg("=2= XA-90* : nTime_EvadePoint2Player(time-ne):[%.2f] <= nTimer[%.2f]", nTime_EvadePoint2Player*1000, pBufferSpell->nTimer);
			fPtrRESET(pBufferSpell->index);
			UnBlockMove();
			return FALSE;
		}
		goto START_EVADE;
	}
	//================ END =============================================================================
	nTime = nDistance/pBufferSpell->nMissileSpeed;
	float nDelta = 150.0;
	if(nTime*1000 + pBufferSpell->nDelay > 1400.0) nDelta = 300.0;
	if ((nTime*1000 + pBufferSpell->nDelay) <= pBufferSpell->nTimer - nDelta)      // Check TIME de RESET pBufferSpell: dan qua roi ko can ne' nua
	{
		fPtrRESET(pBufferSpell->index);
		//__oMsg("========= UnBlockMove() ==> SKILL binh thuong ============");
		//__oMsg("goi unblock:%d, %s", __LINE__, __FILE__);
		UnBlockMove();
		return FALSE;
	}
	//__oMsg("nDistance =%f; nTIme = %f", nDistance, nTime);
	//================ END =============================================================================
START_EVADE:
	//__oMsg("bat dau ne roi:%d;%s", __LINE__, __FILE__);
	if(nKhoangCach >= pBufferSpell->nRadius  + 160.0)
	{
		UnBlockMove();
	}

	//--- cho them doan nay : dang combo se ko ne nhung skill ko nguy hiem --------------------------------------
	if(g_bNormalAttackHero && pBufferSpell->nIsDangerous == false)
	{
		UnBlockMove();
		return FALSE;
	}

	if (IS_INLINE(pPlayer, startPoint, endPoint, pBufferSpell) == false)  // Check PLAYER co nam trong duong dan. hay ko
	{
		//if(g_bNormalAttackHero)
		//{
		//	UnBlockMove();
		//}
		return FALSE;
	}
	//float R = (radius + g_pPlayer->nOverrideCollisionRadius + 30.);
	float R  = (pBufferSpell->nRadius  + 180);
	if (CheckName( (sz__LucianR), pBufferSpell->szSpellName)) R = (pBufferSpell->nRadius  + 220);
	//__oMsg("******* CollisionRadius = %f", pPlayer->nOverrideCollisionRadius);
	//if(CO_HIT_RUN || CO_HARASS || CO_TUNG SKILL) R = (pBufferSpell->nRadius  + 120.0);
	if(pBufferSpell->nDangerValue == 5) R = (pBufferSpell->nRadius  + 250);

	float dX = endPoint->x - startPoint->x;
	float dZ = endPoint->z - startPoint->z;
	float player_x = pPlayer->CurrentPos.x;
	float player_z = pPlayer->CurrentPos.z;
	float C1       = dZ*startPoint->x - dX*startPoint->z;
	float C2    = dX*player_x + dZ*player_z;

	float calc1    = sqrt(dZ*dZ + dX*dX);
	//-----------------------------------
	KPos tmpPos0, tmpstartPoint, tmpendPoint;
	int Nghiem_0  = NghiemHePTBacNhat(tmpPos0,dZ, -dX, C1, dX, dZ, C2); // giao diem cua (1) va (2)
	if (!Nghiem_0)  return FALSE;
	float x_0  =  tmpPos0.x;
	float z_0  =  tmpPos0.z;
	//-----------------------------------
	float C4_1 = dZ*x_0 - dX*z_0 - R*calc1;
	float C4_2 = dZ*x_0 - dX*z_0 + R*calc1; 

	int  Nghiem1  = NghiemHePTBacNhat(tmpstartPoint,dZ, -dX, C4_1, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem1)  return FALSE;
	float dodge1_x  = tmpstartPoint.x;
	float dodge1_z  = tmpstartPoint.z;
	//-----------------------------------
	int  Nghiem2  = NghiemHePTBacNhat(tmpendPoint,dZ, -dX, C4_2, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem2)  return FALSE;
	float dodge2_x  = tmpendPoint.x;
	float dodge2_z  = tmpendPoint.z;
	//-----------------------------------
	KPos dodge;
	float kc1 = sqrt((player_x - dodge1_x)*(player_x - dodge1_x) + (player_z - dodge1_z)*(player_z - dodge1_z));
	float kc2 = sqrt((player_x - dodge2_x)*(player_x - dodge2_x) + (player_z - dodge2_z)*(player_z - dodge2_z));
	if (kc1 < kc2){
		dodge.x = dodge1_x;
		dodge.z = dodge1_z;
	}
	else {
		dodge.x = dodge2_x;
		dodge.z = dodge2_z;
	}
	
	return TRUE;
}
//==================================================================================//
//==================================================================================//
//==================================================================================//
bool nKarma_radius_QR = false;
bool DODGE_LINE_NEW(KPos* startPoint, KPos* endPoint, KBuffer_Spell* pBufferSpell, fPtrRESET_DATA_SPELL fPtrRESET, bool nSpecial)
{
	if (pBufferSpell == NULL) return FALSE;
	
	KNpc *pPlayer = GetPlayer();
	KPos diemVuongGoc;
	GIAO_DIEM_VUONG_GOC(diemVuongGoc, *startPoint, *endPoint, pPlayer->CurrentPos);
	float nKhoangCach = Distance_2D(diemVuongGoc, pPlayer->CurrentPos);
	float nDistance = Distance_2D(diemVuongGoc, *startPoint);
	
	//==================================================================================================
	//...xoa di cho de nhin da~
//================ END =============================================================================
	float nKC_Collist2Player  = pPlayer->nOverrideCollisionRadius + 120;
	float nTime_DanBay        = (nDistance - nKC_Collist2Player)/pBufferSpell->nMissileSpeed;   // tgian dan bay tu luc bat dau ra dan -> toi luc trung muc tieu(la pPlayer)
	float nTime_Total		  = 1000*nTime_DanBay + pBufferSpell->nDelay;// tgian dan bay tu luc cast -> toi luc trung muc tieu(la pPlayer)(bao gom ca delay_cast_spell)
	float nTime_DanDaBay	  = 1000*(GetTimeGame() - pBufferSpell->nTimeGameCAST_SKILL);
	float nTime_ConLai		  = nTime_Total - nTime_DanDaBay;
	float nDelta_NeTruoc	  = 125;// tang len thi se ne som' hon
	if(1000*nKC_Collist2Player/pBufferSpell->nMissileSpeed < 50) nDelta_NeTruoc = 175;
	if(nSpecial == true)
	{
		if(!GET_BUFF((KNpc*) pBufferSpell->pNpc, sz__KarmaMantra) && nKarma_radius_QR == false)
		{
			pBufferSpell->nRadius = 80;
		}
		else
		{
			pBufferSpell->nRadius = 160;
			nKarma_radius_QR = true;
		}
	}
	float nKC_pPlayer2SafePos  = (pBufferSpell->nRadius + 125) - nKhoangCach;// tang 125 len thi se ne som hon chut
	float nTime_Move2SafePos   = 1000*nKC_pPlayer2SafePos/pPlayer->nMoveSpeed;
	/*float nKC_pPlayer2SafePos2 = nKhoangCach - (pBufferSpell->nRadius + 100);
	float nDelta_HetTimeNe	  = 0;
	if(nKC_pPlayer2SafePos2 > 0)
	{
		nDelta_HetTimeNe = 1000*nKC_pPlayer2SafePos2/pPlayer->nMoveSpeed;
		__oMsg("     + nDelta_HetTimeNe-1: %.2f , nDelta_NeTruoc: %f", nDelta_HetTimeNe, nDelta_NeTruoc);
		if(nDelta_HetTimeNe > 30) nDelta_HetTimeNe = 30;
		__oMsg("     + nDelta_HetTimeNe-2: %.2f", nDelta_HetTimeNe);
	}
	__oMsg("---- xxxxxxxxx: ==== nTime_CL(%.2f)->[%.2f] - (%.2f)nTime_Move - KC: %.2f, delay: %f", nTime_ConLai, - 50 + nDelta_HetTimeNe, nTime_Move2SafePos, nKhoangCach, pBufferSpell->nDelay);
	*/
	//__oMsg("---- xxxxxxxxx: ==== nTime_CL[%.2f]--[%.2f]nTime_Move - KC: %.2f, delay: %f, %.2f, %.2f", nTime_ConLai, nTime_Move2SafePos, nKhoangCach, pBufferSpell->nDelay, nTime_Total, nDelta_NeTruoc);
	if(nTime_ConLai + 125/* + nDelta_HetTimeNe*/ < 0)  // giam xuong 1 it de ne muot hon(vi reset som -> co the di chuyen som)
	{
		
		//-----------------------------
		fPtrRESET(pBufferSpell->index);
		if(nSpecial == true) nKarma_radius_QR = false;
		UnBlockMove();
		//__oMsg("---- RESET    : ==== nTime_CL[%.2f]--[%.2f]nTime_Move", nTime_ConLai, nTime_Move2SafePos);
		return FALSE;
	}
	if(nTime_ConLai - nDelta_NeTruoc > nTime_Move2SafePos && nTime_Move2SafePos > 0)
	{
		UnBlockMove();
		//__oMsg("---- ChuaCanNe: ==== nTime_CL[%.2f]--[%.2f]nTime_Move", nTime_ConLai, nTime_Move2SafePos);
		return FALSE;
	}
	
//================ END =============================================================================
//START_EVADE:
	//__oMsg("bat dau ne roi:%d;%s", __LINE__, __FILE__);
	if(nKhoangCach > pBufferSpell->nRadius  + 140.0)
	{
		//__oMsg(" ===>>>>>>> 1400000.....");
		UnBlockMove();
	}

	//--- cho them doan nay : dang combo se ko ne nhung skill ko nguy hiem --------------------------------------
	if(g_bNormalAttackHero && pBufferSpell->nIsDangerous == false)
	{
		UnBlockMove();
		return FALSE;
	}
	if (IS_INLINE(pPlayer, startPoint, endPoint, pBufferSpell) == false)  // Check PLAYER co nam trong duong dan. hay ko
	{
		//__oMsg("=================||=========||============ ===== KOVAO-LINE KC: %f", nKhoangCach);
		return FALSE;
	}
	
//--- moi them ---------------------------------------
	countBiDanhBoiSkillDinhHuong = 1;
	KBuffs* pBuffBlackShield = GET_BUFF(pPlayer, "BlackShield");
	if(pBuffBlackShield && pBuffBlackShield->nEnd_Time - GetTimeGame() > 0.3) return false;

	KBuffs* pBuffSivirE = GET_BUFF(pPlayer, "SivirE");

	

	if(pBuffSivirE && pBuffBlackShield->nEnd_Time - GetTimeGame() > 0.3) return false;

	//__oMsg("================================================ DANG-NE-NE KC: %f - %f\n", nKhoangCach, nDistance);
	//float R = (radius + g_pPlayer->nOverrideCollisionRadius + 30.);
	float R  = (pBufferSpell->nRadius  + 160);
	if (CheckName( (sz__LucianR), pBufferSpell->szSpellName)) R = (pBufferSpell->nRadius  + 220);
	if(pBufferSpell->nDangerValue == 5) R = (pBufferSpell->nRadius  + 260);

	float dX = endPoint->x - startPoint->x;
	float dZ = endPoint->z - startPoint->z;
	float player_x = pPlayer->CurrentPos.x;
	float player_z = pPlayer->CurrentPos.z;
	float C1       = dZ*startPoint->x - dX*startPoint->z;
	float C2    = dX*player_x + dZ*player_z;

	float calc1    = sqrt(dZ*dZ + dX*dX);
	//-----------------------------------
	KPos tmpPos0, tmpstartPoint, tmpendPoint;
	int Nghiem_0  = NghiemHePTBacNhat(tmpPos0,dZ, -dX, C1, dX, dZ, C2); // giao diem cua (1) va (2)
	if (!Nghiem_0)  return FALSE;
	float x_0  =  tmpPos0.x;
	float z_0  =  tmpPos0.z;
	//-----------------------------------
	float C4_1 = dZ*x_0 - dX*z_0 - R*calc1;
	float C4_2 = dZ*x_0 - dX*z_0 + R*calc1; 

	int  Nghiem1  = NghiemHePTBacNhat(tmpstartPoint,dZ, -dX, C4_1, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem1)  return FALSE;
	float dodge1_x  = tmpstartPoint.x;
	float dodge1_z  = tmpstartPoint.z;
	//-----------------------------------
	int  Nghiem2  = NghiemHePTBacNhat(tmpendPoint,dZ, -dX, C4_2, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem2)  return FALSE;
	float dodge2_x  = tmpendPoint.x;
	float dodge2_z  = tmpendPoint.z;
	//-----------------------------------
	KPos dodge;
	float kc1 = sqrt((player_x - dodge1_x)*(player_x - dodge1_x) + (player_z - dodge1_z)*(player_z - dodge1_z));
	float kc2 = sqrt((player_x - dodge2_x)*(player_x - dodge2_x) + (player_z - dodge2_z)*(player_z - dodge2_z));
	if (kc1 < kc2){
		dodge.x = dodge1_x;
		dodge.z = dodge1_z;
	}
	else {
		dodge.x = dodge2_x;
		dodge.z = dodge2_z;
	}
	//----------------------------
	
	return TRUE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool EVADE_THEO_MOUSE(KPos* startPoint, KPos* endPoint, KBuffer_Spell* pBufferSpell, fPtrRESET_DATA_SPELL fPtrRESET, bool nSpecial)
{
	//dZ*x - dX*z  = C1 = dZ*startPoint->x - dX*startPoint->z  (1)(d: duong thang di qua 2 diem startPoint & endPoint)
	//dX*x + dZ*z  = C2 = dX*player_x + dZ*player_z     (2)(vuong goc voi d, di qua vi tri cua nguoi choi)
	//dZ.x - dX.z  = C4   = dZ.dodge_x  - dX.dodge_z     (4)(song song voi d + di qua diem dodge)
	//==>C4 = C1 - R*calc1
	//==>C4 = C1 + R*calc1
	if (pBufferSpell == NULL) return FALSE;
	
	//if (nSPELLDATA->IsDangerous == true){if(nut DODGE DANGEROUS dc ko bat}...   // nut DODGE DANGEROUS: xu ly voi chieu nguy hiem
	KNpc *pPlayer = GetPlayer();
	KPos diemVuongGoc;
	GIAO_DIEM_VUONG_GOC(diemVuongGoc, *startPoint, *endPoint, pPlayer->CurrentPos);
	float nKhoangCach = Distance_2D(diemVuongGoc, pPlayer->CurrentPos);
	float nDistance = Distance_2D(diemVuongGoc, *startPoint);
	//__oMsg("====== 90* : XX_nSpecialTimer[%.2f] -- XX_nTimer[%.2f], ===[nDistance: %.2f]", pBufferSpell->nSpecialTimer, pBufferSpell->nTimer,nDistance);
	float nTime = 0.0;
	//================ DOAN NAY TINH TOAN TIME DAN BAY QUA VI TRI PLAYER DUNG ================ :
	// - con` truong hop dan ko bay ma den luon nhu LUX_R, truong hop dan bay xuyen ban do nhu EZREAL_R.. : ...
	//==================================================================================================
	if(nSpecial == true)
	{
		float nKC_StartPoint2Player   = Distance_2D(diemVuongGoc, *startPoint);    // KC tu StartPoint-> den pPlayer
		float nTime_StartPoint2Player = nKC_StartPoint2Player/pBufferSpell->nMissileSpeed; // tgian dan bay tu diem start' -> den pPlayer
		if(CheckName( (sz__Jinx), pBufferSpell->szHeroName) && nKC_StartPoint2Player > 14000)  nTime_StartPoint2Player = nKC_StartPoint2Player/2200;

		float nKC_EvadePoint2Player = 6500.0;//dung cho EZREAL & DRAVEN       // KC bat dau ne'(cai nay can check ki hon voi tung con)
		if(CheckName( (sz__Ashe), pBufferSpell->szHeroName)) nKC_EvadePoint2Player = 6000;
		if(CheckName( (sz__Jinx), pBufferSpell->szHeroName)) nKC_EvadePoint2Player = 7000;
		float nTime_EvadePoint2Player = nKC_EvadePoint2Player/pBufferSpell->nMissileSpeed;  // tgian dan bay tu diem can ne'-> den pPlayer(thuong dao dong tu 0.7->0.8 giay)
		if(CheckName( (sz__Jinx), pBufferSpell->szHeroName) && nKC_StartPoint2Player > 14000)  nTime_EvadePoint2Player = nKC_EvadePoint2Player/2200;

		float nTime_StartPoint2Evade  = nTime_StartPoint2Player*1000 + pBufferSpell->nDelay - nTime_EvadePoint2Player*1000; // tgian dan bay tu StartPoint -> den diem can ne'
		if(nKC_StartPoint2Player < nKC_EvadePoint2Player) // KC GAN
		{
			float nTime_3 = nTime_StartPoint2Player + pBufferSpell->nDelay/1000; // Tong time tu start -> den pPlayer:bao gom time_delay cast + time dan bay 
			nTime_StartPoint2Evade = nTime_StartPoint2Player + pBufferSpell->nDelay/1000;
			if(nTime_StartPoint2Evade > (float)1.60)
			{
				nTime_StartPoint2Evade = (float)1.6;  // toi da chi cho ne trong 1.6 giay
				if (CheckName( (sz__Jinx), pBufferSpell->szHeroName)) nTime_StartPoint2Evade = (float)2.1;
			}
			if((nTime_3 - nTime_StartPoint2Evade)*1000 > pBufferSpell->nSpecialTimer) // Doan dan bay luc nay chua can ne'
			{
				//__oMsg("=1= GAN-90* : KO_NE(ko-ne):[%.2f] >= nSpecialTimer[%.2f]", (nTime_3 - nTime_StartPoint2Evade)*1000, pBufferSpell->nSpecialTimer);
				RESET_BUFFER_SPELL_SPECIAL(pBufferSpell->index);
				return FALSE;
			}
			//__oMsg("TRUOC: =2= GAN-90* : nTime_StartPoint2Evade(time-ne):[%.2f] <= nTimer[%.2f]", nTime_StartPoint2Evade*1000, pBufferSpell->nTimer);
			if (nTime_StartPoint2Evade*1000 <= pBufferSpell->nTimer ||(nTime_StartPoint2Player*1000 + pBufferSpell->nDelay - 500.0) < pBufferSpell->nSpecialTimer)      // Check TIME de RESET pBufferSpell: dan qua roi ko can ne' nua
			{
				//__oMsg("SAU: =2= GAN-90* : nTime_StartPoint2Evade(time-ne):[%.2f] <= nTimer[%.2f]", nTime_StartPoint2Evade*1000, pBufferSpell->nTimer);
				fPtrRESET(pBufferSpell->index);
				UnBlockMove();
				return FALSE;
			}
			goto START_EVADE;
		}
		if(nTime_StartPoint2Evade >= pBufferSpell->nSpecialTimer)// Doan dan bay luc nay chua can ne'
		{
			//__oMsg("=1= XA-90* : nTime_StartPoint2Evade(ko-ne):[%.2f] >= nSpecialTimer[%.2f]", nTime_StartPoint2Evade*1000, pBufferSpell->nSpecialTimer);
			RESET_BUFFER_SPELL_SPECIAL(pBufferSpell->index);
			return FALSE;
		}
		float deltaTSub = 1000.0;
		if(CheckName( (sz__Jinx), pBufferSpell->szHeroName) && nKC_StartPoint2Player > 9000.0) deltaTSub = 1600.0;
		if (nTime_EvadePoint2Player*1000 <= pBufferSpell->nTimer || (nTime_StartPoint2Player*1000 + pBufferSpell->nDelay - deltaTSub) < pBufferSpell->nSpecialTimer)// Check TIME de RESET pBufferSpell: dan qua roi ko can ne' nua
		{
			//__oMsg("=2= XA-90* : nTime_EvadePoint2Player(time-ne):[%.2f] <= nTimer[%.2f]", nTime_EvadePoint2Player*1000, pBufferSpell->nTimer);
			fPtrRESET(pBufferSpell->index);
			UnBlockMove();
			return FALSE;
		}
		goto START_EVADE;
	}
	//================ END =============================================================================
	nTime = nDistance/pBufferSpell->nMissileSpeed;
	float nDelta = 150.0;
	if(nTime*1000 + pBufferSpell->nDelay > 1400.0) nDelta = 300.0;
	if ((nTime*1000 + pBufferSpell->nDelay) <= pBufferSpell->nTimer - nDelta)      // Check TIME de RESET pBufferSpell: dan qua roi ko can ne' nua
	{
		fPtrRESET(pBufferSpell->index);
		//__oMsg("========= UnBlockMove() ==> SKILL binh thuong ============");
		//__oMsg("goi unblock:%d, %s", __LINE__, __FILE__);
		UnBlockMove();
		return FALSE;
	}
	//__oMsg("nDistance =%f; nTIme = %f - KC:%f", nDistance, nTime, nKhoangCach);
	//================ END =============================================================================
START_EVADE:
	//__oMsg("bat dau ne roi:%d;%s", __LINE__, __FILE__);
	if(nKhoangCach >= pBufferSpell->nRadius  + 160.0)
	{
		UnBlockMove();
	}
	
	//--- cho them doan nay : dang combo se ko ne nhung skill ko nguy hiem --------------------------------------
	if(g_bNormalAttackHero && pBufferSpell->nIsDangerous == false)
	{
		UnBlockMove();
		return FALSE;
	}

	if (IS_INLINE(pPlayer, startPoint, endPoint, pBufferSpell) == false)  // Check PLAYER co nam trong duong dan. hay ko
	{
		if(g_bNormalAttackHero)
		{
			UnBlockMove();
			return FALSE;
		}
		if (pBufferSpell->IsEvaded == false) return FALSE;
		//if(nKhoangCach >= pBufferSpell->nRadius  + 120.0) return FALSE;
		KPos diemVuongGoc_Mouse;
		KPos diemVuongGoc_Player; // diem nay lay tu pBufferSpell, diem nay luon co dinh
		GIAO_DIEM_VUONG_GOC(diemVuongGoc_Mouse, *startPoint, *endPoint, pBufferSpell->MousePos_Player);
		GIAO_DIEM_VUONG_GOC(diemVuongGoc_Player, *startPoint, *endPoint, pBufferSpell->PlayerPos);
		float KC_Player2Mouse  = Distance_2D(diemVuongGoc_Player, diemVuongGoc_Mouse);
		//__oMsg("[...]=========== 0: KC_Player2Mouse : %.2f", KC_Player2Mouse);
		KPos* EXTRA_MOVE_POS = new KPos;
		if(KC_Player2Mouse > 1650.0)
		{
			EXTRA_MOVE_POS = GET_EVADE_EXTRA(*startPoint, *endPoint, *pBufferSpell, 250.0);
			if(!EXTRA_MOVE_POS) return FALSE;
			BlockMove();
			MOVE_TO(EXTRA_MOVE_POS->x, EXTRA_MOVE_POS->z);

			//KPos diemVuongGoc_1;
			//GIAO_DIEM_VUONG_GOC(diemVuongGoc_1, *startPoint, *endPoint, *EXTRA_MOVE_POS);
			//float nKhoangCach_1 = Distance_2D(diemVuongGoc_1, *EXTRA_MOVE_POS);

			//KPos diemVuongGoc_EVADE;
			//GIAO_DIEM_VUONG_GOC(diemVuongGoc_EVADE, *startPoint, *endPoint, *EXTRA_MOVE_POS);
			//float nKhoangCach_b = Distance_2D(diemVuongGoc_EVADE, *EXTRA_MOVE_POS);

			//__oMsg("[...]=========== 1: 280.0 ==============: %.2f - %.2f ==> KCVCC: %.2f - %.2f", EXTRA_MOVE_POS->x, EXTRA_MOVE_POS->z, nKhoangCach_1,nKhoangCach_b);
			return FALSE;
		}
		else if(KC_Player2Mouse > 1250.0)
		{
			EXTRA_MOVE_POS = GET_EVADE_EXTRA(*startPoint, *endPoint, *pBufferSpell, 200.0);
			if(!EXTRA_MOVE_POS) return FALSE;
			BlockMove();
			MOVE_TO(EXTRA_MOVE_POS->x, EXTRA_MOVE_POS->z);

			//KPos diemVuongGoc_2;
			//GIAO_DIEM_VUONG_GOC(diemVuongGoc_2, *startPoint, *endPoint, *EXTRA_MOVE_POS);
			//float nKhoangCach_2 = Distance_2D(diemVuongGoc_2, *EXTRA_MOVE_POS);


			//__oMsg("[...]=========== 2: 220.0 ==============: %.2f - %.2f ==> KC: %.2f", EXTRA_MOVE_POS->x, EXTRA_MOVE_POS->z, nKhoangCach_2);
			return FALSE;
		}
		else if(KC_Player2Mouse > 800.0)
		{
			EXTRA_MOVE_POS = GET_EVADE_EXTRA(*startPoint, *endPoint, *pBufferSpell, 150.0);
			if(!EXTRA_MOVE_POS) return FALSE;
			BlockMove();
			MOVE_TO(EXTRA_MOVE_POS->x, EXTRA_MOVE_POS->z);

			//KPos diemVuongGoc_3;
			//GIAO_DIEM_VUONG_GOC(diemVuongGoc_3, *startPoint, *endPoint, *EXTRA_MOVE_POS);
			//float nKhoangCach_3 = Distance_2D(diemVuongGoc_3, *EXTRA_MOVE_POS);


			//__oMsg("[...]=========== 3: 160.0 ==============: %.2f - %.2f ==> KC: %.2f", EXTRA_MOVE_POS->x, EXTRA_MOVE_POS->z, nKhoangCach_3);
			return FALSE;
		}
		//__oMsg("[...]=========== 4: 90.D0 BT ==============: %.2f - %.2f ", EXTRA_MOVE_POS->x, EXTRA_MOVE_POS->z);

		return FALSE;
	}

	countBiDanhBoiSkillDinhHuong = 1;
	//float R = (radius + g_pPlayer->nOverrideCollisionRadius + 30.);
	float R  = (pBufferSpell->nRadius  + 180);
	if (CheckName( (sz__LucianR), pBufferSpell->szSpellName)) R = (pBufferSpell->nRadius  + 220);
	//__oMsg("******* CollisionRadius = %f", pPlayer->nOverrideCollisionRadius);
	//if(CO_HIT_RUN || CO_HARASS || CO_TUNG SKILL) R = (pBufferSpell->nRadius  + 120.0);
	if(pBufferSpell->nDangerValue == 5) R = (pBufferSpell->nRadius  + 250);

	float dX = endPoint->x - startPoint->x;
	float dZ = endPoint->z - startPoint->z;
	float player_x = pPlayer->CurrentPos.x;
	float player_z = pPlayer->CurrentPos.z;
	float C1       = dZ*startPoint->x - dX*startPoint->z;
	float C2    = dX*player_x + dZ*player_z;

	float calc1    = sqrt(dZ*dZ + dX*dX);
	//-----------------------------------
	KPos tmpPos0, tmpstartPoint, tmpendPoint;
	int Nghiem_0  = NghiemHePTBacNhat(tmpPos0,dZ, -dX, C1, dX, dZ, C2); // giao diem cua (1) va (2)
	if (!Nghiem_0)  return FALSE;
	float x_0  =  tmpPos0.x;
	float z_0  =  tmpPos0.z;
	//-----------------------------------
	float C4_1 = dZ*x_0 - dX*z_0 - R*calc1;
	float C4_2 = dZ*x_0 - dX*z_0 + R*calc1; 

	int  Nghiem1  = NghiemHePTBacNhat(tmpstartPoint,dZ, -dX, C4_1, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem1)  return FALSE;
	float dodge1_x  = tmpstartPoint.x;
	float dodge1_z  = tmpstartPoint.z;
	//-----------------------------------
	int  Nghiem2  = NghiemHePTBacNhat(tmpendPoint,dZ, -dX, C4_2, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem2)  return FALSE;
	float dodge2_x  = tmpendPoint.x;
	float dodge2_z  = tmpendPoint.z;
	//-----------------------------------
	KPos dodge;
	float kc1 = sqrt((player_x - dodge1_x)*(player_x - dodge1_x) + (player_z - dodge1_z)*(player_z - dodge1_z));
	float kc2 = sqrt((player_x - dodge2_x)*(player_x - dodge2_x) + (player_z - dodge2_z)*(player_z - dodge2_z));
	if (kc1 < kc2){
		dodge.x = dodge1_x;
		dodge.z = dodge1_z;
	}
	else {
		dodge.x = dodge2_x;
		dodge.z = dodge2_z;
	}
	//----------------------------

	return TRUE;
}
//==================================================================================//
//==================================================================================//
//==================================================================================//
bool EVADE_LINE_45DO(KPos* startPoint,KPos* endPoint, KBuffer_Spell* pBufferSpell, int nTienLui, fPtrRESET_DATA_SPELL fPtrRESET, bool nSpecial)
{
	//dZ.x - dX.z  = C1 = dZ*pos1.x - dX*pos1.z  (1)(d)
	//dX.x + dZ.z  = C2 = dX*player_x + dZ*player_z (2)(vuong goc voi d, di qua player)
	//dZ.x - dX.z  = C3 = dZ.player_x - dX.player_z (3)(song song voi d + di qua player)
	//dZ.x - dX.z  = C5   = dZ.dodge_x  - dX.dodge_z  (4)(song song voi d + di qua dodge)
	//==>C4 = dZ.x_0 - dX.y_0 - R*calc1
	//==>C4 = dZ.x_0 - dX.y_0 + R*calc1
	//PG cua (2) va (3) : ------------------------------------------------------------------------------
	//dX.x + dZ.z  - C2 = dZ.x - dX.z  - C3  => (dX-dZ).x + (dZ+dX).z = C2-C3  (PG1)
	//dX.x + dZ.z  - C2 = -(dZ.x - dX.z  - C3)  => (dX+dZ).x + (dZ-dX).z = C2+C3 (PG2)
	//--------------------------------------------------------------------------------------------------

	if (pBufferSpell == NULL) return FALSE;
	
	//if (nSPELLDATA->IsDangerous == true){if(nut DODGE DANGEROUS dc ko bat}...   // nut DODGE DANGEROUS: xu ly voi chieu nguy hiem
	//================ DOAN NAY TINH TOAN TIME DAN BAY QUA VI TRI PLAYER DUNG ================ :
	// - con` truong hop dan ko bay ma den luon nhu LUX_R, truong hop dan bay xuyen ban do nhu EZREAL_R.. : ...
	KNpc *pPlayer = GetPlayer();
	KPos diemVuongGoc;
	GIAO_DIEM_VUONG_GOC(diemVuongGoc, *startPoint, *endPoint, pPlayer->CurrentPos);
	float nDistance = Distance_2D(diemVuongGoc, *startPoint);
	//__oMsg("====== 45* : XX_nSpecialTimer[%.2f] -- XX_nTimer[%.2f], ===[nDistance: %.2f]", pBufferSpell->nSpecialTimer, pBufferSpell->nTimer,nDistance);
	float nKhoangCach = Distance_2D(diemVuongGoc, pPlayer->CurrentPos);
	float nTime = 0;
	if(nSpecial == true)
	{
		float nKC_StartPoint2Player   = Distance_2D(diemVuongGoc, *startPoint);    // KC tu StartPoint-> den pPlayer
		float nTime_StartPoint2Player = nKC_StartPoint2Player/pBufferSpell->nMissileSpeed; // tgian dan bay tu diem start' -> den pPlayer
		if(CheckName( (sz__Jinx), pBufferSpell->szHeroName) && nKC_StartPoint2Player > 14000)  nTime_StartPoint2Player = nKC_StartPoint2Player/2200;
		float nKC_EvadePoint2Player = 7500;             // KC bat dau ne'(cai nay can check ki hon voi tung con)
		if(CheckName( (sz__Ashe), pBufferSpell->szHeroName)) nKC_EvadePoint2Player = 7000;
		if(CheckName( (sz__Jinx), pBufferSpell->szHeroName)) nKC_EvadePoint2Player = 7000;
		float nTime_EvadePoint2Player = nKC_EvadePoint2Player/pBufferSpell->nMissileSpeed;  // tgian dan bay tu diem can ne'-> den pPlayer(thuong dao dong tu 0.7->0.8 giay)
		if(CheckName( (sz__Jinx), pBufferSpell->szHeroName) && nKC_StartPoint2Player > 14000)  nTime_EvadePoint2Player = nKC_EvadePoint2Player/2200;
		/*if (nKC_StartPoint2Player >= 1.4 * nKC_EvadePoint2Player && g_TimeSpecial == false)
		{
			g_TimeSpecial = true;
			nTime_EvadePoint2Player += 0.8;
		}*/
		float nTime_StartPoint2Evade  = nTime_StartPoint2Player*1000 + pBufferSpell->nDelay - nTime_EvadePoint2Player*1000; // tgian dan bay tu StartPoint -> den diem can ne'
		if(nKC_StartPoint2Player < nKC_EvadePoint2Player) // KC GAN
		{
			float nTime_3 = nTime_StartPoint2Player + pBufferSpell->nDelay/1000; // Tong time tu start -> den pPlayer:bao gom time_delay cast + time dan bay 
			nTime_StartPoint2Evade = nTime_StartPoint2Player + pBufferSpell->nDelay/1000;
			if(nTime_StartPoint2Evade > 2)
			{
				nTime_StartPoint2Evade = 2;  // toi da chi cho ne trong 2.0 giay
				if (CheckName( (sz__Jinx), pBufferSpell->szHeroName)) nTime_StartPoint2Evade = (float)2.4;
			}

			if((nTime_3 - nTime_StartPoint2Evade)*1000 > pBufferSpell->nSpecialTimer) // Doan dan bay luc nay chua can ne'
			{
				//__oMsg("=1= GAN-45* : KO_NE(ko-ne):[%.2f] >= nSpecialTimer[%.2f]", (nTime_3 - nTime_StartPoint2Evade)*1000, pBufferSpell->nSpecialTimer);
				RESET_BUFFER_SPELL_SPECIAL(pBufferSpell->index);
				return FALSE;
			}
			//__oMsg("TRUOC: =2= GAN-45* : nTime_StartPoint2Evade(time-ne):[%.2f] <= nTimer[%.2f]", nTime_StartPoint2Evade*1000, pBufferSpell->nTimer);
			if (nTime_StartPoint2Evade*1000 <= pBufferSpell->nTimer ||(nTime_StartPoint2Player*1000 + pBufferSpell->nDelay - 500.0) < pBufferSpell->nSpecialTimer)      // Check TIME de RESET pBufferSpell: dan qua roi ko can ne' nua
			{
				//__oMsg("SAU: =2= GAN-45* : nTime_StartPoint2Evade(time-ne):[%.2f] <= nTimer[%.2f]", nTime_StartPoint2Evade*1000, pBufferSpell->nTimer);
				fPtrRESET(pBufferSpell->index);
				UnBlockMove();
				return FALSE;
			}
			goto START_EVADE;
		}
		//__oMsg("TRUOC=1= XA-45* : nTime_StartPoint2Evade(ko-ne):[%.2f] >= nSpecialTimer[%.2f]", nTime_StartPoint2Evade*1000, pBufferSpell->nSpecialTimer);
		if(nTime_StartPoint2Evade >= pBufferSpell->nSpecialTimer)		// Doan dan bay luc nay chua can ne'
		{
			//__oMsg("=1= XA-45* : nTime_StartPoint2Evade(ko-ne):[%.2f] >= nSpecialTimer[%.2f]", nTime_StartPoint2Evade*1000, pBufferSpell->nSpecialTimer);
			RESET_BUFFER_SPELL_SPECIAL(pBufferSpell->index);
			return FALSE;
		}
		float deltaTSub = 1000.0;
		if(CheckName( (sz__Jinx), pBufferSpell->szHeroName) && nKC_StartPoint2Player > 9000.0) deltaTSub = 1600.0;
		if (nTime_EvadePoint2Player*1000 <= pBufferSpell->nTimer ||(nTime_StartPoint2Player*1000 + pBufferSpell->nDelay - deltaTSub) < pBufferSpell->nSpecialTimer)      // Check TIME de RESET pBufferSpell: dan qua roi ko can ne' nua
		{
			//__oMsg("=2= XA-45* : nTime_EvadePoint2Player(time-ne):[%.2f] <= nTimer[%.2f]", nTime_EvadePoint2Player*1000, pBufferSpell->nTimer);
			fPtrRESET(pBufferSpell->index);
			UnBlockMove();
			return FALSE;
		}
		goto START_EVADE;
	}
	//================ END =============================================================================

	nTime = nDistance/pBufferSpell->nMissileSpeed;
	float nDelta = 150.0;
	if(nTime*1000 + pBufferSpell->nDelay > 1400.0) nDelta = 300.0;
	if ((nTime*1000 + pBufferSpell->nDelay) <= pBufferSpell->nTimer - nDelta)      // Check TIME de RESET pBufferSpell: dan qua roi ko can ne' nua
	{
		fPtrRESET(pBufferSpell->index);
		UnBlockMove();
		return FALSE;
	}
	//================ END =============================================================================
START_EVADE:
	if(nKhoangCach >= pBufferSpell->nRadius  + 160.0)
	{
		UnBlockMove();
	}

	//--- cho them doan nay : dang combo se ko ne nhung skill ko nguy hiem --------------------------------------
	if(g_bNormalAttackHero && pBufferSpell->nIsDangerous == false)
	{
		UnBlockMove();
		return FALSE;
	}

	if (IS_INLINE(pPlayer, startPoint, endPoint, pBufferSpell) == false)  // Check PLAYER co nam trong duong dan. hay ko
	{
		//if(g_bNormalAttackHero)
		//{
		//	UnBlockMove();
		//}
		return FALSE;
	}

//--- moi them ---------------------------------------
	countBiDanhBoiSkillDinhHuong = 1;
	KBuffs* pBuffBlackShield = GET_BUFF(pPlayer, "BlackShield");
	if(pBuffBlackShield && pBuffBlackShield->nEnd_Time - GetTimeGame() > 0.3) return false;
	
	KBuffs* pBuffSivirE = GET_BUFF(pPlayer, "SivirE");

	
	
	if(pBuffSivirE && pBuffBlackShield->nEnd_Time - GetTimeGame() > 0.3) return false;

	//float R = (radius + g_pPlayer->nOverrideCollisionRadius + 30.);
	float R  = (pBufferSpell->nRadius  + 180);
	//__oMsg("******* CollisionRadius = %f", pPlayer->nOverrideCollisionRadius);
	if(pBufferSpell->nDangerValue == 5) R = (pBufferSpell->nRadius  + 250);

	float dX = endPoint->x - startPoint->x;
	float dZ = endPoint->z - startPoint->z;
	float player_x = pBufferSpell->PlayerPos.x;
	float player_z = pBufferSpell->PlayerPos.z;
	float C1       = dZ*startPoint->x - dX*startPoint->z;
	float C2      = dX*player_x + dZ*player_z;
	float C3     = dZ*player_x - dX*player_z;
	float C5;
	float PG_1 = C2-C3;
	float PG_2 = C2+C3;

	float calc1    = sqrt(dZ*dZ + dX*dX);
	//-----------------------------------
	KPos tmpPos0, tmpPos1, tmpPos2;
	int Nghiem_0  = NghiemHePTBacNhat(tmpPos0,dZ, -dX, C1, dX, dZ, C2); // giao diem cua (1) va (2)
	if (!Nghiem_0)  return FALSE;
	float x_0  =  tmpPos0.x;
	float z_0  =  tmpPos0.z;
	//-----------------------------------
	float C4_1 = dZ*x_0 - dX*z_0 - R*calc1;
	float C4_2 = dZ*x_0 - dX*z_0 + R*calc1; 

	int  Nghiem1  = NghiemHePTBacNhat(tmpPos1,dZ, -dX, C4_1, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem1)  return FALSE;
	float dodge1_x  = tmpPos1.x;
	float dodge1_z  = tmpPos1.z;
	//-----------------------------------
	int  Nghiem2  = NghiemHePTBacNhat(tmpPos2,dZ, -dX, C4_2, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem2)  return FALSE;
	float dodge2_x  = tmpPos2.x;
	float dodge2_z  = tmpPos2.z;
	//-----------------------------------
	float kc1 = sqrt((player_x - dodge1_x)*(player_x - dodge1_x) + (player_z - dodge1_z)*(player_z - dodge1_z));
	float kc2 = sqrt((player_x - dodge2_x)*(player_x - dodge2_x) + (player_z - dodge2_z)*(player_z - dodge2_z));

	float dodge_x,dodge_z;
	if (kc1 < kc2){
		dodge_x = dodge1_x;
		dodge_z = dodge1_z;
	}
	else {
		dodge_x = dodge2_x;
		dodge_z = dodge2_z;
	}
	//----------------------------
	C5       = dZ*dodge_x  - dX*dodge_z;          // duong thang song song voi (d) va di qua dodge 
	int  rc1 = NghiemHePTBacNhat(tmpPos1,dZ, -dX, C5, (dX-dZ), (dZ+dX), PG_1); // giao diem cua (4) va (PG1)
	if (!rc1) return FALSE;

	float evade1_x = tmpPos1.x;
	float evade1_z = tmpPos1.z;

	int rc2 = NghiemHePTBacNhat(tmpPos2,dZ, -dX, C5, (dX+dZ), (dZ-dX), PG_2); // giao diem cua (4) va (PG2)
	if (!rc2)  return FALSE;

	//----------------------------
	KPos evade;

	if(nTienLui == -1)   // NE 45DO LUI
	{
		float tichvohuong_1 = (dX*evade1_x + dZ*evade1_z - C2)*(dX*startPoint->x + dZ*startPoint->z - C2); // xet evade1 va startPoint so voi duong (2)
		if(tichvohuong_1>0){                 // -> evade1 va pos1 cung huong so voi duong (2)
			evade = tmpPos2;
		}
		else{                     // -> evade1 va pos1 nguoc huong so voi duong (2)
			evade = tmpPos1;
		}
	}
	if(nTienLui == 1)   // NE 45DO TIEN
	{
		float tichvohuong_1 = (dX*evade1_x + dZ*evade1_z - C2)*(dX*startPoint->x + dZ*startPoint->z - C2); // xet evade1 va startPoint so voi duong (2)
		if(tichvohuong_1>0){                 // -> evade1 va pos1 cung huong so voi duong (2)
			evade = tmpPos1;
		}
		else{                     // -> evade1 va pos1 nguoc huong so voi duong (2)
			evade = tmpPos2;
		}
	}

	
	return TRUE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IS_INLINE(KNpc *pNpc, KPos *startPoint,KPos *endPoint, KBuffer_Spell *pBufferSpell, bool isHasMinion)  //dZ.x - dX.z  = C1 = dZ*pos1.x - dX*pos1.z  (1)(d)
{                                                                //dX.x + dZ.z  = C2 = dX*player_x + dZ*player_z (2)(vuong goc voi d)
	float Range = (pBufferSpell->nRange + 120);     //thu 120.0 xem sao
	float R  = (pBufferSpell->nRadius  + 120);
	if (isHasMinion) R  = (pBufferSpell->nRadius  + 90);
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
	if(!pBufferSpell->nFlag_TruocSau && tichvohuong < 0) return FALSE;

	return TRUE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int COUNT_NPC_INLINE(KPos *startPoint,KPos *endPoint, KBuffer_Spell *pBufferSpell, float nKhoangCach)
{
	int nCountNPC = 0;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
	DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
	if (!dw1 || !dw2 ) return 0;
	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	BYTE isDied = (BYTE)pPlayer->nIsDie;
	if (isDied != 0) return 0;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pNpc = (KNpc*)dw3;
		int isDie = (BYTE)pNpc->nIsDie;
		if (!pNpc->IsAlly(pPlayer->nTeam_ID) || isDie == 1 || pNpc->nHP <= 0. || !pNpc->IsMinion())
			continue;
		if ((BYTE)pNpc->nIsTargetableToTeam != 4) continue;
		if (CheckName( (sz__Minion), pNpc->GetNameNpc()) == false) continue;
		if (IS_INLINE(pNpc, startPoint,endPoint, pBufferSpell, true))
		{
			KPos diemVuongGoc1;   // diem vuong goc cua Player chieu xuong duong thang skill
			GIAO_DIEM_VUONG_GOC(diemVuongGoc1, *startPoint, *endPoint, pPlayer->CurrentPos);
			float nDistance1 = Distance_2D(diemVuongGoc1, *startPoint);

			KPos diemVuongGoc2;   // diem vuong goc cua NPC chieu xuong duong thang skill
			GIAO_DIEM_VUONG_GOC(diemVuongGoc2, *startPoint, *endPoint, pNpc->CurrentPos);
			float nDistance2 = Distance_2D(diemVuongGoc2, *startPoint);
			if (nDistance1 - nDistance2 > nKhoangCach) nCountNPC += 1;
		}

	}
	//__oMsg("******* nCountNPC = %d *********", nCountNPC);
	return nCountNPC;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IsShouldDodge(KPos *startPoint,KPos *endPoint, KBuffer_Spell *pBufferSpell)
{
	if(pBufferSpell->nDangerValue == 5) return TRUE;
	KNpc *pPlayer = GetPlayer();
	KPos diemVuongGoc;
	GIAO_DIEM_VUONG_GOC(diemVuongGoc, *startPoint, *endPoint, pBufferSpell->PlayerPos);
	float nDistance = Distance_2D(diemVuongGoc, *startPoint);
	float nTime = 0;
	nTime = nDistance/pBufferSpell->nMissileSpeed;

	float R  = (pBufferSpell->nRadius  + 100);

	float dX = endPoint->x - startPoint->x;
	float dZ = endPoint->z - startPoint->z;
	float player_x = pBufferSpell->PlayerPos.x;
	float player_z = pBufferSpell->PlayerPos.z;
	float C1       = dZ*startPoint->x - dX*startPoint->z;
	float C2    = dX*player_x + dZ*player_z;

	float calc1    = sqrt(dZ*dZ + dX*dX);
	//-----------------------------------
	KPos tmpPos0, tmpStartPoint, tmpEndPoint;
	int Nghiem_0  = NghiemHePTBacNhat(tmpPos0,dZ, -dX, C1, dX, dZ, C2); // giao diem cua (1) va (2)
	if (!Nghiem_0)  return FALSE;
	float x_0  =  tmpPos0.x;
	float z_0  =  tmpPos0.z;
	//-----------------------------------
	float C4_1 = dZ*x_0 - dX*z_0 - R*calc1;
	float C4_2 = dZ*x_0 - dX*z_0 + R*calc1; 

	int  Nghiem1  = NghiemHePTBacNhat(tmpStartPoint,dZ, -dX, C4_1, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem1)  return FALSE;
	KPos dodge1 = tmpStartPoint;
	//-----------------------------------
	int  Nghiem2  = NghiemHePTBacNhat(tmpEndPoint,dZ, -dX, C4_2, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem2)  return FALSE;
	KPos dodge2 = tmpEndPoint;
	//-----------------------------------
	KPos dodge;
	float kc1 = Distance_2D(pBufferSpell->PlayerPos, dodge1);
	float kc2 = Distance_2D(pBufferSpell->PlayerPos, dodge2);
	float nTimeMove2Safe = 0;
	if (kc1 < kc2){
		nTimeMove2Safe = kc1 / pPlayer->nMoveSpeed;
	}
	else {
		nTimeMove2Safe = kc2 / pPlayer->nMoveSpeed;
	}
	//__oMsg("90DO --- tg dan bay = %f; tg di chuyen = %f", nTime*1000 + pBufferSpell->nDelay, nTimeMove2Safe * 1000);
	//__oMsg("90DO --- VuongGoc =%f; kc1 = %f, kc2 = %f; TD=%f",nDistance, kc1, kc2, pPlayer->nMoveSpeed);
	if ((nTime*1000 + pBufferSpell->nDelay + 150) >= (nTimeMove2Safe * 1000))
	{
		return TRUE;
	}
	return FALSE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IsShouldDodge_45Do(KPos* startPoint,KPos* endPoint, KBuffer_Spell* pBufferSpell, int nTienLui)
{
	if(pBufferSpell->nDangerValue == 5) return TRUE;
	KNpc *pPlayer = GetPlayer();
	float R  = (pBufferSpell->nRadius  + 100);
	float dX = endPoint->x - startPoint->x;
	float dZ = endPoint->z - startPoint->z;
	float player_x = pBufferSpell->PlayerPos.x;	
	float player_z = pBufferSpell->PlayerPos.z;
	float C1       = dZ*startPoint->x - dX*startPoint->z;
	float C2       = dX*player_x + dZ*player_z;
	float C3       = dZ*player_x - dX*player_z;
	float C5;
	float PG_1 = C2-C3;
	float PG_2 = C2+C3;

	float calc1    = sqrt(dZ*dZ + dX*dX);
	//-----------------------------------
	KPos tmpPos0, tmpPos1, tmpPos2;
	int Nghiem_0  = NghiemHePTBacNhat(tmpPos0,dZ, -dX, C1, dX, dZ, C2); // giao diem cua (1) va (2)
	if (!Nghiem_0)  return FALSE;
	float x_0  =  tmpPos0.x;
	float z_0  =  tmpPos0.z;
	//-----------------------------------
	float C4_1 = dZ*x_0 - dX*z_0 - R*calc1;
	float C4_2 = dZ*x_0 - dX*z_0 + R*calc1; 

	int  Nghiem1  = NghiemHePTBacNhat(tmpPos1,dZ, -dX, C4_1, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem1)  return FALSE;
	float dodge1_x  = tmpPos1.x;
	float dodge1_z  = tmpPos1.z;
	//-----------------------------------
	int  Nghiem2  = NghiemHePTBacNhat(tmpPos2,dZ, -dX, C4_2, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem2)  return FALSE;
	float dodge2_x  = tmpPos2.x;
	float dodge2_z  = tmpPos2.z;
	//-----------------------------------
	float kc1 = sqrt((player_x - dodge1_x)*(player_x - dodge1_x) + (player_z - dodge1_z)*(player_z - dodge1_z));
	float kc2 = sqrt((player_x - dodge2_x)*(player_x - dodge2_x) + (player_z - dodge2_z)*(player_z - dodge2_z));

	float dodge_x,dodge_z;
	if (kc1 < kc2){
		dodge_x = dodge1_x;
		dodge_z = dodge1_z;
	}
	else {
		dodge_x = dodge2_x;
		dodge_z = dodge2_z;
	}
	//----------------------------
	C5       = dZ*dodge_x  - dX*dodge_z;          // duong thang song song voi (d) va di qua dodge 
	int  rc1 = NghiemHePTBacNhat(tmpPos1,dZ, -dX, C5, (dX-dZ), (dZ+dX), PG_1); // giao diem cua (4) va (PG1)
	if (!rc1) return FALSE;

	float evade1_x = tmpPos1.x;
	float evade1_z = tmpPos1.z;

	int rc2 = NghiemHePTBacNhat(tmpPos2,dZ, -dX, C5, (dX+dZ), (dZ-dX), PG_2); // giao diem cua (4) va (PG2)
	if (!rc2)  return FALSE;

	//----------------------------
	KPos evade;
	KPos diemVuongGoc;

	if(nTienLui == -1)   // NE 45DO LUI XA DICH
	{
		float tichvohuong_1 = (dX*evade1_x + dZ*evade1_z - C2)*(dX*startPoint->x + dZ*startPoint->z - C2); // xet evade1 va pos1 so voi duong (2)
		if(tichvohuong_1>0){                 // -> evade1 va pos1 cung huong so voi duong (2)
			evade = tmpPos2;
		}
		else{                     // -> evade1 va pos1 nguoc huong so voi duong (2)
			evade = tmpPos1;
		}
		GIAO_DIEM_VUONG_GOC(diemVuongGoc, *startPoint, *endPoint, pBufferSpell->PlayerPos);
	}
	if(nTienLui == 1)   // NE 45DO TIEN LAI GAN DICH
	{
		float tichvohuong_1 = (dX*evade1_x + dZ*evade1_z - C2)*(dX*startPoint->x + dZ*startPoint->z - C2); // xet evade1 va pos1 so voi duong (2)
		if(tichvohuong_1>0){                 // -> evade1 va pos1 cung huong so voi duong (2)
			evade = tmpPos1;
		}
		else{                     // -> evade1 va pos1 nguoc huong so voi duong (2)
			evade = tmpPos2;
		}
		GIAO_DIEM_VUONG_GOC(diemVuongGoc, *startPoint, *endPoint, evade);
	}
	float nDistance = Distance_2D(diemVuongGoc, *startPoint);
	float nTime = 0.0;
	nTime = nDistance/pBufferSpell->nMissileSpeed;

	float nKhoangCanhNe = Distance_2D(pBufferSpell->PlayerPos, evade); 
	float nTimeMove2Safe = nKhoangCanhNe/pPlayer->nMoveSpeed;

	//__oMsg("45DO__VuongGoc =%.2f; TG dan bay = %.2f, TG di = %.2f",nDistance, nTime*1000 + pBufferSpell->nDelay - 80.0, nTimeMove2Safe * 1000);
	if ((nTime*1000 + pBufferSpell->nDelay  + 100) > (nTimeMove2Safe * 1000))
	{
		return TRUE;
	}

	////__oMsg("[////////]T1 = %f, T2 = %f, tg di = %f", g_TimePrevious*1000, g_TimeNow*1000, nTimeMove2Safe*1000);
	//g_TimePrevious = (bool)g_TimeNow ? g_TimeNow : nTimeMove2Safe;//???????????????
	//g_TimeNow = nTimeMove2Safe;
	////__oMsg("T1 = %f, T2 = %f, tg di = %f", g_TimePrevious*1000, g_TimeNow*1000, nTimeMove2Safe*1000);
	//float delta_T = g_TimePrevious - g_TimeNow;
	//__oMsg("45DO__VuongGoc =%f.2; tg bay = %.0f, tg di = %.0f",nDistance, nTime*1000 + pBufferSpell->nDelay - delta_T*1000, nTimeMove2Safe * 1000);
	////__oMsg("deltaTime=%.0f", delta_T*1000);
	//if ((nTime*1000 + pBufferSpell->nDelay - delta_T*1000 - 20) >= (nTimeMove2Safe * 1000))
	//{
	//	return TRUE;
	//}
	return FALSE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool IsShouldCircle(KPos* posTam, KBuffer_Spell* pBufferSpell)
{
	if (pBufferSpell == NULL) return FALSE;

	KNpc *pPlayer = GetPlayer();
	float nDistance = Distance_2D(*posTam, pBufferSpell->SourcePos);
	float nTime = 0.0;
	nTime = nDistance/pBufferSpell->nMissileSpeed;
	//----------------------------------------------------------------
	//----------------------------------------------------------------
	float player_x = pBufferSpell->PlayerPos.x;
	float player_z = pBufferSpell->PlayerPos.z;
	float R		   = (pBufferSpell->nRadius + 100);
	float dX	   = player_x - posTam->x;
	float dZ	   = player_z - posTam->z;

	float C1	   = dZ*posTam->x - dX*posTam->z;			//(1) la duong thang di qua posTam & pPlayer
	float C2	   = dX*posTam->x + dZ*posTam->z;			//(2) la duong thang di qua posTam & vuong goc voi (1)

	float calc1    = sqrt(dZ*dZ + dX*dX);
	//---------------------------
	KPos tmpPos0, tmpPos1, tmpPos2;
	//---------------------------
	float C4_1 = dX*posTam->x + dZ*posTam->z - R*calc1;
	float C4_2 = dX*posTam->x + dZ*posTam->z + R*calc1; 

	int  Nghiem1  = NghiemHePTBacNhat(tmpPos1,dX, dZ, C4_1, dZ, -dX, C1); //giao diem cua (1) va (4_1)
	if (!Nghiem1)  return FALSE;
	float dodge1_x  = tmpPos1.x;
	float dodge1_z  = tmpPos1.z;
	//---------------------------
	int  Nghiem2  = NghiemHePTBacNhat(tmpPos2,dX, dZ, C4_2, dZ, -dX, C1); //giao diem cua (1) va (4_2)
	if (!Nghiem2)  return FALSE;
	float dodge2_x  = tmpPos2.x;
	float dodge2_z  = tmpPos2.z;
	//---------------------------
	float kc1 = Distance_2D(player_x, player_z, dodge1_x, dodge1_z);
	float kc2 = Distance_2D(player_x, player_z, dodge2_x, dodge2_z);

	float dodge_theoTam_x,dodge_theoTam_z;		// diem ne tu posTam => pPlayer => dodge_theoTam(3 diem nay nam tren 1 duong thang, va cat duong tron)
	if (kc1 < kc2){
		dodge_theoTam_x = dodge1_x;
		dodge_theoTam_z = dodge1_z;
	}
	else {
		dodge_theoTam_x = dodge2_x;
		dodge_theoTam_z = dodge2_z;
	}
	//----------------------------------------------------------------
	dX = pBufferSpell->SourcePos.x - posTam->x;
	dZ = pBufferSpell->SourcePos.z - posTam->z;
	float D1 = dZ*posTam->x - dX*posTam->z;   //(a)duong thang di qua pBuff->Source va posTam		 : dZ*x - dX*z = D1 = dZ*posTam->x - dX*posTam->z;
	float D2 = dX*player_x  + dZ*player_z;	  //(b)duong thang di qua pPlayer va vuong goc voi (a)   : dX*x + dZ*z = D2 = dX*player_x  + dZ*player_z;
	float D3 = dZ*player_x  - dX*player_z;	  //(c)duong thang di qua pPlayer va song song voi (a)   : dZ*x - dX*z = D3 = dZ*player_x  - dX*player_z;
	float D4 = dX*posTam->x + dZ*posTam->z;	  //(e)duong thang di qua posTam va vuong goc voi (a)    : dX*x + dZ*z = D4 = dX*posTam->x  + dZ*posTam->z;
	//---------------------------------
	KPos *pos_diem1 = new KPos,*pos_diem2 = new KPos, *vuonggoc = new KPos;
	int  Nghiem0  = NghiemHePTBacNhat(tmpPos0,dX, dZ, D2, dZ, -dX, D1);  //giao diem cua (a) va (b)  : giao diem cua 2 duong thang vuong goc voi nhau 
	vuonggoc->x = tmpPos0.x;
	vuonggoc->z = tmpPos0.z;
	GiaoDiem_DuongTronVaDuongThang(pos_diem1, pos_diem2, vuonggoc, &pBufferSpell->PlayerPos, posTam, R);
	float dodge_theoVuongGoc_x,dodge_theoVuongGoc_z;					// diem ne theo duong thang vuong goc voi (a)

	// check pos_diem1 va g_pPlayer nam cung hay khac phia voi (a)
	float tichvohuong = (dZ*pos_diem1->x - dX*pos_diem1->z - D1)*(dZ*player_x - dX*player_z - D1);
	if(tichvohuong >= 0)		
	{
		dodge_theoVuongGoc_x = pos_diem1->x;
		dodge_theoVuongGoc_z = pos_diem1->z;
	}
	else
	{
		dodge_theoVuongGoc_x = pos_diem2->x;
		dodge_theoVuongGoc_z = pos_diem2->z;
	}
	//-----------------------------------------------------------------
	//tinh theo 1 diem nua: diem nay nam tren duong thang(e): vuong goc voi(a),di qua posTam va cat duong tron 
	KPos *pos_diemX = new KPos;
	int  NghiemX  = NghiemHePTBacNhat(tmpPos0,dX, dZ, D4, dZ, -dX, D3);  //giao diem cua (e) va (c)  : 2 duong thang nay cung vuong goc voi nhau
	pos_diemX->x = tmpPos0.x;
	pos_diemX->z = tmpPos0.z;
	GiaoDiem_DuongTronVaDuongThang(pos_diem1, pos_diem2, pos_diemX, posTam, posTam, R);
	float dodge_theoDiemMoi_x,dodge_theoDiemMoi_z;					// diem ne thuoc duong thang vuong (e) va cat duong tron
	// check pos_diem1 va g_pPlayer nam cung hay khac phia voi (a)
	tichvohuong = (dZ*pos_diem1->x - dX*pos_diem1->z - D1)*(dZ*player_x - dX*player_z - D1);
	if(tichvohuong >= 0)		
	{
		dodge_theoDiemMoi_x = pos_diem1->x;
		dodge_theoDiemMoi_z = pos_diem1->z;
	}
	else
	{
		dodge_theoDiemMoi_x = pos_diem2->x;
		dodge_theoDiemMoi_z = pos_diem2->z;
	}
	//----------------------------------------------------------------------------------------------------------------------------------
	float EVADE_x,EVADE_z;
	//----------------------------------------------------------------
	// check posTam va pBufferSpell->Source nam cung hay khac phia voi (b)
	float tichvohuong1 =  (dX*posTam->x + dZ*posTam->z - D2)*(dX*pBufferSpell->SourcePos.x + dZ*pBufferSpell->SourcePos.z - D2);
	if(tichvohuong1 <= 0)		// pPlayer nam giua posTam va pBufferSpell->SourcePos ( pPlayer dang gan tuong dich hon so voi posTam)
	{
		// check MousePos_Player va pBufferSpell->Source nam cung hay khac phia voi (b)
		float tichvohuong2 =  (dX*pBufferSpell->MousePos_Player.x + dZ*pBufferSpell->MousePos_Player.z - D2)*(dX*pBufferSpell->SourcePos.x + dZ*pBufferSpell->SourcePos.z - D2);
		if(tichvohuong2 <= 0)	// LUI XA DICH
		{
			float nTimeDanBay1 = (nTime*1000 + pBufferSpell->nDelay);
			float nDist_dichuyen_DiemMoi = Distance_2D(dodge_theoDiemMoi_x,dodge_theoDiemMoi_z, player_x, player_z);
			float nTime_dichuyen_DiemMoi = nDist_dichuyen_DiemMoi/pPlayer->nMoveSpeed;

			if(nTimeDanBay1 - 0.0 > nTime_dichuyen_DiemMoi*1000)
			{
				EVADE_x = dodge_theoDiemMoi_x;
				EVADE_z = dodge_theoDiemMoi_z;
			}
			else
			{
				EVADE_x = dodge_theoVuongGoc_x;
				EVADE_z = dodge_theoVuongGoc_z;
			}
		}
		else					// TIEN LAI GAN DICH
		{
			EVADE_x = dodge_theoTam_x;
			EVADE_z = dodge_theoTam_z;
		}
	}
	else						// posTam nam giua pPlayer va pBufferSpell->SourcePos ( pPlayer dang xa tuong dich hon so voi posTam)
	{
		// check MousePos_Player va pBufferSpell->Source nam cung hay khac phia voi (b)
		float tichvohuong2 =  (dX*pBufferSpell->MousePos_Player.x + dZ*pBufferSpell->MousePos_Player.z - D2)*(dX*pBufferSpell->SourcePos.x + dZ*pBufferSpell->SourcePos.z - D2);
		if(tichvohuong2 <= 0)	// LUI XA DICH
		{
			EVADE_x = dodge_theoTam_x;
			EVADE_z = dodge_theoTam_z;
		}
		else					// TIEN LAI GAN DICH
		{
			float nTimeDanBay1 = (nTime*1000 + pBufferSpell->nDelay);
			float nDist_dichuyen_DiemMoi = Distance_2D(dodge_theoDiemMoi_x,dodge_theoDiemMoi_z, player_x, player_z);
			float nTime_dichuyen_DiemMoi = nDist_dichuyen_DiemMoi/pPlayer->nMoveSpeed;

			if(nTimeDanBay1 - 0.0 > nTime_dichuyen_DiemMoi*1000)
			{
				EVADE_x = dodge_theoDiemMoi_x;
				EVADE_z = dodge_theoDiemMoi_z;
			}
			else
			{
				EVADE_x = dodge_theoVuongGoc_x;
				EVADE_z = dodge_theoVuongGoc_z;
			}
		}
	}
	//----------------------------------------------------------------
	KPos tempPos;
	if(dX == 0.0) 
	{
		tempPos.x = player_x;
		tempPos.z = 111.0;
	}
	else
	{
		tempPos.x = 1.0;
		tempPos.z = (dZ - D3)/dX ;
	}
	GiaoDiem_DuongTronVaDuongThang(pos_diem1, pos_diem2, &tempPos, &pBufferSpell->PlayerPos, posTam, R);
	float dodge_theoSongSong_x,dodge_theoSongSong_z;					// diem ne theo duong thang song song voi (a)
	// check MousePos_Player va pos_diem1 nam cung hay khac phia voi (b)
	tichvohuong =  (dX*pBufferSpell->MousePos_Player.x + dZ*pBufferSpell->MousePos_Player.z - D2)*(dX*pos_diem1->x + dZ*pos_diem1->z - D2);
	if(tichvohuong >= 0)		
	{
		dodge_theoSongSong_x = pos_diem1->x;
		dodge_theoSongSong_z = pos_diem1->z;
	}
	else
	{
		dodge_theoSongSong_x = pos_diem2->x;
		dodge_theoSongSong_z = pos_diem2->z;
	}
	//----------------------------------------------------------------
	float nTimeDanBay = (nTime*1000 + pBufferSpell->nDelay);
	float nDist_dichuyen_songsong = Distance_2D(dodge_theoSongSong_x,dodge_theoSongSong_z, player_x, player_z);
	float nTime_dichuyen_songsong = nDist_dichuyen_songsong/pPlayer->nMoveSpeed;
	//__oMsg("[1 TRUOC CHECK] === : TIME DI CHUYEN SONG SONG: %.2f",nTime_dichuyen_songsong*1000);
	if(nTimeDanBay - 0 > nTime_dichuyen_songsong*1000)
	{
		EVADE_x = dodge_theoSongSong_x;
		EVADE_z = dodge_theoSongSong_z;

		/*float nDist_Move2Safe = Distance_2D(EVADE_x,EVADE_z, player_x, player_z);
		float nTimeMove2Safe = nDist_Move2Safe/pPlayer->nMoveSpeed;
		__oMsg("[TRUOC CHECK] === SONG SONG : TIME DI CHUYEN SONG SONG: %.2f",nTimeMove2Safe*1000);*/
	}
	//----------------------------------------------------------------
	float nDist_Move2Safe = Distance_2D(EVADE_x,EVADE_z, player_x, player_z);
	float nTimeMove2Safe = nDist_Move2Safe/pPlayer->nMoveSpeed;
	//__oMsg("[CHECK] === CHECK ne CIRCLE: KC ne: %.2f - nTimeDanBay=%f, nTimeMove2Safe=%f",nDist_Move2Safe,  nTimeDanBay, nTimeMove2Safe*1000);
	if(nTimeDanBay + 100 > nTimeMove2Safe*1000)
	{
		return TRUE;
	}
	return FALSE;
}
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
int CheckMousePos(KPos startPoint,KPos endPoint, KBuffer_Spell pBufferSpell)
{
	//dZ.x - dX.z  = C1 = dZ*pos1.x - dX*pos1.z  (1)(d)
	//dX.x + dZ.z  = C2 = dX*player_x + dZ*player_z (2)(vuong goc voi d, di qua player)
	//--------------------------------------------------------------------------------------------------
	float dX = endPoint.x - startPoint.x;
	float dZ = endPoint.z - startPoint.z;
	float player_x = pBufferSpell.PlayerPos.x;
	float player_z = pBufferSpell.PlayerPos.z;
	float C2      = dX*player_x + dZ*player_z;
	float tichVoHuong = (dX*startPoint.x + dZ*startPoint.z  - C2)*(dX*pBufferSpell.MousePos_Player.x + dZ*pBufferSpell.MousePos_Player.z  - C2);

	KPos diemVuongGoc_Mouse2DuongThang;
	KPos diemVuongGoc_Player2DuongThang;
	float nDistance_Mouse2Player = 0.0;
	if (tichVoHuong > 0)
	{
		GIAO_DIEM_VUONG_GOC(diemVuongGoc_Mouse2DuongThang, startPoint, endPoint, pBufferSpell.MousePos_Player);
		GIAO_DIEM_VUONG_GOC(diemVuongGoc_Player2DuongThang, startPoint, endPoint, pBufferSpell.PlayerPos);
		nDistance_Mouse2Player = Distance_2D(diemVuongGoc_Mouse2DuongThang, diemVuongGoc_Player2DuongThang);
		if (nDistance_Mouse2Player >= 800.0)
		{
			return 1;
		} 
		else
		{
			return 0;
		}
	} 
	else
	{
		GIAO_DIEM_VUONG_GOC(diemVuongGoc_Mouse2DuongThang, startPoint, endPoint, pBufferSpell.MousePos_Player);
		GIAO_DIEM_VUONG_GOC(diemVuongGoc_Player2DuongThang, startPoint, endPoint, pBufferSpell.PlayerPos);
		nDistance_Mouse2Player = Distance_2D(diemVuongGoc_Mouse2DuongThang, diemVuongGoc_Player2DuongThang);
		if (nDistance_Mouse2Player >= 300.0)
		{
			return -1;
		} 
		else
		{
			return 0;
		}
	}
	return 0;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool GET_antoanPos(KPos startPoint, KPos endPoint, KBuffer_Spell pBufferSpell, KPos &antoanPos, float nDoRong)
{
	//dZ*x - dX*z  = C1 = dZ*startPoint->x - dX*startPoint->z  (1)(d: duong thang di qua 2 diem startPoint & endPoint)
	//dX*x + dZ*z  = C2 = dX*player_x + dZ*player_z     (2)(vuong goc voi d, di qua vi tri cua nguoi choi)
	//dZ.x - dX.z  = C4   = dZ.dodge_x  - dX.dodge_z     (4)(song song voi d + di qua diem dodge)
	//==>C4 = C1 - R*calc1
	//==>C4 = C1 + R*calc1 

	KNpc *pPlayer = GetPlayer();
	KPos diemVuongGoc;
	GIAO_DIEM_VUONG_GOC(diemVuongGoc, startPoint, endPoint, pPlayer->CurrentPos);

	//------------------ tim diem an toan -------------------------------------------
	float R  = (pBufferSpell.nRadius  + nDoRong);
	float dX = endPoint.x - startPoint.x;
	float dZ = endPoint.z - startPoint.z;
	float player_x = pPlayer->CurrentPos.x;
	float player_z = pPlayer->CurrentPos.z;
	float C1       = dZ*startPoint.x - dX*startPoint.z;
	float C2       = dX*player_x + dZ*player_z;

	float calc1    = sqrt(dZ*dZ + dX*dX);
	//-----------------------------------
	KPos tmpPos0, tmpPos1, tmpPos2;
	int Nghiem_0  = NghiemHePTBacNhat(tmpPos0,dZ, -dX, C1, dX, dZ, C2); // giao diem cua (1) va (2)
	if (!Nghiem_0)  return FALSE;
	float x_0  =  tmpPos0.x;
	float z_0  =  tmpPos0.z;
	//-----------------------------------
	float C4_1 = dZ*x_0 - dX*z_0 - R*calc1;	//Duong thang song song voi (1) di qua diem an toan 1(R=(pBufferSpell->nRadius + n_D))
	float C4_2 = dZ*x_0 - dX*z_0 + R*calc1; //Duong thang song song voi (1) di qua diem an toan 2

	int  Nghiem1  = NghiemHePTBacNhat(tmpPos1,dZ, -dX, C4_1, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem1)  return FALSE;
	float antoanPos1_x  = tmpPos1.x;
	float antoanPos1_z  = tmpPos1.z;
	//-----------------------------------
	int  Nghiem2  = NghiemHePTBacNhat(tmpPos2,dZ, -dX, C4_2, dX, dZ, C2); //giao diem cua (2) va (4)
	if (!Nghiem2)  return FALSE;
	float antoanPos2_x  = tmpPos2.x;
	float antoanPos2_z  = tmpPos2.z;

	//-----------------------------------
	// antoanPos: diem an toan R=(pBufferSpell->nRadius + n_D)
	float kc1 = sqrt((player_x - antoanPos1_x)*(player_x - antoanPos1_x) + (player_z - antoanPos1_z)*(player_z - antoanPos1_z));
	float kc2 = sqrt((player_x - antoanPos2_x)*(player_x - antoanPos2_x) + (player_z - antoanPos2_z)*(player_z - antoanPos2_z));
	if (kc1 < kc2){
		antoanPos.x = antoanPos1_x;
		antoanPos.z = antoanPos1_z;
	}
	else {
		antoanPos.x = antoanPos2_x;
		antoanPos.z = antoanPos2_z;
	}
	//==> SUY RA: duong thang di qua diem an toan co dang :
	//	  dZ*x - dX*z  = C4   = dZ*antoanPos.x  - dX*antoanPos.z  (song song voi d + di qua diem antoanPos)
	//------------------ END tim diem an toan -------------------------------------------
	return TRUE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KPos* GET_EVADE_EXTRA_THEO_MOUSE(KPos startPoint, KPos endPoint, KBuffer_Spell pBufferSpell)
{
	//__oMsg(" ============== 1");
	KPos diemVuongGoc_Mouse;
	KPos diemVuongGoc_Player; // diem nay lay tu pBufferSpell, diem nay luon co dinh
	GIAO_DIEM_VUONG_GOC(diemVuongGoc_Mouse, startPoint, endPoint, pBufferSpell.MousePos_Player);
	GIAO_DIEM_VUONG_GOC(diemVuongGoc_Player, startPoint, endPoint, pBufferSpell.PlayerPos);
	float KC  = Distance_2D(diemVuongGoc_Mouse, diemVuongGoc_Player);
	if(KC <= 100.0) return 0;

	float dX = endPoint.x - startPoint.x;
	float dZ = endPoint.z - startPoint.z;
	//----------------------------------------
	//get diem an toan va duong thang di qua diem antoan+song song voi (d)
	KPos antoanPos;
	bool rc = GET_antoanPos(startPoint, endPoint, pBufferSpell, antoanPos, 180.0);
	//bool rc = GET_antoanPos(startPoint, endPoint, pBufferSpell, antoanPos, 350.0);
	if(!rc) return 0;
	//__oMsg(" ============== 2");
	//==> SUY RA: duong thang di qua antoanPos va song song voi (d) co dang :
	//	  dZ*x - dX*z  = C4   = dZ*antoanPos.x  - dX*antoanPos.z  (song song voi d + di qua diem antoanPos)
	float C4   = dZ*antoanPos.x  - dX*antoanPos.z;// goi la duong thang (c4)	: di qua antoanPos va song song voi (d)

	//----------------------------------------
	//tim duong thang di qua MousePos va vuong goc voi (d)
	//dX*x + dZ*z  = C3 = dX*nMouse_x + dZ*nMouse_z    
	float nMouse_x = pBufferSpell.MousePos_Player.x;
	float nMouse_z = pBufferSpell.MousePos_Player.z;	

	float C3 = dX*nMouse_x + dZ*nMouse_z ; //(c3): thang di qua MousePos va vuong goc voi (d)

	//----------------------------------------
	//tim giao diem cua (c3) & (c4)
	KPos tmpPos0;
	int  Nghiem  = NghiemHePTBacNhat(tmpPos0,dZ, -dX, C4, dX, dZ, C3);
	if (!Nghiem)  return 0;
	//__oMsg(" ============== 3");
	KPos* EVADE = new KPos;;
	EVADE->x  = tmpPos0.x;
	EVADE->z  = tmpPos0.z;
	//__oMsg(" ============== 4");
	return EVADE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
KPos* GET_EVADE_EXTRA(KPos startPoint, KPos endPoint, KBuffer_Spell pBufferSpell, float nDoDai)
{
	float dX = endPoint.x - startPoint.x;
	float dZ = endPoint.z - startPoint.z;

	//get diem an toan
	KPos antoanPos;
	bool rc = GET_antoanPos(startPoint, endPoint, pBufferSpell, antoanPos, 200.0);

	/*KPos diemVuongGoc_antoanPos;
	GIAO_DIEM_VUONG_GOC(diemVuongGoc_antoanPos, startPoint, endPoint, antoanPos);
	float nKhoangCach_a = Distance_2D(*antoanPos, *diemVuongGoc_antoanPos);
	__oMsg("[=1XX=] --------- KC diemVuongGoc_antoanPos: %.2f", nKhoangCach_a);*/

	//bool rc = GET_antoanPos(startPoint, endPoint, pBufferSpell, antoanPos, 350.0);
	if(!rc) return 0;
	//==> SUY RA: duong thang di qua antoanPos va song song voi (d) co dang :
	//	  dZ*x - dX*z  = C4   = dZ*antoanPos.x  - dX*antoanPos.z  (song song voi d + di qua diem antoanPos)
	float C4   = dZ*antoanPos.x  - dX*antoanPos.z;// goi la duong thang (c4)	

	//----------------------------------------
	//tim 2 diem nam tren (d) va cach diemVuongGoc mot khoang xxx
	//KNpc *pPlayer = GetPlayer();	: ko tinh theo toa do hien tai cua pPlayer, tinh theo toa do cua pPlayer trong pBufferSpell
	KPos diemVuongGoc;
	GIAO_DIEM_VUONG_GOC(diemVuongGoc, startPoint, endPoint, pBufferSpell.PlayerPos);

	KPos pos_diem1;
	KPos pos_diem2; 
	TIM_DIEM_CACH_1DIEM(pos_diem1, pos_diem2, diemVuongGoc, startPoint, nDoDai);
	//TIM_DIEM_CACH_1DIEM(pos_diem1, pos_diem2, diemVuongGoc, startPoint, 400.0);

	//-----------------------------------------
	//tim 2 duong thang di qua pos_diem1, pos_diem2 va vuong goc voi (d)
	//dX*x + dZ*z  = D1 = dX*pos_diem1.x + dZ*pos_diem1.z     (a)(vuong goc voi d, di qua pos_diem1)
	//dX*x + dZ*z  = D2 = dX*pos_diem2.x + dZ*pos_diem2.z     (b)(vuong goc voi d, di qua pos_diem2)
	float D1 = dX*pos_diem1.x + dZ*pos_diem1.z;
	float D2 = dX*pos_diem2.x + dZ*pos_diem2.z;

	//-----------------------------------------
	//tim giao diem cua (c4) & (a)
	KPos tmpPos1, tmpPos2;
	int  Nghiem1  = NghiemHePTBacNhat(tmpPos1,dZ, -dX, C4, dX, dZ, D1);
	if (!Nghiem1)  return 0;
	float evade1_x  = tmpPos1.x;
	float evade1_z  = tmpPos1.z;

	//-----------------------------------
	//tim giao diem cua (c4) & (b)
	int  Nghiem2  = NghiemHePTBacNhat(tmpPos2,dZ, -dX, C4, dX, dZ, D2); 
	if (!Nghiem2)  return 0;
	float evade2_x  = tmpPos2.x;
	float evade2_z  = tmpPos2.z;

	//---------------------------------

	float nMouse_x = pBufferSpell.MousePos_Player.x;
	float nMouse_z = pBufferSpell.MousePos_Player.z;

	float kc1 = sqrt((nMouse_x - evade1_x)*(nMouse_x - evade1_x) + (nMouse_z - evade1_z)*(nMouse_z - evade1_z));
	float kc2 = sqrt((nMouse_x - evade2_x)*(nMouse_x - evade2_x) + (nMouse_z - evade2_z)*(nMouse_z - evade2_z));

	KPos* EVADE = new KPos;
	if (kc1 < kc2){
		EVADE->x = evade1_x;
		EVADE->z = evade1_z;
	}
	else {
		EVADE->x = evade2_x;
		EVADE->z = evade2_z;
	}
	
	/*float nKhoangCach_1 = Distance_2D(antoanPos->x, antoanPos->z, evade1_x, evade1_z);
	float nKhoangCach_2 = Distance_2D(antoanPos->x, antoanPos->z, evade2_x, evade2_z);
	float nKhoangCach_3 = Distance_2D(*antoanPos,*EVADE);

	KPos diemVuongGoc_EVADE;
	GIAO_DIEM_VUONG_GOC(diemVuongGoc_EVADE, startPoint, endPoint, *EVADE);
	float nKhoangCach_b = Distance_2D(*diemVuongGoc_EVADE, *EVADE);
	__oMsg("[=2XX=] --------- KC antoanPos->EVADE: %.2f : %.2f - %.2f  ==> %.2f : toa do: [%f-%f]", nKhoangCach_3,nKhoangCach_2,nKhoangCach_1,nKhoangCach_b,EVADE->x,EVADE->z);*/
	return EVADE;
}

//==================================================================================//
//==================================================================================//
bool WINAPI GIAO_DIEM_VUONG_GOC(KPos& pos_vuonggoc, KPos pos1,KPos pos2, KPos pos3)// giao diem giua (1)(di qua pos1,pos2) v?(2)(di qua pos3 va vuong goc voi (1))
{
	//dZ.x - dX.z  = C1   = dZ*pos1.x - dX*pos1.z  (1)(d)
	//dX.x + dZ.z  = C2   = dX*pos3->x + dZ*pos3->z (2)(vuong goc voi d va di qua pos3)
	float dX = pos2.x - pos1.x;
	float dZ = pos2.z - pos1.z;

	float C1       = dZ*pos1.x - dX*pos1.z;
	float C2     = dX*pos3.x + dZ*pos3.z;

	float calc1    = sqrt(dZ*dZ + dX*dX);
	//-----------------------------------
	KPos tmpPos0;
	int Nghiem_0  = NghiemHePTBacNhat(tmpPos0,dZ, -dX, C1, dX, dZ, C2); // giao diem cua (1) va (2)
	if (!Nghiem_0) return FALSE;
	pos_vuonggoc.x  =  tmpPos0.x;
	pos_vuonggoc.z  =  tmpPos0.z;
	return TRUE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool WINAPI TIM_DIEM_CACH_1DIEM(KPos& pos_diem1, KPos& pos_diem2, KPos pos1,KPos pos2, float radius)// tim 1 diem nam tren duong(1)(diqua pos1,pos2) & cach pos1 1 khoang cho truoc
{
	//dZ.x - dX.z  = C1   = dZ*pos1.x - dX*pos1.z  (1)(d)(di qua pos1, pos2)
	//dX.x + dZ.z  = C2  = dX*pos1->x + dZ*pos1->z (2)(vuong goc voi d va di qua pos1(co dinh)
	//dX.x + dZ.z  = C4   = dZ*pos3->x  - dX*pos3->z  (4)(song song voi (2) + di qua pos3)
	//==>C4= dX.x_1 + dZ.z_1 - R*calc1      //(x_1,z_1): la toa do pos1(co dinh)
	//==>C4= dX.x_1 + dZ.z_1 + R*calc1
	//KNpc *g_pPlayer = GetPlayer();
	//float player_x = g_pPlayer->CurrentPos.x;
	//float player_z = g_pPlayer->CurrentPos.z;

	float R = radius;
	float dX = pos2.x - pos1.x;
	float dZ = pos2.z - pos1.z;

	float C1       = dZ*pos1.x - dX*pos1.z;
	float C2    = dX*pos1.x + dZ*pos1.z;

	float calc1    = sqrt(dZ*dZ + dX*dX);
	//-----------------------------------
	KPos tmpPos0, tmpPos1, tmpPos2;
	int Nghiem_0  = NghiemHePTBacNhat(tmpPos0,dZ, -dX, C1, dX, dZ, C2); //tam thoi in ra xem dung la pos1 hay ko
	if (!Nghiem_0) return FALSE;
	
	float x_0  =  tmpPos0.x;
	float z_0  =  tmpPos0.z;
	//-----------------------------------
	float C4_1 = dX*pos1.x + dZ*pos1.z - R*calc1;
	float C4_2 = dX*pos1.x + dZ*pos1.z + R*calc1; 

	int  Nghiem1  = NghiemHePTBacNhat(tmpPos1,dX, dZ, C4_1, dZ, -dX, C1); //giao diem cua (1) va (4)
	if (!Nghiem1) return FALSE;

	pos_diem1.x  = tmpPos1.x;
	pos_diem1.z  = tmpPos1.z;
	//-----------------------------------
	int  Nghiem2  = NghiemHePTBacNhat(tmpPos2,dX, dZ, C4_2, dZ, -dX, C1); //giao diem cua (1) va (4)
	if (!Nghiem2) return FALSE;
	
	pos_diem2.x  = tmpPos2.x;
	pos_diem2.z  = tmpPos2.z;
	//-----------------------------------
	/*float tichvohuong = (dX*dodge1_x + dZ*dodge1_z - C2)*(dX*player_x + dZ*player_z - C2);
	if(tichvohuong >= 0 )
	{
		pos_diem->x = dodge1_x;
		pos_diem->z = dodge1_z;
	}
	else {
		pos_diem->x = dodge2_x;
		pos_diem->z = dodge2_z;
	}*/
	return TRUE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool WINAPI TIM_2DIEM_CACH_1DIEM(KPos* pos_diem1, KPos* pos_diem2, KPos* pos1, KPos* pos2, float radius)
{ // tim 2 diem nam tren duong(2) di qua pos1, vuong goc voi (1)(d)(di qua pos1, pos2) va cach pos1 mot khoang cho truoc

	//dZ.x - dX.z  = C1   = dZ*pos1.x - dX*pos1.z  (1)(d)(di qua pos1, pos2)
	//dX.x + dZ.z  = C2   = dX*pos1->x + dZ*pos1->z (2)(vuong goc voi d va di qua pos1(co dinh)
	//dZ.x - dX.z  = C4   = dZ*pos3->x  - dX*pos3->z  (4)(song song voi (1) + di qua pos3)
	//==>C4= dZ.x_1 - dX.z_1 - R*calc1      //(x_1,z_1): la toa do pos1(co dinh)
	//==>C4= dZ.x_1 - dX.z_1 + R*calc1

	float R = radius;
	float dX = pos2->x - pos1->x;
	float dZ = pos2->z - pos1->z;

	float C1       = dZ*pos1->x - dX*pos1->z;
	float C2       = dX*pos1->x + dZ*pos1->z;

	float calc1    = sqrt(dZ*dZ + dX*dX);
	//-----------------------------------
	KPos tmpPos0, tmpPos1, tmpPos2;
	int Nghiem_0  = NghiemHePTBacNhat(tmpPos0,dZ, -dX, C1, dX, dZ, C2); //tam thoi in ra xem dung la pos1 hay ko
	if (!Nghiem_0) return FALSE;

	float x_0  =  tmpPos0.x;
	float z_0  =  tmpPos0.z;
	//-----------------------------------
	float C4_1 = dZ*pos1->x - dX*pos1->z - R*calc1;
	float C4_2 = dZ*pos1->x - dX*pos1->z + R*calc1; 

	int  Nghiem1  = NghiemHePTBacNhat(tmpPos1,dX, dZ, C2, dZ, -dX, C4_1); //giao diem cua (2) va (4)
	if (!Nghiem1) return FALSE;

	pos_diem1->x  = tmpPos1.x;
	pos_diem1->z  = tmpPos1.z;
	//-----------------------------------
	int  Nghiem2  = NghiemHePTBacNhat(tmpPos2,dX, dZ, C2, dZ, -dX, C4_2); //giao diem cua (2) va (4)
	if (!Nghiem2) return FALSE;

	pos_diem2->x  = tmpPos2.x;
	pos_diem2->z  = tmpPos2.z;
	//-----------------------------------
	return TRUE;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void WINAPI GiaiPT_Bac2(float *nghiem1, float *nghiem2, float a, float b, float c)
{ // PT : ax.x + bx + c = 0
	if(a == 0) return;

	float x1, x2;
	float delta = b*b - 4*a*c;
	if(delta < 0) return;
	if(delta == 0)
	{
		x1 = -b/(2*a);
		x2 = -b/(2*a);
	}
	if(delta > 0)
	{
		x1= (-b + sqrt(delta))/(2*a);
		x2  = (-b - sqrt(delta))/(2*a);
	}
	*nghiem1 = x1;
	*nghiem2 = x2;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void WINAPI GiaoDiem_DuongTronVaDuongThang(KPos* pos_diem1, KPos* pos_diem2, KPos* pos1, KPos* pos2, KPos* pos3, float radius)
{
	//dZ.x - dX.z      = C2   = dZ*pos1.x - dX*pos1.z  (1)(d)(di qua pos1, pos2)
	//A.x  + B.z  + C1 = 0          (1)
	//x.x  + z.z  - 2.a.x - 2.b.z + C = 0              (2) phuong trinh duong tron tam I(a,b)=pos3, ban kinh R 

	float R   = radius;
	float dX  = pos2->x - pos1->x;
	float dZ  = pos2->z - pos1->z;
	float C2  = dZ*pos1->x - dX*pos1->z;

	float a   = pos3->x;
	float b   = pos3->z;
	float A   = dZ;
	float B   = -dX;
	float C1  = -C2;
	float C   = a*a + b*b - R*R;
	//------------------------------------------ 
	if(B == 0) return;
	//z = -(C1 + A.x)/B
	//x.x(1 + A.A/B.B)  +  x.2.(C1.A/B.B - a + b.A/B)  +  C1.C1/B.B + 2.b.C1/B + C = 0
	float Heso_a = 1 + A*A/(B*B);
	float Heso_b = 2*(C1*A/(B*B) - a + b*A/B);
	float Heso_c = C1*C1/(B*B) + 2*b*C1/B  + C;
	float *nghiem1 = new float, *nghiem2 = new float;
	GiaiPT_Bac2(nghiem1, nghiem2, Heso_a, Heso_b, Heso_c);

	pos_diem1->x = *nghiem1;
	pos_diem1->z = -(C1 + A*(*nghiem1))/B;

	pos_diem2->x = *nghiem2;
	pos_diem2->z = -(C1 + A*(*nghiem2))/B;

	//float kc_1 = Distance_2D(pos_diem1->x, pos_diem1->z, a, b);
	//float kc_2 = Distance_2D(pos_diem2->x, pos_diem2->z, a, b);
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
extern KBuffer_Spell g_BufferSpell[MAX_ARRAY_BUFFER_SPELL];
extern KBuffer_Spell g_BufferSpell_2[MAX_ARRAY_BUFFER_SPELL];
void PrintBuffer(int index)
{
	//if (index < 0)
	//{
	//	for (int i = 0; i < MAX_ARRAY_BUFFER_SPELL; ++i)
	//	{
	//		__oMsg("[%s][%d]", __FILE__, __LINE__);
	//		PrintBuffer(i);
	//	}
	//}
	//else
	//{
	//	KBuffer_Spell tmp = g_BufferSpell[index];
	//	__oMsg("===================index[%d]================================", index);
	//	__oMsg("SourcePos		= (%.2f, %.2f, %.2f)", tmp.SourcePos.x, tmp.SourcePos.y, tmp.SourcePos.z);
	//	__oMsg("MaxDestPos		= (%.2f, %.2f, %.2f)", tmp.MaxDestPos.x, tmp.MaxDestPos.y, tmp.MaxDestPos.z);
	//	__oMsg("MousePos		= (%.2f, %.2f, %.2f)", tmp.MousePos.x, tmp.MousePos.y, tmp.MousePos.z);
	//	__oMsg("Timer			= %.2f", tmp.nTimer);
	//	__oMsg("IsCasting		= %d", tmp.isCasting);
	//	__oMsg("Index			= %d", tmp.index);
	//	__oMsg("HeroName		= [%s]", tmp.szHeroName);
	//	__oMsg("PlayerName		= [%s]", tmp.szPlayerName);
	//	__oMsg("SpellName		= [%s]", tmp.szSpellName);
	//	__oMsg("nDelay			= %.2f", tmp.nDelay);
	//	__oMsg("nRange			= %.2f", tmp.nRange);
	//	__oMsg("nRadius			= %.2f", tmp.nRadius);
	//	__oMsg("nRadius_2		= %.2f", tmp.nRadius_2);
	//	__oMsg("nMissileSpeed	= %.2f", tmp.nMissileSpeed);
	//	__oMsg("nDangerValue	= %d", tmp.nDangerValue);
	//	__oMsg("nIsDangerous	= %d", tmp.nIsDangerous);
	//	__oMsg("nFlag_TruocSau	= %d", tmp.nFlag_TruocSau);
	//	__oMsg("IsSetSpellData	= %d", tmp.IsSetSpellData);
	//	__oMsg("\n");
	//}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void RESET_BUFFER_SPELL(int index)
{
	////__oMsg("[%s][%d]", __FILE__, __LINE__);
	if (index < 0)
	{
		////__oMsg("[%s][%d]", __FILE__, __LINE__);
		for (int i = 0; i < MAX_ARRAY_BUFFER_SPELL; ++i)
		{
			RESET_BUFFER_SPELL(i);
		}
	}
	else
	{
		PrintBuffer(index);
		//__oMsg("[%s][%d]-----timer:%f", __FILE__, __LINE__, g_BufferSpell[index].nTimer);
		g_BufferSpell[index].isCasting = false;
		g_BufferSpell[index].nTimer = 0.;
		g_BufferSpell[index].nSpecialTimer = 0.;
		g_BufferSpell[index].IsEvaded = false;
		//__oMsg("index: %d, sizeof(): %d", index, sizeof(KBuffer_Spell));
		g_TimePrevious = 0;
		g_TimeNow = 0;
		g_TimeSpecial = false;
		countBiDanhBoiSkillDinhHuong = 0;
	}
}

//==================================================================================//
void RESET_BUFFER_SPELL_2(int index)
{
	////__oMsg("[%s][%d]", __FILE__, __LINE__);
	if (index < 0)
	{
		////__oMsg("[%s][%d]", __FILE__, __LINE__);
		for (int i = 0; i < MAX_ARRAY_BUFFER_SPELL; ++i)
		{
			RESET_BUFFER_SPELL_2(i);
		}
	}
	else
	{
		PrintBuffer(index);
		//__oMsg("[%s][%d]-----timer:%f", __FILE__, __LINE__, g_BufferSpell[index].nTimer);
		g_BufferSpell_2[index].isCasting = false;
		g_BufferSpell_2[index].nTimer = 0;
		g_BufferSpell_2[index].nSpecialTimer = 0;
		g_BufferSpell_2[index].IsEvaded = false;
		//__oMsg("index: %d, sizeof(): %d", index, sizeof(KBuffer_Spell));
		g_TimePrevious = 0;
		g_TimeNow = 0;
		g_TimeSpecial = false;
		countBiDanhBoiSkillDinhHuong = 0;
	}
}

//==================================================================================//
void RESET_BUFFER_SPELL_2_QUA_3s()
{
	for(int index = 0; index < MAX_ARRAY_BUFFER_SPELL; ++index)
	{
		if (strlen(g_BufferSpell_2[index].szSpellName) == 0) continue;
		if (g_BufferSpell_2[index].isCasting)
		{ // DANG CO VAN DE GOI VAO CHO NAY LIEN TUC ???
			g_BufferSpell_2[index].nTimer += SYS_TIMER;
			g_BufferSpell_2[index].nSpecialTimer += SYS_TIMER;
			//__oMsg("---%f---[%s][%d]",g_BufferSpell[index].nTimer, __FILE__, __LINE__);
		}
		if (g_BufferSpell_2[index].nTimer >= 2000)
		{
			//__oMsg("=###===QUA 2,5s ===============");
			UnBlockMove();
			RESET_BUFFER_SPELL_2(index);
		}
	}
}

//==================================================================================//
//==================================================================================//IsEvaded
//==================================================================================//
void RESET_BUFFER_SPELL_SPECIAL(int index)
{
	////__oMsg("[%s][%d]", __FILE__, __LINE__);
	g_BufferSpell[index].nTimer = 0.;
	PrintBuffer(index);
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void SET_IsEvaded_BUFFER_SPELL_SPECIAL(int index)
{
	g_BufferSpell[index].IsEvaded = true;
	PrintBuffer(index);
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
//bool nPrint_test = false;
float nTime_UpdateSpell = (float)1.5;
void SET_BUFFER_SPELL()
{
////VMProtectBegin("DLL_VM__SET_BUFFER_SPELL");
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return;
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return;

	int nCount = (dw2 - dw1)/4;
	////__oMsg("nCount: %d", nCount);
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return;
////VMProtectEnd();
	BYTE isDied = (BYTE)pPlayer->nIsDie;
	if (isDied != 0) return;
	
	// set buffer
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyPlayer = (KNpc*)dw3;
		int isDie = (BYTE)pEnemyPlayer->nIsDie;
		if (!pEnemyPlayer->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pEnemyPlayer->nHP <= 0. || !pEnemyPlayer->IsChampion())
			continue;
		
		// kiem tra xem co hero nao ra skill
		KCastSpell *pCastSpell = (KCastSpell *)pEnemyPlayer->_pCastSpell;
		if (pCastSpell == NULL) continue;
		KSkill_2 *pSkill_2 = (KSkill_2 *)pCastSpell->__pK_str2;
		if (pSkill_2 == NULL) continue;
		//__oMsg("----- %x -----[%s][%d]", &pSkill_2->nTemp_1, __FILE__, __LINE__);
		if (CheckName( (sz__BasicAttack), pSkill_2->GetSkillName())) continue;
		if (CheckName( (sz__recall), pSkill_2->GetSkillName())) continue;
		//if (CheckName("DANH_DAU", pSkill_2->GetSkillName())) continue;
//-----------------------------Test----------------
		//KSkill_3_Temp* pK3_temp = (KSkill_3_Temp*)pSkill_2->__pK_str3;
		//if(pK3_temp /*&& nPrint_test ==false*/)
		//{
		//	nPrint_test = true;
		//	__oMsg("[CHECK-MISSILE-SPEED]%x : %f - %s", &pK3_temp->nMis_speed, pK3_temp->nMis_speed, pSkill_2->GetSkillName());
		//}		
//-----------------------------End-Test----------------
		// SET BUFFER_SPELL
		for(int index = 0; index < MAX_ARRAY_BUFFER_SPELL; ++index)
		{
			if (g_BufferSpell[index].isCasting == true && strcmp(g_BufferSpell[index].szSpellName, pSkill_2->GetSkillName()) == 0) break;
			float nTimeCastSkill = GetTimeGame();
			//__oMsg("kiem tra update du lieu:%f;%f;%d;%s", nTimeCastSkill, g_BufferSpell[index].nTimeGameCAST_SKILL, __LINE__, __FILE__);
			//__oMsg("zzxxxxzz: %f - %f", nTimeCastSkill - g_BufferSpell[index].nTimeGameCAST_SKILL, 1000*pCastSpell->nDelay_AAAnimate);
			//__oMsg("zzxxxxzz: %f ", nTimeCastSkill - g_BufferSpell[index].nTimeGameCAST_SKILL);
			// THEM MOI or CAP NHAT DU LIEU
			if (strlen(g_BufferSpell[index].szSpellName) == 0 ||(g_BufferSpell[index].isCasting == false && strcmp(g_BufferSpell[index].szSpellName, pSkill_2->GetSkillName()) == 0))
			{
				if(strlen(g_BufferSpell[index].szSpellName) != 0 && (CheckName( (sz__SionQ), g_BufferSpell[index].szSpellName)
				   || CheckName( (sz__MalzaharQ), g_BufferSpell[index].szSpellName)
				   || CheckName( (sz__TaliyahQ), g_BufferSpell[index].szSpellName)))
				{
					nTime_UpdateSpell = (float)2.2;
				}
				else nTime_UpdateSpell = (float) 1.5;
				if (nTimeCastSkill - g_BufferSpell[index].nTimeGameCAST_SKILL < nTime_UpdateSpell)// trong 1.4s ko update lai du lieu
				{
					//__oMsg("khong update du lieu luc nay:%f;%f;%d;%s", nTimeCastSkill, g_BufferSpell[index].nTimeGameCAST_SKILL, __LINE__, __FILE__);
					break;
				}
				g_BufferSpell[index].SourcePos.x		 = pCastSpell->SourcePos.x;
				g_BufferSpell[index].SourcePos.y		 = pCastSpell->SourcePos.y;
				g_BufferSpell[index].SourcePos.z		 = pCastSpell->SourcePos.z;
				g_BufferSpell[index].MaxDestPos.x		 = pCastSpell->MaxDestPos.x;
				g_BufferSpell[index].MaxDestPos.y		 = pCastSpell->MaxDestPos.y;
				g_BufferSpell[index].MaxDestPos.z		 = pCastSpell->MaxDestPos.z;
				g_BufferSpell[index].MousePos.x			 = pCastSpell->MousePos.x;
				g_BufferSpell[index].MousePos.y			 = pCastSpell->MousePos.y;
				g_BufferSpell[index].MousePos.z			 = pCastSpell->MousePos.z;
				g_BufferSpell[index].PlayerPos			 = pPlayer->CurrentPos;
				//g_BufferSpell[index].nDelay				 = 1000*pCastSpell->nDelay_AAAnimate;
				KPos *pMousePos = GetMousePos();
				g_BufferSpell[index].MousePos_Player	 = *pMousePos;
				g_BufferSpell[index].nTimer				 = 0.; // ????
				g_BufferSpell[index].nSpecialTimer		 = 0.; // ????
				g_BufferSpell[index].nTimeGameCAST_SKILL = nTimeCastSkill;
				//__oMsg("da update du lieu:%f;%f;%d;%s", nTimeCastSkill, g_BufferSpell[index].nTimeGameCAST_SKILL, __LINE__, __FILE__);
				g_BufferSpell[index].isCasting			 = true; // ????
				g_BufferSpell[index].index				 = index; // ????
				g_BufferSpell[index].IsEvaded			 = false;
				if (g_BufferSpell[index].IsSetSpellData == true) break;
				g_BufferSpell[index].IsSetSpellData = true;
				g_BufferSpell[index].pNpc				 = (DWORD)pEnemyPlayer;
				strcpy_s(g_BufferSpell[index].szHeroName, pEnemyPlayer->GetNameHero());
				strcpy_s(g_BufferSpell[index].szPlayerName, pEnemyPlayer->GetNameNpc());
				strcpy_s(g_BufferSpell[index].szSpellName, pSkill_2->GetSkillName());
				//SetSpellData(g_BufferSpell[index]);
				//__oMsg("[%s][%d]", __FILE__, __LINE__);
				PrintBuffer(index);
				break;	//??? de thoat khoi vong lap ngay sau khi da cap nhat hoac them moi du lieu,
						//tranh bi trung du lieu cho tat ca cac ban ghi
			}
		}
	}

	// reset buffer
	for(int index = 0; index < MAX_ARRAY_BUFFER_SPELL; ++index)
	{
		if (strlen(g_BufferSpell[index].szSpellName) == 0) continue;
		if (g_BufferSpell[index].isCasting)
		{ // DANG CO VAN DE GOI VAO CHO NAY LIEN TUC ???
			g_BufferSpell[index].nTimer += SYS_TIMER;
			g_BufferSpell[index].nSpecialTimer += SYS_TIMER;
			//__oMsg("---%f---[%s][%d]",g_BufferSpell[index].nTimer, __FILE__, __LINE__);
		}
		if (g_BufferSpell[index].nTimer >= TIME_OUT_CAST_SPELL)
		{
			UnBlockMove();
			RESET_BUFFER_SPELL(index);
		}
	}
}

//==================================================================================//
bool isVarusQFire = false;
void SET_CONDITION_BUFF_2(KNpc* unit, char * animation)
{
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer)				   return;
	if((BYTE)pPlayer->nIsDie != 0) return;

	if(unit && unit->IsChampion() && unit->IsEnemy(pPlayer->nTeam_ID) && (BYTE)unit->nIsDie == 0 && 
	   CheckName(sz__Varus, unit->GetNameHero()) && CheckName(animation, "Spell1_Fire")
	  ) 
	{
		isVarusQFire = true;
	}
		
}
//==================================================================================//
void SET_BUFFER_SPELL_2(KNpc* unit, KCastSpell * pCast)
{
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer)				   return;
	if((BYTE)pPlayer->nIsDie != 0) return;
	if(!unit || !unit->IsChampion() || !unit->IsEnemy(pPlayer->nTeam_ID) || (BYTE)unit->nIsDie == 1 || !pCast) return;
	
	KSkill_2 *pSkill_2 = (KSkill_2 *)pCast->__pK_str2;
	if(!pSkill_2) return;
	
	//--- set buffer 
	if((CheckName(pSkill_2->GetSkillName(), "VarusQ") && isVarusQFire) ||
		CheckName(pSkill_2->GetSkillName(), "ThreshQ")				   ||
	    CheckName(pSkill_2->GetSkillName(), "XerathArcanopulse2")	   ||		//Xerath-Q-Release
		CheckName(pSkill_2->GetSkillName(), "XerathRMissileWrapper")   ||		//Xerath-R-Release
		CheckName(pSkill_2->GetSkillName(), "VelkozW")				   ||
		CheckName("PoppyRSpell", pSkill_2->GetSkillName())			   ||		//Poppy-R
		CheckName("GnarBigE", pSkill_2->GetSkillName())		     	   ||
		CheckName(pSkill_2->GetSkillName(), "GnarE")				   ||	
		CheckName("JhinRShot", pSkill_2->GetSkillName())			   ||
		CheckName("FioraW", pSkill_2->GetSkillName())			       ||
		CheckName("ViktorDeathRay", pSkill_2->GetSkillName())		   ||
		CheckName(sz__SyndraQ, pSkill_2->GetSkillName())		       ||
		CheckName("SyndraWCast", pSkill_2->GetSkillName())			   
		//CheckName("OrianaIzunaCommand", pSkill_2->GetSkillName())
	  ) 
	{
		// SET BUFFER_SPELL_2
		for(int index = 0; index < MAX_ARRAY_BUFFER_SPELL; ++index)
		{
			if (g_BufferSpell_2[index].isCasting == true && strcmp(g_BufferSpell_2[index].szSpellName, pSkill_2->GetSkillName()) == 0) break;
			float nTimeCastSkill = GetTimeGame();
			//__oMsg("kiem tra update du lieu:%f;%f;%d;%s", nTimeCastSkill, g_BufferSpell[index].nTimeGameCAST_SKILL, __LINE__, __FILE__);

			// THEM MOI or CAP NHAT DU LIEU
			if (strlen(g_BufferSpell_2[index].szSpellName) == 0 ||(g_BufferSpell_2[index].isCasting == false && strcmp(g_BufferSpell_2[index].szSpellName, pSkill_2->GetSkillName()) == 0))
			{
				if (nTimeCastSkill - g_BufferSpell_2[index].nTimeGameCAST_SKILL < 0.6f)// trong 1.0s ko update lai du lieu
				{
					//__oMsg("khong update du lieu luc nay:%f;%f;%d;%s", nTimeCastSkill, g_BufferSpell[index].nTimeGameCAST_SKILL, __LINE__, __FILE__);
					break;
				}
				//__oMsg("kiem tra update du lieu: =====vao");
				g_BufferSpell_2[index].SourcePos.x		 = pCast->SourcePos.x;
				g_BufferSpell_2[index].SourcePos.y		 = pCast->SourcePos.y;
				g_BufferSpell_2[index].SourcePos.z		 = pCast->SourcePos.z;
				g_BufferSpell_2[index].MaxDestPos.x		 = pCast->MaxDestPos.x;
				g_BufferSpell_2[index].MaxDestPos.y		 = pCast->MaxDestPos.y;
				g_BufferSpell_2[index].MaxDestPos.z		 = pCast->MaxDestPos.z;
				g_BufferSpell_2[index].MousePos.x		 = pCast->MousePos.x;
				g_BufferSpell_2[index].MousePos.y		 = pCast->MousePos.y;
				g_BufferSpell_2[index].MousePos.z		 = pCast->MousePos.z;
				g_BufferSpell_2[index].PlayerPos		 = pPlayer->CurrentPos;
				//g_BufferSpell_2[index].nDelay			 = 1000*pCastSpell->nDelay_AAAnimate;
				KPos *pMousePos = GetMousePos();
				g_BufferSpell_2[index].MousePos_Player	 = *pMousePos;
				g_BufferSpell_2[index].nTimer			 = 0; // ????
				g_BufferSpell_2[index].nSpecialTimer	 = 0; // ????
				g_BufferSpell_2[index].nTimeGameCAST_SKILL = nTimeCastSkill;
				//__oMsg("da update du lieu:%f;%f;%d;%s", nTimeCastSkill, g_BufferSpell[index].nTimeGameCAST_SKILL, __LINE__, __FILE__);
				g_BufferSpell_2[index].isCasting		 = true; // ????
				g_BufferSpell_2[index].index			 = index; // ????
				g_BufferSpell_2[index].IsEvaded			 = false;
				if (g_BufferSpell_2[index].IsSetSpellData == true) break;
				g_BufferSpell_2[index].IsSetSpellData = true;
				g_BufferSpell_2[index].pNpc				 = (DWORD)unit;
				strcpy_s(g_BufferSpell_2[index].szHeroName, unit->GetNameHero());
				strcpy_s(g_BufferSpell_2[index].szPlayerName, unit->GetNameNpc());
				strcpy_s(g_BufferSpell_2[index].szSpellName, pSkill_2->GetSkillName());
				//SetSpellData(g_BufferSpell_2[index]);
				//__oMsg("[%s][%d]", __FILE__, __LINE__);
				PrintBuffer(index);
				break;	//??? de thoat khoi vong lap ngay sau khi da cap nhat hoac them moi du lieu,
				//tranh bi trung du lieu cho tat ca cac ban ghi
			}
		}
	}

	if(CheckName("OrianaIzunaCommand", pSkill_2->GetSkillName())) 
	{
		// SET BUFFER_SPELL_2
		for(int index = 0; index < MAX_ARRAY_BUFFER_SPELL; ++index)
		{
			if (g_BufferSpell_2[index].isCasting == true && strcmp(g_BufferSpell_2[index].szSpellName, pSkill_2->GetSkillName()) == 0) break;
			float nTimeCastSkill = GetTimeGame();

			// THEM MOI or CAP NHAT DU LIEU
			if (strlen(g_BufferSpell_2[index].szSpellName) == 0 ||(g_BufferSpell_2[index].isCasting == false && strcmp(g_BufferSpell_2[index].szSpellName, pSkill_2->GetSkillName()) == 0))
			{
				if (nTimeCastSkill - g_BufferSpell_2[index].nTimeGameCAST_SKILL < 0.5f)// trong 1.0s ko update lai du lieu
				{
					break;
				}
				//__oMsg("ORINANA - kiem tra update du lieu: =====vao");
		
				g_BufferSpell_2[index].SourcePos.x		 = pCast->SourcePos.x;
				g_BufferSpell_2[index].SourcePos.y		 = pCast->SourcePos.y;
				g_BufferSpell_2[index].SourcePos.z		 = pCast->SourcePos.z;
				g_BufferSpell_2[index].MaxDestPos.x		 = pCast->MaxDestPos.x;
				g_BufferSpell_2[index].MaxDestPos.y		 = pCast->MaxDestPos.y;
				g_BufferSpell_2[index].MaxDestPos.z		 = pCast->MaxDestPos.z;
				g_BufferSpell_2[index].MousePos.x		 = pCast->MousePos.x;
				g_BufferSpell_2[index].MousePos.y		 = pCast->MousePos.y;
				g_BufferSpell_2[index].MousePos.z		 = pCast->MousePos.z;
				g_BufferSpell_2[index].PlayerPos		 = pPlayer->CurrentPos;
				//g_BufferSpell_2[index].nDelay			 = 1000*pCastSpell->nDelay_AAAnimate;
				KPos *pMousePos = GetMousePos();
				g_BufferSpell_2[index].MousePos_Player	 = *pMousePos;
				g_BufferSpell_2[index].nTimer			 = 0; // ????
				g_BufferSpell_2[index].nSpecialTimer	 = 0; // ????
				g_BufferSpell_2[index].nTimeGameCAST_SKILL = nTimeCastSkill;
				//__oMsg("da update du lieu:%f;%f;%d;%s", nTimeCastSkill, g_BufferSpell[index].nTimeGameCAST_SKILL, __LINE__, __FILE__);
				g_BufferSpell_2[index].isCasting		 = true; // ????
				g_BufferSpell_2[index].index			 = index; // ????
				g_BufferSpell_2[index].IsEvaded			 = false;
				
				g_BufferSpell_2[index].nRange			 = 850;
				//if(g_BufferSpell_2[index].pNpc && !GET_BUFF((KNpc*)g_BufferSpell_2[index].pNpc, sz__orianaghostself))// tren nguoi dang co cau
				{
					//__oMsg("11--vao-2");
					//---get cau orianna --------------
					DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
					DWORD nTempBASE_AttackableUnit = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
					DWORD nTempBASE_AttackableUnit_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
					DWORD dw1 = *(DWORD*)nTempBASE_AttackableUnit;
					DWORD dw2 = *(DWORD*)nTempBASE_AttackableUnit_MAX;
					if(dw1 && dw2)
					{
						int nCount = (dw2 - dw1)/4;
						KNpc *pPlayer = GetPlayer();
						for (int i = 0; i < nCount; ++i)
						{
							DWORD dw3 = *(DWORD*)(dw1 + 4*i);
							if (dw3 == 0) continue;
							KNpc *pOri_Sphere = (KNpc*)dw3;
							int isDie = (BYTE)pOri_Sphere->nIsDie;
							if (pOri_Sphere->IsAlly(pPlayer->nTeam_ID) || isDie == 1 || pOri_Sphere->nHP <= 0)
								continue;
							if ((BYTE)pOri_Sphere->nIsTargetableToTeam == 4) continue;
							if (CheckName("TheDoomBall", pOri_Sphere->GetNameNpc()) == false) continue;
							if (CheckName("OriannaBall", pOri_Sphere->GetNameHero()) == false) continue;

							g_BufferSpell_2[index].SourcePos.x		 = pOri_Sphere->CurrentPos.x;
							g_BufferSpell_2[index].SourcePos.y		 = pOri_Sphere->CurrentPos.y;
							g_BufferSpell_2[index].SourcePos.z		 = pOri_Sphere->CurrentPos.z;
							g_BufferSpell_2[index].nRange = Distance_2D(g_BufferSpell_2[index].SourcePos, g_BufferSpell_2[index].MaxDestPos);
							//__oMsg("22--vao-2");
						}
					}
					//g_BufferSpell_2[index].nRange = Distance_2D(g_BufferSpell_2[index].SourcePos, g_BufferSpell_2[index].MaxDestPos);
				}

				if (g_BufferSpell_2[index].IsSetSpellData == true) break;
				g_BufferSpell_2[index].IsSetSpellData = true;
				g_BufferSpell_2[index].pNpc				 = (DWORD)unit;
				strcpy_s(g_BufferSpell_2[index].szHeroName, unit->GetNameHero());
				strcpy_s(g_BufferSpell_2[index].szPlayerName, unit->GetNameNpc());
				strcpy_s(g_BufferSpell_2[index].szSpellName, pSkill_2->GetSkillName());
				//SetSpellData(g_BufferSpell_2[index]);
				//__oMsg("[%s][%d]", __FILE__, __LINE__);
				PrintBuffer(index);
				break;	//??? de thoat khoi vong lap ngay sau khi da cap nhat hoac them moi du lieu,
				//tranh bi trung du lieu cho tat ca cac ban ghi
			}
		}
	}

		
	
//---chac ko can, co vao deo dau --------------------------------
	// reset buffer
	//for(int index = 0; index < MAX_ARRAY_BUFFER_SPELL; ++index)
	//{
	//	if (strlen(g_BufferSpell_2[index].szSpellName) == 0) continue;
	//	if (g_BufferSpell_2[index].isCasting)
	//	{ // DANG CO VAN DE GOI VAO CHO NAY LIEN TUC ???
	//		g_BufferSpell_2[index].nTimer += SYS_TIMER;
	//		g_BufferSpell_2[index].nSpecialTimer += SYS_TIMER;
	//		//__oMsg("---%f---[%s][%d]",g_BufferSpell[index].nTimer, __FILE__, __LINE__);
	//	}
	//	if (g_BufferSpell_2[index].nTimer >= 2500)
	//	{
	//		UnBlockMove();
	//		RESET_BUFFER_SPELL_2(index);
	//	}
	//}
}

//===============================================================================================================//
void AUTO_DODGE_2()
{
	KNpc *pPlayer = GetPlayer();
	if (pPlayer == 0)
	{
		UnBlockMove();
		return;
	}
	if ((BYTE)pPlayer->nIsDie == 1)
	{
		UnBlockMove();
		return;
	}
	for (int i = 0; i < MAX_ARRAY_BUFFER_SPELL; ++i)
	{
		// kiem tra xem co hero nao ra skill
		if (!g_BufferSpell_2[i].isCasting) continue;
		KBuffer_Spell pBuff = g_BufferSpell_2[i];
		float fDistance = Distance_2D(pPlayer->CurrentPos, pBuff.SourcePos);
		//==1===Thresh=====================================================================================================
		if (CheckName(sz__Thresh, pBuff.szHeroName))
		{
			if (CheckName(pBuff.szSpellName, sz__ThreshQ))
			{
				if (COUNT_NPC_INLINE(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff) >= 1)
				{
					UnBlockMove();
					return;
				}
				DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL_2);
			}
		}

		//==2===Varus=====================================================================================================
		else if (CheckName(sz__Varus, pBuff.szHeroName))
		{
			if (CheckName(pBuff.szSpellName, sz__VarusQ))
			{
				if(fDistance > 600)
				{
					DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL_2);
				}
				extern bool isVarusQFire;
				isVarusQFire = false;
			}
		}

		//==3===Xerath=====================================================================================================
		else if (CheckName(sz__Xerath, pBuff.szHeroName))
		{
			if (CheckName(pBuff.szSpellName, "XerathArcanopulse2"))	//Q
			{
				DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL_2);
			}
			else if(CheckName(pBuff.szSpellName, "XerathRMissileWrapper"))//R
			{
				EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL_2);
			}
		}

		//==4===Velkoz=====================================================================================================
		else if (CheckName(sz__Velkoz, pBuff.szHeroName))
		{
			if (CheckName(pBuff.szSpellName, sz__VelkozW))	//W
			{
				DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL_2);
			}
		}

		//==5===Poppy=====================================================================================================
		else if (CheckName(sz__Poppy, pBuff.szHeroName))
		{
			if (CheckName("PoppyRSpell", pBuff.szSpellName))	//R
			{
				DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL_2);
			}
		}
		
		//==6===Gnar=====================================================================================================
		else if (CheckName(sz__Gnar, pBuff.szHeroName))
		{
			if (CheckName(pBuff.szSpellName, "GnarE"))	//E
			{
				EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL_2);
			}
			else if (CheckName("GnarBigE", pBuff.szSpellName))	//E-Big
			{
				EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL_2);
			}
		}

		//==7===JHIN=====================================================================================================
		else if (CheckName(sz__Jhin, pBuff.szHeroName))
		{
			if (CheckName("JhinRShot", pBuff.szSpellName))	//R
			{
				DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL_2);
			}
		}

		//==8===Fiora=====================================================================================================
		else if (CheckName(sz__Fiora, pBuff.szHeroName))
		{
			if (CheckName(sz__FioraW, pBuff.szSpellName))	//W
			{
				DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL_2);
			}
		}

		//==9===Viktor=====================================================================================================
		else if (CheckName(sz__Viktor, pBuff.szHeroName))
		{
			if (CheckName("ViktorDeathRay", pBuff.szSpellName))	//E
			{
				DODGE_LINE_NEW(&pBuff.MaxDestPos, &pBuff.MousePos, &pBuff, RESET_BUFFER_SPELL_2);
			}
		}

		//==10===Syndra=====================================================================================================
		else if (CheckName(sz__Syndra, pBuff.szHeroName))
		{
			if (CheckName(sz__SyndraQ, pBuff.szSpellName))	//Q
			{
				EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL_2);
			}
			else if (CheckName("SyndraWCast", pBuff.szSpellName))	//W
			{
				EVADE_CIRCLE(&pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL_2);
			}
		}

		//==11===Orianna=====================================================================================================
		else if (CheckName(sz__Orianna, pBuff.szHeroName))
		{
			KPos syphere_ori;
			float nNewRange = 0;
			if (CheckName("OrianaIzunaCommand", pBuff.szSpellName))	//Q
			{
				DODGE_LINE_NEW(&pBuff.SourcePos, &pBuff.MaxDestPos, &pBuff, RESET_BUFFER_SPELL_2);
			}
		}
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
extern KBuffer_Spell g_BaseTimeSpell[MAX_ARRAY_BUFFER_SPELL];
void PrintBaseTime(int index)
{
	//if (index < 0)
	//{
	//	for (int i = 0; i < MAX_ARRAY_BUFFER_SPELL; ++i)
	//	{
	//		//__oMsg("---BASE TIMER SPELL---[%s][%d]", __FILE__, __LINE__);
	//		PrintBaseTime(i);
	//	}
	//}
	//else
	//{
	//	KBuffer_Spell tmp = g_BaseTimeSpell[index];
	//	__oMsg("===================index[%d]====---BASE TIMER SPELL---====================", index);
	//	__oMsg("SourcePos		= (%.2f, %.2f, %.2f)", tmp.SourcePos.x, tmp.SourcePos.y, tmp.SourcePos.z);
	//	__oMsg("MaxDestPos		= (%.2f, %.2f, %.2f)", tmp.MaxDestPos.x, tmp.MaxDestPos.y, tmp.MaxDestPos.z);
	//	__oMsg("MousePos		= (%.2f, %.2f, %.2f)", tmp.MousePos.x, tmp.MousePos.y, tmp.MousePos.z);
	//	__oMsg("Timer			= %.2f", tmp.nTimer);
	//	__oMsg("IsCasting		= %d", tmp.isCasting);
	//	__oMsg("Index			= %d", tmp.index);
	//	__oMsg("HeroName		= [%s]", tmp.szHeroName);
	//	__oMsg("PlayerName		= [%s]", tmp.szPlayerName);
	//	__oMsg("SpellName		= [%s]", tmp.szSpellName);
	//	__oMsg("nDelay			= %.2f", tmp.nDelay);
	//	__oMsg("nRange			= %.2f", tmp.nRange);
	//	__oMsg("nRadius			= %.2f", tmp.nRadius);
	//	__oMsg("nRadius_2		= %.2f", tmp.nRadius_2);
	//	__oMsg("nMissileSpeed	= %.2f", tmp.nMissileSpeed);
	//	__oMsg("nDangerValue	= %d", tmp.nDangerValue);
	//	__oMsg("nIsDangerous	= %d", tmp.nIsDangerous);
	//	__oMsg("nFlag_TruocSau	= %d", tmp.nFlag_TruocSau);
	//	__oMsg("IsSetSpellData	= %d", tmp.IsSetSpellData);
	//	__oMsg("\n");
	//}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void RESET_BASE_TIME(int index)
{
	////__oMsg("---BASE TIMER SPELL---[%s][%d]", __FILE__, __LINE__);
	if (index < 0)
	{
		////__oMsg("---BASE TIMER SPELL---[%s][%d]", __FILE__, __LINE__);
		for (int i = 0; i < MAX_ARRAY_BUFFER_SPELL; ++i)
		{
			RESET_BASE_TIME(i);
		}
	}
	else
	{
		////__oMsg("---BASE TIMER SPELL---[%s][%d]-----timer:%f", __FILE__, __LINE__, g_BaseTimeSpell[index].nTimer);
		g_BaseTimeSpell[index].SourcePos = KPos(0,0,0);
		g_BaseTimeSpell[index].MaxDestPos = KPos(0.,0.,0.);
		g_BaseTimeSpell[index].isCasting = false;
		g_BaseTimeSpell[index].nTimer = 0.;
		g_BaseTimeSpell[index].nSpecialTimer = 0.;
		g_BaseTimeSpell[index].IsEvaded = false;
		////__oMsg("---BASE TIMER SPELL---index: %d, sizeof(): %d", index, sizeof(KBuffer_Spell));
		PrintBaseTime(index);
		g_TimePrevious = 0;
		g_TimeNow = 0;
		g_TimeSpecial = false;
		countBiDanhBoiSkillDinhHuong = 0;
	}
}
//==================================================================================//
//==================================================================================//
//==================================================================================//
void SET_BASE_TIME_SPELL()
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return;
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return;

	int nCount = (dw2 - dw1)/4;
	////__oMsg("nCount: %d", nCount);
	KNpc *pPlayer = GetPlayer();
	BYTE isDied = (BYTE)pPlayer->nIsDie;
	if (isDied != 0) return;
	
	// set base time spell
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		bool flagSkill[4] = {false, false, false, false};
		KNpc *pEnemyPlayer = (KNpc*)dw3;
		int isDie = (BYTE)pEnemyPlayer->nIsDie;
		if (!pEnemyPlayer->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pEnemyPlayer->nHP <= 0. || !pEnemyPlayer->IsChampion())
			continue;
		float TIMEGAME = GetTimeGame();
		if (TIMEGAME < 0.) return;
		// kiem tra xem co skill xuat hien
		// Q
		KSkill*   pSkillQ = (KSkill*) pEnemyPlayer->_pSkill[0];
		if(!pSkillQ) continue;
		if ((pSkillQ->nCooldownExpires - pSkillQ->nTotalCooldown) >= (TIMEGAME - float(DELAY_GET_SPELL)/1000.)) 
		{
			KSkill_2*  pKSkill_Q = (KSkill_2*) pSkillQ->__pK_str2;
			if(!pKSkill_Q) continue;
			// SET BASE TIME_SPELL
			for(int index = 0; index < MAX_ARRAY_BUFFER_SPELL; ++index)
			{
				float fDist = Distance_2D(g_BaseTimeSpell[index].SourcePos, g_BaseTimeSpell[index].MaxDestPos);
				float nTimeCastSkill = GetTimeGame();
				if ((fDist > DISTANCE_TO_UPDATE) && strcmp(g_BaseTimeSpell[index].szSpellName, pKSkill_Q->GetSkillName()) == 0) break;
				// THEM MOI or CAP NHAT DU LIEU
				if (strlen(g_BaseTimeSpell[index].szSpellName) == 0 ||(fDist <= DISTANCE_TO_UPDATE && strcmp(g_BaseTimeSpell[index].szSpellName, pKSkill_Q->GetSkillName()) == 0))
				{
					if (nTimeCastSkill - g_BaseTimeSpell[index].nTimeGameCAST_SKILL < 1.5)
					{
						//break;
					}
					g_BaseTimeSpell[index].SourcePos.x			 = pEnemyPlayer->CurrentPos.x;
					g_BaseTimeSpell[index].SourcePos.y			 = pEnemyPlayer->CurrentPos.y;
					g_BaseTimeSpell[index].SourcePos.z			 = pEnemyPlayer->CurrentPos.z;
					DWORD movNote = (DWORD)pEnemyPlayer->_pMOVE;
					DWORD tempMov  = *(DWORD*)(movNote + 4);
					stMOVE *DestPos = (stMOVE *)tempMov;
					//stMOVE *DestPos = (stMOVE*) pEnemyPlayer->_pMOVE;
					g_BaseTimeSpell[index].MaxDestPos.x			 = DestPos->__strPosDest.x;
					g_BaseTimeSpell[index].MaxDestPos.y			 = DestPos->__strPosDest.y;
					g_BaseTimeSpell[index].MaxDestPos.z			 = DestPos->__strPosDest.z;
					g_BaseTimeSpell[index].MousePos.x			 = 0.;
					g_BaseTimeSpell[index].MousePos.y			 = 0.;
					g_BaseTimeSpell[index].MousePos.z			 = 0.;
					g_BaseTimeSpell[index].PlayerPos			 = pPlayer->CurrentPos;
					KPos *pMousePos = GetMousePos();
					g_BaseTimeSpell[index].MousePos_Player		 = *pMousePos;
					g_BaseTimeSpell[index].nTimer				 = 0.; // ????
					g_BaseTimeSpell[index].nSpecialTimer		 = 0.; // ????
					g_BaseTimeSpell[index].nTimeGameCAST_SKILL	 = nTimeCastSkill;
					//__oMsg("da update du lieu:%f;%f;%d;%s", nTimeCastSkill, g_BaseTimeSpell[index].nTimeGameCAST_SKILL, __LINE__, __FILE__);
					g_BaseTimeSpell[index].isCasting			 = true; // ????
					g_BaseTimeSpell[index].index				 = index; // ????
					g_BaseTimeSpell[index].IsEvaded				 = false;
					if (g_BaseTimeSpell[index].IsSetSpellData == true) break;
					g_BaseTimeSpell[index].IsSetSpellData			 = true;
					strcpy_s(g_BaseTimeSpell[index].szHeroName, pEnemyPlayer->GetNameHero());
					strcpy_s(g_BaseTimeSpell[index].szPlayerName, pEnemyPlayer->GetNameNpc());
					strcpy_s(g_BaseTimeSpell[index].szSpellName, pKSkill_Q->GetSkillName());
					//SetSpellData(g_BaseTimeSpell[index]);
					////__oMsg("---BASE TIMER SPELL---[%s][%d]", __FILE__, __LINE__);
					PrintBaseTime(index);
					break;	//??? de thoat khoi vong lap ngay sau khi da cap nhat hoac them moi du lieu,
					//tranh bi trung du lieu cho tat ca cac ban ghi
				}
			}
		}
		// W
		KSkill*   pSkillW = (KSkill*) pEnemyPlayer->_pSkill[1];
		if(!pSkillW) continue;
		if ((pSkillW->nCooldownExpires - pSkillW->nTotalCooldown) >= (TIMEGAME - float(DELAY_GET_SPELL)/1000.))
		{
			KSkill_2*  pKSkill_W = (KSkill_2*) pSkillW->__pK_str2;
			if(!pKSkill_W) continue;
			// SET BASE TIME_SPELL
			for(int index = 0; index < MAX_ARRAY_BUFFER_SPELL; ++index)
			{
				float fDist = Distance_2D(g_BaseTimeSpell[index].SourcePos, g_BaseTimeSpell[index].MaxDestPos);
				float nTimeCastSkill = GetTimeGame();
				if ((fDist > DISTANCE_TO_UPDATE) && strcmp(g_BaseTimeSpell[index].szSpellName, pKSkill_W->GetSkillName()) == 0) break;
				// THEM MOI or CAP NHAT DU LIEU
				if (strlen(g_BaseTimeSpell[index].szSpellName) == 0 ||(fDist <= DISTANCE_TO_UPDATE && strcmp(g_BaseTimeSpell[index].szSpellName, pKSkill_W->GetSkillName()) == 0))
				{
					if (nTimeCastSkill - g_BaseTimeSpell[index].nTimeGameCAST_SKILL < 1.0)
					{
						//break;
					}
					g_BaseTimeSpell[index].SourcePos.x			 = pEnemyPlayer->CurrentPos.x;
					g_BaseTimeSpell[index].SourcePos.y			 = pEnemyPlayer->CurrentPos.y;
					g_BaseTimeSpell[index].SourcePos.z			 = pEnemyPlayer->CurrentPos.z;
					DWORD movNote = (DWORD)pEnemyPlayer->_pMOVE;
					DWORD tempMov  = *(DWORD*)(movNote + 4);
					stMOVE *DestPos = (stMOVE *)tempMov;
					//stMOVE *DestPos = (stMOVE*) pEnemyPlayer->_pMOVE;
					g_BaseTimeSpell[index].MaxDestPos.x			 = DestPos->__strPosDest.x;
					g_BaseTimeSpell[index].MaxDestPos.y			 = DestPos->__strPosDest.y;
					g_BaseTimeSpell[index].MaxDestPos.z			 = DestPos->__strPosDest.z;
					g_BaseTimeSpell[index].MousePos.x			 = 0.;
					g_BaseTimeSpell[index].MousePos.y			 = 0.;
					g_BaseTimeSpell[index].MousePos.z			 = 0.;
					g_BaseTimeSpell[index].PlayerPos			 = pPlayer->CurrentPos;
					KPos *pMousePos = GetMousePos();
					g_BaseTimeSpell[index].MousePos_Player		 = *pMousePos;
					g_BaseTimeSpell[index].nTimer				 = 0.; // ????
					g_BaseTimeSpell[index].nSpecialTimer		 = 0.; // ????
					g_BaseTimeSpell[index].nTimeGameCAST_SKILL	 = nTimeCastSkill;
					//__oMsg("da update du lieu:%f;%f;%d;%s", nTimeCastSkill, g_BaseTimeSpell[index].nTimeGameCAST_SKILL, __LINE__, __FILE__);
					g_BaseTimeSpell[index].isCasting			 = true; // ????
					g_BaseTimeSpell[index].index				 = index; // ????
					g_BaseTimeSpell[index].IsEvaded				 = false;
					if (g_BaseTimeSpell[index].IsSetSpellData == true) break;
					g_BaseTimeSpell[index].IsSetSpellData			 = true;
					strcpy_s(g_BaseTimeSpell[index].szHeroName, pEnemyPlayer->GetNameHero());
					strcpy_s(g_BaseTimeSpell[index].szPlayerName, pEnemyPlayer->GetNameNpc());
					strcpy_s(g_BaseTimeSpell[index].szSpellName, pKSkill_W->GetSkillName());
					//SetSpellData(g_BaseTimeSpell[index]);
					////__oMsg("---BASE TIMER SPELL---[%s][%d]", __FILE__, __LINE__);
					PrintBaseTime(index);
					break;	//??? de thoat khoi vong lap ngay sau khi da cap nhat hoac them moi du lieu,
					//tranh bi trung du lieu cho tat ca cac ban ghi
				}
			}
		}
		// E
		KSkill*   pSkillE = (KSkill*) pEnemyPlayer->_pSkill[2];
		if(!pSkillE) continue;
		if ((pSkillE->nCooldownExpires - pSkillE->nTotalCooldown) >= (TIMEGAME - float(DELAY_GET_SPELL)/1000.))
		{
			KSkill_2*  pKSkill_E = (KSkill_2*) pSkillE->__pK_str2;
			if(!pKSkill_E) continue;
			// SET BASE TIME_SPELL
			for(int index = 0; index < MAX_ARRAY_BUFFER_SPELL; ++index)
			{
				float fDist = Distance_2D(g_BaseTimeSpell[index].SourcePos, g_BaseTimeSpell[index].MaxDestPos);
				float nTimeCastSkill = GetTimeGame();
				if ((fDist > DISTANCE_TO_UPDATE) && strcmp(g_BaseTimeSpell[index].szSpellName, pKSkill_E->GetSkillName()) == 0) break;
				// THEM MOI or CAP NHAT DU LIEU
				if (strlen(g_BaseTimeSpell[index].szSpellName) == 0 ||(fDist <= DISTANCE_TO_UPDATE && strcmp(g_BaseTimeSpell[index].szSpellName, pKSkill_E->GetSkillName()) == 0))
				{
					if (nTimeCastSkill - g_BaseTimeSpell[index].nTimeGameCAST_SKILL < 1.0)
					{
						//break;
					}
					g_BaseTimeSpell[index].SourcePos.x			 = pEnemyPlayer->CurrentPos.x;
					g_BaseTimeSpell[index].SourcePos.y			 = pEnemyPlayer->CurrentPos.y;
					g_BaseTimeSpell[index].SourcePos.z			 = pEnemyPlayer->CurrentPos.z;
					DWORD movNote = (DWORD)pEnemyPlayer->_pMOVE;
					DWORD tempMov  = *(DWORD*)(movNote + 4);
					stMOVE *DestPos = (stMOVE *)tempMov;
					//stMOVE *DestPos = (stMOVE*) pEnemyPlayer->_pMOVE;
					g_BaseTimeSpell[index].MaxDestPos.x			 = DestPos->__strPosDest.x;
					g_BaseTimeSpell[index].MaxDestPos.y			 = DestPos->__strPosDest.y;
					g_BaseTimeSpell[index].MaxDestPos.z			 = DestPos->__strPosDest.z;
					g_BaseTimeSpell[index].MousePos.x			 = 0.;
					g_BaseTimeSpell[index].MousePos.y			 = 0.;
					g_BaseTimeSpell[index].MousePos.z			 = 0.;
					g_BaseTimeSpell[index].PlayerPos			 = pPlayer->CurrentPos;
					KPos *pMousePos = GetMousePos();
					g_BaseTimeSpell[index].MousePos_Player		 = *pMousePos;
					g_BaseTimeSpell[index].nTimer				 = 0.; // ????
					g_BaseTimeSpell[index].nSpecialTimer		 = 0.; // ????
					g_BaseTimeSpell[index].nTimeGameCAST_SKILL	 = nTimeCastSkill;
					//__oMsg("da update du lieu:%f;%f;%d;%s", nTimeCastSkill, g_BaseTimeSpell[index].nTimeGameCAST_SKILL, __LINE__, __FILE__);
					g_BaseTimeSpell[index].isCasting			 = true; // ????
					g_BaseTimeSpell[index].index				 = index; // ????
					g_BaseTimeSpell[index].IsEvaded				 = false;
					if (g_BaseTimeSpell[index].IsSetSpellData == true) break;
					g_BaseTimeSpell[index].IsSetSpellData			 = true;
					strcpy_s(g_BaseTimeSpell[index].szHeroName, pEnemyPlayer->GetNameHero());
					strcpy_s(g_BaseTimeSpell[index].szPlayerName, pEnemyPlayer->GetNameNpc());
					strcpy_s(g_BaseTimeSpell[index].szSpellName, pKSkill_E->GetSkillName());
					//SetSpellData(g_BaseTimeSpell[index]);
					////__oMsg("---BASE TIMER SPELL---[%s][%d]", __FILE__, __LINE__);
					PrintBaseTime(index);
					break;	//??? de thoat khoi vong lap ngay sau khi da cap nhat hoac them moi du lieu,
					//tranh bi trung du lieu cho tat ca cac ban ghi
				}
			}
		}
		//R
		KSkill*   pSkillR = (KSkill*) pEnemyPlayer->_pSkill[3];
		if(!pSkillR) continue;
		if ((pSkillR->nCooldownExpires - pSkillR->nTotalCooldown) >= (TIMEGAME - float(DELAY_GET_SPELL)/1000.))
		{
			KSkill_2*  pKSkill_R = (KSkill_2*) pSkillR->__pK_str2;
			if(!pKSkill_R) continue;
			// SET BASE TIME_SPELL
			for(int index = 0; index < MAX_ARRAY_BUFFER_SPELL; ++index)
			{
				float fDist = Distance_2D(g_BaseTimeSpell[index].SourcePos, g_BaseTimeSpell[index].MaxDestPos);
				float nTimeCastSkill = GetTimeGame();
				if ((fDist > DISTANCE_TO_UPDATE) && strcmp(g_BaseTimeSpell[index].szSpellName, pKSkill_R->GetSkillName()) == 0) break;
				// THEM MOI or CAP NHAT DU LIEU
				if (strlen(g_BaseTimeSpell[index].szSpellName) == 0 ||(fDist <= DISTANCE_TO_UPDATE && strcmp(g_BaseTimeSpell[index].szSpellName, pKSkill_R->GetSkillName()) == 0))
				{
					if (nTimeCastSkill - g_BaseTimeSpell[index].nTimeGameCAST_SKILL < 1.0)
					{
						//break;
					}
					g_BaseTimeSpell[index].SourcePos.x			 = pEnemyPlayer->CurrentPos.x;
					g_BaseTimeSpell[index].SourcePos.y			 = pEnemyPlayer->CurrentPos.y;
					g_BaseTimeSpell[index].SourcePos.z			 = pEnemyPlayer->CurrentPos.z;
					DWORD movNote = (DWORD)pEnemyPlayer->_pMOVE;
					DWORD tempMov  = *(DWORD*)(movNote + 4);
					stMOVE *DestPos = (stMOVE *)tempMov;
					//stMOVE *DestPos = (stMOVE*) pEnemyPlayer->_pMOVE;
					g_BaseTimeSpell[index].MaxDestPos.x			 = DestPos->__strPosDest.x;
					g_BaseTimeSpell[index].MaxDestPos.y			 = DestPos->__strPosDest.y;
					g_BaseTimeSpell[index].MaxDestPos.z			 = DestPos->__strPosDest.z;
					g_BaseTimeSpell[index].MousePos.x			 = 0.;
					g_BaseTimeSpell[index].MousePos.y			 = 0.;
					g_BaseTimeSpell[index].MousePos.z			 = 0.;
					g_BaseTimeSpell[index].PlayerPos			 = pPlayer->CurrentPos;
					KPos *pMousePos = GetMousePos();
					g_BaseTimeSpell[index].MousePos_Player		 = *pMousePos;
					g_BaseTimeSpell[index].nTimer				 = 0.; // ????
					g_BaseTimeSpell[index].nSpecialTimer		 = 0.; // ????
					g_BaseTimeSpell[index].nTimeGameCAST_SKILL	 = nTimeCastSkill;
					//__oMsg("da update du lieu:%f;%f;%d;%s", nTimeCastSkill, g_BaseTimeSpell[index].nTimeGameCAST_SKILL, __LINE__, __FILE__);
					g_BaseTimeSpell[index].isCasting			 = true; // ????
					g_BaseTimeSpell[index].index				 = index; // ????
					g_BaseTimeSpell[index].IsEvaded				 = false;
					if (g_BaseTimeSpell[index].IsSetSpellData == true) break;
					g_BaseTimeSpell[index].IsSetSpellData			 = true;
					strcpy_s(g_BaseTimeSpell[index].szHeroName, pEnemyPlayer->GetNameHero());
					strcpy_s(g_BaseTimeSpell[index].szPlayerName, pEnemyPlayer->GetNameNpc());
					strcpy_s(g_BaseTimeSpell[index].szSpellName, pKSkill_R->GetSkillName());
					//SetSpellData(g_BaseTimeSpell[index]);
					////__oMsg("---BASE TIMER SPELL---[%s][%d]", __FILE__, __LINE__);
					PrintBaseTime(index);
					break;	//??? de thoat khoi vong lap ngay sau khi da cap nhat hoac them moi du lieu,
					//tranh bi trung du lieu cho tat ca cac ban ghi
				}
			}
		}
		
	}

	// reset base time spell
	for(int index = 0; index < MAX_ARRAY_BUFFER_SPELL; ++index)
	{
		if (strlen(g_BaseTimeSpell[index].szSpellName) == 0) continue;
		if (g_BaseTimeSpell[index].isCasting)
		{
			//__oMsg("---BASE TIMER SPELL---[%s][%d]", __FILE__, __LINE__);
			g_BaseTimeSpell[index].nTimer += SYS_TIMER;
			g_BaseTimeSpell[index].nSpecialTimer += SYS_TIMER;
		}
		if (g_BaseTimeSpell[index].nTimer >= TIME_OUT_CAST_SPELL)
		{
			UnBlockMove();
			RESET_BASE_TIME(index);
		}
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
float GetTimeGame_OLD()
{
	return -111111.0;
	/*DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return -1.;
	DWORD nTempBASE_TIME = BASE_TIME - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = *(DWORD *)nTempBASE_TIME;
	if (dw1 == NULL) return -1.;
	KTimer *timeGame = (KTimer *)dw1;
	return timeGame->nTime_Game;*/
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
float GetTimeGame()
{
	//return GetTimeGame_Dubi();


	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return -1.;
	DWORD nBASE_GAME_TIME1 = BASE_GAME_TIME1 - TEMP_ENTRY_POINT + hModule;
	//DWORD nBASE_GAME_TIME2 = BASE_GAME_TIME2 - TEMP_ENTRY_POINT + hModule;
	DWORD nGET_GAMETIME_FUNC = GET_GAMETIME_FUNC - TEMP_ENTRY_POINT + hModule;

	//DWORD dw4 = *(DWORD *)nBASE_GAME_TIME2;
	//__oMsg("dw4=%x", dw4);
	//if (dw4 == NULL) return -1.;
	//float timeGame = *(float *)(dw4 + 4);
	float timeGame = -1;
	//__oMsg("timegame2=%f", timeGame);

	DWORD dw1 = *(DWORD *)nBASE_GAME_TIME1;
	if (dw1 == NULL) return timeGame;
	DWORD dw2 = *(DWORD *)(dw1 + 0x8);
	if (dw2 == NULL) return timeGame;
	/*DWORD dw3 = *(DWORD *)(dw2 + 324);
	if (dw3 == NULL) return timeGame;*/

	//DWORD dw3 = *(DWORD *)(dw1 + 28);
	//if (dw3 == NULL) return timeGame;

	//if (dw1 && (BYTE)dw3)
	if (dw1)
	{
		/*DWORD dw5 =  *(DWORD *)(dw1 + 12);
		if (dw5 == NULL) return timeGame;*/
		DWORD __ECX = dw2;
		if (__ECX == NULL) return timeGame;
		/*DWORD nThamSo1 = *(DWORD *)(dw5 + 4);
		float nThamSo2 = 0;
		DWORD nDC = (DWORD)&nThamSo2;*/
		//return 1;
		DWORD nThamSo2 = 0;
		__asm
		{
			mov ecx, __ECX
			mov eax, nGET_GAMETIME_FUNC
			call eax
			//movss nThamSo2, xmm0
			fstp    dword ptr [esp]
			mov eax,    dword ptr [esp]
			mov nThamSo2, eax
		}
		//__oMsg("tham so 2=%x", nThamSo2);
		if (nThamSo2 != 0)
			timeGame = *(float*)&nThamSo2;
		//__oMsg("timegame1=%f", timeGame);
	}
	return timeGame;
}

float GetTimeGame_Test()
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return -1;
	DWORD nTempBASE_TIME_DUBI = BASE_GAME_TIME_NOW_X - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = nTempBASE_TIME_DUBI;
	
	float timeGame = *(float*)(dw1);
	return timeGame;
}

//==================================================================================//
float GetTimeGame_Dubi()
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return -1;
	DWORD nTempBASE_TIME_DUBI = BASE_TIME_DU_BI - TEMP_ENTRY_POINT + hModule;
	DWORD dw1 = nTempBASE_TIME_DUBI;
	if (dw1 == NULL) return -1;
	float timeGame = *(float*)(dw1 + 0x30);
	return timeGame;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void AUTO_DODGE_BASETIME()
{
	KNpc *pEnemyPlayer = NULL;// GetEnemyPlayer("XXX");
	//PBOOLEAN BeingDebugged=(PBOOLEAN)__readfsdword(0x30)+2;
	//if(*BeingDebugged) // Read the PEB
	//{
	//	CAntiDebugger::GetInstance()->TERMINATE_ALL();
	//}
	//if(CAntiDebugger::GetInstance()->MemoryBreakpointDebuggerCheck())
	//{
	//	CAntiDebugger::GetInstance()->TERMINATE_ALL();
	//}
	KNpc *pPlayer = GetPlayer();
	if ((BYTE)pPlayer->nIsDie == 1)
	{
		UnBlockMove();
		return;
	}
	if ((BYTE)pPlayer->nIsCastingSpell == 1)
	{
		// kiem tra xem co hero nao ra skill
		KCastSpell *pCastSpell = (KCastSpell *)pPlayer->_pCastSpell;
		if (pCastSpell == NULL) return;
		KSkill_2 *pSkill_2 = (KSkill_2 *)pCastSpell->__pK_str2;
		if (pSkill_2 == NULL) return;
		if (!CheckName( (sz__recall), pSkill_2->GetSkillName())) return;
	}
	
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void WINAPI PRINT_SKILL()
{
	//KNpc*   g_pPlayer = GetPlayer();
	//if(!g_pPlayer) return;

	//KSkill*   pSkill = (KSkill*) g_pPlayer->_pSkill[0];
	//if(!pSkill) return;
	//KSkill_1*  pKSkill_1 = (KSkill_1*) pSkill->__pK_str1;
	//if(!pKSkill_1) return;

	//KCastSpell *pCastSpell = (KCastSpell *)g_pPlayer->_pCastSpell;
	//if(pCastSpell != 0){
	//	//__oMsg("g_pPlayer : %x", g_pPlayer);
	//	//__oMsg("pSkill[2] : %x", pSkill);
	//	//__oMsg("pKSkill_1 : %x", pKSkill_1);

	//	//__oMsg("================pSKILL========================================================");
	//	//__oMsg("pKSkill_1->MaxDestPosX	: %f", pKSkill_1->MaxDestPos.x);
	//	//__oMsg("pKSkill_1->MaxDestPosZ	: %f", pKSkill_1->MaxDestPos.z);
	//	//__oMsg("pKSkill_1->MousePosX	: %f", pKSkill_1->MousePos.x);
	//	//__oMsg("pKSkill_1->MousePosZ	: %f", pKSkill_1->MousePos.z);
	//	//__oMsg("pKSkill_1->SourcePosX	: %f", pKSkill_1->SourcePos.x);
	//	//__oMsg("pKSkill_1->SourcePosZ	: %f", pKSkill_1->SourcePos.z);
	//	//__oMsg("\n");

	//	//__oMsg("================pCAST_SPELL===================================================");
	//	//__oMsg("pCastSpell->MaxDestPosX : %f", pCastSpell->MaxDestPos.x);
	//	//__oMsg("pCastSpell->MaxDestPosZ : %f", pCastSpell->MaxDestPos.z);
	//	//__oMsg("pCastSpell->MousePosX	: %f", pCastSpell->MousePos.x);
	//	//__oMsg("pCastSpell->MousePosZ	: %f", pCastSpell->MousePos.z);
	//	//__oMsg("pCastSpell->SourcePosX  : %f", pCastSpell->SourcePos.x);
	//	//__oMsg("pCastSpell->SourcePosZ	: %f", pCastSpell->SourcePos.z);
	//	//__oMsg("\n");

	//	//__oMsg("================LIST SKILL===================================================");
	//	KSkill*   p_Skill;
	//	KSkill_2*  p_Skill_2;
	//	for(int i=0; i<63; i++){
	//		p_Skill = (KSkill*) g_pPlayer->_pSkill[i];
	//		//__oMsg("[%d] pSkill : %x", i, p_Skill);
	//		if(!p_Skill) continue;

	//		p_Skill_2 = (KSkill_2*) p_Skill->__pK_str2;
	//		if(!p_Skill_2) continue;
	//		__oMsg("[%d] pSkill : %x, pSkill_2 : %x, Skill Name : %s", i, p_Skill, p_Skill_2, p_Skill_2->GetSkillName());
	//	}
	//}
	//g_tDelay = 0.;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
int CanCastSpell2(int STT_SKILL)
{
////VMProtectBegin("DLL_VM__CanCastSpell2");
	

	KNpc*   p_Player = GetPlayer();
	if(!p_Player) return 0;


	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc = CAN_CASTSPELL2_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX  = (DWORD)(p_Player) + OFF_THIS_CAST_SPELL_XYZ;
	int v8 = 0;
	int nBuffer = (int)&v8;
	int result = 0;

	__asm{
		push nBuffer
		push STT_SKILL
		mov ecx,_ECX
		mov eax,nFunc
		call eax
		mov result,eax
	}
////VMProtectEnd();
	return (BYTE)result;
}

//==================================================================================//
int CanCastSpell4Lua(int STT_SKILL)
{
	KNpc*   p_Player = GetPlayer();
	if(!p_Player) return 0;


	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc = CAN_CASTSPELL2_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX  = (DWORD)(p_Player) + OFF_THIS_CAST_SPELL_XYZ;
	int v8 = 0;
	int nBuffer = (int)&v8;
	int result = 0;

	__asm{
			push nBuffer
			push STT_SKILL
			mov ecx,_ECX
			mov eax,nFunc
			call eax
			mov result,eax
	}
	return (BYTE)result;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool DO_FLASH(KPos* maxDest)
{
	KNpc*   p_Player = GetPlayer();
	if(!p_Player) return false;
	for (int i = 0; i < 20; ++i)
	{
		KSkill *pSkill = (KSkill *)p_Player->_pSkill[i];
		if(!pSkill) continue;
		KSkill_2*  pKSkill_2GetName = (KSkill_2*) pSkill->__pK_str2;
		if(!pKSkill_2GetName) continue;
		if (CheckName(pKSkill_2GetName->GetSkillName(),  (sz__SummonerFlash)) && CheckName( (sz__SummonerFlash), pKSkill_2GetName->GetSkillName()))
		{
			if (CanCastSpell2(i) != 0) return false;
		////VMProtectBegin("DLL_VM__DO_FLASH");
			DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
			DWORD nFunc = CAST_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;

			DWORD _ECX  = (DWORD)(p_Player) + OFF_THIS_CAST_SPELL_XYZ;
			DWORD nDest = (DWORD)&maxDest->x;
			int nIndex = i;

			float buffMouse[3]		 = {0,0,0};
			DWORD nBuffer = (DWORD)&buffMouse[0];
			__asm{
				push 0
				push nBuffer
				push nDest
				push nIndex
				push pSkill
				mov ecx,_ECX
				mov eax,nFunc
				call eax
			}
		////VMProtectEnd();
			return true;
		}
	}
	return false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool DO_THIEU_DOT(KNpc* pEnemy, bool flag_kocantinhmau)
{
	KNpc*   p_Player = GetPlayer();
	if(!p_Player) return false;
	if ((BYTE)p_Player->nIsDie == 1) return false;

	for (int i = 0; i < 20; ++i)
	{
		KSkill *pSkill = (KSkill *)p_Player->_pSkill[i];
		if(!pSkill) continue;
		KSkill_2*  pKSkill_2GetName = (KSkill_2*) pSkill->__pK_str2;
		if(!pKSkill_2GetName) continue;
		if (CheckName(pKSkill_2GetName->GetSkillName(),  (sz__SummonerDot)) && CheckName( (sz__SummonerDot), pKSkill_2GetName->GetSkillName()))
		{
			float nDamage = (float)(50 + (BYTE)p_Player->nLevel * 20);
			if(flag_kocantinhmau == false)
			{
				if (pEnemy->nHP >= nDamage) return false;
			}
			if (CanCastSpell2(i) != 0) return false;
		////VMProtectBegin("DLL_VM__DO_THIEU_DOT");
			DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
			DWORD nFunc		= CAST_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
			DWORD _ECX		= (DWORD)(p_Player) + OFF_THIS_CAST_SPELL_XYZ;

			DWORD nDest		= (DWORD)&pEnemy->CurrentPos.x;
			DWORD nIndex	= pEnemy->nIndex;

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
		////VMProtectEnd();
			return true;
		}
	}
	return false;
}

//==================================================================================//
bool DO_IGNITE(KNpc* pEnemy)
{
	if(!G_Module)				  return false;
	
	KNpc* pPlayer = GetPlayer();
	if(!pPlayer)		  return false;
	if(pPlayer->isDead()) return false;

	for(int i = 4; i < 6; ++i)
	{
		KSkill *pSkill = (KSkill *)pPlayer->_pSkill[i];
		if(!pSkill) continue;
		KSkill_2*  pKSkill_2GetName = (KSkill_2*) pSkill->__pK_str2;
		if(!pKSkill_2GetName) continue;
		if(CheckName(pKSkill_2GetName->GetSkillName(), sz__SummonerDot) && CheckName(sz__SummonerDot, pKSkill_2GetName->GetSkillName()))
		{
			if(CanCastSpell2(i) != 0) return false;
	
			DWORD nFunc		= CAST_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + G_Module;
			DWORD _ECX		= (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;		
			DWORD nDest		= (DWORD)&pEnemy->CurrentPos.x;
			DWORD nIndex	= pEnemy->nIndex;

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
			return true;
		}
	}
	return false;
}

//==================================================================================//
//==================================================================================//
bool DO_HOI_MAU_SKILL()
{
	KNpc*   pPlayer = GetPlayer();
	if(!pPlayer) return false;
	if ((BYTE)pPlayer->nIsDie == 1) return false;

	for (int i = 0; i < 20; ++i)
	{
		KSkill *pSkill = (KSkill *)pPlayer->_pSkill[i];
		if(!pSkill) continue;
		KSkill_2*  pKSkill_2GetName = (KSkill_2*) pSkill->__pK_str2;
		if(!pKSkill_2GetName) continue;
		if (CheckName(pKSkill_2GetName->GetSkillName(), sz__SummonerHeal) && CheckName(sz__SummonerHeal, pKSkill_2GetName->GetSkillName()))
		{
			if (CanCastSpell2(i) != 0) return false;
		////VMProtectBegin("DLL_VM__DO_HOI_MAU_SKILL");
			DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
			DWORD nFunc		= CAST_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
			DWORD _ECX		= (DWORD)(pPlayer) + OFF_THIS_CAST_SPELL_XYZ;

			DWORD nDest		= (DWORD)&pPlayer->CurrentPos.x;
			DWORD nIndex	= pPlayer->nIndex;

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
		////VMProtectEnd();
			return true;
		}
	}
	return false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
bool DO_RECALL_SKILL()
{
	KNpc*   p_Player = GetPlayer();
	if(!p_Player) return false;
	if ((BYTE)p_Player->nIsDie == 1) return false;

	for (int i = 0; i < 20; ++i)
	{
		KSkill *pSkill = (KSkill *)p_Player->_pSkill[i];
		if(!pSkill) continue;
		KSkill_2*  pKSkill_2GetName = (KSkill_2*) pSkill->__pK_str2;
		if(!pKSkill_2GetName) continue;
		if (CheckName(pKSkill_2GetName->GetSkillName(),  (sz__recall)) && CheckName( (sz__recall), pKSkill_2GetName->GetSkillName()))
		{
			if (CanCastSpell2(i) != 0) return false;
		////VMProtectBegin("DLL_VM__DO_RECALL_SKILL");
			DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
			DWORD nFunc		= CAST_SPELL_XYZ_FUNC - TEMP_ENTRY_POINT + hModule;
			DWORD _ECX		= (DWORD)(p_Player) + OFF_THIS_CAST_SPELL_XYZ;

			DWORD nDest		= (DWORD)&p_Player->CurrentPos.x;
			DWORD nIndex	= p_Player->nIndex;

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
		////VMProtectEnd();
			return true;
		}
	}
	return false;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void AutoTHIEU_DOT()
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return;
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;

	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return;

	KNpc *pPlayer = GetPlayer();
	int nCount = (dw2 - dw1)/4;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyPlayer = (KNpc*)dw3;
		int isDie = (BYTE)pEnemyPlayer->nIsDie;
		if (!pEnemyPlayer->IsEnemy(pPlayer->nTeam_ID) || isDie == 1 || pEnemyPlayer->nHP <= 0. || !pEnemyPlayer->IsChampion())
			continue;
		float fdistance = Distance_2D(pPlayer->CurrentPos, pEnemyPlayer->CurrentPos);
		if (fdistance > KHOANG_CACH_THIEU_DOT) continue;
		DO_THIEU_DOT(pEnemyPlayer);
	}
}

//==================================================================================//
void PrintCastSpell(KNpc *pNpc)
{
	//KNpc *kGetPlayer = pNpc;
	//KNpc *kGetPlayer = GetPlayer();
	////__oMsg("[%x - %x] DWORD *_pCastSpell : %x", &kGetPlayer->_pCastSpell, (DWORD)&kGetPlayer->_pCastSpell - (DWORD)kGetPlayer, kGetPlayer->_pCastSpell);
	//KCastSpell *pCastSpell = (KCastSpell *)kGetPlayer->_pCastSpell;
	//if (pCastSpell == NULL) return;
	//KSkill_2 *pSkill_2 = (KSkill_2 *)pCastSpell->__pK_str2;
	//if (pSkill_2 == NULL) return;
	//KSkill_3_Temp *pSkill_3_Temp = (KSkill_3_Temp *)pSkill_2->__pK_str3;
	//if (pSkill_3_Temp == NULL) return;
	//__oMsg("================SKILL INFO=================================");
	//__oMsg("radius_CIRCLE			: %f", pSkill_3_Temp->nCast_Radius);
	//__oMsg("RADIUS_line				: %f", pSkill_3_Temp->nLine_Width);
	//__oMsg("temp1[239]				: %f", float(pSkill_3_Temp->nTemp_1[239]));
	//__oMsg("[%x]range				: %f", &pSkill_3_Temp->nCast_Range, pSkill_3_Temp->nCast_Range);
	//__oMsg("nCastConeAngle			: %f", pSkill_3_Temp->nCastConeAngle);
	//__oMsg("[%x]nCastConeDistance	: %f", &pSkill_3_Temp->nCastConeDistance, pSkill_3_Temp->nCastConeDistance);
	//__oMsg("nLine_DragLength		: %f", pSkill_3_Temp->nLine_DragLength);
	//__oMsg("nMissileSpeed			: %f", pSkill_3_Temp->nMissileSpeed);
	//__oMsg("nMissileAccel			: %f", pSkill_3_Temp->nMissileAccel);
	//__oMsg("nMissile_MaxSpeed		: %f", pSkill_3_Temp->nMissile_MaxSpeed);
	//__oMsg("nMissile_MinSpeed		: %f", pSkill_3_Temp->nMissile_MinSpeed);
	//__oMsg("[%x]nTargettingType		: %d\n\n", &pSkill_3_Temp->nTargettingType, (BYTE)pSkill_3_Temp->nTargettingType);
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void StrReplace(char * inputStr, char needReplace, char toReplace)
{
	int len = strlen(inputStr);
	for (int i = 0; i < len; ++i)
	{
		if (inputStr[i] == needReplace)
		{
			inputStr[i] = toReplace;
		}
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
CTextEncryptMgr* CTextEncryptMgr::s_Instance = NULL;
CTextEncryptMgr::CTextEncryptMgr()
{}
CTextEncryptMgr::~CTextEncryptMgr()
{}
char* CTextEncryptMgr::FindTextDecrypted(std::string &str2Find)
{
	int left = 0;
	int right = m_TextDecrypted.size() - 1;
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (0 == str2Find.compare(m_TextDecrypted[mid]) )
			return m_TextDecrypted[mid];
		else if (str2Find.compare(m_TextDecrypted[mid]) < 0) 
			right = mid - 1;
		else if (str2Find.compare(m_TextDecrypted[mid]) > 0) 
			left = mid + 1;
	} 
	return NULL;
}
CTextEncryptMgr* CTextEncryptMgr::GetInstance()
{
	if (s_Instance == NULL)
	{
		s_Instance = new CTextEncryptMgr;
	}
	return s_Instance;
}
char* CTextEncryptMgr::GetTextDecrypted(int *inputArr)
{
	int key[3] = {13, 26 , 39};
	//char key[3] = {'K', 'C', 'Q'};
	std::string ketQua = "";
	ketQua.insert(0, 1, *inputArr);
	for (int index = 1;inputArr[index] != -1; ++index)
	{
		char ch =  char( ((inputArr[index])^key[index%(sizeof(key)/sizeof(int))])/7-13-(*inputArr) );
		//char ch =  char( ( ( (inputArr[index])-(*inputArr) )^3 )/7-13);
		ketQua.insert(index, 1, ch);
	}

	char* findIter = FindTextDecrypted(ketQua);
	if (findIter != NULL)
	{
		return findIter;
	}

	//std::cout << "[chuaco], tao moi roi them vao danh sach:" << ketQua.c_str() << std::endl;
	//__oMsg("[chuaco], tao moi roi them vao danh sach:%s", ketQua.c_str());
	char * tmp = new char[ketQua.size() + 1];
	strcpy_s(tmp, ketQua.size() + 1, ketQua.c_str());
	ketQua.clear();
	m_TextDecrypted.push_back(tmp);
	std::sort (m_TextDecrypted.begin(), m_TextDecrypted.end(), compare_case);

	return tmp;
}

// comparison, not case sensitive.
bool compare_nocase (const char* first, char* second)
{
	unsigned int i=0;
	unsigned int firstLen = strlen(first);
	unsigned int secondLen = strlen(second);
	while ( (i<firstLen) && (i<secondLen) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( firstLen < secondLen );
}

// comparison, case sensitive.
bool compare_case (const char* first, const char* second)
{
	unsigned int i=0;
	unsigned int firstLen = strlen(first);
	unsigned int secondLen = strlen(second);
	//__oMsg("check:%s---%s", first, second);
	while ( (i<firstLen) && (i<secondLen) )
	{
		if (first[i] < second[i]) return true;
		else if (first[i] > second[i]) return false;
		++i;
	}
	return ( firstLen < secondLen );
}

char* ArrInt2Str(int * inputArr)
{
	return CTextEncryptMgr::GetInstance()->GetTextDecrypted(inputArr);
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
wchar_t* C2W(const char *strInput)
{
	int leng = strlen(strInput);
	wchar_t* ketqua = new wchar_t[leng + 1];
	for (int i = 0; i < leng; ++i)
		ketqua[i] = strInput[i];
	ketqua[leng] = '\0';
	return ketqua;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
char* W2C(const wchar_t *strInput)
{
	int leng = wcslen(strInput);
	char* ketqua = new char[leng + 1];
	for (int i = 0; i < leng; ++i)
		ketqua[i] = strInput[i];
	ketqua[leng] = '\0';
	return ketqua;
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void HackZoom_Tang()
{
	//return;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return;
	DWORD nTempBASE_SKILL = BASE_SKILL - TEMP_ENTRY_POINT + hModule;

	DWORD dw1 = *(DWORD*)nTempBASE_SKILL;
	//__oMsg("%x",dw1);
	if(!dw1) return;
	DWORD dw2 = *(DWORD*)(dw1 + 0xC);
	//__oMsg("%x",dw2);
	if(!dw2) return;

	KHackZoom* pHackZoom = (KHackZoom*)dw2;
	//__oMsg("[%x] : %f",&pHackZoom->nHackZoom, pHackZoom->nHackZoom);
	if(pHackZoom->nHackZoom < 4)
	{
		pHackZoom->nHackZoom += (float)0.1;
	}
	//__oMsg("HZ_2 : %f",pHackZoom->nHackZoom);
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void HackZoom_Giam()
{
	//return;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return;
	DWORD nTempBASE_SKILL = BASE_SKILL - TEMP_ENTRY_POINT + hModule;

	DWORD dw1 = *(DWORD*)nTempBASE_SKILL;
	if(!dw1) return;
	DWORD dw2 = *(DWORD*)(dw1 + 0xC);
	if(!dw2) return;

	KHackZoom* pHackZoom = (KHackZoom*)dw2;
	if(pHackZoom->nHackZoom > (float)1.29)
	{
		pHackZoom->nHackZoom -= (float)0.1;
	}
}

//==================================================================================//
//==================================================================================//
//==================================================================================//
void MOD_SKIN(DWORD szNameHero, int skinID, KNpc* pNPC)
{
	//return;
	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc_1	= MODSKIN_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD nFunc_2 	= MODSKIN_HU1_FUNC - TEMP_ENTRY_POINT + hModule;
	DWORD nFunc_3 	= MODSKIN_HU2_FUNC - TEMP_ENTRY_POINT + hModule;
	//nFunc_3			= 0xB7CE30; (v7.7)
	if(pNPC == 0)
	{
		pNPC = GetPlayer();
	}
	if(pNPC == 0 ) return;

	int nTeamID = pNPC->nTeam_ID;

	DWORD pName_Hero   = (DWORD)&pNPC->szName_Hero;		// ten Champ
	if((BYTE)pNPC->nLen_Name_Hero > 15)
	{
		pName_Hero	   = *(DWORD*)&pNPC->szName_Hero;
	}

	DWORD pName_Player = (DWORD)&pNPC->szPlayerName;	// ten Nguoi choi
	if((BYTE)pNPC->nLen_Name > 15)
	{
		pName_Player   = *(DWORD*)&pNPC->szPlayerName;
	}
// --- ModSkin : Hinh Anh ---------------------------------------------------------
	//if (szNameHero )	pName_Hero = szNameHero;
	DWORD _ECX	= (DWORD)pNPC;
	__asm{
		push 0
		push skinID
		push pName_Hero
		mov ecx, _ECX
		mov eax,nFunc_1
		call eax
	}
	
	
// --- ModSkin : Hieu Ung Cac Kieu -------------------------------------------------
	int _EDX		  = skinID;
	_ECX			  = pName_Hero;
	DWORD nSkinObject = 0;
	__asm{
		push 0
		push _EDX
		push _ECX
		mov eax,nFunc_2
		call eax
		add esp, 0xC
		mov nSkinObject, eax

		//mov edx, _EDX
		//mov ecx, _ECX
		//mov eax,nFunc_2
		//call eax
		//add esp, 8
		//mov nSkinObject, eax
	}
	//return;
	if(nSkinObject)
	{
		DWORD a1 = pName_Player;
		_ECX	 = (DWORD)pNPC;
		__asm{
			push nSkinObject
			push a1
			mov ecx,_ECX
			mov ebx,nFunc_3
			call ebx
		}
		//pNPC->nTeam_ID = nTeamID;
		pNPC->nModSkinID = skinID;
	}
}

//==================================================================================//
bool IsWall(KPos* pPos)
{
	bool bIsWall    = false;
	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_MAPDATA = BASE_MAPDATA - TEMP_ENTRY_POINT + hModule;
	DWORD dw 		= *(DWORD*)nTempBASE_MAPDATA;
	if(!dw)	return false;

	KWorldData* pWolrdData = (KWorldData*)dw;
	
	float pCell_PosX = (float)((pPos->x - pWolrdData->fOffsetX) * pWolrdData->fCellScale);
	float pCell_PosZ = (float)((pPos->z - pWolrdData->fOffsetZ) * pWolrdData->fCellScale);
	
	int nCellCountX_Tru1 = pWolrdData->nCellCountX - 1;
	if ( (int)pCell_PosX <= nCellCountX_Tru1 )
	{
		nCellCountX_Tru1 = (int)pCell_PosX;
		if ( (int)pCell_PosX < 0 )
			nCellCountX_Tru1 = 0;
	}

	int nCellCountZ_Tru1 = pWolrdData->nCellCountZ - 1;
	if ( (int)pCell_PosZ <= nCellCountZ_Tru1 )
	{
		nCellCountZ_Tru1 = (int)pCell_PosZ;
		if ( (int)pCell_PosZ < 0 )
			nCellCountZ_Tru1 = 0;
	}

	DWORD nCell_Info = pWolrdData->pCellInfo + 8 * (nCellCountX_Tru1 + nCellCountZ_Tru1 * pWolrdData->nCellCountX);

	if(nCell_Info)
	{
		DWORD dw1 = *(DWORD*)(nCell_Info + 4);
		DWORD dw2 = *(DWORD*)(nCell_Info + 8);
		//__oMsg("xxx : %x - %d - %d - %d - %d", nCell_Info, (WORD)dw1, (WORD)dw2, (WORD)dw1 >>2, (WORD)dw1 >>6);
		if((WORD)dw1 >> 1 == 1 || (WORD)dw1 >> 6 == 1)
		{
			bIsWall = true;
			//__oMsg("Wall or Building: %d - %d ", dw1 >> 1, dw1 >> 6);
			return bIsWall;
		}
	}
	return bIsWall;
}

//==================================================================================//
bool IsWall(Vec3D* vPos)
{
	bool bIsWall    = false;
	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nTempBASE_MAPDATA = BASE_MAPDATA - TEMP_ENTRY_POINT + hModule;
	DWORD dw 		= *(DWORD*)nTempBASE_MAPDATA;
	if(!dw)	return false;

	KWorldData* pWolrdData = (KWorldData*)dw;

	float pCell_PosX = (float)((vPos->x - pWolrdData->fOffsetX) * pWolrdData->fCellScale);
	float pCell_PosZ = (float)((vPos->z - pWolrdData->fOffsetZ) * pWolrdData->fCellScale);

	int nCellCountX_Tru1 = pWolrdData->nCellCountX - 1;
	if ( (int)pCell_PosX <= nCellCountX_Tru1 )
	{
		nCellCountX_Tru1 = (int)pCell_PosX;
		if ( (int)pCell_PosX < 0 )
			nCellCountX_Tru1 = 0;
	}

	int nCellCountZ_Tru1 = pWolrdData->nCellCountZ - 1;
	if ( (int)pCell_PosZ <= nCellCountZ_Tru1 )
	{
		nCellCountZ_Tru1 = (int)pCell_PosZ;
		if ( (int)pCell_PosZ < 0 )
			nCellCountZ_Tru1 = 0;
	}

	DWORD nCell_Info = pWolrdData->pCellInfo + 8 * (nCellCountX_Tru1 + nCellCountZ_Tru1 * pWolrdData->nCellCountX);

	if(nCell_Info)
	{
		DWORD dw1 = *(DWORD*)(nCell_Info + 4);
		DWORD dw2 = *(DWORD*)(nCell_Info + 8);
		//__oMsg("xxx : %x - %d - %d - %d - %d", nCell_Info, (WORD)dw1, (WORD)dw2, (WORD)dw1 >>2, (WORD)dw1 >>6);
		if((WORD)dw1 >> 1 == 1 || (WORD)dw1 >> 6 == 1)
		{
			bIsWall = true;
			//__oMsg("Wall or Building: %d - %d ", dw1 >> 1, dw1 >> 6);
			return bIsWall;
		}
	}
	return bIsWall;
}

//==================================================================================//
//==================================================================================//
float Get_AA_Delay(KNpc* pNPC)
{
	float nDelay = 0;
	if(pNPC == 0)
	{
		pNPC = GetPlayer();
	}
	if(pNPC == 0) return nDelay;

	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= GET_AA_DELAY_FUNC - TEMP_ENTRY_POINT + hModule;

	DWORD STT_AA	= 0x40;
	DWORD _ECX		= (DWORD)pNPC;
	DWORD nThamSo2 = 0;
	__asm{
			//mov edx, STT_AA
			//mov ecx, _ECX
			//push STT_AA
			push _ECX
			mov ebx, nFunc
			call ebx
			
			//movss nDelay, xmm0
			movss   dword ptr [esp], xmm0
			fstp    dword ptr [esp]
			mov eax,    dword ptr [esp]
			mov nThamSo2, eax
			add esp, 0x4
	}
	if (nThamSo2 != 0)
		nDelay = *(float*)&nThamSo2;
	return nDelay;
}

//==================================================================================//
//==================================================================================//
float Get_AA_Animate_Delay(KNpc* pNPC)
{
	float nDelay = (float)0.3;
	if(pNPC == 0)
	{
		pNPC = GetPlayer();
	}
	if(pNPC == 0) return nDelay;

	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= GET_AA_ANIMATE_DELAY_FUNC - TEMP_ENTRY_POINT + hModule;

	DWORD STT_AA	= 0x40;
	DWORD _ECX		= (DWORD)pNPC;
	DWORD nThamSo2 = 0;
	__asm{
			//mov edx, STT_AA
			//mov ecx, _ECX
			push STT_AA
			push _ECX
			mov ebx, nFunc
			call ebx
			
			//movss nDelay, xmm2
			movss   dword ptr [esp], xmm2
			fstp    dword ptr [esp]
			mov eax,    dword ptr [esp]
			mov nThamSo2, eax
			add esp, 0x8
	}
	if (nThamSo2 != 0)
		nDelay = *(float*)&nThamSo2;

	if(nDelay < (float)0.1) nDelay = (float)0.1;
	return nDelay;
}

//==================================================================================//
float GET_CDBA_NEW(KNpc* pNpc)
{
	if(!pNpc) return 0;

	float nRs = 0;
	DWORD nFunc = GET_CDBA_NEW_FUNC - TEMP_ENTRY_POINT + G_Module;
	DWORD _ECX 		= (DWORD)pNpc;
	DWORD nThamSo2 = 0;

	__asm{

			mov ecx,_ECX
			mov eax,nFunc
			call eax

			//mov nRs, eax

			movss   dword ptr [esp], xmm0
			fstp    dword ptr [esp]
			mov eax,    dword ptr [esp]
			mov nThamSo2, eax

			//mov nThamSo2, eax


			//fstp    dword ptr [esp + 0x18]
			//movss   xmm0, dword ptr [esp + 0x18]
			//movss	abc, xmm0
	}
	if (nThamSo2 != 0)
		nRs = *(float*)&nThamSo2;

	
	//DWORD nThamSo2 = 456;
	//__oMsg("nRs: %x - %f, nThamSo2=%x, abc=%f", nRs, nRs, nThamSo2, abc);
	return nRs;
}

//==================================================================================//
DWORD GET_PMOVE_NEW(KNpc* pNpc)
{
	if(!pNpc) return 0;

	DWORD nRs = 0;
	DWORD nFunc = GET_PMOVE_FUNC - TEMP_ENTRY_POINT + G_Module;
	DWORD _ECX 		= (DWORD)pNpc;

	__asm{
			mov ecx,_ECX
			mov eax,nFunc
			call eax
			mov nRs, eax
			//add esp, 4
	}

	return nRs;
}

//==================================================================================//
bool IS_HERO(KNpc* pNpc)
{
	if(!pNpc) return false;

	DWORD nRs = 0;
	DWORD nFunc = IS_HERO_FUNC - TEMP_ENTRY_POINT + G_Module;
	DWORD arg1 = (DWORD)pNpc;

	__asm{
			push arg1
			mov ebx,nFunc
			call ebx
			mov nRs, eax
			add esp, 4
	}

	return (BYTE)nRs == 0 ? false : true;
}

//==================================================================================//
bool IS_MINION(KNpc* pNpc)
{
	if(!pNpc) return false;

	DWORD nRs = 0;
	DWORD nFunc = IS_MINION_FUNC - TEMP_ENTRY_POINT + G_Module;
	DWORD arg1 = (DWORD)pNpc;

	__asm{
			push arg1
			mov ebx,nFunc
			call ebx
			mov nRs, eax
			add esp, 4
	}

	return (BYTE)nRs == 0 ? false : true;
}

//==================================================================================//
bool IS_TURRET(KNpc* pNpc)
{
	if(!pNpc) return false;

	DWORD nRs = 0;
	DWORD nFunc = IS_TURRET_FUNC - TEMP_ENTRY_POINT + G_Module;
	DWORD arg1 = (DWORD)pNpc;

	__asm{
			push arg1
			mov ebx,nFunc
			call ebx
			mov nRs, eax
			add esp, 4
	}

	return (BYTE)nRs == 0 ? false : true;
}

//==================================================================================//
bool IS_NEXUS(KNpc* pNpc)
{
	if(!pNpc) return false;

	DWORD nRs = 0;
	DWORD nFunc = IS_NEXUS_FUNC - TEMP_ENTRY_POINT + G_Module;
	DWORD arg1 = (DWORD)pNpc;

	__asm{
			push arg1
			mov ebx,nFunc
			call ebx
			mov nRs, eax
			add esp, 4
	}

	return (BYTE)nRs == 0 ? false : true;
}

//==================================================================================//
bool IS_INHIBITOR(KNpc* pNpc)
{
	if(!pNpc) return false;

	DWORD nRs = 0;
	DWORD nFunc = IS_INHIBITOR_FUNC - TEMP_ENTRY_POINT + G_Module;
	DWORD arg1 = (DWORD)pNpc;

	__asm{
			push arg1
			mov ebx,nFunc
			call ebx
			mov nRs, eax
			add esp, 4
	}

	return (BYTE)nRs == 0 ? false : true;
}

////==================================================================================//
//bool IS_CAN_SEE(KNpc* pNpc)		//--not solved yet
//{
//	if(!pNpc) return false;
//	return true;	//tam lay bang true het
//}
//
////==================================================================================//
//bool IS_DEAD(KNpc* pNpc)		//--not solved yet
//{
//	if(!pNpc) return false;
//	return pNpc->nHP <= 0 ? true : false;
//}

//==================================================================================//
DWORD Get_BasicAttack(KNpc* pNPC)
{
	DWORD nRs = 0;
	if(pNPC == 0)
	{
		pNPC = GetPlayer();
	}
	if(pNPC == 0) return nRs;

	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= GET_BASIC_ATTACK_FUNC - TEMP_ENTRY_POINT + hModule;

	DWORD STT_AA	= 0x40;
	DWORD _ECX		= (DWORD)pNPC;

	__asm{
		push STT_AA
		mov ecx, _ECX
		mov ebx, nFunc
		call ebx
		mov nRs, eax   
	
	}
	return nRs;
}

//==================================================================================//
void Search_All_Champ(int (&nResult)[10])
{
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return;
	DWORD nTempBASE_HERO = BASE_HERO - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_HERO_MAX - TEMP_ENTRY_POINT + hModule;

	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return;

	int nCount = (dw2 - dw1)/4;
	KNpc *pPlayer = GetPlayer();
	if(!pPlayer) return;

	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pEnemyPlayer = (KNpc*)dw3;
		if (pEnemyPlayer->IsChampion() == true){
			nResult[i] = (int)pEnemyPlayer;
		}	
		//__oMsg("[%d]: %x", i, nResult[i]);
	}
}

//==================================================================================//
void Search_All_Unit_Around_NPC(KNpc* pNPC, float nRange, DWORD (&nResult)[300])
{
	if(!pNPC) return;

	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return;
	DWORD nTempBASE_HERO = BASE_AttackableUnit - TEMP_ENTRY_POINT + hModule;
	DWORD nTempBASE_HERO_MAX = BASE_AttackableUnit_MAX - TEMP_ENTRY_POINT + hModule;
	
	//DWORD offsetInhibitor = INHIBITOR - TEMP_ENTRY_POINT + hModule;
	//DWORD offsetNexus = NEXUS - TEMP_ENTRY_POINT + hModule;

	DWORD dw1 = *(DWORD*)nTempBASE_HERO;
	DWORD dw2 = *(DWORD*)nTempBASE_HERO_MAX;
	if (!dw1 || !dw2 ) return;

	int nCount = (dw2 - dw1)/4;
	int j = 0;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pObject = (KNpc*)dw3;
		if(pObject->nIndex < 0x3FFFFCC8 && !pObject->IsInhibitor() && !pObject->IsNexus()) continue;
		{
			//bool nIsInhibitor = (pObject->nIs_Nexus == (int)offsetInhibitor) ? true : false;
			//bool nNexus = (pObject->nIs_Nexus == (int)offsetNexus) ? true : false;
			//if(nIsInhibitor) __oMsg("nIsInhibitor: %x - %s - %x", pObject, pObject->GetNameNpc(), pObject->nIndex);
			//if(nNexus) __oMsg("nNexus: %x - %s -%x", pObject, pObject->GetNameNpc(), pObject->nIndex);
		}

		float fdistance = Distance_2D(pNPC->CurrentPos, pObject->CurrentPos);
		if (fdistance <= nRange)
		{
			//__oMsg("sao ko vao: %x - %d", pObject, GetTypeObject(pObject));
			nResult[j] = (DWORD)pObject;
			j += 1;
		}	
		//__oMsg("[%d]: %x", i, nResult[i]);
	}
}

//==================================================================================//
void Search_All_Object_Around_NPC(KNpc* pNPC, float nRange, DWORD (&nResult)[500])
{
	if(!pNPC) return;

	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	if (hModule == NULL) return;
	DWORD nTempBASE_OBJECT_ALL = BASE_OBJECT_ALL - TEMP_ENTRY_POINT + hModule;
	DWORD dw0 = nTempBASE_OBJECT_ALL + 8;

	DWORD dw1 = *(DWORD*)dw0;
	if (!dw1) return;
	int nCount = *(DWORD*)(dw0 + 4);
	if (!nCount) return;
	
	int j = 0;
	for (int i = 0; i < nCount; ++i)
	{
		DWORD dw3 = *(DWORD*)(dw1 + 4*i);
		if (dw3 == 0) continue;
		KNpc *pObject = (KNpc*)dw3;
		if(pObject->nIndex < 0x3FFFFCC8) continue;
		
		float fdistance = Distance_2D(pNPC->CurrentPos, pObject->CurrentPos);
		if (fdistance <= nRange)
		{
			nResult[j] = (DWORD)pObject;
			//__oMsg("---------trong---[i=%d] [j=%d]: %x - %x", i ,j, nResult[j], pObject);
			j += 1;
		}	
		
		//__oMsg("---------trong---[%d]: %x", i, nResult[i]);
	}
}

//==================================================================================//
int  GetPingGame()//ms
{
	int nRs = 30;
	DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD dw1     = ECX_SEND_CHAT - TEMP_ENTRY_POINT + hModule;
	__oMsg("ECX_SEND_CHAT: %x - hModule: %x", dw1, hModule);
	DWORD nFunc   = GET_PINGGAME_FUNC - TEMP_ENTRY_POINT + hModule;

	DWORD _ECX    = *(DWORD*)dw1;
	if(!_ECX) return nRs;

	__asm{
			mov ecx, _ECX
			mov ebx, nFunc
			call ebx
			mov nRs, eax
	}
	return nRs;


	/*DWORD hModule = (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD dw1     = ECX_SEND_CHAT - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX    = *(DWORD*)dw1;
	if(!_ECX) return 0;
	DWORD dw2  = *(DWORD*)(_ECX + 0x54);
	if(!dw2) return 0;
	DWORD dw3 = *(DWORD*)(dw2 + 0xC);
	if(!dw3) return 0;
	DWORD dw4 = *(DWORD*)(dw3 + 0x90);
	return dw4;*/
}

////==================================================================================//
//bool IsMoving(KNpc* pNpc)
//{
//	bool nIsMoving = (BYTE)pNpc->nIsMove > 0 ? true : false;
//	return nIsMoving;
//}

//==================================================================================//
bool IsDashing(KNpc* pNpc)
{
	if(!pNpc) return false;

	DWORD movNote = (DWORD)pNpc->_pMOVE;
	if(!movNote) return false;
	
	DWORD tempMov  = *(DWORD*)(movNote + 4);
	stMOVE *enemyPos = (stMOVE *)tempMov;
	//stMOVE *enemyPos = (stMOVE*) pNpc->_pMOVE;

	if(enemyPos)
	{
		//if(DashGravity()==true) return true;
		bool nIsDashing = (BYTE)enemyPos->nIsDash == 0 ? true : false;// bang = la Dashing, hoi nguoc doi ti
		return nIsDashing;
		/*bool nIsMoving = (BYTE)enemyPos->nIsMoving > 0 ? true : false;
		if(nIsMoving)
		{
			bool nIsDashing = (BYTE)enemyPos->nIsDashing > 0 ? true : false;
			return nIsDashing;
		}*/
	}
	return false;
}

//==================================================================================//
int nDashGravity = 0;
bool IsDashGravity(KNpc* pNpc)
{
	
	return false;
}

//==================================================================================//
int GetOffsetSpellBook()
{
	KNpc* pPlayer = GetPlayer();
	if(!pPlayer) return 0;
	return (DWORD)&pPlayer->_pCastSpellBook - (DWORD)pPlayer;
}

//==================================================================================//
DWORD GetObjectByID(DWORD nID)
{
	DWORD nRs = 0;
	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= GET_OBJ_BY_ID - TEMP_ENTRY_POINT + hModule;
	DWORD _ECX		= BASE_OBJ_BY_ID - TEMP_ENTRY_POINT + hModule;

	__asm{
		push nID
		mov ecx, _ECX
		mov ebx, nFunc
		call ebx
		mov nRs, eax
	}
	return nRs;
}

//==================================================================================//
DWORD GetObjectByNetworkID(DWORD nNetworkID)
{
	DWORD nRs = 0;
	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= GET_OBJ_BY_NET_ID - TEMP_ENTRY_POINT + hModule;

	__asm{
			push nNetworkID
			mov ebx, nFunc
			call ebx
			add esp, 4
			mov nRs, eax
	}
	return nRs;
}

//==================================================================================//
float GetBoundingRadius(KNpc* pNpc)
{
	float nResult = 66.12345f;
	if(pNpc == 0) return 0;

	DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
	DWORD nFunc		= GET_BOUND_RADIUS_FUNC - TEMP_ENTRY_POINT + hModule;

	DWORD _ECX		= (DWORD)pNpc;
	DWORD nThamSo2 = 0;
	__asm{
		mov ecx, _ECX
		mov ebx, nFunc
		call ebx

		movss   dword ptr [esp + 8], xmm0
		fstp    dword ptr [esp + 8]
		mov eax,    dword ptr [esp + 8]
		mov nThamSo2, eax
		//add esp, 0x8
	}
	if (nThamSo2 != 0)
		nResult = *(float*)&nThamSo2;
	return nResult;
}

//==================================================================================================
//public static bool IsValidTarget(
//								 this AttackableUnit unit,
//								 float range = float.MaxValue,
//								 bool checkTeam = true,
//								 Vector3 from = new Vector3())
//{
//	if (unit == null || !unit.IsValid || !unit.IsVisible || unit.IsDead || !unit.IsTargetable
//		|| unit.IsInvulnerable)
//
//	{
//		return false;
//	}
//
//	if (checkTeam && unit.Team == HeroManager.Player.Team)
//	{
//		return false;
//	}
//
//	if (unit.Name == "WardCorpse")
//	{
//		return false;
//	}
//
//	var @base = unit as Obj_AI_Base;
//
//	return !(range < float.MaxValue)
//		|| !(Vector2.DistanceSquared(
//		(@from.To2D().IsValid() ? @from : HeroManager.Player.ServerPosition).To2D(),
//		(@base != null ? @base.ServerPosition : unit.Position).To2D()) > range * range);
//}
bool IsValidTarget(KNpc* pUnit, float nRange, bool checkTeam, Vec3D* from)
{
	
	return false;
	//return Distance_2D(pPlayer->CurrentPos, pUnit->CurrentPos) <= nRange;
}

//==================================================================================================
float GetDmg_TurretHitMinion(KNpc* turret, KNpc* minion)
{
	if(!turret || !minion) return 0;
	if(minion->nOverrideCollisionRadius < 120)
	{
		if((BYTE)minion->nCombatType == 1) return (float)0.43*minion->nMaxHP;
		if((BYTE)minion->nCombatType == 2) return (float)0.68*minion->nMaxHP;
	}
	else
	{
		if((BYTE)minion->nCombatType == 1) return (float)0.05*minion->nMaxHP;
		if((BYTE)minion->nCombatType == 2) return (float)0.14*minion->nMaxHP;
	}
	return 0;
}

//==================================================================================================
float calcDamage(KNpc* enemy, int dmgType, float dmgRaw)
{
	KNpc* pPlayer = GetPlayer();
	if(!pPlayer) return 0;
	float nFinalDamage = 0;

	if(dmgType == 1)//AD-dmg
	{
		float pEnemy_nArmor = enemy->nArmor;
		if (GET_ITEM(ITEM_NO_THAN_ID) || GET_ITEM(ITEM_LOINHACTUVONG_ID))
		{
			pEnemy_nArmor = (pEnemy_nArmor - enemy->nArmor_CongThem*PERCENT_XUYENGIAP_NOTHAN/100);
		}
		float nXuyenGiap = (SATLUC_XUYENTHANG*pPlayer->nXyenGiap_Diem/100 + (1 - SATLUC_XUYENTHANG/100)*pPlayer->nXyenGiap_Diem*(BYTE)enemy->nLevel/18);

		if(!enemy->IsChampion()) nXuyenGiap = 0;
		pEnemy_nArmor = pEnemy_nArmor - nXuyenGiap;

		nFinalDamage = dmgRaw * (100/(100 + pEnemy_nArmor));
		if(pEnemy_nArmor < 0)
		{
			nFinalDamage = dmgRaw * (2 - 100/(100 - pEnemy_nArmor));
		}
		if(GET_ITEM(ITEM_NO_THAN_ID))
		{
			float nSolan = (enemy->nMaxHP - pPlayer->nMaxHP)/100;
			if(nSolan < 0) nSolan = 0;
			if(nSolan > 10) nSolan = 10;
			nFinalDamage += 0.02f*nFinalDamage*nSolan;
		}
	}
	else if(dmgType == 0)//AP-dmg
	{
		float pEnemy_nSpellBlock = enemy->nSpellBlock;
		if (GET_ITEM(ITEM_TRUONG_HU_VO_ID)) pEnemy_nSpellBlock = pEnemy_nSpellBlock*(1 - PERCENT_XUYENPHEP_TRUONGHUVO/100);
		pEnemy_nSpellBlock = pEnemy_nSpellBlock - pPlayer->nXyenPhep_Diem;

		nFinalDamage = dmgRaw * (100/(100 + pEnemy_nSpellBlock));
		if(pEnemy_nSpellBlock < 0)
		{
			nFinalDamage = dmgRaw * (2 - 100/(100 - pEnemy_nSpellBlock));
		}
	}
	else if(dmgType == 2)//true-dmg
		nFinalDamage = dmgRaw;
	return nFinalDamage;
}

//==================================================================================================
KPathOutWayPoint *pResult = 0;
KPathOutWayPoint* CreatPathWays(KNpc* unit, Vec3D& start, Vec3D& destination, bool smoothPath)
{	
	smoothPath = true;
	
		if(!unit) return 0;
		DWORD hModule	= (DWORD)MyGetModuleHandle( (sz__League_of_Legends_exe));
		if(!hModule) return 0;
		DWORD nFunc		   = NAVMESH_CREATEPATH_FUNC - TEMP_ENTRY_POINT + hModule;
		DWORD nFunc_Smooth = NAVMESH_SMOOTHPATH_FUNC - TEMP_ENTRY_POINT + hModule;
		DWORD MapData	= BASE_MAPDATA - TEMP_ENTRY_POINT + hModule;

		DWORD movNote = (DWORD)unit->_pMOVE;
		if(!movNote) return 0;
		DWORD tempMov  = *(DWORD*)(movNote + 4);
		DWORD pMove = tempMov;
		//DWORD pMove = unit->_pMOVE;

		if(!pMove) return 0;

		DWORD n1 = 0, n2 = 0, n3 = 0;
		DWORD Temp1 = (DWORD)&n1, Temp2 = (DWORD)&n2, Temp3 = (DWORD)&n3;

		DWORD n4[300] = {0};
		DWORD pathOut = (DWORD)&n4[0];
		//DWORD pathOut = (DWORD)&pathOutStruct.nTemp1;
		
		
		DWORD* vklStart = (DWORD*)&start.x;
		DWORD* vklEnd   = (DWORD*)&destination.x;
		//DWORD nFunc_Smooth = 0x617640;
		__asm
		{
			push 0
			push 0x2710
			push Temp3
			push Temp2
			push Temp1
			push 0
			push pMove
			push vklEnd
			push vklStart
			push pathOut
			mov ecx, MapData
			mov eax, nFunc
			call eax
		}
		if(smoothPath)
		{
			__asm
			{
				push pathOut
				mov ecx, pMove
				mov ebx, nFunc_Smooth
				call ebx
			}
		}
		//pResult = (KPathOutWayPoint*)&n4[0];
		pResult = (KPathOutWayPoint*)pathOut;
		//__oMsg("%x, %x, [%x - %x]", pResult->pWayPointStart, pResult->pWayPointEnd, n4[8], n4[9]);
	
	return pResult;
}