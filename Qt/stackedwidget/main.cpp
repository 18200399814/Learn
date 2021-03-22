/*���һ������̳���QObject�࣬����ָ����parent������ô�����ڴ��ͷžͿ��Խ������ĸ����������й���
 *Qt���Ƽ����ڴ����ʽ�ǣ���main�����н������ڴ���Ϊ������Ψһ��ջ���󡣶��������͵�Qt���󶼶���Ϊ
 *�Ѷ��󣬲�ͨ��ֱ�ӻ���ָ��������Ϊ�����ڣ���ʵ�ֶ��ڴ�İ��Զ����ա�
 */

/*Qt�а��Զ��ڴ���յĴ���������
 *1.��̳���QObject��
 *2.����ָ����parent������
 *3.parent������������ʱ�򣬻���ͬ���������Ӷ���Ҳһ����������
 */

/*Qt��ָ��������ļ��ֳ��÷�ʽ��
 *1.ͨ��������ʱ������parent������
 *2.ͨ����������setParent()����ָ��������
 *3.QLayout��addWidget()��������Ϊ��ӵ����ֹ������еĴ��ڣ��Զ�����ϸ�����
 *4.QWidget��setLayout()��������Ϊ���õ������ϵĲ��ֹ��������Զ�����ϸ�����
 *5.QMainWindow��setCentralWidget()��������Ϊ���õ������ڵ����Ĵ��ڣ��Զ�����ϸ�����
 *6.QMainWindow��setDockWidget()��������Ϊ��ӵ��������еĸ������ڣ��Զ�����ϸ�����
 *7.QDockWidget��setWidget()��������Ϊ���õ�ͣ�����ִ����еĴ��ڣ��Զ�����ϸ�����
 *8.QSplitter/QStackedWidget��addWidget()��������Ϊ��ӵ��ָ�ֻ��ջ���ִ����еĴ��壬�Զ�����ϸ�����
 */

/*ΪQWidget�����������ָ��parent�����ã�
 *1.ͨ��ָ����parent�йܶ���������ڴ��ͷŹ�����
 *2.���ô��ڲ�����λ��ʾ������ϵΪ��QWidget������ϵ����������ӵ��������С�
 */

/*Qt���Զ��ڴ������Ƶ�ȱ�ݣ�����parent����������child�Ƿ��䵽ջ�ϻ��Ƕ��ϣ�������ܻ����parent����ջ��
 *�������Ӷ�����������Qt���������ĺ���ԭ���Ǳ�֤�Ӷ����������������Ӷ��������Լ��Ӹ������б���ɾ������
 *����ȡ����������ô����������ʱ�Ͳ����ٴ������Ӷ����ˡ�
 */

//QStackedWidget��Ҫ����ʵ�ֶ�ջ���ڲ��֣�����Ҫʵ�ֲ��Ч���Ķ������ֱ����ӵ�QStackedWidget��ջ���ִ����о��С�

#include <QApplication>
#include <QDialog>
#include <QStackedWidget>
#include <QListWidget>
#include <QLabel>
#include <QHBoxLayout>

#define _ERROR_
#undef _ERROR_

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);

	//main������������һ�㶨��Ϊջ���󣬲�������Ϊparent�����󣬹�������������õ��ӿؼ����ڴ��ͷš�
	QDialog dlg;
	dlg.setWindowTitle("stacked widget test");
	dlg.resize(400,300);

	//�������������⣬�������͵Ŀؼ����鶼����Ϊ�Ѷ��󣬲�Ϊ��ָ�������������Զ�����������ڴ��ͷš�
	QListWidget *listWgt = new QListWidget(&dlg);
	listWgt->addItem("window1");
	listWgt->insertItem(1,"window2");
	listWgt->addItem("window3");
	
	QStackedWidget *stackedWgt = new QStackedWidget();
	stackedWgt->setParent(&dlg);     //ͨ������setParent()����ΪstackedWgtָ��������
	
#ifdef _ERROR_
	/*�������topLabelʱֻ��ָ��stackedWgt��Ϊ�����󣬵�������addWidget()����������ӵ���ջ�����У�
	 *��ôtopLabelֻ�ὫstackedWgt��Ϊһ����ͨ��QWidget������õ������棬���ﲻ����ջ���ֵ�Ч����
	 */
	QLabel *topLabel = new QLabel("top window test",stackedWgt);
	topLabel->setAlignment(Qt::AlignHCenter);
#else
	QLabel *topLabel = new QLabel("top window test");
	topLabel->setAlignment(Qt::AlignHCenter);
	stackedWgt->addWidget(topLabel);
#endif

	//midLabel����ʱû��ָ��������ʹ��addWidget()������õ���ջ������ʱ�����Զ�Ϊ��ָ��������
	QLabel *midLabel = new QLabel("middle window test");
	midLabel->setAlignment(Qt::AlignVCenter);
	stackedWgt->addWidget(midLabel);
	
	//bottomLabel����ʱ�Ѿ�ָ���˸��������Ե���addWidget()������õ���ջ������ʱ��������Ϊ����Ӹ�����
	QLabel *bottomLabel = new QLabel("bottom window test",stackedWgt);
	bottomLabel->setAlignment(Qt::AlignVCenter);
	stackedWgt->addWidget(bottomLabel);
	
	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->setMargin(10);    //���ò��ֹ������������ڱ߾�Ϊ10
	mainLayout->setSpacing(5);   //���ò��ֹ������и��ؼ�֮��ļ��Ϊ5
	mainLayout->addWidget(listWgt);
	mainLayout->addWidget(stackedWgt);
	
	/*setStretchFactor()�������ÿ������ؼ�����1����������ָ�����õĿؼ�����Ŵ�0��ʼ����
	 *��2��������ֵ����0���ʾ�˿ؼ�Ϊ�������ؼ���
	 */
	mainLayout->setStretchFactor(listWgt,1);
	mainLayout->setStretchFactor(stackedWgt,3);    //�ڲ��ֹ�������stackedWgt��С��listWgt��3:1��
	
	//mainLayout����ʱû��ָ��parent������ʹ��setLayout()������ӵ��Ի�����ʱ�����Զ�Ϊ��ָ��������
	dlg.setLayout(mainLayout);
	QObject::connect(listWgt,SIGNAL(currentRowChanged(int)),stackedWgt,SLOT(setCurrentIndex(int)));
	
	dlg.show();
	return app.exec();
}