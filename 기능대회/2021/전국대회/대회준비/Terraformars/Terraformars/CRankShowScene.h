#pragma once

#define SETPOS(a, _x, _y) a._position = D3DXVECTOR2(_x, _y)

class CRankShowScene : public CScene {

public:
	CRankShowScene();
	virtual ~CRankShowScene();

public:
	CSprite _sprite;
	CSprite _name[9];
	CSprite _num[15];

	FILE *fp;

	int _a[3], _b[3], _c[3], _score[3];

	void Update(float deltaTime);
	void Render();
	void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};