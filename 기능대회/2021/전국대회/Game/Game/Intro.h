#pragma once
class Intro : public Scene
{
public:
	Intro();
	virtual ~Intro();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void MsgProc(UINT msg, WPARAM wParam, LPARAM lParam);

	Sprite _sprite;
};
