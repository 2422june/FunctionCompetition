#pragma once

class Camera;

class CSprite {

public:
	CSprite();

public:
	D3DXMATRIX _matrix;
	D3DXVECTOR2 _position;
	D3DXVECTOR2 _scaleCen;
	D3DXVECTOR2 _scale;
	D3DXVECTOR2 _rotateCen;
	D3DXVECTOR2 _center;
	Camera* _camera;
	float _rotate;

	bool _isAnimation;
	bool _isRepeat;
	bool _isAniEnd;
	float _animationTime;
	float _aniStackTime;
	int _scene;
	int _maxScene;
	int _a, _r, _g, _b;

	void Update(float deltaTime);
	void Render(CTexture* texture);
	void SetCamera(Camera* camera);
	void SetAnimation(bool repeat, float time, int maxScene);
};

class Camera {

public:
	CSprite _sprite;
};