#ifndef _ENGINE_H
#define _ENGINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Engine
{
public:
	Engine(const char* brand);
	Engine(const Engine& other);
	~Engine();
	
	void operator =(const char* brand);
	Engine operator =(const Engine& other);
	
	void show()const;
private:
	char* brand;
};

Engine::Engine(const char* brand)
	:brand(nullptr)
{
	if(brand != nullptr)                 //���캯���н���ʹ������Ƕ��if��䣬�������Լ���ʹ��exit��assert��abort��throw�ȷ���
	{
		this->brand = (char*)malloc(strlen(brand) + 1);
		if(this->brand == nullptr)
		{
			printf("malloc brand error\n");
			throw "malloc brand error";           //ʹ����C��C++���﷨��ϱ��
		}
		
		memcpy(this->brand,brand,strlen(brand) + 1);
	}
}

Engine::Engine(const Engine& other)
	:brand(nullptr)
{
	if(other.brand != nullptr)            //���캯���н���ʹ������Ƕ��if��䣬�������Լ���ʹ��exit��assert��abort��throw�ȷ���
	{
		brand = (char*)malloc(strlen(other.brand) + 1);
		if(brand == nullptr)
		{
			printf("malloc brand error\n");
			throw "malloc brand error";
		}
		
		strcpy(brand,other.brand);
	}	
}

Engine::~Engine()
{
	if(brand != NULL)
	{
		free(brand);
		brand = NULL;
	}
}

void Engine::operator =(const char* brand)
{
	if(brand == NULL)                //��Ա�����ж�������ʹ��Ƕ��if��䣬ֱ��ȡ��return��
	{
		fputs("brand is null",stdout);
		return ;
	}
	
	if(this->brand != NULL)
	{
		free(this->brand);
		this->brand = NULL;
	}
	
	this->brand = (char*)malloc(strlen(brand) + 1);
	if(this->brand == NULL)
	{
		puts("brand malloc failed");
		return ;
	}
	
	memcpy(this->brand,brand,strlen(brand) + 1);
}

Engine Engine::operator =(const Engine& other)
{
	if(other.brand == nullptr)             //��Ա�����ж�������ʹ��Ƕ��if��䣬ֱ��ȡ��return��
	{
		fprintf(stdout,"other.brand is null\n");
		return Engine(NULL);
	}
	
	if(brand != nullptr)
	{
		free(brand);
		brand = nullptr;
	}
	
	brand = (char*)malloc(strlen(other.brand) + 1);
	if(brand == nullptr)
	{
		fputs("brand malloc failed",stdout);
		return Engine(nullptr);
	}
	
	strcpy(brand,other.brand);
	return *this;
}

void Engine::show()const
{
	if(brand == NULL)
	{
		puts("show: brand is null");
		return ;
	}
	
	printf("engine brand =%s\n",brand);
}

#endif