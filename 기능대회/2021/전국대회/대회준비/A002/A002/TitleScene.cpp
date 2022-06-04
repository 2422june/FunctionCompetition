#include "Header.h"

CTitleScene::CTitleScene() {

	_sprite = CSprite();
}

CTitleScene::~CTitleScene() {

}

void CTitleScene::Update(float deltaTime) {

	_sprite.Update(deltaTime);
}

void CTitleScene::Render() {

	_sprite.Render(_g_Asset.Title);
}

void CTitleScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (GetKeyState(VK_UP) & 0x8000)
		if (++_sprite._scene > 1)
			_sprite._scene = 0;

	if (GetKeyState(VK_DOWN) & 0x8000)
		if (--_sprite._scene < 0)
			_sprite._scene = 1;

	if (GetKeyState(VK_RETURN) & 0x8000) {

		if (_sprite._scene == 0)
			_g_Black.LoadScene(new CGameScene());

		else if (_sprite._scene == 1)
			PostQuitMessage(0);
	}
}