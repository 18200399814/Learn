@echo off
rem ����Qt MSVC64λ����MSVC62λ�������л�����
rem ���windows cmdִ�е�������ű�·���д��пո���ô����Ҫ���������˫���š�
echo [usage]: setupenv.bat x86 or setupenv.bat x64
echo=
set cmd=%1
if "%cmd%" == "x86" (
	D:\Qt5.12\5.12.0\msvc2017\bin\qtenv2.bat
	"D:\Visual Studio 2017\VC\Auxiliary\Build\vcvars32.bat"
	E:
	cd E:\Github\Learn\Qt
)

if "%cmd%" == "x64" (
	D:\Qt5.12\5.12.0\msvc2017_64\bin\qtenv2.bat
	"D:\Visual Studio 2017\VC\Auxiliary\Build\vcvars64.bat"
	E:
	cd E:\Github\Learn\Qt
)