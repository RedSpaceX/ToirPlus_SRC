#pragma once


// CTabOne dialog

class CTabOne : public CDialog
{
	DECLARE_DYNAMIC(CTabOne)

public:
	CTabOne(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabOne();

// Dialog Data
	enum { IDD = LOLBOT_TAB_ONE };

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTab1ChecBoxStatusChanged(UINT nID);
	afx_msg void OnTab1EditsChanged(UINT nID);
	afx_msg void OnBnClickedButtonTest();
};
