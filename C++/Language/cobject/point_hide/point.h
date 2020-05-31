#ifndef _POINT_H
#define _POINT_H

struct Private_Data;                             //ǰ������Private_Data�ṹ��
typedef struct Private_Data Private_Data;

typedef int data_t;

typedef struct
{
	data_t z;
	Private_Data* private_data;                  //����ΪPrivate_Data*ָ�����ͣ�Ŀ����ʵ��˽�����ݵ�����
}Point;

Point* Point_Ctor(const data_t x,const data_t y,const data_t z);
void Point_Dtor(Point **pppoint);

void setX(Point *ppoint,const data_t x);
data_t getX(const Point *ppoint);

void setY(Point *ppoint,const data_t y);
data_t getY(const Point *ppoint);

void setZ(Point *ppoint,const data_t Z);
data_t getZ(const Point *ppoint);

void setXYZ(Point *ppoint,const data_t x,const data_t y,const data_t Z);
void display(const Point *ppoint);

#endif //_POINT_H