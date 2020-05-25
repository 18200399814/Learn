#ifndef _POINT_H
#define _POINT_H

struct Point;                     //ǰ������Point�ṹ�壬��Դ�ļ��ж���Point�ṹ�壬�ѵ�������Point�ṹ��ʵ�ֵ�Ŀ��

typedef int data_t;
typedef struct Point Point;

Point* point_ctor(data_t x,data_t y);        //����Point���󣬲�����Pointָ�룬��Point���
void point_dtor(Point** pppoint);            //����Point���ȥ����Point����

void setX(Point* ppoint,const data_t x);
data_t getX(const Point* ppoint);

void setY(Point* ppoint,const data_t y);
data_t getY(const Point* ppoint);

void display(const Point* ppoint);

#endif //_POINT_H