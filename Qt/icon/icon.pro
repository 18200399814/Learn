QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = icon
TEMPLATE = app

#����guiӦ�ó���һ�㲻��Ҫ��qDebug()���ն˴�ӡ��Ϣ�����Բ��ü�CONFIG += console���á�
#���guiӦ�ó��������console���ã���ô�����������ɵ�exeʱ�������gui���壬Ҳ���ٴ�һ����ӡ�նˡ�
CONFIG += c++11
DESTDIR = $$PWD/bin

HEADERS += include/dialog.h

SOURCES += source/main.cpp  \
           source/dialog.cpp

#Qt�е�UI�ļ�����ֱ����Qt Designer�������ʦ�н��л��ƣ������ô�Qt Creator������ơ�
FORMS += ui/dialog.ui

RC_ICONS = resource/google_chrome.ico

INCLUDEPATH += include