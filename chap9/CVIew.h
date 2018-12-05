#pragma once
#include "stdafx.h"
#include "CObject.h"

class CView;

typedef LRESULT(CView::*CViewFunPointer)(WPARAM, LPARAM);
typedef struct tagMessageMap {
	UINT iMsg;
	CViewFunPointer fp;
}MessageMap;

static CViewFunPointer fpCViewGlobal;

#define NUM 1000
#define TWOPI (2*3.14159)

class CView : public CObject {
public:
	CObject::hwnd;
public:
	PAINTSTRUCT ps;
	POINT pt[NUM];
	HDC hdc;
	int cyClient;
	int cxClient;

	int cxIcon;
	int cyIcon;
	HICON hIcon;

	LRESULT OnCreate(WPARAM, LPARAM);
	LRESULT OnDraw(WPARAM, LPARAM);
	LRESULT OnDestroy(WPARAM, LPARAM);
	LRESULT OnLButtonDown(WPARAM, LPARAM);
	LRESULT OnSize(WPARAM, LPARAM);
	LRESULT OnCommand(WPARAM, LPARAM);

	DECLARE_MESSAGE_MAP()
};