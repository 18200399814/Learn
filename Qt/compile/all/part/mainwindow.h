#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

/*��Ϊֻ�����Qt���include/libĿ¼��INCLUDE/LIB���������У�����ʹ��Qt���ͷ�ļ�ʱ
 *�������ģ��·������͵�Ч��qmake�ļ��У�ʹ��QT += ģ������
 */
#include <QtWidgets/QMainWindow>    //��Ч��QT += widgets

/*��Ϊmainwindow.ui�����ļ���ʹ����QIconͼ�꣬��QIcon���ʵ����Qt5Gui.lib/Qt5Guid.lib
 *���Ա���mainwindow.cppԴ�ļ�ʱ����Ҫ�ν�Qt5Gui.lib/Qt5Guid.lib�⡣
 */
namespace Ui{
class MainWindow;
}

class QToolButton;
class QPushButton;

/*����MainWindow���п������źŲۻ��ƣ�������Ҫʹ��moc.exe���߶�mainwindow.hͷ�ļ�����Ԫ���룬
 *����moc_mainwindow.cppԴ�ļ���Qt�е��źŲۻ������ڱ�׼C++�������������������ʵ�ֵģ�����
 *���д��������ǰ�������һ��mocԴ������룬��Qt����չ�ķǱ�׼C++�﷨������Ϊ��׼C++Դ�ļ���
 */
class MainWindow:public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = nullptr);
	virtual ~MainWindow();

private slots:
	void showNewQuestionMsgBox();
	void showAboutQtMsgBox();
	void showOpenFileDlg();
	void showHintAboutMsgBox();

private:
	Ui::MainWindow *ui;
	
	QToolButton *menuNewBtn;
	QPushButton *menuOpenBtn;
};

#endif //_MAIN_WINDOW_H