@echo off
echo ---qmake compile start---
qmake ../macro.pro

echo ---g++ compile start---
rem qmake���ɵ�Makefile�ļ��У�Ĭ��ָ���ı�����Ϊg++
make
echo=

echo ---run macro.exe---
echo=
..\bin\macro.exe