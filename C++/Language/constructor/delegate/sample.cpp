#include <iostream>

#define _GCC_
// #undef _GCC_

using namespace std;

class Sample
{
public:
	Sample();
	Sample(int data);
	Sample(int data,double value);
	Sample(const Sample& other);
	
	void setData(const int data);
	int getData()const;
	
	void setValue(const double value);
	double getValue()const;
	
	void display()const;
private:
	int data;
	double value;
};

Sample::Sample()
	:Sample(0,0)                                       //ί�й���
{
	
}

#ifndef _GCC_
Sample::Sample(int data)
{
	this->Sample::Sample(data,0);                      //GCC��������֧�����ַ�ʽ��ί�й���,VC++֧��
}
#else
Sample::Sample(int data)
	:Sample(data,0)
{

}	
#endif

Sample::Sample(int data,double value)
	:data(data)
	,value(value)
{
	
}

Sample::Sample(const Sample& other)
{
	new(this) Sample(other.data,other.value);          //���Ǵ��·����ڴ棬����ֱ�Ӹ�����ԭ�ڴ��ϣ���ԭʼ�ڴ渲�ǡ�
}


void Sample::setData(const int data)
{
	this->data = data;
}

int Sample::getData()const
{
	return data;
}

void Sample::setValue(const double value)
{
	this->value = value;
}

double Sample::getValue()const
{
	return value;
}

void Sample::display()const
{
	cout<<"data ="<<data<<" ,value ="<<value<<endl;
}

int main(void)
{
	Sample sample1;
	sample1.setData(4);
	sample1.setValue(3.1415);
	sample1.display();
	cout<<endl;
	
	Sample sample2(sample1);
	sample2.display();
	
	return 0;
}