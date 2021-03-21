/*QDockWidget��Ҫ����ʵ��������QMainWindow�е�ͣ�����ڲ��֣�����Ҫʵ��ͣ��Ч���Ĵ���ֱ�����õ�ͣ�����ִ����С�
 *�ڽ�ͣ��������ӵ��������ϣ�������ͣ�����ִ��ڵ�ͣ�����Ժ�����ͣ����������С�
 */
 
/*Qt�еĴ��岼�ַ�ʽ��
 *��1���������֣�ˮƽ���֡���ֱ���֡����񲼾֡�
 *��2���߼����֣��ָ�ڲ��֡��������ڲ��֣���ջ���ڲ��֡�
 */

/*��ѧϰQt�е�ĳһ������ʱ�����ݵķ����ǲ��û��ڶ���ı�̷�ʽ��дDemo���������������ı�̷�ʽ��
 *��Ϊ�������ı�̷�ʽʹ���˷�װ���̳кͶ�̬���ԣ�����ʹ��Ҫѧϰ����API������������ֱ�ӣ������˱�
 *дѧϰDemo�Ĵ�������
 */

//ֻҪ�ؼ�����ʾ�����������ϣ���ô�ؼ�������ڴ���Ѿ������������й��ˣ�����Ҫ�û����ֶ��ͷ��ˡ�

#include <QApplication>
#include <QMainWindow>
#include <QDockWidget>
#include <QTextEdit>

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	QMainWindow mainWnd;
	mainWnd.resize(500,400);
	mainWnd.setWindowTitle("dock widget test");
	
	/*��Ϊ������õ�QMainWindow::setCentralWidget()�������Զ�ΪmainTextEdt��Ӹ�����
	 *���Թ���mainTextEdt����ʱ������ָ��������Ҳ���Բ�ָ��������
	 */
	QTextEdit* mainTextEdt = new QTextEdit();
	mainTextEdt->setText("main window");
	mainTextEdt->setAlignment(Qt::AlignHCenter);
	mainWnd.setCentralWidget(mainTextEdt);      //��mainTextEdt�༭������Ϊ�����ڵ����봰��
	
	/*��Ϊ������õ�QMainWindow::addDockWidget()�������Զ�ΪtopDock��Ӹ�����
	 *���Թ���topDock����ʱ������ָ��������Ҳ���Բ�ָ��������
	 */
	QDockWidget* topDock = new QDockWidget("top dock widget");
	topDock->setFeatures(QDockWidget::DockWidgetMovable);     //����topDockͣ������Ϊ���ƶ�
	topDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);   //����ͣ�����ڵĿ�ͣ������
	
	QTextEdit* topEdt = new QTextEdit("the dock widget can be moved between docks by user");
	topDock->setWidget(topEdt);
	mainWnd.addDockWidget(Qt::RightDockWidgetArea,topDock);   //��ͣ��������ӵ��������ϣ���ָ�����ʼͣ��λ��
	
	//����midDockû������QDockWidget::DockWidgetMoveable���ԣ����������ܱ��϶�
	QDockWidget* midDock = new QDockWidget("mid dock widget");
	midDock->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);
	
	QTextEdit* midEdt = new QTextEdit();
	midEdt->setText("the dock widget can be detached from the main window,and floated as an independent window");
	midDock->setWidget(midEdt);
	mainWnd.addDockWidget(Qt::RightDockWidgetArea,midDock);
	
	//����bottomDockû����������ͣ������������Ĭ�����������������򶼿���ͣ��
	QDockWidget* bottomDock = new QDockWidget("bottom dock widget");
	bottomDock->setFeatures(QDockWidget::AllDockWidgetFeatures);   //ȫ��ͣ�����ԣ������ƶ����ɹرա��ɸ���
	
	QTextEdit* bottomEdit = new QTextEdit("bottom dock widget");
	bottomEdit->setText("the dock widget can be closed,moved and floated");
	bottomDock->setWidget(bottomEdit);       //һ��QDockWidget��ֻ������һ��QWidget��һ��QSplitter�����п�����Ӷ��QWidget��
	mainWnd.addDockWidget(Qt::RightDockWidgetArea,bottomDock);

	mainWnd.show();
	return app.exec();
}