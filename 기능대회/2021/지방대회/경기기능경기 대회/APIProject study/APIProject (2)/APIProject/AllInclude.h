//그림과 헤더파일에 대한 셋팅을 하는 헤더파일



#pragma once//같은 헤더파일을 여러번 사용하겠다는 선언?
#include <Windows.h>//윈도우관련 함수가 들어있는 헤더파일
#include <list>//리스트관련 함수가 들어있는 파일



CONST int WIDTH = 80;   //적과 안군의 그림의 가로길이
CONST int HEIGHT = 50;  //적과 안군의 그림의 세로길이
CONST int LOCX = 940;   //적용대상의 x좌표
CONST int LOCY = 490;   //적과 아군의 y값(원래는 980)





//info라는 x, y, 가로, 세로, 스피드를 저장하는 전역변수 생성(즉 요놈은 함수가 아니라 변수로 친다.)
//struct: 한번에 여러개의 변수를 담을 수 있는 변수
struct Info
{
	int x, y, width, height, speed;
};