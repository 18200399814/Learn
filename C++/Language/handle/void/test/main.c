#include "point.h"
#include <stdio.h>

int main(void)
{
	void* handle = createPoint(3,4);
	display(handle);
	
	setX(handle,7);
	setY(handle,8);
	
#ifdef _ERROR_
	printf("x = %d\n",handle->x);             //���󣬾��handle��֪��Point�ṹ���ڲ���ʵ�֣�
	fprintf(stdout,"y =%d\n",handle->y);      //���Բ���ֱ��ȡ���ؽṹ��Point�е����ݡ�
#else
	printf("x = %d\n",getX(handle));
	fprintf(stdout,"y =%d\n",getY(handle));	
#endif                                        //_ERROR_

	display(handle);
	
	return 0;
}