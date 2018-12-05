
// RBView.h: CRBView 클래스의 인터페이스
//

#pragma once
#include "Drawboard.h"

class CRBView : public CView
{
protected: // serialization에서만 만들어집니다.
	CRBView() noexcept;
	DECLARE_DYNCREATE(CRBView)

// 특성입니다.
public:
	CRBDoc* GetDocument() const;

// 작업입니다.
public:
	CEdit m_editNum;
	CButton m_insertButton;
	CButton m_deleteButton;

	HWND hWnd;
	DrawInfo draw_info;
	CString str;
// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CRBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
};

#ifndef _DEBUG  // RBView.cpp의 디버그 버전
inline CRBDoc* CRBView::GetDocument() const
   { return reinterpret_cast<CRBDoc*>(m_pDocument); }
#endif

