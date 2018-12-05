//일반 C =>__cdecl 방식
//#include <stdio.h>

#include <windows.h>
#if 0
int main() {
	printf("Hello world\n");
	return 0;
}
#endif 

//windows C
#if 0
#include <windows.h>
int main() {
	MessageBox(NULL, "This is Text", "This is caption", MB_OK);
	return 0;
}
#endif

//win API => __stdcall 방식
//아래와 같이 작성하면 __cdecl방식의 main을 찾기 때문에 빌드 실패
//프로젝트속성->링커->시스템->하위시스템을 console에서 windows로 바꿔준다.
#if 0
#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdshow)
{
	MessageBox(NULL, "Hello World", "Hello", MB_OK);
}
#endif

//기존C와 다르게 window는 마우스로도 입력을 받기때문에 프로그램이 다를수 밖에 없다.
//마우스로 입력을 받으면 OS의 message queue에 들어가고, 그 message를 각 application message queue에 보내준다.
//application이 메세지를 읽고 operation해준다.
//system message queue는 os에 1개밖에 없다.


//main이 호출되기전에 프로세스 컨트롤블럭이 생성된다.
//프로세스 안에 class가 있다.
//프로세스를 관리하는것이 프로세스 컨트롤 블럭
//프로세스를 표현하기 위한것이 윈도우 인데 윈도우를 관리하는것이 윈도우 클래스 블럭
//윈도우를 메모리에 올리기 위해 세팅 하기위해 윈도우 생성
//show로 display

//1.WinMain 생성
#if 0
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdshow) {
	
	return 0;
}
#endif 

//2.윈도우 등록
#if 0
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	static char  szAppName[] = "HwlloWin";
	WNDCLASSEX wndclass; //구조체
	//main이 끝나면 프로그램이 종료되기 때문에 구조체 변수를 local로 지정해줘도 상관없다.

	//윈도우 클래스 블럭, 윈도우를 이런식으로 만들어주세요
	wndclass.cbSize = sizeof(wndclass); //window size
	wndclass.style = CS_HREDRAW | CS_VREDRAW; //horizontal ,vertical 세팅
	wndclass.lpfnWndProc = DefWindowProc;; //WndProc
	wndclass.cbClsExtra = 0; //여분 메모리 세팅
	wndclass.cbWndExtra = 0; //여분 메모리 세팅
	wndclass.hInstance = hInstance; //porcess control block 연동
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //아이콘 모양 
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); 
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //background color setting
	wndclass.lpszMenuName = NULL; //menu setting
	wndclass.lpszClassName = szAppName; //window name
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION); 

	RegisterClassEx(&wndclass); //class 등록
	return 0;
}
#endif

//3.윈도우 생성 -> 윈도우를 띄우려면 메모리에 setting해줘야 하므로
#if 0
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmcLine, int iCmdShow) {
	static char szAppName[] = "HelloWin";
	HWND hwnd;
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = DefWindowProc; //WndProc
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	//윈도우 생성하기,return을 handle로 해준다
	hwnd = CreateWindow(szAppName, // window class name
		"The Hello Program", //window caption
		WS_OVERLAPPEDWINDOW, //window style, 다른 윈도우 활성화시 덮히는것
		CW_USEDEFAULT, //initial x position, x의 위치
		CW_USEDEFAULT, //initial y position, y의 위치
		CW_USEDEFAULT, //initial x size, x부터 size
		CW_USEDEFAULT, //initial y size, y부터 size
		NULL,  //parent window handle
		NULL, //window menu handle
		hInstance, //program instance handle
		NULL); //creation parameters

	return 0;
}
#endif 

//4.show
#if 0
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmcLine, int iCmdShow) {
	static char szAppName[] = "HelloWin";
	HWND hwnd;
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = DefWindowProc; //WndProc
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName, // window class name
		"The Hello Program", //window caption
		WS_OVERLAPPEDWINDOW, //window style, 다른 윈도우 활성화시 덮히는것
		CW_USEDEFAULT, //initial x position, x의 위치
		CW_USEDEFAULT, //initial y position, y의 위치
		CW_USEDEFAULT, //initial x size, x부터 size
		CW_USEDEFAULT, //initial y size, y부터 size
		NULL,  //parent window handle
		NULL, //window menu handle
		hInstance, //program instance handle
		NULL); //creation parameters

	//비디오 메모리로 윈도우가 카피되서 show가 실행된다.
	ShowWindow(hwnd, iCmdShow);
	while(1){ }
	return 0;
}
#endif 

//5.show
#if 0
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmcLine, int iCmdShow) {
	static char szAppName[] = "HelloWin";
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = DefWindowProc; //WndProc
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName, // window class name
		"The Hello Program", //window caption
		WS_OVERLAPPEDWINDOW, //window style, 다른 윈도우 활성화시 덮히는것
		CW_USEDEFAULT, //initial x position, x의 위치
		CW_USEDEFAULT, //initial y position, y의 위치
		CW_USEDEFAULT, //initial x size, x부터 size
		CW_USEDEFAULT, //initial y size, y부터 size
		NULL,  //parent window handle
		NULL, //window menu handle
		hInstance, //program instance handle
		NULL); //creation parameters

	ShowWindow(hwnd, iCmdShow);
	while (GetMessage(&msg, NULL, 0, 0)) {
		DispatchMessage(&msg);
	}
	return 0;
}
#endif 

//5.message loop
#if 0
#include<windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static char szAppName[] = "HELLOWIN";
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = DefWindowProc;
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
		"The Hello Progream",
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
		DispatchMessage(&msg);
	}
	return 0;
}
#endif

//6.window procedure
#if 0
#include<windows.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) { //os가 호출(callback함수)
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect; //범위
	static int  i = 0;
	switch (iMsg) {
	case WM_CREATE: //생성
			return 0;
	case WM_PAINT: //화면을 다시그려야한다.
		
		hdc = BeginPaint(hwnd, &ps); //그림을 그릴 펜을 만들기
		GetClientRect(hwnd, &rect);
		i++;
		rect.bottom += i;
		rect.left += i;
		DrawText(hdc, "Hello , Window", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER); //그림을 그리는 함수
		EndPaint(hwnd, &ps);
		/*
		hdc = GetDC(hwnd);
		MoveToEx(hdc, 0, 0, NULL);
		LineTo(hdc, i, i);
		i++;
		ReleaseDC(hwnd, hdc);
		Sleep(500);
		*/
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}//switch
	return DefWindowProc(hwnd, iMsg, wParam, lParam); //내가 처리하지않고 윈도우가 처리해야하는 내용을 처리해준다.
	//return 값이 꼭 있어야한다.
}//WndProc()

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static char szAppName[] = "HELLOWIN";
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	//wndclass.lpfnWndProc -> 함수 call해주는 부분
	//DefWindowproc -> callback함수, 사용자가 아닌 os가 함수를 호출한다. 함수 포인터 타입
	//함수 이름을 넣어줘야 함수가 call된다.
	//함수를 호출해달라고 커널에게 알려주는것.
	wndclass.lpfnWndProc = WndProc; //DefWindowproc
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
		"The Hello Progream",
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
	/*
	while (GetMessage(&msg, NULL, 0, 0)) { //어플리케이션 큐에서 값을 가지고 오는 함수
		//이벤트가 없는 상황에서는 GetMessage가 기다리다가 메세지가 발생하면 가지고온다.
		DispatchMessage(&msg); //메세지를 내가 원하는 형태로 필터링하고 커널로 던져주는 부분.
		//커널이 메세지를 받아서 내가 등록한 함수로 return해준다.
	}
	*/
	while (1) {
		//if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
		if(GetMessage(&msg,NULL,0,0)){
			if (msg.message == WM_QUIT)break;
			DispatchMessage(&msg);
		}
		static int i = 0;
		char buffer[8];
		wsprintf(buffer, "%d\n", i++);
		OutputDebugString(buffer);
	}
	return 0;
}
#endif
//show를 하면 메모리에있던 창들이 비디오 메모리에 카피되서 올라오고 시각적으로 표현된다.
//여러개의 창을 띄우면 create된 여러개의 창이 메모리에 각각 저장되어있고
//뒤에있는 창을 앞으로 옮기면 짤려있던부분을 메모리에서 가지고와서 덮어쓰기된다.




