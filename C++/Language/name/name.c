//foo,bar,baz,bax,qur,qux,quz�ڱ���б�����ռλ�������֣���ʾ��ǰ�����޹ؽ�Ҫ����Ӱ�쵱ǰ����ı�
//�����������е����������ģ���������ʻ㡣

#include <stdio.h>

void foo(const char* str)
{
	if(str != NULL)
	{
		printf("foo: %s\n",str);
	}
}

void bar(const char str[])
{
	if(str != NULL)
	{
		printf("bar: %s\n",str);
	}
}

int main(int argc,char **argv)
{
	const char baz[] = "Hello";
	const char* qux = "World";

	foo("foo method");
	bar("bar method");
	printf("variable: baz =%s,qux =%s\n",baz,qux);
	
	return 0;
}