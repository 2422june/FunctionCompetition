#include "Header.h"

GameScene::GameScene() {

}

GameScene::~GameScene() {

}

void GameScene::Update(float deltaTime) {
	if (GetAsyncKeyState(VK_RETURN)) {
		_g_Loading->LoadScene(new GameScene());
	}
}

void GameScene::Render() {

}

void GameScene::MsgProc(UINT msg, WPARAM wParam, LPARAM lParam) {

}