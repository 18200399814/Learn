#include <iostream>
#include <array>

#define _ERROR_
#undef _ERROR_

#define SIZE 5

using namespace std;

class Sample
{
public:
	// Sample():value(0){}                               //Ĭ�Ϲ��캯��
	Sample(int value):value(value){}
	Sample(const Sample& other):value(other.value){}
	
	void setValue(int value){this->value = value;}
	int getValue()const{return value;}
	
	void show()const{cout<<"value ="<<value<<endl;}
private:
	int value;
};

int main(void)
{
#ifdef _ERROR_ 
	array<Sample,SIZE> samples;                      //��ΪSample��û���ṩĬ�ϵĹ��캯��,���� array���޷�װ��Sample���󣬱��뱨��
#else
	array<Sample,SIZE> samples = {0,1,2,3,4};        //��ΪSample��û���ṩĬ�ϵĹ��캯�������Ա���ʹ��{}��ʼ�������Ҷ���array<Sample,SIZE>����ʱ�����Ѿ�װ����Sample����
#endif

	samples[0].show();
	samples[1].show();
	cout<<endl;
	
	array<Sample*,SIZE> psamples;
	for(int i=0;i<SIZE;++i)
	{
		psamples[i] = new Sample(2 * i);
	}
	
	for(int j=0;j<SIZE;++j)
	{
		psamples[j]->show();
		delete psamples[j];
	}
	
	return 0;
}