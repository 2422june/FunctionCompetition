#include<Windows.h>
#include"Player.h"
#include"Guide.h"
#include<stdlib.h>
#include<list>
#include"Zone.h"
#include"Guide.h"
#include"MinMax.h"
#include"Main.h"
#include"Nagative.h"
#include"Nagative2.h"
#pragma comment(lib, "msimg32.lib")

//1050줄!!!!

HWND g_hd;
HINSTANCE g_hi;
bool inZone, boom, newStage, stop;
int x, y, wide, height, size, showCredit, score;
HDC plaDC, bgDC, zoneDC, guideDC, CountDC, hpDC, MainBackDC, StartDC, QuitDC, nagativeDC, nagative2DC, hdc;
HDC EscDC, CreditDC, MenuBackDC, GameOverDC, GameClearDC, SpaceDC, LevelDC, CreditBackgroundDC, scoreDC;
HBITMAP plaBM, bgBM, zoneBM, guideBM, CountBM, MainBackBM, StartBM, QuitBM, hpBM, nagativeBM, nagative2BM;
HBITMAP EscBM, CreditBM, MenuBackBM, GameOverBM, GameClearBM, SpaceBM, LevelBM, CreditBackgroundBM, scoreBM;
PAINTSTRUCT ps;
MSG msg;

Nagative* n;
Nagative2* n2;
Main* M;
Player* p;
MinMax* m;
Zone* z;
Guide* g;
std::list<Zone*> zoneList;
std::list<Guide*> guideList;

HBITMAP load(const char* path) {
	return (HBITMAP)LoadImageA(nullptr, TEXT(path), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
}

void set() {
	plaBM = load("../G/PlayerUp.bmp");
	SelectObject(plaDC, plaBM);
	score = 0;
	p->x = 0;
	p->y = 1080;
	p->wide = 80;
	p->height = 80;
	p->speed = 20;
	p->dirCount = 0;
	p->inZone = true;
	p->lastInZone = false;
	p->updown = VK_SPACE;
	p->rightleft = VK_SPACE;
	p->dir = 0;
	p->hp = 5;
	m->maxx = 0;
	m->maxy = 0;
	m->minx = 0;
	m->miny = 0;
	M->gamecomplete = false;
	M->gameover = false;
	M->stage = 0;
	n->x = -1;
	n->y = -1;
	n->dirx = 0;
	n->diry = 0;
	n->wide = 150;
	n->height = 150;
	n->sign = 0;
	n2->x = -1;
	n2->y = -1;
	n2->dirx = 0;
	n2->diry = 0;
	n2->wide = 150;
	n2->height = 150;
	n2->sign = 0;
}

void screenclear() {
	zoneList.clear();
	guideList.clear();
	zoneList.push_back(new Zone(-5, 540, 10, 1080));//left
	zoneList.push_back(new Zone(1920 / 2, 1080 + 5, 1920, 10));//down
	zoneList.push_back(new Zone(1920 + 5, 540, 10, 1080));//right
	zoneList.push_back(new Zone(1920 / 2, -5, 1920, 10));//up
	p->x = 0;
	p->y = 1080;
	n->x = -1;
	n->y = -1;
	n2->x = -1;
	n2->y = -1;
	p->x1 = 0;
	p->y1 = 0;
	p->y2 = 0;
	p->x2 = 0;
	p->x3 = 0;
	p->y3 = 0;
	p->lastInZone = false;
	p->inZone = true;
	p->dirCount = 0;
	p->nowDir = VK_SPACE;
	p->updown = VK_SPACE;
	p->rightleft = VK_SPACE;
}

void gameOver() {
	if (p->hp <= 0) {
		stop = true;
		M->gameover = true;
	}
	else {
		M->gameover = false;
	}
}

void gameclear() {
	if (M->stage != 5 && newStage == false) {
		newStage = false;
	}
	if (M->gamecomplete == false) {
		size = 0;
		for (Zone* z : zoneList) {
			size += z->wide * z->height;
		}
		if ((1920 * 1080) * 8 / 10 <= size) {
			if (M->stage != 5) {
				screenclear();
				score++;
				newStage = true;
				M->gamecomplete = false;
			}
			else {
				stop = true;
				M->gamecomplete = true;
			}
		}
		else {
			M->gamecomplete = false;
		}
	}
}

void dscreenMain() {
	if (!M->gamestart){
		hdc = GetDC(g_hd);
		showCredit = false;
		BitBlt(hdc, 0, 0, 2000, 1100, MainBackDC, 0, 0, SRCCOPY);
		BitBlt(hdc, 860, 720, 2000, 1100, StartDC, 0, 0, SRCCOPY);
		BitBlt(hdc, 860, 920, 2000, 1100, QuitDC, 0, 0, SRCCOPY);
		BitBlt(hdc, 300, 0, 1320, 100, EscDC, 0, 0, SRCCOPY);
		BitBlt(hdc, 300, 100, 1320, 100, SpaceDC, 0, 0, SRCCOPY);
		if (M->mainSelect) {
			StartBM = load("../G/MainStart.bmp");
			QuitBM = load("../G/MainQuitSelect.bmp");
			SelectObject(StartDC, StartBM);
			SelectObject(QuitDC, QuitBM);
		}
		else {
			StartBM = load("../G/MainStartSelect.bmp");
			QuitBM = load("../G/MainQuit.bmp");
			SelectObject(StartDC, StartBM);
			SelectObject(QuitDC, QuitBM);
		}
		ReleaseDC(g_hd, hdc);
	}
	else if (!M->gamemenu) {
		hdc = GetDC(g_hd);
		if (showCredit) {
			BitBlt(hdc, 0, 0, 1920, 1080, CreditBackgroundDC, 0, 0, SRCCOPY);
			BitBlt(hdc, 800, 0, 1320, 100, SpaceDC, 0, 0, SRCCOPY);
		}
		else {
			SelectObject(StartDC, StartBM);
			BitBlt(hdc, 0, 0, 1920, 1080, MenuBackDC, 0, 0, SRCCOPY);
			BitBlt(hdc, 0, 560, 2000, 1100, StartDC, 0, 0, SRCCOPY);
			BitBlt(hdc, 0, 400, 240, 100, CreditDC, 0, 0, SRCCOPY);
			if (M->menuSelect == 1) {
				StartBM = load("../G/MainStart.bmp");
				CreditBM = load("../G/creditSelect.bmp");
				SelectObject(StartDC, StartBM);
				SelectObject(CreditDC, CreditBM);
			}
			else if (M->menuSelect == 2) {
				StartBM = load("../G/MainStartSelect.bmp");
				CreditBM = load("../G/credit.bmp");
				SelectObject(StartDC, StartBM);
				SelectObject(CreditDC, CreditBM);
			}
		}
		ReleaseDC(g_hd, hdc);
	}
}

//플레이어를 포함한 모든 게임오브젝트
void dscreenGame() {
	if (M->gamestart && M->gamemenu) {//게임시작
		hdc = GetDC(g_hd);
		BitBlt(hdc, 0, 0, 2000, 1100, bgDC, 0, 0, SRCCOPY);
		for (Zone* z : zoneList) {
			BitBlt(hdc, z->x - (z->wide / 2), z->y - (z->height / 2), z->wide, z->height, zoneDC, 0, 0, SRCCOPY);
		}
		for (Guide* g : guideList) {
			BitBlt(hdc, g->x - (g->wide / 2), g->y - (g->height / 2), g->wide, g->height, guideDC, 0, 0, SRCCOPY);
		}
		if (boom) {
			BitBlt(hdc, 300, 0, 1320, 100, SpaceDC, 0, 0, SRCCOPY);
		}
		if (newStage) {
			BitBlt(hdc, 300, 0, 1320, 100, SpaceDC, 0, 0, SRCCOPY);
			BitBlt(hdc, 300, 0, 1320, 200, LevelDC, 0, 0, SRCCOPY);
		}
		switch (p->dirCount) {
		case 0:
			CountBM = load("../G/Count2.bmp");
			break;
		case 1:
			CountBM = load("../G/Count1.bmp");
			break;
		case 2:
			CountBM = load("../G/Count0.bmp");
			break;
		default:
			break;
		}
		switch(score){
		case 0:
			scoreBM = load("../G/Round.bmp");
			break;
		case 1:
			scoreBM = load("../G/Round1.bmp");
			break;
		case 2:
			scoreBM = load("../G/Round2.bmp");
			break;
		case 3:
			scoreBM = load("../G/Round3.bmp");
			break;
		case 4:
			scoreBM = load("../G/Round4.bmp");
			break;
		default:
			break;
		}
		switch (p->hp) {
		case 5:
			hpBM = load("../G/hp5.bmp");
			break;
		case 4:
			hpBM = load("../G/hp4.bmp");
			break;
		case 3:
			hpBM = load("../G/hp3.bmp");
			break;
		case 2:
			hpBM = load("../G/hp2.bmp");
			break;
		case 1:
			hpBM = load("../G/hp1.bmp");
			break;
		default:
			break;
		}
		SelectObject(CountDC, CountBM);
		SelectObject(scoreDC, scoreBM);
		SelectObject(hpDC, hpBM);
		if (!boom && !newStage && !M->gamecomplete && !M->gameover) {
			BitBlt(hdc, 600, 0, 1320, 100, scoreDC, 0, 0, SRCCOPY);
		}
		BitBlt(hdc, 0, 0, 80, 80, CountDC, 0, 0, SRCCOPY);
		BitBlt(hdc, 1840, 0, 80, 80, hpDC, 0, 0, SRCCOPY);
		BitBlt(hdc, p->x - (p->wide / 2), p->y - (p->height / 2), p->wide, p->height, plaDC, 0, 0, SRCCOPY);
		BitBlt(hdc, n->x - (n->wide / 2), n->y - (n->height / 2), n->wide, n->height, nagativeDC, 0, 0, SRCCOPY);
		BitBlt(hdc, n2->x - (n2->wide / 2), n2->y - (n2->height / 2), n2->wide, n2->height, nagative2DC, 0, 0, SRCCOPY);
		ReleaseDC(g_hd, hdc);
	}
}

//Zone, Guide등 연산
void TimerFuction(WPARAM wParam) {
	inZone = false;
	for (Zone* z : zoneList) {
		if (z->inItZone(p->x, p->y)) {
			inZone = true;
		}
	}
	p->UpadteInZone(inZone);
	if (p->inZone != p->lastInZone) {
		if (p->InCommingZone()) {
			if (p->dirCount == 1) {
				wide = m->Maxx3(p->x1, p->x2, p->x) - m->Minx3(p->x1, p->x2, p->x);
				height = m->Maxy3(p->y1, p->y2, p->y) - m->Miny3(p->y1, p->y2, p->y);
				x = m->Minx3(p->x1, p->x2, p->x);
				y = m->Miny3(p->y1, p->y2, p->y);

			}
			else if (p->dirCount == 2) {
				wide = m->Maxx4(p->x1, p->x2, p->x3, p->x) - m->Minx4(p->x1, p->x2, p->x3, p->x);
				height = m->Maxy4(p->y1, p->y2, p->y3, p->y) - m->Miny4(p->y1, p->y2, p->y3, p->y);
				x = m->Minx4(p->x1, p->x2, p->x3, p->x);
				y = m->Miny4(p->y1, p->y2, p->y3, p->y);

			}
			zoneList.push_back(new Zone(x + (wide / 2), y + (height / 2), wide, height));
			guideList.clear();
		}
		else {
			p->ItOutGoingZone();
		}
	}
	p->isinZone();
	if (p->dir == 1) {
		plaBM = load("../G/PlayerUp.bmp");
	}
	if (p->dir == 2) {
		plaBM = load("../G/PlayerDown.bmp");
	}
	if (p->dir == 3) {
		plaBM = load("../G/PlayerRight.bmp");
	}
	if (p->dir == 4) {
		plaBM = load("../G/PlayerLeft.bmp");
	}
	SelectObject(plaDC, plaBM);
	if (!inZone) {
		guideList.push_back(new Guide(p->x, p->y));
	}
	boom = false;
	if (n->InPlayer(p->x, p->y) || n2->InPlayer(p->x, p->y)/* || n3->InPlayer(p->x, p->y)*/) {
		boom = true;
		plaBM = load("../G/boom.bmp");
		SelectObject(plaDC, plaBM);
		p->hp = p->hp -1;
		p->nowDir = VK_SPACE;
	}
}

void CompleteOver() {
	hdc = GetDC(g_hd);
	screenclear();
	if (M->gamecomplete) {
		BitBlt(hdc, 0, 0, 2000, 1100, bgDC, 0, 0, SRCCOPY);
		BitBlt(hdc, 710, 490, 500, 100, GameClearDC, 0, 0, SRCCOPY);
		BitBlt(hdc, 300, 0, 1320, 100, SpaceDC, 0, 0, SRCCOPY);
	}
	else if (M->gameover) {
		BitBlt(hdc, 0, 0, 2000, 1100, bgDC, 0, 0, SRCCOPY);
		BitBlt(hdc, 710, 490, 500, 100, GameOverDC, 0, 0, SRCCOPY);
		BitBlt(hdc, 300, 0, 1320, 100, SpaceDC, 0, 0, SRCCOPY);
		if (score == 0) {
			scoreBM = load("../G/Round.bmp");
		}
		if (score == 1) {
			scoreBM = load("../G/Round1.bmp");
		}
		if (score == 2) {
			scoreBM = load("../G/Round2.bmp");
		}
		if (score == 3) {
			scoreBM = load("../G/Round3.bmp");
		}
		if (score == 4) {
			scoreBM = load("../G/Round4.bmp");
		}
		if (score == 5) {
			scoreBM = load("../G/Round5.bmp");
		}
		SelectObject(scoreDC, scoreBM);
		BitBlt(hdc, 300, 150, 1320, 100, scoreDC, 0, 0, SRCCOPY);
	}
	ReleaseDC(g_hd, hdc);
}

LRESULT CALLBACK wndproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_TIMER:
		if (wParam == 1) {
			if (!newStage && !stop) {
				if (boom == false) {
					TimerFuction(wParam);
					p->PlayerMove();
				}
				n->MoveNagative();
				n2->MoveNagative();
			}
			else {
				if (stop) {
					CompleteOver();
				}
			}
		}
		if (wParam == 2) {
			dscreenMain();
		}
		if (wParam == 3) {
			if (!newStage && !stop) {
				gameOver();
				gameclear();
				dscreenGame();
			}
		}
		break;

	case WM_CREATE:
		SetTimer(hWnd, 1, (1000 / (float)30), nullptr);
		SetTimer(hWnd, 2, (1000 / (float)30), nullptr);
		SetTimer(hWnd, 3, (1000 / (float)30), nullptr);
		hdc = GetDC(g_hd);
		plaDC = CreateCompatibleDC(hdc);
		scoreDC = CreateCompatibleDC(hdc);
		LevelDC = CreateCompatibleDC(hdc);
		CreditBackgroundDC = CreateCompatibleDC(hdc);
		CreditDC = CreateCompatibleDC(hdc);
		SpaceDC = CreateCompatibleDC(hdc);
		EscDC = CreateCompatibleDC(hdc);
		MenuBackDC = CreateCompatibleDC(hdc);
		nagativeDC = CreateCompatibleDC(hdc);
		nagative2DC = CreateCompatibleDC(hdc);
		GameOverDC = CreateCompatibleDC(hdc);
		GameClearDC = CreateCompatibleDC(hdc);
		MainBackDC = CreateCompatibleDC(hdc);
		StartDC = CreateCompatibleDC(hdc);
		QuitDC = CreateCompatibleDC(hdc);
		hpDC = CreateCompatibleDC(hdc);
		CountDC = CreateCompatibleDC(hdc);
		guideDC = CreateCompatibleDC(hdc);
		zoneDC = CreateCompatibleDC(hdc);
		bgDC = CreateCompatibleDC(hdc);
		ReleaseDC(g_hd, hdc);
		plaBM = load("../G/PlayerUp.bmp");
		scoreBM = load("../G/Round.bmp");
		CreditBackgroundBM = load("../G/CreditBackground.bmp");
		LevelBM = load("../G/Level.bmp");
		nagativeBM = load("../G/NagativeBoss.bmp");
		nagative2BM = load("../G/Nagative.bmp");
		CreditBM = load("../G/credit.bmp");
		EscBM = load("../G/Esc.bmp");
		SpaceBM = load("../G/Space.bmp");
		MenuBackBM = load("../G/MenuBackground.bmp");
		MainBackBM = load("../G/MainBackground.bmp");
		GameOverBM = load("../G/GameOver.bmp");
		GameClearBM = load("../G/GameClear.bmp");
		StartBM = load("../G/MainStart.bmp");
		QuitBM = load("../G/MainQuit.bmp");
		hpBM = load("../G/hp5.bmp");
		CountBM = load("../G/Count0.bmp");
		zoneBM = load("../G/Right.bmp");
		guideBM = load("../G/Guide.bmp");
		bgBM = load("../G/Background.bmp");
		SelectObject(plaDC, plaBM);
		SelectObject(scoreDC, scoreBM);
		SelectObject(CreditBackgroundDC, CreditBackgroundBM);
		SelectObject(nagativeDC, nagativeBM);
		SelectObject(LevelDC, LevelBM);
		SelectObject(SpaceDC, SpaceBM);
		SelectObject(nagative2DC, nagative2BM);
		SelectObject(EscDC, EscBM);
		SelectObject(CreditDC, CreditBM);
		SelectObject(MenuBackDC, MenuBackBM);
		SelectObject(MainBackDC, MainBackBM);
		SelectObject(GameOverDC, GameOverBM);
		SelectObject(GameClearDC, GameClearBM);
		SelectObject(StartDC, StartBM);
		SelectObject(QuitDC, QuitBM);
		SelectObject(hpDC, hpBM);
		SelectObject(CountDC, CountBM);
		SelectObject(zoneDC, zoneBM);
		SelectObject(guideDC, guideBM);
		SelectObject(bgDC, bgBM);
		break;

	case WM_KEYDOWN:
		//게임 시작전
		if (!M->gamestart) {//게임시작 전
			if (wParam == VK_SPACE) {//Strat
				if (M->mainSelect == false) {
					StartBM = load("../G/MainStart.bmp");
					M->gamestart = true;
				}
				else {//Quit
					PostQuitMessage(0);
				}
			}
			if (wParam == VK_UP || wParam == VK_DOWN) {//메인선택
				M->mainSelect = !M->mainSelect;
			}
		}
		else if(!M->gamemenu){//메뉴
			if (wParam == VK_SPACE) {
				if (showCredit) {
					showCredit = false;
				}
				else{
					if (M->menuSelect == 1) {//credit
						showCredit = true;
					}
					else if (M->menuSelect == 2) {//start
						screenclear();
						set();
						M->gamemenu = true;
						stop = false;
					}
				}
			}
			if (wParam == VK_UP || wParam == VK_DOWN) {
				if (M->menuSelect == 2) {
					M->menuSelect = 1;
				}
				else {
					M->menuSelect++;
				}
			}
		}
		else if(boom){//터짐
			if (wParam == VK_SPACE) {
				if (M->gameover) {
					p->hp = 5;
					boom = false;
					M->gameover = false;
					M->gamestart = true;
					M->gamemenu = false;
				}
				else {
					p->x = 0;
					p->y = 1080;
					boom = false;
				}
				screenclear();
			}
		}
		else if(M->gamecomplete){//게임클리어
			if (wParam == VK_SPACE) {
				M->gamecomplete = false;
				M->gamestart = true;
				M->gamemenu = false;
				screenclear();
			}
		}
		else if(newStage == true){//새로운 스테이지
			if (wParam == VK_SPACE) {
				p->x = 0;
				p->y = 1080;
				newStage = false;
				M->stage++;
			}
		}
		else {
			p->KeyDown(wParam);
		}
		if (wParam == VK_ESCAPE) {
			PostQuitMessage(0);
		}
		break;

	case WM_PAINT:
		hdc = BeginPaint(g_hd, &ps);
		EndPaint(g_hd, &ps);
		dscreenMain();
		break;

	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProcW(hWnd, message, wParam, lParam);
	}
	return 0;
}

void create(HINSTANCE hi) {
	g_hi = hi;
	WNDCLASSEX wndc;
	wndc.hInstance = hi;
	wndc.hbrBackground = static_cast<HBRUSH>(GetStockObject(GRAY_BRUSH));
	wndc.cbClsExtra = 0;
	wndc.cbWndExtra = 0;
	wndc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wndc.hIconSm = LoadIcon(nullptr, IDI_ERROR);
	wndc.lpfnWndProc = wndproc;
	wndc.lpszClassName = "GAME";
	wndc.lpszMenuName = nullptr;
	wndc.cbSize = sizeof(WNDCLASSEX);
	wndc.style = CS_HREDRAW | CS_VREDRAW;
	auto check = RegisterClassEx(&wndc);
	g_hd = CreateWindowExW(
		WS_EX_APPWINDOW,
		L"GAME",
		L"GAME",
		CW_USEDEFAULT,
		0, 0,
		GetSystemMetrics(SM_CXSCREEN),
		GetSystemMetrics(SM_CYSCREEN),
		nullptr, nullptr, hi, nullptr);
}

void show() {
	SetForegroundWindow(g_hd);
	SetFocus(g_hd);
	ShowCursor(TRUE);
	ShowWindow(g_hd, SW_NORMAL);
	UpdateWindow(g_hd);
}

bool update() {
	ZeroMemory(&msg, sizeof(MSG));
	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.message != WM_QUIT;
}

int APIENTRY WinMain(HINSTANCE hi, HINSTANCE phi, LPSTR cmdshow, int cmdParam) { 
	zoneList.push_back(new Zone(-5, 540, 10, 1080));//left
	zoneList.push_back(new Zone(1920/2, 1080+5, 1920, 10));//down
	zoneList.push_back(new Zone(1920+5, 540, 10, 1080));//right
	zoneList.push_back(new Zone(1920/2, -5, 1920, 10));//up
	n = new Nagative();
	n2 = new Nagative2();
	M = new Main();
	p = new Player();
	m = new MinMax();
	create(hi);
	while (update()) {
		show();
	}
	return 0;
}