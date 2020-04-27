
// LifeDlg.h: 头文件
//

#pragma once


// CLifeDlg 对话框
class CLifeDlg : public CDialogEx
{
// 构造
public:
	CLifeDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIFE_DIALOG };
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
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnEnChangeEdit6();
	double m_height;
	double m_weight;
	double m_bmi;
	CStatic m_bmi_tips;
	CStatic m_tips;
	afx_msg void OnBnClickedButton1();
	CStatic m_tip2;
	double m_xiong;
	double m_yao;
	double m_tun;
	double m_b_weight;
	afx_msg void OnEnChangeEditTun();
	afx_msg void OnStnClickedStaticTips();
	afx_msg void OnBnClickedButtonclear();
};
