#include "Header.h"

CBoss::CBoss(int type, D3DXVECTOR2 position, list<CBullet*> *enemyBullets) {

	_type = type;
	_enemyBullets = enemyBullets;
	isPat2 = false;
	isPat3 = false;

	_sprite = CSprite();
	_sprite._position = position;

	_sprite._center = D3DXVECTOR2(256, 128);
	_sprite._scaleCen = D3DXVECTOR2(256, 128);
	_sprite._rotateCen = D3DXVECTOR2(256, 128);

	if (type == 0) {

		_texture = &_g_Asset.Boss1Img;

		pat1Time = 0.5;
		pat1Timer = 0;

		_life = 200;
	}

	else if (type == 1) {

		_texture = &_g_Asset.Boss2Img;

		_sprite._center = D3DXVECTOR2(256, 256);
		_sprite._scaleCen = D3DXVECTOR2(256, 256);
		_sprite._rotateCen = D3DXVECTOR2(256, 256);

		_sprite.SetAnimation(true, 0.08, 10);

		pat1Time = 0.5;
		pat1Timer = 0;
		pat2Time = 0.01;
		pat1Timer = 0;

		_life = 400;
	}
}

void CBoss::Update(float deltaTime) {

	if (!isDestroy) {

		gameTimer += deltaTime;

		SetRect(&_rect, _sprite._position.x - 256, _sprite._position.y - 80, _sprite._position.x + 256, _sprite._position.y + 80);
		angle = angle + 2;
		if (angle > 360)
			angle = 0;

		if (_type == 0) {

			pat1Timer += deltaTime;
			if (pat1Timer >= pat1Time) {

				pat1Timer = 0;
				_enemyBullets->push_back(new CBullet(&_g_Asset.enemyBullet, _sprite._position + D3DXVECTOR2(50, 0), D3DXVECTOR2((PlayX - (_sprite._position.x + 50)), (PlayY - _sprite._position.y)), 700));
				_enemyBullets->push_back(new CBullet(&_g_Asset.enemyBullet, _sprite._position + D3DXVECTOR2(-50, 0), D3DXVECTOR2((PlayX - (_sprite._position.x - 50)), (PlayY - _sprite._position.y)), 700));
			}

			if (gameTimer <= 2.5)
				_sprite._position.y += 100 * deltaTime;

			if (InTime(5, 7))
				_sprite._position.x += 100 * deltaTime;

			if (InTime(7, 11))
				_sprite._position.x -= 100 * deltaTime;

			if (InTime(11, 13))
				_sprite._position.x += 100 * deltaTime;

			if (InTime(14, 16))
				_sprite._position.y -= 300 * deltaTime;

			if (InTime(16, 17))
				_sprite._position.y = 800;

			if (InTime(17, 19))
				_sprite._position.y -= 300 * deltaTime;

			if (InTime(19, 21))
				_sprite._position.x += 100 * deltaTime;

			if (InTime(21, 24))
				_sprite._position.y -= 300 * deltaTime;

			if (InTime(22, 23))
				_sprite._position.y = 800;

			if (InTime(23, 24))
				_sprite._position.y -= 300 * deltaTime;

			if (InTime(23, 25))
				_sprite._position.x -= 200 * deltaTime;

			if (InTime(25, 27))
				_sprite._position.y -= 300 * deltaTime;

			if (InTime(27, 28))
				_sprite._position.y = 800;

			if (InTime(28, 29)) {
				_sprite._position.y -= 250 * deltaTime;
				_sprite._position.x += 250 * deltaTime;
			}
			if (InTime(30, 31))
				_sprite._position.y -= 300 * deltaTime;

			if (InTime(31, 32))
				pat1Time = 0.3;
		}

		else if (_type == 1) {

			pat1Timer += deltaTime;
			pat2Timer += deltaTime;

			if (pat1Timer >= pat1Time) {

				pat1Timer = 0;
				_enemyBullets->push_back(new CBullet(&_g_Asset.enemySpaceBullet, _sprite._position + D3DXVECTOR2(50, 0), D3DXVECTOR2((PlayX - (_sprite._position.x + 50)), (PlayY - _sprite._position.y)), 700));
				_enemyBullets->push_back(new CBullet(&_g_Asset.enemySpaceBullet, _sprite._position + D3DXVECTOR2(-50, 0), D3DXVECTOR2((PlayX - (_sprite._position.x - 50)), (PlayY - _sprite._position.y)), 700));
				
				//
				if (isPat2) {

					_enemyBullets->push_back(new CBullet(&_g_Asset.enemyBullet, _sprite._position + D3DXVECTOR2(120, 0), D3DXVECTOR2((PlayX - (_sprite._position.x + 50)), (PlayY - _sprite._position.y)), 600));
					_enemyBullets->push_back(new CBullet(&_g_Asset.enemyBullet, _sprite._position + D3DXVECTOR2(-120, 0), D3DXVECTOR2((PlayX - (_sprite._position.x - 50)), (PlayY - _sprite._position.y)), 600));
				}
			}

			if (pat2Timer >= pat2Time) {

				pat2Timer = 0;
				if (isPat3) {

					_enemyBullets->push_back(new CBullet(&_g_Asset.enemySpaceBullet, _sprite._position, D3DXVECTOR2(cosf(angle), sinf(angle)), 300));
					_enemyBullets->push_back(new CBullet(&_g_Asset.enemyBullet, _sprite._position, D3DXVECTOR2(sinf(angle), cosf(angle)), 300));
				}
			}

			if (gameTimer <= 2.5)
				_sprite._position.y += 100 * deltaTime;

			if (InTime(5, 7))
				_sprite._position.x += 100 * deltaTime;

			if (InTime(7, 9))
				_sprite._position.y += 500 * deltaTime;

			if (InTime(9, 11)) {

				_sprite._rotate = 180;
				_sprite._position.y -= 800 * deltaTime;
			}

			if (InTime(11, 12)) {

				_sprite._rotate = 0;
				_sprite._position.x -= 200 * deltaTime;
				isPat2 = true;
				pat1Time = 0.4;
			}

			if (InTime(12, 13))
				_sprite._position.y += 500 * deltaTime;

			if (InTime(13, 15))
				_sprite._position.y += 1000 * deltaTime;

			if (InTime(15, 16)) {

				_sprite._rotate = 270;
				_sprite._position = D3DXVECTOR2(-300, 300);
			}

			if (InTime(16, 17))
				_sprite._position.x += 1000 * deltaTime;

			if (InTime(17, 18)) {

				_sprite._rotate = 90;
				_sprite._position.y += 200 * deltaTime;
			}

			if (InTime(18, 20))
				_sprite._position.x -= 1200 * deltaTime;

			if (InTime(20, 21)) {

				_sprite._rotate = 0;
				_sprite._position = D3DXVECTOR2(384, -300);
				pat1Time = 100;
				isPat2 = false;
				isPat3 = true;
			}
			if (InTime(21, 23))
				_sprite._position.y += 1200 * deltaTime;

			if (InTime(23, 24)) {

				_sprite._rotate = 180;
				_sprite._position = D3DXVECTOR2(184, 1000);
			}

			if (InTime(24, 26))
				_sprite._position.y -= 1200 * deltaTime;

			if (InTime(26, 27)) {

				_sprite._rotate = 30;
				_sprite._position = D3DXVECTOR2(1068, -300);
			}

			if (InTime(27, 29)) {

				_sprite._position.x -= 700 * deltaTime;
				_sprite._position.y += 700 * deltaTime;
			}

			if (InTime(29, 30)) {

				_sprite._rotate = 0;
				_sprite._position = D3DXVECTOR2(384, -300);
				pat1Time = 1.5;
				isPat2 = true;
			}

			if (InTime(30, 32))
				_sprite._position.y += 200 * deltaTime;
		}

		_sprite.Update(deltaTime);
	}
	else {

		SetRect(&_rect, _sprite._position.x, _sprite._position.y, _sprite._position.x, _sprite._position.y);
	}
}

void CBoss::Render() {

	if (!isDestroy)
		_sprite.Render(*_texture);
}