// PEInfoView.cpp : implementation of the CPEInfoView class
//

#include "stdafx.h"
#include "PEInfo.h"

#include "PEInfoDoc.h"
#include "PEInfoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPEInfoView

IMPLEMENT_DYNCREATE(CPEInfoView, CView)

BEGIN_MESSAGE_MAP(CPEInfoView, CView)
	//{{AFX_MSG_MAP(CPEInfoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPEInfoView construction/destruction

CPEInfoView::CPEInfoView()
{
	// TODO: add construction code here
}

CPEInfoView::~CPEInfoView()
{
}

BOOL CPEInfoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPEInfoView drawing

void CPEInfoView::OnDraw(CDC* pDC)
{
	CPEInfoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPEInfoView printing

BOOL CPEInfoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPEInfoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPEInfoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPEInfoView diagnostics

#ifdef _DEBUG
void CPEInfoView::AssertValid() const
{
	CView::AssertValid();
}

void CPEInfoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPEInfoDoc* CPEInfoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPEInfoDoc)));
	return (CPEInfoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPEInfoView message handlers
