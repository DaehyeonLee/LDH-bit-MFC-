
// LineDrawingView.h: CLineDrawingView 클래스의 인터페이스
//

#pragma once


class CLineDrawingView : public CView
{
protected: // serialization에서만 만들어집니다.
	CLineDrawingView() noexcept;
	DECLARE_DYNCREATE(CLineDrawingView)

// 특성입니다.
public:
	CLineDrawingDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CLineDrawingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // LineDrawingView.cpp의 디버그 버전
inline CLineDrawingDoc* CLineDrawingView::GetDocument() const
   { return reinterpret_cast<CLineDrawingDoc*>(m_pDocument); }
#endif

