rem �����ڡ�Visual Studio������ʾ���ն������д˽ű�
rem VC++��������ʹ�õ���nmake�������ߣ�g++������ʹ�õ���make��������
@echo off
qmake ..\manual\manual.pro
nmake /f Makefile Debug

echo run login.exe
start E:\Github\Learn\Qt\manual\bin\login.exe