#include <iostream>

using namespace std;

class A
{
public:
	A(int i){a = i;cout<<"A costructor"<<endl;}
	~A(){cout<<"A destructor"<<endl;}
	void display()const{cout<<"a="<<a<<endl;}
private:
	int a;
};

class B:public A
{
public:
	B(int i):A(i+1){b = i;cout<<"B costructor"<<endl;}
	~B(){cout<<"B destructor"<<endl;}
	void display()const{A::display();cout<<"b="<<b<<endl;}
private:
	int b;
};

class C:public A
{
public:
	C(int i):A(i-1){c = i;cout<<"C costructor"<<endl;}
	~C(){cout<<"C destructor"<<endl;}
	void display()const{A::display();cout<<"c="<<c<<endl;}
private:
	int c;
};

class D:public B,public C
{
public:
	D(int i):B(i+2),C(i-2){d = i;cout<<"D costructor"<<endl;}         //����̳л����˳����ø��๹�캯���������ǳ�ʼ���б��˳�����
	~D(){cout<<"D destructor"<<endl;}
	// void display()const{A::display();B::display();C::display();cout<<"d="<<d<<endl;}   //D�е���A����������
private:
	int d;
};

int main()
{
	D obj(10);
	
	obj.display();
	
	return 0;
}