#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <iostream>

struct Product
{
	virtual ~Product(){};		//����Ҫд���������������������ͷ��ڴ�
	virtual void show() = 0;
};

class ProductA:public Product
{
public:	
	virtual ~ProductA(){std::cout<<"~ProductA()"<<std::endl;};
	virtual void show()
	{
		std::cout<<"I'm ProductA"<<std::endl;
	}
};

class ProductB:public Product
{
public:	
	virtual ~ProductB(){std::cout<<"~ProductB()"<<std::endl;};
	virtual void show()
	{
		std::cout<<"I'm ProductB"<<std::endl;
	}
};

class ProductC:public Product
{
public:	
	virtual ~ProductC(){std::cout<<"~ProductC()"<<std::endl;};
	virtual void show()
	{
		std::cout<<"I'm ProductC"<<std::endl;
	}
};

#endif //_PRODUCT_H