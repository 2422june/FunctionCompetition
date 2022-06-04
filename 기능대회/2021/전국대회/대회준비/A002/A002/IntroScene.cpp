#include "Header.h"

CIntroScene::CIntroScene() {

	_sprite = CSprite();
	_sprite.SetAnimation(false, 0.05, 38);
}

CIntroScene::~CIntroScene() {

}

void CIntroScene::Update(float deltaTime) {

	if (_sprite._isAniEnd)
		_g_Black.LoadScene(new CTitleScene());

	_sprite.Update(deltaTime);
}

void CIntroScene::Render() {
	
	_sprite.Render(_g_Asset.Intro);
}

void CIntroScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (GetKeyState(VK_RETURN) & 0x8000) {

		_g_Black.LoadScene(new CTitleScene());
	}
}