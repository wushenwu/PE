// TblInfoView.cpp : implementation file
//

#include "stdafx.h"
#include "TblInfoView.h"
#include "MainFrm.h"

#include "PE.H"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define PAD         "*"
#define SEP         '|'   //field separator
#define SEP_RECORD  '$'   //record separator

#define CACHE_FILE  "localcache.dat"


/////////////////////////////////////////////////////////////////////////////
// CTblInfoView

IMPLEMENT_DYNCREATE(CTblInfoView, CListView)

CTblInfoView::CTblInfoView()
{
    m_strCurTbl  = "";
    m_Operation  = OP_NONE;
    m_pEdit      = NULL;
    
    m_nItem      = -1;
    m_nSubItem   = -1;
    
    m_strUpdateTime = "";
    m_bRemote       = TRUE;
}

CTblInfoView::~CTblInfoView()
{

}

BEGIN_MESSAGE_MAP(CTblInfoView, CListView)
	//{{AFX_MSG_MAP(CTblInfoView)
	//ON_COMMAND(IDM_OPERATE, OnOperate)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
    ON_MESSAGE(MSG_EDIT_END, OnMSGEditEnd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTblInfoView drawing

void CTblInfoView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CTblInfoView diagnostics

#ifdef _DEBUG
void CTblInfoView::AssertValid() const
{
	CListView::AssertValid();
}

void CTblInfoView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTblInfoView message handlers

void CTblInfoView::OnInitialUpdate() 
{
	CListView::OnInitialUpdate();
	
    //����TreeView Style
    LONG lOld = GetWindowLong(GetSafeHwnd(), GWL_STYLE);
    SetWindowLong(GetSafeHwnd(),
        GWL_STYLE, 
        lOld 
        | WS_CHILDWINDOW| WS_VISIBLE | WS_CLIPCHILDREN | WS_HSCROLL | WS_VSCROLL |WS_TABSTOP 
        | LVS_REPORT| LVS_EDITLABELS | LVS_SHAREIMAGELISTS | LVS_ALIGNLEFT 
        | LVS_NOSORTHEADER
        );	
}

/************************************************************************/
/* TreeView��ѡ������� ListView��չʾ�����Ϣ                         */
/************************************************************************/
void CTblInfoView::UpdateListInfo(CString strTblName)
{
    //It's LogView's duty to show Import Info, Free Space Info, Export Info, BASE Relocation Info
    extern const char *g_pszIMPORT;
    extern const char *g_pszFreeSpace;
    extern const char *g_pszEXPORT;
    extern const char *g_pszBASERELC;
    if (0 == strTblName.Compare(g_pszIMPORT)
        ||0 == strTblName.Compare(g_pszFreeSpace)
        ||0 == strTblName.Compare(g_pszEXPORT)
        ||0 == strTblName.Compare(g_pszBASERELC))
    {
        return;
    }

    //just need to set the header.
    static CMainFrame* pMainFrame = reinterpret_cast<CMainFrame*>(AfxGetMainWnd());
    static CListCtrl &ctrl        = GetListCtrl();
    CHeaderCtrl *pHeader          = ctrl.GetHeaderCtrl(); 
    
    int nCount = pHeader->GetItemCount();
    int i;
    for (i = 0; i < nCount; i++)
    {
        ctrl.DeleteColumn(0);
    }

    ctrl.DeleteAllItems();

    CString strCols = GetHDRInfoByDir(strTblName);
    CString strSub  = _T("");
    for (i = 0; ; i++)
    {
        if (!AfxExtractSubString(strSub, strCols, i, '|')
            || 0 == strSub.GetLength())
        {
            break;
        }
        
        //we use alias
        ctrl.InsertColumn(i, strSub, LVCFMT_LEFT, 70);
    }

    const char *pszInfo = GetItemInfoByDir(strTblName);
    if (pszInfo != NULL)
    {
        SetSelResults(pszInfo);
    }
}

/************************************************************************/
/* ����Ӧ��Ϣչʾ��ListView��                                                                     */
/************************************************************************/
void CTblInfoView::SetSelResults(const char *pszRet)
{    
    static CListCtrl &ctrl = GetListCtrl();
    CHeaderCtrl *pHeader = ctrl.GetHeaderCtrl(); 
    int nCount = pHeader->GetItemCount();
    
    ctrl.DeleteAllItems();
    
    CString strCols = pszRet;
    CString strSub = _T("");
    
    int nItem    = 0;
    int nSubItem = 0;
    int nIndex   = 0;
    
    LVITEM lv;
    lv.mask  = LVIF_TEXT;
    
    for (int i = 0; ; i++)
    {
        if (!AfxExtractSubString(strSub, strCols, i, '|')
            || 0 == strSub.GetLength())
        {
            break;
        }
        
        nItem       = i / nCount;
        nSubItem    = i % nCount;
        
        lv.iItem    = nItem;//0; //nItem;
        lv.iSubItem = nSubItem;
        lv.pszText  = strSub.GetBuffer(0);
        
        if (0 == nSubItem)
        {
            nIndex = ctrl.InsertItem(&lv);
        }
        else
        {
            ctrl.SetItem(&lv);
        }
    }   
}

/************************************************************************/
/* ˫��ʱ����ListView�л���EditView, ��ģ��DataGrid                     */
/************************************************************************/
void CTblInfoView::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
    NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
    if (-1 == pNMListView->iItem)
    {
        //no item selected
        return;
    }
    
    static CListCtrl &ctrl = GetListCtrl();
    ctrl.SetRedraw(FALSE);
    
    int nItem       = pNMListView->iItem;
    int nSubItem    = pNMListView->iSubItem;
    m_nItem         = nItem;
    m_nSubItem      = nSubItem;
    
    //verify which colum cannot be editted
    //TDB
    //we just add id as the 1st column(Member), 2nd column(Offset), 3rd column(size), 5th column(meaning)
    if (0 == nSubItem
        ||1 == nSubItem
        ||2 == nSubItem
        ||4 == nSubItem)
    {
        return;
    }
    
    //��˫����row, col�ػ�edit,
    if (m_pEdit != NULL)
    {
        delete m_pEdit;
        m_pEdit = NULL;
    }
    
    CInfoEdit *pEdit = new CInfoEdit();
    if (NULL == pEdit)
    {
        return;
    }
    
    //make sure to clean up
    m_pEdit = pEdit;
    
    pEdit->Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN, 
        CRect(0, 0, 0, 0), 
        this, 
        1);	
    
    //��ȡ��Ӧ��Χ
    CRect rc;
    ctrl.GetSubItemRect(nItem, nSubItem, LVIR_LABEL, rc);
    
    CString strItem = ctrl.GetItemText(nItem, nSubItem);
    pEdit->MoveWindow(&rc);	
    pEdit->ShowWindow(SW_SHOW);
    pEdit->SetWindowText(strItem);
    pEdit->SetFocus();
    pEdit->SetSel(0, -1);   //select all the text
    
    ctrl.SetRedraw(TRUE);
    
    *pResult = 0;
}

/************************************************************************/
/* ����ListView���Ի��EditView                                                                     */
/************************************************************************/
void CTblInfoView::OnMSGEditEnd(WPARAM wParam,LPARAM lParam)
{
    CString strSub;
    m_pEdit->GetWindowText(strSub);
    
    static CListCtrl &ctrl = GetListCtrl();
    ctrl.SetItemText(m_nItem, m_nSubItem, strSub);

    ::MessageBox(NULL, "Sure", NULL, MB_OK);
}

#if 0
/************************************************************************/
/* �ԡ��������˵�����Ӧ���������������ķ�ģ̬�Ի���                    */
/************************************************************************/
void CTblInfoView::OnOperate() 
{
    CHelpDlg *pdlg = new CHelpDlg(this);
    if (NULL == pdlg)
    {
        return;
    }
    
    BOOL bRet = pdlg->Create(IDD_DLG_HELP,this);
    if (!bRet)
    {
        delete pdlg;
        return;
    }
    
    pdlg->ShowWindow(SW_SHOW);	   
}

/************************************************************************/
/* ������ز������ͣ��Լ�ListView���й���ʾ                                                                     */
/************************************************************************/
void CTblInfoView::OnSearch()
{
    m_Operation = INFO_TYPE_SELECT;

    SetHitInfo();
}

void CTblInfoView::OnAdd()
{
    m_Operation = INFO_TYPE_INSERT;

    SetHitInfo();
}

void CTblInfoView::OnDel()
{
    static CListCtrl &ctrl = GetListCtrl();
    int nItem = ctrl.GetSelectionMark();
    if (-1 == nItem)
    {
        AfxMessageBox("��ѡ���в���");
        return;
    }

    m_Operation = INFO_TYPE_DEL;

	//should not do this until submitted
    //ctrl.DeleteItem(nItem);

    OnSubmit();      
}

void CTblInfoView::OnModify()
{
    static CListCtrl &ctrl = GetListCtrl();
    int nItem = ctrl.GetSelectionMark();
    if (-1 == nItem)
    {
        AfxMessageBox("��ѡ���в�����Ȼ���ύ");
        return;
    }

    m_Operation = INFO_TYPE_UPDATE; 
}

void CTblInfoView::OnCancel()
{
    m_Operation = OP_NONE;
}

void CTblInfoView::OnSubmit()
{
    if (OP_NONE == m_Operation)
    {
        AfxMessageBox("��δѡ���йز���");
        return;
    }

    static CMainFrame *pMainFrame = reinterpret_cast<CMainFrame*>(AfxGetMainWnd());
    static CNetWork *pNet         = &pMainFrame->m_Nets;

    //��ȡ����ֶ�
    static CListCtrl &ctrl = GetListCtrl();
    int nItem = ctrl.GetSelectionMark();
    if (-1 == nItem)
    {
        return;
    }

    //��ȡͷ�������Ϣ
    CHeaderCtrl *pHeader = ctrl.GetHeaderCtrl(); 
    int nCount = pHeader->GetItemCount();

    TCHAR  szBuffer[MAXBYTE];
    HDITEM hdi;
    hdi.mask        = HDI_TEXT;
    hdi.pszText     = szBuffer;
    hdi.cchTextMax  = MAXBYTE;

    CString strSub; 
    CString strCol;
    CString strInfo = "";
    int i = 0;
    int j = 0;
    for (i = 0; i < nCount; i++)
    {
        strSub = ctrl.GetItemText(nItem, i);
        if (0 == strSub.Compare(PAD)
            || 0 == strSub.GetLength())
        {
            continue;
        }

        j++;    //�ǿ��ֶ�

        pHeader->GetItem(i, &hdi);
        strCol = hdi.pszText;

        //alias process
        strInfo += pNet->GetOriName(strCol);
        strInfo += SEP;
        strInfo += strSub;
        strInfo += SEP;
    }

    //check
    if ((INFO_TYPE_INSERT == m_Operation
            || INFO_TYPE_UPDATE == m_Operation
            )
        && j < nCount - 1)
    {
        AfxMessageBox("�ֶβ��������޷�����");
        return;
    }

    if (m_pCurReq != NULL)
    {
        delete m_pCurReq;
        m_pCurReq = NULL;
    }

    //���ֶΡ����ݡ�������Ϣ����M Server
    m_pCurReq = new CRequest(m_Operation, m_strCurTbl, strInfo);
    if (NULL == m_pCurReq)
    {
        //sth wrong
        m_Operation = OP_NONE;
        return;
    }

    //δ�ӱ��ػ����ѯ����������߷ǲ�ѯ������ֱ��ת��M Server����
    if (!QueryLocalCache(m_pCurReq))
    {
        pNet->SendRequest(m_pCurReq);
    }
   
    m_Operation = OP_SUBMITTING;    
}

/************************************************************************/
/* ����ѯ���ý��չʾ��ListView��                                                                     */
/************************************************************************/
void CTblInfoView::SetSelResults(const char *pszRet)
{    
    //update local cache
    m_map_req_resp[m_strQueryReq] = pszRet;

    //make sure m_strCurTbl  matches the results.
    //so, OP_SUBMITTING is added
    static CMainFrame* pMainFrame = reinterpret_cast<CMainFrame*>(AfxGetMainWnd());
    static CListCtrl &ctrl = GetListCtrl();
    CHeaderCtrl *pHeader = ctrl.GetHeaderCtrl(); 
    int nCount = pHeader->GetItemCount();

    ctrl.DeleteAllItems();
    
    CString strCols = pszRet;
    CString strSub = _T("");

    int nItem    = 0;
    int nSubItem = 0;
    int nIndex   = 0;

    LVITEM lv;
    lv.mask  = LVIF_TEXT;

    for (int i = 0; ; i++)
    {
        if (!AfxExtractSubString(strSub, strCols, i, '|')
            || 0 == strSub.GetLength())
        {
            break;
        }

        nItem       = i / nCount;
        nSubItem    = i % nCount;

        lv.iItem    = nIndex;//0; //nItem;
        lv.iSubItem = nSubItem;
        lv.pszText  = strSub.GetBuffer(0);

        if (0 == nSubItem)
        {
            nIndex = ctrl.InsertItem(&lv);
        }
        else
        {
            ctrl.SetItem(&lv);
        }
    }   

    m_Operation = OP_NONE;
}

void CTblInfoView::SetHitInfo()
{
    CListCtrl &ctrl = GetListCtrl();
    ctrl.DeleteAllItems();
    
    CHeaderCtrl *pHeader = ctrl.GetHeaderCtrl(); 
    int nCount = pHeader->GetItemCount();
    
    LVITEM lv;
    lv.mask  = LVIF_TEXT;
    lv.iItem = 0;
    for (int i = 0; i < 1/*nCount*/; i++)
    {
        lv.iSubItem = i;
        lv.pszText = PAD;
        
        if (0 == i)
        {
            ctrl.InsertItem(&lv);
        }
        else
        {
            ctrl.SetItem(&lv);
        }
    }
}

/************************************************************************/
/* ����CRequest �������ǵ���Ϣ�����ȴӱ��ػ����ѯ�����Ҳ���ܶԱ��ػ���������

Return  : TRUE�����ػ�������ͬ������ �����µ����̡�
          FALSE, ���ػ���û����ͬ������Ҫ��ԭ�����̡�

2��Client�����ݵı���: { request : response}
3��Client�˲�ѯʱ���ӱ��ء����Ǵ�Զ�˵�Э������
    a)�ȴӱ��ػ����У���ѯ������ͬ��request ���ڡ�
    b)��������ڣ�����ԭ�����̣���Զ�˷���request.
    c)������ڣ�������Զ�����������޸�ʱ�䡣
    d)��Ҫͬ�����ƣ������յ������޸�ʱ��Ӧ����������жϡ�
    e)������ؼ�¼ʱ�䣬��Զ�������޸�ʱ����ͬ����ӱ��ػ�����ȥrequest����Ӧ��response��Ϊ�����
    f)���򣬰���ԭ�����̣���Զ�˷���request��
    ͬʱ�����±��ؼ�¼ʱ�䡣                                                                  */
/************************************************************************/
BOOL CTblInfoView::QueryLocalCache(CRequest *pReq)
{
    //suppose need remote access
    m_bRemote = TRUE;

    //��������ɾ���Ĳ�����Ӧ��ձ��ػ��棬Ȼ��������M Server
    if (pReq->m_Operation != INFO_TYPE_SELECT)
    {
        m_map_req_resp.clear();
        return FALSE;
    }

    // tblname|req as the key
    m_strQueryReq = "";
    m_strQueryReq.Format("%s|%s", pReq->m_strTbl, pReq->m_strReq);

    //if no such request exists, 
    if (0 == m_map_req_resp.count(m_strQueryReq))
    {
        return FALSE;
    }

    //now seems need local access, but not determined yet
    m_bRemote = FALSE;

    //get update time first.
    static CMainFrame *pMainFrame = reinterpret_cast<CMainFrame*>(AfxGetMainWnd());
    static CNetWork *pNet         = &pMainFrame->m_Nets;
	gs_pNet = pNet;
    pNet->GetUpdateTime(); 
    
    return TRUE;
}

/************************************************************************/
/* �洢���յ���UpdateTime,
ͬʱ������UpdateTime�Ĳ��죬�������ػ���Ŀ�����                      */
/************************************************************************/
void CTblInfoView::SetUpdateTime(const char *pszUpdateTime)
{
    //already being remote access, just update the time is ok
    if (m_bRemote)
    {
        m_strUpdateTime = pszUpdateTime;
        return;
    }

    //if be the latest, then load the local cache directly
    if (0 == 
        m_strUpdateTime.Compare(pszUpdateTime)
        )
    {
        AfxMessageBox("Local Cache Hit!!");
        SetSelResults(m_map_req_resp[m_strQueryReq]);
        m_Operation = OP_NONE;
        return;
    }   

    //if not, then the M Server's turn, and we need to clear the local cache
    m_map_req_resp.clear();
	m_bRemote = TRUE;

    gs_pNet->SendRequest(m_pCurReq);      
}

static void ShowErrorMessage()
{
    LPVOID lpMsgBuf;
    FormatMessage( 
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM | 
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        ::GetLastError(),
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
        (LPTSTR) &lpMsgBuf,
        0,
        NULL 
        );
    
    ::MessageBox( NULL, (LPCTSTR)lpMsgBuf, "Error", MB_OK | MB_ICONINFORMATION );
    LocalFree(lpMsgBuf);
}

/************************************************************************/
/* ���ڴ��еĻ����¼���浽�ļ���
updatetime$req1$resp1$req2$resp2$req3$resp3$                     */
/************************************************************************/
void CTblInfoView::SaveLocalCache()
{
    //prepare the content firstly
    CString strContent = "";

    //updatetime
    strContent += m_strUpdateTime;
    strContent += SEP_RECORD;


    map<CString, CString>::iterator it;
    for (it = m_map_req_resp.begin(); 
         it != m_map_req_resp.end(); 
         it++)
    {
        strContent += it->first;
        strContent += SEP_RECORD;
        strContent += it->second;
        strContent += SEP_RECORD;
    }
    
    //now write to file
    HANDLE hFile = ::CreateFile(CACHE_FILE, 
                                GENERIC_WRITE,          //desired access
                                FILE_SHARE_READ,        //share mode
                                NULL,                   //Security
                                CREATE_ALWAYS,
                                FILE_ATTRIBUTE_NORMAL,
                                NULL);

    if (INVALID_HANDLE_VALUE == hFile)
    {
        ShowErrorMessage();
        return;
    }	

    DWORD dwLen      = strContent.GetLength();
    DWORD dwWriteLen = 0;
    BOOL  bRet       = FALSE;

    bRet = WriteFile(hFile, 
                    (LPCVOID)strContent.GetBuffer(0),
                    dwLen, 
                    &dwWriteLen, 
                    NULL
                    );

    if (!bRet)
    {
        ShowErrorMessage();
    }
   
    CloseHandle(hFile);
}

/************************************************************************/
/* Load the stored local cache into memory                              */
/************************************************************************/
void CTblInfoView::LoadLocalCache()
{
    //read into memory
    HANDLE hFile = ::CreateFile(CACHE_FILE,
                                GENERIC_READ,   //desired access
                                FILE_SHARE_READ, //share mode
                                NULL,           //security
                                OPEN_ALWAYS,
                                FILE_ATTRIBUTE_NORMAL,
                                NULL);
    if (INVALID_HANDLE_VALUE == hFile)
    {
        ShowErrorMessage();
        return;
    }

    DWORD dwLen = ::GetFileSize(hFile, NULL);
    if (INVALID_FILE_SIZE == dwLen)
    {
        ShowErrorMessage();
		CloseHandle(hFile);
        return;
    }

    if (0 == dwLen)
    {
		CloseHandle(hFile);
        return;
    }

    char *pBuff = NULL;
    pBuff = new char[dwLen];
    if (NULL == pBuff)
    {
        return;
    }

    DWORD dwReadLen = 0;
    BOOL bRet       = FALSE;
    bRet = ::ReadFile(hFile,
                      (LPVOID)pBuff,
                      dwLen,
                      &dwReadLen,
                      NULL
                      );
    
    if (!bRet)
    {
        ShowErrorMessage();
    }
    CloseHandle(hFile);

    //now load into our map
    CString strContent = "";
    if (pBuff != NULL)
    {
        strContent = pBuff;
        delete[] pBuff;
        pBuff = NULL;
    }
    
    if (!AfxExtractSubString(m_strUpdateTime, strContent, 0, SEP_RECORD))
    {
        return;
    }

    CString strReq  = _T(""); 
    CString strResp = _T("");
    
    for (int i = 1; ; i += 2)
    {
        //req
        if (!AfxExtractSubString(strReq, strContent, i, SEP_RECORD)
            || 0 == strReq.GetLength())
        {
            break;
        }

        //resp
        if (!AfxExtractSubString(strResp, strContent, i + 1, SEP_RECORD)
            || 0 == strResp.GetLength())
        {
            break;
        }

        m_map_req_resp[strReq] = strResp;
    }

	return;
}

#endif