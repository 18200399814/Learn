/*1.�����ܵ�������
 *��1�������ܵ�����û�����֣�ֻ��������Ե��ϵ�Ľ��̼�ͨ�š�Ϊ�˿˷������ܵ���ȱ�㣬����������ܵ�FIFO��
 *     Ҳ�������ܵ���FIFO�ļ���
 *��2�������ܵ�FIFO��ͬ�������ܵ�֮���������ṩ��һ��·������֮��������FIFO���ļ���ʽ�������ļ�ϵͳ�У�
 *     ������ʹ��FIFO�Ĵ������̲�������Ե��ϵ�Ľ��̣�ֻҪ���Է��ʸ�·�������ܹ��˴�ͨ��FIFO�໥ͨ�ţ�
 *     ���ͨ��FIFO����صĽ���Ҳ�ܽ������ݡ�
 *��3�������ܵ�ӵ�йܵ����������ԣ�֮���Գ�֮Ϊ��������Ϊ�ܵ��ڴ�������ʵ���ļ����ļ�����Ϊp�������ܵ��ļ���С��ԶΪ0��
 *     ��Ϊ�����ܵ�Ҳ�ǽ����ݴ洢���ڴ�Ļ������С��򿪴����ϵĹܵ��ļ����Ϳ��Եõ����������ܵ����ļ���������ͨ���ļ�
 *     ��������д�ܵ��洢���ں��е����ݡ������ܵ�Ҳ���Գ�Ϊfifo(first in first out)��ʹ�������ܵ��ȿ��Խ�����ѪԵ��ϵ
 *     �Ľ��̼�ͨ�ţ�Ҳ���Խ���û��ѪԵ��ϵ�Ľ��̼�ͨ�š����������ܵ��ķ�ʽ�����֣�һ����ͨ�����һ����ͨ��������
 */

/*2.�����ܵ�FIFO�������ܵ�pipe������:
 *��1��FIFO���ļ�ϵͳ����Ϊһ��������ļ������ڣ���FIFO�е�����ȴ������ڴ��С�
 *��2����ʹ��FIFO�Ľ����˳���FIFO�ļ��������������ļ�ϵͳ���Ա��Ժ�ʹ�á�
 *��3��FIFO�����֣�����صĽ��̿���ͨ���������ܵ�����ͨ�š�
 */
 
/*3.�����ܵ�ͨ�ţ�
 *��1����������ѪԵ��ϵ����û��ѪԵ��ϵ��ʹ�������ܵ�ʵ�ֽ��̼�ͨ�ŵķ�ʽ����ͬ�ģ����������������зֱ��Զ�д�ķ�ʽ
 *     �򿪴����ϵĹܵ��ļ����õ����ڶ��ܵ���д�ܵ����ļ����������Ϳ��Ե��ö�Ӧ��read()��write()�������ж�д�����ˡ�
 *��2�������ܵ�������Ҫͨ������open()�õ���д�ܵ����ļ������������ֻ�Ƕ��˴��˻���ֻ��д�˴��ˣ����̻�����������
 *     ��������ִ�У�ֱ������һ�������н��ܵ��ĶԶ˴򿪣���ǰ���̵������Ž�������Ե����ֽ�����������open()�����ϲ�Ҫ
 *     �е����ȡ�
 *��3�����������open()�������ܵ���ʱ������������ʹ�ÿɶ���д��ʽ��FIFO�ļ�������open()�����Ͳ���������
 *��4�������ܵ������ɹ��Ժ󣬾Ϳ��԰������ܵ�������ͨ�ļ�һ������open()��write()��read()��close()�Ȳ�����
 *     �������ܵ�һ�������������ܵ��϶�Ҫ����Ĭ����������������ԡ�
 */

/*4.�����ܵ��������
 *��1�����������ܵ�����mkfifo -m 666 �����ܵ����� �� ��mknod -m 666 �����ܵ��� p����
 *��2��ɾ�������ܵ�����rm -rf �����ܵ����� �� ��unlink �����ܵ�������
 */

/*5.�ܵ��Ķ�д��Ϊ�������ڹܵ������������Ļ��������ģ��ڽ��ж�д��ʱ�����Ǳ��ֳ�����Ϊ��һ�µģ�
 *��1�����ܵ�����Ҫ����д�˵�״̬���з�����
 *  ��д��û�йرգ������ܵ�д�˵��ļ�������û�б��رգ���
 *    ����ܵ���û�������������������ܵ��б�д�����������������
 *    ����ܵ��������ݲ��������ܵ��е����ݱ������ˣ��ټ������ܵ�����������
 *  ��д���Ѿ��ر��ˣ�û�п��õ��ļ�����������д�ܵ��ˣ���
 *    �ܵ���û������ ���˽��������read()��������0��
 *    �ܵ���������read()�Ƚ����ݶ��������ݶ���֮�󷵻�0�����������ˡ�
 *��2��д�ܵ�����Ҫ���ݶ��˵�״̬���з�����
 *  �ٶ���û�йرգ�
 *    ����ܵ��д洢�Ŀռ䣬һֱд���ݡ�
 *    ����ܵ�д���ˣ�д�����������������˽��ܵ����ݶ����ˣ������������д��
 *  �ڶ��˹ر��ˣ��ܵ����ѣ�����ֱ���˳���
 */

/*6.mkfifo()�������÷���
 *��1������ԭ�ͣ�int mkfifo( const char *pathname, mode_t mode)��
 *��2�����ܣ����������ܵ���
 *��3��pathname��������ͨ��·������Ҳ���Ǵ�����FIFO�����֡�
 *��4��mode����: �ļ���Ȩ�ޣ������ͨ�ļ���open()�����е�mode������ͬ��
 *��5������ֵ���ɹ�����0������ļ��Ѿ����ڣ��������ҷ���-1��
 */

/*7.unlink()�������÷���
 *��1������ԭ�ͣ�int unlink(const char *pathname)��
 *��2�����ܣ����ļ�ϵͳ��ɾ��һ�����ơ�����������ļ������һ�����ӣ�����û���������̽��ļ��򿪣�
 *           ���ƶ�Ӧ���ļ���ʵ�ʱ�ɾ����
 *��3��pathname������ָ���������ӵ��ļ�����
 *��4������ֵ���ɹ�ִ�з���0��ʧ�ܷ���-1��������errnoȫ�ֱ�����ֵ��
 */

#include <unistd.h>           //read(),write(),fork(),sleep(),usleep(),access(),unlink()
#include <fcntl.h>            //creat(),open()
#include <sys/types.h>        //pid_t,ssize_t
#include <sys/stat.h>         //mkfifo(),mkdir()
#include <sys/wait.h>         //wait(),waitpid()
#include <stdio.h>
#include <stdlib.h>           //exit(),abort(),system()
#include <string.h>           //strerror(),memset(),bzero()
#include <errno.h>

#define BUFF_SIZE 64

static void read_fifo();
static void fifo_count();

int main(int argc,char* argv[])
{
	// read_fifo();	
	fifo_count();
	
	return 0;
}

void read_fifo()
{
	fprintf(stdout,"read_fifo: start ,pid =%d\n",getpid());
	if(access("./testfifo",F_OK) == -1)
	{
		if(mkfifo("./testfifo",0666) == -1)    //���մ��������ܵ���Ȩ��Ϊ(0666 & ~0022)
		{
			fputs("read_fifo error: can't create fifo file\n",stdout);
			_exit(-1);
		}
	}
	
	int fb = open("testfifo",O_RDONLY);
	if(-1 == fb)
	{
		printf("read_fifo error: %s\n",strerror(errno));
		return ;
	}
	
	ssize_t size = 0;
	char buf[BUFF_SIZE] = {0};
	while((size = read(fb,buf,BUFF_SIZE)) > 0)
	{
		write(STDOUT_FILENO,buf,sizeof(buf));
		memset(buf,0,BUFF_SIZE);
	}
	
	fputs("read_fifo: over\n",stdout);
	close(fb);
}

void fifo_count()
{
	char buf[BUFF_SIZE] = {0};
	sprintf(buf,"fifo_count: read begin ,pid =%d\n",getpid());
	fputs(buf,stdout);
	
	if(access("./count_fifo.p",F_OK) == -1)
	{
		if(mkfifo("count_fifo.p",0777) == -1)
		{
			perror("fifo_count error");
			exit(-1);
		}
	}
	
	int fb = open("./count_fifo.p",O_RDONLY);
	if(fb == -1)
	{
		fputs("fifo_count error: open count_fifo.p failed\n",stdout);
		abort();
	}
	
	int sum = 0;
	for(int i=50;i<=100;++i)
	{
		sum += i;
	}
	
	int ret = 0;
	if(read(fb,&ret,sizeof(ret)) == 0)  //����ܵ��е�����Ϊ�ջ�д�ܵ���������д���ݣ���ô���ܵ����̽�������
	{
		puts("fifo_count error: read data from fifo failed");
		close(fb);
		abort();
	}
	fprintf(stdout,"fifo_count: read ret =%d\n",ret);
	
	sum += ret;
	printf("fifo_count: 0 ~ 100 summation is %d\n",sum);
	
	puts("read_fifo: finish");
	close(fb);
	unlink("./count_fifo.p");
}