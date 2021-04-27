@echo off
echo=
echo "[usage]: setup.bat {run|clean|install}"
echo=

set cmd=%1
if "%cmd%" == "clean" (
	cd build && make -f Makefile distclean && cd ..
	rmdir /Q /S build\debug build\release
	exit /b
)

rem windeployqt����ָ��exe�ļ���Ҳ����ָ����ִ���ļ����ڵ�Ŀ¼
if "%cmd%" == "install" (
	windeployqt bin
	exit /b
)

if "%cmd%" == "run" (
	cd build && build.bat && cd ..
)

if "%cmd%" == "" (
	cd build && build.bat && cd ..
)
