#if !defined(AFX_TBLINFOVIEW_H__926255B7_60F7_4C52_AD62_BE096846616E__INCLUDED_)
#define AFX_TBLINFOVIEW_H__926255B7_60F7_4C52_AD62_BE096846616E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TblInfoView.h : header file
//
#pragma warning(disable: 4786)

#include <afxcview.h>
#include <map>
using namespace std;

#include "InfoEdit.h"

/////////////////////////////////////////////////////////////////////////////
// CTblInfoView view

/************************************************************************/
/* 展示相关信息、与用户交互的关键所在                                  */
/************************************************************************/
class CTblInfoView : public CListView
{
protected:
	CTblInfoView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTblInfoView)

    enum {OP_NONE = 0, OP_SUBMITTING};

public:
    void UpdateListInfo(CString strTblName);
    void SetSelResults(const char *pszRet);
#if 0
	void LoadLocalCache();
	void SaveLocalCache();
	void SetUpdateTime(const char *pszUpdateTime);
	BOOL QueryLocalCache(CRequest *pReq);
    void OnCancel();
    void SetSelResults(const char *pszRet);
    void OnSubmit();
    void OnModify();
    void OnDel();
    void OnAdd();
    void OnSearch();
#endif
	


// Attributes
private:
    CString m_strCurTbl;
    int     m_Operation; 
    CInfoEdit *m_pEdit;

    //which row, col is being operated
    int     m_nItem;
    int     m_nSubItem;

    //local cache
    map<CString, CString> m_map_req_resp;   // request : response
    CString   m_strUpdateTime;
    BOOL      m_bRemote; 

// Operations

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTblInfoView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTblInfoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	void SetHitInfo();
	//{{AFX_MSG(CTblInfoView)
	afx_msg void OnOperate();
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnMSGEditEnd(WPARAM wParam,LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TBLINFOVIEW_H__926255B7_60F7_4C52_AD62_BE096846616E__INCLUDED_)
