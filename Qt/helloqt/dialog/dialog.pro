QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets   #Qt5��QWidget��Qt4�е�guiģ���ƶ�����widgetsģ��

TARGET = dialog
TEMPLATE = app

CONFIG += console c++11
DESTDIR = $$PWD/bin

SOURCES += main.cpp