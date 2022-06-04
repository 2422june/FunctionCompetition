#pragma once

class CBoss {

public:
	CBoss(list<CBullet*> *bullets, list<CMissile*> *missiles, int type);

public:
	CSprite _sprite;
	CTexture* _texture;

	list<CBullet*> *_bullets;
	list<CMissile*> *_missiles;
	
	RECT _rect;
	
	int _type;

	float _gameTime;
	float _bulletTime;
	float _bulletTimer;
	float _misTime;
	float _misTimer;
	float _life;

	bool isDestroy;
	bool isSpawn;

	void Update(float deltaTime);
	void Render();
};