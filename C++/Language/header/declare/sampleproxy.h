#ifndef _SAMPLE_PROXY_
#define _SAMPLE_PROXY_

class Sample;          //ǰ������Sample����

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
	
	Sample* psample;     //��Ϊ��������Sample���͵�ָ�룬���Կ���ʹ��ǰ�������ķ�ʽ�������Sample���͵Ķ��������ʹ��ͷ�ļ������ķ�ʽ��
};

#endif //_SAMPLE_PROXY_