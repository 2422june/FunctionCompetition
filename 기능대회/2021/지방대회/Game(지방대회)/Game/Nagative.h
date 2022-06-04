#pragma once
#include<Windows.h>
#include<random>

class Nagative
{
public:
	int x, y, dirx, diry, wide, height, sign;
	Nagative();

	void MoveNagative();
	bool InPlayer(int px, int py);
	void dir();
};