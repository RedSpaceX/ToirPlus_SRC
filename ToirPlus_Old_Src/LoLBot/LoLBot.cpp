
// LoLBot.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "LoLBot.h"
#include "LoLBotDlg.h"
//#include "..\\InjectBot\\IniManager.h"
#include "IniManager.h"
#include "Commons.h"
#include "DataText.h"
//#include "VMProtectSDK.h"
#include <winhttp.h>
#pragma comment (lib,"Winhttp.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLoLBotApp

BEGIN_MESSAGE_MAP(CLoLBotApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CLoLBotApp construction

CLoLBotApp::CLoLBotApp()
{
	// support Restart Manager
	//	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CLoLBotApp object

CLoLBotApp theApp;
bool g_bCheckConnectApp = false;
char g_szSessionID[126] = "";

// CLoLBotApp initialization

BOOL CLoLBotApp::InitInstance()
{
	CWinApp::InitInstance();

	char* szResult = NULL;
	CIniManager::GetInstance()->ReadIniFile();
	if (IsWin7OrLater())
	{
		g_bCheckConnectApp = CIniManager::GetInstance()->GetChooseLine2() ? false : TestConnect();
		//__oMsg("#xp  chon line2 ini:%d; g_bCheckConnectApp=%d", CIniManager::GetInstance()->GetChooseLine2(), g_bCheckConnectApp);
		szResult = GetCurrentVersion();
	} 
	else
	{
		g_bCheckConnectApp = CIniManager::GetInstance()->GetChooseLine2() ? false : TestConnect4WinXP();
		//__oMsg("xp  chon line2 ini:%d; g_bCheckConnectApp=%d", CIniManager::GetInstance()->GetChooseLine2(), g_bCheckConnectApp);
		szResult = GetCurrentVersion4WinXP();
	}
	DnsFlushResolverCache();
	//__oMsg("%s", szResult);
	if (szResult == NULL)
	{
		//MessageBox(NULL, C2W( (sz__Loi_kiem_tra_phien_ban__ko_lay_duoc_ket_qua_tra_ve_tu_server)), C2W( (sz__Loi)), MB_OK);
		MessageBox(NULL, C2W( "Error version. Response from server is invalid"), C2W(sz__Error), MB_OK);
		return FALSE;
	}
	std::string str2Process(szResult);
	if (str2Process.find( (sz__404_Not_Found)) != std::string::npos)
	{
		//MessageBox(NULL, C2W( (sz__Kiem_tra_phien_ban__Loi_404_Not_Found)), NULL, MB_OK);
		MessageBox(NULL, C2W("Error: 404 Not found"), NULL, MB_OK);
		return FALSE;
	}
	if (str2Process.find( (sz__true)) != std::string::npos || str2Process.find( (sz__True)) != std::string::npos)
	{
		//int idRt = MessageBox(NULL, C2W( (sz__Phien_ban_ban_dang_dung_da_cu__click_OK_de_cap_nhat_phien_ban_moi_nhat)), NULL, MB_OKCANCEL);
		int idRt = MessageBox(NULL, C2W("Old version. Please update"), NULL, MB_OKCANCEL);
		if (idRt == IDOK)
		{
			//::ShellExecute(NULL,NULL,C2W( (sz__https___autolols_com_)),NULL,NULL,SW_SHOWNORMAL); link_homepage_2
		}
		return FALSE;
	}
	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LPCWSTR STR_VIEWUTILITYMUTEX = L"-";
	m_Mutex_h=::CreateMutex(NULL, FALSE, STR_VIEWUTILITYMUTEX);
	if ((m_Mutex_h!=NULL)&&(GetLastError()!=ERROR_ALREADY_EXISTS))
	{
		// Just get default class for the dialogs
		WNDCLASS wndcls;
		::GetClassInfo(AfxGetInstanceHandle(), L"#32770", &wndcls);

		// Set our own class name
		wndcls.lpszClassName = _T("#32770");

		// Just register the class
		//if (!::RegisterClass(&wndcls))
		if (!AfxRegisterClass(&wndcls))
		{
			_ASSERTE(! __FUNCTION__ " Failed to register window class");
			return FALSE;
		}

		// App is NOT running twice
		CLoLBotDlg dlg;
		m_pMainWnd = &dlg;
		INT_PTR nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with OK
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with Cancel
		}
	}
	else
	{
		// App is running twice send message to running app, the app will now know a 2nd instance was started
		//::MessageBox(NULL, C2W( (sz__Chuong_trinh_da_duoc_chay_roi___)), NULL, MB_OK);
		HWND existingApp = FindWindow(_T("#32770"), NULL);
		if (existingApp)
		{
			if (!IsWindowVisible(existingApp))
				ShowWindow(existingApp,SW_SHOW); 
			SetForegroundWindow(existingApp);
		}
		//return FALSE; // Exit the app. For MFC, return false from InitInstance.
	}

	// Delete the shell manager created above.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
