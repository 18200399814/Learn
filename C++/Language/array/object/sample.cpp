#ifndef _SAMPLE_H
#define _SAMPLE_H

#include <stdlib.h>
#include <iostream>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define _ERROR_
#undef _ERROR_

#define SIZE 5

#define DisplayArr(arr,size)                            \
	do{                                                 \
		if((arr) == nullptr || (size) <= 0)             \
		{                                               \
			cout<<"arr or size is illegal"<<endl;       \
			exit(-1);                                   \
		}                                               \
		                                                \
		for(int i=0;i<size;++i)                         \
		{                                               \
			cout<<arr[i].getNum()<<" ";                 \
		}                                               \
		cout<<endl;                                     \
	}while(0)

using std::cout;
using std::endl;

class Sample
{
public:
	// Sample():num(0){}                //Ĭ�Ϲ��캯��
	Sample(const int num):num(num){}
	Sample(const Sample& other):num(other.num){}
	
	void setNum(const int num){this->num = num;}
	int getNum()const{return num;}
	
	void show()const{cout<<"num ="<<num<<endl;}
private:
	int num;
};

static void printArr(const Sample sampleArr[],int size);

template <typename T>
static void showArr(const T* arr,int size);

int main()
{
#ifdef _ERROR_
	Sample sampleArr[SIZE];               //��ΪSample����û��Ĭ�Ϲ��캯��������������벻ͨ��
	DisplayArr(sampleArr,SIZE);
#else
	Sample *psampleArr[SIZE];              //Sample����û��Ĭ�Ϲ��캯��,���ǿ��Զ���Sampleָ�����飬Ȼ��������е�ָ����һ��ֵ
	for(int i=0;i<SIZE;++i)
	{
		psampleArr[i] = new Sample(i);
	}
	
	for(int i=0;i<SIZE;++i)
	{
		if(psampleArr[i] != nullptr)
		{
			psampleArr[i]->show();
			delete psampleArr[i];
			psampleArr[i] = nullptr;
		}
	}
#endif
	
#ifndef _CHANGE_WAY_
	Sample samples[SIZE] = {0,1,2,3,4};                                           //��ʽ����Sample(const int num)���캯��
#else
	Sample samples[SIZE] = {Sample(0),Sample(1),Sample(2),Sample(3),Sample(4)};   //��ʽ����Sample(const int num)���캯��
	Sample sample(samples[2]);                                                    //��ʾ���ÿ������캯��
	sample.show();
#endif
	
	printArr(samples,SIZE);
	DisplayArr(samples,sizeof(samples)/sizeof(Sample));
	showArr(samples,sizeof(samples)/sizeof(samples[0]));
	
	Sample *psample = new Sample[SIZE]{5,6,7,8,9};            //��ʽ����Sample(const int num)���캯��
	showArr(psample,SIZE);
	if(psample != nullptr)
	{
		delete[] psample;
		psample = nullptr;
	}
	
	return 0;
}

static void printArr(const Sample sampleArr[],int size)
{
	if(size <= 0)
	{
		cout<<"size is less than zero"<<endl;
		return ;
	}
	
	for(int i=0;i<size;++i)
	{
		cout<<sampleArr[i].getNum()<<" ";
	}
	cout<<endl;
}

template <typename T>
void showArr(const T* arr,int size)
{
	if((arr) == nullptr || (size) <= 0)
	{
		cout<<"arr or size is illegal"<<endl;
		return ;
	}  

	for(int i=0;i<size;++i)
	{
		cout<<arr[i].getNum()<<" ";         //ģ������T�������public��getNum�������ܱ���ͨ��
	}
	cout<<endl;		  	
}

#endif //_SAMPLE_H