#pragma once
#include "Cview.h"
class CDC {
private:
	CView* pView;
	PAINTSTRUCT ps;

public:
	HDC hdc;
	CDC(CView* pView);
	virtual ~CDC();
	BOOL MoveToEx(int, int, LPPOINT);
	BOOL LineTo(int, int);
	BOOL Polyline(CONST POINT*, int);
};