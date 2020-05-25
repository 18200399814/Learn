#include <iostream>

using namespace std;

class Sample
{
public:
	Sample(int n,int m=0):m(m){this->n = n;}
	void setValue(/*const */int n);            //���ں����д��������ͨ��������������ʹ��const�ؼ������Σ�
	int getValue()const;                       //��Ϊ��ͨ����������һ�ֿ�����ֵ�Ĺ���,�ں������޸��ββ����޸�ʵ��ֵ
	void display();
	void display() const;
private:
	int n;
	const int m;      //const����ֻ��ͨ����ʼ���б��ʼ��
};

void Sample::setValue(/*const */int n)
{
	this->n = n;
}

int Sample::getValue()const
{
	return n;
}

void Sample::display()
{
	cout<<"display: n="<<n<<" m="<<m<<endl;
}

void Sample::display() const
{
	cout<<"const display: n="<<n<<" m="<<m<<endl;
}

int main()
{
	const Sample s(10,12);        //const��Աֻ�ܵ���const����
	
//	s.setValue(11);
	cout<<"n="<<s.getValue()<<endl;
	s.display();
	
	Sample s1(s);
	cout<<"n="<<s1.getValue()<<endl;
	s1.display();
	s1.setValue(120);
	s1.display();
	
	return 0;
}