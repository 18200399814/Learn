@echo off
echo=
echo ---qmake compile start---
qmake ../hellomysql.pro
echo ---c++ compile start---
echo=
rem ��Ϊ��װ��MySql API�Ŀ���ʹ��MSCV 64λ���������б���ģ�����ʹ��libmysql.dll
rem ��libmysql.lib���Ӧ�ó���Ҳ��Ҫʹ��MSCV 64λ���������б��롣
nmake -f Makefile
echo=

echo ---running---
echo=
..\bin\hellomysql.exe
