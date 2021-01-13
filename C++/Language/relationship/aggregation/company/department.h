#ifndef _DEPARTMENT_H
#define _DEPARTMENT_H

#include <map>
#include <vector>
#include <string>

#include "employee.h"
#include "manager.h"

using std::map;        //չ�������ռ�������÷��õ�Դ�ļ���ȥ����Ϊ������õ�ͷ�ļ��У�
using std::vector;     //��ʹͷ�ļ�������ʱ��չ�������ռ�ķ�Χ��һ�������󣬴Ӷ����������ͻ���⡣
using std::string;

class Department
{
public:
	Department(const char* name);       //ʹ��const char*ʱֻ��ʹ���ֵʵ�ֹ��캯�������ʹ��char*�����ʹ���ֵ��Ҳ����ʹ��ǳ��ֵʵ�ֹ��캯����
	Department(const Department& other);
	virtual ~Department();
	
	bool operator ==(const Department& other);
	
	void setName(const char* name);
	const char* getName()const;
	
	void addManager(const string& position,const Manager& manager);
	void removeManager(const string& position);
	Manager& getManager(const string& position);
	
	void addEmployee(const Employee& employee);
	void removeEmployee(const Employee& employee);
	Employee& getEmployee(const int index);
	
	void detail()const;
private:
	char* name;
	map<string,Manager> managers;     //key - ְλ��value - ������
	vector<Employee> employees;
};

#endif //_DEPARTMENT_H