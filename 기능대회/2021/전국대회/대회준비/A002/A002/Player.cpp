#include "Header.h"

CPlayer::CPlayer(list<CBullet*> *bullets) {

	_sprite = CSprite();
	_sprite._center = D3DXVECTOR2(64, 64);
	_sprite._position = D3DXVECTOR2(384, 600);

	_power = 0;
	Single::GetInstance()->howBomb = 2;
	_bullets = bullets;
	isAttack = false;
	pMisTime = 1;
	pMisTimer = 0;
	pBulletTime = 0.2;
	pBulletTimer = 0;
	_state = 0;
	_life = 3;
	_sprite.SetAnimation(false, 0.3, 8);
}

void CPlayer::Update(float deltaTime) {

	if (!isDestroy) {

		SetRect(&_rect, _sprite._position.x - 10, _sprite._position.y - 10, _sprite._position.x + 10, _sprite._position.y + 10);
		PlayX = _sprite._position.x;
		PlayY = _sprite._position.y;

		pBulletTimer += deltaTime;

		if (isAttack) {

			if (_power == 0) {

				if (pBulletTimer >= pBulletTime) {

					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position, D3DXVECTOR2(0, -1), 800));
					pBulletTimer = 0;

					isAttack = false;
				}
			}
			else if (_power == 1) {

				if (pBulletTimer >= pBulletTime) {

					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(-30, 0), D3DXVECTOR2(0, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(30, 0), D3DXVECTOR2(0, -1), 800));
					pBulletTimer = 0;

					isAttack = false;
				}
			}
			else if (_power == 2) {

				pMisTimer += deltaTime;

				if (pBulletTimer >= pBulletTime) {

					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(-30, 0), D3DXVECTOR2(0, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(30, 0), D3DXVECTOR2(0, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(0, -40), D3DXVECTOR2(0, -1), 800));
					pBulletTimer = 0;

					isAttack = false;
				}
			}

			else if (_power == 3) {

				pMisTimer += deltaTime;

				if (pBulletTimer >= pBulletTime) {

					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(-30, 0), D3DXVECTOR2(0, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(30, 0), D3DXVECTOR2(0, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(0, -40), D3DXVECTOR2(0, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(-15, -20), D3DXVECTOR2(0, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(15, -20), D3DXVECTOR2(0, -1), 800));
					pBulletTimer = 0;

					isAttack = false;
				}
			}

			else if(_power == 4) {

				pMisTimer += deltaTime;

				if (pBulletTimer >= pBulletTime) {

					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(-30, 0), D3DXVECTOR2(0, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(30, 0), D3DXVECTOR2(0, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(0, -40), D3DXVECTOR2(0, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(-10, 0), D3DXVECTOR2(0.25, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(10, 0), D3DXVECTOR2(-0.25, -1), 800));

					pBulletTimer = 0;

					isAttack = false;
				}
			}

			else {

				pMisTimer += deltaTime;

				if (pBulletTimer >= pBulletTime) {

					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(-30, -10), D3DXVECTOR2(0.5, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(30, -10), D3DXVECTOR2(-0.5, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(0, -40), D3DXVECTOR2(0, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(-15, -30), D3DXVECTOR2(-0.125, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(15, -30), D3DXVECTOR2(0.125, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(-20, -20), D3DXVECTOR2(0.25, -1), 800));
					_bullets->push_back(new CBullet(&_g_Asset.playerBullet, _sprite._position + D3DXVECTOR2(20, -20), D3DXVECTOR2(-0.25, -1), 800));


					pBulletTimer = 0;

					isAttack = false;
				}
			}
		}

		if (_sprite._position.x >= 768)
			_sprite._position.x = 768;
		if (_sprite._position.x <= 50)
			_sprite._position.x = 50;
		if (_sprite._position.y >= 700)
			_sprite._position.y = 700;
		if (_sprite._position.y <= 50)
			_sprite._position.y = 50;

		_sprite.Update(deltaTime);
	}
}

void CPlayer::Render() {

	if(!isDestroy)
		_sprite.Render(_g_Asset.playerImg[_state]);
}

void CPlayer::ChangeState(int state) {

	if (_state != state) {

		switch (state) {

		case 0:
			_sprite.SetAnimation(true, 0.05, 8);
			break;

		case 1:
			_sprite.SetAnimation(false, 0.03, 8);
			break;

		case 2:
			_sprite.SetAnimation(false, 0.03, 8);
			break;
		}

		_state = state;
	}
}

void CPlayer::Move(float x, float y) {

	_sprite._position.x += x;
	_sprite._position.y += y;

	if (x > 0)
		ChangeState(2);

	else if (x < 0)
		ChangeState(1);

	else if (x == 0 && y == 0)
		ChangeState(0);
}

void CPlayer::Born() {

	_power = 0;
	Single::GetInstance()->howBomb = 2;

	_sprite._position = D3DXVECTOR2(384, 600);
	isDestroy = false;
}