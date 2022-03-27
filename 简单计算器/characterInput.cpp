#include "characterInput.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

characterInput::characterInput()
{
	headPointer = (LNode*)malloc(sizeof(LNode));
	tailPointer = headPointer;
}
characterInput::~characterInput() 
{
};

LNode* characterInput::Input()
{
	 char ch;
	do
	{
		 ch=cin.get();
		if (ch >= '0' && ch <= '9')
		{
			float tempNum = ch - '0';
			do
			{
				ch = cin.get();
				if (ch >= '0' && ch <= '9')
				{
					tempNum = tempNum * 10 + (ch - '0');
				}
				else
				{
					break;
				}
			} while (1);
			LNode* s;
			s = (LNode*)malloc(sizeof(LNode));
			s->next = NULL;
			s->Tag = 1;
			s->URegion.num = tempNum;
			tailPointer->next = s;
			tailPointer = s;
		}
		switch (ch)
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '(':
			case ')':
				LNode * s;
				s = (LNode*)malloc(sizeof(LNode));
				s->next = NULL;
				s->Tag = 0;
				s->URegion.op=ch;
				tailPointer->next = s;
				tailPointer = s;
				break;
			case '=':
				return headPointer;
			default:
				cout << "Input Error!";
				return NULL;
		}
	} while (1);
}

int characterInput::quantity()
{
	int i = 0;
	LNode* q = headPointer->next;
	while (q)
	{
		++i;
		q = q->next;
	}
	return i;
}