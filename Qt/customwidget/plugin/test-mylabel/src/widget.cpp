#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"

Widget::Widget(QWidget *parent)
   :QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

	setWindowTitle("test mylabel widget");
    ui->mylabel->setColor(MyLabel::RED);
    ui->mylabel->setText("use mylabel by promote widget");
	
    connect(ui->popupBtn,SIGNAL(clicked()),this,SLOT(onPopupClick()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onPopupClick()
{
	static Dialog dlg;   //��dlg����Ϊstatic�������Է�ֹ�������popupBtn��ť������ζԻ���
	
	if(dlg.isHidden())
	{
		dlg.show();
		dlg.exec();
	}
}
