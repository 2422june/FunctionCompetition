#include "Header.h"

bool Overlap_Manager::Overlap(RECT* rectTarget1, RECT* rectTarget2) {

	RECT _tmp;
	//FEEDBACK// lprcDst �� ��ġ�� ������ ����, �浹üũ�� �ϴ� ���� �ʿ�X (�ӽú����� ����)
	if (IntersectRect(NULL, rectTarget1, rectTarget2)) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}