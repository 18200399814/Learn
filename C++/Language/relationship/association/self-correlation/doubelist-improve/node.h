#ifndef _NODE_H
#define _NODE_H

typedef double data_t;       //data_t���Ͳ�������Ϊint���ͣ���Ϊ������DoubleList�е�remove��replace��������ʧ��

typedef struct Node_t        //����Node_tӵ���Լ����͵�ָ�룬�����������������ϵ������Թ�����
{
	struct Node_t *prev;     //ָ��ֱ��ǰ��
	data_t data;
	struct Node_t *next;     //ָ��ֱ�Ӻ��
}Node;

#endif //_NODE_H