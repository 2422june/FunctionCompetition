#include "Bullet.h"


Bullet::Bullet(int x, int y, int speed) {
	info.x = x;
	info.y = y;
	info.width = 50;
	info.height = 50;
	info.speed = speed;
}

Bullet::~Bullet()
{

}

void Bullet::Move()
{
	info.y -= info.speed;
}