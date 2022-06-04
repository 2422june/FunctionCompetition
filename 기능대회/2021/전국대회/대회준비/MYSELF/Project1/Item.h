#pragma once
class Item
{
public:
	Item(int iType, D3DXVECTOR2 pos);
	~Item();

	void Update(float deltatime);
	void Render();
	void Move();
	bool GetItem;
	int cen;
	RECT _rect;
	CSprite _sprite;
	float _damage, _speed;
	int _iType;
};

