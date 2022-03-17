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
		getChar(int);//���캯��
		void getCh();//�����������ֺ��ַ�
		void getNum();//ֻ�������� 
		void getPureCh();//ֻ�����������
		void createArray(arrayCh&);//�����ַ�
		void createArray(arrayNum&);//��������
		void printArray(arrayCh);
		void printArray(arrayNum);
	protected:
		int length;
		chNode* chHead;
		chNode* pureChHead;
		numNode* numHead;
};

#endif 