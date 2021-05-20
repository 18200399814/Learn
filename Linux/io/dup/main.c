//dup2������MingW�����������в�����Ч�������µ��ļ�����������ʧ�ܡ�

#include <fcntl.h>        //creat(),open()
#include <unistd.h>       //dup(),dup2(),read(),write()
#include <sys/types.h>    //ssize_t
#include <sys/stat.h>     //struct stat,fstat()
#include <stdio.h>        //sprintf()
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024

#define ERROR_INFO(str)                          \
	do{                                          \
		write(STDERR_FILENO,str,strlen(str));    \
		return ;                                 \
	}while(0)

#define PRINT_INFO(str)  \
	write(STDOUT_FILENO,str,strlen(str))

#define SAVE_TO_FILE(fb,str) write(fb,str,strlen(str))

/*dup()��dup()2�������Ǹ���һ���ļ���������ʹ�µ��ļ�������Ҳָ��ɵ��ļ�����������ʶ���ļ���
 *�����������ļ����������κ�һ�������ܲ���������Ӧ���ļ�����������ʵ���ض����׼������ļ��С�
 */
static void dup_test1();
static void dup_test2();
static void dup_test3();

//dup()��dup2()���÷��빦����ȫһֱ������dup2()���Ƴ��������ļ�����������ָ������һ���Ϸ������֡�
static void dup2_test1();
static void dup2_test2();

int main(void)
{
	dup_test1();
	dup_test2();
	dup_test3();
	
	dup2_test1();
	dup2_test2();
	
	return 0;
}

//ͨ��dup()���Ƶ��ļ��������ǵ��ý����ļ�������������С���õ��ļ��������������¾��ļ���������ָ��ͬһ���ļ���
void dup_test1()
{
	//ʹ��O_CREAT��Ҫʹ��mode˵���ļ�������Ȩ�ޡ����򴴽����ļ��ٴδ�ʱ������Ȩ�޲�������ʧ��
	int old_fb = open("file/dup_test.txt",O_WRONLY | O_APPEND | O_CREAT,S_IRWXU | S_IRWXG | S_IRWXO);
	if(-1 == old_fb)
	{
		PRINT_INFO("dup_test1 error: open file/dup_text.txt failed!\n");
		return ;
	}
	write(old_fb,"hello world\n",strlen("hello world\n"));
	
	char buf[BUFF_SIZE] = {0};
	sprintf(buf,"---old_fb =%d\n",old_fb);
	write(STDOUT_FILENO,buf,strlen(buf));
	
	int new_fb = dup(old_fb);
	if(-1 == new_fb)
	{
		close(old_fb);
		ERROR_INFO("dup_test1 error: dup old_fb failed!\n");
	}
	write(new_fb,"time is 2021/05/19\n",strlen("time is 2021/05/19\n"));

	memset(buf,0,sizeof(buf));
	sprintf(buf,"---new_fb =%d\n",new_fb);
	PRINT_INFO(buf);
	
	close(old_fb);   //�˳�����ʱ���¾������ļ�����������Ҫ�ر�
	close(new_fb);
}

void dup_test2()
{
	int read_fb = open("file/dup_test.txt",O_RDWR);    //O_RDWR��O_RDONLY | O_WRONLY����Ч
	if(-1 == read_fb)
	{
		ERROR_INFO("dup_test2 error: open file/dup_test.txt failed!\n");
	}
	
	//��ʵread_fb�Ѿ����Խ��ж�д�����ˣ��������½�һ���ļ�����������д������ʹ���ڸ�����ȷ��
	int write_fb = dup(read_fb);
	if(write_fb == -1)
	{
		close(read_fb);
		PRINT_INFO("dup_test2 error: dup read_fb failed!\n");
		return ;
	}
	
	char *pbuf = (char*)malloc(BUFF_SIZE);
	if(NULL == pbuf)
	{
		close(read_fb);
		close(write_fb);
		ERROR_INFO("dup_test2 error: pbuf malloc failed!\n");
	}
	
	memset(pbuf,0,BUFF_SIZE);
	ssize_t size = read(read_fb,pbuf,BUFF_SIZE);
	write(STDOUT_FILENO,pbuf,size);
	write(STDOUT_FILENO,"\n",1);
	
	lseek(write_fb,0,SEEK_END);
	
	memset(pbuf,0,BUFF_SIZE);
	strcpy(pbuf,"write a string to file\n");
	SAVE_TO_FILE(write_fb,pbuf);
	
	if(pbuf != NULL)
	{
		free(pbuf);
		pbuf = NULL;
	}
	
	close(read_fb);
	close(write_fb);
}

void dup_test3()
{
	int old_fb = open("file/dup_test.txt",O_WRONLY | O_APPEND);
	if(-1 == old_fb)
	{
		ERROR_INFO("dup_test3 error: open file/dup_test.txt failed!\n");
	}
	puts("output to standard device");
	printf("dup_test3: old_fb =%d\n",old_fb);
	
	//�����µ��ļ����������Ա�������豸���ļ�ָ�룬�����Ժ�ԭ
	int save_fb = dup(STDOUT_FILENO);

	/*STDOUT_FILENO����ָ���׼����豸����1�ļ��������رգ�����˵1����ָ���׼����豸��
	 *����1�ļ��������Ϳ����ˣ����ͳ�Ϊ��С���õ��ļ���������
	 */
	close(STDOUT_FILENO);
	
	/*dup�Ὣ��ǰϵͳ�п��Դ�������С�ļ����������ظ�new_fb������1�ļ��������Ѿ����رյ���
	 *���������ȡ��������STDOUT_FILENO��������ֵ��
	 */
	int new_fb = dup(old_fb);
	if(new_fb == -1)
	{
		close(old_fb);
		PRINT_INFO("dup_test3 error: dup old_fb failed!\n");
		return ;
	}
	close(old_fb);    //�رն�����ļ�������
	
	/*����puts/printf�ȱ�׼IO�����󶨵Ķ���1�ļ���������������1�ļ���������ʶ���Ѿ�����������豸��
	 *�������һ���ļ���������ʹ��puts��printf��ӡ��Ϣʱ����Ϣ�����ٴ�ӡ������豸�У����Ǳ��ض���
	 *д����dup_test.txt�ļ��С�
	 */
	puts("output to dup_test.txt");
	printf("dup_test3: new_fb is %d\n",new_fb);
	
	//dup��dup2�ض����ܣ���Windows������ʹ��MingW����������ʱ������Ҫˢ��������棬�����ض����ļ���
	fflush(stdout);
	
	close(new_fb);
	if(dup(save_fb) == -1)    //���½�1�ļ��������󶨵�����豸��
	{
		ERROR_INFO("dup_test3 error: recover 1 to standard device failed\n");
	}
	PRINT_INFO("dup_test3: recover 1 to standard device successful\n");
}

void dup2_test1()
{
	int old_fb = open("file/dup2_test.txt",O_WRONLY | O_APPEND | O_CREAT,S_IRWXU | S_IRWXG | S_IRWXO);
	if(old_fb == -1)
	{
		ERROR_INFO("dup2_test1 error: open file/dup2_test.txt failed!\n");
	}
	
	char buf[32] = {0};
	sprintf(buf,"---old_fb =%d---\n",old_fb);
	write(STDOUT_FILENO,buf,strlen(buf));
	write(old_fb,"dup2 test\n",strlen("dup2 test\n"));
	
	int new_fb = 8;
	if(dup2(old_fb,new_fb) != new_fb)
	{
		close(old_fb);
		ERROR_INFO("dup2_test1 error: dup2 old_fb failed\n");
	}
	
	memset(buf,0,sizeof(buf));
	sprintf(buf,"---new_fb =%d---\n",new_fb);
	write(STDOUT_FILENO,buf,strlen(buf));
	SAVE_TO_FILE(new_fb,"dup2 can appoint file descriable num\n");
	
	close(old_fb);    //�ر�ʱ�������ļ����������ùر�
	close(new_fb);
}

void dup2_test2()
{
	int file_fb = open("file/dup2_test.txt",O_WRONLY);
	if(-1 == file_fb)
	{
		ERROR_INFO("dup2_test2 error: open file/dup2_test.txt failed\n");
	}
	
	int save_fb = dup2(STDOUT_FILENO,10);
	if(10 != save_fb)
	{
		close(file_fb);
		PRINT_INFO("dup2_test2 error: save standard output device successful\n");
		return ;
	}
	close(STDOUT_FILENO);     //�رձ�׼����豸
	
	const char* info = "close standard output device\n";
	write(save_fb,info,strlen(info));
	
	int stdout_fb = 1;     //stdout_fb����Ϊ��׼����豸�ļ�������
	if((stdout_fb = dup2(file_fb,1)) != 1)    //����׼����豸�ض���dup2_test.txt�ļ���
	{
		close(file_fb);
		ERROR_INFO("dup2_test2 error: can't redirect\n");
	}
	close(file_fb);
	
	puts("write to file");
	printf("save_fb =%d, stdout_fb =%d\n",save_fb,stdout_fb);
	fputs("data is 2021/05/20\n",stdout);
	fprintf(stdout,"linux io test\n");
	fflush(stdout);
	
	close(stdout_fb);
	if(dup(save_fb) == -1)
	{
		ERROR_INFO("dup2_test2 error: recover standard output device failed\n");
	}
	PRINT_INFO("dup2_test2: recover standard output device successful\n");
}