#include "sampleapi.h"    //ʹ��sample.hͷ�ļ�����һ��sample.h��sampleproxy.hͷ�ļ���Ŀ���Ƿ�ֹͷ�ļ�����˳����󣬶����±��벻ͨ��bug

int main()
{
	Sample *psample = new Sample(10);
	SampleProxy proxy(psample);
	
	proxy.setNum(20);
	proxy.display();
	
	return 0;
}