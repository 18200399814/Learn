#include "employee.h"
#include <iostream>
#include "date.h"

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

using std::cout;
using std::endl;
using std::cin;

Employee::Employee(int number)
	:pbirthday(nullptr)
	,number(number)
{
	
}

#ifndef _DEEPLY_COPY_
Employee::Employee(int number,Date* pbirthday)
	:number(number)
	,pbirthday(pbirthday)
{
	
}
#else
Employee::Employee(int number,Date* pbirthday)
	:number(number)
	,pbirthday(nullptr)
{
	if(pbirthday != nullptr)
	{
		this->pbirthday = new Date(*pbirthday);
	}
}
#endif

#ifndef _DEEPLY_COPY_
Employee::Employee(const Employee& other)
	:number(other.number)
	,pbirthday(other.pbirthday)
{
	
}
#else
Employee::Employee(const Employee& other)
	:number(other.number)
{
	if(other.pbirthday == nullptr)
	{
		pbirthday = other.pbirthday;
	}
	else
	{
		pbirthday = new Date(*(other.pbirthday));   //�������캯���е�pbirthday��Աָ�벻��ʹ��ǳ����ʵ�֡���Ϊ���ʹ��ǳ����ʵ�֣������ɿ������
	}                                               //����Employee��������ʱ���Ⱥ��ͷ�ͬһ��pbirthdayָ��ĵ�ַ������ͬһ��ָ������delete����?
}
#endif

#ifndef _DEEPLY_COPY_
Employee& Employee::operator =(const Employee& other)
{
	number = other.number;
	pbirthday = other.pbirthday;
	return *this;
}
#else
Employee& Employee::operator =(const Employee& other)
{
	number = other.number;
	if(pbirthday != nullptr)
	{
		delete pbirthday;
		pbirthday = nullptr;
	}
	
	if(other.pbirthday != nullptr)
	{
		pbirthday = new Date(*(other.pbirthday));
	}
	
	return *this;
}
#endif

Employee::~Employee()
{
#ifndef _CHANGE_WAY_
	if(pbirthday != nullptr)
	{
		delete pbirthday;
		pbirthday = nullptr;
	}
#else
	delete pbirthday;
#endif
}

bool Employee::operator ==(const Employee& other)
{
	if(number == other.number)
	{
		if(pbirthday == other.pbirthday)
		{
			return true;
		}
		
		if(pbirthday == nullptr || other.pbirthday == nullptr)
		{
			return false;
		}
		
		return *pbirthday == *(other.pbirthday);
	}
	
	return false;
}

void Employee::release(ReleaseType type)
{
	if(type != DELETE_POINTER && type != SET_NULLPTR)
	{
		cout<<"release error: release type is illegal"<<endl;
		return ;
	}
	
	if(type == SET_NULLPTR)
	{
		pbirthday = nullptr;
		return ;
	}
	
#ifndef _CHANGE_WAY_
	if(pbirthday != nullptr)
	{
		delete pbirthday;
		pbirthday = nullptr;
	}
#else
	delete pbirthday;        //��deleteָ��ǰ���Բ������пմ�����Ϊnullptrָ��Ҳ����delete����Ұָ��Ҳ���㲻Ϊnullptr���
	pbirthday = nullptr;     //��ֹpbirthdayָ���ΪҰָ��
#endif
}

#ifndef _DEEPLY_COPY_
void Employee::setBirthday(Date* pbirthday)
{
	this->pbirthday = pbirthday;      //ʹ��ǳ����ʵ�����set����
}
#else     //_DEEPLY_COPY_
#ifndef _CHANGE_WAY_
void Employee::setBirthday(const Date* pbirthday)   //�Ƚ�pbirthday��Աָ����ڴ��ͷŵ��������·����ڴ�ռ�
{
	if(this->pbirthday != nullptr)
	{
		delete this->pbirthday;
		this->pbirthday = nullptr;
	}
	
	if(pbirthday != nullptr)
	{
		this->pbirthday = new Date(*pbirthday);   //ʹ�����ʵ�����set����
	}
}
#else     //_CHANGE_WAY_
void Employee::setBirthday(const Date* pbirthday)   //���pbirthday��Աָ�벻Ϊ��ʱ��ֱ������ָ����ڴ��ϸ��ǡ��������Լ��ٲ���Ҫ���ڴ�������ͷ�ʱ����?
{
	if(pbirthday == nullptr)
	{
		if(this->pbirthday != nullptr)
		{
			delete this->pbirthday;	
			this->pbirthday = nullptr;
		}
		return ;
	}

	if(this->pbirthday == nullptr)
	{
		this->pbirthday = new Date(*pbirthday);   //ʹ�����ʵ�����set����
		return ;
	}
	
	*(this->pbirthday) = *pbirthday;
}
#endif    //_CHANGE_WAY_
#endif    //_DEEPLY_COPY_

Date* Employee::getBirthday()  //�û�ʹ��getBirthday()���ص�ָ��ǰ��������пմ�����Ϊ���п��ܷ���nullptrָ��
{
	return pbirthday;
}

void Employee::setNumber(const int number)
{
	this->number = number;
}

int Employee::getNumber()const
{
	return number;
}

void Employee::show()const
{
	if(pbirthday != nullptr)
	{
		cout<<"birthday ="<<*pbirthday<<" ,";
	}
	
	cout<<"number ="<<number<<endl;
}
