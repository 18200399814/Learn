@echo off
rem ����ͨ��%var%��ȡ������ֵ��
rem /a�Ǳ��ʽ���㣬���ʺ�32λ�������㣬�����Ǹ�����
rem /p����ʾ���룬�������ֵ��ֵ��������
rem =<���Խ��ļ��е�������ȡ��������ֵ��������
rem set var���г�var��ͷ�����б�����
rem !var!�е�������̾�ţ���ʾ�ӳٶ�ȡ������

set var=1+1
set /a var1=2+2
set /p var2=please input a number:
set /p fileText=<test.txt
echo var: %var%
echo var1: %var1%
echo var2: %var2%
echo fileText: %fileText%

echo ---ϵͳ���ñ���---
echo ϵͳ����: %date%
echo ϵͳʱ��: %time%
echo ��ǰĿ¼: %cd%
echo ���������: %random%               %����0-32757֮�������ʮ������%
echo ��ǰ�������¼���û���: %username%
