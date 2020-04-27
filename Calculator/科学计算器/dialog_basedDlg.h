// dialog_basedDlg.h : header file
//

#if !defined(AFX_DIALOG_BASEDDLG_H__38D61B53_45A6_4D9E_8F60_29C7C9012197__INCLUDED_)
#define AFX_DIALOG_BASEDDLG_H__38D61B53_45A6_4D9E_8F60_29C7C9012197__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDialog_basedDlg dialog

class CDialog_basedDlg : public CDialog
{
// Construction
public:
	void Equal2();

	CDialog_basedDlg(CWnd* pParent = NULL);	// standard constructor
void CDialog_basedDlg::AddDigit(char numKey);

// Dialog Data
	//{{AFX_DATA(CDialog_basedDlg)
	enum { IDD = IDD_DIALOG_BASED_DIALOG };
	CEdit	m_control_e;
	BOOL	m_inv;
	BOOL	m_hp;
	double	m_num;
	CString	m_sd;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog_basedDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

    long	double m_op1,m_op2,m_result;
	int m_operation;
	int i,s;
	long double r;
	long double m_m;
	long double  data[50];
	bool st1,st2;
	bool pflag;
	long double p;
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnSubtract();
	afx_msg void OnEqual();
	afx_msg void Onsin();
	afx_msg void Oncos();
	afx_msg void Ontan();
	afx_msg void Onlog();
	afx_msg void Onln();
	afx_msg void Oninv();
	afx_msg void OnHp();
	afx_msg void Ondevide();
	afx_msg void Onclear();
	afx_msg void Onmul();
	afx_msg void Onfactoriel();
	afx_msg void Onpow();
	afx_msg void Onx2();
	afx_msg void Onx3();
	afx_msg void Onpi();
	afx_msg void OnChangeEdit1();
	afx_msg void Onb1();
	afx_msg void Onb2();
	afx_msg void Onb3();
	afx_msg void Onb4();
	afx_msg void Onb5();
	afx_msg void Onb6();
	afx_msg void Onb7();
	afx_msg void Onb8();
	afx_msg void Onb9();
	afx_msg void Onb10();
	afx_msg void Onbp();
	afx_msg void OnOr();
	afx_msg void On1x();
	afx_msg void Onbp2();
	afx_msg void Ondata();
	afx_msg void Onsum();
	afx_msg void Ons();
	afx_msg void Onroot();
	afx_msg void Onroot2();
	afx_msg void Onbsp();
	afx_msg void OnAnd();
	afx_msg void OnXor();
	afx_msg void OnMOd();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnClose();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnClos();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnBnClickedMm();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_BASEDDLG_H__38D61B53_45A6_4D9E_8F60_29C7C9012197__INCLUDED_)
