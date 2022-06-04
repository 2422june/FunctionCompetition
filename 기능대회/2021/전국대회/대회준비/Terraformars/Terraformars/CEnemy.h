#pragma once

class CEnemy {

public:
	CEnemy(list<CBullet*> *bullets, int type, D3DXVECTOR2 positon, int item, int hommingCnt);

public:
	CSprite _sprite;
	list<CBullet*> *_bullets;
	CTexture* _texture;

	RECT _rect;

	D3DXVECTOR2 _movDir;

	int _item;
	int _type;
	int _hommingCnt;
	int dir;

	float _life;

	float _bulletTime;
	float _bulletTimer;
	float _effectTime;
	float _effectTimer;
	float _backTime;
	float _backTimer;

	bool isDestroy;
	bool isBack;

	void Update(float deltaTime);
	void Render();
};

class CEnemySpawnInfo {

public:
	float _time;
	int _type;
	D3DXVECTOR2 _position;
	int _item;
	bool isSpawn;

public:
	CEnemySpawnInfo() {};
	CEnemySpawnInfo(float time, int type, D3DXVECTOR2 position, int item) {

		_time = time;
		_type = type;
		_position = position;
		_item = item;
		isSpawn = false;
	}
};