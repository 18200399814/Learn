/*1.�����Ͳ��е�����
 *��1��������ͬʱ������һ������CPU��ĳһ��ʱ���ֻ��Ϊĳһ��������������˲�����ͬʱ���������
 *     ��������ȥ����������ͬʱ���У���ʵ��ͨ���������CPU���ٵ�ʱ��Ƭ�л�ʵ�ֵġ�
 *��2�����������ĳһ��Ӳ����Դ���Եģ���ĳ��ʱ���֮�ڴ�����������������Խ��Ч��Խ�ߡ�
 *��3�����еĶ����ͬʱ��������ʵ���ڵģ�������ͬһʱ��ͬʱ���ж������
 *��4��������Ҫ�������CPUӲ����Դ������CPU���޷�ʵ�ֵġ�
 */

/*2.����CPU���д���������ʵ��ԭ��
 *  CPU���ÿ�����̱�����һ��ʱ��Σ����̵õ����ʱ��Ƭ֮��ſ������У�ʹ��������ӱ����Ͽ���ͬʱ���еġ�
 *  �����ʱ��Ƭ����ʱ���̻������У�CPU��ʹ��Ȩ�����ջأ��ý��̽��ᱻ�жϹ���ȴ���һ��ʱ��Ƭ���������
 *  ��ʱ��Ƭ����ǰ�������������CPU���������л��������Ϳ��Ա���CPU��Դ���˷ѡ����������ʹ�õļ������
 *  �����Ķ�����򣬴Ӻ���Ͽ���ͬʱ���еģ���΢���Ͽ�����CPUһ��ֻ�ܴ���һ�����̣���������������ִ�еģ�
 *  ֻ�����л��ٶ�̫�죬���Ǹо��������ˣ����CPU�ĺ���Խ�������Ĵ���Ч��Խ�ߡ�
 */
 
/*3.PCB��Processing Control Block�����̿��ƿ飺��Linux�ں˵Ľ��̿��ƿ鱾������һ������task_struct�Ľṹ�壩
 *��1������id��ÿһ�����̶�һ��Ψһ�Ľ���ID������Ϊpid_t, ������һ����������
 *��2�����̵�״̬�������в�ͬ��״̬��״̬��һֱ�ڱ仯�ģ��о��������С�����ֹͣ��״̬��
 *��3�����̶�Ӧ�������ַ�ռ����Ϣ��
 *��4�����������ն˵���Ϣ���������ĸ��ն�����Ĭ�Ͼͺ��ĸ��ն˰󶨡�
 *��5����ǰ����Ŀ¼��Ĭ������£��������̵�Ŀ¼���ǵ�ǰ�Ĺ���Ŀ¼
 *��6��umask���룺�ڴ������ļ���ʱ��ͨ�������������ĳЩ���ڶ��ļ��Ĳ���Ȩ�ޡ�
 *��7���ļ���������ÿ����������ļ�����������Ӧһ���Ѿ��򿪵Ĵ����ļ�
 *��8���ź���ص���Ϣ����Linux�е��ú��������̿�ݼ���ִ��shell����Ȳ�����������źš�
 *��9�������źż�����¼��ǰ������������Щ�Ѳ������źţ�ʹ�䲻�ܱ�����
 *��10��δ���źż�����¼�ڵ�ǰ�����в�������Щ�źŻ�û�б��������
 *��11���û�id����id����ǰ���������ĸ��û��������ĸ��û��顣
 *��12���Ự��Session���ͽ����飺������̵ļ��Ͻн����飬���������ļ��ϽлỰ��
 *��13�����̿���ʹ�õ���Դ���ޣ�����ʹ��shell����ulimit -a�鿴��ϸ��Ϣ��
 */
 
/*�ڶ�������У����̵�ִ��˳����û�й��ɵģ���Ϊ���еĽ��̶���Ҫ�ھ���̬����CPUʱ��Ƭ�������˾�ִ�У�
 *�������Ͳ�ִ�У����ǲ��õ��ģ�Ĭ�Ͻ��̵����ȼ�����ͬ�ģ�����ϵͳ������ĳһ������һֱ������CPUʱ��Ƭ��
 */

/*4.ִ�ж���̳���ʱ������ն���ʾ����ԭ�򣺣��¶����̾ͻ���ɣ��������н������ն���ʾ�������⡣����ʬ�����򲻻ᣩ
 *��1��a.out��������֮�󣬹������˶���ӽ��̣���ʵa.outҲ���и����̵ľ��ǵ�ǰ���նˡ�
 *��2���ն�ֻ�ܼ�⵽a.out���̵�״̬����a.outִ���ڼ��ն��л�����̨��a.outִ�����֮���ն��л���ǰ̨��
 *��3�����ն��л���ǰ̨ʱ��a.out���ӽ��̻�û��ִ����ϡ��ӽ����������Ϣ����ʾ���ն�������ʾ���ĺ���ˣ�
 *     �����ն���ʾ�����⣬���Ǵ�ʱ�ն��ǿ��Խ��ռ�������ģ�ֻ�ǿ����������۶��ѡ�
 *��4�������������Ҫ�������ӽ����˳�֮�����˳������̣����磺�ڸ����̴����е���sleep()/wait()/waitpid()��
 */

/*5.���̿��ƣ������̿�����Ҫ��ָ���̵��˳������̵Ļ��ա����̵�����״̬�����¶����̺ͽ�ʬ���̣�
 *��1���������̣������Ҫֱ���˳�ĳ�����̿����ڳ�����κ�λ�õ���exit()����_exit()�����������Ĳ����൱���˳��롣
 *     ��main()������ֱ��ʹ��return���Ҳ�����˳����̣���������һ����ͨ�����е���returnֻ�ܷ��ص������ߵ�λ�ã�
 *     �������˳����̡�
 *��2�����ս�����Դ��Ϊ�˱��⽩ʬ���̵Ĳ�����һ�����ǻ��ڸ������н����ӽ��̵���Դ���ա����շ�ʽ�����֣�
 *     һ����������ʽwait()��һ���Ƿ�������ʽwaitpid()��
 *��3���¶����̣���һ�������Ľ����д����ӽ��̣���ʱ���ӽ���ͬʱ���У����Ǹ���������ĳ��ԭ�����˳��ˣ�
 *     �ӽ��̻������У���ʱ������ӽ��̾Ϳ��Ա���֮Ϊ�¶�����
 *��4����ʬ���̣���һ�������Ľ����д����ӽ��̣���ʱ������˸����������̡�����������������У��ӽ������ڸ����̽�����
 *     �ӽ����޷��ͷ��Լ���PCB��Դ����Ҫ����������������¶����������������Ҳ���ܣ���ʱ���ӽ��̾ͱ���˽�ʬ���̡�
 */

#include <unistd.h>     //fork(),sleep(),_exit()
#include <sys/types.h>
#include <sys/wait.h>   //wait(),waitpid(),WIFEXITED(),WEXITSTATUS()
#include <stdio.h>
#include <stdlib.h>     //exit()
#include <string.h>     //strerror()
#include <errno.h>

#define BUFF_SIZE 512

#define PRINT_INFO(str)  \
	write(STDOUT_FILENO,str,strlen(str))

#define ERROR_INFO(str)  \
	write(STDERR_FILENO,str,strlen(str))

#define SAVE_INFO(fb,str)  \
	write(STDERR_FILENO,str,strlen(str))

typedef void (*pFun)();

typedef enum Signal_t
{
	EXIT,
	WAIT,
	WAITPID,
	ZOMBIE,
	ORPHAN,
	SIGNAL_COUNT
}Signal_t;

static void exit_test();
static void wait_test();
static void waitpid_test();
static void zombie_test();    //���Խ�ʬ����
static void orphan_test();    //���Թ¶�����

#ifndef _CHANGE_WAY_
static const char* signal_str[SIGNAL_COUNT] = {
	[EXIT] = "exit",
	[WAIT] = "wait",
	[WAITPID] = "waitpid",
	[ZOMBIE] = "zombie",
	[ORPHAN] = "orphan"
};

typedef struct Message_t
{
	Signal_t signal;
	pFun handle;
}Message_t;

static const Message_t message_map[SIGNAL_COUNT] = {
	{EXIT,exit_test},
	{WAIT,wait_test},
	{WAITPID,waitpid_test},
	{ZOMBIE,zombie_test},
	{ORPHAN,orphan_test}
};
#else
typedef struct Message_t
{
	char signal[16];
	pFun handle;
}Message_t;

static const Message_t message_map[SIGNAL_COUNT] = {
	{"exit",exit_test},
	{"wait",wait_test},
	{"waitpid",waitpid_test},
	{"zombie",zombie_test},
	{"orphan",orphan_test}
};
#endif

int main(int argc,char* argv[])
{
	puts("usage: ./control.out exit/wait/zombie/orphan");
	if(argc != 2)
	{
		fputs("input argument illegal or default run zombie_test\n",stdout);
#ifndef _CHANGE_WAY_
		//Ĭ�ϲ��Խ�ʬ���̵Ĳ���
		message_map[ZOMBIE].handle();
#else
		//Ĭ�ϲ��Թ¶����̵Ĳ���
		message_map[ORPHAN].handle();
#endif
		return 0;
	}

#ifndef _CHANGE_WAY_
#	pragma message("---undefined _CHANGE_WAY_---")
	for(int i=0;i < SIGNAL_COUNT;++i)
	{
		if(strcmp(argv[1],signal_str[i]) == 0 
			&& message_map[i].signal == i)
		{
			message_map[i].handle();
			return 0;
		}
	}
#else
#	pragma message("---defined _CHANGE_WAY_---")
	for(int i=0;i < SIGNAL_COUNT;++i)
	{	
		if(strcmp(argv[1],message_map[i].signal) == 0)
		{
			message_map[i].handle();
			return 0;
		}
	}
#endif
	
	return 0;
}

void exit_test()
{
#ifndef _CHANGE_WAY_
	printf("using exit()...\n");
	printf("this content will be output on exit");
	exit(0);
#else
	printf("using _exit()...\n");
	printf("this content can't be print on _exit");
	_exit(0);
#endif
}

void wait_test()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		ERROR_INFO("wait_test: fork faild\n");
		return ;
	}
	else if(pid == 0)
	{
		printf("wait_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		for(int i=0;i<8;++i)
		{
			puts("wait_test: child process runing");
			sleep(1);
		}
		
		PRINT_INFO("wait_test: child process run finished and exit\n");
		exit(100);
	}
	else if(pid > 0)
	{
		fprintf(stdout,"wait_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		fprintf(stdout,"wait_test: parent process ,wait recycle child process ,spid =%d\n",pid);
		
		int status;
#ifndef _CHANGE_WAY_
		pid_t retpid = wait(&status);   //wait(&status)�ײ�ʵ�־���waitpid(-1,&status,0)
#else
		pid_t retpid = waitpid(-1,&status,0);
#endif
		if(retpid == -1)
		{
			PRINT_INFO("wait_test: parent process ,recycle child process faild\n");
			return ;
		}
		
		if(WIFEXITED(status))   //�ж��ӽ����Ƿ������˳�
		{
			printf("wait_test: parent process, the child process exits normally - %d\n",WEXITSTATUS(status));   //��ȡ�ӽ��̵��˳���
		}
		else
		{
			puts("wait_test: parent process, the child process exits unexpectedly");
		}
		
		fputs("wait_test: parent process exit\n",stdout);
	}
}

void waitpid_test()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		ERROR_INFO("waitpid_test: fork faild\n");
		return ;
	}
	else if(pid == 0)
	{
		printf("waitpid_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		for(int i=0;i<8;++i)
		{
			puts("waitpid_test: child process runing");
			sleep(1);
		}
		
		PRINT_INFO("waitpid_test: child process run finished and exit\n");
		_exit(150);
	}
	else if(pid > 0)
	{
		fprintf(stdout,"waitpid_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		fprintf(stdout,"waitpid_test: parent process ,waitpid recycle child process ,spid =%d\n",pid);
		
		int status;
		pid_t retpid;
		do{
			retpid = waitpid(pid,&status,WNOHANG);    //ʹ��waitpid�����������ӽ����˳���Դʱ����Ҫ��ѯ�ȴ�
			if(retpid == -1)
			{
				PRINT_INFO("waitpid_test: parent process ,recycle child process faild\n");
				return ;
			}
			else if(retpid == 0)
			{
				printf("waitpid_test: parent process ,child process runing, pid =%d ,spid =%d\n",getpid(),pid);
				PRINT_INFO("waitpid_test: parent process ,do other work\n");
				sleep(2);
			}
			else if(retpid == pid)
			{
				printf("waitpid_test: parent process ,capture child process exit ,pid =%d, spid =%d\n",getpid(),pid);
				break;
			}
		}while(1);
		
		if(WIFEXITED(status))   //�ж��ӽ����Ƿ������˳�
		{
			printf("waitpid_test: parent process, the child process exits normally - %d\n",WEXITSTATUS(status));   //��ȡ�ӽ��̵��˳���
		}
		else
		{
			puts("waitpid_test: parent process, the child process exits unexpectedly");
		}
		
		puts("waitpid_test: parent process exit");
	}
}

void zombie_test()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		fprintf(stdout,"zombie_test error: %s\n",strerror(errno));
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("zombie_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		puts("zombie_test: child process run finished and exit");
		
		/*�ӽ������븸����ִ���꣬��������exit/_exit�����˳��ӽ��̣�
		 *�ӽ��̶����Ϊ��ʬ���̣��ȴ�������Ϊ����ʬ��
		 */
		exit(0);
	}
	else if(pid > 0)
	{
		printf("zombie_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		for(int i=0;i<15;++i)
		{
			puts("zombie_test: parent process runing");
			sleep(1);
		}
		puts("zombie_test: parent process run finished");
	}
}

void orphan_test()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("orphan_test error: ");
		_exit(-1);
	}
	else if(pid == 0)
	{
		printf("orphan_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		
		for(int i=0;i<15;++i)   //ǿ���ӽ��̺��ڸ������˳�, ʹ�ӽ��̱���˹¶�����
		{
			fprintf(stdout,"orphan_test: child process runing, pid =%d ,ppid =%d\n",getpid(),getppid());
			sleep(1);
		}
		fputs("orphan_test: child process run finished\n",stdout);
	}
	else if(pid > 0)
	{
		printf("orphan_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		sleep(2);   //��������ʱ2s�˳����Ա�ʹ��ps -ef | grep control.out����鿴���ӽ��̵�״̬
		puts("orphan_test: parent process run finished");
	}
}