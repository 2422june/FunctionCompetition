#pragma once

class CLoading {

public:
	CLoading();
	~CLoading();

	void Update(float deltaTime);
	void Render();
	void LoadScene(CScene* scene);

public:
	CScene* _scene;
	CSprite _sprite;
	
	bool bIsLoading;
	bool bIsFadeIn;

	float loadTime;
	float loadTimer;
};