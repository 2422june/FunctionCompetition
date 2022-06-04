#pragma once

class CBullet {

public:
	CBullet(CTexture** texture, D3DXVECTOR2 position, D3DXVECTOR2 movDir, float speed, float damage);

public:
	CSprite _sprite;
	CTexture** _texture;

	RECT _rect;

	D3DXVECTOR2 _movDir;
	float _speed;
	float _damage;

	bool isDestroy;

	void Update(float deltaTime);
	void Render();
};