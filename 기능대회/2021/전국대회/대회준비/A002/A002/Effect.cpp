#include "Header.h"

CEffect::CEffect(CTexture** texture, D3DXVECTOR2 position, float aniTime) {

	_texture = texture;
	_aniTime = aniTime;

	_sprite = CSprite();
	_sprite._position = position;
	_sprite._center = D3DXVECTOR2((*texture)->GetWidth() / 2, (*texture)->GetHeight() / 2);

	_sprite.SetAnimation(false, _aniTime, (*texture)->GetSize());

	isDestroy = false;
}

void CEffect::Update(float deltaTime) {
	
	if (_sprite._isAniEnd)
		isDestroy = true;

	_sprite.Update(deltaTime);
}

void CEffect::Render() {

	_sprite.Render(*_texture);
}