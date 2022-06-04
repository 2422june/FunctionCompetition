#pragma once

class CEffect {

public:
	CEffect(int type, D3DXVECTOR2 position);

public:
	CSprite _sprite;
	CTexture* texture;

	void Update(float deltaTime);
	void Render();
};