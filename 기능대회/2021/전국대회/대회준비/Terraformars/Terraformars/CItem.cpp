#include "Header.h"

CItem::CItem(int type, D3DXVECTOR2 position) {

	_sprite = CSprite();
	
	_sprite._position = position;
	_type = type;

	ALLCEN(_sprite, 45, 45);

	if (_type == 1) {

		ALLCEN(_sprite, 50, 50);
		_texture = _g_Asset.item[0];
	}
	if (_type == 2) {

		_texture = _g_Asset.item[1];
	}
	if (_type == 3) {

		_texture = _g_Asset.item[2];
	}
	if (_type == 4) {

		_texture = _g_Asset.item[3];
	}
	if (_type == 5) {

		_texture = _g_Asset.item[4];
	}
	if (_type == 6) {

		_texture = _g_Asset.item[5];
	}

	isDestroy = false;
	_sprite.SetAnimation(true, 0.03f, 26);
}

void CItem::Update(float deltaTime) {

	SetRect(&_rect, _sprite._position.x - 50, _sprite._position.y - 50, _sprite._position.x + 50, _sprite._position.y + 50);

	_sprite._position.y += 300 * deltaTime;
	_sprite.Update(deltaTime);
};

void CItem::Render() {

	_sprite.Render(_texture);
};