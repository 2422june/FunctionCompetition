#pragma once

class CItem {

public:
	CItem();
	CItem(D3DXVECTOR2 position, int type);

public:
	RECT _rect;
	CSprite _sprite;
	CTexture** _texture;
	D3DXVECTOR2 _moveDir;

	int _type;
	bool isDestroy;

	void Update(float deltaTime);
	void Render();
};