#pragma once

class CItem {

public:
	CItem(int type, D3DXVECTOR2 position);

public:
	CSprite _sprite;
	CTexture* _texture;

	RECT _rect;
	int _type;
	bool isDestroy;

	void Update(float deltaTime);
	void Render();
};