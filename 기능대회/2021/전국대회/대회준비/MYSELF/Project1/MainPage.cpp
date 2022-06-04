#include "Header.h"

MainPage::MainPage() {
	_title = new CSprite();
	_title->_position = D3DXVECTOR2(0, 0);
	Select = 0;
}

MainPage::~MainPage() {

}

void MainPage::Update(float deltaTime) {
	if (GetAsyncKeyState(VK_RETURN)) {
		switch (Select) {
		case 0:
			_g_Loading->LoadScene(new CGameScene());
			break;
		case 3:
			PostQuitMessage(0);
			break;
		}
	}
	_title->Update(deltaTime);
};

void MainPage::Render() {
	_title->Render(_g_Asset->GetTexture("Title"));
};

void MainPage::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_KEYDOWN:
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			Select--;
			if (Select == -1) {
				Select = 3;
			}
			_title->_scene = Select;
		}
		else if(GetAsyncKeyState(VK_DOWN) & 0x8000) {
			Select++;
			if (Select == 4) {
				Select = 0;
			}
			_title->_scene = Select;
		}
	}
};