QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = splitter
TEMPLATE = app

#����release�汾��guiӦ�ó���һ�㲻��CONFIG += console���á���debug�汾�����Ҫ�鿴
#qDebug()������Ϣʱ������Ҫ��pro�ļ��м���console���á�������Դ�ӡ��Ϣ�޷����ն�����ʾ��
CONFIG += c++11
DESTDIR = $$PWD/bin

SOURCES += main.cpp
