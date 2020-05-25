#ifndef _ADD_H
#define _ADD_H

//���������ͺ������������Թ��캯�����أ������õ�ʱ����ܻ�������

/*
1.const int x=5 �ȼ��� int const x=5
2.const int& x=y �ȼ��� int& const x=y
3.const int* x=&y ������ int* const x=&y
*/

/* 
C++�涨const int& x=5�Ϸ��Ժ�int add(int x,int y)��int add(const int& x,const int& y)�Ĺ�����ȫ��ͬ��
�������ô��ݵ�Ч�ʱ�ֵ���ݵĸߣ����ö�һ�α�������������C++���麯�����ζ�ʹ�����ô��ݡ�
*/

//

int add(int x,int y);                   //�ȼ��� int add(const int x,const int y)

int add(int* x,int* y);                 //�ȼ��� int add(int* const x,int* const y)
int add(const int* x,const int* y);     //�ȼ��� int add(const int* const x,const int* const y)

int add(int& x,int& y);                 //��VC++�������еȼ��� int add(int& const x,int& const y)����GCC��������int& const���ͱ��벻ͨ����
										//�������Ĳ����Ƿ�cosnt�����������ȵ���int&�汾��
										
int add(const int& x,const int& y);     //��VC++�������еȼ��� int add(const int& const x,const int& const y)����GCC��������const int& const���ͱ��벻ͨ����
			                            //�������Ĳ�����cosnt�����������ȵ���const int&�汾


class Test
{
public:
	void foo();
	void foo()const;
};

#endif //_ADD_H