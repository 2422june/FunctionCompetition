#include "Header.h"

CEnemy::CEnemy(int iType, D3DXVECTOR2 pos, list<EnemyBullet*> *bullets) {
	IsDestroy = false;
	_sprite = CSprite();
	ShotTime = 2.0f;
	ShotTimer = 0.0f;
	_iType = iType;
	_bullets = bullets;
	//이미지 사이즈에 맞게 변경
	if (_iType == ETYPE_BOMB)
	{
		sizeX = 64;
		sizeY = 64;

		health = 100.0f;
		_damage = 50.0f;

		_sprite.SetAnimation(true, 0.0, 21);
	}
	else if (_iType == ETYPE_BULLET)
	{
		sizeX = 64;
		sizeY = 64;

		health = 100.0f;
		_damage = 20.0f;

		_sprite.SetAnimation(true, 0.0, 21);
	}

	_sprite._center = D3DXVECTOR2(sizeX, sizeY);
	_sprite._rotateCen = D3DXVECTOR2(sizeX, sizeY);
	_sprite._scaleCen = D3DXVECTOR2(sizeX, sizeY);

	_sprite._position = pos;
	SetRect(&_rect, _sprite._position.x - sizeX,
					_sprite._position.y - sizeY,
					_sprite._position.x + sizeX,
					_sprite._position.y + sizeY);

	IsDestroy = false;
}

CEnemy::~CEnemy() {

}

void CEnemy::Update(float deltatime) {
	_sprite._position.y += 100 * deltatime;

	if (_sprite._position.y >= 868)
	{
		IsDestroy = true;
	}
	SetRect(&_rect, _sprite._position.x - sizeX,
					_sprite._position.y - sizeY,
					_sprite._position.x + sizeX,
					_sprite._position.y + sizeY);

	//적 동작 코드 (ex, 움직임, 공격주기 등.)
	if (_iType == ETYPE_BOMB)
	{

	}
	else if (_iType == ETYPE_BULLET)
	{

	}

	_sprite.Update(deltatime);
}


void CEnemy::Render() {

	if (_iType == ETYPE_BOMB)
		_sprite.Render(_g_Asset->GetTexture("Enemy1"));
	else if (_iType == ETYPE_BULLET)
		_sprite.Render(_g_Asset->GetTexture("Enemy2"));
}

void CEnemy::GetDamage(float _damage) {
	health -= _damage;
	if (health <= 0) {
		IsDestroy = true;
	}
}