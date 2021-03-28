/*Qt��д�Զ���ؼ��������ʹ�ý̳̣�
 *https://blog.csdn.net/leno_feng/article/details/81667476?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-1&spm=1001.2101.3001.4242
 */

/*���ڱ�����װ��Qt Creator�汾��MSVC 32λrelease�棬������������Լ���Ƶ�Qt Designer���
 *������Qt Creator�ı�׼�ؼ���ֱ����קʹ�ã���ô�ͱ��뽫��Qt���ʦ�Զ���ؼ�������ΪMSVC 32λ
 *release�档���һ���Ҫ����������ɵ�mylableplugin.dll��������õ�Qt Creator�İ�װ·���µ�
 *plugins/designerĿ¼�к�MSVC 32λ�汾Qt�ⰲװ·���µ�plugins/designerĿ¼�С�
 */

/*��mylableplugin.dll���������Qt Creator��װ·���µ�plugins/designerĿ¼�У���Ϊ�����û�
 *�Զ����MyLabel�ؼ�����ӵ�Qt Creator�������ʦ�ı�׼�ؼ����С�����mylableplugin.dll���
 *������MSVC 32λ�汾Qt�ⰲװ·���µ�plugins/designerĿ¼�У���Ϊ�����û��Զ����MyLabel�ؼ���
 *��ӵ�MSVC 32λ�汾��Qt Designer�������ʦ���ߵı�׼�ؼ����С�
 */

/*������û���д�ġ�Qt���ʦ�Զ���ؼ���Qt Designer�����������ΪMingW��MSVC 64λ�汾�����
 *��ô��ֻ�ܽ��俽����MingW��MSVC 64λ�汾Qt�ⰲװ·���µ�plugins/designerĿ¼�У���ֻ��
 *��MingW��MSVC 64λ�汾��designer.exe��������קʹ�á������ܽ�����õ�Qt Creator��װ·��
 *�µ�plugins/designerĿ¼���ӵ�Qt Creator�������ʦ�ı�׼�ؼ�������קʹ�á���Ϊ��ǰ
 *��װ��Qt Creator��MSVC 32λrelease�汾��������ʶ��MingW��MSVC 64λ�汾�Ķ�̬�⡣
 */

#ifndef _MYLABEL_H
#define _MYLABEL_H

#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>

namespace Ui {
class MyLabel;
}

class QDESIGNER_WIDGET_EXPORT MyLabel:public QWidget
{
    Q_OBJECT
public:
    enum Color
    {
        GRAY,    //default
        RED,
        GREEN,
        BLUE
    };

    explicit MyLabel(QWidget *parent = nullptr);
    virtual ~MyLabel();
    void setColor(const Color color);
    void setText(const QString text);

protected:
    void paintEvent(QPaintEvent *event);
	
private:
    Ui::MyLabel *ui;

    Color m_color;
    QString m_text;
};

#endif // _MYLABEL_H
