//�⺻���
#pragma once

//�߰� ���̺귯�� �Ӽ� �߰�
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "winmm.lib")//���� ���

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")//����� �ܼ��� ����

//a�� b�� swap
#define SWAP(a, b) a^=b^=a^=b

#define ETYPE_BOMB 0
#define ETYPE_BULLET 1


#include <vector>
#include <list>
#include <map>
#include <string>
#include <time.h>

using std::vector;
using std::list;
using std::map;
using std::string;

//�����߿�!!!
#include "d3d9.h"//���̷�Ʈ 9
#include "d3dx9core.h"//���̷�Ʈ 9 �ھ�

//-------------------------------------------------------------------------------------

#include "SingleTon.h"

#include "Application.h"
#include "Texture.h"
#include "Sprite.h"

#include "Scene.h"
#include "Loading.h"


//-------------------------------------------------------------------------
#include"Bullet.h"
#include"EnemyBullet.h"
#include "CEnemy.h"
#include "MainPage.h"
#include "Efect.h"
#include "Player.h"//�÷��̾ �����Ǳ⿡ ���Ӻ��� ���� �־����
#include"Item.h"
#include "Map1.h"
#include "Map2.h"
#include "Map3.h"
#include "Object1.h"
#include "Overlap_Manager.h"



#include "GameScene.h"//���� ���ӿ��� �ش� �Լ��� �ҷ��� �� �̱⿡ �ؿ� ��ġ�ؾ���

#include "Game.h"