
#include "AllInclude.h"
#include "Bullet.h"
#include "Plane.h"

static HINSTANCE g_instance;
static HWND g_handle;
int bgTime = 0;
bool attack;
HBITMAP plainBitmap, plainBitmap2, bulletBitmap, bgBitmap;
HDC hdc;
PAINTSTRUCT ps;
HDC planeDC, plane2DC, bulletDC, bgDC;

std::list<Plane*> planeLList;
std::list<Bullet*> bulletList;
std::list<Plane*> planeRList;

Plane* myPlane;

HBITMAP LoadBitMapFile(const char* path) {
	return (HBITMAP)LoadImageA(nullptr, TEXT(path), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);;
}

void DrawScreen() {
	HDC hDC;
	hdc = GetDC(g_handle);

	/* 클리닝 백 스크린*/
	if (bgTime > 1100) {
		bgTime -= 1100;
	}
	BitBlt(hdc, 0, bgTime, 2000, 1100, bgDC, 0, 0, SRCCOPY);
	BitBlt(hdc, 0, bgTime - 1100, 2000, 1100, bgDC, 0, 0, SRCCOPY);

	BitBlt(hdc, myPlane->info.x, myPlane->info.y, myPlane->info.width, myPlane->info.height, planeDC, 0, 0, SRCCOPY);

	for (Plane* p : planeLList) {
		BitBlt(hdc, p->info.x, p->info.y, p->info.width, p->info.height, plane2DC, 0, 0, SRCCOPY);
	}

	for (Plane* p : planeRList) {
		BitBlt(hdc, p->info.x, p->info.y, p->info.width, p->info.height, plane2DC, 0, 0, SRCCOPY);
	}

	for (Bullet* b : bulletList) {
		BitBlt(hdc, b->info.x, b->info.y, b->info.width, b->info.height, bulletDC, 0, 0, SRCCOPY);
	}

	ReleaseDC(g_handle, hdc);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, (1000 / (FLOAT)30), nullptr);
		SetTimer(hWnd, 2, (1000 / (FLOAT)1), nullptr);
		SetTimer(hWnd, 3, (1000 / (FLOAT)1), nullptr);

		hdc = GetDC(g_handle);
		planeDC = CreateCompatibleDC(hdc);
		plane2DC = CreateCompatibleDC(hdc);
		bulletDC = CreateCompatibleDC(hdc);
		bgDC = CreateCompatibleDC(hdc);
		ReleaseDC(g_handle, hdc);

		plainBitmap = LoadBitMapFile("../MyPlane.bmp");
		SelectObject(planeDC, plainBitmap);

		plainBitmap2 = LoadBitMapFile("../Plane.bmp");
		SelectObject(plane2DC, plainBitmap2);

		bgBitmap = LoadBitMapFile("../Background.bmp");
		SelectObject(bgDC, bgBitmap);

		bulletBitmap = LoadBitMapFile("../Misile.bmp");
		SelectObject(bulletDC, bulletBitmap);

		myPlane = new Plane(935, 985, 30);
		break;

	case WM_PAINT:
		hdc = BeginPaint(g_handle, &ps);
		EndPaint(g_handle, &ps);
		DrawScreen();
		break;

	case WM_TIMER:
		if (wParam == 1) {
			bgTime += 1;
			for (Plane* p : planeLList) {
				p->Move();
			}

			for (Plane* p : planeRList) {
				p->Move();
			}

			for (Bullet* b : bulletList) {
				b->Move();			
			}

			Plane* breakPlane = nullptr;
			Bullet* breakBullet = nullptr;

			for (Bullet* b : bulletList) {
				for (Plane* p : planeLList) {
					if ((abs(b->info.x - p->info.x) < 50) &&(abs(b->info.y - p->info.y) < 50)) {
						breakPlane = p;
						breakBullet = b;
					}
				}
				if (breakPlane != nullptr) {
					planeLList.remove(breakPlane);
				}


				for (Plane* p : planeRList) {
					if ((abs(b->info.x - p->info.x) < 50) && (abs(b->info.y - p->info.y) < 50)) {
						breakPlane = p;
						breakBullet = b;
					}
				}		
				if (breakPlane != nullptr) {
					planeRList.remove(breakPlane);
				}
			}

			if (breakBullet != nullptr){
				bulletList.remove(breakBullet);
			}

			DrawScreen();
		}
		else if (wParam == 2) {
			int ran = rand() % 2;

			if (ran == 0) {
				Plane* ePlane = new Plane(true, -3);
				planeLList.push_back(ePlane);
			}
			else
			{
				Plane* ePlane = new Plane(false, 3);
				planeRList.push_back(ePlane);
			}
		}
		else if (wParam == 3) {
			attack = true;
		}
		break;

	case WM_KEYDOWN:
		if (wParam == VK_LEFT) {
			myPlane->Move(-1);
		}
		else if (wParam == VK_RIGHT) {
			myPlane->Move(1);
		}

		if (wParam == VK_SPACE) {
			if (attack) {
				int x = myPlane->info.x;
				int y = myPlane->info.y;

				Bullet* bullet = new Bullet(x, y - 50, 10);
				bulletList.push_back(bullet);
				attack = false;
			}
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

void Create(HINSTANCE hInstance, const UINT& width, const UINT& height)
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

	char buffer[65] = { 0 };
	_itoa_s(GetSystemMetrics(SM_CXSCREEN), buffer, 10);

	OutputDebugString(buffer);
	OutputDebugString("\n");
	_itoa_s(GetSystemMetrics(SM_CYSCREEN), buffer, 10);
	OutputDebugString(buffer);
}

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
	MSG msg;
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
	Create(hInstance, 500, 500);
	
	while (Update()) {
		Show();
	}
	
	return 0;
}