#pragma once

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#define SWAP(a, b) a^=b^=a^=b

#include<vector>
#include<map>
#include<list>
#include<string>
#include<time.h>

using namespace::std;
using std::vector;
using std::map;
using std::list;
using std::string;

#include"d3d9.h"
#include"d3dx9core.h"

#include"SingleTon.h"

#include"Application.h"
#include"Texture.h"
#include"Sprite.h"

#include"Scene.h"
#include"Loading.h"
#include"Intro.h"
#include"Menu.h"

#include"Player.h"



#include"GameScene.h"

#include"Game.h"