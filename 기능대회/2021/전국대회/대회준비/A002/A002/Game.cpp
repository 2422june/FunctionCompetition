#include "Header.h"

CScene* _g_Scene;
CBlack _g_Black;
Asset _g_Asset;

void LoadScene(CScene* scene) {

	delete _g_Scene;
	_g_Scene = scene;
}

void Init() {

	_g_Black = CBlack();
	_g_Asset = Asset();

	//로딩
	_g_Asset.Black = new CTexture(L"Img/Scene/Black", L"png", 0, 1);

	//인트로 애니메이션
	_g_Asset.Intro = new CTexture(L"Img/Intro/Intro", L"png", 0, 38);

	//타이틀
	_g_Asset.Title = new CTexture(L"Img/Scene/Title", L"jpg", 0, 2);

	//엔딩
	_g_Asset.Victory = new CTexture(L"Img/Scene/Victory", L"jpg", 0, 1);
	_g_Asset.Failed = new CTexture(L"Img/Scene/Failed", L"jpg", 0, 1);

	//플레이어 애니메이션
	_g_Asset.playerImg = new CTexture*[3];
	_g_Asset.playerImg[0] = new CTexture(L"Img/Player/char", L"png", 0, 8);
	_g_Asset.playerImg[1] = new CTexture(L"Img/Player/char", L"png", 1, 8);
	_g_Asset.playerImg[2] = new CTexture(L"Img/Player/char", L"png", 2, 8);

	//플레이어 총알
	_g_Asset.playerBullet = new CTexture(L"Img/Bullet/Bullet", L"png", 0, 1);
	_g_Asset.playerBomb = new CTexture(L"Img/Bullet/bomb", L"png", 0, 14);
	
	//적 총알
	_g_Asset.enemyBullet = new CTexture(L"Img/Bullet/Bullet", L"png", 1, 1);
	_g_Asset.enemySpaceBullet = new CTexture(L"Img/Bullet/Bullet", L"png", 3, 1);
	_g_Asset.enemyLaser = new CTexture(L"Img/Bullet/Bullet", L"png", 2, 1);

	//적 애니메이션
	//0 : 자폭, 1 : 전투기, 2 : 헬기, 3 : 운석, 4 : 우주전투기, 5 : 우주헬기 
	_g_Asset.enemyImg = new CTexture*[5];
	_g_Asset.enemyImg[0] = new CTexture(L"Img/Enemy/msi", L"png", 0, 18);
	_g_Asset.enemyImg[1] = new CTexture(L"Img/Enemy/Enemy", L"png", 1, 8);
	_g_Asset.enemyImg[2] = new CTexture(L"Img/Enemy/Enemy", L"png", 2, 8);
	_g_Asset.enemyImg[3] = new CTexture(L"Img/Enemy/Enemy", L"png", 3, 25);
	_g_Asset.enemyImg[4] = new CTexture(L"Img/Enemy/Enemy", L"png", 4, 1);
	_g_Asset.enemyImg[5] = new CTexture(L"Img/Enemy/Enemy", L"png", 5, 13);

	//보스 애니메이션
	_g_Asset.Boss1Img = new CTexture(L"Img/Boss/Boss1", L"png", 0, 1);
	_g_Asset.Boss2Img = new CTexture(L"Img/Boss/final", L"png", 0, 10);

	//아이템
	_g_Asset.itemPower = new CTexture(L"Img/Item/power", L"png", 0, 25);

	//이펙트
	_g_Asset.Effect = new CTexture*[5];
	_g_Asset.Effect[0] = new CTexture(L"Img/Effect/Effect", L"png", 0, 9);
	_g_Asset.Effect[1] = new CTexture(L"Img/Effect/Effect", L"png", 1, 5);
	_g_Asset.Effect[2] = new CTexture(L"Img/Effect/exb", L"png", 0, 17);
	
	//맵
	_g_Asset.Map0 = new CTexture(L"Img/Map/Map", L"png", 0, 1);
	_g_Asset.Map1 = new CTexture(L"Img/Map/Map", L"png", 1, 1);

	//UI관련
	_g_Asset.CUI = new CTexture(L"Img/Scene/UI", L"png", 0, 1);
	_g_Asset.Num = new CTexture(L"Img/Num/Num", L"png", 0, 10);

	_g_Scene = new CIntroScene();
	//_g_Scene = new CNextScene();
}

void Term() {

	delete _g_Scene;
	delete _g_Asset.Black;

	delete _g_Asset.Intro;
	delete _g_Asset.Title;
	delete _g_Asset.Victory;
	delete _g_Asset.Failed;
	delete _g_Asset.playerImg;
	delete _g_Asset.playerBullet;
	delete[] _g_Asset.enemyImg;
	delete _g_Asset.enemyBullet;
	delete _g_Asset.enemySpaceBullet;
	delete _g_Asset.enemyLaser;
	delete _g_Asset.Boss1Img;
	delete[] _g_Asset.Effect;
	delete _g_Asset.Map0;
	delete _g_Asset.Map1;
	delete _g_Asset.CUI;
	delete _g_Asset.Num;
}

void Update(float deltaTime) {

	if (_g_Scene != NULL)
		_g_Scene->Update(deltaTime);

	_g_Black.Update(deltaTime);
}

void Render() {

	if (_g_Scene != NULL)
		_g_Scene->Render();

	_g_Black.Render();
}

void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (_g_Scene != NULL)
		_g_Scene->MsgProc(uMsg, wParam, lParam);
}