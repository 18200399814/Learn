#pro���̹����ļ��������������ڹ���Qt���̣���ͨ��C/C++����Ҳ����ʹ��pro�ļ�������

QT += core

TARGET = macro
TEMPLATE = app

CONFIG += console c++11
DESTDIR = $$PWD/bin

DEFINES += _SUB_    #������pro�ļ��ж���꣬Ȼ����Դ�ļ���ʹ������궨��

HEADERS += include/mymath.h

SOURCES += source/main.c  \
	       source/mymath.c

INCLUDEPATH += $$PWD/include   #ָ������ʱͷ�ļ���·������ָ��ͷ�ļ���������