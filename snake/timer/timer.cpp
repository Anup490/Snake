#include "Timer.h"

Timer::Timer() 
{
	GetSystemTime(&currentTime);
}

bool Timer::IsMilliSecondComplete(unsigned short duration) 
{
	SYSTEMTIME newTime;
	GetSystemTime(& newTime);
	if (HasMilliSecondPassed(newTime)) 
	{
		SaveNewTime(newTime,duration);
		return true;
	}
	return false;
}

void Timer::SaveNewTime(SYSTEMTIME& rNewTime, unsigned short duration) 
{
	currentTime.wHour = rNewTime.wHour;
	currentTime.wMinute = rNewTime.wMinute;
	currentTime.wSecond = rNewTime.wSecond;
	currentTime.wMilliseconds = rNewTime.wMilliseconds + duration;
}

bool Timer::HasMilliSecondPassed(SYSTEMTIME& rNewTime) 
{
	return (rNewTime.wHour > currentTime.wHour)
		|| (rNewTime.wMinute > currentTime.wMinute)
		|| (rNewTime.wSecond > currentTime.wSecond)
		|| (rNewTime.wMilliseconds > currentTime.wMilliseconds);
}