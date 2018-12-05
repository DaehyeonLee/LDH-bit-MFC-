
// MFCExe2View.h: CMFCExe2View 클래스의 인터페이스
//

#pragma once


class CMFCExe2View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCExe2View() noexcept;
	DECLARE_DYNCREATE(CMFCExe2View)

// 특성입니다.
public:
	CMFCExe2Doc* GetDocument() const;

// 작업입니다.
public:
	CList<CPoint, CPoint&> m_ArrList;
	CPoint m_Pt1, m_Pt2;
	BOOL m_bTransparent;
	COLORREF m_colorText;
	COLORREF m_colorBk;
	LOGFONT m_logFont;
// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMFCExe2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg void OnFont();
	afx_msg void OnForecolor();
	afx_msg void OnBackcolor();
	afx_msg void OnBkmode();

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
protected:
	/*void OnFont();
	void OnForcecolor();
	void OnBackcolor();
	void OnBkmode();*/
public:
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFCExe2View.cpp의 디버그 버전
inline CMFCExe2Doc* CMFCExe2View::GetDocument() const
   { return reinterpret_cast<CMFCExe2Doc*>(m_pDocument); }
#endif

