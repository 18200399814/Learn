#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "shape.h"

class Circle:public Shape
{
public:
	Circle(const char* name,const int id)
	{
		if(name == nullptr || strlen(name) >= SIZE){
			throw "name is illegal!";
		}
		
		memset(m_name,0,SIZE);
		strcpy(m_name,name);
		m_id = id;
	}
	
	Circle(const Circle& circle)
	{
		memset(m_name,0,SIZE);
		strcpy(m_name,circle.m_name);
		m_id = circle.m_id;
	}
	
	Shape* clone()
	{
		return new Circle(*this);
	}
	
	void draw()
	{
		std::cout<<"this is circle"<<std::endl;
	}
};

#endif //_CIRCLE_H