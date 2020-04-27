// CtrltestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ctrltest.h"
#include "CtrltestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCtrltestDlg dialog

CCtrltestDlg::CCtrltestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCtrltestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCtrltestDlg)
	m_dbNumber = 0.0;
	m_result = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCtrltestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCtrltestDlg)
	DDX_Control(pDX, IDC_STATIC2, m_ref);
	DDX_Control(pDX, IDC_RADIO_WEIGHT, m_weight);
	DDX_Control(pDX, IDC_RADIO_TIME, m_time);
	DDX_Control(pDX, IDC_RADIO_LENGTH, m_length);
	DDX_Control(pDX, IDC_LIST_UNIT2, m_ltUnit2);
	DDX_Control(pDX, IDC_COMBO_UNIT1, m_cbUnit1);
	DDX_Text(pDX, IDC_EDIT1, m_dbNumber);
	DDX_Text(pDX, IDC_EDIT2, m_result);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_RADIO_MEMORY, m_memory);
	DDX_Control(pDX, IDC_RADIO_AREA, m_area);
}

BEGIN_MESSAGE_MAP(CCtrltestDlg, CDialog)
	//{{AFX_MSG_MAP(CCtrltestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_UNIT1, OnSelchangeComboUnit1)
	ON_BN_CLICKED(IDC_equal, Onequal)
	ON_LBN_SELCHANGE(IDC_LIST_UNIT2, OnSelchangeListUnit2)
	ON_BN_CLICKED(IDC_RADIO_LENGTH, OnRadioLength)
	ON_BN_CLICKED(IDC_RADIO_TIME, OnRadioTime)
	ON_BN_CLICKED(IDC_RADIO_WEIGHT, OnRadioWeight)
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDIT1, &CCtrltestDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_RADIO_MEMORY, &CCtrltestDlg::OnBnClickedRadioMemory)
	ON_BN_CLICKED(IDC_RADIO_AREA, &CCtrltestDlg::OnBnClickedRadioArea)
	ON_BN_CLICKED(IDC_BUTTONclear, &CCtrltestDlg::OnBnClickedButtonclear)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCtrltestDlg message handlers

BOOL CCtrltestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	m_length.SetCheck(1);//默认情况下选中长度单位
	m_weight.SetCheck(0);
	m_time.SetCheck(0);
	m_area.SetCheck(0);
	m_memory.SetCheck(0);
	
	//初始化待转换单位的组合框


	m_cbUnit1.AddString("米");
	m_cbUnit1.AddString("分米");
	m_cbUnit1.AddString("厘米");
	m_cbUnit1.AddString("毫米");
	m_cbUnit1.SetCurSel(0);//初始化单位组合框，使组合框当前选择为第0个—“米”


	//初始化待转换单位的列表框
	m_ltUnit2.AddString("米");
	m_ltUnit2.AddString("分米");
	m_ltUnit2.AddString("厘米");
	m_ltUnit2.AddString("毫米");
	m_ltUnit2.SetCurSel(0);//初始化单位列表框，使组合框当前选择为第0个—“米”


	//设置初始值
	m_dbNumber=1.0;
	m_result="1.0米";


	//初始化转化规则
	m_ref.SetWindowText("1米=1米");
	UpdateData(0);

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCtrltestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCtrltestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialog::OnPaint();
		CPaintDC dc(this);
		CRect rect;
		GetClientRect(&rect);
		dc.FillSolidRect(rect,RGB(237,82,86));
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCtrltestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCtrltestDlg::OnSelchangeComboUnit1() 
{
	// TODO: 在此添加控件通知处理程序代码
	double s=0;
	if (m_length.GetCheck())//检测如果长度的单位被选中
	{	
		double t=1.0;
		for (int i=0;i<abs(m_cbUnit1.GetCurSel()-m_ltUnit2.GetCurSel());i++)
		{
			t*=10;//设置米制的进度为10；
		}
		s=t;
	}
	if (m_time.GetCheck())//和上面的类似，如果是时间被选中则进度为60；
	{	
		double t=1.0;
		for (int i=0;i<abs(m_cbUnit1.GetCurSel()-m_ltUnit2.GetCurSel());i++)
		{	
			t*=60;
		}
		s=t;
	}
	if (m_weight.GetCheck())
	{
		double t=1.0;
		for (int i=0;i<abs(m_cbUnit1.GetCurSel()-m_ltUnit2.GetCurSel());i++)
		{
			t*=1000;
		}
		s=t;
	}
	if (m_memory.GetCheck())
	{
		double t = 1.0;
		for (int i = 0; i < abs(m_cbUnit1.GetCurSel() - m_ltUnit2.GetCurSel()); i++)
		{
			t *= 1024;
		}
		s = t;
	}
	if (m_area.GetCheck())
	{
		double t = 1.0;
		for (int i = 0; i < abs(m_cbUnit1.GetCurSel() - m_ltUnit2.GetCurSel()); i++)
		{
			t *= 100;
		}
		s = t;
	}
	if (m_cbUnit1.GetCurSel()>m_ltUnit2.GetCurSel())
	{
		
		s=1.0/s;
	}
	CString u1,u2,r;
	m_cbUnit1.GetLBText(m_cbUnit1.GetCurSel(),u1);//获取转换的单位，放到u1中
	m_ltUnit2.GetText(m_ltUnit2.GetCurSel(),u2);//获取转换为的单位，放到u2中
	r.Format("%f%s=%f%s",1.0,u1,s,u2);//设置字符转换规则；
	m_ref.SetWindowText(r);//显示转换规则在静态文本中
	
}

void CCtrltestDlg::Onequal() 
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	double s=0;
	if (m_length.GetCheck())//检测如果长度的单位被选中
	{	
		double t=1.0;
		for (int i=0;i<abs(m_cbUnit1.GetCurSel()-m_ltUnit2.GetCurSel());i++)
		{
			t*=10;//设置米制的进度为10；
		}
		s=t;
	}
	if (m_time.GetCheck())//和上面的类似，如果是时间被选中则进度为60；
	{	
		double t=1.0;
		for (int i=0;i<abs(m_cbUnit1.GetCurSel()-m_ltUnit2.GetCurSel());i++)
		{	
			t*=60;
		}
		s=t;
	}
	if (m_weight.GetCheck())
	{
		double t=1.0;
		for (int i=0;i<abs(m_cbUnit1.GetCurSel()-m_ltUnit2.GetCurSel());i++)
		{
			t*=1000;
		}
		s=t;
	}
	if (m_memory.GetCheck())
	{
		double t = 1.0;
		for (int i = 0; i < abs(m_cbUnit1.GetCurSel() - m_ltUnit2.GetCurSel()); i++)
		{
			t *= 1024;
		}
		s = t;
	}
	if (m_area.GetCheck())
	{
		double t = 1.0;
		for (int i = 0; i < abs(m_cbUnit1.GetCurSel() - m_ltUnit2.GetCurSel()); i++)
		{
			t *= 100;
		}
		s = t;
	}
	if (m_cbUnit1.GetCurSel()>m_ltUnit2.GetCurSel())
	{
		
		s=1.0/s;
	}

	CString temp;
	m_ltUnit2.GetText(m_ltUnit2.GetCurSel(),temp);
	m_result.Format("%f",m_dbNumber*s);
	m_result+=temp;
	UpdateData(0);
}

void CCtrltestDlg::OnSelchangeListUnit2() 
{
	// TODO: 在此添加控件通知处理程序代码

	double s=0;
	if (m_length.GetCheck())//检测如果长度的单位被选中
	{	
		double t=1.0;
		for (int i=0;i<abs(m_cbUnit1.GetCurSel()-m_ltUnit2.GetCurSel());i++)
		{
			t*=10;//设置米制的进度为10；
		}
		s=t;
	}
	 if (m_time.GetCheck())//和上面的类似，如果是时间被选中则进度为60；
	{	
		double t=1.0;
		for (int i=0;i<abs(m_cbUnit1.GetCurSel()-m_ltUnit2.GetCurSel());i++)
		{	
			t*=60;
		}
			s=t;
	}
	 if (m_weight.GetCheck())
	{
		double t=1.0;
		for (int i=0;i<abs(m_cbUnit1.GetCurSel()-m_ltUnit2.GetCurSel());i++)
		{
			t*=1000;
		}
			s=t;
	}
	 if (m_memory.GetCheck())
	 {
		 double t = 1.0;
		 for (int i = 0; i < abs(m_cbUnit1.GetCurSel() - m_ltUnit2.GetCurSel()); i++)
		 {
			 t*=1024;
		 }
		     s=t;
	 }
	 if (m_memory.GetCheck())
	 {
		 double t = 1.0;
		 for (int i = 0; i < abs(m_cbUnit1.GetCurSel() - m_ltUnit2.GetCurSel()); i++)
		 {
			 t *= 100;
		 }
		 s = t;
	 }
	if (m_cbUnit1.GetCurSel()>m_ltUnit2.GetCurSel())
	{

		s=1.0/s;
	}
	CString u1,u2,r;
	m_cbUnit1.GetLBText(m_cbUnit1.GetCurSel(),u1);//获取转换的单位，放到u1中
	m_ltUnit2.GetText(m_ltUnit2.GetCurSel(),u2);//获取转换为的单位，放到u2中
	r.Format("%f%s=%f%s",1.0,u1,s,u2);//设置字符转换规则；
	m_ref.SetWindowText(r);//显示转换规则在静态文本中
}

void CCtrltestDlg::OnRadioLength() 
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	m_ltUnit2.ResetContent();//待转换列表框全部清零，重新写入
	m_cbUnit1.ResetContent();//待转换组合框全部清零，重新写入
	//写入组合框数据
	m_cbUnit1.AddString("米");
	m_cbUnit1.AddString("分米");
	m_cbUnit1.AddString("厘米");
	m_cbUnit1.AddString("毫米");
	m_cbUnit1.SetCurSel(0);
	

	//列表框也是类似
	m_ltUnit2.AddString("米");
	m_ltUnit2.AddString("分米");
	m_ltUnit2.AddString("厘米");
	m_ltUnit2.AddString("毫米");
	m_ltUnit2.SetCurSel(0);//初始化单位列表框，使组合框当前选择为第0个—“米”
	m_ref.SetWindowText("1米=1米");
	UpdateData(0);





}

void CCtrltestDlg::OnRadioTime() 
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	m_ltUnit2.ResetContent();//待转换组合框全部清零，重新写入
		m_cbUnit1.ResetContent();
	//写入组合框数据
	m_cbUnit1.AddString("时");
	m_cbUnit1.AddString("分");
	m_cbUnit1.AddString("秒");

	m_cbUnit1.SetCurSel(0);
	
	
	//列表框也是类似
	m_ltUnit2.AddString("时");
	m_ltUnit2.AddString("分");
	m_ltUnit2.AddString("秒");

	m_ltUnit2.SetCurSel(0);//初始化单位列表框，使组合框当前选择为第0个—“米”
	m_ref.SetWindowText("1时=1时");
	UpdateData(0);

}

void CCtrltestDlg::OnRadioWeight() 
{

	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	m_ltUnit2.ResetContent();//待转换组合框全部清零，重新写入
	m_cbUnit1.ResetContent();
	//写入组合框数据
	m_cbUnit1.AddString("千克");
	m_cbUnit1.AddString("克");
	m_cbUnit1.AddString("毫克");
	
	m_cbUnit1.SetCurSel(0);
	
	
	//列表框也是类似
	m_ltUnit2.AddString("千克");
	m_ltUnit2.AddString("克");
	m_ltUnit2.AddString("毫克");
	
	m_ltUnit2.SetCurSel(0);//初始化单位列表框，使组合框当前选择为第0个—“米”
	m_ref.SetWindowText("1千克=1千克");
	UpdateData(0);


	
}


void CCtrltestDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCtrltestDlg::OnBnClickedRadioMemory()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	m_ltUnit2.ResetContent();//待转换组合框全部清零，重新写入
	m_cbUnit1.ResetContent();
	//写入组合框数据
	m_cbUnit1.AddString("B");
	m_cbUnit1.AddString("KB");
	m_cbUnit1.AddString("MB");
	m_cbUnit1.AddString("GB");
	m_cbUnit1.AddString("TB");

	m_cbUnit1.SetCurSel(0);


	//列表框也是类似
	m_ltUnit2.AddString("B");
	m_ltUnit2.AddString("KB");
	m_ltUnit2.AddString("MB");
	m_ltUnit2.AddString("GB");
	m_ltUnit2.AddString("TB");

	m_ltUnit2.SetCurSel(0);//初始化单位列表框，使组合框当前选择为第0个—“B”
	m_ref.SetWindowText("1B=1B");
	UpdateData(0);

}


void CCtrltestDlg::OnBnClickedRadioArea()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	m_ltUnit2.ResetContent();//待转换组合框全部清零，重新写入
	m_cbUnit1.ResetContent();
	//写入组合框数据
	m_cbUnit1.AddString("平方毫米");
	m_cbUnit1.AddString("平方厘米");
	m_cbUnit1.AddString("平方分米");
	m_cbUnit1.AddString("平方米");

	m_cbUnit1.SetCurSel(0);


	//列表框也是类似
	m_ltUnit2.AddString("平方毫米");
	m_ltUnit2.AddString("平方厘米");
	m_ltUnit2.AddString("平方分米");
	m_ltUnit2.AddString("平方米");

	m_ltUnit2.SetCurSel(0);//初始化单位列表框，使组合框当前选择为第0个—“B”
	m_ref.SetWindowText("1平方毫米=1平方毫米");
	UpdateData(0);
}


void CCtrltestDlg::OnBnClickedButtonclear()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT1, _T(""));
	SetDlgItemText(IDC_EDIT2, _T(""));
}
