#pragma once

class CPlayer {

public:
	list<CBullet*> *_bullets;
	CPlayer() {};
	CPlayer(list<CBullet*> *bullets);

public:
	CSprite _sprite;
	RECT _rect;

	float pBulletTime;
	float pBulletTimer;
	float pMisTime;
	float pMisTimer;
	bool isAttack;
	bool canHit;
	bool isDestroy;
	int isSlow;

	int _life;
	int _state;
	int _power;
	int _gameScore;

	void Move(float x, float y);
	void ChangeState(int state);
	void Attack();
	void Hit();
	void Born();

	void Update(float deltaTime);
	void Render();
};

class Single : public SingleTon<Single> {

public:

	int _gameScore;
	int howBomb;
	float PlayerX;
	float PlayerY;
	bool canHit;
};