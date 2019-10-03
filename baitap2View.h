
// baitap2View.h : interface of the Cbaitap2View class
//

#pragma once
#include "Hinh.h"
#include "HCN.h"

class Cbaitap2View : public CView
{
protected: // create from serialization only
	Cbaitap2View();
	DECLARE_DYNCREATE(Cbaitap2View)

// Attributes
public:
	Cbaitap2Doc* GetDocument() const;
	CClientDC *pdc;
	CPoint p1, p2;
	HCN hcn1;
// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Cbaitap2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in baitap2View.cpp
inline Cbaitap2Doc* Cbaitap2View::GetDocument() const
   { return reinterpret_cast<Cbaitap2Doc*>(m_pDocument); }
#endif

