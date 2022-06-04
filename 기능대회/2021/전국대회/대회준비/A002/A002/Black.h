#pragma once

class CBlack {

public:
	CBlack();

public:
	CScene* _scene;
	CSprite _sprite;

	bool isLoading;
	bool isFadeIn;

	float loadTime;
	float loadTimer;

	void Update(float deltaTime);
	void Render();
	void LoadScene(CScene* scene);
};