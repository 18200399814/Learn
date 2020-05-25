#include <iostream>

#define _ERROR_
#undef _ERROR_

using std::cout;
using std::endl;

class Base
{
public:
	Base():num(0),data(0){}
	Base(int num):num(num),data(0){}
	Base(int num,double data):Base(num){this->data = data;}            //ί�й���
	Base(const Base& other){new (this) Base(other.num,other.data);}    //ԭʼ�ڴ渲��
	
	void setNum(const int num){this->num = num;}
	int getNum()const{return num;}
	
	void setData(const double data){this->data = data;}
	double getData()const{return data;}
	
	void show()const{cout<<"num ="<<num<<" ,data ="<<data<<endl;}
private:
	int num;
	double data;
};

class Derived:public Base
{
public:
	using Base::Base;         //�̳й��캯��,������ʹ���˼̳й��캯�������������˱�����Ա���Ǹ������ӵı����������ʹ�þ͵س�ʼ��
	
	Derived(double value):Base(),value(value){}

#ifdef _ERROR_
	Derived(int num,double data,double value):Derived(num,data),value(value){}            //��Ϊί�й��캯�����Ѿ���ʼ������value������value���ܼ�����ʼ����ֻ�ܸ�ֵ
#else
	Derived(int num,double data,double value):Derived(num,data){this->value = value;}     //һ������ֻ�ܱ���ʼ��һ��
#endif
	
	void setValue(const double value){this->value = value;}
	double getValue()const{return value;}
	
	void display()const
	{
		cout<<"value ="<<value<<endl;
		show();
	}
private:
	double value = {2.71828};       //C++11�͵س�ʼ��
};

int main(int argc,char** argv)
{
	Derived derived1(10);
	derived1.display();
	cout<<endl;
	
	Derived derived2(12,18);
	derived2.show();
	derived2.display();
	
	return 0;
}