#pragma once

class CMap {

public:
	CMap(int state);

public:
	CSprite _first;
	CSprite _second;
	CSprite _third;
	FILE* _fp;

	CTexture* texture;

	RECT _leftRect;
	RECT _rightRect;
	RECT _sleftRect;
	RECT _srightRect;

	int _firstScene;
	int _secondScene;

	float _gameTime;

	bool isScrool;

	void Update(float deltaTime);
	void Render();
};