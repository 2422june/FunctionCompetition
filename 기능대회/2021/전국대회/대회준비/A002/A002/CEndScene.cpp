#include "Header.h"

CEndScene::CEndScene(bool Victory) {

	_Victory = Victory;
	_sprite = CSprite();
}

CEndScene::~CEndScene() {

}

void CEndScene::Update(float deltaTime) {

	_sprite.Update(deltaTime);
}

void CEndScene::Render() {

	if (_Victory)
		_sprite.Render(_g_Asset.Victory);

	else
		_sprite.Render(_g_Asset.Failed);
}

void CEndScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (GetKeyState(VK_RETURN) & 0x8000)
		_g_Black.LoadScene(new CTitleScene());
}