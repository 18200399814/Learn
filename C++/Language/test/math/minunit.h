//һ��minunit����������һ��û�в����б���ͨ�����Ժ󷵻�0��NULL���ĺ�����
//�������ʧ�ܣ��������Ӧ�÷���һ������ʧ�ܵ������ַ�����

#ifndef _MINUNIT_H
#define _MINUNIT_H

#include <stdio.h>

#define PRINT(expr) printf("%s =%d\n",#expr,expr)

#define mu_assert(message,test_expr)                \
	do{                                             \
		if(!(test_expr))                            \
		{                                           \
			return message;                         \
		}                                           \
	}while(0)
		
#define mu_run_test(test_case)                      \
	do{                                             \
		char* message = test_case();                \
		tests_run++;                                \
		                                            \
		if(message != NULL)                         \
		{                                           \
			return message;                         \
		}                                           \
	}while(0)

extern int tests_run;

#endif //_MINUNIT_H