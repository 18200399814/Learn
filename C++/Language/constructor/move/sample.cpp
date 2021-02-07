#include "sample.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define _EEROR_
#undef _EEROR_

Sample::Sample()
	:data(0)
	,name(nullptr)
{
	puts("---default constructor---");
}

Sample::Sample(const data_t data)
	:data(data)
	,name(nullptr)
{
	fputs("---normal constructor: 1---\n",stdout);
} 

Sample::Sample(const char* name,const data_t data)
	:data(data)
{
	if(name == nullptr)
	{
		this->name = nullptr;
	}
	else
	{
		int len = strlen(name) + 1;
		this->name = (char*)malloc(len);
		memset(this->name,0,len);
		memcpy(this->name,name,len);
	}
	fputs("---normal constructor: 2---\n",stdout);
}

#ifdef _EEROR_
//�������other.name = nullptr��䣬��ôSample(Sample& other)��ʵ��Ϊ��ǳ�������캯����
//other.name��this->nameָ��ָ��ͬһƬ�ڴ�����Sample��������ʱ�����ͬһƬ�ڴ�ռ䱻����ͷ����⡣
Sample::Sample(Sample& other)
	:data(other.data)
	,name(other.name)
{
	printf("---shallowly copy constructor---\n");
}
#else
//�������other.name = nullptr��䣬��ôSample(Sample& other)��ʵ��Ϊ���ƶ����캯���������ڴ���Դ����Ȩת�ƹ��ܡ�
//other.nameָ�뽫��ָ����ڴ���Դ����Ȩת�Ƹ�this->nameָ�룬ͬʱother.name���ÿ��ˡ���Sample��������ʱ�Ͳ���
//���ͬһƬ�ڴ�ռ䱻����ͷ����⡣
Sample::Sample(Sample& other)
	:data(other.data)
	,name(other.name)
{
	other.name = nullptr;
	printf("---move constructor by left value reference---\n");
}
#endif

Sample::Sample(const Sample& other)
	:data(other.data)
	,name(nullptr)
{
	if(other.name != nullptr)
	{
		int len = strlen(other.name) + 1;
		name = (char*)malloc(len);
		strcpy(name,other.name);
	}
	fprintf(stdout,"---deeply copy constructor---\n");
}

Sample::Sample(Sample&& other)
	:data(other.data)
	,name(other.name)
{
	other.name = nullptr;
	fprintf(stdout,"---move constructor by right value reference---\n");
}

Sample::~Sample()
{
	free(name);
	puts("---desturctor---");
}

#ifdef _EEROR_
Sample& Sample::operator =(Sample& other)  //��ʵ��Ϊǳ������ֵ
{
	data = other.data;
	
	if(name != nullptr)
	{
		free(name);
		name = nullptr;
	}
	
	if(other.name != nullptr)
	{
		name = other.name;
	}
	
	fprintf(stdout,"--shallowly copy assign--\n");
	return *this;
}
#else
Sample& Sample::operator =(Sample& other)  //��ʵ��Ϊ�ƶ���ֵ
{
	data = other.data;
	
	if(name != nullptr)
	{
		free(name);
		name = nullptr;
	}
	
	if(other.name != nullptr)
	{
		name = other.name;
		other.name = nullptr;
	}
	
	printf("--move assign by left value reference--\n");
	return *this;
}
#endif

Sample& Sample::operator =(const Sample& other)   //ֻ�ܱ�ʵ��Ϊ�����ֵ
{
	data = other.data;
	
	if(name != nullptr)
	{
		free(name);
		name = nullptr;
	}
	
	if(other.name != nullptr)
	{
		int len = strlen(other.name) + 1;    //ͨ������һ��len����������������ַ������Ƚ�����������Լ���һ��strlen�������ã�
		name = (char*)malloc(len);           //�Ӷ���������ִ�е��ٶȡ�
		memcpy(name,other.name,len);
	}
	
	fprintf(stdout,"--deeply copy assign--\n");
	return *this;
}

Sample& Sample::operator =(Sample&& other)   //��ʵ��Ϊ�ƶ���ֵ
{
	data = other.data;
	
	if(name != nullptr)
	{
		free(name);
		name = nullptr;
	}
	
	if(other.name != nullptr)
	{
		name = other.name;
		other.name = nullptr;
	}
	
	printf("--move assign by right value reference--\n");
	return *this;
}

void Sample::setName(const char* name)
{
	if(this->name != nullptr)
	{
		free(this->name);
		this->name = nullptr;
	}
	
	if(name != nullptr)
	{
		// int len = strlen(name) + 1;
		this->name = (char*)malloc(strlen(name) + 1);   //���������len����������strlen�����ķ��ؽ������ôstrlen��������Ҫ����ε��á�
		memcpy(this->name,name,strlen(name) + 1);       //�Ӷ����ͳ���ִ�е��ٶȡ�
	}
}

const char* Sample::getName()const
{
	return name;
}

void Sample::setData(const data_t data)
{
	this->data = data;
}

data_t Sample::getData()const
{
	return data;
}

void Sample::show()const
{
	if(name != nullptr)
		printf("name =%s, ",name);
	
	printf("data = %d\n",data);
}