#include "direction.h"

int main()
{
#if 1
	Direction dir1 = TOP_LEFT;
#else
	Direction dir1 = UP|LEFT;
#endif
	
	isDirection(dir1,UP);
	showDirection(dir1);
	
	dir1 = dir1 | RIGHT;    // | ����Ĵ򿪱�־����
	dir1 = dir1 ^ LEFT;     
	dir1 |= DOWN;
	dir1 &= ~UP;            // & ����Ĺرձ�־λ����
	
	printf("dir1 contains left: %d\n",isDirection(dir1,LEFT));
	showDirection(dir1);
	
	dir1 = dir1 ^ LEFT;     // ^ ������л���־λ����
	showDirection(dir1);
	
	return 0;
}