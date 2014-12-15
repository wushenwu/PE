// PEInfoDoc.cpp : implementation of the CPEInfoDoc class
//

#include "stdafx.h"
#include "PEInfo.h"

#include "PEInfoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPEInfoDoc

IMPLEMENT_DYNCREATE(CPEInfoDoc, CDocument)

BEGIN_MESSAGE_MAP(CPEInfoDoc, CDocument)
	//{{AFX_MSG_MAP(CPEInfoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPEInfoDoc construction/destruction

CPEInfoDoc::CPEInfoDoc()
{
	// TODO: add one-time construction code here

}

CPEInfoDoc::~CPEInfoDoc()
{
}

BOOL CPEInfoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPEInfoDoc serialization

void CPEInfoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPEInfoDoc diagnostics

#ifdef _DEBUG
void CPEInfoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPEInfoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPEInfoDoc commands
