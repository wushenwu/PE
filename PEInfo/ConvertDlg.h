#if !defined(AFX_CONVERTDLG_H__6FB90FE0_7380_4584_A228_C59BA75C1A8E__INCLUDED_)
#define AFX_CONVERTDLG_H__6FB90FE0_7380_4584_A228_C59BA75C1A8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConvertDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConvertDlg dialog

class CConvertDlg : public CDialog
{
// Construction
public:
	void ConvertByRVA();
	void ConvertByFA();
	void ConvertByVA();
	CConvertDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CConvertDlg)
	enum { IDD = IDD_DLG_CONVERT };
	int		m_nAddrType;
	CString	m_strAddrValue;
	CString	m_strFA;
	CString	m_strRVA;
	CString	m_strVA;
	CString	m_strSectionName;
	CString	m_HexValue;
	CString	m_szValue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConvertDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConvertDlg)
	afx_msg void OnConvert();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONVERTDLG_H__6FB90FE0_7380_4584_A228_C59BA75C1A8E__INCLUDED_)
