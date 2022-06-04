#pragma once

extern void Init();
extern void Term();
extern void Update(float deltaTime);
extern void Render();
extern void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

class Asset {

public:

	CTexture* Intro;
	CTexture* Black;
	CTexture* Title;
	CTexture* Victory;
	CTexture* Failed;

	CTexture** playerImg;
	CTexture* playerBullet;
	CTexture* playerBomb;

	CTexture** enemyImg;
	CTexture* enemyBullet;
	CTexture* enemySpaceBullet;
	CTexture* enemyLaser;

	CTexture* itemPower;

	CTexture* Boss1Img;
	CTexture* Boss2Img;

	CTexture** Effect;

	CTexture* Map0;
	CTexture* Map1;

	CTexture* CUI;
	CTexture* Num;
};

extern Asset _g_Asset;
extern CBlack _g_Black;