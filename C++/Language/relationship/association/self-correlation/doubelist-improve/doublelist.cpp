#include "doublelist.h"
#include <new>
#include <iostream>
#include <assert.h>
#include <stdlib.h>

#define _DEBUG_
// #undef _DEBUG_

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

#ifdef _DEBUG_
#define BreakPoint(index)   \
	cout<<"---["<<__func__<<": line ="<<__LINE__<<"] break point: "<<index<<" ---"<<endl
#else
#define BreakPoint(index)
#endif

using std::cout;
using std::endl;
using std::cerr;

template <typename T>
static void swap(T& x,T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

DoubleList::DoubleList()
	:m_length(0)
{
	try{
		m_pheadNode = new Node;      //����˫�������ͷ��㣬�������ʼ��
		m_pheadNode->prev = nullptr;     //ʹ��new������������ڴ�ռ�ʱ�����Բ��ö�new������ķ���ֵ���пմ�����Ϊnew����������ڴ�ռ�ʧ��ʱ��
		m_pheadNode->data = 0;           //��ֱ���׳�std::bad_alloc�쳣����ʹ��malloc����������ڴ�ʱ����Ҫ��malloc�����ķ���ֵ���пմ���
		m_pheadNode->next = nullptr;  //C++��ʹ��new�����������ڴ�ռ�ʱ��һ�㲻���쳣������
		
		m_ptailNode = m_pheadNode;   //�¹�����˫���������ڻ�û������������½ڵ㣬����β�ڵ��ͷ���ָ����ͬ��λ�á�
	}
	catch(const std::bad_alloc& e)
	{
		cerr<<"bad_alloc caught: "<< e.what() <<endl;
		throw e;     //��ӡ�쳣��Ϣ�󣬼�������������ס������㺯��û�д����ڲ������׳����쳣����ô����ᱻֱ���жϡ�
	}
}

DoubleList::DoubleList(const DoubleList& other)
	:m_length(other.m_length)
{
	m_pheadNode = new Node;         //���ÿ������캯��ʱ����ǰ�����ͷ����ڴ滹û�б����롣
	m_pheadNode->prev = nullptr;    //����������Ϊͷ��㿪���ڴ�ռ䡣
	m_pheadNode->data = 0;
	m_pheadNode->next = nullptr;
	
	Node *pnode = m_pheadNode;         //������ǰ����Ľڵ�ָ��
	Node *qnode = other.m_pheadNode;   //����other����Ľڵ�ָ��
	while(qnode->next != nullptr)      //�����û�е���other�����β�ڵ㣬��ô�ͼ����ڵ㸴�Ʋ�����
	{                                  //���������other�����β�ڵ㣬��ô��ֹͣ�ڵ㿽��������
		qnode = qnode->next;           //��other����Ľڵ�ָ������һ���ڵ�λ���ƶ�
		
		Node *pnewNode = new Node;     //�����µ�����ڵ�
		pnewNode->prev = pnode;        //�½ڵ��ǰ��ָ�����������һ���ڵ�
		pnewNode->data = qnode->data;  //��other�����ж�Ӧ�ڵ��������е�ֵ���������½ڵ����������
		pnewNode->next = nullptr;      //�½ڵ�ĺ�������Ϊ��
		
		pnode->next = pnewNode;        //�����е����һ���ڵ�ָ���´����Ľڵ�
		pnode = pnode->next;           //�õ�ǰ����Ľڵ�ָ������һ���ڵ��ƶ���������ող�����½ڵ�
	}
	
	m_ptailNode = pnode;    //����˫������β�ڵ��λ�ã��Է��㷴�����
}

DoubleList::~DoubleList()
{
	clear();           //��˫�������еĽڵ���գ�ֻ����ͷ��㡣
	
	if(m_pheadNode != nullptr)
	{
		delete m_pheadNode;    //�ͷ�ͷ����ڴ�
		m_pheadNode = nullptr;
	}
	m_ptailNode = m_pheadNode;   //β�ڵ�ֻ��һ����ʶָ�룬����ͷ���һ��Ϊ�俪�����ڴ�ռ�ġ�β�ڵ�û�п����ڴ�ռ䣬��������ʱ��ȻҲ����Ҫdelete��
}

DoubleList& DoubleList::operator =(const DoubleList& other)
{
	clear();
	m_length = other.m_length;
	
	Node *pnode = m_pheadNode;         //������ǰ����Ľڵ�ָ��
	Node *qnode = other.m_pheadNode;   //����other����Ľڵ�ָ��
	while(qnode->next != nullptr)      //�����û�е���other�����β�ڵ㣬��ô�ͼ����ڵ㸴�Ʋ�����
	{                                  //���������other�����β�ڵ㣬��ô��ֹͣ�ڵ㿽��������
		qnode = qnode->next;           //��other����Ľڵ�ָ������һ���ڵ�λ���ƶ�
		
		Node *pnewNode = new Node;     //�����µ�����ڵ�
		pnewNode->prev = pnode;        //�½ڵ��ǰ��ָ�����������һ���ڵ�
		pnewNode->data = qnode->data;  //��other�����ж�Ӧ�ڵ��������е�ֵ���������½ڵ����������
		pnewNode->next = nullptr;      //�½ڵ�ĺ�������Ϊ��
		
		pnode->next = pnewNode;        //�����е����һ���ڵ�ָ���´����Ľڵ�
		pnode = pnode->next;           //�õ�ǰ����Ľڵ�ָ������һ���ڵ��ƶ���������ող�����½ڵ�
	}
	
	m_ptailNode = pnode;
	return *this;
}

#ifndef _CHANGE_WAY_
data_t& DoubleList::operator [](int index)
{
	assert(index >= 0 && index < m_length);
	
	Node *pnode = m_pheadNode->next;
	while(index--)
	{
		pnode = pnode->next;
	}
	
	return pnode->data;
}
#else
data_t& DoubleList::operator [](int index)
{
	assert(index >= 0 && index < m_length);
	
	Node *pnode = m_pheadNode;      //���ֻ�Ǹ��»���������нڵ�����ݣ���ô�ڵ�ָ�뼴���Դ�ͷ���λ�ÿ�ʼ������Ҳ���Դ�ͷ����ĵ�һ��
	while(pnode->next != nullptr)   //�ڵ�λ�ÿ�ʼ��������Ϊͷ����������е�����û�����壬����һ���ͷ����ĵ�һ���ڵ�λ�ÿ�ʼ������
	{
		pnode = pnode->next;
		if(index-- == 0)
		{
			break;
		}
	}
	
	return pnode->data;
}
#endif

#ifndef _CHANGE_WAY_
void DoubleList::init(int size,const data_t data)
{
	if(size < 1)
	{
		cout<<"init warn: size is less than one"<<endl;
		return ;
	}
	
	clear();            //��˫�������еĽڵ���գ�ֻ����ͷ��㡣
	m_length = size;
	
	while(size--)       //ÿ�β����µĽڵ�ʱ����ͷ����һ��λ�ò���
	{
		Node *pnewNode = new Node;
		pnewNode->prev = m_pheadNode;       //�´����ڵ��ǰ��ָ��ͷ���
		pnewNode->data = data;
		pnewNode->next = m_pheadNode->next;   //�´����ڵ�ĺ������棬ͷ������������
		
		if(m_pheadNode->next != nullptr)
		{
			m_pheadNode->next->prev = pnewNode;
		}
		m_pheadNode->next = pnewNode;      //ͷ���ĺ���ָ���´����Ľڵ�
		
		if(m_length == size + 1)
			m_ptailNode = pnewNode;      //�´����Ľڵ������ͷ�������β���Ļ�����ô��һ��������½��ڵ����β�ڵ㡣
	}
}
#else
void DoubleList::init(int size,const data_t data)
{
	if(size < 1)
	{
		cout<<"init warn: size is less than one"<<endl;
		return ;
	}
	
	clear();            //��˫�������еĽڵ���գ�ֻ����ͷ��㡣
	m_length = size;
	
	Node *pnode = m_pheadNode;     //���Ҫ��ɾ�����еĽڵ㣬��ô�ڵ�ָ������ͷ���λ�ÿ�ʼ������
	while(size--)           //ÿ�β����µĽڵ�ʱ�����������һ���ڵ�������
	{
		Node *pnewNode = new Node;
		pnewNode->prev = pnode;      //�´����ڵ��ǰ��ָ�����������һ���ڵ�
		pnewNode->data = data;
		pnewNode->next = nullptr;   //�´����Ľڵ�û�к�����ֻ��ǰ��
		
		pnode->next = pnewNode;      //���������һ���ڵ�ĺ���ָ���´����Ľڵ�
		pnode = pnode->next;        //������Ľڵ�ָ���������е���һ���ڵ��ƶ���������ող�����½ڵ�
	}
	
	m_ptailNode = pnode;
}
#endif

bool DoubleList::empty()
{
#ifndef _CHANGE_WAY_
	return m_pheadNode->next == nullptr ? true : false;
#else
	return m_pheadNode->next == nullptr;      //��Ϊ���캯����һ�����m_pheadָ�������ڴ�ռ䣬����ʹ��m_pheadָ��ǰ����Ҫ���пմ���
#endif
}

int DoubleList::length()
{
	return m_length;
}

void DoubleList::append(const data_t data)
{	
	Node *pnewNode = new Node;       //�����µĽڵ㣬�������ʼ��
	pnewNode->prev = m_ptailNode;
	pnewNode->data = data;
	pnewNode->next = nullptr;
	
	m_ptailNode->next = pnewNode;      //���´����Ľڵ����ԭ����������
#ifndef _CHANGE_WAY_
	m_ptailNode = m_ptailNode->next;
#else
	m_ptailNode = pnewNode;     //��β�ڵ�����Ϊ��׷�ӵĽڵ�
#endif

	m_length++;
}

void DoubleList::prepend(const data_t data)
{
	Node *pnewNode = new Node;
	pnewNode->prev = m_pheadNode;
	pnewNode->data = data;
	pnewNode->next = m_pheadNode->next;
	
	if(m_length == 0)      //���׷�ӽڵ���ǰ������Ϊ�գ���ô������Ľڵ����β�ڵ�
	{
		m_ptailNode = pnewNode;
	}
	
	if(m_pheadNode->next != nullptr)
	{
		m_pheadNode->next->prev = pnewNode;
	}
	m_pheadNode->next = pnewNode;
	++m_length;
}

#ifndef _CHANGE_WAY_
bool DoubleList::insert(int pos,const data_t data)
{
	if(pos < 0 || pos > m_length)
		return false;

#ifndef _CHANGE_WAY_
	bool isInsertAtTail = (pos == m_length) ? true : false;  //���ֻ��Ҫ����������������boolֵʱ��?��:����ʡ�Բ�д
#else
	bool isInsertAtTail = (pos == m_length);
#endif
	
	Node *pnode = m_pheadNode;   //���Ҫ��ɾ�����еĽڵ㣬��ô�ڵ�ָ������ͷ���λ�ÿ�ʼ������
	while(pos--)
	{
		pnode = pnode->next;      //���ڵ�ָ���ƶ���Ҫ����λ�õ�ǰһ���ڵ��ϡ�
	}
	
	Node *pnewNode = new Node;
	pnewNode->prev = pnode;
	pnewNode->data = data;
	pnewNode->next = pnode->next;
	
	if(pnode->next != nullptr)
	{
		pnode->next->prev = pnewNode;    //˫�������뵥������ͬ����ɾ�ڵ�ʱ������Ҫ��������������⣬Ҳ��Ҫ����ǰ���������⡣
	}
	pnode->next = pnewNode;
	
	if(isInsertAtTail)      //����²���Ľڵ�Ϊ��˫�������β�����룬��ôβ�ڵ�ָ����Ҫ�ƶ����²���Ľڵ��ϡ�
	{                       //����²���Ľڵ㲻�Ǵ������β�����룬��ôm_ptailNodeָ�벻��Ҫ���κ��ƶ���
		m_ptailNode = m_ptailNode->next;
	}
	
	m_length++;
	return true;
}
#else
bool DoubleList::insert(int pos,const data_t data)
{
	if(pos < 0 || pos > m_length)
		return false;

	int count = pos;             //����һ���µ�count��������Ϊ����insert���������pos�������ֲ��䡣
	Node *pnode = m_pheadNode;   //���Ҫ��ɾ�����еĽڵ㣬��ô�ڵ�ָ������ͷ���λ�ÿ�ʼ������
	while(count--)
	{
		pnode = pnode->next;      //���ڵ�ָ���ƶ���Ҫ����λ�õ�ǰһ���ڵ��ϡ�
	}
	
	Node *pnewNode = new Node;
	pnewNode->prev = pnode;
	pnewNode->data = data;
	pnewNode->next = pnode->next;
	
	if(pnode->next != nullptr)
	{
		pnode->next->prev = pnewNode;    //˫�������뵥������ͬ����ɾ�ڵ�ʱ������Ҫ��������������⣬Ҳ��Ҫ����ǰ���������⡣
	}
	pnode->next = pnewNode;
	
	if(pos == m_length)     //����²���Ľڵ�Ϊ��˫�������β�����룬��ôβ�ڵ�ָ����Ҫ�ƶ����²���Ľڵ��ϡ�
	{                       //����²���Ľڵ㲻�Ǵ������β�����룬��ôm_ptailNodeָ�벻��Ҫ���κ��ƶ���
		m_ptailNode = pnewNode;
	}
	
	m_length++;
	return true;
}
#endif

#ifndef _CHANGE_WAY_
bool DoubleList::remove(int pos)
{
	if(pos < 0 || pos >= m_length)
		return false;
	
	if(pos == m_length - 1)
	{
		m_ptailNode = m_ptailNode->prev;     //����Ƴ���λ����β�ڵ㣬��ôβ�ڵ�ָ����Ҫ��ǰͷ��㷽���ƶ�һ���ڵ�
		                                    //����Ƴ���λ�ò���β�ڵ㣬��ôm_ptailNodeָ�벻��Ҫ���κ��ƶ���
		delete m_ptailNode->next;
		m_ptailNode->next = nullptr;
		
		--m_length;
		return true;
	}
	
	Node *pnode = m_pheadNode;
	while(pos--)
	{
		pnode = pnode->next;     //���ڵ�ָ���ƶ���Ҫɾ��λ�õ�ǰһ���ڵ���
	}
	
	Node *qnode = pnode->next;    //��ȡҪɾ���Ľڵ�;
	pnode->next = qnode->next;    //��Ҫɾ���Ľڵ�������жϿ�
	if(qnode->next != nullptr)    //˫�������뵥������ͬ����ɾ�ڵ�ʱ������Ҫ��������������⣬Ҳ��Ҫ����ǰ���������⡣
	{
		qnode->next->prev = pnode;
	}
	
	delete qnode;
	qnode = nullptr;   //��qnodeָ���ò���Ϊ��ָ�붼���ԣ���Ϊ�������Ͼ�Ҫreturn�ˣ�qnodeָ����ȻҲ�������ټ����������ˡ�
	
	m_length--;
	return true;
}
#else
bool DoubleList::remove(int pos)
{
	if(pos < 0 || pos >= m_length)
		return false;
	
	if(pos == m_length - 1)
	{
		m_ptailNode = m_ptailNode->prev;     //����Ƴ���λ����β�ڵ㣬��ôβ�ڵ�ָ����Ҫ��ǰͷ��㷽���ƶ�һ���ڵ�
		                                    //����Ƴ���λ�ò���β�ڵ㣬��ôm_ptailNodeָ�벻��Ҫ���κ��ƶ���
		delete m_ptailNode->next;
		m_ptailNode->next = nullptr;
		
		m_length--;
		return true;
	}
	
	Node *pnode = m_pheadNode;
	while(pos--)
	{
		pnode = pnode->next;     //���ڵ�ָ���ƶ���Ҫɾ��λ�õ�ǰһ���ڵ���
	}
	
	Node *qnode = pnode->next->next;    //����Ҫɾ���ڵ�ĺ���
	if(qnode != nullptr)
	{
		qnode->prev = pnode;   //˫�������뵥������ͬ����ɾ�ڵ�ʱ������Ҫ��������������⣬Ҳ��Ҫ����ǰ���������⡣
	}
	
	delete pnode->next;
	pnode->next = qnode;      
	
	--m_length;
	return true;
}
#endif

#ifndef _CHANGE_WAY_
bool DoubleList::remove(const data_t data)
{
	if(m_length < 1)
		return false;
	
	bool ret = false;
	Node *pnode = m_pheadNode;
	while(pnode->next != nullptr)     //���������������������date�Ľڵ㶼ɾ������
	{
		if(pnode->next->data == data)
		{
			if(pnode->next == m_ptailNode)    //����Ƴ��Ľڵ������β�ڵ㣬��ôβ�ڵ�ָ������ǰ�ƶ�һ���ڵ㡣
			{
				m_ptailNode = m_ptailNode->prev;
			}
			
			Node *qnode = pnode->next->next;     //������Ҫɾ���ڵ�ĺ���
			if(qnode != nullptr)
			{
				qnode->prev = pnode;  //�Ƴ��ڵ�ʱ�����������нڵ��ǰ����������
			}
			
			delete pnode->next;
			pnode->next = qnode;
			
			--m_length;
			ret = true;
		}
		else
		{
			pnode = pnode->next;
		}
	}

	return ret;
}
#else
bool DoubleList::remove(const data_t data)
{
	if(m_length < 1)
		return false;
	
	Node *pnode = m_pheadNode;
	Node *qnode = nullptr;
	while(pnode->next != nullptr)    //ֻɾ��������ֵ����date�ĵ�һ���ڵ㡣
	{
		qnode = pnode->next;     //��ȡpnode�ڵ�ָ�뵱ǰλ�õ���һ���ڵ�λ�á�
		if(qnode->data != data)
		{
			pnode = pnode->next;
			continue;
		}
		
		if(qnode == m_ptailNode)
		{
			m_ptailNode = pnode;
		}
		
		pnode->next = qnode->next;
		if(qnode->next != nullptr)
		{
			qnode->next->prev = pnode;     //�Ƴ��ڵ�ʱ�����������нڵ��ǰ����������
		}
		
		delete qnode;
		// qnode = nullptr;    //��qnodeָ���ò���Ϊ��ָ�붼���ԣ���Ϊ�������Ͼ�Ҫreturn�ˣ�qnodeָ����ȻҲ�������ټ����������ˡ�
		
		m_length--;
		return true;
	}
	
	return false;
}
#endif

#ifndef _CHANGE_WAY_
void DoubleList::popFront()
{
	if(m_length < 1)   //������û�����ݣ���ȻҲ�����ٵ����ڵ���
		return ;
	
	if(m_length == 1)   //���˫��������ֻ��һ���ڵ�ʱ����ô��������ǰ��Ľڵ�ֵ��β�ڵ�ָ����Ҫ��ǰ�ƶ���ͷ���λ���ϡ�
	{
		m_ptailNode = m_ptailNode->prev;
	}
	
	Node* pnode = m_pheadNode->next;   //��ȡҪ�����Ľڵ�
	m_pheadNode->next = pnode->next;
	if(pnode->next != nullptr)
	{
		pnode->next->prev = m_pheadNode;     //�Ƴ��ڵ�ʱ�����������нڵ��ǰ����������
	}
	
	delete pnode;
	m_length--;
}
#else
void DoubleList::popFront()
{
	if(m_length < 1)   //������û�����ݣ���ȻҲ�����ٵ����ڵ���
		return ;

	if(m_length == 1)   //���˫��������ֻ��һ���ڵ�ʱ����ô��������ǰ��Ľڵ�ֵ��β�ڵ�ָ����Ҫ��ǰ�ƶ���ͷ���λ���ϡ�
	{
		m_ptailNode = m_pheadNode;
	}
	
	Node* pnode = m_pheadNode->next->next;   //��ȡҪ�����ڵ�ĺ���
	if(pnode != nullptr)
	{
		pnode->prev = m_pheadNode;     //�Ƴ��ڵ�ʱ�����������нڵ��ǰ����������
	}
	
	delete m_pheadNode->next;
	m_pheadNode->next = pnode;
	--m_length;
}
#endif

void DoubleList::popBack()
{
	if(m_length < 1)   //������û�����ݣ���ȻҲ�����ٵ����ڵ���
		return ;

	m_ptailNode = m_ptailNode->prev;   //��Ϊβ�ڵ�ᱻ�����������Ƚ�β�ڵ�ָ����ǰ�ƶ�һ���ڵ㡣
	
	delete m_ptailNode->next;
	m_ptailNode->next = nullptr;   //��β�ڵ��Ƴ��Ժ���ǰ�ĵ����ڶ����ڵ�ͱ�Ϊ��β�ڵ㣬���Բ���Ҫ�ٴ���β�ڵ��ǰ���������⡣
	m_length--;
}

#ifndef _CHANGE_WAY_
void DoubleList::clear()       //clear()����������У����Բ���ÿɾ��һ���ڵ㣬��������ڵ��ǰ�����⡣��
{                              //��Ϊ��պ������о�û�нڵ��ˣ�Ҳ�Ͳ����ڽڵ�ǰ�����ʵ������ˡ�
	if(m_length < 1)
		return ;
	
	Node *pnode = m_pheadNode->next;
	Node *qnode = nullptr;
	while(pnode != nullptr)    //��ǰ������������˫�������б���Ľڵ�
	{
		qnode = pnode->next;    //��pnodeָ��ָ��Ľڵ㱻����ǰ����pnode�ڵ�ĺ�����ַ���浽qnode�ڵ�ָ���С�
		delete qnode;
		pnode = qnode;
	}
	
	m_ptailNode = m_pheadNode;
	m_pheadNode->next = nullptr;
	m_length = 0;
}
#else
void DoubleList::clear()     //clear()����������У����Բ���ÿɾ��һ���ڵ㣬��������ڵ��ǰ
{                            //��Ϊ��պ������о�û�нڵ��ˣ�Ҳ�Ͳ����ڽڵ�ǰ�����ʵ������ˡ�
	if(m_length == 0)
		return ;
	
	Node *pnode = m_ptailNode;
	Node *qnode = nullptr;
	while(pnode->prev != nullptr)       //�Ӻ���ǰ��������˫�������б���Ľڵ�
	{
		qnode = pnode->prev;
		delete pnode;
		pnode = qnode;
	}
	
	m_ptailNode = m_pheadNode;
	m_pheadNode->next = nullptr;
	m_length = 0;
}
#endif

data_t& DoubleList::front()
{
	Node *pnode = m_pheadNode->next;   //���ֻ�Ǹ��»���������нڵ�����ݣ���ô�ڵ�ָ�뼴���Դ�ͷ���λ�ÿ�ʼ������Ҳ���Դ�ͷ����ĵ�
	if(pnode == nullptr)               //�ڵ�λ�ÿ�ʼ��������Ϊͷ����������е�����û�����壬����һ���ͷ����ĵ�һ���ڵ�λ�ÿ�ʼ������
	{
		cout<<"front error: double link list is empty"<<endl;
		exit(-1);
	}
	
	return pnode->data;
}

data_t& DoubleList::back()
{
	if(m_length == 0)
	{
		cout<<"back error: double link list is empty"<<endl;
		exit(-1);
	}
	
	return m_ptailNode->data;
}

//������Ƶ�����ʽ�����������⣬�������봦��ͷ���ֵ�����
data_t DoubleList::at(int index)
{
	assert(index >= 0 && index < m_length);
	
	Node *pnode = m_pheadNode->next;   //���ֻ�Ǹ��»���������нڵ�����ݣ���ô�ڵ�ָ�뼴���Դ�ͷ���λ�ÿ�ʼ������Ҳ���Դ�ͷ����ĵ�
	while(index--)                     //�ڵ�λ�ÿ�ʼ��������Ϊͷ����������е�����û�����壬����һ���ͷ����ĵ�һ���ڵ�λ�ÿ�ʼ������
	{
		pnode = pnode->next;
	}
	
	return pnode->data;
}

#ifndef _CHANGE_WAY_
int DoubleList::find(const data_t data)
{
	if(m_length == 0)    //�������Ϊ�վͲ����ٲ�����
		return -1;
	
	int index = 0;
	Node *pnode = m_pheadNode->next;
	while(pnode != nullptr)
	{
		if(pnode->data == data)
		{
			return index;
		}
		++index;
		pnode = pnode->next;
	}
	
	return -1;
}
#else
int DoubleList::find(const data_t data)
{
	if(m_length == 0)    //�������Ϊ�վͲ����ٲ�����
		return -1;
	
	Node *pnode = m_pheadNode->next;
	for(int index=0;pnode != nullptr;++index)
	{
		if(pnode->data == data)
		{
			return index;         //��ȡ�����е�һ�����ҵ������������data�Ľڵ�λ��
		}
		pnode = pnode->next;
	}
	
	return -1;
}
#endif

bool DoubleList::replace(int pos,const data_t data)
{
	if(pos < 0 || pos >= m_length)
	{
		return false;
	}
	
	Node *pnode = m_pheadNode->next;
	while(pos--)
	{
		pnode = pnode->next;
	}
	
	pnode->data = data;
	return true;
}

bool DoubleList::replace(const data_t src,const data_t dst)
{
	if(m_length < 1)
		return false;
	
	bool result = false;
	Node *pnode = m_pheadNode->next;
	for(;pnode != nullptr;pnode = pnode->next)
	{
		if(pnode->data == src)
		{
			pnode->data = dst;
			result = true;
		}
	}
	
	return result;
}

#ifndef _CHANGE_WAY_
void DoubleList::reverse()   //β�ڵ���ͷ��㷽�������ƶ����Ӷ�ʵ�ֵ�������
{
	if(m_length < 2)
		return ;
	
	Node *pnode = nullptr;            
	Node *qnode = m_pheadNode;
	Node* const ptailNode = m_pheadNode->next;     //���浹��ǰ������ͷ����ĵ�һ���ڵ㣬��Ϊ���������Ժ󽫱�Ϊβ�ڵ㡣
	for(int i=m_length -1;i>0;--i)
	{
		pnode = m_ptailNode;                //��pnode�ڵ�ָ���ƶ���β�ڵ���
		m_ptailNode = m_ptailNode->prev;    //��β�ڵ�ָ����ǰ�ƶ�һ���ڵ�
		m_ptailNode->next = nullptr;        //��ǰ�ĵ����ڶ����ڵ��Ϊ��β�ڵ㣬������ǰ��β�ڵ��˫�������жϿ�����Ϊ�����ڵ㡣
		
		pnode->next = qnode->next;
		pnode->prev = qnode;
		
		if(qnode->next != nullptr)
		{
			qnode->next->prev = pnode;
		}
		qnode->next = pnode;       //��β�ڵ��ƶ���ͷ�����һ���ڵ�λ����
		qnode = qnode->next;       //��qnode�ڵ�ָ���ƶ����ղ���Ľڵ���
	}
	
	m_ptailNode = ptailNode;
}
#elif 1
void DoubleList::reverse()     //ͷ����ĵ�һ���ڵ���β�ڵ㷽���ƶ��Ӷ�ʵ�ֵ�������
{
	if(m_length < 2)     //������С��2���ڵ㣬�Ͳ��õ����ˡ���Ϊֻ��һ���ڵ�Ļ��������Ժ���ԭ��
		return ;
	
	Node *pnode = nullptr;
	Node* const qnode = m_ptailNode;     //qnode�ڵ�ָ����Զ��ǵ�����ǰ��β�ڵ�λ��
	m_ptailNode = m_pheadNode->next;     //����ǰ�ĵ�һ���ڵ㣬�ڵ����ͱ�Ϊ��β�ڵ�
	while(qnode->prev != m_pheadNode)
	{
		pnode = m_pheadNode->next;
		m_pheadNode->next = pnode->next;
		if(pnode->next != nullptr)
		{
			pnode->next->prev = m_pheadNode;
		}
		
		pnode->next = qnode->next;
		pnode->prev = qnode;
		qnode->next = pnode;
	}
}
#else
void DoubleList::reverse()    //ֻ����������ǰ��ڵ��е������򣬵��ǲ����ƶ��ڵ����������㷨ֻ��˫�����������ɣ�
{                             //��������û��ǰ��ָ�룬�����޷�ʵ�ָ��㷨������������˳�˫����������ڵ��������һ��ǰ��ָ������ơ�
	if(m_length < 2)
		return ;
	
	Node *pnode = m_ptailNode;         //���˫�������б�����β�ڵ��Աָ�룬��ô�Ϳ��Ժܷ����ȡβ�ڵ�λ�ã�
	Node *qnode = m_pheadNode->next;   //�������ٴ�ͷ��㿪ʼ���α���������ȡβ�ڵ��λ�á������˫�������б���β�ڵ��Աָ��ĺô���
	for(int i = m_length/2;i>0;--i)
	{
		swap(qnode->data,pnode->data);
		qnode = qnode->next;
		pnode = pnode->prev;
	}
}
#endif

#ifndef _CHANGE_WAY_
void DoubleList::sort(SortType sortType)   //ð������
{
	if(m_length < 2)    //������С��2���ڵ㣬�Ͳ��������ˡ���Ϊֻ��һ���ڵ�Ļ��������Ժ���ԭ��
		return ;
	
	if(sortType != INCREASE && sortType != DECREASE)
	{
		fputs("sort warn: sortType is illegal\n",stdout);
		return ;
	}
	
	Node *pnode = nullptr;
	Node *qnode = nullptr;
	for(int i=0;i<m_length;++i)
	{
		pnode = m_pheadNode->next;
		qnode = pnode->next;
		for(int j=1;j<m_length - i;++j)
		{
			if(sortType == INCREASE)
			{
				if(pnode->data > qnode->data)
				{
					swap(pnode->data,qnode->data);  //ð������ʱ��ֻ�������������ڵ��������е����ݣ�������Ҫ�����������ڵ������ڵ�
				}
			}
			else
			{
				if(pnode->data < qnode->data)
				{
					swap(pnode->data,qnode->data);
				}
			}
			qnode = qnode->next;
			pnode = pnode->next;
		}
	}
}
#else
void DoubleList::sort(SortType sortType)    //ѡ������
{
	if(m_length < 2)    //������С��2���ڵ㣬�Ͳ��������ˡ���Ϊֻ��һ���ڵ�Ļ��������Ժ���ԭ��
		return ;
	
	if(sortType != INCREASE && sortType != DECREASE)
	{
		fputs("sort warn: sortType is illegal\n",stdout);
		return ;
	}
	
	Node *pnode = nullptr;
	Node *qnode = nullptr;     //qnode�ڵ�ָ������ָ�������У�������ֵ��������С�Ľڵ�
	for(int i=0;i<m_length-1;++i)
	{
		qnode = m_pheadNode->next;      //ÿ�α�������ʱ����Ĭ����������������С�Ľڵ�λ��Ϊͷ�����һ���ڵ��λ��
		pnode = qnode->next;
		for(int j =1;j<m_length - i;++j)
		{
			if(sortType == INCREASE)
			{
				if(qnode->data < pnode->data)
				{
					qnode = pnode;        //��ȡ��������ֵ���Ľڵ�λ��
				}
			}
			else
			{
				if(qnode->data > pnode->data)
				{
					qnode = pnode;        //��ȡ��������ֵ��С�Ľڵ�λ��
				}
			}
			
			if(j < m_length - i -1)
				pnode = pnode->next;
		}
		swap(qnode->data,pnode->data);
	}
}
#endif

#ifndef _CHANGE_WAY_
void DoubleList::show()const
{
	if(m_length < 1)     //���������һ���ڵ�Ҳû�У���ô��û����Ҫ��ʾ�������ˣ�ֱ���˳�
		return ;
	
	Node *pnode = m_pheadNode->next;
	for(;pnode != nullptr;pnode = pnode->next)
	{
		cout<<pnode->data<<" ";
	}
	cout<<endl;
}
#else
void DoubleList::show()const
{
	if(m_length < 1)     //���������һ���ڵ�Ҳû�У���ô��û����Ҫ��ʾ�������ˣ�ֱ���˳�
		return ;
	
	Node *pnode = m_pheadNode;
	for(int i=0;i<m_length;++i)
	{
		pnode = pnode->next;
		cout<<pnode->data<<" ";
	}
	cout<<endl;
}
#endif

void DoubleList::rshow()const
{
	if(m_length < 1)
		return ;
	
	Node *pnode = m_ptailNode;
	for(;pnode->prev != nullptr;pnode = pnode->prev)
	{
		cout<<pnode->data<<" ";
	}
	cout<<endl;
}