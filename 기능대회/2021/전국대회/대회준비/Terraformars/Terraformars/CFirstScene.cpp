#include "Header.h"

CFirstScene::CFirstScene() {

	FILE *fp = fopen("Data/MobData.txt", "r");
	FILE *fpp = fopen("Data/MapData.txt", "r");

	SCORE = 0;

	sndPlaySound(L"Sound/BGM.wav", SND_ASYNC);

	_player = new CPlayer(&_playerBullets, &_playerMissiles);
	_player->_sprite._position = D3DXVECTOR2(512, 600);
	_map = new CMap(1);
	_cut = new CCutScene(0);
	_ui = new CUI();

	_num[0] = new CNum(D3DXVECTOR2(700, 50));
	_num[1] = new CNum(D3DXVECTOR2(750, 50));
	_num[2] = new CNum(D3DXVECTOR2(800, 50));
	_num[3] = new CNum(D3DXVECTOR2(850, 50));
	_num[4] = new CNum(D3DXVECTOR2(900, 50));

	_playerBullets.clear();
	_playerMissiles.clear();
	_enemyMissiles.clear();
	_effects.clear();
	_items.clear();
	_gameTime = 0;

	_finTimer = 0;
	_finTime = 1.0f;
	_bossTimer = 0;
	_bossTime = 1.0f;

	_subBoss = new CBoss(&_enemyBullets, &_enemyMissiles,0);
	_Boss = new CBoss(&_enemyBullets, &_enemyMissiles, 1);

	isBossDead = false;
	isSubBossDead = false;
	isBossSpawn = false;
	isSubBossSpawn = false;
	reset = false;

	for (int i = 0; i < MAXENEMY; ++i) {

		fscanf(fp, "%f %d %d %d %d", &_time, &_type, &_x, &_y, &_item);
		_enemySpawnInfo[i] = CEnemySpawnInfo(_time, _type, D3DXVECTOR2(_x, _y), _item);
	};

	
}

CFirstScene::~CFirstScene() {

	sndPlaySound(NULL, NULL);
}

void CFirstScene::Update(float deltaTime) {



	_gameTime += deltaTime;
	_map->_gameTime = _gameTime;
	if (_player->_life <= 0)
		_g_Black->LoadScene(new CEndScene(0));

	_ui->_life = _player->_life;
	_ui->_speed = _player->_speed;
	_ui->_mis = _player->_missile;

	_num[0]->_num = SCORE / 10000;
	_num[1]->_num = SCORE % 10000 / 1000;
	_num[2]->_num = SCORE % 1000 / 100;
	_num[3]->_num = SCORE % 100 / 10;
	_num[4]->_num = SCORE % 10;

	for (int i = 0; i < MAXENEMY; ++i) {

		if (_gameTime >= _enemySpawnInfo[i]._time) {

			if (!_enemySpawnInfo[i].isSpawn) {

				_enemies.push_back(new CEnemy(&_enemyBullets, _enemySpawnInfo[i]._type, _enemySpawnInfo[i]._position, _enemySpawnInfo[i]._item, i));
				_enemySpawnInfo[i].isSpawn = true;

			}
		}
	}

	if (_gameTime >= 30.0f & !isSubBossDead) {

		_map->isScrool = false;
		_subBoss->isDestroy = false;
	}

	if (_subBoss->_life <= 0) {

		isSubBossDead = true;

		if (!reset) {

			reset = true;
			_gameTime = 0;
			for (int i = 0; i < MAXENEMY; ++i) {

				_enemySpawnInfo[i].isSpawn = false;
			}
		}
	}

	if (isSubBossDead)
		_map->isScrool = true;

	if (_gameTime >= 33.0f & isSubBossDead) {

		_map->isScrool = false;
		_Boss->isDestroy = false;
	}

	if (_Boss->_life <= 0) {

		isBossDead = true;
	}

	if (isBossDead) {

		_finTimer += deltaTime;
		if (_finTimer >= _finTime) {

			_g_Black->LoadScene(new CSecondScene());
		}
	}



	//맵과 충돌?
	if (IntersectRect(&_rect, &_player->_rect, &_map->_leftRect)) {

		_player->_sprite._position.x += 300 * deltaTime;
		_player->Hit(1);
	}
	if (IntersectRect(&_rect, &_player->_rect, &_map->_rightRect)) {

		_player->_sprite._position.x -= 300 * deltaTime;
		_player->Hit(1);
	}
	if (IntersectRect(&_rect, &_player->_rect, &_map->_sleftRect)) {

		_player->_sprite._position.x += 300 * deltaTime;
		_player->Hit(1);
	}
	if (IntersectRect(&_rect, &_player->_rect, &_map->_srightRect)) {

		_player->_sprite._position.x -= 300 * deltaTime;
		_player->Hit(1);
	}

	//적 미사일 X 플레이어 충돌
	for (auto it = _enemyMissiles.begin(); it != _enemyMissiles.end(); ++it) {

		(*it)->_speed = 0.3f;
		(*it)->_boomTime = 10.0f;
		(*it)->_targetPos = _player->_sprite._position;

		if (IntersectRect(&_rect, &(*it)->_rect, &_player->_rect)) {
			
			(*it)->isDestroy = true;
			_player->_life--;
			_effects.push_back(new CEffect(5, (*it)->_sprite._position));
		}
	}

	//적 미사일 X 플레이어 총알
	for (auto it = _enemyMissiles.begin(); it != _enemyMissiles.end(); ++it) {

		for (auto itt = _playerBullets.begin(); itt != _playerBullets.end(); ++itt) {

			if (IntersectRect(&_rect, &(*it)->_rect, &(*itt)->_rect)) {

				_effects.push_back(new CEffect(5, (*it)->_sprite._position));
				(*it)->isDestroy = true;
				(*itt)->isDestroy = true;
			}
		}
	}

	//플레이어 총알 X 보스s  충돌
	for (auto it = _playerBullets.begin(); it != _playerBullets.end(); ++it) {

		if(IntersectRect(&_rect, &(*it)->_rect, &_subBoss->_rect)) {

			_effects.push_back(new CEffect(2, (*it)->_sprite._position));
			_subBoss->_life--;
			(*it)->isDestroy = true;
		}
		if (IntersectRect(&_rect, &(*it)->_rect, &_Boss->_rect)) {

			_effects.push_back(new CEffect(2, (*it)->_sprite._position));
			_Boss->_life--;
			(*it)->isDestroy = true;
		}
	}

	//플레이어 총알 업데이트 X 적 충돌
	for (auto it = _playerBullets.begin(); it != _playerBullets.end();) {

		(*it)->Update(deltaTime);

		for (auto itt = _enemies.begin(); itt != _enemies.end(); ++itt) {

			if (IntersectRect(&_rect, &(*it)->_rect, &(*itt)->_rect)) {

				(*it)->isDestroy = true;
				(*itt)->_life--;

				SCORE += 50;

				if ((*itt)->_type == 0)
					_effects.push_back(new CEffect(4, (*it)->_sprite._position));
				if ((*itt)->_type == 1)
					_effects.push_back(new CEffect(2, (*it)->_sprite._position));
				if ((*itt)->_type == 2)
					_effects.push_back(new CEffect(2, (*it)->_sprite._position));
				if ((*itt)->_type == 3)
					_effects.push_back(new CEffect(4, (*it)->_sprite._position));
				if ((*itt)->_type == 4)
					_effects.push_back(new CEffect(2, (*it)->_sprite._position));
			}

			if (((*itt)->_type == 2) & ((*itt)->_life <= 0)) {

				_enemies.push_back(new CEnemy(&_enemyBullets, 4, (*itt)->_sprite._position + D3DXVECTOR2(50, -50), 0, MAXENEMY + 1));
				_enemies.push_back(new CEnemy(&_enemyBullets, 4, (*itt)->_sprite._position + D3DXVECTOR2(-50, -50), 0, MAXENEMY + 2));
			}
		}

		if ((*it)->isDestroy) {

			delete (*it);
			it = _playerBullets.erase(it);
		}
		else
			++it;
	}

	//적 총알 x 플레이어 미사일
	for (auto it = _enemyBullets.begin(); it != _enemyBullets.end();++it) {
		
		for (auto itt = _playerMissiles.begin(); itt != _playerMissiles.end(); ++itt) {

			if (IntersectRect(&_rect, &(*it)->_rect, &(*itt)->_rect)) {

				_effects.push_back(new CEffect(0, (*it)->_sprite._position));
				(*it)->isDestroy = true;
				(*itt)->isDestroy = true;
			}
			if ((*itt)->isBoom) {

				_effects.push_back(new CEffect(0, (*it)->_sprite._position));
				(*itt)->isDestroy = true;
			}
		}
	}

	//적 총알 업데이트 x 플레이어 충돌
	for (auto it = _enemyBullets.begin(); it != _enemyBullets.end();) {

		(*it)->Update(deltaTime);

		if (IntersectRect(&_rect, &(*it)->_rect, &_player->_rect)) {

			_effects.push_back(new CEffect(0, (*it)->_sprite._position));
			_player->Hit(1);
			(*it)->isDestroy = true;
		}
		if ((*it)->isDestroy) {

			delete (*it);
			it = _enemyBullets.erase(it);
		}
		else
			++it;
	}

	//적 업데이트 X 플레이어와 충돌
	for (auto it = _enemies.begin(); it != _enemies.end();) {

		(*it)->Update(deltaTime);

		if (IntersectRect(&_rect, &(*it)->_rect, &_player->_rect)) {

			if ((*it)->_type == 0)
				_effects.push_back(new CEffect(4, _player->_sprite._position));
			if ((*it)->_type == 1)
				_effects.push_back(new CEffect(3, _player->_sprite._position));
			if ((*it)->_type == 2)
				_effects.push_back(new CEffect(3, _player->_sprite._position));
			if ((*it)->_type == 3)
				_effects.push_back(new CEffect(4, _player->_sprite._position));
			if ((*it)->_type == 4)
				_effects.push_back(new CEffect(2, _player->_sprite._position));

			_player->Hit(1);
			(*it)->isDestroy = true;
		}

		if ((*it)->isDestroy) {

			if ((*it)->_type == 0)
				_effects.push_back(new CEffect(5, (*it)->_sprite._position));
			if ((*it)->_type == 1)
				_effects.push_back(new CEffect(2, (*it)->_sprite._position));
			if ((*it)->_type == 2)
				_effects.push_back(new CEffect(3, (*it)->_sprite._position));
			if ((*it)->_type == 3)
				_effects.push_back(new CEffect(4, (*it)->_sprite._position));
			if ((*it)->_type == 4)
				_effects.push_back(new CEffect(2, (*it)->_sprite._position));

			if ((*it)->_item != 0) {

				_items.push_back(new CItem((*it)->_item, (*it)->_sprite._position));
			}

			delete (*it);
			it = _enemies.erase(it);
		}
		else
			++it;
	}

	//플레이어 미사일 업데이트
	for (auto it = _playerMissiles.begin(); it != _playerMissiles.end();) {

		(*it)->Update(deltaTime);
		
		for (auto itt = _enemies.begin(); itt != _enemies.end(); ++itt) {

			if (((*it)->_homingCnt) == ((*itt)->_hommingCnt)) {

				if ((*itt)->isDestroy) {

					(*it)->isDestroy = true;
				}
				else
					(*it)->_targetPos = (*itt)->_sprite._position;
			};

			if (IntersectRect(&_rect, &(*it)->_rect, &(*itt)->_rect)) {

				_effects.push_back(new CEffect(5, (*it)->_sprite._position));
				SCORE += 100;
				(*it)->isDestroy = true;
				(*itt)->isDestroy = true;
			}
		}
	
		if (_enemies.empty())
			_effects.push_back(new CEffect(5, (*it)->_sprite._position));
			(*it)->isDestroy = true;

		if ((*it)->isDestroy) {

			_effects.push_back(new CEffect(5, (*it)->_sprite._position));
			delete (*it);
			it = _playerMissiles.erase(it);
		}
		else
			++it;
	}

	//아이템 업데이트 X 플레이어 충돌
	for (auto it = _items.begin(); it != _items.end();) {

		(*it)->Update(deltaTime);

		if (IntersectRect(&_rect, &(*it)->_rect, &_player->_rect)) {

			(*it)->isDestroy = true;
			_player->GetItem((*it)->_type);
			SCORE += 10;
		};

		if (IntersectRect(&_rect, &(*it)->_rect, &_map->_leftRect) | IntersectRect(&_rect, &(*it)->_rect, &_map->_sleftRect)) {

			(*it)->_sprite._position.x += 300 * deltaTime;
		}
		if (IntersectRect(&_rect, &(*it)->_rect, &_map->_rightRect) | IntersectRect(&_rect, &(*it)->_rect, &_map->_srightRect)) {

			(*it)->_sprite._position.x -= 300 * deltaTime;
		}

		if ((*it)->isDestroy) {

			delete (*it);
			it = _items.erase(it);
		}
		else
			++it;
	};

	//이펙트 업데이트
	for (auto it = _effects.begin(); it != _effects.end(); ++it)
		(*it)->Update(deltaTime);

	//미사일 업데이트
	for (auto it = _enemyMissiles.begin(); it != _enemyMissiles.end();) {

		(*it)->Update(deltaTime);

		if ((*it)->isDestroy) {

			delete (*it);
			it = _enemyMissiles.erase(it);
		}
		else
			++it;
	}

	bool keyDown = false;
	if (GetAsyncKeyState(VK_UP)) {

		_player->Move(0, -400 * deltaTime);
	}
	if (GetAsyncKeyState(VK_DOWN)) {

		_player->Move(0, 400 * deltaTime);
	}
	if (GetAsyncKeyState(VK_LEFT)) {

		keyDown = true;
		_ui->HandleMove(0);
		_player->Move(-400 * deltaTime * _player->_speed, 0);
	}
	if (GetAsyncKeyState(VK_RIGHT)) {

		keyDown = true;
		_ui->HandleMove(1);
		_player->Move(400 * deltaTime * _player->_speed, 0);
	}
	if (GetAsyncKeyState('X')) {

		_player->Attack();
	}
	if (GetAsyncKeyState('C')) {

		_player->Missile();
	}
	if (GetAsyncKeyState('V')) {

		_g_Black->LoadScene(new CEndScene(1));
	}
	if (GetAsyncKeyState('F')) {

		_g_Black->LoadScene(new CEndScene(0));
	}
	if (GetAsyncKeyState(VK_F1)) {

		_player->_life = 10;
	}
	if (GetAsyncKeyState(VK_F2)) {

		_player->GetItem(2);
	}
	if (GetAsyncKeyState(VK_F3)) {

		_player->GetItem(6);
	}
	if (GetAsyncKeyState(VK_F4)) {

		_g_Black->LoadScene(new CTitleScene());
	}
	if (GetAsyncKeyState(VK_F5)) {

		_g_Black->LoadScene(new CFirstScene());
	}
	if (GetAsyncKeyState(VK_F6)) {

		_g_Black->LoadScene(new CSecondScene());
	}


	if (!keyDown) {

		_player->ChangeState(0);
		_ui->HandleMove(2);
	}

	_num[0]->Update(deltaTime);
	_num[1]->Update(deltaTime);
	_num[2]->Update(deltaTime);
	_num[3]->Update(deltaTime);
	_num[4]->Update(deltaTime);

	_cut->Update(deltaTime);
	_map->Update(deltaTime);
	_subBoss->Update(deltaTime);
	_Boss->Update(deltaTime);
	_player->Update(deltaTime);
	_ui->Update(deltaTime);
}

void CFirstScene::Render() {

	_map->Render();

	for (auto it = _playerBullets.begin(); it != _playerBullets.end(); ++it)
		(*it)->Render();

	for (auto it = _enemyBullets.begin(); it != _enemyBullets.end(); ++it)
		(*it)->Render();

	for (auto it = _items.begin(); it != _items.end(); ++it)
		(*it)->Render();

	for (auto it = _enemies.begin(); it != _enemies.end(); ++it)
		(*it)->Render();

	_player->Render();

	for (auto it = _playerMissiles.begin(); it != _playerMissiles.end(); ++it)
		(*it)->Render();

	_subBoss->Render();

	_Boss->Render();

	for (auto it = _enemyMissiles.begin(); it != _enemyMissiles.end(); ++it)
		(*it)->Render();

	for (auto it = _effects.begin(); it != _effects.end(); ++it)
		(*it)->Render();

	_num[0]->Render();
	_num[1]->Render();
	_num[2]->Render();
	_num[3]->Render();
	_num[4]->Render();

	_cut->Render();
	_ui->Render();
}

void CFirstScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {

}