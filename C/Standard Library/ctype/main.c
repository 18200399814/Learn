#include <stdio.h>
#include <ctype.h>

static void number_test();
static void char_test();

int main(void)
{
	number_test();
	char_test();
	
	return 0;
}

void number_test()
{
	int var = '5';
	if(isdigit(var))    //��鴫����ַ��Ƿ���ʮ��������
	{
		fprintf(stdout,"var =%c ,is a decimal number\n",var);
	}
	
	var = 'd';
	if(!isdigit(var))
	{
		fprintf(stdout,"var =%c ,isn't a decimal number\n",var);
	}
	
	var = '\t';
	if(!isalnum(var))    //�ж��Ƿ�Ϊ��ĸ������
	{
		fprintf(stdout,"var =%c ,isn't a letter or number\n",var);
	}
	
	var = 'B';
	if(isxdigit(var))
	{
		fprintf(stdout,"var =%c ,is a hexadecimal number\n",var);
	}
	
	var = 'b';
	if(isxdigit(var))
	{
		fprintf(stdout,"var =%c ,is a hexadecimal number\n",var);
	}
}

void char_test()
{
	int var = 'd';
	if(isalpha(var))
	{
		printf("var =%c ,is a letter\n",var);
	}
	
	var = '5';
	if(!isalpha(var))
	{
		printf("var =%c ,is not a letter\n",var);
	}
	
	var = '\n';
	if(!isalnum(var))
	{
		printf("var =%c ,isn't a letter or number\n",var);
	}
	
	var = ' ';
	if(isspace(var))
	{
		printf("var =%c ,is a space\n",var);
	}
	
	var = 'e';
	if(islower(var))
	{
		printf("var =%c ,is a lowercase\n",var);
	}
	
	var = toupper(var);     //ת��Ϊ��д��ĸ
	printf("var =%c ,lowercase to uppercase\n",var);
	
	
	var = 'G';
	if(isupper(var))
	{
		printf("var =%c ,is a uppercase\n",var);
	}
	
	var = tolower(var);     //ת��ΪСд��ĸ
	printf("var =%c ,uppercase to lowercase\n",var);
}