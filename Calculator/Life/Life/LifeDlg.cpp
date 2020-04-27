
// LifeDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Life.h"
#include "LifeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLifeDlg 对话框



CLifeDlg::CLifeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIFE_DIALOG, pParent)
	, m_height(0)
	, m_weight(0)
	, m_bmi(0)
	, m_xiong(0)
	, m_yao(0)
	, m_tun(0)
	, m_b_weight(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLifeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_HEI, m_height);
	DDX_Text(pDX, IDC_WEIGHT, m_weight);

	DDX_Text(pDX, IDC_EDIT_BMI, m_bmi);
	DDX_Control(pDX, IDC_STATIC_BMI, m_bmi_tips);
	DDX_Control(pDX, IDC_STATIC_TIPS, m_tips);
	DDX_Control(pDX, IDC_STATIC_TIP2, m_tip2);
	DDX_Text(pDX, IDC_EDIT_XIONG, m_xiong);
	DDX_Text(pDX, IDC_EDIT_YAO, m_yao);
	DDX_Text(pDX, IDC_EDIT_TUN, m_tun);
	DDX_Text(pDX, IDC_EDIT_BWEIGHT, m_b_weight);
}

BEGIN_MESSAGE_MAP(CLifeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON1, &CLifeDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT_TUN, &CLifeDlg::OnEnChangeEditTun)
	ON_STN_CLICKED(IDC_STATIC_TIPS, &CLifeDlg::OnStnClickedStaticTips)
	ON_BN_CLICKED(IDC_BUTTONclear, &CLifeDlg::OnBnClickedButtonclear)
END_MESSAGE_MAP()


// CLifeDlg 消息处理程序

BOOL CLifeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_tips.SetWindowText(_T("*三围男孩子请忽略"));
	m_tip2.SetWindowText(_T("*某网友曾说过：“根据身高体重计算三围，那跟算命没有什么区别！”所以仅供参考，阿门~"));
	m_bmi_tips.SetWindowText(_T("快输入你的身高体重呀！！！注意看单位哦~"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLifeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLifeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialogEx::OnPaint();
		CPaintDC dc(this);
		CRect rect;
		GetClientRect(&rect);
		dc.FillSolidRect(rect, RGB(205, 234, 214));

	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLifeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CLifeDlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CLifeDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);

	m_xiong = m_height * 0.535;
	m_yao = m_height * 0.365;
	m_tun = m_height * 0.565;
	m_b_weight = (m_height - 100) * 0.9;
	m_bmi = m_weight / (m_height / 100 )/ (m_height / 100);

	if (m_bmi<18.5)
	{
		m_bmi_tips.SetWindowText(_T("严重过轻！不要老是减肥！多吃点知道吗？再苦不能苦孩子，再饿也不能饿孩子！好好吃饭知道吗？摸摸头"));
	}
	if (m_bmi>= 18.5 && m_bmi<23)
	{
		m_bmi_tips.SetWindowText(_T("太棒啦！不胖不瘦刚刚好！不愧是你，如此的完美，但是不可大意，还是要好好保持，多运动呦！比心心"));
	}
	if (m_bmi >= 23 && m_bmi < 25)
	{
		m_bmi_tips.SetWindowText(_T("轻度肥胖，哎呀问题不大的啦，多运动两次就回去了啦。偷偷告诉我，昨天晚上是不是背着我吃夜宵了？哼"));
	}
	if (m_bmi >= 25 && m_bmi < 30)
	{
		m_bmi_tips.SetWindowText(_T("中度肥胖，有点问题，这样下去可不行，减肥减肥！管住嘴迈开腿，瘦下去，走向人生巅峰，赢取白富美！"));
	}
	if (m_bmi >= 30 && m_bmi < 35)
	{
		m_bmi_tips.SetWindowText(_T("高度肥胖！！！你干什么！！！不想穿好看的衣服了吗？不想拥有成功的人生了吗？不瘦下来你怎么好意思来见我！"));
	}
	if (m_bmi >= 35 )
	{
		m_bmi_tips.SetWindowText(_T("严.重..肥...胖....放下你手你的炸鸡可乐，从你温暖的小床上离开，外面的世界如此美好，快给我去运动！！！"));
	}


	UpdateData(0);
}


void CLifeDlg::OnEnChangeEditTun()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CLifeDlg::OnStnClickedStaticTips()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CLifeDlg::OnBnClickedButtonclear()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_HEI, _T(""));
	SetDlgItemText(IDC_WEIGHT, _T(""));

}
