//C�����к�ͻص�������ʵ�������ܵ�������Ҫ��������ܻ�⿪������Ա���뾫ͨ�����ּ�����
//������һ���Ӧ�ó��򿪷���Ա��˵���Ժ�ͻص�������ʹ��Ҫ��û����ô�ߡ�

//C++�п��������ܵļ����кꡢ�ص������Ͷ�̬��

#ifndef _MACRO_UTILS_H
#define _MACRO_UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define NULL_PTR ((void*)0)

//��һ���������ĳһ����������#��##����ʱ���������ʹ�õ㲢���ᱻ�滻Ϊչ������ı�
#define Conn(x,y) (x##y)           //##���Ӳ�������Gcc�������в�����ʹ��##�����ַ���������VC++����������
#define CONN(x,y) Conn(x,y)        //����x,yչ����Ľ����������

#define LinkStr(x,y) x y           //Gcc��VC++������ʹ�����ַ�ʽ�����ַ���

/*
#define ToChar(x) (#@x)            //#@�ַ�����������#@���Ǳ�׼C֧�ֵ��﷨��Gcc��������֧��,VC++������֧��
#define TOCHAR(x) ToChar(x)        //����xչ����Ľ��ת��Ϊ�ַ�
*/

#define ToString(x) (#x)           //#�ַ�����������
#define TOSTRING(x) ToString(x)    //����xչ����Ľ��ת��Ϊ�ַ���

#define Show_Integer(value) printf("%s =%d\n",#value,value)
#define Show_Double(value) printf("%s =%f\n",#value,value)
#define Show_String(value) printf("%s =%s\n",#value,value)

//format�������ʽ�����ַ�d-��������f-��������s-�ַ���
#define ShowValue(value,format) printf("%s =%"#format"\n",#value,value)

#define Debug(msg)                                                                     \
	do{                                                                                \
		printf("[%s %s %s line:%d] %s\n",__DATE__,__TIME__,__FILE__,__LINE__,(msg));   \
	}while(0)

#define Warn_IF(expr)                                \
	do{                                              \
		if(expr)                                     \
		{                                            \
			fprintf(stderr,"warning: "#expr"\n");    \
		}                                            \
	}while(0)

#define Assert(expr)                                                                   \
	do{                                                                                \
		if(!(expr))                                                                    \
		{                                                                              \
			printf("assert failed: %s, file %s, line %d\n",#expr,__FILE__,__LINE__);   \
			abort();                                                                   \
		}                                                                              \
	}while(0)

#define Max(x,y) (((x) > (y)) ? (x) : (y))
#define Min(x,y) (((x) < (y)) ? (x) : (y))

#define ArraySize(a) (sizeof((a))/sizeof((a[0])))

#define Swap(x,y)              \
	do{                        \
		((x) = ((x) + (y)));   \
		((y) = ((x) - (y)));   \
		((x) = ((x) - (y)));   \
	}while(0)

#define SWAP(x,y,t) (((t) = (x)),((x) = (y)),((y) = (t)))

#define Malloc(size,type) ((type*)malloc((size)*sizeof(type)))

#define Free(p)                \
	do{                        \
		if(NULL != (p))        \
		{                      \
			free(p);           \
			(p) = NULL;        \
		}                      \
	}while(0)

#define TypeSize(var) ((char*)((&(var)) + 1) - (char*)(&(var)))         //��������͵Ĵ�С
#define MemberSize(type,member) (sizeof(((type*)0)->member))            //��ṹ���г�Ա���͵Ĵ�С
#define OffsetSize(type,member) ((size_t)&(((type*)0)->member))         //���Ա�ڽṹ���е�ƫ������size_t��32λϵͳ����unsigned int����64λ��ϵͳ��λunsigned long

#define Loop(a,b) for(int i=0;i<b;++i)
#define Print(x) printf("%s =%d\n",#x,x)

#endif  //_MACRO_UTILS_H