#ifndef _STUDNET_H
#define _STUDENT_H

/*Windows����ϵͳ��ʹ��MSVC����������dll��̬��ʱ����ͬʱ����һ����lib��β�ĵ����/����⡣
 *��Ȼ�����/�����;�̬�ⶼ����lib��׺��β�ģ��������ǲ���ͬһ���������Ҿ��б��ʵ�����
 *�������ֻ�б�������������ķ�����������Щ������dll��̬���еĵ�ַ���������������������
 *������ʵ������dll��̬���С���̬���м��б�������������ķ���������Ҳ�������ǵĶ����ʵ�֡�
 */

/*Linux����ϵͳ�����ɶ�̬��ʱ��ֻ��һ��.so��̬���ļ�����û����Windowsϵͳ������������һ����
 *ר������˵����̬���е������ź͵�ַ�ĵ����/������ļ���
 */

#include "istudent.h"
#include "student_global.h"

class STUDENT_SHARED_EXPORT Student:public IStudent
{
public:
	Student(const QString& name,const QString& note);
	Student(const Student& other);
	
	virtual void setName(const QString& name);
	virtual QString getName()const;
	
	void setNote(const QString& note) override;
	QString getNote()const override;
	
	void show()const final;
private:
	QString name;
	QString note;
};

#endif //_STUDENT_H