// MyButton.cpp : implementation file
//

#include "stdafx.h"
#include "LuckyDraw.h"
#include "MyButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyButton

CMyButton::CMyButton()
{
}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
	//{{AFX_MSG_MAP(CMyButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyButton message handlers

void CMyButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CButton::OnLButtonDown(nFlags, point);
	WPARAM wParam = (((DWORD)WM_LBUTTONDOWN) << 16) + ((DWORD)GetDlgCtrlID()); 
	::SendMessage(this->GetParent()->GetSafeHwnd(),WM_COMMAND, wParam, 0);
	
}

void CMyButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CButton::OnLButtonUp(nFlags, point);
	WPARAM wParam = (((DWORD)WM_LBUTTONUP) << 16) + ((DWORD)GetDlgCtrlID()); 
	::SendMessage(this->GetParent()->GetSafeHwnd(),WM_COMMAND, wParam, 0);
}
