#include "variable.h"

std::array<std::string,ATTRIBUTE_COUNT> variable;

void initVariable()
{
	variable[VAR_NAME] = "var";
	variable[INIT_VALUE] = "3.14";
	variable[DATA_TYPE] = "analog";
	variable[IO_TYPE] = "input";
	variable[UNIT_INDEX] = "mA";
	variable[TOP_LIMIT] = "100";
	variable[BOTTOM_LIMIT] = "0";
	variable[TOP_VIEW] = "80";
	variable[BOTTOM_VIEW] = "5";
}

#ifdef _DUMMY_
static int dummy = (initVariable(),0);       //����ȫ�ֱ�����Ҫ��ʼ�����ص㣬����ĵ���initVariable()����,
#endif                                       //��������main��������ʾ����initVariable()����