#include "Header.h"

Menu::Menu() {
	_back = _s1 = _s2 = _s3 = _s4 =  _point = _logo = Sprite();

	_back.SetAni(true, 0.1, 137 - 99);
	_back._scale = D3DXVECTOR2((1920 / 960), (1080 / 540));

	fopen_s(&file, "gameStart.txt", "a");
	string s = "gamestart";
	fprintf(file, "%s", &s);
	fclose(file);
}

Menu::~Menu() {

}

void Menu::Update(float deltaTime) {
	_back.Update(deltaTime);
}

void Menu::Render() {
	_back.Render(_g_Asset->GetTexture("MenuBack"));
}

void Menu::MsgProc(UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_KEYDOWN:
		if (wParam == VK_RETURN) {
			_g_Loading->LoadScene(new GameScene());
		}
	}
}