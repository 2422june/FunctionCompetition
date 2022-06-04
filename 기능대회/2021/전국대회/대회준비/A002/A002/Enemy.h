#pragma once

class CEnemy {

public:
	CEnemy() {};
	CEnemy(int type, D3DXVECTOR2 position, list<CBullet*> *enemyBullets, int item);

public:
	CTexture** _texture;
	CSprite _sprite;
	list<CBullet*> *_enemyBullets;

	RECT _rect;
	bool isDestroy;
	int _life;
	int _type;
	int _item;

	float type1Speed;
	float type1BulletTime;
	float type1BulletTimer;
	float type2LaserTime;
	float type2LaserTimer;
	float type2BulletTime;
	float type2BulletTimer;

	float tmpPlayX;
	float tmpPlayY;

	void Update(float deltaTime);
	void Render();
};

class CEnemySpawn {

public:
	CEnemySpawn() {};
	CEnemySpawn(float time, int type, D3DXVECTOR2 pos, int item) {

		_time = time;
		_type = type;
		_pos = pos;
		_item = item;
		isSpawn = false;
	}

public:
	D3DXVECTOR2 _pos;
	float _time;
	int _type;
	int _item;
	bool isSpawn;
};