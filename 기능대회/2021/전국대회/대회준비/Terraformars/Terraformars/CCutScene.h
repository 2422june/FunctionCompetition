#pragma once

class CCutScene {

public:
	CCutScene(int type);

public:
	CSprite _sprite;

	float _cutTime;
	float _cutTimer;
	float _stopTime;
	float _stopTimer;

	CTexture* texture;

	bool isCut;

	int _type;

	void Update(float deltaTime);
	void Render();
};