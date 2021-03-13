/*ʹ����MySQL���ݿ��Ӧ�ó�������ʱ����Ҫ��libmysql.dll��̬����ӵ����ɵ�exe�ļ�Ŀ¼�¡�
 *�������ֲ��ܼ���MySQL���������⡣
 */
 
/*��Ϊ��������а�װ��MySQL���ݿ���mysql-8.0.16-winx64�汾�����ṩ���û������ĵ�������libmysql.dll
 *��mysqlclient.lib����64λ�ģ����Ա���Qt����MySQL���ݿ��Ӧ�ó���ʱ����Ҫʹ��MSVC 64λ��������
 */

/*����Qt MSVC64λ���뻷�����裨����Qt MSVC32λ���뻷���������ƣ���
 *1.��Qt5.12.0 64-bit for Desktop(MSVC 2017)�ն˻�ִ��D:\Qt5.12\5.12.0\msvc2017_64\bin\qtenv2.bat������ű���
 *  ������Qt�����л����뻷��������
 *2.�ڴ򿪵�Qt5.12.0 64-bit for Desktop(MSVC 2017)��������ִ��D:\Visual Studio 2017\VC\Auxiliary\Build\vcvarsall.bat
 *  ������ű���������MSVC 64���뻷���뻷��������
 */

//��Qt5.12.0 64-bit for Desktop(MSVC 2017)�ն˾͵�ͬ������C:\Windows\System32\cmd.exe /A /Q /K D:\Qt5.12\5.12.0\msvc2017_64\bin\qtenv2.bat

//QCoreApplication������coreģ���У���QApplication��Qt5�з�����widgetsģ����
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

#define _CREATE_TABLE_
#undef _CREATE_TABLE_

typedef enum __StudentProperty
{
	ID,
	NAME,
	SEX,
	AGE,
	StudentProperty_END     //���ڼ�¼ѧ�����Ը�������׼β
}StudentProperty_t;

int main(int argc,char** argv)
{
	//��Ҫ����MySQL���ݿ��QtӦ�ó��򣬴���һ��QApplicationӦ�ó�������Լ���MySQL���ݿ�������
	QCoreApplication app(argc,argv);
	
	//��MySQL
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setDatabaseName("testdb");
	db.setUserName("root");
	db.setPassword("123456");
	if(!db.open())
	{
		qDebug()<<"failed to connect mysql with root user";
		return 0;
	}
	qDebug()<<"connect mysql success";
	
	QSqlQuery query(db);
#ifdef _CREATE_TABLE_
	//ע��varchar����һ��Ҫָ�����ȣ�����󳤶�Ϊ20���ֽ�
	if(!query.exec("create table students(id int primary key,name varchar(20),sex varchar(16),age int)"))
	{
		qDebug()<<"create table students failed: "<<query.lastError();
	}
	else
	{
		qDebug()<<"create table students successfuly";
	}
	
	query.exec("insert into students values(001,'amy','girl',24)");
	query.exec("insert into students values(002,'bob','boy',26)");
	query.exec("insert into students values(003,'lisa','girl',25)");
	query.exec("insert into students values(004,'mery','girl',24)");
	query.exec("insert into students values(005,'kevin','boy',23)");
#else
	//��ִ�������ݿ��ѯ�������Ǳ��ȡ����Ӧ��ִ�н������Ϊ��ȡ�Ľ�����ܲ�ֹһ����¼��
    //������Ҫʹ��while(query.next())�����������ȡ������е����ݡ�
	query.exec("select * from students");
	while(query.next())
	{
		int id = query.value(ID).toInt();    //QSqlQuery::value()�����ķ���ֵʱ�и�QVariant���ͣ�����ʹ��ʱ��Ҫ��������ת��
		QString name = query.value(NAME).toString();
		QString sex = query.value(SEX).toString();
		QString age = query.value(AGE).toInt();
		
		qDebug()<<"id ="<<id<<" ,name ="<<name<<" ,sex ="<<sex<<" ,age ="<<age;
	}
	qDebug()<<"";
	
	query.exec("select min(id),max(id) from students");
	while(query.next())
	{
		for(int i=0;i<query.record().count();++i)
		{
			qDebug()<<query.value(i).toInt();
		}
	}
	qDebug()<<"";
#endif
	
	//��������id<4�ĵ�һ����¼
	query.exec("select * from students where id < 4 order by id asc limit 0,1");
	query.next();
	for(int i=0;i<StudentProperty_END;++i)
	{
		qDebug()<<query.value(i).toString();   //���ݿ�����id��age����ʱint���ͣ����Դ�ӡ�����toInt()
	}
	
	return 0;   //ֻ����QCoreApplication�����Լ���MySQL���ݿ����������ǲ�����Ӧ�ó�����¼�ѭ����
}