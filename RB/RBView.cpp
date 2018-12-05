
// RBView.cpp: CRBView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "RB.h"
#endif

#include "RBDoc.h"
#include "RBView.h"
#include "myDefine.h"
#include "Drawboard.h"
#include "RBTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRBView

IMPLEMENT_DYNCREATE(CRBView, CView)

BEGIN_MESSAGE_MAP(CRBView, CView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CRBView 생성/소멸

CRBView::CRBView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CRBView::~CRBView()
{
}

BOOL CRBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CRBView 그리기

void CRBView::OnDraw(CDC* /*pDC*/)
{
	CRBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CRBView 진단

#ifdef _DEBUG
void CRBView::AssertValid() const
{
	CView::AssertValid();
}

void CRBView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRBDoc* CRBView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRBDoc)));
	return (CRBDoc*)m_pDocument;
}
#endif //_DEBUG


// CRBView 메시지 처리기


int CRBView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	//if (CView::OnCreate(lpCreateStruct) == -1)
		//return -1;

	//CEdit m_editNum;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	m_editNum.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
		CRect(95, 10, 175, 30), this, IDC_EDIT_INPUT);
	m_insertButton.Create(_T("Insert") , WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		CRect(10, 35, 90, 65), this ,IDC_BUTTON_INSERT); //insert 버튼
	m_deleteButton.Create(_T("Delete"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		CRect(95, 35, 175, 65),this, IDC_BUTTON_DELETE ); //delete 버튼
	
	InitialInfo(&draw_info);
	draw_info.hWnd = hWnd;
	return 0;
}


void CRBView::OnDestroy()
{
	CView::OnDestroy();
	PostQuitMessage(0);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CRBView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnTimer(nIDEvent);
	switch (nIDEvent) {
	case IDC_TIMER_INSERT:
		if (draw_info.b_flag_eidt_input) {
			if (draw_info.node.cX >= draw_info.node.nX && draw_info.node.cY >= draw_info.node.nY) {
				KillTimer(IDC_TIMER_INSERT);
				Insert_Node(&draw_info);
				InitialInfo(&draw_info);
				//InvalidateRect(hWnd, NULL, 1);
				Invalidate();
			}
			else {
				if (draw_info.node.cX < draw_info.node.nX)		draw_info.node.cX += 5;
				if (draw_info.node.cY < draw_info.node.nY)		draw_info.node.cY += 5;
				EraseNode(&draw_info);
				Invalidate();
			}
		}
		break;
	}
}


void CRBView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

	//hdc = BeginPaint(hWnd, &ps);
	DrawBoard(&draw_info, dc);
	//EndPaint(hWnd, &ps);
}


BOOL CRBView::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	
	switch (LOWORD(wParam)) {
	case IDC_EDIT_INPUT:
		switch (HIWORD(wParam)) {
		case EN_CHANGE:
			m_editNum.GetWindowText(str);
			if (_tcslen(str) > 0) {
				draw_info.b_flag_eidt_input = TRUE;
				_tcscpy_s(draw_info.str_edit_input, _countof(draw_info.str_edit_input), str);
			}
			else {
				EraseNode(&draw_info);
				InitialInfo(&draw_info);
			}
			//InvalidateRect(hWnd, NULL, 1);
			Invalidate();
			break;
		}
		break;
	case IDC_BUTTON_INSERT:
		if (draw_info.b_flag_eidt_input)
			SetTimer(IDC_TIMER_INSERT, 50, 0);
		break;
	case IDC_BUTTON_DELETE:
		if (draw_info.b_flag_eidt_input) {
			Erase_Node(&draw_info);
			InitialInfo(&draw_info);
			//InvalidateRect(hWnd, NULL, 1);
			Invalidate();
		}
		break;
	}

	return CView::OnCommand(wParam, lParam);
}
