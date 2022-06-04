#include "Header.h"

Asset* _g_Asset;
Loading* _g_Loading;
Scene* _g_Scene;
Camera* _g_Camera;

void Init() {
	_g_Asset = new Asset();
	_g_Loading = new Loading();
	_g_Scene = new Intro();
	_g_Camera = new Camera();

	_g_Asset->AddTexture("Loading", new Texture(L"Img/UI/Load", L"png", 0, 1, 4, 0));

	_g_Asset->AddTexture("Intro", new Texture(L"Img/UI/intro/a", L"jpg", 0, 100, 4, 0));


	_g_Asset->AddTexture("MenuBack", new Texture(L"Img/UI/main/background/a", L"jpg", 0, 137, 4, 99));

	_g_Asset->AddTexture("PlayerRun", new Texture(L"Img/Unit/player/move/a", L"png", 0, 12, 4, 0));
}

void Term() {
	delete _g_Scene;
	delete _g_Asset;
}

void Update(float deltaTime) {
	if (_g_Scene != NULL) {
		_g_Scene->Update(deltaTime);
	}
	_g_Loading->Update(deltaTime);
}

void Render() {
	if (_g_Scene != NULL) {
		_g_Scene->Render();
	}
	_g_Loading->Render();
}

void MsgProc(UINT msg, WPARAM wParam, LPARAM lParam) {
	if (_g_Scene != NULL) {
		_g_Scene->MsgProc(msg, wParam, lParam);
	}
}

Asset::Asset() {
	_textures.clear();
}

Asset::~Asset() {
	for (auto it = _textures.begin(); it != _textures.end(); ++it) {
		if (it->second != NULL) {
			delete it->second;
		}
	}
}

void Asset::AddTexture(string key, Texture* value) {
	if (_textures.find(key) == _textures.end()) {
		_textures[key] = value;
	}
}

Texture* Asset::GetTexture(string key) {
	if (_textures.find(key) == _textures.end()) {
		return NULL;
	}
	return _textures[key];
}

void Camera::SetPos(D3DXVECTOR2 pos) {
	_sprite._pos = pos;
}

D3DXVECTOR2 Camera::GetPos() {
	return _sprite._pos;
}