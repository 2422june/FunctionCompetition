#pragma once
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "winmm.lib")
#pragma warning(disable:4996)

#define PlayX Single::GetInstance()->PlayerX
#define PlayY Single::GetInstance()->PlayerY
#define InTime(a, b) (gameTimer >= a)&(gameTimer <= b)

#include <Windows.h>
#include <vector>
#include <list>

using namespace std;
using std::vector;
using std::list;

#include "d3d9.h"
#include "d3dx9core.h"

#include "SingleTon.h"
#include "Application.h"

#include "Texture.h"
#include "Sprite.h"

#include "Map.h"
#include "UI.h"
#include "Num.h"
#include "Effect.h"

#include "Item.h"
#include "Bullet.h"
#include "Bomb.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"

#include "Scene.h"
#include "Black.h"
#include "IntroScene.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "NextScene.h"
#include "CEndScene.h"

#include "Game.h"