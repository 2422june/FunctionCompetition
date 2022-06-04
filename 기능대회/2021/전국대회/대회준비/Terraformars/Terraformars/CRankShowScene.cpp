#include "Header.h"

CRankShowScene::CRankShowScene() {

	_sprite = CSprite();
	ALLCEN(_sprite, 0, 0);
	_sprite._position = D3DXVECTOR2(0, 0);


	for (int i = 0; i < 9; ++i) {

		_name[i] = CSprite();
		ALLCEN(_name[i], 75, 75);
	}

	for (int i = 0; i < 15; ++i) {

		_num[i] = CSprite();
		ALLCEN(_num[i], 17.5, 25);
	}

	SETPOS(_name[0], 250, 300);
	SETPOS(_name[1], 350, 300);
	SETPOS(_name[2], 450, 300);
	SETPOS(_name[3], 250, 450);
	SETPOS(_name[4], 350, 450);
	SETPOS(_name[5], 450, 450);
	SETPOS(_name[6], 250, 600);
	SETPOS(_name[7], 350, 600);
	SETPOS(_name[8], 450, 600);
	
	SETPOS(_num[0], 600, 300);
	SETPOS(_num[1], 650, 300);
	SETPOS(_num[2], 700, 300);
	SETPOS(_num[3], 750, 300);
	SETPOS(_num[4], 800, 300);

	SETPOS(_num[5], 600, 450);
	SETPOS(_num[6], 650, 450);
	SETPOS(_num[7], 700, 450);
	SETPOS(_num[8], 750, 450);
	SETPOS(_num[9], 800, 450);
	
	SETPOS(_num[10], 600, 600);
	SETPOS(_num[11], 650, 600);
	SETPOS(_num[12], 700, 600);
	SETPOS(_num[13], 750, 600);
	SETPOS(_num[14], 800, 600);

	fp = fopen("Data/RankData.txt", "r");
	
	for (int i = 0; i < 3; ++i) {

		fscanf(fp, "%d %d %d %d", &_a[i], &_b[i], &_c[i], &_score[i]);
	}
}

CRankShowScene::~CRankShowScene() {

}

void CRankShowScene::Update(float deltaTime) {

	_sprite.Update(deltaTime);

	_name[0]._scene = _a[0];
	_name[1]._scene = _b[0];
	_name[2]._scene = _c[0];

	_name[3]._scene = _a[1];
	_name[4]._scene = _b[1];
	_name[5]._scene = _c[1];

	_name[6]._scene = _a[2];
	_name[7]._scene = _b[2];
	_name[8]._scene = _c[2];

	_num[0]._scene = _score[0] / 10000;
	_num[1]._scene = _score[0] % 10000 / 1000;
	_num[2]._scene = _score[0] % 1000 / 100;
	_num[3]._scene = _score[0] % 100 / 10;
	_num[4]._scene = _score[0] % 10;

	_num[5]._scene = _score[1] / 10000;
	_num[6]._scene = _score[1] % 10000 / 1000;
	_num[7]._scene = _score[1] % 1000 / 100;
	_num[8]._scene = _score[1] % 100 / 10;
	_num[9]._scene = _score[1] % 10;

	_num[10]._scene = _score[2] / 10000;
	_num[11]._scene = _score[2] % 10000 / 1000;
	_num[12]._scene = _score[2] % 1000 / 100;
	_num[13]._scene = _score[2] % 100 / 10;
	_num[14]._scene = _score[2] % 10;

	for (int i = 0; i < 9; ++i) {

		_name[i].Update(deltaTime);
	}

	for (int i = 0; i < 15; ++i) {

		_num[i].Update(deltaTime);
	}
}

void CRankShowScene::Render() {

	_sprite.Render(_g_Asset.ranking);

	for (int i = 0; i < 9; ++i) {

		_name[i].Render(_g_Asset.text);
	}

	for (int i = 0; i < 15; ++i) {

		_num[i].Render(_g_Asset.num);
	}
}

void CRankShowScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {

	case WM_KEYDOWN:
		if (GetKeyState(VK_RETURN)) {

			_g_Black->LoadScene(new CTitleScene);
		}
	}
}