#include "painter/painter.h"
#include "timer/timer.h"

#define MAX_STEPS_FOR_ITERATION 50

#define MAX_STEPS_X 80
#define MAX_STEPS_Y 20
#define INTERVAL_MILLIS 100

int main()
{
	Painter painter(MAX_STEPS_X, MAX_STEPS_Y);
	Timer timer;
	int i = 0;
	int steps = 1;
	while (steps < MAX_STEPS_FOR_ITERATION) {
		if (timer.isMilliSecondComplete(INTERVAL_MILLIS)) {
			if (steps > (MAX_STEPS_FOR_ITERATION /2)) {
				painter.paint(Direction::PY);
			}
			else {
				painter.paint(Direction::PX);
			}
			steps++;
		}
	}
	return 0;
}

