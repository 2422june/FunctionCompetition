#include"Header.h"

Map1::Map1() {
	_speed = 5.0f;
	_sprite = CSprite();

	_sprite._center = D3DXVECTOR2(512, 384);
	_sprite._rotateCen = D3DXVECTOR2(512, 384);
	_sprite._scaleCen = D3DXVECTOR2(512, 384);
	_sprite._position = D3DXVECTOR2(512, 384);
}

Map1::~Map1() {
}

void Map1::Move(float speed) {
	if (_sprite._position.y >= 768 + 384) {
		_sprite._position.y = -1152;
	}
	_sprite._position.y += speed;
}

void Map1::Render() {
	_sprite.Render(_g_Asset->GetTexture("Map1"));
}

void Map1::Update(float deltaTime) {
	_sprite.Update(deltaTime);
}