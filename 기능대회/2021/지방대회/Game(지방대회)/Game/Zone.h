#pragma once
class Zone
{
public:
	int x, y, wide, height;
	Zone(int Zx, int Zy, int Zwide, int Zheight);
	bool inItZone(int px, int py);
};