//총알에 대한 헤더파일



#pragma once//같은 헤더파일을 여러번 사용하겠다는 선언?



#include "AllInclude.h"//그림과 헤더파일에 대한 셋팅을 하는 헤더파일



class Bullet//클레스(int, float와 같은 자료형이다, 다만 선언이 가능한 자료형) 선언
{

public:
	Bullet(int x, int y, bool dir);

public:
	void Move();


public :
	Info info;
};