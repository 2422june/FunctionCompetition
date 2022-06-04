#include "Header.h"

CBlack::CBlack() {

	_sprite = CSprite();
	isFadeIn = false;
	isLoading = false;

	ALLCEN(_sprite, 0, 0);
	_sprite._position = D3DXVECTOR2(0, 0);
	_sprite._a = 0;
}

void CBlack::Update(float deltaTime) {
	
	if (isLoading) {

		
		if (!isFadeIn) {

			_sprite._a += 255 * deltaTime;
			if (_sprite._a >= 255) {

				isFadeIn = true;
				delete _g_Scene;
				_g_Scene = _scene;
			}
		}
		else {

			_sprite._a -= 255 * deltaTime;
			if (_sprite._a <= 0) {
				isLoading = false;
				isFadeIn = false;
				_sprite._a = 0;
			}
		}
	}

	_sprite.Update(deltaTime);
}

void CBlack::Render() {

	_sprite.Render(_g_Asset.black);
}


void CBlack::LoadScene(CScene* scene) {

	if(!isLoading)
		isLoading = true;
	_scene = scene;
}