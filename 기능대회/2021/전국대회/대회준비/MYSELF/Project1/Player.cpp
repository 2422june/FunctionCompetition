#include "Header.h"

Player::Player(D3DXVECTOR2 pos, list<Bullet*> *bullets) {
	_sprite = CSprite();//������, ����??????

	_sprite._position = pos;

	shield = false;

	speed = 300.0f;
	_sprite._center = D3DXVECTOR2(96, 96);		//�������� ��ġ, ������
	_sprite._scaleCen = D3DXVECTOR2(96, 96);	//ũ�⺯ȯ�� ���� ����
	_sprite._rotateCen = D3DXVECTOR2(96, 96);	//ȸ���� ���� ����

	_isShield = false;
	_shield._center = D3DXVECTOR2(110, 110);
	_shield._rotateCen = D3DXVECTOR2(110, 110);
	_shield._scaleCen = D3DXVECTOR2(110, 110);
	_shield._a = 0;//���İ� 0~255(����)

	_bullets = bullets;
	damage = 50.0f;
	_isAttack= false;
	_attackTime = 0.3f;
	_attackTimer = 0.0f;
	health = 100.0f;
	SetRect(&_rect, _sprite._position.x - 96, _sprite._position.y - 96, _sprite._position.x + 96, _sprite._position.y + 96);
}


Player::Player() {

}

Player::~Player() {

}


void Player::GetDamage(float _damage) {
	if (!shield) {
		health -= _damage;
		if (health <= 0) {
			_isDestroy = true;
		}
	}
}


void Player::GetItem(int __iType, float attack, float _speed) {
	if (__iType == 0) {
		damage += attack;
	}
	else {
		speed += _speed;
	}
}

void Player::Move(int x, int y) {
	_x = x;
	_y = y;
	if (x == 0) {
	}
	else if(x < 0){
		_sprite._scale.x = -1;
		ChangeState(-1);
	}
	else if (x > 0) {
		_sprite._scale.x = 1;
		ChangeState(-1);
	}

	_sprite._position.x += _x;
	_sprite._position.y += _y;
}

void Player::ChangeState(int state) {
	if (state != _state) {//���°� �ٲ���.
		if (state == 0) {
			_sprite.SetAnimation(true, 0.0, 9);
		}
		else {
			_sprite.SetAnimation(false, 0.0, 7);
		}
	}
	_state = state;
}

void Player::Setshield(bool isShield) {
	_isShield = isShield;
	if (isShield) {
		shield = true;
		_shield._a = 110;
	}
	else {
		shield = false;
		_shield._a = 0;
	}
}

void Player::Update(float deltaTime) {
	_shield._position = _sprite._position;

	SetRect(&_rect, _sprite._position.x-96, _sprite._position.y- 96, _sprite._position.x + 96, _sprite._position.y + 96);


	_sprite.Update(deltaTime);//_sprite������ ��ü�� ������ ����(����)

	_shield.Update(deltaTime);
}


void Player::Render() {

	if (_state == 0) {
		_sprite.Render(_g_Asset->GetTexture("Player_idle"));
	}
	else if (_state == -1) {
		_sprite.Render(_g_Asset->GetTexture("Player_turn"));//�ҷ��´�, �����´�????????
	}
	_shield.Render(_g_Asset->GetTexture("Player_Shield"));
}