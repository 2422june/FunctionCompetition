#include "Header.h"

Loading::Loading() {

	_sprite = Sprite();

	_time = _timer = 0;

	_load = _fadeIn = false;

	_sprite._a = 0;
}

void Loading::Update(float deltaTime) {
	if (_load)
	{
		if (_fadeIn)
		{
			_sprite._a += 255 * deltaTime;
			if (_sprite._a >= 255) {
				_sprite._a = 255;
				_timer += deltaTime;

				if (_timer >= _time) {
					_timer = 0;
					delete _g_Scene;
					_g_Scene = _scene;
					_fadeIn = false;
				}
			}
		}
		else
		{
			_sprite._a -= 255 * deltaTime;
			if (_sprite._a <= 0) {
				_sprite._a = 0;
				_load = false;
			}
		}
	}

	_sprite.Update(deltaTime);
}

void Loading::Render() {
	_sprite.Render(_g_Asset->GetTexture("Loading"));
}

void Loading::LoadScene(Scene* scene) {
	if (!_load) {
		_scene = scene;
		_load = _fadeIn = true;
		_timer = 0;

	}
}