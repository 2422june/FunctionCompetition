#pragma once

class CEffect {

public:
	CEffect();
	CEffect(CTexture** texture, D3DXVECTOR2 position, float aniTime);

public:
	CSprite _sprite;
	CTexture** _texture;
	D3DXVECTOR2 _position;

	bool isDestroy;
	float _aniTime;

	void Update(float deltaTime);
	void Render();
};