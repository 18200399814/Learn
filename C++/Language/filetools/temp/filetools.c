#include "filetools.h"
#include "mydebug.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_MAX_SIZE 1024

//ʹ��fopen��ֻд�ķ�ʽ�򿪣����½�һ�����ļ�
bool newFile(const char fileName[])
{
    if(fileName == NULL)
    {
        printf("newFile failed: file name is null\n");
        return false;
    }
    
    FILE *fp = NULL;
	if((fp = fopen(fileName,"w")) == NULL)
    {
        perror("newFile failed: file can't open!");
        return false;
    }
    
    fclose(fp);
    return true;
}

//����ɹ����򷵻��㡣��������򷵻� -1
int deleteFile(const char fileName[])
{
    if(fileName == NULL)
    {
        puts("deleteFile failed: file name is null");
        return -1;
    }
    
    return remove(fileName);
}

//ɾ��Դ�ļ������½�һ��ͬ�����ļ����Դﵽ���һ���ļ���Ŀ��
bool clearFile(const char *fileName)
{
    if(fileName == NULL)
    {
        printf("clearFile failed: file name is null\n");
        return false;
    }
    
    deleteFile(fileName);
    newFile(fileName);
    
    return true;
}

//����ɹ����򷵻��㡣��������򷵻� -1
int renameFile(const char *oldName,const char newName[])
{
    if(oldName == NULL || newFile == NULL)
    {
        fprintf(stdout,"renameFile failed: old or new file name is null\n");
        return -1;
    }
    
    return rename(oldName,newName);
}

//ʹ��fopen��ֻ���ķ�ʽ�򿪣����ж��ļ��Ƿ����
bool isExistFile(const char fileName[])
{
    if(fileName == NULL)
    {
        fputs("isExistFile failed: file name is null\n",stdout);
        return false;
    }
    
    FILE *fp = fopen(fileName,"r");
	if(!fp) return false;
    
    fclose(fp);
    return true;
}

//����ļ���СΪ0������Ϊ�ļ�Ϊ��
bool isEmptyFile(const char *fileName)
{
    Assert(fileName != NULL);
    
    if(getFileSize(fileName) == 0)
    {
        return true;
    }
    return false;
}

//ʹ��fseek���ļ�ָ�������ļ�ĩβ����ʹ��ftell�����ļ�ָ�뵽�ļ���ͷ���ֽ���
int getFileSize(const char *fileName)
{
    if(fileName == NULL)
    {
        puts("getFileSize failed: file name is null");
        return -1;
    }
    
    FILE *fp = fopen(fileName,"r");
    if(fp == NULL)
    {
        perror("getFileSize failed: file can't open!");
        return -1;
    }
    
    fseek(fp,0,SEEK_END);
    int len = ftell(fp);
    
    fclose(fp);
    return len;
}

//ʹ��fgetsʵ��
int getFileRownum(const char *fileName)
{
	Assert(fileName != NULL);
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		Debug("getFileRownum failed: file can't open!");
		return -1;
	}
	
	int count_line = 0;
	char buf[BUFF_MAX_SIZE] = {0};
	while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		if('\n' == buf[strlen(buf) - 1])
		{
			count_line++;
		}
	}
	count_line++;
	
	fclose(fp);
	return count_line;
}


//��һ���ļ��е����ݣ�һ���ַ�һ���ַ��Ķ�ȡ����д������һ���ļ�                   
bool copyFile(const char *src,const char dts[])
{
    if(src == NULL || dts == NULL)
    {
        fprintf(stdout,"copyFile failed: src or dts is null\n");
        return false;
    }
    
    FILE *src_fp = fopen(src,"r");
    if(src_fp == NULL)
    {
        perror("copyFile failed: source file open failed!");
        return false;
    }
    
    FILE *dts_fp = fopen(dts,"w");
    if(dts_fp == NULL)
    {
        perror("copyFile failed: destination file open failed!");
		fclose(src_fp);
        return false;        
    }
    
    int ch = 0;
    while((ch = fgetc(src_fp)) != EOF)
    {
        fputc(ch,dts_fp);
    }
    
    fclose(src_fp);
    fclose(dts_fp);
    return true;
}

//���ļ�׷�ӵķ�ʽ���ļ�������ĩβд��һ������
bool appendLine(const char *fileName,const char *data)
{
    if(fileName == NULL || data == NULL)
    {
        printf("appendLine failed: file name or data is null\n");
        return false;
    }
    
    FILE *fp = fopen(fileName,"a");
    if(fp == NULL)
    {
        Debug("appendLine failed: file can't open!");
        return false;
    }
    fputs(data,fp);
    
    fclose(fp);
    return true;
}

//�ȴ���һ����ʱ�ļ�������Ҫ�����һ������д�롣�ٰ�Դ�ļ��е�����ȫ�����������ļ���ɾ��Դ�ļ������������ļ�
bool prependLine(const char *fileName,const char data[])
{
    if(fileName == NULL || data == NULL)
    {
        puts("prependLine failed: file name or data is null");   //puts�Զ��ӻ��з�
        return false;
    }
    
    FILE *fp = fopen(fileName,"r");
    if(fp == NULL)
    {
        Debug("prependLine failed: file can't open!");
        return false;
    }
   
	char tempFile[] = "./__temp__.txt";
	FILE *temp_fp = fopen(tempFile,"w");
	if(temp_fp == NULL)
	{
		Debug("prependLine failed: file can't open!");
		fclose(fp);
		return false;
	}
	fwrite(data,strlen(data),1,temp_fp);
	
	int read_size = 0;
	char buf[BUFF_MAX_SIZE] = {0};
	while((read_size = fread(buf,1,sizeof(buf),fp)) != 0)
	{
		fwrite(buf,read_size,1,temp_fp);
		memset(buf,0,sizeof(buf));
	}
	
	fclose(fp);
	fclose(temp_fp);
	remove(fileName);
	rename(tempFile,fileName);
	
	return true;
}

//�Ƚ�����ǰ������д����ʱ�ļ��У���д����Ҫ��������ݣ����дԴ�ļ���ʣ��ģ�ɾ��Դ�ļ�����������ʱ�ļ�
bool insertLine(const char *fileName,const int row,const char *data)
{
    if(fileName == NULL || data == NULL || row < 1)
    {
        fputs("insertLine failed: file name or data is null,or row < 1",stdout);
        return false;
    }
	
	if(row > getFileRownum(fileName))
	{
		fprintf(stdout,"insertLine failed: row greater than file rownum\n");
		return false;
	}
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		fprintf(stdout,"insertLine failed: %s can't open, line =%d\n",fileName,__LINE__);
		return false;
	}
	
	char *tempFile = "./__temp__.txt";
	FILE *temp_fp = fopen(tempFile,"w");
	if(!temp_fp)
	{
		Debug("insertLine failed: file can't open!");
		fclose(fp);
		return false;
	}
	
	char buf[BUFF_MAX_SIZE] = {0};
	for(int i=1;i<row;++i)
	{
		fgets(buf,sizeof(buf),fp);
		fputs(buf,temp_fp);
		memset(buf,0,sizeof(buf));
	}
	fputs(data,temp_fp);
	
	while(!feof(fp))
	{
		fgets(buf,sizeof(buf),fp);
		fputs(buf,temp_fp);
		memset(buf,0,sizeof(buf));
	}
	
	fclose(fp);
	fclose(temp_fp);
	remove(fileName);
	rename(tempFile,fileName);
	
	return true;
}

//��Դ�ļ�д����ʱ�ļ��У�������Ҫ�滻����ʱ��Դ�ļ�����ͬ�����ݲ�д�룬ʹ����Ҫ�滻������д����ʱ�ļ���ɾ��Դ�ļ�����������ʱ�ļ�
bool replaceLine(const char *fileName,const int row,const char *data)
{
    if(NULL == fileName || NULL == data || row < 1)
	{
        fprintf(stdout,"replaceLine failed: file name or data is null,or row < 1");
        return false;
	}
	
	if(row > getFileRownum(fileName))
	{
		Debug("replaceLine failed: row greater than file rownum");
		return false;
	}
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		fprintf(stdout,"replaceLine failed: %s can't open, line =%d\n",fileName,__LINE__);
		return false;
	}
	
	char *tempFile = "./__temp__.txt";
	FILE *temp_fp = fopen(tempFile,"w");
	if(!temp_fp)
	{
		printf("replaceLine failed: %s can't open, line =%d\n",tempFile,__LINE__);
		fclose(fp);
		return false;
	}
	
	int line_num = 0;
	char buf[BUFF_MAX_SIZE] = {0};
	while(!feof(fp))
	{
		memset(buf,0,sizeof(buf));
		if(line_num == (row - 1))
		{
			fgets(buf,sizeof(buf),fp);
			fputs(data,temp_fp);
			line_num++;
			continue;
		}
		fgets(buf,sizeof(buf),fp);
		fputs(buf,temp_fp);
		line_num++;
	}

	fclose(fp);
	fclose(temp_fp);
	remove(fileName);
	rename(tempFile,fileName);
	
	return true;
}

//��Դ�ļ�д����ʱ�ļ��У�������Ҫɾ������ʱ����������д��Դ�ļ����������м�����д��ɾ��Դ�ļ�����������ʱ�ļ�
bool deleteLine(const char *fileName,const int row)
{
	Assert(fileName != NULL);
	Assert(row > 0);
	
	if(row > getFileRownum(fileName))
	{
		Debug("deleteLine failed: row greater than file rownum");
		return false;
	}
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		fprintf(stdout,"deleteLine failed: %s can't open, line =%d\n",fileName,__LINE__);
		return false;
	}
	
	char *tempFile = "./__temp__.txt";
	FILE *temp_fp = fopen(tempFile,"w");
	if(!temp_fp)
	{
		printf("deleteLine failed: %s can't open, line =%d\n",fileName,__LINE__);
		fclose(fp);
		return false;
	}
	
	int line_num = 0;
	char buf[BUFF_MAX_SIZE] = {0};
	while(!feof(fp))
	{
		memset(buf,0,sizeof(buf));
		if(line_num == (row -1))
		{
			fgets(buf,sizeof(buf),fp);
		}
		fgets(buf,sizeof(buf),fp);
		fputs(buf,temp_fp);
		line_num++;
	}
	
	fclose(fp);
	fclose(temp_fp);
	remove(fileName);
	rename(tempFile,fileName);
	
	return true;
}

//��Դ�ļ�д����ʱ�ļ�������Ҫ��յ��к�ʱ��ʹ�û��з������ȡ��������д��
bool clearLine(const char *fileName,const int row)
{
	if(NULL == fileName || row < 1)
	{
		puts("clearLine failed: file name is null or row < 1");
		return false;
	}
	
	if(row > getFileRownum(fileName))
	{
		printf("clearLine failed: row greater than file rownum\n");
		return false;
	}
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		fprintf(stdout,"clearLine failed: %s can't open\n",fileName);
		return false;
	}
	
	char tempFile[] = "./__temp__.txt";
	FILE *temp_fp = fopen(tempFile,"w");
	if(!temp_fp)
	{
		fputs("clearLine failed: __temp__.txt can't open\n",stdout);
		fclose(fp);
		return false;
	}
	
	char buf[BUFF_MAX_SIZE] = {0};
	for(int i=0;!feof(fp);++i)
	{
		if(i == (row-1))
		{
			fgets(buf,sizeof(buf),fp);
			fputs("\n",temp_fp);
			continue;
		}
		fgets(buf,sizeof(buf),fp);
		fputs(buf,temp_fp);
	}
	
	fclose(fp);
	fclose(temp_fp);
	remove(fileName);
	rename(tempFile,fileName);
	
	return true;
}

//ʹ��fgets��ȡһ�����ݣ���ʹ��strcmp�Ƚϣ��Ƚϳɹ��ͷ����к�
int findString(const char *fileName,const char* str)
{
	Assert(fileName != NULL);
	Assert(str != NULL);
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		perror("findString failed: file can't open!");
		return -1;
	}
	
	int count_line = 0;
	char buf[BUFF_MAX_SIZE] = {0};
	while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		count_line++;
		if(strstr(buf,str) != NULL)
		{
			fclose(fp);
			return count_line;
		}
		memset(buf,0,sizeof(buf));
	}
	
	fclose(fp);
	return -1;
}

//fgetsֱ���ƶ����Զ��кŶ�ȡ
bool getLineData(const char *fileName,const int row,char* data)
{
	Assert(fileName != NULL);
	Assert(row > 0);
	
	if(row > getFileRownum(fileName))
	{
		puts("getLineData failed: row greater than file rownum\n");
		return false;		
	}
	
	FILE  *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		fprintf(stdout,"getLineData failed: %s can't open, line =%d\n",fileName,__LINE__);
		return false;
	}
	
	int line_num = 1;
	while((fgets(data,BUFF_MAX_SIZE,fp) != NULL))
	{
		if(line_num == row)
		{
			fclose(fp);
			return true;
		}
		line_num++;
	}

	fclose(fp);
	return false;
}

//��ȡ�ļ���ͷ��������
bool getStartArea(const char *fileName,const int len,char buf[],int *size)
{
	if(NULL == fileName || NULL == size || len < 1)
	{
		fputs("getStartArea failed: file name or size is null or row < 1",stdout);
		return false;
	}
	
	if(len > getFileRownum(fileName))
	{
		fputs("getStartArea failed: row greater than file rownum\n",stdout);
		return false;			
	}
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		perror("getStartArea failed: file can't open!");
		return false;
	}
	
	int ch = 0;
	int line_num = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == '\n')
		{
			line_num++;
		}
		
		if(line_num == len)
		{
			break;
		}
	}

	*size = ftell(fp) - line_num;  //�ļ���ÿ��һ�У��������һ���ַ�
	
	fseek(fp,0,SEEK_SET);
	fread(buf,*size,1,fp);
	
	fclose(fp);
	return true;
}

//��ȡ�ļ��������е�����
bool getEndArea(const char *fileName,const int len,char buf[],int *size)
{
	if(NULL == fileName || NULL == size  || len < 1)
	{
		puts("getEndArea failed: file name or size is null or row < 1");
		return false;
	}
	
	int file_size = getFileSize(fileName);
	int file_rownum = getFileRownum(fileName);
	if(len > file_rownum)
	{
		fprintf(stdout,"getEndArea failed: row greater than file rownum\n");
		return false;			
	}

	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		perror("getEndArea failed: file can't open!");
		return false;
	}

	int line_num = 0;
	char temp[BUFF_MAX_SIZE] = {0};
	do{
		if((file_rownum - len) == line_num)
		{
			break;
		}
		line_num++;
	}while(fgets(temp,sizeof(temp),fp) != NULL);
	
	int front_size = ftell(fp);
	*size = file_size - front_size + 2;
	fread(buf,*size,1,fp);
	
	printf("front_size = %d\n",front_size);
	
	fclose(fp);
	return true;
}

//�������bufֻ��һ����ָ��ʱ����̬�����ļ���С�Ŀռ����洢�����ļ�
bool getFileData(const char *fileName,char buf[],int *size)
{
	if(NULL == fileName || NULL == size)
	{
		puts("getFileData failed: file name or size is null");
		return false;
	}
	
	FILE  *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		printf("getFileData failed: %s can't open, line =%d\n",fileName,__LINE__);
		return false;
	}
	
	fseek(fp,0,SEEK_END);
	*size = ftell(fp);
	fseek(fp,0,SEEK_SET);
	fread(buf,*size,1,fp);
	
	fclose(fp);
	return true;
}

void showFile(const char fileName[])
{
	Assert(fileName != NULL);
	
	FILE *fp = NULL;
	if((fp = fopen(fileName,"r")) == NULL)
	{
		perror("showFile failed: file can't open!");
		return ;
	}
	
	int read_size = 0;
	char buf[BUFF_MAX_SIZE] = {0};
	while((read_size = fread(buf,1,sizeof(buf),fp)) != 0)
	{
		fwrite(buf,read_size,1,stdout);
		memset(buf,0,sizeof(buf));
	}

	fclose(fp);
}
