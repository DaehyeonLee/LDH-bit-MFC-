
// chap8_DCView.cpp: Cchap8DCView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "chap8_DC.h"
#endif

#include "chap8_DCDoc.h"
#include "chap8_DCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cchap8DCView

IMPLEMENT_DYNCREATE(Cchap8DCView, CView)

BEGIN_MESSAGE_MAP(Cchap8DCView, CView)
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cchap8DCView 생성/소멸

Cchap8DCView::Cchap8DCView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cchap8DCView::~Cchap8DCView()
{
}

BOOL Cchap8DCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cchap8DCView 그리기

void Cchap8DCView::OnDraw(CDC* /*pDC*/)
{
	Cchap8DCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// Cchap8DCView 진단

#ifdef _DEBUG
void Cchap8DCView::AssertValid() const
{
	CView::AssertValid();
}

void Cchap8DCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cchap8DCDoc* Cchap8DCView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cchap8DCDoc)));
	return (Cchap8DCDoc*)m_pDocument;
}
#endif //_DEBUG


// Cchap8DCView 메시지 처리기


void Cchap8DCView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	cxClient = cx;
	cyClient = cy;
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

#define NUM 1000
#define TWOPI (2*3.14159)
void Cchap8DCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	POINT pt[NUM];
	CClientDC dc(this);
	dc.MoveTo(0, cyClient / 2);
	dc.LineTo(cxClient, cyClient / 2);

	for (int i = 0; i < NUM; i++) {
		pt[i].x = i * cxClient / NUM;
		pt[i].y = (int)(cyClient / 2 * (1 - sin(TWOPI * i / NUM)));
	}
	dc.Polyline(pt, NUM);
	CView::OnLButtonDown(nFlags, point);
}
