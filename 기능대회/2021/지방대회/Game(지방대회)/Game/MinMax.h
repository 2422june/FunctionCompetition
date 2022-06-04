#pragma once
class MinMax
{
public:
	int maxx, maxy, minx, miny;
	MinMax();

	int Maxx4(int x1, int x2, int x3, int x4);
	int Maxy4(int y1, int y2, int y3, int y4);
	int Minx4(int x1, int x2, int x3, int x4);
	int Miny4(int y1, int y2, int y3, int y4);
	int Maxx3(int x1, int x2, int x3);
	int Maxy3(int y1, int y2, int y3);
	int Minx3(int x1, int x2, int x3);
	int Miny3(int y1, int y2, int y3);
};

