#include "Plane.h"

Plane::Plane(bool dir)// ::는 종속과 같은 의미다
{//if던, else던 실행코드가 한줄이면 중괄호는 생략 가능하다
//적 함선에 대한 이동
	if (dir) info.x = -200;
	else info.x = 2120;
	
	info.y = LOCY;
	info.width = WIDTH;
	info.height = HEIGHT;
	if (dir) info.speed = 5;//오른쪽
	else info.speed = -5;//왼쪽
}

void Plane::Move(bool dir, int myspeed)//플레이어의 이동에 따라 적을 이동시키는 함수
{
	if (dir) {
		info.x -= myspeed;
	}
	else {
		info.x += myspeed;
	}
}

void Plane::Move()//적을 이동 시키는 함수
{
	info.x += info.speed;//적 이동에 대한 설정
	if (info.speed > 0)
	{
		info.speed = info.speed * -1;
	}
	info.y += info.speed;
}