#if !defined(AFX_TBLTREEVIEW_H__CA82A23F_346B_4F3B_B91B_468FAAB5FE44__INCLUDED_)
#define AFX_TBLTREEVIEW_H__CA82A23F_346B_4F3B_B91B_468FAAB5FE44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TblTreeView.h : header file
//
#include <afxcview.h>

/////////////////////////////////////////////////////////////////////////////
// CTblTreeView view

/************************************************************************/
/* 视图分割中，为用户展示可操作的信息表项    
当用户选择某表名时，触发List View显示相应的字段信息                         */
/************************************************************************/

class CTblTreeView : public CTreeView
{
protected:
	CTblTreeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTblTreeView)

// Attributes
public:

// Operations
public:
	BOOL LoadTblTree(CString &strFileName, const char *pszTblNames);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTblTreeView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTblTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CTblTreeView)
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TBLTREEVIEW_H__CA82A23F_346B_4F3B_B91B_468FAAB5FE44__INCLUDED_)
