#include "AllInclude.h"//그림과 헤더파일에 대한 셋팅을 하는 헤더파일
#include "Bullet.h"//총알에 대한 헤더파일
#include "Plane.h"//적과 아군의 함선에 대한 헤더파일


using namespace std;

//변수를 winmain에 저장하는 이유는 중복선언을 막기 위해서임

static HINSTANCE HI;                                                                                        //프로그램의 인스턴스(번호)를 HI로 지정한다.
static HWND HW;                                                                                             //프로그램의 윈도우창의 핸들(번호)를 HW로 지정한다.
int bgLoc = 0;                                                                                              //배경위치에 대한 변수
bool dir = false;                                                                                           //개체의 방향에 대한 변수(왼쪽false, 오른쪽True)
int myspeed = 10;                                                                                           //개체의 속도에 대한 변수
bool gameover = false;                                                                                      //게임오버의 유무에 대한 변수
int health = 0;                                                                                             //개체의 hp에 대한 변수
int attackDelay = 0;                                                                                        //공격지연시간에 대한 변수
HBITMAP plainBitmap, plainBitmap1, plainBitmap2, bulletBitmap, bgBitmap, hpBitmap, gameoverBitmap;          //bmp그림파일을 로드할때 얻어지는 핸들
HDC planeDC, plane1DC, plane2DC, bulletDC, bgDC, hpDC, gameoverDC;                                          //HDC: 출력에 필요한 정보를 가지는 데이터 구조체
HDC hdc;                                                                                                    //HDC: 출력에 필요한 정보를 가지는 데이터 구조체
PAINTSTRUCT ps;                                                                                             //클라이언트에 페인트를 사용가능 하게해주는 정보를 가진 구조체
list<Plane*> planeLList;                                                                                    //함선의 방향 관련 리스트
list<Bullet*> bulletList;                                                                                   //총알의 이동 관련 리스트
list<Plane*> planeRList;                                                                                    //함선의 방향 관련 리스트
Plane* myPlane;                                                                                             //Planet클레스의 값을 myPlanet에 저장시킨다???


//Load BMF라는 이름을 가진 이미지를 불러오는 함수**********
HBITMAP LoadBMF(const char* path) {

	//HBITMAP이라는 데이터 타입을 가진 LoadImage함수 ()
	return (HBITMAP)LoadImage(nullptr, TEXT(path), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
}


//주인공에게 들어가는 뎀지와 주인공의 hp에대한 함수
void Damaged() {

	health -= 800;
	if (health <= -1920) {
		gameover = true;
	}
}


//주인공의 방향에 따른 이동에 대한 변수******
void MoveMe(bool dir) {
	if (dir) {
		bgLoc -= myspeed;
	}
	else {
		bgLoc += myspeed;
	}
	for (Plane* p : planeLList) {//plane의 값이 리스트에 있는 동안???
		p -> /*포인터 변수의 값을 참조하기 위한 연산자*/ Move(dir, myspeed);
	}

	for (Plane* p : planeRList) {
		p->Move(dir, myspeed);
	}
}



void DrawScreen() {
	HDC hDC;
	hdc = GetDC(HW);

	//배경의 이동에 대한 코드
	if (bgLoc > 2000) {
		bgLoc -= 2000;
	} else if (bgLoc < 0) {
		bgLoc += 2000;
	}
	//양식: BitBlt(hdc, 출력위치의 핸들, x,      y,     너비,   높이,   이미지의 핸들, 이미지의 좌측상단y, 이미지의 출력방법)
	BitBlt(        hdc,  bgLoc,          0,      2000,  1100,   bgDC,   0,             0,                  SRCCOPY);
	BitBlt(        hdc,  bgLoc - 2000 ,  0,      2000,  1100,   bgDC,   0,             0,                  SRCCOPY);
	BitBlt(        hdc,  health,         0,      1920,  100,    hpDC,   0,             0,                  SRCCOPY);

	//만일 게임오버가 아니라면?
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
		//만일 게임오버라면?
	} else {
		BitBlt(hdc, 500, 400, 900, 300, gameoverDC, 0, 0, SRCCOPY);
	}


	ReleaseDC(HW, hdc);
}


//실질 명령 입수 함수******
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, (1000 / (FLOAT)30), nullptr);
		SetTimer(hWnd, 2, (1000 / (FLOAT)2), nullptr);

		hdc = GetDC(HW);
		planeDC = CreateCompatibleDC(hdc);
		plane1DC = CreateCompatibleDC(hdc);
		plane2DC = CreateCompatibleDC(hdc);
		bulletDC = CreateCompatibleDC(hdc);
		bgDC = CreateCompatibleDC(hdc);
		hpDC = CreateCompatibleDC(hdc);
		gameoverDC = CreateCompatibleDC(hdc);
		ReleaseDC(HW, hdc);


		//이미지를 불러온 뒤 HDC에저장
		plainBitmap = LoadBMF("../MyPlane.bmp");
		SelectObject(planeDC, plainBitmap);

		//이미지를 불러온 뒤 HDC에저장
		plainBitmap1 = LoadBMF("../MyPlane1.bmp");
		SelectObject(plane1DC, plainBitmap1);

		//이미지를 불러온 뒤 HDC에저장
		plainBitmap2 = LoadBMF("../Plane.bmp");
		SelectObject(plane2DC, plainBitmap2);

		//이미지를 불러온 뒤 HDC에저장
		bgBitmap = LoadBMF("../Background.bmp");
		SelectObject(bgDC, bgBitmap);

		//이미지를 불러온 뒤 HDC에저장
		bulletBitmap = LoadBMF("../Misile.bmp");
		SelectObject(bulletDC, bulletBitmap);

		//이미지를 불러온 뒤 HDC에저장
		hpBitmap = LoadBMF("../Hpbar.bmp");
		SelectObject(hpDC, hpBitmap);

		//이미지를 불러온 뒤 HDC에저장
		gameoverBitmap = LoadBMF("../gameover.bmp");
		SelectObject(gameoverDC, gameoverBitmap);
		break;

	case WM_PAINT:
		hdc = BeginPaint(HW, &ps);
		EndPaint(HW, &ps);
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
	HI = hInstance;

	WNDCLASSEX wnd_class;
	wnd_class.cbClsExtra = 0;
	wnd_class.cbWndExtra = 0;
	wnd_class.hbrBackground = static_cast<HBRUSH>(GetStockObject(GRAY_BRUSH));
	wnd_class.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wnd_class.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wnd_class.hIconSm = LoadIcon(nullptr, IDI_ERROR);
	wnd_class.hInstance = HI;
	wnd_class.lpfnWndProc = WndProc;
	wnd_class.lpszClassName = "APIProject";
	wnd_class.lpszMenuName = nullptr;
	wnd_class.style = CS_HREDRAW | CS_VREDRAW;
	wnd_class.cbSize = sizeof(WNDCLASSEX);

	auto check = RegisterClassEx(&wnd_class);

	HW = CreateWindowExW(
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
	SetForegroundWindow(HW);
	SetFocus(HW);
	ShowCursor(TRUE);
	ShowWindow(HW, SW_NORMAL);//화면출력
	UpdateWindow(HW);
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
