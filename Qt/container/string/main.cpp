#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <QtGlobal>
#include <QChar>
#include <QString>
#include <QStringList>
#include <QDebug>

//QString�ַ�����crud����
static void create_string();
static void retrieve_string();
static void update_string();
static void delete_string();

int main(int argc,char* argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);

	create_string();
	retrieve_string();
	update_string();
	delete_string();

	return 0;
}

void create_string()
{
	QString str;       //����QStringĬ�Ϲ��캯��
	str.append("append");    //ͨ������һ�����ַ���������׷�ӵķ�ʽ�����ַ������������
	str.prepend("a");
	str.insert(0,"this");
	str.insert(1,"is");
	str.insert(str.length(),"string");
	qDebug()<<"create string: append/prepend/insert ,str ="<<str;

	QString str1 = "hello world";  //��ʽ����QString(const char* str)���캯��
	QString str2 = "hello c++";  //��ʽ����QString(const char* str)���캯��
	qDebug()<<"create string: constructor ,str1 ="<<str1<<" ,str2 ="<<str2;
	
	/*(1)���������Ż���������ȵ���QString(const char* str)���캯������һ����ʱ�����ٵ����ƶ����캯������str3��
	 *(2)�������Ż��������ֱ���Ż�Ϊ����QString(const char* str)���캯������str3�ַ�����
	 */
	QString str3 = QString("hello qt");
	qDebug()<<"create string: move constructor , str3 ="<<str3;
	
	std::string cstr = "this is a std::string";
	QString str4 = QString::fromStdString(cstr);     //�����������ַ���ת��ΪQString�ַ���
	qDebug()<<"create string: fromStdString ,str4 ="<<str4;
	std::cout<<"create string: toStdString ,"<<str4.toStdString()<<std::endl;
	
	//��ʽ������ķ�ʽ�����ַ���
	QString str5;
	str5.sprintf("%s value is %d","x",50);
	QString str6 = QString("%1 value is %2").arg("y").arg(3.14);
	qDebug()<<"create string: sprintf/arg ,str5 ="<<str5<<" ,str6 ="<<str6;
	
	std::cout<<std::endl;
}

void retrieve_string()
{
	QString str = "Hello world HELLO World qt";
	qDebug()<<"retrieve string: at/[]/front/back ,str.at(1) ="<<str.at(1)<<" ,str[4] ="<<str[4]
			<<" ,str.front() ="<<str.front()<<" ,str.back() ="<<str.back();
	
	qDebug()<<"retrieve string: isEmpty/isNull ,QString("").isEmpty() ="<<QString("").isEmpty()<<" ,QString("").isNull() ="<<QString("").isNull()
		    <<" ,QString().isEmpty() ="<<QString().isEmpty()<<" ,QString().isNull() ="<<QString().isNull();
	
	bool ret = str.contains("world",Qt::CaseInsensitive);     //�����ִ�Сд
	qDebug()<<"retrieve string: constains ,ret ="<<ret;
	
	int num = str.count("hello",Qt::CaseInsensitive);   //ͳ��"hello"�ַ�����str�г��ֵĴ���
	qDebug()<<"retrieve string: count ,num ="<<num;
	
	ret = str.startsWith("hello",Qt::CaseInsensitive);
	qDebug()<<"retrieve string: startsWith ,ret ="<<ret;
	
	ret = str.endsWith("world");
	qDebug()<<"retrieve string: endsWith ,ret ="<<ret;
	
	int pos = str.indexOf("world");     //����"world"��str�ַ����е�һ�γ��ֵ�λ��
	qDebug()<<"retrieve string: indexOf from 0 ,pos ="<<pos;
	
	pos = str.indexOf("world",8,Qt::CaseInsensitive);
	qDebug()<<"retrieve string: indexOf from 8 ,pos ="<<pos;

	pos = str.lastIndexOf("world",-1,Qt::CaseInsensitive);
	qDebug()<<"retrieve string: lastIndexOf ,pos ="<<pos;
	
	QString str1("welcome");
	QString str2 = "world";
	ret = (str1 == str2) ? true : false;      //QString������==��!=��>��>=��<��<=�����
	qDebug()<<"retrieve string: == ,ret ="<<ret;
	
	ret = (str1 > str2);
	qDebug()<<"retrieve string: > ,ret ="<<ret;	

	int result = str1.compare(str2,Qt::CaseInsensitive);
	if(result == 0)
	{
		qDebug()<<"retrieve string: compare ,"<<str1<<" is equal to "<<str2;	
	}else if(result > 0)
	{
		qDebug()<<"retrieve string: compare ,"<<str1<<" is greater than "<<str2;
	}else if(result < 0)
	{
		qDebug()<<"retrieve string: compare ,"<<str1<<" is less than "<<str2;
	}
	
	QString str3 = "forename,middlename,surname,phone";
	QStringList subStr = str3.split(",");     //��","�ָ��ַ��������طָ����ַ����б�
	std::for_each(subStr.begin(),subStr.end(),
		[](const QString& str){
			std::cout<<str.toStdString()<<" ";
		}
	);
	std::cout<<std::endl;
	
	QString path = "/user/local/bin/myapp";
	qDebug()<<"retrieve string: path.section('/',3,3) ="<<path.section('/',3,3)      //��','�ָ�������������ҵĵ�3�η���
	        <<" ,path.section('/',3,4) ="<<path.section("/",3,4)                     //��","�ָ�������������ҵĵ�3�ε���4�η���
	        <<" ,path.section('/',3,3,QString::SectionSkipEmpty) ="<<path.section("/",3,3,QString::SectionSkipEmpty)    //��","�ָ�������������ҵĵ�3�η���(����ǰ��Ŀ��ֶ�)
            <<" ,path.section('/',-3,-2) ="<<path.section('/',-3,-2);                 //���ű�ʾ�����������

	std::cout<<std::endl;
}

void update_string()
{
	QString str = "hello";
	str = "welcome";
	qDebug()<<"update string: = ,str ="<<str;
	
	str = str + " c++";
	qDebug()<<"update string: + ,str ="<<str;
	
	str +=" and qt";
	qDebug()<<"update string: += ,str ="<<str;
	
	str.push_front(QString("he "));
	str.push_front(QChar('T'));
	str.push_back(QString(" and c"));
	str.push_back(QString('#'));
	qDebug()<<"update string: push_front/push_back ,str ="<<str;
	
	str = "say yes";
	str.replace(4,3,"no");
	qDebug()<<"update string: replace ,str ="<<str;
	
	str = "The Qt PROject";
	qDebug()<<"update string: toLower/toUpper, "<<str.toLower()<<" ,"<<str.toUpper();
	
	QCharRef ch1 = str.front();
	QCharRef ch2 = str.back();
	ch1 = 't';
	ch2 = 'T';
	qDebug()<<"update string: front/back ,str ="<<str;
	
	bool ok = true;
	double dvar = QString("3.14").toDouble(&ok);
	if(ok)
	{
		qDebug()<<"update string: toDouble ,dvar ="<<dvar;
	}
	
	int ivar = QString("0x123").toInt(&ok,16);   //�ַ���"123" ��16����ת��Ϊ����
	if(ok)
	{
		qDebug()<<"update string: toInt ,ivar ="<<ivar;
	}
	else
	{
		qDebug()<<"update string: QString convert to int failed";
	}
	
	//setNum()��QString�����ͨ��Ա��������number��QString��ľ�̬��Ա����
	str.setNum(123,16);     //����123ת��Ϊ16�����ַ���
	qDebug()<<"update string: setNum , str ="<<str;
	
	str.setNum(2.71828,'g');     //'g'����ָ��ת������
	qDebug()<<"update string: setNum , str ="<<str;
	
	qDebug()<<"update string: number ,QString::number(200,10) ="<<QString::number(200,10)
	        <<" ,QString::number(0.618,'e') ="<<QString::number(0.618,'e');
			
	std::cout<<std::endl;
}

void delete_string()
{
	QString str = "welcome qt";
	str.clear();
	qDebug()<<"delete string: clear ,str ="<<str<<" ,length ="<<str.length();

	str = "welcome c++";
	str="";
	qDebug()<<"delete string: = ,str ="<<str<<" ,size ="<<str.size();
	
	str = "today is monday";
	str.chop(3);              //���ַ���ĩβɾ�������ַ�
	qDebug()<<"delete string: chop ,str ="<<str;
	
	QString str1 = "  welcome \t to \n you!";
	str = str1.trimmed();     //�Ƴ��ַ������˵Ŀհ��ַ������м�Ŀհ��ַ����ֲ���
	qDebug()<<"delete string: trimmed ,str ="<<str;
	
	str = str1.simplified();       //�Ƴ��ַ������˵Ŀհ��ַ�����ʹ�ÿո��ַ�" "�滻�ַ����г��ֵĿհ��ַ�
	qDebug()<<"delete string: simplified ,str ="<<str;

	str = "truncate test";
	str.truncate(strlen("trunc"));     //��ָ��λ�ýض��ַ���
	qDebug()<<"delete string: truncate ,str ="<<str;

	str = "a pineapple";
	qDebug()<<"delete string: mid/left/right ,str.mid(1,3) ="<<str.mid(2,4)      //��λ��1��ʼ����ȡ3���ַ�
	        <<" ,str.mid(6) ="<<str.mid(6)      //�ӵ�6��λ�ÿ�ʼ��һֱ��ȡ�����
            <<" ,str.left(4) ="<<str.left(5)
			<<" ,str.right(8) ="<<str.right(5);
	
	str.remove(2,4);
	qDebug()<<"delete string: remove ,str ="<<str;
	
	str.fill('*');
	qDebug()<<"delete string: fill ,str ="<<str;
	
	str.fill('A',4);
	qDebug()<<"delete string: fill ,str ="<<str;
}