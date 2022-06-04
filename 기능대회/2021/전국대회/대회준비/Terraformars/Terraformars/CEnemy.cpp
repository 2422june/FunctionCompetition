#include "Header.h"

CEnemy::CEnemy(list<CBullet*> *bullets, int type, D3DXVECTOR2 position, int item, int hommingCnt) {

	_sprite = CSprite();
	_bullets = bullets;
	_sprite._position = position;
	_type = type;
	_hommingCnt = hommingCnt;

	_effectTimer = 0;
	_effectTime = 1.0f;
	_backTimer = 0;
	_backTime = 0.5f;
	_item = item;

	isBack = false;

	if (_type == 0) {

		_texture = _g_Asset.enemy[0];
		ALLCEN(_sprite, 96, 96);
		_sprite._scale.y = -1;

		_bulletTimer = 0;
		_bulletTime = 0.5f;

		_sprite.SetAnimation(true, 0.05f, 11);

		_life = 2;
	}

	if (_type == 1) {

		_texture = _g_Asset.enemy[1];
		ALLCEN(_sprite, 64, 64);

		_sprite.SetAnimation(true, 0.05f, 21);
		
		_life = 1;
	}

	if (_type == 2) {

		_texture = _g_Asset.enemy[2];
		ALLCEN(_sprite, 128, 128);

		_bulletTimer = 0;
		_bulletTime = 1.0f;

		_sprite.SetAnimation(true, 0.05f, 21);

		_life = 2;
	}

	if (_type == 3) {

		_texture = _g_Asset.enemy[3];
		ALLCEN(_sprite, 96, 96);

		_sprite._scale.y = -1;
		_sprite.SetAnimation(true, 0.05f, 9);

		_bulletTimer = 0;
		_bulletTime = 0.5f;

		if (position.x > 512) {

			dir = true;
		}
		else {

			dir = false;
		}

		_life = 1;
	}

	if (_type == 4) {

		_texture = _g_Asset.enemy[4];
		ALLCEN(_sprite, 64, 64);

		_bulletTimer = 0;
		_bulletTime = 1.5f;

		_sprite.SetAnimation(true, 0.05f, 21);

		_life = 1;
	}

	isDestroy = false;
}

void CEnemy::Update(float deltaTime) {

	SetRect(&_rect, _sprite._position.x - 60, _sprite._position.y - 60, _sprite._position.x + 60, _sprite._position.y + 60);

	if (_life <= 0)
		isDestroy = true;

	D3DXVec2Normalize(&_movDir, &D3DXVECTOR2(PX - _sprite._position.x, PY - _sprite._position.y));

	if (_type == 0) {
		
		_sprite._rotate = D3DXToDegree(atan2(_sprite._position.y - PY, _sprite._position.x - PX)) + 90;

		if (!isBack) {

			_sprite._position.y += 350 * deltaTime;
			_effectTimer += deltaTime;
			if (_effectTimer >= _effectTime) {

				isBack = true;
			}
		}
		else {

			_backTimer += deltaTime;
			if (_backTimer >= _backTime) {

				_backTimer = 0;
				_effectTimer = 0;
				isBack = false;
			}
		}

		_bulletTimer += deltaTime;
		if (_bulletTimer >= _bulletTime) {

			_bulletTimer = 0;
			_bullets->push_back(new CBullet(&_g_Asset.bullets[2], _sprite._position, _movDir, 500, 1));
		}
	}
	if (_type == 1) {

		_sprite._rotate = D3DXToDegree(atan2(_sprite._position.y - PY, _sprite._position.x - PX)) + 90;
		_sprite._position += _movDir * 300 * deltaTime;
	}
	if (_type == 2) {

		_sprite._position += _movDir * 150 * deltaTime;

		_sprite._rotate = D3DXToDegree(atan2(_sprite._position.y - PY, _sprite._position.x - PX)) + 90;

		_bulletTimer += deltaTime;
		if (_bulletTimer >= _bulletTime) {

			_bulletTimer = 0;
			_bullets->push_back(new CBullet(&_g_Asset.bullets[3], _sprite._position + D3DXVECTOR2(50, 0), _movDir, 500, 1));
			_bullets->push_back(new CBullet(&_g_Asset.bullets[3], _sprite._position + D3DXVECTOR2(-50, 0), _movDir, 500, 1));
		}
	}
	if (_type == 3) {

		_bulletTimer += deltaTime;
		if (_bulletTimer >= _bulletTime) {

			_bulletTimer = 0;

			_bullets->push_back(new CBullet(&_g_Asset.bullets[4], _sprite._position, D3DXVECTOR2(0, 1), 600, 1));
		}

		if (dir == 0) {

			_sprite._position.x += 250 * deltaTime;
			_sprite._position.y += 100 * deltaTime;
		}
		else {

			_sprite._position.x -= 250 * deltaTime;
			_sprite._position.y += 100 * deltaTime;
		}
	}
	if (_type == 4) {

		_sprite._position += _movDir * 250 * deltaTime;

		_sprite._rotate = D3DXToDegree(atan2(_sprite._position.y - PY, _sprite._position.x - PX)) + 90;

		_bulletTimer += deltaTime;
		if (_bulletTimer >= _bulletTime) {

			_bulletTimer = 0;
			_bullets->push_back(new CBullet(&_g_Asset.bullets[3], _sprite._position, _movDir, 500, 1));
		}
	}
	_sprite.Update(deltaTime);
};

void CEnemy::Render() {

	_sprite.Render(_texture);
}