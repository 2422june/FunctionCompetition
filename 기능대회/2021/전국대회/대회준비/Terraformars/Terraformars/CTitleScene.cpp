#include "Header.h"

CTitleScene::CTitleScene() {

	_sprite = CSprite();
	_sprite._position = D3DXVECTOR2(0, 0);
	ALLCEN(_sprite, 0, 0);
}

CTitleScene::~CTitleScene() {

}

void CTitleScene::Update(float deltaTime) {

	_sprite.Update(deltaTime);
}

void CTitleScene::Render() {

	_sprite.Render(_g_Asset.title);
}

void CTitleScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {

	case WM_KEYDOWN:

		if (GetKeyState(VK_UP) & 0x8000) {

			--_sprite._scene;
			if (_sprite._scene < 0)
				_sprite._scene = 3;
		}

		if (GetKeyState(VK_DOWN) & 0x8000) {

			++_sprite._scene;
			if (_sprite._scene > 3)
				_sprite._scene = 0;
		}

		if (GetAsyncKeyState(VK_RETURN)) {

			if (_sprite._scene == 0) {

				_g_Black->LoadScene(new CFirstScene());
			}
			else if (_sprite._scene == 1) {

				_g_Black->LoadScene(new CHowPlayScene());
			}
			else if (_sprite._scene == 2) {

				_g_Black->LoadScene(new CRankShowScene());
			}
			else if (_sprite._scene == 3) {

				PostQuitMessage(0);
			}
		}
	}
}