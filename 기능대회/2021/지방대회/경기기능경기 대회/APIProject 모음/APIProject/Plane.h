#pragma once
#include "AllInclude.h"

class Plane
{
public:

	Plane(bool dir);//생성자(생성시 딱 한번 호출되는 객체)

	void Move();
	void Move(bool dir, int myspeed);//이름이 달라도 다른 함수로 친다.(오버로드라는 객체지향 개념)

public :
	Info info;
};