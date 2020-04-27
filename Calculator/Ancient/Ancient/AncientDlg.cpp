
// AncientDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Ancient.h"
#include "AncientDlg.h"
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


// CAncientDlg 对话框



CAncientDlg::CAncientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ANCIENT_DIALOG, pParent)
	, m_inleng(0)
	, m_outleng(0)
	, m_invo(0)
	, m_outvo(0)
	, m_inwe(0)
	, m_outwe(0)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAncientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO_QIN, m_qin);
	DDX_Control(pDX, IDC_RADIO_WHAN, m_whan);
	DDX_Control(pDX, IDC_RADIO_EHAN, m_ehan);
	DDX_Control(pDX, IDC_RADIO_SUI, m_sui);
	DDX_Control(pDX, IDC_RADIO_TANG, m_tang);
	DDX_Control(pDX, IDC_RADIO_SONG, m_song);
	DDX_Control(pDX, IDC_RADIO_YUAN, m_yuan);
	DDX_Control(pDX, IDC_RADIO_MING, m_ming);
	DDX_Control(pDX, IDC_RADIO_QING, m_qing);
	DDX_Control(pDX, IDC_RADIO_JIN, m_jin);
	DDX_Text(pDX, IDC_EDIT_INLEN, m_inleng);
	DDX_Text(pDX, IDC_EDIT_OUTLEN, m_outleng);
	DDX_Text(pDX, IDC_EDIT_INVO, m_invo);
	DDX_Text(pDX, IDC_EDIT_OUTVO, m_outvo);
	DDX_Text(pDX, IDC_EDIT_INWE, m_inwe);
	DDX_Text(pDX, IDC_EDIT_OUTWE, m_outwe);
	DDX_Control(pDX, IDC_TIPS, m_tips);
}

BEGIN_MESSAGE_MAP(CAncientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAncientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAncientDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAncientDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_RADIO_QIN, &CAncientDlg::OnBnClickedRadioQin)
	ON_BN_CLICKED(IDC_RADIO_WHAN, &CAncientDlg::OnBnClickedRadioWhan)
	ON_BN_CLICKED(IDC_RADIO_EHAN, &CAncientDlg::OnBnClickedRadioEhan)
	ON_BN_CLICKED(IDC_RADIO_SUI, &CAncientDlg::OnBnClickedRadioSui)
	ON_BN_CLICKED(IDC_RADIO_TANG, &CAncientDlg::OnBnClickedRadioTang)
	ON_BN_CLICKED(IDC_RADIO_SONG, &CAncientDlg::OnBnClickedRadioSong)
	ON_BN_CLICKED(IDC_RADIO_YUAN, &CAncientDlg::OnBnClickedRadioYuan)
	ON_BN_CLICKED(IDC_RADIO_MING, &CAncientDlg::OnBnClickedRadioMing)
	ON_BN_CLICKED(IDC_RADIO_QING, &CAncientDlg::OnBnClickedRadioQing)
	ON_BN_CLICKED(IDC_RADIO_JIN, &CAncientDlg::OnBnClickedRadioJin)
	ON_BN_CLICKED(IDC_BUTTONClear1, &CAncientDlg::OnBnClickedButtonclear1)
	ON_BN_CLICKED(IDC_BUTTONClear2, &CAncientDlg::OnBnClickedButtonclear2)
	ON_BN_CLICKED(IDC_BUTTONClear3, &CAncientDlg::OnBnClickedButtonclear3)
END_MESSAGE_MAP()


// CAncientDlg 消息处理程序

BOOL CAncientDlg::OnInitDialog()
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

	m_qin.SetCheck(1);//默认情况下选中秦朝
	m_whan.SetCheck(0);
	m_ehan.SetCheck(0);
	m_sui.SetCheck(0);
	m_tang.SetCheck(0);
	m_song.SetCheck(0);
	m_yuan.SetCheck(0);
	m_ming.SetCheck(0);
	m_qing.SetCheck(0);
	m_jin.SetCheck(0);

	//设置初始值
	m_tips.SetWindowText(_T("秦朝:商鞅变法前，秦国各地度量衡不统一，为了保证国家的付税收入，商鞅制造了标准的度量衡器，如今传世之“商鞅量”，上有“爰积十六尊五分尊之一为升”。"));


	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAncientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAncientDlg::OnPaint()
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
		dc.FillSolidRect(rect, RGB(99, 194, 162));
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAncientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);

}



void CAncientDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	double s = 0;
	if (m_qin.GetCheck())
	{
		s = 23.1;
	}
	if (m_whan.GetCheck()) 
	{
		s = 23.2;
	}
	if (m_ehan.GetCheck())
	{
		s = 23.4;
	}
	if (m_sui.GetCheck())
	{
		s = 29.4;
	}
	if (m_tang.GetCheck())
	{
		s = 29.4;
	}
	if (m_song.GetCheck())
	{
		s = 30.7;
	}
	if (m_yuan.GetCheck())
	{
		s = 31.6;
	}
	if (m_ming.GetCheck())
	{
		s = 32;
	}
	if (m_qing.GetCheck())
	{
		s = 32;
	}
	if (m_jin.GetCheck())
	{
		s = 33.3;
	}
	m_outleng = s * m_inleng;

	UpdateData(0);
}


void CAncientDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	double s = 0;
	if (m_qin.GetCheck())
	{
		s = 215;
	}
	if (m_whan.GetCheck())
	{
		s = 204;
	}
	if (m_ehan.GetCheck())
	{
		s = 204;
	}
	if (m_sui.GetCheck())
	{
		s = 618.3;
	}
	if (m_tang.GetCheck())
	{
		s = 623;
	}
	if (m_song.GetCheck())
	{
		s = 680;
	}
	if (m_yuan.GetCheck())
	{
		s = 917.4;
	}
	if (m_ming.GetCheck())
	{
		s = 1023;
	}
	if (m_qing.GetCheck())
	{
		s = 1043;
	}
	if (m_jin.GetCheck())
	{
		s = 1000;
	}
	m_outvo = s * m_invo;

	UpdateData(0);
}


void CAncientDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	double s = 0;
	if (m_qin.GetCheck())
	{
		s = 250;
	}
	if (m_whan.GetCheck())
	{
		s = 268.8;
	}
	if (m_ehan.GetCheck())
	{
		s = 268.8;
	}
	if (m_sui.GetCheck())
	{
		s = 993.9;
	}
	if (m_tang.GetCheck())
	{
		s = 640;
	}
	if (m_song.GetCheck())
	{
		s = 640;
	}
	if (m_yuan.GetCheck())
	{
		s = 637.5;
	}
	if (m_ming.GetCheck())
	{
		s = 584;
	}
	if (m_qing.GetCheck())
	{
		s = 579.2;
	}
	if (m_jin.GetCheck())
	{
		s = 500;
	}
	m_outwe = s * m_inwe;

	UpdateData(0);
}


void CAncientDlg::OnBnClickedRadioQin()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);

	m_tips.SetWindowText(_T("商鞅变法前，秦国各地度量衡不统一，为了保证国家的付税收入，商鞅制造了标准的度量衡器，如今传世之“商鞅量”，上有“爰积十六尊五分尊之一为升”。"));

	UpdateData(0);
}


void CAncientDlg::OnBnClickedRadioWhan()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);

	m_tips.SetWindowText(_T("汉代度量衡是汉初各项制度和治国策略，虽然在某些方面有所发展，实际上仍是秦制的延续。史称“汉承秦制”，度量衡专著，最早见于《汉书•律历志》，它既是汉代度量衡的实录，又是对秦以来度量衡的补记。"));

	UpdateData(0);
}


void CAncientDlg::OnBnClickedRadioEhan()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);

	m_tips.SetWindowText(_T("汉朝既是中国度量衡发展成熟的阶段，又是一个承上启下的关键时期。《汉书•律历志》中度量衡各篇，十分简明、全面地将度量衡有关理论、制度、行政管理职责做了论述。"));

	UpdateData(0);
}




void CAncientDlg::OnBnClickedRadioSui()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);

	m_tips.SetWindowText(_T("隋朝建国后，度量衡沿用北周之制。《隋书•律历志》记：“后周市尺......开皇初著令以为官尺，百司用之，终于仁寿。大业中，人间或私用之。”"));

	UpdateData(0);
}



void CAncientDlg::OnBnClickedRadioTang()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);

	m_tips.SetWindowText(_T("《新唐书》卷54《食货志》四记，“武德四年，铸‘开元通宝’，径八分，重二株四参，积十钱重一两。”“参”应作叄，车钱合二十四铢，重一两。实测西安鱼化寨新近出土之“开元通宝》”钱。"));

	UpdateData(0);
	
}


void CAncientDlg::OnBnClickedRadioSong()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);

	m_tips.SetWindowText(_T("据《宋史·律历志》记载：“度量权衡，皆太府掌造，以给内外官司及民间之用。凡遇改元，即差变法，各以年号印而识之。其印有方印、长印、八角印，明制度而防伪滥也。”"));

	UpdateData(0);
}


void CAncientDlg::OnBnClickedRadioYuan()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);

	m_tips.SetWindowText(_T("元立国后，基本上沿用了宋代原有的典章制度。宋代度量衡由国家规定专管商务贸易的太府寺掌管，禁止民间私造。《元典章》中规定：“凡斛斗秤尺，须行使印烙。官降法物。“还规定凡改年号即铸造器具颁至全国”。"));

	UpdateData(0);
}


void CAncientDlg::OnBnClickedRadioMing()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);

	m_tips.SetWindowText(_T("《会典》中记载：“洪武元年，令兵马司并管市司，二日一次校勘街市斛、斗、秤、尺，并依时估定其物价。”《明史·职官》也记载：“凡度量权衡，谨其校勘而颁之，悬式于市而罪其不中度者。”"));

	UpdateData(0);
}


void CAncientDlg::OnBnClickedRadioQing()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);

	m_tips.SetWindowText(_T("据《大清会典》记载：清代的尺共有两种，一种是横黍尺，另一种是纵黍尺，横黍尺是以十个黑黍的横广算作一寸，长短和夏尺相同，所以又叫古尺或律尺；纵黍尺是以十个黑色的纵长算作一寸，工部制造皆以此为标准，所以又叫营造尺。”"));

	UpdateData(0);
}


void CAncientDlg::OnBnClickedRadioJin()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);

	m_tips.SetWindowText(_T("1959 年, 国务院发布《关于统一计量制度的命令》, 确定米制为中国基本计量制度。国务院的命令对尽早结束我国计量制度的混乱局面起了重要作用。该命令的颁布, 标志着我国计量事业实现了由传统的度量衡向近代计量的转变。"));

	UpdateData(0);
}






void CAncientDlg::OnBnClickedButtonclear1()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT_INLEN, _T(""));
}


void CAncientDlg::OnBnClickedButtonclear2()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT_INVO, _T(""));
}


void CAncientDlg::OnBnClickedButtonclear3()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT_INWE, _T(""));
}
