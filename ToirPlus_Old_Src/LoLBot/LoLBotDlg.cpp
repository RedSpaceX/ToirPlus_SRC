#include "stdafx.h"
#include "LoLBot.h"		// main symbols
#include "LoLBotDlg.h"
#include "DataText.h"
#include "Commons.h"
#include "HideProcess\Bridge.h"
//#include "..\\InjectBot\\InjectBot.h"
//#include "..\\InjectBot\\AntiBan.h"
#include "IniManager.h"
#include "AntiDebugApp.h"
//#include "VMProtectSDK.h"
#include "winhttp.h"
#include "AntiGarena.h"
#pragma comment (lib,"Winhttp.lib")

HINSTANCE			hDll = NULL;

TCHAR g_strPath2DLL_Game[MAX_PATH];

#define TEMP_FILE_NAME L"~DF93F76506ABFD2A67.TMP"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define TAB_ONE m_MyTabCtrl.m_tabPages[0]
#define TAB_TWO m_MyTabCtrl.m_tabPages[1]
#define TAB_THREE m_MyTabCtrl.m_tabPages[2]
#define TAB_FOUR m_MyTabCtrl.m_tabPages[3]
#define TAB_FIVE m_MyTabCtrl.m_tabPages[4]

HWND g_hWinAPP;
UINT CheckVersionThread(void*);

// CLoLBotDlg dialog




CLoLBotDlg::CLoLBotDlg(CWnd* pParent /*=NULL*/)
: CTrayDialog(CLoLBotDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hProcess = 0;
	m_isLogined = 0;
}

void CLoLBotDlg::DoDataExchange(CDataExchange* pDX)
{
	CTrayDialog::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_EDIT_USERNAME, m_strUsername);
	DDX_CBString(pDX, IDC_EDIT_PASSWORD, m_strPassword);
	DDX_Control(pDX, IDC_BTN_LOGIN, m_btnLogin);
	DDX_Control(pDX, IDC_BTN_DK, m_btnDangKy);
	DDX_Control(pDX, LOLBOT_MY_TAB_CTRL, m_MyTabCtrl);
}

BEGIN_MESSAGE_MAP(CLoLBotDlg, CTrayDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	//ON_WM_CLOSE(&CLoLBotDlg::OnClose)
	ON_COMMAND(ID_TRAYMENU_SHOW, CLoLBotDlg::OnTrayMenuOPEN)
	ON_COMMAND(ID_TRAYMENU_EXIT, CLoLBotDlg::OnClose)
	ON_BN_CLICKED(IDC_BUTTON_HOOk, &CLoLBotDlg::OnBnClickedButtonHook)
	ON_BN_CLICKED(IDC_BTN_LOGIN, &CLoLBotDlg::OnBnClickedBtnLogin)
	ON_BN_CLICKED(IDC_BTN_DK, &CLoLBotDlg::OnBnClickedBtnDangKy)
	ON_STN_CLICKED(IDC_STATIC_HOME, &CLoLBotDlg::OnStnClickedStaticHome)
	ON_STN_CLICKED(IDC_STATIC_SUPPORT, &CLoLBotDlg::OnStnClickedStaticSupport)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


void write_temp_file(char* buffer)
{
	DWORD dwRetVal = 0;

	TCHAR lpTempPathBuffer[MAX_PATH] = L"";
	TCHAR szTempFileName[MAX_PATH] = L"";  

	HANDLE hTempFile = INVALID_HANDLE_VALUE; 

	BOOL fSuccess  = FALSE;

	DWORD dwBytesWritten = 0;

	dwRetVal = GetTempPathW(MAX_PATH,          // length of the buffer
		lpTempPathBuffer); // buffer for path 

	//__oMsg("lpTempPathBuffer: %s",lpTempPathBuffer);

	wcscat_s(szTempFileName,lpTempPathBuffer);
	wcscat_s(szTempFileName,TEMP_FILE_NAME);

	//__oMsg("szTempFileName: %s",szTempFileName);

	hTempFile = CreateFile((LPTSTR) szTempFileName, // file name 
		GENERIC_WRITE,        // open for write 
		0,                    // do not share 
		NULL,                 // default security 
		CREATE_ALWAYS,        // overwrite existing
		FILE_ATTRIBUTE_NORMAL,// normal file 
		NULL);                // no template

	fSuccess = WriteFile(hTempFile, 
		buffer, 
		strlen(buffer),
		&dwBytesWritten, 
		NULL); 

	//__oMsg("fSuccess: %d",fSuccess);

	CloseHandle(hTempFile);
}




// CLoLBotDlg message handlers

BOOL CLoLBotDlg::OnInitDialog()
{
	CTrayDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	//CFont font;
	//font.CreateFont(10, 0, 0, 0, FW_BOLD,0 , 1, 0, 0, 0, 0, 0, 0, _T("Times New Roman"));
	//this->GetDlgItem(IDC_STATIC_HOME)->SetFont( &font );
	//this->GetDlgItem(IDC_STATIC_SUPPORT)->SetFont( &font );
	CWnd * pWndHome = GetDlgItem(IDC_STATIC_HOME);
	CFont * pfont = pWndHome->GetFont();
	LOGFONT lf; pfont->GetLogFont(&lf);
	//lf.lfItalic = TRUE;         //To Make Text Italic
	lf.lfWeight = FW_BOLD;          //To Make BOLD, Use FW_SEMIBOLD,FW_BOLD,FW_EXTRABOLD,FW_BLACK
	lf.lfUnderline = TRUE;      //Underline Text
	pfont->CreateFontIndirect(&lf);
	pWndHome->SetFont(pfont);
	CWnd * pWndSupport = GetDlgItem(IDC_STATIC_SUPPORT);
	pWndSupport->SetFont(pfont);

	/////m_btnLogin.SetBitmap(LoadBitmap(AfxGetResourceHandle(),MAKEINTRESOURCE(IDB_BITMAP1)));

	SetWindowText(GetTitle());
	SetLastFileTimeModified2LabelBUILD();
	TraySetIcon(IDR_MAINFRAME);
	//TraySetToolTip(C2W( (sz__Auto_Lien_Minh_Huyen_Thoai)));
	TraySetMenu(IDR_MENU_TRAY);

	m_MyTabCtrl.InsertItem(0, _T("Initialization"));
	m_MyTabCtrl.InsertItem(1, _T("Drawing"));
	m_MyTabCtrl.InsertItem(2, _T("Activator"));
	//m_MyTabCtrl.InsertItem(3, _T("Tab Four"));
	//m_MyTabCtrl.InsertItem(4, _T("Tab Five"));
	m_MyTabCtrl.Init();

	UpdateControls(false);
	UpdateData(FALSE);
	SetDlgItemText(IDC_EDIT_USERNAME, m_strUsername.GetString());
	SetDlgItemText(IDC_EDIT_PASSWORD, m_strPassword.GetString());

	TAB_ONE->SetDlgItemText(BOT_EDIT_COMBO_KEY, m_strCombo_Key.GetString());
	TAB_ONE->SetDlgItemText(BOT_EDIT_LANECLEAR_KEY, m_strLaneClear_Key.GetString());
	TAB_ONE->SetDlgItemText(BOT_EDIT_HARASS_KEY, m_strHarass_Key.GetString());
	TAB_ONE->SetDlgItemText(BOT_EDIT_LASTHIT_KEY, m_strLastHit_Key.GetString());

	//TAB_ONE->GetDlgItem(LOLBOT_HACKZOOM)->EnableWindow(FALSE);
	//TAB_ONE->GetDlgItem(LOLBOT_MODSKIN)->EnableWindow(FALSE);
	TAB_ONE->GetDlgItem(BOT_EDIT_MP_CLEARLANE)->EnableWindow(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEAR_LANE))->GetCheck());
	TAB_ONE->GetDlgItem(BOT_EDIT_MP_HARASS)->EnableWindow(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS))->GetCheck());
	TAB_THREE->GetDlgItem(BOT_EDIT_HM_SKILL)->EnableWindow(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_HOIMAU_SKILL))->GetCheck());
	TAB_THREE->GetDlgItem(BOT_EDIT_HM_ITEM)->EnableWindow(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_HOIMAU_ITEM))->GetCheck());
	TAB_THREE->GetDlgItem(BOT_EDIT_LA_CHAN)->EnableWindow(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_LA_CHAN))->GetCheck());
	TAB_THREE->GetDlgItem(BOT_EDIT_IRON_SOLARI)->EnableWindow(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_IRON_SOLARI))->GetCheck());
	TAB_THREE->GetDlgItem(BOT_EDIT_SON_THACH)->EnableWindow(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_SON_THACH))->GetCheck());
	TAB_THREE->GetDlgItem(BOT_EDIT_DONG_HO_CAT)->EnableWindow(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_DONG_HO_CAT))->GetCheck());
	TAB_THREE->GetDlgItem(BOT_EDIT_QT_DTS)->EnableWindow(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_QUYEN_TRUONG_DTS))->GetCheck());
	TAB_THREE->GetDlgItem(BOT_EDIT_CHUOC_TOI)->EnableWindow(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_CHUOC_TOI))->GetCheck());
	TAB_ONE->GetDlgItem(LOLBOT_ATK_CURRENT_SELECTED)->EnableWindow(TRUE);
	TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_Q)->EnableWindow(TRUE);
	TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_W)->EnableWindow(TRUE);
	TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_E)->EnableWindow(TRUE);
	TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_R)->EnableWindow(TRUE);
	TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_Q)->EnableWindow(TRUE);
	TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_W)->EnableWindow(TRUE);
	TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_E)->EnableWindow(TRUE);
	TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_R)->EnableWindow(TRUE);
	TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_Q)->EnableWindow(TRUE);
	TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_W)->EnableWindow(TRUE);
	TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_E)->EnableWindow(TRUE);
	TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_R)->EnableWindow(TRUE);
	TAB_ONE->GetDlgItem(BOT_EDIT_DELAY_SKILL)->EnableWindow(FALSE);
	TAB_ONE->GetDlgItem(BOT_EDIT_COMBO_KEY)->EnableWindow(TRUE);
	m_btnLogin.EnableWindow(TRUE);
	CWnd* pWndStatus = GetDlgItem(IDC_STATUS_LOGIN);
	CWnd* pWndStatus2 = GetDlgItem(IDC_STATUS_LOGIN2);
	if(pWndStatus)
	{
		pWndStatus->ShowWindow(SW_SHOW);
	}
	if(pWndStatus2)
	{
		pWndStatus2->ShowWindow(SW_HIDE);
	}
	TAB_ONE->GetDlgItem(IDC_BUTTON_HOOk)->EnableWindow(FALSE);
	TAB_ONE->GetDlgItem(IDC_BUTTON_HOOk)->ShowWindow(SW_HIDE);// COMMENT DONG NAY LAI DE HIEN THI NUT ["Bat Dau"] TREN APP
	TAB_ONE->GetDlgItem(IDC_BUTTON_TEST)->ShowWindow(SW_HIDE);// COMMENT DONG NAY LAI DE HIEN THI NUT ["nuttest"] TREN APP
	TAB_ONE->GetDlgItem(IDC_BUTTON_TEST)->EnableWindow(FALSE);
	SetTimer(ID_CHECK_LOGIN, 43200000, 0); // 43200000 ms = 12 hours
	SetTimer(ID_CHECK_DEBUGGER, 1000, 0); // 1000 ms = 1 second
	//DriverHideProcess();


	GetModuleFileName(hDll, g_strPath2DLL_Game, MAX_PATH);

	
	//__oMsg("(DllMain)[%x], g_strPath2DLL_Game: %s", hDll, W2C(g_strPath2DLL_Game));
	if (_tcslen(g_strPath2DLL_Game) > 0){

		//__oMsg("g_strPath2DLL_Game(>0) %s",g_strPath2DLL_Game);

		TCHAR sz__fdC_Y_yum3ww09[] = { 102, 100, 67, 41, 89, 37, 121, 117, 109, 51, 119, 119, 48, 57, 0 };
		TCHAR* Data = g_strPath2DLL_Game;
		TCHAR* Key = sz__fdC_Y_yum3ww09;
		//__oMsg("len1: %d [%s]", _tcslen(Data), W2C(Data));
		Crypt(Data, _tcslen(Data), Key, _tcslen(Key));
		//__oMsg("len2: %d [%s]", _tcslen(Data), W2C(Data));
		write_temp_file(W2C(Data));
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLoLBotDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CTrayDialog::OnPaint();
	}
}

BOOL CLoLBotDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN &&
		pMsg->wParam == VK_RETURN)
	{
		// handle return pressed in edit control
		OnBnClickedBtnLogin();
		return TRUE; // this doesn't need processing anymore
	}
	CTrayDialog::PreTranslateMessage(pMsg);
	//return FALSE; // all other cases still need default processing
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLoLBotDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//====================================================:
#include <intrin.h>
int test = 1;
void CLoLBotDlg::OnTimer(UINT_PTR nIDEvent)
{
	/*if (_ReturnAddress())
	{
		__oMsg("R11113331");
	}
	__oMsg("Return address from %s: %p\n", __FUNCTION__, _ReturnAddress());*/

	unsigned char buf[] = {0, 1, 10, 11};
	/* target buffer should be large enough */
	char str[12];

	unsigned char * pin = buf;
	const char * hex = "0123456789ABCDEF";
	char * pout = str;
	int i = 0;
	for(; i < sizeof(buf)-1; ++i){
		*pout++ = hex[(*pin>>4)&0xF];
		*pout++ = hex[(*pin++)&0xF];
		*pout++ = ':';
	}
	*pout++ = hex[(*pin>>4)&0xF];
	*pout++ = hex[(*pin)&0xF];
	*pout = 0;

	printf("%s\n", str);

	__oMsg("xxxx : %s", str);

	return;

	__oMsg("foundx123");
	BYTE  Pattern[] = {0x6A, 0x01, 0x6A, 0x01, 0x8D, 0x44, 0x24, 0x0C};
	char szBASE[] = "6A 01 6A 01 8D 44 24 0C 50";

	int a_t_i = atoi("88");
	__oMsg("a_t_i : %d - %x", a_t_i, a_t_i);

	if (test == 1)
	{
		//Pattern[] = {0x11, 0x22, 0x33};
		for (int i = 0; i < sizeof(Pattern); i++)
		{
			test = 4;
			Pattern[i] += i;
		}

		for (int i = 0; i < strlen(szBASE); i++)
		{
			test = 4;
			szBASE[i] += i;
		}
	}
	
	__oMsg("45678901234");
	//__oMsg("1_TEST_122---------AutoLoLs_VM__OnTimer-----------");
	if (nIDEvent == ID_CHECK_DEBUGGER)
	{
		static bool x = true;
		if ( x )
		{
			//__oMsg("vao hoook;%x", g_hWinAPP);
			OnBnClickedButtonHook();
			x = false;
		}
		if (m_isLogined)
		{
			//__oMsg("dong app");
			this->SendMessage(WM_CLOSE);
		}

		//CAntiDebugApp::GetInstance()->ANTI_DEBUG_TOOL();

		////ANTI_DEBUG_DRIVER
		//if (CAntiDebugApp::GetInstance()->DebuggerDriversPresent())
		//{
		//	CAntiDebugApp::GetInstance()->TERMINATE_ALL();
		//}

		//CAntiDebugApp::GetInstance()->ANTI_HARDWARE_BP();
		////ANTI_MEMORY_BP();
		//if(CAntiDebugApp::GetInstance()->MemoryBreakpointDebuggerCheck())
		//{
		//	CAntiDebugApp::GetInstance()->TERMINATE_ALL();
		//}
		////TRAP_RIP_EXCEPTION();
		//if(CAntiDebugApp::GetInstance()->IsDebuggerPresent_RipException_1() || CAntiDebugApp::GetInstance()->IsDebuggerPresent_RipException_2() || CAntiDebugApp::GetInstance()->IsDebuggerPresent_RipException_3())
		//{
		//	CAntiDebugApp::GetInstance()->TERMINATE_ALL();
		//}
		////ANTI_PEB();
		//PBOOLEAN BeingDebugged=(PBOOLEAN)__readfsdword(0x30)+2;
		//if(*BeingDebugged) // Read the PEB
		//{
		//	CAntiDebugApp::GetInstance()->TERMINATE_ALL();
		//}
		////ANTI_IS_DEBUGGER_PRESENT();
		//char  nIsDebugger = 0;
		//nIsDebugger = IsDebuggerPresent();
		//if (nIsDebugger)
		//{
		//	CAntiDebugApp::GetInstance()->TERMINATE_ALL();
		//}
		////ANTI_DEBUG_OBJECT_CHECK();
		//if(CAntiDebugApp::GetInstance()->DebugObjectCheck())
		//{
		//	CAntiDebugApp::GetInstance()->TERMINATE_ALL();
		//} 
		//////////////// TEMP /////////////////////
	}
	if (nIDEvent == ID_CHECK_LOGIN)
	{
		//VMProtectBegin("AutoLoLs_VM__OnTimer__CheckVersionThread");
		AfxBeginThread(CheckVersionThread, this);
		//VMProtectEnd();
	}
	if (nIDEvent == ID_CLOSE_MSGBOX)
	{
		//__oMsg("HAINT - DONG MSG BOX");
		//CWnd* w = AfxGetMainWnd()->GetFocus();
		//CWnd* w = FindWindow(NULL, L"Demacia");
		//w = w->GetParent();
		//if (w) // bo tinh nang tu dong close messagebox
		//w->SendMessage(WM_CLOSE);
	}

	CTrayDialog::OnTimer(nIDEvent);
}

//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//=================== tls callback ANTI DEBUG =======================================================================
#pragma comment(lib,"ntdll.lib")
#pragma comment(linker,"/include:__tls_used") // This will cause the linker to create the TLS directory
#pragma section(".CRT$XLB",read) // Create a new section
//extern "C"
//{
//	int NTAPI NtQueryInformationProcess(HANDLE hProcess,ULONG InfoClass,PVOID Buffer,ULONG Length,PULONG ReturnLength);
//}
int nCallBack_App = 0;
#define NtCurrentProcess() (HANDLE)-1
void WINAPI TlsCallback(PVOID Module,DWORD Reason,PVOID Context)// VM PROTECT ON
{
	return;

	if(nCallBack_App >= 2)
	{
		//__oMsg("1_--------222");
		resume();
		return;
	}

	if(nCallBack_App == 0)
	{
		//__oMsg("1_---------111");
		//g_hWinAPP = ::FindWindow(_T("UIHOST"), NULL); // Garena
		////__oMsg("[INFO] %s --- %d ---- %s:%x", __FUNCTION__, __LINE__, __FILE__, g_hWinAPP);
		//if (g_hWinAPP)
		//{
		//	//__oMsg("da lay duoc cua so garena");
		//	DWORD dwProcessID;
		//	GetWindowThreadProcessId(g_hWinAPP, &dwProcessID);
		//	if (InjectDll_Mgr(g_hWinAPP))
		//	{
		//		//__oMsg("Thanh cong:%d", dwProcessID);
		//	}
		//	else
		//	{
		//		//__oMsg("ko thanh cong!!");
		//	}
		//}
		
		pause();
		nCallBack_App += 1;
	}
	//__oMsg("1_TEST_1----------AutoLoLs_VM__TlsCallback----------");
	
	//CAntiDebugApp::GetInstance()->ANTI_OUTPUT_DEBUG_STRING("99");
	CAntiDebugApp::GetInstance()->ANTI_DEBUG_TOOL();
	CAntiDebugApp::GetInstance()->ANTI_HARDWARE_BP();
	//ANTI_MEMORY_BP();
	if(CAntiDebugApp::GetInstance()->MemoryBreakpointDebuggerCheck())
	{
		CAntiDebugApp::GetInstance()->TERMINATE_ALL();
	}
	//ANTI_DEBUG_DRIVER
	if (CAntiDebugApp::GetInstance()->DebuggerDriversPresent())
	{
		CAntiDebugApp::GetInstance()->TERMINATE_ALL();
	}
	//TRAP_RIP_EXCEPTION();
	if(CAntiDebugApp::GetInstance()->IsDebuggerPresent_RipException_1() || CAntiDebugApp::GetInstance()->IsDebuggerPresent_RipException_2() || CAntiDebugApp::GetInstance()->IsDebuggerPresent_RipException_3())
	{
		CAntiDebugApp::GetInstance()->TERMINATE_ALL();
	}
	//ANTI_PEB();
	PBOOLEAN BeingDebugged=(PBOOLEAN)__readfsdword(0x30)+2;
	if(*BeingDebugged) // Read the PEB
	{
		CAntiDebugApp::GetInstance()->TERMINATE_ALL();
	}
	//ANTI_IS_DEBUGGER_PRESENT();
	char  nIsDebugger = 0;
	nIsDebugger = IsDebuggerPresent();
	if (nIsDebugger)
	{
		CAntiDebugApp::GetInstance()->TERMINATE_ALL();
	}
	//ANTI_DEBUG_OBJECT_CHECK();
	if(CAntiDebugApp::GetInstance()->DebugObjectCheck())
	{
		CAntiDebugApp::GetInstance()->TERMINATE_ALL();
	} 
	//// Another check
	//HANDLE DebugPort=NULL;
	//if(!NtQueryInformationProcess(
	//	NtCurrentProcess(),
	//	7, // ProcessDebugPort
	//	&DebugPort, // If debugger is present, it will be set to -1 | Otherwise, it is set to NULL
	//	sizeof(HANDLE),
	//	NULL))
	//{
	//	if(DebugPort)
	//	{
	//		CAntiDebugApp::GetInstance()->TERMINATE_ALL();
	//	}
	//}

	//HMODULE hmod;
	//FARPROC _NtQueryInformationProcess;
	//hmod = LoadLibrary(L"ntdll.dll");
	//_NtQueryInformationProcess = GetProcAddress(hmod, "NtQueryInformationProcess");

	//HANDLE retVal;
	//NTSTATUS status = (_NtQueryInformationProcess) (-1, 0x07, &retVal, 4, NULL);

	//if (retVal != 0) {
	//	//Debugger Detected - Do Something Here
	//	CAntiDebugApp::GetInstance()->TERMINATE_ALL();
	//} else {
	//	//No Debugger Detected - Continue
	//}

	//check them cai nay
	/*_NtSetInformationThread = GetProcAddress(lib, "NtSetInformationThread");

	(_NtSetInformationThread) (GetCurrentThread(), 0x11, 0, 0);*/

	typedef NTSTATUS(NTAPI * pNtQueryInformationProcess)
		(
		HANDLE,
		ULONG,
		PVOID,
		ULONG,
		PULONG
		);
	HANDLE DebugPort=NULL;
	pNtQueryInformationProcess NtQIP = (pNtQueryInformationProcess)GetProcAddress(GetModuleHandle(C2W( (sz__ntdll_dll))),  (sz__NtQueryInformationProcess));
	if(!NtQIP(
		NtCurrentProcess(),
		7, // ProcessDebugPort
		&DebugPort, // If debugger is present, it will be set to -1 | Otherwise, it is set to NULL
		sizeof(HANDLE),
		NULL))
	{
		if(DebugPort)
		{
			CAntiDebugApp::GetInstance()->TERMINATE_ALL();
		}
	}
}
// Put the TLS callback address into a null terminated array of the .CRT$XLB section
__declspec(allocate(".CRT$XLB")) PIMAGE_TLS_CALLBACK CallbackAddress[]={TlsCallback,NULL};
//=================== END tls callback ANTI DEBUG =======================================================================

UINT CheckVersionThread(void *pParam)
{
	CLoLBotDlg* pThis= (CLoLBotDlg*)pParam;

	static int nTime = 0;
	//__oMsg("goi on timer lan thu %d, thread ID %d", nTime++, GetCurrentThreadId());

	char* szResult = NULL;
	if (IsWin7OrLater())
	{
		szResult = GetCurrentVersion();
	} 
	else
	{
		szResult = GetCurrentVersion4WinXP();
	}
	DnsFlushResolverCache();
	//__oMsg("%s", szResult);
	if (szResult == NULL)
	{
		//pThis->MsgBox(sz__Loi_kiem_tra_phien_ban__ko_lay_duoc_ket_qua_tra_ve_tu_server);
		pThis->MsgBox("Error version. Response from server is invalid!");
		pThis->SendMessage(WM_CLOSE);
		return 0;
	}
	std::string str2Process(szResult);
	if (str2Process.find( (sz__404_Not_Found)) != std::string::npos)
	{
		//pThis->MsgBox(sz__Kiem_tra_phien_ban__Loi_404_Not_Found);
		pThis->MsgBox("Error: 404 Not found");
		pThis->SendMessage(WM_CLOSE);
		return 0;
	}
	//if (str2Process.compare(" (sz__gameversion_6_15_build_04_08_2016)") != 0)
	if (str2Process.find( (sz__true)) != std::string::npos || str2Process.find( (sz__True)) != std::string::npos)
	{
		//int idRt = pThis->MsgBox(sz__Phien_ban_ban_dang_dung_da_cu__click_OK_de_cap_nhat_phien_ban_moi_nhat, 0, MB_OKCANCEL);
		int idRt = pThis->MsgBox("Old version. Please update", 0, MB_OKCANCEL);
		//if (idRt == IDOK)
		//{
		//::ShellExecute(NULL,NULL,C2W( (sz__https___autolols_com_)),NULL,NULL,SW_SHOWNORMAL);
		//}
		pThis->SendMessage(WM_CLOSE);
		return 0;
	}
	return 1;
}

//================================================================================================================================
void CLoLBotDlg::OnBnClickedButtonHook()
{
	//::ShellExecute(NULL,NULL,L"https://www.google.com",NULL,NULL,SW_SHOWNORMAL);
}

//================================================================================================================================
void CLoLBotDlg::OnClose()
{
	nCallBack_App += 1;
	//__oMsg("In un hook\n");
	UpdateControls(true);
	//::PostMessage(g_hWinAPP, WM_HOOK_WRITE, ID_EXIT_APP, 1);
	//UnmapDll_Mgr(g_hWinAPP);
	CTrayDialog::OnClose();
	CTrayDialog::OnCancel();
	if (IsWin7OrLater())
	{
		GetRequestResult(W2C(m_strUsername.GetString()), W2C(m_strPassword.GetString()));
	}
	else
	{
		GetRequestResult4WinXP(W2C(m_strUsername.GetString()), W2C(m_strPassword.GetString()));
	}
	DnsFlushResolverCache();
	//::ShellExecute(NULL,NULL,C2W( (sz__https___autolols_com_)),NULL,NULL,SW_SHOWNORMAL);

	//char strPathLog[] = "C:\\Windows\\x64.log";
	//ifstream userInfoFile (strPathLog, ios::binary);
	////__oMsg("path log tool file: %s", strPathLog);
	//int pIDToolHide = 0;
	//if (userInfoFile.is_open())
	//{
	//	userInfoFile >> pIDToolHide;
	//	userInfoFile.close();
	//}
	//char szCmdLine[256] = {0};
	//sprintf(szCmdLine, "taskkill /f /pid %d>nul", pIDToolHide);
	////__oMsg("kill:%s", szCmdLine);
	//system(szCmdLine);
	//system("del /f /q C:\\Windows\\x64.log>nul");
	//system("del /f /q C:\\Windows\\x64Hider.exe>nul");
	//system("del /f /q C:\\Windows\\x64.exe>nul");

}

//================================================================================================================================
void CLoLBotDlg::OnTrayMenuOPEN() 
{
	CPoint pt;
	GetCursorPos(&pt);
	ClientToScreen(&pt);
	OnTrayLButtonDblClk(pt);
}

void CLoLBotDlg::OnBnClickedBtnLogin()
{
	//__oMsg("----------------\nvua click nut Dang Nhap");
	UpdateData(TRUE);
	UpdateControls(true);
	if (m_strUsername.IsEmpty())
	{
		MsgBox("ID Empty!");
		return;
	}
	if (m_strPassword.IsEmpty())
	{
		MsgBox("Password Empty!");
		return;
	}
	m_isLogined = 0;
	m_btnLogin.EnableWindow(FALSE);
	char* szResult = NULL;
	if (IsWin7OrLater())
	{
		szResult = GetRequestResult(W2C(m_strUsername.GetString()), W2C(m_strPassword.GetString()));
	} 
	else
	{
		szResult = GetRequestResult4WinXP(W2C(m_strUsername.GetString()), W2C(m_strPassword.GetString()));
	}
	//__oMsg("----------------szResult: %x", szResult);
	DnsFlushResolverCache();
	if (szResult == NULL)
	{
		//MsgBox( (sz__Loi_dang_nhap__ko_lay_duoc_ket_qua_tra_ve_tu_server));
		MsgBox("Error Login. Response from server is invalid!");
		m_btnLogin.EnableWindow(TRUE);
		return;
	}
	vector<string> result2Process = split(szResult, '&');
	char* ssid = GetValueFromVectorString(result2Process, SR_SESSION_ID);
	char *tsv = GetValueFromVectorString(result2Process, SR_TIME_SERVER);
	char *ec = GetValueFromVectorString(result2Process, SR_ERROR_CODE);
	result2Process.clear();
	//char  buff[60];
	//sprintf(buff, "haint :\n%s;\n%s;\n%s", szResult, ssid, tsv);
	//MsgBox(buff);
	if (ec)//tam thoi them cai nay vi tren server chua tra ve truong nay
		switch (atoi(ec))
	{
		case EC_SUCCESSFUL:
			break;
		case EC_INVALID_USERNAME:
			MsgBox("Wrong ID!");
			m_btnLogin.EnableWindow(TRUE);
			return;
		case EC_WRONG_PASSWORD:
			MsgBox("Wrong Password!");
			m_btnLogin.EnableWindow(TRUE);
			return;
		case EC_LOGIN_OTHER_PLACE:
			
			//MsgBox( (sz__Tai_khoan_cua_ban_da_bi_dang_nhap_o_1_noi_khac));
			MsgBox("Your account is logged elsewhere!");
			m_btnLogin.EnableWindow(TRUE);
			return;
		case EC_EXPIRED_ACCOUNT:
			//int id = MsgBox( (sz__Tai_khoan_da_het_han_su_dung__nap_them_de_tiep_tuc_su_dung));
			int id = MsgBox("Expired account");
			if (id == MB_OK)
			{
				//::ShellExecute(NULL,NULL,L"https://autolols.com/id/",NULL,NULL,SW_SHOWNORMAL);
			}
			m_btnLogin.EnableWindow(TRUE);
			return;
	}
	if (ssid)
		strcpy_s(g_szSessionID, ssid); // lay session id
	else
	{
		//MsgBox( (sz__Tai_khoan_cua_ban_da_bi_dang_nhap_o_1_noi_khac));
		MsgBox("Your account is logged elsewhere!");
		m_btnLogin.EnableWindow(TRUE);
		return;// tk da bi dang nhap o noi khac
	}
	__int64 nTimeServerResult = atoi(tsv); // lay time tu server
	__int64 nTimeServerRequest = time(NULL);
	if (IsWin7OrLater())
	{
		nTimeServerRequest = atoi(GetTimeServer());
	} 
	else
	{
		nTimeServerRequest = atoi(GetTimeServer4WinXP());
	}
	DnsFlushResolverCache();
	__int64 nTime2Check = nTimeServerRequest - nTimeServerResult;
	if (nTime2Check < 0) nTime2Check = -nTime2Check;
	if (nTime2Check >= 300)
	{
		//MsgBox( (sz__Loi_dang_nhap__gio_may_tinh_bi_sai__de_nghi_cap_nhat_lai_gio_may_tinh));
		MsgBox("Error computer timer");
		m_btnLogin.EnableWindow(TRUE);
		return;
	}
	m_btnLogin.EnableWindow(FALSE);
	TAB_ONE->GetDlgItem(IDC_BUTTON_HOOk)->EnableWindow(TRUE);
	CWnd* pWndStatus = GetDlgItem(IDC_STATUS_LOGIN);
	CWnd* pWndStatus2 = GetDlgItem(IDC_STATUS_LOGIN2);
	if(pWndStatus)
	{
		pWndStatus->ShowWindow(SW_HIDE);
	}
	if(pWndStatus2)
	{
		pWndStatus2->ShowWindow(SW_SHOW);
	}
	GetDlgItem(IDC_EDIT_USERNAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(FALSE);
	CUserInfo userInfo;
	userInfo.SetSessionID(g_szSessionID);
	userInfo.SetUser(W2C(m_strUsername.GetString()));
	userInfo.SetPass(W2C(m_strPassword.GetString()));
	userInfo.SetLogin(true);
	CFileUserInfoMgr::GetInstance()->AddUser(userInfo);
	CFileUserInfoMgr::GetInstance()->SaveInfo2File( (sz__config_info_dat));
	m_isLogined = 1;
}

void CLoLBotDlg::OnStnClickedStaticHome()
{
	//::ShellExecute(NULL,NULL,C2W( (sz__http___toirplus_com)),NULL,NULL,SW_SHOWNORMAL);//home-page
}

//================================================================================================================================
void CLoLBotDlg::OnStnClickedStaticSupport()
{
	//::ShellExecute(NULL,NULL,C2W( (sz__https___www_facebook_com_auto_lmht_fanpage)),NULL,NULL,SW_SHOWNORMAL);
	//::ShellExecute(NULL,NULL,L"https://autolols.com/id/",NULL,NULL,SW_SHOWNORMAL);
}

//================================================================================================================================
void CLoLBotDlg::OnBnClickedBtnDangKy()
{
	//::ShellExecute(NULL,NULL,C2W( (sz__http___toirplus_com)),NULL,NULL,SW_SHOWNORMAL);
}

//================================================================================================================================
void CLoLBotDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CTrayDialog::OnShowWindow(bShow, nStatus);
	if (bShow)
	{
		TrayHide();
	} 
	else
	{
		TrayShow();
	}
}

//================================================================================================================================
void CLoLBotDlg::UpdateControls(bool bSave)
{
	if (bSave) //save information to ini file
	{
		CIniManager::GetInstance()->SetUsername(W2C(m_strUsername.GetString()));
	

		//TAB_ONE->GetDlgItem(BOT_EDIT_COMBO_KEY)->GetWindowText(m_strCombo_Key);
		//CIniManager::GetInstance()->SetCombo_Key(W2C(m_strCombo_Key.GetString()));

		//TAB_ONE->GetDlgItem(BOT_EDIT_LANECLEAR_KEY)->GetWindowText(m_strLaneClear_Key);
		//CIniManager::GetInstance()->SetLaneClear_Key(W2C(m_strLaneClear_Key.GetString()));

		//TAB_ONE->GetDlgItem(BOT_EDIT_HARASS_KEY)->GetWindowText(m_strHarass_Key);
		//CIniManager::GetInstance()->SetHarass_Key(W2C(m_strHarass_Key.GetString()));

		//TAB_ONE->GetDlgItem(BOT_EDIT_LASTHIT_KEY)->GetWindowText(m_strLastHit_Key);
		//CIniManager::GetInstance()->SetLastHit_Key(W2C(m_strLastHit_Key.GetString()));

		//CIniManager::GetInstance()->SetAtkCurrentSelected(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_ATK_CURRENT_SELECTED))->GetCheck());
		//CIniManager::GetInstance()->SetCombo(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_COMBO))->GetCheck());
		//CIniManager::GetInstance()->SetComboUseQ(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_Q))->GetCheck());
		//CIniManager::GetInstance()->SetComboUseW(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_W))->GetCheck());
		//CIniManager::GetInstance()->SetComboUseE(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_E))->GetCheck());
		//CIniManager::GetInstance()->SetComboUseR(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_R))->GetCheck());
		//CIniManager::GetInstance()->SetClearLane(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEAR_LANE))->GetCheck());
		//CIniManager::GetInstance()->SetClearLaneUseQ(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_Q))->GetCheck());
		//CIniManager::GetInstance()->SetClearLaneUseW(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_W))->GetCheck());
		//CIniManager::GetInstance()->SetClearLaneUseE(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_E))->GetCheck());
		//CIniManager::GetInstance()->SetClearLaneUseR(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_R))->GetCheck());
		//CIniManager::GetInstance()->SetHarass(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS))->GetCheck());
		//CIniManager::GetInstance()->SetHarassUseQ(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_Q))->GetCheck());
		//CIniManager::GetInstance()->SetHarassUseW(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_W))->GetCheck());
		//CIniManager::GetInstance()->SetHarassUseE(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_E))->GetCheck());
		//CIniManager::GetInstance()->SetHarassUseR(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_R))->GetCheck());
		//CIniManager::GetInstance()->SetLastHit(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_LASTHIT))->GetCheck());
		//CIniManager::GetInstance()->SetMove2Mouse(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_MOVE2MOUSE))->GetCheck());
		//CIniManager::GetInstance()->SetEvadeLine(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_EVADE_LINE))->GetCheck());
		//CIniManager::GetInstance()->SetEvadeCircle(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_EVADE_CIRCLE))->GetCheck());
		//CIniManager::GetInstance()->SetEvadeDangerous(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_EVADE_DANGEROUS))->GetCheck());
		//CIniManager::GetInstance()->SetHackZoom(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HACKZOOM))->GetCheck());
		//CIniManager::GetInstance()->SetModSkin(((CButton*)TAB_ONE->GetDlgItem(LOLBOT_MODSKIN))->GetCheck());
		//CIniManager::GetInstance()->SetPlayWithBot(((CButton*)TAB_ONE->GetDlgItem(IDC_DANHVOIMAY))->GetCheck());
		//CIniManager::GetInstance()->SetPercentManaClearLane(TAB_ONE->GetDlgItemInt(BOT_EDIT_MP_CLEARLANE));
		//CIniManager::GetInstance()->SetPercentManaHarass(TAB_ONE->GetDlgItemInt(BOT_EDIT_MP_HARASS));
		//CIniManager::GetInstance()->SetDelaySkillAfter(TAB_ONE->GetDlgItemInt(BOT_EDIT_DELAY_SKILL));

		//CIniManager::GetInstance()->SetBatTatVeHinh(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_TAT_BAT_VE))->GetCheck());
		//CIniManager::GetInstance()->SetVeMatThuong(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_MAT_THUONG))->GetCheck());
		//CIniManager::GetInstance()->SetVeMatKiemSoat(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_MAT_KIEM_SOAT))->GetCheck());
		//CIniManager::GetInstance()->SetVeCanhBaoGank(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_GANK))->GetCheck());
		//CIniManager::GetInstance()->SetVeDoanHuong(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_DOAN_HUONG))->GetCheck());
		//CIniManager::GetInstance()->SetVeTamTruDich(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TAM_TRU_DICH))->GetCheck());
		//CIniManager::GetInstance()->SetVeTamTruDongMinh(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TAM_TRU_DONG_MINH))->GetCheck());
		//CIniManager::GetInstance()->SetVeTimeEnemyRecall(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TIME_ENEMY_RECALL))->GetCheck());
		//CIniManager::GetInstance()->SetVeTimeEnemyHoiSkill(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TIME_REVIVE_ENEMY_SKILL))->GetCheck());
		//CIniManager::GetInstance()->SetVeTimeEnemyHoiSpell(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TIME_REVIVE_ENEMY_SPELL))->GetCheck());
		//CIniManager::GetInstance()->SetVeTimeXuatHienQuaiRung(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TIME_JUNGLE_APPEAR))->GetCheck());
		//CIniManager::GetInstance()->SetVePlayerDanhThuong(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_PLAYER_DANH_THUONG))->GetCheck());
		//CIniManager::GetInstance()->SetVePlayerSkillQ(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_PLAYER_SKILL_Q))->GetCheck());
		//CIniManager::GetInstance()->SetVePlayerSkillW(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_PLAYER_SKILL_W))->GetCheck());
		//CIniManager::GetInstance()->SetVePlayerSkillE(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_PLAYER_SKILL_E))->GetCheck());
		//CIniManager::GetInstance()->SetVePlayerSkillR(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_PLAYER_SKILL_R))->GetCheck());
		//CIniManager::GetInstance()->SetVeEnemyDanhThuong(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_ENEMY_DANH_THUONG))->GetCheck());
		//CIniManager::GetInstance()->SetVeEnemySkillQ(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_ENEMY_SKILL_Q))->GetCheck());
		//CIniManager::GetInstance()->SetVeEnemySkillW(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_ENEMY_SKILL_W))->GetCheck());
		//CIniManager::GetInstance()->SetVeEnemySkillE(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_ENEMY_SKILL_E))->GetCheck());
		//CIniManager::GetInstance()->SetVeEnemySkillR(((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_ENEMY_SKILL_R))->GetCheck());

		//CIniManager::GetInstance()->SetHoiMau_Skill(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_HOIMAU_SKILL))->GetCheck());
		//CIniManager::GetInstance()->SetHoiMau_Item(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_HOIMAU_ITEM))->GetCheck());
		//CIniManager::GetInstance()->SetThieuDot(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_THIEUDOT))->GetCheck());
		//CIniManager::GetInstance()->SetThanhTay(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_THANH_TAY))->GetCheck());
		//CIniManager::GetInstance()->SetLaChan(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_LA_CHAN))->GetCheck());
		//CIniManager::GetInstance()->SetTrungPhat(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_TRUNG_PHAT))->GetCheck());
		//CIniManager::GetInstance()->SetVoDanh(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_VODANH))->GetCheck());
		//CIniManager::GetInstance()->SetHextech(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_HEXTECH))->GetCheck());
		//CIniManager::GetInstance()->SetTiamat(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_TIAMAT))->GetCheck());
		//CIniManager::GetInstance()->SetIronSolari(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_IRON_SOLARI))->GetCheck());
		//CIniManager::GetInstance()->SetSonThach(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_SON_THACH))->GetCheck());
		//CIniManager::GetInstance()->SetDongHoCat(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_DONG_HO_CAT))->GetCheck());
		//CIniManager::GetInstance()->SetQuyenTruongDTS(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_QUYEN_TRUONG_DTS))->GetCheck());
		//CIniManager::GetInstance()->SetKhanGiaiThuat(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_KHAN_GIAI_THUAT))->GetCheck());
		//CIniManager::GetInstance()->SetHomMikael(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_HOM_MIKAEL))->GetCheck());
		//CIniManager::GetInstance()->SetChuocToi(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_CHUOC_TOI))->GetCheck());
		//CIniManager::GetInstance()->SetKhienBang(((CButton*)TAB_THREE->GetDlgItem(LOLBOT_KHIENBANG))->GetCheck());

		//CIniManager::GetInstance()->SetPercentHP4Skill(TAB_THREE->GetDlgItemInt(BOT_EDIT_HM_SKILL));
		//CIniManager::GetInstance()->SetPercentHP4Item(TAB_THREE->GetDlgItemInt(BOT_EDIT_HM_ITEM));
		//CIniManager::GetInstance()->SetPercentHP4LaChan(TAB_THREE->GetDlgItemInt(BOT_EDIT_LA_CHAN));
		//CIniManager::GetInstance()->SetPercentHP4IronSolari(TAB_THREE->GetDlgItemInt(BOT_EDIT_IRON_SOLARI));
		//CIniManager::GetInstance()->SetPercentHP4SonThach(TAB_THREE->GetDlgItemInt(BOT_EDIT_SON_THACH));
		//CIniManager::GetInstance()->SetPercentHP4DongHoCat(TAB_THREE->GetDlgItemInt(BOT_EDIT_DONG_HO_CAT));
		//CIniManager::GetInstance()->SetPercentHP4QT_DTS(TAB_THREE->GetDlgItemInt(BOT_EDIT_QT_DTS));
		//CIniManager::GetInstance()->SetPercentHP4ChuocToi(TAB_THREE->GetDlgItemInt(BOT_EDIT_CHUOC_TOI));

		CIniManager::GetInstance()->WriteIniFile();
	} 
	else // load information from ini file
	{
		CIniManager::GetInstance()->ReadIniFile();

		m_strUsername.SetString(C2W(CIniManager::GetInstance()->GetUsername()));

		//m_strCombo_Key.SetString(C2W(CIniManager::GetInstance()->GetCombo_Key()));
		//m_strLaneClear_Key.SetString(C2W(CIniManager::GetInstance()->GetLaneClear_Key()));
		//m_strHarass_Key.SetString(C2W(CIniManager::GetInstance()->GetHarass_Key()));
		//m_strLastHit_Key.SetString(C2W(CIniManager::GetInstance()->GetLastHit_Key()));

		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_ATK_CURRENT_SELECTED))->SetCheck(CIniManager::GetInstance()->GetAtkCurrentSelected());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_COMBO))->SetCheck(CIniManager::GetInstance()->GetCombo());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_Q))->SetCheck(CIniManager::GetInstance()->GetComboUseQ());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_W))->SetCheck(CIniManager::GetInstance()->GetComboUseW());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_E))->SetCheck(CIniManager::GetInstance()->GetComboUseE());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_R))->SetCheck(CIniManager::GetInstance()->GetComboUseR());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEAR_LANE))->SetCheck(CIniManager::GetInstance()->GetClearLane());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_Q))->SetCheck(CIniManager::GetInstance()->GetClearLaneUseQ());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_W))->SetCheck(CIniManager::GetInstance()->GetClearLaneUseW());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_E))->SetCheck(CIniManager::GetInstance()->GetClearLaneUseE());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_R))->SetCheck(CIniManager::GetInstance()->GetClearLaneUseR());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS))->SetCheck(CIniManager::GetInstance()->GetHarass());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_Q))->SetCheck(CIniManager::GetInstance()->GetHarassUseQ());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_W))->SetCheck(CIniManager::GetInstance()->GetHarassUseW());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_E))->SetCheck(CIniManager::GetInstance()->GetHarassUseE());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_R))->SetCheck(CIniManager::GetInstance()->GetHarassUseR());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_LASTHIT))->SetCheck(CIniManager::GetInstance()->GetLastHit());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_MOVE2MOUSE))->SetCheck(CIniManager::GetInstance()->GetMove2Mouse());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_EVADE_LINE))->SetCheck(CIniManager::GetInstance()->GetEvadeLine());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_EVADE_CIRCLE))->SetCheck(CIniManager::GetInstance()->GetEvadeCircle());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_EVADE_DANGEROUS))->SetCheck(CIniManager::GetInstance()->GetEvadeDangerous());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HACKZOOM))->SetCheck(CIniManager::GetInstance()->GetHackZoom());
		//((CButton*)TAB_ONE->GetDlgItem(LOLBOT_MODSKIN))->SetCheck(CIniManager::GetInstance()->GetModSkin());
		//((CButton*)TAB_ONE->GetDlgItem(IDC_DANHVOIMAY))->SetCheck(CIniManager::GetInstance()->GetPlayWithBot());
		//TAB_ONE->SetDlgItemInt(BOT_EDIT_MP_CLEARLANE, CIniManager::GetInstance()->GetPercentManaClearLane());
		//TAB_ONE->SetDlgItemInt(BOT_EDIT_MP_HARASS, CIniManager::GetInstance()->GetPercentManaHarass());
		//TAB_ONE->SetDlgItemInt(BOT_EDIT_DELAY_SKILL, CIniManager::GetInstance()->GetDelaySkillAfter());

		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_TAT_BAT_VE))->SetCheck(CIniManager::GetInstance()->GetBatTatVeHinh());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_MAT_THUONG))->SetCheck(CIniManager::GetInstance()->GetVeMatThuong());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_MAT_KIEM_SOAT))->SetCheck(CIniManager::GetInstance()->GetVeMatKiemSoat());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_GANK))->SetCheck(CIniManager::GetInstance()->GetVeCanhBaoGank());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_DOAN_HUONG))->SetCheck(CIniManager::GetInstance()->GetVeDoanHuong());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TAM_TRU_DICH))->SetCheck(CIniManager::GetInstance()->GetVeTamTruDich());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TAM_TRU_DONG_MINH))->SetCheck(CIniManager::GetInstance()->GetVeTamTruDongMinh());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TIME_ENEMY_RECALL))->SetCheck(CIniManager::GetInstance()->GetVeTimeEnemyRecall());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TIME_REVIVE_ENEMY_SKILL))->SetCheck(CIniManager::GetInstance()->GetVeTimeEnemyHoiSkill());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TIME_REVIVE_ENEMY_SPELL))->SetCheck(CIniManager::GetInstance()->GetVeTimeEnemyHoiSpell());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TIME_JUNGLE_APPEAR))->SetCheck(CIniManager::GetInstance()->GetVeTimeXuatHienQuaiRung());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_PLAYER_DANH_THUONG))->SetCheck(CIniManager::GetInstance()->GetVePlayerDanhThuong());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_PLAYER_SKILL_Q))->SetCheck(CIniManager::GetInstance()->GetVePlayerSkillQ());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_PLAYER_SKILL_W))->SetCheck(CIniManager::GetInstance()->GetVePlayerSkillW());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_PLAYER_SKILL_E))->SetCheck(CIniManager::GetInstance()->GetVePlayerSkillE());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_PLAYER_SKILL_R))->SetCheck(CIniManager::GetInstance()->GetVePlayerSkillR());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_ENEMY_DANH_THUONG))->SetCheck(CIniManager::GetInstance()->GetVeEnemyDanhThuong());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_ENEMY_SKILL_Q))->SetCheck(CIniManager::GetInstance()->GetVeEnemySkillQ());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_ENEMY_SKILL_W))->SetCheck(CIniManager::GetInstance()->GetVeEnemySkillW());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_ENEMY_SKILL_E))->SetCheck(CIniManager::GetInstance()->GetVeEnemySkillE());
		//((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_ENEMY_SKILL_R))->SetCheck(CIniManager::GetInstance()->GetVeEnemySkillR());

		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_HOIMAU_SKILL))->SetCheck(CIniManager::GetInstance()->GetHoiMau_Skill());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_HOIMAU_ITEM))->SetCheck(CIniManager::GetInstance()->GetHoiMau_Item());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_THIEUDOT))->SetCheck(CIniManager::GetInstance()->GetThieuDot());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_THANH_TAY))->SetCheck(CIniManager::GetInstance()->GetThanhTay());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_LA_CHAN))->SetCheck(CIniManager::GetInstance()->GetLaChan());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_TRUNG_PHAT))->SetCheck(CIniManager::GetInstance()->GetTrungPhat());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_VODANH))->SetCheck(CIniManager::GetInstance()->GetVoDanh());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_HEXTECH))->SetCheck(CIniManager::GetInstance()->GetHextech());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_TIAMAT))->SetCheck(CIniManager::GetInstance()->GetTiamat());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_IRON_SOLARI))->SetCheck(CIniManager::GetInstance()->GetIronSolari());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_SON_THACH))->SetCheck(CIniManager::GetInstance()->GetSonThach());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_DONG_HO_CAT))->SetCheck(CIniManager::GetInstance()->GetDongHoCat());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_QUYEN_TRUONG_DTS))->SetCheck(CIniManager::GetInstance()->GetQuyenTruongDTS());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_KHAN_GIAI_THUAT))->SetCheck(CIniManager::GetInstance()->GetKhanGiaiThuat());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_HOM_MIKAEL))->SetCheck(CIniManager::GetInstance()->GetHomMikael());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_CHUOC_TOI))->SetCheck(CIniManager::GetInstance()->GetChuocToi());
		//((CButton*)TAB_THREE->GetDlgItem(LOLBOT_KHIENBANG))->SetCheck(CIniManager::GetInstance()->GetKhienBang());
		//TAB_THREE->SetDlgItemInt(BOT_EDIT_HM_SKILL, CIniManager::GetInstance()->GetPercentHP4Skill());
		//TAB_THREE->SetDlgItemInt(BOT_EDIT_HM_ITEM, CIniManager::GetInstance()->GetPercentHP4Item());
		//TAB_THREE->SetDlgItemInt(BOT_EDIT_LA_CHAN, CIniManager::GetInstance()->GetPercentHP4LaChan());
		//TAB_THREE->SetDlgItemInt(BOT_EDIT_IRON_SOLARI, CIniManager::GetInstance()->GetPercentHP4IronSolari());
		//TAB_THREE->SetDlgItemInt(BOT_EDIT_SON_THACH, CIniManager::GetInstance()->GetPercentHP4SonThach());
		//TAB_THREE->SetDlgItemInt(BOT_EDIT_DONG_HO_CAT, CIniManager::GetInstance()->GetPercentHP4DongHoCat());
		//TAB_THREE->SetDlgItemInt(BOT_EDIT_QT_DTS, CIniManager::GetInstance()->GetPercentHP4QT_DTS());
		//TAB_THREE->SetDlgItemInt(BOT_EDIT_CHUOC_TOI, CIniManager::GetInstance()->GetPercentHP4ChuocToi());
	}
}

void CLoLBotDlg::SettingParams(void)
{
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_ATK_CURRENT_SELECTED, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_ATK_CURRENT_SELECTED))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_COMBO, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_COMBO))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_COMBO_SKILL_Q, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_Q))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_COMBO_SKILL_W, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_W))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_COMBO_SKILL_E, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_E))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_COMBO_SKILL_R, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_COMBO_SKILL_R))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_CLEAR_LANE, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEAR_LANE))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_CLEARLANE_SKILL_Q, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_Q))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_CLEARLANE_SKILL_W, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_W))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_CLEARLANE_SKILL_E, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_E))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_CLEARLANE_SKILL_R, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_CLEARLANE_SKILL_R))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HARASS, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HARASS_SKILL_Q, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_Q))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HARASS_SKILL_W, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_W))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HARASS_SKILL_E, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_E))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HARASS_SKILL_R, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HARASS_SKILL_R))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_LASTHIT, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_LASTHIT))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_MOVE2MOUSE, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_MOVE2MOUSE))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_EVADE_LINE, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_EVADE_LINE))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_EVADE_CIRCLE, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_EVADE_CIRCLE))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_EVADE_DANGEROUS, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_EVADE_DANGEROUS))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HACKZOOM, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_HACKZOOM))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_MODSKIN, ((CButton*)TAB_ONE->GetDlgItem(LOLBOT_MODSKIN))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, IDC_DANHVOIMAY, ((CButton*)TAB_ONE->GetDlgItem(IDC_DANHVOIMAY))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_MP_CLEARLANE, TAB_ONE->GetDlgItemInt(BOT_EDIT_MP_CLEARLANE));
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_MP_HARASS, TAB_ONE->GetDlgItemInt(BOT_EDIT_MP_HARASS));
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_DELAY_SKILL, TAB_ONE->GetDlgItemInt(BOT_EDIT_DELAY_SKILL));
	//::PostMessage(g_hWinAPP, WM_HOOK_WRITE, IDC_BTN_LOGIN, g_bCheckConnectApp);// sau khi click vao nut DN hook xong thi gui sang dll

	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_TAT_BAT_VE, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_TAT_BAT_VE))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_MAT_THUONG, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_MAT_THUONG))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_MAT_KIEM_SOAT, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_MAT_KIEM_SOAT))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_GANK, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_GANK))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_DOAN_HUONG, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_DOAN_HUONG))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_TAM_TRU_DICH, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TAM_TRU_DICH))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_TAM_TRU_DONG_MINH, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TAM_TRU_DONG_MINH))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_TIME_ENEMY_RECALL, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TIME_ENEMY_RECALL))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_TIME_REVIVE_ENEMY_SKILL, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TIME_REVIVE_ENEMY_SKILL))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_TIME_REVIVE_ENEMY_SPELL, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TIME_REVIVE_ENEMY_SPELL))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_TIME_JUNGLE_APPEAR, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_TIME_JUNGLE_APPEAR))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_PLAYER_DANH_THUONG, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_PLAYER_DANH_THUONG))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_PLAYER_SKILL_Q, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_PLAYER_SKILL_Q))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_PLAYER_SKILL_W, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_PLAYER_SKILL_W))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_PLAYER_SKILL_E, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_PLAYER_SKILL_E))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_PLAYER_SKILL_R, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_PLAYER_SKILL_R))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_ENEMY_DANH_THUONG, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_ENEMY_DANH_THUONG))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_ENEMY_SKILL_Q, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_ENEMY_SKILL_Q))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_ENEMY_SKILL_W, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_ENEMY_SKILL_W))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_ENEMY_SKILL_E, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_ENEMY_SKILL_E))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VE_ENEMY_SKILL_R, ((CButton*)TAB_TWO->GetDlgItem(LOLBOT_VE_ENEMY_SKILL_R))->GetCheck());

	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HOIMAU_SKILL, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_HOIMAU_SKILL))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HOIMAU_ITEM, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_HOIMAU_ITEM))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_THIEUDOT, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_THIEUDOT))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_THANH_TAY, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_THANH_TAY))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_LA_CHAN, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_LA_CHAN))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_TRUNG_PHAT, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_TRUNG_PHAT))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_VODANH, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_VODANH))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HEXTECH, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_HEXTECH))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_TIAMAT, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_TIAMAT))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_IRON_SOLARI, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_IRON_SOLARI))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_SON_THACH, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_SON_THACH))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_DONG_HO_CAT, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_DONG_HO_CAT))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_QUYEN_TRUONG_DTS, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_QUYEN_TRUONG_DTS))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_KHAN_GIAI_THUAT, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_KHAN_GIAI_THUAT))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_HOM_MIKAEL, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_HOM_MIKAEL))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_CHUOC_TOI, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_CHUOC_TOI))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, LOLBOT_KHIENBANG, ((CButton*)TAB_THREE->GetDlgItem(LOLBOT_KHIENBANG))->GetCheck());
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_HM_SKILL, TAB_THREE->GetDlgItemInt(BOT_EDIT_HM_SKILL));
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_HM_ITEM, TAB_THREE->GetDlgItemInt(BOT_EDIT_HM_ITEM));
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_LA_CHAN, TAB_THREE->GetDlgItemInt(BOT_EDIT_LA_CHAN));
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_IRON_SOLARI, TAB_THREE->GetDlgItemInt(BOT_EDIT_IRON_SOLARI));
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_SON_THACH, TAB_THREE->GetDlgItemInt(BOT_EDIT_SON_THACH));
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_DONG_HO_CAT, TAB_THREE->GetDlgItemInt(BOT_EDIT_DONG_HO_CAT));
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_QT_DTS, TAB_THREE->GetDlgItemInt(BOT_EDIT_QT_DTS));
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, BOT_EDIT_CHUOC_TOI, TAB_THREE->GetDlgItemInt(BOT_EDIT_CHUOC_TOI));

	UpdateControls(true);
}

void CLoLBotDlg::SetLastFileTimeModified2LabelBUILD()
{
	// the files handle
	HANDLE hFile1;
	FILETIME ftCreate, ftAccess, ftWrite, ftTEMP;
	SYSTEMTIME stUTC_Create, stLocal_Create, stUTC_Access, stLocal_Access, stUTC_Write, stLocal_Write, stUTC_TEMP, stLocal_TEMP;
	// the file is there...
	TCHAR szExeFileName[MAX_PATH]; 
	GetModuleFileName(NULL, szExeFileName, MAX_PATH);

	// Opening the existing file
	hFile1 = CreateFile(szExeFileName, //file to open
		GENERIC_READ, //open for reading
		FILE_SHARE_READ, //share for reading
		NULL, //default security
		OPEN_EXISTING, //existing file only
		FILE_ATTRIBUTE_NORMAL, //normal file
		NULL); //no attribute template

	if(hFile1 == INVALID_HANDLE_VALUE)
	{
		//__oMsg("Could not open %S file, error %d\n", szExeFileName, GetLastError());
		return ;
	}
	//else
	//__oMsg("%S file opened successfully\n", szExeFileName);

	// Retrieve the file times for the file.
	if(!GetFileTime(hFile1, &ftCreate, &ftAccess, &ftWrite))
	{
		//__oMsg("Something wrong lol!\n");
		return ;
	}
	ftTEMP = (CompareFileTime(&ftCreate,&ftAccess) < 0) ? ftCreate : ftAccess;
	ftTEMP = (CompareFileTime(&ftWrite,&ftTEMP) < 0) ? ftWrite : ftTEMP;

	// Convert the created time to local time.
	FileTimeToSystemTime(&ftCreate, &stUTC_Create);
	SystemTimeToTzSpecificLocalTime(NULL, &stUTC_Create, &stLocal_Create);
	// Convert the last-access time to local time.
	FileTimeToSystemTime(&ftAccess, &stUTC_Access);
	SystemTimeToTzSpecificLocalTime(NULL, &stUTC_Access, &stLocal_Access);
	// Convert the last-write time to local time.
	FileTimeToSystemTime(&ftWrite, &stUTC_Write);
	SystemTimeToTzSpecificLocalTime(NULL, &stUTC_Write, &stLocal_Write);
	// Build a string showing the date and time.
	//__oMsg("Created on: %02d/%02d/%d %02d:%02d\n", stLocal_Create.wDay, stLocal_Create.wMonth, stLocal_Create.wYear, stLocal_Create.wHour, stLocal_Create.wMinute);
	//__oMsg("Last accessed: %02d/%02d/%d %02d:%02d\n", stLocal_Access.wDay, stLocal_Access.wMonth, stLocal_Access.wYear, stLocal_Access.wHour, stLocal_Access.wMinute);
	//__oMsg("Last written: %02d/%02d/%d %02d:%02d\n", stLocal_Write.wDay, stLocal_Write.wMonth, stLocal_Write.wYear, stLocal_Write.wHour, stLocal_Write.wMinute);

	FileTimeToSystemTime(&ftTEMP, &stUTC_TEMP);
	SystemTimeToTzSpecificLocalTime(NULL, &stUTC_TEMP, &stLocal_TEMP);
	//__oMsg("TEMPORARY ->: %02d/%02d/%d %02d:%02d\n", stLocal_TEMP.wDay, stLocal_TEMP.wMonth, stLocal_TEMP.wYear, stLocal_TEMP.wHour, stLocal_TEMP.wMinute);
	CWnd* pWndText = GetDlgItem(LOLBOT_BUILD_DATE);
	if(pWndText)
	{
		char       buf[80];
		sprintf_s(buf, "%02d/%02d/%d", stLocal_TEMP.wDay, stLocal_TEMP.wMonth, stLocal_TEMP.wYear);
		SetDlgItemText(LOLBOT_BUILD_DATE, C2W(buf));
	}
	// close the file's handle and itself
	if(CloseHandle(hFile1) == 0)
		;//__oMsg("Can't close the %S handle!\n", szExeFileName);
	else
		;//__oMsg("%S handle closed successfully!\n", szExeFileName);
}

int CLoLBotDlg::MsgBox(CHAR *content, CHAR *title, int ID)
{
	SetTimer(ID_CLOSE_MSGBOX, 6000, NULL); // 6000ms = 6 secs
	if (title == NULL)
		return AfxMessageBox(C2W(content));
	else
		return ::MessageBox(m_hWnd, C2W(content), C2W(title), MB_OK);
	KillTimer(ID_CLOSE_MSGBOX);
}

