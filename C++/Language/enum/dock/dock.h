#ifndef _DOCK_H
#define _DOCK_H

// #define _DEBUG_
// #undef _DEBUG_

#define _TRACK_
#undef _TRACK_

#if (defined _DEBUG_) || (defined _TRACK_)
#define DEBUG(expr)      \
	printf("%s =%d\n",#expr,(expr))

#define TRACK(expr)      \
	printf("[%s: %s %d] %s =%d\n",__FILE__,__func__,__LINE__,#expr,(expr))
#else
#define DEBUG(expr)
#define TRACK(expr)
#endif

#define FALSE 0
#define TRUE 1

typedef char BOOL;

#define isDockTop(dock) isDock(dock,TOP)
#define isDockBottom(dock) isDock(dock,BOTTOM)
#define isDockLeft(dock) isDock(dock,LEFT)
#define isDockRight(dock) isDock(dock,RIGHT)

//Dockö���������������Ӵ���ͣ���ڸ������ϵ�λ�á�������ö�ٵ�ʹ��
#if 0
typedef enum
{
	TOP = 1,         //0B0001��TOP��ʾ�Ӵ����ϱ�Եͣ���������ϱ�Ե�����Ӵ����븸�����ϱ����غ�
	BOTTOM = 2,      //0B0010��BOTTOM��ʾ�Ӵ����±�Եͣ���������±�Ե�����Ӵ����븸�����±����غ�
	LEFT = 4,        //0B0100��TOP��ʾ�Ӵ������Եͣ�����������Ե�����Ӵ����븸����������غ�
	RIGHT = 8        //0B1000��TOP��ʾ�Ӵ����ұ�Եͣ���������ұ�Ե�����Ӵ����븸�����ұ����غ�
}Dock;
#elif 0
typedef enum Dock
{
	NONE = 0,        //
	TOP = 1,
	BOTTOM = TOP*2,
	LEFT = BOTTOM*2,
	RIGHT = LEFT*2
}Dock;
#elif 0
typedef enum Dock_t
{
	TOP = 1<<0,
	BOTTOM = 1<<1,
	LEFT = 1<<2,
	RIGHT = 1<<3,
	ALL = TOP|BOTTOM|LEFT|RIGHT
}Dock;
#else
typedef enum
{
	NONE = 0B0000,
	TOP = 0B0001,
	BOTTOM = 0B0010,
	LEFT = 0B0100,
	RIGHT = 0B1000,
	ALL = TOP|BOTTOM|LEFT|RIGHT
}Dock;
#endif

BOOL isDock(Dock dock,Dock dockTo)
{
	return (dock & dockTo) > 0;
}

void showDock(Dock dock)
{
	if(dock & TOP)             //��TOPö��ֵ��Ϊ0ʱ���ſ���ʹ��dock&TOP�����жϡ�ʹ��(dock&TOP) == TOP�ⲻ��Ĭ��ֵ�Ƿ�Ϊ0������
	{
		printf("is dock top: %d\n",(dock & TOP) != 0);
	}
	
	if((dock & BOTTOM) > 0)        //dock��������BOTTOM 
	{
		printf("is dock bottom: %d\n",(dock & BOTTOM) > 0);
	}
	
	if((dock & LEFT) == LEFT)     //dock��������BOTTOM 
	{
		printf("is dock left: %d\n",(dock & LEFT) == LEFT);
	}
	
	if((dock & RIGHT) == RIGHT)   //����ѡ��(dock & RIGHT) == RIGHT�����ж�
	{
		printf("is dock right: %d\n",(dock & RIGHT) == RIGHT);
	}
	
	putc('\n',stdout);
}

#endif //_DOCK_H