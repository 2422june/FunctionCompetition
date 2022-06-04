#include "Header.h"

CMissile::CMissile(D3DXVECTOR2 position, int homingCnt) {

	_sprite = CSprite();
	_scope = CSprite();

	_sprite._position = position;

	ALLCEN(_sprite, 25, 50);
	ALLCEN(_scope, 75, 75);
	_homingCnt = homingCnt;

	_speed = 1.0f;

	isBoom = false;

	isDestroy = false;
}

void CMissile::Update(float deltaTime) {

	SetRect(&_rect, _sprite._position.x - 30, _sprite._position.y - 30, _sprite._position.x + 30, _sprite._position.y + 30);

	_sprite._rotate = D3DXToDegree(atan2(_targetPos.y - _sprite._position.y, _targetPos.x - _sprite._position.x)) + 90;
	D3DXVec2Normalize(&_movDir, &D3DXVECTOR2(_targetPos.x - _sprite._position.x, _targetPos.y - _sprite._position.y));
	_sprite._position += _movDir * 800 * _speed *deltaTime;

	_scope._position = _targetPos;
	_scope._rotate += 3;
	if (_scope._rotate >= 360)
		_scope._rotate = 0;

	_sprite.Update(deltaTime);
	_scope.Update(deltaTime);
}

void CMissile::Render() {

	_sprite.Render(_g_Asset.missile);
	_scope.Render(_g_Asset.scope);
}