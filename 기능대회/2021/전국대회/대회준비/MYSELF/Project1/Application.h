#pragma once//헤더 중복 선언, 로드 방지

extern HWND g_hWnd;
extern LPDIRECT3D9 g_pd3d;
extern LPDIRECT3DDEVICE9 g_pd3dDevice;
extern LPD3DXSPRITE g_Sprite;
//extern 클레스를 불러오지 않고 자원을 쓸 수 있다(Public)
//다만 나중에 재선언 필요