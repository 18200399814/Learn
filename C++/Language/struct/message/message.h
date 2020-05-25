#ifndef _MESSAGE_H
#define _MESSAGE_H

/*
 *�ṹ��ת��Ϊ�����Ժ󣬶�����ķ��������ַ�ʽ��
 *1.������ת��Ϊ�ṹ�壬ʹ�ýṹ��ָ��ȥ���ʡ������ַ��ʷ�ʽ��򵥣�
 *2.ͨ��char���͵�ָ����Ͻṹ���и�������ƫ����ȥ���ʡ�
 */

#define DATA_SIZE 256
#define BUFF_SIZE 1024
#define MSG_SIZE sizeof(Message)

//Message�����ֽڶ���ṹ�壬����ֻ��ת��Ϊchar buf[]
typedef struct Message
{
	int id;
	char type;
	double value;
	char data[DATA_SIZE];
}Message;

typedef enum Message_t
{
	ID,
	TYPE,
	VALUE,
	DATA,
	END_MSG
}Message_t;

extern char socketBuf[];
extern char offsetArr[];

void showMsg(const Message msg);
void showMsgArr(const char* arr,int size);

void sendMsg(const Message msg);
void recvMsg(Message *msg);

void msgToArray(const Message msg,char* arr,int size);
void arrayToMsg(const char* arr,int size,Message *msg);

#endif //_MESSAGE_H