// ½øÖÆ×ª»»Dlg.h : header file
//

#if !defined(AFX_DLG_H__63F679AD_C6A3_4428_B741_762E86143C38__INCLUDED_)
#define AFX_DLG_H__63F679AD_C6A3_4428_B741_762E86143C38__INCLUDED_

#include "LINK_STACK.h"	// Added by ClassView
#include "SEQUENCE_QUEUE.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CEdit	mc_source;
	CComboBox	m_box_object;
	CComboBox	m_box_source;
	CString	m_source;
	CString	m_object;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangeEditSource();
	afx_msg void OnSelchangeComboObject();
	afx_msg void OnSelchangeComboSource();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	double x_StringToDouble(CString *str, int redix);
	SEQUENCE_QUEUE m_sequeue;
	int x_StringToInt(CString *str, int redix);
	void OnOK();
	int x_GetRedix(int num);
	LINK_STACK m_linkstack;
	bool CheckNummer(char ch);
public:
	//afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonclear();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__63F679AD_C6A3_4428_B741_762E86143C38__INCLUDED_)
