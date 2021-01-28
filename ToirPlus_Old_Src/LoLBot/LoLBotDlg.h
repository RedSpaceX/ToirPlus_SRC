
// LoLBotDlg.h : header file
//

#pragma once

#include "TrayDialog.h"
#include "afxwin.h"
#include "MyTabCtrl.h"
static const UINT ID_CHECK_LOGIN = 1000;
static const UINT ID_CLOSE_MSGBOX = 1001;
static const UINT ID_CHECK_DEBUGGER = 1002;

// CLoLBotDlg dialog
class CLoLBotDlg : public CTrayDialog
{
	// Construction
public:
	CLoLBotDlg(CWnd* pParent = NULL);	// standard constructor

	// Dialog Data
	enum { IDD = LOLBOT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

public:
	HANDLE m_hProcess;
	bool m_isLogined;
	// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strUsername;
	CString m_strPassword;
	CButton m_btnLogin;
	CButton m_btnDangKy;

	CString m_strCombo_Key;
	CString m_strLaneClear_Key;
	CString m_strHarass_Key;
	CString m_strLastHit_Key;
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnTrayMenuOPEN();
	afx_msg void OnBnClickedButtonHook();
	afx_msg void OnBnClickedBtnLogin();
	afx_msg void OnBnClickedBtnDangKy();
	afx_msg void OnStnClickedStaticHome();
	afx_msg void OnStnClickedStaticSupport();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	void UpdateControls(bool bSave = true);
	void SettingParams(void);
	void SetLastFileTimeModified2LabelBUILD();
	int MsgBox(CHAR *, CHAR* title = NULL, int ID = MB_OK);
	CMyTabCtrl m_MyTabCtrl;
};

