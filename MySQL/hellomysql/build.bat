@echo off
set cmd=%1
if "%cmd%" == "clean" (
	del /f hellomysql.exe
	exit /b
)

echo ---compile start---
rem /link�������е����ಿ�ִ��ݵ�link.exe�ν�����
rem /Linkѡ���������ѡ�����������κ��ļ�����clѡ��֮��/Link���κ�������ѡ��֮����Ҫ��һ���ո�
cl hellomysql.c /I"D:\MySQL8.0.16\include" /link /LIBPATH:"D:\MySQL8.0.16\lib"
echo=

echo ---delete objece file---
del /f hellomysql.obj
echo=

echo ---run hellomysql.exe---
hellomysql.exe
