#include "getChar.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//��ʼ��lengthֵΪ0����ʼ������ͷ�ڵ㣻
getChar::getChar(int initLength=0)
{
	length=initLength;
	chHead=(chNode*)malloc(sizeof(chNode));
	chHead->next=NULL;
	numHead=(numNode*)malloc(sizeof(numNode));
	numHead->next=NULL;	
	pureChHead=(chNode*)malloc(sizeof(chNode));
	pureChHead->next=NULL;
}

//�Զ������������ֺ��ַ���
void getChar::getCh()
{
	chNode *p = chHead;
	char ch;
	ch = cin.get();
	while (ch != '=')
	{
		if ((ch >= '0' && ch <= '9') || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')')
		{
			chNode *q=NULL;
			q = (chNode *)malloc(sizeof(chNode));
			q->next = NULL;
			q->ch=ch;
			p->next=q;
			p=q;
			++length;
		}
		else
		{
			ch=cin.get();
		}
	}
	cin.get();	
}

//ֻ�Զ���������
void getChar::getNum()
{
	numNode *p = numHead;
	char num;
	num = cin.get();
	while (num != '=')
	{
		if (num >= '0' && num <= '9')
		{
			numNode *q=NULL;
			q = (numNode *)malloc(sizeof(numNode));
			q->next = NULL;
			q->num=num-'0';
			p->next=q;
			p=q;
			++length;
		}
		else
		{
			num=cin.get();
		}
	}
	cin.get();	
	
}

//ֻ�Զ����������
void getChar::getPureCh()
{
	chNode *p = pureChHead;
	char ch;
	ch = cin.get();
	while (ch != '=')
	{
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')')
		{
			chNode *q=NULL;
			q = (chNode *)malloc(sizeof(chNode));
			q->next = NULL;
			q->ch=ch;
			p->next=q;
			p=q;
			++length;
		}
		else
		{
			ch=cin.get();
		}
	}
	cin.get();	
	
}

//�����ַ�����
void getChar::createArray(arrayCh& chArray)
{
	chArray.ch=(char*)malloc(length*sizeof(char));
	chArray.length=length;
	//chArray.falg=_CHAR_;
	chNode *p = chHead->next;
	for(int i=0;i<length;++i)
	{
		chArray.ch[i]=p->ch;
		p=p->next;
	}
	chNode* freep=chHead;
	for(int i=0;i<length;++i)
	{
		p=freep->next;
		free(freep);
		freep=p;
	}
	free(freep);
}


//������������
void getChar::createArray(arrayNum& numArray)
{
	numArray.num=(int*)malloc(length*sizeof(int));
	numArray.length=length;
	//numArray->falg=_NUM_;
	numNode *p = numHead->next;
	for(int i=0;i<length;++i)
	{
		numArray.num[i]=p->num;
		p=p->next;
	}
	numNode* freep=numHead;
	for(int i=0;i<length;++i)
	{
		p=freep->next;
		free(freep);
		freep=p;
	}
	free(freep);
}

//ֻ�������������
//void getChar::createArray(arrayCh& pureChArray)
//{
//	pureChArray.ch=(char*)malloc(length*sizeof(char));
//	pureChArray.length=length;
////	pureChArray.falg=_CHAR_;
//	pureChNode *p = pureChHead->next;
//	for(int i=0;i<length;++i)
//	{
//		pureChArray.ch[i]=p->ch;
//		p=p->next;
//	}
//	chNode* freep=pureChHead;
//	for(int i=0;i<length;++i)
//	{
//		p=freep->next;
//		free(freep);
//		freep=p;
//	}
//	free(freep);
//}

//��ӡ����
void getChar::printArray(arrayCh a)
{
	for(int i=0;i<a.length;++i)
	{
		cout << a.ch[i] << ' ';
	}
	cout << endl;
}
void getChar::printArray(arrayNum a)
{
	for(int i=0;i<a.length;++i)
	{
		cout << a.num[i] << ' ';
	}
	cout << endl;
	
}

