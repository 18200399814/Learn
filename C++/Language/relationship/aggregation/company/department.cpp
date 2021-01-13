#include "department.h"
#include <stdio.h>        //��Ϊʹ����char*��Ϊ�ַ��������԰���C���Ե�ͷ�ļ��Դ���C�����ַ�����
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using std::cout;
using std::endl;

Department::Department(const char* name)
{
	if(name == NULL)
	{
		printf("Department construct error: name is null\n");
		throw "Department construct error: name is null";
	}
	
	int len = strlen(name) + 1;
	this->name = (char*)malloc(len);     //Ϊname��Աָ�뿪���ڴ�ռ䣬�������ٵ��ڴ�ռ��е�����������ա�
	memset(this->name,0,len);
	strcpy(this->name,name);
}

Department::Department(const Department& other)
	:name(NULL)
	,managers(other.managers)
	,employees(other.employees)
{
	if(other.name == NULL)
	{
		fprintf(stdout,"Department copy construct error: name is null\n");
		throw "Department copy construct error: name is null";
	}
	
	int len = strlen(other.name) + 1;
	this->name = (char*)malloc(len);
	memcpy(this->name,other.name,len);
}

#ifndef _CHANGE_WAY_
Department::~Department()
{
	if(name != NULL)
	{
		free(name);
		name = NULL;
	}
}
#else
Department::~Department()
{                 //�����������ͷų�Աָ�룬���Բ������пպ��ÿմ�����ΪNULLָ��Ҳ����free��
	free(name);   //��������Ժ��Աָ��Ͳ������ˣ�����Ҳ�������ÿմ�����Ϊ�䲻���ٱ�ʹ���ˡ�
}
#endif

bool Department::operator ==(const Department& other)    //ֻҪ����Departmentd�����������ͬ������Ϊ����������ȣ�
{                                                        //�����ټ���ȥ�Ƚ�����֮���managers��employees�Ƿ���ͬ��
	if(name == other.name)
	{
		return true;
	}
	
	if(name == nullptr || other.name == nullptr)
	{
		return false;
	}
	
	return strcmp(name,other.name) == 0;
}

void Department::setName(const char* name)
{
	if(NULL == name)
	{
		puts("setName error: name is null");
		return ;
	}
	
	if(this->name != NULL)
	{
		free(this->name);
		this->name = NULL;
	}
	
	this->name = (char*)malloc(strlen(name) + 1);
	memcpy(this->name,name,strlen(name) + 1);
}

const char* Department::getName()const
{
	return name;
}

#ifndef _CHANGE_WAY_
void Department::addManager(const string& position,const Manager& manager)
{
	if(position.empty())
	{
		fputs("addManager error: position is empty",stdout);
		return ;
	}
	
	managers.insert(std::pair<string,Manager>(position,manager));
}
#else
void Department::addManager(const string& position,const Manager& manager)
{
	if(position.empty())
	{
		fputs("addManager error: position is empty",stdout);
		return ;
	}
	
	managers[position] = manager;
}
#endif

#ifndef _CHANGE_WAY_
void Department::removeManager(const string& position)
{
	if(position.empty())
	{
		fputs("removeManager error: position is empty",stdout);
		return ;
	}
	
	managers.erase(position);
}
#else
void Department::removeManager(const string& position)
{
	if(position.empty())
	{
		fputs("removeManager error: position is empty",stdout);
		return ;
	}
	
	map<string,Manager>::iterator iter = managers.find(position);
	if(iter != managers.end())
	{
		managers.erase(iter);
	}
}
#endif

#ifndef _CHANGE_WAY_
Manager& Department::getManager(const string& position)
{
	if(managers.count(position) == 0)
	{
		fprintf(stdout,"getManager error: %s is can't find in managers keys",position.c_str());
	}
	
	return managers[position];   //���position��managers��key���Ҳ����Ļ����������managers���Ȳ���һ��keyΪposition��valueΪManagerĬ�Ϲ������ļ�ֵ�ԡ�
}
#else
Manager& Department::getManager(const string& position)
{
	map<string,Manager>::iterator iter = managers.find(position);
	if(iter == managers.end())
	{
		fprintf(stdout,"getManager error: %s is can't find in managers keys",position.c_str());
		abort();
	}
	
	return iter->second;
}
#endif

#ifndef _CHANGE_WAY_
void Department::addEmployee(const Employee& employee)
{
	employees.push_back(employee);   //��vector����׷�����ݵ��ٶȺܿ죬����vectorǰ��������ݵ��ٶȺ�������Ϊ��vectorǰ��������ݻ�����ڴ��ƶ�������
}
#else
void Department::addEmployee(const Employee& employee)
{
	vector<Employee>::iterator iter = employees.begin();  //��employee������õ�vector������ǰ�棬ֻ��ʹ��insertʵ�֡�std::vectorû���ṩprepend����push_front����
	employees.insert(iter,employee);    //���������Ҫ��ǰ����뵽vector�У���ô�����������ʵ�ֿ������캯���͸�ֵ������������ʵ�ָ�ֵ��������ܻ�������벻���Ľ����
}
#endif

void Department::removeEmployee(const Employee& employee)
{
	vector<Employee>::iterator iter = employees.begin();
	while(iter != employees.end())
	{
		if(*iter == employee)
		{
#ifndef _CHANGE_WAY_
			iter->release(DELETE_POINTER);      //��ʹ���ֶ����Employee������pbirthdayָ����ڴ棬Employee����������ʱ��Ҳ���Զ��ͷ�pbirthdayָ���ڴ�
#endif
			employees.erase(iter);     //array��vector��map��û��remove������ֻ��list��remove������
			return ;                   //�������return��䣬��ôemployees�����е����������employee��ȵĶ��󣬶��ᱻɾ����
		}
		++iter;
	}
}

#ifndef _CHANGE_WAY_
Employee& Department::getEmployee(const int index)
{
	assert(index >= 0 && index < employees.size());

	return employees[index];
}
#else
Employee& Department::getEmployee(const int index)
{
	if(index < 0 || index >= employees.size())
	{
		puts("getEmployee error: index is illegal");
		throw "getEmployee error: index is illegal";
	}
	
	return employees.at(index);
}
#endif

void Department::detail()const
{
	if(NULL != name)
	{
		printf("department name: %s\n",name);
	}
	
	for(auto citer = managers.cbegin();citer != managers.cend();++citer)      //ʹ�õ�����ʱ�����ʹ��auto�ؼ��������������Ƶ�����������ʹ������Ӽ�ࡣ
	{
		cout<<"position: "<<citer->first<<" ,manager("<<citer->second<<")"<<endl;    //std::string���Ͳ���ʹ��printf���������ֻ��ʹ��std::cout���������
	}
	
	for(Employee employee: employees)
	{
		employee.show();
	}
}
