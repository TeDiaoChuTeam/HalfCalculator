// LuckyDrawDlg.h : header file
//

#if !defined(AFX_LUCKYDRAWDLG_H__D29EAB48_B1D6_4E88_B424_DAF15EFF7926__INCLUDED_)
#define AFX_LUCKYDRAWDLG_H__D29EAB48_B1D6_4E88_B424_DAF15EFF7926__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyButton.h"
#include "MyEditBox.h"
/////////////////////////////////////////////////////////////////////////////
// CLuckyDrawDlg dialog

class CLuckyDrawDlg : public CDialog
{
// Construction
public:
	CLuckyDrawDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLuckyDrawDlg)
	enum { IDD = IDD_LUCKYDRAW_DIALOG };
	MyEditBox	m_EditBoxShow;
	CString	m_cstrShow;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLuckyDrawDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	map<string, vector<string> > LuckyName;
    string m_team;
    void LoadFile();
//	void initLuckyName();
	bool isSaveName(char* buff);
    bool updateTeam(char* buff);
	// Generated message map functions
	//{{AFX_MSG(CLuckyDrawDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLuckyButton();
	afx_msg void OnShowAllMember();
//	afx_msg void OnSlectTeam();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnKillfocusSelectteam();
	afx_msg void OnCbnSelchangeSelectteam();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LUCKYDRAWDLG_H__D29EAB48_B1D6_4E88_B424_DAF15EFF7926__INCLUDED_)
