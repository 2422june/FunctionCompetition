#include "Header.h"

CHowPlayScene::CHowPlayScene() {

	_sprite = CSprite();
}

CHowPlayScene::~CHowPlayScene() {

}

void CHowPlayScene::Update(float deltaTime) {

	_sprite.Update(deltaTime);
}

void CHowPlayScene::Render() {

	_sprite.Render(_g_Asset.how);
}

void CHowPlayScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {

	case WM_KEYDOWN:
		_g_Black->LoadScene(new CTitleScene());
	}
}