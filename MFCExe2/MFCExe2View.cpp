#pragma warning : (disable 4996)
// MFCExe2View.cpp: CMFCExe2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCExe2.h"
#endif

#include "MFCExe2Doc.h"
#include "MFCExe2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExe2View

IMPLEMENT_DYNCREATE(CMFCExe2View, CView)

BEGIN_MESSAGE_MAP(CMFCExe2View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	//ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	
	//메세지와 연결해준다
	ON_COMMAND(ID_FONT, &CMFCExe2View::OnFont)
	ON_COMMAND(ID_BK, &CMFCExe2View::OnBackcolor)
	ON_COMMAND(ID_FK, &CMFCExe2View::OnForecolor)
	ON_COMMAND(ID_TR, &CMFCExe2View::OnBkmode)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFCExe2View 생성/소멸

CMFCExe2View::CMFCExe2View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_bTransparent = FALSE;
	m_colorText = RGB(0, 0, 255);
	m_colorBk = RGB(255, 255, 0);

	m_logFont.lfHeight = 100;
	m_logFont.lfWidth = 0;
	m_logFont.lfEscapement = 0;
	m_logFont.lfOrientation = 0;
	m_logFont.lfWeight = FW_NORMAL;
	m_logFont.lfItalic = FALSE;
	m_logFont.lfUnderline = FALSE;
	m_logFont.lfStrikeOut = FALSE;
	m_logFont.lfCharSet = DEFAULT_CHARSET;
	m_logFont.lfOutPrecision = OUT_CHARACTER_PRECIS;
	m_logFont.lfClipPrecision = CLIP_CHARACTER_PRECIS;
	m_logFont.lfQuality = DEFAULT_QUALITY;
	m_logFont.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	strcpy(m_logFont.lfFaceName, _T("Times New Roman"));
}

CMFCExe2View::~CMFCExe2View()
{
}

BOOL CMFCExe2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.
	if (!CWnd::PreCreateWindow(cs)) return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(
		CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), NULL, NULL);
	return CView::PreCreateWindow(cs);
}

// CMFCExe2View 그리기

void CMFCExe2View::OnDraw(CDC* pDC)
{
	/*CMFCExe2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;*/

	/*CRect rect;
	GetClientRect(&rect);

	CFont newFont, *pOldFont;
	newFont.CreatePointFontIndirect(&m_logFont);

	pOldFont = (CFont *)pDC->SelectObject(&newFont);

	pDC->SetTextColor(m_colorText);
	pDC->SetBkColor(m_colorBk);

	if (m_bTransparent) pDC->SetBkMode(TRANSPARENT);
	else pDC->SetBkMode(OPAQUE);

	pDC->DrawText("HelloWorld", &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);*/

	/*CPoint point;
	for (POSITION pos = m_ArrList.GetHeadPosition(); pos != NULL; m_ArrList.GetNext(pos)) {
		point = m_ArrList.GetAt(pos);
		pDC->Rectangle(point.x - 25, point.y - 25, point.x + 25, point.y + 25);

	}*/

	/*CRect rect;
	GetClientRect(&rect);

	CPen pen, *pOldPen;
	pen.CreatePen(PS_DOT, 1, RGB(rand() % 256, rand() % 256, rand() % 256));
	pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(0, rect.bottom / 2);
	pDC->LineTo(rect.right, rect.bottom / 2);
	pDC -> MoveTo(rect.right / 2, 0);
	pDC->LineTo(rect.right / 2, rect.bottom);
	pDC->SelectObject(pOldPen);

	CPoint* pPoint = new CPoint[6];
	for (int i = 0; i < 5; i++) {
		int x = rand() % rect.Width();
		int y = rand() % rect.Height();
		pPoint[i].x = x;
		pPoint[i].y = y;
	}
	pPoint[5] = pPoint[0];
	CBrush brush, *pOldBrush;
	brush.CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
	pOldBrush = pDC->SelectObject(&brush);
	pDC->Polygon(pPoint, 6);
	pDC->SelectObject(pOldBrush);
	delete[] pPoint;*/

	//호환성있는 메모리DC를 생성
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	//리소스에서 비트맵을 읽어들여DC에 선택
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	CBitmap *pOldBitmap = (CBitmap *)MemDC.SelectObject(&bitmap);

	//비트맵 크기정보 얻기
	BITMAP bmpInfo;
	bitmap.GetBitmap(&bmpInfo);

	//StretchBlt시 깨짐방지
	pDC->SetStretchBltMode(COLORONCOLOR);

	//비트맵 블록 전송
	pDC->BitBlt(0, 0, 200, 200, &MemDC, 0, 0, SRCCOPY);

	//상하좌우 뒤집어 출력
	pDC->StretchBlt(210, 0, 200, 200, &MemDC, bmpInfo.bmWidth, bmpInfo.bmHeight,
		-bmpInfo.bmWidth, -bmpInfo.bmHeight, SRCCOPY);

	//2배확대하여 출력
	pDC->StretchBlt(420, 0, 200, 200, &MemDC, 0, 0, bmpInfo.bmWidth,
		bmpInfo.bmHeight, SRCCOPY);
	//DC복원
	MemDC.SelectObject(pOldBitmap);
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFCExe2View 진단

#ifdef _DEBUG
void CMFCExe2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExe2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExe2Doc* CMFCExe2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExe2Doc)));
	return (CMFCExe2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExe2View 메시지 처리기


void CMFCExe2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/*CDC *pDC = GetDC();
	pDC->Rectangle(point.x - 25, point.y - 25, point.x + 25, point.y + 25);
	ReleaseDC(pDC);*/

	/*CClientDC dc(this);
	dc.Rectangle(point.x - 25, point.y - 25, point.x + 25, point.y + 25);*/

	/*m_ArrList.AddTail(point);
	Invalidate();
	KillTimer(0);*/
	m_Pt1 = m_Pt2 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCExe2View::OnInitialUpdate()
{
	//CView::OnInitialUpdate();
	//SetTimer(0, 1000, NULL);//0번이벤트를 100동안 호출
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}



void CMFCExe2View::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(0);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

#define OBJ_LINE 0
#define OBJ_RECTANGLE 1
#define OBJ_ELLIPSE 2
#define OBJ_ROUNDRECT 3
#define OBJ_CHORD 4
#define OBJ_PIE 5

void CMFCExe2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CRect rect;
	CBrush brush, *pOldBrush;
	CPen pen, *pOldPen;

	int x1, y1, x2, y2, x3, y3, x4, y4;
	int r, g, b;
	int nObject;

	GetClientRect(rect);

	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;
	brush.CreateSolidBrush(RGB(r, g, b));
	pOldBrush = (CBrush*)dc.SelectObject(&brush);

	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;
	pen.CreatePen(PS_SOLID, 5, RGB(r, g, b));
	pOldPen = (CPen*)dc.SelectObject(&pen);

	x1 = rand() % rect.right;
	y1 = rand() % rect.bottom;
	x2 = rand() % rect.right;
	y2 = rand() % rect.bottom;
	x3 = rand() % rect.right;
	y3 = rand() % rect.bottom;
	x4 = rand() % rect.right;
	y4 = rand() % rect.bottom;

	nObject = rand() % 6;

	switch (nObject) {
	case OBJ_LINE:
		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y2);
		break;
	case OBJ_RECTANGLE:
		dc.Rectangle(x1, y1, x2, y2);
		break;
	case OBJ_ELLIPSE:
		dc.Ellipse(x1, y1, x2, y2);
		break;
	case OBJ_ROUNDRECT:
		dc.RoundRect(x1, y1, x2, y2, x3, y3); break;
	case OBJ_CHORD:
		dc.Chord(x1, y1, x2, y2, x3, y3, x4, y4);
		break;
	case OBJ_PIE:
		dc.Pie(x1, y1, x2, y2, x3, y3, x4, y4);
		break;
	}

	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);
	CView::OnTimer(nIDEvent);
	CView::OnTimer(nIDEvent);
}


//void CMFCExe2View::OnRButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	SetTimer(0, 1000, NULL);//0번이벤트를 100동안 호출
//	CView::OnRButtonDown(nFlags, point);
//}


void CMFCExe2View::OnMouseMove(UINT nFlags, CPoint point)
{
	//// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//if (nFlags & MK_LBUTTON) {
	//	CClientDC dc(this);

	//	dc.SetROP2(R2_XORPEN);
	//	dc.SelectStockObject(WHITE_PEN);

	//	//지우기
	//	dc.MoveTo(m_Pt1);
	//	dc.LineTo(m_Pt2);

	//	//다시그리기
	//	dc.MoveTo(m_Pt1);
	//	dc.LineTo(point);

	//	m_Pt2 = point;
	//}

	//CView::OnMouseMove(nFlags, point);
}


void CMFCExe2View::OnFont()
{
	// TODO: 여기에 구현 코드 추가.
	CFontDialog dlg(&m_logFont);
	if (dlg.DoModal() == IDOK) {
		dlg.GetCurrentFont(&m_logFont);
		Invalidate();
	}
}


void CMFCExe2View::OnForecolor()
{
	// TODO: 여기에 구현 코드 추가.
	CColorDialog dlg(m_colorText);
	if (dlg.DoModal() == IDOK) {
		m_colorText = dlg.GetColor();
		Invalidate();
	}
}


void CMFCExe2View::OnBackcolor()
{
	// TODO: 여기에 구현 코드 추가.
	CColorDialog dlg(m_colorBk);
	if (dlg.DoModal() == IDOK) {
		m_colorBk = dlg.GetColor();
		Invalidate();
	}
}


void CMFCExe2View::OnBkmode()
{
	// TODO: 여기에 구현 코드 추가.
	m_bTransparent = !m_bTransparent;
	Invalidate();
}


void CMFCExe2View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	OnDraw(&dc);
	//CRect rect;
	//GetClientRect(&rect);//내가 그릴 영역 가져오기
	//CPen pen(PS_SOLID/*실선*/, 5/*굵기*/, RGB(rand() % 256, rand() % 256, rand() % 256)), *pOldPen;
	//CBrush brush(HS_CROSS, RGB(0, 255, 0)), brush1, *pOldBrush;
	//pOldBrush = dc.SelectObject(&brush);
	//dc.Rectangle(&rect);
	//dc.SelectObject(pOldBrush);

	////타원
	//dc.SelectStockObject(BLACK_PEN);
	//dc.SelectStockObject(NULL_BRUSH);
	//dc.Ellipse(100, 50, 200, 200);

	////다각형
	//dc.SelectStockObject(NULL_PEN);
	//dc.SelectStockObject(LTGRAY_BRUSH);
	//POINT points[] = { {200,50},{350,150},{300,200},{250,150},{200,100} };
	//dc.Polygon(points, 5);

	//pOldPen = dc.SelectObject(&pen);
	///*밀폐된 공간*/brush1.CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));

	//pOldBrush = dc.SelectObject(&brush1);
	//dc.Rectangle(400, 50, 600, 250);
	//dc.SelectObject(pOldPen);
	//dc.SelectObject(pOldBrush);
}
