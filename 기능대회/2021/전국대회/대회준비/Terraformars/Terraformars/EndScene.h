#pragma once

class CEndScene : public CScene{

public:
	CEndScene(bool vic);
	~CEndScene();

public:
	CSprite _sprite;
	CSprite _vani;
	CSprite _fani;

	CTexture* texture;

	bool isCut;
	bool _vic;

	int _type;

	void Update(float deltaTime);
	void Render();
	void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};
