#pragma once
#include "AllInclude.h"

class Plane
{
public:

	Plane(bool dir);//������(������ �� �ѹ� ȣ��Ǵ� ��ü)

	void Move();
	void Move(bool dir, int myspeed);//�̸��� �޶� �ٸ� �Լ��� ģ��.(�����ε��� ��ü���� ����)

public :
	Info info;
};