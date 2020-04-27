// CtrltestDlg.h : header file
//

#if !defined(AFX_CTRLTESTDLG_H__F33C86DC_6FFF_466B_B678_7CD35F2325EC__INCLUDED_)
#define AFX_CTRLTESTDLG_H__F33C86DC_6FFF_466B_B678_7CD35F2325EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCtrltestDlg dialog

class CCtrltestDlg : public CDialog
{
// Construction
public:
	CCtrltestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCtrltestDlg)
	enum { IDD = IDD_CTRLTEST_DIALOG };
	CStatic	m_ref;
	CButton	m_weight;
	CButton	m_time;
	CButton	m_length;
	CListBox	m_ltUnit2;
	CComboBox	m_cbUnit1;
	double	m_dbNumber;
	CString	m_result;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtrltestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCtrltestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeComboUnit1();
	afx_msg void Onequal();
	afx_msg void OnSelchangeListUnit2();
	afx_msg void OnRadioLength();
	afx_msg void OnRadioTime();
	afx_msg void OnRadioWeight();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CButton m_memory;
	afx_msg void OnBnClickedRadioMemory();
	CButton m_area;
	afx_msg void OnBnClickedRadioArea();
	afx_msg void OnBnClickedButtonclear();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTRLTESTDLG_H__F33C86DC_6FFF_466B_B678_7CD35F2325EC__INCLUDED_)
