#include "timer.h"

Timer::Timer() {
	GetSystemTime(&currentTime);
}

bool Timer::isMilliSecondComplete(unsigned short duration) {
	SYSTEMTIME newTime;
	GetSystemTime(&newTime);
	if (hasMilliSecondPassed(newTime)) {
		saveNewTime(newTime,duration);
		return true;
	}
	return false;
}

void Timer::saveNewTime(SYSTEMTIME& rNewTime, unsigned short duration) {
	currentTime.wHour = rNewTime.wHour;
	currentTime.wMinute = rNewTime.wMinute;
	currentTime.wSecond = rNewTime.wSecond;
	currentTime.wMilliseconds = rNewTime.wMilliseconds + duration;
}

bool Timer::hasMilliSecondPassed(SYSTEMTIME& rNewTime) {
	return (rNewTime.wHour > currentTime.wHour)
		|| (rNewTime.wMinute > currentTime.wMinute)
		|| (rNewTime.wSecond > currentTime.wSecond)
		|| (rNewTime.wMilliseconds > currentTime.wMilliseconds);
}