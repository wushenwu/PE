// LogView.cpp : implementation file
//

#include "stdafx.h"
#include "LogView.h"
#include "PE.H"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogView
CLogView *g_pLogView;

IMPLEMENT_DYNCREATE(CLogView, CEditView)

CLogView::CLogView()
{
    g_pLogView = this;
}

CLogView::~CLogView()
{
}


BEGIN_MESSAGE_MAP(CLogView, CEditView)
	//{{AFX_MSG_MAP(CLogView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogView drawing

void CLogView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CLogView diagnostics

#ifdef _DEBUG
void CLogView::AssertValid() const
{
	CEditView::AssertValid();
}

void CLogView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLogView message handlers

/************************************************************************/
/* 
Function : Show Info, according to different operations                                                                     */
/************************************************************************/
void CLogView::UpdateInfo(CString strTblName)
{
    //we only deal with IMPORT, FreeSpace, EXPORT, BASERELC
    extern const char *g_pszIMPORT;
    extern const char *g_pszFreeSpace;
    extern const char *g_pszEXPORT;
    extern const char *g_pszBASERELC;
    if (strTblName.Compare(g_pszIMPORT)
        && strTblName.Compare(g_pszFreeSpace)
        && strTblName.Compare(g_pszEXPORT)
        && strTblName.Compare(g_pszBASERELC))
    {
        return;
    }  

    char *pszLog = NULL;
    BOOL bRet = TRUE;

    if (0 == strTblName.Compare(g_pszIMPORT))
    {
        bRet = GetImportInfo(&pszLog, NULL);
    }
    else if (0 == strTblName.Compare(g_pszFreeSpace))
    {
        bRet = GetFreeSpaceInfo(&pszLog);
    }
    else if (0 == strTblName.Compare(g_pszEXPORT))
    {
        bRet = GetExportInfo(&pszLog);
    }
    else if (0 == strTblName.Compare(g_pszBASERELC))
    {
        bRet = GetBaseRelocInfo(&pszLog, NULL, NULL);
    }
    else
    {
        //Sth wrong?
    }

    if (bRet)
    {
        LogInfo(pszLog);
    }   
}

void CLogView::LogInfo(CString strLog)
{        
    static CEdit *pEditLog = &GetEditCtrl();
    int nLen = pEditLog->GetWindowTextLength();
    pEditLog->SetSel(nLen, nLen);
    pEditLog->ReplaceSel(strLog + "\r\n");
}
