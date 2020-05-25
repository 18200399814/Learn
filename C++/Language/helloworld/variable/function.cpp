#include <iostream>

#define Print(expr) printf("%s =%d\n",#expr,(expr))

int foo1(int x)              //�β�����ͨ�������ں����ڲ������޸ı�����С�����޸����βδ�С��Ӱ��ʵ�δ�С��
{
	x *= x;
	return x;
}

int foo2(const int x)       //�β���const�������ں����ڲ��������޸ı�����С��
{
	// x *= x;
	return x * x;
}

int bar1(int* x)            //�β���ָ�룬�ں����ڲ������޸�ָ��ָ������ݴ�С�����޸����β�ָ������ݴ�С��ʵ��ָ������ݴ�СҲ��仯��
{                            //Ҳ�����޸���ָ��ָ��ĵ�ַ�������޸����β�ָ��ָ��ĵ�ַ�Ժ����޸�ָ��ָ������ݣ�ʵ��ָ��ָ������ݽ����ᱻ�ı䡣
	*x *= *x;
	return *x;
}

int bar2(const int* x)      //�β���constָ�룬�ں����ڲ��������޸�ָ��ָ������ݴ�С�����ǿ����޸��β�ָ��ָ���ַ��
{
	// *x *= *x;
	return (*x)*(*x);
}

int qux1(int& x)            //�β������ã��ں����ڲ������޸����ñ�����С������������������ʱ��ʵ�κ��β���ͬһ���������β�ֻ��ʵ�εı�����
{
	x *= x;
	return x;
}

int qux2(const int& x)     //�β���const���ã��ں����ڲ��������޸����ñ�����С��������������const����ʱ��ʵ�κ��β���ͬһ���������β�ֻ��ʵ�εı�����
{
	// x *= x;
	return x * x;
}

#if 0
static int baz(int x);
#else
static int baz(const int x);
#endif

int main()
{
	int x = 3;
	Print(x);
	Print(foo1(x));
	Print(x);
	Print(foo2(x));
	Print(x);
	puts("");
	
	x = 4;
	Print(x);
	Print(bar1(&x));
	Print(x);
	Print(bar2(&x));
	Print(x);
	putc('\n',stdout);
	
	x = 5;
	Print(x);
	Print(qux1(x));
	Print(x);
	Print(qux2(x));
	Print(x);
	fputs("\n",stdout);
	
	x = 6;
	Print(x);
	Print(baz(x));
	
	return 0;
}

int baz(const int x)
{
	return x * x;
}