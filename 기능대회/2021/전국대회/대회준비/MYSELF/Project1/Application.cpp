//기본파일
#include "Header.h"

HWND g_hWnd;
LPDIRECT3D9 g_pd3d;
LPDIRECT3DDEVICE9 g_pd3dDevice;
LPD3DXSPRITE g_Sprite;

float _elapsedTime;//프레임간의 간격계산
DWORD _prevTime;

//다이렉트 초기화
HRESULT InitD3D() {

	g_pd3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_pd3d == NULL)//초기화가 안됬는가?
		return E_FAIL;

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;//True는 창, False는 전체화면
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	if (FAILED(g_pd3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice)))
		return E_FAIL;

	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	D3DXCreateSprite(g_pd3dDevice, &g_Sprite);
	Init();

	return S_OK;
}

//렌더링:화면의 화소계산 과정(2D로 변경하는 과정)
//렌더링 파이프라인
HRESULT D3DRendering() {

	if (g_pd3dDevice == NULL)
		return E_FAIL;
	//128, 128, 128:화면에 아무 그림이 없을때 띄울 색
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(128, 128, 128), 1.0f, 0);

	if (SUCCEEDED(g_pd3dDevice->BeginScene())) {

		//스프라이트 화면에 나올 무언가들(오브젝트)
		g_Sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_DEPTH_FRONTTOBACK);
		Render();
		g_Sprite->End();
		g_pd3dDevice->EndScene();
	}

	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
	return S_OK;
}

//화면**
void CleanUp() {

	Term();

	if (g_Sprite)
		g_Sprite->Release();

	if (g_pd3d)
		g_pd3d->Release();

	if (g_pd3dDevice)
		g_pd3dDevice->Release();
}


//키 입력 처리
LRESULT WINAPI MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	MsgProc(uMsg, wParam, lParam);

	switch (uMsg) {

	case WM_DESTROY://창 종료
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//메인 화면
 INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, INT) {

	WNDCLASSEX wcx = {

		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, L"FrameWork", NULL
	};
	RegisterClassEx(&wcx);

	//윈도우 생성
	g_hWnd = CreateWindow(L"FrameWork", L"FrameWork", WS_OVERLAPPEDWINDOW /*WS_POPUP | WS_EX_TOPMOST*/, 100, 100, 1024, 768, GetDesktopWindow(), NULL, wcx.hInstance, NULL);

	//메세지 출력 (핸들, 내용, 제목, 몰라)
	MessageBox(nullptr, L"Hello", L"H", MB_OK);

	int timeCount = 0;
	//다이렉트의 버전확인, 초기화 확인 등이 잘 됬는가
	if (SUCCEEDED(InitD3D())) {

		ShowWindow(g_hWnd, SW_SHOWDEFAULT);
		UpdateWindow(g_hWnd);
		MSG msg;
		ZeroMemory(&msg, sizeof(MSG));

		while (msg.message != WM_QUIT) {

			//메인 루프
			if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {

				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else {
				//
				DWORD curTime = timeGetTime();//현재시간 체크
				if (timeCount == 0) {

					timeCount = 1;
					_elapsedTime = 0;
				}
				else
					_elapsedTime = (curTime - _prevTime) / 1000.0f;//현재시간 - 이전시간으로 프레임 간격 계산
				_prevTime = curTime;//이전시간

				Update(_elapsedTime);//Time.deltaTime처럼 사용하기 위함
				D3DRendering();
			}
		}
	}

	UnregisterClass(L"FrameWork", wcx.hInstance);
	return 0;
}