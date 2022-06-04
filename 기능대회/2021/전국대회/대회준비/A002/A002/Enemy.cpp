#include "Header.h"

CEnemy::CEnemy(int type, D3DXVECTOR2 position, list<CBullet*> *enemyBullets, int item) {

	_sprite = CSprite();
	_type = type;
	_enemyBullets = enemyBullets;
	_sprite._scaleCen = D3DXVECTOR2(128, 128);
	_sprite._rotateCen = D3DXVECTOR2(128, 128);
	_sprite._center = D3DXVECTOR2(128, 128);
	_sprite._scale.y = 1;
	_sprite._position = position;
	_item = item;


	//----<Stage 1>----//
	if (type == 0) {

		_texture = &_g_Asset.enemyImg[0];

		_sprite.SetAnimation(true, 0.05, 18);
		_life = 2;
	}

	if (type == 1) {

		type1Speed = 200;
		type1BulletTime = 1;
		type1BulletTimer = 0;

		_texture = &_g_Asset.enemyImg[1];
		_sprite.SetAnimation(true, 0.05, 8);
		_life = 5;
	}

	if (type == 2 | type == 3) {

		_sprite._scaleCen = D3DXVECTOR2(64, 64);
		_sprite._rotateCen = D3DXVECTOR2(64, 64);
		_sprite._center = D3DXVECTOR2(64, 64);

		type2BulletTime = 1;
		type2BulletTimer = 0;

		_texture = &_g_Asset.enemyImg[2];
		_sprite.SetAnimation(true, 0.05, 8);
		_life = 1;
	}

	//----<Stage 2>----//
	if (type == 10) {
	
		_texture = &_g_Asset.enemyImg[3];

		_sprite._scaleCen = D3DXVECTOR2(64, 64);
		_sprite._rotateCen = D3DXVECTOR2(64, 64);
		_sprite._center = D3DXVECTOR2(64, 64);

		_sprite.SetAnimation(true, 0.02, 25);
		_life = 2;
	}
	if (type == 11) {

		_texture = &_g_Asset.enemyImg[4];

		type1Speed = 200;
		type1BulletTime = 1;
		type1BulletTimer = 0;

		_life = 5;
	}
	if (type == 12 | type == 13) {

		_texture = &_g_Asset.enemyImg[5];

		_sprite._scaleCen = D3DXVECTOR2(64, 64);
		_sprite._rotateCen = D3DXVECTOR2(64, 64);
		_sprite._center = D3DXVECTOR2(64, 64);

		type2BulletTime = 0.9;
		type2BulletTimer = 0;
		type2LaserTime = 1.5;
		type2LaserTimer = 0;

		_sprite.SetAnimation(true, 0.05, 13);
		_life = 1;
	}
}

void CEnemy::Update(float deltaTime) {

	SetRect(&_rect, _sprite._position.x - 64, _sprite._position.y - 64, _sprite._position.x + 64, _sprite._position.y + 64);

	//----<Stage 1>----//
	if (_type == 0) {

		_sprite._position.y += 400 * deltaTime;
	}

	if (_type == 1) {

		
		type1BulletTimer += deltaTime;

		_sprite._position.y += type1Speed * deltaTime;
		type1Speed--;

		if (type1BulletTimer >= type1BulletTime) {

			type1BulletTimer = 0;
			_enemyBullets->push_back(new CBullet(&_g_Asset.enemyBullet, _sprite._position + D3DXVECTOR2(30, 0), D3DXVECTOR2(0, 1), 700));
			_enemyBullets->push_back(new CBullet(&_g_Asset.enemyBullet, _sprite._position + D3DXVECTOR2(-30, 0), D3DXVECTOR2(0, 1), 700));
			_enemyBullets->push_back(new CBullet(&_g_Asset.enemyBullet, _sprite._position + D3DXVECTOR2(80, 0), D3DXVECTOR2(0, 1), 700));
			_enemyBullets->push_back(new CBullet(&_g_Asset.enemyBullet, _sprite._position + D3DXVECTOR2(-80, 0), D3DXVECTOR2(0, 1), 700));
		}
		
	}

	if (_type == 2) {

		type2BulletTimer += deltaTime;
		_sprite._position.x += 200 * deltaTime;

		_sprite._rotate = D3DXToDegree(atan2(_sprite._position.y - PlayY, _sprite._position.x - PlayX)) + 90;

		if (type2BulletTimer >= type2BulletTime) {

			type2BulletTimer = 0;
			_enemyBullets->push_back(new CBullet(&_g_Asset.enemyBullet, _sprite._position, D3DXVECTOR2((PlayX - _sprite._position.x), (PlayY - _sprite._position.y)), 400));
		}
	}

	if (_type == 3) {

		type2BulletTimer += deltaTime;
		_sprite._position.x -= 200 * deltaTime;

		_sprite._rotate = D3DXToDegree(atan2(_sprite._position.y - PlayY, _sprite._position.x - PlayX)) + 90;

		if (type2BulletTimer >= type2BulletTime) {

			type2BulletTimer = 0;
			_enemyBullets->push_back(new CBullet(&_g_Asset.enemyBullet, _sprite._position, D3DXVECTOR2((PlayX - _sprite._position.x), (PlayY - _sprite._position.y)), 400));
		}
	}

	//----<Stage 2>----//
	if (_type == 10) {

		_sprite._position.y += 400 * deltaTime;
	}

	if (_type == 11) {


		type1BulletTimer += deltaTime;

		_sprite._position.y += type1Speed * deltaTime;
		type1Speed--;

		if (type1BulletTimer >= type1BulletTime) {

			type1BulletTimer = 0;
			_enemyBullets->push_back(new CBullet(&_g_Asset.enemySpaceBullet, _sprite._position + D3DXVECTOR2(30, 0), D3DXVECTOR2(0, 1), 700));
			_enemyBullets->push_back(new CBullet(&_g_Asset.enemySpaceBullet, _sprite._position + D3DXVECTOR2(-30, 0), D3DXVECTOR2(0, 1), 700));
			_enemyBullets->push_back(new CBullet(&_g_Asset.enemySpaceBullet, _sprite._position + D3DXVECTOR2(80, 0), D3DXVECTOR2(0, 1), 700));
			_enemyBullets->push_back(new CBullet(&_g_Asset.enemySpaceBullet, _sprite._position + D3DXVECTOR2(-80, 0), D3DXVECTOR2(0, 1), 700));
		}

	}

	if (_type == 12) {

		type2BulletTimer += deltaTime;

		if (type2BulletTimer >= type2BulletTime) {

			type2LaserTimer += deltaTime;
			if (type2LaserTimer >= type2LaserTime) {

				type2BulletTimer = 0;
				type2LaserTimer = 0;
			}

			_enemyBullets->push_back(new CBullet(&_g_Asset.enemyLaser, _sprite._position, D3DXVECTOR2((tmpPlayX - _sprite._position.x), (tmpPlayY - _sprite._position.y)), 400));
		}
		else {

			tmpPlayX = PlayX;
			tmpPlayY = PlayY;
			_sprite._position.x += 200 * deltaTime;
			_sprite._rotate = D3DXToDegree(atan2(_sprite._position.y - PlayY, _sprite._position.x - PlayX)) + 90;
		}
	}

	if (_type == 13) {

		type2BulletTimer += deltaTime;

		if (type2BulletTimer >= type2BulletTime) {

			type2LaserTimer += deltaTime;
			if (type2LaserTimer >= type2LaserTime) {

				type2BulletTimer = 0;
				type2LaserTimer = 0;
			}
			
			_enemyBullets->push_back(new CBullet(&_g_Asset.enemyLaser, _sprite._position, D3DXVECTOR2((tmpPlayX - _sprite._position.x), (tmpPlayY - _sprite._position.y)), 400));

		}
		else {

			tmpPlayX = PlayX;
			tmpPlayY = PlayY;
			_sprite._position.x -= 200 * deltaTime;
			_sprite._rotate = D3DXToDegree(atan2(_sprite._position.y - PlayY, _sprite._position.x - PlayX)) + 90;
		}
	}
	////////////////

	if ((_sprite._position.x > 868) || (_sprite._position.x < -100) || (_sprite._position.y > 868) || (_sprite._position.y < -100))
		isDestroy = true;

	_sprite.Update(deltaTime);
}

void CEnemy::Render() {

	_sprite.Render(*_texture);
}