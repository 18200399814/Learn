@echo off
echo=
echo ---qmake compile start---
qmake ../test-mylabel.pro
echo ---c++ compile start---
echo=
make -f Makefile
echo=

echo ---running---
echo=
..\bin\testmylabel.exe
