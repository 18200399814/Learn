#include "fileoperate.h"
#include "mydebug.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_MAX_SIZE 1024

//����ļ����ݴ洢�ṹ�е����ݣ���ͷ��㱣��
static void clearFileData(FileData *fileData);

FileData* openFile(const char fileName[])
{
	Assert(fileName != NULL);               //�ж��ļ����Ƿ����
	
	FILE *fp = fopen(fileName,"r");         //�����ж��ļ��Ƿ����
	if(NULL == fp)
	{
		perror("openFile failed: file is't exist\n");
		return NULL;
	}
	fclose(fp);
	
	FileData *headNode = (FileData*)malloc(sizeof(FileData));    //�����ļ�����ͷ��㣬����ʼ��
	if(NULL == headNode)
	{
		puts("openFile warn: headNode malloc failed\n");
		return NULL;
	}
	headNode->row = 0;
	headNode->size = -1;
	headNode->buf = NULL;
	headNode->next = NULL;
	
	return headNode;
}

void closeFile(FileData** fileData)
{
	if(NULL == *fileData)           //���������жϣ��ж��ļ������Ƿ�Ϊ��
	{
		fprintf(stdout,"closeFile warn: fileData is null\n");
		return ;
	}
	
	clearFileData(*fileData);       //����ļ����ݴ洢�ṹ�е�����
	
	free(*fileData);                //�����ļ����ݴ洢�ṹͷ���
	*fileData = NULL;
}

bool readFile(const char *fileName,FileData *fileData)
{
	if(!fileName || fileData == NULL)       //���������жϣ��ж��ļ��������ļ������Ƿ�Ϊ��
	{
		printf("readFile failed: fileName or filedata is null\n");
		return false;
	}
	
	FILE *fp = fopen(fileName,"r");         //��ֻ����ʽ���ļ�
	if(NULL == fp)
	{
		perror("readFile failed: fopen error\n");
		return false;
	}
	
	int rownum = 0;
	FileData *p = fileData;
	char buf[BUFF_MAX_SIZE] = {0};
	while(fgets(buf,sizeof(buf),fp) != NULL)       //ѭ����ȡ�ļ�����
	{
		rownum++;                                  //ÿ��ȡһ���ļ��кż�1
		FileData* newNode = (FileData*)malloc(sizeof(FileData));    //�������ڴ洢һ���ļ�������Ϣ�����ݿ�
		if(newNode == NULL)
		{
			puts("readFile failed: newNode malloc failed\n");
			fclose(fp);
			return false;
		}
		newNode->row = rownum;              //�����ȡ��һ���ļ����ݵ��к�
		newNode->size = strlen(buf)+1;      //�����ȡ��һ���ļ����ݵĴ�С
		
		newNode->buf = (char*)malloc(strlen(buf)+1);     //���ݶ�ȡ����һ���ļ����ݴ�С������һ���ڴ�ռ����ڴ洢��ȡ����һ���ļ�����
		if(NULL == newNode->buf)
		{
			fputs("readFile failed: newNode->buf malloc failed\n",stdout);
			free(newNode);
			fclose(fp);
			return false;
		}
		memcpy(newNode->buf,buf,strlen(buf)+1);      //����ȡ����һ���ļ����ݣ��������¿��ٵ��ڴ�ռ�
		memset(buf,'\0',sizeof(buf));
		newNode->next = NULL;
		
		p->next = newNode;       //���´�����������һ���ļ���Ϣ�����ݿ飬���뵽�ļ��洢���ݽṹ��
		p = p->next;
	}
	
	fclose(fp);        //�رմ��ļ�
	return true;
}

bool writeFile(FileData *fileData,const char *fileName)
{
	if(fileName == NULL || fileData == NULL)         //���������жϣ��ж��ļ��������ļ������Ƿ�Ϊ��
	{
		printf("writeFile failed: fileName or filedata is null\n");
		return false;
	}
	
	FILE *fp = fopen(fileName,"w");        //��ֻд��ʽ���ļ�
	if(NULL == fp)
	{
		perror("writeFile failed: fopen error\n");
		return false;
	}
	
	FileData *p = fileData->next;          //���ļ������У�ÿ�����ݿ鱣���һ���ļ����ݣ�д��������ļ�����
	while(NULL != p)
	{
		if(p->buf != NULL)
		{
			fputs(p->buf,fp);
		}
		p = p->next;
	}
	
	fclose(fp);         //�رմ��ļ�
	return true;
}

bool newFile(const char fileName[])
{
    if(fileName == NULL)        //�ж�������ļ����Ƿ�Ϊ��
    {
        printf("newFile failed: file name is null\n");
        return false;
    }
    
    FILE *fp = NULL;
	if((fp = fopen(fileName,"w")) == NULL)        //��ֻд��ʽ���ļ�������ļ��������򴴽�һ���µĿ��ļ�������ļ��������ļ����
    {
        perror("newFile failed: file can't create!\n");
        return false;
    }
    
    fclose(fp);         //�رմ��ļ�
    return true;
}

int deleteFile(const char fileName[])
{
    if(fileName == NULL)        //�ж�������ļ����Ƿ�Ϊ��
    {
        puts("deleteFile failed: file name is null");
        return -1;
    }
    
    return remove(fileName);       //ɾ���ļ�
}

bool clearFile(const char *fileName)
{
    if(fileName == NULL)        //�ж�������ļ����Ƿ�Ϊ��
    {
        printf("clearFile failed: file name is null\n");
        return false;
    }
	
	FILE *fp = fopen(fileName,"r");     //�����ж��ļ��Ƿ����
	if(NULL == fp)
	{
		fprintf(stdout,"clearFile failed: file isn't exist\n");
		return false;
	}
	fclose(fp);
	fp = NULL;
    
	fp = fopen(fileName,"w");          //����ļ����ڣ����ļ����
	if(NULL == fp)
	{
		Debug("clearFile failed: fopen error\n");
		return false;
	}
	fclose(fp);
    
    return true;
}

bool isExistFile(const FileData *fileData)
{
	if(fileData == NULL)
	{
		return false;
	}
    
	return true;
}

bool isEmptyFile(const FileData *fileData)
{
	if(fileData == NULL || fileData->next == NULL)
	{
		return true;
	}
	
	return false;
}

int getFileSize(const FileData *fileData)
{
    if(fileData == NULL)       //�ж��ļ������Ƿ�Ϊ��
    {
        puts("getFileSize failed: fileData is null");
        return -1;
    }
    
	int file_size = 0;
	const FileData *p = fileData;
	while(p->next != NULL)              //�����ļ����ݣ�����ÿһ���ļ����ݵĴ�С���������͵��������ļ��Ĵ�С
	{
		file_size += p->next->size;
		p = p->next;
	}
	
	if(p->buf[p->size - 2] != '\n')     //�ļ��Ľ�β����һ��'\0'�������
	{
		file_size--;
	}
	
	return file_size;
}

int getFileRow(const FileData *fileData)
{
    if(fileData == NULL)        //�ж��ļ������Ƿ�Ϊ��
    {
        puts("getFileRow failed: fileData is null");
        return -1;
    }
	
	const FileData *p = fileData;        //���ļ�����ָ�룬�ƶ����ļ����ݴ洢�ṹ���һ��
	while(p->next != NULL)
	{
		p = p->next;
	}
	
	if(p->buf[p->size - 2] == '\n')      //�����ļ����һ���Ƿ�����з������ļ������ļ�������
	{
		return p->row + 1;
	}
	
	return p->row;       //�ļ����һ�в������з�ʱ���ļ����һ�е��кž��������ļ�������
}

int renameFile(const char *oldName,const char newName[])
{
    if(oldName == NULL || newFile == NULL)        //�ж�������ǰ������������ļ����Ƿ�Ϊ��
    {
        fprintf(stdout,"renameFile failed: old or new file name is null\n");
        return -1;
    }
    
    return rename(oldName,newName);
}

bool copyFile(const char *srcFile,const char dtsFile[])
{
    if(srcFile == NULL || dtsFile == NULL)         //�жϸ���ǰ�͸��ƺ���ļ����Ƿ�Ϊ��
    {
        fprintf(stdout,"copyFile failed: srcFile or dtsFile is null\n");
        return false;
    }
    
    FILE *src_fp = fopen(srcFile,"r");      //��ֻ����ʽ�򿪸���ǰ�ļ�
    if(src_fp == NULL)
    {
        perror("copyFile failed: source file open failed!");
        return false;
    }
    
    FILE *dts_fp = fopen(dtsFile,"w");     //��ֻд��ʽ�򿪸��ƺ��ļ�
    if(dts_fp == NULL)
    {
        perror("copyFile failed: destination file open failed!");
		fclose(src_fp);
        return false;        
    }
    
    int ch = 0;                            //����4���ֽڵĿռ䣬���ڴ洢��ȡ���ַ�
    while((ch = fgetc(src_fp)) != EOF)     //һ���ַ�һ���ַ��Ĵ�Դ�ļ��ж�ȡ�ļ���������д��Ŀ���ļ�
    {
        fputc(ch,dts_fp);
    }
    
    fclose(src_fp);        //�ر�Ŀ���ļ���Դ�ļ�
    fclose(dts_fp);
    return true;
}

bool appendLine(FileData *fileData,const char *data)
{
	if(fileData == NULL || data == NULL)     //�ж�������ļ����ݺ���Ҫ׷�ӵ��ļ������Ƿ�Ϊ��
	{
        fprintf(stdout,"appendLine failed: fileData or data is null\n");
        return false;		
	}
	
	int rownum = 0;
	FileData *p = fileData;      //���ļ�����ָ�룬�ƶ����ļ����ݴ洢�ṹ���һ��
	while(p->next != NULL)
	{
		p = p->next;
		rownum++;
	}
	rownum++;            //��Ϊ��׷��һ�����ݣ������ܵ��к���Ҫ��1
	
	FileData *newNode = (FileData*)malloc(sizeof(FileData));     //��������׷��һ���ļ�������Ϣ�����ݿ飬����ʼ��
	if(newNode == NULL)
	{
		fputs("appendLine failed: newNode malloc failed\n",stdout);
		return false;
	}
	newNode->row = rownum;
	newNode->size = strlen(data)+1;

	newNode->buf = (char*)malloc(strlen(data)+1);    //����׷�ӵ�һ���ļ����ݴ�С������һ���ڴ�ռ����ڴ洢׷�ӵ�һ���ļ�����
	if(newNode->buf == NULL)
	{
		puts("appendLine failed: newNode->buf malloc failed\n");
		free(newNode);
		return false;
	}
	memcpy(newNode->buf,data,strlen(data)+1);       //��׷�ӵ�һ���ļ����ݣ��������¿��ٵ��ڴ�ռ�
	newNode->next = NULL;

	p->next = newNode;        //��׷�Ӳ�������һ���ļ���Ϣ�����ݿ飬���뵽�ļ��洢���ݽṹ��
	return true;
}

bool prependLine(FileData *fileData,const char data[])
{
	if(fileData == NULL || data == NULL)       //�ж�������ļ����ݺ���Ҫ��ӵ��ļ������Ƿ�Ϊ��
	{
        printf("prependLine failed: fileData or data is null\n");
        return false;		
	}
	
	FileData *newNode = (FileData*)malloc(sizeof(FileData));    //�����������һ���ļ�������Ϣ�����ݿ飬����ʼ��
	if(newNode == NULL)
	{
		puts("prependLine failed: newNode malloc failed");
		return false;		
	}
	newNode->row = 1;
	newNode->size = strlen(data)+1;
	
	newNode->buf = (char*)malloc(newNode->size);    //������ӵ�һ���ļ����ݴ�С������һ���ڴ�ռ����ڴ洢��ӵ�һ���ļ�����
	if(newNode->buf == NULL)
	{
		puts("prependLine failed: newNode->buf malloc failed\n");
		free(newNode);
		return false;		
	}
	memcpy(newNode->buf,data,newNode->size);     //����ӵ�һ���ļ����ݣ��������¿��ٵ��ڴ�ռ�
	newNode->next = fileData->next;
	
	if(data[strlen(data)-1] == '\n')        //���ļ���ͷ��ӵ�һ�����ݰ������з����������ÿ�����ݵ��кŶ�Ҫ��1
	{
		FileData *p = fileData->next;
		while(p != NULL)
		{
			(p->row)++;
			p = p->next;
		}
	}
	
	fileData->next = newNode;      //����Ӳ�������һ���ļ���Ϣ�����ݿ飬���뵽�ļ��洢���ݽṹ��
	return true;
}

bool deleteLine(FileData *fileData,const int row)
{
	if(fileData == NULL || row < 1)      //�ж��ļ������Ƿ�Ϊ�գ��͸�����ɾ���к��Ƿ�С��1����ɾ�����к�С��1ʱ���Ϸ�
	{
        printf("deleteLine failed: fileData is null,or row<1\n");
        return false;		
	}
	
	if(row > getFileRow(fileData))      //�ж�ɾ�����ݵ��к��Ƿ�������ļ�������кţ�����������ܽ���ɾ������
	{
		fputs("deleteLine failed: row is greater than file total row",stdout);
		return false;
	}
	
	FileData *q = NULL;
	FileData *p = fileData;
	for(int i=1;i<row;++i)         //���ļ�����ָ�룬�ƶ�����Ҫɾ�����кŵ�ǰһ��
	{
		p = p->next;
	}
	q = p->next->next;
	
	if(p->next->buf != NULL)      //��ָ���кŵ��������ݺ���Ϣfree��
	{
		free(p->next->buf);
		p->next->buf = NULL;
	}
	free(p->next);
	p->next = q;            //����Ҫɾ���к��Ժ�����ݿ飬���뵽�ļ��洢���ݽṹ��
	
	while(q != NULL)        //�޸�ɾ����ָ���к��Ժ�����ݣ����кŶ���1
	{
		(q->row)--;
		q = q->next;
	}
	
	return true;
}

bool clearLine(FileData *fileData,const int row)
{
	if(fileData == NULL || row < 1)      //�ж��ļ������Ƿ�Ϊ�գ��͸���������к��Ƿ�С��1������յ��к�С��1ʱ���Ϸ�
	{
        printf("clearLine failed: fileData is null,or row<1\n");
        return false;		
	}
	
	if(row > getFileRow(fileData))      //�ж�������ݵ��к��Ƿ�������ļ�������кţ�����������ܽ�����ղ���
	{
		fprintf(stdout,"clearLine failed: row is greater than file total row");
		return false;
	}
	
	FileData *p = fileData->next;
	while(p != NULL)
	{
		if(p->row == row)         //�ж��ļ�����ָ�룬�Ƿ��ƶ�����Ҫ��յ��к�
		{
			if(p->buf != NULL)    //��ԭ���к��ϵ�����free��������'\n'���
			{
				free(p->buf);
				p->buf = NULL;
			}
			
			p->buf = (char*)malloc(sizeof(char)+1);    //���¿���2���ֽڵĿռ䣬���ڱ���'\n'��'\0'
			if(p->buf == NULL)
			{
				puts("clearLine failed: newNode->buf malloc failed\n");
				return false;
			}
			memcpy(p->buf,"\n",sizeof(char)+1);    //���¿��ٵ��ڴ�ռ���д��"\n"�ַ���
			p->size = 2;
			
			return true;
		}

		p = p->next;
	}
	
	return false;	
}

bool insertLine(FileData *fileData,const int row,const char *data)
{
	if(fileData == NULL || row < 1 || data == NULL)    //�ж��ļ���������Ҫ������ļ������Ƿ�Ϊ�գ��͸����Ĳ����к��Ƿ�С��1����������к�С��1ʱ���Ϸ�
	{
        fprintf(stdout,"insertLine failed: fileData or data is null,or row<1\n");
        return false;
	}
	
	if(row > getFileRow(fileData))      //�жϲ������ݵ��к��Ƿ�������ļ�������кţ�����������ܽ��в������
	{
		puts("insertLine failed: row is greater than file total row");
		return false;
	}
	
	FileData *p = fileData;
	while(p->next != NULL)
	{
		if(p->next->row == row)      //�ж��ļ�����ָ�룬�Ƿ��ƶ�����Ҫ�����кŵ�ǰһ��
		{
			FileData *newNode = (FileData*)malloc(sizeof(FileData));      //�������ڲ���һ���ļ�������Ϣ�����ݿ飬����ʼ��
			if(newNode == NULL)
			{
				Debug("insertLine failed: newNode malloc failed");
				return false;					
			}
			newNode->row = row;
			newNode->size = strlen(data)+1;
			
			newNode->buf = (char*)malloc(newNode->size);    
			if(newNode->buf == NULL)
			{
				Debug("insertLine failed: newNode->buf malloc failed");
				free(newNode);
				return false;				
			}
			memcpy(newNode->buf,data,newNode->size);
			newNode->next = p->next;
			
			p->next = newNode;     //�����벢������һ���ļ���Ϣ�����ݿ飬���뵽�ļ��洢���ݽṹ��
			p = p->next;
		}
		p = p->next;

		if(data[strlen(data)-1] == '\n')
		{
			if(p->row >= row)     //�������к��Ժ�������кţ�����1
			{
				(p->row)++;
			}
		}
	}
	
	return true;
}

bool replaceLine(FileData *fileData,const int row,const char *data)
{
	if(fileData == NULL || row < 1 || data == NULL)    //�ж��ļ���������Ҫ�滻���ļ������Ƿ�Ϊ�գ��͸������滻�к��Ƿ�С��1�����滻���к�С��1ʱ���Ϸ�
	{
        fprintf(stdout,"replaceLine failed: fileData or data is null,or row<1\n");
        return false;
	}
	
	if(row > getFileRow(fileData))      //�ж��滻���ݵ��к��Ƿ�������ļ�������кţ�����������ܽ����滻����
	{
		puts("replaceLine failed: row is greater than file total row");
		return false;
	}
	
	FileData *p = fileData;
	while(p->next != NULL)
	{
		if(p->next->row == row)         //�ж��ļ�����ָ�룬�Ƿ��ƶ�����Ҫ�滻�кŵ�ǰһ��
		{
			FileData *newNode = (FileData*)malloc(sizeof(FileData));      //���������滻һ���ļ�������Ϣ�����ݿ飬����ʼ��
			if(newNode == NULL)
			{
				Debug("replaceLine failed: newNode malloc failed");
				return false;					
			}
			newNode->row = row;
			newNode->size = strlen(data)+1;
			
			newNode->buf = (char*)malloc(newNode->size);    //�����滻��һ���ļ����ݴ�С������һ���ڴ�ռ����ڴ洢�滻��һ���ļ�����
			if(newNode->buf == NULL)
			{
				Debug("replaceLine failed: newNode->buf malloc failed");
				free(newNode);
				return false;				
			}
			memcpy(newNode->buf,data,newNode->size);
			newNode->next = p->next->next;
			
			if(p->next->buf != NULL)       //��ԭ����Ҫ�滻�к��ϵ�����free������ʹ����Ҫ�滻�����ݴ���
			{
				free(p->next->buf);
				p->next->buf = NULL;
			}
			free(p->next);
			p->next = newNode;       //���滻��������һ���ļ���Ϣ�����ݿ飬���뵽�ļ��洢���ݽṹ��
		}
		p = p->next;
	}
	
	return true;	
}

int findStrRow(const FileData *fileData,const char* str)
{
	if(fileData == NULL || str == NULL)       //�ж��ļ����ݺ�Ŀ������ַ����Ƿ�Ϊ��
	{
        Debug("findStrRow failed: fileData or str is null");
        return false;
	}
	
	FileData *p = fileData->next;      //�����ļ����ݣ����ļ���ĳһ���а�����Ҫ���ҵ��ַ������򷵻ز��ҵ����к�
	while(p != NULL)
	{
		if(p->buf != NULL && strstr(p->buf,str) != NULL)
		{
			return p->row;
		}
		p = p->next;
	}
	
	return -1;
}

bool getLineData(const FileData *fileData,const int row,char* data)
{
	if(fileData == NULL || row < 1 || data == NULL)     //�ж��ļ����ݺ���������һ���ļ����ݵ��ڴ�ռ��Ƿ�Ϊ�գ��͸�����ȡ���ݵ��к��Ƿ�С��1���������к�С��1ʱ���Ϸ�
	{
        fputs("getLineData failed: fileData or data is null,or row<1\n",stdout);
        return false;
	}
	
	if(row > getFileRow(fileData))      //�жϻ�ȡ���ݵ��к��Ƿ�������ļ�������кţ�����������ܽ��л�ȡ����
	{
		printf("getLineData failed: row is greater than file total row\n");
		return false;
	}
	
	int count_line = 1;
	FileData *p = fileData->next;
	while(p != NULL)
	{
		if(count_line == row && p->buf != NULL)      //���ļ�����ָ�룬�ƶ�����Ҫ��ȡ���ݵ��кţ�������һ�����ݿ���������buf��
		{
			memcpy(data,p->buf,p->size);
			return true;
		}
		count_line++;
		p = p->next;
	}
	
	return false;
}

void getFileData(const FileData *fileData,char buf[],int *size)
{
	Assert(fileData != NULL);        //�ж��ļ����ݺ����������ļ����ݵ��ڴ�ռ��Ƿ�Ϊ��
	Assert(buf != NULL);
	
	char *p = buf;
	const FileData *q = fileData->next;      //���ļ����ݿ���������buf��
	while(q != NULL)
	{
		if(q->buf != NULL)
		{
			memcpy(p,q->buf,q->size);
			p = p + strlen(q->buf);
			(*size) += q->size;
		}
		
		if(q->next == NULL)
		{
			if(q->buf[q->size-2] != '\n')
			{
				(*size) -= 1;
			}
		}
		q = q->next;
	}
}

bool getStartArea(const FileData *fileData,const int len,char buf[],int *size)
{
	if(fileData == NULL || len < 1 || buf == NULL)
	{
        puts("getStartArea failed: fileData or buf is null,or len<1\n");
        return false;
	}

	*size = 0;
	int line_num = 0;
	const FileData *q = fileData;
	while(q->next != NULL)
	{
		line_num++;
		q = q->next;
	}

	if(line_num < len)
	{
        fprintf(stdout,"getStartArea failed: len greater than file rownum\n");
        return false;		
	}
	
	if(line_num == len)
	{
		if(q->buf[q->size-2] != '\n')
		{
			(*size) -= 1;
		}
	}
	
	int length = len;
	bool flag = false;
	char *p = buf;
	q = fileData->next;
	while(length--)
	{
		if(q->buf != NULL)
		{
			memcpy(p,q->buf,q->size - 1);
			p += q->size - 1;
			(*size) += strlen(q->buf) + 1;
			flag = true;
		}
		q = q->next;
	}
	
	return flag;
}

bool getEndArea(const FileData *fileData,const int len,char buf[],int *size)
{
	if(fileData == NULL || len < 1 || buf == NULL)
	{
        printf("getEndArea failed: fileData or buf is null,or len<1\n");
        return false;
	}
	
	*size = 0;
	int line_num = 0;
	const FileData *q = fileData;
	while(q->next != NULL)
	{
		line_num++;
		q = q->next;
	}
	
	if(line_num < len)
	{
        fprintf(stdout,"getStartArea failed: len greater than file rownum\n");
        return false;		
	}
	
	if(q->buf[q->size - 2] == '\n')
	{
		line_num++;
	}
	
	bool flag = false;
	char *p = buf;
	q = fileData;
	for(int i=0;q->next != NULL;++i)
	{
		if(i >= (line_num-len) && q->buf != NULL)
		{
			memcpy(p,q->buf,q->size-1);
			p += q->size - 1;
			(*size) += q->size;
			flag = true;
		}
		q = q->next;		
	}
	
	if(q->buf[q->size - 2] != '\n')
	{
		(*size) -= 2;
	}
	
	return flag;
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

void printFile(const FileData *fileData)
{
	Assert(fileData != NULL);
	
	FileData *p = fileData->next;
	while(p != NULL)
	{
		if(p->buf != NULL)
		{
			fprintf(stdout,"%s",p->buf);
		}
		p = p->next;
	}
}

void clearFileData(FileData *fileData)
{
	if(fileData == NULL)
	{
		fputs("clearFileData warn: fileData is null",stdout);
		return ;
	}
	
	FileData *q = NULL;
	FileData *p = fileData->next;
	while(NULL != p)
	{
		q = p->next;
		if(p->buf != NULL)
		{
			free(p->buf);
			p->buf = NULL;
		}
		free(p);
		p = q;
	}
	fileData->next = NULL;
}