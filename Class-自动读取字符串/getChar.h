#ifndef GETCHAR_H
#define GETCHAR_H

typedef struct chNode{
	char ch;
	chNode* next;
}chNode;

typedef struct numNode{
	int num;
	numNode* next;
}numNode;

typedef struct{
	char* ch;
	int length;
}arrayCh;

typedef struct{
	int* num;
	int length;
}arrayNum;

class getChar
{
	public:
		getChar(int);//构造函数
		void getCh();//读入所有数字和字符
		void getNum();//只读入数字 
		void getPureCh();//只读入运算符；
		void createArray(arrayCh&);//传出字符
		void createArray(arrayNum&);//传出数字
		void printArray(arrayCh);
		void printArray(arrayNum);
	protected:
		int length;
		chNode* chHead;
		chNode* pureChHead;
		numNode* numHead;
};

#endif 