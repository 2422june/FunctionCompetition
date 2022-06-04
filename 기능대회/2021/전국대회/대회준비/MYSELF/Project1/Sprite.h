#pragma once

class CSprite {

public:
	D3DXMATRIX _matrix;//���
	D3DXVECTOR2 _position;//��ġ
	D3DXVECTOR2 _scaleCen;//ũ�⺯���� ��������
	D3DXVECTOR2 _scale;//ũ��
	D3DXVECTOR2 _rotateCen;//ȸ���� ��������
	D3DXVECTOR2 _center;//��ġ�� ���� ����
	D3DXVECTOR3 _zDepthPosition;//�켱 ���̾� ����
	//z����
	//x����
	//y����

	float _rotate;//�� ����(���ͱ���)

	bool _isAnimation;//�ִϸ��̼� ��� ����
	bool _isRepeat;//�ִϸ��̼� �ݺ� ����
	bool _isAniEnd;//�ִϸ��̼� ���� ����
	bool _isSetCamera;//ī�޶�� ������ �� ������ ����(UI�� False, NPC�� True)
	
	float _animationTime;//�ִϸ��̼��� ������ ������ ����
	float _aniStackTime;

	int _scene;//�� ������� �ִϸ��̼��� �����Ӽ���
	int _maxScene;//�ִϸ��̼��� �������� ����
	int _a, _r, _g, _b;

	CSprite();
	void Update(float deltaTime);
	void Render(CTexture* texture);

	void SetAnimation(bool repeat, float time, int maxScene);
	void SetCamera();
	void SetDepth(float depth);
};