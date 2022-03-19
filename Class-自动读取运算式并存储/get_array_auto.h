#ifndef GET_ARRAY_AUTO_H
#define GET_ARRAY_AUTO_H
#define datetype char

/*********************************************************************
    类名: get_array_auto（自动读入字符）
    日期: 2022-03-19 12:19

    结构：
    	提供3个外部接口：
    	1.可以使用array_get()函数从键盘中顺序读入所有数字和运算符并存储；
    	2.从函数1中产生一个可供外部使用的
			typedef struct snack
			{
			datetype *date;
			int size;
			} snack;
			结构体，其中date顺序存储了所有读入的字符；
						size存储了字符的数量；
						date的大小与size一致；
		3.函数array_print(const snack&)可以打印出2中的字符数组；
		4.使用析构函数释放所有临时申请的空间
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
		void array_get();//从键盘读入字符;唯一的外部接口
		void array_print(const snack &date_array);//打印出snack数组
		~get_array_auto();
	public:
		snack date_array;//供外部使用的snack数组
	protected:
		LNode *head;//头指针用来读
		LNode *rail;//尾指针用于写
	private:
		void array_write(LNode *&rail, datetype date);//把数据写入链表中
		//把链表中的数据顺序存储在snack数组中
		void array_write_to_snack(snack &date_array, LNode *head);

};

#endif