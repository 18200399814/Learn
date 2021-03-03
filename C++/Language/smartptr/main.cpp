/*1.ΪʲôҪʹ������ָ�룺
 *  ��C++���ڴ������һ���úܶ���ͷ�۵��£�������дһ��new���ʱ��һ���������delete���ֱ��Ҳд�ϡ�
 *  �����ǲ��ܱ������δִ�е�delete������ת�˻��������ˡ����û����ÿһ��������ת���߷��ص����ǰ�ͷ���Դ��
 *  �ͻ�����ڴ�й¶��ʹ������ָ����Ժܴ�̶��ϵı���������⣬��Ϊ����ָ�����һ���࣬�����������������ʱ��
 *  ����Զ����������������ͷ���Դ��
 */
 
/*2.����ָ���ʹ�÷�����
 *��1������ָ�������ԭʼָ��һ���������public��Ա��
 *��2��get()�������ڷ�������ָ���йܵ�ԭʼָ�롣
 *��3��reset()��������ʹ����ָ�����°�ָ��Ķ��󣬶�ԭ���Ķ�����ᱻ�ͷš�
 *     �������reset()����ʱ�������¶�����ô�������þ�ֻ�������ͷ������ָ�����Դ��
 *��4��release()���������ͷ�����ָ�����Դ������Ȩ������ԭ�������ԭʼָ���ڴ治�ᱻ�ͷš�
 *     shared_ptr��weak_ptrû��release()������ֻ��reset()������
 */

/*����autp_ptr�ĸ�ֵ�����򿽱�����������������ԭ��auto_ptr�������Դ����ʽ�ͷŵ���ʹ���Ϊһ��ʧЧ������ָ�롣
 *Ӧ�ñ����auto_ptr�ŵ������У���Ϊ���ѱ����û�����������е�Ԫ�ؽ��и�ֵ������������ʹ�����кܶ�Ԫ�ر���ΪNULL��
 *��auto_ptr��Ϊ����ʵ�δ��ݵ������е�ʱ����Դ����Ȩת�Ƶ��˺����βΣ����������غ�û�аѿ���Ȩ������������ʵ��,
 *���Թ��˺���������ԭ�ȵ�auto_ptr���Ѿ�ʧЧ�ˡ�Ϊ�˱���������ʽ����Դ����Ȩת�ƹ���C++11ʹ��unique_ptrȡ����auto_ptr��
 *��unique_ptr����Դ����Ȩֻ����ʽ��std::move()ת�ƣ������ܼ򵥵ĸ�ֵ�򿽱��������û���֪��ԭ�ȵ�unique_ptr�Ѿ�ʧЧ�ˡ�
 */

/*unique_ptr��һ����������Ȩ������ָ�룬������auto_ptr�ľ��󲿷ֹ��ܡ����޷����и��ƹ���͸�ֵ������
 *���޷�ʹ����unique_ptrָ��ͬһ�����󡣵��ǿ��Խ����ƶ�������ƶ���ֵ���������ҿ��Ա����浽�����У�
 */

/*weak_ptr��������ָ���������������ָ����������ڵ�����ָ�룬��ָ����һ��shared_ptr���������ָ�롣
 *��һ��weak_ptr�󶨵�һ��shared_ptr���󣬲���ı�shared_ptr�����ü�����һ�����һ����ָ������shared_ptr�����٣�
 *��ָ��Ķ���ͻᱻ�ͷţ���ʹ��ʱ��weak_ptrָ��ö�����ָ��Ķ�����Ȼ���ͷš�
 */

/*weak_ptrָ������һ����С�ܡ���ģ����Ҳ����C++11��ʱ������ı�׼�⣬���ĳ�����ȫ��Ϊ���ֲ����ϴ�shared_ptr������ȱ�ݵ����⡣
 *��ʵ�������һ��������ָ��auto_ptr��˵���½��ϴ�shared_ptr����˵��������������ͨ�����ü���ʵ�ֵ�������Ȼ�����ָ���ռ�����⣬
 *��Ҳ�������໥���õ����⣬�ҿ����Լ���û�취����ģ�����C++11��weak_ptr��shared_ptrһ�������˱�׼�⣬�������ѭ�����õ����⡣
 */

/*weak_ptr����Ҳ��һ��ģ���࣬���ǲ���ֱ������������һ������ָ��Ķ���ֻ�����shared_ptr��ʹ�ã����Խ�shared_ptr�Ķ���
 *��ֵ��weak_ptr��������������ı����ü�����ֵ��weak_ptr��Ҫ��lock��swap��reset��expired��operator=��use_count����������
 *��shared_ptr��ȶ���lock��expired����������ȴ����get������������operator* �� operator->��û�У����õĺ��������ٵĿ�����
 */

#include <cstdio>     //getchar()
#include <iostream>
#include <memory>      //std::auto_ptr��std::unique_ptr��std::shared_ptr��std::weak_ptr
#include <utility>     //std::move()
#include "demo.h"

#define _ERROR_
// #undef _ERROR_

using namespace std;

static unique_ptr<Demo> fun();

static void test_auto_ptr();      //auto_ptr��C++11���Ѿ����ã���unique_ptrȡ����֮��
static void test_unique_ptr();    //������Դָ�룬���ܸ��ƣ�ֻ���ƶ���
static void test_shared_ptr();    //������Դָ�룬shared_ptr����C++�и���rawԭʼָ�������ָ�롣
static void test_weak_ptr();      //��ָ�룬�������shared_ptrʹ�á�

int main(int argc,char* argv[])
{
	test_auto_ptr();
	test_unique_ptr();
	test_shared_ptr();
	test_weak_ptr();
	return 0;
}

static void test_auto_ptr()
{
	auto_ptr<Demo> spdemo(new Demo("C++",10));
	spdemo->show();
	
	spdemo->setName("Java");      //����auto_ptr�й�ָ��ĳ�Ա����ʱ���õ���ָ���Ա�����������->����
	spdemo.get()->setData(11);    //����auto_ptr�ĳ�Ա����ʱ���õ��Ƕ����Ա�����������.����
	spdemo.get()->show();         //auto_ptr::get()���������Ƿ�������ָ������ԭʼָ�롣

	cout<<"get name: "<<(*spdemo).getName()<<endl;
	cout<<"get data: "<<(*spdemo).getData()<<endl;
	
	spdemo.reset(new Demo("C#",12));    //auto_ptr::reset()���������ͷŵ�ԭ�е�ָ�룬����滻������ָ������ָ�롣
	spdemo->show();
	cout<<endl;
	
	auto_ptr<Demo> spdemo1(new Demo("Qt",13));
	spdemo1.get()->show();
	
	spdemo1 = spdemo;           //spdemo1����ָ�뽫�ӹ�spdemoָ��ԭ�����ڴ����Ȩ��spdemo���Ϊ��ָ�롣
	spdemo1->show();            //���spdemo1ԭ����Ϊ�գ����������ͷ�ԭ�����ڴ���Դ��
	if(spdemo.get() == nullptr)    //auto_ptr�пղ���ʹ��if(spdemo == nullptr)����Ӧ��ʹ��if(spdemo.get() == nullptr)
	{
		cout<<"spdemo is null"<<endl;
	}
	cout<<endl;
	
	Demo* pdemo = spdemo1.release();   //auto_ptr::release()����ֻ�ǽ�����ָ���йܵ�ԭʼָ������Ϊnullptr��������
    if(spdemo1.get() == nullptr)       //ԭ��ָ����ڴ�ռ䲢û�б��ͷš��൱����ֻ���ͷ�������ָ�����Դ������Ȩ��
	{
		cout<<"spdemo1 is null"<<endl;
	}
	
	if(pdemo != nullptr)
	{
		pdemo->show();
	}

	auto_ptr<Demo> spdemo2;
	spdemo2.reset(new Demo("Go",14));
	(*spdemo2).show();
	
	spdemo2.reset();       //�����Ҫ��;�ͷ���Դ�������ǵȵ�����ָ�뱻����ʱ���ͷţ�����ʹ��auto_ptr::reset()������
	if(spdemo2.get() == nullptr)
	{
		cout<<"release source immediately"<<endl;
	}
}

unique_ptr<Demo> fun()
{
	return unique_ptr<Demo>(new Demo("hello",20));
}

/*unique_ptr��auto_ptr�÷������ƣ���������ʹ����������ָ�븳ֵ������Ӧ��ʹ��std::move��
 *����������ֱ����if(spdemo == NULL)���ж��Ƿ��ָ�롣release��get��reset���÷�Ҳ��auto_ptrһ�£�
 *ʹ�ú����ķ���ֵ��ֵʱ������ֱ��ʹ��=����Ϊ����ʹ��C++11���ƶ��������ԡ������������������ݸ�����ʱ��
 *��ʵ��ʱҲҪʹ��std::move����������������һ����Ա����swap���ڽ�����������ָ���ֵ��
 */
static void test_unique_ptr()
{
	unique_ptr<Demo> spdemo(new Demo("JaveScript",21));
	spdemo->show();
	
	spdemo->setName("world");
	(*spdemo).setData(22);
	spdemo.get()->show();
	cout<<endl;
	
	unique_ptr<Demo> spdemo1(new Demo("Rust",23));
	(*spdemo1).show();
	
	spdemo = std::move(spdemo1);   //����ʹ��spdemo = spdemo1����Ϊunique_ptr���ܽ��и��ƹ����ֵ������ֻ�ܽ����ƶ�������
	if(spdemo1 == nullptr)         //unique_ptr�пռ�����ʹ��if(spdemo == nullptr)��Ҳ����ʹ��if(spdemo.get() == nullptr)
	{
		cout<<"spdemo1 is null"<<endl;
	}
	spdemo->show();
	cout<<endl;
	
	Demo* pdemo = spdemo.release();
	if(spdemo.get() == nullptr)
	{
		cout<<"spdemo is null"<<endl;
	}
	(*pdemo).show();
	
	spdemo1.reset(pdemo);
	spdemo1->show();
	cout<<endl;
	
	spdemo = fun();    //���������=����Ϊʹ�����ƶ���ֵ����
	spdemo.get()->show();
	
	spdemo1.swap(spdemo);   //unique_ptr::swap()�������ڽ�����������ָ���ֵ
	spdemo1->show();
	(*spdemo).show();
	
	spdemo.reset();
	if(spdemo == nullptr)
	{
		cout<<"release source immediately"<<endl;
	}
}

/*shared_ptr��һ����������Ȩ������ָ�룬��ͨ�����ü���������ͳ����Դ������ָ��ʹ�á�����ʹ��use_count()��������
 *����Դ�������߸�����������reset()ʱ����ǰָ����ͷ���Դ����Ȩ�����ü�����1�������ü�������0ʱ����Դ�Żᱻ�ͷš�
 *���˹���ʱnew rawָ�����⣬������ͨ������auto_ptr, unique_ptr,weak_ptr������shared_ptr����ָ�롣
 */
void test_shared_ptr()
{
	shared_ptr<Demo> spdemo(new Demo("shared pointer",30));
	cout<<"get name: "<<spdemo.get()->getName()<<endl;
	cout<<"get data: "<<(*spdemo).getData()<<endl;
	cout<<"reference count: "<<spdemo.use_count()<<endl;     //�鿴raw��Դ�����ü���
	spdemo->show();
	
	shared_ptr<Demo> spdemo1 = make_shared<Demo>("test",31);   //ʹ��make_shared����shared_ptr��ֱ�ӵ��ù��캯����Ч�ʸ���
	spdemo1.get()->show();
	
	spdemo1 = spdemo;     //spdemo1ԭ������Դ�ᱻ�ͷţ������°󶨵�spdemo���е���Դ�ϣ�
	(*spdemo1).show();    //��ʱspdemo��spdemo1����ͬһ����Դ�����ü�����1��
	cout<<"spdemo reference count: "<<spdemo.use_count()<<endl;
	cout<<"spdemo1 reference count: "<<spdemo1.use_count()<<endl;
	cout<<endl;

	spdemo.reset();      //shared_ptrû��release()������ֻ��reset()����������reset()����ʱ��Դ�����ü������һ��
	cout<<"spdemo reference count: "<<spdemo.use_count()<<endl;
	cout<<"spdemo1 reference count: "<<spdemo1.use_count()<<endl;
	
	if(spdemo.get() == nullptr)
	{
		cout<<"spdemo is null"<<endl;
	}
	
	spdemo1->show();
	spdemo1.reset();     //��ʱ��Դ�����ü����ż�Ϊ0����delete�ͷŵ���
	if(spdemo1 == nullptr)
	{
		cout<<"spdemo is null"<<endl;
	}
}

class Foo;      //�������໥����ʱ����Ҫ������һ����ǰ����������
class Bar
{
public:
	shared_ptr<Foo> spfoo;
	
	virtual ~Bar(){cout<<"Bar destructor"<<endl;}
};

class Foo
{
public:
#ifdef _ERROR_
	shared_ptr<Bar> spbar;
#else
	weak_ptr<Bar> spbar;    //weak_ptr����ֱ����������һ������ָ��Ķ���ֻ�����shared_ptr��ʹ�á�
#endif
	
	virtual ~Foo(){cout<<"Foo destructor"<<endl;}
};

/*weak_ptr��һ�ֶ���Դ�������ã��������Ӷ�������ü�������Ҫ�������shared_ptrʹ�õģ����shared_ptr�໥����
 *ʱ���������⡣�������shared_ptr�໥���ã���ô������ָ������ü�����Զ�������½�Ϊ0����ԴҲ����Զ���ᱻ�ͷš�
 *weak_ptr��shared_ptr֮������໥ת����shared_ptr����ֱ�Ӹ�ֵ��������Ҳ����ͨ������lock���������shared_ptr��
 */
void test_weak_ptr()
{
	shared_ptr<Demo> spdemo = make_shared<Demo>("weak pointer",40);
	cout<<"spdemo reference count: "<<spdemo.use_count()<<endl;
	spdemo->show();
	
	weak_ptr<Demo> wpdemo = spdemo;   //weak_ptrֻ��ͨ��shared_ptr������һ��weak_ptr���г�ʼ����weak_ptr��ʼ��ʱ���ü��������1��
	cout<<"spdemo reference count: "<<spdemo.use_count()<<endl;    //���۶��ٸ�weak_ptrָ��ͬһ��shared_ptr��shared_ptr�����ü���������ı�
	cout<<"wpdemo reference count: "<<spdemo.use_count()<<endl;
	puts("");
	
	shared_ptr<Demo> spdemo1 = wpdemo.lock();    //weak_ptr����һ�ֶ���������ָ�룬��������������ָ�����Դ����ֻ��shared_ptr��һ�����֡�
	cout<<"spdemo reference count: "<<spdemo.use_count()<<endl;
	cout<<"wpdemo reference count: "<<spdemo.use_count()<<endl;
	cout<<"spdemo1 reference count: "<<spdemo.use_count()<<endl;
	spdemo1->show();
	cout<<endl;
	
	spdemo1.reset();
	cout<<"spdemo reference count: "<<spdemo.use_count()<<endl;
	cout<<"wpdemo reference count: "<<spdemo.use_count()<<endl;
	cout<<"spdemo1 reference count: "<<spdemo.use_count()<<endl;
	putchar('\n');
	
	if(!wpdemo.expired())   //expired()��鱻���õĶ����Ƿ���ɾ��������false�Դ��ڣ�����true���Ѿ��ͷű��ˡ�
	{
		shared_ptr<Demo> spdemo2 = wpdemo.lock();  //��Ȼweak_ptr���Ʋ�����ָ����������ںͲ��ܷ��ʶ�����Դ���������Լ��ӵ�����ָ��Ķ����Ƿ���ڡ�
		spdemo2.get()->show();
	}
	
	spdemo.reset();    //��shared_ptr��Ҫ�ͷ���ָ�������ʱ���ճ��ͷţ������Ƿ���weak_ptrָ��ö���
	cout<<"spdemo reference count: "<<spdemo.use_count()<<endl;
	cout<<"wpdemo reference count: "<<spdemo.use_count()<<endl;
	
	{
		shared_ptr<Foo> spfoo(new Foo);
		shared_ptr<Bar> spbar(new Bar);
		
		spfoo->spbar = spbar;
		spbar->spfoo = spfoo;
		
		cout<<"spfoo reference count: "<<spfoo.use_count()<<endl;
		cout<<"spbar reference count: "<<spbar.use_count()<<endl;
	}

	puts("\n���������ַ���������");
	getchar();    //��ֹ�����˺��������򣬵��ö�����������
}