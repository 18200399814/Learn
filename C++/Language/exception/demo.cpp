#include <iostream>

using namespace std;

class Expt
{
public:
	Expt(){cout<<"Expt constructor1"<<endl;};
	Expt(const Expt& e){*this = e;cout<<"Expt constructor2"<<endl;}
	~Expt(){cout<<"Expt destructor"<<endl;};
	void show(){cout<<"����show��Ա����"<<endl;}	
};

class Demo
{
public:
	Demo(){cout<<"Demo constructor1"<<endl;}
	Demo(int n){Demo::n = n;cout<<"Demo constructor2"<<endl;}
	~Demo(){cout<<"Demo destructor"<<endl;}
private:	
	int n;
};

void fun()
{
	Demo d1;
	Demo d2(10);
	
	cout<<"�ں���fun���׳�Expt���쳣"<<endl;
	throw Expt();
}

int main()
{
	cout<<"main start"<<endl;
	
	try{
		Demo d3;
		fun();		
	}catch(Expt e){
		e.show();		//��try����м�鵽�׳��쳣�Ժ����׳��쳣��ǰ�湹��Ķ��󶼽���������
	}catch(...){
		cout<<"Ĭ�ϲ����쳣"<<endl;
	}
	
	cout<<"main end"<<endl;
	
	return 0;
}