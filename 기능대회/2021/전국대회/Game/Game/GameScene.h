#pragma once
class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene();

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void MsgProc(UINT msg, WPARAM wParam, LPARAM lParam);
};