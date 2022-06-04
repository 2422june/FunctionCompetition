#include "Header.h"

CItem::CItem(D3DXVECTOR2 position, int type) {

	_type = type;
	_sprite = CSprite();
	_sprite._position = position;
	_sprite._center = D3DXVECTOR2(32, 32);

	if (_type == 1) {

		_texture = &_g_Asset.itemPower;
		_sprite.SetAnimation(true, 0.02, 25);
	}

	D3DXVec2Normalize(&_moveDir, &D3DXVECTOR2(0, 1));
	isDestroy = false;
}

void CItem::Update(float deltaTime) {

	SetRect(&_rect, _sprite._position.x - 32, _sprite._position.y - 32, _sprite._position.x + 32, _sprite._position.y + 32);
	_sprite._position += _moveDir * 250 * deltaTime;

	if ((_sprite._position.x > 868) || (_sprite._position.x < -100) || (_sprite._position.y > 868) || (_sprite._position.y < -100))
		isDestroy = true;

	_sprite.Update(deltaTime);
}

void CItem::Render() {

	_sprite.Render(*_texture);
}