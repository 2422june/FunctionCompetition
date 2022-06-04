#pragma once

class CNum {

public:
	CNum(D3DXVECTOR2 position);

public:
	CSprite _sprite;
	int _num;

	void Update(float deltaTime);
	void Render();
};