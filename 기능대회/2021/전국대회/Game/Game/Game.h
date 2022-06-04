#pragma once

extern void Init();
extern void Term();
extern void Update(float deltaTime);
extern void Render();
extern void MsgProc(UINT msg, WPARAM wParam, LPARAM lParam);

class Asset
{
public:
	Asset();
	~Asset();

	void AddTexture(string key, Texture* value);

	Texture* GetTexture(string key);

private:
	map<string, Texture*> _textures;
};

class Camera
{
public:
	void SetPos(D3DXVECTOR2 pos);
	D3DXVECTOR2 GetPos();

private:
	Sprite _sprite;
};


extern Asset* _g_Asset;
extern Loading* _g_Loading;
extern Scene* _g_Scene;
extern Camera* _g_Camera;