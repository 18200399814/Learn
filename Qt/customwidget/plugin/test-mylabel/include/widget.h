/*���Զ���Qt Designer������õ�Qt Creator��Qt�ⰲװ·���µ�plugins/designerĿ¼�У�
 *ʹ����ӵ�Qt Creator�������ʦ��Qt Designer���ߵı�׼�ؼ��������ͨ����ק�ķ�ʽ
 *�������Զ���ؼ�������ʹ�ø��Զ���ؼ��Ĺ����У���Ȼ��Ҫ����Զ���Qt Designer�ؼ�
 *ͷ�ļ�����̬���������֧�֡�
 */

/*�Զ���Qt Designer�ؼ���ӵ�Qt Creator�������ʦ��Qt Designer���ߵı�׼�ؼ����У�
 *ֻ��Ϊ�˷�����ק�����Զ���ؼ������������á�������ק�½��Զ���ؼ��Ĺ��̱��롢
 *�νӺ�����ʱ����Ȼ��Ҫ�Զ���Qt Designer�ؼ���ͷ�ļ�����̬��������֧�֡�
 *������������ڲ������ķ�ʽ��ʹ���Զ���ؼ�û�б��ʵ�����
 */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget:public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
	void onPopupClick();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
