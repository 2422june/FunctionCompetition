#pragma once

#include "AllInclude.h"

class Bullet
{
public:
	Bullet(int x, int y, int speed);
	~Bullet();

public:
	void Move();
public :
	Info info;
};