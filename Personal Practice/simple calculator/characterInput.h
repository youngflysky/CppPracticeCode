#ifndef _CHARACTERINPUT_H_
#define _CHARACTERINPUT_H_

typedef struct LNode
{
	int Tag;		//Tag==0,URegion storage op£¬Tag==1 storage num;
	union
	{
		char op;
		float num;
	}URegion;
	struct LNode* next;
}LNode;

class characterInput
{
public:
	characterInput();//default Constructor
	characterInput(const characterInput& p) :		//copy Constructor
		headPointer(p.headPointer), tailPointer(p.tailPointer)
	{
	};

	~characterInput();
private:
	LNode* headPointer;
	LNode* tailPointer;
public:
	//Input valid data from keybord , storage LNode list ,and return headPointer 
	LNode* Input();

	int quantity(); //return quantity of the elements of list;

};
#endif // !_CHARACTERINPUT_H_