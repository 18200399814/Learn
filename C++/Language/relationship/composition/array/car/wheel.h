#ifndef _WHEEL_H
#define _WHEEL_H

#include <iostream>

typedef double data_t;

class Wheel
{
public:
	Wheel(const data_t size);
	Wheel(const Wheel& other);
	
	void print()const;
private:
	data_t size;
};

Wheel::Wheel(const data_t size =0)       //Ĭ�ϲ�������д�ں�����������Ҳ��д�ں���ʵ�ִ��������������ط���д��һ�㶼д������������ۿ�
	:size(size)
{
	
}

Wheel::Wheel(const Wheel& other)
	:size(other.size)
{
	
}

void Wheel::print()const
{
	std::cout<<"wheel size ="<<size<<std::endl;
}

#endif //_WHEEL_H