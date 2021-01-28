// TabOne.cpp : implementation file
//

#include "stdafx.h"
#include "LoLBot.h"
#include "TabOne.h"


// CTabOne dialog

IMPLEMENT_DYNAMIC(CTabOne, CDialog)

CTabOne::CTabOne(CWnd* pParent /*=NULL*/)
	: CDialog(CTabOne::IDD, pParent)
{

}

CTabOne::~CTabOne()
{
}

BOOL CTabOne::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE  unless you set the focus to a control
}
void CTabOne::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabOne, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_TEST, &CTabOne::OnBnClickedButtonTest)
	ON_CONTROL_RANGE(BN_CLICKED, LOLBOT_ATK_CURRENT_SELECTED, IDC_DANHVOIMAY, OnTab1ChecBoxStatusChanged)
	ON_CONTROL_RANGE(EN_CHANGE, BOT_EDIT_MP_CLEARLANE, BOT_EDIT_DELAY_SKILL, OnTab1EditsChanged)
END_MESSAGE_MAP()


// CTabOne message handlers
//#include "Commons.h"
//extern HWND g_hWinAPP;
void CTabOne::OnTab1ChecBoxStatusChanged(UINT nID)
{
	CButton *pCheckBox = (CButton *)GetDlgItem(nID);
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, nID, pCheckBox->GetCheck());
	//__oMsg("--------------->[%s][%d]haint--->%d; ID=%d", __FILE__, __LINE__, pCheckBox->GetCheck(), nID);
	GetDlgItem(BOT_EDIT_MP_CLEARLANE)->EnableWindow( ((CButton*)GetDlgItem(LOLBOT_CLEAR_LANE))->GetCheck() );
	GetDlgItem(BOT_EDIT_MP_HARASS)->EnableWindow( ((CButton*)GetDlgItem(LOLBOT_HARASS))->GetCheck() );
}

void CTabOne::OnTab1EditsChanged(UINT nID)
{
	UINT nValue = GetDlgItemInt(nID);
	//__oMsg("--------------->[%s][%d]haint--->value=%d; ID=%d", __FILE__, __LINE__, nValue, nID);
	if (nValue <= 0)
	{
		if (nID == BOT_EDIT_MP_CLEARLANE && nValue >= 101)
		{
			nValue = 45; // reset ve gia tri mac dinh khi gia tri % khong hop le
			SetDlgItemInt(BOT_EDIT_MP_CLEARLANE, nValue);
		}
		if (nID == BOT_EDIT_MP_HARASS && nValue >= 101)
		{
			nValue = 45; // reset ve gia tri mac dinh khi gia tri % khong hop le
			SetDlgItemInt(BOT_EDIT_MP_HARASS, nValue);
		}
		if (nID == BOT_EDIT_DELAY_SKILL && nValue >= 100000)
		{
			nValue = 88; // reset ve gia tri mac dinh khi gia tri % khong hop le
			SetDlgItemInt(BOT_EDIT_DELAY_SKILL, nValue);
		}
		if (nID == BOT_EDIT_COMBO_KEY)
		{
			SetDlgItemInt(BOT_EDIT_COMBO_KEY, nValue);
		}
	}
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, nID, nValue);
	//__oMsg("--------------->[%s][%d]haint--->%d", __FILE__, __LINE__, nValue);
}

void CTabOne::OnBnClickedButtonTest()
{
	//__oMsg("\n1-------------------click test");
	// TODO: Add your control notification handler code here
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, IDC_BUTTON_TEST, 1);
}