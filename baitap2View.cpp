
// baitap2View.cpp : implementation of the Cbaitap2View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "baitap2.h"
#endif

#include "baitap2Doc.h"
#include "baitap2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cbaitap2View

IMPLEMENT_DYNCREATE(Cbaitap2View, CView)

BEGIN_MESSAGE_MAP(Cbaitap2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cbaitap2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
//	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cbaitap2View construction/destruction

Cbaitap2View::Cbaitap2View()
{
	// TODO: add construction code here
	
}

Cbaitap2View::~Cbaitap2View()
{
}

BOOL Cbaitap2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cbaitap2View drawing

void Cbaitap2View::OnDraw(CDC* /*pDC*/)
{
	Cbaitap2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pdc = new CClientDC(this);
	hcn1.draw(pdc);
	// TODO: add draw code for native data here
}


// Cbaitap2View printing


void Cbaitap2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cbaitap2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cbaitap2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cbaitap2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Cbaitap2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cbaitap2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cbaitap2View diagnostics

#ifdef _DEBUG
void Cbaitap2View::AssertValid() const
{
	CView::AssertValid();
}

void Cbaitap2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cbaitap2Doc* Cbaitap2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cbaitap2Doc)));
	return (Cbaitap2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cbaitap2View message handlers


void Cbaitap2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p1.x=point.x;
	p1.y=point.y;
	CView::OnLButtonDown(nFlags, point);
}


void Cbaitap2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p2.x = point.x;
	p2.y = point.y;
	CClientDC pdc(this);
	hcn1.thietlap(p1.x,p1.y,p2.x,p2.y);
	hcn1.draw(&pdc);
	CView::OnLButtonUp(nFlags, point);
}


//void Cbaitap2View::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: Add your message handler code here and/or call default
///*	CClientDC pDC(this);
//		hcn1.thietlap(p1.x,p1.y,point.x,point.y);*/
//	CView::OnMouseMove(nFlags, point);
//}
