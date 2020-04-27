// LuckyDraw.h : main header file for the LUCKYDRAW application
//

#if !defined(AFX_LUCKYDRAW_H__0EAA10CB_F6A7_4492_AC55_D37990F22DC9__INCLUDED_)
#define AFX_LUCKYDRAW_H__0EAA10CB_F6A7_4492_AC55_D37990F22DC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLuckyDrawApp:
// See LuckyDraw.cpp for the implementation of this class
//

class CLuckyDrawApp : public CWinApp
{
public:
	CLuckyDrawApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLuckyDrawApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLuckyDrawApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LUCKYDRAW_H__0EAA10CB_F6A7_4492_AC55_D37990F22DC9__INCLUDED_)
