QT += core sql   #QCoreApplication������coreģ���У���QApplication��Qt5�з�����widgetsģ����

TARGET = hellomysql
TEMPLATE = app

CONFIG += console c++11
DESTDIR = $$PWD/bin

SOURCES += main.cpp

#��ΪMySQL�Ŀ��ļ���ʹ��msvc��������������ʹ��mingw����������ģ�������Ҫ�����뻷���л���vc++���뻷��
DEFINES += _MSVC_COMPILE_

if(contains(DEFINES,_MSVC_COMPILE_)){
QMAKE_CC = cl
QMAKE_CXX = cl
QMAKE_LINK = link
}else{
QMAKE_CC = g++
QMAKE_CXX = g++
QMAKE_LINK = g++
}