#include "Header.h"

CLoading::CLoading(){

	bIsLoading = false;
	bIsFadeIn = false;
	loadTime = 0.f;
	loadTimer = 0.f;

	_sprite = CSprite();
	_sprite._a = 0.f;
}

void CLoading::Update(float deltaTime) {

	if (bIsLoading) {

		if (bIsFadeIn) {

			_sprite._a += 255.0f * deltaTime;
			if (_sprite._a >= 255) {

				_sprite._a = 255;
				loadTimer += deltaTime;

				if (loadTimer >= loadTime) {

					bIsFadeIn = false;
					delete _g_Scene;
					_g_Scene = _scene;
				}
			}
		}
		else {

			_sprite._a -= 255.0f * deltaTime;
			if (_sprite._a <= 0) {

				_sprite._a = 0;
				bIsLoading = false;
			}
		}
	}

	_sprite.Update(deltaTime);
}

void CLoading::Render() {

	_sprite.Render(_g_Asset->GetTexture("Loading"));
}

void CLoading::LoadScene(CScene* scene) {

	if (!bIsLoading) {

		bIsLoading = true;
		bIsFadeIn = true;
		loadTimer = 0.f;

		_scene = scene;
	}
}