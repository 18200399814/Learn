#include <stdio.h>

#define ERROE
#undef ERROE

#define _GCC_
#undef _GCC_

#define PRINT(expr) printf("%s =%d\n",#expr,(expr))

static void variable_test();
static void pointer_test();
static void reference_test();
static void volatile_test();

int main(int argc,char** argv)
{
	variable_test();
	pointer_test();
	reference_test();
	volatile_test();
	
	return 0;
}

void variable_test()
{
	puts("variable_test()");
	
	int x = 10;                   //��ͨ����
	const int y = 20;             //const���Ʊ�����ֵ���ɸı䡣const int��Ч��int const
	int const z = 30;
#ifdef ERROE
	y = 40;
	z = 50;
#endif
	PRINT(x);
	PRINT(y);
	PRINT(z);
}

static void pointer_test()
{
	fputs("pointer_test()\n",stdout);
	int a=0,b=0;
	
	int *p = &a;          //��ָͨ��
	const int *q = &a;    //ָ��ָ���������const int���ͣ���ָ��ָ�򲻿��޸ĵ����ͱ�����ָ��ָ������ݲ������޸ģ�����ָ���ָ������޸ġ�
	int const *r = &a;    //const int*��Ч��int const*     
	int* const s = &a;    //constָ��ָ���������int���ͣ��������޸ĵ�ָ��ָ�����ͱ�����ָ��ָ������ݿ����޸ġ�����ָ���ָ�򲻿����޸ġ�
	const int* const t = &a;   //constָ��ָ���������const int���͡��������޸ĵ�ָ��ָ�򲻿��޸ĵ����ͱ�����ָ��ָ������ݺͷ��򶼲������޸ġ�
#ifdef ERROE
	*q = 1;
	*r = 2;
	*s = &b;
	*t = 3;
	t = &b;
#endif
	PRINT(*q);
	PRINT(*r);
	PRINT(*s);
	PRINT(*t);
}

void reference_test()
{
	printf("reference_test()\n");
	int x=0,y=0;
	
	int &a = x;              //��ͨ����
	const int& b = x;        //���ð󶨵ı���ʱconst int���ͣ������ò����޸ı���������
	int const& c = x;        //��VC++��int&��int const&��const int& const���ߵ�Ч��GCC�в�֧��int const&��const int& const���������͵�����
#ifndef _GCC_
	int& const d = x;        //int&��int& const��Ч�����ð󶨵�ĳ�������ϣ������Ͳ������޸�ʹ��󶨵����������ϡ���constֻ�Ƕ��һ�٣�GCC��ֱ�Ӳ�֧�������������͡�
	const int& const e = x;
#endif

#ifdef ERROE
	b = 1;
	c = 2;
	e = 3;
#endif
	PRINT(b);
	PRINT(c);
	
	PRINT(d);
	PRINT(e);
}

static void volatile_test()
{
	const int n = 5;
	
//	n = 10;                          //const�����Ĵ�С������ֱ���޸�
//	printf("n=%d\n",n);
	
	int* p = (int*)&n;               //C++���Բ���ͨ��ָ���޸�const������ֵ��C���Կ���
	*p = 20;
	printf("n =%d\n",n);
	
	volatile const int m = 7;
	
	int* q = (int*)&m;               //C++���Կ���ͨ��ָ���޸�volatile const������ֵ
	*q = 14;
	printf("m =%d\n",m);	
}