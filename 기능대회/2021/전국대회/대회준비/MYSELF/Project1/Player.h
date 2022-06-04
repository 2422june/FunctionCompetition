#pragma once

class Player
{
public:
	Player(D3DXVECTOR2 pos, list<Bullet*> *bullets);//������ ������ ����
	~Player();//�Ҹ��� �Ҹ�� ����

	Player();

	int _x, _y;

	list<Bullet*> *_bullets;

	CSprite _sprite;//???�ӿ���???
	CSprite _shield;
	
	void Update(float deltaTime);//�ʼ��Լ�
	void Render();//�ʼ��Լ�
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