@echo off
rem %0�ű��ļ�����%1��һ��������%2�ڶ���������
rem %*�����б�������ű��ļ�����
rem %~1��һ������ȥ���š�
rem %~f0�ű��ļ�����·������
rem %~dp0�ű��ļ����ڵ�Ŀ¼��
rem %~n0������׺�ű��ļ�����

echo arg0=%0
echo arg1=%1
echo arguments list=%*
echo arg1 no quotes=%~1
echo batfile fullpath=%~f0
echo batfolder=%~dp0
@echo on

@echo off
rem ͨ��һ�������ִ�н�����ص�ֵ��������0��ʾ�ɹ���1��ʾʧ�ܡ�
rem ʵ����errorlevel����ֵ������һ����������ֵ��һ��ֻ������0~255֮��
rem bat�ű��ļ���exitָ����code�������룬Ҳ������һ�л�ȡ����errorlevelֵ��
rem ���bat�ű��ļ���û��exit�����ôerrorlevel��ֵ������һ���ķ���ֵ��

set var=1
exit /b %var%

echo return code is: %errorlevel%     %ǰ��exit�Ѿ��˳������Բ���ִ��%