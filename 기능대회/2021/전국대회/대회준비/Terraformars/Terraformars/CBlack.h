#pragma once


//Load Screen
class CBlack {

public:
	CBlack();

public:
	CSprite _sprite;
	CScene* _scene;

	bool isLoading;
	bool isFadeIn;

	float _pauseTime;
	float _pauseTimer;

	void Update(float deltaTime);
	void Render();
	void LoadScene(CScene* scene);
};

extern CBlack* _g_Black;