#include "Header.h"


CGameScene::CGameScene() {
	//동적 배열
	//1. 맵 : 키워드 + 이름으로 추가
	//2. 백터 : 지워도 데이터를 남기는 방식
	_MakeEnemy = 0;
	_PlayerBullets.clear();
	_Enemys.clear();
	_Effects.clear();
	_Object.clear();
	_Items.clear();
	_Player = new Player(D3DXVECTOR2(512, 600), &_PlayerBullets);
	_Enemys.push_back(new CEnemy(ETYPE_BOMB, D3DXVECTOR2(100, 20), &_EnemyBullets));
	_Enemys.push_back(new CEnemy(ETYPE_BULLET, D3DXVECTOR2(350, 20), &_EnemyBullets));
	_Map1 = new Map1();
	_Map2 = new Map2();
	_Map3 = new Map3();
	_PlaDir = 0;
	CanMovePla = true;

	for (auto it = _Object.begin(); it != _Object.end(); ++it) {
		(*it)->_sprite.SetAnimation(true, 0.0, 21);
	}

	//애니메이션 구성(반복여부, 간격, 프레임 갯수)
	_Player->_sprite.SetAnimation(true, 0.0, 7);
	_Map1->_sprite.SetAnimation(false, 0.0, 1);
	_Map2->_sprite.SetAnimation(false, 0.0, 1);
	_Map3->_sprite.SetAnimation(false, 0.0, 1);

	_startTime = 0.0f;
}

CGameScene::~CGameScene() {

}



void CGameScene::Update(float deltaTime) {

	_startTime += deltaTime;

	if (_startTime >= 5.0f && _MakeEnemy == 0)
	{
		_Enemys.push_back(new CEnemy(ETYPE_BULLET, D3DXVECTOR2(128 / 2, 20), &_EnemyBullets));
		_Enemys.push_back(new CEnemy(ETYPE_BOMB, D3DXVECTOR2(1024 / 2, 20), &_EnemyBullets));
		_Enemys.push_back(new CEnemy(ETYPE_BULLET, D3DXVECTOR2(950, 20), &_EnemyBullets));
		++_MakeEnemy;
	}
	if (_startTime >= 10.5f && _MakeEnemy == 1)
	{
		_Enemys.push_back(new CEnemy(ETYPE_BOMB, D3DXVECTOR2(128 / 2, 20), &_EnemyBullets));
		_Enemys.push_back(new CEnemy(ETYPE_BULLET, D3DXVECTOR2(1024 / 2, 20), &_EnemyBullets));
		_Enemys.push_back(new CEnemy(ETYPE_BOMB, D3DXVECTOR2(950, 20), &_EnemyBullets));
		++_MakeEnemy;
	}
	if (_startTime >= 16.0f && _MakeEnemy == 2)
	{
		_Enemys.push_back(new CEnemy(ETYPE_BOMB, D3DXVECTOR2(128 / 2, 20), &_EnemyBullets));
		_Enemys.push_back(new CEnemy(ETYPE_BULLET, D3DXVECTOR2(1024 / 2, 20), &_EnemyBullets));
		_Enemys.push_back(new CEnemy(ETYPE_BOMB, D3DXVECTOR2(950, 20), &_EnemyBullets));
		++_MakeEnemy;
	}

	for (auto it = _Enemys.begin(); it != _Enemys.end(); it++) {
		if ((*it)->_iType == ETYPE_BULLET) {
			if ((*it)->ShotTime <= (*it)->ShotTimer) {
				_EnemyBullets.push_back(new EnemyBullet((*it)->_sprite._position, D3DXVECTOR2(0, 1), 1000.0f, 50.0f));
				(*it)->ShotTimer = 0.0f;
			}
			else {
				(*it)->ShotTimer += deltaTime;
			}
		}
	}


	if (GetAsyncKeyState(VK_RETURN)) {

		_g_Loading->LoadScene(new CGameScene());
	}


	//키를 누르고 있는가?
	if (GetAsyncKeyState(VK_UP) && CanMovePla) {
		if (_Player->_sprite._position.y > 0 + 96) {
			_Player->Move(0, -1 * _Player->speed * deltaTime);
			_PlaDir = 1;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN) && CanMovePla) {
		if (_Player->_sprite._position.y < 768 - 96) {
			_Player->Move(0, _Player->speed * deltaTime);
			_PlaDir = 2;
		}
	}


	if (GetAsyncKeyState(VK_RIGHT) && CanMovePla) {
		if (_Player->_sprite._position.x < 1024 - 85) {
			_Player->Move( _Player->speed * deltaTime, 0);
			_PlaDir = 3;
		}
	}
	else if (GetAsyncKeyState(VK_LEFT) && CanMovePla) {
		if (_Player->_sprite._position.x > 0 + 68) {
			_Player->Move(-1 * _Player->speed * deltaTime, 0);
			_PlaDir = 4;
		}
	}
	else {
		_Player->ChangeState(0);
		_PlaDir = 0;
	}

	
	if (GetAsyncKeyState(VK_SPACE)) {

		_Player->_isAttack = true;
	}

	if (_Player->_isAttack) {
		_Player->_attackTimer += deltaTime;
		if (_Player->_attackTimer >= _Player->_attackTime) {
			_Player->_bullets->push_back(new Bullet(_Player->_sprite._position, D3DXVECTOR2(0, -1), 1000.0f, _Player->damage));
			printf("%f\n", _Player->damage);
			_Player->_attackTimer = 0.0f;
			_Player->_isAttack = false;
		}
	}

	if (GetAsyncKeyState(VK_LSHIFT)) {
		_Player->Setshield(true);
	}
	else {
		_Player->Setshield(false);
	}


	_Map1->Move(6);
	_Map2->Move(6);
	_Map3->Move(6);

	for (auto _it = _Enemys.begin(); _it != _Enemys.end(); _it++) {
		if (Overlap_Manager::Overlap(&_Player->_rect, &(*_it)->_rect))
		{
			_Effects.push_back(new Efect(_Player->_sprite._position));
			_Player->GetDamage((*_it)->_damage);
			(*_it)->IsDestroy = true;
		}
	}

	for (auto it = _PlayerBullets.begin(); it != _PlayerBullets.end(); it++) {//불렛 배열 체크
		for (auto _it = _Enemys.begin(); _it != _Enemys.end(); _it++) {
			if (Overlap_Manager::Overlap(&(*it)->_rect, &(*_it)->_rect))
			{
				_Effects.push_back(new Efect((*it)->_sprite._position));
				(*_it)->GetDamage((*it)->_damage);
				(*it)->_isDestroy = true;
			}
		}
	}

	for (auto it = _PlayerBullets.begin(); it != _PlayerBullets.end(); it++) {//불렛 배열 체크
		for (auto _it = _Object.begin(); _it != _Object.end(); _it++) {
			if (Overlap_Manager::Overlap(&(*it)->_rect, &(*_it)->_rect))
			{
				_Effects.push_back(new Efect((*it)->_sprite._position));
				(*_it)->GetDamage((*it)->_damage);
				(*it)->_isDestroy = true;
			}
		}
	}

	for (auto it = _EnemyBullets.begin(); it != _EnemyBullets.end(); it++) {//불렛 배열 체크
		if (Overlap_Manager::Overlap(&(*it)->_rect, &_Player->_rect))
		{
			_Effects.push_back(new Efect((*it)->_sprite._position));
			_Player->GetDamage((*it)->_damage);
			(*it)->_isDestroy = true;
		}
	}

	for (auto it = _Items.begin(); it != _Items.end(); it++) {//불렛 배열 체크
		if (Overlap_Manager::Overlap(&(*it)->_rect, &_Player->_rect))
		{
			_Player->GetItem((*it)->_iType, (*it)->_damage, (*it)->_speed);
			(*it)->GetItem = true;
		}
	}

//--------------------------------------------------------------------------------------------
	for (auto it = _PlayerBullets.begin(); it != _PlayerBullets.end();) {//불렛 배열 체크
		(*it)->Update(deltaTime);
		if ((*it)->_isDestroy) {
			delete (*it);
			it = _PlayerBullets.erase(it);
		}
		else {
			++it;
		}
	}
	for (auto it = _EnemyBullets.begin(); it != _EnemyBullets.end();) {//불렛 배열 체크
		(*it)->Update(deltaTime);
		if ((*it)->_isDestroy) {
			delete (*it);
			it = _EnemyBullets.erase(it);
		}
		else {
			++it;
		}
	}

	for (auto _it = _Enemys.begin(); _it != _Enemys.end();) {
		(*_it)->Update(deltaTime);
		if ((*_it)->IsDestroy) {
			if ((*_it)->_iType == ETYPE_BOMB) {
				_Items.push_back(new Item(1, D3DXVECTOR2((*_it)->_sprite._position)));
			}else{
				_Items.push_back(new Item(0, D3DXVECTOR2((*_it)->_sprite._position)));
			}
			delete (*_it);
			_it = _Enemys.erase(_it);
		}
		else {
			++_it;
		}
	}

	for (auto _it = _Object.begin(); _it != _Object.end();) {
		(*_it)->Update(deltaTime);
		if ((*_it)->IsDestroy) {
			delete (*_it);
			_it = _Object.erase(_it);
		}
		else {
			++_it;
		}
	}

	for (auto _it = _Items.begin(); _it != _Items.end();) {
		(*_it)->Update(deltaTime);
		if ((*_it)->GetItem) {
			delete (*_it);
			_it = _Items.erase(_it);
		}
		else {
			++_it;
		}
	}


	if (_Player->_isDestroy) {
		PostQuitMessage(0);
	}
	_Player->Update(deltaTime);

	_Map1->Update(deltaTime);
	_Map2->Update(deltaTime);
	_Map3->Update(deltaTime);
};

void CGameScene::Render() {

	_Map1->Render();
	_Map2->Render();
	_Map3->Render();

	for (auto it = _PlayerBullets.begin(); it != _PlayerBullets.end(); ++it) {
		(*it)->Render();
	}
	for (auto it = _EnemyBullets.begin(); it != _EnemyBullets.end(); ++it) {
		(*it)->Render();
	}

	_Player->Render();

	for (auto it = _Enemys.begin(); it != _Enemys.end(); ++it) {
		(*it)->Render();
	}
	for (auto it = _Items.begin(); it != _Items.end(); ++it) {
		(*it)->Render();
	}
	for (auto it = _Object.begin(); it != _Object.end(); ++it) {
		(*it)->Render();
	}
	for (auto it = _Effects.begin(); it != _Effects.end(); ++it) {
		(*it)->Render();
	}
};

void CGameScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {

};