#include "math.h"
#include <stdio.h>

#ifdef _TRACK_
#define Print(expr) printf("%s =%d\n",#expr,(expr))
#else
#define Print(expr)
#endif

int main(int argc,char **argv)
{
	double x = 3;                //����C89��׼Ҫ�����еı����������ں����Ŀ�ͷ��C99�������������λ�ö������
	double y = 4;
	double ret = 0;
	
	Print(1 + 2);
	
	printf("%f + %f =%f\n",x,y,Operater(x,y,add));
	
	OPERATER(x,-,y,ret);
	printf("%f - %f =%f\n",x,y,ret);
	
	return 0;
}