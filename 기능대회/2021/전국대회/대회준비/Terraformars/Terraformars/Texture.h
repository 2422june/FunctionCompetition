#pragma once

class CTexture {

public:
	CTexture(LPCWSTR filename, LPCWSTR extname, int state, int scene);
	virtual ~CTexture();

public:
	vector<LPDIRECT3DTEXTURE9> _textures;
	D3DXIMAGE_INFO _info;

	LPDIRECT3DTEXTURE9 GetTexture(int i) {

		return _textures[i];
	};

	UINT GetSize() {

		return _textures.size();
	};

	int GetWidth() {

		return _info.Width;
	};

	int GetHeight() {

		return _info.Height;
	};
};