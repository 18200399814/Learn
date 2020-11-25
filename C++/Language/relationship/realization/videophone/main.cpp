#include "videophone.h"

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

int main()
{
	Videophone* pvideophone = new Videophone();
	pvideophone->call();
	pvideophone->show();

#ifndef _CHANGE_WAY_
	IPhone* pphone = pvideophone;
	pphone->call();
	// pphone->show();                //IPhone�ӿ�û��show()����
#else
	IPhone* pphone = (IPhone*)pvideophone;
	if(pphone != nullptr)                         //ʵ��������ָ���Ƿ�Ϊ���ж�û���ã���ΪֻҪpvideophone��ΪNULL����ת���ɹ������Ǵ��ڷ��ա�
	{                                             //�������Ͷ�����ʹ��C���ǿ��ת,��ʹ����֮��û�м̳й�ϵ
		pphone->call();          
		// pphone->show();              //IPhone�ӿ�û��show()����
	}
#endif
	
#ifndef _CHANGE_WAY_
	IVideo* pvideo = pvideophone;
	// pvideo->call();                //IVideo�ӿ�û��call����
	pvideo->show();
#else
	IVideo* pvideo = dynamic_cast<IVideo*>(pvideophone);        //ʹ��dynamic_cast�����ǿ�ƣ����û�м̳й�ϵ����ǿתΪnullptr
	if(pvideo != nullptr)
	{
		// pvideo->call();           //IVideo�ӿ�û��call����
		pvideo->show();	
	}
#endif

	if(pvideophone != nullptr)
	{
		delete pvideophone;
		pvideophone = nullptr;
	}
	
	return 0;
}