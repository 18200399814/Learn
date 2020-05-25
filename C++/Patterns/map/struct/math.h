#ifndef _MATH_H
#define _MATH_H

#define SIZE 4
#define EPS 0.000001

#define INIT_CHANGE
// #undef INIT_CHANGE

#ifdef _DEBUG_
#define TRACK(expr)   \
	printf("[%s: %s] $s =%f\n",__FILE__,__LINE__,#expr,expr)
#else
#define TRACK(expr)
#endif

typedef enum Signal_t
{
	ADD = '+',
	SUB = '-',
	MULT = 'x',
	DIVI = '/'
}Signal_t;

typedef double (*pFun)(double x,double y);

typedef struct Message_t
{
	Signal_t signal;
	pFun operate;
}Message_t;

#ifndef INIT_CHANGE
extern Message_t messageMap[];           //ʹ��extern��������ʱ�����Բ���ָ������Ĵ�С������������ʱ��ָ�������С��
#else
extern Message_t messageMap[SIZE];       //ͷ�ļ��ж��������ʱ����ö�Ҫ��extern��static����������ӻ�����ض��塣extern�����������ȫ�ֱ�����
#endif                                   //static�������ÿһ��Դ�ļ��ж��ᶨ��һ��ͬ����static������ֻ���ڵ�ǰԴ�ļ���ʹ�á�Դ�ļ�֮�以��Ӱ�졣

extern const int messageMap_size;

extern void calculate(double x,double y,char opt);
extern void initMath();

extern double add(double x,double y);
extern double sub(double x,double y);
extern double mult(double x,double y);
extern double divi(double x,double y);

extern char strToChar(const char* str);
#endif //_MATH_H