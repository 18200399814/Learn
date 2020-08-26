#include <cstdio>
#include <cstdlib>
#include <iostream>

#define _WARNNING_      //����������Window�����¸����ױ�����Linux�����¸���������������Linux���ڴ����û��Windows��ȫ��
// #undef _WARNNING_

#define _ERROR_
#undef _ERROR_

using namespace std;

//Sampleû����ʾ��д����������������������Ĭ�ϵ�����������
class Sample
{
public:
	explicit Sample(int data):data(data){cout<<"Sample constructor"<<endl;}
	Sample(const Sample& other):data(other.data){cout<<"Sample copy constructor"<<endl;}
	
	void setData(const int data){this->data = data;}
	int getData()const{return data;}

	void show()const{cout<<"data ="<<data<<endl;}
private:
	int data;
};

//Test������ʾ��������������delete Test�����ʱ���Զ����������������ͷ�����Դ��
class Test
{
public:
	explicit Test(double value):value(value){cout<<"Test constructor"<<endl;}
	Test(const Test& other):value(other.value){cout<<"Test copy constructor"<<endl;}
	virtual ~Test(){value = 10;cout<<"Test destructor"<<endl;}

	void setValue(const double value){this->value = value;}
	double getValue()const{return value;}

	void print()const{cout<<"value ="<<value<<endl;}
private:
	double value;
};

static void free_pointer();
static void delete_pointer();

static void free_wild_pointer();
static void delete_wild_pointer();

static void free_sample();
static void delete_sample();

static void free_test();
static void delete_test();

int main()
{
	free_pointer();
	delete_pointer();
	
	free_wild_pointer();
	delete_wild_pointer();
	
	free_sample();
	delete_sample();
	
	free_test();
	delete_test();
	
	return 0;
}

void free_pointer()
{
	int *p = (int*)malloc(sizeof(int));    //malloc����������ڴ�ʱ�����ܻ�ʧ�ܣ�������Ҫ���пմ���
	if(p == NULL)
	{
		printf("free_pointer warn: p malloc failed\n");
		return ;
	}
	printf("free_pointer: *p =%d, address: %p\n",*p,p);
	
	*p = 10;
	printf("free_pointer: *p =%d, address: %p\n",*p,p);
	
	free(p);      //free�Ժ�pָ��ͱ�Ϊ��Ұָ�롣����һ��free�Ժ���Ҫ��ָ����ΪNULL���Է�ֹҰָ��ĳ��֡�
	printf("free_pointer: *p =%d, address: %p\n",*p,p);    //Ұָ�������ȡ�����򲻻����������ȡ�������������塣

#ifdef _WARNNING_
	*p = 11;      //Ұָ�����д�룬�����ż�ֱ�����������ÿ�ζ��������ż���������
	printf("free_pointer: *p =%d, address: %p\n",*p,p);

	//Windows�е�Ұָ����free���������ʻ��������Linux�е�Ұָ����free�����ֻ��С���ʻ������
	free(p);     //��һ���ǿ�ָ��free��Σ����δ���塣����ʱ���ᱨ���п��ܳ�������ʱ����
	printf("free_pointer: *p =%d, address: %p\n",*p,p);    //malloc�������ڴ�����free�����������ż�Ա�����
	
	*p = 12;
	printf("free_pointer: *p =%d, address: %p\n",*p,p);
#endif
	
	p = NULL;      //NULLָ�����free�����ҳ��򲻻���������Կ�ָ��free��Σ����ᱨ��
	free(p);       //C�����ж����˿��Զ��free NULLָ�롣

#ifdef _ERROR_
	printf("free_pointer: *p =%d, address: %p\n",*p,p);     //��NULLָ����з��ʱ��Ա�����
#endif
}

void delete_pointer()
{
	int *p = new int(20);
	cout<<"delete_pointer: *p ="<<*p<<", address: "<<p<<endl;
	
	*p = 21;
	cout<<"delete_pointer: *p ="<<*p<<", address: "<<p<<endl;
	
	delete p;       //delete�Ժ�ָ��p�ͱ�Ϊ��Ұָ�롣����һ��delete�Ժ���Ҫ��ָ����Ϊnullptr���Է�ֹҰָ��ĳ��֡�
	cout<<"delete_pointer: *p ="<<*p<<", address: "<<p<<endl;    //Ұָ�������ȡ�����򲻻����������ȡ�������������塣

#ifdef _WARNNING_
	*p = 22;        //Ұָ�����д�룬�����ż�ֱ���
	cout<<"delete_pointer: *p ="<<*p<<", address: "<<p<<endl;

	//Windows�е�Ұָ����delete���������ʻ��������Linux�е�Ұָ����delete�����ֻ��С���ʻ������
	delete p;       //new�����Ķ��ڴ�����delete���������Ǳ��Ա�����������ÿ�ζ��������ż�������
	cout<<"delete_pointer: *p ="<<*p<<", address: "<<p<<endl;
	
	*p = 23;
	cout<<"delete_pointer: *p ="<<*p<<", address: "<<p<<endl;
#endif

	p = nullptr;
	delete p;       //nullptrָ�����delete�����ҳ��򲻻������C++���Զ����˿��Զ��delete nullptrָ�롣

#ifdef _ERROR_
	cout<<"delete_pointer: *p ="<<*p<<", address: "<<p<<endl;     //��NULLָ����з��ʱ��Ա�����
#endif
}

void free_wild_pointer()
{
	double *p = (double*)malloc(sizeof(double));
	if(p == NULL)                    ////malloc����������ڴ�ռ���ܻ�ʧ�ܣ�������Ҫ���пմ���
	{
		printf("free_wild_pointer warn: p malloc failed\n");
		return ;
	}
	double *q = p;            //ָ��p��qָ��ͬһƬmalloc���ٳ����Ķѵ�ַ��
	printf("free_wild_pointer: *p =%f, address: %p , *q =%f, address: %p\n",*p,p,*q,q);
	
	*q = 30.01;
	printf("free_wild_pointer: *p =%f, address: %p , *q =%f, address: %p\n",*p,p,*q,q);
	
	free(p);     //ָ��P��malloc���ٳ����Ķ��ڴ�ռ��ͷŵ��ˡ�
	p = NULL;    //��Pָ����Ϊ�˿�ָ�룬����ʱqָ���Ϊ��Ұָ�룬����ָ����ǰmalloc�����ĵ�ַ��
	printf("free_wild_pointer: *q =%f, address: %p\n",*q,q);    //Ұָ�������ȡ�����򲻻����������ȡ�������������塣

#ifdef _WARNNING_
	*q = 31.01;     //������ǰmalloc���ٵĶ��ڴ�ռ��Ѿ����ͷŵ��ˡ����Դ�ʱ��qָ��ָ����Ѿ���������ַ��
	printf("free_wild_pointer: *q =%f, address: %p\n",*q,q);     //���������ڴ��ַ��д����Ϊ�����ܻ�������������

	free(q);        //��һ��ָ�������ڴ��Ұָ����free����Ϊδ���壬���ܻ�������������
	printf("free_wild_pointer: *q =%f, address: %p\n",*q,q);
	
	*q = 32.01;
	printf("free_wild_pointer: *q =%f, address: %p\n",*q,q); 
#endif

	q = NULL;
	free(p);     //pָ��Ϊ��ָ�룬���Զ��free
	
#ifdef _ERROR_
	printf("free_wild_pointer: *q =%f, address: %p\n",*q,q);    //��һ����ָ����з��ʣ�����ض��������
#endif
}

void delete_wild_pointer()
{
	double *p = new double(40.01);
	double *q = p;             //ָ��p��qָ��ͬһƬnew���ٳ����Ķ��ڴ�ռ䡣
	cout<<"delete_wild_pointer: *p ="<<*p<<", address: "<<p
		<<" , *q ="<<*q<<", address"<<q<<endl;
	
	*p = 41.01;
	cout<<"delete_wild_pointer: *p ="<<*p<<", address: "<<p
		<<" , *q ="<<*q<<", address: "<<q<<endl;
	
	delete p;          //ָ��p��new�����Ķѿռ�delete�Ժ�ָ��p��q��Ϊ��Ұָ�롣
	p = nullptr;       //��Pָ����Ϊ�˿�ָ�룬����ʱqָ���Ϊ��Ұָ�룬����ָ����ǰnew�����ĵ�ַ��
	cout<<"delete_wild_pointer: *q ="<<*q<<", address: "<<q<<endl;    //Ұָ�������ȡ�����򲻻����������ȡ�������������塣

#ifdef _WARNNING_
	*q = 42.01;        //������ǰnew���ٵĶ��ڴ�ռ��Ѿ����ͷŵ��ˡ����Դ�ʱ��qָ��ָ����Ѿ���������ַ��
	cout<<"delete_wild_pointer: *q ="<<*q<<", address: "<<q<<endl;   //Ұָ�����д�룬�����ż�ֱ���

	delete q;       //ָ������delete���Σ���Ϊδ���壬������ܻ������
	cout<<"delete_wild_pointer: *q ="<<*q<<", address: "<<q<<endl;
	
	*q = 43.01;
	cout<<"delete_wild_pointer: *q ="<<*q<<", address: "<<q<<endl;
#endif

	q = nullptr;
	delete q;       //nullptrָ�����delete�����ҳ��򲻻������C++���Զ����˿��Զ��delete nullptrָ�롣

#ifdef _ERROR_
	cout<<"delete_wild_pointer: *q ="<<*q<<", address: "<<q<<endl;    //NULLָ�벻�ܷ��ʡ�
#endif
}

void free_sample()
{
	Sample *psample = (Sample*)malloc(sizeof(Sample));     //mallocֻ�ǿ���һƬ�ڴ�ռ䣬������ù��캯�������ʼ����
	if(psample == NULL)                          //malloc����������ڴ�ռ���ܻ�ʧ�ܣ�������Ҫ���пմ���
	{
		printf("free_sample warn: psample malloc failed\n");
		return ;
	}
	printf("free_sample: *data =%d, address: %p\n",psample->getData(),psample);
	
	psample->setData(50);
	psample->show();
	
#ifdef _ERROR_
	printf("free_sample: *data =%d, address: %p\n",psample->data,psample);     //��˽�г�Ա����ֱ�ӷ��ʣ����벻ͨ����
#endif

	free(psample);       //free����ֻ���ͷ��ڴ棬�����������������free�Ժ�psampleָ���Ϊ��Ұָ�롣
	printf("free_sample: *data =%d, address: %p\n",psample->getData(),psample);     //Ұָ�������ȡ�����򲻻����������ȡ�������������塣
	
#ifdef _WARNNING_
	psample->setData(51);     //Ұָ�����д�룬�������ܻ������
	psample->show();
	
	free(psample);    //ָ����free��Ϊδ���壬���ܻᵼ�����������
	printf("free_sample: *data =%d, address: %p\n",psample->getData(),psample); 
	
	psample->setData(52);
	psample->show();
#endif
	
	psample = NULL;
	free(psample);      //NULLָ����free������������С�C���Թ涨NULLָ����Զ��free��
	
#ifdef _ERROR_
	printf("free_sample: *data =%d, address: %p\n",psample->getData(),psample);      //NULLָ�벻�ܷ��ʡ�
#endif
}

void delete_sample()
{
	Sample *psample = new Sample(60);    //new���㲻������������ڴ�ռ䣬�����������ڴ�ռ�ɹ�����ù��캯�������ʼ����
	cout<<"delete_sample: data ="<<psample->getData()<<", address: "<<psample<<endl;   //new����ʧ���Ժ󣬻��׳��쳣�����Բ���Ҫ�����пմ���
	
	psample->setData(61);
	psample->show();

#ifdef _ERROR_
	cout<<"delete_sample: data ="<<psample->data<<", address: "<<psample<<endl;     //��˽�г�Ա����ֱ�ӷ��ʣ����벻ͨ����
#endif

	delete psample;       //delete���㲻�������ͷ��ڴ棬ͬʱ�����������������
	cout<<"delete_sample: data ="<<psample->getData()<<", address: "<<psample<<endl;

#ifdef _WARNNING_
	psample->setData(62);      //Ұָ�����д�룬�������ܻ������
	psample->show();
	
	delete psample;       //�����û��������������ôָ������delete���Σ�������ܻ������
	cout<<"delete_sample: data ="<<psample->getData()<<", address: "<<psample<<endl;
	
	psample->setData(63);
	psample->show();
#endif
	
	psample = nullptr;
	delete psample;         //pָ��Ϊ��ָ�룬���Զ��delete

#ifdef _ERROR_
	cout<<"delete_sample: data ="<<psample->getData()<<", address: "<<psample<<endl;   //NULLָ��������������
#endif
}

void free_test()
{
	Test *ptest = (Test*)malloc(sizeof(Test));   //mallocֻ�ǿ���һƬ�ڴ�ռ䣬������ù��캯�������ʼ����
	if(ptest == NULL)                            //malloc����������ڴ�ռ���ܻ�ʧ�ܣ�������Ҫ���пմ���
	{
		printf("free_test warn: ptest malloc failed\n");
		return ;
	}
	printf("free_test: value =%f, address: %p\n",ptest->getValue(),ptest);
	
	ptest->setValue(70.01);
	ptest->print();

#ifdef _ERROR_
	printf("free_test: value =%f, address: %p\n",ptest->value,ptest);     //��˽�г�Ա����ֱ�ӷ��ʣ����벻ͨ����
#endif

	free(ptest);     //free����ֻ���ͷ��ڴ棬�����������������free�Ժ�psampleָ���Ϊ��Ұָ�롣
	printf("free_test: value =%f, address: %p\n",ptest->getValue(),ptest);   //Ұָ�������ȡ�����򲻻����������ȡ�������������塣

#ifdef _WARNNING_
	ptest->setValue(71.01);    //Ұָ�����д�룬�������ܻ������
	ptest->print();
	
	free(ptest);     //ָ����free��Ϊδ���壬���ܻᵼ�����������
	printf("free_test: value =%f, address: %p\n",ptest->getValue(),ptest); 
	
	ptest->setValue(72.01);    //Ұָ�����д�룬�������ܻ������
	ptest->print();
#endif

	ptest = NULL;
	free(ptest);          //NULLָ����free������������С�C���Թ涨NULLָ����Զ��free��

#ifdef _ERROR_
	printf("free_test: value =%f, address: %p\n",ptest->getValue(),ptest); 	  //����NULLָ�룬���������
#endif
}

void delete_test()
{
	Test *ptest = new Test(80.01);    //new���㲻������������ڴ�ռ䣬�����������ڴ�ռ�ɹ�����ù��캯�������ʼ����
	cout<<"delete_test: value ="<<ptest->getValue()<<", address: "<<ptest<<endl;   //new����ʧ���Ժ󣬻��׳��쳣�����Բ���Ҫ�����пմ���
	
	ptest->setValue(81.01);
	ptest->print();

#ifdef _ERROR_
	cout<<"delete_test: value ="<<ptest->value<<", address: "<<ptest<<endl;     //��˽�г�Ա����ֱ�ӷ��ʣ����벻ͨ����
#endif

	delete ptest;       //delete���㲻�������ͷ��ڴ棬ͬʱ�����������������
	cout<<"delete_test: value ="<<ptest->getValue()<<", address: "<<ptest<<endl;

#ifdef _WARNNING_
	ptest->setValue(82.01);      //Ұָ�����д�룬�������ܻ������
	ptest->print();
#endif

#ifdef _ERROR_
	delete ptest;       //�������������������ôָ������delete���Σ�������������ΪҰָ���Ҳ�������������
	cout<<"delete_test: value ="<<ptest->getValue()<<", address: "<<ptest<<endl;
#endif

	ptest = nullptr;
	delete ptest;         //pָ��Ϊ��ָ�룬���Զ��delete

#ifdef _ERROR_
	cout<<"delete_test: value ="<<ptest->getValue()<<", address: "<<ptest<<endl;   //����NULLָ�룬���������
#endif
}