#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#define _DEEPLY_COPY_
// #undef _DEEPLY_COPY_

enum ReleaseType
{
	DELETE_POINTER,
	SET_NULLPTR
};

class Date;

class Employee
{
public:
	Employee(int number);
	Employee(int number,Date* pbirthday);
	Employee(const Employee& other);
	virtual ~Employee();              //һ����������һ�������ָ���Ա����ô��Ҫʵ�������������Է�ֹ����󲻴����Ժ󣬳�Աָ����ɵ��ڴ�й©���⡣
	
	Employee& operator =(const Employee& other);
	bool operator ==(const Employee& other);

	void release(ReleaseType type = DELETE_POINTER);            //�ͷ�birthday��Աָ��ָ��Ķ��ڴ�ռ䡣
#ifndef _DEEPLY_COPY_
	void setBirthday(Date* pbirthday);       //ʹ��ǳ����ʵ��setBirthday����ʱ���亯�����β�����const Date*����ΪC++��const Date*ָ�벻��ֱ�Ӹ�ֵ��Date*ָ�롣
#else
	void setBirthday(const Date* pbirthday); //ֻ�����ʵ��setBirthday����ʱ���亯������������const Date*ָ�룬Ҳ������Date*ָ�롣
#endif
	Date* getBirthday();
	
	void setNumber(const int number);
	int getNumber()const;
	
	void show()const;
private:
	Date* pbirthday;
	int number;
};

#endif //_EMPLOYEE_H