//ʹ��������ΪEmployee�ṹ��ľ����������Linux���ļ�������fp

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

int createEmployee(const char* name,int num);        //������Ա���󣬷��ع�Ա�ṹ����
void destroyEmployee(int handle);                    //ͨ����Ա��������ٹ�Ա����

void setName(int handle,const char* name);           //ͨ����Ա��������ù�Ա����
const char* getName(int handle);                     //ͨ����Ա�������ȡ��Ա����

void setNum(int handle,int num);
int getNum(int handle);

void showEmployee(int handle);

#endif //_EMPLOYEE_H