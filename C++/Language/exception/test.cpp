#include <iostream>
#include <string>

using namespace std;

template<typename T>
void check(const T n);

int main()
{
	try{
		check(2);
		check(1);
		check('a');
		check(3.14);
	}catch(int e){
		cout<<"�����������ͣ�"<<e<<endl;
		return false;
	}catch(char e){
		cout<<"�����ַ������ͣ�"<<e<<endl;
		return false;
	}catch(double e){
		cout<<"���񸡵������ͣ�"<<e<<endl;
		return false;
	}catch(...){
		cout<<"Ĭ�ϲ���"<<endl;
		return false;		
	}
	
	return 0;
}

template<typename T>
void check(const T n)
{
	if(n == 1) throw n;
	if(n == 'a') throw 'q';
	if(n == 3.14) throw 3.14;
	
	cout<<"���쳣"<<endl;
}