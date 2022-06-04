#pragma once

class CEndScene : public CScene {

public:
	CEndScene(bool Victory);
	virtual ~CEndScene();

public:
	CSprite _sprite;
	bool _Victory;

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};