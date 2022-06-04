#pragma once
class EnemyBullet
{

public:
	EnemyBullet(D3DXVECTOR2 pos, D3DXVECTOR2 MovDir, float speed, float damage);//생성자 생성시 실행
	~EnemyBullet();//소멸자 소멸실 실행

	CSprite _sprite;//???머였지???

	bool _isDestroy;

	D3DXVECTOR2 _MovDir;

	float _speed;
	float _damage;


	RECT _rect;//FEEDBACK// 충돌처리할 RECT

	void Update(float deltaTime);//필수함수
	void Render();//필수함수
};

