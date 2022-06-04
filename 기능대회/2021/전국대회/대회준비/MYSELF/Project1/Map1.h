#pragma once
class Map1
{
public:
	Map1();
	~Map1();

	void Move(float speed);

	float _speed;

	CSprite _sprite;

	void Update(float deltaTime);
	void Render();
};

