@echo off
rem �ж������ַ�����ȿ���ʹ��==��equ�������ʹ��not��neq��
rem ���������ļ���>��<��ʾΪ�ض�����ţ����Բ���ʹ��>��ʾ���ڣ�<��ʾС�ڣ�
rem Ҳ����ζ�Ų���ʹ��>=,<=,<>��ʾ���ڵ��ڣ�С�ڵ��ںͲ����ڡ�
rem equ���ڣ�neq�����ڣ�lssС�ڣ�leqС�ڵ��ڣ�gtr���ڣ�geq���ڵ��ڡ�

setlocal
set /p arg1="please input a string:"
set /p arg2=please input another string:

setlocal
if %arg1% == %arg2% (
	echo %arg1% equals %arg2%
) else (
	echo %arg1% not equals %arg2%
)

if not %arg1% == %arg2% (
	echo %arg1% not equals %arg2%
) else (
	echo %arg1% equals %arg2%
)

if %arg1% equ %arg2% (
	echo %arg1% equals %arg2%
) else (
	echo %arg1% not equals %arg2%
)

if %arg1% neq %arg2% (
	echo %arg1% not equals %arg2%
) else (
	echo %arg1% equals %arg2%
)
endlocal

rem ��/i���Դ�Сд
echo=
set /p name=please input your name:
if /i "%name%" == "amy" (echo you are amy!) else (echo you are not amy)

echo=
set /a num1=1+1
set num2=2
if %num1% gtr %num2% (echo %num1% greater than %num2%) else (echo %num1% less than %num2%)
if %num1% geq %num2% (echo %num1% greater than or equals %num2%) else (echo %num1% less than %num2%)
