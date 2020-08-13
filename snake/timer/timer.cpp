#include "timer.h"

Timer::Timer() {
	GetSystemTime(&currentTime);
}

bool Timer::isSecondComplete() {
	SYSTEMTIME newTime;
	GetSystemTime(&newTime);
	if (newTime.wHour>currentTime.wHour) {
		saveNewTime(currentTime,newTime);
		return true;
	}
	if (newTime.wMinute > currentTime.wMinute) {
		saveNewTime(currentTime, newTime);
		return true;
	}
	if (newTime.wSecond > currentTime.wSecond) {
		saveNewTime(currentTime, newTime);
		return true;
	}
	return false;
}

bool Timer::isMilliSecondComplete(unsigned short duration) {
	SYSTEMTIME newTime;
	GetSystemTime(&newTime);
	if (newTime.wHour > currentTime.wHour) {
		saveNewTime(currentTime, newTime);
		return true;
	}
	if (newTime.wMinute > currentTime.wMinute) {
		saveNewTime(currentTime, newTime);
		return true;
	}
	if (newTime.wSecond > currentTime.wSecond) {
		saveNewTime(currentTime, newTime);
		return true;
	}
	if (newTime.wMilliseconds > currentTime.wMilliseconds) {
		saveNewTime(currentTime, newTime);
		currentTime.wMilliseconds = currentTime.wMilliseconds + duration;
		return true;
	}
	return false;
}

void Timer::saveNewTime(SYSTEMTIME& rCurrentTime, SYSTEMTIME& rNewTime) {
	rCurrentTime.wHour = rNewTime.wHour;
	rCurrentTime.wMinute = rNewTime.wMinute;
	rCurrentTime.wSecond = rNewTime.wSecond;
	rCurrentTime.wMilliseconds = rNewTime.wMilliseconds;
}