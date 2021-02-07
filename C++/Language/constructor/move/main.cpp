#include <iostream>
#include <utility>         //std::move
#include "sample.h"

#define _EEROR_
#undef _EEROR_

#define _CHANGE_WAY_
#define _CHANGE_WAY_

static Sample g_sample("global sample",1001);

using namespace std;

/*1.fun�����ĵ��÷��ع��̣�
 *��1���ȵ���Sample��Ĺ��캯��������һ��Sample���͵���ʱ����
 *��2���ٵ���Sample����ƶ����캯��������ǰ����������������Դת�Ƶ�һ���µ���ʱ�����У���������Ϊfun()�����ķ���ֵ��
 *     ��ǰ�����������������١�
 *��3�������fun()�����ķ���ֵ��ֵ��һ��Sample���͵ı�������ô���ٵ���һ���ƶ����캯�����ƶ��������
 *     ��fun()�����ķ���ֵ��Դ���ƶ�����Ҫ��ֵ����Sample�����У��ƶ�����Ժ�fun()�������ص���ʱ����������
 *     �����fun()�����ķ���ֵ��ֵ��һ��Sample���͵���ֵ���ã���ô�����ֵ���ý���Ϊfun()��������ֵ�ı�����
 *     fun()��������ֵ�������ڵõ����ӳ������������������١�������fun()�����ķ���ֵ��һ����ʱ�������Բ���
 *     ���丳ֵ��һ����ֵ���á�
 */
Sample fun()
{
	return Sample("fun",31);
}

#ifndef _CHANGE_WAY_
/*2.foo�����ĵ��÷��ع��̣�
 *��1���ȵ���Sample��Ĺ��캯��������һ��Sample���͵ı�����
 *��2���ٵ���Sample����ƶ����캯��������ǰ������Sample������Դ�ƶ���һ���µ���ʱ�����У���������Ϊfoo()�����ķ���ֵ��
 *     ��ǰ������Sample�������ں������ض������١�
 *��3�������foo()�����ķ���ֵ��ֵ��һ��Sample���͵ı�������ô���ٵ���һ���ƶ����캯�����ƶ��������
 *     ��foo()�����ķ���ֵ��Դ���ƶ�����Ҫ��ֵ����Sample�����У��ƶ�����Ժ�foo()�������ص���ʱ����������
 *     �����foo()�����ķ���ֵ��ֵ��һ��Sample���͵���ֵ���ã���ô�����ֵ������foo()��������ֵһ��������
 *     foo()��������ֵ�������ڵõ����ӳ������������������١�fun()�����ķ���ֵ������һ����ʱ�������Բ���
 *     �����ظ�ֵ��һ����ֵ���á�
 */
Sample foo()
{
	Sample sample("foo",32);  //���ʹ����ʱ�����ֲ�������Ϊ��������ֵʱ���������Ὣ������Ϊ��ֵ�Դ����õ��ƶ����캯������Ϊ����ִ�з����Ժ�
	return sample;            //�ֲ���������ʱ���󶼻ᱻ���٣�Ϊ�������Դ�����ʣ����ⲻ��Ҫ�����������������ƶ����캯��������һ����ʱ������
}                             //���󷵻��������С����ھֲ���������ֵ�����Ա������Զ������ƶ����캯��ǰ���϶��ȵ���std::move��������ֵת��Ϊ����ֵ��
#else
/*3.foo�����ĵ��÷��ع��̣�
 *��1���ȵ���Sample��Ĺ��캯��������һ��Sample���͵ı�����
 *��2���ٵ���Sample���������캯��������ǰ����������������һ�ݵ�һ���µ���ʱ�����У���������Ϊfoo()�����ķ���ֵ��
 *     ��ǰ�����ı������ں������ض������١�
 *��3�������foo()�����ķ���ֵ��ֵ��һ��Sample���͵ı�������ô���ٵ���һ���ƶ����캯�����ƶ��������
 *     ��foo()�����ķ���ֵ��Դ�ƶ�����Ҫ��ֵ����Sample�����У��ƶ�����Ժ�foo()�������ص���ʱ����������
 *     �����foo()�����ķ���ֵ��ֵ��һ��Sample���͵���ֵ���ã���ô�����ֵ������foo()��������ֵһ��������
 *     foo()��������ֵ�������ڵõ����ӳ������������������١�foo()�����ķ���ֵ������һ����ʱ�������Բ���
 *     �����ظ�ֵ��һ����ֵ���á�
 */
Sample foo()
{
	const Sample sample("foo",32);
	return sample;
}
#endif


#ifdef _EEROR_
#ifndef _CHANGE_WAY_
//4.bar����ʵ�ִ��ڵĴ��󣺺������ص���ֵ���ò��ܰ󶨵�һ����ֵ����ʱ���������ϡ�
Sample& bar()
{
	return Sample("bar",33);
}
#else
//5.bar����ʵ�ִ��ڵĴ�����Ȼ�������صĳ�����ֵ���ÿ��԰󶨵�һ����ֵ��������ʱ�����ϡ������ڸ�����
//��ʱ�����ں�������֮��ͱ������ˣ�����bar()�����ٷ���һ���������˵Ķ������ã���������ֱ�ӱ��﷨����
const Sample& bar()
{
	return Sample("bar",33);
}
#endif
#else
Sample& bar()
{
	g_sample = Sample("bar",33);
	return g_sample;
}
#endif

#ifdef _EEROR_
#ifndef _CHANGE_WAY_
//6.baz����ʵ�ִ��ڵĴ�����Ȼ�������ص���ֵ���ÿ��԰󶨵�һ����ֵ������ϡ������ڸñ�����һ���ֲ�����
//�ں�������֮��ͱ������ˣ�����baz()�����ٷ���һ���������˵Ķ������ã���������ֱ�ӱ��﷨����
Sample& baz()
{
	Sample sample("baz",34);
	return sample;
}
#else
//7.baz����ʵ�ִ��ڵĴ�����Ȼ�������صĳ�����ֵ���ÿ��԰󶨵�һ��������ֵ��const�����ϡ������ڸ�const������
//һ���ֲ������ں�������֮��ͱ������ˣ�����baz()�����ٷ���һ���������˵Ķ������ã���������ֱ�ӱ��﷨����
const Sample& baz()
{
	const Sample sample("baz",34);
	return sample;
}
#endif
#else
Sample& baz()
{
	static Sample sample;
	sample = Sample("baz",34);
	return sample;
}
#endif

#ifdef _EEROR_
#ifndef _CHANGE_WAY_
//8.qux����ʵ�ִ��ڵĴ��󣺺������ص���ֵ���ò��ܰ󶨵�һ����ֵ������ϡ�
Sample&& qux()
{
	Sample sample("qux",35);
	return sample;
}
#else
//9.qux����ʵ�ִ��ڵĴ�����Ȼ�������ص���ֵ���ÿ��԰󶨵�һ����ֵ����ʱ�����ϡ������ڸ���ʱ����
//�ں�������֮��ͱ������ˣ�����qux()�����ٷ���һ���������˵Ķ������ã���������ֱ�ӱ��﷨����
Sample&& qux()
{
	return Sample("qux",35);
}
#endif
#else
Sample&& qux(Sample& sample)
{
	sample = Sample("qux",35);
	return std::move(sample);
}
#endif

#ifdef _EEROR_
//10.quz����ʵ�ִ��ڵĴ�����Ȼ����ʹ��std::move������һ����ֵ/����ת��Ϊ��ֵ���ٰ󶨵��������ص���ֵ�����ϡ�
//�����ڸþֲ������ں�������֮��ͱ������ˣ�����quz()�����ٷ���һ���������˵Ķ������ã���������ֱ�ӱ��﷨����
Sample&& quz()
{
	Sample sample("quz",36);
	return std::move(sample);
}
#else
Sample&& quz()
{
	static Sample sample;
	sample = Sample("quz",36);
	return std::move(sample);
}
#endif

static void constructor_test();
static void assign_test();
static void fun_test();
static void foo_test();
static void bar_test();
static void baz_test();
static void qux_test();
static void quz_test();

int main(int argc,char** argv)
{
	constructor_test();
	assign_test();
	fun_test();
	foo_test();
	bar_test();
	baz_test();
	qux_test();
	quz_test();

	return 0;
}

void constructor_test()
{
	Sample sample;
	sample.setName("default");
	sample.setData(10);
	sample.show();
	cout<<"default constructor"<<endl<<endl;
	
	const Sample sample1(11);
	sample1.show();
	cout<<"normal constructor 1"<<endl<<endl;
	
	Sample sample2("normal: 2",12);
	sample2.show();
	cout<<"normal constructor 2"<<endl<<endl;

#ifndef _CHANGE_WAY_
	Sample sample3(sample);   //����Sample(Sample& other)�汾���캯��
#else
	Sample sample3 = sample;
#endif
	sample.show();
	sample3.show();
	cout<<"shallowly copy or move constructor"<<endl<<endl;

#ifndef _CHANGE_WAY_
	Sample sample4(sample1);    //����Sample(const Sample& other)�汾������캯��
#else
	Sample sample4 = sample1;
#endif
	sample4.show();
	cout<<"deeply copy constructor"<<endl<<endl;
	
#ifndef _CHANGE_WAY_
	Sample sample5(Sample("move",13));    //�ᱻ������ֱ���Ż�Ϊ��Sample sample5("move",13)
#else
	Sample sample5 = Sample("move",13);   //g++ʹ��-fno-elide-constructorsѡ��رձ������Ż���VC++ʹ��/Odѡ��رձ������Ż���
#endif
	sample5.show();
	cout<<"normal or move constructor"<<endl<<endl;

#ifndef _CHANGE_WAY_
	Sample sample6(move(sample2));
#else
	Sample sample6 = std::move(sample2);
#endif
	sample6.show();
	sample2.show();     //sample2�����е�name��Աָ���ڴ�ռ��Ѿ���ת����
	cout<<"move constructor"<<endl<<endl;
}

void assign_test()
{
	Sample sample("hello",20);
	sample.show();
	
	Sample sample1("world",21);
	sample1.show();
	
	sample = sample1;       //����Sample& operator =(Sample& other)��ֵ�����
	sample.show();
	sample1.show();
	cout<<"call: operator =(Sample& other)"<<endl<<endl;
	
	const Sample sample2("C++",22);
	sample2.show();
	
	sample = sample2;
	sample.show();
	cout<<"call: operator =(const Sample& other)"<<endl<<endl;
	
	sample = Sample("Qt",23);
	sample.show();
	cout<<"call operator =(Sample&& other)"<<endl<<endl;
	
	Sample sample3("JAVA",24);
	sample3.show();
	
	sample = std::move(sample3);
	sample.show();
	sample3.show();
	cout<<"call: operator =(Sample&& other)"<<endl<<endl;
	
	Sample& lref = sample1;     //��ֵ����ֻ�����ñ���/����/��ֵ��
	lref.setData(25);
	lref.show();
	sample1.show();
	cout<<endl;
	
	const Sample& lref1 = sample1;    //������ֵ���ÿ������ñ���/const����/����/const����/��ֵ/������ֵ/��ֵ/������ֵ/��ʱ����
	lref1.show();
	cout<<endl;
	
	const Sample& lref2 = Sample("C",26);
	lref2.show();
	cout<<endl;
	
	Sample&& rref = Sample("C#",27);      //��ֵ���ÿ���������ʱ����Ҳ����ͨ��std::move�������õ�����
	rref.setData(28);
	rref.show();
	cout<<endl;
	
	Sample&& rref1 = std::move(sample1);
	rref1.setName("JavaScript");          //��ֵ���õ�ֵ�ı䣬��ͨ��std::move�����󶨵ı���Ҳ����Ÿı�
	rref1.setData(29);
	rref1.show();
	sample1.show();
}

static void fun_test()
{
	Sample sample("sample",31);
	sample = fun();     //�����ƶ���ֵ���������fun()�����ķ���ֵ��ֵ��sample����
	sample.show();
	cout<<endl;
	
	Sample sample1 = fun();   //�����ƶ����캯��������fun()�����ķ���ֵ��ֵ��sample����
	sample1.show();
	cout<<endl;

#ifdef _EEROR_
	Sample& rsample = fun();
#else
	Sample&& rsample = fun();
#endif
	rsample.show();
}

static void foo_test()
{
	Sample sample("sample",41);
	sample = foo();     //�����ƶ���ֵ���������fun()�����ķ���ֵ��ֵ��sample����
	sample.show();
	cout<<endl;
	
	Sample sample1 = foo();   //�����ƶ����캯��������fun()�����ķ���ֵ��ֵ��sample����
	sample1.show();
	cout<<endl;

#ifdef _EEROR_
	Sample& rsample = foo();   //��ֵ�����޷��󶨵���������ʱ�����ϡ�
#else
	Sample&& rsample = foo();  //��ֵ���ÿ��԰󶨵���������ʱ������
#endif
	rsample.show();
}

void bar_test()
{
	Sample sample("sample",51);
	sample = bar();         //�����ƶ���ֵ���������bar()�����ķ���ֵ��ֵ��sample����
	sample.show();
	cout<<endl;
	
	Sample sample1 = bar();  //�����ƶ����캯��������bar()�����ķ���ֵ��ֵ��sample����
	sample1.show();
	cout<<endl;
	
#ifndef _EEROR_
	Sample& rsample = bar();   //��ֵ���ÿ��԰󶨵�bar()�������ص���ֵ�����ϡ�
#else
	Sample&& rsample = bar();  //��ֵ���ò����԰󶨵�bar()�������ص���ֵ�����ϡ�
#endif
	rsample.show();
}

void baz_test()
{
	Sample sample("sample",61);
	sample = baz();         //�����ƶ���ֵ���������baz()�����ķ���ֵ��ֵ��sample����
	sample.show();
	cout<<endl;
	
	Sample sample1 = baz();  //�����ƶ����캯��������baz()�����ķ���ֵ��ֵ��sample����
	sample1.show();
	cout<<endl;
	
#ifndef _EEROR_
	Sample& rsample = baz();   //��ֵ���ÿ��԰󶨵�baz()�������ص���ֵ�����ϡ�
#else
	Sample&& rsample = baz();  //��ֵ���ò����԰󶨵�baz()�������ص���ֵ�����ϡ�
#endif
	rsample.show();
}

void qux_test()
{
#ifdef _EEROR_
	Sample sample("sample",71);
	sample = qux();         //�����ƶ���ֵ���������baz()�����ķ���ֵ��ֵ��sample����
	sample.show();
	cout<<endl;
	
	Sample sample1 = qux();  //�����ƶ����캯��������baz()�����ķ���ֵ��ֵ��sample����
	sample1.show();
	cout<<endl;
	
#ifndef _CHANGE_WAY_
	Sample& rsample = qux();   //��ֵ���ò����԰󶨵�baz()�������ص���ֵ�����ϡ�
#else
	Sample&& rsample = qux();  //��ֵ���ÿ��԰󶨵�baz()�������ص���ֵ�����ϡ�
#endif
	rsample.show();
#else    //_EEROR_
	Sample sample("sample",71);
	Sample sample1("sample",72);
	sample1 = qux(sample);         //�����ƶ���ֵ���������baz()�����ķ���ֵ��ֵ��sample����
	sample.show();
	sample1.show();
	cout<<endl;
	
	Sample sample2 = qux(sample);  //�����ƶ����캯��������baz()�����ķ���ֵ��ֵ��sample����
	sample2.show();
	cout<<endl;

#ifdef _EEROR_
	Sample& rsample = qux(sample);   //��ֵ���ò����԰󶨵�baz()�������ص���ֵ�����ϡ�
#else
	Sample&& rsample = qux(sample);  //��ֵ���ÿ��԰󶨵�baz()�������ص���ֵ�����ϡ�
#endif
	rsample.show();
#endif
}

void quz_test()
{
	Sample sample("sample",81);
	sample = quz();         //�����ƶ���ֵ���������baz()�����ķ���ֵ��ֵ��sample����
	sample.show();
	cout<<endl;
	
	Sample sample1 = quz();  //�����ƶ����캯��������baz()�����ķ���ֵ��ֵ��sample����
	sample1.show();
	cout<<endl;
	
#ifdef _EEROR_
	Sample& rsample = quz();   //��ֵ���ò����԰󶨵�baz()�������ص���ֵ�����ϡ�
#else
	Sample&& rsample = quz();  //��ֵ���ÿ��԰󶨵�baz()�������ص���ֵ�����ϡ�
#endif
	rsample.show();
}