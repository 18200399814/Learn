QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET =
TEMPLATE = app

#CONFIG += console c++11   #ʹ�ñ�����Ĭ�ϵ�c++14��׼
DESTDIR = $$PWD/bin

#DEFINES +=

HEADERS += include/

SOURCES += source/main.cpp  \
           source/

FORMS += ui/

INCLUDEPATH += $$PWD/include

#DEPENDPATH += $$PWD/

#RC_ICONS = $$PWD/resource/

#RESOURCES += $$PWD/resource/