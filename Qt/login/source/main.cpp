#include <QApplication>
#include <QWidget>
#include <QIcon>
#include "logindialog.h"

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifndef _CHANGE_WAY_
	//���û���¼ǰ���Ѿ��������ڹ�������ˣ�ֻ�ǻ�û��show()��������������
	//�û���¼�ٶȣ���ȱ�����û��ڻ�û��¼ǰ��Ҫռ�ö�����ڴ�ռ䡣
    QWidget w;
	w.setWindowTitle("welcome");
	w.setWindowIcon(QIcon("../resource/myico.ico"));

    LoginDialog dlg;
    if(dlg.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
#else
    LoginDialog dlg;
    if(dlg.exec() == QDialog::Accepted)
    {
		//�û���¼��Ž������ڹ���������������Ա����ڴ�ռ��˷ѵ�����
		//��ȱ���û���¼�Ժ󣬼��������ڵ��ٶȽ�����
		QWidget w;
		w.setWindowTitle("welcome");
		w.setWindowIcon(QIcon("../resource/myico.ico"));
        w.show();
		
        return a.exec();
    }
#endif

	return 0;
}


