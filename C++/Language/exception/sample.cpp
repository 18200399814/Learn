#include <iostream>

using namespace std;

class Sample
{
public:
	Sample(){
		cout<<"Sample constructor"<<endl;
//		throw 1;							//��Ϊ�ڹ��캯�����׳��쳣������Sample���󲻻ṹ��ɹ�
	}
	
	~Sample(){
		cout<<"Sample destructor"<<endl;
	}
};

int main()
{
	try{
		Sample s;
		throw 1;
	}catch(int){
		cout<<"�����쳣"<<endl;
	}
	
	return 0;
}