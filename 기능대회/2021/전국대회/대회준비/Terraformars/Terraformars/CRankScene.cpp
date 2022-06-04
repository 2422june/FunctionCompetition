#include "Header.h"

CRankScene::CRankScene(int score) {

	_sprite = CSprite();

	_text = CSprite();
	_a = CSprite();
	_b = CSprite();
	_c = CSprite();

	ALLCEN(_sprite, 0, 0);
	ALLCEN(_text, 75, 75);
	ALLCEN(_a, 75, 75);
	ALLCEN(_b, 75, 75);
	ALLCEN(_c, 75, 75);

	_sprite._position = D3DXVECTOR2(0, 0);
	_text._position = D3DXVECTOR2(512, 550);
	_a._position = D3DXVECTOR2(350, 250);
	_b._position = D3DXVECTOR2(500, 250);
	_c._position = D3DXVECTOR2(650, 250);

	_a._scene = 26;
	_b._scene = 26;
	_c._scene = 26;

	_score = score;
	inpCount = 0;

	fp = fopen("Data/RankData.txt", "a");
}

CRankScene::~CRankScene() {

	fclose(fp);
}

void CRankScene::Update(float deltaTime) {

	_sprite.Update(deltaTime);

	_text.Update(deltaTime);
	_a.Update(deltaTime);
	_b.Update(deltaTime);
	_c.Update(deltaTime);
}

void CRankScene::Render() {

	_sprite.Render(_g_Asset.rank);

	_text.Render(_g_Asset.text);
	_a.Render(_g_Asset.text);
	_b.Render(_g_Asset.text);
	_c.Render(_g_Asset.text);
}

void CRankScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {

	case WM_KEYDOWN:
		
		for (int i = 0; i < 26; ++i) {

			if (GetKeyState(i + 65) & 0x8000) {

				_text._scene = i;
			}
		}

		if (GetAsyncKeyState(VK_RETURN)) {

			if (inpCount == 0) {

				_c._scene = _text._scene;
				inpCount++;
			}
			else if (inpCount == 1) {

				_b._scene = _c._scene;
				_c._scene = _text._scene;
				inpCount++;
			}
			else if (inpCount == 2) {

				_a._scene = _b._scene;
				_b._scene = _c._scene;
				_c._scene = _text._scene;
				_text._scene = 27;
				inpCount++;
			}
			else if (inpCount == 3) {

				fprintf(fp, "%d %d %d %d \n", _a._scene, _b._scene, _c._scene, _score);
				_g_Black->LoadScene(new CTitleScene());
			}
		}
		if (GetAsyncKeyState(VK_BACK)) {

			_text._scene = 0;

			if (inpCount == 1) {

				_a._scene = 26;
				_b._scene = 26;
				_c._scene = 26;
				inpCount--;
			}
			else if (inpCount == 2) {

				_c._scene = _b._scene;
				_b._scene = 26;
				_a._scene = 26;
				inpCount--;
			}
			else if (inpCount == 3) {

				_c._scene = _b._scene;
				_b._scene = _a._scene;
				_a._scene = 26;
				inpCount--;
			}
		}
	}
}