@echo off
echo=
echo "[usage]: build.bat {cl/g++/clean}"
echo=

set cmd=%1
if "%cmd%" == "clean" (
	del /Q /f *.o *.obj main.exe
	exit /b
)

rem ��ΪWindows���û������������У���ӵ�INCLUDE��LIB��������ֵ����"()"С���ţ�
rem ��������������䲻�ܷ���if����У���������if������Ų�ƥ�����⡣
set INCLUDE=D:\Qt5.12\5.12.0\msvc2017_64\include;%INCLUDE%
set LIB=D:\Qt5.12\5.12.0\msvc2017_64\lib;%LIB%

rem vc++����������ʱ���ŻᵽINCLUDE��LIB�����������Զ�����ͷ�ļ�����ļ���
if "%cmd%" == "cl" (
	echo ---compile *.cpp to *.obj---
	cl /c sample.cpp
	cl /c moc_sample.cpp /Fo"moc_sample.obj"
	echo=
	
	echo --compile main.cpp to main.exe---
	echo=
	cl /Fe"main.exe" main.cpp sample.obj moc_sample.obj /link Qt5Cored.lib
	del /f main.obj
	echo=
)

rem cmd�ű��ļ���Ĭ��Ϊȫ�ֱ�����ʹ��setlocal����ɽ���������������Ϊlocal�ֲ���
setlocal EnableDelayedExpansion

rem ��Windows�����У�g++����ʱ�����Զ�����INCLUDE��LIB���������е�ͷ�ļ�����ļ���
rem INCLUDE��LIB��������ֻ��vc++��������Ч��
if "%cmd%" == "g++" (
	if not defined set_qtenv (
		echo ---setting up qt header and library environment---
		set INCLUDE=D:\Qt5.12\5.12.0\mingw73_64\include
		set LIB=D:\Qt5.12\5.12.0\mingw73_64\lib
		echo=
	)

	echo ---compile *.cpp to *.obj---
	g++ -c sample.cpp -o sample.o -I !INCLUDE!
	g++ -c moc_sample.cpp -o moc_sample.o -I !INCLUDE!
	echo=

	echo --compile main.cpp to main.exe---
	echo=
	g++ main.cpp sample.o moc_sample.o -L !LIB! -lQt5Cored -o main.exe -I !INCLUDE!
	echo=
)

if "%cmd%" == "" (
	if not defined set_qtenv (
		echo ---setting up qt header and library environment---
		set INCLUDE=D:\Qt5.12\5.12.0\mingw73_64\include
		set LIB=D:\Qt5.12\5.12.0\mingw73_64\lib
		echo=
	)
	
	echo ---compile *.cpp to *.obj---
	g++ -c sample.cpp -o sample.o -I !INCLUDE!
	g++ -c moc_sample.cpp -o moc_sample.o -I !INCLUDE!
	echo=

	echo --compile main.cpp to main.exe---
	echo=
	g++ main.cpp sample.o moc_sample.o !LIB!\libQt5Cored.a -o main.exe -I !INCLUDE!
	echo=
)

echo ---runing main.exe---
main.exe

set set_qtenv="set qt library environment"