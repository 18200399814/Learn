#include <iostream>

using namespace std;

class Sample
{
public:
	Sample(){n = 0;}
	Sample(int n){this->n = n;}
	Sample(/*const*/ Sample &s);
	~Sample();
	void setN(int n);
	int getN()/*const*/;
	void setM(int m);
	int getM()const;
	
	static void display(const Sample &s);
	static int m;
private:
	int n;
};

int Sample::m = 0;		 //static��Ա���๫�еģ�����ͨ�������Ͷ��������á�

Sample::Sample(/*const*/ Sample &s)        //const����ֻ�ܵ���const���εĺ���
{
#if 0
	n = s.getN();
#else
    n = s.n;
#endif
}

Sample::~Sample()
{
	cout << "Sample destroy"<<endl;
}

void Sample::setN(int n)
{
	this->n = n;
}

int Sample::getN()/*const*/
{
	return n;
}

void Sample::setM(int m)
{
	Sample::m = m;
}

int Sample::getM()const
{
	return m;
}


void Sample::display(const Sample &s)
{
	cout << "n ="<<s.n<<" ,m="<<m<<endl;     //static��Ա����ֻ��ֱ�ӷ���static��Ա
}

int main(int argc,char** argv)
{
	
	Sample s(5);	
	s.display(s);
	
	Sample *p = &s;
	p->setN(6);
	(*p).setM(7);
	cout << "n ="<<(*p).getN()<<" ,m="<<Sample::m/*p->m*/<<endl;
	
	Sample t(s);
	t.display(t);	
	
	return 0;
}