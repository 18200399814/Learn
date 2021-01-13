//C++�м�鵥��Դ�ļ��Ƿ���Ա���ͨ�������g++ -c Դ�ļ��������磺g++ -c date.cpp �� g++ -c date.cpp -o date.o

#ifndef _DATE_H
#define _DATE_H

#include <iostream>

class Date
{
public:
	Date(int year,int month,int day);
	Date(const Date& other);
	
	Date& operator =(const Date& other);
	bool operator ==(const Date& other);
	
	void setYear(int year);
	int year()const;         //��Ϊ������year()��Ա���������Բ����ٶ���year��Ա������ֻ�ܽ�year��Ա����������Ϊm_year�ȡ�
	
	void setMonth(int month);
	int month()const;
	
	void setDay(int day);
	int day()const;
	
	void print()const;
	
	friend std::ostream& operator <<(std::ostream& os,const Date& other);
	
private:
	int m_year;      //C++�к������������ͬ����������ʶ����������ͻ��������벻ͨ����
	int m_month;     //C++�к����뺯������ͬ����������ͬ���ֳ�Ϊ���������ء�
	int m_day;
};

#endif //_DATE_H