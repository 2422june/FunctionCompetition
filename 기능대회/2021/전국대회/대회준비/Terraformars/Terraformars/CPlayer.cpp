#include "Header.h"

CPlayer::CPlayer(list<CBullet*> *bullets, list<CMissile*> *missiles) {

	_sprite = CSprite();
	_shadow = CSprite();
	_sheild = CSprite();
	_laser = CSprite();
	_addon = CSprite();

	ALLCEN(_sprite, 96, 96);
	ALLCEN(_shadow, 1270, 1250);
	ALLCEN(_sheild, 110, 110);
	ALLCEN(_laser, 75, 800);
	ALLCEN(_addon, 128, 128);

	_shadow._a = 200;
	_sprite._a = 255;
	_bullets = bullets;
	_missiles = missiles;

	_bulletTime = 0.2f;
	_bulletTimer = 0;
	_missileTime = 1.0f;
	_missileTimer = 0;
	_sheildTime = 1.0f;
	_sheildTimer = 0;
	_laserTime = 0.1f;
	_laserTimer = 0;
	_addonBulletTime = 0.5f;
	_addonBulletTimer = 0;
	_addCount = 0;

	_missile = 3;

	_godTime = 1.0f;
	_godTimer = 0;
	_life = 10;
	_speed = 1.0f;

	isAttack = false;
	isHit = false;
	isSheild = false;
	canDamage = true;
	isLaser = false;

	_sprite.SetAnimation(true, 0.05f, 9);
}

void CPlayer::Update(float deltaTime) {

	SetRect(&_rect, _sprite._position.x - 30, _sprite._position.y - 30, _sprite._position.x + 30, _sprite._position.y + 30);

	PX = _sprite._position.x;
	PY = _sprite._position.y;

	_shadow._position = _sprite._position;
	_sheild._position = _sprite._position;
	_laser._position = _sprite._position;

	_laser._a = 0;

	_addon._scene = _addCount;
	_addon._position = _sprite._position;

	if (isAttack) {

		_bulletTimer += deltaTime;

		if (_bulletTimer >= _bulletTime) {

			_bulletTimer = 0;
			isAttack = false;
			isLaser = false;

			if (_power == 0) {

				_bulletTime = 0.2f;
				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position, D3DXVECTOR2(0, -1), 800, 1));
			}
			else if (_power == 1) {

				_bulletTime = 0.1f;
				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position, D3DXVECTOR2(0, -1), 800, 1));
			}
			else if (_power == 2) {

				_bulletTime = 0.2f;
				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position, D3DXVECTOR2(0, -1), 800, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position + D3DXVECTOR2(30, 0), D3DXVECTOR2(-0.25, -1), 800, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position + D3DXVECTOR2(-30, 0), D3DXVECTOR2(0.25, -1), 800, 1));
			}
			if (_power == 3) {

				_bulletTime = 0.2f;
				isLaser = true;
				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position, D3DXVECTOR2(0, -1), 800, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position + D3DXVECTOR2(30, 0), D3DXVECTOR2(-0.25, -1), 800, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position + D3DXVECTOR2(-30, 0), D3DXVECTOR2(0.25, -1), 800, 1));
			}
		}

		if (isLaser) {

			_laserTimer += deltaTime;
			if (_laserTimer >= _laserTime) {

				_laserTimer = 0;
				_bullets->push_back(new CBullet(&_g_Asset.air, _sprite._position + D3DXVECTOR2(50, 0), D3DXVECTOR2(0, -1), 10000, 1));
				_bullets->push_back(new CBullet(&_g_Asset.air, _sprite._position + D3DXVECTOR2(-50, 0), D3DXVECTOR2(0, -1), 10000, 1));
			}

			_laser._a = 155;
		}
		
		_addonBulletTimer += deltaTime;

		if (_addonBulletTimer >= _addonBulletTime) {

			_addonBulletTimer = 0;

			if (_addCount == 0) {

			}
			if (_addCount == 1) {

				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position + D3DXVECTOR2(-55, 30), D3DXVECTOR2(0, -1), 600, 1));
			}
			if (_addCount == 2) {

				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position + D3DXVECTOR2(-55, 30), D3DXVECTOR2(0, -1), 600, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position + D3DXVECTOR2(55, 30), D3DXVECTOR2(0, -1), 600, 1));
			}
			if (_addCount == 3) {

				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position + D3DXVECTOR2(-55, 30), D3DXVECTOR2(0, -1), 600, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position + D3DXVECTOR2(55, 30), D3DXVECTOR2(0, -1), 600, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position + D3DXVECTOR2(-90, 60), D3DXVECTOR2(0, -1), 600, 1));
			}
			if (_addCount == 4) {

				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position + D3DXVECTOR2(-55, 30), D3DXVECTOR2(0, -1), 600, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position + D3DXVECTOR2(55, 30), D3DXVECTOR2(0, -1), 600, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position + D3DXVECTOR2(-90, 60), D3DXVECTOR2(0, -1), 600, 1));
				_bullets->push_back(new CBullet(&_g_Asset.bullets[0], _sprite._position + D3DXVECTOR2(90, 60), D3DXVECTOR2(0, -1), 600, 1));
			}
		}
	}

	if (isMissile) {

		_missileTimer += deltaTime;
		if (_missileTimer >= _missileTime) {

			_missileTimer = 0;
			isMissile = false;
			for(int i = 0; i < 100; ++i)
				_missiles->push_back(new CMissile(_sprite._position, i));
		}
	}

	if (isHit) {

		isSheild = false;

		_godTimer += deltaTime;
		_sprite._a += 510 * deltaTime;
		if (_godTimer >= _godTime) {

			_godTimer = 0;
			isHit = false;
		}
	}
	else
		_sprite._a = 255;

	if (isSheild) {

		canDamage = false;
		_sheild._a = 105;
		_sheild._rotate += 1;
		if (_sheild._rotate >= 360)
			_sheild._rotate = 0;
	}
	else {

		canDamage = true;
		_sheild._a = 0;
	}

	if (_sprite._position.x >= 974)
		_sprite._position.x = 974;
	if (_sprite._position.x <= 50)
		_sprite._position.x = 50;
	if (_sprite._position.y >= 658)
		_sprite._position.y = 658;
	if (_sprite._position.y <= 50)
		_sprite._position.y = 50;

	if (_sprite._position.x >= 900)
		Hit(1);
	if (_sprite._position.x <= 100)
		Hit(1);

	_addon.Update(deltaTime);
	_laser.Update(deltaTime);
	_sheild.Update(deltaTime);
	_shadow.Update(deltaTime);
	_sprite.Update(deltaTime);
};

void CPlayer::Render() {

	_shadow.Render(_g_Asset.shadow);
	_laser.Render(_g_Asset.laser);
	_sprite.Render(_g_Asset.playerImg[_state]);
	_addon.Render(_g_Asset.addon);
	_sheild.Render(_g_Asset.sheild);
}

void CPlayer::Move(int x, int y) {

	_sprite._position.x += x;
	_sprite._position.y += y;

	if (x > 0) {

		_sprite._scale.x = 1;
		ChangeState(1);
	};
	if (x < 0) {

		_sprite._scale.x = -1;
		ChangeState(1);
	};
}

void CPlayer::ChangeState(int state) {
	
	if (_state != state) {

		switch (state) {

		case 0:
			_sprite.SetAnimation(true, 0.05f, 9);
			break;

		case 1:
			_sprite.SetAnimation(false, 0.05f, 7);
			break;
		}

		_state = state;
	}
};


void CPlayer::Attack() {

	isAttack = true;
};

void CPlayer::Hit(int damage) {

	if (!isHit) {

		isHit = true;

		if(canDamage)
			_life -= damage;

		_power = 0;
		_addCount = 0;
	}
}

void CPlayer::Missile() {

	isMissile = true;
	_missile--;
	if(_missile <= 0)
			_missile = 0;
}

//1 = spd  /2 = life  /3 = power  /4 = sheild  /5 = missile  /6 = add;
void CPlayer::GetItem(int type) {


	if (type == 1) {

		_speed += 0.2f;
		if (_speed >= 2.0f)
			_speed = 2.0f;
	}
	else if (type == 2) {

		_life += 5;
		if (_life >= 10)
			_life = 10;
	}
	else if (type == 3) {


		Single::GetInstance()->_power++;
		if (Single::GetInstance()->_power >= 3)
			Single::GetInstance()->_power = 3;
	}
	else if (type == 4) {

		isSheild = true;
	}
	else if (type == 5) {

		Single::GetInstance()->_missile++;
		if (Single::GetInstance()->_missile >= 3)
			Single::GetInstance()->_missile = 3;
	}
	else if (type == 6) {

		Single::GetInstance()->_addon++;
		if (Single::GetInstance()->_addon >= 4)
			Single::GetInstance()->_addon = 4;
	}
}