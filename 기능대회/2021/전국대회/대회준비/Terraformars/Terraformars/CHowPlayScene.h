#pragma once

class CHowPlayScene : public CScene{

public:
	CHowPlayScene();
	virtual ~CHowPlayScene();

public:
	CSprite _sprite;

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};