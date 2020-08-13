#include <windows.h>

class Timer {
	unsigned short second = 0;
	SYSTEMTIME currentTime;
	void saveNewTime(SYSTEMTIME& rNewTime, unsigned short duration);
	bool hasMilliSecondPassed(SYSTEMTIME& rNewTime);
public:
	Timer();
	bool isMilliSecondComplete(unsigned short duration);
};