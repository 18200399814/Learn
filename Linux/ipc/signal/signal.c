/*������һ����������Դ���䵥Ԫ����ͬ����֮�����Դ�Ƕ����ģ�û�й�����������һ��������ֱ�ӷ�����һ�����̵���Դ��
 *�����̲��ǹ����ģ���ͬ������Ҫ������Ϣ�Ľ�����״̬�Ĵ��ݵȣ������Ҫ���̼�ͨ��(IPC��Inter Processes Communication)��
 */

/*1.���̼�ͨ�ŵ�Ŀ�ģ�
 *��1�����ݴ��䣺һ��������Ҫ���������ݷ��͸���һ�����̡�
 *��2��֪ͨ�¼���һ��������Ҫ����һ����һ����̷�����Ϣ��֪ͨ���Ƿ�����ĳ���¼������ӽ�����ֹʱҪ֪ͨ�����̡�
 *��3����Դ�����������֮�乲��ͬ������Դ��Ϊ��������һ�㣬��Ҫ�ں��ṩ�����ͬ�����ơ�
 *��4�����̿��ƣ���Щ����ϣ����ȫ������һ�����̵�ִ�У���Debug���̣�����ʱ���ƽ���ϣ���ܹ�������һ�����̵�
 *     ����������쳣�����ܹ���ʱ֪������״̬�ı䡣
 */

/*2.Linuxϵͳ�н��̼�ͨ�ŵ�6�ַ�ʽ��
 *��1���ܵ������������ܵ���pipe���������ܵ���named pipe���������ܵ������ھ��и����̺��ӽ���֮���ͨ�š�
 *     �����ܵ��˷��˹ܵ�û�����ֵ����ƣ���˳����йܵ������еĹ����⣬������������Ե��ϵ���̼��ͨ�š�
 *��2����Ϣ���У�message�������̿���������������Ϣ�������Ľ�������Զ�ȡ�����е���Ϣ��
 *��3���źţ�signal�����ź�����֪ͨ����������ĳ���¼��������źŵ�Ӧ�ó����ǳ��࣬��Ҫ���ڽ��̵Ŀ��ƣ�
 *     ��֪ͨ���������еĺ�̨��������˳���
 *��4�������ڴ棨shared memory����������̿��Է���ͬһ���ڴ�ռ䡣ͬһϵͳ�н���֮����ù����ڴ潻�����ݵ�
 *     Ч������ߵģ����ǹ����ڴ�û�м����Ļ��ƣ����Ծ������źŵƽ��һ����ʹ�á��ڸ����ܵ��������˳����У�
 *     �����ù����ڴ���Ϊ�����ݻ���cache��
 *��5���ź�����semaphore����Ҳ���źŵƣ����ڽ���֮��Թ�����Դ���м�����
 *��6���׽��֣�socket���������ڲ�ͬ�����֮��Ľ���ͨ�š�����ȫ���Դ���ֻ����ͬһϵͳ�н���֮��ͨ�ŵĹܵ�����Ϣ���С�
 */

/*3.�ó����ں�̨���е�2�ַ�����
 *��1���ӡ�&�����ţ�������ó����ں�̨���У�ִ�г����ʱ������������ӡ�&�����ţ���./a.out &��
 *     �ں�̨���еĳ�����Ctrl+c�޷��жϣ����Ҿ����ն��˳��ˣ��������ں�̨���С�����ն��˳��ˣ�
 *     ��̨���еĳ�����ϵͳ�йܡ�
 *��2������fork��������ִ��fork������һ���ӽ��̣�Ȼ�󸸽����˳��������ӽ��̼������У��ӽ��̽���ϵͳ�йܡ�
 */

/*4.��ֹ��̨���г����2�ַ������������ں�̨���У��뿪���ն˿��ƣ���Ctrl+c��Ҳ�޷���ֹ��
 *��1��killall ��������
 *��2�����á�ps -ef | grep ���������ҵ�����Ľ��̱�ţ�Ȼ���á�kill ���̱�š���
 */

/*5.signal�źţ����ź��ǽ��̿��Ƶ�һ���֣�
 *��1��signal�ź��ǽ���֮���໥������Ϣ��һ�ַ������ź�ȫ��Ϊ���ж��źţ�Ҳ�������жϡ�����ʵ�ʺ�ʹ�ú����жϡ�
 *��2�����ж��ź�signal����֪ͨ���̷������¼�������֮�����ͨ������kill�⺯���������ж��źš�Linux�ں�Ҳ���ܸ�
 *     ���̷����źţ�֪ͨ���̷�����ĳ���¼������ڴ�Խ�硣ע���ź�ֻ������֪ͨĳ���̷�����ʲô�¼����޷�������
 *     �����κ����ݡ�
 *��3���ź������������϶��жϻ��Ƶ�һ��ģ�⡣��ԭ����һ�������յ�һ���ź��봦�����յ�һ���ж��������˵��һ���ġ�
 *��4���ź����첽�ģ�һ�����̲���ͨ���κβ������ȴ��źŵĵ����ʵ�Ͻ���Ҳ��֪���źŵ���ʲôʱ�򵽴
 *��5���źſ���ֱ�ӽ����û��ռ���̺��ں˽���֮��Ľ������ں˽���Ҳ������������֪ͨ�û��ռ���̷�������Щϵͳ�¼���
 *     ���������κ�ʱ�򷢸�ĳһ�����̣�������֪���ý��̵�״̬��������źŵ�ǰ��δ����ִ��̬������ź����ں˱���������
 *     ֱ���ý��ָ̻�ִ���ٴ��ݸ���Ϊֹ�����һ���źű���������Ϊ����������źŵĴ��ݱ��ӳ٣�ֱ����������ȡ��ʱ�ű�
 *     ���ݸ����̡�
 *��6���ź��ǽ��̼�ͨ�Ż�����Ψһ���첽ͨ�Ż��ƣ����Կ������첽֪ͨ��֪ͨ�����źŵĽ�������Щ�¼������ˡ��źŻ��Ƴ���
 *     ����֪ͨ�⣬�����Դ��ݸ�����Ϣ��
 */

/*6.�ź��¼���������Դ��
 *��1��Ӳ����Դ�������ǰ����˼����ϵİ�ť���߳�������Ӳ�����ϣ�
 *��2�������Դ����÷����źŵ�ϵͳ������kill()��raise()��alarm()��setitimer()��sigqueue()�ȡ�
 *               �����Դ������һЩ�Ƿ�����Ȳ�����
 */
 
/*7.Linux�в����źŵĳ��������
 *��1��ͨ�����̲��������źţ��û����¡�Ctrl + c�������ݼ������SIGINT�źţ�����źŻ�ɱ����Ӧ��ĳ�����̡�
 *��2��ͨ��shell��������źţ�ͨ����kill -9 ����PID��������ֹĳһ�����̻����SIGKILL�źš�
 *��3��ͨ���������ò����źţ����ú���sleep()�����̻��յ�SIGSTOP�źţ����ȹ���
 *��4��ͨ����Ӳ�����зǷ����ʲ����źţ��������еĳ�������˷Ƿ��ڴ棬�����δ��󣬽����˳���
 */

/*8.���̶��źŵ�3�ִ�������
 *��1��SIG_IGN�����źţ����źŲ����κδ�������δ������һ������SIGKILL��SIGSTOP�������źŲ��ܱ����ԣ�
 *     �����򳬼��û��ṩ��һ����ֹ��ֹͣ���̵ķ�����
 *��2����׽�źţ������źŴ����������źŷ���ʱ��ִ����Ӧ�Ĵ�������
 *��3��SIG_DFLִ��Ĭ�϶������Ը��źŵĴ������ϵͳ��Ĭ�ϲ������󲿷ֵ��źŵ�Ĭ�ϲ�������ֹ���̡�
 */

/*9.�źŵ��������ڣ�
 *һ���������ź��������ڿ��Է�Ϊ3����Ҫ�׶Σ���3���׶���4����Ҫ�¼����̻��ģ��źŲ������ź��ڽ�����ע�ᡢ
 *�ź��ڽ�����ע����ִ���źŴ������������źŵĲ�����ע�ᡢע����ָ�źŵ��ڲ�ʵ�ֻ��ƣ��������źŵĺ���ʵ�֡�
 *����ź��Ƿ�ע���뷢���źź���kill()���źŰ�װ����signal()�޹أ�ֻ���ź�ֵ�йء����������¼���ʱ��������
 *�ź��������ڵ�һ���׶Ρ��źŴ����ж��ַ�ʽ��һ�������ں���ɵģ���ȻҲ�������û���������ɡ��źŵĴ������
 *�źŵķ��͡���׽�ʹ��������и������Ӧ�ĺ�����
 */

/*10.�źŴ�����غ�����
 *��1�������źŵĺ���: kill()��raise()�� 
 *��2����׽�źŵĺ���: alarm()��pause()��
 *��3�������źŵĺ���: signal()��sigaction()��
 */

/*11.�źŷ��ͺ���kill()��raise()��abort()��
 *��1��kill()����ͬkillϵͳ����һ�������Է����źŸ����̻�����飬ʵ����kill����ֻ��kill()������һ���û��ӿڡ�
 *     kill()������������ͨ������SIGKILL�ź���ֹ���̣�Ҳ��������̷��������źš�raise()��kill()�����������ƣ�
 *     ��raise()����ֻ��������������źš�
 *��2��kill()�������÷���
 *  �ٺ���ԭ�ͣ�int kill(pid_t pid, int sig)��
 *  �ڹ��ܣ�����ָ�����źŵ�ָ���Ľ��̣�����ĳһ�����̷���һ���źš�
 *  �۲�����pid - ����ID��sig - Ҫ���͵��źš�
 *  �ܾ������Լ�ɱ���Լ� - kill(getpid(),9)���ӽ���ɱ���Լ��ĸ����� - kill(getppid(),10)��
 *��3��raise()�������÷���
 *  �ٺ���ԭ�ͣ�int raise(int sig)��
 *  �ڹ��ܣ�����ǰ���̷���ָ�����źţ������Լ�����ĳһ���źš�
 *  �۲�����sig - ����ǰ���̷��͵��źš�
 *��4��abort()�������÷���
 *  �ٺ���ԭ�ͣ�void abort()��
 *  �ڹ��ܣ�����ǰ���̷���һ���̶��ź�SIGABRT������һ���жϺ���, �����������, 
 *          ����һ���̶��ź�SIGABRT, ɱ����ǰ���̡�
 */

/*12.�źŲ�׽����alarm()��pause()��
 *��1��alarm()Ҳ��Ϊ���Ӻ������������ڽ���������һ����ʱ��������ʱ��ָ����ʱ�䵽ʱ����������̷���SIGALARM�źš�
 *     ע��һ������ֻ����һ������ʱ�䣬����ڵ���alarm()֮ǰ�����ù�����ʱ�䣬���κ���ǰ������ʱ�䶼����ֵ�����档
 *��2��pause()�������ڽ����ý��̹���ֱ����׽���ź�Ϊֹ��ͨ�����������ж��ź��Ƿ��ѵ���
 *��3��alarm()�������÷���
 *  �ٺ���ԭ�ͣ�unsigned int alarm(unsigned int seconds)��
 *  �ڹ��ܣ�alarm()����ֻ�ܽ��е��ζ�ʱ����ʱ��ɷ����һ���źš�
 *  �۲���������ʱseconds�룬����ʱ��ɷ���һ���ź�SIGALRM����ǰ���̻��յ�����źš�SIGALRM�ź�Ĭ�ϵĴ�������
 *          �жϵ�ǰ���̡�
 *  �ܷ���ֵ������0��ʾ����ʱ��ʣ�����룬����ֵΪ0��ʾ����ʱ��ɣ��źű�������
 *��4��pause()�������÷���
 *  �ٺ���ԭ�ͣ�int pause()��
 *  �ڹ��ܣ�ʹ���ý��̹���ֱ����׽��һ���źš�ֻ��ִ����һ���źŴ������󣬹���Ž�����
 */

/*13.�źŴ����2����Ҫ������
 *��1��ʹ��signal()������
 *��2��ʹ���źż������飬�����sigaction()������
 */

/*14.�źŴ�����signal()��sigaction()��
 *��1��ʹ��signal()��������ʱ��ֻ��ָ��Ҫ������źźʹ��������ɡ�����Ҫ����ǰ32�ַ�ʵʱ�źŵĴ���
 *     �Ҳ�֧���źŴ�����Ϣ��Linux��֧��һ������׳�����µ��źŴ�����sigaction()���Ƽ�ʹ�����������
 *��2��signal()����ԭ������ָ��һ���޷���ֵ���Ҵ�һ�����β����ĺ���ָ�룬Ҳ�����źŵ�ԭʼ���ú�����
 *     ���Ÿ�ԭ���ִ����������������е�2�������������û��Զ�����źŴ������ĺ���ָ�롣
 *��3��ʹ��signal()�������Բ�׽�����в������źţ������޸Ĳ�׽�����źź�����Ϊ���źŵ��Զ��崦������һ���ص�������
 *     �ں�ͨ��signal()�õ�����ص������ĵ�ַ�����źŲ���֮��ú����ᱻ�ں˵��á�
 *��4��sigaction()������signal()�����Ĺ�����һ���ģ����ڲ�׽�����в������źţ������û��Զ�����ź���Ϊ�������ص�������
 *     ע����ںˣ��ں����źŲ���֮����������������sigaction()���Կ�����signal()�����Ǽ�ǿ�棬����������������ӣ�
 *     ��������Ҳ��ǿһЩ��
 *��5��sigaction()�����е�2���͵�3��������Ҫ�õ�sigaction�ṹ�壬��ָ�����źż��Ĵ���
 *��6��signal()�������÷���
 *  �ٺ���ԭ�ͣ�typedef void (*sighandler_t)(int)��
 *              sighandler_t signal(int signum, sighandler_t handler);��
 *  �ڹ��ܣ�������ʲôʱ������ź��ǲ�����ģ���˲������źŲ���֮����ȥ�������źŲ���֮ǰ���ṩһ��ע�ắ���� 
 *          ������׽�źš����轫������źŲ����ˣ���ί���ں˽��в�׽����ȡ��ִ���źŵ�Ĭ�϶�������ִ��ʲô����
 *          ��������signal������ָ�����������źŲ��������ص�������Զ���ᱻ���á�
 *  ��signum��������Ҫ��׽���źš�
 *  ��handler�������źŲ�׽��֮��Ĵ���������һ������ָ�롣����ص���������Ҫ����Աд�ģ����ǳ���Ա�����ã�
 *                 ���ں˵��á��ں˵��ûص�������ʱ�򣬻��������һ��ʵ�Σ���ʵ�ε�ֵ���ǲ�׽���Ǹ��ź�ֵ��
 *��7��sigaction()�������÷���
 *  �ٺ���ԭ�ͣ�int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)��
 *  �ڹ��ܣ������޸���ָ���ź�������Ĵ�������
 *  ��signum������Ҫ��׽���źš�
 *  ��act��������׽���ź�֮��Ĵ�������
 *  ��oldact��������һ�ε��øú��������źŲ�׽���õ��źŴ��������ò���һ��ָ��ΪNULL��
 *  �޷���ֵ���������óɹ�����0��ʧ�ܷ���-1��
 */

/*15.siaction�ṹ��Ķ��壺
 * struct sigaction {
 *     void     (*sa_handler)(int signum);                                    //�ɵ��źŴ�����ָ�롣
 *     void     (*sa_sigaction)(int signum, siginfo_t *info, void *context);  //�µ��źŴ�����ָ�롣
 *     sigset_t  sa_mask;                                                     //�ź�����������ʼ��Ϊ�ռ���, ������ִ���ڼ䲻�����κ��źš�
 *     int       sa_flags;	                                                  //�źŴ���ķ�ʽ��
 *     void     (*sa_restorer)(void);                                         //����
 * };
 *
 *��1��sa_handler����һ������ָ�룬ָ���źŴ����������˿���ʹ���Զ���Ĵ������⣬������ΪSIG_DFLĬ�ϴ���ʽ
 *                 ��SIG_IGN�����źš����Ĵ�����ֻ��һ�����������ź�ֵ��
 *��2��sa_sigaction: ��һ������ָ�룬ָ��ĺ������ǲ�׽�����źŵĴ�������
 *��2��sa_mask����һ���źż���������ָ�����źŴ������ִ�й�������Щ�ź�Ӧ�������Ρ��ڵ����źŲ�����ǰ��
 *              ���źż�Ҫ���뵽�źŵ��ź����μ��С�
 *��3��sa_flags���а����˺ܶ��־λ���Ƕ��źŽ��д���ĸ���ѡ���
 */

#include <unistd.h>       //fork(),pause(),sleep(),alarm(),getpid()
#include <signal.h>       //kill(),signal(),raise()
#include <sys/types.h>    //pid_t,ssize_t
#include <sys/wait.h>     //wait(),waitpid()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

static void handle(int signo);
static void safeexit(int signo);
static void mysleep(int second);

static void pause_test();
static void raise_test();
static void kill_test1();
static void kill_test2();
static void alarm_test1();
static void alarm_test2();
static void mysleep_test();

int main(int argc,char* argv[])
{
	// pause_test();
	// raise_test();
	// kill_test1();
	// kill_test2();
	// alarm_test1();
	alarm_test2();
	// mysleep_test();
	
	return 0;
}

void handle(int signo)
{
	printf("handle: deal with signal ,signo =%d\n",signo);
}

/*������������ں�̨���������ֹ����ǿ��ɱ�����Ǹ��ð취����Ϊ����ɱ��ʱ�򣬳���ͻȻ������
 *û���ͷ���Դ����Ӱ��ϵͳ���ȶ�����Ctrl+c��ֹ��ɱ��������ͬ��Ч������������̨������һ���źţ�
 *��̨�����յ�����źź󣬵���һ���������ں������ͷ���Դ������Ϳ����мƻ����˳�����ȫ�����档
 */
void safeexit(int signo)
{
	fflush(stdout);
	
	if(signo == SIGINT)
	{
		printf("\nSIGINT: ctrl + c\n");
	}
	else if(signo == SIGQUIT)
	{
		puts("\nSIGQUIT: ctrl + \\");
	}
	else if(signo == SIGTERM)
	{
		fputs("\nSIGTERM: kill + pid\n",stdout);
	}
	
	printf("process safe exit ,signo =%d\n",signo);
	exit(5);
}

//����ϵͳ���õĽ��̽���������״̬��ֱ�����źŵݴｫ�份�ѡ�
void mysleep(int second)
{
	/*����ʱ����ʱ�ź�SIGALRM�����������û�м�ʱ����ʱ����ʱ�źţ�
	 *��ô��SIGALRM�źŵ���ʱ������Ĭ����Ϊ����ֹ���̣�����˳���
	 */
	signal(SIGALRM,handle);    //�޸�SIGALRM�źŵ�Ĭ����Ϊ���Ա����źŵ���ʱ��ֹ���̡�
	alarm(second);
	
	//û�в����ź�ǰ������һֱ������pause()��������ִ�С��������ǰ���Ctrl+c����pause()�Ჶ��SIGTERM�źţ��жϵ�ǰ���̡�
	pause();
}

//pause()����ֻ��һ������ֵ��ֻ�гɹ�������Ϊ-1��ͬʱerrno��ֵ��ΪEINTR��
void pause_test()
{
#ifndef _CHANGE_WAY_
    //���û��ΪSIGUSE1�ź�ָ������ʽ����ô����Ĭ�϶���Ϊɱ�����̡�
	signal(SIGUSR1,handle);   //ʹ��kill -SIGUSE1 ���̺ţ�����ʹpause()�Ľ��̱����Ѽ���ִ�С�
#endif

	fprintf(stdout,"pause_test: pause before ,pid =%d\n",getpid());
	
	/*ֻ�е�һ���źŵݴ��Ҵ���ʽΪ����׽ʱ��pause()���������������Ľ��̲Żᱻ���ѣ�
	 *����ֻ�е��źŴ�����󣨵������û�����������pause�����ŷ���-1����errno��EINTR��
	 *���̱����Ѽ���ִ�к���ĳ���
	 */
	pause();   //pause()�յ����źŲ��ܱ����Σ���������Σ���ô���Ͳ��ܱ����ѡ�
	
	/*����źŵĴ���ʽΪĬ�ϴ���ʽ����ԣ���ôpause()�������᷵��ֵ�����źŵ�Ĭ�϶�������ֹ���̣�
	 *��ô���̽������˳�������ִ��pause()�����䡣����źű���������ô���̲��ᱻ�������һֱ������
	 */
	for(int i=0;i<10;++i)
	{
		puts("pause_test: do some work");
		sleep(1);
	}
	
	printf("pause_test: pause after ,pid =%d\n",getpid());
}

void raise_test()
{
	fprintf(stdout,"raise_test: raise(SIGSTOP) before ,pid =%d\n",getpid());
	
	//����raise()������ʹ������������SIGSTOP�źţ����������̣�ʹ������������cpu��
	raise(SIGSTOP);    //�ն���ʹ��kill -SIGCONT ���̺ţ�������SIGSTOP�ź������Ľ��̱����ѣ�����ִ�С�
	for(int i=0;i<10;++i)
	{
		puts("raise_test: do some work");
		sleep(1);
	}
	
	printf("raise_test: raise(SIGSTOP) after ,pid =%d\n",getpid());
}

void kill_test1()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("kill_test1 error: ");
		_exit(-1);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"kill_test1: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		puts("kill_test1: child process stop runing and wait signal");
		
		raise(SIGSTOP);  //�ӽ�����ʹ��raise()������������SIGSTOP�źţ�ʹ�ӽ�����ͣ��
		for(int i=0;i<5;++i)
		{
			printf("kill_test1: child process do some work ,i =%d\n",i);
			sleep(1);
		}
		
		fputs("kill_test1: child process run finished and exit\n",stdout);
		exit(3);
	}
	else if(pid > 0)
	{
		fprintf(stdout,"kill_test1: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		sleep(2);  //�ø��������ߣ�ʹ�ӽ�����ִ�С�
		puts("kill_test1: inter process communicate");
		
#ifndef _CHANGE_WAY_
		if(kill(pid,SIGKILL) == 0)  //����kill()�������ӽ��̷���SIGKILL�źţ�ɱ���ӽ��̡�
		{
			fputs("kill_test1: kill child process successfully\n",stdout);
		}
		else
		{
			puts("kill_test1: kill child process failed\n");
		}
#else
		if(kill(pid,SIGCONT) == 0)  //����kill()�������ӽ��̷���SIGCONT�źţ�ʹ�ӽ��̼���ִ�С�
		{
			fputs("kill_test1: make child process to run successfully\n",stdout);
		}
		else
		{
			puts("kill_test1: make child process to run failed\n");
		}
#endif
		int count = 10;
		do{
			int status;
			pid_t retpid = waitpid(pid,&status,WNOHANG);  //ʹ��waitpid()��ѯ�������ӽ��̵��˳���Դ����ֹ��ʬ���̵Ĳ���
			if(retpid == -1)    //��û���ӽ��̿��Ի����˻�����ӽ��̹����г���waipid()����-1��
			{
				puts("kill_test1: don't have child process");
				break;
			}
			else if(retpid == 0)  //���ӽ��̻���ִ���У�waipid()����0��
			{
				const char* str = "kill_test: child process is running\n";
				fwrite(str,strlen(str),1,stdout);
				
				str = "kill_test1: parent process do some work\n";
				write(STDOUT_FILENO,str,strlen(str));
				
				sleep(1);
			}
			else if(retpid == pid)  //�����յ��ӽ��̣�waipid()�����ӽ���pid��
			{
				fputs("kill_test1: parent process capture child process exit\n",stdout);
				
				if(WIFEXITED(status))  //�ж��ӽ����Ƿ������˳���WIFEXITED()�����������˳��ķ���1��
				{
					//WEXITSTATUS()�õ������˳�ʱ���״̬��
					printf("kill_test1: child process exit normally ,exit code =%d\n",WEXITSTATUS(status));
				}
				
				if(WIFSIGNALED(status))  //�ж��ӽ����Ƿ��ź�ɱ����WIFSIGNALED()�����Ǳ��ź�ɱ���˷���1��
				{
					//WTERMSIG()��ý����Ǳ��ĸ��ź�ɱ���ģ���õ��źŵı�š�
					printf("kill_test1: child process exit by signal ,signal number =%d\n",WTERMSIG(status));
				}
				
				break;
			}
		}while(count--);
		
		fputs("kill_test1: parent process run finished and exit",stdout);
		exit(6);
	}
}

/*��1������һ��ֻ��Ҫ��עSIGINT��SIGTERM��SIGKILL�������źš�
 *��2���������еĽ��̣������Ctrl+c��������򷢳�SIGINT�źţ��źű����2��
 *��3�����á�kill ���̱�š���killall ������������򷢳�����SIGTERM�źţ��źű����15��
 *��4�����á�kill -9 ���̱�š�����򷢳�����SIGKILL�źţ��źű����9��SIGKILL�źŲ��ܱ����ԣ�
 *     Ҳ�޷����񣬳���ͻȻ���������Գ���ֻҪ����SIGINT��SIGTERM�����źŵĴ������Ϳ����ˣ�
 *     �������źſ���ʹ��ͬһ���������ͷ���Դ��
 */
void kill_test2()
{
	printf("kill_test2 error: start ,pid =%d\n",getpid());
	
	//����ȫ�����źţ���ϣ�����򱻸���
	for(int i=1;i<=64;++i) signal(i,SIG_IGN);
	
	//�������ù��ĵ��ź�
	signal(SIGINT,safeexit);     //ctrl + c
	signal(SIGQUIT,safeexit);    //ctrl + '\'
	signal(SIGTERM,safeexit);    //kill + ���̺ţ���killĬ�Ϸ������źž���SIGTERM
	
	printf("kill_test2: process is runing");  //printf�Ǵ��л���ģ�û�м�'\n'����ӡ��Ϣ�������������
	while(1) sleep(2);   //����������ѭ��
}

void alarm_test1()
{
	fprintf(stdout,"alarm_test1: alarm before ,pid =%d\n",getpid());

	alarm(5);   //alarm()�����������������������sleep()�������������ý��̡�
	fputs("alarm_test1: continue to run\n",stdout);
	
#ifndef _CHANGE_WAY_
    /*�������̣��ȴ���ʱ���ź�SIGALRM����Ϊû��ָ��SIGALRM�źŵĴ���ʽ�����Լ�ʹpause()�����ȵ���
	 *SIGALRM�źŵĵ���������Ҳ�����������ִ���ˣ����ǻ�ִ��SIGALRM�źŵ�Ĭ�϶�������ֹ���̡�
	 */
	pause();
#endif

	for(int i=0;i<10;++i)
	{
		puts("alarm_test1: do some work");
		sleep(1);    //������5s�Ժ󣬵���ʱ���ź�SIGALRM���������̾ͻᱻ��ֹ��
	}

	printf("alarm_test1: alarm after ,pid =%d\n",getpid());  //��������5s��ͻᱻɱ������ִ�в�����һ�����
}

/*��1��ֱ��ͨ���ն������time ./signal.out
 *  real	0m1.009s      //ʵ�������õ���ʱ��
 *  user	0m0.046s      //�û�������ʹ�õ�ʱ��
 *  sys	    0m0.691s      //�ں���ʹ�õ�ʱ��
 *  real = user + sys + ���ĵ�ʱ��(Ƶ�ʵĴ��û������ں��������л�)
 *  
 *��2����ֱ��д�ն�, �������ض��򵽴����ļ��У�time ./signal.out > test.txt
 *  real	0m1.034s      //�û�ʵ��������ʱ��䳤��
 *  user	0m0.000s
 *  sys	    0m0.229s
 */

/*�ļ�IO������Ҫ�����û������ں������л�������ʽ��ͬ������֮���л���Ƶ��Ҳ��ͬ��
 *Ҳ����˵���ļ�IO���������Ż��ǿ����ṩ�����ִ��Ч�ʵġ�
 */
void alarm_test2()
{
	printf("alarm_test2: alarm before ,pid =%d\n",getpid());
	
	alarm(1);    //ʹ��alarm()��ʱ���������������1s֮�ڿ������������
	
	int i = 0;
	while(1)
	{
		printf("%d\n",++i);
	}
	
	fprintf(stdout,"alarm_test2: alarm before ,pid =%d\n",getpid());
}

void mysleep_test()
{
	printf("mysleep_test: start ,pid =%d\n",getpid());
	
	puts("mysleep_test: do some work");
	mysleep(5);
	
	fprintf(stdout,"mysleep_test: end ,pid =%d\n",getpid());
}