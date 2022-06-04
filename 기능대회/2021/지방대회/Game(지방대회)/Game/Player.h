#pragma once
#include<Windows.h>

class Player
{
public:

	int x, y, wide, height, speed, dirCount, dir, hp;
	int x1, x2, x3, y1, y2, y3;
	bool inZone, lastInZone;
	WPARAM updown, rightleft, nowDir;

	Player();

	void KeyDown(WPARAM key);
	bool AvilableDir(WPARAM dir);
	void PlayerMove();
	void isinZone();
	void UpadteInZone(bool inZone2);
	bool InCommingZone();
	void ItOutGoingZone();
};

