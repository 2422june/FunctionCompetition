#include "Header.h"

CIntro::CIntro() {

	/*
	for (int i = 0; i < 5; ++i) {

		_intro[i] = CSprite();
		ALLCEN(_intro[i], 0, 0);
		_intro[i]._position = D3DXVECTOR2(0, 0);
	}
	*/
	_intro[0] = CSprite();
	ALLCEN(_intro[0], 0, 0);
	_intro[0]._position = D3DXVECTOR2(0, 0);
	_intro[0].SetAnimation(false, 0.02, 99);
	ani1 = false;
	ani2 = false;
	ani3 = false;
	ani4 = false;
}

CIntro::~CIntro() {

}

void CIntro::Update(float deltaTime) {

	_time += deltaTime;

	_intro[0].Update(deltaTime);
	
	if (_intro[0]._isAniEnd) {

		_g_Black->LoadScene(new CTitleScene());
	}
}

void CIntro::Render() {



	_intro[0].Render(_g_Asset.Intro[0]);
}

void CIntro::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {


}