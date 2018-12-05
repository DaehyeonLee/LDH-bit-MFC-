
// RB_testView.cpp: CRBtestView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "RB_test.h"
#endif

#include "RB_testDoc.h"
#include "RB_testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRBtestView

IMPLEMENT_DYNCREATE(CRBtestView, CView)

BEGIN_MESSAGE_MAP(CRBtestView, CView)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CRBtestView 생성/소멸

CRBtestView::CRBtestView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CRBtestView::~CRBtestView()
{
}

BOOL CRBtestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CRBtestView 그리기

void CRBtestView::OnDraw(CDC* /*pDC*/)
{
	CRBtestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CRBtestView 진단

#ifdef _DEBUG
void CRBtestView::AssertValid() const
{
	CView::AssertValid();
}

void CRBtestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRBtestDoc* CRBtestView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRBtestDoc)));
	return (CRBtestDoc*)m_pDocument;
}
#endif //_DEBUG


// CRBtestView 메시지 처리기
CRBtestDoc *doc;
HDC hdc;
PAINTSTRUCT ps;
TCHAR str[128] = { 0, };
static DrawInfo draw_info;
HWND hWnd;
HINSTANCE g_hInst;

void CRBtestView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					// TODO: 여기에 메시지 처리기 코드를 추가합니다.
					// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	//CRBtestDoc *doc;
	hdc = (HDC)BeginPaint(&ps);
	doc->DrawBoard(&draw_info, hdc);
	EndPaint(&ps);
	return ;
}



int CRBtestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	/*if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;*/


	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	/*HWND hWnd;
	HINSTANCE g_hInst;*/
	hEdit_Input = CreateWindow(_T("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
		95, 10, 80, 20, hWnd, (HMENU)IDC_EDIT_INPUT, g_hInst, NULL);
	CreateWindow(_T("button"), _T("Insert"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 35, 80, 30, hWnd, (HMENU)IDC_BUTTON_INSERT, g_hInst, NULL);
	CreateWindow(_T("button"), _T("Delete"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		95, 35, 80, 30, hWnd, (HMENU)IDC_BUTTON_DELETE, g_hInst, NULL);
	//CRBtestDoc *doc;
	doc->InitialInfo(&draw_info);
	draw_info.hWnd = hWnd;

	return 0;
}



BOOL CRBtestView::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	hEdit_Input = hWnd;
	//CRBtestDoc *doc;
	switch (LOWORD(wParam)) {
		case IDC_EDIT_INPUT:
			switch (HIWORD(wParam)) {
			case EN_CHANGE:
				//GetWindowText(hEdit_Input, str, 128);
				if (_tcslen(str) > 0) {
					draw_info.b_flag_eidt_input = TRUE;
					_tcscpy_s(draw_info.str_edit_input, _countof(draw_info.str_edit_input), str);
				}
				else {
					doc->EraseNode(&draw_info);
					doc->InitialInfo(&draw_info);
				}
				InvalidateRect(NULL, 1);
				break;
			}
			break;
		case IDC_BUTTON_INSERT:
			if (draw_info.b_flag_eidt_input)
				SetTimer(IDC_TIMER_INSERT, 50, 0);
			break;
		case IDC_BUTTON_DELETE:
			if (draw_info.b_flag_eidt_input) {
				doc->Erase_Node(&draw_info);
				doc->InitialInfo(&draw_info);
				InvalidateRect(NULL, 1);
			}
			break;
		}
		return 0;
	//return CView::OnCommand(wParam, lParam);
}



void CRBtestView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnTimer(nIDEvent);
	//CRBtestDoc *doc;
	switch (LOWORD(nIDEvent)) {
	case IDC_TIMER_INSERT:
		if (draw_info.b_flag_eidt_input) {
			if (draw_info.node.cX >= draw_info.node.nX && draw_info.node.cY >= draw_info.node.nY) {
				KillTimer(IDC_TIMER_INSERT);
				doc->Insert_Node(&draw_info);
				doc->InitialInfo(&draw_info);
				InvalidateRect(NULL, 1);
			}
			else {
				if (draw_info.node.cX < draw_info.node.nX)		draw_info.node.cX += 5;
				if (draw_info.node.cY < draw_info.node.nY)		draw_info.node.cY += 5;
				doc->EraseNode(&draw_info);
			}
		}
		break;
	}
	return ;
}


void CRBtestView::OnDestroy()
{
	CView::OnDestroy();
	PostQuitMessage(0);
	return ;
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
