/*Qt creator��ִ��qmakeʱֻ������Makefile�ļ������������uic.exe/rcc.exe/moc.exe���߱���
 *ui�����ļ�/qrc��Դ�ļ�/hͷ�ļ�������������������ִ��Makefile�ļ�ʱ���Ż���������������
 *QtԤ���빤�ߴ���ui�����ļ�/qrc��Դ�ļ�/hͷ�ļ���
 */

#include <QApplication>    //��Ч��QT += widgets
#include "mainwindow.h"

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	MainWindow mainWnd;
	mainWnd.show();

	return app.exec();
}