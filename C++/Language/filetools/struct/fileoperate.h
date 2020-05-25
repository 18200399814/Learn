#ifndef _FILE_OPERATE_H
#define _FILE_OPERATE_H

#include <stdbool.h>

//�洢�ļ����ݵ����ݽṹ���Է�������ļ�����ɾ�Ĳ����
typedef struct FileData_t
{
	int row;                      //��¼�ļ�һ�����ݵ��к�
	int size;                     //��¼�ļ�һ�����ݵĴ�С
	char *buf;                    //�洢�ļ���һ������
	struct FileData_t *next;      //��ʽָ�룬��һ�������ݴ��������γ������ļ�
}FileData;

//���ļ��������ж��ļ��Ƿ���ڣ�����ļ������򴴽��ļ����ݴ洢�ṹ
extern FileData* openFile(const char fileName[]);
//�ر��ļ��������ļ����ݴ洢�ṹ
extern void closeFile(FileData** fileData);

//��ȡ�ļ����ݵ��ļ����ݴ洢�ṹ
extern bool readFile(const char *fileName,FileData *fileData);
//���ļ����ݴ洢�ṹ�е�����д���ļ���
extern bool writeFile(FileData *fileData,const char *fileName);

//�����ļ����½�һ�����ļ�
extern bool newFile(const char fileName[]);
//ɾ���ļ�
extern int deleteFile(const char fileName[]);
//����ļ�
extern bool clearFile(const char *fileName);

//�������ļ�
extern int renameFile(const char *oldName,const char newName[]);
//�����ļ�
extern bool copyFile(const char *srcFile,const char dtsFile[]);

//�����ļ����ݴ洢�ṹ���ж��ļ��Ƿ����
extern bool isExistFile(const FileData *fileData);
//�����ļ����ݴ洢�ṹ���ж��ļ��Ƿ�Ϊ��
extern bool isEmptyFile(const FileData *fileData);

//�����ļ����ݴ洢�ṹ����ȡ�ļ��Ĵ�С
extern int getFileSize(const FileData *fileData);
//�����ļ����ݴ洢�ṹ����ȡ�ļ�������
extern int getFileRow(const FileData *fileData);

//���ļ����ݴ洢�ṹ��ĩβ׷��һ������
extern bool appendLine(FileData *fileData,const char *data);
//���ļ����ݴ洢�ṹ��ǰ�����һ������
extern bool prependLine(FileData *fileData,const char data[]);

//���ļ����ݴ洢�ṹ�У�ɾ��һ�����ݣ����������ǰ��һ��
extern bool deleteLine(FileData *fileData,const int row);
//���ļ����ݴ洢�ṹ�У����һ�����ݣ���������ݱ��ֲ���
extern bool clearLine(FileData *fileData,const int row);

//���ļ����ݴ洢�ṹָ���У���������
extern bool insertLine(FileData *fileData,const int row,const char *data);
//�滻�ļ����ݴ洢�ṹ�У�ָ���е�����
extern bool replaceLine(FileData *fileData,const int row,const char *data);

//���ļ����ݴ洢�ṹ�У������ļ����������к�
extern int findStrRow(const FileData *fileData,const char* str);
//���ļ����ݴ洢�ṹ�У���ȡ�����к��ϵ��ļ�����
extern bool getLineData(const FileData *fileData,const int row,char* data);
//��ȡ�ļ����ݴ洢�ṹ�е��������ݵ�һ�����ڴ���
extern void getFileData(const FileData *fileData,char buf[],int *size);

//��ȡ�ļ���ʼ���е�����
extern bool getStartArea(const FileData *fileData,const int len,char buf[],int *size);
//��ȡ�ļ��������е�����
extern bool getEndArea(const FileData *fileData,const int len,char buf[],int *size);

//�����ļ�����ʾ�ļ�����
extern void showFile(const char fileName[]);
//��ӡ�ļ����ݴ洢�ṹ�е��ļ�����
extern void printFile(const FileData *fileData);

#endif //_FILE_OPERATE_H