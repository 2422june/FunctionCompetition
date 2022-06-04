#include "Header.h"

CBoss::CBoss(list<CBullet*> *bullets, list<CMissile*> *missiles, int type) {

	_sprite = CSprite();
	_bullets = bullets;
	_missiles = missiles;

	_type = type;
	_sprite._position = D3DXVECTOR2(512, -200);

	_bulletTime = 0.5f;
	_bulletTimer = 0;
	_misTime = 1.0f;
	_misTimer = 0;

	//0 : 1R 중간, /1 : 1R 최종, /2 : 2R 중간, /3 : 2R 최종
	if (_type == 0) {

		_texture = _g_Asset.boss[0];
		ALLCEN(_sprite, 256, 256);

		_sprite.SetAnimation(true, 0.05f, 21);
		_life = 150;
	}
	else if (_type == 1) {

		_texture = _g_Asset.boss[1];
		ALLCEN(_sprite, 256, 256);

		_sprite.SetAnimation(true, 0.05f, 21);
		_life = 250;
	}
	else if (_type == 2) {

		_texture = _g_Asset.boss[2];
		ALLCEN(_sprite, 256, 256);

		_sprite.SetAnimation(true, 0.06f, 10);
		_life = 250;
	}
	else if (_type == 3) {

		_texture = _g_Asset.boss[3];
		ALLCEN(_sprite, 256, 256);

		_sprite.SetAnimation(true, 0.06f, 9);
		_life = 350;
	}

	_gameTime = 0;
	isDestroy = true;
}

void CBoss::Update(float deltaTime) {

	if (_life <= 0)
		isDestroy = true;

	SetRect(&_rect, _sprite._position.x - 150, _sprite._position.y - 150, _sprite._position.x + 150, _sprite._position.y + 150);

	if (isDestroy)
		SetRect(&_rect, _sprite._position.x, _sprite._position.y, _sprite._position.x, _sprite._position.y);

	if (!isDestroy) {

		_gameTime += deltaTime;

		if (_type == 0) {

			_bulletTimer += deltaTime;
			if (_bulletTimer >= _bulletTime) {

				_bulletTimer = 0;
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0, 1), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0, -1), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(1, 0), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-1, 0), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, -0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, -0.5), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.25, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.25, -0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.25, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.25, -0.5), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, -0.25), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, 0.25), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, -0.25), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, 0.25), 500, 1));
			}

			INTIME(3, 4) {

				_sprite._position.y += 300 * deltaTime;
			}
			INTIME(4, 5) {

				_sprite._rotate += 25;
			}
			INTIME(5, 7) {

				_sprite._rotate += 25;
				_sprite._position.y += 700 * deltaTime;
			}
			INTIME(7, 8) {

				_sprite._rotate += 25;
				_sprite._position.y -= 100 * deltaTime;
			}
			INTIME(8, 9) {

				_sprite._rotate += 25;
				_sprite._position.y = 968;
				_sprite._position.x = 212;
			}
			INTIME(9, 11) {

				_sprite._rotate += 25;
				_sprite._position.y -= 700 * deltaTime;
			}
			INTIME(11, 12) {

				_sprite._rotate += 25;
				_sprite._position.y = -256;
				_sprite._position.x = 812;
				_sprite._position.y += 700 * deltaTime;
			}
			INTIME(12, 13) {

				_sprite._position.y = 968;
				_sprite._position.x = 512;
				_sprite._rotate = 180;
			}
			INTIME(13, 15) {

				_sprite._position.y -= 700 * deltaTime;

			}
			INTIME(16, 17) {

				_sprite._position.y = -200;
				_sprite._rotate = 0;
			}
			INTIME(17, 18) {

				_sprite._position.y += 300 * deltaTime;
			}
			INTIME(23, 24) {

				_gameTime = 4;
			}
		}
		else if (_type == 1) {

			_bulletTimer += deltaTime;
			if (_bulletTimer >= _bulletTime) {

				_bulletTimer = 0;
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0, 1), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0, -1), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(1, 0), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-1, 0), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, -0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, -0.5), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.25, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.25, -0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.25, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.25, -0.5), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, -0.25), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, 0.25), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, -0.25), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, 0.25), 500, 1));
			}

			_misTimer += deltaTime;
			if (_misTimer >= _misTime) {

				_misTimer = 0;
				_missiles->push_back(new CMissile(_sprite._position + D3DXVECTOR2(60, 0), 0));
				_missiles->push_back(new CMissile(_sprite._position + D3DXVECTOR2(-60, 0), 0));
				_missiles->push_back(new CMissile(_sprite._position + D3DXVECTOR2(30, 0), 0));
				_missiles->push_back(new CMissile(_sprite._position + D3DXVECTOR2(-30, 0), 0));
				_missiles->push_back(new CMissile(_sprite._position, 0));
			}

			INTIME(3, 4)
				_sprite._position.y += 300 * deltaTime;
			INTIME(4, 5)
				_sprite._position.y -= 100 * deltaTime;
			INTIME(5, 5.5)
				_sprite._position.y += 1000 * deltaTime;
			INTIME(5.5, 6)
				_sprite._position.y -= 1000 * deltaTime;
			INTIME(6, 7)
				_sprite._position.y += 100 * deltaTime;
			INTIME(7, 8)
				_sprite._position.x += 200 * deltaTime;
			INTIME(8, 9)
				_sprite._position.y -= 100 * deltaTime;
			INTIME(9, 9.5)
				_sprite._position.y += 1000 * deltaTime;
			INTIME(9.5, 10)
				_sprite._position.y -= 1000 * deltaTime;
			INTIME(10, 11)
				_sprite._position.y += 100 * deltaTime;
			INTIME(11, 12)
				_sprite._position.x -= 400 * deltaTime;
			INTIME(12, 13)
				_sprite._position.y -= 100 * deltaTime;
			INTIME(13, 13.5)
				_sprite._position.y += 1000 * deltaTime;
			INTIME(13.5, 14)
				_sprite._position.y -= 1000 * deltaTime;
			INTIME(14, 15)
				_sprite._position.y += 100 * deltaTime;
			INTIME(15, 16)
				_sprite._position.x += 200 * deltaTime;
			INTIME(21, 26)
				_gameTime = 4;
		}

		else if (_type == 2) {

			_bulletTimer += deltaTime;
			if (_bulletTimer >= _bulletTime) {

				_bulletTimer = 0;
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0, 1), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0, -1), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(1, 0), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-1, 0), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, -0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, -0.5), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.25, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.25, -0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.25, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.25, -0.5), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, -0.25), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, 0.25), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, -0.25), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, 0.25), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.125, 1.0), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.125, -1.0), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.125, 1.0), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.125, -1.0), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(1.0, 0.125), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(1.0, -0.125), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-1.0, 0.125), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-1.0, -0.125), 500, 1));

			}

			INTIME(3, 4)
				_sprite._position.y += 300 * deltaTime;
			INTIME(4, 5)
				_sprite._position.y -= 100 * deltaTime;
			INTIME(5, 6)
				_sprite._position.y += 1500 * deltaTime;
			INTIME(6, 7)
				_sprite._rotate = 180;
			INTIME(7, 8)
				_sprite._position.y -= 1500 * deltaTime;
			INTIME(8, 9) {

				_sprite._position = D3DXVECTOR2(1224, -200);
				_sprite._rotate = 45;
			}
			INTIME(9, 10)
				_sprite._position += D3DXVECTOR2(-1300, 1300) * deltaTime;
			INTIME(10, 11) {

				_sprite._position = D3DXVECTOR2(-200, -200);
				_sprite._rotate = -45;
			}
			INTIME(11, 12) {

				_sprite._position += D3DXVECTOR2(1300, 1300) * deltaTime;
			}
			INTIME(12, 13) {

				_sprite._position = D3DXVECTOR2(512, -200);
				_sprite._rotate = 0;
			}
			INTIME(13, 14)
				_sprite._position.y += 300 * deltaTime;
			INTIME(14, 14.5)
				_sprite._position.y -= 100 * deltaTime;
			INTIME(14.5, 15)
				_sprite._position.y += 100 * deltaTime;
			INTIME(15, 15.5)
				_sprite._position.y -= 100 * deltaTime;
			INTIME(15.5, 16)
				_sprite._position.y += 100 * deltaTime;
			INTIME(16, 16.5)
				_sprite._position.y -= 100 * deltaTime;
			INTIME(16.5, 17)
				_sprite._position.y += 100 * deltaTime;
			INTIME(17, 17.5)
				_sprite._position.y -= 100 * deltaTime;
			INTIME(17.5, 18)
				_sprite._position.y += 100 * deltaTime;
			INTIME(19, 20)
				_gameTime = 4;
		}
		else if (_type == 3) {

			_misTimer += deltaTime;
			if (_misTimer >= _misTime) {

				_misTimer = 0;
				_missiles->push_back(new CMissile(_sprite._position + D3DXVECTOR2(60, 0), 0));
				_missiles->push_back(new CMissile(_sprite._position + D3DXVECTOR2(-60, 0), 0));
				_missiles->push_back(new CMissile(_sprite._position + D3DXVECTOR2(30, 0), 0));
				_missiles->push_back(new CMissile(_sprite._position + D3DXVECTOR2(-30, 0), 0));
				_missiles->push_back(new CMissile(_sprite._position + D3DXVECTOR2(-40, -40), 0));
				_missiles->push_back(new CMissile(_sprite._position + D3DXVECTOR2(-40, -40), 0));
				_missiles->push_back(new CMissile(_sprite._position, 0));
			}

			_bulletTimer += deltaTime;
			if (_bulletTimer >= _bulletTime) {

				_bulletTimer = 0;
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0, 1), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0, -1), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(1, 0), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-1, 0), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, -0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, -0.5), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.25, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.25, -0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.25, 0.5), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.25, -0.5), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, -0.25), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.5, 0.25), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, -0.25), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.5, 0.25), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.125, 1.0), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(0.125, -1.0), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.125, 1.0), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-0.125, -1.0), 500, 1));

				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(1.0, 0.125), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(1.0, -0.125), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-1.0, 0.125), 500, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[1], _sprite._position, D3DXVECTOR2(-1.0, -0.125), 500, 1));

			}
			INTIME(3, 4)
				_sprite._position.y += 300 * deltaTime;
			INTIME(4, 5)
				_sprite._position.y -= 100 * deltaTime;
			INTIME(5, 5.5)
				_sprite._position.y += 1000 * deltaTime;
			INTIME(5.5, 6)
				_sprite._position.y -= 1000 * deltaTime;
			INTIME(6, 7)
				_sprite._position.y += 100 * deltaTime;
			INTIME(7, 8)
				_sprite._position.x += 200 * deltaTime;
			INTIME(8, 9)
				_sprite._position.y -= 100 * deltaTime;
			INTIME(9, 9.5)
				_sprite._position.y += 1000 * deltaTime;
			INTIME(9.5, 10)
				_sprite._position.y -= 1000 * deltaTime;
			INTIME(10, 11)
				_sprite._position.y += 100 * deltaTime;
			INTIME(11, 12)
				_sprite._position.x -= 400 * deltaTime;
			INTIME(12, 13)
				_sprite._position.y -= 100 * deltaTime;
			INTIME(13, 13.5)
				_sprite._position.y += 1000 * deltaTime;
			INTIME(13.5, 14)
				_sprite._position.y -= 1000 * deltaTime;
			INTIME(14, 15)
				_sprite._position.y += 100 * deltaTime;
			INTIME(15, 16)
				_sprite._position.x += 200 * deltaTime;
			INTIME(21, 26)
				_gameTime = 4;
		}


		_sprite.Update(deltaTime);
	}
}

void CBoss::Render() {

	if(!isDestroy)
		_sprite.Render(_texture);
}