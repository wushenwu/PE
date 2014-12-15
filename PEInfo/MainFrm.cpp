// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "PEInfo.h"

#include "MainFrm.h"
#include "TblTreeView.h"
#include "TblInfoView.h"
#include "LogView.h"
#include "ConvertDlg.h"
#include "DumpDlg.h"

#include "PE.H"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////////
static CEdit *gs_pEditLog = NULL;
static CTblTreeView *gs_pTblTreeView;
static CTblInfoView *gs_pTblInfoView;

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(IDM_Convert, OnConvertTool)
	ON_COMMAND(IDM_APPLOADER, OnApploader)
	ON_COMMAND(IDM_GETPROCADDR, OnGetProcAddr)
	ON_COMMAND(IDM_DUMPFILE, OnDumpFile)
	ON_COMMAND(IDM_DLLLOADER, OnDllLoader)
	ON_COMMAND(IDM_DUMPFIXIMPORT, OnDumpFixImport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
    ReleaseBuf();
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

#ifdef DISPLAY_TOOLBAR
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
#endif

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

#ifdef DISPLAY_TOOLBAR
	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
#endif

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
    //划分成两行一列
    BOOL bRet = m_SplitterWnd1.CreateStatic(this, 2, 1);
    
    //将第1行进行再分割，分割成一个TreeView，一个DataGrid
    bRet = m_SplitterWnd2.CreateStatic(&m_SplitterWnd1, 
                                            1, 2, 
                                            WS_CHILD | WS_VISIBLE, 
                                            m_SplitterWnd1.IdFromRowCol(0, 0)
                                            );
    
    //紧接着createview
    m_SplitterWnd2.CreateView(0, 0, RUNTIME_CLASS(CTblTreeView), CSize(0, 0), pContext);
    m_SplitterWnd2.CreateView(0, 1, RUNTIME_CLASS(CTblInfoView), CSize(0, 0), pContext);
    
    m_SplitterWnd2.SetColumnInfo(0, 200, 1);
    
    //将第2行设置为CEditView
    m_SplitterWnd1.CreateView(1, 0, RUNTIME_CLASS(CLogView), CSize(0, 0), pContext);
    
    m_SplitterWnd1.SetRowInfo(0, 300, 10);
    
    //
    CLogView *pLogView = reinterpret_cast<CLogView*>(m_SplitterWnd1.GetPane(1,0)); 
    gs_pEditLog = &pLogView->GetEditCtrl();
    
    //
    gs_pTblTreeView = reinterpret_cast<CTblTreeView*>(m_SplitterWnd2.GetPane(0,0));
    gs_pTblInfoView = reinterpret_cast<CTblInfoView*>(m_SplitterWnd2.GetPane(0,1));
    
	return TRUE;
}

//To indicate whether file being processed
BOOL g_bHasFile = FALSE;
/************************************************************************/
/* 
Function : Select One Specific File, Load into Memory               */
/************************************************************************/
void CMainFrame::OnFileOpen() 
{
    //release memory mapped last time if exists
    ReleaseBuf();

    CFileDialog *pDlgSRCFile = new CFileDialog(TRUE);
    if (NULL == pDlgSRCFile)
    {
        return;
    }
    
    if (pDlgSRCFile->DoModal() != IDOK)
    {
        return;
    }  
    
    //Retrieve Basic Infos: full path, filename, size, md5, 
    m_strFilePath = pDlgSRCFile->GetPathName();
    m_strFileName = pDlgSRCFile->GetFileName();
    
    CFile myFile;
    CFileException myFileException;
    BOOL bRet = myFile.Open(m_strFilePath, CFile::modeRead, &myFileException);
    if (!bRet)
    {
        TRACE( "Can't open file %s, error = %u\n", 
                                        m_strFilePath,
                                        myFileException.m_cause 
                                        );
        
    }
    
    m_dwFileLen = myFile.GetLength();
    myFile.Close(); 
    
    //Try to load into memory
    if (!LoadFile(m_strFilePath.GetBuffer(0)))
    {
        return;
    }

    //Now verify PE
    if (!IsPE())
    {
        MessageBox("This File Is Not a Valid PE!!");
        return;
    }

    //now update UI
    gs_pTblTreeView->LoadTblTree(m_strFileName, GetPETree());

    g_bHasFile = TRUE;
}

/************************************************************************/
/* 
Function : Entry for RVA/FA/VA converting
                                                                     */
/************************************************************************/
void CMainFrame::OnConvertTool() 
{
    CConvertDlg *pdlg = new CConvertDlg(this);
    if (NULL == pdlg)
    {
        return;
    }
    
    BOOL bRet = pdlg->Create(IDD_DLG_CONVERT,this);
    if (!bRet)
    {
        delete pdlg;
        return;
    }
    
    pdlg->ShowWindow(SW_SHOW);	  	
}


/************************************************************************/
/* 
Function: Entry For mapping app into our own space, and then "Execute" it.
1) map app into our space
2) check whether a valid PE
3) make sure our ImageBase same to the target app
4) copy target app's image into our image base

  Target App:                         Our Space:
              DOS Header                        DOS Header
              DOS Stub                          DOS Stub                     
              FileHeader                        File Header
              OPT Header                        OPT Header
              Section Headers                   Section Headers
              Section Datas                     Aligned Free space
                                                (Big enough to contain Target's Section Datas)
                                              Our Own Section Datas
0x400 1024
0x800 2048
0x1000 4096
0x2000 8192
0x4000 16384
0x8000  32768
0x10000 65536
0x20000 
0x100000  1024 * 1024  

1 2 4 8    
0x1000  0x10000 0x100000 
0x2000  0x20000 0x200000
0x4000  0x40000 0x400000
0x8000  0x80000 0x800000                                                                */
/************************************************************************/
#pragma comment(linker, "/FILEALIGN:0x1000")
#pragma comment(linker, "/ALIGN:0x1000")
#pragma comment(linker, "/BASE:0x00400000")

void CMainFrame::OnApploader() 
{
    //reuse the code to map app into memory, and valid checking
    OnFileOpen(); 

    //
    HMODULE hSelf = GetModuleHandle(NULL);
    if (!LoadAPP(hSelf))
    {
        return;
    }
}

/************************************************************************/
/* 
Function : Demo for self implementation of GetProcAddress               */
/************************************************************************/
void CMainFrame::OnGetProcAddr() 
{
    //loadlibrary can also self implemented
    HMODULE hDll = LoadLibrary("User32");
    if (NULL == hDll)
    {
        return;
    }

    DWORD ptrFunc = DoGetProcAddress(hDll, "MessageBoxA");
    if (NULL == ptrFunc)
    {
        return;
    }

    _asm
    {
        push MB_OK
        push NULL
        push NULL
        push NULL
        call ptrFunc
    }

    DoGetProcAddress(LoadLibrary("Kernel32"), "AddVectoredExceptionHandler");
}

/************************************************************************/
/* 
Function : Entry for Dump specified process into exe file              */
/************************************************************************/
void CMainFrame::OnDumpFile() 
{
    static CDumpDlg *pdlg = new CDumpDlg(this);
    if (NULL == pdlg)
    {
        return;
    }
    
    BOOL bRet = pdlg->Create(IDD_DLG_DUMP,this);
    if (!bRet)
    {
        delete pdlg;
        return;
    }

    pdlg->GetDlgItem(IDC_BTN_DUMPFIX)->EnableWindow(FALSE);
    pdlg->ShowWindow(SW_SHOW);	  
    
}

/************************************************************************/
/* 
Function : Entry for demonstrating dll loader

1) Virtualloc space, copy dll image into the space
2) Fix IAT
3) Fix Base Relocation
4) call DllMain
5) call exported func to verify                           */
/************************************************************************/
void CMainFrame::OnDllLoader() 
{    
    //reuse the code to map app into memory, and valid checking
    OnFileOpen(); 
    
    //
    HMODULE hDll = LoadDll();
    if (NULL == hDll)
    {
        return;
    }

    DoGetProcAddress(hDll, "MessageBoxA");
    _asm
    {
        push NULL
        push NULL
        push NULL
        push NULL
        call eax
    }
}

/************************************************************************/
/* 
Function : Entry for Dump File and Fix Import                                                                     */
/************************************************************************/
void CMainFrame::OnDumpFixImport() 
{
    static CDumpDlg *pdlg = new CDumpDlg(this);
    if (NULL == pdlg)
    {
        return;
    }
    
    BOOL bRet = pdlg->Create(IDD_DLG_DUMP,this);
    if (!bRet)
    {
        delete pdlg;
        return;
    }
    
    pdlg->GetDlgItem(IDC_BTN_DUMP)->EnableWindow(FALSE);
    pdlg->ShowWindow(SW_SHOW);	  	
}
