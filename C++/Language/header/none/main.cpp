#include "sample.h"            //�������ample.hͷ�ļ����Ұ�����˳��Ϊ��sampleproxy.hͷ�ļ���ǰ��
                               //�������ȱ��Sample���Ͷ�����main.cpp���벻ͨ��
#include "sampleproxy.h"

int main()
{
	Sample *psample = new Sample(10);
	SampleProxy proxy(psample);
	
	proxy.setNum(20);
	proxy.display();
	
	return 0;
}