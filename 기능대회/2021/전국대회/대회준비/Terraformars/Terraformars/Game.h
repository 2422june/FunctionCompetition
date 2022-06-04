#pragma once

extern void Init();
extern void Term();
extern void Update(float deltaTime);
extern void Render();
extern void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

class Asset {

public:

	CTexture* scope;
	CTexture* missile;

	CTexture** item;

	CTexture* addon;
	CTexture** effect;
	CTexture** bullets;
	CTexture* laser;
	CTexture* air;
	CTexture** playerImg;
	CTexture* shadow;
	CTexture* sheild;

	CTexture** enemy;
	CTexture** boss;

	CTexture* title;
	CTexture* num;

	CTexture* black;
	CTexture* text;
	CTexture* rank;
	CTexture* ranking;

	CTexture* cut;
	CTexture* end;
	CTexture* vic;
	CTexture* fai;

	CTexture* ui;
	CTexture* handle;
	CTexture* needle;

	CTexture* how;
	CTexture** Intro;

	CTexture* map;
	CTexture* map2;
};

extern Asset _g_Asset;