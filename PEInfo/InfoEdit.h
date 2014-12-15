#if !defined(AFX_INFOEDIT_H__50EED899_CC09_4BA6_9774_9C64504A96B7__INCLUDED_)
#define AFX_INFOEDIT_H__50EED899_CC09_4BA6_9774_9C64504A96B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InfoEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInfoEdit window

/************************************************************************/
/* 同ListView 结合使用，对信息进行修改, 模拟DataGrid                                                                 */
/************************************************************************/
class CInfoEdit : public CEdit
{
// Construction
public:
	CInfoEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInfoEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CInfoEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CInfoEdit)
	afx_msg void OnEditEnd();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFOEDIT_H__50EED899_CC09_4BA6_9774_9C64504A96B7__INCLUDED_)
