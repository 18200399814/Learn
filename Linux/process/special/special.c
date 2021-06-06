/*1.�¶�����:�������64λϵͳ���¶����̵ĸ����̺Ų�����1�ţ�
 *��1�����������н��������ӽ��̻������У�δ���н������ӽ��̾ͳ�Ϊ�¶����̣�Orphan Process����
 *     �¶��������ջᱻinit���̣�1�Ž��̣�������������init���̶��������״̬�ռ�������
 *��2���¶�������û�и����̵Ľ��̣�Ϊ����¶������˳�ʱ�޷��ͷ���ռ�õ���Դ����Ϊ��ʬ���̣�
 *     ���̺�Ϊ1��init���̽��������Щ�¶����̣���һ����Ҳ����Ϊ������init���̾ͺ�����һ���¶�Ժ��
 *     ר�Ÿ�����¶����̵��ƺ�����ÿ������һ���¶����̵�ʱ���ں˾Ͱѹ¶����̵ĸ���������Ϊinit��
 *     ��init���̻�ѭ����wait()�����Ѿ��˳����ӽ��̡�������һ���¶����������ؽ��������������ڵ�ʱ��
 *     init���̾ͻ�������������洦������һ���ƺ�������˹¶����̲�������ʲôΣ����
 *��3������ϵͳ����⵽ĳһ�����̱���˹¶����̣���ʱ��ϵͳ�оͻ���һ���̶��Ľ�����������¶����̡�
 *     ���ʹ��Linuxû�������նˣ���������¶����̵Ľ��̾���init���̣�PID=1��������������նˣ�
 *     ��������¶����̾���������̡�
 *��4�����ӽ����˳���ʱ��, �����е��û��������Լ��ͷ�, ���ǽ����ں�����pcb��Դ�Լ��޷��ͷţ�
 *     ����Ҫ�ɸ��������ͷ��ӽ��̵�pcb��Դ���¶����̱�����֮������¶��ɵ��Ϳ��Դ����ˣ�
 *     �������Ա���ϵͳ��Դ���˷ѡ�
 */

/*2.��ʬ���̣�
 *��1�����������н����������̵�ռ�õ���Դδ�����գ������Ľ��̳�Ϊ��ʬ���̣�Zombie Process����
 *     �ӽ��������н�����������δ����wait/waitpid���������ӽ�����Դ���ӽ��̱�Ϊ��ʬ���̵�ԭ��
 *��2����ÿ�������˳���ʱ���ں��ͷŸý������е���Դ�������򿪵��ļ���ռ�õ��ڴ�ȡ�������ȻΪ�䱣��һ������Ϣ��
 *     ��Щ��Ϣ��Ҫָ���̿��ƿ����Ϣ���������̺š��˳�״̬������ʱ��ȣ���ֱ��������ͨ��wait()/waitpid()����ȡ
 *     ��״̬���ͷš���������̲�����wait()/waitpid()�Ļ�����ô�������Ƕ���Ϣ�Ͳ����ͷţ�����̺žͻ�һֱ��ռ�ã�
 *     ����ϵͳ����ʹ�õĽ��̺������޵ģ���������Ĳ����������̣�����Ϊû�п��õĽ��̺Ŷ�����ϵͳ���ܲ����µĽ��̣�
 *     �˼�Ϊ��ʬ���̵�Σ����Ӧ�����⡣
 *��3��һ���ӽ����ڵ���return��exit()�����Լ���������ʱ����ʵ����û�������ı����٣���������һ����ʬ���̡�
 *     ��ʬ�������ӽ��̽���ʱ����������û�л����ӽ���ռ�õ���Դ����ʬ��������ʧ֮ǰ�����ռ��ϵͳ��Դ��
 *     ������������˳����ӽ��̱�ϵͳ�ӹܣ��ӽ����˳���ϵͳ�������ռ�õ������Դ�������Ϊ��ʬ���̡�
 *��4����ʬ���̲��ܽ���������һ�������Ľ��̣���������Ѿ������ˣ��û�����Դ�Ѿ����ͷ��ˣ�ֻ�ǻ�ռ����һЩ
 *     �ں���Դ��PCB������ʬ���̵ĳ�������������������Ľ��̵ĸ����̲���Ϊ��ɵġ�
 *��5������ʬ���̵ķ����ǣ�ɱ�������ʬ���̵ĸ����̣�������ʬ���̵���Դ�ͱ�ϵͳ�����ˡ�ͨ��kill -9 ��ʬ����PID
 *     �ķ�ʽ�ǲ�������ʬ���̵ģ��������ֻ�Ի��ŵĽ�����Ч����ʬ�����Ѿ����ˣ���ʬ�ǲ��ܽ������ġ�
 */

/*3.��ʬ���̲����Ĺ��̣�
 *��1�������̵���fork�����ӽ��̺��ӽ�������ֱ������ֹ�����������ڴ����Ƴ��������̿��ƿ�PCB��Ȼ�������ں��С�
 *��2���ӽ��̵�״̬���EXIT_ZOMBIE�������򸸽��̷���SIGCHLD�źţ������̴�ʱӦ�õ���wait()ϵͳ��������ȡ�ӽ��̵�
 *     �˳�״̬�Լ���������Ϣ����wait����֮�󣬽�ʬ���̾���ȫ���ڴ����Ƴ���
 *��3�����һ����ʬ����������ֹ�������̵���wait�Ⱥ������ʱ��ļ�϶��һ��ܿ����ʧ������������̴Ӳ�����wait��
 *     ϵͳ�������ռ���ʬ���̣���ô��Щ���̻�һֱ�����ڴ档
 */

/*4.���⽩ʬ���̵ķ�����
 *��1��������ͨ��wait()/waitpid()�����ȴ��ӽ��̽������������ӽ�����Դ������ᵼ�¸����̹���
 *��2�����������Ҫ���������ܶ࣬���ܹ����𣬿���ͨ��signal()������Ϊ����SIGCHLD�źš�ֻҪ���ӽ���
 *     �˳��ͻ��Զ�����ָ���õĻص���������Ϊ�ӽ��̽����󣬸����̻��յ�SIGCHLD�źţ���������ص�������
 *     ����wait()/waitpid()�����˳����ӽ�����Դ��
 *��3����������̲������ӽ���ʲôʱ���������ô������signal(SIGCHLD,SIG_IGN)֪ͨ�ںˣ��Լ����ӽ��̵Ľ���
 *     ������Ȥ�������̺��Դ��źš���ô�ӽ��̽������ں˻Ὣ����գ������ٸ������̷����źš�
 *��4��������fork()һ���ӽ��̣�Ȼ������������ӽ�����fork()һ������̺��˳�����ô����̾ͻᱻinit���̽ӹܣ�
 *     ����̽�����init���̻���ա������ӽ��̵Ļ��ջ�Ҫ�Լ�����ͨ������fork()���������ʬ���̵�ԭ���ǽ�
 *     �ӽ��̳�Ϊ�¶����̣��Ӷ���ĸ����̱�Ϊinit���̣�ͨ��1�Ž��̿��Դ���ʬ���̡�
 */

/*5.exit()�� _exit()������ʹ�÷�����
 *��1�����ǿ���ͨ��exit()�� _exit()��������ǰ���̡����ǵĹ��ܺ��÷���һ���ģ��޷�����������ͷ�ļ���һ����
 *     exit()���ڱ�׼�⺯����_exit()����ϵͳ���ú���������exit()�����˳�����ʱ����ˢ��I/O��������������
 *     _exit()��������ʱ������ˢ��I/O��������
 *��2��exit()�� _exit()�����Ĳ���status���Ƿ��ظ������̵Ĳ�������8λ��Ч����������������Ƕ��ٸ�����Ҫ����д��
 */

/*5.wait()������ʹ�÷�����
 *��1��wait()��һ���������������û���ӽ����˳���������һֱ�����ȴ�������⵽�ӽ����˳��ˣ��ú����������
 *     �����ӽ�����Դ��wait()������һ�Σ�ֻ�ܻ���һ���ӽ��̵���Դ������ж���ӽ�����Ҫ��Դ���գ�������Ҫ
 *     �����ö�Ρ�
 *��2��wait()�ɹ����ر����յ��ӽ��̵Ľ���ID��û���ӽ�����Դ���Ի����ˣ��������������Զ����������-1��
 *     �����ӽ�����Դ��ʱ��������쳣��Ҳ����-1��
 *��3��WIFEXITED(status): ����1, �����������˳��ġ�
 *��4��WEXITSTATUS(status)���õ������˳�ʱ���״̬�룬�൱��return��ߵ���ֵ������exit()�����Ĳ�����
 *��5��WIFSIGNALED(status): ����1, �����Ǳ��ź�ɱ���ˡ�
 *��6��WTERMSIG(status): ��ý����Ǳ��ĸ��ź�ɱ���ģ���õ��źŵı�š�
 */

/*6.waitpid()������ʹ�÷�����
 *��1��waitpid()�������Կ�����wait()�����������棬ͨ���ú������Կ��ƻ����ӽ�����Դ�ķ�ʽ���������Ƿ�������
 *     ���⻹����ͨ���ú������о�׼��������Ծ�ȷָ������ĳ������ĳһ�������ȫ���ӽ�����Դ��
 *��2��waitpid()�ɹ����ر����յ��ӽ��̵Ľ���ID����������Ƿ������ģ������ӽ��̻������У�����0��û���ӽ�����Դ
 *     ���Ի����ˣ���������������ģ�����������ֱ�ӷ���-1�������ӽ�����Դ��ʱ��������쳣��Ҳ����-1��
 *��3��pid = -1���������е��ӽ�����Դ��wait()��һ���ģ��޲����գ�������һ���ԾͿ��Ի��ն����Ҳ����Ҫѭ�����յġ�
 *��4��pid > 0��ָ������ĳһ�����̵���Դ��pid��Ҫ���յ��ӽ��̵Ľ���ID��
 *��5��pid = 0�����յ�ǰ������������ӽ���ID��
 *��6��pid < -1��pid�ľ���ֵ���������ID����ʾҪ�������������������ӽ�����Դ��
 *��7��status: ��wait()�Ĳ�����һ���ģ�������������״ֵ̬�������status�������NULL��
 *��8��options: ���ƺ������������Ƿ�������0������Ϊ�������ĺ�wait()һ����WNOHANG������Ϊ�Ƿ������ġ�
 */

#include <unistd.h>       //fork(),sleep(),_exit()
#include <sys/wait.h>     //wait(),waitpid()
#include <sys/types.h>    //pid_t,ssize_t
#include <stdio.h>        //perror()
#include <stdlib.h>       //exit(),abort()
#include <string.h>       //strerror()
#include <errno.h>        //errno

#define _CHANFE_WAY_
#undef _CHANFE_WAY_

typedef void (*pFun)();

typedef struct Message_t
{
	char signal[16];
	pFun handle;
}Message;

static void recycle_process(int signo);

static void orphan_test();
static void zombie_test();

static void wait_recycle();
static void waitpid_recycle();
static void signal_ignore();
static void signal_handle();
static void fork_twice();

static const Message message_map[] = {
	{"orphan",orphan_test},
	{"zombie",zombie_test},
	{"wait",wait_recycle},
	{"waitpid",waitpid_recycle},
	{"ignore",signal_ignore},
	{"handle",signal_handle},
	{"fork",fork_twice}
};

/*C��������������Ĳ�����ֵ��constָ�����ͣ���ô�������һ��Ϊ����������������������ָ�룬
 *��ô�������һ����Ϊ����������
 */
int main(int argc,char **argv)
{
	puts("usage: ./special.out orphan/zombie/wait/waitpid/ignore/handle/fork");
	if(argc != 2)
	{
		// orphan_test();
		// zombie_test();
		
		// wait_recycle();
		// waitpid_recycle();
		// signal_ignore();
		// signal_handle();
		fork_twice();
		
		return -1;
	}
	
	for(int i=0;i<sizeof(message_map)/sizeof(message_map[0]);++i)
	{
		if(strcmp(argv[i],message_map[i].signal) == 0)
		{
			message_map[i].handle();
			break;
		}
	};
	
	return 0;
}

void recycle_process(int signo)
{
#ifndef _CHANFE_WAY_
	pid_t pid;
	while((pid = waitpid(-1,NULL,WNOHANG)) > 0)   //����ʬ����, -1����ȴ�����һ���ӽ���, WNOHANG��������
	{
		//ֻ�м���û�н�ʬ���̣����Ż᷵��0�������Ϳ���ȷ�����еĽ�ʬ���̶���ɱ���ˡ�
		printf("child %d terminated.\n", pid);
	}
#else
	puts("deal with child process exit");
	
	/*wait()�Ĳ���status�������汻�ռ������˳�ʱ��һЩ״̬������һ��ָ��int���͵�ָ�롣
	 *��������ӽ�������������ĺ������⣬ֻ��ѽ�ʬ������������Ϳ����趨�������ΪNULL��
	 *���wait()�ɹ��᷵�ر��ռ����ӽ��̵Ľ���ID��������ý���û���ӽ��̣����þͻ�ʧ�ܣ�
	 *��ʱwait()����-1��ͬʱerrno����ΪECHILD��
	 */
	wait(NULL);
#endif
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
		fprintf(stdout,"orphan_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		
		for(int i=0;i<10;++i)
		{
			fputs("orphan_test: child process running\n",stdout);
			sleep(1);
		}
		
		fputs("orphan_test: child process finish and exit\n",stdout);
		exit(3);
	}
	else if(pid > 0)   //�����������ӽ����˳����ӽ��̾ͱ�Ϊ�˹¶�����
	{
		printf("orphan_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		sleep(2);
		puts("orphan_test: parent process finish and exit");
		_exit(13);
	}
}

void zombie_test()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		printf("orphan_test error: %s\n",strerror(errno));
		exit(-1);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"orphan_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		sleep(2);
		
		fputs("orphan_test: child process finish and exit\n",stdout);
		_exit(4);
	}
	else if(pid > 0)   //�ӽ������ڸ������˳����Ҹ�������û�л����ӽ����˳���Դ���ӽ��̾ͱ�Ϊ�˽�ʬ����
	{
		printf("orphan_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		for(int i=0;i<10;++i)
		{
			fputs("orphan_test: parent process running\n",stdout);
			sleep(1);
		}

		puts("orphan_test: parent process finish and exit");
		exit(14);
	}
}

void wait_recycle()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		printf("wait_recycle error: %s\n",strerror(errno));
		exit(-1);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"wait_recycle: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		sleep(2);
		
		fputs("wait_recycle: child process finish and exit\n",stdout);
		_exit(5);
	}
	else if(pid > 0)   //�ӽ������ڸ������˳�������������ʹ��wait()�����ӽ����˳���Դ�������ӽ��̲����Ϊ��ʬ����
	{
		printf("wait_recycle: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		printf("wait_recycle: parent process call wait() recycle child process ,spid =%d\n",pid);

		/*���������ӽ�����Դ������һ��wait()����ֻ�ܻ���һ���ӽ��̣����Ҫ���ն���ӽ��̣�����Ҫ�������ö�Ρ�
		 *wait()���������ӽ��̳ɹ������Ѿ������ӽ��̵Ľ��̺ţ�ʧ�ܷ���-1������status���ڷ��ؽ����˳�ʱ��״̬��Ϣ��
		 *ͨ��status�������ݳ�����Ϣ�жϻ��յĽ�������ô�˳��ģ��������Ҫ����Ϣ����ָ��ΪNULL��
		 */
		int status;
		pid_t retpid = wait(&status);  //wait()������status����Ϊ����������
		if(retpid == -1)  //��û���ӽ�����Դ���Ի����˻�����ӽ�����Դ��ʱ��������쳣��wait()����ʧ�ܣ�����-1��
		{
			fprintf(stdout,"wait_recycle: parent process ,recycle child process faild\n");
			return ;
		}
		
		//ȡ��wait()��������status�е�������Ҫʹ��һЩ�꺯����WIFEXITED(),WEXITSTATUS(),WIFSIGNALED(),WTERMSIG()�ȡ�
		if(WIFEXITED(status))   //WIFEXITED(status): ����1, �����������˳���
		{
			//WEXITSTATUS(status)���õ������˳�ʱ���״̬�룬�൱��return��ߵ���ֵ������exit ()�����Ĳ���
			printf("wait_recycle: parent process ,child process exit code %d\n",WEXITSTATUS(status));
		}
		else
		{
			puts("wait_recycle: parent process, the child process exits unexpectedly");
		}
		
		for(int i=0;i<10;++i)
		{
			fputs("wait_recycle: parent process running\n",stdout);
			sleep(1);
		}

		puts("wait_recycle: parent process finish and exit");
		exit(15);
	}
}

/*��1��waitpid(-1,&status,0)��wait()û���������ȴ��ӽ����˳���
 *��2��waitpid(pid,&status,0)ָ�������ȴ����̺�Ϊpid���ӽ����˳���
 *��3��waitpid(pid,&status,WNOHANG)���ս��̺�Ϊpid���ӽ��̣����ǲ�������
 */
void waitpid_recycle()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		printf("waitpid_recycle error: %s\n",strerror(errno));
		exit(-1);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"waitpid_recycle: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		sleep(2);
		
		fputs("waitpid_recycle: child process finish and exit\n",stdout);
		_exit(6);
	}
	else if(pid > 0)   //�ӽ������ڸ������˳�������������ʹ��wait()�����ӽ����˳���Դ�������ӽ��̲����Ϊ��ʬ����
	{
		printf("waitpid_recycle: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		printf("waitpid_recycle: parent process call wait() recycle child process ,spid =%d\n",pid);

		int count = 10;
		do
		{
			/*ϵͳ����waitpid()��wait()����������ȫ��ͬ�ģ���waitpid()��������������û����ƵĲ���pid��options��
			 *�Ӷ�Ϊ���Ǳ���ṩ����һ�ָ����ķ�ʽ��
			 */
			int status;
			pid_t retpid = waitpid(pid,&status,WNOHANG);  //�ɹ�ʱ������ֹ���ӽ���ID����0����ʧ��ʱ����-1
			if(retpid == -1)  //û���ӽ�����Դ���Ի����ˣ���������������ģ�����������ֱ�ӷ���-1�������ӽ�����Դ��ʱ��������쳣Ҳ�᷵��-1��
			{
				fprintf(stdout,"waitpid_recycle: parent process ,recycle child process faild\n");
				break;
			}
			else if(retpid == 0)    //��������Ƿ������ģ������ӽ��̻������У�����0
			{
				fputs("waitpid_recycle: parent process running\n",stdout);
				sleep(1);
			}
			else if(retpid == pid)   //waitpid()�����ӽ���pid��˵���Ѿ��������ӽ�����Դ
			{
				fprintf(stdout,"waitpid_recycle: parent process capture child process exit ,retpid =%d\n",retpid);
				
				if(WIFEXITED(status))
				{
					fprintf(stdout,"waitpid_recycle: parent process ,child process exit code %d\n",WEXITSTATUS(status));
				}
				else
				{
					fputs("waitpid_recycle: parent process, the child process exits unexpectedly",stdout);
				}
			}
		}while(count--);

		puts("wait_recycle: parent process finish and exit");
		exit(16);
	}
}

void signal_ignore()
{
    //�����ӽ����˳��ź�SIGCHLD����ô�ӽ��̽������ں˻�����ӽ��̣������ٸ������̷����źš�
    signal(SIGCHLD, SIG_IGN);
	
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("signal_ignore error: ");
		_exit(-1);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"signal_ignore: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		sleep(2);
		
		fputs("signal_ignore: child process finish and exit\n",stdout);
		_exit(7);
	}
	else if(pid > 0)   //�ӽ������ڸ������˳����Ҹ�������û�л����ӽ����˳���Դ���ӽ��̾ͱ�Ϊ�˽�ʬ����
	{
		printf("signal_ignore: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		for(int i=0;i<10;++i)
		{
			fputs("signal_ignore: parent process running\n",stdout);
			sleep(1);
		}

		puts("signal_ignore: parent process finish and exit");
		exit(17);
	}
}

void signal_handle()
{
	//������׽�ӽ����˳��ź�ֻҪ�ӽ����˳�������SIGCHLD���Զ�����recycle_process()
	signal(SIGCHLD,recycle_process);
	
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("signal_handle error: ");
		_exit(-1);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"signal_handle: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		sleep(2);
		
		fputs("signal_handle: child process finish and exit\n",stdout);
		_exit(8);
	}
	else if(pid > 0)   //�ӽ������ڸ������˳����Ҹ�������û�л����ӽ����˳���Դ���ӽ��̾ͱ�Ϊ�˽�ʬ����
	{
		printf("signal_handle: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		for(int i=0;i<10;++i)
		{
			fputs("signal_handle: parent process running\n",stdout);
			sleep(1);
		}

		puts("signal_handle: parent process finish and exit");
		exit(18);
	}
}

void fork_twice()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fork_twice 1 error: ");
		exit(-1);
	}
	else if(pid == 0)
	{
		puts("fork_twice: child process create grandchild process");
		
		pid = fork();    //�ӽ��̼���fork()���������
		if(pid == -1)
		{
			printf("fork_twice 2 error: %s\n",strerror(errno));
			_exit(-1);
		}
		else if(pid == 0)  //������������������ִ�С���������̻��Ϊ�¶����̣����Բ��ù�������˳������Դ�������⡣
		{
			fprintf(stdout,"fork_twice: grandchild process ,pid =%d ,ppid =%d\n",getpid(),getppid());
			sleep(2);
		
			fputs("fork_twice: grandchild process finish and exit\n",stdout);
			_exit(9);
		}
		else if(pid > 0)
		{
			/*�ӽ��̴�����������Ժ������˳���ʹ�ӽ��̱�Ϊ�¶����̡���Ϊ�¶����̻���init����Ϊ����ʬ��
			 *����ʹ��fork()���εķ���Ҳ���Ա��⽩ʬ���̵Ĳ�����
			 */
			const char* msg = "fork_twice: child process exits immediately\n";
			fwrite(msg,strlen(msg),1,stdout);
			fflush(stdout);     //fwrite()��ȫ����ģ�����Ҫʹ��ӡ����������ն��ϣ���Ҫ�ֶ�ˢ�»�����
			exit(0);
		}
	}
	else if(pid > 0)   //�ӽ������ڸ������˳����Ҹ�������û�л����ӽ����˳���Դ���ӽ��̾ͱ�Ϊ�˽�ʬ����
	{
		/*ʹ��fork()���η�ֹ��ʬ���̲����Ĺ����У���������������ʹ��wait()/waitpid()�����ȴ������ӽ��̣�
		 *����Ϊ������ȷ֪���ӽ���ֻ��fork()������̺󣬺ܿ���˳���������ִ�кܳ�һ��ʱ�䡣����wait()��
		 *waitpid()Ҳ�������������̺ܳ�ʱ�䡣
		 */
		const char str[] = "fork_twice: parent process call waitpid() recycle child process\n";
		fwrite(str,strlen(str),1,stdout);
		fflush(stdout);
		waitpid(pid,NULL,0);   //��Ϊ��ȷ֪���ӽ��̻�ܿ��˳������Կ��������ȴ������ӽ��̡�
		
		printf("fork_twice: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		for(int i=0;i<10;++i)
		{
			fputs("fork_twice: parent process running\n",stdout);
			sleep(1);
		}

		puts("fork_twice: parent process finish and exit");
		exit(19);
	}
}