#ifndef _PERSON_H
#define _PERSON_H

struct HPerson__
{
	int unused;
};

typedef void* handle_t;                              //ͨ�þ��
typedef struct HPerson__* HPerson;                   //Person�ṹ��ר�þ��,���ڱ��Person����

HPerson createPerson(const char name[]);
void destroyPerson(HPerson* hperson);

void setName(HPerson hperson,const char* name);
const char* getName(const HPerson hperson);           //�ڵ���getNameǰ�����ܵ���destroyPerson����

void setAge(HPerson hperson,const int age);
int getAge(const HPerson hperson);

void showPerson(const HPerson hperson);

#endif //_PERSON_H