@echo off

rem ��ȡ������ű�����ʱ���û�����ĵ�һ���������
set cmd=%1

rem exit /b�˳�������ű��������������������ն�
if "%cmd%" == "clean" (
	rmdir /Q /S build\debug build\release
	del /Q /f build\Makefile build\Makefile.Debug build\Makefile.Release build\.qmake.stash bin\*
	exit /b
)

rem �л���buildĿ¼��ִ��build.bat�ű�����build.bat�ű�ִ�����Ժ����л���ԭ����Ŀ¼��
cd  build && build.bat && cd ..