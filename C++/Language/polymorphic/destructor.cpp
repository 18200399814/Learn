#include <iostream>

using namespace std;

class Base
{
public:
	Base(){cout<<"Base constructor"<<endl;}
	/*virtual*/ ~Base(){cout<<"Base destructor"<<endl;}   //��������������ʵ�ֵ������������Ķ�̬����
};

class Demo:public Base
{
public:
	Demo(int i){buf = new char[i];cout<<"Demo constructor"<<endl;}
	/*virtual*/ ~Demo(){delete [] buf;cout<<"Demo destructor"<<endl;}
private:
	char* buf;
};

void destroy(Base *p)
{
	if(p != NULL)
		delete p;
}

int main()
{
	Base *p = new Demo(8);
	destroy(p);
	
	p = new Demo(16);
	delete p;
	
	return 0;
}