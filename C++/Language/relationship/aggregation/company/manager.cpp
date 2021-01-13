#include "manager.h"

using std::cout;
using std::endl;
using std::cin;

Manager::Manager()
	:sex(BOY)
	,salary(0.00)
{
	
}

Manager::Manager(const Sex_t& sex,double salary)
	:salary(salary)
{
	if(sex != GIRL && sex != BOY)
	{
		cout<<"Manager constructor error: sex is illegal"<<endl;
		throw "Manager constructor error: sex is illegal";
	}
	this->sex = sex;
}

Manager::Manager(const Manager& other)
	:sex(other.sex)
	,salary(other.salary)
{
	
}

void Manager::setSex(const Sex sex)      //��C/C++��ʵ��һ��������������ע������������������⣬���������ݴ���ͺ�������ֵ�����
{
	if(sex != GIRL && sex != BOY)
	{
		cout<<"setSex error: input sex is illegal"<<endl;
		return ;
	}
	this->sex = sex;
}

Sex Manager::getSex()const
{
	return sex;
}

void Manager::setSalary(double salary)
{
	this->salary = salary;
}

double Manager::getSalary()const
{
	return salary;
}

void Manager::display()const
{
	if(sex == GIRL)
	{
		cout<<"sex =girl"<<" ,";	
	}
	else if(sex == BOY)
	{
		cout<<"sex =boy"<<" ,";
	}
	else
	{
		cout<<"display error: sex is illegal"<<endl;
		return ;
	}
	
	cout<<"salary ="<<salary<<endl;
}

std::ostream& operator <<(std::ostream& os,const Manager& other)
{
	if(other.sex == GIRL)
	{
		os<<"sex =girl"<<" ,";	
	}
	else if(other.sex == BOY)
	{
		os<<"sex =boy"<<" ,";
	}
	else
	{
		os<<"display error: sex is illegal"<<endl;
		return os;
	}
	
	os<<"salary ="<<other.salary;
	return os;
}