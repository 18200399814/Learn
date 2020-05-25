#ifndef _SIMPLIFY_H
#define _SIMPLIFY_H

#include "math.h"

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

typedef int data_t;

typedef double (*pFun)(double,double);

typedef struct Message_t
{
	Option opt;
	pFun pfun;
}Message;

const Message messageMap[] = 
{
	{ADD,add},
	{SUB,sub},
	{MULT,mult},
	{'x',mult},
	{DIVI,divi},
	{MAX,max},
	{MIN,min}
};

const int messageMap_size = sizeof(messageMap)/sizeof(Message);

//if else����е�else��֧���󲿷ֶ�����ͨ��ʹ��return��break��continue�ȿ�������滻
void use_else(data_t value);            //����ȥ��else�����
void use_return(data_t value);          //ʹ��return��䣬ȥ��else
void use_break(data_t value);           //ʹ��break��䣬ȥ��else
void use_continue(data_t value);        //ʹ��continue��䣬ȥ��else

data_t use_switch(data_t x,data_t y, Option opt);        //ʹ��switch������if else
data_t use_operator(data_t value);                       //ʹ����Ŀ�������ȥ��else

void front(data_t value,data_t *num);                    //ʹ�ý�else�е����ǰ�ã�ȥ��else
void merge(data_t value,data_t num);                     //ʹ�úϲ�if�жϵķ�����ȥ��else

void tableDriven(data_t x,data_t y, Option opt);                     //ʹ�������������/���������/ӳ�䷽����ȥ��else

#ifndef _CHANGE_WAY_
void strategyPattern(data_t x,data_t y, Option opt);                 //ʹ�ò���ģʽ����Ϊֻ��C++�����������C���Բ����ԡ�����ֻ��C++����ʹ�ò���ģʽ
#else
void strategyPattern(data_t x,data_t y, pFun pfun); 	             //C���Կ���ʹ�ûص�����ģ�����ģʽ�������Ǹ�if else��֧��ѡ��Ȩ����ǰ�����ͻ���ȥѡ��
#endif

void stateMachine(data_t value);                                     //ʹ��״̬����ȥ��else

#endif //_SIMPLIFY_H