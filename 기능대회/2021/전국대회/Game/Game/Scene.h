#pragma once

class Scene
{
public:
	Scene() {};
	virtual ~Scene() {};
	virtual void Update(float deltaTime) {};
	virtual void Render() {};
	virtual void MsgProc(UINT msg, WPARAM wParam, LPARAM lParam) {};
};

extern Scene* _g_Scene;
extern void LoadScene(Scene* scene);