/*ϵͳIO��������int�ļ�������������׼IO��������FILE*����
 *fileno()�����ļ�ָ��FILE*ת��Ϊ�ļ���������
 *fdopen()�����ļ�������ת��Ϊ��FILE*��
 *perror()��linuxϵͳ����ʧ��һ�㷵��-1���һ���ȫ�ֱ���errnoΪ�ض��Ĵ����룬
 *          ����ʹ��perror()��ͨ��strerror(errno)��ӡ������ʾ��
 */

/*fopen()�������ļ���ģʽmode��
 *��1��r��rb: ֻ����ʽ�򿪣��ļ������Ѵ��ڡ�
 *��2��w��wb: ֻд��ʽ�򿪣�����ļ��������򴴽�������ļ��Ѵ��������д��
 *��3��a��ab: ֻ�����ļ�ĩβ׷�����ݣ�����ļ��������򴴽���
 *��4��r+��rb+��r+b: ��д��ʽ�򿪣��ļ������Ѵ��ڡ�
 *��5��w+��w+b��wb+: ��д��ʽ�򿪣�����ļ��������򴴽�������ļ��Ѵ��������д��
 *��6��a+��a+b��ab+: ����׷�ӷ�ʽ�򿪣�����ļ��������򴴽���
 *��7��b�������ֶ������ļ����ı��ļ�����һ����DOS��Windowsϵͳ���������ֵģ�
 *     ��Linux�����ֶ������ļ����ı��ļ���
 */

/*��׼IO������3�ֻ������ͣ�
 *��1��ȫ���棺��������׼IO��������Ž���ʵ��IO���������ڷ����ڴ����ϵ���ͨ�ļ����ñ�׼IO��ʱ
 *             Ĭ����ȫ����ġ���������������ִ��fflush()ˢ�»�����ʱ�Ż���д��̲�����
 *��2���л��棺�������������������з�ʱִ��IO��������׼�������������ʹ���л���ĵ������ӡ�
 *��3���޻��棺�ڶ����Ķ�дʱ�����̲���ʵ�ʵ��ļ�����׼�������ǲ�������ģ����ʹ�ô�����Ϣ����
 *             ������ʾ���ն��ϣ�����������������Ƿ�������з���
 */

#include <fcntl.h>         //creat(),open()
#include <unistd.h>        //read(),write()
#include <sys/types.h>     //ssize_t,off_t
#include <stdio.h>         //fileno(),fdopen()
#include <stdlib.h>
#include <string.h>        //strerror()
#include <errno.h>         //errnoȫ�ֱ���

#define BUFF_SIZE 1024

static void fileno_test();
static void fdopen_test();

int main()
{
	fileno_test();
	fdopen_test();
	
	return 0;
}

void fileno_test()
{
	printf("stdin <-> %d\n",fileno(stdin));
	printf("stdout <-> %d\n",fileno(stdout));
	printf("stderr <-> %d\n",fileno(stderr));
	
	FILE* fp = fopen("file/fileno_test.txt","w+");
	if(NULL == fp)
	{
		perror("fileno_test error: ");
		abort();
	}
	
	int fb = fileno(fp);   //��FILE*ת��Ϊ�ļ�������
	if(fb == -1)
	{
		fclose(fp);
		puts("fileno_test error: FILE* to file descriptor failed");
		exit(-1);
	}
	
	char buf[BUFF_SIZE] = "time is 2021/05/20\n";
	write(fb,"hello world\n",strlen("hello world\n"));
	write(fb,buf,strlen(buf));
	
	lseek(fb,0,SEEK_SET);    //�ļ�ָ���ƶ����ļ���ͷ
	memset(buf,0,BUFF_SIZE);
	
	ssize_t size = 0;
	while((size = read(fb,buf,BUFF_SIZE)) > 0)
	{
		puts(buf);
		memset(buf,0,BUFF_SIZE);
	}
	
	off_t offset = lseek(fb,0,SEEK_END);   //���ļ�ָ���ƶ����ļ�ĩβ���Ի�ȡ�ļ���С
	fprintf(stdout,"fileno_test: fileno_test.txt size is %ld\n",offset);
	
	fclose(fp);
}

void fdopen_test()
{
	FILE* stdin_fp = fdopen(STDIN_FILENO,"r");    //���ļ�������ת��ΪFILE*
	if(stdin_fp == NULL)
	{
		fputs("fdopen_test error: STDIN_FILENO to FILE* failed\n",stdout);
		abort();
	}
	
	char buf[BUFF_SIZE] = "fdopen_test error: STDOUT_FILENO to FILE* failed\n";
	FILE* stdout_fp = fdopen(STDOUT_FILENO,"w");    //���ļ�������ת��ΪFILE*
	if(stdout_fp == NULL)
	{
		fprintf(stdout,"%s",buf);
		exit(-1);
	}
	
	memset(buf,0,BUFF_SIZE);
	printf("Please input a text: ");
	if(fgets(buf,BUFF_SIZE,stdin_fp) != NULL)
	{
		fwrite(buf,strlen(buf),1,stdout_fp);
	}
	
	int fb = open("file/fdopen_test.txt",O_RDWR | O_CREAT,S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if(fb == -1)
	{
		perror("fdopen_test error: ");
		abort();
	}
	
	FILE* fp = fdopen(fb,"w+");
	if(fp == NULL)
	{
		close(fb);
		printf("fdopen_test error: %s\n",strerror(errno));
		exit(-1);
	}
	
	fwrite("hello world\n",strlen("hello world\n"),1,fp);
	fputs("time is 2021.05.21",fp);
	fprintf(fp,"study fdopen usage");
	
	fseek(fp,0,SEEK_SET);   //�ļ�ָ���ƶ����ļ���ͷ
	memset(buf,0,sizeof(buf));
	
	size_t size = 0;
	while((size = fread(buf,BUFF_SIZE,1,fp)) > 0)
	{
		fwrite(buf,size,1,stdout);
		memset(buf,0,BUFF_SIZE);
	}
	
	//�ն�ȡ���ļ��е����ݣ��ļ�ָ�����ļ�ĩβ���Կ���ֱ��ʹ��ftell()��ȡ�ļ���С
	fprintf(stdout,"fdopen_test: fdopen_test.txt size is %ld\n",ftell(fp));
	
	close(fb);
}