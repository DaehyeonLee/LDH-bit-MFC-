#include "PaintDC.h"

PaintDC::PaintDC(CView *p) {
	pView = p;
	hdc = BeginPaint(pView->hwnd,&ps);
}

PaintDC::~PaintDC() {
	EndPaint(pView->hwnd, &ps);
}

void PaintDC::GetClientRect() {
	::GetClientRect(pView->hwnd, &rect);
}

void PaintDC::DrawTextDC() {
	::DrawText(hdc, "HELLO WINDOW!", -1, &rect,
		DT_SINGLELINE | DT_VCENTER | DT_CENTER);
}