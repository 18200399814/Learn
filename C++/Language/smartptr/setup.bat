@echo off
echo ----compile start----
echo=
cl /Od main.cpp demo.cpp    %ѡ��/Od�ر�MSVC�������Ż�������VC++���������ܹرտ��������Ż�%
echo=
echo ----compile successful----

echo ----delete middle file----
del /f main.obj demo.obj

echo ----running----
echo=

set flag="change way"
if %flag% == "" (
	start main.exe    rem ���´򿪵�������������main.exe����
) else (
	main.exe          rem �ڵ�ǰ�����д���������main.exe����
)