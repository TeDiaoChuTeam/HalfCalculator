
// AncientDlg.h: 头文件
//

#pragma once


// CAncientDlg 对话框
class CAncientDlg : public CDialogEx
{
// 构造
public:
	CAncientDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANCIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_qin;
	CButton m_whan;
	CButton m_ehan;
	CButton m_sui;
	CButton m_tang;
	CButton m_song;
	CButton m_yuan;
	CButton m_ming;
	CButton m_qing;
	CButton m_jin;
	double m_inleng;
	double m_outleng;
	double m_invo;
	double m_outvo;
	double m_inwe;
	double m_outwe;

	CStatic m_tips;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedRadioQin();
	afx_msg void OnBnClickedRadioWhan();
	afx_msg void OnBnClickedRadioEhan();
	afx_msg void OnBnClickedRadioSui();
	afx_msg void OnBnClickedRadioTang();
	afx_msg void OnBnClickedRadioSong();
	afx_msg void OnBnClickedRadioYuan();
	afx_msg void OnBnClickedRadioMing();
	afx_msg void OnBnClickedRadioQing();
	afx_msg void OnBnClickedRadioJin();
	afx_msg void OnBnClickedButtonclear1();
	afx_msg void OnBnClickedButtonclear2();
	afx_msg void OnBnClickedButtonclear3();
};
