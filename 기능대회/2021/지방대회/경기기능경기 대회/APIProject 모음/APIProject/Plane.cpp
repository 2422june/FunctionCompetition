#include "Plane.h"

Plane::Plane(bool dir)// ::�� ���Ӱ� ���� �ǹ̴�
{//if��, else�� �����ڵ尡 �����̸� �߰�ȣ�� ���� �����ϴ�
//�� �Լ��� ���� �̵�
	if (dir) info.x = -200;
	else info.x = 2120;
	
	info.y = LOCY;
	info.width = WIDTH;
	info.height = HEIGHT;
	if (dir) info.speed = 5;//������
	else info.speed = -5;//����
}

void Plane::Move(bool dir, int myspeed)//�÷��̾��� �̵��� ���� ���� �̵���Ű�� �Լ�
{
	if (dir) {
		info.x -= myspeed;
	}
	else {
		info.x += myspeed;
	}
}

void Plane::Move()//���� �̵� ��Ű�� �Լ�
{
	info.x += info.speed;//�� �̵��� ���� ����
	if (info.speed > 0)
	{
		info.speed = info.speed * -1;
	}
	info.y += info.speed;
}