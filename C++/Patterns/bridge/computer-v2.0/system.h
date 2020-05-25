#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <iostream>

class System
{
public:
	virtual ~System(){}
	virtual void installOS_impl() = 0;
};

class Windows:public System
{
public:
	virtual void installOS_impl()
	{
		std::cout<<"��װWindow����ϵͳ"<<std::endl;
	}
};

class Linux:public System
{
public:
	virtual void installOS_impl()
	{
		std::cout<<"��װLinux����ϵͳ"<<std::endl;
	}
};

class Unix:public System
{
public:
	virtual void installOS_impl()
	{
		std::cout<<"��װUnix����ϵͳ"<<std::endl;
	}
};

#endif //_SYSTEM_H