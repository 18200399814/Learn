/*Linux��Ŀ¼��һ����״�ṹ������һ������򵥵ķ�ʽ�ǵݹ顣Linux�������ṩ����ص�Ŀ¼�����ĺ�����opendir(),
 *readdir()��closedir()��DIR�ṹ��������FILE�ṹ�壬Ŀ¼�Ĳ�����ʽ�ͱ�׼C���ṩ���ļ��������������Ƶġ�
 */

/*Ŀ¼�ļ������������ļ��������Լ�ָ������Щ�ļ��йص���Ϣ��ָ�롣�Ӷ����ܹ�������dirent������ָ��Ŀ¼��
 *��ָ��Ŀ¼�еľ����ļ���readdir����ͬ��Ҳ��ȡĿ¼�µ��ļ���
 */

/*1.Ŀ¼���Խṹ��struct dirent���壺��ʹ��man 3 readdir���Բ鿴��
 * struct dirent{
 *     ino_t          d_ino;       // Inode number���ļ���Ӧ��inode���, ��λ�ļ��洢�ڴ��̵��Ǹ����ݿ��ϣ���
 *     off_t          d_off;       // Offset to the next dirent���ļ��ڵ�ǰĿ¼�е�ƫ��������
 *     unsigned short d_reclen;    // Length of this record���ļ����ֵ�ʵ�ʳ��ȣ���
 *     unsigned char  d_type;      // Type of file���ļ�������, linux����7���ļ����ͣ���
 *     char           d_name[256]; // Null-terminated filename���ļ������֣���
 * };
 */
 
/*2.dirent�ṹ���е��ļ�����d_type�������ö���Linux�е�7���ļ����ͣ�
 *��1��DT_BLK�����豸�ļ�
 *��2��DT_CHR���ַ��豸�ļ�
 *��3��DT_DIR��Ŀ¼�ļ�
 *��4��DT_FIFO ���ܵ��ļ�
 *��5��DT_LNK���������ļ�
 *��6��DT_REG ����ͨ�ļ�
 *��7��DT_SOCK�������׽����ļ�
 *��8��DT_UNKNOWN���޷�ʶ����ļ�����
 */

/*3.��ȡĳĿ¼�������ļ�����ϸ��Ϣ���裺
 *��1��ʹ��opendir()������Ŀ¼������ָ��Ŀ¼��DIR�ṹ�塣
 *��2������readdir()��������Ŀ¼�������ļ�������Ŀ¼��������ָ��Ŀ¼�������ļ���dirent�ṹ�塣
 *��3������dirent�ṹ�壬����stat()����ȡÿ���ļ�����ϸ��Ϣ���洢��stat�ṹ���С�
 * �����������һ����ϸ���Ĺ��̣�����һ�����У�DIR��dirent��stat��3�ֽṹ������Ų�ͬ�Ľ�ɫ��
*/

/*opendir()Ŀ¼��֮�󣬾Ϳ���ͨ��readdir()��������Ŀ¼�е��ļ���Ϣ�ˡ�ÿ����һ����������Ϳ���
 *�õ�Ŀ¼�е�һ���ļ���Ϣ����Ŀ¼�е��ļ���Ϣ��ȫ��������ϻ�õ�һ���ն���Ŀ¼�������֮��
 *��Ҫͨ��closedir()�ر�ͨ��opendir()�õ���ʵ�����ͷ���Դ��
 */

/*4.ͨ��readdir()����Ŀ¼�е��ļ����裺
 * DIR* dir = opendir("/home/test");      //��Ŀ¼
 *
 * struct dirent* ptr = NULL;
 * while( (ptr=readdir(dir)) != NULL)     // ����Ŀ¼
 * {
 *    .......
 * }
 *
 * closedir(dir);                         //�ر�Ŀ¼
 */

/*����ʹ�õ�DIR�ṹҲֻ�������˸ýṹ��ָ�룬��ôDIR�ṹӦ��Ҳ��ͬFILE�ṹһ����
 *�ڴ�һ��Ŀ¼��ʱ�����ں˰����Ƿ���ýṹ����ڴ档
 */

#include <fcntl.h>
#include <unistd.h>     //rmdir()
#include <sys/types.h>
#include <sys/stat.h>   //mkdir()
#include <dirent.h>     //DIR,struct dirent,opendir(),readdir(),closedir()
#include <stdio.h>      //perror()
#include <stdlib.h>
#include <string.h>     //strerror()
#include <errno.h>      //errnoȫ�ֱ���

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define BUFF_SIZE 1024

#define PRINT_INFO(str)  \
	write(STDOUT_FILENO,str,strlen(str))

#define ERROR_INFO(str)                        \
	do{                                        \
		write(STDERR_FILENO,str,strlen(str));  \
		return ;                               \
	}while(0)

#define SAVE_INFO(fb,str)  \
	write(fb,str,strlen(str))
	
static void mkdir_test();
static void rmdir_test();

static void printDir();
static void printDetail();

static void displayFile(char suffix[]);   //��������Ŀ¼
static int displayDir(const char* path);                 //�������Ŀ¼

int main(int argc,char* argv[])
{
	if(argc != 2)
	{
		PRINT_INFO("main warn: usage main.out mkdir/rmdir/ls/ls -l/ls -f/ls -d\n");
		return -1;
	}
	fprintf(stdout,"exe name: %s ,argument %s\n",argv[0],argv[1]);
	
	if(strcmp(argv[1],"mkdir") == 0)
	{
		mkdir_test();
	}
	else if(strcmp(argv[1],"rmdir") == 0)
	{
		rmdir_test();
	}
	else if(strcmp(argv[1],"ls") == 0)
	{
		printDir();
	}
	else if(strcmp(argv[1],"ls -l") == 0)
	{
		printDetail();
	}
	else if(strcmp(argv[1],"ls -f") == 0)
	{
		displayFile(".txt");
	}
	else if(strcmp(argv[1],"ls -d") == 0)
	{
		int file_count = displayDir("../io");
		printf("\ndisplayDir: have %d file in ../io\n",file_count);
	}
	else
	{
		SAVE_INFO(STDOUT_FILENO,"main: input argument illegal\n");
	}
	
	return 0;
}

void mkdir_test()
{
	int ret = mkdir("./directory",S_IRWXO | S_IRGRP | S_IROTH);
	if(ret == -1)
	{
		perror("mkdir_test error: ");
		return ;
	}
	PRINT_INFO("mkdir_test: make directory successfully\n");
	
	ret = chmod("directory",S_IRWXU | S_IRWXG |S_IRWXO);
	if(-1 == ret)
	{
		printf("mkdir_test error: %s\n",strerror(errno));
		return ;
	}
	puts("mkdir_test: change mode successfully\n");
	
	/*creat()�����ļ��൱�ڵ���open(char* filename,O_CREAT|O_WRONLY|O_TRUNC)��
	 *�������ļ��Ѿ������ˣ�����Ҫ�ٵ���open()
	 */
	 int fb = creat("directory/mkdir_test.txt",S_IRWXO | S_IRGRP | S_IWGRP | S_IRWXO);
	 if(-1 == fb)
	 {
		 PRINT_INFO("mkdir_test error: create mkdir_test.txt failed\n");
		 return ;
	 }
	 
	write(fb,"hello world\n",strlen("hello world\n"));
	SAVE_INFO(fb,"time is 2021/05/22\n");
	SAVE_INFO(fb,"this is mkdir test\n");
	
	close(fb);
}

void rmdir_test()
{
	char buf[128] = {0};
	if(getcwd(buf,sizeof(buf)) == NULL)   //��ȡ��ǰĿ¼����·��
	{
		ERROR_INFO("rmdir_test error: getcwd failed\n");
	}
	printf("rmdir_test: current directory is %s\n",buf);
	
	//ʹ��C���е�remove����ɾ���ļ���Linux��û��ɾ���ļ�ϵͳ����
	if(remove("directory/mkdir_test.txt") == -1)
	{
		perror("rmdir_test error: ");
		return ;
	}
	
	//rmdir()ֻ��ɾ����Ŀ¼������Ŀ¼ɾ��ʱ����Ҫ��Ŀ¼�е��ļ����
	if(rmdir("./directory") == -1)
	{
		printf("rmdir_test error: %s\n",strerror(errno));
		return ;
	}
	PRINT_INFO("rmdir_test: remove directory successfully\n");
}

void printDir()
{
	DIR *dir = opendir("..");    //��Ŀ¼
	if(dir == NULL)
	{
		fprintf(stderr,"printDir error: %s\n",strerror(errno));
		return ;
	}
	
	struct dirent* entity = NULL;
	while((entity = readdir(dir)) != NULL)    //������Ŀ¼�е������ļ�
	{
		if(strncmp(entity->d_name,".",1) == 0
			|| strncmp(entity->d_name,"..",2) == 0)      //���˵���ǰĿ¼����һ��Ŀ¼
		{
			continue;
		}
		
		printf("%s\n",entity->d_name);
	}
	
	closedir(dir);    //�ر�Ŀ¼
}

void printDetail()
{
	DIR *dir = opendir(".");
	if(dir == NULL)
	{
		ERROR_INFO("printDetail error: can't open directory failed\n");
	}
	
	char buf[32] = {0};
	struct dirent* entity = NULL;
	while((entity = readdir(dir)) != NULL)
	{
		switch(entity->d_type){
		case DT_BLK:
			strcpy(buf,"block device");
			break;
		case DT_CHR:
			strcpy(buf,"charactor device");
			break;
		case DT_DIR:
			strncpy(buf,"directory",strlen("directory") + 1);
			break;
		case DT_FIFO:
			strncpy(buf,"named pipe(FIFO)",strlen("named pipe(FIFO)") + 1);
			break;
		case DT_LNK:
			memcpy(buf,"symbolic link",strlen("symbolic link") + 1);
			break;
		case DT_REG:
			memcpy(buf,"regular file",strlen("regular file") + 1);
			break;
		case DT_SOCK:
			sprintf(buf,"Unix domain socket");
			break;
		case DT_UNKNOWN:
			sprintf(buf,"could not be determined");
			break;
		}
		
		printf("d_ino: %ld, d_off: %ld, d_reclen: %d,d_type: %s, d_name: %s\n",
				entity->d_ino,entity->d_off,entity->d_reclen,buf,entity->d_name);
		memset(buf,0,sizeof(buf));
	}
	
	closedir(dir);
}

void displayFile(char suffix[])
{
	if(suffix == NULL)
	{
		ERROR_INFO("displayFile error: input argument suffix is null\n");
	}
	
	DIR *dir = opendir("directory");
	if(dir == NULL)
	{
		ERROR_INFO("displayFile error: can't open directory\n");
	}
	
	int count = 0;
	struct dirent* entity = NULL;
	while((entity = readdir(dir)) != NULL)
	{
		if((strcmp(entity->d_name,".") == 0)
			|| strncmp(entity->d_name,"..",strlen("..") == 0))
		{
			continue;
		}
		
		if(entity->d_type == DT_REG)
		{
#ifndef _CHANGE_WAY_
			char *str = strstr(entity->d_name,suffix);
			if(str != NULL && *(str + strlen(suffix)) == '\0')
			{
				++count;
				printf("%s\n",entity->d_name);
			}
#else
			char *str = strchr(entity->d_name,'.');
			if(str != NULL && strcmp(str,suffix) == 0)
			{
				++count;
				printf("%s\n",entity->d_name);
			}
#endif
		}
	}
	
	printf("%s count is %d\n",suffix,count);
	closedir(dir);
}

/*Linux��Ŀ¼����״�ṹ������ÿ��Ŀ¼�ķ�ʽ����һ���ģ�Ҳ����˵��򵥵ı�����ʽ�ǵݹ顣
 *�ݹ�����ļ��г�����ص����ȷ���ݹ�������������������ļ��������Ŀ¼���;ͽ����ݹ顣
 */
int displayDir(const char* path)
{
	if(path == NULL)
	{
		return 0;
	}
	puts(path);
	
	DIR *dir = opendir(path);
	if(dir == NULL)
	{
		perror("displayDir error: ");
		return 0;
	}
	
	int count = 0;
	struct dirent* entity = NULL;
	while((entity = readdir(dir)) != NULL)
	{
		if((strcmp(entity->d_name,".") == 0) 
			|| strncmp(entity->d_name,"..",strlen("..")) == 0)
		{
			continue;
		}
		
		if(entity->d_type == DT_REG)
		{
			count++;
			fprintf(stdout,"%s\n",entity->d_name);
		}
		else if(entity->d_type == DT_DIR)
		{
			char newPath[1024] = {0};
			sprintf(newPath,"%s/%s",path,entity->d_name);
			count += displayDir(newPath);       //�ݹ����Ŀ¼������Ŀ¼�е��ļ�
		}
	}
	
	closedir(dir);
	return count;
}