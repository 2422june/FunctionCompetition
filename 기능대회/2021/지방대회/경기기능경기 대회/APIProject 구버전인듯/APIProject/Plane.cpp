
#include "Plane.h"

Plane::Plane(int x, int y, int speed)
{
	info.x = x;
	info.y = y;
	info.width = 50;
	info.height = 50;
	info.speed = speed;
}

Plane::Plane(bool dir, int speed)
{
	if (dir) info.x = -200;
	else info.x = 2120;
	
	info.y = 200;
	info.width = 50;
	info.height = 50;
	info.speed = speed;
}

Plane::~Plane()
{

}

void Plane::Move(int dir)
{
	info.x += dir * info.speed;

	if (info.x < 0) {
		info.x = 0;
	}
	else if (info.x > 1870) {
		info.x = 1870;
	}
}

void Plane::Move()
{
	if (info.speed < 0) {
		info.x += info.speed * info.speed;
		info.y -= info.speed;
	}
	else {
		info.x -= info.speed * info.speed;
		info.y += info.speed;
	}
}
