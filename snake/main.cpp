#include "painter/painter.h"
#include "items/snakeitem.h"
#include "timer/timer.h"
#include "collision/collision.h"
#include <ppl.h>

char value = 'l';

void listenInput(SnakeItem* pSnakeItem, Timer* pTimer) {
	while (value != EXIT_KEY) {
		if (pTimer->isMilliSecondComplete(FRAME_INTERVAL_MILLIS)) {
			cin >> value;
			pSnakeItem->onInput(value);
		}
	}
}

int main()
{
	SnakeItem snakeItem;
	Painter painter(&snakeItem,1);
	Timer timer;
	Collision collision(SNAKE_LENGTH);
	thread listener(listenInput, &snakeItem, &timer);
	listener.detach();
	while (value != EXIT_KEY) {
		if (timer.isMilliSecondComplete(FRAME_INTERVAL_MILLIS)) {
			try {
				collision.checkCollision(painter.paint());
			}
			catch (CollisionException& e) {
				value = EXIT_KEY;
			}
		}
	}
	return 0;
}

