#include "Header.h"

CMap::CMap(CTexture* texture, D3DXVECTOR2 position) {

	_texture = texture;
	_sprite = CSprite();
	_sprite._position = position;
	_sprite._center = D3DXVECTOR2(0, 5376);
}

void CMap::Update(float deltaTime) {

	_sprite.Update(deltaTime);
}

void CMap::Render() {

	_sprite.Render(_texture);
}