@echo off
rem �����ڡ�Visual Studio������ʾ���ն������д˽ű�
rem VC++��������ʹ�õ���nmake�������ߣ�g++������ʹ�õ���make��������

qmake ..\manual\manual.pro
nmake /f Makefile Debug

echo ---run login.exe---
echo =
start E:\Github\Learn\Qt\manual\bin\login.exe