//�Ѿ˿� ���� �������



#pragma once//���� ��������� ������ ����ϰڴٴ� ����?



#include "AllInclude.h"//�׸��� ������Ͽ� ���� ������ �ϴ� �������



class Bullet//Ŭ����(int, float�� ���� �ڷ����̴�, �ٸ� ������ ������ �ڷ���) ����
{

public:
	Bullet(int x, int y, bool dir);

public:
	void Move();


public :
	Info info;
};