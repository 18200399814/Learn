/* 
 *ʹ��ʱ_DEBUG_OFF_���Դ�ӡ�꿪�ر�������mydebug.hͷ�ļ�֮ǰ��������Ч��
 *#define _DEBUG_OFF_
 *#include "mydebug.h" 
 */

#ifndef _MYDEBUG_H
#define _MYDEBUG_H

#include <stdio.h>
#include <stdlib.h>

#ifndef _DEBUG_OFF_
#define Debug(str)  \
    printf("[%s]%s: %s (line:%d) -- %s\n",__TIME__,__FILE__,__func__,__LINE__,(str))
#else
#define Debug(str)
#endif

#ifndef _ASSERT_OFF_
#define Assert(expr)                                                                                                 \
    do{                                                                                                              \
       if(!(expr))                                                                                                   \
       {                                                                                                             \
           fprintf(stderr,"assert failed: [%s %s] %s (line:%d) -- %s\n",__TIME__,__FILE__,__func__,__LINE__,#expr);  \
           exit(-1);                                                                                                 \
       }                                                                                                             \
    }while(0)
#else
#define Assert(expr) ((void)0)
#endif

#endif //_MYDEBUG_H