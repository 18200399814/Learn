#include "math.h"
#include <stdio.h>

#define PRINT(expr) printf("%s= %f\n",#expr,(expr))

int main(int argc,char* argv[])
{
	PRINT(3.5+5.2);
	printf("%d + %d =%d\n",3,5,(int)add(3,5));                         //������ֻ��ʹ��%d��ӡ��������ֻ��ʹ��%f��ӡ���������ʹ�û��bug
	printf("%f + %f =%f\n",(double)3,(double)5,(double)add(3,5));      //�������������ڴ��еĴ洢��ʽ��һ�������Դ�ӡ���ʵķ�ʽҲ����ͬ��
	printf("%f + %f =%f\n",3.5,5.2,add(3.5,5.2));
	
	return 0;
}