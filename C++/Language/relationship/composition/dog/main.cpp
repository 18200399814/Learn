#include "dog.h"

int main(void)
{
	Dog dog1("curly","red",5);
	dog1.detail();
	cout<<endl;
	
	Dog dog2 = dog1;        //����Dog�Ŀ������캯��
	dog2.detail();
	
	return 0;
}