/*������һ�������һ��ִ�У���ϵͳ��Դ�������С��Ԫ�����ڴ����û�̬�Ĳ�ͬ���̼��Ǳ˴˸���ģ�
 *�������Ǻܿ�����Ҫ�໥����һЩ��Ϣ�����öԷ�֪���Լ��Ľ�����������̼䴫����Ϣ�ͽн��̼�ͨ�š�
 */

/*1.Ϊʲô���н��̼�ͨ�ţ�
 *��1�����ݴ��䣺һ��������Ҫ���������ݷ��͸���һ�����̡�
 *��2���������ݣ����������Ҫ�����������ݣ�һ�����̶Թ������ݵ��޸ģ���Ľ���Ӧ�����̿�����
 *��3��֪ͨ�¼���һ��������Ҫ����һ����һ����̷�����Ϣ��֪ͨ��������ĳ���¼���
 *��4�����̿��ƣ�һ������ϣ��������һ�����̵����С�
 *��5�����̵����ݿռ��Ƕ����ġ�˽�еġ������໥���ʣ�����ĳЩ����½���֮����Ҫͨ����ʵ��ĳ���ܻ򽻻����ݡ�
 */

/*2.Linux���̼�ͨ�ŵ�6�ַ�ʽ��
 *��1���ܵ�(Pipe)�������ܵ�(Named Pipe): �ܵ������ھ���"ѪԵ"��ϵ���̼��ͨ�ţ������ӽ��̻��ֵܽ��̼��ͨ�š�
 *     �����ܵ������йܵ������еĹ����⣬��������"ѪԵ"��ϵ���̼��ͨ�š�
 *��2���ź�(Signal): �ź������������϶��жϻ��Ƶ�һ��ģ�⣬���ǱȽϸ��ӵ�ͨ�ŷ�ʽ������֪ͨ������ĳ�¼�������
 *     ��ʵһ�������յ�һ���ź��봦�����յ�һ���ж�����Ч���Ͽ���˵��һ���ġ�
 *��3���ź���(Semaphore): ��Ҫ��Ϊ����֮�估ͬһ���̵Ĳ�ͬ�߳�֮���ͬ���ͻ����ֶΡ�
 *��4�������ڴ�(Shared Memory): ����˵��������Ч�Ľ��̼�ͨ�ŷ�ʽ����ʹ�ö�����̿��Է���ͬһ���ڴ�ռ䣬
 *     ��ͬ���̿��Լ�ʱ�����Է������жԹ����ڴ������ݵĸ��¡�����ͨ�ŷ�ʽ��Ҫ����ĳ��ͬ�����ƣ��绥�������ź����ȡ�
 *��5����Ϣ����(Messge Queue): ��Ϣ��������Ϣ����������Posix��Ϣ���к�System V��Ϣ���С����˷��˹ܵ����ź�ͨ�ŷ�ʽ
 *     ����Ϣ�����޵�ȱ�㡣����дȨ�޵Ľ��̿��԰���һ���Ĺ�������Ϣ�����������Ϣ������Ϣ���о��ж�Ȩ�޵Ľ�������Դ�
 *     ��Ϣ�����ж�ȡ��Ϣ��
 *��6���׽���(Socket): ��һ�ָ�Ϊһ��Ľ��̼�ͨ�Ż��ƣ��������������в�ͬ����֮��Ľ��̼�ͨ�ţ���Ӧ���൱�㷺��
 */

/*3.�ܵ�ͨ�ţ����ܵ���UNIXϵͳ���̼�ͨ��IPC���������ʽ�����е�UNIXϵͳ��֧������ͨ�Ż��ƣ�
 *��1���ܵ���Linux�н��̼�ͨ�ŵ�һ�ַ�ʽ������һ����������ֱ�����ӵ���һ����������롣Linux�Ĺܵ���Ҫ�������֣�
 *     �����ܵ��������ܵ��������ܵ�ֻ���ɸ��ӽ���ʹ�ã�����ͨ�������ܵ�������صĽ���Ҳ�ܽ������ݡ�
 *��2���ܵ��ǵ���ġ��Ƚ��ȳ��ģ�����һ�����̵��������һ�����̵�����������һ��һ�������ڹܵ���β��д�����ݣ�
 *     ��һ�����̴ӹܵ���ͷ���������ݡ������ݱ�һ�����̶����󣬽��ӹܵ���ɾ�������������̽������ٶ�����Щ���ݡ�
 *     �ܵ��ṩ�˼򵥵������ƻ��ƣ�������ͼ���չܵ�ʱ�����̽�������ͬ���ܵ��Ѿ���ʱ����������ͼ��ܵ�д�����ݣ�
 *     ����Ҳ��������
 *��3���ܵ����������ܵ��������ܵ����֡������ܵ���Ҫ���ڸ����̺��ӽ��̼��ͨ�ţ������ܵ�������������ͬһϵͳ�е�
 *     �����������̼��ͨ�š�
 */

/*4.�����ܵ�pipe���ص㣺�������ܵ���Linux�йܵ�ͨ�ŵ�һ��ԭʼ������
 *��1����ֻ�����ھ�����Ե��ϵ�Ľ���֮���ͨ�ţ�Ҳ���Ǹ��ӽ��̻����ֵܽ���֮��ͨ�š�
 *��2������һ����˫����ͨ��ģʽ�����й̶��Ķ��˺�д�ˡ�
 *��3���ܵ�Ҳ���Կ�����һ��������ļ����������Ķ�дҲ����ʹ����ͨ��read()��write()�Ⱥ���������������ͨ���ļ���
 *     �������������κ��ļ�ϵͳ����ֻ�������ڴ��С�
 */

/*5.pipe()�������÷���
 *��1������ԭ�ͣ�int pipe(int pipefd[2])��
 *��2�����ܣ�����һ�������Ĺܵ�, �õ��������õ��ļ���������
 *��3��������������������Ҫ����һ����������ĵ�ַ�������СΪ2��Ҳ����˵���ջᴫ������Ԫ�ء�
 *  ��pipefd[0]: ��Ӧ�ܵ����˵��ļ���������ͨ�������Խ����ݴӹܵ��ж�����
 *  ��pipefd[1]: ��Ӧ�ܵ�д�˵��ļ���������ͨ�������Խ�����д�뵽�ܵ��С�
 *��4������ֵ���ɹ�����0��ʧ�ܷ���-1��
 */

/*6.�����ܵ���ʹ�ã�
 *��1�������ܵ��ǹܵ���һ�֣���Ȼ������Ҳ����˵����ܵ�û�����֣����䱾���ǲ���ģ�����λ���ں��е�һ���ڴ棬
 *     �����ܵ�ӵ�йܵ����������ԡ������ܵ�ֻ��ʵ����ѪԵ��ϵ�Ľ��̼�ͨ�ţ����ӽ��̡��ֵܽ��̡�ү����̻���ֶ���̣���
 *��2���ܵ��ǻ����ļ���������ͨ�ŷ�ʽ����һ�������ܵ�����ʱ�����ᴴ�������ļ�������fd[0]��fd[1]������fd[0]�̶�
 *     ���ڶ��ܵ�����fd[1]�̶�����д�ܵ���
 *��3�������ܵ��ر�ʱֻ��Ҫ���������ļ��������رռ��ɣ���ʹ����ͨ��close()��������رո����ļ���������
 *��4����pipe()�����Ĺܵ����˴���ͬһ�������У����ڹܵ���Ҫ�������ڲ�ͬ�Ľ��̼�ͨ�ŵģ������ʵ��Ӧ����û��̫�����塣
 *     ʵ����ͨ�����Ǵ���һ���ܵ����ٵ���fork()����һ���ӽ��̣����ӽ��̻�̳и������������Ĺܵ�����ʱ���ӽ��̷ֱ�ӵ��
 *     �Լ��Ķ�дͨ����Ϊ��ʵ�ָ��ӽ���֮��Ķ�д��ֻ����޹صĶ��˻�д�˵��ļ��������رռ��ɡ��������̵�д��fd[1]��
 *     �ӽ��̵Ķ���fd[0]�رգ����ӽ���֮��ͽ�����һ�����ӽ���д�븸���̶�ȡ����ͨ����ͬ��Ҳ���Խ������̵Ķ���fd[0]��
 *     �ӽ��̵�д��fd[1]�رգ����ӽ���֮��ͽ�����һ����������д���ӽ��̶�ȡ����ͨ�������⸸���̻����Դ�������ӽ��̣�
 *     �����ӽ��̶��̳�����Ӧ��fd[0]��fd[1]����ʱֻ��Ҫ�ر���Ӧ�Ķ˿ھͿ��Խ������ӽ���֮��ĵ�ͨ����
 */

/*7.�����ܵ���дע�����
 *��1��ʹ�������ܵ�ֻ�ܹ�ʵ����ѪԵ��ϵ�Ľ��̼�ͨ�ţ��ұ���Ҫ��֤�����ڹܵ��еĵ���������
 *��2��ֻ���ڹܵ��Ķ��˴���ʱ����ܵ�д�����ݲ������塣������ܵ�д�����ݵĽ��̽��յ��ں˴�����SIGPIPE�ź�
 *     ��ͨ��ΪBroken pipe���󣩡�
 *��3����ܵ�д������ʱ��Linux������֤д���ԭ���ԣ��ܵ�������һ�п�������д���̾ͻ���ͼ��ܵ�д�����ݡ�
 *     ��������̲���ȡ�ܵ��������е����ݣ���ôд���̽���һֱ������
 *��4�����ӽ���������ʱ�����ǵ��Ⱥ���򲢲���ȷ�������Ϊ�˱�֤���ӽ����Ѿ��ر�����Ӧ���ļ�����������������������
 *     ����sleep()��������Ȼʹ�ý������߲��ǺܺõĽ�����������ʹ��ͬ���뻥���������֤���ӽ��̼������˳��
 */

/*8.�����ܵ���ʹ�ò��裺
 *��1���ڸ������д����������ܵ����õ�������������ļ���������fd3�����ܵ��Ķ��ˣ�fd4�����ܵ���д�ˡ�
 *��2�������̴����ӽ��̣������̵��ļ������������������ӽ��̵��ļ�����������Ҳ�õ�����������Ŀ���ʹ�õ��ļ���������
 *     ͨ��fd3���ܵ���fd4д�ܵ�����ʱ�����ܵ������ݵ����������ǵ���ģ�����4��������������ڹܵ���ΪĬ���������ģ�
 *     �����ӽ���ͨ��д�˽�����д��ܵ��������̵Ķ��˽����ݶ���������������ӽ��̵Ķ��˾Ͷ��������ݣ������ӽ�������
 *     �ڶ��ܵ��Ĳ����ϣ������ͻ�������ִ�����һЩ����Ҫ��Ӱ�졣���û�д����ý��̶�����д�ܵ�����ô�Ϳ��Խ�����
 *     �����Ķ��˻���д�˹رա�
 *��3��Ϊ�˱����������̶����ܵ������ǿ�������ĳ���������ڶ��������ݶ���������������ǿ��Թرս������ò�������һ��
 *     ���ļ����������������ݾ�ֻ�ܵ���Ĵ�һ����������һ���ˡ�
 */

/*9.��׼���ܵ���
 *��1����Linux���ļ��������л����ļ����ı�׼I/O����һ�����ܵ��Ĳ���Ҳ֧�ֻ����ļ����ĵ�ģʽ�����ֻ����ļ�����
 *     �ܵ���Ҫ����������һ�����ӵ���һ�����̣�һ�����Խ���һ�������Ŀ�ִ���ļ����Ĺܵ���������������ܳ��ã�
 *     ��˱�׼���ܵ��ͽ�һϵ�еĴ������̺ϲ���һ������popen()����ɡ�
 *��2��popen()������ʹ�ÿ��Դ����ٴ���ı�д������ͬʱҲ��һЩ����֮����������ܵ������ĺ�����������䣬
 *    ������popen()�����Ĺܵ�����ʹ�ñ�׼I/O�������в�����������ʹ��read()��write()һ�಻�������I/O������
 *    �ر���popen()���������ܵ�����ʹ�ú���pclose()���ú����رձ�׼I/O�������ȴ�����ִ�н�����
 */

/*10.popen()�����Ĺ������̣�
 *��1������һ���ܵ���
 *��2��fork()����һ���ӽ��̡�
 *��3���ڸ��ӽ����йرղ���Ҫ���ļ���������
 *��4��ִ��exec��������á�
 *��5��ִ�к�������ָ�������
 *��6��������ִ�н��д��ܵ��С�
 */

#include <unistd.h>       //fork(),dup(),dup2(),execlp()
#include <fcntl.h>        //fcntl()
#include <sys/types.h>    //pid_t,ssize_t
#include <sys/wait.h>     //wait(),waitpid(),WIFEXITED(),WEXITSTATUS()
#include <stdio.h>        //popen(),pclose()
#include <stdlib.h>       //exit(),malloc(),free(),system()
#include <string.h>       //strerror(),bzero()
#include <assert.h>
#include <errno.h>        //errnoȫ�ֱ���

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

#define BUFF_SIZE 256

static void pipe_test();
static void pipe_count();
static void pipe_message();   //struct

static void pipe_communicate();
static void pipe_transmit();
static void popen_test();

static void mysystem(const char* cmd);
static void fcntl_pipe();

int main(void)
{
    // pipe_test();
    // pipe_count();
    
    // pipe_communicate();
    // pipe_transmit();
    // popen_test();
	// mysystem("ls -al");
	fcntl_pipe();
	
	return 0;
}

/*�����ܵ���Ҫ���ھ���ѪԵ��ϵ�Ľ��̼�ͨ�ţ�ͬһ��������ʹ�������ܵ�����������û������ġ�
 *������ͬһ��������ʹ�������ܵ���ֻ��Ϊ��ѧϰ�����ܵ���д��ص�API��ϵͳ���á�
 */
void pipe_test()
{
	int fb[2];
	if(pipe(fb) == -1)
	{
		printf("pipe_test error: %s\n",strerror(errno));
		_exit(-1);
	}
	
	//�������ܵ�дһ�Σ������β���
	char buf[BUFF_SIZE] = {0};
	write(fb[1],"hello world\n",strlen("hello world\n"));    //fb[1]Ϊ�����ܵ���д���
	read(fb[0],buf,sizeof(buf));       //fb[0]Ϊ�����ܵ��Ķ�ȡ�ˡ���ȡ����Ժ󣬹ܵ��е����ݾͻᱻɾ����
	write(STDOUT_FILENO,buf,strlen(buf));
	
	memset(buf,0,BUFF_SIZE);
	write(fb[1],"data is 2021.05.10\n",strlen("data is 2021.05.10\n"));

	ssize_t size = 0;
#ifndef _CHANGE_WAY_   //�Թܵ�дһ�Σ������β�������
	read(fb[0],buf,sizeof(buf));       //����ܵ��е�����Ϊ�գ���ô������������
	write(STDOUT_FILENO,buf,strlen(buf));
	
	/*��Ϊ��һ�ζ�ȡʱ�����Ѿ���pipe�ܵ��е����ݶ�ȡ���ˡ����Եڶ��ζ�ȡʱ����ʵ�����Ѿ��ǿչܵ���
	 *�Կչܵ��Ķ�ȡ��������ɽ���������
	 */
	memset(buf,0,sizeof(buf));
	if((size = read(fb[0],buf,BUFF_SIZE)) > 0)   //�ܵ�������ȡ���Σ��ڶ��ζ�ȡʱ�������������ȡ�ɹ���
	{
		fwrite(buf,size,1,stdout);
	}
	else
	{
		puts("pipe_test: can't read anything from pipe");
	}
#else                  //�Թܵ�д���Σ���һ�β�������
	/*��Ϊ��һ���������ܵ���д������ʱ����û�н��ܵ�д�������Եڶ���д������ʱ������д��ɹ���
	 *ֻ�йܵ�����ʱ����������д�����ݣ��Ż����д����������
	 */
	size = write(fb[1],"welcome linux\n",strlen("welcome linux\n"));     //�ܵ�������д���Σ��ڶ���д��ʱ������������д��ɹ���
	if(size > 0)
	{
		read(fb[0],buf,BUFF_SIZE);     //��ȡ����Ժ󣬹ܵ��е����ݾͻᱻɾ����
		fwrite(buf,strlen(buf),1,stdout);
	}
	else
	{
		fputs("pipe_test: can't write anything to pipe\n",stdout);
	}
#endif
	
	close(fb[0]);
	close(fb[1]);
}

void pipe_count()
{
	int pipe_fb[2] = {-1,-1};
	if(pipe(pipe_fb) == -1)
	{
		fprintf(stdout,"pipe_count error: %s\n",strerror(errno));
		abort();
	}
	
	int sum = 0;
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("pipe_count error: ");
		_exit(-1);
	}
	
	/*�����̸�fork()�ɹ������ӽ���ʱ���ܵ������ݵ����������ǵ���ģ���4����������
     *��1��������ͨ��fd4������д��ܵ���Ȼ�󸸽�����ͨ��fd3�����ݴӹܵ��ж�����
     *��2��������ͨ��fd4������д��ܵ���Ȼ���ӽ�����ͨ��fd3�����ݴӹܵ��ж�����
     *��3���ӽ���ͨ��fd4������д��ܵ���Ȼ���ӽ�����ͨ��fd3�����ݴӹܵ��ж�����
     *��4���ӽ���ͨ��fd4������д��ܵ���Ȼ�󸸽�����ͨ��fd3�����ݴӹܵ��ж�����
     */
	if(pid == 0)
	{
		close(pipe_fb[0]);    //�ر��ӽ����ж���Ķ��˿ڣ���ʹ���ݵ���Ĵ�һ����������һ�ˡ�
		fprintf(stdout,"pipe_count: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		
		for(int i=0;i<50;++i)
		{
			sum += i;
		}
		
		printf("pipe_count: child process write data to pipe ,sum =%d\n",sum);
		write(pipe_fb[1],&sum,sizeof(int));
		
		puts("pipe_count: child process exit");
		close(pipe_fb[1]);
		exit(5);
	}
	else if(pid > 0)
	{
		close(pipe_fb[1]);   //�رո������ж����д�˿ڣ���ʹ���ݵ�����ӽ��̵�д�����򸸽��̵Ķ��ˡ�
		fprintf(stdout,"pipe_count: parent process ,pid =%d ,cpid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		pid_t retpid = -1;
		int status,result = 0,i = 50;
		do{
			retpid = waitpid(pid,&status,WNOHANG);
			if(retpid == pid)
			{
				if(WIFEXITED(status))
				{
					printf("pipe_count: waitpid() ,child process exit code %d\n",WEXITSTATUS(status));
					
					read(pipe_fb[0],&result,sizeof(result));
					fprintf(stdout,"pipe_count: parent process read data from pipe ,result =%d\n",result);
				}
				else
				{
					const char* error = "pipe_count: child process exit unexpectedly\n";
					fwrite(error,strlen(error),1,stderr);
					exit(-2);
				}
			}
			
			sum += i;
		}while(i++ < 100);
		
		if(retpid != pid)
		{
			wait(&status);
			if(WIFEXITED(status))
			{
				printf("pipe_count: wait() ,child process exit code %d\n",WEXITSTATUS(status));
				
				read(pipe_fb[0],&result,sizeof(int));
				fprintf(stdout,"pipe_count: parent process read data from pipe ,result =%d\n",result);
			}
			else
			{
				const char info[] = "pipe_count: child process exit abnormally\n";
				write(STDERR_FILENO,info,strlen(info));
				_exit(-3);
			}
		}
		
		sum += result;
		printf("pipe_count: 0~100 sum is %d\n",sum);
		
		fputs("pipe_count: parent process finish\n",stdout);
		close(pipe_fb[0]);
	}
}

void pipe_communicate()
{
	int pipe_fb[2] = {-1,-1};
	if(pipe(pipe_fb) == -1)
	{
		perror("pipe_communicate error: ");
		return ;
	}
	
	pid_t pid = fork();
	if(-1 == pid)
	{
		puts("pipe_communicate error: fork() failed");
		_exit(-1);
	}
	else if(pid == 0)
	{
		close(pipe_fb[1]);
		printf("pipe_communicate: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		
		sleep(1);   //�ӽ���sleep()����1s���ȴ������̽�����д��
		fputs("pipe_communicate: child process read data from pipe\n",stdout);
		
		ssize_t size = 0;
		char buf[BUFF_SIZE] = {0};
		if((size = read(pipe_fb[0],buf,BUFF_SIZE)) > 0)
		{
			puts(buf);
		}
		else
		{
			const char* error = "pipe_communicate: child process read() failed\n";
			fwrite(error,strlen(error),1,stderr);   //��׼�����������stdin/stdout�����л���ģ�stderr���޻����
		}
		
		puts("pipe_communicate: child process finish");
		close(pipe_fb[0]);
		exit(1);
	}
	else if(pid > 0)
	{
		close(pipe_fb[0]);
		fprintf(stdout,"pipe_communicate: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		const char* str = "Pipe test program\n";
		write(pipe_fb[1],str,strlen(str));
		
		char buf[BUFF_SIZE] = {0};
		sprintf(buf,"parent process: pid =%d ,spid =%d ,ppid =%d",getpid(),pid,getppid());
		write(pipe_fb[1],buf,strlen(buf));
		
		int status;
		int retpid = wait(&status);
		if(retpid == pid)
		{
			if(WIFEXITED(status))
			{
				printf("parent process recycle child process ,retpid =%d ,status =%d\n",retpid,WEXITSTATUS(status));
			}
			else
			{
				const char msg[] = "parent process: child process exit unexpectedly\n";
				write(STDERR_FILENO,msg,strlen(msg));
			}
		}
		else
		{
			fprintf(stdout,"parent process recycle other process ,retpid =%d\n",retpid);
		}
		
		fputs("pipe_communicate: parent process exit\n",stdout);
		close(pipe_fb[1]);
	}
}

/*�ܵ��������ǵ��������ġ���������ܵ������������̣���ô���ܵ�������Ҫ�رչܵ���д�ˣ�д�ܵ�������Ҫ�رչܵ��Ķ��ˡ�
 *��������ò�������Գ���Ľ�����һЩӰ�죬�Թܵ��Ĳ����޷�������
 */
void pipe_transmit()
{
	int fb[2] = {-1,-1};
	if(pipe(fb) == -1)    //���������ܵ�, �õ������ļ�������
	{
		printf("pipe_transmit error: %s\n",strerror(errno));
		abort();
	}
	
	//������ϵͳ����fork()ǰ����pipe()�������ӽ��̽�����̳и������е��ļ�������
	pid_t pid = fork();  //�����ӽ��̡��ܹ������ܵ����ļ������������Ƶ��ӽ�����
	if(-1 == pid)
	{
		perror("pipe_transmit error: ");
		exit(-1);
	}
	else if(pid == 0)
	{
		close(fb[0]);   //�رն���
		printf("pipe_transmit: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		
		/*���ӽ��������������ض���ԭ��������ն�����Ҫд�ܵ���
		 *���̴�ӡ����Ĭ��������նˣ��ն˶�Ӧ���ļ�������STDOUT_FILENO��
		 */
		if(dup2(fb[1],STDOUT_FILENO) != STDOUT_FILENO)   //����׼������ض��򵽹ܵ���д���
		{
			close(fb[1]);
			puts("pipe_transmit: dup2() failed");
			exit(-1);
		}
		
		close(fb[1]);  //�ӽ��̽��̿ռ䱻�滻ǰ���رչܵ��Ķ���
		if(execlp("ps","ps","-ef",NULL) == -1)
		{
			fputs("pipe_transmit: execlp() failed\n",stdout);
		}
		
		fputs("pipe_transmit: child process finish\n",stdout);  //��������滻����execlp()ִ�гɹ�����ô������ӡ����ִ��
		exit(-2);
	}
	else if(pid > 0)
	{
		close(fb[1]);  //�رչܵ���д��
		fprintf(stdout,"pipe_transmit: parent process ,pid =%d ,cpid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		/*���ܵ�ʱ����ܵ���û�����ݣ�read()��������������֮��read()���������ֱ�Ӷ����ݡ�
         *��Ҫѭ�������ݣ���Ϊ�ܵ����������ģ�д��֮��Ͳ�д�ˡ����ݱ�����֮�󣬼���д�ܵ���
		 *��ô����Ҫ�ټ��������ݡ�
		 */
		
		/*�ܵ���д�˹ر��ˣ�����ܵ���û�����ݣ��ܵ����˲���������
         *û����ֱ�ӷ���0����������ݣ������ݶ��������ݶ���֮�󷵻�0��
		 */
		int length = 0;
		char buf[16] = {0};
		while((length = read(fb[0],buf,sizeof(buf))) > 0)   //��һ�ζ�ȡ�ܵ���û�����ݣ�Ҳ������
		{
			write(STDOUT_FILENO,buf,length);   //����ʹ��printf("%s",buf)�滻����Ϊbuf��ȡ���ַ����п��ܲ�����'\0'
			memset(buf,0,sizeof(buf));
		}
		
		close(fb[0]);   //�������˳�ʱ���رչܵ���д��
		wait(NULL);     //�����ӽ�����Դ
		puts("pipe_transmit: parent process quit");
	}
}

//ʹ��popen()������ִ�С�ls -l�����ʹ��popen()�������ó����ö�С������
void popen_test()
{
	FILE *fp = popen("ls -al","r");
	if(NULL == fp)
	{
		printf("popen_test error: popen() failed\n");
		return ;
	}
	
	char buf[128] = {0};
	while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		fputs(buf,stdout);
		bzero(buf,sizeof(buf));
	}
	
	pclose(fp);
}

void mysystem(const char* cmd)
{
	assert(cmd != NULL);
	
	FILE *fp = popen(cmd,"r");
	if(fp == NULL)
	{
		perror("mysystem error: ");
		_exit(-1);
	}
	
	int size = 0;
	char buf[BUFF_SIZE] = {0};
	while((size = fread(buf,1,sizeof(buf),fp)) > 0)   //fread()һ�ζ�ȡһ���ֽڲ��ܶ�ȡ�ļ��ĳ���
	{
		fwrite(buf,size,1,stdout);
		memset(buf,0,BUFF_SIZE);
	}
}

/*ͨ��fcntl()���������ļ����������ԣ�
 *��1������Ϊ������fcntl(fd,F_SETFL,0)��
 *��2������Ϊ��������fcntl(fd,F_SETFL,O_NONBLOCK)��
 */
void fcntl_pipe()
{
	int fb[2] = {-1,-1};
	if(pipe(fb) == -1)
	{
		puts("fcntl_pipe error: create pipe failed");
		abort();
	}
	
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fcntl_pipe error: ");
		return ;
	}
	else if(pid == 0)
	{
		close(fb[0]);
		sleep(2);
		
		const char info[] = "fcntl() modify pipe";
		write(fb[1],info,strlen(info));
		
		close(fb[1]);
		exit(1);
	}
	else if(pid > 0)
	{
		close(fb[1]);
#ifndef _CHANGE_WAY_
		puts("fcntl_pipe: non-blocking pipe");
		fcntl(fb[0],F_SETFL,O_NONBLOCK);   //���ùܵ��Ķ����ļ�������Ϊ������
#else
		fputs("fcntl_pipe: blocking pipe\n",stdout);
		fcntl(fb[0],F_SETFL,0);            //���ùܵ��Ķ����ļ�������Ϊ����
#endif

		char buf[BUFF_SIZE] = {0};
		for(int i=0;i<5;++i)
		{
			read(fb[0],buf,BUFF_SIZE);
			printf("receive [%s] from pipe ,i =%d\n",buf,i);
			
			sleep(1);
			bzero(buf,sizeof(buf));
		}
		
		close(fb[0]);
		waitpid(pid,NULL,0);   //�����ȴ������ӽ�����Դ
	}
}