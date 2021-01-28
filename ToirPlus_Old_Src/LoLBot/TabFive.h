#pragma once


// CTabFive dialog

class CTabFive : public CDialog
{
	DECLARE_DYNAMIC(CTabFive)

public:
	CTabFive(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabFive();

// Dialog Data
	enum { IDD = LOLBOT_TAB_FIVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
