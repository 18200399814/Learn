@echo off
rem exist�����ж��ļ��Ƿ���ڡ�
rem bat�ļ��е���������ǵ������ģ�������and��or��������������㣬������ʹ��not��������ȡ�����㡣
rem ������ű���û��else if��

if exist "test.txt" (
	echo found
) else (
	echo not found
)

if "%var%" == "" (
	echo var is't defined
) else (
	echo var = %var%
)

rem defined��not defined���������жϱ����Ƿ���
set var1="define var1"
if not defined var1 (echo var1 is't defined) else (echo var1 = %var1%)

rem &˳��ִ�ж�����������ù��Ƿ�ִ�гɹ���
rem &&˳��ִ�ж������������ִ�г���������ִ�к���������ֻ��ǰ�������ִ����ȷ��ִ�к�������
rem |�ܵ�����������һ������������Ϊ����һ����������롣
rem ||˳��ִ�ж������������ִ����ȷ�������ִ�к���������ֻ��ǰ�������ִ�д����ִ�к�������
rem findstr�����ͨ����ʹ��&&��||���ţ��ֱ��ʾ�ҵ�ִ�к�û�ҵ�ִ�С�
set str="Apple,HuaWei,Oppo,Vivo"
echo %str% | findstr /i "apple" > nul && (echo found) || (echo not found)