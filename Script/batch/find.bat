@echo off
rem nul�����κγ�������
rem ʹ��ping������ʵ�ֳ�����ʱЧ��
rem �ܵ���|���ڽ�һ������������Ϊ����һ�����������

echo hello world > nul   %�����Ϣ�������������ӡ%

rem /i�����ִ�Сд
set str1=The most severs place New SARA is Wuhan
set str2=%~1
echo %str1% | findstr /i %str2% > nul && (echo found) || (echo not found)

echo=
echo "program sleep 5 seconds, start..."
ping /n 5 192.168.3.221 > nul
echo "program sleep 5 seconds, start..."

rem /bʹ�ÿո�ʽ����û�б�����Ϣ����ժҪ
dir /b | sort                              %��dir /b�Ľ�������ַ�����%
exit /b 0