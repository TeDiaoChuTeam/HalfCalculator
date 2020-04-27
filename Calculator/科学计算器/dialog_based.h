// dialog_based.h : main header file for the DIALOG_BASED application
//

#if !defined(AFX_DIALOG_BASED_H__9665C853_0BAE_4D9F_999E_FF7344DCA287__INCLUDED_)
#define AFX_DIALOG_BASED_H__9665C853_0BAE_4D9F_999E_FF7344DCA287__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDialog_basedApp:
// See dialog_based.cpp for the implementation of this class
//

class CDialog_basedApp : public CWinApp
{
public:
	CDialog_basedApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_basedApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDialog_basedApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_BASED_H__9665C853_0BAE_4D9F_999E_FF7344DCA287__INCLUDED_)
