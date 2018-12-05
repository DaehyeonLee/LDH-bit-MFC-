#include "stdafx.h"
#include "CObject.h"
#include "resource.h"

void CObject::InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow) {
	hInst = hInstance;
	wndclass.cbSize = sizeof(wndclass); //������ ����ü ������
	wndclass.style = CS_HREDRAW | CS_VREDRAW; //����,����
	wndclass.lpfnWndProc = WndProc; // �ݹ� �Լ�
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	//wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //Ÿ��Ʋ ������
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	//wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //��׶��� �÷�
	//wndclass.lpszMenuName = NULL; //�޴�
	wndclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1); //�޴�
	wndclass.lpszClassName = szAppName;
	//wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		"CDC step 2",
		WS_OVERLAPPEDWINDOW, //������ ���� ��ġ�� �����ϰ�
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