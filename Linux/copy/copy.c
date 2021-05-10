/*Linux�ļ����ͺ��ļ����ļ����������������������ͬ�ĸ����linux���ļ��������ļ���չ��û�й�ϵ��
 *������Windows�����������ļ���׺���������ļ����͵ģ���linux���ļ���ֻ��Ϊ�˷��������ȡ�õ����֡�
 */

//Linux�е�7���ļ����ͣ���ͨ�ļ�[-]��Ŀ¼�ļ�[d]�������ļ�[l]���ܵ�[p]���׽���[s]���ַ��豸[c]�����豸[b]

/*1.�ļ��򿪵ķ�ʽflags��
 *��1��O_RDONLY����ֻ����ʽ�򿪡�
 *��2��O_WRONLY����ֻд��ʽ�򿪡�
 *��3��O_RDWR�� �Կɶ�����д�ķ�ʽ�򿪡�
 *��4��O_CREAT������ļ��������򴴽��ļ���ʹ�ô�ѡ��ʱ��Ҫʹ��mode˵���ļ�������Ȩ�ޡ�
 *��5��O_EXCL�����ͬʱָ����O_CREAT���ļ����������
 *��6��O_TRUNC������ļ����ڣ�������ļ����ݡ�
 *��7��O_APPEND��д�ļ�ʱ��������ӵ��ļ�ĩβ��
 *��8��O_NONBLOCK�����򿪵��ļ���FIFO���ַ��豸�����豸ʱ����ѡ��Ϊ��������־λ
 */

/*2.�½��ļ�ʱָ���ļ���Ȩ��mode:
 *��1��S_IRWXU���ļ������ߵĶ���д����ִ��Ȩ��
 *��2��S_IRUSR���ļ������ߵĶ�Ȩ��
 *��3��S_IWUSR���ļ������ߵ�дȨ��
 *��4��S_IXUSR���ļ������ߵĿ�ִ��Ȩ��
 *
 *��5��S_IRWXG���ļ�������ͬ���û��Ķ���д����ִ��Ȩ��
 *��6��S_IRGRP���ļ�������ͬ���û��Ķ�Ȩ��
 *��7��S_IWGRP���ļ�������ͬ���û���дȨ��
 *��8��S_IXGRP���ļ�������ͬ���û��Ŀ�ִ��Ȩ��
 *
 *��9��S_IRWXO���������û��Ķ���д����ִ��Ȩ��
 *��10��S_IROTH���������û��Ķ�Ȩ��
 *��11��S_IWOTH���������û���дȨ��
 *��12��S_IXOTH���������û��Ŀ�ִ��Ȩ��
 */

#include <fcntl.h>          //open()��O_RDONLY��OWRONLY��O_CREAT��S_IRWXU��S_IRGRP��S_IWGRP��S_IROTH��S_IWOTH
#include <unistd.h>         //read()��write()��close()
#include <sys/types.h>      //ssize_t
#include <sys/stat.h>       //û�л�ȡ�ļ������ԣ����Կ��Բ��ð���sys/stat.hͷ�ļ�
#include <string.h>

#define BUFF_SIZE 1024

int main(void)
{
	char msg[] = "copy file.txt to copy.txt\n";
	write(STDOUT_FILENO,msg,sizeof(msg) - 1);    //��1��Ϊ��ȥ���ַ��������'\0'��β��־���Ա��������ӡ����
	
	const char* error_info = "open file.txt error\n";
	int read_fb = open("./file.txt",O_RDONLY);        //open()ʧ�ܷ���-1���ɹ������ļ�������
	if(read_fb == -1)
	{
		write(STDOUT_FILENO,error_info,strlen(error_info));
		return -1;
	}
	
	error_info = "open copy.txt failed\n";
	int write_fb = open("./copy.txt",O_WRONLY | O_CREAT,S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);   //�½���copy.txt�ļ�������Ȩ��-rwxrw-rw-��766
	if(write_fb == -1)
	{
		write(STDERR_FILENO,error_info,strlen(error_info));
		return -1;
	}
	
	ssize_t size = 0;
	char buf[BUFF_SIZE] = {0};
	while((size = read(read_fb,buf,sizeof(buf))) > 0)
	{
		write(write_fb,buf,size);
		memset(buf,0,BUFF_SIZE);
	}
	
	close(read_fb);
	close(write_fb);
	
	return 0;
}