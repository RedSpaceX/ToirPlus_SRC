// MyTabCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "LoLBot.h"
#include "MyTabCtrl.h"

#include "TabOne.h"
#include "TabTwo.h"
#include "TabThree.h"
#include "TabFour.h"
#include "TabFive.h"


/////////////////////////////////////////////////////////////////////////////
// CMyTabCtrl

CMyTabCtrl::CMyTabCtrl()
{
	m_tabPages[0]=new CTabOne;
	m_tabPages[1]=new CTabTwo;
	m_tabPages[2]=new CTabThree;
	m_tabPages[3]=new CTabFour;
	m_tabPages[4]=new CTabFive;

	m_nNumberOfPages=5;
}

CMyTabCtrl::~CMyTabCtrl()
{
	for(int nCount=0; nCount < m_nNumberOfPages; nCount++){
		delete m_tabPages[nCount];
	}
}

void CMyTabCtrl::Init()
{
	m_tabCurrent=0;

	m_tabPages[0]->Create(LOLBOT_TAB_ONE, this);
	m_tabPages[1]->Create(LOLBOT_TAB_TWO, this);
	m_tabPages[2]->Create(LOLBOT_TAB_THREE, this);
	m_tabPages[3]->Create(LOLBOT_TAB_FOUR, this);
	m_tabPages[4]->Create(LOLBOT_TAB_FIVE, this);

	m_tabPages[0]->ShowWindow(SW_SHOW);
	m_tabPages[1]->ShowWindow(SW_HIDE);
	m_tabPages[2]->ShowWindow(SW_HIDE);
	m_tabPages[3]->ShowWindow(SW_HIDE);
	m_tabPages[4]->ShowWindow(SW_HIDE);

	SetRectangle();
}

void CMyTabCtrl::SetRectangle()
{
	CRect tabRect, itemRect;
	int nX, nY, nXc, nYc;

	GetClientRect(&tabRect);
	GetItemRect(0, &itemRect);

	nX=itemRect.left;
	nY=itemRect.bottom+1;
	nXc=tabRect.right-itemRect.left-1;
	nYc=tabRect.bottom-nY-1;

	m_tabPages[0]->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_SHOWWINDOW);
	for(int nCount=1; nCount < m_nNumberOfPages; nCount++){
		m_tabPages[nCount]->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_HIDEWINDOW);
	}
}

BEGIN_MESSAGE_MAP(CMyTabCtrl, CTabCtrl)
	//{{AFX_MSG_MAP(CMyTabCtrl)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTabCtrl message handlers

void CMyTabCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CTabCtrl::OnLButtonDown(nFlags, point);

	if(m_tabCurrent != GetCurFocus()){
		m_tabPages[m_tabCurrent]->ShowWindow(SW_HIDE);
		m_tabCurrent=GetCurFocus();
		m_tabPages[m_tabCurrent]->ShowWindow(SW_SHOW);
		m_tabPages[m_tabCurrent]->SetFocus();
	}
}
