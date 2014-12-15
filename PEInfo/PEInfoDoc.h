// PEInfoDoc.h : interface of the CPEInfoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PEINFODOC_H__03FA00DC_17C5_4CA3_A9ED_18167493E7FC__INCLUDED_)
#define AFX_PEINFODOC_H__03FA00DC_17C5_4CA3_A9ED_18167493E7FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPEInfoDoc : public CDocument
{
protected: // create from serialization only
	CPEInfoDoc();
	DECLARE_DYNCREATE(CPEInfoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPEInfoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPEInfoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPEInfoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PEINFODOC_H__03FA00DC_17C5_4CA3_A9ED_18167493E7FC__INCLUDED_)
