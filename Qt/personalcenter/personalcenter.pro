QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = personalcenter
TEMPLATE = app

CONFIG += c++11
DESTDIR = $$PWD/bin

#����_TRANSLATE_����꣬�Կ��Ƴ�����������Ƿ���Ҫת�롣��Դ��ΪUTF-8����ʱ��Ҫת��
#DEFINES += _TRANSLATE_

HEADERS += include/common.h  \
		   include/mainwindow.h  \
		   include/content.h  \
		   include/baseinfo.h  \
		   include/contact.h  \
		   include/detail.h

SOURCES += source/main.cpp  \
           source/mainwindow.cpp  \
		   source/content.cpp  \
		   source/baseinfo.cpp  \
		   source/contact.cpp  \
		   source/detail.cpp

INCLUDEPATH += $$PWD/include