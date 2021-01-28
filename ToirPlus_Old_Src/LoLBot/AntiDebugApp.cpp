#include "StdAfx.h"
#include "AntiDebugApp.h"

CAntiDebugApp* CAntiDebugApp::s_Instance = 0;

CAntiDebugApp::CAntiDebugApp(void)
{
}

CAntiDebugApp::~CAntiDebugApp(void)
{
}

CAntiDebugApp* CAntiDebugApp::GetInstance()
{
	if (!s_Instance)
	{
		s_Instance = new CAntiDebugApp();
	}
	return s_Instance;
}

bool CAntiDebugApp::CheckFindWindow(TCHAR* wndClassName, TCHAR* wndCaption)
{
	bool result = false;
	HWND hwnd = ::FindWindow(wndClassName, NULL);
	if (!hwnd) return result;
	TCHAR wnd_title[256];
	::GetWindowText(hwnd, wnd_title, sizeof(wnd_title));
	//MessageBoxA(NULL, typeid(wndClassName).name(), typeid(wndCaption).name(), MB_OK);
	if (typeid(TCHAR) == typeid(CHAR))
	{
		std::string strInString((CHAR*)wnd_title);
		int found = strInString.find((CHAR*)wndCaption);
		if (found >= 0)
			result = true;
	}
	if (typeid(TCHAR) == typeid(WCHAR))
	{
		std::wstring strInString((WCHAR*)wnd_title);
		int found = strInString.find((WCHAR*)wndCaption);
		if (found >= 0)
			result = true;
	}
	return result;
}

void CAntiDebugApp::TERMINATE_ALL() // VM PROTECT ON
{
	return;
	//__oMsg("==APPPPPP== TERMINATE_ALL ====== ExitProcess : xxx");
	TerminateProcess(GetCurrentProcess(), 0xBABEFACE);
	//BlockInput(TRUE);  // ====> NGUY HIEM
	ExitProcess(0);
	exit(-1);
}

void CAntiDebugApp::ANTI_DEBUG_TOOL() // anti OllyDbg, MHS, Cheat Engine, TSearch, ArtMoney, IDA, WinDbg
{
	bool hasOlly1     = CheckFindWindow(C2W( (sz__fengyue)), C2W( (sz__OllyDbg)));					//OllyDbg fengyue
	if(hasOlly1) TERMINATE_ALL();
	bool hasOlly2     = CheckFindWindow(C2W( (sz__OLLYDBG)), C2W( (sz__OllyDbg)));					//OllyDbg Org
	if(hasOlly2) TERMINATE_ALL();
	bool hasOlly3     = CheckFindWindow(C2W( (sz__DEROX)), C2W( (sz__OllyDbg)));						//OllyDbg DEROX
	if(hasOlly3) TERMINATE_ALL();
	bool hasOlly4     = CheckFindWindow(C2W( (sz___CiS_)), C2W( (sz__OllyDbg)));						//OllyDbg -CiS-
	if(hasOlly4) TERMINATE_ALL();
	bool hasOlly5     = CheckFindWindow(C2W( (sz__MTCTOly)), C2W( (sz__OllyDbg)));					//OllyDbg MTCTOly
	if(hasOlly5) TERMINATE_ALL();
	bool hasMHS       = CheckFindWindow(C2W( (sz__Calc)), C2W( (sz__MHS)));							//MHS
	if(hasMHS) TERMINATE_ALL();
	bool hasCE		  = CheckFindWindow(C2W( (sz__Window)), C2W( (sz__Cheat_Engine)));				//Cheat Engine 6.5
	if(hasCE) TERMINATE_ALL();
	bool hasTSearch	  = CheckFindWindow(C2W( (sz__Afx_400000_8_10011_0_a0655)), C2W( (sz__TSearch)));	//TSearch
	if(hasTSearch) TERMINATE_ALL();
	bool hasArtMoney  = CheckFindWindow(C2W( (sz__TForm1)), C2W( (sz__ArtMoney_Pro)));				//ArtMoney Pro v7.35.1
	if(hasArtMoney) TERMINATE_ALL();
	bool hasIDA		  = CheckFindWindow(C2W( (sz__QWidget)), C2W( (sz__IDA_Pro)));					//IDA Pro v6.1.110315
	if(hasIDA) TERMINATE_ALL();
	bool hasWinDbg	  = CheckFindWindow(C2W( (sz__WinDbgFrameClass)), C2W( (sz__WinDbg)));			//WinDbg
	if(hasWinDbg) TERMINATE_ALL();
	// check windows's game
	//bool hasGarena		  = CheckFindWindow(L"UIHOST", L"Garena+ (Beta)");												//garena
	//if(hasGarena) TERMINATE_ALL();
	//bool hasLolClient1	  = CheckFindWindow("ApolloRuntimeContentWindow", "PVP.net Client");							//client garena
	//if(hasLolClient1) TERMINATE_ALL();
	//bool hasLolClient2	  = ::FindWindow(NULL, "League of Legends");													//client beta
	//if(hasLolClient2) TERMINATE_ALL();
	//bool hasClientGame	  = ::FindWindow(NULL, C2W( (sz__League_of_Legends__TM__Client)));						//client game
	//if(hasClientGame) TERMINATE_ALL();
}

void CAntiDebugApp::ANTI_PEB()
{
	//PBOOLEAN BeingDebugged=(PBOOLEAN)__readfsdword(0x30)+2;
	//if(*BeingDebugged) // Read the PEB
	//{
	//	TERMINATE_ALL();
	//}
}

void CAntiDebugApp::ANTI_IS_DEBUGGER_PRESENT()
{
	//VMProtectBegin("AutoLoLs_VM__ANTI_IS_DEBUGGER_PRESENT");
	//char  nIsDebugger = 0;
	//nIsDebugger = IsDebuggerPresent();
	//if (nIsDebugger)
	//{
	//	TERMINATE_ALL();
	//}
	//VMProtectEnd();
}

void CAntiDebugApp::ANTI_HARDWARE_BP()
{
	//VMProtectBegin("AutoLoLs_VM__ANTI_HARDWARE_BP");
	CONTEXT ctx = {};
	ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;
	if (GetThreadContext(GetCurrentThread(), &ctx))
	{
		if (ctx.Dr0 != 0 || ctx.Dr1 != 0 || ctx.Dr2 != 0 || ctx.Dr3 != 0)
		{
			TERMINATE_ALL();
		}
	}
	//VMProtectEnd();
}

bool CAntiDebugApp::MemoryBreakpointDebuggerCheck()
{
	//VMProtectBegin("AutoLoLs_VM__MemoryBreakpointDebuggerCheck");
	unsigned char *pMem = NULL;
	SYSTEM_INFO sysinfo = {0}; 
	DWORD OldProtect = 0;
	void *pAllocation = NULL; // Get the page size for the system 
	GetSystemInfo(&sysinfo); // Allocate memory 
	pAllocation = VirtualAlloc(NULL, sysinfo.dwPageSize, 
		MEM_COMMIT | MEM_RESERVE, 
		PAGE_EXECUTE_READWRITE); 
	if (pAllocation == NULL)
		return false; 
	// Write a ret to the buffer (opcode 0xc3)
	pMem = (unsigned char*)pAllocation;
	*pMem = 0xc3; 
	// Make the page a guard page         
	if (VirtualProtect(pAllocation, sysinfo.dwPageSize, 
		PAGE_EXECUTE_READWRITE | PAGE_GUARD, 
		&OldProtect) == 0)
	{
		return false;
	} 
	__try
	{
		__asm
		{
			mov eax, pAllocation
				// This is the address we'll return to if we're under a debugger
				push MemBpBeingDebugged
				jmp eax // Exception or execution, which shall it be :D?
		}
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		// The exception occured and no debugger was detected
		VirtualFree(pAllocation, NULL, MEM_RELEASE);
		return false;
	}     

	__asm{MemBpBeingDebugged:}
	VirtualFree(pAllocation, NULL, MEM_RELEASE);
	return true;
	//VMProtectEnd();
}

void CAntiDebugApp::ANTI_MEMORY_BP()
{
	//VMProtectBegin("AutoLoLs_VM__ANTI_MEMORY_BP");
	if(MemoryBreakpointDebuggerCheck())
	{
		TERMINATE_ALL();
	}
	//VMProtectEnd();
}

void CAntiDebugApp::ANTI_OUTPUT_DEBUG_STRING(LPCTSTR String)
{
	//VMProtectBegin("AutoLoLs_VM__ANTI_OUTPUT_DEBUG_STRING");
	OutputDebugString(String);
	if (GetLastError() == 0)	TERMINATE_ALL();
	//VMProtectEnd();
}

bool CAntiDebugApp::DebugObjectCheck() //==> chi chong dc CE attack
{
	//VMProtectBegin("AutoLoLs_VM__DebugObjectCheck");
	// Much easier in ASM but C/C++ looks so much better
	typedef int (WINAPI *pNtQueryInformationProcess)
		(HANDLE ,UINT ,PVOID ,ULONG , PULONG); 

	HANDLE hDebugObject = NULL;
	int Status; 

	// Get NtQueryInformationProcess
	pNtQueryInformationProcess NtQIP = (pNtQueryInformationProcess)
		GetProcAddress(  GetModuleHandle( C2W( (sz__ntdll_dll))), 
		 (sz__NtQueryInformationProcess) ); 

	Status = NtQIP(GetCurrentProcess(), 
		0x1e, // ProcessDebugObjectHandle
		&hDebugObject, 4, NULL); 

	if (Status != 0x00000000)
	{
		return false; 
	}

	if(hDebugObject)
		return true;
	else
	{
		//VMProtectEnd();
		return false;
	}
}

void CAntiDebugApp::ANTI_DEBUG_OBJECT_CHECK()
{
	//VMProtectBegin("AutoLoLs_VM__ANTI_DEBUG_OBJECT_CHECK");
	if(DebugObjectCheck())
	{
		TERMINATE_ALL();
	}
	//VMProtectEnd();
}


bool CAntiDebugApp::TestExceptionCode(DWORD dwCode)
{
	//VMProtectBegin("AutoLoLs_VM__TestExceptionCode");
	__try
	{
		RaiseException(dwCode, 0, 0, 0);
	}
	__except(1)
	{
		return FALSE;
	}
	//VMProtectEnd();
	return TRUE;
}


bool CAntiDebugApp::DebuggerDriversPresent()
{
	// an array of common debugger driver device names
	const char drivers[9][20] = {
		"\\\\.\\EXTREM", "\\\\.\\ICEEXT",
		"\\\\.\\NDBGMSG.VXD", "\\\\.\\RING0",
		"\\\\.\\SIWVID", "\\\\.\\SYSER",
		"\\\\.\\TRW", "\\\\.\\SYSERBOOT",
		"\0"
	};
	for (int i = 0; drivers[i][0] != '\0'; i++) {
		HANDLE h = CreateFileA(drivers[i], 0, 0, 0, OPEN_EXISTING, 0, 0);
		if (h != INVALID_HANDLE_VALUE) {
			CloseHandle(h);
			return true;
		}
	}
	return false;
}

bool CAntiDebugApp::IsDebuggerPresent_RipException_1()
{
	//VMProtectBegin("AutoLoLs_VM__IsDebuggerPresent_RipException_1");
	return TestExceptionCode(STATUS_BREAKPOINT);
	//VMProtectEnd();
}

bool CAntiDebugApp::IsDebuggerPresent_RipException_2()
{
	DWORD DBG_PRINTEXCEPTION_C	= 0x40010006;
//VMProtectBegin("AutoLoLs_VM__IsDebuggerPresent_RipException_2");
	return TestExceptionCode(DBG_PRINTEXCEPTION_C);
	//VMProtectEnd();
}

bool CAntiDebugApp::IsDebuggerPresent_RipException_3()
{
	DWORD DBG_RIPEXCEPTION		= 0x40010007;
//VMProtectBegin("AutoLoLs_VM__IsDebuggerPresent_RipException_3");
	return TestExceptionCode(DBG_RIPEXCEPTION);
	//VMProtectEnd();
}

void CAntiDebugApp::TRAP_RIP_EXCEPTION()
{
	//VMProtectBegin("AutoLoLs_VM__TRAP_RIP_EXCEPTION");
	if(IsDebuggerPresent_RipException_1() || IsDebuggerPresent_RipException_2() || IsDebuggerPresent_RipException_3())
	{
		TERMINATE_ALL();
	}
	//VMProtectEnd();
}
