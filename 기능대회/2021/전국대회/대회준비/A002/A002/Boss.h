#pragma once

class CBoss {

public:
	CBoss();
	CBoss(int type, D3DXVECTOR2 position, list<CBullet*> *enemyBullets);
	~CBoss() {};

public:
	CSprite _sprite;
	CTexture** _texture;
	RECT _rect;

	list<CBullet*> *_enemyBullets;

	float gameTimer;
	int _life;
	int _type;
	bool isDestroy;
	bool isPat2;
	bool isPat3;

	float pat1Time;
	float pat1Timer;
	float pat2Time;
	float pat2Timer;
	int angle;
	int i;

	void Update(float deltaTime);
	void Render();
};