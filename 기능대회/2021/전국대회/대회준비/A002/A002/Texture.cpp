#include "Header.h"

CTexture::CTexture(LPCWSTR filename, LPCWSTR extname, int state, int scene) {

	for (int i = 0; i < scene; ++i) {

		LPDIRECT3DTEXTURE9 tex;
		wchar_t temp[256];
		wsprintf(temp, L"%s%02d%02d.%s", filename, state, i, extname);

		D3DXGetImageInfoFromFile(temp, &_info);

		if (FAILED(D3DXCreateTextureFromFileEx(g_pd3dDevice, temp, _info.Width, _info.Height, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &tex)))
			MessageBox(g_hWnd, temp, L"Tex Load Err", MB_OK);

		_textures.push_back(tex);
	}
}

CTexture::~CTexture() {

	for (int i = 0; i < GetSize(); ++i) {

		if (_textures[i])
			_textures[i]->Release();
	}

	_textures.clear();
}