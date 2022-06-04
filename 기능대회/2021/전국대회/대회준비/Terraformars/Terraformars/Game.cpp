#include "Header.h"

CScene* _g_Scene;
CBlack* _g_Black;
Asset _g_Asset;
void LoadScene(CScene* scene) {

	delete _g_Scene;
	_g_Scene = scene;
};

void Init() {

	Single::GetInstance()->_addon = 0;
	Single::GetInstance()->_missile = 1;
	Single::GetInstance()->_power = 0;

	SCORE = 0;

	_g_Asset = Asset();
	_g_Black = new CBlack();

	_g_Asset.item = new CTexture*[6];
	_g_Asset.item[0] = new CTexture(L"Img/Item/item", L"png", 0, 26);
	_g_Asset.item[1] = new CTexture(L"Img/Item/item", L"png", 1, 26);
	_g_Asset.item[2] = new CTexture(L"Img/Item/item", L"png", 2, 26);
	_g_Asset.item[3] = new CTexture(L"Img/Item/item", L"png", 3, 26);
	_g_Asset.item[4] = new CTexture(L"Img/Item/item", L"png", 4, 26);
	_g_Asset.item[5] = new CTexture(L"Img/Item/item", L"png", 5, 26);

	_g_Asset.scope = new CTexture(L"Img/Bullet/scope", L"png", 0, 1);
	_g_Asset.missile = new CTexture(L"Img/Bullet/missile", L"png", 0, 1);
	_g_Asset.laser = new CTexture(L"Img/Bullet/laser", L"png", 0, 1);

	_g_Asset.addon = new CTexture(L"Img/Player/addon", L"png", 0, 5);

	_g_Asset.air = new CTexture(L"Img/Bullet/air", L"png", 0, 1);

	_g_Asset.bullets = new CTexture*[6];
	_g_Asset.bullets[0] = new CTexture(L"Img/Bullet/bullet", L"png", 0, 4);
	_g_Asset.bullets[1] = new CTexture(L"Img/Bullet/bullet", L"png", 1, 1);
	_g_Asset.bullets[2] = new CTexture(L"Img/Bullet/bullet", L"png", 2, 1);
	_g_Asset.bullets[3] = new CTexture(L"Img/Bullet/bullet", L"png", 3, 1);
	_g_Asset.bullets[4] = new CTexture(L"Img/Bullet/bullet", L"png", 4, 1);


	_g_Asset.playerImg = new CTexture*[3];
	_g_Asset.playerImg[0] = new CTexture(L"Img/Player/char", L"png", 0, 9);
	_g_Asset.playerImg[1] = new CTexture(L"Img/Player/char", L"png", 1, 7);

	_g_Asset.shadow = new CTexture(L"Img/Player/shadow", L"png", 0, 1);

	_g_Asset.sheild = new CTexture(L"Img/Player/sheild", L"png", 0, 1);

	_g_Asset.effect = new CTexture*[6];
	_g_Asset.effect[0] = new CTexture(L"Img/Effect/effect", L"png", 0, 19);
	_g_Asset.effect[1] = new CTexture(L"Img/Effect/effect", L"png", 1, 19);
	_g_Asset.effect[2] = new CTexture(L"Img/Effect/effect", L"png", 2, 19);
	_g_Asset.effect[3] = new CTexture(L"Img/Effect/effect", L"png", 3, 19);
	_g_Asset.effect[4] = new CTexture(L"Img/Effect/effect", L"png", 4, 19);
	_g_Asset.effect[5] = new CTexture(L"Img/Effect/effect", L"png", 5, 19);

	_g_Asset.enemy = new CTexture*[5];
	_g_Asset.enemy[0] = new CTexture(L"Img/Enemy/enemy", L"png", 0, 11);
	_g_Asset.enemy[1] = new CTexture(L"Img/Enemy/enemy", L"png", 1, 21);
	_g_Asset.enemy[2] = new CTexture(L"Img/Enemy/enemy", L"png", 2, 21);
	_g_Asset.enemy[3] = new CTexture(L"Img/Enemy/enemy", L"png", 3, 9);
	_g_Asset.enemy[4] = new CTexture(L"Img/Enemy/enemy", L"png", 4, 21);

	_g_Asset.boss = new CTexture*[4];
	_g_Asset.boss[0] = new CTexture(L"Img/Boss/boss", L"png", 0, 21);
	_g_Asset.boss[1] = new CTexture(L"Img/Boss/boss", L"png", 1, 21);
	_g_Asset.boss[2] = new CTexture(L"Img/Boss/boss", L"png", 2, 10);
	_g_Asset.boss[3] = new CTexture(L"Img/Boss/boss", L"png", 3, 9);

	_g_Asset.map = new CTexture(L"Img/Map/map", L"png", 0, 3);
	_g_Asset.map2 = new CTexture(L"Img/Map/map", L"png", 1, 3);

	_g_Asset.cut = new CTexture(L"Img/Scene/stage", L"png", 0, 2);

	_g_Asset.black = new CTexture(L"Img/Scene/black", L"png", 0, 1);

	_g_Asset.num = new CTexture(L"Img/Num/num", L"png", 0, 10);

	_g_Asset.title = new CTexture(L"Img/Scene/title", L"png", 0, 4);

	_g_Asset.rank = new CTexture(L"Img/Rank/rank", L"png", 0, 1);
	_g_Asset.ranking = new CTexture(L"Img/Rank/ranking", L"png", 0, 1);
	_g_Asset.text = new CTexture(L"Img/Rank/text", L"png", 0, 28);

	_g_Asset.end = new CTexture(L"Img/Scene/end", L"png", 0, 2);
	_g_Asset.vic = new CTexture(L"Img/Scene/Victory/victory", L"png", 0, 99);
	_g_Asset.fai = new CTexture(L"Img/Scene/Defeat/def", L"png", 0, 99);

	_g_Asset.ui = new CTexture(L"Img/UI/ui", L"png", 0, 5);
	_g_Asset.handle = new CTexture(L"Img/UI/handle", L"png", 0, 1);
	_g_Asset.needle = new CTexture(L"Img/UI/needle", L"png", 0, 1);

	_g_Asset.Intro = new CTexture*[5];
	_g_Asset.Intro[0] = new CTexture(L"Img/Intro/intro", L"png", 0, 100);

	_g_Asset.how = new CTexture(L"Img/Scene/howplay", L"png", 0, 1);
	_g_Scene = new CIntro();
};

void Term() {

	delete _g_Scene;
};

void Update(float deltaTime) {

	if (_g_Scene != NULL)
		_g_Scene->Update(deltaTime);

	_g_Black->Update(deltaTime);
};

void Render() {

	if (_g_Scene != NULL)
		_g_Scene->Render();

	_g_Black->Render();
};

void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (_g_Scene != NULL)
		_g_Scene->MsgProc(uMsg, wParam, lParam);
};