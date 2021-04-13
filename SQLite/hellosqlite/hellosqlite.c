//��Ϊ��װ��SQLite���ݿ���win64λ�����Ա���ʹ��MSVC 64λ���������б��롣

/*1.SQLite3�����ӿڣ�
 *��1�������ݿ�:
 *	int sqlite3_open(const char* filename,sqlite3 **ppDb);
 *  ���ܣ���һ��ָ��SQLite���ݿ��ļ������ӣ�����һ����������SQLite��������ݿ����Ӷ���
 *  ������filename����Ҫ���������ݿ��ļ���·������ppdb�����������ݿ�Ĳ��������SQLite db handle����
 *  ����ֵ���ɹ�����SQLITE_OK�������������롣
 *  ע�⣺���filename������NULL��':memory:'����ôsqlite3_open()������RAM�д���һ���ڴ����ݿ⣬��ֻ����
 *        session����Чʱ���ڳ���������ļ���filename��ΪNULL����ôsqlite3_open()��ʹ���������ֵ���Դ�
 *        ���ݿ��ļ�����������Ƶ��ļ������ڣ�sqlite3_open()������һ���µ�����Ϊ�����Ƶ����ݿ��ļ����򿪡�
 *
 *��2���ر����ݿ⣺
 *	int sqlite3_close(sqlite3* db);
 *  ���ܣ��ر�֮ǰ����sqlite3_open()�򿪵����ݿ����ӡ�
 *  ������db�����������ݿ�ľ����
 *  ����ֵ���ɹ�����SQLITE_OK�������������롣
 *  ע�⣺������������ص���䶼Ӧ�����ӹر�֮ǰ��ɡ�������в�ѯû����ɣ�sqlite3_close()������SQLITE_BUSY
 *        ��ֹ�رյĴ�����Ϣ��
 *
 *��3����ȡ���ݿ�����Ĵ�����Ϣ��
 * const char* sqlite3_errmsg(sqlite3* db);
 * ������db����SQLite database handle��
 * ����ֵ��������Ϣ���׵�ַ��
 *
 *��4��ִ��sql��䣺
 * int sqlite3_exec(sqlite3* db,const char* sql,sqlite3_callback callback,void* data,char **errmsg);
 * ���ܣ��ṩ��һ��ִ��SQL����Ŀ�ݷ�ʽ��SQL������sql�����ṩ�������ɶ��SQL������ɡ�
 * ������db�������ݿ���������An open database handle����
 *       sql����һ��sql��䣨SQL to be evaluated����
 *       callback����ֻ��sqlΪ��ѯ���ʱ���Ż�ִ�д˻ص�������Callback function����
 *	     data�������ݸ��ص�����callback�ĵ�һ��������1st argument to callback����
 *       errmsg����������Ϣ��Error msg written here����
 * ����ֵ���ɹ�����SQLITE_OK�������������롣
 *
 *��5����ȡ��ѯ�����
 * typedef int (*sqlite3_callback)(void* data, int column, char** rowData, char** columnName);
 * ���ܣ�����ص��ṩ��һ����SELECT����ý���ķ�ʽ�������ĵ��ô������ڲ�ѯ��¼�������������sqlite3_callback�ص���
         sqlite_exec()��������Ϊ��������������ôSQLite��ΪSQL������ִ�е�ÿ��SELECT����д����ÿ����¼���øûص�������
 * ������data����sqlite3_exec()�����д��ݸ��ص������Ĳ�����Data provided in the 4th argument of sqlite3_exec()����
 *		 column������¼�а������ֶ���Ŀ�������������The number of columns in row����
 *       rowData��������ÿ���ֶ�ֵ��ָ�����飬�������ÿһ�����ݣ�An array of strings representing fields in the row����
 *       columnName��������ÿ���ֶ����Ƶ�ָ�����飬�����ͷ��An array of strings representing column names����
 * ����ֵ���ɹ�����0��ʧ�ܷ���-1��
 */

#include <stdio.h>
#include <sqlite3.h>

#ifdef _CHANGE_WAY_
#pragma message("---explicit load sqlite3.lib")
#pragma comment(lib,"sqlite3.lib")
#else
#pragma message("---implicit load sqlite3.lib")
#endif

int main(void)
{
	sqlite3 *db;
	
	int ret = sqlite3_open("bin/test.db",&db);
	if(ret != SQLITE_OK)
	{
		fprintf(stderr,"Can't open database: %s\n",sqlite3_errmsg(db));
		exit(-1);
	}
	else
	{
		puts("Opened database successfully\n");
	}

	sqlite3_close(db);

	return 0;
}