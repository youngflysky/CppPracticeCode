#include "Clock.h"
#include <iostream>
using namespace std;

int main() {
	Clock myClock;
	cout << "Ĭ����ʾʱ��: "<<endl;
	myClock.setTime();
	myClock.showTime();
	cout<<"����ʱ�䣺"<<endl;
	myClock.setTime(8,30);
	myClock.showTime();
	return 0;
}