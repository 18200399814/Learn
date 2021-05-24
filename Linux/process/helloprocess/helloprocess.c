#include <unistd.h>       //write(),sleep(),getpid(),getppid()
#include <sys/types.h>    //pid_t
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 1024

#define PRINT_INFO(str)  \
	write(STDOUT_FILENO,str,strlen(str))

int main(void)
{
	PRINT_INFO("---start main---\n");
	
	char buf[BUFF_SIZE] = {0};
	sprintf(buf,"main process id: %d\n",getpid());
	PRINT_INFO(buf);
	
	int var = 0;  //����var�ڸ��ӽ��̵�ջ�ռ��ж����ڣ����ڸ��ӽ��̿ռ��еĵ�ַ����ͬ
	
	/*fork()�������ӽ��������Ŀ����������̵�4G�ڴ�ռ䣬������ջ��Ϣ������κ����ݶΣ�
	 *���Ը��ӽ��̰�����ͬ�����д��롢ȫ�ֱ�������̬�������ַ���������
	 */
	pid_t pid = fork();   //fork()�ɹ������������з����ӽ���pid�����ӽ����з���0��fork()ʧ�ܷ���-1
	if(pid == -1)
	{
		perror("fork error: ");
		return -1;
	}
	else if(pid > 0)   //fork()�ɹ����ӽ��̶���ִ������else if(pid > 0)�жϡ�
	{
		/*���ӽ��̵Ĵ�����ж�����else if(pid > 0)�жϵ����飬ֻ�����ڸ�������pid�Ŵ���0��
		 *����ֻ�и����̲����߽������ӽ�������pid����0�����Բ���ִ����һ�δ���顣
		 */
		++var;
		int mainpid = getpid();   //��ȡ��ǰ����id�����ڵ�ǰ����Ϊ�����̣�����Ϊ��ȡ������id
		memset(buf,0,sizeof(buf));
		sprintf(buf,"this is main process, pid =%d,mainpid =%d, var =%d, &var =%p\n",pid,mainpid,var,&var);
		
		PRINT_INFO(buf);
		var++;
	}
	else if(pid == 0)  //fork()�ɹ����ӽ��̶���ִ������else if(pid = 0)�жϡ�
	{
		/*���ӽ��̵Ĵ�����ж�����else if(pid == 0)�жϵ����飬ֻ�������ӽ�����pid�ŵ���0��
		 *����ֻ���ӽ��̲����߽���������������pid����0�����Բ���ִ����һ�δ���顣
		 */
		++var;
		int subpid = getpid();   //��ȡ��ǰ����id�����ڵ�ǰ����Ϊ�ӽ��̣�����Ϊ��ȡ�ӽ���id
		memset(buf,0,sizeof(buf));
		sprintf(buf,"this is child process,pid =%d,subpid =%d, var =%d, &var =%p\n",pid,subpid,var,&var);
		
		PRINT_INFO(buf);
		var += 1;
	}
	
	//����û�����ָ��ӽ���pid�����������̺��ӽ��̶���ִ����һ�δ��롣
	memset(buf,0,BUFF_SIZE);
	sprintf(buf,"var will print twice, var =%d, &var =%p, pid =%d, getpid() =%d\n\n",var,&var,pid,getpid());
	PRINT_INFO(buf);
	
	//���������̺��ӽ��̣�����ʹ��ps -ef | grep helloprocess.out�鿴����id
	sleep(10);
	PRINT_INFO("---end main---\n");
	
	return 0;
}