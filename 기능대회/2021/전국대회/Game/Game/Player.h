#pragma once
class Player
{
public:
	Player();
	~Player();

	void Update(float deltaTime);
	void Render();

	void Move(float x, float y);

	float _x, _y;

	Sprite _pla;
};

