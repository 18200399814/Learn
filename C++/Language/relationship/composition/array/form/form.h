#ifndef _FORM_H
#define _FORM_H

#include "textbox.h"
#include "label.h"
#include "button.h"
#include <iostream>
#include <array>

#define BUTTON_COUNT 2
#define LABEL_COUNT 4

#define FREE_POINTER_ARRAY(parr,size)       \
	do{                                     \
		for(int i=0;i<size;++i)             \
		{                                   \
			if(parr[i] != nullptr)          \
			{                               \
				delete parr[i];             \
				parr[i] = nullptr;      \
			}                               \
		}                                   \
	}while(0)

using std::array;

class Form
{
public:
	Form(const string& text,const Pos_t& labelPos,bool buttonClick = false);
	virtual ~Form();
	
	void detail()const;
private:
	Form(const Form& other){};                          //��ֹ��������
	Form operator =(const Form& other) = delete;        //��ֹ��ֵ
	
	TextBox* ptextbox;                                  //ֻҪ���㸸�Ӷ���֮�䡰ͬʱ���죬ͬʱ��������Ϊ��Ϲ�ϵ
	array<Label*,LABEL_COUNT> plabels;
	array<Button*,BUTTON_COUNT> pbuttons;
};

Form::Form(const string& text,const Pos_t& labelPos,bool buttonClick)
	:ptextbox(new TextBox(text))
	,plabels{new Label(labelPos),new Label(labelPos),new Label(labelPos),new Label(labelPos)}
	,pbuttons{new Button(buttonClick),new Button(buttonClick)}
{
	
}

Form::~Form()
{
	delete ptextbox;               //��ΪTextBox��Form����Ϲ�ϵ������deleteʱ���Բ������пմ���
	
	delete pbuttons.at(0);
	delete pbuttons.at(1);
	
	FREE_POINTER_ARRAY(plabels,LABEL_COUNT);
}

void Form::detail()const
{
	ptextbox->show();             //��ΪTextBox��Form����Ϲ�ϵ������ʹ��ptextboxǰ���Բ������пմ���
	
	pbuttons.at(0)->print();
	pbuttons.at(1)->print();
	
	for(int i=0;i<LABEL_COUNT;++i)
	{
		plabels[i]->display();
	}
}

#endif //_FORM_H