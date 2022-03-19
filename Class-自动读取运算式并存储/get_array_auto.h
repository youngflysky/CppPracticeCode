#ifndef GET_ARRAY_AUTO_H
#define GET_ARRAY_AUTO_H
#define datetype char

/*********************************************************************
    ����: get_array_auto���Զ������ַ���
    ����: 2022-03-19 12:19

    �ṹ��
    	�ṩ3���ⲿ�ӿڣ�
    	1.����ʹ��array_get()�����Ӽ�����˳������������ֺ���������洢��
    	2.�Ӻ���1�в���һ���ɹ��ⲿʹ�õ�
			typedef struct snack
			{
			datetype *date;
			int size;
			} snack;
			�ṹ�壬����date˳��洢�����ж�����ַ���
						size�洢���ַ���������
						date�Ĵ�С��sizeһ�£�
		3.����array_print(const snack&)���Դ�ӡ��2�е��ַ����飻
		4.ʹ�����������ͷ�������ʱ����Ŀռ�
*********************************************************************/


typedef struct LNode
{
	datetype date;
	LNode *next;
} LNode;

typedef struct snack
{
	datetype *date;
	int size;
} snack;


class get_array_auto
{
	public:
		get_array_auto();
		void array_get();//�Ӽ��̶����ַ�;Ψһ���ⲿ�ӿ�
		void array_print(const snack &date_array);//��ӡ��snack����
		~get_array_auto();
	public:
		snack date_array;//���ⲿʹ�õ�snack����
	protected:
		LNode *head;//ͷָ��������
		LNode *rail;//βָ������д
	private:
		void array_write(LNode *&rail, datetype date);//������д��������
		//�������е�����˳��洢��snack������
		void array_write_to_snack(snack &date_array, LNode *head);

};

#endif