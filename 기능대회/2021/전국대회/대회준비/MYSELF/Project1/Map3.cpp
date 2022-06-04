#include "Header.h"

Map3::Map3() {
	_speed = 5.0f;
	_sprite = CSprite();

	_sprite._center = D3DXVECTOR2(512, 384);
	_sprite._rotateCen = D3DXVECTOR2(512, 384);
	_sprite._scaleCen = D3DXVECTOR2(512, 384);
	_sprite._position.x = 512;
	_sprite._position.y = -1152;
}

Map3::~Map3() {
}

void Map3::Move(float speed) {
	if (_sprite._position.y >= 768 + 384) {
		_sprite._position.y = -1152;
	}
	_sprite._position.y += speed;
}

void Map3::Render() {
	_sprite.Render(_g_Asset->GetTexture("Map3"));
}

void Map3::Update(float deltaTime) {
	_sprite.Update(deltaTime);
}