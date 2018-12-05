
// LDH(bit MFC)_chap7View.cpp: CLDHbitMFCchap7View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "LDH(bit MFC)_chap7.h"
#endif

#include "LDH(bit MFC)_chap7Doc.h"
#include "LDH(bit MFC)_chap7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLDHbitMFCchap7View

IMPLEMENT_DYNCREATE(CLDHbitMFCchap7View, CView)

BEGIN_MESSAGE_MAP(CLDHbitMFCchap7View, CView)
END_MESSAGE_MAP()

// CLDHbitMFCchap7View 생성/소멸

CLDHbitMFCchap7View::CLDHbitMFCchap7View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CLDHbitMFCchap7View::~CLDHbitMFCchap7View()
{
}

BOOL CLDHbitMFCchap7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CLDHbitMFCchap7View 그리기

void CLDHbitMFCchap7View::OnDraw(CDC* /*pDC*/)
{
	CLDHbitMFCchap7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CLDHbitMFCchap7View 진단

#ifdef _DEBUG
void CLDHbitMFCchap7View::AssertValid() const
{
	CView::AssertValid();
}

void CLDHbitMFCchap7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLDHbitMFCchap7Doc* CLDHbitMFCchap7View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLDHbitMFCchap7Doc)));
	return (CLDHbitMFCchap7Doc*)m_pDocument;
}
#endif //_DEBUG


// CLDHbitMFCchap7View 메시지 처리기
