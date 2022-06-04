#pragma once

//이런식으로 짜지 마라 이런건 속성이다.

#define ALLCEN(_a, _x, _y) _a._scaleCen=D3DXVECTOR2(_x,_y);_a._rotateCen=D3DXVECTOR2(_x,_y);_a._center=D3DXVECTOR2(_x,_y);
#define PX Single::GetInstance()->playerX
#define PY Single::GetInstance()->playerY
#define INTIME(a, b) if((_gameTime>a)&(_gameTime<b))
#define SCORE Single::GetInstance()->gameScore

#pragma warning(disable:4996)
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "winmm.lib")

#include <Windows.h>
#include <mmsystem.h>
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

#include "CUI.h"
#include "CCutScene.h"

#include "CMap.h"

#include "CEffect.h"
#include "CItem.h"
#include "CMissile.h"
#include "CBullet.h"
#include "CBoss.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CNum.h"

#include "Scene.h"
#include "CIntro.h"
#include "EndScene.h"
#include "CBlack.h"
#include "CTitleScene.h"
#include "CHowPlayScene.h"
#include "CRankScene.h"
#include "CFirstScene.h"
#include "CSecondScene.h"
#include "CRankShowScene.h"

#include "Game.h"