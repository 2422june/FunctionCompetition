#include "Nagative.h"


Nagative::Nagative() {
	x = -1;
	y = -1;
	dirx = 0;
	diry = 0;
	wide = 150;
	height = 150;
	sign = 0;
}

void Nagative::MoveNagative() {
	x += dirx;
	y += diry;
	if (x > 1920 || x < 0 || y > 1080 || y < 0) {
		dir();
	}
}
bool Nagative::InPlayer(int px, int py) {
	if (px >= x - (wide / 2) && px <= x + (wide / 2) && py >= y - (height / 2) && py <= y + (height / 2)) {
		return true;
	}
	else {
		return false;
	}
}

void Nagative::dir() {
	dirx = rand() % 31;
	diry = rand() % 31;
	if (x > 1920) {
		dirx *= -1;
	}
	if (x < 1920 && x > 0) {
		sign = 1 + (rand() % 2);
		if (sign == 1) {
			dirx *= -1;
		}
	}
	if (y > 1080) {
		diry *= -1;
	}
	if (y > 0 && y < 1080) {
		sign = 1 + (rand() % 2);
		if (sign == 1) {
			diry *= -1;
		}
	}

}