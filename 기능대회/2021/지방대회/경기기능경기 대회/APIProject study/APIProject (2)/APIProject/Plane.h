//���� �Ʊ��� �Լ��� ���� �������



#pragma once//���� ��������� ������ ����ϰڴٴ� ����?



#include "AllInclude.h"//�׸��� ������Ͽ� ���� ������ �ϴ� �������



class Plane//Ŭ����(int, float�� ���� �ڷ����̴�, �ٸ� ������ ������ �ڷ���) ����
{
public:
	Plane(bool dir);

	void Move();
	void Move(bool dir, int myspeed);//move��� �Ű��Լ�(parameter)

public :
	Info info;
};