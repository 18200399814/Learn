#ifndef _BEAK_H
#define _BEAK_H

#define _ERROR_
#undef _ERROR_

enum Color_t
{
	RED = 0,
	BLACK,
	BLUE,
	YELLOW,
	GREEN,
	GRAY,
	COLOR_COUNT
};

#ifdef _ERROR_
const char* colorArr[COLOR_COUNT] = {            //������ָ��������ʼ���ķ�ʽ��C99�������ԣ�C++11��C++14�ȱ�׼�в���֧����������
	[RED] = "red",
	[BLACK] = "black",
	[YELLOW] = "yellow",
	[GREEN] = "green",
	[GRAY] = "gray"
};
#else
const char* colorArr[COLOR_COUNT] = {
	"red",
	"black",
	"yellow",
	"green",
	"gray"
};	
#endif

class Beak
{
public:
	Beak(const Color_t& color):color(color){}
	
	void show()const{cout<<"beak color ="<<colorArr[color]<<endl;}
private:
	Color_t color;
};

#endif //_BEAK_H