#ifndef _LEG_H
#define _LEG_H

class Leg
{
public:
	Leg(const char* type);
	Leg(const Leg& other);
	~Leg();
	
	void operator =(const Leg& other);
	Leg operator =(const char* type);
	
	void print()const;
private:
	char* type;
};

Leg::Leg(const char* type)
	:type(nullptr)
{
	if(type != nullptr)
	{
		this->type = new char[strlen(type) + 1];
		memcpy(this->type,type,strlen(type) + 1);
	}
}

Leg::Leg(const Leg& other)
	:type(nullptr)
{
	if(other.type != nullptr)
	{
/*		if(type != nullptr)         //��Ϊ�ǿ������죬����type�ڳ�ʼ���б����Ѿ���ʼ��Ϊ��nullptr���������ﲻ��Ҫ�пպ��delete����
		{
			delete type;
			type = nullptr;
		}
*/
		type = new char[strlen(other.type) + 1];
		strcpy(type,other.type);
	}
}

Leg::~Leg()
{
	if(type != nullptr)
	{
		delete type;
		type = nullptr;
	}
}

void Leg::operator =(const Leg& other)
{
	if(other.type != nullptr)
	{
		if(type != nullptr)              //��Ϊ�����Ǹ�ֵ����ǰ�����type���Ϳ��ܲ�Ϊ�գ������Ϊ����Ҫ��delete�������ڴ�й©
		{
			delete type;
			type = nullptr;
		}
		
		type = new char[strlen(other.type) + 1];
		strcpy(type,other.type);
	}
}

Leg Leg::operator =(const char* type)
{
	if(type != nullptr)
	{
		if(this->type != nullptr)          //��Ϊ�����Ǹ�ֵ����ǰ�����type���Ϳ��ܲ�Ϊ�գ������Ϊ����Ҫ��delete�������ڴ�й©
		{
			delete this->type;
			this->type = nullptr;
		}
		
		this->type = new char[strlen(type) + 1];
		memcpy(this->type,type,strlen(type) + 1);
	}
	
	return *this;
}

void Leg::print()const
{
	if(type != nullptr)
	{
		printf("leg type =%s\n",type);
	}
}

#endif //_LEG_H