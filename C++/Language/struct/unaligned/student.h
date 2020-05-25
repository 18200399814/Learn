#ifndef _STUDENT_H
#define _STUDENT_H

#include <stddef.h>             //offsetof�������stddef.hͷ�ļ���

#define NAME_SIZE 128
#define ADDRESS_SIZE 256
#define TELEPHONE_SIZE 32

#define GIRL 0
#define BOY 1
typedef char Sex;

#define STUDENT_SIZE sizeof(struct Student)

//��Ϊstudent���Ͳ����ֽڶ���ģ�����ֻ��ת��Ϊ�ַ�������
typedef struct Student
{
	int num;                        //ѧ��
	char name[NAME_SIZE];           //����
	Sex sex;                        //�Ա�
	char age;                       //����
	double score;                   //����
	char addr[ADDRESS_SIZE];        //��ַ
	char tel[TELEPHONE_SIZE];       //�绰
}Student;

typedef enum Student_t
{
	NUM,
	NAME,
	SEX,
	AGE,
	SCORE,
	ADDRESS,
	TELEPHONE,
	PROPERTY_COUNT
}Student_t;

extern const int offsetArr[PROPERTY_COUNT];

void showStudent(const Student student);
void showArray(const char arr[],int size);

void studentToArray(const Student student,char* arr,int arrSize);
void arrayToStudent(const char* arr,int arrSize,Student* student);

//����������ͬ��������memcpy����
void structToArray(void* arr,const void* pstruct,int size);
void arrayToStruct(void* pstruct,const void* arr,int size);

#endif //_STUDENT_H