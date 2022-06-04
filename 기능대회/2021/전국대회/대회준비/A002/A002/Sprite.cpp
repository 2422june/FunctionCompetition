#include "Header.h"

CSprite::CSprite() {

	_position = D3DXVECTOR2(0, 0);
	_scaleCen = D3DXVECTOR2(0, 0);
	_scale = D3DXVECTOR2(1, 1);
	_rotateCen = D3DXVECTOR2(0, 0);
	_center = D3DXVECTOR2(0, 0);
	_rotate = 0;

	_isAnimation = false;
	_isRepeat = false;
	_isAniEnd = false;
	_animationTime = 0;
	_aniStackTime = 0;
	_scene = 0;
	_maxScene = 0;
	_camera = NULL;

	_a = _r = _g = _b = 255;
}

void CSprite::Update(float deltaTime) {

	D3DXMatrixIdentity(&_matrix);
	D3DXVECTOR2 pos = _position;
	pos = pos - _center;

	if(!_camera)
		D3DXMatrixTransformation2D(&_matrix, &_scaleCen, 0.f, &_scale, &_rotateCen, D3DXToRadian(_rotate), &pos);
	else {

		D3DXVECTOR2 camPos = pos - _camera->_sprite._position;
		D3DXMatrixTransformation2D(&_matrix, &_scaleCen, 0.f, &_scale, &_rotateCen, D3DXToRadian(_rotate), &camPos);
	}

	if (_isAnimation) {

		_aniStackTime += deltaTime;

		if (_aniStackTime >= _animationTime) {

			_aniStackTime = 0;

			if (++_scene >= _maxScene) {

				if (_isRepeat) {

					_scene = 0;
				}
				else {

					--_scene;
					_isAniEnd = true;
				}
			}
		}
	}
}

void CSprite::Render(CTexture* texture) {

	g_Sprite->SetTransform(&_matrix);
	g_Sprite->Draw(texture->GetTexture(_scene), NULL, NULL, NULL, D3DCOLOR_ARGB(_a, _r, _g, _b));
}

void CSprite::SetAnimation(bool repeat, float time, int maxScene) {

	_isAnimation = true;
	_isRepeat = repeat;
	_isAniEnd = false;
	_animationTime = time;
	_aniStackTime = 0;
	_scene = 0;
	_maxScene = maxScene;
}

void CSprite::SetCamera(Camera* camera) {

	_camera = camera;
}