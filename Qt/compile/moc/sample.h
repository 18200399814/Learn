#ifndef _SAMPLE_H
#define _SAMPLE_H

#include <QtCore/QObject>

typedef int data_t;

class Sample:public QObject
{
	Q_OBJECT
public:
	explicit Sample(const data_t& value);
	virtual ~Sample();   //Sample����û�г�Աָ�룬���Կ��Բ���Ҫ��������������������Դ
	
	void setValue(const data_t& value);
	data_t getValue()const;
	void display()const;

signals:
	void changeValue(const data_t& value);

public slots:
	void onChangeValue(const data_t& value);
	
private:
	data_t value;
};

#endif //_SAMPLE_H