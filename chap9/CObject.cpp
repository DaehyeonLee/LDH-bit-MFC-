#include "stdafx.h"
#include "CObject.h"
#include "resource.h"

void CObject::InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow) {
	hInst = hInstance;
	wndclass.cbSize = sizeof(wndclass); //윈도우 구조체 사이즈
	wndclass.style = CS_HREDRAW | CS_VREDRAW; //가로,세로
	wndclass.lpfnWndProc = WndProc; // 콜백 함수
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	//wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //타이틀 아이콘
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	//wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //백그라운드 컬러
	//wndclass.lpszMenuName = NULL; //메뉴
	wndclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1); //메뉴
	wndclass.lpszClassName = szAppName;
	//wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		"CDC step 2",
		WS_OVERLAPPEDWINDOW, //윈도우 끼리 겹치기 가능하게
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
}
void CObject::Run() {
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
WPARAM CObject::ExitInstance() {
	return msg.wParam;
}

char CObject::szAppName[] = "HelloWin";