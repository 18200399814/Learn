@echo off & setlocal
rem bat�ű�ʵ��ѭ���ķ�ʽ�����֣�ʹ��goto��forѭ�����Ƽ�ʹ��forѭ����䡣
rem bat�ű���û��continue��return��break���ж���䣬ֻ��ͨ��goto����ѭ����
rem ʹ��forѭ��ʱ��bat�ļ��б���ʹ��%%i����cmd�������ʹ��%i��
rem ������cmd�������ʹ��for /���鿴for���������Ϣ��

rem goto��ʽʵ��1-10��ѭ��
set var=0
rem ***loop start***
:continue
set /a var+=1
echo loop time: %var%
if %var% lss 10 goto continue
rem ***loop end***
echo loop execution finished

rem FOR /L %variable IN (start,step,end) DO command [command-parameters]
rem FOR /D %variable IN (set) DO command [command-parameters]
echo=
rem ***loop1 start***
for /l %%i in (1,1,10) do (echo loop time: %%i)
rem ***loop1 end***
echo loop1 execution finished

echo=
rem ***loop2 start***
for %%i in (Beijing,Shanghai,Chengdu,Wuhan,Chongqing) do echo %%i
rem ***loop2 end***
echo loop2 execution finished


