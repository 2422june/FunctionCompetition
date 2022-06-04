#include "Bullet.h"//총알에 대한 헤더파일



Bullet::Bullet(int x, int y, bool dir)
{
	info.x = x;
	info.y = y;
	info.width = WIDTH;
	info.height = HEIGHT;
	if (dir) info.speed = 15;
	else info.speed = -15;
}



void Bullet::Move()
{
	info.x += info.speed;
}