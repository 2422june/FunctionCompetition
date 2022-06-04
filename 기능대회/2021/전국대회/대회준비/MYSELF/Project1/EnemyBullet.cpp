#include "Header.h"

EnemyBullet::EnemyBullet(D3DXVECTOR2 pos, D3DXVECTOR2 MovDir, float speed, float damage) {
	_sprite = CSprite();//������, ����??????

	_speed = speed;
	_damage = damage;

	D3DXVec2Normalize(&_MovDir/*a*/, &MovDir/*b*/);
	//b�� ��ȯ�� a�� ����

	_sprite._position = pos;
	_sprite._center = D3DXVECTOR2(20, 20);		//�������� ��ġ, ������
	_sprite._scaleCen = D3DXVECTOR2(20, 20);	//ũ�⺯ȯ�� ���� ����
	_sprite._rotateCen = D3DXVECTOR2(20, 20);	//ȸ���� ���� ����
	SetRect(&_rect, _sprite._position.x - 20, _sprite._position.y - 20, _sprite._position.x + 20, _sprite._position.y + 20);

	_isDestroy = false;
}


EnemyBullet::~EnemyBullet() {

}

void EnemyBullet::Update(float deltaTime) {
	//��ֶ����� =  ���� ����ȭ(�Ÿ� ����)
	_sprite._position += ((_MovDir * _speed) * deltaTime);


	if (_sprite._position.y >= 868) {
		_isDestroy = true;
	}

	//FEEDBACK// ������Ʈ ��ġ������ ���߾� ���� �̵�
	SetRect(&_rect, _sprite._position.x - 10, _sprite._position.y - 10, _sprite._position.x + 10, _sprite._position.y + 10);

	_sprite.Update(deltaTime);//_sprite������ ��ü�� ������ ����(����)
}


void EnemyBullet::Render() {
	_sprite.Render(_g_Asset->GetTexture("EnemyBullet"));
}