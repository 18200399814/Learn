#include <stdio.h>

typedef enum {
	INPUT = 0,
	RUN,
	FINISH,
	EXIT
}Status_t;

int main(void)
{
	int num = 0,sum = 0;
	Status_t status = INPUT;
	while(status != EXIT)
	{
		switch(status){
		case INPUT:{
			printf("�����ۼ�������ֵ��");
			scanf("%d",&num);
			getchar();
			
			if(num <= 0)
			{
				puts("�����������С��1");
				status = INPUT;
				break;
			}
			
			sum = 0;
			status = RUN;
			break;
		}
		case RUN:{
			for(int i=0;i<=num;++i)
			{
				sum += i;
			}
			
			status = FINISH;
			break;
		}
		case FINISH:{
			printf("sum =%d\n",sum);
			
			fputs("�������������q�˳�����",stdout);
			if(getchar() == 'q')
			{
				status = EXIT;
			}
			else
			{
				status = INPUT;
			}
			
			getchar();
			break;
		}
		default:
			fprintf(stdout,"status error\n");
		}
	}
	
	puts("�˳�Ӧ�ó���");
	return 0;
}