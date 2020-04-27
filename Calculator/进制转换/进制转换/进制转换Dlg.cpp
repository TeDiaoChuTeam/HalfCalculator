// 进制转换Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "进制转换.h"
#include "进制转换Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define NSYS_STR 6

char	redix_code[]="0123456789AaBbCcDdEeFf";
char	nsys_str[][21]={"二进制","五进制","八进制","十进制","十二进制","十六进制"};
char	nsys[]={2,5,8,10,14,22};

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
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_source = _T("");
	m_object = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_EDIT_SOURCE, mc_source);
	DDX_Control(pDX, IDC_COMBO_OBJECT, m_box_object);
	DDX_Control(pDX, IDC_COMBO_SOURCE, m_box_source);
	DDX_Text(pDX, IDC_EDIT_SOURCE, m_source);
	DDV_MaxChars(pDX, m_source, 22);
	DDX_Text(pDX, IDC_STATIC_OBJECT, m_object);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_SOURCE, OnChangeEditSource)
	ON_CBN_SELCHANGE(IDC_COMBO_OBJECT, OnSelchangeComboObject)
	ON_CBN_SELCHANGE(IDC_COMBO_SOURCE, OnSelchangeComboSource)
	//}}AFX_MSG_MAP
	//ON_BN_CLICKED(IDCANCEL, &CMyDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTONclear, &CMyDlg::OnBnClickedButtonclear)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
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
	
	// TODO: Add extra initialization here
	for(int i=0;i<NSYS_STR;i++)
	{
		m_box_source.AddString(nsys_str[i]);
		m_box_object.AddString(nsys_str[i]);
	}
	m_box_source.SetCurSel(3);		//设置为十进制
	m_box_object.SetCurSel(2);		//设置为八进制

	m_linkstack.Init();				//栈初始化
	m_sequeue.Init();				//队初始化
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyDlg::OnPaint() 
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
		dc.FillSolidRect(rect, RGB(255, 174, 171));

	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CMyDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	CString str;
	if(pMsg->message==WM_CHAR && pMsg->hwnd==this->mc_source.m_hWnd)
	{
		char num=(TCHAR)pMsg->wParam;
		if(!(CheckNummer(num) || num=='.' || num==VK_BACK))
			return true;
		if(num=='.')
		{
			mc_source.GetWindowText(str);			//得到当前文本
			if(str.Find(".",0)>=0)					//测试串中是否已有"."字符
				return true;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

bool CMyDlg::CheckNummer(char ch)
{//基数范围合法性检测，返回真合法

	bool	v=false;
	int len=nsys[m_box_source.GetCurSel()];		//按进制得到基数范围

	for(int i=0;i<len;i++)
	{
		if(redix_code[i]==ch)
		{
			v=true;
			break;
		}
	}
	return v;
}


int CMyDlg::x_GetRedix(int num)
{
	int	n;
	switch(num)
	{
	case 0:
		n=2;
		break;
	case 1:
		n=5;
		break;
	case 2:
		n=8;
		break;
	case 3:
		n=10;
		break;
	case 4:
		n=12;
		break;
	case 5:
		n=16;
		break;
	}
	return n;
}

void CMyDlg::OnChangeEditSource() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	int n,sredix,oredix;
	CString str;
	this->UpdateData();
	n=m_source.Find(".",0);

	sredix=x_GetRedix(m_box_source.GetCurSel());
	oredix=x_GetRedix(m_box_object.GetCurSel());
	if(n<0)
	{
		m_linkstack.Change(m_object,x_StringToInt(&m_source,sredix),oredix);
	}
	else
	{
		str=m_source.Right(m_source.GetLength()-n-1);
		m_sequeue.Change(str,x_StringToDouble(&str,sredix),oredix);
		if(n==0)
		{
			m_object="0."+str;
		}
		if(n>0)
		{
			m_linkstack.Change(m_object,x_StringToInt(&m_source.Left(n),sredix),oredix);
			m_object+="."+str;
		}
	}
	if(!m_source.GetLength())
		m_object="";
	this->UpdateData(false);	
}

void CMyDlg::OnOK()
{

}

int CMyDlg::x_StringToInt(CString *str, int redix)
{
	int	val,i,len;
	char num;
	len=str->GetLength();
	for(val=i=0;i<len;i++)
	{
		num=str->GetAt(i);
		if(num>'9')
		{
			num&=0x5f;
			num-=7;
		}
		val=val*redix+num-'0';
	}
	return val;
}

double CMyDlg::x_StringToDouble(CString *str, int redix)
{
	double val;
	int	i,len;
	char num;
	len=str->GetLength();
	for(val=0,i=len-1;i>=0;i--)
	{
		num=str->GetAt(i);
		if(num>'9')
		{
			num&=0x5f;
			num-=7;
		}
		val=(val+num-'0')/redix;
	}
	return val;
}

void CMyDlg::OnSelchangeComboObject() 
{
	// TODO: Add your control notification handler code here
	m_source="";
	m_object="";
	this->UpdateData(false);
}

void CMyDlg::OnSelchangeComboSource() 
{
	// TODO: Add your control notification handler code here
	m_source="";
	m_object="";
	this->UpdateData(false);
}

/*
void CMyDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}
*/

void CMyDlg::OnBnClickedButtonclear()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT_SOURCE, _T(""));
}
