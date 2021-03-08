#include <cstdio>
#include <QApplication>
#include <QObject>
#include <QDialog>
#include <QPushButton>
#include <QLabel>

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

#define BUTTON_WIDTH 60
#define BUTTON_HEIGHT 30

static const int label_width = 100;
static const int label_height = 30;
static const int yoffset = 20;

static QLabel* g_plabel = nullptr;

static void registerLabel(QLabel* plabel);
static void onChangeText();

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	QDialog dlg;
	dlg.setWindowTitle("simplest gui");
	dlg.resize(300,200);
	
#ifdef _ERROR_
	dlg.show();   //�����ڵ���ʾ������õ������ӿռ�Ĳ������֮�󡣷��򸸴�����ʾʱ�������治����ʾshow()�����Ժ�����ӵĿؼ���
#endif

	QLabel label("hello world",&dlg);
	label.setAlignment(Qt::AlignHCenter);   //����QLabel��ʾ�ļ�Ϊˮƽ���ж���
	label.setGeometry((dlg.width() - label_width)/2,dlg.height()/2 - yoffset,label_width,label_height);
	
	QPushButton button("click",&dlg);
	button.resize(BUTTON_WIDTH,BUTTON_HEIGHT);
	button.move((dlg.width() - BUTTON_WIDTH)/2,dlg.height()/2 + yoffset);     //ʹ��setGeometry()��move()�������о��Բ���
	
#ifndef _CHANGE_WAY_
	registerLabel(&label);
	QObject::connect(&button,&QPushButton::clicked,onChangeText);    //�źŰ���ͨ����
#else
	QObject::connect(&button,&QPushButton::clicked,                  //�źŰ�lambda���ʽ
		[&label](){
			if(label.text() == "hello world")
			{
				label.setText("welcome qt");
			}
			else
			{
				label.setText("hello world");
			}
		}
	)
#endif

#ifndef _ERROR_
	dlg.show();
#endif

#ifdef _CHANGE_WAY_
	if(dlg.exec() != QDialog::Accepted)    //����Ի�����¼�ѭ��������dlg������Ϊģ̬����
	{
		fprintf(stdout,"exit dialog event loop\n");
		return -1;
	}
#endif

	return app.exec();
}

void registerLabel(QLabel* plabel)
{
	g_plabel = plabel;
}

void onChangeText()
{
	if(g_plabel == nullptr)
	{
		puts("onChangeText warn: g_plabel is null");
		return ;
	}
	
	if(g_plabel->text() == "hello world")
	{
		g_plabel->setText("welcome qt");
		return ;
	}

	g_plabel->setText("hello world");
}