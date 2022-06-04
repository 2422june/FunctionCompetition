#pragma once
class MainPage : public CScene {

public:
	MainPage();
	virtual ~MainPage();

	CSprite* _title;

	int Select;

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};

