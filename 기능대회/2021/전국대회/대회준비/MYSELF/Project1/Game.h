#pragma once

extern void Init();
extern void Term();
extern void Update(float deltaTime);
extern void Render();
extern void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

class Asset {

private:
	map<string, CTexture*> _textures;

public:
	Asset();
	~Asset();

	void AddTexture(string key, CTexture* value);
	CTexture* GetTexture(string key);

};

class CCamera {

private:
	CSprite _sprite;

public:
	void SetPos(D3DXVECTOR2 pos);
	D3DXVECTOR2 GetPos();
};

extern Asset* _g_Asset;
extern CLoading* _g_Loading;
extern CCamera* _g_Camera;