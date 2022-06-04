#pragma once

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

	bool _isAnimation;
	bool _isRepeat;
	bool _isAniEnd;

	int _scene;
	int _maxScene;
	int _a, _r, _g, _b;

	float _animationTime;
	float _aniStackTime;
	float _rotate;

	void Update(float deltaTime);
	void Render(CTexture* texture);
	void SetAnimation(bool repeat, float time, int maxScene);
};