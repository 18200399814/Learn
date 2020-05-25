#ifndef _DECORATORPHONE_H
#define _DECORATORPHONE_H

#include "phone.h"

class DecoratorPhone:public Phone
{
public:
	DecoratorPhone(Phone* phone):phone(phone){}
	virtual void show()override
	{
		if(phone != nullptr)
			phone->show();
	}
protected:
	Phone* phone;
};

class DecoratorPhoneA:public DecoratorPhone
{
public:
	DecoratorPhoneA(Phone* phone):DecoratorPhone(phone){}
	void show()
	{
		addDecorator();
		DecoratorPhone::show();
	}
private:
	void addDecorator()
	{
		std::cout<<"���ӹҼ�"<<std::endl;
	}
};

class DecoratorPhoneB:public DecoratorPhone
{
public:
	DecoratorPhoneB(Phone* phone):DecoratorPhone(phone){}
	void show()
	{
		addDecorator();
		DecoratorPhone::show();
	}
private:
	void addDecorator()
	{
		std::cout<<"��Ļ��Ĥ"<<std::endl;
	}
};

#endif //_DECORATORPHONE_H