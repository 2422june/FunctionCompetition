#include "Header.h"

Intro::Intro() {
	_sprite = Sprite();
	_sprite.SetAni(false, 0.05, 100);
	_sprite._scale = D3DXVECTOR2((1920 / 960), (1080 / 540));

}

Intro::~Intro() {

}

void Intro::Update(float deltaTime) {
	if (_sprite._aniEnd) {
		_g_Loading->LoadScene(new Menu());
	}

	_sprite.Update(deltaTime);
}

void Intro::Render() {
	_sprite.Render(_g_Asset->GetTexture("Intro"));
}

void Intro::MsgProc(UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_KEYDOWN:
		if (wParam == VK_RETURN) {
			_g_Loading->LoadScene(new Menu());
		}
	}
}