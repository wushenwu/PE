// TblTreeView.cpp : implementation file
//

#include "stdafx.h"
#include "TblTreeView.h"
#include "MainFrm.h"
#include "TblInfoView.h"
#include "LogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTblTreeView

IMPLEMENT_DYNCREATE(CTblTreeView, CTreeView)

CTblTreeView::CTblTreeView()
{
}

CTblTreeView::~CTblTreeView()
{
}


BEGIN_MESSAGE_MAP(CTblTreeView, CTreeView)
	//{{AFX_MSG_MAP(CTblTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTblTreeView drawing

void CTblTreeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CTblTreeView diagnostics

#ifdef _DEBUG
void CTblTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CTblTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTblTreeView message handlers

void CTblTreeView::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
	
    //设置TreeView Style
    LONG lOld = GetWindowLong(GetSafeHwnd(), GWL_STYLE);
    SetWindowLong(GetSafeHwnd(), 
                    GWL_STYLE, lOld | TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT
                    );
}

/************************************************************************/
/* 将FileName 及PE 主要结构名称显示到树形结构中。                                                                     */
/************************************************************************/
BOOL CTblTreeView::LoadTblTree(CString &strFileName, const char *pszTblNames)
{
    //添加item
    CTreeCtrl& ctrl = GetTreeCtrl();
    ctrl.DeleteAllItems();

    HTREEITEM hParent = ctrl.InsertItem("File: " + strFileName);

    CString strTbls = pszTblNames; 
    CString strSub  = _T("");
    for (int i = 0; ; i++)
    {
        if (!AfxExtractSubString(strSub, strTbls, i, '|'))
        {
            break;
        }

        ctrl.InsertItem(strSub, hParent);
    }

    ctrl.Expand(hParent, TVE_EXPAND);

    return TRUE;
}

/************************************************************************/
/* 当用户选择某表时，在List View中更新相应的字段信息。                                                                     */
/************************************************************************/
void CTblTreeView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	
    static CTreeCtrl& ctrl = GetTreeCtrl();  
    HTREEITEM hCurSel      = ctrl.GetSelectedItem();
    if (NULL == hCurSel)
    {
        return;
    }

    if (ctrl.ItemHasChildren(hCurSel))
    {
        return;
    }

    //already get table name
    CString strTbl = ctrl.GetItemText(hCurSel);

    static CMainFrame *pMainFrame     = reinterpret_cast<CMainFrame*>(AfxGetMainWnd());
    static CTblInfoView *pTblInfoView = reinterpret_cast<CTblInfoView*>(pMainFrame->m_SplitterWnd2.GetPane(0,1));
    static CLogView *pLogView         = reinterpret_cast<CLogView*>(pMainFrame->m_SplitterWnd1.GetPane(1,0)); 
    pTblInfoView->UpdateListInfo(strTbl);
    pLogView->UpdateInfo(strTbl);
	
	*pResult = 0;
}
