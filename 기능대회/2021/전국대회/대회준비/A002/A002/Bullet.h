#pragma once

class CBullet {

public:
	CBullet();
	CBullet(CTexture** texture, D3DXVECTOR2 position, D3DXVECTOR2 moveDir, float speed);

public:
	CSprite _sprite;
	CTexture** _texture;
	RECT _rect;

	D3DXVECTOR2 _moveDir;
	float _speed;
	bool isDestroy;

	void Update(float deltaTime);
	void Render();
};