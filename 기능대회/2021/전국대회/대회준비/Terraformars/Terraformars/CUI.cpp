#include "Header.h"

CUI::CUI() {

	_sprite = CSprite();
	_needle1 = CSprite();
	_needle2 = CSprite();
	_handle = CSprite();

	ALLCEN(_sprite, 0, 0);
	ALLCEN(_needle1, 85, 85);
	ALLCEN(_needle2, 85, 85);
	ALLCEN(_handle, 207, 100);

	_sprite._position = D3DXVECTOR2(0, 0);
	_handle._position = D3DXVECTOR2(512, 700);
	_needle1._position = D3DXVECTOR2(90, 750);
	_needle2._position = D3DXVECTOR2(970 , 750);

	_needle2._rotate = -85;

	_dir = 2;
	_life = 0;
	_mis = 2;
	_speed = 1.0f;
}

void CUI::Update(float deltaTime) {

	if (_dir == 1) {

		_handle._rotate += 1;
		if (_handle._rotate >= 45)
			_handle._rotate = 45;
	}
	if (_dir == 0) {

		_handle._rotate -= 1;
		if (_handle._rotate <= -45)
			_handle._rotate = -45;
	}
	if(_dir == 2) {

		if (_handle._rotate > 0) {

			_handle._rotate -= 1;
			if (_handle._rotate <= 0)
				_handle._rotate = 0;
		}
		if (_handle._rotate < 0) {

			_handle._rotate += 1;
			if (_handle._rotate >= 0)
				_handle._rotate = 0;
		}
	}

	if (_speed == 1.0f) {

		_needle2._rotate -= 1;
		if (_needle2._rotate <= -85)
			_needle2._rotate = -85;
	}
	if (_speed == 1.2f) {

		_needle2._rotate += 1;
		if (_needle2._rotate >= -68)
			_needle2._rotate = -68;
	}
	if (_speed == 1.4f) {
	
		_needle2._rotate += 1;
		if (_needle2._rotate >= -51)
			_needle2._rotate = -51;
	}
	if (_speed == 1.6f) {

		_needle2._rotate += 1;
		if (_needle2._rotate >= -34)
			_needle2._rotate = -34;
	}
	if (_speed == 1.8f) {

		_needle2._rotate += 1;
		if (_needle2._rotate >= -17)
			_needle2._rotate = -17;
	}
	if (_speed == 2.0f) {

		_needle2._rotate += 1;
		if (_needle2._rotate >= 0)
			_needle2._rotate = 0;
	}

	if (_life == 0) {

		_needle1._rotate = 0;
	}
	if (_life == 1) {

		_needle1._rotate = 9;
	}
	if (_life == 2) {

		_needle1._rotate = 18;
	}
	if (_life == 3) {

		_needle1._rotate = 27;
	}
	if (_life == 4) {

		_needle1._rotate -= 1;
		if (_needle1._rotate <= 36)
			_needle1._rotate = 36;
	}
	if (_life == 5) {

		_needle1._rotate = 45;
	}
	if (_life == 6) {

		_needle1._rotate = 54;
	}
	if (_life == 7) {

		_needle1._rotate = 63;
	}
	if (_life == 8) {

		_needle1._rotate = 72;
	}
	if (_life == 9) {

		_needle1._rotate = 81;
	}
	if (_life == 10) {

		_needle1._rotate = 90;
	}
	_sprite._scene = _mis;

	_sprite.Update(deltaTime);
	_needle1.Update(deltaTime);
	_needle2.Update(deltaTime);
	_handle.Update(deltaTime);
}

void CUI::Render() {

	_sprite.Render(_g_Asset.ui);
	_needle1.Render(_g_Asset.needle);
	_needle2.Render(_g_Asset.needle);
	_handle.Render(_g_Asset.handle);
}

void CUI::HandleMove(int dir) {

	_dir = dir;
}