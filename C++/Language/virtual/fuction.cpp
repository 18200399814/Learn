#include <iostream>

using namespace std;

class Base
{
public:
	virtual void fun(int a)
	{
		cout<<"class Base: fun "<<a<<endl;
	}
	
	virtual void foo(int x)
	{
		cout<<"class Base: foo "<<x<<endl;
	}
};

class SubClass:public Base
{
public:
	void fun(int a)
	{
		cout<<"class SubClass: fun "<<a<<endl;
	}
	
	void foo(double x)
	{
		cout<<"class SubClass: foo "<<x<<endl;
	}
	
	void bar()
	{
		foo(2.71828);      //�������า�ǵ�foo()�麯��������������ȵ����Լ�ʵ�ֵĺ���
		Base::foo(5);      //�������ͨ��::����������ʵ������б������˵�foo()�麯��
		cout<<"class SubClass: bar"<<endl;
	}
};

int main()
{
	Base a,*p = &a;
	SubClass b;
	
	(*p).fun(1);
	p->foo(1);
	
	p = &b;
	(*p).fun(2);
	p->foo(2);
	p->foo(3.1415);
	
	b.Base::foo(1.414);   //����������ͨ��::����������ʸ���������public�����������������˵��麯��
	b.foo(3.1415);
	b.bar();
}