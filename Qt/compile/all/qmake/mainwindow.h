#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

#include <QMainWindow>

namespace Ui{
class MainWindow;
}

class QToolButton;
class QPushButton;

/*����MainWindow���п������źŲۻ��ƣ�������Ҫʹ��moc.exe���߶�mainwindow.hͷ�ļ�����Ԫ���룬
 *����moc_mainwindow.cppԴ�ļ���Qt�е��źŲۻ������ڱ�׼C++�������������������ʵ�ֵģ�����
 *���д��������ǰ�������һ��mocԴ������룬��Qt����չ�ķǱ�׼C++�﷨������Ϊ��׼C++Դ�ļ���
 */

/*��������ʹ����Q_OBJECT�꿪���źŲۻ��ƣ��ͻ��Զ�����moc.exeԪ���빤�ߣ��Կ������źŲۻ��Ƶ�
 *����д�������moc_*.cppԴ�ļ���uic.exe�����������rcc.exe��Դ���������Զ����ö�����pro����
 *�����ļ���ָ���ģ�Ψ��moc.exeԪ����������ĵ����������ͷ�ļ���Դ�ļ���ָ���ġ�
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