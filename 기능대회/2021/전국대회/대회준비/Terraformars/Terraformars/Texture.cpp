#include "Header.h"

HWND g_hWnd;
LPDIRECT3D9 g_pd3d;
LPDIRECT3DDEVICE9 g_pd3dDevice;
LPD3DXSPRITE g_Sprite;

CTexture::CTexture(LPCWSTR filename, LPCWSTR extname, int state, int scene) {

	for (int i = 0; i < scene; ++i) {

		LPDIRECT3DTEXTURE9 tex;
		wchar_t tmp[256];
		wsprintf(tmp, L"%s%02d%02d.%s", filename, state, i, extname);
		D3DXGetImageInfoFromFile(tmp, &_info);

		if (FAILED(D3DXCreateTextureFromFileEx(g_pd3dDevice, tmp, _info.Width, _info.Height, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &tex)))
			MessageBox(g_hWnd, tmp, L"Tex Load Err", MB_OK);

		_textures.push_back(tex);
	};
};

CTexture::~CTexture() {

	for (int i = 0; i < GetSize(); ++i) {

		if (_textures[i])
			_textures[i]->Release();
	};

	_textures.clear();
};