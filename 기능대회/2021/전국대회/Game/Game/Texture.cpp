#include "Header.h"

Texture::Texture(LPCWSTR filename, LPCWSTR extname, int state, int maxScene, int num, int val) {
	for (int i = val; i < maxScene; ++i) {
		LPDIRECT3DTEXTURE9 _tex;
		wchar_t tmp[256];

		switch (num) {
		case 0:
			wsprintf(tmp, L"%s.%s", filename, extname);
			break;

		case 2:
			wsprintf(tmp, L"%s%02d.%s", filename, i, extname);
			break;

		case 4:
			wsprintf(tmp, L"%s%04d.%s", filename, i, extname);
			break;

		case 6:
			wsprintf(tmp, L"%s%04d%02d.%s", filename, state, i, extname);
			break;
		}

		D3DXGetImageInfoFromFile(tmp, &_info);

		if (FAILED(D3DXCreateTextureFromFileEx(g_d3dDevice, tmp, _info.Width, _info.Height, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
			D3DX_DEFAULT, D3DX_DEFAULT, NULL, NULL, NULL, &_tex)))
		{
			MessageBox(g_hwnd, tmp, L"Img Load Err", MB_OK);
		}

		_textures.push_back(_tex);
	}
}

Texture::~Texture() {
	for (int i = 0; i < GetSize(); ++i) {
		if (_textures[i]) {
			_textures[i]->Release();
		}
	}
	_textures.clear();
}