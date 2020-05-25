#ifndef _FILE_TOOLS_H
#define _FILE_TOOLS_H

#include <stdbool.h>

//�½����ļ�
extern bool newFile(const char fileName[]);
//ɾ���ļ�
extern int deleteFile(const char fileName[]);
//����ļ�
extern bool clearFile(const char *fileName);
//�޸��ļ���
extern int renameFile(const char *oldName,const char newName[]);
//�ж��ļ��Ƿ����
extern bool isExistFile(const char fileName[]);
//�ж��ļ��Ƿ�Ϊ��
extern bool isEmptyFile(const char *fileName);
//��ȡ�ļ���С
extern int getFileSize(const char *fileName);
//��ȡ�ļ�����
extern int getFileRownum(const char *fileName);
//�����ļ�                    
extern bool copyFile(const char *src,const char dts[]);
//�ļ�׷��һ�����ݣ���ĩβ����һ�����ݣ�
extern bool appendLine(const char *fileName,const char *data);
//���ļ���ͷ����һ������
extern bool prependLine(const char *fileName,const char data[]);
//���ļ�ָ���в�������(�����������ܴ����ļ���������)
extern bool insertLine(const char *fileName,const int row,const char *data);
//�滻�ļ�ָ���е�����
extern bool replaceLine(const char *fileName,const int row,const char *data);
//ɾ���ļ�ָ���У�ʣ����ļ����ƣ�
extern bool deleteLine(const char *fileName,const int row);
//����ļ�ָ���У�ʣ���ļ������ƣ�
extern bool clearLine(const char *fileName,const int row);
//�ļ��в���ĳ���ַ���,�����к�
extern int findStringRownum(const char *fileName,const char* str);
//��ȡ�ļ�ĳһ�е�����
extern bool getLineData(const char *fileName,const int row,char* data);
//��ȡ�ļ���ͷ��������
extern bool getStartArea(const char *fileName,const int len,char **buf,int *size);
//��ȡ�ļ��������е�����
extern bool getEndArea(const char *fileName,const int len,char **buf,int *size);
//��ȡ�����ļ������ݵ�������
extern bool getFileData(const char *fileName,char **buf,int *size);
//��ʾ�ļ�����
extern void showFile(const char* fileName);

#endif //_FILE_TOOLS_H