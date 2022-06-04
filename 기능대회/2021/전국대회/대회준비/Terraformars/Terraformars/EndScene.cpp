#include "Header.h"

CEndScene::CEndScene(bool victory) {

	_sprite = CSprite();
	_vani = CSprite();
	_fani = CSprite();

	ALLCEN(_sprite, 0, 0);
	ALLCEN(_vani, 0, 0);
	ALLCEN(_fani, 0, 0);

	_vani._a = 0;
	_fani._a = 0;

	_sprite._position = D3DXVECTOR2(0, 0);
	_vani._position = D3DXVECTOR2(0, 0);
	_fani._position = D3DXVECTOR2(0, 0);

	_vic = victory;
	_vani.SetAnimation(true, 0.01f, 99);
	_fani.SetAnimation(true, 0.01f, 99);
	
	if (victory) {

		_vani._a = 255;
		_fani._a = 0;
		_sprite._scene = 1;
		_vani.SetAnimation(true, 0.01f, 99);
		_fani.SetAnimation(true, 0.01f, 99);
	}
	else {

		_fani._a = 255;
		_vani._a = 0;
		_sprite._scene = 0;
		_vani.SetAnimation(true, 0.01f, 99);
		_fani.SetAnimation(true, 0.01f, 99);
	}
}

CEndScene::~CEndScene() {

}

void CEndScene::Update(float deltaTime) {

	_vani.Update(deltaTime);
	_fani.Update(deltaTime);
	_sprite.Update(deltaTime);
}

void CEndScene::Render() {

	_sprite.Render(_g_Asset.end);
	_vani.Render(_g_Asset.vic);
	_fani.Render(_g_Asset.fai);
}

void CEndScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {

	case WM_KEYDOWN:

		if (GetAsyncKeyState(VK_RETURN)) {

				_g_Black->LoadScene(new CRankScene(SCORE));
		}
	};
}
