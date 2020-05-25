#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

static void fopen_test();
static void fread_test();
static void fwrite_test();      //fread���ڿ����ݵ�д��
static void fprintf_test();
static void fscanf_test();
static void fgets_test();
static void fputs_test();       //fputs����������д�룬��fputs���Զ��ӻ��з�����puts���Զ���\n
static void fgetc_test();
static void fputc_test();
static void fseek_test();
static int  ftell_test();
static void ferror_test();
static void fflush_test();
static void fsetpos_test();
static void fgetpos_test();
static void feof_test();
static void rename_test();
static void remove_test();

int main(int argc,char* argv[])
{
    fopen_test();
    fread_test();
    fwrite_test();
    fprintf_test();
    fscanf_test();
    fgets_test();
    fputs_test();
    fgetc_test();
    fputc_test();
    fseek_test();
    ferror_test();
    fflush_test();
    fsetpos_test();
    fgetpos_test();
    rename_test();
    remove_test();
    
    printf("ftell_test.txt�ļ����ܴ�СΪ: %d\n",ftell_test());
    
    return 0;
}

void fopen_test()
{
    FILE *fp = fopen("file/fopen_test.txt","r+");
	if(fp == NULL)
    {
		perror("fopen failed!");
		abort();
	}
	
	char buf[256] = {0};
	fgets(buf,sizeof(buf),fp);
	printf("%s",buf);
	
	fgets(buf,sizeof(buf),fp);
	printf("%s",buf);

	fgets(buf,sizeof(buf),fp);
	printf("%s\n",buf);
    
	fclose(fp);
}

void fread_test()
{
    FILE *fp = fopen("./file/fread_test.txt","r");
    assert(fp != NULL);
    
    char buf[1024] = {0};              //����һ���Ƚϴ���ڴ棬���ļ�һ�ζ���buf�ڴ���
    fread(buf,sizeof(buf),1,fp);
    printf("%s\n",buf);

    fclose(fp);
}

void fwrite_test()
{
    FILE *fp = fopen("file/fwrite_test.txt","w");
    assert(fp != NULL);
#if 1
    char buf[] = "stdio.h: fwrite test\n\
time : 2019-11-27\n\
hello world\n";
    fwrite(buf,1,sizeof(buf),fp);
#else
    char buf[] = "stdio.h: fwrite test\n"
                 "time : 2019-11-27\n"
                 "hello world\n";
    fwrite(buf,1,sizeof(buf)-1,fp);        //sizeof(buf)-1��Ҫ��ȥ�ַ���ĩβ�ġ�\0"���������NULL����
#endif
    
    fclose(fp);
}

void fprintf_test()
{
    FILE *fp = fopen("file/fprintf_test.txt","w+");
    if(NULL == fp)
    {
        perror("fopen failed!");
        exit(-1);
    }
    
    fprintf(fp,"%s %s %s\n","stdio.h:","fprintf","test");
    fprintf(fp,"%s : %d-%d-%d\n","time",2019,11,27);
    fprintf(fp,"%s","hello world");
    
    fclose(fp);
}

void fscanf_test()
{
    FILE *fp = fopen("file/fscanf_test.txt","w+");
    if(NULL == fp)
    {
        perror("fopen failed");
        abort();
    }
    
    fputs("we are in 2019",fp);
    rewind(fp);        //���ļ�ָ�������ļ��Ŀ�ͷ
    
    int year;
    char str1[16],str2[16],str3[16];
    fscanf(fp,"%s %s %s %d",str1,str2,str3,&year);
    
    fprintf(stdout,"str1 =%s\n",str1);
    fprintf(stdout,"str2 =%s\n",str2);
    printf("str3 =%s\n",str3);
    printf("year =%d\n\n",year);
    
    fclose(fp);
}

void fgets_test()
{
    FILE *fp = fopen("file/fgets_test.txt","r");
	if(fp == NULL)
    {
		perror("fopen failed!");
		return ;
	}
	
	char buf[256];
    while(fgets(buf,sizeof(buf),fp) != NULL)
    {
        printf("%s",buf);
    }
    
	fclose(fp);
}

void fputs_test()
{
    FILE *fp = fopen("file/fputs test.txt","w");
    if(fp == NULL)
    {
        printf("fopen failed!");
        return ;
    }

    fputs("stdio.h: fputs test\n",fp);
    fputs("time : 2019-11-27\n",fp);
    fputs("hello world\n",fp);
    
    fclose(fp);
}

void fgetc_test()
{
    FILE *fp = fopen("file/fgetc_test.txt","r+");
    if(fp == NULL)
    {
        perror("fopen failed!");
        return ;
    }

#if 1 
    int c = 0;              //����4���ֽڵĿռ����洢һ���ַ�
    while(!feof(fp))
    {
        c = fgetc(fp);      //int fgetc(FILE *stream)
        printf("%c",c);
    }
#else
    int c = 0;              //����4���ֽڵĿռ����洢һ���ַ�
    do{
        c = fgetc(fp);      //int fgetc(FILE *stream)
        printf("%c",c);
    }while(c != EOF);
#endif    
    
    fclose(fp);
}

void fputc_test()
{
    FILE *fp = fopen("file/fputc_test.txt","w+");
    if(fp == NULL)
    {
        perror("fopen failed!");
        return ;
    }
    
    char buf[] = "stdio.h: fputc test\n"
                 "time : 2019-11-27\n"
                 "hello world\n";
    for(int i=0;i<sizeof(buf)-1;++i)     //sizeof(buf)-1���š�\0��
    {
        fputc(buf[i],fp);
    }
    
    fclose(fp);
}

void fseek_test()
{
    FILE *fp = fopen("file/fseek_test.txt","w+");
    if(fp == NULL)
    {
        puts("fopen failed!");
        abort();
    }
    
    char buf[] = "This is fseek test\n";
    fputs(buf,fp);
    
    fseek(fp,7,SEEK_SET);    //���ļ���дָ�붨λ�����ļ���ͷ��7���ֽڵ�λ��
    fputs(" C programming langauge\n",fp);
    
    fseek(fp,0,SEEK_END);   //���ļ�ָ�붨λ��ĩβ,SEEK_SET-�ļ���ͷ��SEEK_CUR-�ļ�ָ��ĵ�ǰλ�ã�SEEK_END-�ļ�ĩβ
    fputs("Hello world\n",fp);
    
    fclose(fp);
}

int ftell_test()
{
    FILE *fp = fopen("file/ftell_test.txt","r");
    if(NULL == fp)
    {
        perror("fopen failed!");
        exit(-1);
    }
    
    int len = 0;
    fseek(fp,0,SEEK_END);
    len = ftell(fp);
    
    fclose(fp);
    return len;
}

void ferror_test()
{
    FILE *fp = fopen("file/ferror_test.txt","a");
    if(NULL == fp)
    {
        perror("fopen failed!");
        return ;
    }
    
    int ch = fgetc(fp);
    if(ferror(fp))
    {
        printf("��ȡ�ļ���ferror_test.txtʱ��������\n\n");
    }else{
        printf("ch =%c\n",ch);
    }
    
    //��������� stream ���ļ������ʹ����ʶ����
    clearerr(fp);
    fseek(fp,0,SEEK_END);
    
    char *buf = "C programming langauge\n";
    fwrite(buf,1,strlen(buf),fp);
    if(ferror(fp))
    {
        printf("д���ļ���ferror_test.txtʱ��������\n");
    }
    
    fclose(fp);
}

void fflush_test()
{
    //��bufΪ�ֲ�����ʱ�������˳�ʱbuf�����٣����Դ�ӡ��������롣
    //����buf���붨��Ϊ��̬�ֲ���������ȫ�ֱ�����
    static char buf[1024];
    memset(buf,'\0',sizeof(buf));
    
    fprintf(stdout, "����ȫ����\n");
#if 1
   //��һ�������� stream Ӧ��λ���ĺ�����
   //  IOFBF  ȫ���壺��������������ڻ�������ʱ��һ����д�롣�������룬����������������һ���Ϊ��ʱ����䡣
   // _IOLBF  �л��壺����������������������з������ڻ�������ʱ��д�룬����������������������룬����������������һ���Ϊ��ʱ����䣬ֱ��������һ�����з���
   // _IONBF  �޻��壺��ʹ�û��塣ÿ�� I/O ����������ʱд�롣buffer �� size ����������
    setvbuf(stdout,buf,_IOFBF,sizeof(buf));
#else
   //������ stream Ӧ��λ��塣
    setbuf(stdout,buf);
#endif
    fprintf(stdout,"������runoob.com\n");
    fprintf(stdout,"����������浽buf\n");
    fflush(stdout);
    
    fprintf(stdout,"�⽫�ڱ��ʱ����\n");
    fprintf(stdout,"�������������\n");
    printf("hello world\n\n");

    sleep(2);
}

void fsetpos_test()
{
    FILE *fp = fopen("file/fsetpos_test.txt","w");
    if(!fp)
    {
        fprintf(stdout,"fopen error");
        abort();
    }

    fputs("stdio.h: fsetpos test\n",fp);
    fputs("time : 2019-11-27\n",fp);

    //ȡ�õ�ǰ�ļ���ָ����ָ��λ�ã����Ѹ�ָ����ָ��λ������ŵ�pos��ָ�Ķ����С�
    //posֵ���ڲ���ʽ�洢,����fgetpos��fsetposʹ�á�����fsetpos�Ĺ�����fgetpos�෴.
    fpos_t pos;
    fgetpos(fp,&pos);         //��ȡ��stream�ĵ�ǰ�ļ�λ�ã�������д�뵽pos
    fputs("hello world\n",fp);
    fputs("fsetpos/fgetpos test\n",fp);
    
    fsetpos(fp,&pos);        //���ø�����stream���ļ�λ��Ϊ������λ�á�����pos���ɺ���fgetpos������λ�á�
    fputs("�⽫����֮ǰ������\n",fp);
    fputs("C programming language\n",fp);
    
    fclose(fp);
}

void fgetpos_test()
{
    FILE *fp = fopen("file/fgetpos_test.txt","w");
    if(!fp)
    {
        fputs("fopen failed\n",stdout);
        exit(-1);
    }
    
    char buf[] = "hello world\n";
    fwrite(buf,sizeof(buf)-1,1,fp);
    
    fpos_t pos;
    fgetpos(fp,&pos);
    printf("the file pointer is at byte %ld\n",pos);
    
    fseek(fp,5,SEEK_SET);
    fgetpos(fp,&pos);
    printf("the file pointer is at byte %ld\n\n",pos);
    
    fclose(fp);
}

void feof_test()
{
    FILE *fp = fopen("file/feof_test.txt","r");
    if(!fp)
    {
        puts("fopen failed\n");
        return ;
    }

    char buf[1024] = {0};
    while(!feof(fp))              //��û�дﵽ�ļ�ĩβʱѭ��
    {
        static int cout = 1;
        fprintf(stdout,"cout =%d\n",cout);
        fread(buf,sizeof(buf),1,fp);
        fputs(buf,stdout);
        cout++;
    }
    
    fclose(fp);
}

void rename_test()
{   
    {//����һ���ļ�
        FILE *fp = fopen("file/rename_test.txt","w+");
        if(!fp)
        {
            perror("fopen error!\n");
            exit(-1);
        }
        
        char buf[] = "stdio.h: rename test\n"
                    "time : 2019-11-27\n"
                    "hello world\n";
        fwrite(buf,sizeof(buf),1,fp);
        fclose(fp);
    }

    rename("file/rename_test.txt","file/rename.txt");
    
    FILE *fp = fopen("file/rename.txt","r");
    if(!fp)
    {
        perror("fopen error!\n");
        exit(-1);
    }
    
    int ch = 0;
    while((ch = fgetc(fp)) != EOF)
    {
        fputc(ch,stdout);
    }
    
    fclose(fp);
}

void remove_test()
{
    FILE *fp = fopen("file/remove_test.txt","w+");
    if(NULL == fp)
    {
        fputs("fopen failed\n",stdout);
        abort();
    }
    
    fprintf(fp,"stdio.h: remove test\n");
    fprintf(fp,"time: 2019-12-03\n");
    fputs("hello world\n",fp);
    
    rewind(fp);   //�ļ�ָ�������ļ���ͷ
    
    char buf[256] = {0};
    while(!feof(fp))
    {
        fgets(buf,sizeof(buf),fp);
        fputs(buf,stdout);
        memset(buf,0,sizeof(buf));
    }
    fclose(fp);    //Ҫɾ���ļ���ǰ������ļ��رգ�����ɾ�����ɹ�
    
    int ret = remove("file/remove_test.txt");
    if(ret == 0)
    {
        puts("�ļ�ɾ���ɹ�\n");
        return ;
    }
    
    printf("�ļ�ɾ��ʧ��\n");
}