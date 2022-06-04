#include "Header.h"

Efect::Efect(D3DXVECTOR2 pos) {
	_sprite = CSprite();
	_sprite._center = D3DXVECTOR2(75, 75);
	_sprite._rotateCen = D3DXVECTOR2(75, 75);
	_sprite._scaleCen = D3DXVECTOR2(75, 75);
	_sprite._position = pos;
	_isDestroy = false;
	_sprite.SetAnimation(false, 0, 19);
}

Efect::~Efect() {

}

void Efect::Update(float deltaTime) {
	if (_sprite._isAniEnd) {
		_isDestroy = true;
	}
	_sprite.Update(deltaTime);
}

void Efect::Render() {
	_sprite.Render(_g_Asset->GetTexture("Efect1"));
}