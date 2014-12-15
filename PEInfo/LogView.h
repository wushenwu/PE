#if !defined(AFX_LOGVIEW_H__49E0718A_9EC1_402D_AC48_FE8B267D400D__INCLUDED_)
#define AFX_LOGVIEW_H__49E0718A_9EC1_402D_AC48_FE8B267D400D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogView view

/************************************************************************/
/* 记录运行时的提示信息，后续可进行文件的保存处理                      */
/************************************************************************/

class CLogView : public CEditView
{
protected:
	CLogView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLogView)

// Attributes
public:

// Operations
public:
    void UpdateInfo(CString strTblName);
    void LogInfo(CString strLog);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CLogView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGVIEW_H__49E0718A_9EC1_402D_AC48_FE8B267D400D__INCLUDED_)
