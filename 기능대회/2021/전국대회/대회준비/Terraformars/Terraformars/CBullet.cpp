#include "Header.h"

CBullet::CBullet(CTexture** texture, D3DXVECTOR2 position, D3DXVECTOR2 movDir, float speed, float damage) {

	_sprite = CSprite();
	ALLCEN(_sprite, (*texture)->GetWidth() / 2, (*texture)->GetHeight() / 2);

	_sprite._position = position;
	_texture = texture;
	_movDir = movDir;
	_speed = speed;
	_damage = damage;
	D3DXVec2Normalize(&_movDir, &movDir);
	isDestroy = false;

	_sprite.SetAnimation(true, 0.05f, (*texture)->GetSize());
};

void CBullet::Update(float deltaTime) {

	SetRect(&_rect, _sprite._position.x - 16, _sprite._position.y - 16, _sprite._position.x + 16, _sprite._position.y + 16);

	_sprite._position += _movDir * _speed * deltaTime;

	if (_sprite._position.x >= 1024 | _sprite._position.x <= 0 | _sprite._position.y >= 768 | _sprite._position.y <= 0)
		isDestroy = true;

	_sprite.Update(deltaTime);
};

void CBullet::Render() {

	_sprite.Render(*_texture);
};