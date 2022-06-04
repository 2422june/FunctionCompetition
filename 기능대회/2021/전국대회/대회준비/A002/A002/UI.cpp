#include "Header.h"

CUI::CUI(CTexture** texture) {

	_texture = texture;

	_sprite = CSprite();
	_sprite._position = D3DXVECTOR2(0, 0);
	_sprite._center = D3DXVECTOR2(0, 0);

};

void CUI::Update(float deltaTime) {

	_sprite.Update(deltaTime);
}

void CUI::Render() {

	_sprite.Render(*_texture);
}