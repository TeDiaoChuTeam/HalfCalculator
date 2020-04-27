
// CalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
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


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON_PRIM, &CCalculatorDlg::OnBnClickedButtonPrim)
	ON_BN_CLICKED(IDC_BUTTON_HIGH, &CCalculatorDlg::OnBnClickedButtonHigh)
	ON_BN_CLICKED(IDC_BUTTON_CTRL, &CCalculatorDlg::OnBnClickedButtonCtrl)
	ON_BN_CLICKED(IDC_BUTTON_CODE, &CCalculatorDlg::OnBnClickedButtonCode)
	ON_BN_CLICKED(IDC_BUTTON_NAME, &CCalculatorDlg::OnBnClickedButtonName)
	ON_BN_CLICKED(IDC_BUTTON_LIFE, &CCalculatorDlg::OnBnClickedButtonLife)
	ON_BN_CLICKED(IDC_BUTTON_ANCIENT, &CCalculatorDlg::OnBnClickedButtonAncient)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
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

	CFont font;
	font.CreatePointFont(500, _T("黑体"),NULL);
	GetDlgItem(IDC_BUTTON_PRIM)->SetFont(&font);
	GetDlgItem(IDC_BUTTON_HIGH)->SetFont(&font);
	GetDlgItem(IDC_BUTTON_CTRL)->SetFont(&font);
	GetDlgItem(IDC_BUTTON_LIFE)->SetFont(&font);
	GetDlgItem(IDC_BUTTON_NAME)->SetFont(&font);
	GetDlgItem(IDC_BUTTON_CODE)->SetFont(&font);
	GetDlgItem(IDC_BUTTON_ANCIENT)->SetFont(&font);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
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
		dc.FillSolidRect(rect, RGB(241, 184, 228));

	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CCalculatorDlg::OnBnClickedButtonPrim()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(NULL, L"open", L"E:\\课程文档及作业\\软件工程实践\\两人项目\\Calculator\\基础计算器\\Debug\\dialog_based.exe", NULL, NULL, SW_SHOWNORMAL);
}


void CCalculatorDlg::OnBnClickedButtonHigh()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(NULL, L"open", L"E:\\课程文档及作业\\软件工程实践\\两人项目\\Calculator\\科学计算器\\Release\\dialog_based.exe", NULL, NULL, SW_SHOWNORMAL);
}


void CCalculatorDlg::OnBnClickedButtonCtrl()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(NULL, L"open", L"E:\\课程文档及作业\\软件工程实践\\两人项目\\Calculator\\Ctrltest\\Ctrltest\\Debug\\Ctrltest.exe", NULL, NULL, SW_SHOWNORMAL);
}


void CCalculatorDlg::OnBnClickedButtonCode()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(NULL, L"open", L"E:\\课程文档及作业\\软件工程实践\\两人项目\\Calculator\\进制转换\\进制转换\\Debug\\进制转换.exe", NULL, NULL, SW_SHOWNORMAL);
}



void CCalculatorDlg::OnBnClickedButtonName()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(NULL, L"open", L"E:\\课程文档及作业\\软件工程实践\\两人项目\\Calculator\\LuckyDraw\\Debug\\LuckyDraw.exe", NULL, NULL, SW_SHOWNORMAL);
}




void CCalculatorDlg::OnBnClickedButtonLife()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(NULL, L"open", L"E:\\课程文档及作业\\软件工程实践\\两人项目\\Calculator\\Life\\Debug\\Life.exe", NULL, NULL, SW_SHOWNORMAL);
}



void CCalculatorDlg::OnBnClickedButtonAncient()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(NULL, L"open", L"E:\\课程文档及作业\\软件工程实践\\两人项目\\Calculator\\Ancient\\Debug\\Ancient.exe", NULL, NULL, SW_SHOWNORMAL);
}
