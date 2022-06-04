#include "Player.h"
Player::Player() {
	x = 0;
	y = 1080;
	wide = 80;
	height = 80;
	speed = 20;
	dirCount = 0;
	inZone = true;
	lastInZone = false;
	updown = VK_SPACE;
	rightleft = VK_SPACE;
	dir = 0;
	hp = 5;
}


bool Player::AvilableDir(WPARAM dir) {
	if (dir == VK_UP && nowDir == VK_DOWN) {
		return false;
	}
	else if (dir == VK_DOWN && nowDir == VK_UP) {
		return false;
	}
	else if (dir == VK_RIGHT && nowDir == VK_LEFT) {
		return false;
	}
	else if (dir == VK_LEFT && nowDir == VK_RIGHT) {
		return false;
	}
	else {
		if (dirCount == 0) {
			x2 = x;
			y2 = y;
		}
		if (dirCount == 1) {
			x3 = x;
			y3 = y;
		}
		return true;
	}
}

void Player::KeyDown(WPARAM key) {
	if (!inZone) {
		if (dirCount < 2) {
			if (key == VK_UP || key == VK_DOWN) {
				if (updown == VK_SPACE) {
					if (AvilableDir(key)) {
						updown = key;
						dirCount++;
						nowDir = key;
					}
				}
				else if(updown != key) {
					if (AvilableDir(key)) {
						updown = key;
						dirCount++;
						nowDir = key;
					}
				}
			}
			if (key == VK_RIGHT || key == VK_LEFT) {
				if (rightleft == VK_SPACE) {
					if (AvilableDir(key)) {
						rightleft = key;
						dirCount++;
						nowDir = key;
					}
				}
				else if (rightleft != key) {
					if (AvilableDir(key)) {
						rightleft = key;
						dirCount++;
						nowDir = key;
					}
				}
			}
		}
	}
	else {
		nowDir = key;
	}
}

void Player::PlayerMove() {
	switch (nowDir) {
	case VK_UP:
		dir = 1;
		y -= speed;
		if (y < 0) {
			y = 0;
		}
		break;

	case VK_DOWN:
		dir = 2;
		y += speed;
		if (y > 1080) {
			y = 1080;
		}
		break;

	case VK_RIGHT:
		dir = 3;
		 x += speed;
		if (x > 1920) {
			x = 1920;
		}
		break;

	case VK_LEFT:
		dir = 4;
		x -= speed;
		if (x < 0) {
			x = 0;
		}
		break;
	}
}

void Player::isinZone() {
	if (inZone) {
		dirCount = 0;
		updown = VK_SPACE;
		rightleft = VK_SPACE;
		inZone = true;
		x1 = 0;
		x2 = 0;
		x3 = 0;
		y1 = 0;
		y2 = 0;
		y3 = 0;
	}
}

void Player::UpadteInZone(bool inZone2) {
	lastInZone = inZone;
	inZone = inZone2;
}

bool Player::InCommingZone() {
	if (inZone == true && lastInZone == false) {
		return true;
	}
}

void Player::ItOutGoingZone() {
	if (inZone == false && lastInZone == true) {
		if (nowDir == VK_UP || nowDir == VK_DOWN) {
			updown = nowDir;
		}
		else {
			rightleft = nowDir;
		}
		if(dirCount == 0){
			x1 = x;
			y1 = y;
		}
	}
}