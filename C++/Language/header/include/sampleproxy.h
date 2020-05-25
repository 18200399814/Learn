#ifndef _SAMPLE_PROXY_
#define _SAMPLE_PROXY_

#include "sample.h"          //ͷ�ļ����������ṩSample����

class SampleProxy
{
public:
	SampleProxy(Sample* psample=nullptr);
	virtual ~SampleProxy();
	
	void setNum(const int num);
	int getNum()const;
	void display()const;
private:
	SampleProxy(const SampleProxy& other);                 //˽�еĿ������캯���͸�ֵ��������Բ���ʵ��
	SampleProxy& operator=(const SampleProxy& other);
	
	Sample* psample;
};

#endif //_SAMPLE_PROXY_