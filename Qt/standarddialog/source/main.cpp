#include <QApplication>
#include "maindialog.h"

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);

	MainDialog mainDlg;
	mainDlg.show();

	return app.exec();
}