
// LineDrawingView.cpp: CLineDrawingView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "LineDrawing.h"
#endif

#include "LineDrawingDoc.h"
#include "LineDrawingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLineDrawingView

IMPLEMENT_DYNCREATE(CLineDrawingView, CView)

BEGIN_MESSAGE_MAP(CLineDrawingView, CView)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CLineDrawingView 생성/소멸

CLineDrawingView::CLineDrawingView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CLineDrawingView::~CLineDrawingView()
{
}

BOOL CLineDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CLineDrawingView 그리기

void CLineDrawingView::OnDraw(CDC* pDC)
{

	/*using Gdiplus::Font;
	CRect rect;
	GetClientRect(rect);

	Graphics graphics(pDC->m_hDC);
	TCHAR string[] = _T("대한사람 대한으로 길이 보전하세");

	FontFamily fontFamily(_T("궁서체"));
	Font font(&fontFamily, 24, FontStyleBold, UnitPixel);

	SolidBrush brush(Color(255, 0, 0, 255));
	
	StringFormat stringFormat;
	stringFormat.SetAlignment(StringAlignmentCenter);
	stringFormat.SetLineAlignment(StringAlignmentCenter);

	PointF pointF(rect.Width() / 2.0f, rect.Height() / 2.0f);
	graphics.DrawString(string, (INT)wcslen(string), &font, pointF, &stringFormat, &brush);

	graphics.SetTextRenderingHint(TextRenderingHintClearTypeGridFit);

	RectF rectF(150, 20, 200, 100);
	graphics.DrawString(string, (INT)wcslen(string), &font, rectF, &stringFormat, &brush);
	Pen pen(Color(255, 255, 0, 0));
	graphics.DrawRectangle(&pen, rectF);*/

	/*Graphics graphics(pDC->m_hDC);

	Image image(_T("son.jpg"));
	int width = image.GetWidth();
	int height = image.GetHeight();

	graphics.DrawImage(&image, 10, 10, width / 10, height / 10);

	Point points[] = { Point(250,20),Point(200,100),Point(350,50) };
	graphics.DrawImage(&image, points, 3);

	graphics.SetInterpolationMode(
		InterpolationModeNearestNeighbor);
	graphics.DrawImage(&image, 10, 150, width / 7, width / 7);

	graphics.SetInterpolationMode(InterpolationModeHighQualityBilinear);
	graphics.DrawImage(&image, 300, 150, width / 7, width / 7);*/

	/*Graphics graphics(pDC->m_hDC);
	for (int i = 0; i < HatchStyleTotal; i++) {
		HatchBrush brush((Gdiplus::HatchStyle)i, Color(255, 0, 0, 255), Color(255, 100, 255, 100));
		graphics.FillRectangle(&brush, 20 + (i % 7) * 90, 20 + (i / 7) * 60, 80, 50);
	}*/

	/*CLineDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	Graphics graphics(pDC->m_hDC);

	LinearGradientBrush linerBrush(Point(50, 100), Point(400, 250), Color(255, 0, 255, 0), Color(255, 0, 0, 255));
	graphics.FillRectangle(&linerBrush, 50, 100, 300, 150);

	GraphicsPath path;
	path.AddEllipse(50, 300, 300, 150);

	int count = 1;
	PathGradientBrush pathBrush(&path);

	pathBrush.SetCenterColor(Color(255, 0, 0, 255));
	pathBrush.SetSurroundColors(&Color(255, 255, 255, 0), &count);
	graphics.FillEllipse(&pathBrush, 50, 300, 300, 150);*/

	/*Graphics graphics(pDC->m_hDC);

	CRect rect;
	GetClientRect(&rect);
	int x = 0, y = 0;

	SolidBrush brush(Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256));

	x = rand() % rect.Width();
	y = rand() % rect.Height();
	graphics.FillRectangle(&brush, x, y, 200, 100);

	brush.SetColor(Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256));
	x = rand() % rect.Width();
	y = rand() % rect.Height();
	graphics.FillEllipse(&brush, x, y, 200, 100);

	brush.SetColor(Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256));
	x = rand() % rect.Width();
	y = rand() % rect.Height();
	graphics.FillPie(&brush, x, y, 200, 200, 135, 90);

	brush.SetColor(Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256));

	Point* pPoints = new Point[6];
	for (int j = 0; j < 6; j++) {
		x = rand() % rect.Width();
		y = rand() % rect.Height();
		pPoints[j].X = x;
		pPoints[j].Y = y;

	}
	graphics.FillClosedCurve(&brush, pPoints, 6, FillModeAlternate, 1);
	delete[] pPoints;*/

	/*Graphics graphics(pDC->m_hDC);
	Pen  pen(Color(255, 0, 0, 0), 3);

	pen.SetDashStyle(DashStyleSolid);
	graphics.DrawLine(&pen, 50, 50, 400, 50);

	pen.SetDashStyle(DashStyleDash);
	graphics.DrawLine(&pen, 50, 100, 400, 100);

	pen.SetDashStyle(DashStyleDot);
	graphics.DrawLine(&pen, 50, 150, 400, 150);

	pen.SetDashStyle(DashStyleDashDot);
	graphics.DrawLine(&pen, 50, 200 , 400, 200);

	pen.SetDashStyle(DashStyleDashDotDot);
	graphics.DrawLine(&pen, 50, 250, 400, 250);

	pen.SetDashOffset(5);
	graphics.DrawLine(&pen, 50, 250, 400, 250);

	REAL dashVals[4] = { 5,1,2,1 };
	pen.SetDashPattern(dashVals, 4);
	graphics.DrawLine(&pen, 50, 310, 400, 310);*/

	/*Graphics graphics(pDC->m_hDC);

	Pen capPen(Color(255, 0, 0, 0), 5);

	capPen.SetStartCap(LineCapSquare);
	capPen.SetEndCap(LineCapRound);
	graphics.DrawLine(&capPen, 50, 50, 400, 50);

	capPen.SetStartCap(LineCapTriangle);
	capPen.SetEndCap(LineCapNoAnchor);
	graphics.DrawLine(&capPen, 50, 100, 400, 100);

	capPen.SetStartCap(LineCapSquareAnchor);
	capPen.SetEndCap(LineCapRoundAnchor);
	graphics.DrawLine(&capPen, 50, 150, 400, 150);

	capPen.SetStartCap(LineCapDiamondAnchor);
	capPen.SetEndCap(LineCapArrowAnchor);
	graphics.DrawLine(&capPen, 50, 200, 400, 200);

	Pen joinPen(Color(255, 0, 0, 0), 10);

	joinPen.SetLineJoin(LineJoinBevel);
	graphics.DrawRectangle(&joinPen, 50, 250, 100, 100);

	joinPen.SetLineJoin(LineJoinMiter);
	graphics.DrawRectangle(&joinPen, 180, 250, 100, 100);

	joinPen.SetLineJoin(LineJoinRound);
	graphics.DrawRectangle(&joinPen, 310, 250, 100, 100);*/

	/*Graphics graphics(pDC->m_hDC);
	Pen pen(Color(255, 0, 0, 0), 3);

	int i = 0;
	Point points[] = { Point(30,30),Point(120,50),
					Point(170,40),Point(160,20),
					Point(280,100),Point(150,90),
					Point(90,70),Point(50,130) };
	int pointNum = sizeof(points) / sizeof(points[0]);
	graphics.DrawPolygon(&pen, points, pointNum);

	for (i = 0; i < pointNum; i++) {
		points[i].X += 300;
	}
	graphics.DrawClosedCurve(&pen, points, pointNum, 0.5f);
	for (i = 0; i < pointNum; i++) {
		points[i].X += 300;
	}
	graphics.DrawClosedCurve(&pen, points, pointNum, 1);

	for (i = 0; i < pointNum; i++) {
		points[i].X -= 600;
		points[i].X += 200;
	}
	graphics.DrawCurve(&pen, points, pointNum, 0);

	for (i = 0; i < pointNum; i++) {
		points[i].X += 300;
	}
	graphics.DrawCurve(&pen, points, pointNum, 0.5);

	for (i = 0; i < pointNum; i++) {
		points[i].X += 300;
	}
	graphics.DrawCurve(&pen, points, pointNum, 1);*/

	/*Graphics graphics(pDC->m_hDC);
	Pen pen(Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256), 4);
	SolidBrush brush(Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256));

	graphics.DrawLine(&pen, 50, 50, 500, 50);
	graphics.DrawRectangle(&pen, 50, 100, 200, 100);
	graphics.FillRectangle(&brush, 300, 100, 200, 100);
	graphics.DrawEllipse(&pen, 50, 250, 200, 200);
	graphics.FillEllipse(&brush, 300, 250, 200, 200);
	graphics.DrawPie(&pen, 550, 100, 200, 200, 225, 90);
	graphics.FillPie(&brush, 550, 300, 200, 200, 225, 90);
	graphics.DrawArc(&pen, 800, 100, 200, 200, 225, 90);*/

	

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CLineDrawingView 진단

#ifdef _DEBUG
void CLineDrawingView::AssertValid() const
{
	CView::AssertValid();
}

void CLineDrawingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLineDrawingDoc* CLineDrawingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLineDrawingDoc)));
	return (CLineDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CLineDrawingView 메시지 처리기


void CLineDrawingView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);

	Pen RedPen(Color(255, 255, 0, 0), 2.0f);
	Pen GreenPen(Color(255, 0, 255, 0), 2.0f);
	Pen BluePen(Color(255, 0, 0, 255), 2.0f);

	Point points[6] = { Point(10,150), Point(110,10), Point(170,250),Point(220,120),Point(270,150),Point(350,150) };
	graphics.DrawCurve(&RedPen, points, 6, 0.0f);
	graphics.DrawCurve(&GreenPen, points, 6, 0.5f);
	graphics.DrawCurve(&BluePen, points, 6, 1.0f);

}
