#include "crypto.h"
#include <string.h>

#define KEY 0x86
#define SIZE 256

int main()
{
	int plainNum = 1000;
	PRINT_INT(plainNum);
	
	int cipherNum = cryptoNum(plainNum,KEY);
	PRINT_INT(cipherNum);
	
	DEBUG_FLAG
	
	plainNum = 0;
	PRINT_INT(plainNum);
	plainNum = cryptoNum(cipherNum,KEY);
	PRINT_INT(plainNum);
	
	char src[] = "hello world";
	PRINT_STR(src);

#if defined(_BETTER_)
	char dts[SIZE] = {0};
	if(cryptoStr(src,dts,KEY))
	{
		PRINT_STR(dts);
	}
#if 0	
	memset(src,0,SIZE);             //������Ϊsrcֻ��12���ֽڣ�����ǿ�����256���ֽڣ����src��dts�ڴ����ȽϽ��Ļ���
#else                               //�������յ�dts�е����ݡ�������յ�����������ϵͳ���õ�����������������
	memset(src,0,sizeof(src));
#endif
	PRINT_STR(src);
	if(cryptoStr(dts,src,KEY))
	{
		PRINT_STR(src);
	}
	DEBUG_FLAG
#else
	char *dts = NULL;
	if(NULL != (dts = cryptoStr(src,KEY)))
	{
		PRINT_STR(dts);
	}
	
	char *plainStr = NULL;
	if(NULL != (plainStr = cryptoStr(dts,KEY)))
	{
		PRINT_STR(plainStr);
	}

	FREE(dts);
	FREE(plainStr);
#endif

	char src2[] = "hello world";
	PRINT_STR(src2);
	
	char dts2[SIZE] = {0};
	if(encryptStr(src2,dts2,KEY))
	{
		PRINT_STR(dts2);
	}
#if 0	
	memset(src2,0,SIZE);             //������Ϊsrc2ֻ��12���ֽڣ�����ǿ�����256���ֽڣ����src2��dts2�ڴ����ȽϽ��Ļ���
#else                                //�������յ�dts2�е����ݡ�������յ�����������ϵͳ���õ�����������������
	memset(src2,0,sizeof(src2));
#endif
	PRINT_STR(src2);
	if(decryptStr(dts2,src2,KEY))
	{
		PRINT_STR(src2);
	}
	
	return 0;
}