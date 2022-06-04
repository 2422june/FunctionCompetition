#pragma once

class CUI {

public:
	CUI();

public:
	CSprite _sprite;
	CSprite _needle1;
	CSprite _needle2;
	CSprite _handle;

	int _dir;
	int _life;
	int _mis;
	float _speed;

public:
	void Update(float deltaTime);
	void Render();
	void HandleMove(int dir);
};