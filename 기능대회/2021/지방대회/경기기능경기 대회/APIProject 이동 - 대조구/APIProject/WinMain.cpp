#include<Windows.h>
#pragma comment(lib, "msimg32.lib")

static HINSTANCE g_hi;
static HWND g_hd;
HBITMAP plaBM, bgBM;
PAINTSTRUCT ps;
HDC plaDC, bgDC, hdc;
MSG msg;
int x, y;

HBITMAP load(const char* path)
{
	return(HBITMAP)LoadImageA(nullptr, TEXT(path), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
}

void dscreen()
{
	hdc = GetDC(g_hd);
	BitBlt(hdc, 0, 0, 2000, 1100, bgDC, 0, 0, SRCCOPY);
	BitBlt(hdc, 940 + x, 980 + y, 80, 50, plaDC, 0, 0, SRCCOPY);
	ReleaseDC(g_hd, hdc);
}

LRESULT CALLBACK wndproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_TIMER:
		if (wParam == 1)
		{
			dscreen();
		}
		break;

	case WM_CREATE:
		SetTimer(hWnd, 1, (1000 / (float)30), nullptr);
		hdc = GetDC(g_hd);
		plaDC = CreateCompatibleDC(hdc);
		bgDC = CreateCompatibleDC(hdc);
		ReleaseDC(g_hd, hdc);
		plaBM = load("../a./MyPlane.bmp");
		SelectObject(plaDC, plaBM);
		bgBM = load("../a./Background.bmp");
		SelectObject(bgDC, bgBM);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_DOWN)
		{
			y += 30;
		}
		if (wParam == VK_UP)
		{
			y -= 30;
		}
		if (wParam == VK_LEFT)
		{
			x -= 30;
		}
		if (wParam == VK_RIGHT)
		{
			x += 30;
		}
		if (wParam == VK_ESCAPE)
		{
			PostQuitMessage(0);
		}
		break;

	case WM_PAINT:
		hdc = BeginPaint(g_hd, &ps);
		EndPaint(g_hd, &ps);
		dscreen();
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

void create(HINSTANCE hi)
{
	g_hi = hi;
	WNDCLASSEX wndc;
	wndc.cbWndExtra = 0;
	wndc.cbClsExtra = 0;
	wndc.hbrBackground = static_cast<HBRUSH>(GetStockObject(GRAY_BRUSH));

	wndc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wndc.hIconSm = LoadIcon(nullptr, IDI_ERROR);

	wndc.hInstance = g_hi;
	wndc.lpfnWndProc = wndproc;//******************

	wndc.lpszClassName = "APIProject";
	wndc.lpszMenuName = nullptr;
	wndc.style = CS_HREDRAW | CS_VREDRAW;

	wndc.cbSize = sizeof(WNDCLASSEX);//***********************************

	auto check = RegisterClassEx(&wndc);//*************************

	g_hd = CreateWindowExW(
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
		hi,
		nullptr);//*********************
}

void show()//****************
{
	SetForegroundWindow(g_hd);
	SetFocus(g_hd);
	ShowCursor(TRUE);
	ShowWindow(g_hd, SW_NORMAL);
	UpdateWindow(g_hd);
}

bool update()
{
	ZeroMemory(&msg, sizeof(MSG));
	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.message != WM_QUIT;
}

int APIENTRY WinMain(HINSTANCE hi, HINSTANCE phi, LPSTR cmdparam, int cmdshow)
{
	create(hi);
	while (update()){
		show();
	}
	return 0;
}