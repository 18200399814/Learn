#include "prime.h"
#include <stdio.h>
#include <math.h>

#if 1
bool isPrime(int num)
{
	if(num <=0)
	{
		printf("isPrime error: num is less than or equal zero\n");
		return false;
	}
	
	for(int i=2;i<num;++i)
	{
		if(num%i == 0)
		{
			return false;
		}
	}
	return true;
}
#elif 0
bool isPrime(int num)
{
	if(num <= 0)
	{
		puts("isPrime error: num is less than or equal zero\n");
		return false;
	}
	
	int i = 2;
	int temp = sqrt(num);
	for(i;i<=temp;++i)
	{
		if(num%i == 0)
		{
			break;
		}
	}
	
	if(i > temp)
	{
		return true;
	}
	return false;
}
#elif 0
bool isPrime(int num)
{
	if(num <= 0)
	{
		puts("isPrime error: num is less than or equal zero\n");
		return false;
	}
	
	bool flag = false;
	int temp = sqrt(num);
	for(int i=2;i<=temp;++i)
	{
		if(num%i != 0)
		{
			flag = true;
		}
	}
	
	if(flag)
	{
		return true;
	}
	return false;
}
#endif

#if 1
void prime(int num)
{
	if(num <=0)
	{
		fprintf(stdout,"isPrime error: num is less than or equal zero\n");
		return ;
	}
	
	for(int i=2;i<=num;++i)        //��������С�ڵ���num����
	{
		int j = 2;
		for(j;j<i;++j)       //�ж�ÿһ��С�ڵ���num�����ǲ���������
		{
			if(i%j == 0)
			{
				break;
			}
		}
		
		if(j >= i)
		{
			printf("%d ",i);
		}
	}
	puts("");
}
#elif 0
void prime(int num)
{
	if(num <=0)
	{
		fputs("isPrime error: num is less than or equal zero\n",stdout);
		return ;
	}
	
	int count;                //ͳ��һ����������������
	for(int i=2;i<=num;++i)
	{
		count = 0;
		for(int j=2;j<i;++j)
		{
			if(i%j == 0)
			{
				count++;
			}
		}
		
		if(count == 0)
		{
			printf("%d ",i);
		}
	}
	putc('\n',stdout);
}
#elif 0
void prime(int num)
{
	if(num <=0)
	{
		fputs("isPrime error: num is less than or equal zero\n",stdout);
		return ;
	}
	
	for(int i=2;i<=num;++i)
	{
		bool flag = true;            //ʹ�ñ�־λ
		int temp = sqrt(i);
		for(int j=2;j<=temp;++j)
		{
			if(i%j == 0)
			{
				flag = false;
				break;
			}
		}
		
		if(flag)
		{
			printf("%d ",i);
		}
	}
	putchar('\n');
}
#endif