#pragma once


// CTabFour dialog

class CTabFour : public CDialog
{
	DECLARE_DYNAMIC(CTabFour)

public:
	CTabFour(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTabFour();

// Dialog Data
	enum { IDD = LOLBOT_TAB_FOUR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
