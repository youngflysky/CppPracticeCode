#include "Clock.h"
#include <iostream>
using namespace std;

int main() {
	Clock myClock;
	cout << "默认显示时间: "<<endl;
	myClock.setTime();
	myClock.showTime();
	cout<<"设置时间："<<endl;
	myClock.setTime(8,30);
	myClock.showTime();
	return 0;
}