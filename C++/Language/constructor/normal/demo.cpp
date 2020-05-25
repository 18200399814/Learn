#include <iostream>

using namespace std;

class B1
{
public:
	B1(){cout<<"B1 constructor"<<endl;}
	~B1(){cout<<"B1 destructor"<<endl;}
};

class B2
{
public:
	B2(){cout<<"B2 constructor"<<endl;}
	~B2(){cout<<"B2 destructor"<<endl;}
};

class B3
{
public:
	B3(){cout<<"B3 constructor"<<endl;}
	~B3(){cout<<"B3 destructor"<<endl;}
};

class A
{
public:
	A():b3(),b2(),b1(){cout<<"A constructor"<<endl;}     //��b1��b2��b3�����еĶ���˳���죬���ʼ���б��е�˳���޹�
	~A(){cout<<"A destructor"<<endl;}
private:
	B1 b1;
	B2 b2;
	B3 b3;
};

int main()
{
	A a;
}