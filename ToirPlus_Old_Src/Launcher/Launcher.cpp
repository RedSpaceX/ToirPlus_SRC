// Laucher.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"

#include <string>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tlhelp32.h>


#include "IniManager.h"
#include "resource.h"

#include "..\\InjectBot\\InjectBot.h"
//#include "..\\InjectBot\\AntiBan.h"
//#include "..\\LoLBot\\Commons.h"
//#include "..\\Lib\\VMProtectSDK.h"

#include "Launcher.h"

bool g_bCheckConnectApp = true;// ko truyen dc roi, fix ben trong thoi
HINSTANCE			hDll = NULL;
//---------------------------------------------------------------------------------

#define ID_EXIT_APP                     12302
HWND g_hWinAPP;

void SettingParams(void);
void FindProcessId(const std::wstring& processName, DWORD * pids);
BOOL PauseResumeThreadList(DWORD dwOwnerPID, bool bResumeThread); 

const UINT WM_HOOK_WRITE = RegisterWindowMessage(_T("WM_HOOK_WRITE"));

char sz__League_of_Legends__TM__Client[] = {76, 101, 97, 103, 117, 101, 32, 111, 102, 32, 76, 101, 103, 101, 110, 100, 115, 32, 40, 84, 77, 41, 32, 67, 108, 105, 101, 110, 116, 0};
char sz__League_of_Legends_exe[] = {76, 101, 97, 103, 117, 101, 32, 111, 102, 32, 76, 101, 103, 101, 110, 100, 115, 46, 101, 120, 101, 0};
char sz__WINHTTP_dll[] = {87, 73, 78, 72, 84, 84, 80, 46, 100, 108, 108, 0};
char sz__WTSAPI32_dll[] = {87, 84, 83, 65, 80, 73, 51, 50, 46, 100, 108, 108, 0};

//---------------------------------------------------------------------------------
void pause(){
	return;
	VMProtectBegin("Launcer_VM__pause");
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

	/*DWORD pids_lolGame[1];
	FindProcessId(_T("League of Legends.exe"), pids_lolGame);
	if (pids_lolGame[0] > 0)
		PauseResumeThreadList(pids_lolGame[0],FALSE);*/

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
	VMProtectEnd();
}

//---------------------------------------------------------------------------------
void resume()
{
	return;
	VMProtectBegin("Launcer_VM__resume");
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

	/*DWORD pids_lolGame[1];
	FindProcessId(_T("League of Legends.exe"), pids_lolGame);
	if (pids_lolGame[0] > 0)
		PauseResumeThreadList(pids_lolGame[0],TRUE);*/

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
	VMProtectEnd();
}

//---------------------------------------------------------------------------------
int SetDebugPrivileges(void) 
{ 
	VMProtectBegin("Launcer_VM__SetDebugPrivileges");
	TOKEN_PRIVILEGES priv = {0};
	HANDLE hToken = NULL; 

	if( OpenProcessToken( GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken ) ) {
		priv.PrivilegeCount           = 1;
		priv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

		if( LookupPrivilegeValue( NULL, SE_DEBUG_NAME, &priv.Privileges[0].Luid ) ) {
			if(AdjustTokenPrivileges( hToken, FALSE, &priv, 0, NULL, NULL ) == 0) {
				//printf("AdjustTokenPrivilege Error! [%u]\n",GetLastError());
			} 
		}	

		CloseHandle( hToken );
	} 
	VMProtectEnd();
	return GetLastError();
}

//---------------------------------------------------------------------------------
HANDLE AttachToProcess(DWORD procID) 
{
	OSVERSIONINFO osver; 
	// SetDebugPrivileges SE_DEBUG_NAME
	//printf("[+] Setting Debug Privileges [%d]\n", SetDebugPrivileges());
	SetDebugPrivileges();
	VMProtectBegin("Launcer_VM__AttachToProcess");
	osver.dwOSVersionInfoSize = sizeof(osver);
	if (GetVersionEx(&osver)) {	
		if (osver.dwMajorVersion == 5) {
			//printf("\t[+] Detected Windows XP\n");
			return OpenProcess( PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_CREATE_THREAD, 0, procID );
		}
		if (osver.dwMajorVersion == 6 && osver.dwMinorVersion == 0) {
			//printf("\t[+] Detected Windows Vista\n");
			return NULL;
		}
		if (osver.dwMajorVersion == 6 && osver.dwMinorVersion == 1)	{
			//printf("\t[+] Detected Windows 7\n");
			//printf("\t[+] Attaching to Process ID: %d\n", procID);
			return OpenProcess( PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, FALSE, procID );
		}
		return OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, FALSE, procID);
	} else {
		//printf("\n[!] Could not detect OS version\n");
	}
	VMProtectEnd();
	return NULL;
}

//-------------------------------------------------------------------------------------------------------------------
//=================== tls callback ANTI DEBUG =======================================================================
extern DWORD nBase_MainDLL;
int nCallBack_Laucher = 0;
#pragma comment(lib,"ntdll.lib")
#pragma comment(linker,"/include:__tls_used") // This will cause the linker to create the TLS directory
#pragma section(".CRT$XLB",read) // Create a new section
//extern "C"
//{
//	int NTAPI NtQueryInformationProcess(HANDLE hProcess,ULONG InfoClass,PVOID Buffer,ULONG Length,PULONG ReturnLength);
//}
#define NtCurrentProcess() (HANDLE)-1
void WINAPI Laucher_TlsCallback(PVOID Module,DWORD Reason,PVOID Context)// VM PROTECT ON
{
	
	//__oMsg("1_nCallBack_Laucher: %d", nCallBack_Laucher);
	if(nCallBack_Laucher >= 2)
	{
		resume();
		return;
	}
	
	return;
	VMProtectBegin("Launcer_VM__Laucher_TlsCallback");
	if(nCallBack_Laucher == 0)
	{
		g_hWinAPP = ::FindWindow(_T("XX_RiotWindowClass_XXX"), NULL); // Game
		if (g_hWinAPP)
		{
			DWORD dwProcessID;
			GetWindowThreadProcessId(g_hWinAPP, &dwProcessID);
			SetDebugPrivileges();
			
			__oMsg("found-Window");
			
			glo23523vsasfsabal(g_hWinAPP);
			//InjectLibraryW(dwProcessID, L"C:\\Users\\admin\\Desktop\\Working\\Sample\\SAFE_NOTT\\FOR_ADDR8.19\\Release\\riot.dll");

			return;
			return;
			return;
			return;


			//EjectLibraryW(dwProcessID, L"G:\\LMHT_VN\\GameData\\Apps\\LoLVN\\gp\\bs.gp");
			bool abc = MapRemoteModuleW(dwProcessID, L"D:\\___WORKING\\Temp\\GAS\\Release\\riot.dll");	//D:\___WORKING\Temp\FOR_ADDRESS\Release
			//bool abc = MapRemoteModuleA(dwProcessID, "C:\\Users\\GCafe\\Downloads\\Demacia_2.45\\GameData\\riot.dll");
			  //bool abc = MapRemoteModuleA(dwProcessID, "C:\\AutoLMHT\\riot.dll");

			__oMsg("found-Window: %d", abc);
			//MapRemoteModuleA(dwProcessID, "C:\\Users\\Leon\\Desktop\\Toir_1.21\\Plugin\\riot.dll");
			//MapRemoteModuleA(dwProcessID, "C:\\Users\\Administrator\\Desktop\\New\\riot.dll");
			
			//C:\Users\Administrator.ADMIN\Desktop\1
			//MapRemoteModuleA(dwProcessID, "C:\\Users\\Administrator\\Desktop\\Toir_1.8\\Plugin\\Scripts\\1Test\\riot.dll");
			
			//MapRemoteModuleA(dwProcessID, "C:\\Users\\Administrator\\Desktop\\Toir_1.3\\tets\\riot.dll");
			//if(MapRemoteModuleA_Bin(dwProcessID, data))
			//{
			//	if(nBase_MainDLL != 0)// Erase PE-Header
			//	{
			//		DWORD dwProcessID;
			//		GetWindowThreadProcessId(g_hWinAPP, &dwProcessID);
			//		HANDLE dwH = AttachToProcess(dwProcessID);

			//		DWORD nSize  = 4;
			//		DWORD nValue = 0;
			//		DWORD nData     = 0;
			//		for (int i = 0; i < 1024; ++i)
			//		{
			//			nData = nBase_MainDLL + 4*i;
			//			WriteProcessMemory(dwH, (LPVOID)nData, &nValue, nSize, &nSize);
			//		}
			//	}
			//	//__oMsg("Ok");
			//	//ListModules(3660);
			//}
			//else MessageBoxA(NULL, "Injection failed !!!", "Failed", MB_OK);
		}
		pause();
		nCallBack_Laucher += 1;
	}
	VMProtectEnd();
}
// Put the TLS callback address into a null terminated array of the .CRT$XLB section
__declspec(allocate(".CRT$XLB")) PIMAGE_TLS_CALLBACK CallbackAddress[]={Laucher_TlsCallback,NULL};
//=================== END tls callback ANTI DEBUG ===================================================================


//-------------------------------------------------------------------------------------------------------------------
BOOL PauseResumeThreadList(DWORD dwOwnerPID, bool bResumeThread) 
{ 
	VMProtectBegin("Launcer_VM__PauseResumeThreadList");
	HANDLE        hThreadSnap = NULL; 
	BOOL          bRet        = FALSE; 
	THREADENTRY32 te32        = {0}; 

	hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0); 
	if (hThreadSnap == INVALID_HANDLE_VALUE) 
		return (FALSE); 
	te32.dwSize = sizeof(THREADENTRY32); 
	if (Thread32First(hThreadSnap, &te32)) 
	{ 
		do 
		{ 
			if (te32.th32OwnerProcessID == dwOwnerPID) 
			{
				HANDLE hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, te32.th32ThreadID);
				if (bResumeThread)
				{					
					DWORD nResume = ResumeThread(hThread);
				}
				else
				{					
					DWORD nSuspend = SuspendThread(hThread);
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
	VMProtectEnd();
} 

//-------------------------------------------------------------------------------------------------------------------
void FindProcessId(const std::wstring& processName, DWORD * pids)
{
	VMProtectBegin("Launcer_VM__FindProcessId");
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
	VMProtectEnd();
}

//-------------------------------------------------------------------------------------------------------------------
void SettingParams(void)
{
	VMProtectBegin("Launcer_VM__SettingParams");
	// load information from ini file
	CIniManager::GetInstance()->ReadIniFile();
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_ATK_CURRENT_SELECTED, CIniManager::GetInstance()->GetAtkCurrentSelected());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_COMBO, CIniManager::GetInstance()->GetCombo());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_COMBO_SKILL_Q, CIniManager::GetInstance()->GetComboUseQ());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_COMBO_SKILL_W, CIniManager::GetInstance()->GetComboUseW());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_COMBO_SKILL_E, CIniManager::GetInstance()->GetComboUseE());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_COMBO_SKILL_R, CIniManager::GetInstance()->GetComboUseR());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_CLEAR_LANE, CIniManager::GetInstance()->GetClearLane());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_CLEARLANE_SKILL_Q, CIniManager::GetInstance()->GetClearLaneUseQ());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_CLEARLANE_SKILL_W, CIniManager::GetInstance()->GetClearLaneUseW());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_CLEARLANE_SKILL_E, CIniManager::GetInstance()->GetClearLaneUseE());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_CLEARLANE_SKILL_R, CIniManager::GetInstance()->GetClearLaneUseR());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HARASS, CIniManager::GetInstance()->GetHarass());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HARASS_SKILL_Q, CIniManager::GetInstance()->GetHarassUseQ());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HARASS_SKILL_W, CIniManager::GetInstance()->GetHarassUseW());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HARASS_SKILL_E, CIniManager::GetInstance()->GetHarassUseE());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HARASS_SKILL_R, CIniManager::GetInstance()->GetHarassUseR());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_LASTHIT, CIniManager::GetInstance()->GetLastHit());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_MOVE2MOUSE, CIniManager::GetInstance()->GetMove2Mouse());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_EVADE_LINE, CIniManager::GetInstance()->GetEvadeLine());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_EVADE_CIRCLE, CIniManager::GetInstance()->GetEvadeCircle());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_EVADE_DANGEROUS, CIniManager::GetInstance()->GetEvadeDangerous());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HACKZOOM, CIniManager::GetInstance()->GetHackZoom());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_MODSKIN, CIniManager::GetInstance()->GetModSkin());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, IDC_DANHVOIMAY, CIniManager::GetInstance()->GetPlayWithBot());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_MP_CLEARLANE, CIniManager::GetInstance()->GetPercentManaClearLane());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_MP_HARASS, CIniManager::GetInstance()->GetPercentManaHarass());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_DELAY_SKILL, CIniManager::GetInstance()->GetDelaySkillAfter());
	//::PostMessage(g_hWinAPP, WM_HOOK_WRITE, IDC_BTN_LOGIN, g_bCheckConnectApp);// sau khi click vao nut DN hook xong thi gui sang dll

	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_TAT_BAT_VE, CIniManager::GetInstance()->GetBatTatVeHinh());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_MAT_THUONG, CIniManager::GetInstance()->GetVeMatThuong());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_MAT_KIEM_SOAT, CIniManager::GetInstance()->GetVeMatKiemSoat());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_GANK, CIniManager::GetInstance()->GetVeCanhBaoGank());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_DOAN_HUONG, CIniManager::GetInstance()->GetVeDoanHuong());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_TAM_TRU_DICH, CIniManager::GetInstance()->GetVeTamTruDich());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_TAM_TRU_DONG_MINH, CIniManager::GetInstance()->GetVeTamTruDongMinh());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_TIME_ENEMY_RECALL, CIniManager::GetInstance()->GetVeTimeEnemyRecall());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_TIME_REVIVE_ENEMY_SKILL, CIniManager::GetInstance()->GetVeTimeEnemyHoiSkill());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_TIME_REVIVE_ENEMY_SPELL, CIniManager::GetInstance()->GetVeTimeEnemyHoiSpell());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_TIME_JUNGLE_APPEAR, CIniManager::GetInstance()->GetVeTimeXuatHienQuaiRung());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_PLAYER_DANH_THUONG, CIniManager::GetInstance()->GetVePlayerDanhThuong());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_PLAYER_SKILL_Q, CIniManager::GetInstance()->GetVePlayerSkillQ());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_PLAYER_SKILL_W, CIniManager::GetInstance()->GetVePlayerSkillW());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_PLAYER_SKILL_E, CIniManager::GetInstance()->GetVePlayerSkillE());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_PLAYER_SKILL_R, CIniManager::GetInstance()->GetVePlayerSkillR());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_ENEMY_DANH_THUONG, CIniManager::GetInstance()->GetVeEnemyDanhThuong());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_ENEMY_SKILL_Q, CIniManager::GetInstance()->GetVeEnemySkillQ());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_ENEMY_SKILL_W, CIniManager::GetInstance()->GetVeEnemySkillW());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_ENEMY_SKILL_E, CIniManager::GetInstance()->GetVeEnemySkillE());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_ENEMY_SKILL_R, CIniManager::GetInstance()->GetVeEnemySkillR());

	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HOIMAU_SKILL,		CIniManager::GetInstance()->GetHoiMau_Skill());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HOIMAU_ITEM,			CIniManager::GetInstance()->GetHoiMau_Item());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_THIEUDOT,			CIniManager::GetInstance()->GetThieuDot());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_THANH_TAY,			CIniManager::GetInstance()->GetThanhTay());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_LA_CHAN,				CIniManager::GetInstance()->GetLaChan());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_TRUNG_PHAT,			CIniManager::GetInstance()->GetTrungPhat());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VODANH,				CIniManager::GetInstance()->GetVoDanh());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HEXTECH,				CIniManager::GetInstance()->GetHextech());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_TIAMAT,				CIniManager::GetInstance()->GetTiamat());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_IRON_SOLARI,			CIniManager::GetInstance()->GetIronSolari());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_SON_THACH,			CIniManager::GetInstance()->GetSonThach());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_DONG_HO_CAT,			CIniManager::GetInstance()->GetDongHoCat());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_QUYEN_TRUONG_DTS,	CIniManager::GetInstance()->GetQuyenTruongDTS());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_KHAN_GIAI_THUAT,		CIniManager::GetInstance()->GetKhanGiaiThuat());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HOM_MIKAEL,			CIniManager::GetInstance()->GetHomMikael());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_CHUOC_TOI,			CIniManager::GetInstance()->GetChuocToi());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_KHIENBANG,			CIniManager::GetInstance()->GetKhienBang());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_HM_SKILL,			CIniManager::GetInstance()->GetPercentHP4Skill());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_HM_ITEM,			CIniManager::GetInstance()->GetPercentHP4Item());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_LA_CHAN,			CIniManager::GetInstance()->GetPercentHP4LaChan());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_IRON_SOLARI,		CIniManager::GetInstance()->GetPercentHP4IronSolari());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_SON_THACH,			CIniManager::GetInstance()->GetPercentHP4SonThach());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_DONG_HO_CAT,		CIniManager::GetInstance()->GetPercentHP4DongHoCat());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_QT_DTS,			CIniManager::GetInstance()->GetPercentHP4QT_DTS());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_CHUOC_TOI,			CIniManager::GetInstance()->GetPercentHP4ChuocToi());
	VMProtectEnd();
}


//-------------------------------------------------------------------------------------------------------------------
const BYTE HEX[0x80] = //This is the ASCII table in number value form
{   //0     1     2     3     4     5     6    7      8     9     A     B     C     D     E     F
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//0
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//1
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//2
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//3
	0x00, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//4
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//5
	0x00, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//6
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 //7
};
void StringToHex(const char* str, BYTE* hex)
{
	int len = strlen(str)/2;
	for(int i = 0; i < len; i++)
	{
		hex[i] =  (HEX[*str++] << 4);
		hex[i] += (HEX[*str++]);
	}
}


//--------------------------------//--------------------------------||
//--------------------------------//--------------------------------||
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

// link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")


#include <time.h>       /* time */
//--------------------------------//--------------------------------||
//--------------------------------//--------------------------------||
int CHECK_ID_PW(char* myID, char* myPW)
{
	int checkID = 69;

	if (strlen(myID) != 11)
	{
		__oMsg("Wrong.strlen(ID)");
		checkID = 12;
		return 0;
	}

	//int ID_1[12] = {50^69, 86^69, 65^69, 105^69, 108^69, 111^69, 90^69, 97^69, 54^69, 56^69, 104^69, 53^69};
	if ((myID[0]^69) !=	(50 ^69) &&
		(myID[0]^69) !=	(86 ^69) &&
		(myID[0]^69) !=	(65 ^69) &&
		(myID[0]^69) !=	(105^69) && 
		(myID[0]^69) !=	(108^69) && 
		(myID[0]^69) !=	(111^69) && 
		(myID[0]^69) !=	(90 ^69) && 
		(myID[0]^69) !=	(97 ^69) && 
		(myID[0]^69) !=	(54 ^69) && 
		(myID[0]^69) !=	(56 ^69) && 
		(myID[0]^69) !=	(104^69) && 
		(myID[0]^69) !=	(53 ^69))
	{
		checkID = 1;
		__oMsg("Wrong.ID.1: %d", myID[0]);
		return 0;
	}

	//int ID_2[10] = {48<<2, 49<<2, 50<<2, 67<<2, 97<<2, 78<<2, 54<<2, 55<<2, 56<<2, 57<<2};
	if ((myID[1]<<2) !=	(48 <<2) &&
		(myID[1]<<2) !=	(49 <<2) &&
		(myID[1]<<2) !=	(50 <<2) &&
		(myID[1]<<2) !=	(67 <<2) && 
		(myID[1]<<2) !=	(97 <<2) && 
		(myID[1]<<2) !=	(78 <<2) && 
		(myID[1]<<2) !=	(54 <<2) && 
		(myID[1]<<2) !=	(55 <<2) && 
		(myID[1]<<2) !=	(56 <<2) && 
		(myID[1]<<2) !=	(57 <<2))
	{
		checkID = 2;
		__oMsg("Wrong.ID.2: %d", myID[1]);
		return 0;
	}

	//int ID_3[8]  = {79^25, 49^25, 98^25, 112^25, 52^25, 70^25, 82^25, 71^25};
	if ((myID[2]^25) !=	(79 ^25) &&
		(myID[2]^25) !=	(49 ^25) &&
		(myID[2]^25) !=	(98 ^25) &&
		(myID[2]^25) !=	(112^25) && 
		(myID[2]^25) !=	(52 ^25) && 
		(myID[2]^25) !=	(70^25) && 
		(myID[2]^25) !=	(82 ^25) && 
		(myID[2]^25) !=	(71 ^25)) 
	{
		checkID = 3;
		__oMsg("Wrong.ID.3: %d", myID[2]);
		return 0;
	}

	//int ID_4[6]  = {99<<3, 97<<3, 50<<3, 53<<3, 78<<3, 110<<3};
	if ((myID[3]<<3) !=	(99 <<3) &&
		(myID[3]<<3) !=	(97 <<3) &&
		(myID[3]<<3) !=	(50 <<3) &&
		(myID[3]<<3) !=	(53 <<3) && 
		(myID[3]<<3) !=	(78 <<3) && 
		(myID[3]<<3) !=	(110<<3))
	{
		checkID = 4;
		__oMsg("Wrong.ID.4: %d", myID[3]);
		return 0;
	}

	//int ID_5[4]  = {103^205, 55^205, 57^205, 83^205};
	if ((myID[4]^205) != (103^205) &&
		(myID[4]^205) != (55 ^205) &&
		(myID[4]^205) != (57 ^205) &&
		(myID[4]^205) != (83 ^205)) 
	{
		checkID = 5;
		__oMsg("Wrong.ID.5: %d", myID[4]);
		return 0;
	}

	//int ID_6[3]  = {51^52, 119^52, 77^52};
	if ((myID[5]^52) != (51 ^52) &&
		(myID[5]^52) != (119^52) &&
		(myID[5]^52) != (77 ^52)) 
	{
		checkID = 6;
		__oMsg("Wrong.ID.6: %d", myID[5]);
		return 0;
	}

	//int ID_7[5]  = {67<<4, 104<<4, 48<<4, 85<<4, 114<<4};
	if ((myID[6]<<4) != (67 <<4) &&
		(myID[6]<<4) != (104<<4) &&
		(myID[6]<<4) != (48 <<4) &&
		(myID[6]<<4) != (85 <<4) &&
		(myID[6]<<4) != (114<<4)) 
	{
		checkID = 7;
		__oMsg("Wrong.ID.7: %d", myID[6]);
		return 0;
	}

	//int ID_8[7]  = {121^502, 106^502, 52^502, 49^502, 81^502, 76^502, 69^502};
	if ((myID[7]^502) !=	(121^502) &&
		(myID[7]^502) !=	(106^502) &&
		(myID[7]^502) !=	(52 ^502) &&
		(myID[7]^502) !=	(49 ^502) && 
		(myID[7]^502) !=	(81 ^502) && 
		(myID[7]^502) !=	(76 ^502) && 
		(myID[7]^502) !=	(69 ^502)) 
	{
		checkID = 8;
		__oMsg("Wrong.ID.8: %d", myID[7]);
		return 0;
	}

	//int ID_9[5]  = {57^102, 55^102, 52^102, 49^102, 50^102};		// ****** phai bang myPW[8] ****** CHU Y
	if ((myID[8]^102) !=	(57 ^102) &&
		(myID[8]^102) !=	(55 ^102) &&
		(myID[8]^102) !=	(52 ^102) &&
		(myID[8]^102) !=	(49 ^102) && 
		(myID[8]^102) !=	(50 ^102)) 
	{
		checkID = 9;
		__oMsg("Wrong.ID.9: %d", myID[8]);
		return 0;
	}

	
	//int ID_10[10] = {68^47, 113^47, 57^47, 54^47, 72^47, 117^47, 48^47, 50^47, 102^47, 118^47};
	if ((myID[9]^47) !=	(68 ^47) &&
		(myID[9]^47) !=	(113^47) &&
		(myID[9]^47) !=	(57 ^47) &&
		(myID[9]^47) !=	(54 ^47) && 
		(myID[9]^47) !=	(72 ^47) && 
		(myID[9]^47) !=	(117^47) && 
		(myID[9]^47) !=	(48 ^47) && 
		(myID[9]^47) !=	(50 ^47) && 
		(myID[9]^47) !=	(102^47) && 
		(myID[9]^47) !=	(118^47)) 
	{
		checkID = 10;
		__oMsg("Wrong.ID.10: %d", myID[9]);
		return 0;
	}

	//int ID_10[9] = {49^88, 122^88, 84^88, 53^88, 66^88, 109^88, 56^88, 52^88, 71^88};
	if ((myID[10]^88) !=	(49 ^88) &&
		(myID[10]^88) !=	(122^88) &&
		(myID[10]^88) !=	(84 ^88) &&
		(myID[10]^88) !=	(53 ^88) && 
		(myID[10]^88) !=	(66 ^88) && 
		(myID[10]^88) !=	(109^88) && 
		(myID[10]^88) !=	(56 ^88) && 
		(myID[10]^88) !=	(52 ^88) && 
		(myID[10]^88) !=	(71 ^88)) 
	{
		checkID = 11;
		__oMsg("Wrong.ID.11: %d", myID[10]);
		return 0;
	}
	
	if (checkID == 69 ) checkID = 169;
	if (checkID != 169)
	{
		__oMsg("WRONGGGGGGGGGGGGG -----ID----------------");
	}

 //------------ END.CHECK.ID ------------/------------/------------||
 //------------/------------/------------/------------/------------||

	
	int checkPW = 96;
	if (strlen(myPW) != 11)
	{
		__oMsg("Wrong.strlen(PW)");
		checkPW = 12;
		return 0;
	}

	//int PW_1[11] = {52^96, 112^96, 78^96, 104^96, 53^96, 88^96, 99^96, 65^96, 103^96, 55^96, 107^96};
	if ((myPW[0]^96) !=	(52 ^96) &&
		(myPW[0]^96) !=	(112^96) &&
		(myPW[0]^96) !=	(78 ^96) &&
		(myPW[0]^96) !=	(104^96) && 
		(myPW[0]^96) !=	(53 ^96) && 
		(myPW[0]^96) !=	(88 ^96) && 
		(myPW[0]^96) !=	(99 ^96) && 
		(myPW[0]^96) !=	(65 ^96) && 
		(myPW[0]^96) !=	(103^96) && 
		(myPW[0]^96) !=	(55 ^96) && 
		(myPW[0]^96) !=	(107^96))
	{
		checkPW = 1;
		__oMsg("Wrong.PW.1: %d", myPW[0]);
		return 0;
	}

	//int PW_2[9] = {48<<3, 67<<3, 50<<3, 51<<3, 104<<3, 85<<3, 110<<3, 71<<3, 56<<3};
	if ((myPW[1]<<3) !=	(48 <<3) &&
		(myPW[1]<<3) !=	(67 <<3) &&
		(myPW[1]<<3) !=	(50 <<3) &&
		(myPW[1]<<3) !=	(51 <<3) && 
		(myPW[1]<<3) !=	(104<<3) && 
		(myPW[1]<<3) !=	(85 <<3) && 
		(myPW[1]<<3) !=	(110<<3) && 
		(myPW[1]<<3) !=	(71 <<3) && 
		(myPW[1]<<3) !=	(56 <<3))
	{
		checkPW = 2;
		__oMsg("Wrong.PW.2: %d", myPW[1]);
		return 0;
	}

	//int PW_3[7] = {116^66, 52^66, 77^66, 101^66, 55^66, 114^66, 83^66};
	if ((myPW[2]^66) !=	(116^66) &&
		(myPW[2]^66) !=	(52 ^66) &&
		(myPW[2]^66) !=	(77 ^66) &&
		(myPW[2]^66) !=	(101^66) && 
		(myPW[2]^66) !=	(55 ^66) && 
		(myPW[2]^66) !=	(114^66) && 
		(myPW[2]^66) !=	(83 ^66)) 
	{
		checkPW = 3;
		__oMsg("Wrong.PW.3: %d", myPW[2]);
		return 0;
	}

	//int PW_4[5] = {49^32, 72^32, 97^32, 105^32, 57^32};
	if ((myPW[3]^32) !=	(49 ^32) &&
		(myPW[3]^32) !=	(72 ^32) &&
		(myPW[3]^32) !=	(97 ^32) &&
		(myPW[3]^32) !=	(105^32) && 
		(myPW[3]^32) !=	(57 ^32))
	{
		checkPW = 4;
		__oMsg("Wrong.PW.4: %d", myPW[3]);
		return 0;
	}

	//int PW_5[3] = {50^84, 53^84, 67^84};
	if ((myPW[4]^84) != (50 ^84) &&
		(myPW[4]^84) != (53 ^84) &&
		(myPW[4]^84) != (67 ^84)) 
	{
		checkPW = 5;
		__oMsg("Wrong.PW.5: %d", myPW[4]);
		return 0;
	}

	//int PW_6[4] = {74^21, 56^21, 55^21, 122^21};
	if ((myPW[5]^21) != (74 ^21) &&
		(myPW[5]^21) != (56 ^21) &&
		(myPW[5]^21) != (55 ^21) &&
		(myPW[5]^21) != (122^21)) 
	{
		checkPW = 6;
		__oMsg("Wrong.PW.6: %d", myPW[5]);
		return 0;
	}

	//int PW_7[5] = {118^68, 87^68, 111^68, 54^68, 107^68};
	if ((myPW[6]^68) != (118^68) &&
		(myPW[6]^68) != (87 ^68) &&
		(myPW[6]^68) != (111^68) &&
		(myPW[6]^68) != (54 ^68) &&
		(myPW[6]^68) != (107^68)) 
	{
		checkPW = 7;
		__oMsg("Wrong.PW.7: %d", myPW[6]);
		return 0;
	}

	//int PW_8[4] = {105^99, 97^99, 117^99, 52^99};
	if ((myPW[7]^99) !=	(105^99) &&
		(myPW[7]^99) !=	(97 ^99) &&
		(myPW[7]^99) !=	(117^99) &&
		(myPW[7]^99) !=	(52 ^99)) 
	{
		checkPW = 8;
		__oMsg("Wrong.PW.8: %d", myPW[7]);
		return 0;
	}
	
	//int PW_10[5]  = {57^102, 55^102, 52^102, 49^102, 50^102};		// ****** phai bang myID[8] ****** CHU Y
	if (myPW[8] != myID[8]) 
	{
		checkPW = 9;
		__oMsg("Wrong.PW.9: %d", myPW[8]);
		return 0;
	}

	//int PW_10[6] = {116^609, 82^609, 65^609, 78^609, 113^609, 89^609};
	if ((myPW[9]^609) !=	(116^609) &&
		(myPW[9]^609) !=	(82 ^609) &&
		(myPW[9]^609) !=	(65 ^609) &&
		(myPW[9]^609) !=	(78 ^609) && 
		(myPW[9]^609) !=	(113^609) &&  
		(myPW[9]^609) !=	(89 ^609)) 
	{
		checkPW = 10;
		__oMsg("Wrong.PW.10: %d", myPW[9]);
		return 0;
	}

	//int PW_11[7] = {49^906, 51^906, 53^906, 50^906, 54^906, 72^906, 78^906};
	if ((myPW[10]^906) !=	(49 ^906) &&
		(myPW[10]^906) !=	(51 ^906) &&
		(myPW[10]^906) !=	(53 ^906) &&
		(myPW[10]^906) !=	(50 ^906) && 
		(myPW[10]^906) !=	(54 ^906) && 
		(myPW[10]^906) !=	(72 ^906) && 
		(myPW[10]^906) !=	(78 ^906)) 
	{
		checkPW = 11;
		__oMsg("Wrong.PW.11: %d", myPW[9]);
		return 0;
	}

	if (checkPW == 96 )	checkPW = 196;
	if (checkPW != 196)
	{
		__oMsg("WRONGGGGGGGGGGGGG -----PW----------------");
	}


	return 1;
}


void GEN_ID_PW(int soluong)
{
	srand ((unsigned)time(NULL));
	char myID[12] = {0};
	char myPW[12] = {0};

	for (int ID = 0; ID < soluong; ID++)
	{
		//====== ID ====================================================================:
		//------ ID.1: (2    , V    , A    , i     , l     , o     , Z    , a    , 6    , 8    , h     , 5 )
		int ID_1[12] = {50^69, 86^69, 65^69, 105^69, 108^69, 111^69, 90^69, 97^69, 54^69, 56^69, 104^69, 53^69};
		myID[0] = ID_1[rand() % 12] ^ 69;

		//------ ID.2: (0    , 1    , 2    , C    , a    , N    , 6    , 7    , 8    , 9 )
		int ID_2[10] = {48<<2, 49<<2, 50<<2, 67<<2, 97<<2, 78<<2, 54<<2, 55<<2, 56<<2, 57<<2};
		myID[1] = ID_2[rand() % 10] >> 2;

		//------ ID.3: (O    , 1    , b    , p     , 4    , F    , R    , G )
		int ID_3[8]  = {79^25, 49^25, 98^25, 112^25, 52^25, 70^25, 82^25, 71^25};
		myID[2] = ID_3[rand() % 8] ^ 25;
		
		//------ ID.4: (c    , a    , 2    , 5    , N    , n )
		int ID_4[6]  = {99<<3, 97<<3, 50<<3, 53<<3, 78<<3, 110<<3};
		myID[3] = ID_4[rand() % 6] >> 3;
					
		//------ ID.5: (g      , 7     , 9    , S )
		int ID_5[4]  = {103^205, 55^205, 57^205, 83^205};
		myID[4] = ID_5[rand() % 4] ^ 205;

		//------ ID.6: (3    , w     , M )
		int ID_6[3]  = {51^52, 119^52, 77^52};
		myID[5] = ID_6[rand() % 3] ^ 52;

		//------ ID.7: (C    , h     , 0    , U	   , r )
		int ID_7[5]  = {67<<4, 104<<4, 48<<4, 85<<4, 114<<4};
		myID[6] = ID_7[rand() % 5] >> 4;

		//------ ID.8: (y      , j      , 4     , 1	    , Q     , L     , E )
		int ID_8[7]  = {121^502, 106^502, 52^502, 49^502, 81^502, 76^502, 69^502};
		myID[7] = ID_8[rand() % 7] ^ 502;

		//------ ID.8: (9     , 7     , 4     , 1	    , 2 )		****** phai bang myPW[8] ****** CHU Y
		int ID_9[5]  = {57^102, 55^102, 52^102, 49^102, 50^102};
		myID[8] = ID_9[rand() % 5] ^ 102;

		//------ ID.10: ( D   , q     , 9    , 6	   , H    , u     , 0    , 2    , f     ,  V)
		int ID_10[10] = {68^47, 113^47, 57^47, 54^47, 72^47, 117^47, 48^47, 50^47, 102^47, 118^47};
		myID[9] = ID_10[rand() % 10] ^ 47;
		
		//------ ID.10:( 1    , z    , T    , 5	   , B    , m     , 8    , 4    , G )
		int ID_11[9] = {49^88, 122^88, 84^88, 53^88, 66^88, 109^88, 56^88, 52^88, 71^88};
		myID[10] = ID_11[rand() % 9] ^ 88;

		//======= END.ID ====================================================================
		

		//====== PW ====================================================================:
		//------ PW.1: (4    , p     , N    , h     , 5    , X    , c    , A    , g     , 7    , k )
		int PW_1[11] = {52^96, 112^96, 78^96, 104^96, 53^96, 88^96, 99^96, 65^96, 103^96, 55^96, 107^96};
		myPW[0] = PW_1[rand() % 11] ^ 96;

		//------ PW.2: (0    , C    , 2    , 3    , h    , U    , n     , G    , 8 )
		int PW_2[9] = {48<<3, 67<<3, 50<<3, 51<<3, 104<<3, 85<<3, 110<<3, 71<<3, 56<<3};
		myPW[1] = PW_2[rand() % 9] >> 3;

		//------ PW.3: (t    , 4    , M    , e     , 7    , r     , S  )
		int PW_3[7] = {116^66, 52^66, 77^66, 101^66, 55^66, 114^66, 83^66};
		myPW[2] = PW_3[rand() % 7] ^ 66;

		//------ PW.4: (1   , H    , a    , i     , 9 )
		int PW_4[5] = {49^32, 72^32, 97^32, 105^32, 57^32};
		myPW[3] = PW_4[rand() % 5] ^ 32;

		//------ PW.5: (2   , 5    , C )
		int PW_5[3] = {50^84, 53^84, 67^84};
		myPW[4] = PW_5[rand() % 3] ^ 84;

		//------ PW.6: (J   , 8    , 7    , z )
		int PW_6[4] = {74^21, 56^21, 55^21, 122^21};
		myPW[5] = PW_6[rand() % 4] ^ 21;

		//------ PW.7: (v    , W    , 0     , 6    , k)
		int PW_7[5] = {118^68, 87^68, 111^68, 54^68, 107^68};
		myPW[6] = PW_7[rand() % 5] ^ 68;

		//------ PW.8: (i    , a    , u     , 4 )
		int PW_8[4] = {105^99, 97^99, 117^99, 52^99};
		myPW[7] = PW_8[rand() % 4] ^ 99;

		//------ PW.9: (9     , 7     , 4     , 1	    , 2 )		****** phai bang  myID[8] ****** CHU Y
		myPW[8] = myID[8] ;

		//------ PW.10: (t     , R     , A     , N     , q      , Y)
		int PW_10[6] = {116^609, 82^609, 65^609, 78^609, 113^609, 89^609};
		myPW[9] = PW_10[rand() % 6] ^ 609;

		//------ PW.11: (1     , 3     , 5     , 2     , 6     , H     , N  )
		int PW_11[7] = {49^906, 51^906, 53^906, 50^906, 54^906, 72^906, 78^906};
		myPW[10] = PW_11[rand() % 7] ^ 906;
		
		//====== END.PW ====================================================================
		
		__oMsg("%s    %s", myID, myPW);
		
		CHECK_ID_PW(myID, myPW);
	}

	//CHECK_ID_PW("22345678915", "52345612345");


	extern HANDLE vai_logFile;	
	extern bool   chi1lan;
	if (vai_logFile)
	{
		CloseHandle(vai_logFile);
		vai_logFile = 0;
		chi1lan		= false;
	}
}


//-------------------------------------------------------------------------------------------------------------------
#include "Logger.h"
int _tmain(int argc, _TCHAR* argv[])
{
	
	GEN_ID_PW(5000);
	MessageBoxA(NULL, "DONE 5000 ACCOUNTS", "DONE", MB_OK);
	return 0;

	////////////-----------------------------------------
	//////////// Declare and initialize variables
	//////////WSADATA wsaData;
	//////////int iResult;

	//////////DWORD dwRetval;

	//////////int i = 1;

	//////////struct addrinfo *result = NULL;
	//////////struct addrinfo *ptr = NULL;
	//////////struct addrinfo hints;


	////////////// Validate the parameters
	////////////if (argc != 2) {
	////////////	__oMsg_22("usage: %s <IP Address String>\n", argv[0]);
	////////////	__oMsg_22("  getaddrinfo determines the IP binary network address\n");
	////////////	__oMsg_22("       %s 207.46.197.32\n", argv[0]);  /* www.contoso.com */
	////////////	return 1;
	////////////}

	//////////// Initialize Winsock
	//////////iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	//////////if (iResult != 0) {
	//////////	__oMsg_22("WSAStartup failed: %d\n", iResult);
	//////////	getchar();
	//////////	return 1;
	//////////}

	////////////--------------------------------
	//////////// Setup the hints address info structure
	//////////// which is passed to the getaddrinfo() function
	//////////ZeroMemory( &hints, sizeof(hints) );
	//////////hints.ai_flags = AI_NUMERICHOST;
	//////////hints.ai_family = AF_UNSPEC;
	////////////    hints.ai_socktype = SOCK_STREAM;
	////////////    hints.ai_protocol = IPPROTO_TCP;


	////////////--------------------------------
	//////////// Call getaddrinfo(). If the call succeeds,
	//////////// the result variable will hold a linked list
	//////////// of addrinfo structures containing response
	//////////// information
	//////////dwRetval = getaddrinfo("125.212.223.34", NULL, &hints, &result);
	//////////if ( dwRetval != 0 ) {
	//////////	__oMsg_22("getaddrinfo failed with error: %d\n", dwRetval);
	//////////	getchar();
	//////////	WSACleanup();
	//////////	return 1;
	//////////}

	//////////__oMsg_22("getaddrinfo returned success\n");

	//////////// Retrieve each address and print out the hex bytes
	//////////for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

	//////////	__oMsg_22("getaddrinfo response %d\n", i++);
	//////////	__oMsg_22("\tFlags: 0x%x\n", ptr->ai_flags);
	//////////	__oMsg_22("\tFamily: ");
	//////////	switch (ptr->ai_family) {
	//////////		case AF_UNSPEC:
	//////////			__oMsg_22("Unspecified\n");
	//////////			break;
	//////////		case AF_INET:
	//////////			__oMsg_22("AF_INET (IPv4)\n");
	//////////			break;
	//////////		case AF_INET6:
	//////////			__oMsg_22("AF_INET6 (IPv6)\n");
	//////////			break;
	//////////		case AF_NETBIOS:
	//////////			__oMsg_22("AF_NETBIOS (NetBIOS)\n");
	//////////			break;
	//////////		default:
	//////////			__oMsg_22("Other %ld\n", ptr->ai_family);
	//////////			break;
	//////////	}
	//////////	__oMsg_22("\tSocket type: ");
	//////////	switch (ptr->ai_socktype) {
	//////////		case 0:
	//////////			__oMsg_22("Unspecified\n");
	//////////			break;
	//////////		case SOCK_STREAM:
	//////////			__oMsg_22("SOCK_STREAM (stream)\n");
	//////////			break;
	//////////		case SOCK_DGRAM:
	//////////			__oMsg_22("SOCK_DGRAM (datagram) \n");
	//////////			break;
	//////////		case SOCK_RAW:
	//////////			__oMsg_22("SOCK_RAW (raw) \n");
	//////////			break;
	//////////		case SOCK_RDM:
	//////////			__oMsg_22("SOCK_RDM (reliable message datagram)\n");
	//////////			break;
	//////////		case SOCK_SEQPACKET:
	//////////			__oMsg_22("SOCK_SEQPACKET (pseudo-stream packet)\n");
	//////////			break;
	//////////		default:
	//////////			__oMsg_22("Other %ld\n", ptr->ai_socktype);
	//////////			break;
	//////////	}
	//////////	__oMsg_22("\tProtocol: ");
	//////////	switch (ptr->ai_protocol) {
	//////////		case 0:
	//////////			__oMsg_22("Unspecified\n");
	//////////			break;
	//////////		case IPPROTO_TCP:
	//////////			__oMsg_22("IPPROTO_TCP (TCP)\n");
	//////////			break;
	//////////		case IPPROTO_UDP:
	//////////			__oMsg_22("IPPROTO_UDP (UDP) \n");
	//////////			break;
	//////////		default:
	//////////			__oMsg_22("Other %ld\n", ptr->ai_protocol);
	//////////			break;
	//////////	}
	//////////	__oMsg_22("\tLength of this sockaddr: %d\n", ptr->ai_addrlen);
	//////////	__oMsg_22("\tCanonical name: %s\n", ptr->ai_canonname);
	//////////}

	//////////freeaddrinfo(result);
	//////////WSACleanup();

	//////////getchar();
	//////////return 0;		
	

//	//char* gky = "55D38577093A88F3B5EA40BBF11158813A2C662EB71FBAB9";
//	string TESTs = "6A 01 6A 01 8D 44 24 0C 50";
//	__oMsg("TESTs-1 :%s", TESTs.c_str()); 
//	for (int i = 0; i < (int)TESTs.length(); i++)
//	{
//		if (TESTs.at(i) == 32)
//		{
//			__oMsg("i: %d ->%d", i, TESTs.at(i));
//			TESTs.erase (TESTs.begin() + i);
//		}
//	}
//	
//	__oMsg("TESTs-2 :%s", TESTs.c_str()); 
//
//	int len = strlen(TESTs.c_str())/2;
//	BYTE* GKY = new BYTE[len];
//	StringToHex(TESTs.c_str(), GKY);
//	
//	for (int i = 0; i < len; i++)
//	{
//		__oMsg("i = %d - GKY: %x", i, GKY[i]);
//	}
//
//	//LogArray("GKY", GKY, len);
//	//delete[] GKY;
//	
//
//
//
//	__oMsg("foundx123");
//	BYTE  Pattern[] = {0x6A, 0x01, 0x6A, 0x01, 0x8D, 0x44, 0x24, 0x0C};
//
//
//
//return 0;


	//Logger _logger(L"Laucher_Test");

	//_logger.startLog();

	////_logger.LogString("testString.1 : ", "ABC_XYZ_1");
	////_logger.LogString("testString.2 : ", "ABC_XYZ_2");
	////_logger.LogInt("testInt : ", 12334);
	//_logger.LogInt("testInt22 : ", 9999);
	//_logger.LogInt("testInt22 : ", 1234);

	//_logger.stopLog();



	VMProtectBegin("Launcer_VM__tmain");
	//::ShellExecute(NULL,NULL,L"https://www.google.com",NULL,NULL,SW_SHOWNORMAL);
	
	g_hWinAPP = ::FindWindow(_T("Qt5QWindowToolSaveBits"), NULL); // Garena - Trò choi

	//g_hWinAPP = ::FindWindow( _T("Qt5QWindowIcon"), _T("Garena") ); // Garena - Trò choi
	if (g_hWinAPP)
	{
		DWORD dwProcessID;
		GetWindowThreadProcessId(g_hWinAPP, &dwProcessID);
		SetDebugPrivileges();
		
		__oMsg("found-Window");
		
		glo23523vsasfsabal(g_hWinAPP);
	}

	nCallBack_Laucher += 1;
	if (argc == 0){
		//MessageBoxA(NULL, "Injection failed !!!", "Failed", MB_OK);
		resume();
		return 0;
	}
	if (!g_hWinAPP)
	{
		//MessageBoxA(NULL, "Injection failed !!!", "Failed", MB_OK);
		resume();
		//MsgBox( (sz__Khong_tim_thay_cua_so_game__ban_phai_chay_game_truoc_da_));
		return 0;
	}
	//::PostMessage(g_hWinAPP, WM_HOOK_WRITE, ID_EXIT_APP, 0);
	//SettingParams();
	resume();
	VMProtectEnd();
	return 0;
}
