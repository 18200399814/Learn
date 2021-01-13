//C++����ƹ����У�һ�㶼��Ҫ�ṩ�������룬���ݴ��������������ֽӿڣ�����ͬʵ����Ĺ��ܡ����еĳ�Ա�������ʱ��
//���Ҳ�����������룬���ݴ��������������ֹ��ܽ��л��֣���ʹ��Ĺ��ܸ��Ӳ�η������Ӷ��ﵽ����Ƶĸ��ھ۵����Ŀ�ġ�

/*C++���е����г�Ա���������Է�Ϊ�����ࣺ�������뺯�������ݴ��������������������������������������������Ϊpublic�ӿڣ�
 *�������Ϊprivate�����Ļ�����ô�Ͳ��ܴﵽΪ�������������ݵ�Ŀ�ġ������ݴ�����������Ϊpublic�ӿڣ�Ҳ����Ϊprivate������
 *�����ݴ������������Ϊprivate���Թ��������������ӿڵ��ã��Ӷ��ﵽ����Ƶĸ��ھ۵����Ŀ�ġ�
 */

#ifndef _MANAGER_H
#define _MANAGER_H

#include <iostream>

typedef enum Sex_t
{
	GIRL,
	BOY
}Sex;

class Manager
{
public:
	Manager();         //�洢��map�е�ֵ������Ҫ��Ĭ�Ͽ������캯������������Ҫ���ش���>�������
	Manager(const Sex_t& sex,double salary);
	Manager(const Manager& other);      //�ж�һ�����Ƿ���Ҫ��ʾʵ�����������ķ����ǿ�������Ƿ���г�Աָ�롣
	                                    //������г�Աָ����ô����Ҫʵ����������������������г�Աָ����ô�Ϳ��Բ���Ҫʵ��������������
	void setSex(const Sex sex);
	Sex getSex()const;
	
	void setSalary(double salary);
	double getSalary()const;
	
	void display()const;
	
	friend std::ostream& operator <<(std::ostream& os,const Manager& other);
private:
	Sex_t sex;
	double salary;
};

#endif //_MANAGER_H