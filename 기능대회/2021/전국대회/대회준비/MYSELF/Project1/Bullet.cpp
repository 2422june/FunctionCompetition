#include "Header.h"

Bullet::Bullet(D3DXVECTOR2 pos, D3DXVECTOR2 MovDir, float speed, float damage) {
	_sprite = CSprite();//������, ����??????

	_speed = speed;
	_damage = damage;

	D3DXVec2Normalize(&_MovDir/*a*/, &MovDir/*b*/);
	//b�� ��ȯ�� a�� ����

	_sprite._position = pos;
	_sprite._center = D3DXVECTOR2(40, 40);		//�������� ��ġ, ������
	_sprite._scaleCen = D3DXVECTOR2(40, 40);	//ũ�⺯ȯ�� ���� ����
	_sprite._rotateCen = D3DXVECTOR2(40, 40);	//ȸ���� ���� ����

	_sprite.SetAnimation(true, 0, 4);

	_isDestroy = false;
}


Bullet::~Bullet() {

}

void Bullet::Update(float deltaTime) {
	//��ֶ����� =  ���� ����ȭ(�Ÿ� ����)
	_sprite._position += ((_MovDir * _speed) * deltaTime);

	if (_sprite._position.y <= -100) {
		_isDestroy = true;
	}

	//FEEDBACK// ������Ʈ ��ġ������ ���߾� ���� �̵�
	SetRect(&_rect, _sprite._position.x - 10, _sprite._position.y - 10, _sprite._position.x + 10, _sprite._position.y + 10);
	
	_sprite.Update(deltaTime);//_sprite������ ��ü�� ������ ����(����)
}


void Bullet::Render() {
	_sprite.Render(_g_Asset->GetTexture("Bullet0"));
}