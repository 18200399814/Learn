//��C/C++����У���deleteһ��ָ���Ժ�ָ����ָ��Ķ��ڴ�ռ�㱻�ͷţ�ָ���ΪҰָ�롣
//��Ȼָ���Ѿ���Ч�����ںܶ������ָ����Ȼָ���Ѿ����ͷ��˵Ķ�̬�ڴ��ַ�������ڴ��ַ�е�����Ҳ��δ�������

//��deleteһ��ָ��ʱ������ϵͳ���ͷ�ָ��ָ��Ķ��ڴ�ռ䣬�Ա���һ��new��������ʱ������������ʹ����һƬ�ڴ�ռ䡣
//��ָ��ָ����ڴ����򲢲�����delete��ʱ����գ���Ϊ����ڴ�������ռ��CPU���ڡ���һ��ָ�뱻delete�Ժ�
//������һ��Σ��ָ�룬����ʹ�õĻ������һЩδ�����������Ҳ��Ϊʲôdeleteһ��ָ���Ժ�Ҫ���ϰ�����Ϊnullptr��ԭ��
//��Ϊ�˱�֤����ʹ�õ���һ����Ч��ָ�룬�����ǻ���ɲ���Ԥ֪�����Ұָ�롣

#include <cstdio>
#include <cstdlib>
#include <iostream>

#define _UNSAFETY_
#undef _UNSAFETY_

#define _ERROR_
#undef _ERROR_

using namespace std;

class Sample
{
public:
	explicit Sample(int data = 0):data(data){}
	Sample(const Sample& other):data(other.data){}
	~Sample(){cout<<"call ~Sample()"<<endl;}
	
	void setData(const int data){this->data = data;}
	int getData()const{return data;}

	void show()const{cout<<"data ="<<data<<endl;}
private:
	int data;
};

class Demo
{
public:
	explicit Demo(Sample* psample):psample(psample),value(0){}         //���캯��ʹ��ǳ������psample��Demo::psampleָ��ͬһƬ�ռ䡣
	Demo(Sample* psample,double value):psample(psample),value(value){}
	Demo(const Demo& other):psample(new Sample(*(other.psample))),value(other.value){}   //�������캯��ʹ�����
	
	void setSample(Sample* psample){this->psample = psample;}  //Sample���������Demo�๹�죬Ҳ���Ժ���Demo��new������
	Sample* getSample(){return psample;}                       //Sample���������Demo��������Ҳ���Ժ���Demo��delete����
	
	void setValue(const double value){this->value = value;}
	double getValue()const{return value;}

	void release()                  //Demo�����ʹ��release()����������Sample����������ڡ�
	{
		if(psample != nullptr)      //���Demo�����psampleָ����delete���Ǹ������Demo�ڵ�psampleָ���ΪҰָ�롣
		{                           //����ټ�������release()�����Ļ����ͻᵼ��Ұָ�����ͷ����⡣
			delete psample;
			psample = nullptr;      //ֻ��Demo���캯���д���ѱ�����ַʱ�ſ��Ե���release()������
		}                           //����ջ������ַʱ���ܵ���release()����,��Ϊջ�ռ��еı����ڴ���ɲ���ϵͳ�Զ����գ�������Ҫ�û��ֶ�delete��
	}
	
	void setData(const int data)
	{
		if(psample == nullptr)      //Ұָ��Ҳ���㲻����nullptr������ʹ��psample == nullptr���жϣ��������ų�Ұָ�롣
		{
			cout<<"setData warn: psample is null"<<endl;
			return ;
		}
		psample->setData(data);
	}
	
	int getData()const
	{
		if(psample == nullptr)      //C��C++�����в���ͨ���κ��﷨���ж�һ��ָ���ǲ���Ұָ�룬
		{                           //ֻ��ͨ��free��delete�Ժ����Ͻ�ָ����Ϊ��ָ��(NULL��nullptr)��������Ұָ��ķ�����
			cout<<"getData warn: psample is null"<<endl;
			throw "getData warn: psample is null";
		}
		return psample->getData();
	}

	void display()const
	{
		if(psample != nullptr)
		{
			psample->show();
		}
		cout<<"value ="<<value<<endl;
	}
private:
	Sample* psample;      //Sample������Demo����������ڿ�����ȫ����ͬ��Demo�಻����Sample��Ĵ��������١�
	double value;
};

class Test
{
public:
	explicit Test(Sample* psample):psample(psample),num(0){}      //���캯��ʹ��ǳ������psampleָ���Test::psampleָ��ָ��ͬһƬ��ַ�ռ䡣
	Test(Sample* psample,int num):psample(psample),num(num){}
	
	Test(const Test& other):num(other.num)      //Test�࿽�������ʱ��ʹ�������this->psampleָ��new�������¶��ڴ�ռ䡣
	{
		if(other.psample == nullptr)
		{
			throw "Test copy construct error: other.psample = nullptr";
		}
		psample = new Sample(*(other.psample));
	}
	
	virtual ~Test()               //Test�������Sample����������ڽ�������Test������ʱSample��Ҳ������
	{                             //���Test�����psampleָ����delete�Ļ���Test::psampleָ�뽫��ΪҰָ�롣
		if(psample != nullptr)    //��Ϊdeleteֻ���ͷŶ��ڴ棬����deleteջ����������Test�๹�캯����ֻ�ܴ���ѱ�����ַ�����ܴ���ջ������ַ
		{
			delete psample;       //Sample���������Test���������������Test��������������Test�������psampleָ����ò�Ҫ��Test����������
			psample = nullptr;    //��Ϊ���������Test���е�psampleָ���ΪҰָ�롣��Test������������в����ж�Test::psampleָ���Ƿ�ΪҰָ�롣
		}                         //�Ӷ������Ұָ����delete���⡣
	}
	
	void setNum(const int num){this->num = num;}
	int getNum()const{return num;}
	
	void setData(const int data)
	{
		if(psample == nullptr)    //Ұָ��Ҳ���㲻����nullptr������ʹ��psample == nullptr���жϣ��������ų�Ұָ�롣
		{
			cout<<"setData error: psample is null"<<endl;
			return ;
		}
		psample->setData(data);
	}
	
	int getData()const
	{
		if(psample == nullptr)     //C��C++�����в���ͨ���κ��﷨���ж�һ��ָ���ǲ���Ұָ�룬
		{                          //ֻ��ͨ��free��delete�Ժ����Ͻ�ָ����Ϊ��ָ��(NULL��nullptr)��������Ұָ��ķ�����
			cout<<"getData warn: psample is null"<<endl;
			throw "getData warn: psample is null";
		}
		return psample->getData();
	}
	
	void print()const
	{
		if(psample != nullptr)
		{
			psample->show();
		}
		cout<<"num ="<<num<<endl;
	}
private:
	Sample* psample;    //�����Sample����Test��֮ǰ���죬Ȼ����Test��������Sample�������������ڡ�
	int num;            //�������Ա���Test::psampleָ���ΪҰָ�룬�Ӷ��������Ұָ�뱻delete�������⡣
};

class Example
{
public:
	explicit Example(int data):psample(new Sample(data)),size(0){}        //Example�������Sample����Ĵ�������Example�๹��ʱSample��Ҳ�ṹ��
	Example(int data,double size):psample(new Sample(data)),size(size){}
	
	Example(const Example& other):size(size)
	{
		if(other.psample == nullptr)
		{
			throw "Example copy construct error: other.psample = nullptr";
		}
		psample = new Sample(*(other.psample));
	}
	
	void setSize(const double size){this->size = size;}
	double getSize()const{return size;}
	Sample* sample(){return psample;}
	
	void release()                //Example�����ʹ��release()��������Sample������������ڡ�
	{
		if(psample != nullptr)    //���Example������Ѿ��ͷ�����Example�๹�캯����new������Sample�����ڴ档
		{                         //��ôSample::psampleָ��ͻ��ΪҰָ�룬����ټ�������release()����ʱ����Ұָ�뱻���delete���⡣
			delete psample;
			psample = nullptr;
		}
	}
	
	void setData(const int data)
	{
		if(psample != nullptr)
		{
			psample->setData(data);
		}
	}
	
	int getData()const
	{
		if(psample == nullptr)
		{
			cout<<"getData error: psample is null"<<endl;
			exit(-1);
		}
		return psample->getData();
	}
	
	void detail()const
	{
		if(psample != nullptr)
		{
			psample->show();
		}
		cout<<"size ="<<size<<endl;
	}
private:
	Sample* psample;
	double size;
};

static void delete_pointer();
static void delete_wild_pointer();

static void Sample_test();
static void Test_test();
static void Example_test();

int main(int argc,char* argv[])
{
	delete_pointer();
	delete_wild_pointer();
	
	Sample_test();
	Test_test();
	Example_test();
	
	return 0;
}

void delete_pointer()
{
	int *p = new int(10);
	printf("*p = %d, address: %p\n",*p,p);

	delete p;                                   //���ڴ���new�����ĵ�ַ�ռ䣬��ʹ��delete�ͷŵ�ʱ��ԭ�ڴ������е�ֵ�����ᱻ������ա���Ϊ������ռ��CPU���ڡ�
	printf("*p = %d, address: %p\n",*p,p);      //����ԭnew�����Ķ��ڴ��ַ�ռ䣬��Ȼ���Լ������ʡ�ֱ����һ��ָ������ͨ��new��������������һƬ���ڴ�ռ䡣

#ifdef _UNSAFETY_
	*p = 11;             //Ұָ�����д�룬������ܻ������
	printf("*p = %d, address: %p\n",*p,p);
	
	delete p;            //Ұָ����delete�����Ҳ���ܻ������
	printf("*p = %d, address: %p\n",*p,p);
	
	*p = 12;
	printf("*p = %d, address: %p\n",*p,p);
#endif

	p = nullptr;       //��ָ����Ϊnullptr�Ժ���delete�����������nullptrָ����Զ��delete��
	delete p;          //���Թ����н���deleteһ��ָ���Ժ�Ҫ��ָ�븳Ϊ��ָ�룬�Դ���ߴ���Ľ�׳�ԡ�
	
	{
		int a = 100;
		cout<<"a ="<<a<<" ,address: "<<&a<<endl;
		
		int *q = &a;
		cout<<"*p ="<<*p<<" ,address: "<<q<<endl;

#ifdef _ERROR_
		delete p;       //deleteջ�ڴ��Ժ󣬻����ջ�����������򣬱��ͷ����Σ����������
		p = nullptr;
#endif
	}
}

void delete_wild_pointer()
{
	int *p = new int(20);
	int *q = p;                                 //ָ��p��qָ��new������ͬһƬ���ڴ�ռ�
	cout<<"*p ="<<*p<<" ,address: "<<p<<" , *q ="<<*q<<" ,address: "<<q<<endl;
	
	*q = 21;
	cout<<"*p ="<<*p<<" ,address: "<<p<<" , *q ="<<*q<<" ,address: "<<q<<endl;
	
	delete p;                                     //ָ��p�ͷ���ԭ��new�����ĵ�ַ��ԭ��new�����ĵ�ַ�ͱ�Ϊ��������ַ��
	p = nullptr;                                  //��ָ��q��֪��ԭ��new�����ĵ�ַ��delete���ˣ���ָ��ԭ����new�����ĵ�ַ��
	cout<<"*q ="<<*q<<" ,address: "<<q<<endl;     //����qָ��ͱ�Ϊ��Ұָ�롣����ԭ��new�����Ķ��ڴ�ռ䱻delete���ˣ�
	                                              //�����ڴ��е�����û�б���գ����������ϼ������ʣ����Ҳ��ᱨ��

#ifdef _UNSAFETY_
	*q = 22;               //Ұָ�����д�룬������ܻ������
	cout<<"*q ="<<*q<<" ,address: "<<q<<endl; 
	
	delete q;              //Ұָ����delete�����Ҳ���ܻ������
	cout<<"*q ="<<*q<<" ,address: "<<q<<endl;
	
	*q = 23;               //Ұָ�����д�룬������ܻ������
	cout<<"*q ="<<*q<<" ,address: "<<q<<endl; 
#endif

	q = nullptr;
	delete q;           //C++���Թ涨nullptrָ�����delete����������������С�
}

static void Sample_test()
{
	Sample sample(31);       //һ��ջ������˱��������򣬻��Զ��������������ͷ�ջ�ռ��ڴ档
	sample.show();           //����ջ�����ڴ�ռ䲻��ʹ��delete�ֶ��ͷţ����������һ��ջ�����ڴ�ռ䱻�ͷ��������⡣
	
	Demo demo(nullptr,32.01);
	demo.display();
	
	demo.setSample(&sample);   //demo���õ���ջ�������Բ��ܵ���release()����
	demo.display();
	
	demo.setData(33);
	demo.setValue(34.01);
	demo.display();

#ifdef _ERROR_
	demo.release();      //demo�����Ǵ����ջ��������release()�����л��ֶ�deleteջ�������Ӷ����ջ�ڴ汻�ͷ����Σ��������
#endif
	
	Sample* psample = new Sample(35);
	demo.setSample(psample);
	demo.display();
		
#ifdef _UNSAFETY_
	delete psample;      //��Ȼpsample�Ѿ�delete���ˣ�����ָ����nullptr������Demo���е�psampleָ�뻹ָ��deleteǰ��new�����ĵ�ַ��
	psample = nullptr;   //��ʱDemo::psampleָ���Ϊ��Ұָ�롣
#else
	demo.release();
	psample = nullptr;   //��psample����Ϊnullptrָ�룬�Ա���release()�����н�new�������ڴ��ͷŵ��ˣ�psample��ΪҰָ�롣
#endif

	demo.setData(36);    //���Demo���е�psampleָ���Ϊ��Ұָ�룬��ô��Ұָ���д����ܻ�������������
	demo.display();
}

static void Test_test()
{
	{
#ifdef _ERROR_
		Sample sample(40);
		Test test(&sample);
#else
		Sample* psample = new Sample(40);
		Test test(psample);
#endif
		test.print();
	}
}

static void Example_test()
{
	
}