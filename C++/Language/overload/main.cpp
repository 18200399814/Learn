#include "add.h"
#include <stdio.h>

#define ERROR
#undef ERROR

#define PRINT(expr) printf("%s =%d\n",#expr,(expr))

int main(int argc,char* argv[])
{
	int x = 3;
	int y = 4;

#ifdef ERROR
	int& z = 5;           //�����Ǳ����ı���������ֻ�б����������ã�����û������
#else
	const int& z = 5;     //C++�涨const���ÿ���ֱ�����ó������������ð󶨳���ʱ�����½�һ����ʱ����temp�������ð󶨵�ʵ�����������ʱ������
                          //const int& z=5 <--> int temp =5; const int& z=temp��������������涨������C++�����ô��ݿ�����ȫ���ֵ���ݡ�
#endif

	// PRINT(add(3,4));   //�����壬���Ե���int add(int,int) �� int add(const int&,const int&)
	// PRINT(add(x,y));   //�����壬���Ե���int add(int,int) �� int add(int&,int&)
	
	Test test1;
	test1.foo();
	
	const Test test2;
	test2.foo();
	
	return 0;
}