#ifndef _FRENCH_H
#define _FRENCH_H

#include "man.h"

class French:public Man
{
public:
	French(const std::string name):Man(name){};
	French(const French& other):Man(other){};
	
	virtual void sayHello()
	{
		std::cout<<"������ "<<name<<": ˵����"<<std::endl;
	}
};

#endif //_FRENCH_H