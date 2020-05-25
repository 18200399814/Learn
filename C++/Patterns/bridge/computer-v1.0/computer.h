#ifndef _COMPUTER_H
#define _COMPUTER_H

#include "system.h"

class Computer
{
public:
	Computer(System* system):system(system){}
	virtual ~Computer(){}
	
	void setSystem(System* system)
	{
		this->system = system;
	}
	
	virtual void installOS()
	{
		if(system != nullptr)
			system->installOS_impl();
	}
private:
	System* system;          //system����Ϊ˽�г�Ա
};

class DellComputer:public Computer
{
public:
	DellComputer(System* system):Computer(system){}
	void installOS()override
	{
		std::cout<<"Dell�������װ����ϵͳ"<<std::endl;
		Computer::installOS();
	}
};

class AppleComputer:public Computer
{
public:
	AppleComputer(System* system):Computer(system){}
	void installOS()override
	{
		std::cout<<"Apple�������װ����ϵͳ"<<std::endl;
		Computer::installOS();
	}
};

class HPComputer:public Computer
{
public:
	HPComputer(System* system):Computer(system){}
	void installOS()override
	{
		std::cout<<"HP�������װ����ϵͳ"<<std::endl;
		Computer::installOS();
	}
};

#endif //_COMPUTER_H