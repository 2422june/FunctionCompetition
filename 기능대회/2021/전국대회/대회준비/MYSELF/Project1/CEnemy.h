#pragma once

class CEnemy
{
public:
	CEnemy(int iType, D3DXVECTOR2 pos, list<EnemyBullet*> *bullets);
	~CEnemy();

	void Update(float deltatime);
	void Render();
	void GetDamage(float _damage);

	bool IsDestroy;
	float health, _damage, ShotTime, ShotTimer;
	int _iType;

	int sizeX = 0, sizeY = 0;

	list<EnemyBullet*> *_bullets;

	CSprite _sprite;
	RECT _rect;

};