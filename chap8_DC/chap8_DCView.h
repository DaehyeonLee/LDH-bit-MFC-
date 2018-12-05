
// chap8_DCView.h: Cchap8DCView 클래스의 인터페이스
//

#pragma once


class Cchap8DCView : public CView
{
	int cyClient;
	int cxClient;

protected: // serialization에서만 만들어집니다.
	Cchap8DCView() noexcept;
	DECLARE_DYNCREATE(Cchap8DCView)

// 특성입니다.
public:
	Cchap8DCDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~Cchap8DCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // chap8_DCView.cpp의 디버그 버전
inline Cchap8DCDoc* Cchap8DCView::GetDocument() const
   { return reinterpret_cast<Cchap8DCDoc*>(m_pDocument); }
#endif

