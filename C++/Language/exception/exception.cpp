#include <iostream>

using namespace std;

static int fun(const int n);

int main()
{
	try{
		cout<<"4!="<<fun(4)<<endl;
		cout<<"-2!="<<fun(-2)<<endl;
		cout<<"5!="<<fun(5)<<endl;
	}catch(int n){
		cout<<" n="<<n<<"���ܼ���׳�"<<endl;
	}catch(...){
		cout<<"����������ʽ�쳣"<<endl;
	}
	cout<<"����ִ�н���"<<endl;
	
	return 0;
}

int fun(const int n)
{
	if(n <= 0) throw n;
	
	if(n == 1) return 1;
	return n*fun(n-1);
}