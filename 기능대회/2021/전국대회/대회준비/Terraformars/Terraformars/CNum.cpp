#include "Header.h"

CNum::CNum(D3DXVECTOR2 position) {

	_sprite = CSprite();
	_sprite._position = position;
	ALLCEN(_sprite, 17.5, 25);

	_num = 0;
}

void CNum::Update(float deltaTime) {

	_sprite._scene = _num;
	_sprite.Update(deltaTime);
}


void CNum::Render() {

	_sprite.Render(_g_Asset.num);
}