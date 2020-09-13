#include "painter/painter.h"
#include "items/snakeitem.h"
#include "timer/timer.h"
#include "collision/collision.h"
#include <ppl.h>

char value = 'l';

void setupKeyListener(SnakeItem* pSnakeItem, Timer* pTimer);
void listenInput(SnakeItem* pSnakeItem, Timer* pTimer);
void runGame(Collision* pCollision, Painter* pPainter, Timer* pTimer);
void showGameOverMessage();

int main()
{
	SnakeItem snakeItem;
	initializer_list<AbstractItem*> items({ &snakeItem });
	Painter painter(&items, 1);
	Timer timer;
	Collision collision(SNAKE_LENGTH);
	
	setupKeyListener(&snakeItem, &timer);
	runGame(&collision,&painter,&timer);
	showGameOverMessage();
	
	return 0;
}

void setupKeyListener(SnakeItem* pSnakeItem, Timer* pTimer) {
	thread listener(listenInput, pSnakeItem, pTimer);
	listener.detach();
}

void listenInput(SnakeItem* pSnakeItem, Timer* pTimer) {
	while (value != EXIT_KEY) {
		if (pTimer->isMilliSecondComplete(FRAME_INTERVAL_MILLIS)) {
			cin >> value;
			pSnakeItem->onInput(value);
		}
	}
}

void runGame(Collision* pCollision, Painter* pPainter, Timer* pTimer) {
	while (value != EXIT_KEY) {
		if (pTimer->isMilliSecondComplete(FRAME_INTERVAL_MILLIS)) {
			try {
				pCollision->checkCollision(pPainter->paint());
			}
			catch (CollisionException& e) {
				value = EXIT_KEY;
			}
		}
	}
}

void showGameOverMessage() {
	for (int i = 0; i < (((MAX_X_AXIS) / 2) - 5); i++) {
		cout << " ";
	}
	cout << "GAME OVER" << endl;
}
