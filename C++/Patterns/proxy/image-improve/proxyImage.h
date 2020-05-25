#ifndef _PROXY_IMAGE_H
#define _PROXY_IMAGE_H

#include "realImage.h"

class ProxyImage:public Image
{
public:
	ProxyImage(std::string fileName):image(fileName)
	{
		this->fileName = fileName;
	}
	
	void show()final				//ProxyImage��һ�������࣬����RealImage������ص��ڴ�ռ�á�
	{
		image.show();
	}
private:
	RealImage image;				    //���������ֻ�ܷ���Image����Ľӿ�
	std::string fileName;
};

#endif //_PROXY_IMAGE_H