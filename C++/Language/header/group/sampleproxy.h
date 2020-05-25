#ifndef _SAMPLE_PROXY_
#define _SAMPLE_PROXY_

//����sampleproxy.hͷ�ļ���û�а���Sample�������ݣ������������Ȼ���Ա���ɹ���˵����ͷ�ļ��а�������ͷ�ļ�����ǰ�������������Ͷ����Ǳ���ġ�
//ֻҪ��sampleproxy.cppԴ�ļ�����Ҫʹ��sampleproxy.hͷ�ı���Դ�ļ��У��ڰ���sampleproxy.hͷ�ļ�ǰ�Ȱ���sample.h���ɡ���Ϊ��C/C++����С����
//��Ԫ����Դ�ļ�����#includeԤ����ָ�������ֻ�Ǽ򵥵��ļ����ƣ�����������������Ĺ��������������Ƚ���������main���������һ����Դ�ļ�����ͨ����
//Ȼ���ڱ������main������Դ�ļ��н����νӣ�������ɿ�ִ�е�exe�ļ�����

class SampleProxy
{
public:
	SampleProxy(Sample* psample=nullptr);
	virtual ~SampleProxy();
	
	void setNum(const int num);
	int getNum()const;
	void display()const;
private:
	SampleProxy(const SampleProxy& other);               //˽�еĿ������캯���͸�ֵ��������Բ���ʵ��
	SampleProxy& operator=(const SampleProxy& other);
	
	Sample* psample;              //û�а���sample.hͷ�ļ���Ҳû�ж�Sample������ǰ������
};

#endif //_SAMPLE_PROXY_