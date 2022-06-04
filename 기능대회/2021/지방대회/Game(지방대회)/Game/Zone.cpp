#include "Zone.h"

Zone::Zone(int Zx, int Zy, int Zwide, int Zheigt) {
	x = Zx;
	y = Zy;
	wide = Zwide;
	height = Zheigt;
}

bool Zone::inItZone(int px, int py) {
	if (px >= x - (wide / 2) && px <= x + (wide / 2) && py >= y - (height / 2) && py <= y + (height / 2)) {
		return true;
	}
	else {
		return false;
	}
}