/*���pro�ļ���û�����INCLUDEPATH += $$PWD/include��䣬��ôԴ�ļ��о͵������ͷ�ļ���
 *ȫ·����#include "../include/mymath.h"����Ȼ�ͻ��ڱ���Դ�ļ�ʱ��ʾ�Ҳ���ͷ�ļ�����
 */
 
#include "mymath.h"
#include <stdio.h>

static int add(int x,int y)
{
	printf("add: %d + %d = %d\n",x,y,x + y);
	return x + y;
}

static int sub(int x,int y)
{
	printf("sub: %d - %d = %d\n",x,y,x - y);
	return x - y;
}

//_SUB_��һ�����嵽pro�ļ��еĺ꣬������������ʹ��gcc/g++�������C/C++Դ�ļ�ʱָ���ꡣ
int operate(int x,int y)
{
#ifndef _SUB_
	puts("operate is add");
	return add(x,y);
#else
	fputs("operate is sub\n",stdout);
	return sub(x,y);
#endif
}