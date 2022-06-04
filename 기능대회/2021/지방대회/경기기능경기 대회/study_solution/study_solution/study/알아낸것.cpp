#include <iostream>                                //이 헤더파일은  C 표준 라이브러리인 stdio.h와 같이, C++ 표준 라이브러리의 하나이며, 기능은 stdio.h와 같다.

#include <sstream>                                 //문자열간의 상호작용을 돕는 헤더파일?

#pragma comment(lib, "msimg32.lib")                //라이브러리 추가시 사용

#include <stdlib.h>                                //문자열 변환, 난수 생성, 동적 메모리 관리 등의 함수들을 포함하고 있다.

#pragma once                                       //같은 헤더파일을 여러번 사용하겠다는 선언?

#include <Windows.h>                               //윈도우에대한 함수가 들어있는 헤더파일

#include<list>

struct /*구조체 이름*/ {
	//데이터형 변수이름1, 변수이름2,  ....         //struct:구조체이다. 한번에 여러개의 변수를 담을 수 있다.
};

class /*클래스 이름*/ {                            //클레스(int, float와 같은 자료형이다, 다만 선언이 가능한 자료형) 선언(클레스의 자료형은 void이다.)
	//멤버함수와 변수나 함수들                     //변수나 함수들을 자료형으로 사용할 수 있다, 멤버함수는 클래스와 이름이 같아야 한다.
};                                                 //클래스 이름: a 함수이름:b(c, d)
                                                   //사용 예시:   void a::b(c,d){실행 코드}

//#include "kdkdkkkkee"                            //사용자가 정의한 헤더파일은 불러올시 <>가 아닌""를 사용한다.

//const                                            //


























//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
static HINSTANCE g_instance;
static HWND g_handle;
HBITMAP plainBitmap, plainBitmap1, plainBitmap2, bulletBitmap, bgBitmap, hpBitmap, gameoverBitmap;
HDC hdc;
PAINTSTRUCT ps;
HDC planeDC, plane1DC, plane2DC, bulletDC, bgDC, hpDC, gameoverDC;



//std::는 기존 라이브러리를 사용할 시 붙이는 접두어이다.
std::list<Plane*> planeLList;//함선의 방향 관련 리스트
std::list<Bullet*> bulletList;//총알의 이동 관련 리스트
std::list<Plane*> planeRList;//함선의 방향 관련 리스트



Plane* myPlane;//Planet클레스의 값을 myPlanet에 저장시킨다???



HBITMAP LoadBitMapFile(const char* path) {
	return (HBITMAP)LoadImageA(nullptr, TEXT(path), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);;
}




for (Plane* p : planeLList) {//plane의 값이 리스트에 있는 동안???
	p ->/*포인터 변수의 값을 참조하기 위한 연산자*/ Move(dir, myspeed);//p에 Move의()
}

for (Plane* p : planeRList) {
	p->Move(dir, myspeed);
}



void DrawScreen() {
	HDC hDC;
	hdc = GetDC(g_handle);

	/* 클리닝 백 스크린*/
	if (bgLoc > 2000) {
		bgLoc -= 2000;
	}
	else if (bgLoc < 0) {
		bgLoc += 2000;
	}
	BitBlt(hdc, bgLoc, 0, 2000, 1100, bgDC, 0, 0, SRCCOPY);
	BitBlt(hdc, bgLoc - 2000, 0, 2000, 1100, bgDC, 0, 0, SRCCOPY);
	BitBlt(hdc, health, 0, 1920, 100, hpDC, 0, 0, SRCCOPY);
	if (!gameover) {
		if (dir) BitBlt(hdc, LOCX, LOCY, WIDTH, HEIGHT, planeDC, 0, 0, SRCCOPY);
		else BitBlt(hdc, LOCX, LOCY, WIDTH, HEIGHT, plane1DC, 0, 0, SRCCOPY);

		for (Plane* p : planeLList) {
			BitBlt(hdc, p->info.x, p->info.y, p->info.width, p->info.height, plane2DC, 0, 0, SRCCOPY);
		}

		for (Plane* p : planeRList) {
			BitBlt(hdc, p->info.x, p->info.y, p->info.width, p->info.height, plane2DC, 0, 0, SRCCOPY);
		}

		for (Bullet* b : bulletList) {
			BitBlt(hdc, b->info.x, b->info.y, b->info.width, b->info.height, bulletDC, 0, 0, SRCCOPY);
		}
	}
	else {
		BitBlt(hdc, 500, 400, 900, 300, gameoverDC, 0, 0, SRCCOPY);
	}


	ReleaseDC(g_handle, hdc);
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)//실질 명령 입수 함수******
{
	switch (message)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, (1000 / (FLOAT)30), nullptr);
		SetTimer(hWnd, 2, (1000 / (FLOAT)2), nullptr);

		hdc = GetDC(g_handle);
		planeDC = CreateCompatibleDC(hdc);
		plane1DC = CreateCompatibleDC(hdc);
		plane2DC = CreateCompatibleDC(hdc);
		bulletDC = CreateCompatibleDC(hdc);
		bgDC = CreateCompatibleDC(hdc);
		hpDC = CreateCompatibleDC(hdc);
		gameoverDC = CreateCompatibleDC(hdc);
		ReleaseDC(g_handle, hdc);

		plainBitmap = LoadBitMapFile("../MyPlane.bmp");
		SelectObject(planeDC, plainBitmap);

		plainBitmap1 = LoadBitMapFile("../MyPlane1.bmp");
		SelectObject(plane1DC, plainBitmap1);

		plainBitmap2 = LoadBitMapFile("../Plane.bmp");
		SelectObject(plane2DC, plainBitmap2);

		bgBitmap = LoadBitMapFile("../Background.bmp");
		SelectObject(bgDC, bgBitmap);

		bulletBitmap = LoadBitMapFile("../Misile.bmp");
		SelectObject(bulletDC, bulletBitmap);

		hpBitmap = LoadBitMapFile("../Hpbar.bmp");
		SelectObject(hpDC, hpBitmap);

		gameoverBitmap = LoadBitMapFile("../gameover.bmp");
		SelectObject(gameoverDC, gameoverBitmap);
		break;

	case WM_PAINT:
		hdc = BeginPaint(g_handle, &ps);
		EndPaint(g_handle, &ps);
		DrawScreen();
		break;

	case WM_TIMER:

		if (wParam == 1) {
			attackDelay += 1;
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

			for (Plane* p : planeLList) {
				for (Bullet* b : bulletList) {
					if (abs(b->info.x - p->info.x) < WIDTH) {
						breakPlane = p;
						breakBullet = b;
					}
				}

				if (abs(p->info.x - LOCX) < WIDTH) {
					breakPlane = p;
					Damaged();
				}
			}
			if (breakPlane != nullptr) {
				planeLList.remove(breakPlane);
			}
			for (Plane* p : planeRList) {
				for (Bullet* b : bulletList) {
					if (abs(b->info.x - p->info.x) < WIDTH) {
						breakPlane = p;
						breakBullet = b;
					}

				}

				if (abs(p->info.x - LOCX) < WIDTH) {
					breakPlane = p;
					Damaged();
				}
			}
			if (breakPlane != nullptr) {
				planeRList.remove(breakPlane);
			}
			if (breakBullet != nullptr) {
				bulletList.remove(breakBullet);
			}
			breakPlane = nullptr;
			breakBullet = nullptr;

			DrawScreen();
		}




		else if (wParam == 2) {
			int ran = rand() % 2;

			if (ran == 0) {
				Plane* ePlane = new Plane(true);
				planeLList.push_back(ePlane);
			}
			else
			{
				Plane* ePlane = new Plane(false);
				planeRList.push_back(ePlane);
			}
		}

		break;

	case WM_KEYDOWN:
		if (wParam == VK_LEFT && !gameover) {
			dir = false;
			MoveMe(dir);
		}
		else if (wParam == VK_RIGHT && !gameover) {
			dir = true;
			MoveMe(dir);
		}

		if (wParam == VK_SPACE && !gameover) {
			if (attackDelay > 10) {
				int x = LOCX;
				int y = LOCY;
				if (dir) {
					x += WIDTH;
				}
				else {
					x -= WIDTH;
				}
				Bullet* bullet = new Bullet(x, y, dir);
				bulletList.push_back(bullet);
				attackDelay = 0;
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
}



void Show()
{
	SetForegroundWindow(g_handle);
	SetFocus(g_handle);
	ShowCursor(TRUE);
	ShowWindow(g_handle, SW_NORMAL);//화면출력
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


//int main
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE previnstacne, LPSTR ipszCmdParam, int nCmdShow)
{
	Create(hInstance, 500, 500);

	while (Update()) {
		Show();
	}

	return 0;
}
