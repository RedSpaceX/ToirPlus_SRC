#include "StdAfx.h"
#include "AntiGarena.h"

using namespace std;


void pause(){
	return;
	DWORD pids_ggdllhost[2];
	FindProcessId(_T("ggdllhost.exe"), pids_ggdllhost);
	for (int i=0; i<2; i++)
	{
		if (pids_ggdllhost[i] > 0)
			PauseResumeThreadList(pids_ggdllhost[i],FALSE);
	}

	DWORD pids_msg[1];
	FindProcessId(_T("GarenaMessenger.exe"), pids_msg);
	if (pids_msg[0] > 0)
		PauseResumeThreadList(pids_msg[0],FALSE);

	DWORD pids_lol[1];
	FindProcessId(_T("lol.exe"), pids_lol);
	if (pids_lol[0] > 0)
		PauseResumeThreadList(pids_lol[0],FALSE);

	DWORD pids_lolClient[1];
	FindProcessId(_T("LolClient.exe"), pids_lolClient);
	if (pids_lolClient[0] > 0)
		PauseResumeThreadList(pids_lolClient[0],FALSE);

	DWORD pids_lolGame[1];
	FindProcessId(_T("League of Legends.exe"), pids_lolGame);
	if (pids_lolGame[0] > 0)
		PauseResumeThreadList(pids_lolGame[0],FALSE);

	DWORD pids_LeagueClientUxRender[2];
	FindProcessId(_T("LeagueClientUxRender.exe"), pids_LeagueClientUxRender);
	for (int i=0; i<2; i++)
	{
		if (pids_LeagueClientUxRender[i] > 0)
			PauseResumeThreadList(pids_LeagueClientUxRender[i],FALSE);
	}

	DWORD pids_LeagueClientUx[1];
	FindProcessId(_T("LeagueClientUx.exe"), pids_LeagueClientUx);
	if (pids_LeagueClientUx[0] > 0)
		PauseResumeThreadList(pids_LeagueClientUx[0],FALSE);

	DWORD pids_LeagueClient[1];
	FindProcessId(_T("LeagueClient.exe"), pids_LeagueClient);
	if (pids_LeagueClient[0] > 0)
		PauseResumeThreadList(pids_LeagueClient[0],FALSE);

}

void resume(){
    return;
	DWORD _pids_ggdllhost[2];
	FindProcessId(_T("ggdllhost.exe"), _pids_ggdllhost);
	for (int i=0; i<2; i++)
	{
		if (_pids_ggdllhost[i] > 0)
			PauseResumeThreadList(_pids_ggdllhost[i],TRUE);
	}

	DWORD _pids_msg[1];
	FindProcessId(_T("GarenaMessenger.exe"), _pids_msg);
	if (_pids_msg[0] > 0)
		PauseResumeThreadList(_pids_msg[0],TRUE);

	DWORD pids_lol[1];
	FindProcessId(_T("lol.exe"), pids_lol);
	if (pids_lol[0] > 0)
		PauseResumeThreadList(pids_lol[0],TRUE);

	DWORD pids_lolClient[1];
	FindProcessId(_T("LolClient.exe"), pids_lolClient);
	if (pids_lolClient[0] > 0)
		PauseResumeThreadList(pids_lolClient[0],TRUE);

	DWORD pids_lolGame[1];
	FindProcessId(_T("League of Legends.exe"), pids_lolGame);
	if (pids_lolGame[0] > 0)
		PauseResumeThreadList(pids_lolGame[0],TRUE);

	DWORD pids_LeagueClientUxRender[2];
	FindProcessId(_T("LeagueClientUxRender.exe"), pids_LeagueClientUxRender);
	for (int i=0; i<2; i++)
	{
		if (pids_LeagueClientUxRender[i] > 0)
			PauseResumeThreadList(pids_LeagueClientUxRender[i],TRUE);
	}

	DWORD pids_LeagueClientUx[1];
	FindProcessId(_T("LeagueClientUx.exe"), pids_LeagueClientUx);
	if (pids_LeagueClientUx[0] > 0)
		PauseResumeThreadList(pids_LeagueClientUx[0],TRUE);

	DWORD pids_LeagueClient[1];
	FindProcessId(_T("LeagueClient.exe"), pids_LeagueClient);
	if (pids_LeagueClient[0] > 0)
		PauseResumeThreadList(pids_LeagueClient[0],TRUE);
}

BOOL PauseResumeThreadList(DWORD dwOwnerPID, bool bResumeThread) 
{ 
	HANDLE        hThreadSnap = NULL; 
	BOOL          bRet        = FALSE; 
	THREADENTRY32 te32        = {0}; 

	// Take a snapshot of all threads currently in the system. 

	hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0); 
	if (hThreadSnap == INVALID_HANDLE_VALUE) 
		return (FALSE); 

	// Fill in the size of the structure before using it. 

	te32.dwSize = sizeof(THREADENTRY32); 

	// Walk the thread snapshot to find all threads of the process. 
	// If the thread belongs to the process, add its information 
	// to the display list.

	if (Thread32First(hThreadSnap, &te32)) 
	{ 
		do 
		{ 
			if (te32.th32OwnerProcessID == dwOwnerPID) 
			{
				HANDLE hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, te32.th32ThreadID);
				if (bResumeThread)
				{					
					ResumeThread(hThread);
				}
				else
				{					
					SuspendThread(hThread);
				}
				CloseHandle(hThread);
			} 
		}
		while (Thread32Next(hThreadSnap, &te32)); 
		bRet = TRUE; 
	} 
	else 
		bRet = FALSE;          // could not walk the list of threads 

	// Do not forget to clean up the snapshot object. 
	CloseHandle (hThreadSnap); 

	return (bRet); 
} 

void FindProcessId(const std::wstring& processName, DWORD * pids)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if ( processesSnapshot == INVALID_HANDLE_VALUE )
		return;

	int i=0;
	Process32First(processesSnapshot, &processInfo);

	if ( !processName.compare(processInfo.szExeFile) )
	{
		//CloseHandle(processesSnapshot);
		//return processInfo.th32ProcessID;
		pids[i] = processInfo.th32ProcessID;
		i++;
	}
	while ( Process32Next(processesSnapshot, &processInfo) )
	{
		if ( !processName.compare(processInfo.szExeFile) )
		{
			//CloseHandle(processesSnapshot);
			//return processInfo.th32ProcessID;
			pids[i] = processInfo.th32ProcessID;
			i++;
		}
	}

	CloseHandle(processesSnapshot);
}