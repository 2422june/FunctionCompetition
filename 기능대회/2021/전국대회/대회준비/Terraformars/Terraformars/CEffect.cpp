#include "Header.h"

CEffect::CEffect(int type, D3DXVECTOR2 position) {

	_sprite = CSprite();

	_sprite._position = position;

	if (type == 0) {

		ALLCEN(_sprite, 75, 75);
		texture = _g_Asset.effect[0];
	}
	if (type == 1) {

		ALLCEN(_sprite, 150, 150);
		texture = _g_Asset.effect[1];
	}
	if (type == 2) {

		ALLCEN(_sprite, 75, 75);
		texture = _g_Asset.effect[2];
	}
	if (type == 3) {

		ALLCEN(_sprite, 150, 150);
		texture = _g_Asset.effect[3];
	}
	if (type == 4) {

		ALLCEN(_sprite, 75, 75);
		texture = _g_Asset.effect[4];
	}
	if (type == 5) {

		ALLCEN(_sprite, 150, 150);
		texture = _g_Asset.effect[5];
	}

	_sprite.SetAnimation(false, 0.05f, 19);
}

void CEffect::Update(float deltaTime) {
	
	if(!_sprite._isAniEnd)
		_sprite.Update(deltaTime);
}

void CEffect::Render() {

	if (!_sprite._isAniEnd)
		_sprite.Render(texture);
}