#include <stdio.h>
#include <iostream>
#include <QDebug>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

using namespace std;

int main(int argc,char** argv)
{
#ifndef _CHANGE_WAY_
	qDebug()<<"qDebug : hello world"<<endl;
#else
	cout<<"std::cout : hello world"<<endl;
#endif

	getchar();    //��ֹ�����������Ժ��ն�����
	return 0;
}