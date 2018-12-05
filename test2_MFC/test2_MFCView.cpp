
// test2_MFCView.cpp: Ctest2MFCView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "test2_MFC.h"
#endif

#include "test2_MFCDoc.h"
#include "test2_MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest2MFCView

IMPLEMENT_DYNCREATE(Ctest2MFCView, CView)

BEGIN_MESSAGE_MAP(Ctest2MFCView, CView)
	//	ON_WM_LBUTTONDOWN()
	//3.구조체 메세지 맵의 초기화
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Ctest2MFCView 생성/소멸

Ctest2MFCView::Ctest2MFCView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Ctest2MFCView::~Ctest2MFCView()
{
}

BOOL Ctest2MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Ctest2MFCView 그리기

void Ctest2MFCView::OnDraw(CDC* /*pDC*/)
{
	Ctest2MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// Ctest2MFCView 진단

#ifdef _DEBUG
void Ctest2MFCView::AssertValid() const
{
	CView::AssertValid();
}

void Ctest2MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest2MFCDoc* Ctest2MFCView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest2MFCDoc)));
	return (Ctest2MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// Ctest2MFCView 메시지 처리기


//void Ctest2MFCView::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	//4.구현부
//	CView::OnLButtonDown(nFlags, point);
//}


void Ctest2MFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//::MessageBox(*this, "LButtonUp", "LButton", MB_OK);
	CView::OnLButtonDown(nFlags, point);
}

void Ctest2MFCView::OnLButtonUp(UINT nFlags, CPoint point) {
	::MessageBox(*this, "LButtonUp", "LButton", MB_OK);
	CView::OnLButtonUp(nFlags, point);
}