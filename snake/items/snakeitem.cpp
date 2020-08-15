#include "snakeitem.h"

SnakeItem::SnakeItem() {
	this->pPoints = new Points(SNAKE_LENGTH);
	initPoints();
}
SnakeItem::~SnakeItem() {
	delete pPoints;
}

void SnakeItem::onDraw() {
	for (int i = 0; i < SNAKE_LENGTH; i++) {
		Point* pPoint = (pPoints->pPointArray)+i;

		if (((pPoint->x) == (MAX_X_AXIS - 1)) && ((pPoint->y) < (MAX_Y_AXIS - 1))) {
			(pPoint->y)++;
		}
		else if (((pPoint->y) == (MAX_Y_AXIS - 1)) && ((pPoint->x) > 0)) {
			(pPoint->x)--;
		}
		else if (((pPoint->y) > 0) && ((pPoint->x) == 0)) {
			(pPoint->y)--;
		}
		else {
			(pPoint->x)++;
		}
	}
}

Points* SnakeItem::getPoints() {
	return pPoints;
}

void SnakeItem::initPoints() {
	for (int i = 0; i < SNAKE_LENGTH; i++) {
		Point* pPoint = (pPoints->pPointArray) + i;
		pPoint->x = i;
		pPoint->y = 0;
	}
}
