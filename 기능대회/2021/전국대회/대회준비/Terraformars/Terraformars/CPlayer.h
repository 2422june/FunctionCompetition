#pragma once

class CPlayer {

public:
	CPlayer(list<CBullet*> *bullets, list<CMissile*> *missiles);

public:

	CSprite _sprite;
	CSprite _shadow;
	CSprite _sheild;
	CSprite _laser;
	CSprite _addon;
	list<CBullet*> *_bullets;
	list<CMissile*> *_missiles;

	RECT _rect;

	float _bulletTime;
	float _bulletTimer;
	float _godTime;
	float _godTimer;
	float _missileTime;
	float _missileTimer;
	float _speed;
	float _sheildTime;
	float _sheildTimer;
	float _addonBulletTime;
	float _addonBulletTimer;

	float _laserTime;
	float _laserTimer;

	int _state;
	int _power;
	int _addCount;
	int _missile;

	float _life;

	bool isAttack;
	bool isMissile;
	bool isHit;
	bool shoot;
	bool isSheild;
	bool canDamage;
	bool isLaser;

	void Move(int x, int y);
	void ChangeState(int state);
	void Attack();
	void Missile();
	void Hit(int damage);
	void GetItem(int type);
	void Update(float deltaTime);
	void Render();
};

class Single : public CSingleTon<Single> {

public:
	float playerX;
	float playerY;

	int _missile;
	int _addon;
	int _power;
	float _speed;

	int gameScore;
};