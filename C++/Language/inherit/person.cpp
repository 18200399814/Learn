#include <iostream>

using namespace std;

class Person
{
public:
	Person(){cout<<"person constructor"<<endl;}
	~Person(){cout<<"person destructor"<<endl;}
	
	void input()
	{
		cout<<"������"<<endl;cin>>name;
		cout<<"��ţ�"<<endl;cin>>number;
		cout<<"���䣺"<<endl;cin>>age;
	}
	
	void display()const
	{
		cout<<"������"<<name<<endl;
		cout<<"��ţ�"<<number<<endl;
		cout<<"���䣺"<<age<<endl;
	}
private:
	char name[32];
	char number[32];
	int age;
};

class Student:public Person
{
public:
	Student(){cout<<"Student constructor"<<endl;}
	~Student(){cout<<"Student destructor"<<endl;}
	
	void input()
	{
		Person::input();
		cout<<"�༶��"<<endl;cin>>department;
		cout<<"�ɼ���"<<endl;cin>>degree;		
	}
	
	void display()const
	{
		Person::display();
		cout<<"�༶��"<<department<<endl;
		cout<<"�ɼ���"<<degree<<endl;
	}
private:
	char department[32];
	int degree;
};

class Teacher:public Person
{
public:
	Teacher(){cout<<"Teacher constructor"<<endl;}
	~Teacher(){cout<<"Teacher destructor"<<endl;}
	
	void input()
	{
		Person::input();
		cout<<"���ޣ�"<<endl;cin>>major;
		cout<<"нˮ��"<<endl;cin>>salary;			
	}
	
	void display()const
	{
		Person::display();
		cout<<"���ޣ�"<<major<<endl;
		cout<<"нˮ��"<<salary<<endl;		
	}
private:
	char major[32];
	float salary;	
};

int main()
{
	Student student;
	Teacher teacher;
	
	cout<<"������ѧ����Ϣ��"<<endl;
	student.input();
	student.display();
	
	cout<<endl;
	
	cout<<"��������ʦ��Ϣ��"<<endl;
	teacher.input();
	teacher.display();
	
	return 0;
}