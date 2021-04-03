QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = testmylabel
TEMPLATE = app
DESTDIR = $$PWD/bin

include($$PWD/../mylabel/mylabel.pri)

HEADERS += include/widget.h  \
		   include/dialog.h

SOURCES += src/main.cpp  \
		   src/widget.cpp  \
		   src/dialog.cpp

FORMS += ui/widget.ui

#INCLUDEPATH�������ڱ���ʱ��ָ��ͷ�ļ�·������Ȼ����Ҫ��Դ�ļ������ͷ�ļ�������·����
INCLUDEPATH += $$PWD/include

#DEPENDPATH�������ڸ��߱����������DEPENDPATHָ����Ŀ¼��ͷ�ļ������˱仯��
#��ô����������Щͷ�ļ���Դ�ļ�����Ҫ�����±��롣
DEPENDPATH += $$PWD/include

LIBS += -L$$PWD/lib -lmylabel