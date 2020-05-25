#ifndef _CRYPTO_H
#define _CRYPTO_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define _DEBUG_
// #undef _DEBUG_

#define _BETTER_
// #undef _BETTER_

#ifdef _DEBUG_
#define DEBUG_FLAG printf("%s: %s line -- %d\n",__FILE__,__func__,__LINE__);
#define PRINT_INT(x) printf("%s =%d\n",#x,(x))
#define PRINT_STR(x) printf("%s =%s\n",#x,(x))
#else
#define DEBUG_FLAG
#define PRINT_INT(x)
#define PRINT_STR(x)
#endif

#define FREE(ptr)                \
	do{                          \
		if((ptr) != NULL)        \
		{                        \
			free(ptr);           \
			ptr = NULL;          \
		}                        \
	}while(0)

extern int cryptoNum(int num,int key);        //��һ�ε��ú����Ǽ��ܣ��ڶ��ε����ǽ���

#ifdef _BETTER_
extern bool cryptoStr(const char src[],char* const dts,int key);
#else
extern char* cryptoStr(const char *str,int key);       //��������ָ��Ļ���������ɳ���Ա����free
#endif

extern bool encryptStr(const char *src,char *dts,int key);
extern bool decryptStr(const char* src,char *dts,int key);

#endif //_CRYPTO_H