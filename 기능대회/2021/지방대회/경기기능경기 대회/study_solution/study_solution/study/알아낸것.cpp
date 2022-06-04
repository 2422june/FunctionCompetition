#include <iostream>                                //�� ���������  C ǥ�� ���̺귯���� stdio.h�� ����, C++ ǥ�� ���̺귯���� �ϳ��̸�, ����� stdio.h�� ����.

#include <sstream>                                 //���ڿ����� ��ȣ�ۿ��� ���� �������?

#pragma comment(lib, "msimg32.lib")                //���̺귯�� �߰��� ���

#include <stdlib.h>                                //���ڿ� ��ȯ, ���� ����, ���� �޸� ���� ���� �Լ����� �����ϰ� �ִ�.

#pragma once                                       //���� ��������� ������ ����ϰڴٴ� ����?

#include <Windows.h>                               //�����쿡���� �Լ��� ����ִ� �������

#include<list>

struct /*����ü �̸�*/ {
	//�������� �����̸�1, �����̸�2,  ....         //struct:����ü�̴�. �ѹ��� �������� ������ ���� �� �ִ�.
};

class /*Ŭ���� �̸�*/ {                            //Ŭ����(int, float�� ���� �ڷ����̴�, �ٸ� ������ ������ �ڷ���) ����(Ŭ������ �ڷ����� void�̴�.)
	//����Լ��� ������ �Լ���                     //������ �Լ����� �ڷ������� ����� �� �ִ�, ����Լ��� Ŭ������ �̸��� ���ƾ� �Ѵ�.
};                                                 //Ŭ���� �̸�: a �Լ��̸�:b(c, d)
                                                   //��� ����:   void a::b(c,d){���� �ڵ�}

//#include "kdkdkkkkee"                            //����ڰ� ������ ��������� �ҷ��ý� <>�� �ƴ�""�� ����Ѵ�.

//const                                            //


























//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
static HINSTANCE g_instance;
static HWND g_handle;
HBITMAP plainBitmap, plainBitmap1, plainBitmap2, bulletBitmap, bgBitmap, hpBitmap, gameoverBitmap;
HDC hdc;
PAINTSTRUCT ps;
HDC planeDC, plane1DC, plane2DC, bulletDC, bgDC, hpDC, gameoverDC;



//std::�� ���� ���̺귯���� ����� �� ���̴� ���ξ��̴�.
std::list<Plane*> planeLList;//�Լ��� ���� ���� ����Ʈ
std::list<Bullet*> bulletList;//�Ѿ��� �̵� ���� ����Ʈ
std::list<Plane*> planeRList;//�Լ��� ���� ���� ����Ʈ



Plane* myPlane;//PlanetŬ������ ���� myPlanet�� �����Ų��???



HBITMAP LoadBitMapFile(const char* path) {
	return (HBITMAP)LoadImageA(nullptr, TEXT(path), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);;
}




for (Plane* p : planeLList) {//plane�� ���� ����Ʈ�� �ִ� ����???
	p ->/*������ ������ ���� �����ϱ� ���� ������*/ Move(dir, myspeed);//p�� Move��()
}

for (Plane* p : planeRList) {
	p->Move(dir, myspeed);
}



void DrawScreen() {
	HDC hDC;
	hdc = GetDC(g_handle);

	/* Ŭ���� �� ��ũ��*/
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



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)//���� ��� �Լ� �Լ�******
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
	ShowWindow(g_handle, SW_NORMAL);//ȭ�����
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
