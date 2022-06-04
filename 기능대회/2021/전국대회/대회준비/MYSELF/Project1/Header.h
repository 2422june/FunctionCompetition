//기본헤더
#pragma once

//추가 라이브러리 속성 추가
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "winmm.lib")//사운드 출력

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")//디버그 콘솔을 띄운다

//a와 b를 swap
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

//순서중요!!!
#include "d3d9.h"//다이렉트 9
#include "d3dx9core.h"//다이렉트 9 코어

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
#include "Player.h"//플레이어가 참조되기에 게임보다 위에 있어야함
#include"Item.h"
#include "Map1.h"
#include "Map2.h"
#include "Map3.h"
#include "Object1.h"
#include "Overlap_Manager.h"



#include "GameScene.h"//씬과 게임에서 해당 함수를 불러올 것 이기에 밑에 배치해야함

#include "Game.h"