#if !defined(AFX_DUMPDLG_H__7A71550A_E77F_4105_99A2_A4A10D072C00__INCLUDED_)
#define AFX_DUMPDLG_H__7A71550A_E77F_4105_99A2_A4A10D072C00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DumpDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDumpDlg dialog

class CDumpDlg : public CDialog
{
// Construction
public:
	CDumpDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDumpDlg)
	enum { IDD = IDD_DLG_DUMP };
	CButton	m_BtnDumpFix;
	CButton	m_BtnTList;
	CButton	m_BtnDump;
	CButton	m_BtnSelect;
	DWORD	m_dwPID;
	//}}AFX_DATA

protected:
    CString m_strModuleName;
    BYTE *m_pModBase;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDumpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDumpDlg)
	afx_msg void OnBtnTlist();
	afx_msg void OnBtnSelect();
	afx_msg void OnBtnDump();
	afx_msg void OnBtnDumpFix();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DUMPDLG_H__7A71550A_E77F_4105_99A2_A4A10D072C00__INCLUDED_)
