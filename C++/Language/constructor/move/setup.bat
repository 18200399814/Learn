@echo off
echo ---compile start---
echo=
cl /Od main.cpp sample.cpp   %ѡ��/Od�ر�MSVC�������Ż�������VC++���������ܹرտ��������Ż�%
echo=
echo ---compile successfully---

echo ---delete object file---
del /f main.obj sample.obj

echo ---running---
echo=
set var="change way"
if %var% == "" (
	start main.exe        rem �����´򿪵�������������main.exe����
) else (
	main.exe              rem �ڵ�ǰ�ն�������main.exe����
)