#pragma once

class CTitleScene : public CScene{

public:
	CTitleScene();
	virtual ~CTitleScene();

public:

	CSprite _sprite;

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};