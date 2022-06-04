#pragma once
#include "AllInclude.h"

class Plane
{
public:
	Plane(int x, int y, int speed);

	Plane(bool dir, int speed);
	~Plane();

	void Move(int dir);
	void Move();
	void Attack();

public :
	Info info;
};