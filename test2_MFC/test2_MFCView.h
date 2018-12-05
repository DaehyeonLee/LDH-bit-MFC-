
// test2_MFCView.h: Ctest2MFCView 클래스의 인터페이스
//

#pragma once


class Ctest2MFCView : public CView
{
protected: // serialization에서만 만들어집니다.
	Ctest2MFCView() noexcept;
	DECLARE_DYNCREATE(Ctest2MFCView) //1.정적 구조체 메세지 맵 선언

// 특성입니다.
public:
	Ctest2MFCDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~Ctest2MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point); //2.처리를 원하는 메세지 핸들러의 선언
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // test2_MFCView.cpp의 디버그 버전
inline Ctest2MFCDoc* Ctest2MFCView::GetDocument() const
   { return reinterpret_cast<Ctest2MFCDoc*>(m_pDocument); }
#endif

