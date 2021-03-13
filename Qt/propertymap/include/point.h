#ifndef _POINT_H
#define _POINT_H

#include <map>
#include <string>
#include <climits>   //��ȡint���͵����ֵ����Сֵ

#define INFILITY INT_MAX   //INFILITY��һ�������ϲ����ܴﵽ��ֵ������������Ϊint���͵�������32767

typedef int data_t;

const std::string point_x = "x";
const std::string point_y = "y";
const std::string point_z = "z";

class Point
{
public:
	Point();
	Point(data_t x,data_t y,data_t z);
	
	void setX(const data_t x);
	data_t getX()/* const */;
	
	void setY(const data_t y);
	data_t getY()const;
	
	void setZ(const data_t z);
	data_t getZ()const;
	
	void display()const;
private:
	std::map<std::string,data_t> m_pos;   //ʹ��һ��mapӳ�����洢��Ա���ݣ�������Ч�������ж���ĳ�Ա��������
};

#endif //_POINT_H