#include <windows.h>

class Timer {
	unsigned short second = 0;
	SYSTEMTIME currentTime;
	void saveNewTime(SYSTEMTIME& rCurrentTime, SYSTEMTIME& rNewTime);
public:
	Timer();
	bool isSecondComplete();
	bool isMilliSecondComplete(unsigned short duration);
};