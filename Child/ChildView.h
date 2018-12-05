
// ChildView.h: CChildView 클래스의 인터페이스
//

#pragma once


class CChildView : public CView
{
protected: // serialization에서만 만들어집니다.
	CChildView() noexcept;
	DECLARE_DYNCREATE(CChildView)

// 특성입니다.
public:
	CChildDoc* GetDocument() const;
	BOOL m_bDrawMode;
	int m_x1, m_y1, m_x2, m_y2;
	BOOL m_bMouseIn;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CChildView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
};

#ifndef _DEBUG  // ChildView.cpp의 디버그 버전
inline CChildDoc* CChildView::GetDocument() const
   { return reinterpret_cast<CChildDoc*>(m_pDocument); }
#endif

