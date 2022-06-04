#pragma once
class Loading
{
public:

	Loading();

	void Update(float deltaTime);
	void Render();


	Scene* _scene;
	Sprite _sprite;

	float _time, _timer;

	bool _load, _fadeIn;

	void LoadScene(Scene* scene);
};

