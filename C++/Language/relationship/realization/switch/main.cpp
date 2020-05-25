#include "light.h"
#include "fan.h"
#include <stdlib.h>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using std::cout;
using std::endl;

#define FREE(ptr)                    \
	do{                              \
		if(ptr != nullptr)           \
		{                            \
			delete ptr;              \
			ptr = nullptr;           \
		}                            \
	}while(0)

template <class T>
static void myFree(T** pp);

static void Free(void* ptr);

int main(int argc,char* argv[])
{
	Light* plight = new Light;
	plight->turnUp();
	plight->turnDown();
	plight->show();
	FREE(plight);
	
	Turn* pfan = new Fan();
	pfan->turnUp();
	pfan->turnDown();

#ifndef _CHANGE_WAY_
	Fan *fan = (Fan*)pfan;
	if(fan != nullptr)
	{
		fan->display();
	}
	myFree(&pfan);
#else
	Fan *fan = static_cast<Fan*>(pfan);
	if(fan != nullptr)
	{
		fan->display();
	}
	Free(pfan);	
#endif
	
	cout<<"end main()"<<endl;
	
	return 0;
}

template <class T>
void myFree(T** pp)
{
	if(*pp != nullptr)
	{
		delete *pp;
		*pp = nullptr;
	}
}

void Free(void* ptr)
{
	if(ptr != nullptr)
	{
		free(ptr);              //new��delete�������ʹ�ã�����new�����Ŀռ�ʹ����free�����ڴ��ͷ�,��������������������
	}                           //new�����Ŀռ�ŵ��ù��캯����delete�ͷſռ�ŵ�������������malloc�����ڴ�ռ䲻���ù��캯����free�ͷ��ڴ�ռ䲻������������
}