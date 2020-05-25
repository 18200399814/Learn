#include "chinese.h"
#include "french.h"
#include "american.h"
#include "korean.h"

int main()
{
	Chinese chinese("����");
	chinese.sayHello();
	
	French french("�շ�");
	french.sayHello();
	
	Man* pman = new American("Tom");
	pman->sayHello();
	if(pman != nullptr)
	{
		delete pman;
		pman = nullptr;
	}
	
	Man&& man = Korean("��֪��");       //��ֵ����Man&&�ſ���������ʱֵ����ֵ���ò���������ʱ����
	man.sayHello();
	
	return 0;
}