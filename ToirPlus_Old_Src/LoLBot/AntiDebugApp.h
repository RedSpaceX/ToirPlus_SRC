#pragma once
#include <Windows.h>
#include "VMProtectSDK.h"
#include "Commons.h"
//#include "../InjectBot/Utils.h"

class CAntiDebugApp
{
	CAntiDebugApp(void);
	static CAntiDebugApp* s_Instance;
public:
	~CAntiDebugApp(void);
	static CAntiDebugApp* GetInstance();
	bool CheckFindWindow(TCHAR* wndClassName, TCHAR* wndCaption);
	//===================ALL ANTI DEBUG =================================================================================
	void TERMINATE_ALL();//	VM PROTECT ON
	//------------------------------------------------------------------------------------------------------------------
	void ANTI_DEBUG_TOOL(); // anti OllyDbg, MHS, Cheat Engine,  TSearch, ArtMoney, IDA, WinDbg
	//------------------------------------------------------------------------------------------------------------------
	void ANTI_PEB();
	//------------------------------------------------------------------------------------------------------------------
	void ANTI_IS_DEBUGGER_PRESENT();
	//------------------------------------------------------------------------------------------------------------------
	void ANTI_HARDWARE_BP();
	//------------------------------------------------------------------------------------------------------------------
	bool MemoryBreakpointDebuggerCheck();
	void ANTI_MEMORY_BP();
	//------------------------------------------------------------------------------------------------------------------
	void ANTI_OUTPUT_DEBUG_STRING(LPCTSTR String);
	//------------------------------------------------------------------------------------------------------------------
	bool DebugObjectCheck();        //==> chi chong dc CE attack
	void ANTI_DEBUG_OBJECT_CHECK();
	//------------------------------------------------------------------------------------------------------------------
	bool TRAP_INT3();
	//------------------------------------------------------------------------------------------------------------------
	bool TRAP_INT_2D();              // ==> TRAP nay tu exit
	//------------------------------------------------------------------------------------------------------------------
	bool IsDebuggerPresent_IceBp();    // ==> TRAP nay can dung ham exit, chi exit khi F8 olly qua int1
	void TRAP_ICE_BP();
	//------------------------------------------------------------------------------------------------------------------
	bool DebuggerDriversPresent();   // ==> chong debugger o muc driver
	//------------------------------------------------------------------------------------------------------------------
	bool TestExceptionCode(DWORD dwCode);
	bool IsDebuggerPresent_RipException_1();
	bool IsDebuggerPresent_RipException_2();
	bool IsDebuggerPresent_RipException_3();
	void TRAP_RIP_EXCEPTION();
	//===================END ANTI DEBUG =============================================================================
};
