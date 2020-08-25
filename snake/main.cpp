#include "painter/painter.h"
#include "items/snakeitem.h"
#include "timer/timer.h"
#include <ppl.h>

#define INTERVAL_MILLIS 100
#define EXIT_KEY 'x'

char value = 'l';

void listenInput(SnakeItem* pSnakeItem) {
	while (value != EXIT_KEY) {
		cin >> value;
		pSnakeItem->onInput(value);
	}
}

int main()
{
	SnakeItem snakeItem;
	Painter painter(&snakeItem,1);
	Timer timer;
	thread listener(listenInput, &snakeItem);
	listener.detach();
	while (value != EXIT_KEY) {
		if (timer.isMilliSecondComplete(INTERVAL_MILLIS)) {
			painter.paint();
		}
	}
	return 0;
}

