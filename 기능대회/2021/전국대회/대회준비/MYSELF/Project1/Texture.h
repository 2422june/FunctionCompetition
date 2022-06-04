#pragma once
//텍스쳐 = 이미지
class CTexture {

public:
	vector<LPDIRECT3DTEXTURE9> _textures;
	D3DXIMAGE_INFO _info;

	CTexture(LPCWSTR filename, LPCWSTR extname, int state, int scene);
	~CTexture();

	LPDIRECT3DTEXTURE9 GetTexture(int i) {

		return _textures[i];
	}

	int GetSize() {

		return _textures.size();
	}

	UINT GetWidth() {

		return _info.Width;
	}

	UINT GetHeight() {

		return _info.Height;
	}
};