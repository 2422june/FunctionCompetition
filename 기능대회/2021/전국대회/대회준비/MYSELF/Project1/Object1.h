#pragma once
class Object1
{
public:
	Object1(D3DXVECTOR2 pos);
	~Object1();

	void Update(float deltatime);
	void Render();
	void GetDamage(float _damage);

	bool IsDestroy;
	float health, _damage;

	CSprite _sprite;
	RECT _rect;

};

