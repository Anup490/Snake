#include "painter/painter.h"
#include <windows.h>

int main()
{
	Painter painter;
	unsigned short second = 0;
	SYSTEMTIME time;
	GetSystemTime(&time);
	int i = 0;
	int steps = 1;
	while (steps < 20) {
		GetSystemTime(&time);
		if (time.wSecond > second) {
			painter.paint(steps);
			second = time.wSecond;
			steps++;
		}
	}
	return 0;
}

