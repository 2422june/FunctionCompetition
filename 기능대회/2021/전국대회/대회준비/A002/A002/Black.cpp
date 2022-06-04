#include "Header.h"

CBlack::CBlack() {

	isLoading = false;
	isFadeIn = false;
	loadTime = 0.3;
	loadTimer = 0;

	_sprite = CSprite();
	_sprite._a = 0;
}

void CBlack::Update(float deltaTime) {

	if (isLoading) {

		if (isFadeIn) {

			_sprite._a += 255.0f * deltaTime;
			if (_sprite._a >= 255) {

				_sprite._a = 255;
				loadTimer += deltaTime;
				if (loadTimer >= loadTime) {

					isFadeIn = false;
					delete _g_Scene;
					_g_Scene = _scene;
				}
			}
		}

		else {

			_sprite._a -= 255.0f * deltaTime;
			if (_sprite._a <= 0) {

				_sprite._a = 0;
				isLoading = false;
			}
		}
	}

	_sprite.Update(deltaTime);
}

void CBlack::Render() {

	_sprite.Render(_g_Asset.Black);
}

void CBlack::LoadScene(CScene* scene) {

	if (!isLoading) {

		isLoading = true;
		isFadeIn = true;
		loadTimer = 0;

		_scene = scene;
	}
}