#pragma once


// CTabThree dialog

class CTabThree : public CDialog
{
	DECLARE_DYNAMIC(CTabThree)

public:
	CTabThree(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabThree();

// Dialog Data
	enum { IDD = LOLBOT_TAB_THREE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTab3ChecBoxStatusChanged(UINT nID);
	afx_msg void OnTab3EditsChanged(UINT nID);
};
