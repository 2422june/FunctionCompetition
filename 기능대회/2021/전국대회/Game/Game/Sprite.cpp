#include "Header.h"

Sprite::Sprite() {
	_zDepthPos = D3DXVECTOR3(0, 0, 0);
	_scale = D3DXVECTOR2(1, 1);
	_center = D3DXVECTOR2(0, 0);
	_pos = D3DXVECTOR2(0, 0);
	_rotateCen = D3DXVECTOR2(0, 0);
	_scaleCen = D3DXVECTOR2(0, 0);

	_isAni = _aniEnd = _isRe = _setCam = false;

	_aniTime = _aniStackTime = _rotate = 0;

	_scene = _maxScene = 0;

	_a = _r = _g = _b = 255;
}

void Sprite::Update(float deltaTime) {
	D3DXMatrixIdentity(&_matrix);

	D3DXVECTOR2 pos = _pos - _center;
	if (!_setCam) {
		D3DXMatrixTransformation2D(&_matrix, &_scaleCen, 0, &_scale, &_rotateCen, D3DXToRadian(_rotate), &pos);
	}
	else {
		D3DXVECTOR2 camPos = pos - _g_Camera->GetPos();
		D3DXMatrixTransformation2D(&_matrix, &_scaleCen, 0, &_scale, &_rotateCen, D3DXToRadian(_rotate), &camPos);
	}

	if (_isAni) {
		_aniStackTime += deltaTime;
		
		if (_aniTime <= _aniStackTime) {
			_aniStackTime = 0;

			if (++_scene >= _maxScene) {

				if (_isRe) {
					_scene = 0;
				}
				else {
					--_scene;
					_aniEnd = true;
				}
			}
		}
	}
}

void Sprite::Render(Texture* texture) {
	g_sprite->SetTransform(&_matrix);
	g_sprite->Draw(texture->GetTexture(_scene), NULL, NULL, &_zDepthPos, D3DCOLOR_ARGB(_a, _r, _g, _b));
}

void Sprite::SetCam() {
	_setCam = true;
}

void Sprite::SetDepth(float depth) {
	_zDepthPos.z = depth;
}

void Sprite::SetAni(bool re, float time, int maxScene) {
	_isRe = re;
	_aniTime = time;
	_aniStackTime = 0;
	_scene = 0;
	_maxScene = maxScene;

	_isAni = true;
	_aniEnd = false;
}