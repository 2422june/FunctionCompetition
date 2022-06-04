#include "Header.h"

HWND g_hwnd;
LPDIRECT3DDEVICE9 g_d3dDevice;
LPDIRECT3D9 g_d3d;
LPD3DXSPRITE g_sprite;

float frameTime;
DWORD _prevTime;

HRESULT Init3D() {
	g_d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_d3d == NULL) {
		return E_FAIL;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	
	d3dpp.BackBufferWidth = 1920;
	d3dpp.BackBufferHeight = 1080;

	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	if (FAILED(g_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &g_d3dDevice))) {
		return E_FAIL;
	}

	g_d3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	D3DXCreateSprite(g_d3dDevice, &g_sprite);

	Init();

	return S_OK;
}

HRESULT D3DRendering() {
	if (g_d3dDevice == NULL) {
		return E_FAIL;
	}

	g_d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(128, 128, 128), 1, 0);
	if (SUCCEEDED(g_d3dDevice->BeginScene())) {
		g_sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_DEPTH_FRONTTOBACK);
		Render();
		g_sprite->End();
		g_d3dDevice->EndScene();
	}

	g_d3dDevice->Present(NULL, NULL, NULL, NULL);
	return S_OK;
}

void CleanUp() {
	Term();
	if (g_d3d) {
		g_d3d->Release();
	}
	if (g_d3dDevice) {
		g_d3dDevice->Release();
	}
	if (g_sprite) {
		g_sprite->Release();
	}
}

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	MsgProc(msg, wParam, lParam);

	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, INT) {
	WNDCLASSEX wcx = {
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		L"Game", NULL
	};
	RegisterClassEx(&wcx);

	g_hwnd = CreateWindow(L"Game", L"Game", WS_OVERLAPPEDWINDOW, 0, 0, 1920, 1080, GetDesktopWindow(), NULL, wcx.hInstance, NULL);
	int timeCnt = 0;

	if (SUCCEEDED(Init3D())) {
		ShowWindow(g_hwnd, SW_SHOWDEFAULT);
		UpdateWindow(g_hwnd);
		MSG msg;
		ZeroMemory(&msg, sizeof(MSG));

		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else {
				DWORD curTime = timeGetTime();
				if (timeCnt == 0) {
					timeCnt = 1;
					frameTime = 0;
				}
				else {
					frameTime = (curTime - _prevTime) / 1000.0f;
				}
				_prevTime = curTime;
				Update(frameTime);
				D3DRendering();
			}
		}
	}
	UnregisterClass(L"Game", wcx.hInstance);
	return 0;
}