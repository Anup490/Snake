#include "painter/painter.h"
#include "timer/timer.h"

#define MAX_STEPS_FOR_ITERATION 80

#define MAX_STEPS_X 20
#define MAX_STEPS_Y 10
#define INTERVAL_MILLIS 100

int main()
{
	Painter painter(MAX_STEPS_X, MAX_STEPS_Y);
	Timer timer;
	int i = 0;
	int steps = 1;
	while (steps < MAX_STEPS_FOR_ITERATION) {
		if (timer.isMilliSecondComplete(INTERVAL_MILLIS)) {
			if (steps > (MAX_STEPS_X * 2 + MAX_STEPS_Y + TURN_LENGTH_X)) {
				painter.paint(Direction::NY);
			}
			else if (steps > (MAX_STEPS_X + MAX_STEPS_Y)) {
				painter.paint(Direction::NX);
			}
			else if (steps > MAX_STEPS_X) {
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

