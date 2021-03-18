//QSplitter��Ҫ����ʵ�ַָ�ڲ��֣�����Ҫʵ�ַָ�Ч���Ķ������ֱ����ӵ�QSplitter�ָ�ִ����о��С�

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
#include <QSplitter>
#include <QTextEdit>
#include <QFont>

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	QFont font("����",12);
	app.setFont(font);
	
	QSplitter mainSplitter;     //���ָ��
	mainSplitter.setWindowTitle("splitter test");
	mainSplitter.resize(500,400);
	
	//leftTextEdt��new����ʱ��ָ���˸�������ô���ͱ���ӵ������ָ���С�
	QTextEdit *leftTextEdt = new QTextEdit("left text edit",&mainSplitter);
	leftTextEdt->setAlignment(Qt::AlignHCenter);
	mainSplitter.setOpaqueResize(true);
	
	QSplitter *rightSpliter = new QSplitter(Qt::Vertical,&mainSplitter);    //�ҷָ��
	rightSpliter->setOpaqueResize(false);     //�����ҷָ�����϶��ָ���ʱ����ʵʱ���´�����ʾ��С
	
	QTextEdit *upTextEdt = new QTextEdit("top text edit",rightSpliter);   //�ҷָ�����������ı������
	upTextEdt->setAlignment(Qt::AlignHCenter);
	
	//midTextEdt��new����ʱ��û��ָ����������ô���ͻ�û�б���ӵ����κδ����С�
	QTextEdit *midTextEdt = new QTextEdit("middle text edit");
	midTextEdt->setAlignment(Qt::AlignHCenter);
	//���midTextEdt���ҷָ����С�QSpliter::addWidget()���Զ�Ϊ��ӵ��ָ����еĴ�����Ӹ�����
	//��ʵ���Ӷ�����Զ��ڴ���ա�
	rightSpliter->addWidget(midTextEdt);
	
	QTextEdit *bottonTextEdt = new QTextEdit("bottom text edit");
	bottonTextEdt->setAlignment(Qt::AlignHCenter);
	rightSpliter->addWidget(bottonTextEdt);   //�ҷָ�����������ı��༭��
	
	//�趨�������ؼ�����һ����������ָ�����õĿؼ�����Ŵ�0���ţ�����2��������ֵ����0���ʾ�˿ؼ�Ϊ�������ؼ���
	mainSplitter.setStretchFactor(0,0);   //�������ı��༭��Ϊ���������ؼ�����ʵ�ʲ����з������API��Ч������Qt��һ��Bug��
	mainSplitter.show();    //Qt�����пؼ����̳���QWidget���ڲ��������ǿ�����Ϊһ��������������ʾ�ġ�
	
	return app.exec();
}