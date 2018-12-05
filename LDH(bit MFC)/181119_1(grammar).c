//�Ϲ� C =>__cdecl ���
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

//win API => __stdcall ���
//�Ʒ��� ���� �ۼ��ϸ� __cdecl����� main�� ã�� ������ ���� ����
//������Ʈ�Ӽ�->��Ŀ->�ý���->�����ý����� console���� windows�� �ٲ��ش�.
#if 0
#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdshow)
{
	MessageBox(NULL, "Hello World", "Hello", MB_OK);
}
#endif

//����C�� �ٸ��� window�� ���콺�ε� �Է��� �ޱ⶧���� ���α׷��� �ٸ��� �ۿ� ����.
//���콺�� �Է��� ������ OS�� message queue�� ����, �� message�� �� application message queue�� �����ش�.
//application�� �޼����� �а� operation���ش�.
//system message queue�� os�� 1���ۿ� ����.


//main�� ȣ��Ǳ����� ���μ��� ��Ʈ�Ѻ��� �����ȴ�.
//���μ��� �ȿ� class�� �ִ�.
//���μ����� �����ϴ°��� ���μ��� ��Ʈ�� ��
//���μ����� ǥ���ϱ� ���Ѱ��� ������ �ε� �����츦 �����ϴ°��� ������ Ŭ���� ��
//�����츦 �޸𸮿� �ø��� ���� ���� �ϱ����� ������ ����
//show�� display

//1.WinMain ����
#if 0
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdshow) {
	
	return 0;
}
#endif 

//2.������ ���
#if 0
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	static char  szAppName[] = "HwlloWin";
	WNDCLASSEX wndclass; //����ü
	//main�� ������ ���α׷��� ����Ǳ� ������ ����ü ������ local�� �������൵ �������.

	//������ Ŭ���� ��, �����츦 �̷������� ������ּ���
	wndclass.cbSize = sizeof(wndclass); //window size
	wndclass.style = CS_HREDRAW | CS_VREDRAW; //horizontal ,vertical ����
	wndclass.lpfnWndProc = DefWindowProc;; //WndProc
	wndclass.cbClsExtra = 0; //���� �޸� ����
	wndclass.cbWndExtra = 0; //���� �޸� ����
	wndclass.hInstance = hInstance; //porcess control block ����
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //������ ��� 
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); 
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //background color setting
	wndclass.lpszMenuName = NULL; //menu setting
	wndclass.lpszClassName = szAppName; //window name
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION); 

	RegisterClassEx(&wndclass); //class ���
	return 0;
}
#endif

//3.������ ���� -> �����츦 ������ �޸𸮿� setting����� �ϹǷ�
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

	//������ �����ϱ�,return�� handle�� ���ش�
	hwnd = CreateWindow(szAppName, // window class name
		"The Hello Program", //window caption
		WS_OVERLAPPEDWINDOW, //window style, �ٸ� ������ Ȱ��ȭ�� �����°�
		CW_USEDEFAULT, //initial x position, x�� ��ġ
		CW_USEDEFAULT, //initial y position, y�� ��ġ
		CW_USEDEFAULT, //initial x size, x���� size
		CW_USEDEFAULT, //initial y size, y���� size
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
		WS_OVERLAPPEDWINDOW, //window style, �ٸ� ������ Ȱ��ȭ�� �����°�
		CW_USEDEFAULT, //initial x position, x�� ��ġ
		CW_USEDEFAULT, //initial y position, y�� ��ġ
		CW_USEDEFAULT, //initial x size, x���� size
		CW_USEDEFAULT, //initial y size, y���� size
		NULL,  //parent window handle
		NULL, //window menu handle
		hInstance, //program instance handle
		NULL); //creation parameters

	//���� �޸𸮷� �����찡 ī�ǵǼ� show�� ����ȴ�.
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
		WS_OVERLAPPEDWINDOW, //window style, �ٸ� ������ Ȱ��ȭ�� �����°�
		CW_USEDEFAULT, //initial x position, x�� ��ġ
		CW_USEDEFAULT, //initial y position, y�� ��ġ
		CW_USEDEFAULT, //initial x size, x���� size
		CW_USEDEFAULT, //initial y size, y���� size
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
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) { //os�� ȣ��(callback�Լ�)
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect; //����
	static int  i = 0;
	switch (iMsg) {
	case WM_CREATE: //����
			return 0;
	case WM_PAINT: //ȭ���� �ٽñ׷����Ѵ�.
		
		hdc = BeginPaint(hwnd, &ps); //�׸��� �׸� ���� �����
		GetClientRect(hwnd, &rect);
		i++;
		rect.bottom += i;
		rect.left += i;
		DrawText(hdc, "Hello , Window", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER); //�׸��� �׸��� �Լ�
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
	return DefWindowProc(hwnd, iMsg, wParam, lParam); //���� ó�������ʰ� �����찡 ó���ؾ��ϴ� ������ ó�����ش�.
	//return ���� �� �־���Ѵ�.
}//WndProc()

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static char szAppName[] = "HELLOWIN";
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	//wndclass.lpfnWndProc -> �Լ� call���ִ� �κ�
	//DefWindowproc -> callback�Լ�, ����ڰ� �ƴ� os�� �Լ��� ȣ���Ѵ�. �Լ� ������ Ÿ��
	//�Լ� �̸��� �־���� �Լ��� call�ȴ�.
	//�Լ��� ȣ���ش޶�� Ŀ�ο��� �˷��ִ°�.
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
	while (GetMessage(&msg, NULL, 0, 0)) { //���ø����̼� ť���� ���� ������ ���� �Լ�
		//�̺�Ʈ�� ���� ��Ȳ������ GetMessage�� ��ٸ��ٰ� �޼����� �߻��ϸ� ������´�.
		DispatchMessage(&msg); //�޼����� ���� ���ϴ� ���·� ���͸��ϰ� Ŀ�η� �����ִ� �κ�.
		//Ŀ���� �޼����� �޾Ƽ� ���� ����� �Լ��� return���ش�.
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
//show�� �ϸ� �޸𸮿��ִ� â���� ���� �޸𸮿� ī�ǵǼ� �ö���� �ð������� ǥ���ȴ�.
//�������� â�� ���� create�� �������� â�� �޸𸮿� ���� ����Ǿ��ְ�
//�ڿ��ִ� â�� ������ �ű�� ©���ִ��κ��� �޸𸮿��� ������ͼ� �����ȴ�.




