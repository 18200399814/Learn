#ifndef _DIALOG_H
#define _DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog:public QDialog
{
	Q_OBJECT
public:
	Dialog(QWidget *parent = nullptr);
	virtual ~Dialog();
	
private:
	Ui::Dialog *ui;  //��IDE������Qt��Ŀʱ��Ui�ļ�����ֱ��ʹ�ø���������Qt Designer������ơ�
};

#endif //_DIALOG_H