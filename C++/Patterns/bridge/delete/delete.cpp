#include <iostream>

using namespace std;

class IBase
{
public:
	virtual ~IBase(){}
//	virtual void draw() = 0;
	virtual void show() = 0;
};

class Demo:public IBase
{
public:
//	void draw() = delete;   //=delete���������麯��
	void show()
	{
		cout<<"test =delete"<<endl;
	}
} ;


int main()
{
	Demo demo;
	demo.show();
	
	return 0;
}