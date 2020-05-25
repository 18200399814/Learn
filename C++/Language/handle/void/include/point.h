/*���handle�����Ͼ���һ��Ϊ�����ؽṹ���ʵ�ֶ�������ָ�롣handle���ָ�����ؽṹ�������׵�ַ,
 *�ڿ������ͨ���Ծ����ǿ�����ͣ��Ϳ��Է������صĽṹ�����һ��ʹ��void*ָ����Ϊͨ�þ���Ķ��塣
 */

#ifndef _POINT_H
#define _POINT_H

typedef int data_t;

void* createPoint(data_t x,data_t y);
void destroyPoint(void** handle);

void setX(void* handle,const data_t x);
data_t getX(const void* handle);

void setY(void* handle,const data_t y);
data_t getY(const void* handle);

void display(const void* handle);

#endif //_POINT_H