#include "painter/painter.h"
#include "timer/timer.h"

#define MAX_STEPS_FOR_ITERATION 75

#define INTERVAL_MILLIS 100

int main()
{
	Painter painter();
	Timer timer;
	int i = 0;
	int steps = 1;
	while (steps < MAX_STEPS_FOR_ITERATION) {
		if (timer.isMilliSecondComplete(INTERVAL_MILLIS)) {
			if (steps > (MAX_X_AXIS * 2 + MAX_Y_AXIS + TURN_LENGTH_X)) {
				painter.paint();
			}
			else if (steps > (MAX_X_AXIS + MAX_Y_AXIS)) {
				painter.paint();
			}
			else if (steps > MAX_X_AXIS) {
				painter.paint();
			}
			else {
				painter.paint();
			}
			steps++;
		}
	}
	return 0;
}

