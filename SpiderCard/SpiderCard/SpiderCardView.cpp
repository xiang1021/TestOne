
// SpiderCardView.cpp : implementation of the CSpiderCardView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SpiderCard.h"
#endif

#include "SpiderCardDoc.h"
#include "SpiderCardView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSpiderCardView

IMPLEMENT_DYNCREATE(CSpiderCardView, CView)

BEGIN_MESSAGE_MAP(CSpiderCardView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSpiderCardView construction/destruction

CSpiderCardView::CSpiderCardView() noexcept
{
	// TODO: add construction code here

}

CSpiderCardView::~CSpiderCardView()
{
}

BOOL CSpiderCardView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSpiderCardView drawing

void CSpiderCardView::OnDraw(CDC* /*pDC*/)
{
	CSpiderCardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CSpiderCardView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);

	//Test Name


	OnContextMenu(this, point);
}

void CSpiderCardView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSpiderCardView diagnostics

#ifdef _DEBUG
void CSpiderCardView::AssertValid() const
{
	CView::AssertValid();
}

void CSpiderCardView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSpiderCardDoc* CSpiderCardView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSpiderCardDoc)));
	return (CSpiderCardDoc*)m_pDocument;
}
#endif //_DEBUG


// CSpiderCardView message handlers
