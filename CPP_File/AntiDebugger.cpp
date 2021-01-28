#include "AntiDebugger.h"

CAntiDebugger* CAntiDebugger::s_Instance = 0;

CAntiDebugger::CAntiDebugger(void)
{
}

CAntiDebugger::~CAntiDebugger(void)
{
}

CAntiDebugger* CAntiDebugger::GetInstance()
{
	if (!s_Instance)
	{
		s_Instance = new CAntiDebugger();
	}
	return s_Instance;
}

bool CAntiDebugger::CheckFindWindow(TCHAR* wndClassName, TCHAR* wndCaption)
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

extern DWORD g_Address;
void CAntiDebugger::TERMINATE_ALL() // VM PROTECT ON
{
	return;
	////__oMsg("==== TERMINATE_ALL ====== ExitProcess : xxx");
	//VMProtectBegin("DLL_VM__TERMINATE_ALL");
	//TerminateProcess(GetCurrentProcess(), 0xBABEFACE);
	////BlockInput(TRUE);  // ====> NGUY HIEM
	//g_Address = TEMP_ENTRY_POINT_FAKE;
	//VMProtectEnd();
	//exit(-1);
	//ExitProcess(0);
}

void CAntiDebugger::ANTI_DEBUG_TOOL() // anti OllyDbg, MHS, Cheat Engine, TSearch, ArtMoney, IDA, WinDbg
{
	//VMProtectBegin("DLL_VM__ANTI_DEBUG_TOOL");
	//bool hasOlly1     = CheckFindWindow( (sz__fengyue),  (sz__OllyDbg));					//OllyDbg fengyue
	//if(hasOlly1) TERMINATE_ALL();
	//bool hasOlly2     = CheckFindWindow( (sz__OLLYDBG),  (sz__OllyDbg));					//OllyDbg Org
	//if(hasOlly2) TERMINATE_ALL();
	//bool hasOlly3     = CheckFindWindow( (sz__DEROX),  (sz__OllyDbg));					//OllyDbg DEROX
	//if(hasOlly3) TERMINATE_ALL();
	//bool hasOlly4     = CheckFindWindow( (sz___CiS_),  (sz__OllyDbg));					//OllyDbg -CiS-
	//if(hasOlly4) TERMINATE_ALL();
	//bool hasOlly5     = CheckFindWindow( (sz__MTCTOly),  (sz__OllyDbg));					//OllyDbg MTCTOly
	//if(hasOlly5) TERMINATE_ALL();
	//bool hasMHS       = CheckFindWindow( (sz__Calc),  (sz__MHS));							//MHS
	//if(hasMHS) TERMINATE_ALL();
	//bool hasCE		  = CheckFindWindow( (sz__Window),  (sz__Cheat_Engine));				//Cheat Engine 6.5
	//if(hasCE) TERMINATE_ALL();
	//bool hasTSearch	  = CheckFindWindow( (sz__Afx_400000_8_10011_0_a0655),  (sz__TSearch));//TSearch
	//if(hasTSearch) TERMINATE_ALL();
	//bool hasArtMoney  = CheckFindWindow( (sz__TForm1),  (sz__ArtMoney_Pro));				//ArtMoney Pro v7.35.1
	//if(hasArtMoney) TERMINATE_ALL();
	//bool hasIDA		  = CheckFindWindow( (sz__QWidget),  (sz__IDA_Pro));					//IDA Pro v6.1.110315
	//if(hasIDA) TERMINATE_ALL();
	//bool hasWinDbg	  = CheckFindWindow( (sz__WinDbgFrameClass),  (sz__WinDbg));			//WinDbg
	//if(hasWinDbg) TERMINATE_ALL();
	//VMProtectEnd();
}

void CAntiDebugger::ANTI_PEB()
{
	//PBOOLEAN BeingDebugged=(PBOOLEAN)__readfsdword(0x30)+2;
	//if(*BeingDebugged) // Read the PEB
	//{
	//	TERMINATE_ALL();
	//}
}

void CAntiDebugger::ANTI_IS_DEBUGGER_PRESENT()
{
	/*char  nIsDebugger = 0;
	nIsDebugger = IsDebuggerPresent();
	if (nIsDebugger)
	{
		TERMINATE_ALL();
	}*/
}

void CAntiDebugger::ANTI_HARDWARE_BP()
{
	/*CONTEXT ctx = {};
	ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;
	if (GetThreadContext(GetCurrentThread(), &ctx))
	{
		if (ctx.Dr0 != 0 || ctx.Dr1 != 0 || ctx.Dr2 != 0 || ctx.Dr3 != 0)
		{
			TERMINATE_ALL();
		}
	}*/
}

bool CAntiDebugger::MemoryBreakpointDebuggerCheck()
{
	//unsigned char *pMem = NULL;
	//SYSTEM_INFO sysinfo = {0}; 
	//DWORD OldProtect = 0;
	//void *pAllocation = NULL; // Get the page size for the system 
	//GetSystemInfo(&sysinfo); // Allocate memory 
	//pAllocation = VirtualAlloc(NULL, sysinfo.dwPageSize, 
	//	MEM_COMMIT | MEM_RESERVE, 
	//	PAGE_EXECUTE_READWRITE); 
	//if (pAllocation == NULL)
	//	return false; 
	//// Write a ret to the buffer (opcode 0xc3)
	//pMem = (unsigned char*)pAllocation;
	//*pMem = 0xc3; 
	//// Make the page a guard page         
	//if (VirtualProtect(pAllocation, sysinfo.dwPageSize, 
	//	PAGE_EXECUTE_READWRITE | PAGE_GUARD, 
	//	&OldProtect) == 0)
	//{
	//	return false;
	//} 
	//__try
	//{
	//	__asm
	//	{
	//		mov eax, pAllocation
	//			// This is the address we'll return to if we're under a debugger
	//			push MemBpBeingDebugged
	//			jmp eax // Exception or execution, which shall it be :D?
	//	}
	//}
	//__except(EXCEPTION_EXECUTE_HANDLER)
	//{
	//	// The exception occured and no debugger was detected
	//	VirtualFree(pAllocation, NULL, MEM_RELEASE);
	//	return false;
	//}     

	//__asm{MemBpBeingDebugged:}
	//VirtualFree(pAllocation, NULL, MEM_RELEASE);
	return true;
}

void CAntiDebugger::ANTI_MEMORY_BP()
{
	/*if(MemoryBreakpointDebuggerCheck())
	{
		TERMINATE_ALL();
	}*/
}

void CAntiDebugger::ANTI_OUTPUT_DEBUG_STRING(LPCTSTR String)
{
	//OutputDebugString(String);
	//if (GetLastError() == 0)	TERMINATE_ALL();
}

bool CAntiDebugger::DebugObjectCheck() //==> chi chong dc CE attack
{
	//// Much easier in ASM but C/C++ looks so much better
	//typedef int (WINAPI *pNtQueryInformationProcess)
	//	(HANDLE ,UINT ,PVOID ,ULONG , PULONG); 

	//HANDLE hDebugObject = NULL;
	//int Status; 

	//// Get NtQueryInformationProcess
	//pNtQueryInformationProcess NtQIP = (pNtQueryInformationProcess)
	//	GetProcAddress(  GetModuleHandle(  (sz__ntdll_dll)), 
	//	 (sz__NtQueryInformationProcess) ); 

	//Status = NtQIP(GetCurrentProcess(), 
	//	0x1e, // ProcessDebugObjectHandle
	//	&hDebugObject, 4, NULL); 

	//if (Status != 0x00000000)
	//{
	//	return false; 
	//}

	//if(hDebugObject)
	//	return true;
	//else
	//{
	//	return false;
	//}
	return false;
}

void CAntiDebugger::ANTI_DEBUG_OBJECT_CHECK()
{
	/*if(DebugObjectCheck())
	{
		TERMINATE_ALL();
	}*/
}

bool CAntiDebugger::TestExceptionCode(DWORD dwCode)
{
	/*__try
	{
		RaiseException(dwCode, 0, 0, 0);
	}
	__except(1)
	{
		return FALSE;
	}*/
	return TRUE;
}

bool CAntiDebugger::IsDebuggerPresent_RipException_1()
{
	//return TestExceptionCode(STATUS_BREAKPOINT);
}

bool CAntiDebugger::IsDebuggerPresent_RipException_2()
{
	////DWORD DBG_PRINTEXCEPTION_C	= 0x40010006;
	//return TestExceptionCode(DBG_PRINTEXCEPTION_C);
}

bool CAntiDebugger::IsDebuggerPresent_RipException_3()
{
	////DWORD DBG_RIPEXCEPTION		= 0x40010007;
	//return TestExceptionCode(DBG_RIPEXCEPTION);
}

void CAntiDebugger::TRAP_RIP_EXCEPTION()
{
	/*if(IsDebuggerPresent_RipException_1() || IsDebuggerPresent_RipException_2() || IsDebuggerPresent_RipException_3())
	{
		TERMINATE_ALL();
	}*/
}
