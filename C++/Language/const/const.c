#include <stdio.h>

int main(int argc,char** argv)
{
	const int n;
	
//	n = 10;
//	printf("n=%d\n",n);
	
	int* p = &n;              //����C���Կ���ͨ��ָ���޸�const������ֵ
	*p = 20;
	printf("n=%d\n",n);
	
	return 0;
}