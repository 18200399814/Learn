#ifndef _STUDENT_GLOBAL_H
#define _STUDENT_GLOBAL_H

/*ֻ��windows����ϵͳ��ʹ��VC++���������ɶ�̬��ʱ������Ҫʹ��__declspec(dllexport)��__declspec(dllimport)
 *���������dll��̬���з��ŵĵ����뵼�롣�����Windows����ϵͳ��ʹ��MSVC���������ɾ�̬�⣬��ô����Ҫʹ����
 *�������ŵĵ����뵼��������䡣��LInux����ϵͳ�����ɶ�̬���̬�ⶼû�п��з��ŵ����뵼�����
 */

/*Windows����ϵͳ��ʹ��MSVC���������ɶ�̬��ʱ��__declspec(dllexport)��������һ����������������
 *��dll��̬���е��������Ա��ⲿӦ�ó��������á�__declspec(dllimport)�����ڶ�̬���ṩ��ͷ�ļ��У�
 *��ʾ�����ⲿӦ�ó��򣬸ö�̬������Щ���������������ǿ���ֱ�Ӵ�dll�е���ģ������ñ������ν�ʱ
 *��ȥ�����Ĳ��ң��Ӷ���߱����ν��ٶȡ�
 */

#ifdef WIN32
#	if defined(STUDENT_LIBRARY)
#  		define STUDENT_SHARED_EXPORT __declspec(dllexport)
#	else
#  		define STUDENT_SHARED_EXPORT __declspec(dllimport)
#	endif
#else
#	define STUDENT_SHARED_EXPORT
#endif

#endif //_STUDENT_GLOBAL_H