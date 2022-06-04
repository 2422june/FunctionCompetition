#include "Header.h"

CCutScene::CCutScene(int type) {

	_sprite = CSprite();

	ALLCEN(_sprite, 0, 0);
	_sprite._position = D3DXVECTOR2(0, 0);

	_type = type;

	if (_type == 0) {

		_sprite._scene = 0;
	}
	else if (_type == 1) {

		_sprite._scene = 1;
	}

	_cutTime = 2.0f;
	_cutTimer = 0;
	_stopTime = 0;
	_stopTimer = 0;
	_sprite._a = 0;

	isCut = false;
}

void CCutScene::Update(float deltaTime) {

	if (!isCut) {

		_sprite._a += 255 * deltaTime;
		if (_sprite._a >= 255) {

			_sprite._a = 255;

			_cutTimer += deltaTime;
			if (_cutTimer >= _cutTime) {

				_cutTimer = 0;
				isCut = true;
			}
		}
	}
	else {

		_sprite._a -= 255 * deltaTime;
		if (_sprite._a <= 0) {

			_sprite._a = 0;
		}
	}
	
	_sprite.Update(deltaTime);
}

void CCutScene::Render() {

	_sprite.Render(_g_Asset.cut);
}