#include "AllInclude.h"
#include "Bullet.h"
#include "Plane.h"

static HINSTANCE g_instance;
static HWND g_handle;
int bgLoc = 0;
bool dir = false;/*����*/
int myspeed = 10;
bool gameover = false;
int health = 0;
int attackDelay = 0;
HDC planeDC, plane1DC, plane2DC, bulletDC, bgDC, hpDC, gameoverDC, hdc;
HBITMAP plainBitmap, plainBitmap1, plainBitmap2, bulletBitmap, bgBitmap, hpBitmap, gameoverBitmap;
PAINTSTRUCT ps;

std::list<Plane*> planeLList;
// std::list<�ڷ���> �̸�;
//����Ʈ ����:�ʱ�ȭ ���ʿ�

std::list<Bullet*> bulletList;
std::list<Plane*> planeRList;

Plane* myPlane;


HBITMAP LoadBitMapFile(const char* path) {
	return (HBITMAP)LoadImageA(nullptr, TEXT(path), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
}

void Damaged() {

	health -= 800;
	if (health <= -1920) {
		gameover = true;
	}
}

void MoveMe(bool dir) {
	if (dir) {
		bgLoc -= myspeed;
	}
	else {
		bgLoc += myspeed;
	}
	for (Plane* p: planeLList) {//plane����Ʈ�� planeŬ����(��ü)�� p��� �̸��� ���̰� �� ��ü�� ����ִ� ���� ��ŭ �ݺ� ��Ų��,
		p->Move(dir, myspeed);//������ ������ plane* �� move�Լ��� dir, myspeed�� �ְ� ����
	}

	for (Plane* p : planeRList) {
		p->Move(dir, myspeed);
	}
}

void DrawScreen() {
	HDC hDC;
	hdc = GetDC(g_handle);

	/* ��ũ�� �� ��ũ��*/
	if (bgLoc > 2000) {
		bgLoc -= 2000;
	} else if (bgLoc < 0) {
		bgLoc += 2000;
	}
	BitBlt(hdc, bgLoc, 0, 2000, 1100, bgDC, 0, 0, SRCCOPY);//���1
	BitBlt(hdc, bgLoc - 2000, 0, 2000, 1100, bgDC, 0, 0, SRCCOPY);//����2
	BitBlt(hdc, health, 0, 1920, 100, hpDC, 0, 0, SRCCOPY);//hp��

	if (!gameover) {//������ �϶�
		if (dir) BitBlt(hdc, LOCX, LOCY, WIDTH, HEIGHT, planeDC, 0, 0, SRCCOPY);//�÷��̾ ������
		else BitBlt(hdc, LOCX, LOCY, WIDTH, HEIGHT, plane1DC, 0, 0, SRCCOPY);//�÷��̾ ����

		for (Plane* p : planeLList) {
			BitBlt(hdc, p->info.x, p->info.y, p->info.width, p->info.height, plane2DC, 0, 0, SRCCOPY);//p�� ���ڰ� ��������
		}

		for (Plane* p : planeRList) {
			BitBlt(hdc, p->info.x, p->info.y, p->info.width, p->info.height, plane2DC, 0, 0, SRCCOPY);
		}

		for (Bullet* b : bulletList) {
			BitBlt(hdc, b->info.x, b->info.y, b->info.width, b->info.height, bulletDC, 0, 0, SRCCOPY);
		}
	} else {
		BitBlt(hdc, 500, 400, 900, 300, gameoverDC, 0, 0, SRCCOPY);//���ӿ��� ����
	}


	ReleaseDC(g_handle, hdc);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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
				planeLList.remove(breakPlane);//remove: ����Ʈ���� �����϶�
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
			int ran = rand() % 2;// 0�Ǵ� 1

			if (ran == 0) {
				//��ü���� �ڵ�
				Plane* ePlane = new Plane(true);//new ��ü���� Ű������ Plane Ŭ��������
				planeLList.push_back(ePlane);//list�� �߰��ϴ� Ű���� push_back
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
	wnd_class.lpszClassName = "My study01";
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
