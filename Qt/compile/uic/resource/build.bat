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
echo ---setting up msvc 64bit qt library environment---
set INCLUDE_BACKUP=%INCLUDE%
set LIB_BACKUP=%LIB%

set INCLUDE=D:\Qt5.12\5.12.0\msvc2017_64\include;%INCLUDE%
set LIB=D:\Qt5.12\5.12.0\msvc2017_64\lib;%LIB%

rem vc++����������ʱ���ŻᵽINCLUDE��LIB�����������Զ�����ͷ�ļ�����ļ���
if "%cmd%" == "cl" (
	echo ---compile *.cpp to *.obj---
	cl /c qrc_resource.cpp /Fo"qrc_resource.obj"
	cl /c mainwindow.cpp /Fo"mainwindow.obj" /link Qt5Cored.lib Qt5Widgetsd.lib
	echo=
	
	echo --compile main.cpp to main.exe---
	echo=
	cl /Fe"main.exe" main.cpp mainwindow.obj qrc_resource.obj /link Qt5Cored.lib Qt5Widgetsd.lib Qt5Guid.lib
	del /f main.obj
	echo=
)

echo ---restore INCLUDE and LIB environment variable---
set INCLUDE=%INCLUDE_BACKUP%
set LIB=%LIB_BACKUP%

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

	echo ---compile *.cpp to *.o---
	g++ -c qrc_resource.cpp -o qrc_resource.o -I !INCLUDE!
	g++ -c mainwindow.cpp -o mainwindow.o -L !LIB! -lQt5Cored -lQt5Widgetsd -I !INCLUDE!
	echo=

	echo --compile main.cpp to main.exe---
	echo=
	g++ main.cpp mainwindow.o qrc_resource.o -L !LIB! -lQt5Cored -lQt5Widgetsd -lQt5Guid -o main.exe -I !INCLUDE!
	echo=
)

rem ��Ϊ��Ҫ��ȡINCLUDE��LIB��ֵ�Ժ��ֵ��������Ҫʹ��!INCLUDE!��!LIB!��ʱ��ȡ������ֵ
if "%cmd%" == "" (
	if not defined set_qtenv (
		echo ---setting up qt header and library environment---
		set INCLUDE=D:\Qt5.12\5.12.0\mingw73_64\include
		set LIB=D:\Qt5.12\5.12.0\mingw73_64\lib
		echo=
	)
	
	echo --compile main.cpp to main.exe---
	echo=
	g++ main.cpp mainwindow.cpp qrc_resource.cpp -L !LIB! -lQt5Cored -lQt5Widgetsd -lQt5Guid -o main.exe -I !INCLUDE!
	echo=
)

echo ---runing main.exe---
main.exe

set set_qtenv="set qt library environment"