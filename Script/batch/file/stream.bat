@echo off & setlocal & setlocal EnableDelayedExpansion
rem stdin��׼���룬�ض���ʱҲ����ʹ������0��ʾ��
rem stdout��׼������ض���ʱҲ����ʹ������1��ʾ��
rem stderr����������ض���ʱҲ����ʹ������2��ʾ��
rem >�ض���������磺dir > dir.txt,����һ�����ļ�dir.txt������dir�����ӡ�������ļ�����Ŀ¼�б������dir.txt�ļ��С�
rem >>�ض���������磺dir >> dir.txt,��dir�����ӡ�������ļ�����Ŀ¼�б������dir.txt�ļ���,���dir.txt�ļ���������ӣ������½�dir.txt�ļ���
rem <��ĳһ�ļ���Ϊ��������

dir > dir.txt
dir >> dir.txt
echo hello world > test.txt    %��test.txt�ļ��е����ݸ���Ϊhello world%
echo=
echo ---��ʾdir.txt�ļ��е�����---
type dir.txt
echo=
echo ---��dir.txt�ļ��е�����������ʾ---
sort < dir.txt
type con > line.txt             %��Ӧ�������룬ֱ�Ӱ�ctrl+z�����������line.txt�ļ���%