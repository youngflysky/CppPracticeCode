#include "Clock.h"
#include <iostream>
using namespace std;


void Clock::setTime(int newH, int newM, int newS)
{
	hour = newH;
	minute = newM;
	second = newS;
}


void Clock::showTime()
{
	cout << hour << " : " << minute << " : " << second << endl;
}