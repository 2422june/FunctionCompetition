#pragma once

#define MAXENEMY 70

class CFirstScene : public CScene {

public:
	CFirstScene();
	virtual ~CFirstScene();

public:
	CPlayer* _player;
	CBoss* _subBoss;
	CBoss* _Boss;
	CMap* _map;
	CNum* _num[5];
	CUI* _ui;
	CCutScene* _cut;
	CEnemySpawnInfo _enemySpawnInfo[100];

	list<CBullet*> _playerBullets;
	list<CBullet*> _enemyBullets;
	list<CMissile*> _playerMissiles;
	list<CMissile*> _enemyMissiles;
	list<CEnemy*> _enemies;
	list<CEffect*> _effects;
	list<CItem*> _items;

	RECT _rect;

	float _time;
	float _gameTime;
	int _type;
	int _x;
	int _y;
	int _item;

	float _finTime;
	float _finTimer;

	float _bossTime;
	float _bossTimer;

	bool isSubBossSpawn;
	bool isBossSpawn;
	bool reset;

	bool isSubBossDead;
	bool isBossDead;

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};