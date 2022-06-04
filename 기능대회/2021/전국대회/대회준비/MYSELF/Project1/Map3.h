#pragma once
class Map3
{
public:
	Map3();
	~Map3();

	void Move(float speed);

	float _speed;

	CSprite _sprite;

	void Update(float deltaTime);
	void Render();
};

