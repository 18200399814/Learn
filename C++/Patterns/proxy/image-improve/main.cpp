#include "proxyImage.h"

int main()
{
	Image* image = new ProxyImage("proxty.jpg");

	std::cout<<"ͼ�񽫴Ӵ��̼��� showing"<<std::endl;
	image->show();
	std::cout<<"ͼ����Ҫ�Ӵ��̼��� showing"<<std::endl;
	image->show();
	
	return 0;
}