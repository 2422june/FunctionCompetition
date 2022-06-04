#pragma once

class CMap {

public:
	CMap();
	CMap(CTexture* texture, D3DXVECTOR2 position);

public:
	CSprite _sprite;
	CTexture* _texture;

	void Update(float deltaTime);
	void Render();
};