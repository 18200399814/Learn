/*���handle�����Ͼ���һ��Ϊ�����ؽṹ���ʵ�ֶ�������ָ�롣handle���ָ�����ؽṹ�������׵�ַ,
 *�ڿ������ͨ���Ծ����ǿ�����ͣ��Ϳ��Է������صĽṹ�����һ��ʹ��void*ָ����Ϊͨ�þ���Ķ��塣
 *�����������ؽṹ���ڲ�ʵ��ΪĿ�ģ��κ����͵�ָ�붼������Ϊ���ʹ�á�
 */

#ifndef _POINT_H
#define _POINT_H

typedef int data_t;
typedef void* handle_t;                       //ͨ��handle�������ʹ��void*ָ���ʾ����������handle_t���ڱ��Point������׵�ַ
                                              //ʹ��handle_t���������ʵ��Point�ṹ����Ϣ�����ء�

handle_t createPoint(data_t x,data_t y);      //��ȡPoint����Ĳ��������
void destroyPoint(handle_t* handle);          //���پ��ָ���Point����

void setX(handle_t handle,const data_t x);
data_t getX(const handle_t handle);

void setY(handle_t handle,const data_t y);
data_t getY(const handle_t handle);

void display(const handle_t handle);

#endif //_POINT_H