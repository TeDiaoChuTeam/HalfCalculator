// Ctrltest.h : main header file for the CTRLTEST application
//

#if !defined(AFX_CTRLTEST_H__B4BF9259_5A3D_4115_AFAA_20FC0EA4DD17__INCLUDED_)
#define AFX_CTRLTEST_H__B4BF9259_5A3D_4115_AFAA_20FC0EA4DD17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCtrltestApp:
// See Ctrltest.cpp for the implementation of this class
//

class CCtrltestApp : public CWinApp
{
public:
	CCtrltestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtrltestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCtrltestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTRLTEST_H__B4BF9259_5A3D_4115_AFAA_20FC0EA4DD17__INCLUDED_)
