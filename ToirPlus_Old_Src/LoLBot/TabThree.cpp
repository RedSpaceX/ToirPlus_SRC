// TabThree.cpp : implementation file
//

#include "stdafx.h"
#include "LoLBot.h"
#include "TabThree.h"


// CTabThree dialog

IMPLEMENT_DYNAMIC(CTabThree, CDialog)

CTabThree::CTabThree(CWnd* pParent /*=NULL*/)
	: CDialog(CTabThree::IDD, pParent)
{

}

CTabThree::~CTabThree()
{
}

void CTabThree::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabThree, CDialog)
	ON_CONTROL_RANGE(BN_CLICKED, LOLBOT_HOIMAU_SKILL, LOLBOT_KHIENBANG, OnTab3ChecBoxStatusChanged)
	ON_CONTROL_RANGE(EN_CHANGE, BOT_EDIT_HM_SKILL, BOT_EDIT_CHUOC_TOI, OnTab3EditsChanged)
END_MESSAGE_MAP()


// CTabThree message handlers
//#include "Commons.h"
//extern HWND g_hWinAPP;
void CTabThree::OnTab3ChecBoxStatusChanged(UINT nID)
{
	CButton *pCheckBox = (CButton *)GetDlgItem(nID);
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, nID, pCheckBox->GetCheck());
	//__oMsg("--------------->[%s][%d]haint--->%d; ID=%d", __FILE__, __LINE__, pCheckBox->GetCheck(), nID);
	GetDlgItem(BOT_EDIT_HM_SKILL)->EnableWindow( ((CButton*)GetDlgItem(LOLBOT_HOIMAU_SKILL))->GetCheck() );
	GetDlgItem(BOT_EDIT_HM_ITEM)->EnableWindow( ((CButton*)GetDlgItem(LOLBOT_HOIMAU_ITEM))->GetCheck() );
	GetDlgItem(BOT_EDIT_LA_CHAN)->EnableWindow( ((CButton*)GetDlgItem(LOLBOT_LA_CHAN))->GetCheck() );
	GetDlgItem(BOT_EDIT_IRON_SOLARI)->EnableWindow( ((CButton*)GetDlgItem(LOLBOT_IRON_SOLARI))->GetCheck() );
	GetDlgItem(BOT_EDIT_SON_THACH)->EnableWindow( ((CButton*)GetDlgItem(LOLBOT_SON_THACH))->GetCheck() );
	GetDlgItem(BOT_EDIT_DONG_HO_CAT)->EnableWindow( ((CButton*)GetDlgItem(LOLBOT_DONG_HO_CAT))->GetCheck() );
	GetDlgItem(BOT_EDIT_QT_DTS)->EnableWindow( ((CButton*)GetDlgItem(LOLBOT_QUYEN_TRUONG_DTS))->GetCheck() );
	GetDlgItem(BOT_EDIT_CHUOC_TOI)->EnableWindow( ((CButton*)GetDlgItem(LOLBOT_CHUOC_TOI))->GetCheck() );
}

void CTabThree::OnTab3EditsChanged(UINT nID)
{
	UINT nValue = GetDlgItemInt(nID);
	//__oMsg("--------------->[%s][%d]haint--->value=%d; ID=%d", __FILE__, __LINE__, nValue, nID);
	if (nValue <= 0 || nValue >= 101)
	{
		if (nID == BOT_EDIT_HM_SKILL)
		{
			nValue = 15; // reset ve gia tri mac dinh khi gia tri % khong hop le
			SetDlgItemInt(BOT_EDIT_HM_SKILL, nValue);
		}
		if (nID == BOT_EDIT_HM_ITEM)
		{
			nValue = 35; // reset ve gia tri mac dinh khi gia tri % khong hop le
			SetDlgItemInt(BOT_EDIT_HM_ITEM, nValue);
		}
		if (nID == BOT_EDIT_LA_CHAN)
		{
			nValue = 40; // reset ve gia tri mac dinh khi gia tri % khong hop le
			SetDlgItemInt(BOT_EDIT_LA_CHAN, nValue);
		}
		if (nID == BOT_EDIT_IRON_SOLARI)
		{
			nValue = 40; // reset ve gia tri mac dinh khi gia tri % khong hop le
			SetDlgItemInt(BOT_EDIT_IRON_SOLARI, nValue);
		}
		if (nID == BOT_EDIT_SON_THACH)
		{
			nValue = 40; // reset ve gia tri mac dinh khi gia tri % khong hop le
			SetDlgItemInt(BOT_EDIT_SON_THACH, nValue);
		}
		if (nID == BOT_EDIT_DONG_HO_CAT)
		{
			nValue = 30; // reset ve gia tri mac dinh khi gia tri % khong hop le
			SetDlgItemInt(BOT_EDIT_DONG_HO_CAT, nValue);
		}
		if (nID == BOT_EDIT_QT_DTS)
		{
			nValue = 40; // reset ve gia tri mac dinh khi gia tri % khong hop le
			SetDlgItemInt(BOT_EDIT_QT_DTS, nValue);
		}
		if (nID == BOT_EDIT_CHUOC_TOI)
		{
			nValue = 35; // reset ve gia tri mac dinh khi gia tri % khong hop le
			SetDlgItemInt(BOT_EDIT_CHUOC_TOI, nValue);
		}
	}
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, nID, nValue);
	//__oMsg("--------------->[%s][%d]haint--->%d", __FILE__, __LINE__, nValue);
}
