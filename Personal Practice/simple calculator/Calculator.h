#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_
#include "characterInput.h"
#define MIN 0.001
class Calculator
{
public:
	Calculator();
	~Calculator();
public:
	float result()
	{
		initialization();
		return calIntfix();
	}
private:
	characterInput  InPut;
private:
	LNode* PtrL;
	int n;
	void initialization();
private:
	float* numStack;
	int top1 ;
	char* chStack;
	int top2 ;
private:
	int calSub(float opnd1, char op, float opnd2, float& result);
	int getPriority(char op);
	int calStackTopTwo(float num[], int& top1, char op[], int& top2);
	float calIntfix();
};

#endif
