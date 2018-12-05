#pragma once
#include <windows.h>

class CObject {
protected:
	static char szAppName[];
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

public:
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmeShow);
	void Run();
	WPARAM ExitInstance();
};