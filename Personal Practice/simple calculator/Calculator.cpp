#include "Calculator.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
Calculator::Calculator() :
	top1(-1), top2(-1)
{
};

Calculator::~Calculator() {};
void Calculator:: initialization()
{
	PtrL=InPut.Input();
	n = InPut.quantity();
	numStack = (float*)malloc(n*sizeof(float));
	chStack = (char*)malloc(n * sizeof(char));
}
int Calculator::calSub(float opnd1, char op, float opnd2, float& result)
{
	if (op == '+')
		result = opnd1 + opnd2;
	if (op == '-')
		result = opnd1 - opnd2;
	if (op == '*')
		result = opnd1 * opnd2;
	if (op == '/')
	{
		if (fabs(opnd2) < MIN)
		{
			return 0;
		}
		else
		{
			result = opnd1 / opnd2;
		}
	}
	return 1;
}

int Calculator:: getPriority(char op)
{
	if (op == '*' || op == '/')
	{
		return 1;
	}
	else if (op == '+' || op == '-')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int Calculator:: calStackTopTwo(float num[], int& top1, char op[], int& top2)
{
	if (calSub(num[top1 - 1], op[top2], num[top1], num[top1 - 1]))
	{
		--top1;
		--top2;
		return 1;
	}
	else
	{
		cout << "ERROR!" << endl;
		return 0;
	}
}

float Calculator::calIntfix()
{
	LNode* p = PtrL->next;
	while (p)
	{
		if (p->Tag==1)
		{
			numStack[++top1] = p->URegion.num; //字符整型转化成int整型
			p = p->next;
		}
		else if (p->URegion.op == '(')
		{
			chStack[++top2] = p->URegion.op;
			p = p->next;
		}
		else if (p->URegion.op== '+' || p->URegion.op== '-' || p->URegion.op== '*' || p->URegion.op== '/')
		{
			if (top2 == -1 ||
				chStack[top2] == '(' ||
				(getPriority(p->URegion.op) > getPriority(chStack[top2]))
				)
			{
				chStack[++top2] = p->URegion.op;
				p = p->next;
			}
			else //if((getPriority(p->URegion.op)<=getPriority(chStack[top2])))
			{
				calStackTopTwo(numStack, top1, chStack, top2);
			}
		}
		else if (p->URegion.op== ')')
		{
			while (chStack[top2] != '(')
			{
				calStackTopTwo(numStack, top1, chStack, top2);
			}
			--top2;
			p=p->next;
		}
	}
	while (top2 != -1)
	{
		calStackTopTwo(numStack, top1, chStack, top2);
	}
	return numStack[top1];
}