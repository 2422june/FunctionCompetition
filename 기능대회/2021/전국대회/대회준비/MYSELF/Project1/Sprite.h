#pragma once

class CSprite {

public:
	D3DXMATRIX _matrix;//행렬
	D3DXVECTOR2 _position;//위치
	D3DXVECTOR2 _scaleCen;//크기변경의 중점선정
	D3DXVECTOR2 _scale;//크기
	D3DXVECTOR2 _rotateCen;//회전의 중점선정
	D3DXVECTOR2 _center;//위치의 중점 선정
	D3DXVECTOR3 _zDepthPosition;//우선 레이어 선정
	//z깊이
	//x가로
	//y세로

	float _rotate;//현 각도(센터기준)

	bool _isAnimation;//애니메이션 재생 여부
	bool _isRepeat;//애니메이션 반복 여부
	bool _isAniEnd;//애니메이션 종료 여부
	bool _isSetCamera;//카메라와 동행할 것 인지의 여부(UI가 False, NPC가 True)
	
	float _animationTime;//애니메이션의 프레임 사이의 간격
	float _aniStackTime;

	int _scene;//현 재생중인 애니메이션의 프레임순서
	int _maxScene;//애니메이션의 프레임의 갯수
	int _a, _r, _g, _b;

	CSprite();
	void Update(float deltaTime);
	void Render(CTexture* texture);

	void SetAnimation(bool repeat, float time, int maxScene);
	void SetCamera();
	void SetDepth(float depth);
};