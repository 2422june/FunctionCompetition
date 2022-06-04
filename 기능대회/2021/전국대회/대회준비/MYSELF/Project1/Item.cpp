#include "Header.h"

Item::Item(int iType, D3DXVECTOR2 pos) {
	_sprite = CSprite();
	_sprite._position = pos;
	_iType = iType;
	RECT _rect;
	GetItem = false;
	_damage = 50.0f;
	_speed = 150.0f;
	if (_iType == 0) {
		_sprite._center = D3DXVECTOR2(45, 45);
		_sprite._scaleCen = D3DXVECTOR2(45, 45);
		_sprite._rotateCen = D3DXVECTOR2(45, 45);
		cen = 45;
	}
	else {
		_sprite._center = D3DXVECTOR2(50, 50);
		_sprite._scaleCen = D3DXVECTOR2(50, 50);
		_sprite._rotateCen = D3DXVECTOR2(50, 50);
		cen = 50;
	}
	_sprite.SetAnimation(true, 0.0, 21);
}
Item::~Item() {
}

void Item::Move() {
}


void Item::Update(float deltatime) {
	SetRect(&_rect, _sprite._position.x - cen, _sprite._position.y - cen, _sprite._position.x + cen, _sprite._position.y + cen);
	_sprite.Update(deltatime);
}
void Item::Render() {
	if (_iType == 0) {
		_sprite.Render(_g_Asset->GetTexture("Item0"));
	}
	else {
		_sprite.Render(_g_Asset->GetTexture("Item1"));
	}
}