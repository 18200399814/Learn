#include "foobar.h"
#include <stdio.h>

extern int var;
extern const double pi;      //extern����ȫ�ֱ���piΪconst double���������piҲӦ����const double����

static void baz()
{
	extern int num;
	extern const double e;
	printf("call fun(): num =%d, e =%f\n",num,e);
}

static void qux();

int num = 10;
const double e = 2.718281;

int main(void)
{
	foo();
	bar();
	baz();
	qux();
	return 0;
}

void qux()
{
	printf("call qux(): var =%d, pi =%f\n",var,pi);
}