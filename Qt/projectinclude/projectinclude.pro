QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = projectinclude
TEMPLATE = app

#对于release版本的gui应用程序一般不加CONFIG += console配置。而debug版本如果需要查看
#qDebug()调试信息时，则需要在pro文件中加上console配置。否则调试打印信息无法在终端中显示。
CONFIG += c++11
DESTDIR = $$PWD/bin

include(subsystem.pri)