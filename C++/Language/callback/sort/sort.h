//C�����к�ͻص�������ʵ�������ܵ�������Ҫ��������ܻ�⿪������Ա���뾫ͨ�����ּ�����
//������һ���Ӧ�ó��򿪷���Ա��˵���Ժ�ͻص�������ʹ��Ҫ��û����ô�ߡ�

//C++�п��������ܵļ����кꡢ�ص������Ͷ�̬��

#ifndef _SORT_H
#define _SORT_H

#define FALSE 0
#define TRUE 1
typedef char BOOL;

typedef BOOL (*pFun)(int x,int y);

BOOL ascend(const int x,const int y);         //��������
BOOL descend(const int x,const int y);        //��������

extern void sort(int arr[],int size,const pFun pfun);
extern void display(const int arr[],const int size);

#endif //_SORT_H