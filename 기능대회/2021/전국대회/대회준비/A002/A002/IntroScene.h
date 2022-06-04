#pragma once

class CIntroScene : public CScene {

public:
	CIntroScene();
	virtual ~CIntroScene();

public:
	CSprite _sprite;
	
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};