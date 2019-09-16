
// SpiderCardView.h : interface of the CSpiderCardView class
//

#pragma once


class CSpiderCardView : public CView
{
protected: // create from serialization only
	CSpiderCardView() noexcept;
	DECLARE_DYNCREATE(CSpiderCardView)

// Attributes
public:
	CSpiderCardDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CSpiderCardView();
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
};

#ifndef _DEBUG  // debug version in SpiderCardView.cpp
inline CSpiderCardDoc* CSpiderCardView::GetDocument() const
   { return reinterpret_cast<CSpiderCardDoc*>(m_pDocument); }
#endif

