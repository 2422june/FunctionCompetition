#pragma once

class CIntro : public CScene {

public:
	CIntro();
	virtual ~CIntro();

public:
	CSprite _intro[5];

	bool ani1;
	bool ani2;
	bool ani3;
	bool ani4;

	float _time;

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};