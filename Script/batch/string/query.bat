@echo off & setlocal & setlocal EnableDelayedExpansion
rem �ַ����������������find��findstr��findstr��find�ļ�ǿ�棬����/cֻ��ʾƥ�亯���⣬����������ʵ�֡�
rem �����������ʹ��find /?��findstr /?�鿴�����ĵ���

rem ��ΪfindΪϵͳ���õ�������������������ļ�������Ҫ����Ϊfind.bat��
rem ����data.txt�ļ��а�����Hello�У����ִ�Сд��
find "Hello" data.txt
echo=
findstr "Hello" data.txt

rem ����data.txt�ļ��а�����Hello�У����ִ�Сд��
find /i "Hello" data.txt

rem ����data.txt�ļ��в�������please�ַ����У����ִ�Сд��
find /v /i "please" data.txt

rem �ַ�����Ϊ���룬���Ҹ��ַ����Ƿ������hello��
echo hello world | find /i "hello"
echo=
echo Hello marcus | findstr /i "hello"

rem ����data.txt�ļ���Hello��ͷ���У����ִ�Сд�����ֱȽ����ų�˫���š��ո���š�
findstr /i "^Hello" data.txt

rem ����data.txt�ļ���Hello��β���У����ִ�Сд�����ֱȽ����ų�˫���š��ո���š�
rem �ļ����һ�������ǿհ��У������һ�е�hello$ƥ�䲻�����ַ�������ʱhello$Ҳƥ�䲻����
findstr /i "hello$" data.txt