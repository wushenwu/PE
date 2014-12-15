// DumpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PEInfo.h"
#include "DumpDlg.h"
#include <Tlhelp32.h>
#include "pe.h"

#include "LogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDumpDlg dialog


CDumpDlg::CDumpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDumpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDumpDlg)
	m_dwPID = 0;
	//}}AFX_DATA_INIT

    m_pModBase = NULL;
}


void CDumpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDumpDlg)
	DDX_Control(pDX, IDC_BTN_DUMPFIX, m_BtnDumpFix);
	DDX_Control(pDX, IDC_BTN_TLIST, m_BtnTList);
	DDX_Control(pDX, IDC_BTN_DUMP, m_BtnDump);
	DDX_Control(pDX, IDC_BTN_SELECT, m_BtnSelect);
	DDX_Text(pDX, IDC_EDIT_PID, m_dwPID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDumpDlg, CDialog)
	//{{AFX_MSG_MAP(CDumpDlg)
	ON_BN_CLICKED(IDC_BTN_TLIST, OnBtnTlist)
	ON_BN_CLICKED(IDC_BTN_SELECT, OnBtnSelect)
	ON_BN_CLICKED(IDC_BTN_DUMP, OnBtnDump)
	ON_BN_CLICKED(IDC_BTN_DUMPFIX, OnBtnDumpFix)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDumpDlg message handlers

/************************************************************************/
/* 
Function : Call system's tasklist, used to get pid                                                                     */
/************************************************************************/
void CDumpDlg::OnBtnTlist() 
{
    system("taskmgr");
}

/************************************************************************/
/* 
Function : Select the directory you want to save the dumped file*/
/************************************************************************/
void CDumpDlg::OnBtnSelect() 
{
    //TBD
    //now we just save into the current directory, named with APPNAME_dump.exe
}

/************************************************************************/
/*  
Function : the real point for dumpping specific process into file                                                                    */
/************************************************************************/
void CDumpDlg::OnBtnDump() 
{
    UpdateData();
    ASSERT(m_dwPID != 0);

    BOOL bFix = FALSE;
    DumpPE(m_dwPID, bFix, NULL);
}

void CDumpDlg::OnBtnDumpFix() 
{
    UpdateData();
    ASSERT(m_dwPID != 0);

    BOOL bFix = TRUE; 
    char *pszBuf = NULL;
    DumpPE(m_dwPID, bFix, &pszBuf);
    
    extern CLogView *g_pLogView;
    if (pszBuf != NULL)
    {
        g_pLogView->LogInfo(pszBuf);
    }
}
