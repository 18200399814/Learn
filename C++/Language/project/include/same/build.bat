@echo off
cl testcase.c math.c
echo ---build success---
del /f /s /q .\*.obj          rem �������������м��ļ�
echo=
echo ---runing---
testcase.exe