#include "Header.h"

CNextScene::CNextScene() {

	_map = new CMap(_g_Asset.Map1, D3DXVECTOR2(0, 0));
	_ui = new CUI(&_g_Asset.CUI);
	_player = new CPlayer(&_playerBullets);
	_boss1 = new CBoss(1, D3DXVECTOR2(384, -50), &_enemyBullets);
	_bomb = new CBomb();
	_playerBullets.clear();
	_enemyBullets.clear();
	_effects.clear();
	_items.clear();
	_camera = new Camera();
	_camera->_sprite.SetCamera(_camera);
	_gameTime = 0;
	_bomb->isDestroy = true;
	Single::GetInstance()->canHit = true;
	_player->isDestroy = false;
	_boss1->isDestroy = true;
	isEntBoss = false;
	isBossDead = false;

	bossEntTime = 3;
	bossEntTimer = 0;
	_playerBornTime = 1;
	_playerBornTimer = 0;
	_godTime = 3;
	_godTimer = 0;
	_finTime = 3;
	_finTimer = 0;

	SCORE = 0;

	_num[0] = new CNum(&_g_Asset.Num, D3DXVECTOR2(834, 230));
	_num[1] = new CNum(&_g_Asset.Num, D3DXVECTOR2(869, 230));
	_num[2] = new CNum(&_g_Asset.Num, D3DXVECTOR2(904, 230));
	_num[3] = new CNum(&_g_Asset.Num, D3DXVECTOR2(939, 230));
	_num[4] = new CNum(&_g_Asset.Num, D3DXVECTOR2(974, 230));
	_num[5] = new CNum(&_g_Asset.Num, D3DXVECTOR2(939, 435));
	_num[6] = new CNum(&_g_Asset.Num, D3DXVECTOR2(939, 635));

	_enemySpawn[0] = CEnemySpawn(3, 10, D3DXVECTOR2(384, -100), 1);
	_enemySpawn[1] = CEnemySpawn(3, 10, D3DXVECTOR2(184, -100), 0);
	_enemySpawn[2] = CEnemySpawn(3, 10, D3DXVECTOR2(584, -100), 0);
	_enemySpawn[3] = CEnemySpawn(5, 11, D3DXVECTOR2(384, -100), 0);
	_enemySpawn[4] = CEnemySpawn(5.5, 12, D3DXVECTOR2(0, 150), 0);
	_enemySpawn[5] = CEnemySpawn(6.5, 12, D3DXVECTOR2(0, 150), 0);
	_enemySpawn[6] = CEnemySpawn(7.5, 12, D3DXVECTOR2(0, 150), 0);
	_enemySpawn[7] = CEnemySpawn(5.5, 13, D3DXVECTOR2(768, 150), 0);
	_enemySpawn[8] = CEnemySpawn(6.5, 13, D3DXVECTOR2(768, 150), 0);
	_enemySpawn[9] = CEnemySpawn(7.5, 13, D3DXVECTOR2(768, 150), 0);
	_enemySpawn[10] = CEnemySpawn(8, 10, D3DXVECTOR2(184, -100), 1);
	_enemySpawn[11] = CEnemySpawn(8, 10, D3DXVECTOR2(584, -100), 1);
	_enemySpawn[12] = CEnemySpawn(9, 10, D3DXVECTOR2(184, -100), 0);
	_enemySpawn[13] = CEnemySpawn(9, 10, D3DXVECTOR2(584, -100), 0);
	_enemySpawn[14] = CEnemySpawn(10, 10, D3DXVECTOR2(184, -100), 0);
	_enemySpawn[15] = CEnemySpawn(10, 10, D3DXVECTOR2(584, -100), 0);
	_enemySpawn[16] = CEnemySpawn(11, 11, D3DXVECTOR2(184, -100), 0);
	_enemySpawn[17] = CEnemySpawn(14, 11, D3DXVECTOR2(284, -100), 0);
	_enemySpawn[18] = CEnemySpawn(11.5, 11, D3DXVECTOR2(384, -100), 1);
	_enemySpawn[19] = CEnemySpawn(14.5, 11, D3DXVECTOR2(484, -100), 0);
	_enemySpawn[20] = CEnemySpawn(12, 11, D3DXVECTOR2(584, -100), 0);

	_enemySpawn[21] = CEnemySpawn(18, 10, D3DXVECTOR2(184, -100), 0);
	_enemySpawn[22] = CEnemySpawn(18, 10, D3DXVECTOR2(284, -100), 0);
	_enemySpawn[23] = CEnemySpawn(18, 10, D3DXVECTOR2(384, -100), 1);
	_enemySpawn[24] = CEnemySpawn(18, 10, D3DXVECTOR2(484, -100), 0);
	_enemySpawn[25] = CEnemySpawn(18, 10, D3DXVECTOR2(584, -100), 0);
	_enemySpawn[26] = CEnemySpawn(18, 10, D3DXVECTOR2(684, -100), 0);

	_enemySpawn[27] = CEnemySpawn(19, 12, D3DXVECTOR2(0, 150), 1);
	_enemySpawn[28] = CEnemySpawn(19, 13, D3DXVECTOR2(768, 150), 1);

	_enemySpawn[29] = CEnemySpawn(20, 10, D3DXVECTOR2(184, -100), 0);
	_enemySpawn[30] = CEnemySpawn(20, 10, D3DXVECTOR2(284, -100), 0);
	_enemySpawn[31] = CEnemySpawn(20, 10, D3DXVECTOR2(384, -100), 1);
	_enemySpawn[32] = CEnemySpawn(20, 10, D3DXVECTOR2(484, -100), 1);
	_enemySpawn[33] = CEnemySpawn(20, 10, D3DXVECTOR2(584, -100), 0);
	_enemySpawn[34] = CEnemySpawn(20, 10, D3DXVECTOR2(684, -100), 0);

	_enemies.clear();
}

CNextScene::~CNextScene() {

	delete _camera;
	delete _ui;
	delete _player;
	delete _boss1;
	delete _bomb;

	for (list<CEffect*>::iterator it = _effects.begin(); it != _effects.end(); it++) {

		delete (*it);
	}
	_effects.clear();

	for (list<CBullet*>::iterator it = _playerBullets.begin(); it != _playerBullets.end(); it++) {

		delete (*it);
	}
	_playerBullets.clear();

	for (list<CBullet*>::iterator it = _enemyBullets.begin(); it != _enemyBullets.end(); it++) {

		delete (*it);
	}
	_enemyBullets.clear();

	for (list<CEnemy*>::iterator it = _enemies.begin(); it != _enemies.end(); it++) {

		delete (*it);
	}
	_enemies.clear();

	for (list<CItem*>::iterator it = _items.begin(); it != _items.end(); it++) {

		delete (*it);
	}
	_items.clear();

}

void CNextScene::Update(float deltaTime) {

	_gameTime += deltaTime;

	_camera->_sprite._position.x = _map->_sprite._position.x;
	_camera->_sprite._position.y = (_map->_sprite._position.y) += ((800 - (400 * _player->isSlow)) * deltaTime);
	if (_map->_sprite._position.y >= 3072)
		_map->_sprite._position.y = 0;

	if (_player->isDestroy) {

		_playerBornTimer += deltaTime;
		if (_playerBornTimer >= _playerBornTime) {


			if (--_player->_life > 0) {

				_player->Born();
			}

			else {
				_g_Black.LoadScene(new CEndScene(false));
				return;
			}

			_playerBornTimer = 0;

		}
	}

	if (!Single::GetInstance()->canHit) {

		_player->_sprite._a += 255.0f * deltaTime;

		_godTimer += deltaTime;
		if (_godTimer >= _godTime) {

			_godTimer = 0;
			_player->_sprite._a = 255;
			Single::GetInstance()->canHit = true;
		}
	}

	SCORE++;
	if (SCORE >= 99999) {

		SCORE = 99999;
	}

	_num[4]->_sprite._scene = SCORE % 10;
	_num[3]->_sprite._scene = SCORE % 100 / 10;
	_num[2]->_sprite._scene = SCORE % 1000 / 100;
	_num[1]->_sprite._scene = SCORE % 10000 / 1000;
	_num[0]->_sprite._scene = SCORE / 10000;
	_num[5]->_sprite._scene = _player->_life;
	_num[6]->_sprite._scene = Single::GetInstance()->howBomb;

	for (int i = 0; i < 35; i++) {

		if (!_enemySpawn[i].isSpawn) {

			if (_gameTime >= _enemySpawn[i]._time) {

				_enemySpawn[i].isSpawn = true;
				_enemies.push_back(new CEnemy(_enemySpawn[i]._type, _enemySpawn[i]._pos, &_enemyBullets, _enemySpawn[i]._item));

				if (i == 27) {

					isEntBoss = true;
				}

			}
		}
	}

	if (isEntBoss) {

		if (_enemies.empty()) {

			bossEntTimer += deltaTime;
			if (bossEntTimer >= bossEntTime) {

				isEntBoss = false;
				_boss1->isDestroy = false;
			}
		}

	}

	if (isBossDead) {

		_finTimer += deltaTime;
		if (_finTimer >= _finTime) {

			_finTimer = 0;
			_g_Black.LoadScene(new CEndScene(true));
		}
	}

	//보스 X 플레이어
	if (IntersectRect(&_rect, &_player->_rect, &_boss1->_rect) & !_player->isDestroy) {

		_effects.push_back(new CEffect(&_g_Asset.Effect[2], _player->_sprite._position, 0.03f));

		if (Single::GetInstance()->canHit) {

			_player->isDestroy = true;
			Single::GetInstance()->canHit = false;
		}
	}

	//플레이어 총알 X 적
	for (list<CBullet*>::iterator it = _playerBullets.begin(); it != _playerBullets.end();) {

		(*it)->Update(deltaTime);

		for (list<CEnemy*>::iterator itt = _enemies.begin(); itt != _enemies.end(); ++itt) {

			if (IntersectRect(&_rect, &(*it)->_rect, &(*itt)->_rect)) {

				SCORE += 50;
				(*it)->isDestroy = true;
				(*itt)->_life--;

				if (((*itt)->_life) <= 0) {

					SCORE += 500;
					_effects.push_back(new CEffect(&_g_Asset.Effect[2], (*itt)->_sprite._position, 0.03f));
					(*itt)->isDestroy = true;

					if ((*itt)->_item == 1) {

						_items.push_back(new CItem((*itt)->_sprite._position, 1));
					}
				}

				else
					_effects.push_back(new CEffect(&_g_Asset.Effect[1], (*it)->_sprite._position, 0.1f));
			}

		}

		if (IntersectRect(&_rect, &(*it)->_rect, &_boss1->_rect)) {

			_effects.push_back(new CEffect(&_g_Asset.Effect[0], (*it)->_sprite._position, 0.03f));
			SCORE += 100;
			(*it)->isDestroy = true;
			_boss1->_life--;

			if ((_boss1->_life) <= 0) {

				SCORE += 500;
				_effects.push_back(new CEffect(&_g_Asset.Effect[2], _boss1->_sprite._position, 0.05f));
				_boss1->isDestroy = true;
				isBossDead = true;
			}
			else
				_effects.push_back(new CEffect(&_g_Asset.Effect[1], (*it)->_sprite._position, 0.1f));
		}

		if ((*it)->isDestroy) {

			delete (*it);
			it = _playerBullets.erase(it);
		}
		else
			++it;
	}


	//적
	for (list<CEnemy*>::iterator it = _enemies.begin(); it != _enemies.end();) {

		(*it)->Update(deltaTime);

		if (!_player->isDestroy) {

			if (IntersectRect(&_rect, &_player->_rect, &(*it)->_rect)) {

				(*it)->isDestroy = true;
				_effects.push_back(new CEffect(&_g_Asset.Effect[2], _player->_sprite._position, 0.03f));

				if (Single::GetInstance()->canHit) {

					_player->isDestroy = true;
					Single::GetInstance()->canHit = false;
				}
			}

			if (IntersectRect(&_rect, &(*it)->_rect, &_bomb->_rect)) {

				(*it)->isDestroy = true;
				_effects.push_back(new CEffect(&_g_Asset.Effect[2], (*it)->_sprite._position, 0.03f));
			}
		}
		if ((*it)->isDestroy) {

			delete (*it);
			it = _enemies.erase(it);
		}
		else {

			++it;
		}

	}

	//적총알 업데이트
	for (list<CBullet*>::iterator it = _enemyBullets.begin(); it != _enemyBullets.end();) {

		(*it)->Update(deltaTime);

		if (!_player->isDestroy) {

			if (IntersectRect(&_rect, &_player->_rect, &(*it)->_rect)) {

				(*it)->isDestroy = true;
				_effects.push_back(new CEffect(&_g_Asset.Effect[2], _player->_sprite._position, 0.03f));

				if (Single::GetInstance()->canHit) {

					_player->isDestroy = true;
					Single::GetInstance()->canHit = false;
				}
			}

			if (IntersectRect(&_rect, &(*it)->_rect, &_bomb->_rect)) {

				(*it)->isDestroy = true;
				_effects.push_back(new CEffect(&_g_Asset.Effect[2], (*it)->_sprite._position, 0.03f));
			}
		}

		if ((*it)->isDestroy) {

			delete (*it);
			it = _enemyBullets.erase(it);
		}
		else
			++it;
	}

	//아이템과 플레이어 충돌
	for (list<CItem*>::iterator it = _items.begin(); it != _items.end();) {

		(*it)->Update(deltaTime);

		if (!_player->isDestroy) {

			if (IntersectRect(&_rect, &_player->_rect, &(*it)->_rect)) {

				_player->_power++;
				(*it)->isDestroy = true;
			}
		}

		if ((*it)->isDestroy) {

			delete (*it);
			it = _items.erase(it);
		}
		else
			++it;
	}

	//이펙트 업데이트
	for (list<CEffect*>::iterator it = _effects.begin(); it != _effects.end();) {

		(*it)->Update(deltaTime);
		if ((*it)->isDestroy) {

			delete (*it);
			it = _effects.erase(it);
		}

		else
			++it;
	}

	//키 입력
	_player->isAttack = false;
	bool isPush = false;

	if (GetAsyncKeyState(VK_UP)) {

		isPush = true;
		_player->Move(0, ((-900) + (500 * _player->isSlow)) * deltaTime);
	}
	if (GetAsyncKeyState(VK_DOWN)) {

		isPush = true;
		_player->Move(0, (900 - (500 * _player->isSlow)) * deltaTime);
	}
	if (GetAsyncKeyState(VK_LEFT)) {

		isPush = true;
		_player->Move(((-900) + (500 * _player->isSlow)) * deltaTime, 0);
	}
	if (GetAsyncKeyState(VK_RIGHT)) {

		isPush = true;
		_player->Move((900 - (500 * _player->isSlow)) * deltaTime, 0);
	}
	if (GetAsyncKeyState('X')) {

		_player->isAttack = true;
	}
	if (GetAsyncKeyState('C')) {

		if (Single::GetInstance()->howBomb) {

			_bomb->isDestroy = false;
		}
	}
	if (GetAsyncKeyState(VK_LSHIFT)) {

		_player->isSlow = 1;
	}
	else
		_player->isSlow = 0;


	if (!isPush) {

		_player->Move(0, 0);
	}

	_num[0]->Update(deltaTime);
	_num[1]->Update(deltaTime);
	_num[2]->Update(deltaTime);
	_num[3]->Update(deltaTime);
	_num[4]->Update(deltaTime);
	_num[5]->Update(deltaTime);
	_num[6]->Update(deltaTime);
	_map->Update(deltaTime);
	_ui->Update(deltaTime);
	_player->Update(deltaTime);
	_boss1->Update(deltaTime);
	_bomb->Update(deltaTime);
};

void CNextScene::Render() {

	_map->Render();

	for (list<CBullet*>::iterator it = _playerBullets.begin(); it != _playerBullets.end(); ++it) {

		(*it)->Render();
	}

	_boss1->Render();

	for (list<CBullet*>::iterator it = _enemyBullets.begin(); it != _enemyBullets.end(); ++it) {

		(*it)->Render();
	}

	for (list<CEnemy*>::iterator it = _enemies.begin(); it != _enemies.end(); ++it) {

		(*it)->Render();
	}

	for (list<CItem*>::iterator it = _items.begin(); it != _items.end(); ++it) {

		(*it)->Render();
	}

	for (list<CEffect*>::iterator it = _effects.begin(); it != _effects.end(); ++it) {

		(*it)->Render();
	}

	_player->Render();
	_bomb->Render();
	_ui->Render();

	_num[0]->Render();
	_num[1]->Render();
	_num[2]->Render();
	_num[3]->Render();
	_num[4]->Render();
	_num[5]->Render();
	_num[6]->Render();
};

void CNextScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {

};