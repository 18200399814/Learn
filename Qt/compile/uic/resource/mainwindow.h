#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

/*��Ϊֻ�����Qt���include/libĿ¼��INCLUDE/LIB���������У�����ʹ��Qt���ͷ�ļ�ʱ
 *�������ģ��·������͵�Ч��qmake�ļ��У�ʹ��QT += ģ������
 */
#include <QtWidgets/QMainWindow>    //��Ч��QT += widgets

namespace Ui{
class MainWindow;
}

/*���۲�uic.exe���߽���*.ui������룬��*.ui�ļ�����Ϊui_*.hͷ�ļ���������ʱ������MainWindow��
 *���źŲ۲�����������Ҫʹ��moc.exe���߶Ա�ͷ�ļ�����Ԫ���룬����moc_mainwindow.cppԴ�ļ���
 */
class MainWindow:public QMainWindow
{
	// Q_OBJECT
public:
	MainWindow(QWidget *parent = nullptr);
	virtual ~MainWindow();
	
private:
	Ui::MainWindow *ui;
};

#endif //_MAIN_WINDOW_H