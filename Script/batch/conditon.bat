@echo off
rem exist�����ж��ļ��Ƿ����

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