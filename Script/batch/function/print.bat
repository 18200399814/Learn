@echo off
rem bat�ű�����򵥵ĺ���д���ǣ���:func��ʼ����goto :eof������:func��goto :eof֮��Ϊ�������ݡ�
rem �������������ַ�����goto func��call :func��
rem call :func��������:func�е�goto :eof���ʱ������������ű������˳���
rem goto func��������:func�е�goto :eof���ʱ������������ű����˳���

set ret=0

call :func
goto sum
pause
echo end batch
rem exit
goto :eof

:func
echo this is a bat func
goto :eof

:sum
for /l %%i in (1,1,100) do (set /a ret+=%%i)
echo 1-100 sum: %ret%
goto :eof