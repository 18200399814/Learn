rem ����������cmd�ն������д˽ű�
rem mingw32-makeҲ�����滻Ϊmake�����Ϊmingw32-make.exe����ֵ������Ϊmake.exe��
@echo off
qmake ..\manual\manual.pro
mingw32-make

echo run login.exe
start E:\Github\Learn\Qt\manual\bin\login.exe