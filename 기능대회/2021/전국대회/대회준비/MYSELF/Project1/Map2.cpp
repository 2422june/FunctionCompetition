#include "Header.h"

Map2::Map2() {
	_speed = 5.0f;
	_sprite = CSprite();

	_sprite._center = D3DXVECTOR2(512, 384);
	_sprite._rotateCen = D3DXVECTOR2(512, 384);
	_sprite._scaleCen = D3DXVECTOR2(512, 384);
	_sprite._position.x = 512;
	_sprite._position.y = -384;
}

Map2::~Map2() {
}

void Map2::Move(float speed) {
	if (_sprite._position.y >= 768 + 384) {
		_sprite._position.y = -1152;
	}
	_sprite._position.y += speed;
}

void Map2::Render() {
	_sprite.Render(_g_Asset->GetTexture("Map2"));
}

void Map2::Update(float deltaTime) {
	_sprite.Update(deltaTime);
}