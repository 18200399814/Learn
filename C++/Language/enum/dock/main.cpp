#include <stdio.h>

#define _DEBUG_
// #undef _DEBUG_
#include "dock.h"

#define _IS_CPP_
// #undef _IS_CPP_

#define _USE_ENUM_
// #undef _USE_ENUM_

int main(int argc,char* argv[])
{
#ifdef _IS_CPP_
	Dock dock1 = (Dock)10;             //C++�����в��ܶ�ö���ͱ���ֱ�Ӹ�����ֵ��ö��ֵ����ϣ��������ǿ������ת��
	Dock dock2 = Dock(TOP | LEFT);
#else
	Dock dock1 = 10;                   //C�����п��Զ�ö���ͱ���ֱ�Ӹ�����ֵ��ö��ֵ�����
	Dock dock2 = TOP | LEFT;
#endif
	DEBUG(dock1);
	TRACK(dock2);

#ifndef _USE_ENUM_
	BOOL isTop = TRUE;                //ֱ��ʹ��bool�ͱ�����ʾ���Ӵ���֮��ķ�λʱ����Ҫ����4�������ͱ�����
	BOOL isBottom = FALSE;
	BOOL isLeft = TRUE;
	BOOL isRIGHT = FALSE;
	
	printf("is dock top: %d\n",isTop);
	printf("is dock bottom: %d\n",isBottom);
	printf("is dock right: %d\n",isRIGHT);
	printf("is dock left: %d\n",isLeft);
#else
	char dock3 = TOP|LEFT;             //ʹ�ö�����ö�ٿ��Լ���bool���ͱ�������

	printf("is dock top: %d\n",isDockTop((Dock)dock3));
	printf("is dock bottom: %d\n",isDockBottom((Dock)dock3));
	printf("is dock left: %d\n",isDockLeft(static_cast<Dock>(dock3)));
	printf("is dock right: %d\n\n",isDockRight(static_cast<Dock>(dock3)));
	
	fputs("test add and delete1\n",stdout);
	char dock4 = Dock(TOP | BOTTOM | LEFT);   //��ΪTOP|LEFT���Ͳ���Dockö�����ͷ�Χ�ڣ����Զ���һ��char���ͱ�����
	showDock(Dock(dock4));
	
	dock4 |= RIGHT;     //���һ��ö��ֵRIGHT�������һ������
	showDock((Dock)dock4);
	
	dock4 ^= BOTTOM;    //�Ƴ�һ��ö��ֵBOTTOM�����Ƴ�һ��ѡ���������ͬΪ0��������Ϊ1
	showDock((Dock)dock4);
	
	dock4 &= ~LEFT;     //ɾ��һ��ö��ֵLEFT����ɾ��һ��Ȩ��
	showDock((Dock)dock4);
	
	puts("test add and delete2");
	int dock5 = (Dock)((BOTTOM | LEFT | RIGHT) ^ BOTTOM);      //����Ϊint��Ϊ�˱��⣬ʹ�ù��������ӻ���ɾ����ʱ�������м�ֵ����ö��ֵ��
	showDock(Dock(dock5));
	
	dock5 = dock5 ^ BOTTOM;      //���������ֻ��ֵ��ӻ���
	dock5 = dock5 & (~LEFT);     //�����������ٴζ����᲻ֵ�������û���
	dock5 = dock5 | TOP;
	showDock(Dock(dock5));
#endif
	
	return 0;
}
