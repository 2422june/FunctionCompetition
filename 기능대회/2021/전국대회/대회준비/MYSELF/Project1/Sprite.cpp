#include "Header.h"

CSprite::CSprite() {
	//초기화
	_zDepthPosition = D3DXVECTOR3(0, 0, 0);
	_position = D3DXVECTOR2(0, 0);
	_scaleCen = D3DXVECTOR2(0, 0);
	_scale = D3DXVECTOR2(1, 1);//스케일 크기는 0이 안되지
	_rotateCen = D3DXVECTOR2(0, 0);
	_center = D3DXVECTOR2(0, 0);

	_rotate = 0;

	_isAnimation = false;
	_isRepeat = false;
	_isAniEnd = false;
	_isSetCamera = false;
	_animationTime = 0;
	_aniStackTime = 0;
	_scene = 0;
	_maxScene = 0;
	//a투명도(0이면 투명)
	//r, g, b= 3원색
	_a = _r = _b = _g = 255;
}

void CSprite::Update(float deltaTime) {

	D3DXMatrixIdentity(&_matrix);
	D3DXVECTOR2 pos = _position;
	pos = pos - _center;

	if (!_isSetCamera) {

		D3DXMatrixTransformation2D(&_matrix, &_scaleCen, 0.f, &_scale, &_rotateCen, D3DXToRadian(_rotate), &pos);//카메라 포지션을 안 넣어줌
	}
	else {

		D3DXVECTOR2 cameraPos = pos - _g_Camera->GetPos();
		D3DXMatrixTransformation2D(&_matrix, &_scaleCen, 0.f, &_scale, &_rotateCen, D3DXToRadian(_rotate), &cameraPos);//카메라 포지션을 넣어줌
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
	g_Sprite->Draw(texture->GetTexture(_scene), NULL, NULL, &_zDepthPosition, D3DCOLOR_ARGB(_a, _r, _g, _b));
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

void CSprite::SetCamera() {

	_isSetCamera = true;
}

void CSprite::SetDepth(float depth) {

	_zDepthPosition.z = depth;
}