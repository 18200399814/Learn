#include <cassert>
#include <cstring>
#include <iostream>

#include "goose.h"
#include "feather.h"

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define _ERROR_
#undef _ERROR_

#define _BAD_IDEA_
#undef _BAD_IDEA_

#define SafeDelete(ptr)            \
	do{                            \
		if(ptr != nullptr)         \
		{                          \
			delete ptr;            \
			ptr == nullptr;        \
		}                          \
	}while(0)

using std::list;
using std::cout;
using std::endl;

static void clearFeatherList(list<Feather*> &feathers);

Goose::Goose(const char* number)
{
	if(number == nullptr)
	{
		cout<<"Goose constructor error: number is nullptr"<<endl;
		throw "Goose constructor error: number is nullptr";
	}
	
	this->number = new char[strlen(number) + 1];
	memcpy(this->number,number,strlen(number) + 1);
}

Goose::Goose(const Goose& other)
{
	if(other.number == nullptr)
	{
		cout<<"copy constructor error: other.number is nullptr"<<endl;
		throw "copy constructor error: other.number is nullptr";
	}
	
	int len = strlen(other.number) + 1;
	number = new char[len];
	memset(number,0,len);
	memcpy(number,other.number,len);
	
	//因为拷贝构造的Goose对象还没有生成，所以feathers容器中肯定是没有内容，不需要做清空操作。
	// clearFeatherList(feathers);
	
	list<Feather*>::const_iterator citer = other.feathers.cbegin();
	while(citer != other.feathers.cend())
	{
		Feather* pfeather = *citer;
		feathers.push_back(new Feather(*pfeather));
		++citer;
	}
}

Goose::~Goose()
{
#ifndef _CHANGE_WAY_
	delete[] number;          //delete或free前可以不用做判空处理，因为nullptr指针也可以delete或free
#else
	if(nullptr != number)   //1.判断条件nullptr != number并不能排除number是野指针的情况，因为野指针也不指向nullptr。
	{
		delete[] number;      //2.C++语言规定nullptr指针是可以delete的，程序并不会崩溃。
		number = nullptr;
	}
#endif

	while(!feathers.empty())
	{
		Feather* pfeather = feathers.front();
		feathers.pop_front();
		
		delete pfeather;
		pfeather = nullptr;
	}
}

//list中remove和erase方法都可以进行数据的移除，区别在于remove移除的是List中所有与待移除项相等的数据，而erase移除的是迭代器所指的内容。
//remove有一个是否相等的比较，因此我们在remove自定义的数据时，要添加==运算符的重载实现。
Goose& Goose::operator =(const Goose& other)
{
	assert(other.number != nullptr);
	
	delete[] number;
	int len = strlen(other.number) + 1;
	number = new char[len];
	memset(number,0,len);
	strcpy(number,other.number);

#ifndef _CHANGE_WAY_
	list<Feather*>::iterator iter = feathers.begin();
	while(iter != feathers.end())
	{
		delete *iter;             //当容器中的一个元素被删除时，指向该元素后续的迭代器变得无效。利用了后置自增运算符在运算结束之后会给变量重新赋值的特点，
		feathers.erase(iter++);   //把迭代器的值重新赋值为了原先的值加一。删除节点的前先对迭代器进行后移的操作，因此其他元素不会失效。
	}
#else
	clearFeatherList(feathers);
#endif

	for(const auto pfeather: other.feathers)
	{
		feathers.push_back(new Feather(*pfeather));
	}
	
	return *this;
}

bool Goose::operator ==(const Goose& other)
{
	if(strcmp(number,other.number) != 0 || feathers.size() != other.feathers.size())
	{
		return false;
	}

#ifdef _ERROR_
	for(int i=0;i<feathers.size();++i)
	{
		if(*(feathers[i]) != *(other.feathers.at(i)))    //C++中list只能通过迭代器遍历访问，不能通过位置索引访问。
		{
			return false;
		}
	}
#else
	list<Feather*>::const_iterator citer = feathers.cbegin();
	list<Feather*>::const_iterator other_citer = other.feathers.cbegin();
	while(citer != feathers.cend())
	{
		if(**citer != **other_citer)
		{
			return false;
		}
		++citer;
		++other_citer;
	}
#endif
	
	return true;
}
	
void Goose::setNumber(const char* number)
{
	if(nullptr == number)
	{
		cout<<"setNumber error: number is nullptr"<<endl;
		return ;
	}
	
	delete this->number;
	this->number = new char[strlen(number) + 1];
	strcpy(this->number,number);
}

const char* Goose::getNumber()const
{
	return number;
}

void Goose::addFeather(Feather* pfeather)   //使用浅拷贝实现的addFeather()方法，使用过程中需要注意是否会造成野指针或者内存泄漏等问题
{
	if(pfeather == nullptr)
	{
		cout<<"addFeather error: pfeather is nullptr"<<endl;
		return ;
	}
	
	feathers.push_back(pfeather);
}

#ifdef _BAD_IDEA_
void Goose::removeFeather(Feather* pfeather)   //只能移除那些传入的pfeather与feathers列表中存放的指针地址完全相同的指针。
{                                              //这就意味着用户使用addFeather()方法将pfeather指针添加到feathers列表中时，
	if(pfeather == nullptr)                    //还需要一直保存pfeather指针的指向，因为在removeFeather()方法中还需要用到。
	{
		cout<<"removeFeather error: pfeather is nullptr"<<endl;
		return ;
	}
	
	feathers.remove(pfeather);
}
#else
void Goose::removeFeather(Feather* pfeather)
{
	if(nullptr == pfeather)
	{
		cout<<"removeFeather error: pfeather is nullptr"<<endl;
		return ;
	}
	
	list<Feather*>::iterator iter = feathers.begin();
	while(iter != feathers.end())
	{
		if(*iter != nullptr && *iter == pfeather)
		{
			feathers.erase(iter++);     //只将pfeather指针从feathers列表中移除，但不释放pfeather指针的内存。
			continue;                   //将pfeather指针内存释放工作交给Goose类外的用户去做。因为如果removeFeather()
		}                               //方法中将形参pfeather指针释放了以后，则实参pfeather指针就会变为野指针。
		
		if(*iter != nullptr && **iter == *pfeather)
		{
			delete *iter;
			*iter = nullptr;
			feathers.erase(iter++);    //将内存被释放掉了的Feather指针从list容器中移除掉，以减少list容器的大小。
		}
		iter++;
	}
}	
#endif

void Goose::show()const
{
	if(number == nullptr)     //在指针做读取或者写入操作时，才需要做判空处理。如果指针delete操作，则不需要判空处理。
	{
		return ;
	}
	cout<<"goose number ="<<number<<endl;
	
	list<Feather*>::const_iterator citer;
	for(citer = feathers.cbegin();citer != feathers.cend();++citer)
	{
		(*citer)->print();
	}
}

#ifndef _ERROR_
void clearFeatherList(list<Feather*> &feathers)
{
	for(Feather* pfeather: feathers)     //会造成软件崩溃，因为范围for循环正在遍历list容器，但是循环过程中又改变了list容器的大小
	{
		SafeDelete(pfeather);
		feathers.remove(pfeather);       //STL容器在删除完元素之后，其迭代器的值会改变，成为一个无效值，以至于无法继续遍历。
	}
}
#else
void clearFeatherList(list<Feather*> &feathers)
{
	for(Feather* pfeather: feathers)
	{
		SafeDelete(pfeather);
	}
	
	feathers.clear();
}	
#endif