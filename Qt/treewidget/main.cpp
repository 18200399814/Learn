#include <QApplication>
#include <QTreeWidget>
#include <QTreeWidgetItem>

static void initTreeWidget(QTreeWidget* ptreeWgt);
static void treeItemChange(QTreeWidgetItem* pitem,int column);
static void updateParent(QTreeWidgetItem* pparentItem);

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	/*main�����е�������һ�㶨��Ϊջ���󣬶��������е������ؼ�һ�㶨��Ϊ�Ѷ���
	 *�������ǵ�parent������ֱ�ӻ���ָ��Ϊ�����ڣ��Ա�ʵ�ֶѶ�����Զ��ڴ���ա�
	 */
	QTreeWidget treeWgt;
	initTreeWidget(&treeWgt);
	
	QObject::connect(&treeWgt,QTreeWidget::itemChanged,treeItemChange);
	treeWgt.show();

	return app.exec();
}

void initTreeWidget(QTreeWidget* ptreeWgt)
{
	ptreeWgt->setWindowTitle("tree widget test");
	ptreeWgt->resize(400,300);
	ptreeWgt->setHeaderHidden(true);
	
	/********������ַ����ڵ�*********/
	QTreeWidgetItem* groupAddress = new QTreeWidgetItem(ptreeWgt);
	groupAddress->setText(0,"address");
	groupAddress->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	groupAddress->setCheckState(0,Qt::Unchecked);
	groupAddress->setExpanded(true);
	
	QTreeWidgetItem* beijingItem = new QTreeWidgetItem(groupAddress);
	beijingItem->setText(0,"beijing");
	beijingItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	beijingItem->setCheckState(0,Qt::Unchecked);
	
	QTreeWidgetItem* shanghaiItem = new QTreeWidgetItem;
	shanghaiItem->setText(0,"shanghai");
	shanghaiItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	shanghaiItem->setCheckState(0,Qt::Unchecked);
	groupAddress->addChild(shanghaiItem);     //���Ϻ���ӵ���ַ��������
	
	QTreeWidgetItem* hongkongItem = new QTreeWidgetItem();
	hongkongItem->setText(0,"hongkong");
	hongkongItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	hongkongItem->setCheckState(0,Qt::Unchecked);
	groupAddress->addChild(hongkongItem);     //�������ӵ���ַ��������

	/********������������ڵ�*********/
	QTreeWidgetItem* groupName = new QTreeWidgetItem;
	groupName->setText(0,"name");
	groupName->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	groupName->setCheckState(0,Qt::Unchecked);
	ptreeWgt->addTopLevelItem(groupName);
	groupName->setExpanded(true);    //����Ҫ��groupName����ӵ�ptreeWgt��չ��������Ч����Ȼ������Ч
	
	QTreeWidgetItem* amyItem = new QTreeWidgetItem(groupName);
	amyItem->setText(0,"amy");
	amyItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	amyItem->setCheckState(0,Qt::Unchecked);

	QTreeWidgetItem* bobItem = new QTreeWidgetItem;
	bobItem->setText(0,"bob");
	bobItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	bobItem->setCheckState(0,Qt::Unchecked);
	groupName->addChild(bobItem);
	
	QTreeWidgetItem* lisaItem = new QTreeWidgetItem();
	lisaItem->setText(0,"lisa");
	lisaItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	lisaItem->setCheckState(0,Qt::Unchecked);
	groupName->addChild(lisaItem);
}

void treeItemChange(QTreeWidgetItem* pitem,int column)
{
	if(pitem == nullptr)
		return ;
	
	int count = pitem->childCount();
	if(Qt::Checked == pitem->checkState(column))
	{
		//˵�����ڵ㱻ѡ�У���ôֻ��Ҫ��������������ӽڵ�����Ϊѡ��״̬
		if(count > 0)
		{
			for(int i=0;i<count;++i)
			{
				pitem->child(i)->setCheckState(0,Qt::Checked);
			}
			return ;
		}
	}
	else if(Qt::Unchecked == pitem->checkState(column))
	{
		//˵�����ڵ㱻ȡ��ѡ�У���ô��ֻ��Ҫ������������ӽڵ�����Ϊ��ѡ��״̬
		if(count > 0)
		{
			for(int i=0;i<count;++i)
			{
				pitem->child(i)->setCheckState(0,Qt::Unchecked);
			}
			return ;
		}
	}
	
	//������ӽڵ㱻ѡ�л�ȡ��ѡ�У���ô�͵ü����ж����������ֵܽڵ��״̬�������ø��ڵ��ѡ��״̬
	QTreeWidgetItem* parentItem = pitem->parent();
	updateParent(parentItem);
}

void updateParent(QTreeWidgetItem* pparentItem)
{
	if(pparentItem == nullptr)
		return ;
	
	int selectCount = 0;     //ͳ�Ƹ��ڵ��±�ѡ���ӽڵ�ĸ���
	int childCount = pparentItem->childCount();
	for(int i=0;i<childCount;++i)
	{
		if(Qt::Checked == pparentItem->child(i)->checkState(0))
		{
			selectCount++;
		}
	}
	
	/*�����if-else if-else��䲻�ܸ�Ϊswitch-case-default��䣬
	 *��Ϊcase����ֻ�ܽӳ������ʽ����childCount��һ��������
	 */
	if(selectCount == 0)
	{
		pparentItem->setCheckState(0,Qt::Unchecked);   //δѡ��״̬
	}
	else if(selectCount == childCount)
	{
		pparentItem->setCheckState(0,Qt::Checked);     //ѡ��״̬
	}
	else
	{
		pparentItem->setCheckState(0,Qt::PartiallyChecked);   //����ѡ��״̬
	}
}