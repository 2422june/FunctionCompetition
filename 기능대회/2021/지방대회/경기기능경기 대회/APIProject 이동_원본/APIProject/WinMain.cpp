#include <Windows.h>
#pragma comment(lib, "msimg32.lib")

static HINSTANCE g_instance;
static HWND g_handle;

HBITMAP plainBitmap, bgBitmap;
PAINTSTRUCT ps;
HDC planeDC, hdc, bgDC;
MSG msg;
int x;
int y;



HBITMAP LoadBMF(const char* path) {
	return (HBITMAP)LoadImageA (nullptr, TEXT(path), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
}

void DrawScreen() {
	hdc = GetDC(g_handle);

	BitBlt(hdc, 0, 0, 2000, 1100, bgDC, 0, 0, SRCCOPY);
	BitBlt(hdc, 940 + x, 980 + y, 80, 50, planeDC, 0, 0, SRCCOPY);

	ReleaseDC(g_handle, hdc);
}


//입력처리를 하는 특수한 함수(백그라운드), 윈도우 메세지를 처리하는 함수
LRESULT/**/ CALLBACK/*호출당하지 않는 함수, 특정조건을 만족할때 자동(?) 수행*/ WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_TIMER://특정시간(수정가능)마다 무언가를 수행하는 메세지.
		if (wParam == 1)//1번 타이머가 울렸는가?
		{

			DrawScreen();//스크린에 그려라

		}
		break;

	case WM_CREATE://message == WM_CREATE
		SetTimer(hWnd, 1/*번호*/, (1000 / (float)30), nullptr);//밀리세컨드(1000분의 1초) * 1000 / 30 마다(1초에 30번) 1번 타이머를 작동시켜라
		SetTimer(hWnd, 2, (1000 / (float)200), nullptr);//밀리세컨드(1000분의 1초) * 1000 / 2 마다(1초에 2번) 2번 타이머를 작동시켜라


		hdc = GetDC(g_handle);
		planeDC = CreateCompatibleDC(hdc);
		bgDC = CreateCompatibleDC(hdc);
		ReleaseDC(g_handle, hdc);

		plainBitmap = LoadBMF("../a./MyPlane.bmp"/*path, 경로*/);//..:상위, .:하위 상대주소
		SelectObject(planeDC, plainBitmap);//()안의 정보로 오브젝트 생성

		bgBitmap = LoadBMF("../a./Background.bmp"/*path, 경로*/);//..:상위, .:하위 상대주소
		SelectObject(bgDC, bgBitmap);//()안의 정보로 오브젝트 생성

		break;

	case WM_PAINT:
		hdc = BeginPaint(g_handle, &ps);
		EndPaint(g_handle, &ps);
		DrawScreen();
		break;

	case WM_KEYDOWN:
		if (wParam == VK_LEFT) {
			x -= 20;
		}
		else if (wParam == VK_RIGHT) {
			x += 20;
		}
		else if (wParam == VK_UP) {
			y -= 20;
		}
		else if (wParam == VK_DOWN) {
			y += 20;
		}
		if (wParam == VK_ESCAPE) {
			PostQuitMessage(0);
		}
	
		break;

	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void Create(HINSTANCE hInstance)
{
	g_instance = hInstance;

	WNDCLASSEX wnd_class;
	wnd_class.cbClsExtra = 0;
	wnd_class.cbWndExtra = 0;
	wnd_class.hbrBackground = static_cast<HBRUSH>(GetStockObject(GRAY_BRUSH));
	wnd_class.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wnd_class.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wnd_class.hIconSm = LoadIcon(nullptr, IDI_ERROR);
	wnd_class.hInstance = g_instance;
	wnd_class.lpfnWndProc = WndProc;
	wnd_class.lpszClassName = "APIProject";
	wnd_class.lpszMenuName = nullptr;
	wnd_class.style = CS_HREDRAW | CS_VREDRAW;
	wnd_class.cbSize = sizeof(WNDCLASSEX);

	auto check = RegisterClassEx(&wnd_class);

	g_handle = CreateWindowExW(
		WS_EX_APPWINDOW,
		L"APIProject",
		L"APIProject",
		CW_USEDEFAULT,
		0,
		0,
		GetSystemMetrics(SM_CXSCREEN),
		GetSystemMetrics(SM_CYSCREEN),
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);
}//그냥암기

void Show()
{
	SetForegroundWindow(g_handle);
	SetFocus(g_handle);
	ShowCursor(TRUE);
	ShowWindow(g_handle, SW_NORMAL);
	UpdateWindow(g_handle);
}


bool Update()
{
	ZeroMemory(&msg, sizeof(MSG));
	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.message != WM_QUIT;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE previnstacne, LPSTR ipszCmdParam, int nCmdShow)
{
	Create(hInstance);
	while (Update()) {
		Show();
	}
	
	return 0;
}


