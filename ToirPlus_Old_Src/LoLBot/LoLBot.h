
// LoLBot.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


const UINT WM_HOOK_WRITE = RegisterWindowMessage(_T("WM_HOOK_WRITE"));
extern HWND g_hWinAPP;
// CLoLBotApp:
// See LoLBot.cpp for the implementation of this class
//

class CLoLBotApp : public CWinApp
{
public:
	CLoLBotApp();

	// Overrides
public:
	virtual BOOL InitInstance();

	// Implementation
	HANDLE m_Mutex_h;
	DECLARE_MESSAGE_MAP()
};

//extern CLoLBotApp theApp;