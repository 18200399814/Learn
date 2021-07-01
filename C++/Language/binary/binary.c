/*������ԭ�롢����Ͳ������߶���ȡ�Ҳ����˵����������ԭ�롢����Ͳ��롣
 *����Ͳ�����Ҫ����Ը�����˵�ģ��������ڴ��о����Բ������ʽ�洢�ġ�
 *�������ڴ�������ԭ����ʽ�洢�ġ�
 */

/*������ԭ��Ͳ���֮���໥ת�����м��룬�Ա���ԭ��Ͳ���֮����໥���㡣
 *ʵ�ʼ�����в�û��һ���������Է������ʽ�洢�ġ�
 */

/*1.ԭ����Ƿ���λ������ֵ�ľ���ֵ�����õ�һλ��ʾ���ţ�����λ��ʾֵ��
 *2.�����ķ������䱾�������ķ���������ԭ��Ļ����ϣ�����λ���䣬�������λȡ����
 *3.�����Ĳ�������䱾�������Ĳ���������ԭ��Ļ����ϣ�����λ���䣬�����λȡ��������1��
 *  ���������ڷ���Ļ����ϼ�1��
 */

/*mingw�������ṩ�ı�׼��ֻ�Ƕ�msvc��������׼���һ�ַ�װ���ѡ�msvc��׼����ʵ�ֵĺ�����
 *��mingw��������׼�ⶼ�ж�Ӧ�ĺ�������msvc��������׼����û���ṩ�Ľӿڣ���mingw��׼��
 *�ж��Ҳû���ṩ��
 */

#include <stdio.h>
#include <stdlib.h>   //itoa() - cl������
#include <string.h>   //memset(),bzero() - gcc������

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

#define BUFF_SIZE 64

int main(void)
{
	int x = 6;
	printf("decimal: x =%d\n",x);
	printf("octal: x =%o\n",x);
	printf("hexadecimal: x =%x\n",x);
	
	/*itoa()���Ǳ�׼C�⺯����ֻ��vc++/mingw gcc��������string.hͷ�ļ���ʵ���������������gcc�������ṩ��
	 *��׼C��ͷ�ļ�string.h��û�ж���ú�����
	 */
	char buf[BUFF_SIZE] = {0};
	itoa(x,buf,2);
	printf("binary: x =%s\n\n",buf);   //�������ڴ�����ԭ�����ʽ�洢

	int y = -6;
	fprintf(stdout,"decimal: y =%d\n",y);
	fprintf(stdout,"octal: y =%o\n",y);
	fprintf(stdout,"hexadecimal: y =%x\n",y);
	
	/*bzero()Ҳ���Ǳ�׼C�⺯��������������POXIS��׼�⺯�����������µ�POXIS��׼���Ѿ���bzero()�����Ƴ���
	 *���Ƽ�ʹ��memset()����bzero()��������Ϊbzero()ֻ������POXIS��׼�й�������ֻ��gcc��������string.h
	 *ͷ�ļ���ʵ���������������msvc/mingw�������ṩ�ı�׼C��ͷ�ļ�string.h��û�ж���ú�����
	 */
#ifndef _CHANGE_WAY_
	memset(buf,0,BUFF_SIZE);
#else
	bzero(buf,sizeof(buf));
#endif
	itoa(y,buf,2);
	fprintf(stdout,"binary: y =%s\n",buf);   //�������ڴ����Բ������ʽ�洢
	
	return 0;
}