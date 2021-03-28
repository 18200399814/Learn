/*���Լ���ƵĿؼ���װΪ��Qt���ʦ�Զ���ؼ���Qt Designer�Զ���ؼ����������Է���ͻ�ֱ��
 *��Qt Designer��ʹ����ק�ķ�ʽ�����Զ���ؼ����Դﵽ���������õ�Ч�����û��Զ���ؼ���
 *Qt Designer����ķ�ʽ�ṩ���ͻ�ʹ�ã���ͨ��Դ����ķ�ʽ�ṩ���ͻ�ʹ�ø��ӷ��㡣
 */

#ifndef _MY_LABEL_PLUGIN_H
#define _MY_LABEL_PLUGIN_H

#include <QDesignerCustomWidgetInterface>

class MyLabelPlugin:public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")
#endif // QT_VERSION >= 0x050000

public:
    MyLabelPlugin(QObject *parent = 0);

    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget *createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);

private:
    bool m_initialized;
};

#endif  //_MY_LABEL_PLUGIN_H
