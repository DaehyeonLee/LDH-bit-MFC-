#pragma once
#include "CVIew.h"

class PaintDC {
private:
	CView* pView;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect;

public:
	PaintDC(CView* pView);
	virtual ~PaintDC();
	void DrawTextDC();
	void GetClientRect();

};
