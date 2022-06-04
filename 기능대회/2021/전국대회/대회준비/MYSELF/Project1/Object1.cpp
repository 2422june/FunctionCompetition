#include "Header.h"

Object1::Object1(D3DXVECTOR2 pos) {
	_sprite = CSprite();
	_sprite._center = D3DXVECTOR2(64, 64);
	_sprite._rotateCen = D3DXVECTOR2(64, 64);
	_sprite._scaleCen = D3DXVECTOR2(64, 64);
	_sprite._position = pos;
	SetRect(&_rect, _sprite._position.x-64, _sprite._position.y- 64, _sprite._position.x + 64, _sprite._position.y + 64);
	health =100.0f;
	_damage = 50.0f;
	IsDestroy = false;
}

Object1::~Object1() {

}

void Object1::Update(float deltatime) {
	_sprite._position.y += 200 * deltatime;
	SetRect(&_rect, _sprite._position.x - 64, _sprite._position.y - 64, _sprite._position.x + 64, _sprite._position.y + 64);
	_sprite.Update(deltatime);
}


void Object1::Render() {
	_sprite.Render(_g_Asset->GetTexture("Object1"));
}

void Object1::GetDamage(float _damage) {
	health -= _damage;
	if (health <= 0) {
		IsDestroy = true;
	}
}