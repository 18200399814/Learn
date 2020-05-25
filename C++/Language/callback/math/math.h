#ifndef _MATH_H
#define _MATH_H

#define EPS 0.000001

typedef enum BOOL
{
	FALSE,
	TRUE
}BOOL;

typedef double (*pFun)(double x,double y);

double calculate(double x,double y,pFun pfun);
double process(double x,double y,pFun pfun);      //process��calculate��ʵ����ȫһģһ����ֻ��Ϊ��������������󵼶�����дһ������

double add(double x,double y);
double sub(double x,double y);
double mult(double x,double y);
double divi(double x,double y);
double max(double x,double y);
double min(double x,double y);

#endif //_MATH_H