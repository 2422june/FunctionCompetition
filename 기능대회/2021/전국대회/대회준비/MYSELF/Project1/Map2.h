#pragma once
class Map2
{
public:
	Map2();
	~Map2();

	void Move(float speed);

	float _speed;

	CSprite _sprite;

	void Update(float deltaTime);
	void Render();
};

