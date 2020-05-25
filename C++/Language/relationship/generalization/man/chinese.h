#ifndef _CHINESE_H
#define _CHINESE_H

#include "man.h"

class Chinese:public Man
{
public:
	Chinese(const std::string name):Man(name){};
	Chinese(const Chinese& other):Man(other){};
	
	void sayHello()
	{
		std::cout<<"�й��� "<<name<<": ˵����"<<std::endl;
	}
};

#endif //_CHINESE_H