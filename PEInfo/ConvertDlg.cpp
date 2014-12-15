// ConvertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PEInfo.h"
#include "ConvertDlg.h"

#include "PE.H"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConvertDlg dialog


CConvertDlg::CConvertDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConvertDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConvertDlg)
	m_nAddrType = -1;
	m_strAddrValue = _T("");
	m_strFA = _T("");
	m_strRVA = _T("");
	m_strVA = _T("");
	m_strSectionName = _T("");
	m_HexValue = _T("");
	m_szValue = _T("");
	//}}AFX_DATA_INIT
}


void CConvertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConvertDlg)
	DDX_CBIndex(pDX, IDC_AddrType, m_nAddrType);
	DDX_Text(pDX, IDC_AddrValue, m_strAddrValue);
	DDX_Text(pDX, IDC_EditFA, m_strFA);
	DDX_Text(pDX, IDC_EditRVA, m_strRVA);
	DDX_Text(pDX, IDC_EditVA, m_strVA);
	DDX_Text(pDX, IDC_EditSection, m_strSectionName);
	DDX_Text(pDX, IDC_EditHexValue, m_HexValue);
	DDX_Text(pDX, IDC_EditStrValue, m_szValue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConvertDlg, CDialog)
	//{{AFX_MSG_MAP(CConvertDlg)
	ON_BN_CLICKED(IDC_Convert, OnConvert)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConvertDlg message handlers
#define  ADDR_FA     0
#define  ADDR_RVA    1
#define  ADDR_VA     2

extern BOOL g_bHasFile;

void CConvertDlg::OnConvert() 
{
    UpdateData();

    if (!g_bHasFile)
    {
        MessageBox("请选打开exe文件!");
        return;
    }

    if (_T("") == m_strAddrValue
        || -1 == m_nAddrType
        //More to be checked
        )
    {
        MessageBox("请选择地址类型，输入合法的地址!");
        return;
    }

    static tagAddrMAP *pAddrMap = new tagAddrMAP;
    ASSERT(pAddrMap != NULL);

    if (ADDR_FA == m_nAddrType)
    {
        pAddrMap->m_dwFA = strtoul(m_strAddrValue, NULL, 16);
        pAddrMap->m_AddrType = tagAddrMAP::enu_AddrType::FA;
    }
    else if (ADDR_RVA == m_nAddrType)
    {
        pAddrMap->m_dwRVA = strtoul(m_strAddrValue, NULL, 16);
        pAddrMap->m_AddrType = tagAddrMAP::enu_AddrType::RVA;
    }
    else if (ADDR_VA == m_nAddrType)
    {
        pAddrMap->m_dwVA = strtoul(m_strAddrValue, NULL, 16);
        pAddrMap->m_AddrType = tagAddrMAP::enu_AddrType::VA;
    }

    if (!GetAddrMAP(pAddrMap))
    {
        return;
    }

    //now set info
    m_strFA.Format("%p", pAddrMap->m_dwFA);
    m_strRVA.Format("%p", pAddrMap->m_dwRVA);
    m_strVA.Format("%p", pAddrMap->m_dwVA);
    m_strSectionName.Format("%s", pAddrMap->m_szSectionName);
    
    char szBuf[64] = {0};
    for (int i = 0; i < 2 * IMAGE_SIZEOF_SHORT_NAME; i++)
    {
        wsprintf(szBuf, "%s%02X ", szBuf, pAddrMap->m_HexValue[i]);
    }
    m_HexValue = szBuf;
    m_szValue = pAddrMap->m_szValue;

    UpdateData(FALSE);
}
