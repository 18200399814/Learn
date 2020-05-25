/*C++��֮���ʵ�ֹ�ϵ�뷺����ϵ���ƣ�����ͨ���̳�ʵ�ֵġ�
 *�̳��Գ�����Ϊʵ�ֹ�ϵ���̳�����ͨ��Ϊ������ϵ��
 */

#include <iostream>

using namespace std;

class Base
{
public:
	virtual ~Base(){};
	virtual void show() = 0;
};

class SubClass:public Base
{
public:
	void show()override
	{
		cout<<"SubClass show()"<<endl;
	}
};

class Interface
{
public:
	virtual ~Interface() = default;
	virtual void doWork() = 0;
};

class Implement:public Interface
{
public:
	void doWork()
	{
		cout<<"Implement doWork"<<endl;
	}
};

int main()
{
	Base *p = new SubClass;
	p->show();
	if(p != nullptr)
	{
		delete p;
		p = nullptr;
	}
	
	Interface* q = new Implement();
	q->doWork();
	if(q != nullptr)
	{
		delete q;
		q = nullptr;
	}
	
	return 0;
}