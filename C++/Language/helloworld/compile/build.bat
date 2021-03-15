@echo off
echo=
set cmd=%1
if "%cmd%" == "clean" (
	del /Q /f helloworld.i helloworld.asm helloworld.obj helloworld.exe
	exit /b
)

rem cl��������Ԥ����׶ν����ɺ�չ�����.iԤ�����ļ�
echo ---preprocess---
cl /P helloworld.cpp /Fi:helloworld.i
echo=

rem cl�������ڱ�������׶ν�.iԤ�����ļ�����/���Ϊ.asm�������.obj�ļ���
echo ---compile add assembly---
cl /FAs /c /Tp helloworld.i

rem Ŀǰ�����cl���������ɵ�.asm�������ml�������ʹ�÷�����������ʱ�Ȳ���ʾMSVC�������Ļ��׶Ρ�
set flag=close assembly
if "%flag%" == "open assembly" (
	rem cl�ı���ͻ���������һ����ɵģ�ֻ��ʹ��/FAsѡ����ָ������.obj�������ļ������У�
	rem ˳�����.asm�ļ�����û�а취������.asm�������������.obj�������ļ���
	echo ---only keep *.asm, delete *.obj file---
	del /f helloworld.obj
	echo=

	rem ���׶�ml.exe/ml64.exe��.asm�����뷭���.obj�������ļ���
	echo ---assembly compile---
	ml64 /c helloworld.asm
	echo=
)

rem �νӽ׶�link.exe�����е�.obj�������ļ��ν�Ϊ.exe��ִ���ļ�
echo ---link object file---
link helloworld.obj /out:helloworld.exe
echo=

echo ---run helloworld.exe---
helloworld.exe