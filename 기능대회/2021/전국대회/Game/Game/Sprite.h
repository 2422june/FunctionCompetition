#pragma once
class Sprite
{
public:
	D3DXMATRIX _matrix;
	D3DXVECTOR3 _zDepthPos;
	D3DXVECTOR2 _scale;
	D3DXVECTOR2 _center;
	D3DXVECTOR2 _pos;
	D3DXVECTOR2 _rotateCen;
	D3DXVECTOR2 _scaleCen;

	float _rotate;

	bool _isAni, _aniEnd, _isRe, _setCam;

	float _aniTime, _aniStackTime;

	int _scene, _maxScene;

	int _a, _r, _g, _b;

	Sprite();

	void Update(float deltaTime);
	void Render(Texture* texture);
	void SetCam();
	void SetDepth(float depth);
	void SetAni(bool re, float time, int maxScene);
};

