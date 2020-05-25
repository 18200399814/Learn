#include <iostream>

using namespace std;

template<typename T>
bool check(const T n);

int main()
{
	check(2);
	check(1);
	check('a');
	check(3.14);
	
	return 0;
}

template<typename T>
bool check(const T n)
{
	try{
		if(n == 1) throw n;
		if(n == 'a') throw 'q';
		if(n == 3.14) throw 3.14;
	}catch(int e){
		cout<<"�����������ͣ�"<<e<<endl;
		return false;
	}catch(char e){
		cout<<"�����ַ������ͣ�"<<e<<endl;
		return false;
	}catch(double e){
		cout<<"���񸡵������ͣ�"<<e<<endl;
		return false;
	}
	
	cout<<"���쳣"<<endl;
	return true;
}