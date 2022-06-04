#include "Header.h"

CBullet::CBullet(CTexture** texture, D3DXVECTOR2 position, D3DXVECTOR2 moveDir, float speed) {

	_texture = texture;

	_sprite = CSprite();
	_sprite._position = position;
	_sprite._center = D3DXVECTOR2(_texture[0]->GetWidth() / 2, _texture[0]->GetHeight() / 2);

	_sprite.SetAnimation(true, 0.05, (*texture)->GetSize());
	D3DXVec2Normalize(&_moveDir, &moveDir);

	_speed = speed;
}

void CBullet::Update(float deltaTime) {

	SetRect(&_rect, _sprite._position.x - 8, _sprite._position.y - 8, _sprite._position.x + 8, _sprite._position.y + 8);
	_sprite._position += _moveDir * _speed * deltaTime;
	_sprite.Update(deltaTime);

	if ((_sprite._position.x > 768) || (_sprite._position.x < 0) || (_sprite._position.y > 768) || (_sprite._position.y < 0))
		isDestroy = true;
}

void CBullet::Render() {

	_sprite.Render(*_texture);
}