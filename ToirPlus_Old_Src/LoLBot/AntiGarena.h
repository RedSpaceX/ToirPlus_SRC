#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <iostream>
#include <tlhelp32.h>

void FindProcessId(const std::wstring& processName, DWORD * pids);
BOOL PauseResumeThreadList(DWORD dwOwnerPID, bool bResumeThread); 
void pause();
void resume();