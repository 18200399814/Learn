#include "mymalloc.h"
#include <stdio.h>
#include <string.h>

#define MAX_PATH 256
#define MEMORY_DETECTOR_RST "memory_detector_result.txt"

typedef struct MemAllocUnit
{
	char file[MAX_PATH];            //�ļ���
	int line;                       //�к�
	void *addr;                     //�ڴ��ַ
	unsigned int size;              //�ڴ���С
	struct MemAllocUnit *next;      //��һ���ڴ��
}MemAllocUnit;

static MemAllocUnit* memAllocList = NULL;        //�ڴ���������ʼ��ַ

void* doMalloc(size_t size,const char *type,const char *file,int line)
{
	if(size <= 0 || type == NULL || file == NULL || line <- 0)
	{
		puts("doMalloc warn: illegal input!");
		return NULL;
	}
	
	if(strlen(file) >= MAX_PATH)
	{
		printf("doMalloc warn: file name is more than %d charector: %s\n",MAX_PATH,file);
		return NULL;
	}
	
	void *addr = malloc(size);
	if(NULL == addr)
	{
		fputs("doMalloc warn: addr malloc failed\n",stdout);
		return NULL;
	}
	
	MemAllocUnit *pmemAllocUnit = (MemAllocUnit*)malloc(sizeof(MemAllocUnit));
	if(NULL == pmemAllocUnit)
	{
		fprintf(stdout,"doMalloc warn: memory unit malloc failed\n");
		free(addr);
		return NULL
	}
	memset(pmemAllocUnit->file,0,MAX_PATH);
	strcpy(pmemAllocUnit->file,file);
	
	pmemAllocUnit->line = line;
	pmemAllocUnit->addr = addr;
	pmemAllocUnit->size = size;
	pmemAllocUnit->next = memAllocList;
	memAllocList = pmemAllocUnit;
	
	printf("doMalloc: alloc memory in %p, size: %d, object type: %s, file: %s, line: %d\n",addr,size,type,file,line);
	return addr;
}

//����doMalloc�ģ����myFree�����myMalloc�ģ�����myFree
void myFree(void *ptr)
{
	
}

void memReport()
{
	
}