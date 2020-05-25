#ifndef _LANGUAGE_H
#define _LANGUAGE_H

#include <stdio.h>

#if (defined _DEBUG_) | (defined _TRACK_)
#define DEBUG(expr)   \
	printf("%s = %s\n",#expr,(expr))
#define TRACK(expr)  \
	printf("[%s: %s %d] %s =%s\n",__FILE__,__func__,__LINE__,#expr,(expr))
#else
#define DEBUG(expr)
#define DEBUG(expr)	
#endif

typedef enum Language_t
{
	UNKNOWN,
	CHINESE,
	ENGLISH,
	FRENCH,
	GERMAN,
	SPANISH,
	JAPANESE,
	KOREAN
}Language;

//ʹ��C99������
const char* language_data[] = {
	[UNKNOWN] = "δ֪",
	[CHINESE] = "����",
	[ENGLISH] = "Ӣ��",
	[FRENCH] = "����",
	[GERMAN] = "����",
	[SPANISH] = "��������",
	[JAPANESE] = "����",
	[KOREAN] = "����"
};

const int language_data_size = sizeof(language_data)/sizeof(language_data[0]);

void showLanguage()
{
	for(int i=0;i<language_data_size;++i)
	{
		puts(language_data[i]);
	}
	putc('\n',stdout);
}

#endif //_LANGUAGE_H