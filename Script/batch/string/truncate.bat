@echo off & setlocal & setlocal EnableDelayedExpansion

rem �ַ�����ȡ
set str=This is a string function demo

rem ������5λ��ʼ��ȡ4λ��demo
echo %str:~-4,4%

rem ������13λ��ʼ��ȡ�����ַ���function demo
echo %str:~-13%

rem ����100λ��ʼ����Ϊ�����˳��ȣ����Է��ش�0��ʼ���ַ�����This is a string function demo
echo %str:~-100%

rem ˳����0λ��ʼ��ȡ4λ��This
echo %str:~0,4%

rem ˳��0λ��ʼȡ�����ַ���This is a string function demo
echo %str:~0%

rem ˳��0λ��ʼ��ȡ100λ�������ȷ��أ�This is a string function demo
echo %str:~0,100%

rem ��ʾϵͳʱ�䣬ȥ������ĺ�����ʾ
echo %time:~0,8%

