@echo off
rem ��Ϊ������ű��ķ���ֵ������exit���������õģ����ű��˳�ʱ�ŷ��أ�
:: ���Բ����ڴ���������������ļ��У�ʹ��errorlevel�жϷ���ֵ��

echo return code is: %errorlevel%

rem errorlevel 1 , errorlevel >= 1
if errorlevel 1 (echo fail) else (echo success)

rem %errorlevel% EQU 0 , errorlevel == 0
if %errorlevel% EQU 0 (
	echo success
) else (
	echo fail
)