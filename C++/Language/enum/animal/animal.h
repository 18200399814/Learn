#ifndef _ANIMAL_H
#define _ANIMAL_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef enum Animal_t
{
	EAGLE,
	MAGPIE,
	CAT,
	PIG,
	CARP,
	CAMEL,
	ANIMAL_END
}Animal_t;

const char* animal_str[] = 
{
	[EAGLE] = "eagle",
	[MAGPIE] = "magple",
	[CAT] = "cat",
	[PIG] = "pig",
	[CARP] = "carp",
	[CAMEL] = "camel",
};

bool convertStringToEnum(const char* str,Animal_t *animal)
{
	if(str == NULL || animal == NULL)
	{
		puts("convertStringToEnum warn: input parameter is illegal");
		return false;
	}
	
	for(int i=0;i<ANIMAL_END;++i)
	{
		if(0 == strcmp(str,animal_str[i]))
		{
			*animal = (Animal_t)i;
			return true;
		}
	}
	
	return false;
}

bool convertEnumToString(const Animal_t animal,char* str)
{
	if(animal < 0 || animal >= ANIMAL_END || str == NULL)
	{
		fputs("convertEnumToString warn: input parameter is illegal",stdout);
		return false;
	}
	
	strcpy(str,animal_str[animal]);	     //����ʹ��str = animal_str[animal],��Ϊ����ֻ���޸���ʱָ��str��ֵ�������޸�ʵ�ε�ֵ
	return true;
}

#endif //_ANIMAL_H