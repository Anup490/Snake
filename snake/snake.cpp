#include "painter/painter.h"
#include "timer/timer.h"

#define MAX_STEPS 50
#define INTERVAL_MILLIS 100

int main()
{
	Painter painter;
	Timer timer;
	int i = 0;
	int steps = 1;
	while (steps < MAX_STEPS) {
		if (timer.isMilliSecondComplete(INTERVAL_MILLIS)) {
			painter.paint(steps);
			steps++;
		}
	}
	return 0;
}

