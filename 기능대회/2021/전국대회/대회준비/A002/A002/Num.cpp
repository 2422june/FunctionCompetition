#include "Header.h"

CNum::CNum(CTexture** texture, D3DXVECTOR2 position) {

	_texture = texture;

	_sprite = CSprite();
	_sprite._position = position;
	_sprite._center = D3DXVECTOR2(_texture[0]->GetWidth() / 2, _texture[0]->GetHeight() / 2);
}

void CNum::Update(float deltaTime) {

	_sprite.Update(deltaTime);
}

void CNum::Render() {

	_sprite.Render(*_texture);
}