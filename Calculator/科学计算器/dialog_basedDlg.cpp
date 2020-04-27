// dialog_basedDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dialog_based.h"
#include "dialog_basedDlg.h"
#include <math.h>
#include "Afxwin.h"
#include "tahir.h"
#include "iso646.h"

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
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
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
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_basedDlg dialog

CDialog_basedDlg::CDialog_basedDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_basedDlg::IDD, pParent)
{
	m_op1 = 0.0;
	m_op2 = 0.0;
	m_result = 0.0;
	m_operation =0;
	m_m=0;
	i=s=0;
	p=0;
	r=0;
	st1=pflag=st2=0;
	//{{AFX_DATA_INIT(CDialog_basedDlg)
	m_inv = FALSE;
	m_hp = FALSE;
	m_num = 0.0;
	m_sd = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialog_basedDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_basedDlg)
	DDX_Control(pDX, IDC_EDIT1, m_control_e);
	DDX_Check(pDX, IDC_inv, m_inv);
	DDX_Check(pDX, IDC_Hp, m_hp);
	DDX_Text(pDX, IDC_EDIT1, m_num);
	//DDX_Text(pDX, IDC_sd, m_sd);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDialog_basedDlg, CDialog)
	//{{AFX_MSG_MAP(CDialog_basedDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_SUBTRACT, OnSubtract)
	ON_BN_CLICKED(IDC_EQUAL, OnEqual)
	ON_BN_CLICKED(IDC_sin, Onsin)
	ON_BN_CLICKED(IDC_cos, Oncos)
	ON_BN_CLICKED(IDC_tan, Ontan)
	ON_BN_CLICKED(IDC_log, Onlog)
	ON_BN_CLICKED(IDC_ln, Onln)
	ON_BN_CLICKED(IDC_inv, Oninv)
	ON_BN_CLICKED(IDC_Hp, OnHp)
	ON_BN_CLICKED(IDC_devide, Ondevide)
	ON_BN_CLICKED(IDC_clear, Onclear)
	ON_BN_CLICKED(IDC_mul, Onmul)
	ON_BN_CLICKED(IDC_factoriel, Onfactoriel)
	ON_BN_CLICKED(IDC_pow, Onpow)
	ON_BN_CLICKED(IDC_x2, Onx2)
	ON_BN_CLICKED(IDC_x3, Onx3)
	ON_BN_CLICKED(IDC_pi, Onpi)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_b1, Onb1)
	ON_BN_CLICKED(IDC_b2, Onb2)
	ON_BN_CLICKED(IDC_b3, Onb3)
	ON_BN_CLICKED(IDC_b4, Onb4)
	ON_BN_CLICKED(IDC_b5, Onb5)
	ON_BN_CLICKED(IDC_b6, Onb6)
	ON_BN_CLICKED(IDC_b7, Onb7)
	ON_BN_CLICKED(IDC_b8, Onb8)
	ON_BN_CLICKED(IDC_b9, Onb9)
	ON_BN_CLICKED(IDC_b10, Onb10)
	ON_BN_CLICKED(IDC_bp, Onbp)
	ON_BN_CLICKED(IDC_OR, OnOr)
	ON_BN_CLICKED(IDC_1x, On1x)
	ON_BN_CLICKED(IDC_bp2, Onbp2)
	ON_BN_CLICKED(IDC_data, Ondata)
	ON_BN_CLICKED(IDC_sum, Onsum)
	ON_BN_CLICKED(IDC_s, Ons)
	ON_BN_CLICKED(IDC_root, Onroot)
	ON_BN_CLICKED(IDC_root2, Onroot2)
	ON_BN_CLICKED(IDC_bsp, Onbsp)
	ON_BN_CLICKED(IDC_And, OnAnd)
	ON_BN_CLICKED(IDC_XOR, OnXor)
	ON_BN_CLICKED(IDC_MOd, OnMOd)
	ON_WM_CHAR()
	ON_WM_CLOSE()
	ON_WM_KEYDOWN()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_CL, OnClos)
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_basedDlg message handlers

BOOL CDialog_basedDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDialog_basedDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDialog_basedDlg::OnPaint() 
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
		CPaintDC dc(this); 
		CRect ClientRect;
		GetClientRect(ClientRect);
		CBrush bkBrush(RGB(247,145,79));
		dc.FillRect(ClientRect,&bkBrush);
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDialog_basedDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDialog_basedDlg::OnAdd() //求和
{
	if(st2==0)
	{
	UpdateData(TRUE);
	m_op1 = m_num;
	m_operation = 1;
    m_control_e.SetFocus();
    st1=pflag=0;
	st2=1;
	}
	else
	{
	UpdateData(TRUE);
	m_operation = 1;
    m_control_e.SetFocus();
	Equal2();
	}

}

void CDialog_basedDlg::OnSubtract()//求差
{
	if(st2==0)
	{
	UpdateData(TRUE);
	m_op1 = m_num;
	m_operation = 2;
    m_control_e.SetFocus();
    st1=pflag=0;
	st2=1;
	}
	else
	{
	UpdateData(TRUE);
	m_operation = 2;
    m_control_e.SetFocus();
	Equal2();
	}
}

void CDialog_basedDlg::OnEqual()//根据操作符，进行运算并显示运算结果
{
	if(st2==0)
	{
	  UpdateData(TRUE);
      m_op2 = m_num;
	}
	else
	{
		UpdateData(TRUE);
		m_op2=m_num;
	}
	switch(m_operation)
	{
	case 1:
		m_result = m_op1 + m_op2;
		break;
	case 2:
		m_result = m_op1 - m_op2;
		break;
	case 3:
		m_result = m_op1/m_op2;
		break;
	case 4:
		m_result = m_op1*m_op2;
		break;
	case 5:
		m_result = pow(m_op1,m_op2);
		break;
	case 6:
		m_result = (m_op1||m_op2);
		break;
	case 7:
		{
			m_op2=1/m_op2;
		m_result = pow(m_op1,m_op2);
		}
		break;
	case 8:
		{
		
		m_result =  int(m_op1) bitor int(m_op2) ;
		 break;
		}
		break;
	case 9:
		{
		
		m_result =  int(m_op1)  bitand int(m_op2) ;
		 break;
		}
	case 10:
	m_result =  int(m_op1)  xor int(m_op2) ;
		break;
	case 11:
		m_result=int(m_op1) % int(m_op2) ;
		break;
	default :	;
	}
	
	m_num = m_result;
	st1=0;
    m_op1=m_result;
    st2=0;
	pflag=0;
	m_control_e.SetFocus();
	UpdateData(FALSE);
}
void CDialog_basedDlg::Ondevide()//除运算 
{
    UpdateData(TRUE);
	m_op1 = m_num;
	m_operation = 3;
	m_control_e.SetFocus();
    st1=0;
    st2=1;
	pflag=0;
}
void CDialog_basedDlg::Onsin() 
{
	UpdateData(TRUE);
	m_op1 = m_num;
	
	if(m_hp&&1)
          m_num = sinh(m_op1);//双曲三角，m_hp为标志
	else if(m_inv&&1)
	{
	  m_num = asin(m_op1);//反三角，m_inv为标志
	  m_num=m_num*360/(2*3.1415926535897932384626433832795);
	}
	else
	{
	m_op1=m_op1*(2*3.1415926535897932384626433832795/360);
    m_num = sin( m_op1 );//三角函数
	}
	UpdateData(FALSE);
	m_control_e.SetFocus();
    st1=0;
    st2=0;
	pflag=0;
}

void CDialog_basedDlg::Oncos()//余弦
{
	UpdateData(TRUE);
	m_op1 = m_num;
	m_op1 = m_num;
	if(m_hp) 
        m_num = cosh( m_op1 );
	else if(m_inv)
	{
      m_num = acos( m_op1 );
	  m_num=m_num*360/(2*3.1415926535897932384626433832795);
	}
	else
	{
	m_op1=m_op1*(2*3.1415926535897932384626433832795/360);
    m_num = cos( m_op1 );
	
	}
	UpdateData(FALSE);
	m_control_e.SetFocus();
    st1=0;
    pflag=0;
}

void CDialog_basedDlg::Ontan()//正切 
{
	UpdateData(TRUE);
	m_op1 = m_num;
	m_op1 = m_num;
    if(m_hp)
	  m_num=tanh(m_op1);
	else if(m_inv)
	{
      m_num=atan(m_op1);
	  m_num=m_num*360/(2*3.1415926535897932384626433832795);
	}
	else
	{
	  m_op1=m_op1*(2*3.1415926535897932384626433832795/360);
      m_num=tan( m_op1 );
	}
	UpdateData(FALSE);
	m_control_e.SetFocus();
    st1=0;
    pflag=0;
}

void CDialog_basedDlg::Onlog()//求10对数
{
	UpdateData(TRUE);
	m_op1 = m_num;
	m_num= log10(m_op1);
	UpdateData(FALSE);
	m_control_e.SetFocus();
    st1=0;
   
}

void CDialog_basedDlg::Onln()//求e对数
{
	UpdateData(TRUE);
	m_op1 = m_num;
	if(m_inv)
	   m_num=exp(m_op1);//以e为底x次幂
	else
    m_num=log(m_op1);
	UpdateData(FALSE);
	m_control_e.SetFocus();
    st1=0;
    pflag=0;
	
}

void CDialog_basedDlg::Oninv()//按钮锁定，进行特殊运算,双曲三角
{
	UpdateData(TRUE);
	m_inv=1;
	m_control_e.SetFocus();
    m_control_e.SetSel(0,-1);
}

void CDialog_basedDlg::OnHp() //三角函数自动切换，反三角
{
	UpdateData(TRUE);
	m_hp=1;
}


void CDialog_basedDlg::Onclear()//清屏 
{
	m_op1 = 0.0;
	m_op2 = 0.0;
	m_result = 0.0;
	m_operation =0;
		
	m_num = 0.0;
	m_inv = FALSE;
	m_hp = FALSE;
	UpdateData(FALSE);
	m_control_e.SetFocus();
    st1=st2=0;
    pflag=0;
}

void CDialog_basedDlg::Onmul()//乘运算
{
	if(st2==0)
	{
	UpdateData(TRUE);
	m_op1 = m_num;
	m_operation = 4;
    m_control_e.SetFocus();
    st1=pflag=0;
	st2=1;
	}
	else
	{
	UpdateData(TRUE);
	m_operation = 4;
    m_control_e.SetFocus();
	st1=pflag=0;
	Equal2();
	}

}

void CDialog_basedDlg::Onfactoriel()//阶乘运算
{
	UpdateData(TRUE);
	m_op1 = m_num;
	double tahir=m_op1;
	if(m_op1==0)
		m_num=1;
	else
	{
	   while(tahir>1)
		{
			tahir--;
			m_op1=m_op1*tahir;
			
		}
	    m_num=m_op1;
	}
    UpdateData(FALSE);
    m_control_e.SetFocus();
    st1=0;
    pflag=0;
	
}






void CDialog_basedDlg::Onpow()//x^y
{
    UpdateData(TRUE);
	m_op1 = m_num;
	m_operation = 5;
    pflag=0;
    m_control_e.SetFocus();
    st1=0;
    m_control_e.SetSel(0,-1);
}

void CDialog_basedDlg::Onx2()//x^2
{
    UpdateData(TRUE);
	m_num=pow(m_num,2);
	UpdateData(FALSE);
	m_control_e.SetFocus();
    st1=0;
    m_control_e.SetSel(0,-1);
	pflag=0;
}

void CDialog_basedDlg::Onx3()//x^3 
{
	UpdateData(TRUE);
	m_num=pow(m_num,3);
	UpdateData(FALSE);
	m_control_e.SetFocus();
    st1=0;
    m_control_e.SetSel(0,-1);
}

void CDialog_basedDlg::Onpi()//π
{
	m_num=3.1415926535897932384626433832795;
    UpdateData(FALSE);
	m_control_e.SetFocus();
    st1=0;
	pflag=0;
}


void CDialog_basedDlg::OnChangeEdit1() 
{
}

void CDialog_basedDlg::AddDigit(char numKey) //按钮响应函数
{
	CString str, tmp;
    tmp.Format("%c", numKey);
	m_control_e.GetWindowText(str);
	if(str == '0'||st1==0)
		str = tmp;
	else
		str += tmp;
	st1=1;
	m_control_e.SetWindowText(str);
}

void CDialog_basedDlg::Onb1() 
{
	AddDigit('1');
}

void CDialog_basedDlg::Onb2() 
{
	AddDigit('2');
}

void CDialog_basedDlg::Onb3() 
{
	AddDigit('3');
}

void CDialog_basedDlg::Onb4() 
{
	AddDigit('4');
}

void CDialog_basedDlg::Onb5() 
{
	AddDigit('5');
}

void CDialog_basedDlg::Onb6() 
{
	AddDigit('6');
}

void CDialog_basedDlg::Onb7() 
{
	AddDigit('7');
}

void CDialog_basedDlg::Onb8() 
{
	AddDigit('8');
}

void CDialog_basedDlg::Onb9() 
{
	AddDigit('9');
}

void CDialog_basedDlg::Onb10() 
{
	AddDigit('0');
}

void CDialog_basedDlg::Onbp()//小数点
{
	if(pflag==0)
	AddDigit('.');
	pflag=1;
}

void CDialog_basedDlg::OnOr()//或运算 
{
	UpdateData(TRUE);
	m_op1 = m_num;
    m_operation= 8;
	 st1=0;
	 pflag=0;
	m_control_e.SetFocus();   
}

void CDialog_basedDlg::On1x()//求1/x
{
	UpdateData(TRUE);
	m_num=1/m_num;
	UpdateData(FALSE);
    st1=0;
	m_control_e.SetFocus();
    pflag=0;
}

void CDialog_basedDlg::Onbp2() //求相反数
{
	UpdateData(TRUE);
	m_num=-m_num;
	UpdateData(FALSE);
	st1=0;
}



void CDialog_basedDlg::Ondata() 
{
	UpdateData(TRUE);
	data[i]=m_num;
    r= r+data[i];
    p=p+data[i]*data[i];
	i++;
	st1=0;
	m_control_e.SetFocus();
    pflag=0;
}

void CDialog_basedDlg::Onsum() 
{
	m_num=r;
	UpdateData(FALSE);

	st1=0;
	m_control_e.SetFocus();
   
	pflag=0;
}

void CDialog_basedDlg::Ons()//x^y具体运算 
{
	m_num=pow((float)(p/i-((r*r)/(i*i))), (float)0.5);
    UpdateData(FALSE);
	st1=0;
	m_control_e.SetFocus();
    pflag=0;
}

/*void CDialog_basedDlg::OnDate() 
{
	Ctahir t;
	t.DoModal();
}*/

void CDialog_basedDlg::Onroot()//求平方根运算
{
	UpdateData(TRUE);
	m_num=pow(m_num,0.5);
    UpdateData(FALSE);
	pflag=0;
}

void CDialog_basedDlg::Onroot2()//求x次方根运算
{
	UpdateData(TRUE);
	m_op1 = m_num;
	m_operation = 7;
    pflag=0;
    m_control_e.SetFocus();
    st1=0;
}
 
void CDialog_basedDlg::Onbsp() 
{
	
	CString str, tmp;
	m_control_e.GetWindowText(str);
    int a;
	a=str.GetLength();
	if(a!=0)
    str.Delete(a-1,1);

	m_control_e.SetWindowText(str);
}

void CDialog_basedDlg::OnAnd()//与按钮
{
	UpdateData(TRUE);
	m_op1 = m_num;
    m_operation= 9;
	 st1=0;
	 pflag=0;
	m_control_e.SetFocus();
    m_control_e.SetSel(0,-1);
}

void CDialog_basedDlg::OnXor()//异或
{
	UpdateData(TRUE);
	m_op1 = m_num;
    m_operation= 10;
	st1=0;
	pflag=0;
	m_control_e.SetFocus();
    m_control_e.SetSel(0,-1);
}

void CDialog_basedDlg::OnMOd()//求模运算 
{
	UpdateData(TRUE);
	m_op1 = m_num;
    m_operation= 11;
	 st1=0;
	 pflag=0;
	m_control_e.SetFocus();
    m_control_e.SetSel(0,-1);
}



void CDialog_basedDlg::Equal2()//对按钮响应，进行相应操作
{
	UpdateData(TRUE);
	m_op2=m_num;
    switch(m_operation)
	{
	case 1:
		m_result = m_op1 + m_op2;
		break;
	case 2:
		m_result = m_op1 - m_op2;
		break;
	case 3:
		m_result = m_op1/m_op2;
		break;
	case 4:
		m_result = m_op1*m_op2;
		break;
	case 5:
		m_result = pow(m_op1,m_op2);
		break;
	case 6:
		m_result = (m_op1||m_op2);
		break;
	case 7:
		{
			m_op2=1/m_op2;
		m_result = pow(m_op1,m_op2);
		}
		break;
	case 8:
		{
		
		m_result =  int(m_op1) bitor int(m_op2) ;
		 break;
		}
		break;
	case 9:
		{
		
		m_result =  int(m_op1)  bitand int(m_op2) ;
		 break;
		}
	case 10:
	m_result =  int(m_op1)  xor int(m_op2) ;
		break;
	case 11:
		m_result=int(m_op1) % int(m_op2) ;
		break;
	case 12:break;
	default :	;
	}
	
	m_num = m_result;
	st1=0;
    m_op1=m_result;
   
	pflag=0;
	m_control_e.SetFocus();
   // m_control_e.SetSel(0,-1);
	UpdateData(FALSE);
}

void CDialog_basedDlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	AfxMessageBox(" Key is  Pressed ");

	CDialog::OnChar(nChar, nRepCnt, nFlags);
}

void CDialog_basedDlg::OnClose() //退出对话框
{
	AfxMessageBox("Exit ? ");
	CDialog::OnClose();
}

void CAboutDlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	AfxMessageBox("Pressed ");
	CDialog::OnChar(nChar, nRepCnt, nFlags);
}

void CDialog_basedDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
		AfxMessageBox("  Pressed");
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CDialog_basedDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu menu;
	menu.LoadMenu( IDR_MENU1 );
	SetMenu(NULL);
  
}

void CDialog_basedDlg::OnClos() 
{
	// TODO: Add your command handler code here
	CDialog::OnClose();
}

void CDialog_basedDlg::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
		CMenu menu;
	menu.LoadMenu( IDR_MENU1 );

	CDialog::OnRButtonUp(nFlags, point);
}






