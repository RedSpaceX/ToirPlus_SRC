#pragma once


// CTabTwo dialog

class CTabTwo : public CDialog
{
	DECLARE_DYNAMIC(CTabTwo)

public:
	CTabTwo(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabTwo();

// Dialog Data
	enum { IDD = LOLBOT_TAB_TWO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTab2ChecBoxStatusChanged(UINT nID);
};
