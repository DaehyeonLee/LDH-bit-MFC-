
// KEYView.cpp: CKEYView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "KEY.h"
#endif

#include "KEYDoc.h"
#include "KEYView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKEYView

IMPLEMENT_DYNCREATE(CKEYView, CView)

BEGIN_MESSAGE_MAP(CKEYView, CView)
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_CREATE()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

// CKEYView 생성/소멸

CKEYView::CKEYView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_xPos = m_yPos = 60;
	m_bFill = FALSE;
}

CKEYView::~CKEYView()
{
}

BOOL CKEYView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CKEYView 그리기

void CKEYView::OnDraw(CDC* /*pDC*/)
{
	CKEYDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CKEYView 진단

#ifdef _DEBUG
void CKEYView::AssertValid() const
{
	CView::AssertValid();
}

void CKEYView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKEYDoc* CKEYView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKEYDoc)));
	return (CKEYDoc*)m_pDocument;
}
#endif //_DEBUG


// CKEYView 메시지 처리기


void CKEYView::OnSetFocus(CWnd* pOldWnd)
{
	CreateSolidCaret(20, 20);
	SetCaretPos(CPoint(50, 50));
	ShowCaret();
	CView::OnSetFocus(pOldWnd);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CKEYView::OnKillFocus(CWnd* pNewWnd)
{
	HideCaret();
	::DestroyCaret();
	CView::OnKillFocus(pNewWnd);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CKEYView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	/*CBrush brush, *pOldBrush;
	if (m_bFill == TRUE) {
		brush.CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
		pOldBrush = dc.SelectObject(&brush);
	}
	dc.Rectangle(m_xPos - 20, m_yPos - 20, m_xPos + 20, m_yPos + 20);

	if (m_bFill) dc.SelectObject(pOldBrush);*/
//	CPaintDC dc(this);
	CFont font;
	font.CreatePointFont(150, _T("Arial"));
	dc.SelectObject(&font);

	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(m_str.GetData(), m_str.GetSize(), &rect, DT_LEFT);
	SIZE sizex, sizey;
	::GetTextExtentPoint(dc.m_hDC, m_strTemp.GetData(), m_strTemp.GetSize(), &sizex);
	::GetTextExtentPoint(dc.m_hDC, m_str.GetData(), m_str.GetSize(), &sizey);
	SetCaretPos(CPoint(sizex.cx, m_nLine*sizey.cy));

}


void CKEYView::OnSize(UINT nType, int cx, int cy)
{
	m_xMax = cx;
	m_yMax = cy;
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CKEYView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar) {
	case VK_LEFT: m_xPos -= 20; break;
	case VK_RIGHT: m_xPos += 20; break;
	case VK_UP: m_yPos -= 20; break;
	case VK_DOWN: m_yPos += 20; break;
	case VK_SPACE: m_bFill = !m_bFill;
	}
	m_xPos = min(max(20, m_xPos), m_xMax - 20);
	m_yPos = min(max(20, m_yPos), m_yMax - 20);
	Invalidate(FALSE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CKEYView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nChar == VK_BACK) {
		if (m_str.GetSize() > 0) {
			m_str.RemoveAt(m_str.GetSize() - 1);
			m_strTemp.RemoveAt(m_strTemp.GetSize() - 1);
		}
	}
	else if (nChar == VK_RETURN) {
		CClientDC dc(this);
		m_nLine++;
		m_str.Add(nChar);
		m_strTemp.RemoveAll();
	}
	else {
		m_str.Add(nChar);
		m_strTemp.Add(nChar);
	}
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}


//BOOL CKEYView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
//{
//	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
//
//	return CView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
//}


int CKEYView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	CreateSolidCaret(20, 20);
	SetCaretPos(CPoint(50, 50));
	ShowCaret();
	m_nLine = 0;
	return 0;
}


void CKEYView::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	HideCaret();
	::DestroyCaret();

	CView::OnClose();
}
