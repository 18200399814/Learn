#ifndef _DOOR_H
#define _DOOR_H

#include <iostream>
#include <string.h>

using namespace std;

class Door
{
public:
	Door(const string& color = "black");       //Ĭ�ϲ�������д�ں�����������Ҳ��д�ں���ʵ�ִ��������������ط���д��һ�㶼д������������ۿ�
	Door(const Door& other);
	
	void display()const;
private:
	string color;
};

Door::Door(const string& color)
	:color(color)
{
	
}

Door::Door(const Door& other)
	:color(other.color)
{
	
}

void Door::display()const
{
	cout<<"door color ="<<color<<endl;
}

#endif //_DOOR_H