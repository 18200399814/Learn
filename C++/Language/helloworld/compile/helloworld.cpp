/*Visual Studio��װĿ¼VC\Tools�µ�һЩ���ù��ߣ�
 *1.������cl.exe
 *2.�����ml.exe/ml64.exe
 *3.�ν���link.exe
 *4.��̬��������lib.exe
 *5.����Makefile�ļ������ͱ��빤��nmake.exe
 *6.�鿴dll��exe�������⹤��dumpbin.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

char *str = (char*)malloc(SIZE);

int main(void)
{
	memset(str,0,SIZE);
	strcpy(str,"hello world");
	puts(str);
	
	return 0;
}