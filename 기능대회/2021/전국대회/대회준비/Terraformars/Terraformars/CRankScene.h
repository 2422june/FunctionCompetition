#pragma once

class CRankScene : public CScene{

public:
	CRankScene(int score);
	virtual ~CRankScene();

public:
	CSprite _sprite;

	CSprite _text;
	CSprite _a;
	CSprite _b;
	CSprite _c;

	FILE* fp;

	int _score;
	int inpCount;

	void Update(float deltaTime);
	void Render();
	void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};