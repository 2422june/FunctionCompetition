#include "Header.h"

CBomb::CBomb() {

	_sprite._center = D3DXVECTOR2(0, 0);
	_sprite._position = D3DXVECTOR2(0, 0);

	bombStayTime = 2;
	bombStayTimer = 0;
	_sprite.SetAnimation(true, 0.05, 14);
}

void CBomb::Update(float deltaTime) {

	SetRect(&_rect, _sprite._position.x, _sprite._position.y, _sprite._position.x, _sprite._position.y);

	if (!isDestroy) {

		SetRect(&_rect, _sprite._position.x - 1000, _sprite._position.y - 1000, _sprite._position.x + 1000, _sprite._position.y + 1000);

		bombStayTimer += deltaTime;
		if (bombStayTimer >= bombStayTime) {

			Single::GetInstance()->howBomb--;
			isDestroy = true;
			bombStayTimer = 0;
		}

		_sprite.Update(deltaTime);
	}
}

void CBomb::Render() {

	if (!isDestroy)
		_sprite.Render(_g_Asset.playerBomb);
}