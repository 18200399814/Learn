#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>

#define _ERROR_
// #undef _ERROR_

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

static void initWidget(QWidget *wgt);

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);

	QWidget wgt;
	initWidget(&wgt);
	wgt.show();
	
	return app.exec();
}

void initWidget(QWidget *wgt)
{
	QVBoxLayout *mainLayout = new QVBoxLayout(wgt);
	mainLayout->setMargin(5);
	mainLayout->setSpacing(5);
	
	/* static */ QListWidget *listWgt = new QListWidget();
	listWgt->addItem(new QListWidgetItem("name: bob"));
	listWgt->insertItem(1,new QListWidgetItem("age: 25"));

#ifndef _CHANGE_WAY_
	QComboBox *sexComboBox = new QComboBox();
	QLineEdit *scoreLineEdt = new QLineEdit("score: 80");
	QLabel *contentLabel = new QLabel("selected content");
#else
	static QComboBox *sexComboBox = new QComboBox();
	static QLineEdit *scoreLineEdt = new QLineEdit("score: 80");
	static QLabel *contentLabel = new QLabel("selected content");
#endif
	sexComboBox->addItem("sex: boy");
	sexComboBox->insertItem(0,"sex: girl");
	contentLabel->setAlignment(Qt::AlignHCenter);

	QListWidgetItem *sexItem = new QListWidgetItem("sex: ");
	listWgt->addItem(sexItem);
	listWgt->setItemWidget(sexItem,sexComboBox);
	
	QListWidgetItem *scoreItem = new QListWidgetItem;
	scoreItem->setText("score: 60");
	listWgt->insertItem(listWgt->count(),scoreItem);
	listWgt->setItemWidget(scoreItem,scoreLineEdt);

	mainLayout->addWidget(listWgt);
	mainLayout->addWidget(contentLabel);
	
	/*����connect�ǰ�listWgtָ��ָ��ĶѶ������Լ�ʹlistwgtָ�뱾�������ˣ�
	 *currentTextChanged�ź�Ҳ�ܷ��ͳ�ȥ�������ᵼ��Ұָ�����bug��
	 */
	QObject::connect(listWgt,&QListWidget::currentTextChanged,contentLabel,&QLabel::setText);
	
#ifndef _ERROR_
#ifndef _CHANGE_WAY_
	QObject::connect(sexComboBox,&QComboBox::currentTextChanged,contentLabel,&QLabel::setText);
	QObject::connect(scoreLineEdt,&QLineEdit::textEdited,contentLabel,&QLabel::setText);
#else
	/*���ڳ���initWidget()�������������Եľֲ�����ָ�붼�ᱻ���٣��Ժ��ٴ���currentTextChanged�ź�����
	 *�ͻ����contentLabelҰָ����ʣ��������������Ϊ��ֹsexComboBox��scoreLineEdt��contentLabelָ��
	 *�������������٣����Խ����Ƕ���Ϊstatic������
	 */
	 
	 //lambda���ʽ��[=]ֵ/[&]���ò����������е����б���ʱ�������Զ�����static��̬��������������������ͨ����
	QObject::connect(sexComboBox,&QComboBox::currentTextChanged,
		[&](const QString &text){
			contentLabel->setText(text);
		}
	);
	
	/*�ⲿstatic��̬����������lambda���ʽ�б�ֱ��ʹ�ã�������Ҫ�ٱ������ⲿ��̬����������lambda
	 *���ʽ�Ĳ����б��У������ᵼ�±��뾯�档
	 */
	QObject::connect(scoreLineEdt,&QLineEdit::editingFinished,
		[](){
			contentLabel->setText(scoreLineEdt->text());
		}
	);
#endif   //_CHANGE_WAY_
#else
	QObject::connect(sexComboBox,&QComboBox::currentTextChanged,
		[&contentLabel](const QString &text){
			contentLabel->setText(text);
		}
	);
	
	QObject::connect(scoreLineEdt,&QLineEdit::editingFinished,
		[&contentLabel,&scoreLineEdt](){
			contentLabel->setText(scoreLineEdt->text());
		}
	);
#endif   //_ERROR_
}