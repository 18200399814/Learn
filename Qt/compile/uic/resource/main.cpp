/*��Ϊֻ�����Qt���include/libĿ¼��INCLUDE/LIB���������У�����ʹ��Qt���ͷ�ļ�ʱ
 *�������ģ��·������͵�Ч��qmake�ļ��У�ʹ��QT += ģ������
 */

/*���*.ui�����ļ������õ�ͼƬ��������Դ�ļ�����ôʹ��uic.exe���߱�����*.ui�����ļ���
 *����Ҫʹ��rcc.exe���߱���*.qrc��Դ�ļ������*.ui�ļ���ֱ��ʹ��ͼƬ�ļ����������Ƚ�ͼƬ
 *��ӵ���Դ�ļ��У���ʹ����Դ�ļ�����ôֻ��Ҫʹ�ý�����빤��uic.exe������*.ui�ļ����ɡ�
 */

#include <QtWidgets/QApplication>    //��Ч��QT += widgets
#include "mainwindow.h"

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	MainWindow mainWnd;
	mainWnd.show();
	
	return app.exec();
}