#include "Header.h"

Player::Player(D3DXVECTOR2 pos, list<Bullet*> *bullets) {
	_sprite = CSprite();//모음짐, 도움말??????

	_sprite._position = pos;

	shield = false;

	speed = 300.0f;
	_sprite._center = D3DXVECTOR2(96, 96);		//정보적인 위치, 포지션
	_sprite._scaleCen = D3DXVECTOR2(96, 96);	//크기변환에 대한 센터
	_sprite._rotateCen = D3DXVECTOR2(96, 96);	//회전에 대한 센터

	_isShield = false;
	_shield._center = D3DXVECTOR2(110, 110);
	_shield._rotateCen = D3DXVECTOR2(110, 110);
	_shield._scaleCen = D3DXVECTOR2(110, 110);
	_shield._a = 0;//알파값 0~255(투명도)

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
	if (state != _state) {//상태가 바꼈다.
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


	_sprite.Update(deltaTime);//_sprite내부의 객체의 정보를 저장(갱신)

	_shield.Update(deltaTime);
}


void Player::Render() {

	if (_state == 0) {
		_sprite.Render(_g_Asset->GetTexture("Player_idle"));
	}
	else if (_state == -1) {
		_sprite.Render(_g_Asset->GetTexture("Player_turn"));//불러온다, 가져온다????????
	}
	_shield.Render(_g_Asset->GetTexture("Player_Shield"));
}