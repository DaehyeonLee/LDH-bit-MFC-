#include <windows.h>
#if 0
//step 1 : WinMain에서 모든걸 처리한다. window를 C로
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	switch (iMsg) {
	case WM_CREATE: return 0;
	case WM_PAINT: hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, "HELLO, WINDOW!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_LBUTTONDOWN:
		hdc = GetDC(hwnd);
		MoveToEx(hdc, 0, 0, NULL);
		LineTo(hdc, 100, 100);
		ReleaseDC(hwnd, hdc);
		return 0;
	case WM_CLOSE:
		hdc = GetDC(hwnd);
		MoveToEx(hdc, 0, 0, NULL);
		LineTo(hdc, 100, 100);
		ReleaseDC(hwnd, hdc);
		Sleep(2000);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	static char szAppName[] = "HelloWin";
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		"The Hello Program",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);

	while (GetMessage(&msg, NULL, 0, 0)) {
		static int i = 0;
		char buffer[80];
		wsprintf(buffer, "%i\n", ++i);
		OutputDebugString(buffer);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}
#endif

#if 0
//step 2: class화, window를 C++로
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
class CApp {
	static char szAppName[];
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

public:
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdshow);
	void Run();
	WPARAM ExitInstance();

	void OnCreate();
	void OnDraw();
	void OnDestroy();
	void OnLButtonDown();
};
void CApp::InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow) {

	//윈도우 등록
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	//메모리에 잡는다.
	hwnd = CreateWindow(szAppName,
		"The Hello Program",
		WS_OVERLAPPEDWINDOW,
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

//메세지 Get
void CApp::Run() {
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

//리턴
WPARAM CApp::ExitInstance() {
	return msg.wParam;
}

char CApp::szAppName[] = "HelloWin";

void CApp::OnCreate() {}

void CApp::OnDraw() {
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	hdc = BeginPaint(hwnd, &ps);
	GetClientRect(hwnd, &rect);
	DrawText(hdc, "hello, window!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	EndPaint(hwnd, &ps);
}

void CApp::OnDestroy() {
	PostQuitMessage(0);
}

void CApp::OnLButtonDown() {
	HDC hdc;
	hdc = GetDC(hwnd);
	MoveToEx(hdc, 0, 0, NULL);
	LineTo(hdc, 100, 100);
	ReleaseDC(hwnd, hdc);
}

CApp app; //객체 전역선언

//메세지에 맞게 함수를 만들어준다.
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	switch (iMsg) {
	case WM_CREATE: app.OnCreate(); return 0;
	case WM_PAINT: app.OnDraw(); return 0;
	case WM_DESTROY: app.OnDestroy(); return 0;
	case WM_LBUTTONDOWN:app.OnLButtonDown(); return 0;
	//case WM_CLOSE:
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	app.InitInstance(hInstance, szCmdLine, iCmdShow);
	app.Run();
	return app.ExitInstance();
}
#endif

#if 0
//step3 : virtual 함수를 사용해서 부모에서 자식의 함수를 사용.
//폐단:미리 선언된 define이 약200개 라서 이렇게 사용하면 오버헤드 발생
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
class CObject {
	//똑같은 부분을 여러번만들지않고 자식들이 상속받는다.
	//부모의 포인터는 모든자식을 건드릴수 있으므로 포인터 사용
	//똑같은 부분------------------------
protected:
	static char szAppName[];
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;
public:
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow);
	void Run();
	WPARAM ExitInstance();
	//------------------------------------

	//message handler
	//CView에서 overriding해서 쓰겠다.
	//함수정의는 CView에서 하겠다. 그래야 내가 원하는값을 그릴수 있으니까
	virtual void OnCreate()=0;
	virtual void OnDraw()=0;
	virtual void OnDestroy()=0;
	virtual void OnLButtonDown() = 0;
};

void CObject::InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow) {
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		"The Hello Program",
		WS_OVERLAPPEDWINDOW,
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

WPARAM CObject::ExitInstance() { return msg.wParam; }

char CObject::szAppName[] = "HelloWin";

CObject *pCObject;

class CView : public CObject {
public:
	void OnCreate();
	void OnDraw();
	void OnDestroy();
	void OnLButtonDown();
};
void CView::OnCreate(){}

void CView::OnDraw(){
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	hdc = BeginPaint(hwnd, &ps);
	GetClientRect(hwnd, &rect);
	DrawText(hdc, "Hello, Windows!", -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	EndPaint(hwnd, &ps);
}
void CView::OnDestroy(){ PostQuitMessage(0); }

void CView::OnLButtonDown() {
	MessageBox(NULL, "MESSAGE", "TITLE", MB_ICONEXCLAMATION | MB_OK);
}

CView app;

//GetMessate로 받으면 윈도우가 callback 함수 호출
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	switch (iMsg) {
	case WM_CREATE:
		pCObject->OnCreate(); return 0;
	case WM_PAINT:
		pCObject->OnDraw(); return 0;
	case WM_DESTROY:
		pCObject->OnDestroy(); return 0;
	case WM_LBUTTONDOWN:
		pCObject->OnLButtonDown(); return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	pCObject = &app;//내가 그릴 객체의 주소를 던져준다. 부모의 포인터로 모든 자식을 컨트롤 할수있으므로.
	//자식 객체의 타입을 알기위해서 나온것이 RTTI
	pCObject->InitInstance(hInstance, szCmdLine, iCmdShow);
	pCObject->Run();
	pCObject->ExitInstance();
}
#endif

#if 0
//step4 : 멤버함수 포인터 테이블을 이용하자.
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
class CObject {
protected:
	static char szAppName[];
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;
public:
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow);
	void Run();
	WPARAM ExitInstance();

	virtual void OnCreate() = 0;
	virtual void OnDraw() = 0;
	virtual void OnDestroy() = 0;
};

void CObject::InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow) {
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		"The Hello Program",
		WS_OVERLAPPEDWINDOW,
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

WPARAM CObject::ExitInstance() { return msg.wParam; }

char CObject::szAppName[] = "HelloWin";

class CView;

typedef void (CView::*CViewFunPointer)(); //함수포인터 type defines

typedef struct tagMessageMap {
	UINT iMsg;
	CViewFunPointer fp;
}MessageMap;

static CViewFunPointer fpCViewGlobal;

class CView : public CObject {
public:
	static MessageMap messageMap[];
public:
	void OnCreate();
	void OnDraw();
	void OnDestroy();
	void OnLButtonDown();
};
MessageMap CView::messageMap[] = {
	{WM_CREATE,&CView::OnCreate},
	{WM_PAINT,&CView::OnDraw},
	{WM_DESTROY,&CView::OnDestroy},
	{WM_LBUTTONDOWN,&CView::OnLButtonDown},
	{0,NULL}
};

void CView::OnCreate() {}

void CView::OnDraw() {
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	hdc = BeginPaint(hwnd, &ps);
	GetClientRect(hwnd, &rect);
	DrawText(hdc, "Hello, Windows!", -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	EndPaint(hwnd, &ps);
}
void CView::OnDestroy() { PostQuitMessage(0); }

void CView::OnLButtonDown() {
	MessageBox(NULL, "MESSAGE", "TITLE", MB_ICONEXCLAMATION | MB_OK);
}

CView app;

//내가 등록한 것만 배열에 넣고 포인터함수를 이용하여 디스플레이
//메모리 효율이 좋아짐.
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	int i = 0;
	while (CView::messageMap[i].iMsg != 0) {
		if (iMsg == CView::messageMap[i].iMsg) {
			fpCViewGlobal = CView::messageMap[i].fp;
			(app.*fpCViewGlobal)();
			return 0;
		}
		++i;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	app.InitInstance(hInstance, szCmdLine, iCmdShow);
	app.Run();
	return app.ExitInstance();
}

#endif

#if 1
#define DECLARE_MESSAGE_MAP() static MessageMap messageMap[];
#define BEGIN_MESSAGE_MAP(class_name) MessageMap\
                           class_name::messageMap[] = {
						   #define END_MESSAGE_MAP() {0,NULL}};

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

class CObject {
protected:
	static char szAppName[];
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

public:
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow);
	void Run();
	WPARAM ExitInstance();
};
void CObject::InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow) {
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		"The Hello Program",
		WS_OVERLAPPEDWINDOW,
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

char CObject::szAppName[] = "HelloWin\n";

class CView;

typedef void (CView::*CViewFunPointer)();
typedef struct tagMessageMap
{
	UINT iMsg;
	CViewFunPointer fp;
}MessageMap;
static CViewFunPointer fpCViewGlobal;

class CView : public CObject {
public:
	void OnCreate();
	void OnDraw();
	void OnDestroy();
	void OnLButtonDown();

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CView)
	{WM_CREATE, &CView::OnCreate},
	{ WM_PAINT, &CView::OnDraw },
	{ WM_DESTROY, &CView::OnDestroy },
	{ WM_LBUTTONDOWN, &CView::OnLButtonDown },
	END_MESSAGE_MAP()


	void CView::OnCreate() {}

	void CView::OnDraw() {
		HDC hdc;
		PAINTSTRUCT ps;
		RECT rect;

		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, "Hello, Windows!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
	}

	void CView::OnDestroy() {
		PostQuitMessage(0);
	}
	void CView::OnLButtonDown() {
		MessageBox(NULL, "MESSAGE", "TITLE", MB_ICONEXCLAMATION | MB_OK);
	}
	CView app;

	LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
		int i = 0;

		while (CView::messageMap[i].iMsg != 0)
		{
			if (iMsg == CView::messageMap[i].iMsg)
			{
				fpCViewGlobal = CView::messageMap[i].fp;
				(app.*fpCViewGlobal)();
				return 0;
			}
			++i;
		}
		return DefWindowProc(hwnd, iMsg, wParam, lParam);
	}

	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
		app.InitInstance(hInstance, szCmdLine, iCmdShow);
		app.Run();
		return app.ExitInstance();
	}
#endif