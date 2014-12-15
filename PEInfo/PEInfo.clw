; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDumpDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PEInfo.h"
LastPage=0

ClassCount=7
Class1=CPEInfoApp
Class2=CPEInfoDoc
Class3=CPEInfoView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CConvertDlg
Resource3=IDD_DLG_CONVERT
Class7=CDumpDlg
Resource4=IDD_DLG_DUMP

[CLS:CPEInfoApp]
Type=0
HeaderFile=PEInfo.h
ImplementationFile=PEInfo.cpp
Filter=N
LastObject=CPEInfoApp

[CLS:CPEInfoDoc]
Type=0
HeaderFile=PEInfoDoc.h
ImplementationFile=PEInfoDoc.cpp
Filter=N
LastObject=CPEInfoDoc

[CLS:CPEInfoView]
Type=0
HeaderFile=PEInfoView.h
ImplementationFile=PEInfoView.cpp
Filter=C
LastObject=CPEInfoView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=PEInfo.cpp
ImplementationFile=PEInfo.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
Command14=IDM_Convert
Command15=IDM_APPLOADER
Command16=IDM_DLLLOADER
Command17=IDM_GETPROCADDR
Command18=IDM_DUMPFILE
Command19=IDM_DUMPFIXIMPORT
CommandCount=19

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DLG_CONVERT]
Type=1
Class=CConvertDlg
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EditVA,edit,1484849280
Control5=IDC_EditRVA,edit,1484849280
Control6=IDC_EditFA,edit,1484849280
Control7=IDC_AddrValue,edit,1350631552
Control8=IDC_AddrType,combobox,1344340227
Control9=IDC_Convert,button,1342242816
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EditSection,edit,1484849280
Control12=IDC_EditHexValue,edit,1484849280
Control13=IDC_EditStrValue,edit,1484849280

[CLS:CConvertDlg]
Type=0
HeaderFile=ConvertDlg.h
ImplementationFile=ConvertDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CConvertDlg
VirtualFilter=dWC

[DLG:IDD_DLG_DUMP]
Type=1
Class=CDumpDlg
ControlCount=8
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_PID,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BTN_SELECT,button,1476460544
Control6=IDC_BTN_DUMP,button,1342242816
Control7=IDC_BTN_TLIST,button,1342242816
Control8=IDC_BTN_DUMPFIX,button,1342177280

[CLS:CDumpDlg]
Type=0
HeaderFile=DumpDlg.h
ImplementationFile=DumpDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDumpDlg

