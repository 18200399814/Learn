-- ʹ��.read importtable.sql�����ִ��importtable.sql�ļ��е�SQL���

/*��student_table.txt�ļ��е����ݵ��뵽student_table����С�����Ҫע�������ݵ���֮ǰ��
 *��Ҫ�����ļ������ݾ���ķָ���ʽ���������ݵ���ļ��������student_table.txt�ı�����
 *�в��õ���tab�Ʊ��'\t����������ݣ����Ӧ�ȵ���.seperator '	'����tab�Ʊ��Ϊ�������
 */
.import student_table.txt student_table

-- ��score_table.txt�ļ��е����ݵ��뵽score_table����С�
.import score_table.txt score_table

-- ��month_table.txt�ļ��е����ݵ��뵽month_table����С�
.import month_table.txt month_table

/*��sale_table.txt�ļ��е����ݵ��뵽sale_table����С���sale_table.txt�ı������в���
 *����','��������ݣ����Ӧ�ȵ���.seperator ','����.mode csv���ö���','Ϊ�������
 */
.import sale_table.txt sale_table

-- ��score_info_table.txt�ļ��е����ݵ��뵽score_info_table����С�
.import score_info_table.txt score_info_table