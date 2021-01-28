#pragma once

#include <iostream>
#include <string>

#include <Windows.h>
#include <TlHelp32.h>
#include "Log.h"
#include "Logger.h"

// Better than using namespace std;

using std::cout;
using std::endl;
using std::string;


DWORD GEN_CODE(char* nameFunc, LPCSTR Sign, LPCSTR Mask, int addSub = 0, int processId = 0);
DWORD GEN_CODE2(BYTE* Pattern, int p_Size);
void  GENARATE();
void  INIT_INDICATOR();
void  PRINT_RESULT(DWORD AddrFound, DWORD AddrFinish, char* exportName, int type/*, Logger printLog*/);

//====================================================//===========================:
struct module
{
	DWORD dwBase, dwSize;
};

//-----------------------------------------------------:
class SignatureScanner
{
public:
	module TargetModule;  // Hold target module
	HANDLE TargetProcess; // for target process
	DWORD  TargetId;      // for target process

	// For getting a handle to a process

	//HANDLE GetProcess(const std::wstring& processName)
	HANDLE GetProcess(char* processName)
	{
		HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
		PROCESSENTRY32 entry;
		entry.dwSize = sizeof(entry);

		do
		//if ( !processName.compare(entry.szExeFile) ){
			if (!strcmp(entry.szExeFile, processName)) {
			TargetId = entry.th32ProcessID;
			CloseHandle(handle);
			TargetProcess = OpenProcess(PROCESS_QUERY_INFORMATION|PROCESS_CREATE_THREAD|PROCESS_VM_OPERATION|
				PROCESS_VM_WRITE|PROCESS_VM_READ, false, TargetId);
			return TargetProcess;
		}
		while (Process32Next(handle, &entry));

		return false;
	}

	// For getting information about the executing module
	
	//module GetModule(const std::wstring& moduleName) 
	module GetModule(char* moduleName)
	{
	
		HANDLE hmodule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, TargetId);
		MODULEENTRY32 mEntry;
		mEntry.dwSize = sizeof(mEntry);

		do 
		{	
		//if ( !moduleName.compare(mEntry.szModule) )
			if (!strcmp(mEntry.szModule, (LPSTR)moduleName)) 
			{

				CloseHandle(hmodule);

				TargetModule.dwBase = (DWORD)mEntry.hModule ;
				TargetModule.dwSize =  mEntry.modBaseSize;

				//__oMsg_2("#pragma once\n");
				//__oMsg_2("#define TEMP_ENTRY_POINT_FAKE		0x49d2a");
				//__oMsg_2("#define TEMP_ENTRY_POINT\t\t0x%x", TargetModule.dwBase);
				//__oMsg_2("//GetModule -> dwSize : \t\t0x%x\n", TargetModule.dwSize);

				return TargetModule;
			}
		} while (Module32Next(hmodule, &mEntry));

		module mod = { (DWORD)false, (DWORD)false };
		return mod;
	}

	// Basic WPM wrapper, easier to use.
	template <typename var>
	bool WriteMemory(DWORD Address, var Value) {
		return WriteProcessMemory(TargetProcess, (LPVOID)Address, &Value, sizeof(var), 0);
	}

	// Basic RPM wrapper, easier to use.
	template <typename var>
	var ReadMemory(DWORD Address) {
		var value;
		ReadProcessMemory(TargetProcess, (LPCVOID)Address, &value, sizeof(var), NULL);
		return value;
	}

	// for comparing a region in memory, needed in finding a signature
	bool MemoryCompare(const BYTE* bData, const BYTE* bMask, const char* szMask) {
		for (; *szMask; ++szMask, ++bData, ++bMask) {
			if (*szMask == 'x' && *bData != *bMask) {
				return false;
			}
		}
		return (*szMask == NULL);
	}

	//----------- memcmp ----------//-----------------------//-----------------------------//-----------------------
	//----------- memcmp ----------//-----------------------//-----------------------------//-----------------------
	DWORD FindSignature_memcmp(DWORD BaseGame, DWORD SizeGame, BYTE*  Pattern, int p_Size)
	{
		SIZE_T Memory = 0;
		SYSTEM_INFO sys_info = { 0 };
		GetSystemInfo(&sys_info);
		MEMORY_BASIC_INFORMATION mem_basic_info = { 0 };
		HANDLE hProcess = TargetProcess;
		PVOID ab = (PVOID)0;

		for (Memory = BaseGame; Memory < BaseGame + SizeGame /*< (SIZE_T)sys_info.lpMaximumApplicationAddress*/; Memory += mem_basic_info.RegionSize)
		{
			//__oMsg_2(" [AllocationBase: %x - Address: %x - size: %x]-- type: %x, Protect: %x, state: %x", (DWORD)mem_basic_info.AllocationBase, (DWORD)mem_basic_info.BaseAddress, (DWORD)mem_basic_info.RegionSize, (DWORD)mem_basic_info.Type, (DWORD)mem_basic_info.Protect, (DWORD)mem_basic_info.State);
			ab = mem_basic_info.AllocationBase;
			if(VirtualQueryEx(hProcess, (LPCVOID)Memory, &mem_basic_info, sizeof(MEMORY_BASIC_INFORMATION)))
			{
				if (mem_basic_info.Protect == PAGE_EXECUTE_READ /*&& mem_basic_info.State == 0x1000 && mem_basic_info.Type == 0x20000*/)
				{
					//__oMsg_2(" [AllocationBase: %x - Address: %x - size: %x]-- type: %x, Protect: %x, state: %x", (DWORD)mem_basic_info.AllocationBase, (DWORD)mem_basic_info.BaseAddress, (DWORD)mem_basic_info.RegionSize, (DWORD)mem_basic_info.Type, (DWORD)mem_basic_info.Protect, (DWORD)mem_basic_info.State);

					for(int i = 0; i < (int)mem_basic_info.RegionSize - p_Size - p_Size; i++)	// tru di p_Size cho khoi crash
					{
						if(memcmp((void*)((DWORD)mem_basic_info.BaseAddress + i), Pattern, p_Size) == 0)
						{
							//__oMsg_2("---| FOUND-XXXX |=====================: %x", (DWORD)mem_basic_info.BaseAddress + i);
							return (DWORD)mem_basic_info.BaseAddress + i;
						}
					}

					/*for(int i = 0; i < (int)0x1d000; i++)
					{
						if(memcmp((void*)((DWORD)0x13c4000 + i), Pattern, p_Size) == 0)
						{
							__oMsg_2("---| FOUND-XXXX |=====================: %x", (DWORD)0x13c4000 + i);
							return (DWORD)0x13c4000 + i;
						}
					}*/
				}
			}
		}
		return 0;
	}

	//-----------------------------//-----------------------//-----------------------------//-----------------------
	//-----------------------------//-----------------------//-----------------------------//-----------------------


	// for finding a signature/pattern in memory of another process
	DWORD FindSignature(DWORD start, DWORD size, const char* sig, const char* mask)
	{
		SIZE_T Memory = 0;
		SYSTEM_INFO sys_info = { 0 };
		GetSystemInfo(&sys_info);
		MEMORY_BASIC_INFORMATION mem_basic_info = { 0 };
		HANDLE hProcess = TargetProcess;
		PVOID ab = (PVOID)0;

		for (Memory = start; Memory < start + size /*< (SIZE_T)sys_info.lpMaximumApplicationAddress*/; Memory += mem_basic_info.RegionSize)
		{
			//__oMsg_2(" [AllocationBase: %x - Address: %x - size: %x]-- type: %x, Protect: %x, state: %x", (DWORD)mem_basic_info.AllocationBase, (DWORD)mem_basic_info.BaseAddress, (DWORD)mem_basic_info.RegionSize, (DWORD)mem_basic_info.Type, (DWORD)mem_basic_info.Protect, (DWORD)mem_basic_info.State);
			ab = mem_basic_info.AllocationBase;
			if(VirtualQueryEx(hProcess, (LPCVOID)Memory, &mem_basic_info, sizeof(MEMORY_BASIC_INFORMATION)))
			{
				if (mem_basic_info.Protect == PAGE_EXECUTE_READ /*&& mem_basic_info.State == 0x1000 && mem_basic_info.Type == 0x20000*/)
				{
					BYTE* data = new BYTE[(DWORD)mem_basic_info.RegionSize];
					SIZE_T bytesRead;
					__oMsg(" [AllocationBase: %x - Address: %x - size: %x]-- type: %x, Protect: %x, state: %x", (DWORD)mem_basic_info.AllocationBase, (DWORD)mem_basic_info.BaseAddress, (DWORD)mem_basic_info.RegionSize, (DWORD)mem_basic_info.Type, (DWORD)mem_basic_info.Protect, (DWORD)mem_basic_info.State);
					
					ReadProcessMemory(TargetProcess, (LPVOID)mem_basic_info.BaseAddress, data, (DWORD)mem_basic_info.RegionSize, &bytesRead);
					for (DWORD i = 0; i < (DWORD)mem_basic_info.RegionSize; i++)
					{
						if (MemoryCompare((const BYTE*)(data + i), (const BYTE*)sig, mask)) {
							return (DWORD)mem_basic_info.BaseAddress + i;
						}
					}
					delete[] data;
				}
			}
		}
		return NULL;
	
		//BYTE* data = new BYTE[size];
		//SIZE_T bytesRead;
		//
		//
		//ReadProcessMemory(TargetProcess, (LPVOID)start, data, size, &bytesRead);
		//
		//DWORD test = 0;
		//for (DWORD i = 0; i < size; i++)
		//{
		//	
		//		if (MemoryCompare((const BYTE*)(data + i), (const BYTE*)sig, mask)) {
		//			return start + i;
		//		}
		//	 
		//		//__oMsg_2("error ....1: %d", i); 
		//		test = i;
		//}
		//	
		//__oMsg_2("test ....1: %x", test);
		//
		//delete[] data;
		//return NULL;
	}

	DWORD FindPattern(DWORD start, DWORD size, const char* sig, const char* mask) {
		BYTE* data = new BYTE[size];

		unsigned long bytesRead;
		if (!ReadProcessMemory(TargetProcess, (LPVOID)start, data, size, &bytesRead)) {
			return NULL;
		}

		for (DWORD i = 0; i < size; i++) {
			if (MemoryCompare((const BYTE*)(data + i), (const BYTE*)sig, mask)) {
				return start + i;
			}
		}
		return NULL;
	}
};


//// datatype for a module in memory (dll, regular exe) 
//struct module
//{
//	DWORD dwBase, dwSize;
//};
//
//class SignatureScanner
//{
//public:
//	module TargetModule;  // Hold target module
//	HANDLE TargetProcess; // for target process
//	DWORD  TargetId;      // for target process
//
//	// For getting a handle to a process
//	HANDLE GetProcess(char* processName)
//	{
//		HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
//		PROCESSENTRY32 entry;
//		entry.dwSize = sizeof(entry);
//
//		do
//		if (!StrCmp(entry.szExeFile, processName)) {
//			TargetId = entry.th32ProcessID;
//			CloseHandle(handle);
//			TargetProcess = OpenProcess(PROCESS_ALL_ACCESS, false, TargetId);
//			return TargetProcess;
//		}
//		while (Process32Next(handle, &entry));
//
//		return false;
//	}
//
//	// For getting information about the executing module
//	module GetModule(char* moduleName) {
//		HANDLE hmodule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, TargetId);
//		MODULEENTRY32 mEntry;
//		mEntry.dwSize = sizeof(mEntry);
//
//		do {
//			if (!strcmp(mEntry.szModule, (LPSTR)moduleName)) {
//				CloseHandle(hmodule);
//
//				TargetModule = { (DWORD)mEntry.hModule, mEntry.modBaseSize };
//				return TargetModule;
//			}
//		} while (Module32Next(hmodule, &mEntry));
//
//		module mod = { (DWORD)false, (DWORD)false };
//		return mod;
//	}
//
//	// Basic WPM wrapper, easier to use.
//	template <typename var>
//	bool WriteMemory(DWORD Address, var Value) {
//		return WriteProcessMemory(TargetProcess, (LPVOID)Address, &Value, sizeof(var), 0);
//	}
//
//	// Basic RPM wrapper, easier to use.
//	template <typename var>
//	var ReadMemory(DWORD Address) {
//		var value;
//		ReadProcessMemory(TargetProcess, (LPCVOID)Address, &value, sizeof(var), NULL);
//		return value;
//	}
//
//	// for comparing a region in memory, needed in finding a signature
//	bool MemoryCompare(const BYTE* bData, const BYTE* bMask, const char* szMask) {
//		for (; *szMask; ++szMask, ++bData, ++bMask) {
//			if (*szMask == 'x' && *bData != *bMask) {
//				return false;
//			}
//		}
//		return (*szMask == NULL);
//	}
//
//	// for finding a signature/pattern in memory of another process
//	DWORD FindSignature(DWORD start, DWORD size, const char* sig, const char* mask)
//	{
//		BYTE* data = new BYTE[size];
//		SIZE_T bytesRead;
//
//		ReadProcessMemory(TargetProcess, (LPVOID)start, data, size, &bytesRead);
//
//		for (DWORD i = 0; i < size; i++)
//		{
//			if (MemoryCompare((const BYTE*)(data + i), (const BYTE*)sig, mask)) {
//				return start + i;
//			}
//		}
//		delete[] data;
//		return NULL;
//	}
//
//	DWORD FindPattern(DWORD start, DWORD size, const char* sig, const char* mask) {
//		BYTE* data = new BYTE[size];
//
//		unsigned long bytesRead;
//		if (!ReadProcessMemory(TargetProcess, (LPVOID)start, data, size, &bytesRead)) {
//			return NULL;
//		}
//
//		for (DWORD i = 0; i < size; i++) {
//			if (MemoryCompare((const BYTE*)(data + i), (const BYTE*)sig, mask)) {
//				return start + i;
//			}
//		}
//		return NULL;
//	}
//};



