#include "Header.h"

Bullet::Bullet(D3DXVECTOR2 pos, D3DXVECTOR2 MovDir, float speed, float damage) {
	_sprite = CSprite();//모음짐, 도움말??????

	_speed = speed;
	_damage = damage;

	D3DXVec2Normalize(&_MovDir/*a*/, &MovDir/*b*/);
	//b를 변환해 a로 저장

	_sprite._position = pos;
	_sprite._center = D3DXVECTOR2(40, 40);		//정보적인 위치, 포지션
	_sprite._scaleCen = D3DXVECTOR2(40, 40);	//크기변환에 대한 센터
	_sprite._rotateCen = D3DXVECTOR2(40, 40);	//회전에 대한 센터

	_sprite.SetAnimation(true, 0, 4);

	_isDestroy = false;
}


Bullet::~Bullet() {

}

void Bullet::Update(float deltaTime) {
	//노멀라이즈 =  벡터 정규화(거리 조정)
	_sprite._position += ((_MovDir * _speed) * deltaTime);

	if (_sprite._position.y <= -100) {
		_isDestroy = true;
	}

	//FEEDBACK// 업데이트 위치변동에 맞추어 범위 이동
	SetRect(&_rect, _sprite._position.x - 10, _sprite._position.y - 10, _sprite._position.x + 10, _sprite._position.y + 10);
	
	_sprite.Update(deltaTime);//_sprite내부의 객체의 정보를 저장(갱신)
}


void Bullet::Render() {
	_sprite.Render(_g_Asset->GetTexture("Bullet0"));
}