
// RB_testView.h: CRBtestView 클래스의 인터페이스
//

#pragma once


class CRBtestView : public CView
{
protected: // serialization에서만 만들어집니다.
	CRBtestView() noexcept;
	DECLARE_DYNCREATE(CRBtestView)

// 특성입니다.
public:
	CRBtestDoc* GetDocument() const;

// 작업입니다.
public:
	
// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CRBtestView();
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
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // RB_testView.cpp의 디버그 버전
inline CRBtestDoc* CRBtestView::GetDocument() const
   { return reinterpret_cast<CRBtestDoc*>(m_pDocument); }
#endif

