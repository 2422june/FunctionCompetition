#pragma once

class CBomb {

public:
	CBomb();
	
public:
	CSprite _sprite;
	CTexture** _texture;
	RECT _rect;

	bool isDestroy;
	float bombStayTime;
	float bombStayTimer;

	void Update(float deltaTime);
	void Render();
};