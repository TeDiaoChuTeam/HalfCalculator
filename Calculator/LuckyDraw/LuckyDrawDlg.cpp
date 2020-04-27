// LuckyDrawDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LuckyDraw.h"
#include "LuckyDrawDlg.h"
#include <random>

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
// CLuckyDrawDlg dialog

CLuckyDrawDlg::CLuckyDrawDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLuckyDrawDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLuckyDrawDlg)
	m_cstrShow = _T("");
    m_team = "all";
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);	
	LoadFile();
}


bool CLuckyDrawDlg::isSaveName(char* buff)
{
	if ('#' == buff[0])
	{
		return false;
	}
	int num = 0;
	char c;
	while (c = *buff++)
	{
		if (islower(c) || isupper(c))
		{
			num++;
		}
	}
	return (bool)num;
}
bool CLuckyDrawDlg::updateTeam(char* buff)
{
    if ('[' == buff[0])
    {
        m_team = string(buff);
        m_team = m_team.substr(1, m_team.find(']') - 1);
        vector<string> empty;
        LuckyName[m_team] = empty;
        return true;
    }
    return false;
}
void CLuckyDrawDlg::LoadFile()
{
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	_splitpath(__argv[0], drive, dir, fname, ext);

	string strDir(drive);
	strDir += dir;
	strDir += "\\member.dat";
	FILE* fd = fopen(strDir.c_str(),"r+");
	if (NULL == fd)
	{
		//MessageBox(strDir.c_str());
		return;
	}
	
	char buff[1024] = {0};
	while(NULL != fgets(buff, 1024, fd))
	{    
        if (updateTeam(buff))
        {
            continue;
        }
		if (strlen(buff) <= 4)
		{
			memset(buff, 0, sizeof(buff));
			continue;
		}		
		LuckyName[m_team].push_back(string(buff));
		memset(buff, 0, sizeof(buff));
	}
	fclose(fd);

    LuckyName[string("all")] = LuckyName[string("class1")];
        
	if (LuckyName[string("all")].empty())
	{
		MessageBox("there's no student!");
	}
    m_team = "all";
}

void CLuckyDrawDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CLuckyDrawDlg)
    DDX_Control(pDX, IDC_Show, m_EditBoxShow);
    DDX_Text(pDX, IDC_Show, m_cstrShow);
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLuckyDrawDlg, CDialog)
	//{{AFX_MSG_MAP(CLuckyDrawDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_LuckyButton, OnLuckyButton)
	ON_BN_CLICKED(IDC_ShowAllMember, OnShowAllMember)
//	ON_CBN_EDITCHANGE(IDC_SelectTeam, OnSlectTeam)
	//}}AFX_MSG_MAP
    ON_CBN_KILLFOCUS(IDC_SelectTeam, &CLuckyDrawDlg::OnKillfocusSelectteam)
	ON_CBN_SELCHANGE(IDC_SelectTeam, &CLuckyDrawDlg::OnCbnSelchangeSelectteam)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLuckyDrawDlg message handlers

BOOL CLuckyDrawDlg::OnInitDialog()
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
	
	COLORREF color = RGB(0,255,0);
	m_EditBoxShow.SetForeColor(color);
	
	m_EditBoxShow.SetBkColor(RGB(0,0,0));
	m_EditBoxShow.SetTextFont(650, _T("FangSong_GB2312"));	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CLuckyDrawDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLuckyDrawDlg::OnPaint() 
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
		dc.FillSolidRect(rect, RGB(139, 201, 228));

	}
	SetDlgItemText(IDC_Show, "Are you ready for the roll call?");
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLuckyDrawDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLuckyDrawDlg::OnLuckyButton() 
{
	// TODO: Add your control notification handler code here
	m_EditBoxShow.SetTextFont(600, _T("FangSong_GB2312"));
	m_EditBoxShow.SetForeColor(RGB(0,255,0));
	CString str;
	if (GetDlgItemText(IDC_LuckyButton,str),str=="start"|| str=="start-roll")
	{	
		SetDlgItemText(IDC_LuckyButton,"stop");
		srand((unsigned)time(NULL));
		SetTimer(1001,1,NULL);
		
	}
	else
	{		
		SetDlgItemText(IDC_LuckyButton,"start");
		KillTimer(1001);		
		CString luckyMan;
		GetDlgItemText(IDC_Show, luckyMan);
		luckyMan.Delete(0,1);
		int nameLength = luckyMan.GetLength();
		CString flgStr('-', (nameLength) );
		CString finalShow;
		//finalShow.Format("===Congratulation===\r\n-------------\r\n|" + luckyMan + "|\r\n-------------\r\nYou are the lottery",)
		luckyMan = "=====Congratulation=====\r\n" + flgStr + "\r\n|" + luckyMan + "|\r\n" + flgStr + "\r\nYou are the lucky dog!";
		m_EditBoxShow.SetTextFont(400, _T("FangSong_GB2312"));
		m_EditBoxShow.SetForeColor(RGB(255,0,0));
		SetDlgItemText(IDC_Show, luckyMan);
		//MessageBox(LPCTSTR(luckyMan));
	}
}


void CLuckyDrawDlg::OnTimer(UINT nIDEvent)
{
	// TODO: Add yourmessage handler code here and/or call default
	switch(nIDEvent)
	{
		case 1001:      //ID为1001的定时器代码部分
		{

			//SetDlgItemText(IDC_Show, LuckyName[rand()%9].c_str());
			/*(rand()*LuckyName.size())/(RAND_MAX+1.0)*/
			if (LuckyName[m_team].empty())
			{
				break;
			}
			m_cstrShow = "\r\n";
			static default_random_engine e;
			static uniform_int_distribution<unsigned> u(0, LuckyName[m_team].size() - 1);
			m_cstrShow += LuckyName[m_team][u(e)].c_str();
			//update
			m_EditBoxShow.SetTextFont(600, _T("FangSong_GB2312"));
			m_EditBoxShow.SetForeColor(RGB(0,255,0));
			UpdateData(FALSE);			
			break;
		}
		default:
			break;
	}
	CDialog::OnTimer(nIDEvent);
}


void CLuckyDrawDlg::OnShowAllMember() 
{
	// TODO: Add your control notification handler code here
	m_EditBoxShow.SetTextFont(300, _T("FangSong_GB2312"));
	m_EditBoxShow.SetForeColor(RGB(255,0,255));
	m_cstrShow.Empty();
	char buff[100] = { 0 };
	itoa(LuckyName[m_team].size(), buff, 10);
	m_cstrShow += "Total members: ";
	m_cstrShow += buff;
	m_cstrShow += "\r\n";

	for (int i = 0; i < LuckyName[m_team].size(); ++i)
	{
	    m_cstrShow += LuckyName[m_team][i].c_str();
		m_cstrShow += "\r\n";
	}	
	m_cstrShow.Delete(m_cstrShow.GetLength() - 1, 1);
	UpdateData(FALSE);

}


void CLuckyDrawDlg::OnKillfocusSelectteam()
{
    // TODO: Add your control notification handler code here
    CString team;
    GetDlgItemText(IDC_SelectTeam, team);
    m_team = team.GetBuffer();
}


void CLuckyDrawDlg::OnCbnSelchangeSelectteam()
{
	// TODO: 在此添加控件通知处理程序代码
}
