#include <iostream>

using namespace std;

//������������������
static inline void swap(double &a,double &b);
static inline void swap(double* const a,double* const b);

static inline void swap(int &a,int &b);
static inline void swap(int* const a,int* const b);

int main()
{
	int a=0,b=0;
//��ʾ����������
	cout<<"����������������"<<endl;
//����������
	cin>>a>>b;
//��ӡ�����������
	cout<<"a = "<<a<<" , "<<"b = "<<b<<endl;
//���������������
	swap(a,b);
//��ӡ������Ľ��
	cout<<"a = "<<a<<" , "<<"b = "<<b<<endl;
	
	double x=0,y=0;
	cout<<"������������������"<<endl;
	cin>>x>>y;
	cout<<"x = "<<x<<" , "<<"y = "<<y<<endl;
	swap(x,y);
	cout<<"x = "<<x<<" , "<<"y = "<<y<<endl;
	
	return 0;
}

void swap(double &a,double &b)
{
	double temp = a;
	a = b;
	b = temp;
}

static void swap(double* const a,double* const b)
{
	double temp = *a;
	*a = *b;
	*b = temp;	
}

inline void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

static inline void swap(int* const a,int* const b)
{
	int temp = *a;
	*a = *b;
	*b = temp;		
}