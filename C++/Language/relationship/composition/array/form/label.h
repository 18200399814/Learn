#ifndef _LABEL_H
#define _LABEL_H

#include <iostream>

typedef int data_t;

//C�����нṹ��Ҳ����ͨ����=����ֵ����Ч����ͬ��C++�е�ǳ������
typedef struct Position     //C��C++�нṹ�����û��ʵ��Ĭ�ϵĿ������캯���Ļ�����Ĭ������һ��ǳ�������캯����
{
	data_t x;
	data_t y;
}Pos_t;

class Label
{
public:
	explicit Label(const Pos_t& pos);   //ֻ��һ�������Ĺ��캯���Żᷢ��Ĭ��ת������������Ĺ��캯�����ᷢ��Ĭ��ת��
	Label(data_t x,data_t y);           //ֻ��һ�������Ĺ��캯������Ҫ��explicit���ж�������Ĺ��캯������Ҫ��explicit
	Label(const Label& other);
	
	void setX(const data_t& x);
	data_t getX()const;
	
	void setY(const data_t& y);
	data_t getY()const;
	
	void setPos(const Pos_t& pos);
	Pos_t getPos()const;
	
	void display()const;
private:
	Pos_t pos;
};

Label::Label(const Pos_t& pos)
	:pos(pos)
{
	
}

Label::Label(data_t x,data_t y)
	:pos{x,y}
{
	
}
Label::Label(const Label& other)
	:pos(other.pos)
{
	
}

void Label::setX(const data_t& x)
{
	pos.x = x;
}

data_t Label::getX()const
{
	return pos.x;
}

void Label::setY(const data_t& y)
{
	pos.y = y;
}

data_t Label::getY()const
{
	return pos.y;
}

void Label::setPos(const Pos_t& pos)
{
	this->pos = pos;
}

Pos_t Label::getPos()const
{
	return pos;
}

void Label::display()const
{
	std::cout<<"("<<pos.x<<","<<pos.y<<")"<<std::endl;
}

#endif //_LABEL_H