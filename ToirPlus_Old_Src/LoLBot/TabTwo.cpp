// TabTwo.cpp : implementation file
//

#include "stdafx.h"
#include "LoLBot.h"
#include "TabTwo.h"


// CTabTwo dialog

IMPLEMENT_DYNAMIC(CTabTwo, CDialog)

CTabTwo::CTabTwo(CWnd* pParent /*=NULL*/)
	: CDialog(CTabTwo::IDD, pParent)
{

}

CTabTwo::~CTabTwo()
{
}

void CTabTwo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabTwo, CDialog)
	ON_CONTROL_RANGE(BN_CLICKED, LOLBOT_TAT_BAT_VE, LOLBOT_VE_ENEMY_SKILL_R, OnTab2ChecBoxStatusChanged)
END_MESSAGE_MAP()


// CTabTwo message handlers
//#include "Commons.h"
//extern HWND g_hWinAPP;
void CTabTwo::OnTab2ChecBoxStatusChanged(UINT nID)
{
	CButton *pCheckBox = (CButton *)GetDlgItem(nID);
	::PostMessage(g_hWinAPP, WM_HOOK_WRITE, nID, pCheckBox->GetCheck());
	//__oMsg("--------------->[%s][%d]haint--->stt check:%d;ID=%d", __FILE__, __LINE__, pCheckBox->GetCheck(), nID);
}