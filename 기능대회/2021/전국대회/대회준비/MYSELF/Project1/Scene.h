#pragma once
//���� ����� ���¸� ����ش�.
class CScene {

public:
	CScene() {};
	virtual ~CScene() {};

public:
	virtual void Update(float deltaTime) {};
	virtual void Render() {};
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {};//Ű �Է�
};

extern CScene* _g_Scene;
extern void LoadScene(CScene* scene);