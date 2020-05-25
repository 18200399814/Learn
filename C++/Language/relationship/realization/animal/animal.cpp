#include <iostream>
#include <stdlib.h>

using namespace std;

#define FREE(ptr)                   \
	do{                             \
		if((ptr) != nullptr)        \
		{                           \
			delete ptr;             \
			ptr = nullptr;          \
		}                           \
	}while(0)

class Move
{
public:
	virtual ~Move(){};
	virtual void fly() = 0;
	virtual void run() = 0;
};

class Bird:public Move
{
public:
	void fly()
	{
		cout<<"bird can fly"<<endl;
	}
private:
	virtual void run()
	{
		
	}
};

class Animal:public Move
{
public:
	void run()final
	{
		cout<<"animal can run"<<endl;
	}
private:
	void fly()override
	{

	}
};

template <typename T>
static void myFree(T** pp);

static void Free(void* ptr);            // C/C++��ֻ��void*ָ�룬û��void**ָ�롣��void*ָ�벻��ʹ��delete

int main()
{
	Move* p = new Bird;
	p->fly();
	p->run();
	if(p != nullptr)
	{
		delete p;
		p = nullptr;
	}
	
	Bird* pbrid = new Bird();
	pbrid->fly();
	// pbrid->run();          //˽�г�Ա�����Ե���
	FREE(pbrid);
	
	Move* q = new Animal();
	q->fly();
	q->run();
	FREE(p);
	
	Animal* panimal = new Animal;
	// panimal->fly();        //˽�г�Ա�����Ե���
	panimal->run();
	Free(panimal);
	
	return 0;
}

template <typename T>
void myFree(T** pp)
{
	if(*pp != nullptr)
	{
		delete *pp;
		*pp = nullptr;
	}
}

void Free(void* ptr)
{
	if(ptr != nullptr)
	{
		free(ptr);
		// ptr = nullptr;            //��Ϊ���ݵ�Ϊvoid*ָ�룬����Ϊptr��nullptrû������
	}
}