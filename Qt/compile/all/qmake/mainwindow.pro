QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = mainwindow
TEMPLATE = app

CONFIG += c++11
DESTDIR = $$PWD/bin

HEADERS += mainwindow.h

SOURCES += main.cpp  \
           mainwindow.cpp

#qmake��ָ����ui�����ļ�����ô�ͻ����uic.exe�������������*.ui�����ļ�����Ϊui_*.hͷ�ļ�
FORMS +=mainwindow.ui

#qmake��ָ����qrc��Դ�ļ�����ô�ͻ����rcc.exe��Դ����������*.qrc��Դ�ļ�����Ϊqrc_*.cppԴ�ļ�
RESOURCES += $$PWD/resource.qrc