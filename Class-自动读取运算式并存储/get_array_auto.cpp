#include "get_array_auto.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

get_array_auto::get_array_auto()
{
	head = (LNode *)malloc(sizeof(LNode));
	head->next = NULL;
	head->date='1';//��������head��û�б��ͷţ�
	rail = head;
}

//��array_get�õ����ַ�д��һ������β�巨��
void get_array_auto::array_write(LNode *&rail, datetype date)
{
	LNode *q;
	q = (LNode *)malloc(sizeof(LNode));
	q->date = date;
	q->next = NULL;
	rail->next = q;
	rail = q;
}

//��array_write�õ�������д��snack������
void get_array_auto::array_write_to_snack(snack &date_array, LNode *head)
{
	int i = 0;
	LNode *temp;
	temp = head;
	while (temp->next)
	{
		temp = temp->next;
		++i;
	}
	temp = head;
	date_array.size = i;
	date_array.date = (datetype *)malloc(sizeof(datetype) * (date_array.size));
	i = 0;
	while (temp->next)
	{
		temp = temp->next;
		date_array.date[i] = temp->date;
		++i;
	}
}

//��ӡ���õ��ı��ʽ
void get_array_auto::array_print(const snack &date_array)
{
	for (int i = 0; i < date_array.size; ++i)
	{
		cout << date_array.date[i];
	}
	cout << '=' << endl;
}

//�ⲿ�ӿڣ��Ӽ����ж������ֺ������ַ�����д��snack�����й��ⲿʹ��
void get_array_auto::array_get()
{
	datetype date;
	do
	{
		date = cin.get();
		if (date >= '0' && date <= '9')
		{
			array_write(rail, date);//
		}
		else
		{
			switch (date)
			{
				case '+':
				case '-':
				case '*':
				case '/':
				case '(':
				case ')':
					array_write(rail, date);
					break;
				default:
					break;
			}
		}
	} while (date != '=');
	array_write_to_snack(date_array, head);
	cout << "�����������ʽ��" << endl;
	array_print(date_array);
}

get_array_auto::~get_array_auto()
{
	rail = head;
	do
	{
		rail = head->next;
		delete head;
		head = rail;
	}while(head);
}