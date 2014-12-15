// InfoEdit.cpp : implementation file
//

#include "stdafx.h"
#include "InfoEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInfoEdit

CInfoEdit::CInfoEdit()
{
}

CInfoEdit::~CInfoEdit()
{
}


BEGIN_MESSAGE_MAP(CInfoEdit, CEdit)
	//{{AFX_MSG_MAP(CInfoEdit)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, OnEditEnd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInfoEdit message handlers

void CInfoEdit::OnEditEnd() 
{   
    //make the list ctrl update info
    ::PostMessage(GetParent()->GetSafeHwnd(), MSG_EDIT_END, NULL, NULL);
	ShowWindow(SW_HIDE);
}
