#pragma once

#include <Windows.h>
#pragma comment(lib, "msimg32.lib")
#include <list>
#include <random>

CONST int WIDTH = 80;
CONST int HEIGHT = 50;
CONST int LOCX = 940;
CONST int LOCY = 980;

struct Info/*�� ��ü�� ����*/
{
	int x, y;
	int width, height;
	int speed;
};