#pragma once
class EnemyBullet
{

public:
	EnemyBullet(D3DXVECTOR2 pos, D3DXVECTOR2 MovDir, float speed, float damage);//������ ������ ����
	~EnemyBullet();//�Ҹ��� �Ҹ�� ����

	CSprite _sprite;//???�ӿ���???

	bool _isDestroy;

	D3DXVECTOR2 _MovDir;

	float _speed;
	float _damage;


	RECT _rect;//FEEDBACK// �浹ó���� RECT

	void Update(float deltaTime);//�ʼ��Լ�
	void Render();//�ʼ��Լ�
};

