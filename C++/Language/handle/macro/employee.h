#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include "handle.h"

DECLARE_HANDLE(HEmployee);

HEmployee createEmployee(const char* name,int num);            //������Ա���󣬷��ع�Ա�ṹ����
void destroyEmployee(HEmployee *hemployee);                    //ͨ����Ա��������ٹ�Ա����

void setName(HEmployee hemployee,const char* name);            //ͨ����Ա��������ù�Ա����
const char* getName(HEmployee hemployee);                      //ͨ����Ա�������ȡ��Ա����

void setNum(HEmployee hemployee,int num);
int getNum(HEmployee hemployee);

void showEmployee(HEmployee hemployee);

#endif //_EMPLOYEE_H