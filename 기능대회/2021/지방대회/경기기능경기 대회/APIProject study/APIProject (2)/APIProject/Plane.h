//적과 아군의 함선에 대한 헤더파일



#pragma once//같은 헤더파일을 여러번 사용하겠다는 선언?



#include "AllInclude.h"//그림과 헤더파일에 대한 셋팅을 하는 헤더파일



class Plane//클레스(int, float와 같은 자료형이다, 다만 선언이 가능한 자료형) 선언
{
public:
	Plane(bool dir);

	void Move();
	void Move(bool dir, int myspeed);//move라는 매개함수(parameter)

public :
	Info info;
};