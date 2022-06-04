
#include "Plane.h"

int timer = 0;

Plane::Plane(bool dir)
{
	if (dir) info.x = -200;
	else info.x = 2120;
	
	info.y = LOCY;
	info.width = WIDTH;
	info.height = HEIGHT;
	if (dir) info.speed = 5;
	else info.speed = -5;
}



void Plane::Move(bool dir, int myspeed)
{
	if (dir) {
		info.x -= myspeed;
	}
	else {
		info.x += myspeed;
	}
}

void Plane::Move()
{
	info.x += info.speed;
}