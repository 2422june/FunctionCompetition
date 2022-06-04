#pragma once

#define SCORE Single::GetInstance()->_gameScore

class CGameScene : public CScene {

public:
	CGameScene();
	virtual ~CGameScene();

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	bool isPush;

public:
	CPlayer* _player;
	CBoss* _boss1;
	CBomb* _bomb;
	Camera* _camera;
	CMap* _map;
	CUI* _ui;
	CNum* _num[7];

	list<CEnemy*> _enemies;
	list<CBullet*> _enemyBullets;
	list<CBullet*> _playerBullets;
	list<CEffect*> _effects;
	list<CItem*> _items;

	CEnemySpawn _enemySpawn[100];

	RECT _rect;

	float _playerBornTime;
	float _playerBornTimer;
	float _godTime;
	float _godTimer;
	float _finTime;
	float _finTimer;

	float bossEntTime;
	float bossEntTimer;
	bool isEntBoss;
	bool isBossDead;
	float _gameTime;
};