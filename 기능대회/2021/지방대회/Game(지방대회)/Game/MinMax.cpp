#include "MinMax.h"
MinMax::MinMax() {
	maxx = 0;
	maxy = 0;
	minx = 0;
	miny = 0;
 }

int MinMax::Maxx4(int x1, int x2, int x3, int x4) {
	maxx = x1;
	if (x2 > maxx) {
		maxx = x2;
	}
	if (x3 > maxx) {
		maxx = x3;
	}
	if (x4 > maxx) {
		maxx = x4;
	}
	return maxx;
}
int MinMax::Maxy4(int y1, int y2, int y3, int y4) {
	maxy = y1;
	if (y2 > maxy) {
		maxy = y2;
	}
	if (y3 > maxy) {
		maxy = y3;
	}
	if (y4 > maxy) {
		maxy = y4;
	}
	return maxy;
}


int MinMax::Minx4(int x1, int x2, int x3, int x4) {
	minx = x1;
	if (x2 < minx) {
		minx = x2;
	}
	if (x3 < minx) {
		minx = x3;
	}
	if (x4 < minx) {
		minx = x4;
	}
	return minx;
}
int MinMax::Miny4(int y1, int y2, int y3, int y4) {
	miny = y1;
	if (y2 < miny) {
		miny = y2;
	}
	if (y3 < miny) {
		miny = y3;
	}
	if (y4 < miny) {
		miny = y4;
	}
	return miny;
}


int MinMax::Maxx3(int x1, int x2, int x3) {
	maxx = x1;
	if (x2 > maxx) {
		maxx = x2;
	}
	if (x3 > maxx) {
		maxx = x3;
	}
	return maxx;
}
int MinMax::Maxy3(int y1, int y2, int y3){
	maxy = y1;
	if (y2 > maxy) {
		maxy = y2;
	}
	if (y3 > maxy) {
		maxy = y3;
	}
	return maxy;
}


int MinMax::Minx3(int x1, int x2, int x3) {
	minx = x1;
	if (x2 < minx) {
		minx = x2;
	}
	if (x3 < minx) {
		minx = x3;
	}
	return minx;
}
int MinMax::Miny3(int y1, int y2, int y3) {
	miny = y1;
	if (y2 < miny) {
		miny = y2;
	}
	if (y3 < miny) {
		miny = y3;
	}
	return miny;
}