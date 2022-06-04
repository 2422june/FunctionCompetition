#pragma once
//씬의 공통된 형태를 잡아준다.
class CScene {

public:
	CScene() {};
	virtual ~CScene() {};

public:
	virtual void Update(float deltaTime) {};
	virtual void Render() {};
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {};//키 입력
};

extern CScene* _g_Scene;
extern void LoadScene(CScene* scene);