#include "person.h"
#include <stdio.h>

int main(void)
{
	HPerson hperson = createPerson("Tom");      //��ȡPerson����ľ������ʹ�þ��ȥ��������
	setAge(hperson,25);
	showPerson(hperson);
	
	destroyPerson(&hperson);
	return 0;
}