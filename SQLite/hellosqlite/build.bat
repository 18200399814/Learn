@echo off
set cmd=%1
if "%cmd%" == "clean" (
	del /f bin\hellosqlite.exe bin\test.db build\hellosqlite.obj
	exit /b
)

rem /link�������е����ಿ�ִ��ݵ�link.exe�ν�����
rem /Linkѡ���������ѡ�����������κ��ļ�����clѡ��֮��/Link���κ�������ѡ��֮����Ҫ��һ���ո�
echo ---compile start---
set flag=change_way
if "%flag%" == "change_way" (
	cl hellosqlite.c /Fe:bin\hellosqlite.exe /D_CHANGE_WAY_ /Fo:build\hellosqlite.obj /I"include" /link /LIBPATH:"lib"
) else (
	cl hellosqlite.c /Fe:bin\hellosqlite.exe /Fo:build\hellosqlite.obj /I"include" /link lib\sqlite3.lib
)
echo=

echo ---run hellosqlite.exe---
bin\hellosqlite.exe