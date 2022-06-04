#pragma once

class Player
{
public:
	Player(D3DXVECTOR2 pos, list<Bullet*> *bullets);//생성자 생성시 실행
	~Player();//소멸자 소멸실 실행

	Player();

	int _x, _y;

	list<Bullet*> *_bullets;

	CSprite _sprite;//???머였지???
	CSprite _shield;
	
	void Update(float deltaTime);//필수함수
	void Render();//필수함수
	void GetDamage(float _damage);
	void GetItem(int __iType, float attack, float _speed);

	bool _isAttack, _isDestroy, shield;
	float _attackTime, _attackTimer, damage;
	float speed, health;
	void Move(int x, int y);

	//S:0, RL:-1
	int _state;

	void ChangeState(int state);


	bool _isShield;
	void Setshield(bool isShield);

	RECT _rect;
};