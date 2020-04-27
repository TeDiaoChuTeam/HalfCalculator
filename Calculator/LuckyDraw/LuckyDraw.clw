; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLuckyDrawDlg
LastTemplate=CEdit
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "LuckyDraw.h"

ClassCount=5
Class1=CLuckyDrawApp
Class2=CLuckyDrawDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_LUCKYDRAW_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Class4=CMyButton
Class5=MyEditBox
Resource5=IDD_LUCKYDRAW_DIALOG (English (U.S.))

[CLS:CLuckyDrawApp]
Type=0
HeaderFile=LuckyDraw.h
ImplementationFile=LuckyDraw.cpp
Filter=N
LastObject=CLuckyDrawApp

[CLS:CLuckyDrawDlg]
Type=0
HeaderFile=LuckyDrawDlg.h
ImplementationFile=LuckyDrawDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CLuckyDrawDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=LuckyDrawDlg.h
ImplementationFile=LuckyDrawDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_LUCKYDRAW_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CLuckyDrawDlg

[DLG:IDD_LUCKYDRAW_DIALOG (English (U.S.))]
Type=1
Class=CLuckyDrawDlg
ControlCount=4
Control1=IDC_Show,edit,1353783429
Control2=IDC_LuckyButton,button,1342242816
Control3=IDC_ShowAllMember,button,1342242816
Control4=IDC_SelectTeam,combobox,1344340226

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CMyButton]
Type=0
HeaderFile=MyButton.h
ImplementationFile=MyButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC
LastObject=CMyButton

[CLS:MyEditBox]
Type=0
HeaderFile=MyEditBox.h
ImplementationFile=MyEditBox.cpp
BaseClass=CEdit
Filter=W
LastObject=MyEditBox
VirtualFilter=WC

