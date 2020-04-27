// tahir.cpp : implementation file
//

#include "stdafx.h"
#include "dialog_based.h"
#include "tahir.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Ctahir dialog


Ctahir::Ctahir(CWnd* pParent /*=NULL*/)
	: CDialog(Ctahir::IDD, pParent)
{
	//{{AFX_DATA_INIT(Ctahir)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Ctahir::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Ctahir)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Ctahir, CDialog)
	//{{AFX_MSG_MAP(Ctahir)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ctahir message handlers

void Ctahir::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	AfxMessageBox(" hello ");
	CDialog::OnChar(nChar, nRepCnt, nFlags);
}
