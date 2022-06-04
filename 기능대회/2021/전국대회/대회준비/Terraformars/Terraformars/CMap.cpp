#include "Header.h"

CMap::CMap(int stage) {

	_first = CSprite();
	_second = CSprite();
	_third = CSprite();
	
	ALLCEN(_first, 0, 0);
	ALLCEN(_second, 0, 0);
	ALLCEN(_third, 0, 0);

	_first._position = D3DXVECTOR2(0, 0);
	_second._position = D3DXVECTOR2(0, -768);

	_first._scene = 0;
	_second._scene = 0;
	_firstScene = 0;
	_secondScene = 0;

	if (stage == 1) {

		texture = _g_Asset.map;
	}
	if (stage == 2) {

		texture = _g_Asset.map2;
	}

	isScrool = true;
}

void CMap::Update(float deltaTime) {

	if (isScrool) {

		_first._position.y += 200 * deltaTime;
		_second._position.y += 200 * deltaTime;
	}


	if(_gameTime >= 3) {

		_firstScene = 1;
	}
	if (_gameTime >= 4) {

		_firstScene = 0;
		_secondScene = 2;
	}
	if (_gameTime >= 7) {

		_firstScene = 0;
		_secondScene = 2;
	}
	if (_gameTime >= 10) {

		_firstScene = 1;
		_secondScene = 2;
	}
	if (_gameTime >= 14) {

		_firstScene = 0;
		_secondScene = 0;
	}


	if (_first._scene == 0) {

		SetRect(&_leftRect, _first._position.x, _first._position.y, _first._position.x, _first._position.y);
		SetRect(&_rightRect, _first._position.x, _first._position.y, _first._position.x, _first._position.y);
	}
	if (_first._scene == 1) {

		SetRect(&_leftRect, _first._position.x, _first._position.y + 128, _first._position.x + 300, _first._position.y + 640);
		SetRect(&_rightRect, _first._position.x + 750, _first._position.y + 128, _first._position.x + 1024, _first._position.y + 640);
	}
	if (_first._scene == 2) {

		SetRect(&_leftRect, _first._position.x, _first._position.y + 50, _first._position.x + 350, _first._position.y + 600);
		SetRect(&_rightRect, _first._position.x + 624, _first._position.y + 120, _first._position.x + 1024, _first._position.y + 724);
	}

	if (_second._scene == 0) {

		SetRect(&_sleftRect, _first._position.x, _first._position.y, _first._position.x, _first._position.y);
		SetRect(&_srightRect, _first._position.x, _first._position.y, _first._position.x, _first._position.y);
	}
	if (_second._scene == 1) {

		SetRect(&_sleftRect, _second._position.x, _second._position.y + 128, _second._position.x + 300, _second._position.y + 640);
		SetRect(&_srightRect, _second._position.x + 750, _second._position.y + 128, _second._position.x + 1024, _second._position.y + 640);
	}
	if (_second._scene == 2) {

		SetRect(&_sleftRect, _second._position.x, _second._position.y + 50, _second._position.x + 350, _second._position.y + 600);
		SetRect(&_srightRect, _second._position.x + 624, _second._position.y + 120, _second._position.x + 1024, _second._position.y + 724);
	}

	if (_first._position.y >= 768) {

		_first._scene = _firstScene;
		_first._position.y = -768;
		_second._position.y = 0;
	}
	if (_second._position.y >= 768) {

		_second._scene = _secondScene;
		_second._position.y = -768;
		_first._position.y = 0;
	}

	_first.Update(deltaTime);
	_second.Update(deltaTime);
}

void CMap::Render() {

	_first.Render(texture);
	_second.Render(texture);
}

