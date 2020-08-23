#include "painter/painter.h"
#include "items/snakeitem.h"
#include "timer/timer.h"

#define MAX_STEPS_FOR_ITERATION 549

#define INTERVAL_MILLIS 100

int main()
{
	SnakeItem snakeItem;
	Painter painter(&snakeItem,1);
	Timer timer;
	int steps = 1;
	while (steps < MAX_STEPS_FOR_ITERATION) {
		if (timer.isMilliSecondComplete(INTERVAL_MILLIS)) {
			painter.paint();
			steps++;
		}
	}
	return 0;
}

