#ifndef _MYSTRING_H
#define _MYSTRING_H

//���ַ����ĳ��� 
int myStrlen(const char* str);

//���Ȳ������Ƶ��ַ������� 
char* myStrcpy(char *dst,const char* src);
bool myStrcmp(const char *str1,const char *str2);
char* myStrcat(char* dst,const char* src);

//���������Ƶ��ַ������� 
char* myStrncpy(char *dst,const char *src,int n);
bool myStrncmp(const char *str1,const char *str2,int n);
char* myStrncat(char* dst,const char* src,int n);

//�ַ������� 
char* myStrchr(const char* src,const char chr);
char* myStrstr(const char* src,const char* str);
char* myStrrchr(const char* src,const char chr);
char* myStrpbrk(const char* src,const char* key);

//��ʾ�ַ���
void strShow(const char *str);

//��ȡ���ַ���
char* strLeft(const char* src,const int n);
char* strRight(const char* src,const int n);
char* strMid(const char* src,const int index,const int n);

//�ж��ַ����Ŀ�ͷ���β
bool startWith(const char* src,const char* str);
bool endWith(const char* src,const char* str);
bool contains(const char* src,const char* str);

#endif  //_MYSTRING_H