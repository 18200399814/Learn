/*��1������ϵͳ��غ궨�壺Windows32ϵͳ��_WIN32����Windows64ϵͳ��_WIN64����Linuxϵͳ��__linux��__linux__��
 *��2����������غ궨�壺GCC��������__GNUC__����VC++��MSVC��������_MSC_VER_��
 */

#include <iostream>
#include <algorithm>
#include <QtGlobal>
#include <QtAlgorithms>
#include <QtMath>
#include <QString>
#include <QList>
#include <QListIterator>
#include <QMutableListIterator>
#include <QRegExp>
#include <QDebug>

#define DisplayList(list)                  \
	do{                                    \
		foreach(const auto& data,list)     \
		{                                  \
			qDebug()<<data;                \
		}                                  \
	}while(0)

template <class T>
void display(const T& data)
{
	qDebug()<<data;
}

/*��GCC�������У�ģ������ʹ��ģ����Ļ�����Ҫ��ģ����ǰ���typename�ؼ��֣��������ᱨ��
 *��MSVC�������У�ģ������ʹ��ģ����Ļ�������Ҫ��ģ����ǰ���typename�ؼ��֣�Ҳ�ܱ���ͨ����
 */
template <typename T>
void showList(const QList<T>& list)
{
#ifdef __GNUC__
#	pragma message("---use g++ compiler---")       //#pragma message()���ڱ����ڴ�ӡ��Ϣ
	typename QList<T>::const_iterator citer = list.cbegin();        //STL��������
#else
#	pragma message("---use vc++ compiler---")      //����showList()ģ�庯���ᱻʵ����showList<int>()��showList<double>()������#pragma message()Ҳ���ӡ����
    QList<T>::const_iterator citer = list.cbegin();        //STL��������
#endif

	for(;citer != list.cend();++citer)
	{
		qDebug()<<*citer;
	}
}

template <typename T>
class Print
{	
public:
	void operator ()(const T& data)
	{
		qDebug()<<data;
	}
};

//��QList����crud����
static void create_list();
static void retrieve_list();
static void update_list();
static void delete_list();

int main(int argc,char* argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);
	
    create_list();
    retrieve_list();
    update_list();
    delete_list();
	
	return 0;
}

void create_list()
{
	QList<int> list;
	list.append(3);
	list.prepend(2);
	list.push_front(1);
	list.push_back(4);
	list<<6<<7;
	list.insert(4,5);
	list.insert(0,0);               //��QList��0λ�ò������ݣ��൱��prepend()
	list.insert(list.length(),8);   //��QList��β���������ݣ��൱��append()
	DisplayList(list);
	qDebug()<<"create list: default constructor";
	
	QList<int> list1(list);
	showList(list1);            //showList()����ģ����ʽ������
	qDebug()<<"create list: copy constructor";
	
	// ����Ҫ֧��C++11���ϵ�Qt�ͱ������汾������ʹ��QList���б��ʼ�����캯��
	QList<double> list2 = {3.142,2.718,0.618,1.414};    //�б��ʼ�����캯��
	showList<double>(list2);                            //showList()����ģ����ʽ������
	std::cout<<"create list: list initialize constructor"<<std::endl<<std::endl;	
}

void retrieve_list()
{
	QList<QString> list = {"111","222","333"};
	list.append("ccc");
	list.push_back("ddd");
	list.prepend("bbb");
	list.push_front("aaa");
	list<<"eee"<<"fff"<<"333";
	list.insert(list.length(),"ggg");
	list.insert(0,"000");
	list.insert(list.indexOf("ddd")+1,"444");
	std::for_each(list.begin(),list.end(),display<QString>);
	qDebug()<<"retrieve list: append/prepend/push_back/push_front/insert ,add item to list";
	
	qDebug()<<"retrieve list: list.isEmpty() ="<<list.isEmpty()<<" ,list.empty() ="<<list.empty();
	qDebug()<<"retrieve list: list.size() ="<<list.size()<<" ,list.length() ="<<list.length()<<" ,list.count() ="<<list.count();
	qDebug()<<"retrieve list: list[3] ="<<list[3]<<" ,list.at(5) ="<<list.at(5)<<" ,list.value(7) ="<<list.value(7);
	
	if(list.contains("bbb"))
	{
		qDebug()<<"retrieve list: contains ,list contains \"bbb\"";
	}
	
	QList<QString>::iterator iter = qFind(list.begin(),list.end(),"222");
	if(iter != list.end())
	{
		qDebug()<<"retrieve list: qFind ,find \"222\" at "<<iter - list.begin();
	}
	
	iter = qBinaryFind(list.begin(),list.end(),"444");
	if(iter != list.end())
	{
		qDebug()<<"retrieve list: qBinaryFind ,find \"444\" at "<<iter - list.begin();
	}
	
	iter = std::find(list.begin(),list.end(),"ccc");
	if(iter != list.end())
	{
		qDebug()<<"retrieve list: std::find ,find \"ccc\" at "<<iter - list.begin();
	}
	
	iter = std::find_if(list.begin(),list.end(),[](const QString& str){return str.contains(QRegExp("^d+"));});
	if(iter != list.end())
	{
		qDebug()<<"retrieve list: std::find_if ,find "<<*iter<<" at "<<iter - list.begin();
	}
	
	QListIterator<QString> listIter(list);   //Java����������QListIteratorΪֻ����������QMutableListIteratorΪ�ɶ���д������
	if(listIter.findNext("eee"))
	{
		qDebug()<<"retrieve list: QListIterator , find \"eee\" in list";
	}
	
	listIter.toBack();
	while(listIter.hasPrevious())     //Java�����������������list
	{
		std::cout<<listIter.previous().toStdString()<<" ";
	}
	std::cout<<std::endl<<"retrieve list: QListIterator ,reverse print"<<std::endl;
	
	qDebug()<<"retrieve list: list.count(\"333\") ="<<list.count("333");
	qDebug()<<"retrieve list: QListIterator ,first item ="<<listIter.next()<<" ,second iter ="<<listIter.peekNext();

	listIter.toBack();
	qDebug()<<"retrieve list: QListIterator ,last item ="<<listIter.previous()<<" ,last item but one ="<<listIter.peekPrevious();

	int index = list.indexOf("333");
	qDebug()<<"retrieve list: list.indexof(\"333\") ="<<index;
	
	index = list.indexOf("333",7);    //�ӵ�7��λ�ÿ�ʼ����
	qDebug()<<"retrieve list: list.indexof(\"333\",7) ="<<index;

	index = list.lastIndexOf("333");
	qDebug()<<"retrieve list: list.lastIndexOf(\"333\") ="<<index;
	
	if(list.startsWith("000"))
	{
		qDebug()<<"retrieve list: list.startsWith(\"000\") ="<<list.startsWith("000");
	}
	
	if(list.endsWith("ggg"))
	{
		qDebug()<<"retrieve list: list.endsWith(\"ggg\") ="<<list.endsWith("ggg");
	}

	QList<QString> list1 = list.mid(1,2);
	qDebug()<<"retrieve list: mid ,list1.length() ="<<list1.length()<<" ,list1.at(0) ="<<list1.at(0)<<" ,list1.value(1) ="<<list1.value(1);
	
	std::cout<<std::endl;
}

void update_list()
{
	QList<double> list{0.5,1.5,2.5};
	list<<3.5<<4.5<<5.5;
	std::for_each(list.begin(),list.end(),Print<double>());
	qDebug()<<"update list: << ,add item to list";
	
	list[2] = 2.71828;    //at()��value()�����ķ���ֵ�����������ͣ����Բ��������޸�QList�����д�ŵ�ֵ
	list.first() = 3.14159;
	list.last() = 0.618;
	
	list.push_front(0.0);
	list.push_back(0.0);
	list.front() = 0.8;
	list.back() = 5.8;
	std::for_each(list.begin(),list.end(),
		[](double& num){
			std::cout<<num<<" ";
		}
	);
	std::cout<<std::endl<<"update list: first/last/front/back ,modify list"<<std::endl;
	
	QMutableListIterator<double> mutListIter(list);
	mutListIter.insert(0.2);
	mutListIter.next() = 1.3;       //������һ��item�����ã�������������ǰ�ƶ�
	mutListIter.peekNext() = 1.4;   //������һ��item�����ã���������������ǰ�ƶ�
	mutListIter.toBack();
	mutListIter.previous() = 5.2;
	mutListIter.peekPrevious() = 4.3;
	mutListIter.insert(5.3);
	for(double num: list)
	{
		std::cout<<num<<" ";
	}
	std::cout<<std::endl;
	
	mutListIter.toFront();
	while(mutListIter.hasNext())
	{
		double val = mutListIter.next();
		mutListIter.setValue(sqrt(val));
		std::cout<<mutListIter.value()<<" ";
	}
	std::cout<<std::endl<<"update list: QMutableListIterator ,modify list"<<std::endl;

	list.replace(2,7.5);
	list.swap(4,5);
	list.move(6,list.count() - 1);    //����6���ƶ���list���
	
	QList<double>::const_iterator citer = --list.constEnd();
	while(citer != --list.constBegin())    //ʹ��C++�����������������list
	{
		std::cout<<*citer<<" ";            //�����ӡQList����ʹ��Java������������ΪC++��������ʵ�ֵ����ӡ�Ḵ�Ӻܶ࣬�����׳���
		--citer;
	}
	std::cout<<std::endl<<"update list: replace/swap/move ,modify list"<<std::endl;
	
	qSort(list.begin(),list.end());
	QListIterator<double> listIter(list);
	while(listIter.hasNext())
	{
		std::cout<<listIter.next()<<" ";
	}
	std::cout<<std::endl<<"update list: qSort ,sort list"<<std::endl<<std::endl;
}

void delete_list()
{
	QList<QString> list({"111","222","222"});
	list.append("222");
	list.append("333");
	list.append("444");
	
	QMutableListIterator<QString> mutIter(list);
	mutIter.insert("AAA");
	mutIter.insert("BBB");
	mutIter.insert("BBB");
	mutIter.insert("CCC");
	
	mutIter.toFront();
	while(mutIter.hasNext())
	{
		mutIter.next();
		std::cout<<mutIter.value().toStdString()<<" ";
	}
	std::cout<<std::endl<<"delete list: QMutableListIterator ,add Item to list"<<std::endl;
	
	QList<QString> list1(list);
	list1.clear();
	std::cout<<"delete list: clear ,list1.isEmpty() ="<<list1.isEmpty()<<" ,list1.length() ="<<list1.length()<<std::endl;;
	
	//QList��remove������take�����������ǣ�take�����᷵��ɾ�����ݵ�ֵ
	list1 = list;
	list1.removeFirst();
	list1.removeLast();
	list1.removeAt(2);
	list1.removeOne("222");
	list1.removeAll("BBB");
	foreach(const QString& str,list1)
	{
		std::cout<<str.toStdString()<<" ";
	}
	std::cout<<std::endl<<"delete list: removeFirst/removeLast/removeAt/removeOne/removeAll ,list1.size() ="<<list1.size()<<std::endl;
	
	//���ɾ��QList�е����ݣ����ֲ���Ҫʹ��ɾ������ʱ�ķ���ֵ�����ʹ��removeAt()�ȷ�������ɾ��
	QString str1 = list1.takeFirst();
	QString str2 = list1.takeLast();
	QString str3 = list1.takeAt(1);
	std::for_each(list1.begin(),list1.end(),
		[](const QString& str){
			std::cout<<str.toStdString()<<" ";
		}
	);
	std::cout<<std::endl<<"delete list: takeFirst/takeLast/takeAt ,list1.count() ="<<list1.count()<<std::endl;

	QList<QString>::iterator iter = list.begin();
	while(iter != list.end())
	{
		if(*iter == "BBB")
		{
			list.erase(iter);
		}
		else
		{
			++iter;
		}
	}
	
	iter = list.begin();
	list.erase(iter+2,iter + 3);
	
	mutIter.toFront();
	while(mutIter.hasNext())
	{
		QString str = mutIter.next();
		if(str == "333" || str == "AAA")
		{
			mutIter.remove();   //ɾ��next()/previous()������������Ԫ��
		}
	}
	
	for(const QString& str: list)
	{
		std::cout<<str.toStdString()<<" ";
	}
	std::cout<<std::endl<<"delete list: erase/QMutableListIterator::remove ,list.size() ="<<list.size()<<std::endl<<std::endl;
}