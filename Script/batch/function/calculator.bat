@echo off & setlocal
rem bat�ļ���û����ʾ��function��sub�ȹؼ��֡���������ʹ��goto����ʵ�ֺ���,�ﵽ�ֲ��������á�
rem eofֱ���˳���������ͬ��exit��
rem �ں���ִ��ʱ��ִ�����������ת������:eof�����������������ŵ���������������ִ�С�

set num1=%~1
set opt=%~2
set num2=%~3
set ret=0

if "%opt%" == "+" goto add
if "%opt%" == "-" goto sub
if "%opt%" == "*" goto mult
if "%opt%" == "/" goto divi
echo "invalid arguments,usage: calculator 3 + 5, ret is 3 + 5 = 8"
goto :eof

:add
set /a ret=num1+num2
goto result

:sub
set /a ret=num1-num2
goto result

:mult
set /a ret=num1*num2
goto result

:divi
set /a ret=num1/num2
goto result

:result
echo %num1% %opt% %num2% = %ret%