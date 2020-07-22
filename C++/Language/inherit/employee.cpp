//����û���ָ��ָ�����������ʵ�ֶ�̬�����麯���ķ���Ȩ���Ի����еķ���Ȩ��Ϊ׼��
//���ֻҪ�����еķ���Ȩ����public���Ϳ���ͨ������ָ����������е������麯����private�麯��Ҳ���Է��ʡ�
//���������ķ���Ȩ�����������е�Ϊ׼��

#include <iostream>
#include <cstring>

#define _ERROR_
#undef _ERROR_

using std::cout;
using std::endl;

using std::string;

class Employee
{
public:
	explicit Employee(const string& name,int number);
	Employee(const Employee& other);
	virtual ~Employee();
	
	void setName(const string& name);
	string getName()const;
	
	void setNumber(const int number);
	int getNumber()const;
	
	virtual double salary()const;
	virtual void showInfo()const;
private:
	string m_name;
	int m_number;
};

Employee::Employee(const string& name,int number)
	:m_name(name)
	,m_number(number)
{
	
}

Employee::Employee(const Employee& other)
	:m_name(other.m_name)
	,m_number(other.m_number)
{
	
}

Employee::~Employee()
{
	
}

void Employee::setName(const string& name)
{
	m_name = name;
}

string Employee::getName()const
{
	return m_name;
}

void Employee::setNumber(const int number)
{
	m_number = number;
}

int Employee::getNumber()const
{
	return m_number;
}

void Employee::showInfo()const
{
	cout<<"name ="<<m_name<<" ,number ="<<m_number<<endl;
}

double Employee::salary()const
{
	return 0;
}

class Manager:public Employee
{
public:
	explicit Manager(const string& name,int number,double salary);
	Manager(const Manager& other);
	virtual ~Manager();
	
	void setSalary(const double salary);
	double getSalary()const;
private:
	virtual void showInfo()const;            //�����е��麯�������������и�д�����Ȩ��
	double salary()const override;           //ֻҪ�����е��麯����public��������Է��������е�����̳ж������麯��
private:
	double m_salary;
};

Manager::Manager(const string& name,int number,double salary)
	:Employee(name,number)
	,m_salary(salary)
{
	
}

Manager::Manager(const Manager& other)
	:Employee(other)
	,m_salary(other.m_salary)
{
	
}

Manager::~Manager()
{
	
}

void Manager::setSalary(const double salary)
{
	m_salary = salary;
}

double Manager::getSalary()const
{
	return salary();
}

void Manager::showInfo()const
{
	Employee::showInfo();
	cout<<"salary ="<<m_salary<<endl;
}

double Manager::salary()const
{
	return m_salary;
}

int main(void)
{
	Employee *pemployee = new Manager("Tom",123456,50.00);
	
	//ֻҪ������麯��Ȩ����public���Ϳ���ʹ�û���ָ����ʵ�������˽�е��麯����
	pemployee->showInfo();
	cout<<pemployee->getName()<<" salary is "<<pemployee->salary()<<endl;
	
	pemployee->setName("lisa");
	cout<<pemployee->getName()<<" salary is "<<pemployee->salary()<<endl;
	if(pemployee != nullptr)
	{
		delete pemployee;
		pemployee = nullptr;
	}
	
	Manager manager("kevin",456789,150.00);
#ifdef _ERROR_
	manager.showInfo();            //private��Ա����ֱ�ӷ���
	cout<<manager.getName()<<" salary is "<<manager.salary()<<endl;
#else
	cout<<manager.getName()<<" salary is "<<manager.getSalary()<<endl;
#endif

	return 0;
}
