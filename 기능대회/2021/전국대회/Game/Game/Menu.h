#pragma once

class Menu : public Scene
{
public:
	Menu();
	virtual ~Menu();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void MsgProc(UINT msg, WPARAM wParam, LPARAM lParam);

	Sprite _back, _s1, _s2, _s3, _s4, _logo, _point;

	FILE *file;
};
