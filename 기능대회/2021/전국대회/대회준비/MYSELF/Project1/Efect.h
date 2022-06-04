#pragma once
class Efect
{
public:
	Efect(D3DXVECTOR2 pos);
	~Efect();

	CSprite _sprite;

	bool _isDestroy;

	void Update(float deltaTime);
	void Render();
};

