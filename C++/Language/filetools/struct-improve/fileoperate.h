#ifndef _FILE_OPERATE_H
#define _FILE_OPERATE_H

#include <stdbool.h>

#define FILE_NAME_MAX_SIZE 256

typedef struct LineData_t
{
	int row;                    //��¼�ļ�һ�����ݵ��к�
	int size;                   //��¼�ļ�һ�����ݵĴ�С
	char *buf;                  //�洢�ļ���һ������
	struct LineData_t *next;    //��ʽָ�룬��һ�����ļ����ݴ��������γ������ļ�
}LineData;

typedef struct FileData_t
{
	int fileRow;                              //�ļ���������
	int fileSize;                             //�ļ����ܴ�С
	char fileName[FILE_NAME_MAX_SIZE];        //�ļ���
	LineData *headNode;                       //�ļ��������ݵ�ͷ���
}FileData;

extern FileData* openFile(const char fileName[]);
extern void closeFile(FileData** fileData);

extern bool newFile(const char fileName[]);
extern int deleteFile(const char fileName[]);
extern bool clearFile(const char *fileName);

extern int renameFile(const char *oldName,const char newName[]);
extern bool copyFile(const char *srcFile,const char dtsFile[]);

extern bool isExistFile(const FileData *fileData);
extern bool isEmptyFile(const FileData *fileData);

extern int getFileSize(const FileData *fileData);
extern int getFileRow(const FileData *fileData);

extern bool appendLine(FileData *fileData,const char *data);
extern bool prependLine(FileData *fileData,const char data[]);

extern bool deleteLine(FileData *fileData,const int row);
extern bool clearLine(FileData *fileData,const int row);

extern bool insertLine(FileData *fileData,const int row,const char *data);
extern bool replaceLine(FileData *fileData,const int row,const char *data);

extern bool getFileData(const FileData *fileData,char buf[],const int size);
extern bool getLineData(const FileData *fileData,const int row,char* buf,const int size);

extern bool getStartArea(const FileData *fileData,const int len,char buf[],const int size);
extern bool getEndArea(const FileData *fileData,const int len,char buf[],const int size);

extern int findStrRow(const FileData *fileData,const char* str);
extern bool saveFile(FileData *fileData,const char* fileName);

extern void showFile(const char fileName[]);
extern void printFile(const FileData *fileData);

#endif //_FILE_OPERATE_H