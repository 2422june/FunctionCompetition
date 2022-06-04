#include "Header.h"

bool Overlap_Manager::Overlap(RECT* rectTarget1, RECT* rectTarget2) {

	RECT _tmp;
	//FEEDBACK// lprcDst 는 곂치는 영역을 리턴, 충돌체크만 하는 경우는 필요X (임시변수로 버림)
	if (IntersectRect(NULL, rectTarget1, rectTarget2)) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}