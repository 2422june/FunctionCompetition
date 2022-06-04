#pragma once

class CUI {

public:
	CUI();
	CUI(CTexture** texture);

public:
	CSprite _sprite;
	CTexture** _texture;

	void Update(float deltaTime);
	void Render();
};