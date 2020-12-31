#include <iostream>
#include <string>

using namespace std;

template <class T>
T add(const T& x,const T& y)
{
	cout <<"����ģ��"<<endl;
	return x+y;
}

template <>
string add(const string& x,const string& y)      //����ģ��������ʱ�����Ը����亯��ʵ�֣�ʹ����Ϊ��ͨ��ģ�岻һ�¡�
{
	cout<<"Specialized template for string type"<<endl;
	return x + y;
}

int main()
{
	int i=3,j=4;
	double m=2.12,n=3.34;
	string x="hello",y="world";
	
	cout<<i<<" + "<<j<<" ="<<add(i,j)<<endl;
	cout<<m<<" + "<<n<<" ="<<add(m,n)<<endl;            //����ģ����ʽ���廯
	
	cout<<m<<" + "<<n<<" ="<<add<double>(m,n)<<endl;    //����ģ����ʾ���廯
	
	string z = add(x,y);
	cout<<x<<" + "<<y<<" ="<<z<<endl;                    //����ģ���string����������
	
	return 0;
}