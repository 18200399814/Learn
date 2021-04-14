/*Windowsϵͳ�����õ������������·����Ϊ�ˣ�����cl��������Ԥ������νӽ׶���ֱ���ҵ������
 *ͷ�ļ�����ļ���������ָ����������ľ���·��������һ�㲻�Ƽ��������������õ�MSVC��������
 *����·���У���Ϊ����������ĿԴ���ڱ������������������У���������������������޷�����ͨ��
 *���������С��Ƽ��������ǽ�������ͷ�ļ�����ļ�ֱ�ӿ�������ĿԴ��·����ʹ�á�
 */

/*Windowsϵͳ�����õ�������ķ�����
 *1.��cl�������ҵ�ͷ�ļ����½�һ��INCLUDE������������ָ���û���������ֵ������������ͷ�ļ�·����
 *  ��cl/MSVC/VS��������ͷ�ļ�����·������INCLUDE��������ָ���ġ�
 *2.��cl�������ҵ����ļ����½�һ��LIB������������ָ���û���������ֵ�������������ļ�·����
 *  ��cl/MSVC/VS�������Ŀ��ļ�����·������LIB��������ָ���ġ�
 *3.PATH��������ֻ������ָ����ִ�г���exe��������ߵ�����·������������������Windows��������
 *  ͷ�ļ��Ϳ��ļ�·������Ϊcl/MSVC/VS��������Ԥ������νӽ׶Σ����ᵽPATH��������ָ����·����
 *  ȥѰ�ҿ��ļ���ͷ�ļ���WIndowsϵͳ��ָ����������ͷ�ļ���Ҫʹ��INCLUDE����������ָ����������
 *  �ļ���Ҫʹ��LIB�������������Windowsϵͳ�в�����INCLUDE/LIB����������ֻ��Ҫ�Լ��½����С�
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

//��sqlite3�����õ�MSVC�������Ĳ���·���к�ʹ��sqlite3.dll��̬��ʱ������ʾ�ļ���sqlite3.lib����⡣
#pragma comment(lib,"sqlite3.lib")

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define NAME_LENGTH 64
#define MAX_SQL_SIZE 1024

typedef struct Student_t
{
	int id;
	char name[NAME_LENGTH];
	int age;
	double score;
}Student;

static Student student_table[] = {
	{1,"amy",25,80},
	{2,"lisa",26,75},
	{3,"bob",23,67},
	{4,"kevin",24,92},
	{5,"jorden",24,73},
	{6,"james",27,58},
	{7,"linda",23,76},
	{8,"david",26,69},
	{9,"susan",22,86}
};

static int callback(void *data,int column,char** rowData,char** columnName)
{
	if(data != NULL)
		printf("%s\n",(char*)data);
	
	for(int i=0;i<column;++i)
	{
		printf("%s =%s\n",columnName[i],rowData[i] ? rowData[i] : "null");
	}
	putchar('\n');
	
	return 0;
}

int main(void)
{
	FILE *db_fp = fopen("class.db","r");    //��ֻ����ʽ���ļ������ж��ļ��Ƿ����
    
	sqlite3 *db;
	int ret = sqlite3_open("class.db",&db);     //�򿪻��ߴ���student.db���ݿ�
	if(ret != SQLITE_OK)
	{
		printf("class.db open failed: %s\n",sqlite3_errmsg(db));
		return -1;
	}
	
	char *errmsg = NULL;
	char sql[MAX_SQL_SIZE] = {0};
	if(db_fp == NULL)
    {
		//��class.db���ݿ��д���һ��students���
		sprintf(sql,"create table students(id integer primary key,name char(64),age int,score double)");
		ret = sqlite3_exec(db,sql,NULL,NULL,&errmsg);
		if(ret != SQLITE_OK)
		{
			printf("class.db create table students error: %s\n",errmsg);
			sqlite3_close(db);
			return -1;
		}
		puts("create table successfully!");
		
		//��students����в��뼸����¼
		for(int i=0;i<sizeof(student_table)/sizeof(student_table[0]);++i)
		{
			memset(sql,0,MAX_SQL_SIZE);
			sprintf(sql,"insert into students values(%d,'%s',%d,%f)",
				student_table[i].id,
				student_table[i].name,
				student_table[i].age,
				student_table[i].score);
				
			ret = sqlite3_exec(db,sql,NULL,NULL,&errmsg);
			if(ret != SQLITE_OK)
			{
				fprintf(stdout,"students insert record error: %s\n",errmsg);
				sqlite3_close(db);
				return -1;
			}
		}
		puts("students table insert data successfully!");
    }
	else
	{
		//��ʾstudents����е�����
		sprintf(sql,"select * from students");
#ifndef _CHANGE_WAY_
		const char* data = "Callback function called:";
		ret = sqlite3_exec(db,sql,callback,(void*)data,&errmsg);
		if(ret != SQLITE_OK)
		{
			fprintf(stdout,"select from students error: %s\n",errmsg);
			sqlite3_close(db);
			return -1;
		}
#else
		int row = 0;
		int column = 0;
		char **result = NULL;
		ret = sqlite3_get_table(db,sql,&result,&row,&column,&errmsg);
		if(ret != SQLITE_OK)
		{
			fprintf(stdout,"select from students error: %s\n",errmsg);
			sqlite3_close(db);
			return -1;
		}
		
		printf("result table: row =%d, column =%d\n",row,column);
		char** resultTable = result;
		for(int i=0;i<=row;++i)     //����Ϊ��ͷ��������ݴ�index=1��ʼ������ʹ��i<=row
		{
			for(int j=0;j<column;++j)
			{
				printf("%s \t",*resultTable++);
			}
			puts("");
		}
		
		sqlite3_free_table(result);
#endif
	}
	
	sqlite3_close(db);
	return 0;
}