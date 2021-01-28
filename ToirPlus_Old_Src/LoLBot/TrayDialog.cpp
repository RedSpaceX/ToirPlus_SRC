// TrayDialog.cpp : implementation file
//

#include "stdafx.h"
//#include "TrayDemo.h"
#include "TrayDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrayDialog dialog


CTrayDialog::CTrayDialog(UINT uIDD,CWnd* pParent /*=NULL*/)
	: CDialog(uIDD, pParent)
{
	m_nidIconData.cbSize			= sizeof(NOTIFYICONDATA);
	
	m_nidIconData.hWnd				= 0;
	m_nidIconData.uID				= 1;

	m_nidIconData.uCallbackMessage	= WM_TRAY_ICON_NOTIFY_MESSAGE;

	m_nidIconData.hIcon				= 0;
	m_nidIconData.szTip[0]			= 0;	
	m_nidIconData.uFlags			= NIF_MESSAGE;

	m_bTrayIconVisible				= FALSE;

	m_nDefaultMenuItem				= 0;

	m_bMinimizeToTray				= TRUE;

}


BEGIN_MESSAGE_MAP(CTrayDialog, CDialog)
	//{{AFX_MSG_MAP(CTrayDialog)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SYSCOMMAND()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_TRAY_ICON_NOTIFY_MESSAGE,OnTrayNotify)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrayDialog message handlers

int CTrayDialog::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_nidIconData.hWnd = this->m_hWnd;
	m_nidIconData.uID = 1;
	
	return 0;
}

void CTrayDialog::OnDestroy() 
{
	CDialog::OnDestroy();
	if(m_nidIconData.hWnd && m_nidIconData.uID>0 && TrayIsVisible())
	{
		Shell_NotifyIcon(NIM_DELETE,&m_nidIconData);
	}
}

BOOL CTrayDialog::TrayIsVisible()
{
	return m_bTrayIconVisible;
}

void CTrayDialog::TraySetIcon(HICON hIcon)
{
	ASSERT(hIcon);

	m_nidIconData.hIcon = hIcon;
	m_nidIconData.uFlags |= NIF_ICON;
}

void CTrayDialog::TraySetIcon(UINT nResourceID)
{
	ASSERT(nResourceID>0);
	HICON hIcon = 0;
	hIcon = AfxGetApp()->LoadIcon(nResourceID);
	if(hIcon)
	{
		m_nidIconData.hIcon = hIcon;
		m_nidIconData.uFlags |= NIF_ICON;
	}
	else
	{
		TRACE0("FAILED TO LOAD ICON\n");
	}
}

void CTrayDialog::TraySetIcon(LPCTSTR lpszResourceName)
{
	HICON hIcon = 0;
	hIcon = AfxGetApp()->LoadIcon(lpszResourceName);
	if(hIcon)
	{
		m_nidIconData.hIcon = hIcon;
		m_nidIconData.uFlags |= NIF_ICON;
	}
	else
	{
		TRACE0("FAILED TO LOAD ICON\n");
	}
}

void CTrayDialog::TraySetToolTip(LPCTSTR lpszToolTip)
{
	ASSERT(wcslen(lpszToolTip) > 0 && wcslen(lpszToolTip) < 64);

	wcscpy_s(m_nidIconData.szTip,lpszToolTip);
	m_nidIconData.uFlags |= NIF_TIP;
}

BOOL CTrayDialog::TrayShow()
{
	BOOL bSuccess = FALSE;
	if(!m_bTrayIconVisible)
	{
		bSuccess = Shell_NotifyIcon(NIM_ADD,&m_nidIconData);
		if(bSuccess)
			m_bTrayIconVisible= TRUE;
	}
	else
	{
		TRACE0("ICON ALREADY VISIBLE");
	}
	return bSuccess;
}

BOOL CTrayDialog::TrayHide()
{
	BOOL bSuccess = FALSE;
	if(m_bTrayIconVisible)
	{
		bSuccess = Shell_NotifyIcon(NIM_DELETE,&m_nidIconData);
		if(bSuccess)
			m_bTrayIconVisible= FALSE;
	}
	else
	{
		TRACE0("ICON ALREADY HIDDEN");
	}
	return bSuccess;
}

BOOL CTrayDialog::TrayUpdate()
{
	BOOL bSuccess = FALSE;
	if(m_bTrayIconVisible)
	{
		bSuccess = Shell_NotifyIcon(NIM_MODIFY,&m_nidIconData);
	}
	else
	{
		TRACE0("ICON NOT VISIBLE");
	}
	return bSuccess;
}


BOOL CTrayDialog::TraySetMenu(UINT nResourceID,UINT nDefaultPos)
{
	BOOL bSuccess;
	bSuccess = m_mnuTrayMenu.LoadMenu(nResourceID);
	return bSuccess;
}


BOOL CTrayDialog::TraySetMenu(LPCTSTR lpszMenuName,UINT nDefaultPos)
{
	BOOL bSuccess;
	bSuccess = m_mnuTrayMenu.LoadMenu(lpszMenuName);
	return bSuccess;
}

BOOL CTrayDialog::TraySetMenu(HMENU hMenu,UINT nDefaultPos)
{
	m_mnuTrayMenu.Attach(hMenu);
	return TRUE;
}

LRESULT CTrayDialog::OnTrayNotify(WPARAM wParam, LPARAM lParam) 
{ 
    UINT uID; 
    UINT uMsg; 
 
    uID = (UINT) wParam; 
    uMsg = (UINT) lParam; 
 
	if (uID != 1)
		return 0;
	
	CPoint pt;	

    switch (uMsg ) 
	{ 
	case WM_MOUSEMOVE:
		GetCursorPos(&pt);
		ClientToScreen(&pt);
		OnTrayMouseMove(pt);
		break;
	case WM_LBUTTONDOWN:
		GetCursorPos(&pt);
		ClientToScreen(&pt);
		OnTrayLButtonDown(pt);
		break;
	case WM_LBUTTONDBLCLK:
		GetCursorPos(&pt);
		ClientToScreen(&pt);
		OnTrayLButtonDblClk(pt);
		break;
	
	case WM_RBUTTONDOWN:
	case WM_CONTEXTMENU:
		GetCursorPos(&pt);
		//ClientToScreen(&pt);
		OnTrayRButtonDown(pt);
		break;
	case WM_RBUTTONDBLCLK:
		GetCursorPos(&pt);
		ClientToScreen(&pt);
		OnTrayRButtonDblClk(pt);
		break;
    } 
     return 1; 
 } 
void CTrayDialog::OnSysCommand(UINT nID, LPARAM lParam)
{
	if(m_bMinimizeToTray)
	{
		if ((nID & 0xFFF0) == SC_MINIMIZE)
		{
		
			if( TrayShow())
				this->ShowWindow(SW_HIDE);		
		}
		else
			CDialog::OnSysCommand(nID, lParam);	
	}
	else
		CDialog::OnSysCommand(nID, lParam);
}
void CTrayDialog::TraySetMinimizeToTray(BOOL bMinimizeToTray)
{
	m_bMinimizeToTray = bMinimizeToTray;
}


void CTrayDialog::OnTrayRButtonDown(CPoint pt)
{
	m_mnuTrayMenu.GetSubMenu(0)->TrackPopupMenu(TPM_BOTTOMALIGN|TPM_LEFTBUTTON|TPM_RIGHTBUTTON,pt.x,pt.y,this);
	m_mnuTrayMenu.GetSubMenu(0)->SetDefaultItem(m_nDefaultMenuItem,TRUE);
}

void CTrayDialog::OnTrayLButtonDown(CPoint pt)
{

}

void CTrayDialog::OnTrayLButtonDblClk(CPoint pt)
{
	if(m_bMinimizeToTray)
		if(TrayHide())
			this->ShowWindow(SW_SHOW);
}

void CTrayDialog::OnTrayRButtonDblClk(CPoint pt)
{
}

void CTrayDialog::OnTrayMouseMove(CPoint pt)
{
}

