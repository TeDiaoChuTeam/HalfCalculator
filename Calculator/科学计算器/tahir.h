#if !defined(AFX_TAHIR_H__2B75A375_F964_423F_918F_2E63AC838544__INCLUDED_)
#define AFX_TAHIR_H__2B75A375_F964_423F_918F_2E63AC838544__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// tahir.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Ctahir dialog

class Ctahir : public CDialog
{
// Construction
public:
	Ctahir(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Ctahir)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ctahir)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Ctahir)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TAHIR_H__2B75A375_F964_423F_918F_2E63AC838544__INCLUDED_)
