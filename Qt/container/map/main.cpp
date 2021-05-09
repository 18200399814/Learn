#include <iostream>
#include <algorithm>
#include <QtGlobal>
#include <QtAlgorithms>
#include <QChar>
#include <QString>
#include <QRegExp>
#include <QList>
#include <QMap>
#include <QMapIterator>
#include <QMutableMapIterator>
#include <QDebug>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

//foreachֻ�ܱ�����QMap�е�valueֵ�������ܻ�ȡ��keyֵ
#define ShowValues(container)                    \
	do{                                          \
		foreach(const auto& data,container)      \
		{                                        \
			qDebug()<<data;                      \
		}                                        \
	}while(0)

template <typename K,typename V>
void showMap(const QMap<K,V> &map)
{
#ifndef _CHANGE_WAY_
	QMapIterator<K,V> iter(map);
	while(iter.hasNext())
	{
		iter.next();
		qDebug()<<"("<<iter.key()<<","<<iter.value()<<")";
	}
#else   //_CHANGE_WAY_
#ifdef _MSC_VER
#	pragma message("---use vc++ compilter---")
	QMap<K,V>::const_iterator citer = map.cbegin();
#else
#	pragma message("---use g++ compilter---")
	typename QMap<K,V>::const_iterator citer = map.cbegin();
#endif   //_MSC_VER

	for(;citer != map.cend();++citer)
	{
		qDebug()<<"("<<citer.key()<<","<<citer.value()<<")";
	}
#endif    //_CHANGE_WAY_
}

template <class T>
void display(const T& data)
{
	qDebug()<<data;
}

template <class T>
class Print
{
public:
	void operator ()(const T& data)
	{
		qDebug()<<data;
	}
};

//��QMap����crud��ɾ�Ĳ����
static void create_map();
static void retrieve_map();
static void update_map();
static void delete_map();

int main(int argc,char* argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);
	
	create_map();
	retrieve_map();
	update_map();
	delete_map();
	
	return 0;
}

void create_map()
{
	QMap<int,QString> map;
	map.insert(1,"aaa");
	map.insert(2,"bbb");
	map[3] = "ccc";
	map[4] = "ddd";
	ShowValues(map);
	qDebug()<<"create map: default constructor";
	
	QMap<int,QString> map1(map);
	showMap(map1);                        //showMap()����ģ����ʽ������
	qDebug()<<"create map: copy constructor";
	
	QMap<QString,double> map2 = {{"pi",3.14159},{"e",2.71828},{"phi",0.618}};
	showMap<QString,double>(map2);        //showMap()����ģ����ʽ������
	qDebug()<<"create map: initializer_list constructor";
}

void retrieve_map()
{
	//QMap�д洢�������ǰ���key�������еģ�QHash�д洢����������ȫ������õ�
	QMap<QChar,QString> map{{'a',"AA"},{'b',"BB"}};
	map.insert('f',"FF");
	map.insertMulti('f',"FFFF");
	map.insertMulti('b',"BBBB");
	map['c'] = "CC";
	map['d'] = "DD";
	map['e'] = "EE";
	showMap<QChar,QString>(map);
	qDebug()<<"retrieve map: insert/insertMulti/[] ,add item to map";

	qDebug()<<"retrieve map: isEmpty/empty ,map.isEmpty() ="<<map.isEmpty()<<" ,map.empty() ="<<map.empty();
	qDebug()<<"retrieve map: size/count ,map.size() ="<<map.size()<<" ,map.count() ="<<map.count()<<" ,map.count('b') ="<<map.count('b');
	qDebug()<<"retrieve map: []/key/value ,map['b'] ="<<map['b']<<" ,map.key(\"EE\") ="<<map.key("EE")<<" ,map.value('c') ="<<map.value('c');
	qDebug()<<"retrieve map: firstKey/first/lastKey/last ,(firstKey,firstValue) ="<<"("<<map.firstKey()<<","<<map.first()<<") "
	        <<"(lastKey,lastValue) ="<<"("<<map.lastKey()<<","<<map.last()<<")";

	QList<QChar> keys = map.keys();
	for(const QChar& key: keys)
	{
		std::cout<<key.toLatin1()<<" ";
	}
	std::cout<<std::endl<<"retrieve map: keys ,display keys"<<std::endl;
	
	QList<QChar> uniqueKeys = map.uniqueKeys();
	std::for_each(uniqueKeys.begin(),uniqueKeys.end(),display<QChar>);
	qDebug()<<"retrieve map: uniqueKeys ,display keys";
	
	QList<QString> values = map.values();
	std::for_each(values.begin(),values.end(),Print<QString>());
	qDebug()<<"retrieve map: values ,display values";
	
	if(map.contains('d'))
	{
		qDebug()<<"retrieve map: contains ,map contains 'd' key";
	}
	
	QMap<QChar,QString>::const_iterator citer = map.constFind('c');
	if(citer != map.constEnd())
	{
		qDebug()<<"retrieve map: constFind ,("<<citer.key()<<","<<citer.value()<<")";
	}
	
	QMap<QChar,QString>::iterator iter = map.find('a');
	if(iter != map.end())
	{
		qDebug()<<"retrieve map: find ,("<<iter.key()<<","<<iter.value()<<")";
		iter.value() = "aa";
	}
	
	citer = qFind(map,"DD");
	if(iter != map.end())
	{
		qDebug()<<"retrieve map: qFind ,("<<citer.key()<<","<<citer.value()<<")";
	}
	
	iter = qFind(map.begin(),map.end(),"EE");
	if(iter != map.end())
	{
		qDebug()<<"retrieve map: qFind ,("<<iter.key()<<","<<iter.value()<<")";
		*iter = "eeee";
	}
	
	iter = std::find(map.begin(),map.end(),"FFFF");
	if(iter != map.end())
	{
		qDebug()<<"retrieve map: std::find ,("<<iter.key()<<","<<iter.value()<<")";
		*iter = "ffff";
	}
	
	iter = std::find_if(map.begin(),map.end(),
		[](const QString& str){
			return str.contains(QRegExp("^BBB?"));
		}
	);
	
	if(iter != map.end())
	{
		qDebug()<<"retrieve map: std::find_if ,("<<iter.key()<<","<<iter.value()<<")";
		*iter = "bbbb";
	}
	
	//QMap��foreach��std::for_eachν�ʲ�������value����std::map��ν�ʲ�������pair��ֵ��
	std::for_each(map.begin(),map.end(),
		[](const QString& str){
			std::cout<<str.toStdString()<<" ";
		}
	);
	std::cout<<std::endl;
	
	QMapIterator<QChar,QString> mapIter(map);
	if(mapIter.findNext("BB"))
	{
		qDebug()<<"retrieve map: QMapIterator ,find "<<mapIter.value()<<" in map, key ="<<mapIter.key()
		        <<" ,previous item("<<mapIter.peekPrevious().key()<<","<<mapIter.peekPrevious().value()<<")"
				<<" ,next item("<<mapIter.peekNext().key()<<","<<mapIter.peekNext().value()<<")";
	}
	
	mapIter.toBack();
	while(mapIter.hasPrevious())
	{
		mapIter.previous();
		qDebug()<<"("<<mapIter.key()<<","<<mapIter.value()<<")";
	}
	qDebug()<<"retrieve map: QMapIterator ,reverse display map";
	
	std::cout<<std::endl;
}

void update_map()
{
	QMap<QString,double> map({{"pi",3.14159},{"e",2.71828}});
	map.insert("phi",0.618);
	map["sqrt(2)"] = 1.41421;
	
	//QMutableMapIterator������ֻ�������޸�QMap�е�valueֵ����������QMap�в����ֵ�Ի��޸�keyֵ
	QMutableMapIterator<QString,double> mutIter(map);
	while(mutIter.hasNext())
	{
		mutIter.next();
		std::cout<<"("<<mutIter.key().toStdString()<<","<<mutIter.value()<<") ";
	}
	std::cout<<std::endl<<"update map: QMutableMapIterator ,display map"<<std::endl;
	
	map["pi"] = 3.142;   //QList��QMap��value()�������������޸������е�ֵ
	map.first() = 2.178;
	map.last() = 1.414;
	qDebug()<<"update map: []/first/last ,map[\"pi\"] ="<<map["pi"]
	        <<" ,first item("<<map.firstKey()<<","<<map.first()<<") "
	        <<" ,last item("<<map.lastKey()<<","<<map.last()<<")";

	if(mutIter.findPrevious(0.618))
	{
		qDebug()<<"update map: QMutableMapIterator ,find "<<mutIter.value()<<" in map, key ="<<mutIter.key();
		mutIter.value() = 0.61803;
	}
	
	mutIter.previous();
	mutIter.setValue(2.17);
	
	QMap<QString,double>::iterator iter = map.find("sqrt(2)");
	if(iter != map.end())
	{
		qDebug()<<"update map: find ,find "<<iter.value()<<" in map, key ="<<iter.key();
		iter.value() = 1.4;
	}

	iter = std::find_if(map.begin(),map.end(),
		[](const double& data)
		{
			return (data > 3 && data < 4);
		}
	);
	
	if(iter != map.end())
	{
		qDebug()<<"update map: std::find_if ,find ("<<iter.key()<<","<<iter.value()<<")";
		*iter = 3.1;
	}
	
	for(const QString& key: map.keys())
	{
		qDebug()<<"("<<key<<","<<map.value(key)<<") "; 
	}
	std::cout<<std::endl<<"update map: range for display map"<<std::endl;
}

void delete_map()
{
	QMap<int,double> map = {{1,10.11},{2,10.22}};
	map[3] = 10.33;
	map.insert(4,10.44);
	map.insert(5,10.55);
	map.insertMulti(6,10.66);
	map.insertMulti(5,10.5555);
	
	foreach(const int& key,map.keys())
	{
		std::cout<<"("<<key<<","<<map.value(key)<<") ";
	}
	std::cout<<std::endl<<"delete map: foreach ,display map"<<std::endl;
	
	QMap<int,double> map1(map);
	map1.clear();
	qDebug()<<"delete map: clear ,map1.isEmpty() ="<<map1.isEmpty()<<" ,map1.count() ="<<map1.count();
	
	map1 = map;
	map1.remove(6);
	double data = map1.take(3);    //���ɾ��QMap�е����ݣ����ֲ���Ҫʹ��ɾ���ķ���ֵ����ô���ʹ��remove()����ɾ��
	showMap<int,double>(map1);
	std::cout<<"delete map: remove/take ,map1.size() ="<<map1.size()<<std::endl;
	
	QMap<int,double>::iterator iter = map1.find(4);
	if(iter != map1.end())
	{
		map1.erase(iter);
	}
	
	//keyBegin()��keyEnd()��������ֱ�����ڱ���QMap��keyֵ
	std::for_each(map1.keyBegin(),map1.keyEnd(),display<int>);
	qDebug()<<"delete map: erase ,map1.count() ="<<map1.count();
	
	QMutableMapIterator<int,double> mutIter(map1);
	mutIter.toBack();
	for(int i=0;i<2;++i)
	{
		mutIter.previous();
	}
	mutIter.remove();   //ɾ��QMap�еĵ����ڶ���
	
	mutIter.toFront();
	while(mutIter.hasNext())
	{
		mutIter.next();
		std::cout<<"("<<mutIter.key()<<","<<mutIter.value()<<") ";
	}
	std::cout<<std::endl;
}