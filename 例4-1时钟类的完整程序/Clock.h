#ifndef CLOCK_H
#define CLOCK_H

class Clock
{
	public:
		void setTime(int newH=0,int newM=0,int newS=0);
		void showTime();
	private:
		int hour;
		int minute;
		int second;
};

#endif