
// KEYView.h: CKEYView 클래스의 인터페이스
//

#pragma once


class CKEYView : public CView
{
protected: // serialization에서만 만들어집니다.
	CKEYView() noexcept;
	DECLARE_DYNCREATE(CKEYView)

// 특성입니다.
public:
	CKEYDoc* GetDocument() const;

// 작업입니다.
public:
	int m_xPos, m_yPos;
	int m_xMax, m_yMax;
	BOOL m_bFill;

	CArray<TCHAR, TCHAR> m_str;
	CArray<TCHAR, TCHAR> m_strTemp;
	int m_nLine;

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CKEYView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
//	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
};

#ifndef _DEBUG  // KEYView.cpp의 디버그 버전
inline CKEYDoc* CKEYView::GetDocument() const
   { return reinterpret_cast<CKEYDoc*>(m_pDocument); }
#endif

