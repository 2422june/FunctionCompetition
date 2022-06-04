#pragma once
#include<Windows.h>
#include<random>

class Nagative2
{
public:
	int x, y, dirx, diry, wide, height, sign;
	Nagative2();

	void MoveNagative();
	bool InPlayer(int px, int py);
	void dir();
};