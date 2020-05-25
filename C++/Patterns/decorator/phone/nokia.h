#ifndef _NOKIA_H
#define _NOKIA_H

#include "phone.h"
#include <iostream>

class Nokia:public Phone
{
public:
	Nokia(char* name):m_name(name){}
	void show()override
	{
		std::cout<<m_name<<"��װ��"<<std::endl;
	}
private:
	char* m_name;
};

#endif //_NOKIA_H