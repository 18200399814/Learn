@echo off
rem ��������������ֱ�����ã���ֵĬ��Ϊ�գ����Ҵ�Сд�����С�
:: ����ʹ��defined�ؼ��ֻ����Ƿ�Ϊ���ַ������жϱ����Ƿ�Ϊ�ա�

@echo off
echo ---����ʹ��---
echo=
if not defined var1 (                                     %if��else���Ľṹ�̶���else�������⻻��%
	echo var1 is not defined, the value is: %var1%
) else (
	echo var1 is defined, the value is: %var1% 
)

set var2="var2 test"                                      %������ֵ�Ⱥ�ǰ�����пո�%
if %var2% == "" (
	echo var2 is not defined, the value is: %var2%
) else (
	echo var2 is defined, the value is: %var2%
)

rem var=����Ϊ���var������ֵ���������ļ��еı���Ĭ�϶���ȫ�ֵģ�ֻҪ��һ��cmd��������б����ڡ�
set var2=
echo var2 = %var2%

rem cmd�ű��ļ���Ĭ��Ϊȫ�ֱ�����ʹ��setlocal����ɽ���������������Ϊlocal�ֲ��ģ�
rem ֱ������endlocal��exit�����bat�ļ�ִ�н���������local������Ž������ظ���global������
setlocal
set localVar=local variable
echo localVar = %localVar%
endlocal

rem ������׼��ִ��һ�����������������Ƚ������ȡ������������б�������ô���Ƚ�������ֵ��ȡ������Ȼ���������������
set x=1
set /a x+=1 > nul & echo x = %x%           %x��ֵ���Ϊ1�������Ǽ�����ֵ2%

rem !var!������̾�ű�ʾ�ӳٶ�ȡ������ֵ��������Ҫ��ʹ��setlocal EnableDelayedExpansion����������ʱ��
rem ����������ʱ�������ע������ʱ��ιرա���ʱΪ�˴����ֱ࣬��д��bat�ļ���ͷ@echo off�������.
rem @echo off & setlocal EnableDelayedExpansion��
setlocal EnableDelayedExpansion
set y=1
set /a y+=1 > nul & echo y = !y!