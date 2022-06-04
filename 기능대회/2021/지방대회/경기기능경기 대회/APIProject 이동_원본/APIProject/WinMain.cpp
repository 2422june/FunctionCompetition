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


//�Է�ó���� �ϴ� Ư���� �Լ�(��׶���), ������ �޼����� ó���ϴ� �Լ�
LRESULT/**/ CALLBACK/*ȣ������� �ʴ� �Լ�, Ư�������� �����Ҷ� �ڵ�(?) ����*/ WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_TIMER://Ư���ð�(��������)���� ���𰡸� �����ϴ� �޼���.
		if (wParam == 1)//1�� Ÿ�̸Ӱ� ��ȴ°�?
		{

			DrawScreen();//��ũ���� �׷���

		}
		break;

	case WM_CREATE://message == WM_CREATE
		SetTimer(hWnd, 1/*��ȣ*/, (1000 / (float)30), nullptr);//�и�������(1000���� 1��) * 1000 / 30 ����(1�ʿ� 30��) 1�� Ÿ�̸Ӹ� �۵����Ѷ�
		SetTimer(hWnd, 2, (1000 / (float)200), nullptr);//�и�������(1000���� 1��) * 1000 / 2 ����(1�ʿ� 2��) 2�� Ÿ�̸Ӹ� �۵����Ѷ�


		hdc = GetDC(g_handle);
		planeDC = CreateCompatibleDC(hdc);
		bgDC = CreateCompatibleDC(hdc);
		ReleaseDC(g_handle, hdc);

		plainBitmap = LoadBMF("../a./MyPlane.bmp"/*path, ���*/);//..:����, .:���� ����ּ�
		SelectObject(planeDC, plainBitmap);//()���� ������ ������Ʈ ����

		bgBitmap = LoadBMF("../a./Background.bmp"/*path, ���*/);//..:����, .:���� ����ּ�
		SelectObject(bgDC, bgBitmap);//()���� ������ ������Ʈ ����

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
}//�׳ɾϱ�

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


