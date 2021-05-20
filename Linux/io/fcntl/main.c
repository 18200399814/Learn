#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

#define BUFF_SIZE 1024

#define READ_TEST_FAILED "read_test failed: can't open read_test.txt file\n"
#define LSEEK_TEST_FAILED "lseek_test failed: can't open lseek_test.txt file\n"

#define UNUSED(x) (void)x

#define ToString(x) #x

#define ERROR_INFO(str)                            \
	do{                                            \
		write(STDERR_FILENO,str,strlen(str));      \
		return ;                                   \
	}while(0)

#define PRINT_INFO(str)  \
	write(STDOUT_FILENO,str,strlen(str))

static void creat_test();
static void open_test();
static void read_test();
static void write_test();
static void lseek_test();

int main(int argc,char* argv[])
{
	UNUSED(argc);
	UNUSED(argv);
	
	creat_test();
	open_test();
	read_test();
	write_test();
	lseek_test();
	
	return 0;
}

//creat()�������൱�ڵ���open(const char * pathname ,O_CREAT|O_WRONLY|O_TRUNC)����
void creat_test()
{
#ifndef _CHANGE_WAY_
	int fb = creat("file/creat_test.txt",S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH);
	if(fb == -1)
	{
		perror("creat_test error: create file/creat_test.txt failed!");
		return ;
	}
	
	char strfb[16] = {0};
	itoa(fb,strfb,10);      //��������ת��Ϊ�ַ�������10���Ƶķ�ʽ
	
	char info[128] = "creat_test: create file/creat_test.txt success ,fb =";
	strcat(info,strfb);
	strcat(info,"\n");
	
	PRINT_INFO(info);    //��ʹ�ø�ʽ����ӡ������ַ���
#else
	int fb = open("file/creat_test.txt",O_CREAT | O_WRONLY| O_TRUNC,S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH);
	if(fb == -1)
	{
		perror("creat_test error: create file/creat_test.txt failed!");
		return ;
	}
	
	char strfb[16] = {0};
	itoa(fb,strfb,10);
	
	char info[128] = "creat_test: create file/creat_test.txt success ,fb =%1\n";
	char *str = strstr(info,"%1");
	
	int tailStr_size = strlen(str + 2) + 1;
	char* tailStr = (char*)malloc(tailStr_size);
	memcpy(tailStr,str + 2,tailStr_size);
	
	memcpy(str,strfb,strlen(strfb));
	strcpy(str + strlen(strfb),tailStr);
	
	PRINT_INFO(info);
	
	if(tailStr != NULL)
	{
		free(tailStr);
		tailStr = NULL;
	}
#endif
	
	close(fb);
}

void open_test()
{
	char buf[BUFF_SIZE] = "open_test error: open file/open_test.txt failed\n";
	int fb = open("./file/open_test.txt",O_RDONLY);
	if(fb == -1)
	{
		write(STDERR_FILENO,buf,strlen(buf));
		return ;
	}
	
	memset(buf,0,sizeof(buf));
	strcpy(buf,"open_test: open file/open_test.txt success\n");
	write(STDOUT_FILENO,buf,strlen(buf));
	
	close(fb);
}

void read_test()
{
	int fb = open("file/read_test.txt",O_RDONLY);
	if(-1 == fb)
	{
		write(STDERR_FILENO,READ_TEST_FAILED,strlen(READ_TEST_FAILED));
		return ;
	}
	
	int size = 0;
	char buf[BUFF_SIZE] = {0};
	while((size = read(fb,buf,sizeof(buf))) > 0)
	{
		write(STDOUT_FILENO,buf,size);
		memset(buf,0,STDOUT_FILENO);
	}
	write(STDOUT_FILENO,"\n",1);     //ϵͳIO���ǲ�������ģ������"\n"ֻ�𵽻��е����ã�������ˢ���ն˵����������
	
	close(fb);
}

void write_test()
{
	int fb = -1;
	
#ifndef _CHANGE_WAY_
	if((fb = open("./file/write_test.txt",O_WRONLY | O_CREAT | O_TRUNC,766)) == -1)
	{
		const char* error_info = "write_test error: open file/write_test.txt failed\n";
		write(STDERR_FILENO,error_info,strlen(error_info));
		return ;
	}
	
	write(fb,"write file test\n",strlen("write file test\n"));
	write(fb,"hello world\n",strlen("hello world\n"));
	write(fb,"time is 2020.05.12\n",strlen("time is 2020.05.12\n"));
	
	PRINT_INFO("write_test: write file success\n");
#else
	if((fb = open("./file/write_test.txt",O_WRONLY | O_APPEND)) == -1)    //���ļ�ʱָ��O_APPEND�������ǽ��ļ�ָ���ƶ����ļ�ĩβ
	{
		const char* error_info = "write_test error: open file/write_test.txt failed\n";
		write(1,error_info,strlen(error_info));
		return ;
	}
	
	printf("fb =%d\n",fb);
	write(fb,"append line text\n",strlen("append line text\n"));
	write(1,"write_test: append file success\n",strlen("write_test: append file success\n"));
#endif

	close(fb);
}

/*ÿһ���Ѵ򿪵��ļ�����һ����дλ��, �����ļ�ʱͨ�����дλ����ָ���ļ���ͷ, 
 *�����Ը��ӵķ�ʽ���ļ�(��O_APPEND), ���дλ�û�ָ���ļ�β����read()��write()ʱ, 
 *��дλ�û���֮����, lseek()�����������Ƹ��ļ��Ķ�дλ�á�
 */
void lseek_test()
{
	int fb = open("file/lseek_test.txt",O_RDWR);   //O_RDWR��O_RDONLY | O_WRONLY����Ч
	if(-1 == fb)
	{
		write(2,LSEEK_TEST_FAILED,strlen(LSEEK_TEST_FAILED));   //STDERR_FILENO���ֵ��2
		return ;
	}
	
	//linuxϵͳ������û��tell������C��׼���е�ftell����ʹ��lseek(fb,0,SEEK_END)ʵ��
	int size = lseek(fb,0,SEEK_END);
	lseek(fb,0,SEEK_SET);       //һ���ƶ����ļ���дָ�룬ʹ������Ժ������Ҫ�ƻ���

	char buf[64] = {0};
	sprintf(buf,"lseek_test: file size is - %d\n",size);
	write(1,buf,strlen(buf));       //STDOUT_FILENO���ֵ��1
	
	lseek(fb,10,SEEK_CUR);          //�ļ�ָ��ӵ�ǰλ����ǰ�ƶ�10���ַ�
	write(fb,"AAA BBB\n",strlen("AAA BBB\n"));
	
	lseek(fb,0,SEEK_END);
	write(fb,"append line text\n",strlen("append line text\n"));
	
	close(fb);
}