#include "Header.h"

CScene* _g_Scene;
Asset* _g_Asset;
CLoading* _g_Loading;
CCamera* _g_Camera;

void LoadScene(CScene* scene) {

	delete _g_Scene;
	_g_Scene = scene;
}

void Init() {

	_g_Asset = new Asset();
	_g_Loading = new CLoading();
	_g_Scene = new MainPage();
	_g_Camera = new CCamera();

	//scene
	_g_Asset->AddTexture("Title", new CTexture(L"Img/Scene/title", L"png", 0, 4));
	//load
	_g_Asset->AddTexture("Loading", new CTexture(L"Img/Loading/Loading", L"png", 0, 1));//�̹��� �ҷ�����
	//map
	_g_Asset->AddTexture("Map1", new CTexture(L"Img/Background/map", L"png", 0, 1));
	_g_Asset->AddTexture("Map3", new CTexture(L"Img/Background/map", L"png", 2, 1));
	_g_Asset->AddTexture("Map2", new CTexture(L"Img/Background/map", L"png", 1, 1));
	//player
	_g_Asset->AddTexture("Player_idle"/*�̹��� �г���*/, new CTexture(L"Img/Player/char", L"png", 0, 9/*����*/));//L�� ���̴� ������ ���ڿ� ����(�����ڵ�, ��Ƽ����Ʈ)�� �޶� �̴�.
	_g_Asset->AddTexture("Player_turn"/*�̹��� �г���*/, new CTexture(L"Img/Player/char", L"png", 1, 7));//????????
	//shield
	_g_Asset->AddTexture("Player_Shield", new CTexture(L"Img/Player/shield", L"png", 0, 1));
	//bullet
	_g_Asset->AddTexture("Bullet0", new CTexture(L"Img/Bullet/bullet", L"png", 0, 4));
	_g_Asset->AddTexture("EnemyBullet", new CTexture(L"Img/Bullet/bullet", L"png", 1, 1));
	//efect
	_g_Asset->AddTexture("Efect1", new CTexture(L"Img/Efect/effect", L"png", 0, 19));
	//Enemy
	_g_Asset->AddTexture("Enemy1", new CTexture(L"Img/Enemy/enemy", L"png", 1, 21));
	_g_Asset->AddTexture("Object1", new CTexture(L"Img/Enemy/enemy", L"png", 1, 21));
	_g_Asset->AddTexture("Enemy2", new CTexture(L"Img/Enemy/enemy", L"png", 4, 21));
	//Item
	_g_Asset->AddTexture("Item1", new CTexture(L"Img/Item/item", L"png", 0, 26));
	_g_Asset->AddTexture("Item0", new CTexture(L"Img/Item/item", L"png", 2, 26));
}

void Term() {
	//����� ����°�
	delete _g_Scene;
	delete _g_Asset;
}

//�� ������Ʈ
void Update(float deltaTime) {

	if (_g_Scene != NULL)
		_g_Scene->Update(deltaTime);

	_g_Loading->Update(deltaTime);
}

void Render() {

	if (_g_Scene != NULL)
		_g_Scene->Render();

	_g_Loading->Render();
}

void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (_g_Scene != NULL)
		_g_Scene->MsgProc(uMsg, wParam, lParam);
}

Asset::Asset() {

	_textures.clear();
}

Asset::~Asset() {

	for (auto it = _textures.begin(); it != _textures.end(); ++it) {

		if (it->second != NULL)
			delete it->second;
	}
}

void Asset::AddTexture(string key, CTexture* value) {

	if (_textures.find(key) == _textures.end())
		_textures[key] = value;

	else {};
}

CTexture* Asset::GetTexture(string key) {//�̹��� ���ε�

	if (_textures.find(key) == _textures.end())
		return NULL;

	return _textures[key];
}

void CCamera::SetPos(D3DXVECTOR2 pos) {//�����ɶ� ī�޶��� �ʱ� ������

	_sprite._position = pos;
}

D3DXVECTOR2 CCamera::GetPos() {//ī�޶� ��ġ ���

	return _sprite._position;
}