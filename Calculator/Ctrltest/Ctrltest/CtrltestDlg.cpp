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
	m_length.SetCheck(1);//Ĭ�������ѡ�г��ȵ�λ
	m_weight.SetCheck(0);
	m_time.SetCheck(0);
	m_area.SetCheck(0);
	m_memory.SetCheck(0);
	
	//��ʼ����ת����λ����Ͽ�


	m_cbUnit1.AddString("��");
	m_cbUnit1.AddString("����");
	m_cbUnit1.AddString("����");
	m_cbUnit1.AddString("����");
	m_cbUnit1.SetCurSel(0);//��ʼ����λ��Ͽ�ʹ��Ͽ�ǰѡ��Ϊ��0�������ס�


	//��ʼ����ת����λ���б��
	m_ltUnit2.AddString("��");
	m_ltUnit2.AddString("����");
	m_ltUnit2.AddString("����");
	m_ltUnit2.AddString("����");
	m_ltUnit2.SetCurSel(0);//��ʼ����λ�б��ʹ��Ͽ�ǰѡ��Ϊ��0�������ס�


	//���ó�ʼֵ
	m_dbNumber=1.0;
	m_result="1.0��";


	//��ʼ��ת������
	m_ref.SetWindowText("1��=1��");
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	double s=0;
	if (m_length.GetCheck())//���������ȵĵ�λ��ѡ��
	{	
		double t=1.0;
		for (int i=0;i<abs(m_cbUnit1.GetCurSel()-m_ltUnit2.GetCurSel());i++)
		{
			t*=10;//�������ƵĽ���Ϊ10��
		}
		s=t;
	}
	if (m_time.GetCheck())//����������ƣ������ʱ�䱻ѡ�������Ϊ60��
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
	m_cbUnit1.GetLBText(m_cbUnit1.GetCurSel(),u1);//��ȡת���ĵ�λ���ŵ�u1��
	m_ltUnit2.GetText(m_ltUnit2.GetCurSel(),u2);//��ȡת��Ϊ�ĵ�λ���ŵ�u2��
	r.Format("%f%s=%f%s",1.0,u1,s,u2);//�����ַ�ת������
	m_ref.SetWindowText(r);//��ʾת�������ھ�̬�ı���
	
}

void CCtrltestDlg::Onequal() 
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(1);
	double s=0;
	if (m_length.GetCheck())//���������ȵĵ�λ��ѡ��
	{	
		double t=1.0;
		for (int i=0;i<abs(m_cbUnit1.GetCurSel()-m_ltUnit2.GetCurSel());i++)
		{
			t*=10;//�������ƵĽ���Ϊ10��
		}
		s=t;
	}
	if (m_time.GetCheck())//����������ƣ������ʱ�䱻ѡ�������Ϊ60��
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	double s=0;
	if (m_length.GetCheck())//���������ȵĵ�λ��ѡ��
	{	
		double t=1.0;
		for (int i=0;i<abs(m_cbUnit1.GetCurSel()-m_ltUnit2.GetCurSel());i++)
		{
			t*=10;//�������ƵĽ���Ϊ10��
		}
		s=t;
	}
	 if (m_time.GetCheck())//����������ƣ������ʱ�䱻ѡ�������Ϊ60��
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
	m_cbUnit1.GetLBText(m_cbUnit1.GetCurSel(),u1);//��ȡת���ĵ�λ���ŵ�u1��
	m_ltUnit2.GetText(m_ltUnit2.GetCurSel(),u2);//��ȡת��Ϊ�ĵ�λ���ŵ�u2��
	r.Format("%f%s=%f%s",1.0,u1,s,u2);//�����ַ�ת������
	m_ref.SetWindowText(r);//��ʾת�������ھ�̬�ı���
}

void CCtrltestDlg::OnRadioLength() 
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(1);
	m_ltUnit2.ResetContent();//��ת���б��ȫ�����㣬����д��
	m_cbUnit1.ResetContent();//��ת����Ͽ�ȫ�����㣬����д��
	//д����Ͽ�����
	m_cbUnit1.AddString("��");
	m_cbUnit1.AddString("����");
	m_cbUnit1.AddString("����");
	m_cbUnit1.AddString("����");
	m_cbUnit1.SetCurSel(0);
	

	//�б��Ҳ������
	m_ltUnit2.AddString("��");
	m_ltUnit2.AddString("����");
	m_ltUnit2.AddString("����");
	m_ltUnit2.AddString("����");
	m_ltUnit2.SetCurSel(0);//��ʼ����λ�б��ʹ��Ͽ�ǰѡ��Ϊ��0�������ס�
	m_ref.SetWindowText("1��=1��");
	UpdateData(0);





}

void CCtrltestDlg::OnRadioTime() 
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(1);
	m_ltUnit2.ResetContent();//��ת����Ͽ�ȫ�����㣬����д��
		m_cbUnit1.ResetContent();
	//д����Ͽ�����
	m_cbUnit1.AddString("ʱ");
	m_cbUnit1.AddString("��");
	m_cbUnit1.AddString("��");

	m_cbUnit1.SetCurSel(0);
	
	
	//�б��Ҳ������
	m_ltUnit2.AddString("ʱ");
	m_ltUnit2.AddString("��");
	m_ltUnit2.AddString("��");

	m_ltUnit2.SetCurSel(0);//��ʼ����λ�б��ʹ��Ͽ�ǰѡ��Ϊ��0�������ס�
	m_ref.SetWindowText("1ʱ=1ʱ");
	UpdateData(0);

}

void CCtrltestDlg::OnRadioWeight() 
{

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(1);
	m_ltUnit2.ResetContent();//��ת����Ͽ�ȫ�����㣬����д��
	m_cbUnit1.ResetContent();
	//д����Ͽ�����
	m_cbUnit1.AddString("ǧ��");
	m_cbUnit1.AddString("��");
	m_cbUnit1.AddString("����");
	
	m_cbUnit1.SetCurSel(0);
	
	
	//�б��Ҳ������
	m_ltUnit2.AddString("ǧ��");
	m_ltUnit2.AddString("��");
	m_ltUnit2.AddString("����");
	
	m_ltUnit2.SetCurSel(0);//��ʼ����λ�б��ʹ��Ͽ�ǰѡ��Ϊ��0�������ס�
	m_ref.SetWindowText("1ǧ��=1ǧ��");
	UpdateData(0);


	
}


void CCtrltestDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CCtrltestDlg::OnBnClickedRadioMemory()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(1);
	m_ltUnit2.ResetContent();//��ת����Ͽ�ȫ�����㣬����д��
	m_cbUnit1.ResetContent();
	//д����Ͽ�����
	m_cbUnit1.AddString("B");
	m_cbUnit1.AddString("KB");
	m_cbUnit1.AddString("MB");
	m_cbUnit1.AddString("GB");
	m_cbUnit1.AddString("TB");

	m_cbUnit1.SetCurSel(0);


	//�б��Ҳ������
	m_ltUnit2.AddString("B");
	m_ltUnit2.AddString("KB");
	m_ltUnit2.AddString("MB");
	m_ltUnit2.AddString("GB");
	m_ltUnit2.AddString("TB");

	m_ltUnit2.SetCurSel(0);//��ʼ����λ�б��ʹ��Ͽ�ǰѡ��Ϊ��0������B��
	m_ref.SetWindowText("1B=1B");
	UpdateData(0);

}


void CCtrltestDlg::OnBnClickedRadioArea()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(1);
	m_ltUnit2.ResetContent();//��ת����Ͽ�ȫ�����㣬����д��
	m_cbUnit1.ResetContent();
	//д����Ͽ�����
	m_cbUnit1.AddString("ƽ������");
	m_cbUnit1.AddString("ƽ������");
	m_cbUnit1.AddString("ƽ������");
	m_cbUnit1.AddString("ƽ����");

	m_cbUnit1.SetCurSel(0);


	//�б��Ҳ������
	m_ltUnit2.AddString("ƽ������");
	m_ltUnit2.AddString("ƽ������");
	m_ltUnit2.AddString("ƽ������");
	m_ltUnit2.AddString("ƽ����");

	m_ltUnit2.SetCurSel(0);//��ʼ����λ�б��ʹ��Ͽ�ǰѡ��Ϊ��0������B��
	m_ref.SetWindowText("1ƽ������=1ƽ������");
	UpdateData(0);
}


void CCtrltestDlg::OnBnClickedButtonclear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetDlgItemText(IDC_EDIT1, _T(""));
	SetDlgItemText(IDC_EDIT2, _T(""));
}
