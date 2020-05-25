#ifndef _FACADE_H
#define _FACADE_H

#include "subsystem.h"

class Facade final
{
public:
	void methodA()
	{
		std::cout<<"---������A()---"<<std::endl;
		one.methodOne();
		two.methodTwo();
	}

	void methodB()
	{
		std::cout<<"---������B()---"<<std::endl;
		three.methodThree();
		four.methodFour();
	}	
private:
	SubsystemOne one;
	SubsystemTwo two;
	SubsystemThree three;
	SubsystemFour four;
};

#endif //_FACADE_H