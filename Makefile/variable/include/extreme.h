#ifndef _MAX_H
#define _MAX_H

typedef char BOOL;
#define TRUE 1
#define FALSE 0

extern const char* strBool[];

typedef int data_t;

extern BOOL isMax(data_t x,data_t y);                  //�ж�x�Ƿ��y��
extern data_t max(data_t x,data_t y);                  //��ȡ�������е����ֵ
extern data_t Max(data_t x,data_t y,data_t z);         //��ȡ�������е����ֵ

extern BOOL isMin(data_t x,data_t y);                  //�ж�x�Ƿ��yС
extern data_t min(data_t x,data_t y);                  //��ȡ�������е���Сֵ       
extern data_t Min(data_t x,data_t y,data_t z);         //��ȡ�������е���Сֵ

#endif //_MAX_H