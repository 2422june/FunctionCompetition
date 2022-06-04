#include "Header.h"

Stage1::Stage1(int _stage) {
	_enemys.clear();
	switch (_stage) {
	case 1:
		break;
	}
}

Stage1::~Stage1() {

}

void Stage1::Peathon1() {
	//x, y, sec
	float set[10][3];
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 3; j++) {
			set[i][j] = 0;
		}
	}

	set[0][0] = 80;
}

void Stage1::Update(float deltaTime) {

}