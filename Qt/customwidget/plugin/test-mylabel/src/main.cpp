#include <QApplication>
#include "widget.h"

int main(int argc,char* argv[])
{
    QApplication a(argc,argv);

    Widget mainWgt;
    mainWgt.show();

    return a.exec();
}
