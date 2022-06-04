#pragma once

class CMissile {

public:
	CMissile(D3DXVECTOR2 position, int homingCnt);

public:
	CSprite _sprite;
	CSprite _scope;

	D3DXVECTOR2 _movDir;
	D3DXVECTOR2 _targetPos;

	RECT _rect;
	RECT _boomRect;

	float _boomTime;
	float _boomTimer;
	float _speed;

	int _homingCnt;

	bool isDestroy;
	bool isBoom;

	void Update(float deltaTime);
	void Render();
};