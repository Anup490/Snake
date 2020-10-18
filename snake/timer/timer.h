#pragma once
#include <windows.h>

class Timer 
{
	unsigned short second = 0;
	SYSTEMTIME currentTime;
	void SaveNewTime(SYSTEMTIME& rNewTime, unsigned short duration);
	bool HasMilliSecondPassed(SYSTEMTIME& rNewTime);
public:
	Timer();
	bool IsMilliSecondComplete(unsigned short duration);
};