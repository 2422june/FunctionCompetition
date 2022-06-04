#pragma once

class CGameScene : public CScene {

public:
	CGameScene();
	virtual ~CGameScene();

	list<Bullet*> _PlayerBullets;
	list<EnemyBullet*> _EnemyBullets;
	list<CEnemy*> _Enemys;
	list<Object1*> _Object;
	list<Item*> _Items;
	Player* _Player;
	list<Efect*> _Effects;
	Map1* _Map1;
	Map2* _Map2;
	Map3* _Map3;


	bool CanMovePla;

	int _PlaDir, _MakeEnemy;

	float _startTime;

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};